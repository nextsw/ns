#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DISMISSIBLE
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DISMISSIBLE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/flutter.hpp>
#include "automatic_keep_alive.hpp"
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "gesture_detector.hpp"
#include "ticker_provider.hpp"
#include "transitions.hpp"

Curve _kResizeTimeCurve;

double _kMinFlingVelocity;

double _kMinFlingVelocityDelta;

double _kFlingVelocityScale;

double _kDismissThreshold;


enum DismissDirection{
    vertical,
    horizontal,
    endToStart,
    startToEnd,
    up,
    down,
    none,
} // end DismissDirection

class DismissibleCls : public StatefulWidgetCls {
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


     DismissibleCls(Widget background, HitTestBehavior behavior, Widget child, ConfirmDismissCallback confirmDismiss, double crossAxisEndOffset, DismissDirection direction, Map<DismissDirection, double> dismissThresholds, DragStartBehavior dragStartBehavior, Key key, Duration movementDuration, DismissDirectionCallback onDismissed, VoidCallback onResize, DismissUpdateCallback onUpdate, Duration resizeDuration, Widget secondaryBackground);

    virtual State<Dismissible> createState();

private:

};
using Dismissible = std::shared_ptr<DismissibleCls>;

class DismissUpdateDetailsCls : public ObjectCls {
public:
    DismissDirection direction;

    bool reached;

    bool previousReached;

    double progress;


     DismissUpdateDetailsCls(DismissDirection direction, bool previousReached, double progress, bool reached);
private:

};
using DismissUpdateDetails = std::shared_ptr<DismissUpdateDetailsCls>;

class _DismissibleClipperCls : public CustomClipperCls<Rect> {
public:
    Axis axis;

    Animation<Offset> moveAnimation;


    virtual Rect getClip(Size size);

    virtual Rect getApproximateClipRect(Size size);

    virtual bool shouldReclip(_DismissibleClipper oldClipper);

private:

     _DismissibleClipperCls(Axis axis, Animation<Offset> moveAnimation);

};
using _DismissibleClipper = std::shared_ptr<_DismissibleClipperCls>;

enum _FlingGestureKind{
    none,
    forward,
    reverse,
} // end _FlingGestureKind

class _DismissibleStateCls : public StateCls<Dismissible> {
public:

    virtual void initState();

    virtual bool wantKeepAlive();

    virtual void dispose();

    virtual Widget build(BuildContext context);

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


    virtual bool _directionIsXAxis();

    virtual DismissDirection _extentToDirection(double extent);

    virtual DismissDirection _dismissDirection();

    virtual bool _isActive();

    virtual double _overallDragAxisExtent();

    virtual void _handleDragStart(DragStartDetails details);

    virtual void _handleDragUpdate(DragUpdateDetails details);

    virtual void _handleDismissUpdateValueChanged();

    virtual void _updateMoveAnimation();

    virtual _FlingGestureKind _describeFlingGesture(Velocity velocity);

    virtual void _handleDragEnd(DragEndDetails details);

    virtual Future<void> _handleDismissStatusChanged(AnimationStatus status);

    virtual Future<void> _handleMoveCompleted();

    virtual Future<bool> _confirmStartResizeAnimation();

    virtual void _startResizeAnimation();

    virtual void _handleResizeProgressChanged();

};
using _DismissibleState = std::shared_ptr<_DismissibleStateCls>;


#endif