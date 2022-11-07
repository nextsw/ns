#ifndef SCROLL_ACTIVITY_H
#define SCROLL_ACTIVITY_H
#include <memory>

#include <async/async.hpp>
#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "scroll_metrics.hpp"
#include "scroll_notification.hpp"



class ScrollActivityDelegate {
public:

    AxisDirection axisDirection();

    double setPixels(double pixels);

    void applyUserOffset(double delta);

    void goIdle();

    void goBallistic(double velocity);

private:

};

class ScrollActivity {
public:

     ScrollActivity(ScrollActivityDelegate _delegate);

    ScrollActivityDelegate delegate();

    void updateDelegate(ScrollActivityDelegate value);

    void resetActivity();

    void dispatchScrollStartNotification(BuildContext context, ScrollMetrics metrics);

    void dispatchScrollUpdateNotification(BuildContext context, ScrollMetrics metrics, double scrollDelta);

    void dispatchOverscrollNotification(BuildContext context, ScrollMetrics metrics, double overscroll);

    void dispatchScrollEndNotification(BuildContext context, ScrollMetrics metrics);

    void applyNewDimensions();

    bool shouldIgnorePointer();

    bool isScrolling();

    double velocity();

    void dispose();

    String toString();

private:
    ScrollActivityDelegate _delegate;


};

class IdleScrollActivity : ScrollActivity {
public:

     IdleScrollActivity(Unknown);

    void applyNewDimensions();

    bool shouldIgnorePointer();

    bool isScrolling();

    double velocity();

private:

};

class ScrollHoldController {
public:

    void cancel();

private:

};

class HoldScrollActivity : ScrollActivity {
public:
    VoidCallback onHoldCanceled;


     HoldScrollActivity(ScrollActivityDelegate delegate, VoidCallback onHoldCanceled);

    bool shouldIgnorePointer();

    bool isScrolling();

    double velocity();

    void cancel();

    void dispose();

private:

};

class ScrollDragController {
public:
    VoidCallback onDragCanceled;

    double carriedVelocity;

    double motionStartDistanceThreshold;

    static const Duration momentumRetainStationaryDurationThreshold;

    static const double momentumRetainVelocityThresholdFactor;

    static const Duration motionStoppedDurationThreshold;


     ScrollDragController(double carriedVelocity, ScrollActivityDelegate delegate, DragStartDetails details, double motionStartDistanceThreshold, VoidCallback onDragCanceled);

    ScrollActivityDelegate delegate();

    void updateDelegate(ScrollActivityDelegate value);

    void update(DragUpdateDetails details);

    void end(DragEndDetails details);

    void cancel();

    void dispose();

    dynamic lastDetails();

    String toString();

private:
    ScrollActivityDelegate _delegate;

    Duration _lastNonStationaryTimestamp;

    bool _retainMomentum;

    double _offsetSinceLastStop;

    static const double _bigThresholdBreakDistance;

    dynamic _lastDetails;


    bool _reversed();

    void _maybeLoseMomentum(double offset, Duration timestamp);

    double _adjustForScrollStartThreshold(double offset, Duration timestamp);

};

class DragScrollActivity : ScrollActivity {
public:

     DragScrollActivity(ScrollDragController controller, Unknown);

    void dispatchScrollStartNotification(BuildContext context, ScrollMetrics metrics);

    void dispatchScrollUpdateNotification(BuildContext context, ScrollMetrics metrics, double scrollDelta);

    void dispatchOverscrollNotification(BuildContext context, ScrollMetrics metrics, double overscroll);

    void dispatchScrollEndNotification(BuildContext context, ScrollMetrics metrics);

    bool shouldIgnorePointer();

    bool isScrolling();

    double velocity();

    void dispose();

    String toString();

private:
    ScrollDragController _controller;


};

class BallisticScrollActivity : ScrollActivity {
public:

     BallisticScrollActivity(Unknown, Simulation simulation, TickerProvider vsync);

    void resetActivity();

    void applyNewDimensions();

    bool applyMoveTo(double value);

    void dispatchOverscrollNotification(BuildContext context, ScrollMetrics metrics, double overscroll);

    bool shouldIgnorePointer();

    bool isScrolling();

    double velocity();

    void dispose();

    String toString();

private:
    AnimationController _controller;


    void _tick();

    void _end();

};

class DrivenScrollActivity : ScrollActivity {
public:

     DrivenScrollActivity(Curve curve, Unknown, Duration duration, double from, double to, TickerProvider vsync);

    Future<void> done();

    void dispatchOverscrollNotification(BuildContext context, ScrollMetrics metrics, double overscroll);

    bool shouldIgnorePointer();

    bool isScrolling();

    double velocity();

    void dispose();

    String toString();

private:
    Completer<void> _completer;

    AnimationController _controller;


    void _tick();

    void _end();

};

#endif