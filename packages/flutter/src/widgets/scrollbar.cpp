#include "scrollbar.hpp"
ScrollbarPainter::ScrollbarPainter(Color color, double crossAxisMargin, Animation<double> fadeoutOpacityAnimation, bool ignorePointer, double mainAxisMargin, double minLength, double minOverscrollLength, EdgeInsets padding, Radius radius, ScrollbarOrientation scrollbarOrientation, OutlinedBorder shape, TextDirection textDirection, double thickness, Color trackBorderColor, Color trackColor, Radius trackRadius) {
    {
        assert(color != nullptr);
        assert(radius == nullptr || shape == nullptr);
        assert(thickness != nullptr);
        assert(fadeoutOpacityAnimation != nullptr);
        assert(mainAxisMargin != nullptr);
        assert(crossAxisMargin != nullptr);
        assert(minLength != nullptr);
        assert(minLength >= 0);
        assert(minOverscrollLength == nullptr || minOverscrollLength <= minLength);
        assert(minOverscrollLength == nullptr || minOverscrollLength >= 0);
        assert(padding != nullptr);
        assert(padding.isNonNegative);
        assert(trackColor != nullptr);
        assert(trackBorderColor != nullptr);
        assert(ignorePointer != nullptr);
        _color = color;
        _textDirection = textDirection;
        _thickness = thickness;
        _radius = radius;
        _shape = shape;
        _padding = padding;
        _mainAxisMargin = mainAxisMargin;
        _crossAxisMargin = crossAxisMargin;
        _minLength = minLength;
        _trackColor = trackColor;
        _trackBorderColor = trackBorderColor;
        _trackRadius = trackRadius;
        _scrollbarOrientation = scrollbarOrientation;
        _minOverscrollLength = minOverscrollLength ?? minLength;
        _ignorePointer = ignorePointer;
    }
    {
        fadeoutOpacityAnimation.addListener(notifyListeners);
    }
}

Color ScrollbarPainter::color() {
    return _color;
}

void ScrollbarPainter::color(Color value) {
    assert(value != nullptr);
    if (color == value) {
        return;
    }
    _color = value;
    notifyListeners();
}

Color ScrollbarPainter::trackColor() {
    return _trackColor;
}

void ScrollbarPainter::trackColor(Color value) {
    assert(value != nullptr);
    if (trackColor == value) {
        return;
    }
    _trackColor = value;
    notifyListeners();
}

Color ScrollbarPainter::trackBorderColor() {
    return _trackBorderColor;
}

void ScrollbarPainter::trackBorderColor(Color value) {
    assert(value != nullptr);
    if (trackBorderColor == value) {
        return;
    }
    _trackBorderColor = value;
    notifyListeners();
}

Radius ScrollbarPainter::trackRadius() {
    return _trackRadius;
}

void ScrollbarPainter::trackRadius(Radius value) {
    if (trackRadius == value) {
        return;
    }
    _trackRadius = value;
    notifyListeners();
}

TextDirection ScrollbarPainter::textDirection() {
    return _textDirection;
}

void ScrollbarPainter::textDirection(TextDirection value) {
    assert(value != nullptr);
    if (textDirection == value) {
        return;
    }
    _textDirection = value;
    notifyListeners();
}

double ScrollbarPainter::thickness() {
    return _thickness;
}

void ScrollbarPainter::thickness(double value) {
    assert(value != nullptr);
    if (thickness == value) {
        return;
    }
    _thickness = value;
    notifyListeners();
}

double ScrollbarPainter::mainAxisMargin() {
    return _mainAxisMargin;
}

void ScrollbarPainter::mainAxisMargin(double value) {
    assert(value != nullptr);
    if (mainAxisMargin == value) {
        return;
    }
    _mainAxisMargin = value;
    notifyListeners();
}

double ScrollbarPainter::crossAxisMargin() {
    return _crossAxisMargin;
}

void ScrollbarPainter::crossAxisMargin(double value) {
    assert(value != nullptr);
    if (crossAxisMargin == value) {
        return;
    }
    _crossAxisMargin = value;
    notifyListeners();
}

