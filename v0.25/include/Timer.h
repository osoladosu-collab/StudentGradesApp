#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>
#include <iostream>

class Timer {
public:
    Timer();
    Timer(const std::string &name);
    ~Timer();

    void reset();
    double elapsedMilliseconds() const;

private:
    std::string name;
    std::chrono::high_resolution_clock::time_point start;
};

#endif
