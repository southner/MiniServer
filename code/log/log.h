#pragma once

#include <assert.h>
#include <stdarg.h>
#include <sys/stat.h>

#include <mutex>
#include <string>
#include <thread>

#include "buffer/buffer.h"
#include "log/log_queue.h"

using std::string;

namespace MiniServer {

const int LOG_PATH_LEN = 256;
const int LOG_NAME_LEN = 256;
const int MAX_CHARS_IN_LINE = 1000;
const int MAX_LINES = 50000;

enum LOG_LEVEL {
  ELL_DEBUG,
  ELL_INFO,
  ELL_WARN,
  ELL_ERROR,
};

/*
包含一个logqueue，一个写线程
初始化时创建一个写线程，写线程会自动从logqueue拿出东西写入fp，若无东西可写，会自动阻塞
writebuffer时会唤醒阻塞的写线程
*/
class Log {
 public:
  void init(LOG_LEVEL level, const char* path = "./log",
            const char* suffix = ".log", int max_capacity = 1000);

  static Log* get_instance();

  void write_buffer(LOG_LEVEL level, const char* format, ...);
  void flush();

  int get_level() { return level_; };
  void set_level(LOG_LEVEL level) { level_ = level; };

 private:
  Log();
  virtual ~Log();

  static void async_thread_func();
  void async_write();
  void log_message_level(LOG_LEVEL level);

  string path_;
  string suffix_;

  int line_count_;
  int day_of_month_;

  Buffer buffer_;
  LOG_LEVEL level_;
  bool is_async_;

  std::mutex fp_mtx_;
  FILE* fp_;
  std::unique_ptr<LogQueue<string>> log_queue_;
  std::unique_ptr<std::thread> write_thread_;
};

}  // namespace MiniServer

// 使用 while(0) 把宏包起来,可以使其不受括号,分号等的影响
#define LOG_BASE(level, format, ...)                        \
  do {                                                      \
    MiniServer::Log* log = MiniServer::Log::get_instance(); \
    if (log->get_level() <= level) {                        \
      log->write_buffer(level, format, ##__VA_ARGS__);      \
    }                                                       \
  } while (0);

#define LOG_DEBUG(format, ...)                                         \
  do {                                                                 \
    LOG_BASE(MiniServer::LOG_LEVEL::ELL_DEBUG, format, ##__VA_ARGS__); \
  } while (0);

#define LOG_INFO(format, ...)                                         \
  do {                                                                \
    LOG_BASE(MiniServer::LOG_LEVEL::ELL_INFO, format, ##__VA_ARGS__); \
  } while (0);

#define LOG_WARN(format, ...)                                         \
  do {                                                                \
    LOG_BASE(MiniServer::LOG_LEVEL::ELL_WARN, format, ##__VA_ARGS__); \
  } while (0);

#define LOG_ERROR(format, ...)                                         \
  do {                                                                 \
    LOG_BASE(MiniServer::LOG_LEVEL::ELL_ERROR, format, ##__VA_ARGS__); \
  } while (0);