Radius ScrollbarPainter::radius() {
    return _radius;
}

void ScrollbarPainter::radius(Radius value) {
    assert(shape == nullptr || value == nullptr);
    if (radius == value) {
        return;
    }
    _radius = value;
    notifyListeners();
}

OutlinedBorder ScrollbarPainter::shape() {
    return _shape;
}

void ScrollbarPainter::shape(OutlinedBorder value) {
    assert(radius == nullptr || value == nullptr);
    if (shape == value) {
        return;
    }
    _shape = value;
    notifyListeners();
}

EdgeInsets ScrollbarPainter::padding() {
    return _padding;
}

void ScrollbarPainter::padding(EdgeInsets value) {
    assert(value != nullptr);
    if (padding == value) {
        return;
    }
    _padding = value;
    notifyListeners();
}

double ScrollbarPainter::minLength() {
    return _minLength;
}

void ScrollbarPainter::minLength(double value) {
    assert(value != nullptr);
    if (minLength == value) {
        return;
    }
    _minLength = value;
    notifyListeners();
}

double ScrollbarPainter::minOverscrollLength() {
    return _minOverscrollLength;
}

void ScrollbarPainter::minOverscrollLength(double value) {
    assert(value != nullptr);
    if (minOverscrollLength == value) {
        return;
    }
    _minOverscrollLength = value;
    notifyListeners();
}

ScrollbarOrientation ScrollbarPainter::scrollbarOrientation() {
    return _scrollbarOrientation;
}

void ScrollbarPainter::scrollbarOrientation(ScrollbarOrientation value) {
    if (scrollbarOrientation == value) {
        return;
    }
    _scrollbarOrientation = value;
    notifyListeners();
}

bool ScrollbarPainter::ignorePointer() {
    return _ignorePointer;
}

void ScrollbarPainter::ignorePointer(bool value) {
    if (ignorePointer == value) {
        return;
    }
    _ignorePointer = value;
    notifyListeners();
}

void ScrollbarPainter::update(AxisDirection axisDirection, ScrollMetrics metrics) {
    if (_lastMetrics != nullptr && _lastMetrics!.extentBefore == metrics.extentBefore && _lastMetrics!.extentInside == metrics.extentInside && _lastMetrics!.extentAfter == metrics.extentAfter && _lastAxisDirection == axisDirection) {
        return;
    }
    ScrollMetrics oldMetrics = _lastMetrics;
    _lastMetrics = metrics;
    _lastAxisDirection = axisDirection;
    ;
    if (!needPaint(oldMetrics) && !needPaint(metrics)) {
        return;
    }
    notifyListeners();
}

void ScrollbarPainter::updateThickness(Radius nextRadius, double nextThickness) {
    thickness = nextThickness;
    radius = nextRadius;
}

void ScrollbarPainter::dispose() {
    fadeoutOpacityAnimation.removeListener(notifyListeners);
    super.dispose();
}

double ScrollbarPainter::getTrackToScroll(double thumbOffsetLocal) {
    assert(thumbOffsetLocal != nullptr);
    double scrollableExtent = _lastMetrics!.maxScrollExtent - _lastMetrics!.minScrollExtent;
    double thumbMovableExtent = _trackExtent - _thumbExtent();
    return scrollableExtent * thumbOffsetLocal / thumbMovableExtent;
}

void ScrollbarPainter::paint(Canvas canvas, Size size) {
    if (_lastAxisDirection == nullptr || _lastMetrics == nullptr || _lastMetrics!.maxScrollExtent <= _lastMetrics!.minScrollExtent) {
        return;
    }
    if (_lastMetrics!.viewportDimension <= _mainAxisPadding || _trackExtent <= 0) {
        return;
    }
    double beforePadding = _isVertical? padding.top : padding.left;
    double thumbExtent = _thumbExtent();
    double thumbOffsetLocal = _getScrollToTrack(_lastMetrics!, thumbExtent);
    _thumbOffset = thumbOffsetLocal + mainAxisMargin + beforePadding;
    if (_lastMetrics!.maxScrollExtent.isInfinite) {
        return;
    }
    return _paintScrollbar(canvas, size, thumbExtent, _lastAxisDirection!);
}

