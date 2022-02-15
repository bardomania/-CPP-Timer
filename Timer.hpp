#pragma once

#include <chrono>
#include <iostream>

class Timer
{
private:
    /* data */
    std::chrono::duration<double> _timer;

    bool _isrunning;
    bool _ispaused;
    bool _haseverbeenpaused;

    std::chrono::_V2::steady_clock::time_point _start;
    std::chrono::_V2::steady_clock::time_point _paused;
    std::chrono::duration<double> _duration;
public:
    // 600 seconds equals to 10mins
    Timer(double seconds = 600);
    ~Timer();

    void Pause();
    void Start();
    std::chrono::duration<double> GetTime();
};