# buffer

# log

# mux

# thread_pool

# sql_pool

# timer

# http_request

# http_response

# http_conn

# server


# 数据库创建
```shell
# 安装服务器
sudo apt install mysql-server

# 安装客户端
sudo apt install mysql-client

# 配置用户账号密码和代码中对应
# 默认为 root 123456z

# 创建数据库
CREATE DATABASE miniserver;
CREATE TABLE IF NOT EXISTS users(
    user_id BIGINT(20) UNSIGNED AUTO_INCREMENT,
    user_name VARCHAR(40) NOT NULL,
    user_passwd VARCHAR(40) NOT NULL,
    PRIMARY KEY (user_id)
);
CREATE TABLE IF NOT EXISTS secrets(
    secret_id BIGINT(20) UNSIGNED AUTO_INCREMENT,
    secret VARCHAR(300) NOT NULL,
    user_id BIGINT(20) UNSIGNED,
    time DATE NOT NULL,
    PRIMARY KEY (secret_id)
);
```
# 前后端交互
## 事件描述
制作一个树洞，实现用户的注册，登录，登出功能。
用户可以向树洞倾诉自己的秘密、删除自己的秘密，其他用户可以选择倾听别人的秘密。
```json
{
    "brain_twister_id" : "xxx",
    "user_id": "xxx",
    "secret_id" : "xxx",
    "secret" : "xxx",
    "time": "时间戳",
}
```

## 服务器交互
- 浏览器发送内容
```text
{
    "action": "register/login/logout/query(查询自己的所有秘密)/random_query(随机获取一个其它用户的秘密)/add/update/delete",
    "action_info": {
        // register
        "user": "xxx",
        "passwd": "xxx",
        // login
        "user": "xxx",
        "passwd": "xxx",
        // logout
        "action_token": "xxx",
        // query:
        "action_token": "xxx",
        // random_query:
        "action_token": "xxx",
        // add
        "action_token": "xxx",
        "time": "2099-01-01",
        "secret": "xxx",
        // update
        "action_token": "xxx",
        "time": "2099-01-01",
        "secret_id": "xxx",
        "secret": "xxx",
        // delete
        "action_token": "xxx",
        "secret_id": "xxx",
    }
}
```
- 服务器返回内容
```text
{
    "action_result": "true/false",
    "result_info": {
        // register
        "action_token": "xxx",
        // login
        "action_token": "xxx",
        // logout
        // query:
        "secrets": [
                {
                  "secret_id": "xxx",
                  "time": "时间戳",
                  "secret": "xxx",
                }
              ]
        // random_query:
        "secrets": [
                {
                  "secret_id": "xxx",
                  "time": "时间戳",
                  "secret": "xxx",
                }
              ]
        // add
        //add完成后再次执行一下query
        // 发生错误时
        "error_message" :"xxx",
    }
}
```
# 浏览器调试语句

- register 

```js
fetch(new Request('action/register',{
    method:'POST', 
    headers: {'Content-Type': 'application/json'},
    body:"{\"action\":\"login\", \"action_info\": {\"user\":\"ztt\", \"passwd\": \"12345\"}}"
})).then((resp)=>{console.log(resp)})
```

- login
```js
fetch(new Request('action/login',{
    method:'POST', 
    headers: {'Content-Type': 'application/json'},
    body:"{\"action\":\"login\", \"action_info\": {\"user\":\"ztt\", \"passwd\": \"12345\"}}"
})).then((resp)=>{console.log(resp)})
```