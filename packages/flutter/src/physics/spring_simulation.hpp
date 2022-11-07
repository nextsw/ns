#ifndef SPRING_SIMULATION_H
#define SPRING_SIMULATION_H
#include <memory>
#include "tolerance.hpp"

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include "simulation.hpp"
#include "utils.hpp"



class SpringDescription {
public:
    double mass;

    double stiffness;

    double damping;


     SpringDescription(double damping, double mass, double stiffness);

    void  withDampingRatio(double mass, double ratio, double stiffness);

    String toString();

private:

};

enum SpringType{
    criticallyDamped,
    underDamped,
    overDamped,
} // end SpringType

class SpringSimulation : Simulation {
public:

     SpringSimulation(double end, SpringDescription spring, double start, Unknown, double velocity);

    SpringType type();

    double x(double time);

    double dx(double time);

    bool isDone(double time);

    String toString();

private:
    double _endPosition;

    _SpringSolution _solution;


};

class ScrollSpringSimulation : SpringSimulation {
public:

     ScrollSpringSimulation(Unknown, Unknown, Unknown, Unknown, Unknown);

    double x(double time);

private:

};

class _SpringSolution {
public:

    double x(double time);

    double dx(double time);

    SpringType type();

private:

     _SpringSolution(double initialPosition, double initialVelocity, SpringDescription spring);

};

#endif