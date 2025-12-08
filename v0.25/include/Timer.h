#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
private:
    std::chrono::high_resolution_clock::time_point start;

public:
    void reset();
    double elapsed() const;
};

#endif
