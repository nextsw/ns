#ifndef GRAVITY_SIMULATION_H
#define GRAVITY_SIMULATION_H
#include <memory>

#include <flutter/foundation.hpp>
#include "simulation.hpp"



class GravitySimulation : Simulation {
public:

     GravitySimulation(double acceleration, double distance, double endDistance, double velocity);

    double x(double time);

    double dx(double time);

    bool isDone(double time);

    String toString();

private:
    double _x;

    double _v;

    double _a;

    double _end;


};

#endif