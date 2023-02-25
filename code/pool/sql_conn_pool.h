#pragma once

#include <assert.h>
#include <cppconn/connection.h>
#include <cppconn/driver.h>
#include <semaphore.h>

#include <string>
#include <mutex>
#include <vector>

#include "log/log.h"

namespace MiniServer{

#define MAX_URL_SIZE 200

class SQLConnPool{
 public:
    //单例模式
    static SQLConnPool* get_instance();

    //申请一个连接
    sql::Connection* get_connect();
    void free_connect(sql::Connection* conn);
    int get_free_connect_count();

    void init(const char* host, int port, const char* user,const char* pwd,
            const char* db_name, int max_conn_count);
    void close();

 private:
    SQLConnPool();
    ~SQLConnPool();
    int Max_CONN_;
    std::vector<sql::Connection*> connections_;
    std::mutex mtx_;
    sem_t sem_id_;
};

class SQLConn{
 public:
    SQLConn() {
        pool_ = SQLConnPool::get_instance();
        conn = pool_->get_connect();
    }
    bool is_valid() {return (conn == nullptr);}

    ~SQLConn() {pool_->free_connect(conn);}

    sql::Connection* conn;
 private:
    //对外界完全隐藏
    SQLConnPool* pool_;
};
}