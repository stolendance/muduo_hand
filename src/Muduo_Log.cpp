#include<iostream>
#include"Muduo_Log.h"
#include<thread>
#include<stdio.h>
#include<string>

Muduo_Log::Muduo_Log()
{
    std::thread t([&](){
        for(;;)
        {
            std::string info=read_log();
            // 得到当前的时间  年月日   时分秒
            time_t t;
            time(&t);
            tm* tt=localtime(&t);
            char filename_time[100];
            sprintf(filename_time,"%d-%d-%d",tt->tm_year+1900,tt->tm_mon+1,tt->tm_mday);
            std::string filename="../log/"+std::string(filename_time)+".txt";
            char timestamp[100];
            sprintf(timestamp,"%d:%d:%d",tt->tm_hour,tt->tm_min,tt->tm_sec);
            // 如果文件不存在则创建,如果存在,则追加
            FILE* f=fopen(filename.c_str(),"a");
            // 取出数据,结合时间戳,写入文件
            fprintf(f,"%s \n    %s \n",timestamp,info.c_str());
            fclose(f);
        }
    });
    t.detach();// 转到后台执行
}
std::string Muduo_Log::read_log()
{
    return line.pop();
}
Muduo_Log& Muduo_Log::getInstance()
{
    static Muduo_Log log_ins;
    return log_ins;
}   
void Muduo_Log::log(std::string data)
{
    line.push(data);
}