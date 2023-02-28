#pragma once

#include <arpa/inet.h>
#include <unistd.h>

#include <atomic>
#include <string>

#include "buffer/buffer.h"
#include "http_request.h"
#include "http_response.h"
#include "log/log.h"

using std::string;

namespace MiniServer
{

    class HttpConn
    {
    public:
        HttpConn();
        ~HttpConn();

        // 控制函数
        void init(int sock_fd, const sockaddr_in sock_addr);
        void close_conn();

        // 通用静态设置
        static void global_config(bool is_ET, string &src_dir, int user_count);

        // 功能函数
        ssize_t read(int *errno_);
        ssize_t write(int *errno_);
        bool process();

        int get_fd() const { return sock_fd_; }
        sockaddr_in get_addr() const { return sock_addr_; }
        int get_port() const { return sock_addr_.sin_port; }
        string get_ip() const { return string(inet_ntoa(sock_addr_.sin_addr)); };
        static int get_user_count() { return user_count_; }

        size_t get_writable_bytes() const
        {
            return iov_[0].iov_len + iov_[1].iov_len;
        };

        bool is_keep_alive() const { return request_.get_is_keep_alive(); };

        bool is_closed() const { return is_closed_; }

        std::mutex mtx_;

    private:
        static bool is_ET_;
        static string src_dir_;
        static std::atomic<int> user_count_;

        int sock_fd_;
        struct sockaddr_in sock_addr_;
        bool is_closed_;

        // iov[0] 响应头 buffer
        // iov[1] 响应体 文件
        int iov_count_;
        struct iovec iov_[2];

        Buffer read_buffer_;
        Buffer write_buffer_;

        HttpRequest request_;
        HttpResponse response_;
    };
}