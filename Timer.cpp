/*
** Quentin Félix Project, 2022
** Timer
** File description:
** Timer
*/

#include "Timer.hpp"

Timer::Timer(double seconds)
: _timer {seconds}
, _isrunning {false}
, _ispaused {false}
, _haseverbeenpaused {false}
, _start {std::chrono::seconds::zero()}
, _paused {std::chrono::seconds::zero()}
, _duration {0}
{
}

Timer::~Timer()
{
}

void Timer::Start()
{
    if (!_isrunning) {
        _start = std::chrono::steady_clock::now();
        _isrunning = true;
    }
}

void Timer::Pause()
{
    _haseverbeenpaused = true;
    if (!_ispaused)
        _paused = std::chrono::steady_clock::now();
    else
        _duration += _paused > _start ? _start - _paused : _paused - _start;
    _ispaused = !_ispaused;
}

/**
 * @brief return the timer taking into account Pause
 * 
 * @return std::chrono::duration<double> 
 */
std::chrono::duration<double> Timer::GetTime()
{
    //TODO find a better way to set duration to 0
    std::chrono::duration<double> duration = std::chrono::steady_clock::now() - std::chrono::steady_clock::now();
    if (_isrunning) {
        if (_haseverbeenpaused)
            duration = (_paused - _start - _duration);
        else
            duration = (std::chrono::steady_clock::now() - _start - _duration);
    }
    return _timer - duration;
}

