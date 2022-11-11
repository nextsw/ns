#include "scrollbar.hpp"
ScrollbarPainterCls::ScrollbarPainterCls(Color color, double crossAxisMargin, Animation<double> fadeoutOpacityAnimation, bool ignorePointer, double mainAxisMargin, double minLength, double minOverscrollLength, EdgeInsets padding, Radius radius, ScrollbarOrientation scrollbarOrientation, OutlinedBorder shape, TextDirection textDirection, double thickness, Color trackBorderColor, Color trackColor, Radius trackRadius) {
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
        assert(padding->isNonNegative);
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
        _minOverscrollLength = minOverscrollLength or minLength;
        _ignorePointer = ignorePointer;
    }
    {
        fadeoutOpacityAnimation->addListener(notifyListeners);
    }
}

Color ScrollbarPainterCls::color() {
    return _color;
}

void ScrollbarPainterCls::color(Color value) {
    assert(value != nullptr);
    if (color() == value) {
        return;
    }
    _color = value;
    notifyListeners();
}

Color ScrollbarPainterCls::trackColor() {
    return _trackColor;
}

void ScrollbarPainterCls::trackColor(Color value) {
    assert(value != nullptr);
    if (trackColor() == value) {
        return;
    }
    _trackColor = value;
    notifyListeners();
}

Color ScrollbarPainterCls::trackBorderColor() {
    return _trackBorderColor;
}

void ScrollbarPainterCls::trackBorderColor(Color value) {
    assert(value != nullptr);
    if (trackBorderColor() == value) {
        return;
    }
    _trackBorderColor = value;
    notifyListeners();
}

Radius ScrollbarPainterCls::trackRadius() {
    return _trackRadius;
}

void ScrollbarPainterCls::trackRadius(Radius value) {
    if (trackRadius() == value) {
        return;
    }
    _trackRadius = value;
    notifyListeners();
}

TextDirection ScrollbarPainterCls::textDirection() {
    return _textDirection;
}

void ScrollbarPainterCls::textDirection(TextDirection value) {
    assert(value != nullptr);
    if (textDirection() == value) {
        return;
    }
    _textDirection = value;
    notifyListeners();
}

double ScrollbarPainterCls::thickness() {
    return _thickness;
}

void ScrollbarPainterCls::thickness(double value) {
    assert(value != nullptr);
    if (thickness() == value) {
        return;
    }
    _thickness = value;
    notifyListeners();
}

double ScrollbarPainterCls::mainAxisMargin() {
    return _mainAxisMargin;
}

void ScrollbarPainterCls::mainAxisMargin(double value) {
    assert(value != nullptr);
    if (mainAxisMargin() == value) {
        return;
    }
    _mainAxisMargin = value;
    notifyListeners();
}

double ScrollbarPainterCls::crossAxisMargin() {
    return _crossAxisMargin;
}

void ScrollbarPainterCls::crossAxisMargin(double value) {
    assert(value != nullptr);
    if (crossAxisMargin() == value) {
        return;
    }
    _crossAxisMargin = value;
    notifyListeners();
}

Radius ScrollbarPainterCls::radius() {
    return _radius;
}

void ScrollbarPainterCls::radius(Radius value) {
    assert(shape() == nullptr || value == nullptr);
    if (radius() == value) {
        return;
    }
    _radius = value;
    notifyListeners();
}

OutlinedBorder ScrollbarPainterCls::shape() {
    return _shape;
}

void ScrollbarPainterCls::shape(OutlinedBorder value) {
    assert(radius() == nullptr || value == nullptr);
    if (shape() == value) {
        return;
    }
    _shape = value;
    notifyListeners();
}

EdgeInsets ScrollbarPainterCls::padding() {
    return _padding;
}

void ScrollbarPainterCls::padding(EdgeInsets value) {
    assert(value != nullptr);
    if (padding() == value) {
        return;
    }
    _padding = value;
    notifyListeners();
}

double ScrollbarPainterCls::minLength() {
    return _minLength;
}

void ScrollbarPainterCls::minLength(double value) {
    assert(value != nullptr);
    if (minLength() == value) {
        return;
    }
    _minLength = value;
    notifyListeners();
}

double ScrollbarPainterCls::minOverscrollLength() {
    return _minOverscrollLength;
}

void ScrollbarPainterCls::minOverscrollLength(double value) {
    assert(value != nullptr);
    if (minOverscrollLength() == value) {
        return;
    }
    _minOverscrollLength = value;
    notifyListeners();
}

ScrollbarOrientation ScrollbarPainterCls::scrollbarOrientation() {
    return _scrollbarOrientation;
}

