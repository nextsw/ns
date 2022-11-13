#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_ACTIVITY
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_ACTIVITY
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "scroll_metrics.hpp"
#include "scroll_notification.hpp"


class ScrollActivityDelegateCls : public ObjectCls {
public:

    virtual AxisDirection axisDirection();
    virtual double setPixels(double pixels);
    virtual void applyUserOffset(double delta);
    virtual void goIdle();
    virtual void goBallistic(double velocity);
private:

};
using ScrollActivityDelegate = std::shared_ptr<ScrollActivityDelegateCls>;

class ScrollActivityCls : public ObjectCls {
public:

     ScrollActivityCls(ScrollActivityDelegate _delegate);
    virtual ScrollActivityDelegate delegate();

    virtual void updateDelegate(ScrollActivityDelegate value);

    virtual void resetActivity();

    virtual void dispatchScrollStartNotification(ScrollMetrics metrics, BuildContext context);

    virtual void dispatchScrollUpdateNotification(ScrollMetrics metrics, BuildContext context, double scrollDelta);

    virtual void dispatchOverscrollNotification(ScrollMetrics metrics, BuildContext context, double overscroll);

    virtual void dispatchScrollEndNotification(ScrollMetrics metrics, BuildContext context);

    virtual void applyNewDimensions();

    virtual bool shouldIgnorePointer();
    virtual bool isScrolling();
    virtual double velocity();
    virtual void dispose();

    virtual String toString();

private:
    ScrollActivityDelegate _delegate;


};
using ScrollActivity = std::shared_ptr<ScrollActivityCls>;

class IdleScrollActivityCls : public ScrollActivityCls {
public:

     IdleScrollActivityCls(ScrollActivityDelegate delegate);
    virtual void applyNewDimensions();

    virtual bool shouldIgnorePointer();

    virtual bool isScrolling();

    virtual double velocity();

private:

};
using IdleScrollActivity = std::shared_ptr<IdleScrollActivityCls>;

class ScrollHoldControllerCls : public ObjectCls {
public:

    virtual void cancel();
private:

};
using ScrollHoldController = std::shared_ptr<ScrollHoldControllerCls>;

class HoldScrollActivityCls : public ScrollActivityCls {
public:
    VoidCallback onHoldCanceled;


     HoldScrollActivityCls(ScrollActivityDelegate delegate, VoidCallback onHoldCanceled);

    virtual bool shouldIgnorePointer();

    virtual bool isScrolling();

    virtual double velocity();

    virtual void cancel();

    virtual void dispose();

private:

};
using HoldScrollActivity = std::shared_ptr<HoldScrollActivityCls>;

class ScrollDragControllerCls : public ObjectCls {
public:
    VoidCallback onDragCanceled;

    double carriedVelocity;

    double motionStartDistanceThreshold;

    static Duration momentumRetainStationaryDurationThreshold;

    static double momentumRetainVelocityThresholdFactor;

    static Duration motionStoppedDurationThreshold;


     ScrollDragControllerCls(double carriedVelocity, ScrollActivityDelegate delegate, DragStartDetails details, double motionStartDistanceThreshold, VoidCallback onDragCanceled);

    virtual ScrollActivityDelegate delegate();

    virtual void updateDelegate(ScrollActivityDelegate value);

    virtual void update(DragUpdateDetails details);

    virtual void end(DragEndDetails details);

    virtual void cancel();

    virtual void dispose();

    virtual Object lastDetails();

    virtual String toString();

private:
    ScrollActivityDelegate _delegate;

    Duration _lastNonStationaryTimestamp;

    bool _retainMomentum;

    double _offsetSinceLastStop;

    static double _bigThresholdBreakDistance;

    Object _lastDetails;


    virtual bool _reversed();

    virtual void _maybeLoseMomentum(double offset, Duration timestamp);

    virtual double _adjustForScrollStartThreshold(double offset, Duration timestamp);

};
using ScrollDragController = std::shared_ptr<ScrollDragControllerCls>;

class DragScrollActivityCls : public ScrollActivityCls {
public:

     DragScrollActivityCls(ScrollActivityDelegate delegate, ScrollDragController controller);

    virtual void dispatchScrollStartNotification(ScrollMetrics metrics, BuildContext context);

    virtual void dispatchScrollUpdateNotification(ScrollMetrics metrics, BuildContext context, double scrollDelta);

    virtual void dispatchOverscrollNotification(ScrollMetrics metrics, BuildContext context, double overscroll);

    virtual void dispatchScrollEndNotification(ScrollMetrics metrics, BuildContext context);

    virtual bool shouldIgnorePointer();

    virtual bool isScrolling();

    virtual double velocity();

    virtual void dispose();

    virtual String toString();

private:
    ScrollDragController _controller;


};
using DragScrollActivity = std::shared_ptr<DragScrollActivityCls>;

class BallisticScrollActivityCls : public ScrollActivityCls {
public:

     BallisticScrollActivityCls(ScrollActivityDelegate delegate, Simulation simulation, TickerProvider vsync);

    virtual void resetActivity();

    virtual void applyNewDimensions();

    virtual bool applyMoveTo(double value);

    virtual void dispatchOverscrollNotification(ScrollMetrics metrics, BuildContext context, double overscroll);

    virtual bool shouldIgnorePointer();

    virtual bool isScrolling();

    virtual double velocity();

    virtual void dispose();

    virtual String toString();

private:
    AnimationController _controller;


    virtual void _tick();

    virtual void _end();

};
using BallisticScrollActivity = std::shared_ptr<BallisticScrollActivityCls>;

class DrivenScrollActivityCls : public ScrollActivityCls {
public:

     DrivenScrollActivityCls(ScrollActivityDelegate delegate, Curve curve, Duration duration, double from, double to, TickerProvider vsync);

    virtual Future<void> done();

    virtual void dispatchOverscrollNotification(ScrollMetrics metrics, BuildContext context, double overscroll);

    virtual bool shouldIgnorePointer();

    virtual bool isScrolling();

    virtual double velocity();

    virtual void dispose();

    virtual String toString();

private:
    Completer<void> _completer;

    AnimationController _controller;


    virtual void _tick();

    virtual void _end();

};
using DrivenScrollActivity = std::shared_ptr<DrivenScrollActivityCls>;


#endif