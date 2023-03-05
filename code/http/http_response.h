#pragma once

#include <sys/mman.h>
#include <sys/stat.h>

#include <functional>
#include <string>
#include <unordered_map>

#include "buffer/buffer.h"
#include "http_request.h"
#include "log/log.h"
using std::string;
using std::unordered_map;

namespace MiniServer {

// 动态路由回调函数
typedef std::function<bool(const HttpRequest &request, Buffer &buffer)>
    router_cb;

class HttpResponse {
 public:
  HttpResponse();
  ~HttpResponse();

  void init(const std::string &src_dir, const std::string &file_path,
            bool is_keep_alive = false, int code = -1);

  void make_response(const HttpRequest &request, Buffer &buffer);

  // 获取映射至内存的文件指针
  char *get_file();
  // 释放内存中的文件
  void unmap_file();

  size_t get_file_size() const { return mm_file_stat_.st_size; };
  int get_code() const { return code_; };

  static bool register_static_router(string &src, string &des);
  static bool register_dynamic_router(string &src, const router_cb &cb);

 private:
  // 分别生成状态行 响应头 响应体
  void add_state_line_(Buffer &buff);
  void add_header_(Buffer &buff);
  void add_content_(Buffer &buff);

  // 生成错误信息
  void add_error_content(Buffer &buff, std::string message);

  // 若code_为错误码，根据code_取出对应错误时应返回的网页文件
  void response_to_code_();

  string get_file_type_();

  // 处理动态路由时使用的buffer
  Buffer dynamic_buffer_;

  int code_;
  bool is_keep_alive_;

  string src_dir_;
  // 静态路由的文件 动态路由的标识符
  string file_path_;

  char *mm_file_;
  struct stat mm_file_stat_;

  static const unordered_map<string, string> SUFFIX_TYPE;
  static const unordered_map<int, string> CODE_STATUS;
  static const unordered_map<int, string> ERROR_CODE_FILE;

  // 动态路由处理需要查询数据库的POST请求 静态路由处理静态资源文件的跳转
  static unordered_map<string, router_cb> dynamic_router_;
  static unordered_map<string, string> static_router_;
};
}  // namespace MiniServer
