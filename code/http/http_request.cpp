#include "http_request.h"

const static char LOG_TAG[] = "HTTP_REQUEST";

namespace MiniServer {
void HttpRequest::init() {
  // 如果是解析到请求体部分，就继续解析，不清空
  if (state_ != PARSE_STATE::PS_BODY) {
    state_ = PARSE_STATE::PS_REQUEST_LINES;
    method_ = "";
    path_ = "";
    version_ = "";
    body_ = "";

    header_.clear();
    post_ = Json();
  }
}
void HttpRequest::clear() {
  state_ = PARSE_STATE::PS_REQUEST_LINES;
  method_ = "";
  path_ = "";
  version_ = "";
  body_ = "";

  header_.clear();
  post_ = Json();
}
HttpRequest::PARSE_RESULT HttpRequest::parse(Buffer &buffer) {
  const char CRLF[] = "\r\n";
  if (buffer.get_readable_bytes() <= 0) {
    return PARSE_RESULT::PR_ERROR;
  }

  string line;
  const char *begin_ptr = buffer.get_read_ptr();
  const char *end_ptr = buffer.get_write_ptr();

  while (end_ptr >= begin_ptr) {
    // 请求行 和 请求头
    const char *line_end = nullptr;
    if (state_ != PARSE_STATE::PS_BODY) {
      line_end = std::search(begin_ptr, end_ptr, CRLF, CRLF + 2);
      line = string(begin_ptr, line_end);
    } else {
      // 解析请求体
      line_end = end_ptr;
      line = string(begin_ptr, line_end);
      {
        int content_length = -1;
        if (header_.count("Content-Length") != 0) {
          content_length = std::stoi(header_["Content-Length"]) + 2;
        } else if (header_.count("content-length") != 0) {
          content_length = std::stoi(header_["content-length"]) + 2;
        } else {
          // post请求必须包含Content-Length
          LOG_ERROR("[%s] Missing key: Content-Length", LOG_TAG);
          state_ = PARSE_STATE::PS_ERROR;
          return PARSE_RESULT::PR_ERROR;
        }

        LOG_DEBUG("[%s] Content Length:%d/%d", LOG_TAG, line.size(),
                  content_length);
        if (content_length > line.size()) {
          LOG_DEBUG("[%s] Incomplete post data.", LOG_TAG);
          return PARSE_RESULT::PR_INCOMPLETE;
        } else if (content_length < line.size()) {
          LOG_ERROR("[%s] Error while parsing, recevied unexpected data",
                    LOG_TAG);
          state_ = PARSE_STATE::PS_ERROR;
          return PARSE_RESULT::PR_ERROR;
        }
      }
    }
    switch (state_) {
      case PARSE_STATE::PS_REQUEST_LINES:
        state_ = parse_request_line(line);
        break;
      
      case PARSE_STATE::PS_HEADERS:
        state_ = parse_header(line);
        break;

      case PARSE_STATE::PS_BODY:
        state_ = parse_body(line);
        break;

      case PARSE_STATE::PS_FINISH:
        return PARSE_RESULT::PR_SUCCESS;

      case PARSE_STATE::PS_ERROR:
        return PARSE_RESULT::PR_ERROR;

      default:
        break;
    }

    if (state_ != PARSE_STATE::PS_BODY) {
      buffer.move_read_ptr(line_end - begin_ptr + 2);
      begin_ptr = line_end + 2;
    }
  }

  return PARSE_RESULT::PR_SUCCESS;
}
bool HttpRequest::get_is_keep_alive() const {
  //?
  if (header_.count("Connection") == 1) {
    return header_.find("Connection")->second == "keep-alive";
  }
  return false;
}
const string HttpRequest::query_header(const string &key) const {
  assert(key != "");
  if (header_.count(key) == 1) {
    return header_.find(key)->second;
  }
  return "";
}
const string HttpRequest::query_header(const char *key) const {
  assert(key != nullptr);
  if (header_.count(key) == 1) {
    return header_.find(key)->second;
  }
  return "";
}
const Json HttpRequest::query_post(const string &key) const {
  assert(key != "");
  return post_[key];
}
const Json HttpRequest::query_post(const char *key) const {
  assert(key != nullptr);
  return post_[string(key)];
}
HttpRequest::PARSE_STATE HttpRequest::parse_request_line(const string &line) {
  std::regex pattern("^([^ ]*) ([^ ]*) HTTP/([^ ]*)$");
  std::smatch sub_match;

  bool result = std::regex_match(line, sub_match, pattern);
  if (result) {
    method_ = sub_match[1];
    path_ = sub_match[2];
    version_ = sub_match[3];
    return PARSE_STATE::PS_HEADERS;
  }
  LOG_ERROR("[%s] Parse request line error!", LOG_TAG);
  return PARSE_STATE::PS_ERROR;
}
HttpRequest::PARSE_STATE HttpRequest::parse_header(const string &line) {
  if (line.size() == 0) {
    if (method_ == "post" || method_ == "POST") {
      return PARSE_STATE::PS_BODY;
    } else {
      return PARSE_STATE::PS_FINISH;
    }
  }
  std::regex pattern_header("^([^:]*): ?(.*)$");
  std::smatch match_header;
  
  if (std::regex_match(line, match_header, pattern_header)) {
    header_[match_header[1]] = match_header[2];
    return PARSE_STATE::PS_HEADERS;
  }
  // 解析错误
  return PARSE_STATE::PS_ERROR;
}
HttpRequest::PARSE_STATE HttpRequest::parse_body(const string &line) {
  if (header_["Content-Type"] == "application/json" ||
      header_["content-type"] == "application/json") {
    // 只解析json格式请求
    string error;
    post_ = Json::parse(line, error);
    if (error != "") {
      // 解析发生错误
      LOG_ERROR("[%s] Body(json) parse error: %s", LOG_TAG, error.data());
      return PARSE_STATE::PS_ERROR;
    }
  }
  return PARSE_STATE::PS_FINISH;
}
}  // namespace MiniServer