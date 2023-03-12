#include "routers.h"
#include "server/server.h"

int main() {
  MiniServer::Server server(2345, true, 5000, true, "../", "localhost", 3306,
                            "root", "123456z", "miniserver", 8, 8,
                            MiniServer::LOG_LEVEL::ELL_WARN, 0);

  // 注册静态路由
  server.register_static_router("/", "/index.html");
  server.register_static_router("/picture", "/picture.html");

  // 注册动态路由

  server.register_dynamic_router("/action/login", router_login);
  server.register_dynamic_router("/action/logout", router_logout);
  server.register_dynamic_router("/action/register", router_register);
  server.register_dynamic_router("/action/add", router_add);
  server.register_dynamic_router("/action/query", router_query);
  server.register_dynamic_router("/action/random_query", router_random_query);
  server.register_dynamic_router("/action/update", router_update);
  server.register_dynamic_router("/action/delete", router_delete);

  server.start();
}