void ScrollbarPainterCls::scrollbarOrientation(ScrollbarOrientation value) {
    if (scrollbarOrientation() == value) {
        return;
    }
    _scrollbarOrientation = value;
    notifyListeners();
}

bool ScrollbarPainterCls::ignorePointer() {
    return _ignorePointer;
}

void ScrollbarPainterCls::ignorePointer(bool value) {
    if (ignorePointer() == value) {
        return;
    }
    _ignorePointer = value;
    notifyListeners();
}

void ScrollbarPainterCls::update(AxisDirection axisDirection, ScrollMetrics metrics) {
    if (_lastMetrics != nullptr && _lastMetrics!->extentBefore() == metrics->extentBefore() && _lastMetrics!->extentInside() == metrics->extentInside() && _lastMetrics!->extentAfter() == metrics->extentAfter() && _lastAxisDirection == axisDirection) {
        return;
    }
    ScrollMetrics oldMetrics = _lastMetrics;
    _lastMetrics = metrics;
    _lastAxisDirection = axisDirection;
    InlineMethod;
    if (!needPaint(oldMetrics) && !needPaint(metrics)) {
        return;
    }
    notifyListeners();
}

void ScrollbarPainterCls::updateThickness(Radius nextRadius, double nextThickness) {
    thickness() = nextThickness;
    radius() = nextRadius;
}

void ScrollbarPainterCls::dispose() {
    fadeoutOpacityAnimation->removeListener(notifyListeners);
    super->dispose();
}

double ScrollbarPainterCls::getTrackToScroll(double thumbOffsetLocal) {
    assert(thumbOffsetLocal != nullptr);
    double scrollableExtent = _lastMetrics!->maxScrollExtent() - _lastMetrics!->minScrollExtent();
    double thumbMovableExtent = _trackExtent() - _thumbExtent();
    return scrollableExtent * thumbOffsetLocal / thumbMovableExtent;
}

void ScrollbarPainterCls::paint(Canvas canvas, Size size) {
    if (_lastAxisDirection == nullptr || _lastMetrics == nullptr || _lastMetrics!->maxScrollExtent() <= _lastMetrics!->minScrollExtent()) {
        return;
    }
    if (_lastMetrics!->viewportDimension() <= _mainAxisPadding() || _trackExtent() <= 0) {
        return;
    }
    double beforePadding = _isVertical()? padding()->top : padding()->left;
    double thumbExtent = _thumbExtent();
    double thumbOffsetLocal = _getScrollToTrack(_lastMetrics!, thumbExtent);
    _thumbOffset = thumbOffsetLocal + mainAxisMargin() + beforePadding;
    if (_lastMetrics!->maxScrollExtent()->isInfinite) {
        return;
    }
    return _paintScrollbar(canvas, size, thumbExtent, _lastAxisDirection!);
}

bool ScrollbarPainterCls::hitTestInteractive(bool forHover, PointerDeviceKind kind, Offset position) {
    if (_trackRect == nullptr) {
        return false;
    }
    if (ignorePointer()) {
        return false;
    }
    if (!_lastMetricsAreScrollable()) {
        return false;
    }
    Rect interactiveRect = _trackRect!;
    Rect paddedRect = interactiveRect->expandToInclude(RectCls->fromCircle(_thumbRect!->center(), _kMinInteractiveSize / 2));
    if (fadeoutOpacityAnimation->value() == 0.0) {
        if (forHover && kind == PointerDeviceKindCls::mouse) {
            return paddedRect->contains(position);
        }
        return false;
    }
    ;
}

bool ScrollbarPainterCls::hitTestOnlyThumbInteractive(PointerDeviceKind kind, Offset position) {
    if (_thumbRect == nullptr) {
        return false;
    }
    if (ignorePointer()) {
        return false;
    }
    if (fadeoutOpacityAnimation->value() == 0.0) {
        return false;
    }
    if (!_lastMetricsAreScrollable()) {
        return false;
    }
    ;
}

bool ScrollbarPainterCls::hitTest(Offset position) {
    if (_thumbRect == nullptr) {
        return nullptr;
    }
    if (ignorePointer()) {
        return false;
    }
    if (fadeoutOpacityAnimation->value() == 0.0) {
        return false;
    }
    if (!_lastMetricsAreScrollable()) {
        return false;
    }
    return _trackRect!->contains(position!);
}

