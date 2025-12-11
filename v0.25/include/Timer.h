#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>
#include <iostream>

class Timer {
private:
    std::chrono::high_resolution_clock::time_point start;
    std::string label;

public:
    Timer(const std::string &lbl = "") : label(lbl) {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        auto end = std::chrono::high_resolution_clock::now();
        long long ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        if (!label.empty())
            std::cout << label << " completed in " << ms << " ms\n";
    }
};

#endif
