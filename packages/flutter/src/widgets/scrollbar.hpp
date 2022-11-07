#ifndef SCROLLBAR_H
#define SCROLLBAR_H
#include <memory>

#include <async/async.hpp>
#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include "basic.hpp"
#include "binding.hpp"
#include "framework.hpp"
#include "gesture_detector.hpp"
#include "media_query.hpp"
#include "notification_listener.hpp"
#include "primary_scroll_controller.hpp"
#include "scroll_configuration.hpp"
#include "scroll_controller.hpp"
#include "scroll_metrics.hpp"
#include "scroll_notification.hpp"
#include "scroll_position.hpp"
#include "scrollable.hpp"
#include "ticker_provider.hpp"


const double _kMinThumbExtent;

const double _kMinInteractiveSize;

const double _kScrollbarThickness;

const Duration _kScrollbarFadeDuration;

const Duration _kScrollbarTimeToFade;


enum ScrollbarOrientation{
    left,
    right,
    top,
    bottom,
} // end ScrollbarOrientation

class ScrollbarPainter : ChangeNotifier {
public:
    Animation<double> fadeoutOpacityAnimation;


     ScrollbarPainter(Color color, double crossAxisMargin, Animation<double> fadeoutOpacityAnimation, bool ignorePointer, double mainAxisMargin, double minLength, double minOverscrollLength, EdgeInsets padding, Radius radius, ScrollbarOrientation scrollbarOrientation, OutlinedBorder shape, TextDirection textDirection, double thickness, Color trackBorderColor, Color trackColor, Radius trackRadius);

    Color color();

    void  color(Color value);

    Color trackColor();

    void  trackColor(Color value);

    Color trackBorderColor();

    void  trackBorderColor(Color value);

    Radius trackRadius();

    void  trackRadius(Radius value);

    TextDirection textDirection();

    void  textDirection(TextDirection value);

    double thickness();

    void  thickness(double value);

    double mainAxisMargin();

    void  mainAxisMargin(double value);

    double crossAxisMargin();

    void  crossAxisMargin(double value);

    Radius radius();

    void  radius(Radius value);

    OutlinedBorder shape();

    void  shape(OutlinedBorder value);

    EdgeInsets padding();

    void  padding(EdgeInsets value);

    double minLength();

    void  minLength(double value);

    double minOverscrollLength();

    void  minOverscrollLength(double value);

    ScrollbarOrientation scrollbarOrientation();

    void  scrollbarOrientation(ScrollbarOrientation value);

    bool ignorePointer();

    void  ignorePointer(bool value);

    void update(AxisDirection axisDirection, ScrollMetrics metrics);

    void updateThickness(Radius nextRadius, double nextThickness);

    void dispose();

    double getTrackToScroll(double thumbOffsetLocal);

    void paint(Canvas canvas, Size size);

    bool hitTestInteractive(bool forHover, PointerDeviceKind kind, Offset position);

    bool hitTestOnlyThumbInteractive(PointerDeviceKind kind, Offset position);

    bool hitTest(Offset position);

    bool shouldRepaint(ScrollbarPainter oldDelegate);

    bool shouldRebuildSemantics(CustomPainter oldDelegate);

    SemanticsBuilderCallback semanticsBuilder();

    String toString();

private:
    Color _color;

    Color _trackColor;

    Color _trackBorderColor;

    Radius _trackRadius;

    TextDirection _textDirection;

    double _thickness;

    double _mainAxisMargin;

    double _crossAxisMargin;

    Radius _radius;

    OutlinedBorder _shape;

    EdgeInsets _padding;

    double _minLength;

    double _minOverscrollLength;

    ScrollbarOrientation _scrollbarOrientation;

    bool _ignorePointer;

    ScrollMetrics _lastMetrics;

    AxisDirection _lastAxisDirection;

    Rect _thumbRect;

    Rect _trackRect;

    double _thumbOffset;


    void _debugAssertIsValidOrientation(ScrollbarOrientation orientation);

    bool _isVerticalOrientation(ScrollbarOrientation orientation);

    Paint _paintThumb();

    Paint _paintTrack(bool isBorder);

    void _paintScrollbar(Canvas canvas, AxisDirection direction, Size size, double thumbExtent);

    double _thumbExtent();

    bool _isVertical();

    bool _isReversed();

    double _beforeExtent();

    double _afterExtent();

    double _mainAxisPadding();

