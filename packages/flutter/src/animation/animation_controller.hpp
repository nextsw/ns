#ifndef PACKAGES_FLUTTER_SRC_ANIMATION_ANIMATION_CONTROLLER
#define PACKAGES_FLUTTER_SRC_ANIMATION_ANIMATION_CONTROLLER
#include <base.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "animation.hpp"
#include "curves.hpp"

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "animation.hpp"
#include "curves.hpp"
#include "listener_helpers.hpp"


enum _AnimationDirection{
    forward,
    reverse,
} // end _AnimationDirection
SpringDescription _kFlingSpringDescription;

Tolerance _kFlingTolerance;


enum AnimationBehavior{
    normal,
    preserve,
} // end AnimationBehavior

class AnimationControllerCls : public AnimationCls<double> {
public:
    double lowerBound;

    double upperBound;

    String debugLabel;

    AnimationBehavior animationBehavior;

    Duration duration;

    Duration reverseDuration;


     AnimationControllerCls(AnimationBehavior animationBehavior, String debugLabel, Duration duration, double lowerBound, Duration reverseDuration, double upperBound, double value, TickerProvider vsync);

    virtual void  unbounded(AnimationBehavior animationBehavior, String debugLabel, Duration duration, Duration reverseDuration, double value, TickerProvider vsync);

    virtual Animation<double> view();

    virtual void resync(TickerProvider vsync);

    virtual double value();

    virtual void  value(double newValue);

    virtual void reset();

    virtual double velocity();

    virtual Duration lastElapsedDuration();

    virtual bool isAnimating();

    virtual AnimationStatus status();

    virtual TickerFuture forward(double from);

    virtual TickerFuture reverse(double from);

    virtual TickerFuture animateTo(Curve curve, Duration duration, double target);

    virtual TickerFuture animateBack(Curve curve, Duration duration, double target);

    virtual TickerFuture repeat(double max, double min, Duration period, bool reverse);

    virtual TickerFuture fling(AnimationBehavior animationBehavior, SpringDescription springDescription, double velocity);

    virtual TickerFuture animateWith(Simulation simulation);

    virtual void stop(bool canceled);

    virtual void dispose();

    virtual String toStringDetails();

private:
    Ticker _ticker;

    Simulation _simulation;

    double _value;

    Duration _lastElapsedDuration;

    _AnimationDirection _direction;

    AnimationStatus _status;

    AnimationStatus _lastReportedStatus;


    virtual void _internalSetValue(double newValue);

    virtual TickerFuture _animateToInternal(Curve curve, Duration duration, double target);

    virtual void _directionSetter(_AnimationDirection direction);

    virtual TickerFuture _startSimulation(Simulation simulation);

    virtual void _checkStatusChanged();

    virtual void _tick(Duration elapsed);

};
using AnimationController = std::shared_ptr<AnimationControllerCls>;

class _InterpolationSimulationCls : public SimulationCls {
public:

    virtual double x(double timeInSeconds);

    virtual double dx(double timeInSeconds);

    virtual bool isDone(double timeInSeconds);

private:
    double _durationInSeconds;

    double _begin;

    double _end;

    Curve _curve;


     _InterpolationSimulationCls(double _begin, Curve _curve, double _end, Duration duration, double scale);

};
using _InterpolationSimulation = std::shared_ptr<_InterpolationSimulationCls>;

class _RepeatingSimulationCls : public SimulationCls {
public:
    double min;

    double max;

    bool reverse;

    _DirectionSetter directionSetter;


    virtual double x(double timeInSeconds);

    virtual double dx(double timeInSeconds);

    virtual bool isDone(double timeInSeconds);

private:
    double _periodInSeconds;

    double _initialT;


     _RepeatingSimulationCls(_DirectionSetter directionSetter, double initialValue, double max, double min, Duration period, bool reverse);

};
using _RepeatingSimulation = std::shared_ptr<_RepeatingSimulationCls>;


#endif