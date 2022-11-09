#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_SIMULATION
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_SIMULATION
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>


class BouncingScrollSimulationCls : public SimulationCls {
public:
    static double maxSpringTransferVelocity;

    double leadingExtent;

    double trailingExtent;

    SpringDescription spring;


     BouncingScrollSimulationCls(double leadingExtent, double position, SpringDescription spring, Unknown tolerance, double trailingExtent, double velocity);

    virtual double x(double time);

    virtual double dx(double time);

    virtual bool isDone(double time);

    virtual String toString();

private:
    FrictionSimulation _frictionSimulation;

    Simulation _springSimulation;

    double _springTime;

    double _timeOffset;


    virtual Simulation _underscrollSimulation(double dx, double x);

    virtual Simulation _overscrollSimulation(double dx, double x);

    virtual Simulation _simulation(double time);

};
using BouncingScrollSimulation = std::shared_ptr<BouncingScrollSimulationCls>;

class ClampingScrollSimulationCls : public SimulationCls {
public:
    double position;

    double velocity;

    double friction;


     ClampingScrollSimulationCls(double friction, double position, Unknown tolerance, double velocity);

    virtual double x(double time);

    virtual double dx(double time);

    virtual bool isDone(double time);

private:
    double _duration;

    double _distance;

    static double _kDecelerationRate;

    static double _initialVelocityPenetration;


    static double _decelerationForFriction(double friction);

    virtual double _flingDuration(double velocity);

    static double _flingDistancePenetration(double t);

    static double _flingVelocityPenetration(double t);

};
using ClampingScrollSimulation = std::shared_ptr<ClampingScrollSimulationCls>;


#endif