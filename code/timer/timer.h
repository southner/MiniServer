#pragma once

#include <assert.h>
#include <chrono>
#include <functional>
#include <unordered_map>
#include <vector>

typedef std::function<void()> timeout_cb;
typedef unsigned int timer_id;
typedef std::chrono::milliseconds MS;
typedef std::chrono::high_resolution_clock Clock;
typedef Clock::time_point time_stamp;

namespace MiniServer{
struct TimerNode {
    //存入定时器的定时器id，一般为连接的socket
    timer_id id;
    time_stamp timeout_point;
    timeout_cb cb;
    bool operator<(const TimerNode& t) {return timeout_point < t.timeout_point;}
};


class Timer{
 public:

    Timer() {};
    ~Timer() {};

    /*timeout_period:定时器的存活时间*/
    void add_timer(timer_id id, int timeout_period, const timeout_cb& call_back);
    void pop_timer();

    /*启动某个定时器里的回调函数*/
    void do_work(timer_id id);
    /*重新调整某个定时器的时间*/
    void adjust(timer_id id, int timeout_period);

    /*删除所有定时器*/
    void clear();
    //查看堆顶的定时器是否到时间并删除它
    void tick();

    //获取下一个定时器触发的剩余时间
    int get_next_timeout_period();

 private:

    void delete_(size_t index);
    void shift_up_(size_t index);
    bool shift_down_(size_t index, size_t border);
    void swap_(size_t index1,size_t index2);
    
    //小顶堆，0下标对应最小元素
    std::vector<TimerNode> heap_;
    //定时器id->定时器在vector的index
    std::unordered_map<timer_id,size_t> timer_ref_;
};
}