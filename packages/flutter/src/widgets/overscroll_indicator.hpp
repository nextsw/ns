#ifndef OVERSCROLL_INDICATOR_H
#define OVERSCROLL_INDICATOR_H
#include <memory>

#include <async/async.hpp>
#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include <flutter/physics.hpp>
#include <flutter/rendering.hpp>
#include <flutter/scheduler.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "media_query.hpp"
#include "notification_listener.hpp"
#include "scroll_notification.hpp"
#include "ticker_provider.hpp"
#include "transitions.hpp"



class GlowingOverscrollIndicator : StatefulWidget {
public:
    bool showLeading;

    bool showTrailing;

    AxisDirection axisDirection;

    Color color;

    ScrollNotificationPredicate notificationPredicate;

    Widget child;


     GlowingOverscrollIndicator(AxisDirection axisDirection, Widget child, Color color, Unknown, ScrollNotificationPredicate notificationPredicate, bool showLeading, bool showTrailing);

    Axis axis();

    State<GlowingOverscrollIndicator> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _GlowingOverscrollIndicatorState : State<GlowingOverscrollIndicator> {
public:

    void initState();

    void didUpdateWidget(GlowingOverscrollIndicator oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:
    _GlowController _leadingController;

    _GlowController _trailingController;

    Listenable _leadingAndTrailingListener;

    Type _lastNotificationType;

    Map<bool, bool> _accepted;


    bool _handleScrollNotification(ScrollNotification notification);

};

enum _GlowState{
    idle,
    absorb,
    pull,
    recede,
} // end _GlowState

class _GlowController : ChangeNotifier {
public:

    Color color();

    void  color(Color value);

    Axis axis();

    void  axis(Axis value);

    void dispose();

    void absorbImpact(double velocity);

    void pull(double crossAxisOffset, double crossExtent, double extent, double overscroll);

    void scrollEnd();

    void paint(Canvas canvas, Size size);

    String toString();

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

    static const Duration _recedeTime;

    static const Duration _pullTime;

    static const Duration _pullHoldTime;

    static const Duration _pullDecayTime;

    static Duration _crossAxisHalfTime;

    static const double _maxOpacity;

    static const double _pullOpacityGlowFactor;

    static const double _velocityGlowFactor;

    static const double _sqrt3;

    static const double _widthToHeightFactor;

    static const double _minVelocity;

    static const double _maxVelocity;


     _GlowController(Axis axis, Color color, TickerProvider vsync);

    void _changePhase(AnimationStatus status);

    void _recede(Duration duration);

    void _tickDisplacement(Duration elapsed);

};

class _GlowingOverscrollIndicatorPainter : CustomPainter {
public:
    _GlowController leadingController;

    _GlowController trailingController;

    AxisDirection axisDirection;

    static const double piOver2;


    void paint(Canvas canvas, Size size);

    bool shouldRepaint(_GlowingOverscrollIndicatorPainter oldDelegate);

    String toString();

private:

     _GlowingOverscrollIndicatorPainter(AxisDirection axisDirection, _GlowController leadingController, Unknown, _GlowController trailingController);

    void _paintSide(AxisDirection axisDirection, Canvas canvas, _GlowController controller, GrowthDirection growthDirection, Size size);

};

class StretchingOverscrollIndicator : StatefulWidget {
public:
    AxisDirection axisDirection;

    ScrollNotificationPredicate notificationPredicate;

    Clip clipBehavior;

    Widget child;


     StretchingOverscrollIndicator(AxisDirection axisDirection, Widget child, Clip clipBehavior, Unknown, ScrollNotificationPredicate notificationPredicate);

    Axis axis();

    State<StretchingOverscrollIndicator> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _StretchingOverscrollIndicatorState : State<StretchingOverscrollIndicator> {
public:

    void dispose();

    Widget build(BuildContext context);

private:
    _StretchController _stretchController;

    ScrollNotification _lastNotification;

    OverscrollNotification _lastOverscrollNotification;

    bool _accepted;


    bool _handleScrollNotification(ScrollNotification notification);

    AlignmentDirectional _getAlignmentForAxisDirection(double overscroll);

};

enum _StretchState{
    idle,
    absorb,
    pull,
    recede,
} // end _StretchState

class _StretchController : ChangeNotifier {
public:

    double pullDistance();

    double value();

    void absorbImpact(double velocity);

    void pull(double normalizedOverscroll);

    void scrollEnd();

    void dispose();

    String toString();

private:
    AnimationController _stretchController;

    Animation<double> _stretchSize;

    Tween<double> _stretchSizeTween;

    _StretchState _state;

    double _pullDistance;

    static const double _exponentialScalar;

    static const double _stretchIntensity;

    static const double _flingFriction;

    static const Duration _stretchDuration;


     _StretchController(TickerProvider vsync);

    void _changePhase(AnimationStatus status);

    void _recede(Duration duration);

};

class OverscrollIndicatorNotification : Notification {
public:
    bool leading;

    double paintOffset;

    bool accepted;


     OverscrollIndicatorNotification(bool leading);

    void disallowGlow();

    void disallowIndicator();

    void debugFillDescription(List<String> description);

private:

};

#endif