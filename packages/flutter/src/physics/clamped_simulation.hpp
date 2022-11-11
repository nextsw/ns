#ifndef PACKAGES_FLUTTER_SRC_PHYSICS_CLAMPED_SIMULATION
#define PACKAGES_FLUTTER_SRC_PHYSICS_CLAMPED_SIMULATION
#include <base.hpp>
#include "simulation.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "simulation.hpp"


class ClampedSimulationCls : public SimulationCls {
public:
    Simulation simulation;

    double xMin;

    double xMax;

    double dxMin;

    double dxMax;


     ClampedSimulationCls(Simulation simulation, double dxMax, double dxMin, double xMax, double xMin);

    virtual double x(double time);

    virtual double dx(double time);

    virtual bool isDone(double time);

    virtual String toString();

private:

};
using ClampedSimulation = std::shared_ptr<ClampedSimulationCls>;


#endif