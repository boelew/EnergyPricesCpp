#include "time_utils.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

std::tm *getTimeInHistory(int days)
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm *now_tm = std::localtime(&now_time);
    now_tm->tm_mday -= days;
    std::mktime(now_tm);
    return now_tm;
}

std::tm *getLocalTime()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm *now_tm = std::localtime(&now_time);
    return now_tm;
}

std::tm *setToMidnight(std::tm *time)
{
    time->tm_hour = 0;
    time->tm_min = 0;
    time->tm_sec = 0;
    return time;
}

std::tm *setToEndOfDay(std::tm *time)
{
    time->tm_hour = 23;
    time->tm_min = 59;
    time->tm_sec = 59;
    return time;
}

void printTime(std::tm *time)
{
    int year = time->tm_year + 1900;
    int month = time->tm_mon + 1;
    int day = time->tm_mday;
    int hour = time->tm_hour;
    int min = time->tm_min;
    int sec = time->tm_sec;
    std::cout << "Date: " << year << "-" << month << "-" << day << " " << hour << ":" << min << ":" << sec << std::endl;
}

std::string formatDate(const std::tm &tm)
{
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S+00:00");
    return oss.str();
}