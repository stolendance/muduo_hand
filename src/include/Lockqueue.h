#include<iostream>
#include<queue>
#include<mutex>
#include<condition_variable>
template<typename T>
class Lockqueue
{
public:
    T pop()
    {
        std::unique_lock<std::mutex> lock(mt);
        while(line.empty())
        {
            cont.wait(lock);
        }
        T data=line.front();
        line.pop();
        return data;

    }
    void push(T data)
    {
        std::lock_guard<std::mutex> lock(mt);
        line.push(data);
        // 唤醒条件变量
        cont.notify_all();
    }
private:
    std::queue<T> line;
    std::mutex mt;
    std::condition_variable cont;
};