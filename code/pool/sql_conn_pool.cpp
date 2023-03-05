#include "sql_conn_pool.h"

namespace MiniServer {
SQLConnPool::SQLConnPool() { Max_CONN_ = 0; }
SQLConnPool::~SQLConnPool() { close(); }
SQLConnPool *MiniServer::SQLConnPool::get_instance() {
  static SQLConnPool conn_pool;
  return &conn_pool;
}
sql::Connection *SQLConnPool::get_connect() {
  if (connections_.empty()) {
    return nullptr;
  }

  sql::Connection *conn;
  // 原子操作 若为0 则阻塞
  sem_wait(&sem_id_);
  {
    std::lock_guard<std::mutex> locker(mtx_);
    conn = connections_.back();
    connections_.pop_back();
  }
  return conn;
}
void SQLConnPool::free_connect(sql::Connection *conn) {
  assert(conn);
  std::lock_guard<std::mutex> locker(mtx_);
  connections_.push_back(conn);

  // 信号量+1
  sem_post(&sem_id_);
}
int SQLConnPool::get_free_connect_count() {
  std::lock_guard<std::mutex> locker(mtx_);
  return connections_.size();
}
void SQLConnPool::init(const char *host, int port, const char *user,
                       const char *pwd, const char *db_name,
                       int max_conn_count) {
  assert(max_conn_count > 0);

  // driver 指针无需手动释放
  sql::Driver *driver = get_driver_instance();
  assert(driver != nullptr);

  char url_buffer[MAX_URL_SIZE] = {0};
  sprintf(url_buffer, "tcp://%s:%d", host, port);
  std::string url(url_buffer);

  for (int i = 0; i < max_conn_count; i++) {
    sql::Connection *conn = driver->connect(url, user, pwd);
    assert(conn != nullptr);

    // 为conn选择数据库
    conn->setSchema(db_name);

    connections_.push_back(conn);
  }
}
void SQLConnPool::close() {
  std::lock_guard<std::mutex> locker(mtx_);
  while (!connections_.empty()) {
    sql::Connection *conn = connections_.back();
    connections_.pop_back();
    delete conn;
  }
}

}  // namespace MiniServer