    double _trackExtent();

    double _totalContentExtent();

    double _getScrollToTrack(ScrollMetrics metrics, double thumbExtent);

    bool _lastMetricsAreScrollable();

};

class RawScrollbar : StatefulWidget {
public:
    Widget child;

    ScrollController controller;

    bool thumbVisibility;

    bool isAlwaysShown;

    OutlinedBorder shape;

    Radius radius;

    double thickness;

    Color thumbColor;

    double minThumbLength;

    double minOverscrollLength;

    bool trackVisibility;

    Radius trackRadius;

    Color trackColor;

    Color trackBorderColor;

    Duration fadeDuration;

    Duration timeToFade;

    Duration pressDuration;

    ScrollNotificationPredicate notificationPredicate;

    bool interactive;

    ScrollbarOrientation scrollbarOrientation;

    double mainAxisMargin;

    double crossAxisMargin;


     RawScrollbar(Widget child, ScrollController controller, double crossAxisMargin, Duration fadeDuration, bool interactive, bool isAlwaysShown, Unknown, double mainAxisMargin, double minOverscrollLength, double minThumbLength, ScrollNotificationPredicate notificationPredicate, Duration pressDuration, Radius radius, ScrollbarOrientation scrollbarOrientation, OutlinedBorder shape, double thickness, Color thumbColor, bool thumbVisibility, Duration timeToFade, Color trackBorderColor, Color trackColor, Radius trackRadius, bool trackVisibility);

    RawScrollbarState<RawScrollbar> createState();

private:

};

class RawScrollbarState<T extends RawScrollbar> : State<T> {
public:
    ScrollbarPainter scrollbarPainter;


    bool showScrollbar();

    bool enableGestures();

    void initState();

    void didChangeDependencies();

    void updateScrollbarPainter();

    void didUpdateWidget(T oldWidget);

    Axis getScrollbarDirection();

    void handleThumbPress();

    void handleThumbPressStart(Offset localPosition);

    void handleThumbPressUpdate(Offset localPosition);

    void handleThumbPressEnd(Offset localPosition, Velocity velocity);

    bool isPointerOverTrack(PointerDeviceKind kind, Offset position);

    bool isPointerOverThumb(PointerDeviceKind kind, Offset position);

    bool isPointerOverScrollbar(bool forHover, PointerDeviceKind kind, Offset position);

    void handleHover(PointerHoverEvent event);

    void handleHoverExit(PointerExitEvent event);

    void dispose();

    Widget build(BuildContext context);

private:
    Offset _dragScrollbarAxisOffset;

    ScrollController _currentController;

    Timer _fadeoutTimer;

    AnimationController _fadeoutAnimationController;

    Animation<double> _fadeoutOpacityAnimation;

    GlobalKey _scrollbarPainterKey;

    bool _hoverIsActive;


    bool _showTrack();

    bool _debugScheduleCheckHasValidScrollPosition();

    void _validateInteractions(AnimationStatus status);

    bool _debugCheckHasValidScrollPosition();

    void _updateScrollPosition(Offset updatedOffset);

    void _maybeStartFadeoutTimer();

    void _handleTrackTapDown(TapDownDetails details);

    bool _shouldUpdatePainter(Axis notificationAxis);

    bool _handleScrollMetricsNotification(ScrollMetricsNotification notification);

    bool _handleScrollNotification(ScrollNotification notification);

    Map<Type, GestureRecognizerFactory> _gestures();

};

class _ThumbPressGestureRecognizer : LongPressGestureRecognizer {
public:

    bool isPointerAllowed(PointerDownEvent event);

private:
    GlobalKey _customPaintKey;


     _ThumbPressGestureRecognizer(GlobalKey customPaintKey, Object debugOwner, Duration pressDuration);

    bool _hitTestInteractive(GlobalKey customPaintKey, PointerDeviceKind kind, Offset offset);

};

class _TrackTapGestureRecognizer : TapGestureRecognizer {
public:

    bool isPointerAllowed(PointerDownEvent event);

private:
    GlobalKey _customPaintKey;


     _TrackTapGestureRecognizer(GlobalKey customPaintKey, Object debugOwner);

    bool _hitTestInteractive(GlobalKey customPaintKey, PointerDeviceKind kind, Offset offset);

};
Offset _getLocalOffset(Offset position, GlobalKey scrollbarPainterKey);


#endif