bool ScrollbarPainter::hitTestInteractive(bool forHover, PointerDeviceKind kind, Offset position) {
    if (_trackRect == nullptr) {
        return false;
    }
    if (ignorePointer) {
        return false;
    }
    if (!_lastMetricsAreScrollable) {
        return false;
    }
    Rect interactiveRect = _trackRect!;
    Rect paddedRect = interactiveRect.expandToInclude(Rect.fromCircle(_thumbRect!.center, _kMinInteractiveSize / 2));
    if (fadeoutOpacityAnimation.value == 0.0) {
        if (forHover && kind == PointerDeviceKind.mouse) {
            return paddedRect.contains(position);
        }
        return false;
    }
    ;
}

bool ScrollbarPainter::hitTestOnlyThumbInteractive(PointerDeviceKind kind, Offset position) {
    if (_thumbRect == nullptr) {
        return false;
    }
    if (ignorePointer) {
        return false;
    }
    if (fadeoutOpacityAnimation.value == 0.0) {
        return false;
    }
    if (!_lastMetricsAreScrollable) {
        return false;
    }
    ;
}

bool ScrollbarPainter::hitTest(Offset position) {
    if (_thumbRect == nullptr) {
        return nullptr;
    }
    if (ignorePointer) {
        return false;
    }
    if (fadeoutOpacityAnimation.value == 0.0) {
        return false;
    }
    if (!_lastMetricsAreScrollable) {
        return false;
    }
    return _trackRect!.contains(position!);
}

bool ScrollbarPainter::shouldRepaint(ScrollbarPainter oldDelegate) {
    return color != oldDelegate.color || trackColor != oldDelegate.trackColor || trackBorderColor != oldDelegate.trackBorderColor || textDirection != oldDelegate.textDirection || thickness != oldDelegate.thickness || fadeoutOpacityAnimation != oldDelegate.fadeoutOpacityAnimation || mainAxisMargin != oldDelegate.mainAxisMargin || crossAxisMargin != oldDelegate.crossAxisMargin || radius != oldDelegate.radius || trackRadius != oldDelegate.trackRadius || shape != oldDelegate.shape || padding != oldDelegate.padding || minLength != oldDelegate.minLength || minOverscrollLength != oldDelegate.minOverscrollLength || scrollbarOrientation != oldDelegate.scrollbarOrientation || ignorePointer != oldDelegate.ignorePointer;
}

bool ScrollbarPainter::shouldRebuildSemantics(CustomPainter oldDelegate) {
    return false;
}

SemanticsBuilderCallback ScrollbarPainter::semanticsBuilder() {
    return nullptr;
}

String ScrollbarPainter::toString() {
    return describeIdentity(this);
}

void ScrollbarPainter::_debugAssertIsValidOrientation(ScrollbarOrientation orientation) {
    assert((_isVertical && _isVerticalOrientation(orientation)) || (!_isVertical && !_isVerticalOrientation(orientation)), "The given ScrollbarOrientation: $orientation is incompatible with the current AxisDirection: $_lastAxisDirection.");
}

bool ScrollbarPainter::_isVerticalOrientation(ScrollbarOrientation orientation) {
    return orientation == ScrollbarOrientation.left || orientation == ScrollbarOrientation.right;
}

Paint ScrollbarPainter::_paintThumb() {
    return ;
}

Paint ScrollbarPainter::_paintTrack(bool isBorder) {
    if (isBorder) {
        return ;
    }
    return ;
}

