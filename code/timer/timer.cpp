#include "timer.h"

namespace MiniServer{

void MiniServer::Timer::add_timer(timer_id id, int timeout_period, const timeout_cb &call_back)
{
    assert(id >= 0);
    size_t i;

    if (timer_ref_.count(id) == 0){
        //新节点
        i = heap_.size();
        timer_ref_[id] = i;
        heap_.push_back({id,Clock::now()+MS(timeout_period),call_back});
        shift_up_(i);
    } else {
        //已有节点
        i = timer_ref_[id];
        heap_[i].timeout_point = Clock::now() + MS(timeout_period);
        heap_[i].cb = call_back;

        //调整节点位置
        if (!shift_down_(i,heap_.size())){
            shift_up_(i);
        }
    }
}

void MiniServer::Timer::pop_timer()
{
    assert(!heap_.empty());
    delete_(0);
}

void MiniServer::Timer::do_work(timer_id id)
{
    //堆为空或id不存在
    if (heap_.empty() || timer_ref_.count(id) == 0){
        return;
    }
    size_t i = timer_ref_[id];
    TimerNode& node = heap_[i];
    node.cb();
    delete_(i);
}

void MiniServer::Timer::adjust(timer_id id, int timeout_period)
{
    //确保元素存在
    assert(!heap_.empty() && timer_ref_.count(id) > 0);
    //更新时间并调整位置
    heap_[timer_ref_[id]].timeout_point = Clock::now() + MS(timeout_period);
    if (!shift_down_(timer_ref_[id],heap_.size())){
            shift_up_(timer_ref_[id]);
    }  
}

//是否应该把定时器中所有元素弹出并调用回调函数？ 目前不调用
void MiniServer::Timer::clear()
{
    timer_ref_.clear();
    heap_.clear();
}

void MiniServer::Timer::tick()
{
    if (heap_.empty()){
        return;
    }

    //从堆顶把到时间的定时器挨个删除
    while(!heap_.empty()){
        TimerNode& node = heap_.front();
        MS time_left = std::chrono::duration_cast<MS>(node.timeout_point - Clock::now());
        if (time_left.count() > 0){
            break;
        }

        node.cb();
        delete_(0);
    }
}

int MiniServer::Timer::get_next_timeout_period()
{
    tick();

    size_t res = -1;
    if (!heap_.empty()){
        time_stamp timeout_point = heap_.front().timeout_point;
        res = std::chrono::duration_cast<MS>(timeout_point - Clock::now()).count();
    }

    return res;
}

//私有函数
void Timer::delete_(size_t index)
{
    assert(!heap_.empty() && index >= 0 && index < heap_.size());
    size_t n = heap_.size() -1 ;

    //把定时器移动到末尾 再调整原堆尾元素位置
    if (index < n){
        swap_(index, n);
        if (!shift_down_(index,n)){
            shift_up_(index);
        }
    }

    //删除堆尾元素
    timer_ref_.erase(heap_.back().id);
    heap_.pop_back();

}

//(size_t(0)-1)/2 -> 下溢出
void Timer::shift_up_(size_t index)
{
    assert(index >=0 && index<= heap_.size());

    size_t parent = (index -1)/2;

    //如果节点小于父节点，就一直向上移动
    while(index>0){
        if (heap_[parent] < heap_[index]) break;
        swap_(index,parent);
        index = parent;
        parent = (parent - 1)/2;
        
    }
}
bool Timer::shift_down_(size_t index, size_t border)
{
    assert(index >=0 && index<= heap_.size());
    size_t init_pos = index;

    size_t n = border;
    //左儿子
    size_t child = index * 2 + 1;
    while (child < n){
        //选择值较小的子节点
        if (child+1 < n && heap_[child+1] < heap_[child]) child++;
        //当前节点小于字节 停止下沉
        if (heap_[index] < heap_[child]){
            break;
        }
        swap_(index,child);
        index = child;
        child = child * 2 + 1;
    }
    //返回是否进行了下沉
    return index > init_pos;
}
void Timer::swap_(size_t index1, size_t index2)
{
    assert(index1 >= 0 && index1 < heap_.size());
    assert(index2 >= 0 && index2 < heap_.size());

    std::swap(heap_[index1],heap_[index2]);

    //上面交换的是两个timer，修改后heap_[index1]就是之前的heap_[index2]
    timer_ref_[heap_[index1].id] = index1;
    timer_ref_[heap_[index2].id] = index2;

}
}
