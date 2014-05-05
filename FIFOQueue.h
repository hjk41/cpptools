#pragma once

#include <list>
#include <mutex>
#include <condition_variable>
#include "BoolFlag.h"

template<class T>
class FIFOQueue
{
public:
    explicit FIFOQueue(const BoolFlag * exit_flag) 
        : m_exit(exit_flag)
    {
    }


    void push(const T & e)
    {
        std::lock_guard<std::mutex> lk(m_mutex);
        m_queue.push_back(e);
        if (m_queue.size() == 1)
            m_cv.notify_one();
    }


    T pop()
    {
        std::unique_lock<std::mutex> lk(m_mutex);
        while (m_queue.empty() && !(m_exit->read()))
            m_cv.wait(lk);
        if (!m_queue.empty())
        {
            T rv = m_queue.front();
            m_queue.pop_front();
            return rv;
        }
        else
            return T();
    }


    std::list<T> popAll()
    {
        std::lock_guard<std::mutex> lk(m_mutex);
        std::list<T> rv;
        rv.swap(m_queue);
        return rv;
    }


    void signalForKill()
    {
        assert(m_exit->read());
        std::unique_lock<std::mutex> lk(m_mutex);
        m_cv.notify_all();
    }

private:
    std::list<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_cv;
    const BoolFlag * m_exit;
};