void ScrollbarPainter::_paintScrollbar(Canvas canvas, AxisDirection direction, Size size, double thumbExtent) {
    assert(textDirection != nullptr, "A TextDirection must be provided before a Scrollbar can be painted.");
    ScrollbarOrientation resolvedOrientation;
    if (scrollbarOrientation == nullptr) {
        if (_isVertical) {
            resolvedOrientation = textDirection == TextDirection.ltr? ScrollbarOrientation.right : ScrollbarOrientation.left;
        } else {
            resolvedOrientation = ScrollbarOrientation.bottom;
        }
    } else {
        resolvedOrientation = scrollbarOrientation!;
    }
    double x, y;
    Size thumbSize, trackSize;
    Offset trackOffset, borderStart, borderEnd;
    _debugAssertIsValidOrientation(resolvedOrientation);
    ;
    _trackRect = trackOffset & trackSize;
    _thumbRect = Offset(x, y) & thumbSize;
    if (fadeoutOpacityAnimation.value != 0.0) {
        if (trackRadius == nullptr) {
            canvas.drawRect(_trackRect!, _paintTrack());
        } else {
            canvas.drawRRect(RRect.fromRectAndRadius(_trackRect!, trackRadius!), _paintTrack());
        }
        canvas.drawLine(borderStart, borderEnd, _paintTrack(true));
        if (radius != nullptr) {
            canvas.drawRRect(RRect.fromRectAndRadius(_thumbRect!, radius!), _paintThumb);
            return;
        }
        if (shape == nullptr) {
            canvas.drawRect(_thumbRect!, _paintThumb);
            return;
        }
        Path outerPath = shape!.getOuterPath(_thumbRect!);
        canvas.drawPath(outerPath, _paintThumb);
        shape!.paint(canvas, _thumbRect!);
    }
}

double ScrollbarPainter::_thumbExtent() {
    double fractionVisible = clampDouble((_lastMetrics!.extentInside - _mainAxisPadding) / (_totalContentExtent - _mainAxisPadding), 0.0, 1.0);
    double thumbExtent = math.max(math.min(_trackExtent, minOverscrollLength), _trackExtent * fractionVisible);
    double fractionOverscrolled = 1.0 - _lastMetrics!.extentInside / _lastMetrics!.viewportDimension;
    double safeMinLength = math.min(minLength, _trackExtent);
    double newMinLength = (_beforeExtent > 0 && _afterExtent > 0)? safeMinLength : safeMinLength * (1.0 - clampDouble(fractionOverscrolled, 0.0, 0.2) / 0.2);
    return clampDouble(thumbExtent, newMinLength, _trackExtent);
}

bool ScrollbarPainter::_isVertical() {
    return _lastAxisDirection == AxisDirection.down || _lastAxisDirection == AxisDirection.up;
}

bool ScrollbarPainter::_isReversed() {
    return _lastAxisDirection == AxisDirection.up || _lastAxisDirection == AxisDirection.left;
}

double ScrollbarPainter::_beforeExtent() {
    return _isReversed? _lastMetrics!.extentAfter : _lastMetrics!.extentBefore;
}

double ScrollbarPainter::_afterExtent() {
    return _isReversed? _lastMetrics!.extentBefore : _lastMetrics!.extentAfter;
}

double ScrollbarPainter::_mainAxisPadding() {
    return _isVertical? padding.vertical : padding.horizontal;
}

double ScrollbarPainter::_trackExtent() {
    return _lastMetrics!.viewportDimension - 2 * mainAxisMargin - _mainAxisPadding;
}

double ScrollbarPainter::_totalContentExtent() {
    return _lastMetrics!.maxScrollExtent - _lastMetrics!.minScrollExtent + _lastMetrics!.viewportDimension;
}

double ScrollbarPainter::_getScrollToTrack(ScrollMetrics metrics, double thumbExtent) {
    double scrollableExtent = metrics.maxScrollExtent - metrics.minScrollExtent;
    double fractionPast = (scrollableExtent > 0)? clampDouble((metrics.pixels - metrics.minScrollExtent) / scrollableExtent, 0.0, 1.0) : 0;
    return (_isReversed? 1 - fractionPast : fractionPast) * (_trackExtent - thumbExtent);
}

