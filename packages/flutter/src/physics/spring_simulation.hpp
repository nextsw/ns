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

     SpringSimulationCls(SpringDescription spring, double start, double end, double velocity, Tolerance tolerance);

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

     ScrollSpringSimulationCls(Unknown spring, Unknown start, Unknown end, Unknown velocity, Tolerance tolerance);
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

class _CriticalSolutionCls : public ObjectCls {
public:

    virtual void  withArgs(double r, double c1, double c2);

    virtual double x(double time);

    virtual double dx(double time);

    virtual SpringType type();

private:
    double _r;

    double _c1;

    double _c2;


     _CriticalSolutionCls(SpringDescription spring, double distance, double velocity);

};
using _CriticalSolution = std::shared_ptr<_CriticalSolutionCls>;

class _OverdampedSolutionCls : public ObjectCls {
public:

    virtual void  withArgs(double r1, double r2, double c1, double c2);

    virtual double x(double time);

    virtual double dx(double time);

    virtual SpringType type();

private:
    double _r1;

    double _r2;

    double _c1;

    double _c2;


     _OverdampedSolutionCls(SpringDescription spring, double distance, double velocity);

};
using _OverdampedSolution = std::shared_ptr<_OverdampedSolutionCls>;

class _UnderdampedSolutionCls : public ObjectCls {
public:

    virtual void  withArgs(double w, double r, double c1, double c2);

    virtual double x(double time);

    virtual double dx(double time);

    virtual SpringType type();

private:
    double _w;

    double _r;

    double _c1;

    double _c2;


     _UnderdampedSolutionCls(SpringDescription spring, double distance, double velocity);

};
using _UnderdampedSolution = std::shared_ptr<_UnderdampedSolutionCls>;


#endif