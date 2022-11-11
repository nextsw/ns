#ifndef PACKAGES_FLUTTER_SRC_PHYSICS_FRICTION_SIMULATION
#define PACKAGES_FLUTTER_SRC_PHYSICS_FRICTION_SIMULATION
#include <base.hpp>
#include "tolerance.hpp"

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "simulation.hpp"


class FrictionSimulationCls : public SimulationCls {
public:

     FrictionSimulationCls(double drag, double position, double velocity, Tolerance tolerance);

    virtual void  through(double startPosition, double endPosition, double startVelocity, double endVelocity);

    virtual double x(double time);

    virtual double dx(double time);

    virtual double finalX();

    virtual double timeAtX(double x);

    virtual bool isDone(double time);

    virtual String toString();

private:
    double _drag;

    double _dragLog;

    double _x;

    double _v;


    static double _dragFor(double startPosition, double endPosition, double startVelocity, double endVelocity);

};
using FrictionSimulation = std::shared_ptr<FrictionSimulationCls>;

class BoundedFrictionSimulationCls : public FrictionSimulationCls {
public:

     BoundedFrictionSimulationCls(Unknown drag, Unknown position, Unknown velocity, double _minX, double _maxX);

    virtual double x(double time);

    virtual bool isDone(double time);

    virtual String toString();

private:
    double _minX;

    double _maxX;


};
using BoundedFrictionSimulation = std::shared_ptr<BoundedFrictionSimulationCls>;


#endif