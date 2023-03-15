#pragma once

#include <error.h>
#include <regex>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "buffer/buffer.h"
#include "json11/json11.hpp"
#include "log/log.h"

using json11::Json;
using std::string;

namespace MiniServer {

class HttpRequest {
 public:
  enum PARSE_STATE {
    PS_REQUEST_LINES,
    PS_HEADERS,
    PS_BODY,
    PS_FINISH,
    PS_ERROR,
  };
  enum PARSE_RESULT {
    PR_ERROR,
    PR_INCOMPLETE,
    PR_SUCCESS,
  };
  HttpRequest() {
    init();
  }
  ~HttpRequest() = default;

  void init();
  void clear();
  PARSE_RESULT parse(Buffer &buffer);

  string get_path() const { return path_; }

  string get_method() const { return method_; }
  string get_version() const { return version_; }

  bool get_is_keep_alive() const;

  const string query_header(const string &key) const;
  const string query_header(const char *key) const;
  const std::unordered_map<string, string> get_header() const {
    return header_;
  }

  const Json query_post(const string &key) const;
  const Json query_post(const char *key) const;
  const Json get_post() const { return post_; }

 private:
  PARSE_STATE parse_request_line(const string &line);
  PARSE_STATE parse_header(const string &line);
  PARSE_STATE parse_body(const string &line);

  PARSE_STATE state_;
  string method_;
  string path_;
  string version_;
  string body_;

  std::unordered_map<string, string> header_;
  Json post_;

  
};

}  // namespace MiniServer
