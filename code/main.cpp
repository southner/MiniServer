#include "routers.h"
#include "server/server.h"

int main() {
  MiniServer::Server server(2345, true, 10000, true, "../", "localhost", 3306,
                            "root", "123456z", "miniserver", 8, 8,
                            MiniServer::LOG_LEVEL::ELL_DEBUG, 0);

  // 注册静态路由
  server.register_static_router("/", "/index.html");

  // 注册动态路由
  server.register_dynamic_router("/action/login", router_login);
  server.register_dynamic_router("/action/logout", router_logout);
  
  server.start();
}