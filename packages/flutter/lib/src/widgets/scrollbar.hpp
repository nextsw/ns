#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLLBAR
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLLBAR
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
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

double _kMinThumbExtent;

double _kMinInteractiveSize;

double _kScrollbarThickness;

Duration _kScrollbarFadeDuration;

Duration _kScrollbarTimeToFade;


enum ScrollbarOrientation{
    left,
    right,
    top,
    bottom,
} // end ScrollbarOrientation

class ScrollbarPainterCls : public ChangeNotifierCls {
public:
    Animation<double> fadeoutOpacityAnimation;


     ScrollbarPainterCls(Color color, double crossAxisMargin, Animation<double> fadeoutOpacityAnimation, bool ignorePointer, double mainAxisMargin, double minLength, double minOverscrollLength, EdgeInsets padding, Radius radius, ScrollbarOrientation scrollbarOrientation, OutlinedBorder shape, TextDirection textDirection, double thickness, Color trackBorderColor, Color trackColor, Radius trackRadius);

    virtual Color color();

    virtual void  color(Color value);

    virtual Color trackColor();

    virtual void  trackColor(Color value);

    virtual Color trackBorderColor();

    virtual void  trackBorderColor(Color value);

    virtual Radius trackRadius();

    virtual void  trackRadius(Radius value);

    virtual TextDirection textDirection();

    virtual void  textDirection(TextDirection value);

    virtual double thickness();

    virtual void  thickness(double value);

    virtual double mainAxisMargin();

    virtual void  mainAxisMargin(double value);

    virtual double crossAxisMargin();

    virtual void  crossAxisMargin(double value);

    virtual Radius radius();

    virtual void  radius(Radius value);

    virtual OutlinedBorder shape();

    virtual void  shape(OutlinedBorder value);

    virtual EdgeInsets padding();

    virtual void  padding(EdgeInsets value);

    virtual double minLength();

    virtual void  minLength(double value);

    virtual double minOverscrollLength();

    virtual void  minOverscrollLength(double value);

    virtual ScrollbarOrientation scrollbarOrientation();

    virtual void  scrollbarOrientation(ScrollbarOrientation value);

    virtual bool ignorePointer();

    virtual void  ignorePointer(bool value);

    virtual void update(AxisDirection axisDirection, ScrollMetrics metrics);

    virtual void updateThickness(Radius nextRadius, double nextThickness);

    virtual void dispose();

    virtual double getTrackToScroll(double thumbOffsetLocal);

    virtual void paint(Canvas canvas, Size size);

    virtual bool hitTestInteractive(bool forHover, PointerDeviceKind kind, Offset position);

    virtual bool hitTestOnlyThumbInteractive(PointerDeviceKind kind, Offset position);

    virtual bool hitTest(Offset position);

    virtual bool shouldRepaint(ScrollbarPainter oldDelegate);

    virtual bool shouldRebuildSemantics(CustomPainter oldDelegate);

    virtual SemanticsBuilderCallback semanticsBuilder();

    virtual String toString();

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


    virtual void _debugAssertIsValidOrientation(ScrollbarOrientation orientation);

    virtual bool _isVerticalOrientation(ScrollbarOrientation orientation);

    virtual Paint _paintThumb();

    virtual Paint _paintTrack(bool isBorder);

    virtual void _paintScrollbar(Canvas canvas, AxisDirection direction, Size size, double thumbExtent);

    virtual double _thumbExtent();

    virtual bool _isVertical();

    virtual bool _isReversed();

    virtual double _beforeExtent();

    virtual double _afterExtent();

    virtual double _mainAxisPadding();

    virtual double _trackExtent();

    virtual double _totalContentExtent();

    virtual double _getScrollToTrack(ScrollMetrics metrics, double thumbExtent);

    virtual bool _lastMetricsAreScrollable();

};
using ScrollbarPainter = std::shared_ptr<ScrollbarPainterCls>;

class RawScrollbarCls : public StatefulWidgetCls {
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


