#pragma once
#include <chrono>

class Timer {
    using clock = std::chrono::high_resolution_clock;
    std::chrono::time_point<clock> start_time;

public:
    void start() { start_time = clock::now(); }

    double elapsedSeconds() const {
        auto end_time = clock::now();
        std::chrono::duration<double> diff = end_time - start_time;
        return diff.count();
    }
};
