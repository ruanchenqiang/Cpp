#include <algorithm>
#include <atomic>
#include <iostream>
#include <thread>

#include "LogBuffer.h"

std::atomic<uint64_t> g_counter = 0;

void monitor_task()
{
    uint64_t prev = 0;
    uint64_t curr = 0;

    while(1)
    {
        curr = g_counter;
        std::cout << "count=" << curr << " diff=" << (curr - prev) << std::endl;
        prev = curr;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void producer_task(LogBuffer& logbuffer)
{
    std::string test_data = R"({"key": "value"})";

    while(1)
    {
        logbuffer.push(test_data);
        ++g_counter;
    }
}

void consumer_task(LogBuffer& logbuffer)
{
    while(1)
    {
        LogBuffer::Buffer buffer = logbuffer.pop_all();
        
        for(auto& log : buffer)
        {
            for(size_t i = 0; i < 100; ++i)
            {
                std::reverse(log.begin(), log.end());
            }
        }
    }
}

int main()
{
    LogBuffer logbuffer(500000);

    std::thread monitor_thrd(monitor_task);
    monitor_thrd.detach();
    
    std::thread consumer_thrd(consumer_task, std::ref(logbuffer));
    consumer_thrd.detach();

    std::thread producer_thrd(producer_task, std::ref(logbuffer));
    producer_thrd.detach();

    while(1)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}