bool ScrollbarPainter::_lastMetricsAreScrollable() {
    return _lastMetrics!.minScrollExtent != _lastMetrics!.maxScrollExtent;
}

RawScrollbar::RawScrollbar(Widget child, ScrollController controller, double crossAxisMargin, Duration fadeDuration, bool interactive, bool isAlwaysShown, Unknown, double mainAxisMargin, double minOverscrollLength, double minThumbLength, ScrollNotificationPredicate notificationPredicate, Duration pressDuration, Radius radius, ScrollbarOrientation scrollbarOrientation, OutlinedBorder shape, double thickness, Color thumbColor, bool thumbVisibility, Duration timeToFade, Color trackBorderColor, Color trackColor, Radius trackRadius, bool trackVisibility) {
    {
        assert(child != nullptr);
        assert(thumbVisibility == nullptr || isAlwaysShown == nullptr, "Scrollbar thumb appearance should only be controlled with thumbVisibility, isAlwaysShown is deprecated.");
        assert(!((thumbVisibility == false || isAlwaysShown == false) && (trackVisibility ?? false)), "A scrollbar track cannot be drawn without a scrollbar thumb.");
        assert(minThumbLength != nullptr);
        assert(minThumbLength >= 0);
        assert(minOverscrollLength == nullptr || minOverscrollLength <= minThumbLength);
        assert(minOverscrollLength == nullptr || minOverscrollLength >= 0);
        assert(fadeDuration != nullptr);
        assert(radius == nullptr || shape == nullptr);
        assert(timeToFade != nullptr);
        assert(pressDuration != nullptr);
        assert(mainAxisMargin != nullptr);
        assert(crossAxisMargin != nullptr);
    }
}

RawScrollbarState<RawScrollbar> RawScrollbar::createState() {
    return <RawScrollbar>RawScrollbarState();
}

bool RawScrollbarState::showScrollbar() {
    return widget.isAlwaysShown ?? widget.thumbVisibility ?? false;
}

bool RawScrollbarState::enableGestures() {
    return widget.interactive ?? true;
}

void RawScrollbarState::initState() {
    super.initState();
    _fadeoutAnimationController = ;
    _fadeoutOpacityAnimation = CurvedAnimation(_fadeoutAnimationController, Curves.fastOutSlowIn);
    scrollbarPainter = ScrollbarPainter(widget.thumbColor ?? const Color(0x66BCBCBC), _fadeoutOpacityAnimation, widget.thickness ?? _kScrollbarThickness, widget.radius, widget.trackRadius, widget.scrollbarOrientation, widget.mainAxisMargin, widget.shape, widget.crossAxisMargin, widget.minThumbLength, widget.minOverscrollLength ?? widget.minThumbLength);
}

void RawScrollbarState::didChangeDependencies() {
    super.didChangeDependencies();
    assert(_debugScheduleCheckHasValidScrollPosition());
}

void RawScrollbarState::updateScrollbarPainter() {
    ;
}

void RawScrollbarState::didUpdateWidget(T oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (widget.isAlwaysShown != oldWidget.isAlwaysShown || widget.thumbVisibility != oldWidget.thumbVisibility) {
        if ((widget.isAlwaysShown ?? false) || (widget.thumbVisibility ?? false)) {
            assert(_debugScheduleCheckHasValidScrollPosition());
            _fadeoutTimer?.cancel();
            _fadeoutAnimationController.animateTo(1.0);
        } else {
            _fadeoutAnimationController.reverse();
        }
    }
}

Axis RawScrollbarState::getScrollbarDirection() {
    assert(_currentController != nullptr);
    if (_currentController!.hasClients) {
        return _currentController!.position.axis;
    }
    return nullptr;
}

void RawScrollbarState::handleThumbPress() {
    assert(_debugCheckHasValidScrollPosition());
    if (getScrollbarDirection() == nullptr) {
        return;
    }
    _fadeoutTimer?.cancel();
}

