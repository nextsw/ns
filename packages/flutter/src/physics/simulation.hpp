#ifndef PACKAGES_FLUTTER_SRC_PHYSICS_SIMULATION
#define PACKAGES_FLUTTER_SRC_PHYSICS_SIMULATION
#include <base.hpp>
#include "tolerance.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "tolerance.hpp"


class SimulationCls : public ObjectCls {
public:
    Tolerance tolerance;


     SimulationCls(Tolerance tolerance);
    virtual double x(double time);
    virtual double dx(double time);
    virtual bool isDone(double time);
    virtual String toString();

private:

};
using Simulation = std::shared_ptr<SimulationCls>;


#endif