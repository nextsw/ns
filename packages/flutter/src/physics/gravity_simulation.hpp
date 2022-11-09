#ifndef PACKAGES_FLUTTER_SRC_PHYSICS_GRAVITY_SIMULATION
#define PACKAGES_FLUTTER_SRC_PHYSICS_GRAVITY_SIMULATION
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "simulation.hpp"


class GravitySimulationCls : public SimulationCls {
public:

     GravitySimulationCls(double acceleration, double distance, double endDistance, double velocity);

    virtual double x(double time);

    virtual double dx(double time);

    virtual bool isDone(double time);

    virtual String toString();

private:
    double _x;

    double _v;

    double _a;

    double _end;


};
using GravitySimulation = std::shared_ptr<GravitySimulationCls>;


#endif