void RawScrollbarState::handleThumbPressStart(Offset localPosition) {
    assert(_debugCheckHasValidScrollPosition());
    _currentController = widget.controller ?? PrimaryScrollController.of(context);
    Axis direction = getScrollbarDirection();
    if (direction == nullptr) {
        return;
    }
    _fadeoutTimer?.cancel();
    _fadeoutAnimationController.forward();
    _dragScrollbarAxisOffset = localPosition;
}

void RawScrollbarState::handleThumbPressUpdate(Offset localPosition) {
    assert(_debugCheckHasValidScrollPosition());
    Axis direction = getScrollbarDirection();
    if (direction == nullptr) {
        return;
    }
    _updateScrollPosition(localPosition);
    _dragScrollbarAxisOffset = localPosition;
}

void RawScrollbarState::handleThumbPressEnd(Offset localPosition, Velocity velocity) {
    assert(_debugCheckHasValidScrollPosition());
    Axis direction = getScrollbarDirection();
    if (direction == nullptr) {
        return;
    }
    _maybeStartFadeoutTimer();
    _dragScrollbarAxisOffset = nullptr;
    _currentController = nullptr;
}

bool RawScrollbarState::isPointerOverTrack(PointerDeviceKind kind, Offset position) {
    if (_scrollbarPainterKey.currentContext == nullptr) {
        return false;
    }
    Offset localOffset = _getLocalOffset(_scrollbarPainterKey, position);
    return scrollbarPainter.hitTestInteractive(localOffset, kind) && !scrollbarPainter.hitTestOnlyThumbInteractive(localOffset, kind);
}

bool RawScrollbarState::isPointerOverThumb(PointerDeviceKind kind, Offset position) {
    if (_scrollbarPainterKey.currentContext == nullptr) {
        return false;
    }
    Offset localOffset = _getLocalOffset(_scrollbarPainterKey, position);
    return scrollbarPainter.hitTestOnlyThumbInteractive(localOffset, kind);
}

bool RawScrollbarState::isPointerOverScrollbar(bool forHover, PointerDeviceKind kind, Offset position) {
    if (_scrollbarPainterKey.currentContext == nullptr) {
        return false;
    }
    Offset localOffset = _getLocalOffset(_scrollbarPainterKey, position);
    return scrollbarPainter.hitTestInteractive(localOffset, kindtrue);
}

void RawScrollbarState::handleHover(PointerHoverEvent event) {
    if (isPointerOverScrollbar(event.position, event.kindtrue)) {
        _hoverIsActive = true;
        _fadeoutAnimationController.forward();
        _fadeoutTimer?.cancel();
    } else     {
        if (_hoverIsActive) {
        _hoverIsActive = false;
        _maybeStartFadeoutTimer();
    }
;
    }}

void RawScrollbarState::handleHoverExit(PointerExitEvent event) {
    _hoverIsActive = false;
    _maybeStartFadeoutTimer();
}

void RawScrollbarState::dispose() {
    _fadeoutAnimationController.dispose();
    _fadeoutTimer?.cancel();
    scrollbarPainter.dispose();
    super.dispose();
}

Widget RawScrollbarState::build(BuildContext context) {
    updateScrollbarPainter();
    return <ScrollMetricsNotification>NotificationListener(_handleScrollMetricsNotification, <ScrollNotification>NotificationListener(_handleScrollNotification, RepaintBoundary(RawGestureDetector(_gestures, MouseRegion(, , CustomPaint(_scrollbarPainterKey, scrollbarPainter, RepaintBoundary(widget.child)))))));
}

bool RawScrollbarState::_showTrack() {
    return showScrollbar && (widget.trackVisibility ?? false);
}

bool RawScrollbarState::_debugScheduleCheckHasValidScrollPosition() {
    if (!showScrollbar) {
        return true;
    }
    WidgetsBinding.instance.addPostFrameCallback();
    return true;
}

void RawScrollbarState::_validateInteractions(AnimationStatus status) {
    ScrollController scrollController = widget.controller ?? PrimaryScrollController.of(context);
    if (status == AnimationStatus.dismissed) {
        assert(_fadeoutOpacityAnimation.value == 0.0);
    } else     {
        if (scrollController != nullptr && enableGestures) {
        assert(_debugCheckHasValidScrollPosition());
    }
;
    }}

