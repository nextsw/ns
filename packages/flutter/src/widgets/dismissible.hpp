#ifndef DISMISSIBLE_H
#define DISMISSIBLE_H
#include <memory>

#include <flutter/gestures.hpp>
#include "automatic_keep_alive.hpp"
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "gesture_detector.hpp"
#include "ticker_provider.hpp"
#include "transitions.hpp"


const Curve _kResizeTimeCurve;

const double _kMinFlingVelocity;

const double _kMinFlingVelocityDelta;

const double _kFlingVelocityScale;

const double _kDismissThreshold;


enum DismissDirection{
    vertical,
    horizontal,
    endToStart,
    startToEnd,
    up,
    down,
    none,
} // end DismissDirection

class Dismissible : StatefulWidget {
public:
    Widget child;

    Widget background;

    Widget secondaryBackground;

    ConfirmDismissCallback confirmDismiss;

    VoidCallback onResize;

    DismissDirectionCallback onDismissed;

    DismissDirection direction;

    Duration resizeDuration;

    Map<DismissDirection, double> dismissThresholds;

    Duration movementDuration;

    double crossAxisEndOffset;

    DragStartBehavior dragStartBehavior;

    HitTestBehavior behavior;

    DismissUpdateCallback onUpdate;


     Dismissible(Widget background, HitTestBehavior behavior, Widget child, ConfirmDismissCallback confirmDismiss, double crossAxisEndOffset, DismissDirection direction, Map<DismissDirection, double> dismissThresholds, DragStartBehavior dragStartBehavior, Key key, Duration movementDuration, DismissDirectionCallback onDismissed, VoidCallback onResize, DismissUpdateCallback onUpdate, Duration resizeDuration, Widget secondaryBackground);

    State<Dismissible> createState();

private:

};

class DismissUpdateDetails {
public:
    DismissDirection direction;

    bool reached;

    bool previousReached;

    double progress;


     DismissUpdateDetails(DismissDirection direction, bool previousReached, double progress, bool reached);

private:

};

class _DismissibleClipper : CustomClipper<Rect> {
public:
    Axis axis;

    Animation<Offset> moveAnimation;


    Rect getClip(Size size);

    Rect getApproximateClipRect(Size size);

    bool shouldReclip(_DismissibleClipper oldClipper);

private:

     _DismissibleClipper(Axis axis, Animation<Offset> moveAnimation);

};

enum _FlingGestureKind{
    none,
    forward,
    reverse,
} // end _FlingGestureKind

class _DismissibleState : State<Dismissible> {
public:

    void initState();

    bool wantKeepAlive();

    void dispose();

    Widget build(BuildContext context);

private:
    AnimationController _moveController;

    Animation<Offset> _moveAnimation;

    AnimationController _resizeController;

    Animation<double> _resizeAnimation;

    double _dragExtent;

    bool _confirming;

    bool _dragUnderway;

    Size _sizePriorToCollapse;

    bool _dismissThresholdReached;


    bool _directionIsXAxis();

    DismissDirection _extentToDirection(double extent);

    DismissDirection _dismissDirection();

    bool _isActive();

    double _overallDragAxisExtent();

    void _handleDragStart(DragStartDetails details);

    void _handleDragUpdate(DragUpdateDetails details);

    void _handleDismissUpdateValueChanged();

    void _updateMoveAnimation();

    _FlingGestureKind _describeFlingGesture(Velocity velocity);

    void _handleDragEnd(DragEndDetails details);

    Future<void> _handleDismissStatusChanged(AnimationStatus status);

    Future<void> _handleMoveCompleted();

    Future<bool> _confirmStartResizeAnimation();

    void _startResizeAnimation();

    void _handleResizeProgressChanged();

};

#endif