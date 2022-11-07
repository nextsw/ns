#ifndef ANIMATION_CONTROLLER_H
#define ANIMATION_CONTROLLER_H
#include <memory>
#include <flutter/physics.hpp>
#include <flutter/scheduler.hpp>
#include "animation.hpp"
#include "curves.hpp"

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/physics.hpp>
#include <flutter/scheduler.hpp>
#include <flutter/semantics.hpp>
#include "animation.hpp"
#include "curves.hpp"
#include "listener_helpers.hpp"



enum _AnimationDirection{
    forward,
    reverse,
} // end _AnimationDirection
SpringDescription _kFlingSpringDescription;

const Tolerance _kFlingTolerance;


enum AnimationBehavior{
    normal,
    preserve,
} // end AnimationBehavior

class AnimationController : Animation<double> {
public:
    double lowerBound;

    double upperBound;

    String debugLabel;

    AnimationBehavior animationBehavior;

    Duration duration;

    Duration reverseDuration;


     AnimationController(AnimationBehavior animationBehavior, String debugLabel, Duration duration, double lowerBound, Duration reverseDuration, double upperBound, double value, TickerProvider vsync);

    void  unbounded(AnimationBehavior animationBehavior, String debugLabel, Duration duration, Duration reverseDuration, double value, TickerProvider vsync);

    Animation<double> view();

    void resync(TickerProvider vsync);

    double value();

    void  value(double newValue);

    void reset();

    double velocity();

    Duration lastElapsedDuration();

    bool isAnimating();

    AnimationStatus status();

    TickerFuture forward(double from);

    TickerFuture reverse(double from);

    TickerFuture animateTo(Curve curve, Duration duration, double target);

    TickerFuture animateBack(Curve curve, Duration duration, double target);

    TickerFuture repeat(double max, double min, Duration period, bool reverse);

    TickerFuture fling(AnimationBehavior animationBehavior, SpringDescription springDescription, double velocity);

    TickerFuture animateWith(Simulation simulation);

    void stop(bool canceled);

    void dispose();

    String toStringDetails();

private:
    Ticker _ticker;

    Simulation _simulation;

    double _value;

    Duration _lastElapsedDuration;

    _AnimationDirection _direction;

    AnimationStatus _status;

    AnimationStatus _lastReportedStatus;


    void _internalSetValue(double newValue);

    TickerFuture _animateToInternal(Curve curve, Duration duration, double target);

    void _directionSetter(_AnimationDirection direction);

    TickerFuture _startSimulation(Simulation simulation);

    void _checkStatusChanged();

    void _tick(Duration elapsed);

};

class _InterpolationSimulation : Simulation {
public:

    double x(double timeInSeconds);

    double dx(double timeInSeconds);

    bool isDone(double timeInSeconds);

private:
    double _durationInSeconds;

    double _begin;

    double _end;

    Curve _curve;


     _InterpolationSimulation(double _begin, Curve _curve, double _end, Duration duration, double scale);

};

class _RepeatingSimulation : Simulation {
public:
    double min;

    double max;

    bool reverse;

    _DirectionSetter directionSetter;


    double x(double timeInSeconds);

    double dx(double timeInSeconds);

    bool isDone(double timeInSeconds);

private:
    double _periodInSeconds;

    double _initialT;


     _RepeatingSimulation(_DirectionSetter directionSetter, double initialValue, double max, double min, Duration period, bool reverse);

};

#endif