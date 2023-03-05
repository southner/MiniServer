#include "buffer.h"

namespace MiniServer {

size_t Buffer::get_readable_bytes() const { return write_pos_ - read_pos_; }

char *Buffer::get_read_ptr() {
  // 先解除iterator再取地址
  return &(*buffer_.begin()) + read_pos_;
}

char *Buffer::get_write_ptr() { return &(*buffer_.begin()) + write_pos_; }

void Buffer::move_read_ptr(size_t len) {
  if (len > write_pos_ - read_pos_) {
    read_pos_ = write_pos_ = 0;
  } else {
    read_pos_ += len;
  }
}

void Buffer::make_space(size_t len) {
  // 本身空间就够
  // 1024(size) - 1023(write_pos) = 1 剩余1023这个位置
  int remaining_bytes = buffer_.size() - write_pos_;
  if (remaining_bytes > len) return;

  // 加上已读的空间足够
  // read_pos_ = 1 (0读过了 1没有读)
  int used_bytes = read_pos_;
  if (remaining_bytes + used_bytes > len) {
    size_t readable_bytes = get_readable_bytes();
    std::copy(get_read_ptr(), get_write_ptr(), &(*buffer_.begin()));
    read_pos_ = 0;
    write_pos_ = readable_bytes;
  }

  buffer_.resize(buffer_.size() + len);
}

void Buffer::move_write_ptr(size_t len) {
  assert((buffer_.size() - write_pos_) >= len);
  write_pos_ += len;
}

void Buffer::clear() {
  read_pos_ = 0;
  write_pos_ = 0;
}

std::string Buffer::read(size_t len) {
  len = len > get_readable_bytes() ? get_readable_bytes() : len;

  std::string str(get_read_ptr(), get_read_ptr() + len);
  read_pos_ += len;
  return str;
}

std::string Buffer::read_all() { return read(get_readable_bytes()); }

void Buffer::write_buffer(const std::string &str) {
  write_buffer(str.data(), str.size());
}

// 将其他写函数转换至通用接口
void Buffer::write_buffer(const char *str, size_t len) {
  assert(str);
  make_space(len);
  std::copy(str, str + len, get_write_ptr());
  write_pos_ += len;
}

void Buffer::write_buffer(const void *data, size_t len) {
  assert(data);
  write_buffer(static_cast<const char *>(data), len);
}

void Buffer::write_buffer(Buffer &buff) {
  write_buffer(buff.get_read_ptr(), buff.get_readable_bytes());
}

ssize_t Buffer::read_fd(int fd, int *errno_) {
  // IPv4的数据报最大大小是65535字节
  char buff[65536];
  struct iovec iov[2];
  const size_t writeable_bytes = buffer_.size() - write_pos_;

  iov[0].iov_base = get_write_ptr();
  iov[0].iov_len = writeable_bytes;
  iov[1].iov_base = buff;
  iov[1].iov_len = sizeof(buff);

  const ssize_t len = readv(fd, iov, 2);

  if (len < 0) {
    *errno_ = errno;
  } else if (static_cast<size_t>(len) < writeable_bytes) {
    write_pos_ += len;
  } else {
    write_pos_ = buffer_.size();
    write_buffer(buff, len - writeable_bytes);
  }
  return len;
}

ssize_t Buffer::write_fd(int fd, int *errno_) {
  size_t read_size = get_readable_bytes();
  size_t len = write(fd, get_read_ptr(), read_size);

  if (len < 0) {
    *errno_ = errno;
    return len;
  }
  read_pos_ += len;
  return 0;
}

}  // namespace MiniServer
