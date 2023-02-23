#pragma once

#include <assert.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>

#include <atomic>
#include <string>
#include <vector>

namespace MiniServer{

class Buffer{
 public:
    Buffer(int size = 1024) : buffer_(size), read_pos_(0),write_pos_(0){};
    ~Buffer() = default;

    // 读取缓存(获取可读字节数,获取读指针，移动读指针)
    size_t get_readable_bytes() const;
    char* get_read_ptr();
    void move_read_ptr(size_t len);

    // 写入缓存(确保有足够空间写入)
    void make_space(size_t len);
    char* get_write_ptr();
    void move_write_ptr(size_t len);

    void clear();

    // 读取缓存 string
    std::string read(size_t len);
    std::string read_all();

    // 写入缓存 (string char* Buffer)
    void write_buffer(const std::string& str);
    void write_buffer(const char* str, size_t len);
    void write_buffer(const void* data, size_t len);
    void write_buffer(Buffer& buff);
    
    // 文件接口
    // errno_后缀是为了和系统的errno变量区分
    ssize_t read_fd(int fd, int* errno_);
    ssize_t write_fd(int fd, int* errno_);

 private:
    std::vector<char> buffer_;
    std::atomic<std::size_t> read_pos_;
    std::atomic<std::size_t> write_pos_;
};

}