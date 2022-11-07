#ifndef CLAMPED_SIMULATION_H
#define CLAMPED_SIMULATION_H
#include <memory>
#include "simulation.hpp"

#include <flutter/foundation.hpp>
#include "simulation.hpp"



class ClampedSimulation : Simulation {
public:
    Simulation simulation;

    double xMin;

    double xMax;

    double dxMin;

    double dxMax;


     ClampedSimulation(double dxMax, double dxMin, Simulation simulation, double xMax, double xMin);

    double x(double time);

    double dx(double time);

    bool isDone(double time);

    String toString();

private:

};

#endif