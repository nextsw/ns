#ifndef PACKAGES_FLUTTER_SRC_PHYSICS_SPRING_SIMULATION
#define PACKAGES_FLUTTER_SRC_PHYSICS_SPRING_SIMULATION
#include <base.hpp>
#include "tolerance.hpp"

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "simulation.hpp"
#include "utils.hpp"


class SpringDescriptionCls : public ObjectCls {
public:
    double mass;

    double stiffness;

    double damping;


     SpringDescriptionCls(double damping, double mass, double stiffness);
    virtual void  withDampingRatio(double mass, double ratio, double stiffness);

    virtual String toString();

private:

};
using SpringDescription = std::shared_ptr<SpringDescriptionCls>;

enum SpringType{
    criticallyDamped,
    underDamped,
    overDamped,
} // end SpringType

class SpringSimulationCls : public SimulationCls {
public:

     SpringSimulationCls(SpringDescription spring, double start, double end, double velocity, Unknown tolerance);

    virtual SpringType type();

    virtual double x(double time);

    virtual double dx(double time);

    virtual bool isDone(double time);

    virtual String toString();

private:
    double _endPosition;

    _SpringSolution _solution;


};
using SpringSimulation = std::shared_ptr<SpringSimulationCls>;

class ScrollSpringSimulationCls : public SpringSimulationCls {
public:

     ScrollSpringSimulationCls(Unknown spring, Unknown start, Unknown end, Unknown velocity, Unknown tolerance);
    virtual double x(double time);

private:

};
using ScrollSpringSimulation = std::shared_ptr<ScrollSpringSimulationCls>;

class _SpringSolutionCls : public ObjectCls {
public:

    virtual double x(double time);
    virtual double dx(double time);
    virtual SpringType type();
private:

     _SpringSolutionCls(SpringDescription spring, double initialPosition, double initialVelocity);

};
using _SpringSolution = std::shared_ptr<_SpringSolutionCls>;


#endif