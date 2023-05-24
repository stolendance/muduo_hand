#include<iostream>
#include"Muduo_Log.h"
#include<unistd.h>
int main()
{
    Muduo_Log& log_ins=Muduo_Log::getInstance();
    log_ins.log("hello world!");
    log_ins.log("muduo_hand, i am coming");
    sleep(1);
}