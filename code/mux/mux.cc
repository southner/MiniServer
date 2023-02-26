#include <mux.h>

const static char LOG_TAG[] = "mux";

namespace MiniServer{

    Mux::Mux(int max_event) : mux_fd_(epoll_create(max_event)), events_(max_event){
        assert(mux_fd_ >= 0 && events_.size() > 0);
    }
    Mux::~Mux()
    {
        close(mux_fd_);
    }
    bool Mux::add_fd(int fd, uint32_t events)
    {
        if (fd < 0){
            return false;
        }

        epoll_event ev = {0};
        ev.data.fd = fd;
        ev.events = events;

        return 0 == epoll_ctl(mux_fd_, EPOLL_CTL_ADD, fd, &ev);
    }
    bool Mux::mod_fd(int fd, uint32_t events)
    {
        if (fd < 0){
            return false;
        }

        epoll_event ev = {0};
        ev.data.fd = fd;
        ev.events = events;

        return 0 == epoll_ctl(mux_fd_, EPOLL_CTL_MOD, fd, &ev);
    }
    bool Mux::del_fd(int fd)
    {
        if (fd < 0){
            LOG_WARN("[%s] Delete a negative fd[%d]!", LOG_TAG, fd);
            return false;
        }
        
        epoll_event ev = {0};

        return 0 == epoll_ctl(mux_fd_, EPOLL_CTL_DEL, fd, &ev);
    }
    int Mux::wait(int timeout)
    {
        //当一个线程在对epoll_wait()的调用中被阻塞时，
        //另一个线程有可能向等待的epoll实例添加文件描述符。
        //如果新文件描述符准备就绪，它将导致epoll_wait()调用解除阻塞。
        events_count_ = epoll_wait(mux_fd_, &events_[0], 
                        static_cast<int>(events_.size()), timeout);
        
        if (events_count_ < 0){
            LOG_ERROR("[%s] epoll_wait error with error:[%d]", LOG_TAG, errno);
        }
        return events_count_;
    }
    int Mux::get_active_fd(int i) const
    {   
        //当epoll_wait阻塞时若被信号中断，在线程处理完信号函数后返回时，epoll_wait()不会继续阻塞，而是推出，返回-1。
        //所以不能assert(i < events_count_)
        assert(i < events_.size() && i>=0);
        return events_[i].data.fd;
    }
    int Mux::get_active_events(int i) const
    {
        assert(i < events_.size() && i>=0);
        return events_[i].events;
    }
}