bool RawScrollbarState::_debugCheckHasValidScrollPosition() {
    if (!mounted) {
        return true;
    }
    ScrollController scrollController = widget.controller ?? PrimaryScrollController.of(context);
    bool tryPrimary = widget.controller == nullptr;
    String controllerForError = tryPrimary? "PrimaryScrollController" : "provided ScrollController";
    String when = "";
    if (widget.isAlwaysShown ?? false) {
        when = "Scrollbar.isAlwaysShown is true";
    } else     {
        if (widget.thumbVisibility ?? false) {
        when = "Scrollbar.thumbVisibility is true";
    } else     {
        if (enableGestures) {
        when = "the scrollbar is interactive";
    } else {
        when = "using the Scrollbar";
    }
;
    };
    }    assert(scrollController != nullptr, "A ScrollController is required when $when. ${tryPrimary ? 'The Scrollbar was not provided a ScrollController, '      'and attempted to use the PrimaryScrollController, but none was found.' :''}");
    assert(());
    assert(());
    return true;
}

void RawScrollbarState::_updateScrollPosition(Offset updatedOffset) {
    assert(_currentController != nullptr);
    assert(_dragScrollbarAxisOffset != nullptr);
    ScrollPosition position = _currentController!.position;
    double primaryDelta;
    ;
    double scrollOffsetLocal = scrollbarPainter.getTrackToScroll(primaryDelta);
    double scrollOffsetGlobal = scrollOffsetLocal + position.pixels;
    if (scrollOffsetGlobal != position.pixels) {
        double physicsAdjustment = position.physics.applyBoundaryConditions(position, scrollOffsetGlobal);
        double newPosition = scrollOffsetGlobal - physicsAdjustment;
        ;
        position.jumpTo(newPosition);
    }
}

void RawScrollbarState::_maybeStartFadeoutTimer() {
    if (!showScrollbar) {
        _fadeoutTimer?.cancel();
        _fadeoutTimer = Timer(widget.timeToFade, );
    }
}

void RawScrollbarState::_handleTrackTapDown(TapDownDetails details) {
    assert(_debugCheckHasValidScrollPosition());
    _currentController = widget.controller ?? PrimaryScrollController.of(context);
    double scrollIncrement;
    ScrollIncrementCalculator calculator = Scrollable.of(_currentController!.position.context.notificationContext!)?.widget.incrementCalculator;
    if (calculator != nullptr) {
        scrollIncrement = calculator(ScrollIncrementDetails(ScrollIncrementType.page, _currentController!.position));
    } else {
        scrollIncrement = 0.8 * _currentController!.position.viewportDimension;
    }
    ;
    _currentController!.position.moveTo(_currentController!.position.pixels + scrollIncrementconst Duration(100), Curves.easeInOut);
}

bool RawScrollbarState::_shouldUpdatePainter(Axis notificationAxis) {
    ScrollController scrollController = widget.controller ?? PrimaryScrollController.of(context);
    if (scrollController == nullptr) {
        return true;
    }
    if (scrollController.positions.length > 1) {
        return false;
    }
    return !scrollController.hasClients || scrollController.position.axis == notificationAxis;
}

bool RawScrollbarState::_handleScrollMetricsNotification(ScrollMetricsNotification notification) {
    if (!widget.notificationPredicate(ScrollUpdateNotification(notification.metrics, notification.context, notification.depth))) {
        return false;
    }
    if (showScrollbar) {
        if (_fadeoutAnimationController.status != AnimationStatus.forward && _fadeoutAnimationController.status != AnimationStatus.completed) {
            _fadeoutAnimationController.forward();
        }
    }
    ScrollMetrics metrics = notification.metrics;
    if (_shouldUpdatePainter(metrics.axis)) {
        scrollbarPainter.update(metrics, metrics.axisDirection);
    }
    return false;
}

