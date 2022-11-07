#include "stopwatch.hpp"
Stopwatch::Stopwatch() {
    {
        _frequency;
    }
}

int Stopwatch::frequency() {
    return _frequency;
}

void Stopwatch::start() {
    int stop = _stop;
    if (stop != nullptr) {
        _start = _now() - stop;
        _stop = nullptr;
    }
}

void Stopwatch::stop() {
    _stop = _now();
}

void Stopwatch::reset() {
    _start = _stop ?? _now();
}

int Stopwatch::elapsedTicks() {
    return (_stop ?? _now()) - _start;
}

Duration Stopwatch::elapsed() {
    return Duration(elapsedMicroseconds);
}

bool Stopwatch::isRunning() {
    return _stop == nullptr;
}
