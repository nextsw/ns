#ifndef SCROLL_SIMULATION_H
#define SCROLL_SIMULATION_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include <flutter/physics.hpp>



class BouncingScrollSimulation : Simulation {
public:
    static const double maxSpringTransferVelocity;

    double leadingExtent;

    double trailingExtent;

    SpringDescription spring;


     BouncingScrollSimulation(double leadingExtent, double position, SpringDescription spring, Unknown, double trailingExtent, double velocity);

    double x(double time);

    double dx(double time);

    bool isDone(double time);

    String toString();

private:
    FrictionSimulation _frictionSimulation;

    Simulation _springSimulation;

    double _springTime;

    double _timeOffset;


    Simulation _underscrollSimulation(double dx, double x);

    Simulation _overscrollSimulation(double dx, double x);

    Simulation _simulation(double time);

};

class ClampingScrollSimulation : Simulation {
public:
    double position;

    double velocity;

    double friction;


     ClampingScrollSimulation(double friction, double position, Unknown, double velocity);

    double x(double time);

    double dx(double time);

    bool isDone(double time);

private:
    double _duration;

    double _distance;

    static double _kDecelerationRate;

    static const double _initialVelocityPenetration;


    static double _decelerationForFriction(double friction);

    double _flingDuration(double velocity);

    static double _flingDistancePenetration(double t);

    static double _flingVelocityPenetration(double t);

};

#endif