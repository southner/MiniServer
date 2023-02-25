#pragma once

#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>
#include <functional>
#include <assert.h>

namespace MiniServer{
class ThreadPool{
 public:
    explicit ThreadPool(size_t threadCount = 10):pool_(std::make_shared<Pool>()){
        assert(threadCount > 0);
        for (size_t i = 0; i < threadCount; i++){
            std::thread([pool = pool_] {
                std::unique_lock<std::mutex> locker(pool->mtx);
                while (true){
                    if (!pool->tasks.empty()){
                        auto task = std::move(pool->tasks.front());
                        pool->tasks.pop();
                        locker.unlock();
                        task();
                        locker.lock();
                    } else if (pool->isClosed) break;
                    else{
                        //阻塞线程 并自动给locker解锁
                        pool->cond.wait(locker);
                    }
                }
            }).detach();
        }
    };
    //默认构造函数
    ThreadPool() = default;
    ThreadPool(ThreadPool &&) = default;
    ~ThreadPool(){
        if (static_cast<bool>(pool_)){
            std::lock_guard<std::mutex> locker(pool_->mtx);
            pool_->isClosed = true;
        }
        pool_->cond.notify_all();
    }

    //完美转发
    template<class F>
    void AddTask(F&& task){
        {
            std::lock_guard<std::mutex> locker(pool_->mtx);
            pool_->tasks.emplace(std::forward<F>(task));
        }
        pool_->cond.notify_one();
    }

 private:
    //将pool_z整个传给线程
    struct Pool {
        //确保安全使用队列
        std::mutex mtx;
        //用来唤醒线程
        std::condition_variable cond;
        bool isClosed;
        std::queue<std::function<void()>> tasks;
    };
    std::shared_ptr<Pool> pool_;
};
}
