#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_OVERSCROLL_INDICATOR
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_OVERSCROLL_INDICATOR
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "media_query.hpp"
#include "notification_listener.hpp"
#include "scroll_notification.hpp"
#include "ticker_provider.hpp"
#include "transitions.hpp"


class GlowingOverscrollIndicatorCls : public StatefulWidgetCls {
public:
    bool showLeading;

    bool showTrailing;

    AxisDirection axisDirection;

    Color color;

    ScrollNotificationPredicate notificationPredicate;

    Widget child;


     GlowingOverscrollIndicatorCls(AxisDirection axisDirection, Widget child, Color color, Key key, ScrollNotificationPredicate notificationPredicate, bool showLeading, bool showTrailing);

    virtual Axis axis();

    virtual State<GlowingOverscrollIndicator> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using GlowingOverscrollIndicator = std::shared_ptr<GlowingOverscrollIndicatorCls>;

class _GlowingOverscrollIndicatorStateCls : public StateCls<GlowingOverscrollIndicator> {
public:

    virtual void initState();

    virtual void didUpdateWidget(GlowingOverscrollIndicator oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    _GlowController _leadingController;

    _GlowController _trailingController;

    Listenable _leadingAndTrailingListener;

    Type _lastNotificationType;

    Map<bool, bool> _accepted;


    virtual bool _handleScrollNotification(ScrollNotification notification);

};
using _GlowingOverscrollIndicatorState = std::shared_ptr<_GlowingOverscrollIndicatorStateCls>;

enum _GlowState{
    idle,
    absorb,
    pull,
    recede,
} // end _GlowState

class _GlowControllerCls : public ChangeNotifierCls {
public:

    virtual Color color();

    virtual void  color(Color value);

    virtual Axis axis();

    virtual void  axis(Axis value);

    virtual void dispose();

    virtual void absorbImpact(double velocity);

    virtual void pull(double overscroll, double extent, double crossAxisOffset, double crossExtent);

    virtual void scrollEnd();

    virtual void paint(Canvas canvas, Size size);

    virtual String toString();

private:
    _GlowState _state;

    AnimationController _glowController;

    Timer _pullRecedeTimer;

    double _paintOffset;

    double _paintOffsetScrollPixels;

    Tween<double> _glowOpacityTween;

    Animation<double> _glowOpacity;

    Tween<double> _glowSizeTween;

    Animation<double> _glowSize;

    Ticker _displacementTicker;

    Duration _displacementTickerLastElapsed;

    double _displacementTarget;

    double _displacement;

    double _pullDistance;

    Color _color;

    Axis _axis;

    static Duration _recedeTime;

    static Duration _pullTime;

    static Duration _pullHoldTime;

    static Duration _pullDecayTime;

    static Duration _crossAxisHalfTime;

    static double _maxOpacity;

    static double _pullOpacityGlowFactor;

    static double _velocityGlowFactor;

    static double _sqrt3;

    static double _widthToHeightFactor;

    static double _minVelocity;

    static double _maxVelocity;


     _GlowControllerCls(Axis axis, Color color, TickerProvider vsync);

    virtual void _changePhase(AnimationStatus status);

    virtual void _recede(Duration duration);

    virtual void _tickDisplacement(Duration elapsed);

};
using _GlowController = std::shared_ptr<_GlowControllerCls>;

class _GlowingOverscrollIndicatorPainterCls : public CustomPainterCls {
public:
    _GlowController leadingController;

    _GlowController trailingController;

    AxisDirection axisDirection;

    static double piOver2;


    virtual void paint(Canvas canvas, Size size);

    virtual bool shouldRepaint(_GlowingOverscrollIndicatorPainter oldDelegate);

    virtual String toString();

private:

     _GlowingOverscrollIndicatorPainterCls(AxisDirection axisDirection, _GlowController leadingController, Unknown repaint, _GlowController trailingController);
    virtual void _paintSide(Canvas canvas, Size size, _GlowController controller, AxisDirection axisDirection, GrowthDirection growthDirection);

};
using _GlowingOverscrollIndicatorPainter = std::shared_ptr<_GlowingOverscrollIndicatorPainterCls>;

class StretchingOverscrollIndicatorCls : public StatefulWidgetCls {
public:
    AxisDirection axisDirection;

    ScrollNotificationPredicate notificationPredicate;

    Clip clipBehavior;

    Widget child;


     StretchingOverscrollIndicatorCls(AxisDirection axisDirection, Widget child, Clip clipBehavior, Key key, ScrollNotificationPredicate notificationPredicate);

    virtual Axis axis();

    virtual State<StretchingOverscrollIndicator> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using StretchingOverscrollIndicator = std::shared_ptr<StretchingOverscrollIndicatorCls>;

class _StretchingOverscrollIndicatorStateCls : public StateCls<StretchingOverscrollIndicator> {
public:

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    _StretchController _stretchController;

    ScrollNotification _lastNotification;

    OverscrollNotification _lastOverscrollNotification;

    bool _accepted;


    virtual bool _handleScrollNotification(ScrollNotification notification);

    virtual AlignmentDirectional _getAlignmentForAxisDirection(double overscroll);

};
using _StretchingOverscrollIndicatorState = std::shared_ptr<_StretchingOverscrollIndicatorStateCls>;

enum _StretchState{
    idle,
    absorb,
    pull,
    recede,
} // end _StretchState

class _StretchControllerCls : public ChangeNotifierCls {
public:

    virtual double pullDistance();

    virtual double value();

    virtual void absorbImpact(double velocity);

    virtual void pull(double normalizedOverscroll);

    virtual void scrollEnd();

    virtual void dispose();

    virtual String toString();

private:
    AnimationController _stretchController;

    Animation<double> _stretchSize;

    Tween<double> _stretchSizeTween;

    _StretchState _state;

    double _pullDistance;

    static double _exponentialScalar;

    static double _stretchIntensity;

    static double _flingFriction;

    static Duration _stretchDuration;


     _StretchControllerCls(TickerProvider vsync);

    virtual void _changePhase(AnimationStatus status);

    virtual void _recede(Duration duration);

};
using _StretchController = std::shared_ptr<_StretchControllerCls>;

class OverscrollIndicatorNotificationCls : public NotificationCls {
public:
    bool leading;

    double paintOffset;

    bool accepted;


     OverscrollIndicatorNotificationCls(bool leading);
    virtual void disallowGlow();

    virtual void disallowIndicator();

    virtual void debugFillDescription(List<String> description);

private:

};
using OverscrollIndicatorNotification = std::shared_ptr<OverscrollIndicatorNotificationCls>;


#endif