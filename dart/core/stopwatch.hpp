#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <memory>




class Stopwatch {
public:

     Stopwatch();

    int frequency();

    void start();

    void stop();

    void reset();

    int elapsedTicks();

    Duration elapsed();

    external int elapsedMicroseconds();

    external int elapsedMilliseconds();

    bool isRunning();

private:
    static int _frequency;

    int _start;

    int _stop;


    external static int _initTicker();

    external static int _now();

};

#endif