bool ScrollbarPainterCls::shouldRepaint(ScrollbarPainter oldDelegate) {
    return color() != oldDelegate->color() || trackColor() != oldDelegate->trackColor() || trackBorderColor() != oldDelegate->trackBorderColor() || textDirection() != oldDelegate->textDirection() || thickness() != oldDelegate->thickness() || fadeoutOpacityAnimation != oldDelegate->fadeoutOpacityAnimation || mainAxisMargin() != oldDelegate->mainAxisMargin() || crossAxisMargin() != oldDelegate->crossAxisMargin() || radius() != oldDelegate->radius() || trackRadius() != oldDelegate->trackRadius() || shape() != oldDelegate->shape() || padding() != oldDelegate->padding() || minLength() != oldDelegate->minLength() || minOverscrollLength() != oldDelegate->minOverscrollLength() || scrollbarOrientation() != oldDelegate->scrollbarOrientation() || ignorePointer() != oldDelegate->ignorePointer();
}

bool ScrollbarPainterCls::shouldRebuildSemantics(CustomPainter oldDelegate) {
    return false;
}

SemanticsBuilderCallback ScrollbarPainterCls::semanticsBuilder() {
    return nullptr;
}

String ScrollbarPainterCls::toString() {
    return describeIdentity(this);
}

void ScrollbarPainterCls::_debugAssertIsValidOrientation(ScrollbarOrientation orientation) {
    assert((_isVertical() && _isVerticalOrientation(orientation)) || (!_isVertical() && !_isVerticalOrientation(orientation)), __s("The given ScrollbarOrientation: $orientation is incompatible with the current AxisDirection: $_lastAxisDirection."));
}

bool ScrollbarPainterCls::_isVerticalOrientation(ScrollbarOrientation orientation) {
    return orientation == ScrollbarOrientationCls::left || orientation == ScrollbarOrientationCls::right;
}

Paint ScrollbarPainterCls::_paintThumb() {
    auto _c1 = make<PaintCls>();_c1.color() = color()->withOpacity(color()->opacity() * fadeoutOpacityAnimation->value());return _c1;
}

Paint ScrollbarPainterCls::_paintTrack(bool isBorder) {
    if (isBorder) {
            auto _c1 = make<PaintCls>();    _c1.color() = auto _c2 = trackBorderColor()->withOpacity(trackBorderColor()->opacity() * fadeoutOpacityAnimation->value());    _c2.style = auto _c3 = PaintingStyleCls::stroke;    _c3.strokeWidth = 1.0;    _c3;    _c2;return _c1;
    }
    auto _c4 = make<PaintCls>();_c4.color() = trackColor()->withOpacity(trackColor()->opacity() * fadeoutOpacityAnimation->value());return _c4;
}

void ScrollbarPainterCls::_paintScrollbar(Canvas canvas, AxisDirection direction, Size size, double thumbExtent) {
    assert(textDirection() != nullptr, __s("A TextDirection must be provided before a Scrollbar can be painted."));
    ScrollbarOrientation resolvedOrientation;
    if (scrollbarOrientation() == nullptr) {
        if (_isVertical()) {
            resolvedOrientation = textDirection() == TextDirectionCls::ltr? ScrollbarOrientationCls::right : ScrollbarOrientationCls::left;
        } else {
            resolvedOrientation = ScrollbarOrientationCls::bottom;
        }
    } else {
        resolvedOrientation = scrollbarOrientation()!;
    }
    double x, y;
    Size thumbSize, trackSize;
    Offset trackOffset, borderStart, borderEnd;
    _debugAssertIsValidOrientation(resolvedOrientation);
    ;
    _trackRect = trackOffset & trackSize;
    _thumbRect = make<OffsetCls>(x, y) & thumbSize;
    if (fadeoutOpacityAnimation->value() != 0.0) {
        if (trackRadius() == nullptr) {
            canvas->drawRect(_trackRect!, _paintTrack());
        } else {
            canvas->drawRRect(RRectCls->fromRectAndRadius(_trackRect!, trackRadius()!), _paintTrack());
        }
        canvas->drawLine(borderStart, borderEnd, _paintTrack(true));
        if (radius() != nullptr) {
            canvas->drawRRect(RRectCls->fromRectAndRadius(_thumbRect!, radius()!), _paintThumb());
            return;
        }
        if (shape() == nullptr) {
            canvas->drawRect(_thumbRect!, _paintThumb());
            return;
        }
        Path outerPath = shape()!->getOuterPath(_thumbRect!);
        canvas->drawPath(outerPath, _paintThumb());
        shape()!->paint(canvas, _thumbRect!);
    }
}

