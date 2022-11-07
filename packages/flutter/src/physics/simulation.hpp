#ifndef SIMULATION_H
#define SIMULATION_H
#include <memory>
#include "tolerance.hpp"

#include <flutter/foundation.hpp>
#include "tolerance.hpp"



class Simulation {
public:
    Tolerance tolerance;


     Simulation(Tolerance tolerance);

    double x(double time);

    double dx(double time);

    bool isDone(double time);

    String toString();

private:

};

#endif