bool RawScrollbarState::_handleScrollNotification(ScrollNotification notification) {
    if (!widget.notificationPredicate(notification)) {
        return false;
    }
    ScrollMetrics metrics = notification.metrics;
    if (metrics.maxScrollExtent <= metrics.minScrollExtent) {
        if (_fadeoutAnimationController.status != AnimationStatus.dismissed && _fadeoutAnimationController.status != AnimationStatus.reverse) {
            _fadeoutAnimationController.reverse();
        }
        if (_shouldUpdatePainter(metrics.axis)) {
            scrollbarPainter.update(metrics, metrics.axisDirection);
        }
        return false;
    }
    if (notification is ScrollUpdateNotification || notification is OverscrollNotification) {
        if (_fadeoutAnimationController.status != AnimationStatus.forward && _fadeoutAnimationController.status != AnimationStatus.completed) {
            _fadeoutAnimationController.forward();
        }
        _fadeoutTimer?.cancel();
        if (_shouldUpdatePainter(metrics.axis)) {
            scrollbarPainter.update(metrics, metrics.axisDirection);
        }
    } else     {
        if (notification is ScrollEndNotification) {
        if (_dragScrollbarAxisOffset == nullptr) {
            _maybeStartFadeoutTimer();
        }
    }
;
    }    return false;
}

Map<Type, GestureRecognizerFactory> RawScrollbarState::_gestures() {
    Map<Type, GestureRecognizerFactory> gestures = ;
    ScrollController controller = widget.controller ?? PrimaryScrollController.of(context);
    if (controller == nullptr || !enableGestures) {
        return gestures;
    }
    gestures[_ThumbPressGestureRecognizer] = <_ThumbPressGestureRecognizer>GestureRecognizerFactoryWithHandlers(, );
    gestures[_TrackTapGestureRecognizer] = <_TrackTapGestureRecognizer>GestureRecognizerFactoryWithHandlers(, );
    return gestures;
}

bool _ThumbPressGestureRecognizer::isPointerAllowed(PointerDownEvent event) {
    if (!_hitTestInteractive(_customPaintKey, event.position, event.kind)) {
        return false;
    }
    return super.isPointerAllowed(event);
}

_ThumbPressGestureRecognizer::_ThumbPressGestureRecognizer(GlobalKey customPaintKey, Object debugOwner, Duration pressDuration) {
    {
        _customPaintKey = customPaintKey;
        super(pressDuration);
    }
}

bool _ThumbPressGestureRecognizer::_hitTestInteractive(GlobalKey customPaintKey, PointerDeviceKind kind, Offset offset) {
    if (customPaintKey.currentContext == nullptr) {
        return false;
    }
    CustomPaint customPaint = (;
    ScrollbarPainter painter = (;
    Offset localOffset = _getLocalOffset(customPaintKey, offset);
    return painter.hitTestOnlyThumbInteractive(localOffset, kind);
}

bool _TrackTapGestureRecognizer::isPointerAllowed(PointerDownEvent event) {
    if (!_hitTestInteractive(_customPaintKey, event.position, event.kind)) {
        return false;
    }
    return super.isPointerAllowed(event);
}

_TrackTapGestureRecognizer::_TrackTapGestureRecognizer(GlobalKey customPaintKey, Object debugOwner) {
    {
        _customPaintKey = customPaintKey;
        super(debugOwner);
    }
}

bool _TrackTapGestureRecognizer::_hitTestInteractive(GlobalKey customPaintKey, PointerDeviceKind kind, Offset offset) {
    if (customPaintKey.currentContext == nullptr) {
        return false;
    }
    CustomPaint customPaint = (;
    ScrollbarPainter painter = (;
    Offset localOffset = _getLocalOffset(customPaintKey, offset);
    return painter.hitTestInteractive(localOffset, kind) && !painter.hitTestOnlyThumbInteractive(localOffset, kind);
}

Offset _getLocalOffset(Offset position, GlobalKey scrollbarPainterKey) {
    RenderBox renderBox = (;
    return renderBox.globalToLocal(position);
}