double ScrollbarPainterCls::_thumbExtent() {
    double fractionVisible = clampDouble((_lastMetrics!->extentInside() - _mainAxisPadding()) / (_totalContentExtent() - _mainAxisPadding()), 0.0, 1.0);
    double thumbExtent = math->max(math->min(_trackExtent(), minOverscrollLength()), _trackExtent() * fractionVisible);
    double fractionOverscrolled = 1.0 - _lastMetrics!->extentInside() / _lastMetrics!->viewportDimension();
    double safeMinLength = math->min(minLength(), _trackExtent());
    double newMinLength = (_beforeExtent() > 0 && _afterExtent() > 0)? safeMinLength : safeMinLength * (1.0 - clampDouble(fractionOverscrolled, 0.0, 0.2) / 0.2);
    return clampDouble(thumbExtent, newMinLength, _trackExtent());
}

bool ScrollbarPainterCls::_isVertical() {
    return _lastAxisDirection == AxisDirectionCls::down || _lastAxisDirection == AxisDirectionCls::up;
}

bool ScrollbarPainterCls::_isReversed() {
    return _lastAxisDirection == AxisDirectionCls::up || _lastAxisDirection == AxisDirectionCls::left;
}

double ScrollbarPainterCls::_beforeExtent() {
    return _isReversed()? _lastMetrics!->extentAfter() : _lastMetrics!->extentBefore();
}

double ScrollbarPainterCls::_afterExtent() {
    return _isReversed()? _lastMetrics!->extentBefore() : _lastMetrics!->extentAfter();
}

double ScrollbarPainterCls::_mainAxisPadding() {
    return _isVertical()? padding()->vertical : padding()->horizontal;
}

double ScrollbarPainterCls::_trackExtent() {
    return _lastMetrics!->viewportDimension() - 2 * mainAxisMargin() - _mainAxisPadding();
}

double ScrollbarPainterCls::_totalContentExtent() {
    return _lastMetrics!->maxScrollExtent() - _lastMetrics!->minScrollExtent() + _lastMetrics!->viewportDimension();
}

double ScrollbarPainterCls::_getScrollToTrack(ScrollMetrics metrics, double thumbExtent) {
    double scrollableExtent = metrics->maxScrollExtent() - metrics->minScrollExtent();
    double fractionPast = (scrollableExtent > 0)? clampDouble((metrics->pixels() - metrics->minScrollExtent()) / scrollableExtent, 0.0, 1.0) : 0;
    return (_isReversed()? 1 - fractionPast : fractionPast) * (_trackExtent() - thumbExtent);
}

bool ScrollbarPainterCls::_lastMetricsAreScrollable() {
    return _lastMetrics!->minScrollExtent() != _lastMetrics!->maxScrollExtent();
}

