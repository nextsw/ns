#ifndef TOLERANCE_H
#define TOLERANCE_H
#include <memory>

#include <flutter/foundation.hpp>



class Tolerance {
public:
    static const Tolerance defaultTolerance;

    double distance;

    double time;

    double velocity;


     Tolerance(double distance, double time, double velocity);

    String toString();

private:
    static const double _epsilonDefault;


};

#endif