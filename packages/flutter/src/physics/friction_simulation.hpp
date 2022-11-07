#ifndef FRICTION_SIMULATION_H
#define FRICTION_SIMULATION_H
#include <memory>
#include "tolerance.hpp"

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include "simulation.hpp"



class FrictionSimulation : Simulation {
public:

     FrictionSimulation(double drag, double position, Unknown, double velocity);

    void  through(double endPosition, double endVelocity, double startPosition, double startVelocity);

    double x(double time);

    double dx(double time);

    double finalX();

    double timeAtX(double x);

    bool isDone(double time);

    String toString();

private:
    double _drag;

    double _dragLog;

    double _x;

    double _v;


    static double _dragFor(double endPosition, double endVelocity, double startPosition, double startVelocity);

};

class BoundedFrictionSimulation : FrictionSimulation {
public:

     BoundedFrictionSimulation(double _maxX, double _minX, Unknown, Unknown, Unknown);

    double x(double time);

    bool isDone(double time);

    String toString();

private:
    double _minX;

    double _maxX;


};

#endif