RawScrollbarCls::RawScrollbarCls(Widget child, ScrollController controller, double crossAxisMargin, Duration fadeDuration, bool interactive, bool isAlwaysShown, Unknown key, double mainAxisMargin, double minOverscrollLength, double minThumbLength, ScrollNotificationPredicate notificationPredicate, Duration pressDuration, Radius radius, ScrollbarOrientation scrollbarOrientation, OutlinedBorder shape, double thickness, Color thumbColor, bool thumbVisibility, Duration timeToFade, Color trackBorderColor, Color trackColor, Radius trackRadius, bool trackVisibility) {
    {
        assert(child != nullptr);
        assert(thumbVisibility == nullptr || isAlwaysShown == nullptr, __s("Scrollbar thumb appearance should only be controlled with thumbVisibility, isAlwaysShown is deprecated."));
        assert(!((thumbVisibility == false || isAlwaysShown == false) && (trackVisibility or false)), __s("A scrollbar track cannot be drawn without a scrollbar thumb."));
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

RawScrollbarState<RawScrollbar> RawScrollbarCls::createState() {
    return <RawScrollbar>make<RawScrollbarStateCls>();
}

template<typename T>
bool RawScrollbarStateCls<T>::showScrollbar() {
    return widget->isAlwaysShown or widget->thumbVisibility or false;
}

template<typename T>
bool RawScrollbarStateCls<T>::enableGestures() {
    return widget->interactive or true;
}

template<typename T>
void RawScrollbarStateCls<T>::initState() {
    super->initState();
    auto _c1 = make<AnimationControllerCls>(this, widget->fadeDuration);_c1.addStatusListener(_validateInteractions);_fadeoutAnimationController = _c1;
    _fadeoutOpacityAnimation = make<CurvedAnimationCls>(_fadeoutAnimationController, CurvesCls::fastOutSlowIn);
    scrollbarPainter = make<ScrollbarPainterCls>(widget->thumbColor or make<ColorCls>(0x66BCBCBC), _fadeoutOpacityAnimation, widget->thickness or _kScrollbarThickness, widget->radius, widget->trackRadius, widget->scrollbarOrientation, widget->mainAxisMargin, widget->shape, widget->crossAxisMargin, widget->minThumbLength, widget->minOverscrollLength or widget->minThumbLength);
}

template<typename T>
void RawScrollbarStateCls<T>::didChangeDependencies() {
    super->didChangeDependencies();
    assert(_debugScheduleCheckHasValidScrollPosition());
}

template<typename T>
void RawScrollbarStateCls<T>::updateScrollbarPainter() {
    auto _c1 = scrollbarPainter;_c1.color = widget->thumbColor or auto _c2 = make<ColorCls>(0x66BCBCBC);_c2.trackRadius = auto _c3 = widget->trackRadius;_c3.trackColor = _showTrack()? widget->trackColor or make<ColorCls>(0x08000000) : auto _c4 = make<ColorCls>(0x00000000);_c4.trackBorderColor = _showTrack()? widget->trackBorderColor or make<ColorCls>(0x1a000000) : auto _c5 = make<ColorCls>(0x00000000);_c5.textDirection = auto _c6 = DirectionalityCls->of(context);_c6.thickness = auto _c7 = widget->thickness or _kScrollbarThickness;_c7.radius = auto _c8 = widget->radius;_c8.padding = auto _c9 = MediaQueryCls->of(context)->padding;_c9.scrollbarOrientation = auto _c10 = widget->scrollbarOrientation;_c10.mainAxisMargin = auto _c11 = widget->mainAxisMargin;_c11.shape = auto _c12 = widget->shape;_c12.crossAxisMargin = auto _c13 = widget->crossAxisMargin;_c13.minLength = auto _c14 = widget->minThumbLength;_c14.minOverscrollLength = auto _c15 = widget->minOverscrollLength or widget->minThumbLength;_c15.ignorePointer = !enableGestures();_c15;_c14;_c13;_c12;_c11;_c10;_c9;_c8;_c7;_c6;_c5;_c4;_c3;_c2;_c1;
}

template<typename T>
void RawScrollbarStateCls<T>::didUpdateWidget(T oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (widget->isAlwaysShown != oldWidget->isAlwaysShown || widget->thumbVisibility != oldWidget->thumbVisibility) {
        if ((widget->isAlwaysShown or false) || (widget->thumbVisibility or false)) {
            assert(_debugScheduleCheckHasValidScrollPosition());
            _fadeoutTimer?->cancel();
            _fadeoutAnimationController->animateTo(1.0);
        } else {
            _fadeoutAnimationController->reverse();
        }
    }
}

template<typename T>
Axis RawScrollbarStateCls<T>::getScrollbarDirection() {
    assert(_currentController != nullptr);
    if (_currentController!->hasClients()) {
        return _currentController!->position()->axis;
    }
    return nullptr;
}

template<typename T>
void RawScrollbarStateCls<T>::handleThumbPress() {
    assert(_debugCheckHasValidScrollPosition());
    if (getScrollbarDirection() == nullptr) {
        return;
    }
    _fadeoutTimer?->cancel();
}

template<typename T>
void RawScrollbarStateCls<T>::handleThumbPressStart(Offset localPosition) {
    assert(_debugCheckHasValidScrollPosition());
    _currentController = widget->controller or PrimaryScrollControllerCls->of(context);
    Axis direction = getScrollbarDirection();
    if (direction == nullptr) {
        return;
    }
    _fadeoutTimer?->cancel();
    _fadeoutAnimationController->forward();
    _dragScrollbarAxisOffset = localPosition;
}

template<typename T>
void RawScrollbarStateCls<T>::handleThumbPressUpdate(Offset localPosition) {
    assert(_debugCheckHasValidScrollPosition());
    Axis direction = getScrollbarDirection();
    if (direction == nullptr) {
        return;
    }
    _updateScrollPosition(localPosition);
    _dragScrollbarAxisOffset = localPosition;
}

template<typename T>
void RawScrollbarStateCls<T>::handleThumbPressEnd(Offset localPosition, Velocity velocity) {
    assert(_debugCheckHasValidScrollPosition());
    Axis direction = getScrollbarDirection();
    if (direction == nullptr) {
        return;
    }
    _maybeStartFadeoutTimer();
    _dragScrollbarAxisOffset = nullptr;
    _currentController = nullptr;
}

template<typename T>
bool RawScrollbarStateCls<T>::isPointerOverTrack(PointerDeviceKind kind, Offset position) {
    if (_scrollbarPainterKey->currentContext() == nullptr) {
        return false;
    }
    Offset localOffset = _getLocalOffset(_scrollbarPainterKey, position);
    return scrollbarPainter->hitTestInteractive(localOffset, kind) && !scrollbarPainter->hitTestOnlyThumbInteractive(localOffset, kind);
}

template<typename T>
bool RawScrollbarStateCls<T>::isPointerOverThumb(PointerDeviceKind kind, Offset position) {
    if (_scrollbarPainterKey->currentContext() == nullptr) {
        return false;
    }
    Offset localOffset = _getLocalOffset(_scrollbarPainterKey, position);
    return scrollbarPainter->hitTestOnlyThumbInteractive(localOffset, kind);
}

template<typename T>
bool RawScrollbarStateCls<T>::isPointerOverScrollbar(bool forHover, PointerDeviceKind kind, Offset position) {
    if (_scrollbarPainterKey->currentContext() == nullptr) {
        return false;
    }
    Offset localOffset = _getLocalOffset(_scrollbarPainterKey, position);
    return scrollbarPainter->hitTestInteractive(localOffset, kindtrue);
}

template<typename T>
void RawScrollbarStateCls<T>::handleHover(PointerHoverEvent event) {
    if (isPointerOverScrollbar(event->position, event->kindtrue)) {
        _hoverIsActive = true;
        _fadeoutAnimationController->forward();
        _fadeoutTimer?->cancel();
    } else     {
        if (_hoverIsActive) {
        _hoverIsActive = false;
        _maybeStartFadeoutTimer();
    }
;
    }}

template<typename T>
void RawScrollbarStateCls<T>::handleHoverExit(PointerExitEvent event) {
    _hoverIsActive = false;
    _maybeStartFadeoutTimer();
}

template<typename T>
void RawScrollbarStateCls<T>::dispose() {
    _fadeoutAnimationController->dispose();
    _fadeoutTimer?->cancel();
    scrollbarPainter->dispose();
    super->dispose();
}

template<typename T>
Widget RawScrollbarStateCls<T>::build(BuildContext context) {
    updateScrollbarPainter();
    return <ScrollMetricsNotification>make<NotificationListenerCls>(_handleScrollMetricsNotification, <ScrollNotification>make<NotificationListenerCls>(_handleScrollNotification, make<RepaintBoundaryCls>(make<RawGestureDetectorCls>(_gestures(), make<MouseRegionCls>([=] (PointerExitEvent event) {
        ;
    }, [=] (PointerHoverEvent event) {
        ;
    }, make<CustomPaintCls>(_scrollbarPainterKey, scrollbarPainter, make<RepaintBoundaryCls>(widget->child)))))));
}

template<typename T>
bool RawScrollbarStateCls<T>::_showTrack() {
    return showScrollbar() && (widget->trackVisibility or false);
}

template<typename T>
bool RawScrollbarStateCls<T>::_debugScheduleCheckHasValidScrollPosition() {
    if (!showScrollbar()) {
        return true;
    }
    WidgetsBindingCls::instance->addPostFrameCallback([=] (Duration duration) {
        assert(_debugCheckHasValidScrollPosition());
    });
    return true;
}

template<typename T>
void RawScrollbarStateCls<T>::_validateInteractions(AnimationStatus status) {
    ScrollController scrollController = widget->controller or PrimaryScrollControllerCls->of(context);
    if (status == AnimationStatusCls::dismissed) {
        assert(_fadeoutOpacityAnimation->value() == 0.0);
    } else     {
        if (scrollController != nullptr && enableGestures()) {
        assert(_debugCheckHasValidScrollPosition());
    }
;
    }}

template<typename T>
bool RawScrollbarStateCls<T>::_debugCheckHasValidScrollPosition() {
    if (!mounted) {
        return true;
    }
    ScrollController scrollController = widget->controller or PrimaryScrollControllerCls->of(context);
    bool tryPrimary = widget->controller == nullptr;
    String controllerForError = tryPrimary? __s("PrimaryScrollController") : __s("provided ScrollController");
    String when = __s("");
    if (widget->isAlwaysShown or false) {
        when = __s("Scrollbar.isAlwaysShown is true");
    } else     {
        if (widget->thumbVisibility or false) {
        when = __s("Scrollbar.thumbVisibility is true");
    } else     {
        if (enableGestures()) {
        when = __s("the scrollbar is interactive");
    } else {
        when = __s("using the Scrollbar");
    }
;
    };
    }    assert(scrollController != nullptr, __s("A ScrollController is required when $when. ${tryPrimary ? 'The Scrollbar was not provided a ScrollController, '      'and attempted to use the PrimaryScrollController, but none was found.' :''}"));
    assert([=] () {
        if (!scrollController!->hasClients()) {
            ;
        }
        return true;
    }());
    assert([=] () {
        try {
            scrollController!->position();
        } catch (Unknown error) {
            if (scrollController == nullptr || scrollController->positions()->length() <= 1) {
                throw;
            }
            ;
        };
        return true;
    }());
    return true;
}

template<typename T>
void RawScrollbarStateCls<T>::_updateScrollPosition(Offset updatedOffset) {
    assert(_currentController != nullptr);
    assert(_dragScrollbarAxisOffset != nullptr);
    ScrollPosition position = _currentController!->position();
    double primaryDelta;
    ;
    double scrollOffsetLocal = scrollbarPainter->getTrackToScroll(primaryDelta);
    double scrollOffsetGlobal = scrollOffsetLocal + position->pixels();
    if (scrollOffsetGlobal != position->pixels()) {
        double physicsAdjustment = position->physics->applyBoundaryConditions(position, scrollOffsetGlobal);
        double newPosition = scrollOffsetGlobal - physicsAdjustment;
        ;
        position->jumpTo(newPosition);
    }
}

template<typename T>
void RawScrollbarStateCls<T>::_maybeStartFadeoutTimer() {
    if (!showScrollbar()) {
        _fadeoutTimer?->cancel();
        _fadeoutTimer = make<TimerCls>(widget->timeToFade, [=] () {
            _fadeoutAnimationController->reverse();
            _fadeoutTimer = nullptr;
        });
    }
}

template<typename T>
void RawScrollbarStateCls<T>::_handleTrackTapDown(TapDownDetails details) {
    assert(_debugCheckHasValidScrollPosition());
    _currentController = widget->controller or PrimaryScrollControllerCls->of(context);
    double scrollIncrement;
    ScrollIncrementCalculator calculator = ScrollableCls->of(_currentController!->position()->context->notificationContext()!)?->widget->incrementCalculator;
    if (calculator != nullptr) {
        scrollIncrement = calculator(make<ScrollIncrementDetailsCls>(ScrollIncrementTypeCls::page, _currentController!->position()));
    } else {
        scrollIncrement = 0.8 * _currentController!->position()->viewportDimension();
    }
    ;
    _currentController!->position()->moveTo(_currentController!->position()->pixels() + scrollIncrementmake<DurationCls>(100), CurvesCls::easeInOut);
}

template<typename T>
bool RawScrollbarStateCls<T>::_shouldUpdatePainter(Axis notificationAxis) {
    ScrollController scrollController = widget->controller or PrimaryScrollControllerCls->of(context);
    if (scrollController == nullptr) {
        return true;
    }
    if (scrollController->positions()->length() > 1) {
        return false;
    }
    return !scrollController->hasClients() || scrollController->position()->axis == notificationAxis;
}

template<typename T>
bool RawScrollbarStateCls<T>::_handleScrollMetricsNotification(ScrollMetricsNotification notification) {
    if (!widget->notificationPredicate(make<ScrollUpdateNotificationCls>(notification->metrics, notification->context, notification->depth))) {
        return false;
    }
    if (showScrollbar()) {
        if (_fadeoutAnimationController->status() != AnimationStatusCls::forward && _fadeoutAnimationController->status() != AnimationStatusCls::completed) {
            _fadeoutAnimationController->forward();
        }
    }
    ScrollMetrics metrics = notification->metrics;
    if (_shouldUpdatePainter(metrics->axis())) {
        scrollbarPainter->update(metrics, metrics->axisDirection());
    }
    return false;
}

template<typename T>
bool RawScrollbarStateCls<T>::_handleScrollNotification(ScrollNotification notification) {
    if (!widget->notificationPredicate(notification)) {
        return false;
    }
    ScrollMetrics metrics = notification->metrics;
    if (metrics->maxScrollExtent() <= metrics->minScrollExtent()) {
        if (_fadeoutAnimationController->status() != AnimationStatusCls::dismissed && _fadeoutAnimationController->status() != AnimationStatusCls::reverse) {
            _fadeoutAnimationController->reverse();
        }
        if (_shouldUpdatePainter(metrics->axis())) {
            scrollbarPainter->update(metrics, metrics->axisDirection());
        }
        return false;
    }
    if (is<ScrollUpdateNotification>(notification) || is<OverscrollNotification>(notification)) {
        if (_fadeoutAnimationController->status() != AnimationStatusCls::forward && _fadeoutAnimationController->status() != AnimationStatusCls::completed) {
            _fadeoutAnimationController->forward();
        }
        _fadeoutTimer?->cancel();
        if (_shouldUpdatePainter(metrics->axis())) {
            scrollbarPainter->update(metrics, metrics->axisDirection());
        }
    } else     {
        if (is<ScrollEndNotification>(notification)) {
        if (_dragScrollbarAxisOffset == nullptr) {
            _maybeStartFadeoutTimer();
        }
    }
;
    }    return false;
}

template<typename T>
Map<Type, GestureRecognizerFactory> RawScrollbarStateCls<T>::_gestures() {
    Map<Type, GestureRecognizerFactory> gestures = makeMap(makeList(), makeList();
    ScrollController controller = widget->controller or PrimaryScrollControllerCls->of(context);
    if (controller == nullptr || !enableGestures()) {
        return gestures;
    }
    gestures[_ThumbPressGestureRecognizerCls] = <_ThumbPressGestureRecognizer>make<GestureRecognizerFactoryWithHandlersCls>([=] ()     {
        make<_ThumbPressGestureRecognizerCls>(this, _scrollbarPainterKey, widget->pressDuration);
    }, [=] (_ThumbPressGestureRecognizer instance) {
        instance->onLongPress = handleThumbPress;
        instance->onLongPressStart = [=] (LongPressStartDetails details)         {
            handleThumbPressStart(details->localPosition);
        };
        instance->onLongPressMoveUpdate = [=] (LongPressMoveUpdateDetails details)         {
            handleThumbPressUpdate(details->localPosition);
        };
        instance->onLongPressEnd = [=] (LongPressEndDetails details)         {
            handleThumbPressEnd(details->localPosition, details->velocity);
        };
    });
    gestures[_TrackTapGestureRecognizerCls] = <_TrackTapGestureRecognizer>make<GestureRecognizerFactoryWithHandlersCls>([=] ()     {
        make<_TrackTapGestureRecognizerCls>(this, _scrollbarPainterKey);
    }, [=] (_TrackTapGestureRecognizer instance) {
        instance->onTapDown = _handleTrackTapDown;
    });
    return gestures;
}

bool _ThumbPressGestureRecognizerCls::isPointerAllowed(PointerDownEvent event) {
    if (!_hitTestInteractive(_customPaintKey, event->position, event->kind)) {
        return false;
    }
    return super->isPointerAllowed(event);
}

_ThumbPressGestureRecognizerCls::_ThumbPressGestureRecognizerCls(GlobalKey customPaintKey, Object debugOwner, Duration pressDuration) {
    {
        _customPaintKey = customPaintKey;
    }
}

bool _ThumbPressGestureRecognizerCls::_hitTestInteractive(GlobalKey customPaintKey, PointerDeviceKind kind, Offset offset) {
    if (customPaintKey->currentContext() == nullptr) {
        return false;
    }
    CustomPaint customPaint = as<CustomPaint>(customPaintKey->currentContext()!->widget());
    ScrollbarPainter painter = as<ScrollbarPainter>(customPaint->foregroundPainter!);
    Offset localOffset = _getLocalOffset(customPaintKey, offset);
    return painter->hitTestOnlyThumbInteractive(localOffset, kind);
}

bool _TrackTapGestureRecognizerCls::isPointerAllowed(PointerDownEvent event) {
    if (!_hitTestInteractive(_customPaintKey, event->position, event->kind)) {
        return false;
    }
    return super->isPointerAllowed(event);
}

_TrackTapGestureRecognizerCls::_TrackTapGestureRecognizerCls(GlobalKey customPaintKey, Object debugOwner) {
    {
        _customPaintKey = customPaintKey;
    }
}

bool _TrackTapGestureRecognizerCls::_hitTestInteractive(GlobalKey customPaintKey, PointerDeviceKind kind, Offset offset) {
    if (customPaintKey->currentContext() == nullptr) {
        return false;
    }
    CustomPaint customPaint = as<CustomPaint>(customPaintKey->currentContext()!->widget());
    ScrollbarPainter painter = as<ScrollbarPainter>(customPaint->foregroundPainter!);
    Offset localOffset = _getLocalOffset(customPaintKey, offset);
    return painter->hitTestInteractive(localOffset, kind) && !painter->hitTestOnlyThumbInteractive(localOffset, kind);
}

Offset _getLocalOffset(Offset position, GlobalKey scrollbarPainterKey) {
    RenderBox renderBox = as<RenderBox>(scrollbarPainterKey->currentContext()!->findRenderObject()!);
    return renderBox->globalToLocal(position);
}
