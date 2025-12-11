#include "Timer.h"

void Timer::start() {
    startTime = std::chrono::high_resolution_clock::now();
}

double Timer::stop() {
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - startTime;
    return elapsed.count();
}
