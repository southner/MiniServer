#include "mux/mux.h"

#include <assert.h>
#include <fcntl.h>
#include <gtest/gtest.h>
#include <stdio.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <vector>

#include "buffer/buffer.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace MiniServer
{

    class MuxTest : public ::testing::Test
    {
    protected:
        // 初始化数据
        void SetUp() override
        {
            int ans = pipe(pipe_fds);
            assert(ans == 0);

            base_events = EPOLLONESHOT | EPOLLET | EPOLLHUP;
            fd = fopen("../data/test/http/request_get.txt","r");
        }

        // override TearDown 来清理数据
        void TearDown() override
        {
            close(pipe_fds[0]);
            close(pipe_fds[1]);
            fclose(fd);
        }

        const int timeout = 100;
        std::vector<struct epoll_event> events;
        int pipe_fds[2];
        
        FILE* fd;
        Mux mux;
        uint32_t base_events;
    };

    TEST_F(MuxTest, all)
    {   
        //使用epoll监听文件失败
        // mux.add_fd(fd->_fileno, base_events | EPOLLIN);
        // int events_count = mux.wait(timeout);
        // EXPECT_TRUE(events_count > 0);
        // EXPECT_TRUE(mux.get_active_fd(0) == fd->_fileno);
        // EXPECT_TRUE(mux.get_active_events(0) & EPOLLIN);

        //使用管道 从写端写数据 读端接受事件
        // 创建监听事件(可读)
        mux.add_fd(pipe_fds[0], base_events | EPOLLIN);
        write(pipe_fds[1], "hello", 5);
        // 监听可读事件
        int events_count = mux.wait(timeout);

        EXPECT_TRUE(events_count > 0);
        EXPECT_TRUE(mux.get_active_fd(0) == pipe_fds[0]);
        EXPECT_TRUE(mux.get_active_events(0) & EPOLLIN);
    }
}