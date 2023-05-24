// 单例模式
// 一个线程持续读并写入磁盘, 在没有数据的时候阻塞住
// 创建一个线程安全的队列
#include<string>
#include"Lockqueue.h"
class Muduo_Log
{
public:
    static Muduo_Log& getInstance();
    void log(std::string data);
private:
    std::string read_log();
    Lockqueue<std::string> line;
    Muduo_Log();
    Muduo_Log& operator=(const Muduo_Log&) =delete;
    Muduo_Log(const Muduo_Log&) =delete;
    Muduo_Log(const Muduo_Log&&) =delete;
};