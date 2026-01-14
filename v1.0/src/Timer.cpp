#include "Timer.h"

Timer::Timer() : name("") {
    reset();
}

Timer::Timer(const std::string &name) : name(name) {
    reset();
}

Timer::~Timer() {
    if (!name.empty()) {
        std::cout << name << " took " << elapsedMilliseconds() << " ms\n";
    }
}

void Timer::reset() {
    start = std::chrono::high_resolution_clock::now();
}

double Timer::elapsedMilliseconds() const {
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(end - start).count();
}
