#ifndef PACKAGES_FLUTTER_SRC_GESTURES_VELOCITY_TRACKER
#define PACKAGES_FLUTTER_SRC_GESTURES_VELOCITY_TRACKER
#include <base.hpp>
#include <dart/ui/ui.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "events.hpp"
#include "lsq_solver.hpp"


class VelocityCls : public ObjectCls {
public:
    static Velocity zero;

    Offset pixelsPerSecond;


     VelocityCls(Offset pixelsPerSecond);

    virtual Velocity operator-();

    virtual Velocity operator-(Velocity other);

    virtual Velocity operator+(Velocity other);

    virtual Velocity clampMagnitude(double minValue, double maxValue);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using Velocity = std::shared_ptr<VelocityCls>;

class VelocityEstimateCls : public ObjectCls {
public:
    Offset pixelsPerSecond;

    double confidence;

    Duration duration;

    Offset offset;


     VelocityEstimateCls(double confidence, Duration duration, Offset offset, Offset pixelsPerSecond);

    virtual String toString();

private:

};
using VelocityEstimate = std::shared_ptr<VelocityEstimateCls>;

class _PointAtTimeCls : public ObjectCls {
public:
    Duration time;

    Offset point;


    virtual String toString();

private:

     _PointAtTimeCls(Offset point, Duration time);

};
using _PointAtTime = std::shared_ptr<_PointAtTimeCls>;

class VelocityTrackerCls : public ObjectCls {
public:
    PointerDeviceKind kind;


    virtual void  withKind(PointerDeviceKind kind);
    virtual void addPosition(Duration time, Offset position);

    virtual VelocityEstimate getVelocityEstimate();

    virtual Velocity getVelocity();

private:
    static int _assumePointerMoveStoppedMilliseconds;

    static int _historySize;

    static int _horizonMilliseconds;

    static int _minSampleSize;

    List<_PointAtTime> _samples;

    int _index;


};
using VelocityTracker = std::shared_ptr<VelocityTrackerCls>;

class IOSScrollViewFlingVelocityTrackerCls : public VelocityTrackerCls {
public:

     IOSScrollViewFlingVelocityTrackerCls(Unknown kind);

    virtual void addPosition(Duration time, Offset position);

    virtual VelocityEstimate getVelocityEstimate();

private:
    static int _sampleSize;

    List<_PointAtTime> _touchSamples;


    virtual Offset _previousVelocityAt(int index);

};
using IOSScrollViewFlingVelocityTracker = std::shared_ptr<IOSScrollViewFlingVelocityTrackerCls>;


#endif