     RawScrollbarCls(Widget child, ScrollController controller, double crossAxisMargin, Duration fadeDuration, bool interactive, bool isAlwaysShown, Unknown key, double mainAxisMargin, double minOverscrollLength, double minThumbLength, ScrollNotificationPredicate notificationPredicate, Duration pressDuration, Radius radius, ScrollbarOrientation scrollbarOrientation, OutlinedBorder shape, double thickness, Color thumbColor, bool thumbVisibility, Duration timeToFade, Color trackBorderColor, Color trackColor, Radius trackRadius, bool trackVisibility);

    virtual RawScrollbarState<RawScrollbar> createState();

private:

};
using RawScrollbar = std::shared_ptr<RawScrollbarCls>;

template<typename T : RawScrollbar> class RawScrollbarStateCls : public StateCls<T> {
public:
    ScrollbarPainter scrollbarPainter;


    virtual bool showScrollbar();

    virtual bool enableGestures();

    virtual void initState();

    virtual void didChangeDependencies();

    virtual void updateScrollbarPainter();

    virtual void didUpdateWidget(T oldWidget);

    virtual Axis getScrollbarDirection();

    virtual void handleThumbPress();

    virtual void handleThumbPressStart(Offset localPosition);

    virtual void handleThumbPressUpdate(Offset localPosition);

    virtual void handleThumbPressEnd(Offset localPosition, Velocity velocity);

    virtual bool isPointerOverTrack(PointerDeviceKind kind, Offset position);

    virtual bool isPointerOverThumb(PointerDeviceKind kind, Offset position);

    virtual bool isPointerOverScrollbar(bool forHover, PointerDeviceKind kind, Offset position);

    virtual void handleHover(PointerHoverEvent event);

    virtual void handleHoverExit(PointerExitEvent event);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    Offset _dragScrollbarAxisOffset;

    ScrollController _currentController;

    Timer _fadeoutTimer;

    AnimationController _fadeoutAnimationController;

    Animation<double> _fadeoutOpacityAnimation;

    GlobalKey _scrollbarPainterKey;

    bool _hoverIsActive;


    virtual bool _showTrack();

    virtual bool _debugScheduleCheckHasValidScrollPosition();

    virtual void _validateInteractions(AnimationStatus status);

    virtual bool _debugCheckHasValidScrollPosition();

    virtual void _updateScrollPosition(Offset updatedOffset);

    virtual void _maybeStartFadeoutTimer();

    virtual void _handleTrackTapDown(TapDownDetails details);

    virtual bool _shouldUpdatePainter(Axis notificationAxis);

    virtual bool _handleScrollMetricsNotification(ScrollMetricsNotification notification);

    virtual bool _handleScrollNotification(ScrollNotification notification);

    virtual Map<Type, GestureRecognizerFactory> _gestures();

};
template<typename T : RawScrollbar> using RawScrollbarState = std::shared_ptr<RawScrollbarStateCls<T : RawScrollbar>>;

class _ThumbPressGestureRecognizerCls : public LongPressGestureRecognizerCls {
public:

    virtual bool isPointerAllowed(PointerDownEvent event);

private:
    GlobalKey _customPaintKey;


     _ThumbPressGestureRecognizerCls(GlobalKey customPaintKey, Object debugOwner, Duration pressDuration);

    virtual bool _hitTestInteractive(GlobalKey customPaintKey, PointerDeviceKind kind, Offset offset);

};
using _ThumbPressGestureRecognizer = std::shared_ptr<_ThumbPressGestureRecognizerCls>;

class _TrackTapGestureRecognizerCls : public TapGestureRecognizerCls {
public:

    virtual bool isPointerAllowed(PointerDownEvent event);

private:
    GlobalKey _customPaintKey;


     _TrackTapGestureRecognizerCls(GlobalKey customPaintKey, Object debugOwner);

    virtual bool _hitTestInteractive(GlobalKey customPaintKey, PointerDeviceKind kind, Offset offset);

};
using _TrackTapGestureRecognizer = std::shared_ptr<_TrackTapGestureRecognizerCls>;
Offset _getLocalOffset(Offset position, GlobalKey scrollbarPainterKey);



#endif