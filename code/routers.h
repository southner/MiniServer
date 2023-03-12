#pragma once
#include <cppconn/prepared_statement.h>

#include "json11/json11.hpp"
#include <string>

#include "buffer/buffer.h"
#include "http/http_request.h"
#include "log/log.h"
#include "pool/sql_conn_pool.h"
#include "server/server.h"

using MiniServer::Buffer;
using MiniServer::HttpRequest;
using std::string;

struct secret {
  public:
  string secret_id_;
  string time_;
  string secret_;
  string user_name_;
  secret(const string& secret_id, const string& time, const string& secret,
    const string& user_name="")
      : secret_id_(secret_id), time_(time), secret_(secret), user_name_(user_name){}
  Json to_json() const {
    return Json::object{{"secret_id", secret_id_},
                        {"time", time_},
                        {"secret", secret_},
                        {"user_name", user_name_},
                        };
  }
};

bool router_register(const HttpRequest& request, Buffer& buffer);
bool router_login(const HttpRequest& request, Buffer& buffer);
bool router_logout(const HttpRequest& request, Buffer& buffer);
bool router_add(const HttpRequest& request, Buffer& buffer);
bool router_query(const HttpRequest& request, Buffer& buffer);
bool router_random_query(const HttpRequest& request, Buffer& buffer);
bool router_update(const HttpRequest& request, Buffer& buffer);
bool router_delete(const HttpRequest& request, Buffer& buffer);