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

     FrictionSimulationCls(double drag, double position, Unknown tolerance, double velocity);

    virtual void  through(double endPosition, double endVelocity, double startPosition, double startVelocity);

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


    static double _dragFor(double endPosition, double endVelocity, double startPosition, double startVelocity);

};
using FrictionSimulation = std::shared_ptr<FrictionSimulationCls>;

class BoundedFrictionSimulationCls : public FrictionSimulationCls {
public:

     BoundedFrictionSimulationCls(double _maxX, double _minX, Unknown drag, Unknown position, Unknown velocity);

    virtual double x(double time);

    virtual bool isDone(double time);

    virtual String toString();

private:
    double _minX;

    double _maxX;


};
using BoundedFrictionSimulation = std::shared_ptr<BoundedFrictionSimulationCls>;


#endif