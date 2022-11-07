#ifndef VELOCITY_TRACKER_H
#define VELOCITY_TRACKER_H
#include <memory>
#include <ui.hpp>

#include <flutter/foundation.hpp>
#include "events.hpp"
#include "lsq_solver.hpp"



class Velocity {
public:
    static const Velocity zero;

    Offset pixelsPerSecond;


     Velocity(Offset pixelsPerSecond);

    Velocity -();

    Velocity -(Velocity other);

    Velocity +(Velocity other);

    Velocity clampMagnitude(double maxValue, double minValue);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class VelocityEstimate {
public:
    Offset pixelsPerSecond;

    double confidence;

    Duration duration;

    Offset offset;


     VelocityEstimate(double confidence, Duration duration, Offset offset, Offset pixelsPerSecond);

    String toString();

private:

};

class _PointAtTime {
public:
    Duration time;

    Offset point;


    String toString();

private:

     _PointAtTime(Offset point, Duration time);

};

class VelocityTracker {
public:
    PointerDeviceKind kind;


    void  withKind(PointerDeviceKind kind);

    void addPosition(Offset position, Duration time);

    VelocityEstimate getVelocityEstimate();

    Velocity getVelocity();

private:
    static const int _assumePointerMoveStoppedMilliseconds;

    static const int _historySize;

    static const int _horizonMilliseconds;

    static const int _minSampleSize;

    List<_PointAtTime> _samples;

    int _index;


};

class IOSScrollViewFlingVelocityTracker : VelocityTracker {
public:

     IOSScrollViewFlingVelocityTracker(Unknown);

    void addPosition(Offset position, Duration time);

    VelocityEstimate getVelocityEstimate();

private:
    static const int _sampleSize;

    List<_PointAtTime> _touchSamples;


    Offset _previousVelocityAt(int index);

};

#endif