#include "Timer.hpp"

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int main(int argc, char const *argv[])
{
    Timer timer;

    std::cout << timer.GetTime().count() << std::endl;
    timer.Start();
    fib(42);
    std::cout << timer.GetTime().count() << std::endl;
    timer.Pause();
    fib(42);
    fib(42);
    fib(42);
    std::cout << timer.GetTime().count() << std::endl;
    timer.Pause();
    fib(42);
    fib(42);
    std::cout << timer.GetTime().count() << std::endl;
    return 0;
}
