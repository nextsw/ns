#include "overscroll_indicator.hpp"
GlowingOverscrollIndicator::GlowingOverscrollIndicator(AxisDirection axisDirection, Widget child, Color color, Unknown, ScrollNotificationPredicate notificationPredicate, bool showLeading, bool showTrailing) {
    {
        assert(showLeading != nullptr);
        assert(showTrailing != nullptr);
        assert(axisDirection != nullptr);
        assert(color != nullptr);
        assert(notificationPredicate != nullptr);
    }
}

Axis GlowingOverscrollIndicator::axis() {
    return axisDirectionToAxis(axisDirection);
}

State<GlowingOverscrollIndicator> GlowingOverscrollIndicator::createState() {
    return _GlowingOverscrollIndicatorState();
}

void GlowingOverscrollIndicator::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AxisDirection>EnumProperty("axisDirection", axisDirection));
    String showDescription;
    if (showLeading && showTrailing) {
        showDescription = "both sides";
    } else     {
        if (showLeading) {
        showDescription = "leading side only";
    } else     {
        if (showTrailing) {
        showDescription = "trailing side only";
    } else {
        showDescription = "neither side (!)";
    }
;
    };
    }    properties.add(MessageProperty("show", showDescription));
    properties.add(ColorProperty("color", colorfalse));
}

void _GlowingOverscrollIndicatorState::initState() {
    super.initState();
    _leadingController = _GlowController(this, widget.color, widget.axis);
    _trailingController = _GlowController(this, widget.color, widget.axis);
    _leadingAndTrailingListener = Listenable.merge();
}

void _GlowingOverscrollIndicatorState::didUpdateWidget(GlowingOverscrollIndicator oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (oldWidget.color != widget.color || oldWidget.axis != widget.axis) {
        _leadingController!.color = widget.color;
        _leadingController!.axis = widget.axis;
        _trailingController!.color = widget.color;
        _trailingController!.axis = widget.axis;
    }
}

void _GlowingOverscrollIndicatorState::dispose() {
    _leadingController!.dispose();
    _trailingController!.dispose();
    super.dispose();
}

Widget _GlowingOverscrollIndicatorState::build(BuildContext context) {
    return <ScrollNotification>NotificationListener(_handleScrollNotification, RepaintBoundary(CustomPaint(_GlowingOverscrollIndicatorPainter(widget.showLeading? _leadingController : nullptr, widget.showTrailing? _trailingController : nullptr, widget.axisDirection, _leadingAndTrailingListener), RepaintBoundary(widget.child))));
}

bool _GlowingOverscrollIndicatorState::_handleScrollNotification(ScrollNotification notification) {
    if (!widget.notificationPredicate(notification)) {
        return false;
    }
    _leadingController!._paintOffsetScrollPixels = -math.min(notification.metrics.pixels - notification.metrics.minScrollExtent, _leadingController!._paintOffset);
    _trailingController!._paintOffsetScrollPixels = -math.min(notification.metrics.maxScrollExtent - notification.metrics.pixels, _trailingController!._paintOffset);
    if (notification is OverscrollNotification) {
        _GlowController controller;
        if (notification.overscroll < 0.0) {
            controller = _leadingController;
        } else         {
            if (notification.overscroll > 0.0) {
            controller = _trailingController;
        } else {
            assert(false);
        }
;
        }        bool isLeading = controller == _leadingController;
        if (_lastNotificationType is! OverscrollNotification) {
            OverscrollIndicatorNotification confirmationNotification = OverscrollIndicatorNotification(isLeading);
            confirmationNotification.dispatch(context);
            _accepted[isLeading] = confirmationNotification.accepted;
            if (_accepted[isLeading]!) {
                controller!._paintOffset = confirmationNotification.paintOffset;
            }
        }
        assert(controller != nullptr);
        assert(notification.metrics.axis == widget.axis);
        if (_accepted[isLeading]!) {
            if (notification.velocity != 0.0) {
                assert(notification.dragDetails == nullptr);
                controller!.absorbImpact(notification.velocity.abs());
            } else {
                assert(notification.overscroll != 0.0);
                if (notification.dragDetails != nullptr) {
                    assert(notification.dragDetails!.globalPosition != nullptr);
                    RenderBox renderer = (;
                    assert(renderer != nullptr);
                    assert(renderer.hasSize);
                    Size size = renderer.size;
                    Offset position = renderer.globalToLocal(notification.dragDetails!.globalPosition);
                    ;
                }
            }
        }
    } else     {
        if (notification is ScrollEndNotification || notification is ScrollUpdateNotification) {
        if ((().dragDetails != nullptr) {
            _leadingController!.scrollEnd();
            _trailingController!.scrollEnd();
        }
    }
;
    }    _lastNotificationType = notification.runtimeType;
    return false;
}

Color _GlowController::color() {
    return _color;
}

void _GlowController::color(Color value) {
    assert(color != nullptr);
    if (color == value) {
        return;
    }
    _color = value;
    notifyListeners();
}

Axis _GlowController::axis() {
    return _axis;
}

void _GlowController::axis(Axis value) {
    assert(axis != nullptr);
    if (axis == value) {
        return;
    }
    _axis = value;
    notifyListeners();
}

void _GlowController::dispose() {
    _glowController.dispose();
    _displacementTicker.dispose();
    _pullRecedeTimer?.cancel();
    super.dispose();
}

void _GlowController::absorbImpact(double velocity) {
    assert(velocity >= 0.0);
    _pullRecedeTimer?.cancel();
    _pullRecedeTimer = nullptr;
    velocity = clampDouble(velocity, _minVelocity, _maxVelocity);
    _glowOpacityTween.begin = _state == _GlowState.idle? 0.3 : _glowOpacity.value;
    _glowOpacityTween.end = clampDouble(velocity * _velocityGlowFactor, _glowOpacityTween.begin!, _maxOpacity);
    _glowSizeTween.begin = _glowSize.value;
    _glowSizeTween.end = math.min(0.025 + 7.5e-7 * velocity * velocity, 1.0);
    _glowController.duration = Duration((0.15 + velocity * 0.02).round());
    _glowController.forward(0.0);
    _displacement = 0.5;
    _state = _GlowState.absorb;
}

void _GlowController::pull(double crossAxisOffset, double crossExtent, double extent, double overscroll) {
    _pullRecedeTimer?.cancel();
    _pullDistance = overscroll / 200.0;
    _glowOpacityTween.begin = _glowOpacity.value;
    _glowOpacityTween.end = math.min(_glowOpacity.value + overscroll / extent * _pullOpacityGlowFactor, _maxOpacity);
    double height = math.min(extent, crossExtent * _widthToHeightFactor);
    _glowSizeTween.begin = _glowSize.value;
    _glowSizeTween.end = math.max(1.0 - 1.0 / (0.7 * math.sqrt(_pullDistance * height)), _glowSize.value);
    _displacementTarget = crossAxisOffset / crossExtent;
    if (_displacementTarget != _displacement) {
        if (!_displacementTicker.isTicking) {
            assert(_displacementTickerLastElapsed == nullptr);
            _displacementTicker.start();
        }
    } else {
        _displacementTicker.stop();
        _displacementTickerLastElapsed = nullptr;
    }
    _glowController.duration = _pullTime;
    if (_state != _GlowState.pull) {
        _glowController.forward(0.0);
        _state = _GlowState.pull;
    } else {
        if (!_glowController.isAnimating) {
            assert(_glowController.value == 1.0);
            notifyListeners();
        }
    }
    _pullRecedeTimer = Timer(_pullHoldTime, );
}

void _GlowController::scrollEnd() {
    if (_state == _GlowState.pull) {
        _recede(_recedeTime);
    }
}

void _GlowController::paint(Canvas canvas, Size size) {
    if (_glowOpacity.value == 0.0) {
        return;
    }
    double baseGlowScale = size.width > size.height? size.height / size.width : 1.0;
    double radius = size.width * 3.0 / 2.0;
    double height = math.min(size.height, size.width * _widthToHeightFactor);
    double scaleY = _glowSize.value * baseGlowScale;
    Rect rect = Rect.fromLTWH(0.0, 0.0, size.width, height);
    Offset center = Offset((size.width / 2.0) * (0.5 + _displacement), height - radius);
    Paint paint = ;
    canvas.save();
    canvas.translate(0.0, _paintOffset + _paintOffsetScrollPixels);
    canvas.scale(1.0, scaleY);
    canvas.clipRect(rect);
    canvas.drawCircle(center, radius, paint);
    canvas.restore();
}

String _GlowController::toString() {
    return "_GlowController(color: $color, axis: ${describeEnum(axis)})";
}

_GlowController::_GlowController(Axis axis, Color color, TickerProvider vsync) {
    {
        assert(vsync != nullptr);
        assert(color != nullptr);
        assert(axis != nullptr);
        _color = color;
        _axis = axis;
    }
    {
        _glowController = ;
        Animation<double> decelerator = ;
        _glowOpacity = decelerator.drive(_glowOpacityTween);
        _glowSize = decelerator.drive(_glowSizeTween);
        _displacementTicker = vsync.createTicker(_tickDisplacement);
    }
}

void _GlowController::_changePhase(AnimationStatus status) {
    if (status != AnimationStatus.completed) {
        return;
    }
    ;
}

void _GlowController::_recede(Duration duration) {
    if (_state == _GlowState.recede || _state == _GlowState.idle) {
        return;
    }
    _pullRecedeTimer?.cancel();
    _pullRecedeTimer = nullptr;
    _glowOpacityTween.begin = _glowOpacity.value;
    _glowOpacityTween.end = 0.0;
    _glowSizeTween.begin = _glowSize.value;
    _glowSizeTween.end = 0.0;
    _glowController.duration = duration;
    _glowController.forward(0.0);
    _state = _GlowState.recede;
}

void _GlowController::_tickDisplacement(Duration elapsed) {
    if (_displacementTickerLastElapsed != nullptr) {
        double t = (elapsed.inMicroseconds - _displacementTickerLastElapsed!.inMicroseconds).toDouble();
        _displacement = _displacementTarget - (_displacementTarget - _displacement) * math.pow(2.0, -t / _crossAxisHalfTime.inMicroseconds);
        notifyListeners();
    }
    if (nearEqual(_displacementTarget, _displacement, Tolerance.defaultTolerance.distance)) {
        _displacementTicker.stop();
        _displacementTickerLastElapsed = nullptr;
    } else {
        _displacementTickerLastElapsed = elapsed;
    }
}

void _GlowingOverscrollIndicatorPainter::paint(Canvas canvas, Size size) {
    _paintSide(canvas, size, leadingController, axisDirection, GrowthDirection.reverse);
    _paintSide(canvas, size, trailingController, axisDirection, GrowthDirection.forward);
}

bool _GlowingOverscrollIndicatorPainter::shouldRepaint(_GlowingOverscrollIndicatorPainter oldDelegate) {
    return oldDelegate.leadingController != leadingController || oldDelegate.trailingController != trailingController;
}

String _GlowingOverscrollIndicatorPainter::toString() {
    return "_GlowingOverscrollIndicatorPainter($leadingController, $trailingController)";
}

void _GlowingOverscrollIndicatorPainter::_paintSide(AxisDirection axisDirection, Canvas canvas, _GlowController controller, GrowthDirection growthDirection, Size size) {
    if (controller == nullptr) {
        return;
    }
    ;
}

StretchingOverscrollIndicator::StretchingOverscrollIndicator(AxisDirection axisDirection, Widget child, Clip clipBehavior, Unknown, ScrollNotificationPredicate notificationPredicate) {
    {
        assert(axisDirection != nullptr);
        assert(notificationPredicate != nullptr);
        assert(clipBehavior != nullptr);
    }
}

Axis StretchingOverscrollIndicator::axis() {
    return axisDirectionToAxis(axisDirection);
}

State<StretchingOverscrollIndicator> StretchingOverscrollIndicator::createState() {
    return _StretchingOverscrollIndicatorState();
}

void StretchingOverscrollIndicator::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AxisDirection>EnumProperty("axisDirection", axisDirection));
}

void _StretchingOverscrollIndicatorState::dispose() {
    _stretchController.dispose();
    super.dispose();
}

Widget _StretchingOverscrollIndicatorState::build(BuildContext context) {
    Size size = MediaQuery.of(context).size;
    double mainAxisSize;
    return <ScrollNotification>NotificationListener(_handleScrollNotification, AnimatedBuilder(_stretchController, ));
}

bool _StretchingOverscrollIndicatorState::_handleScrollNotification(ScrollNotification notification) {
    if (!widget.notificationPredicate(notification)) {
        return false;
    }
    if (notification is OverscrollNotification) {
        _lastOverscrollNotification = notification;
        if (_lastNotification.runtimeType is! OverscrollNotification) {
            OverscrollIndicatorNotification confirmationNotification = OverscrollIndicatorNotification(notification.overscroll < 0.0);
            confirmationNotification.dispatch(context);
            _accepted = confirmationNotification.accepted;
        }
        assert(notification.metrics.axis == widget.axis);
        if (_accepted) {
            if (notification.velocity != 0.0) {
                assert(notification.dragDetails == nullptr);
                _stretchController.absorbImpact(notification.velocity.abs());
            } else {
                assert(notification.overscroll != 0.0);
                if (notification.dragDetails != nullptr) {
                    double viewportDimension = notification.metrics.viewportDimension;
                    double distanceForPull = (notification.overscroll.abs() / viewportDimension) + _stretchController.pullDistance;
                    double clampedOverscroll = clampDouble(distanceForPull, 0, 1.0);
                    _stretchController.pull(clampedOverscroll);
                }
            }
        }
    } else     {
        if (notification is ScrollEndNotification || notification is ScrollUpdateNotification) {
        _stretchController.scrollEnd();
    }
;
    }    _lastNotification = notification;
    return false;
}

AlignmentDirectional _StretchingOverscrollIndicatorState::_getAlignmentForAxisDirection(double overscroll) {
    ;
}

double _StretchController::pullDistance() {
    return _pullDistance;
}

double _StretchController::value() {
    return _stretchSize.value;
}

void _StretchController::absorbImpact(double velocity) {
    assert(velocity >= 0.0);
    velocity = clampDouble(velocity, 1, 10000);
    _stretchSizeTween.begin = _stretchSize.value;
    _stretchSizeTween.end = math.min(_stretchIntensity + (_flingFriction / velocity), 1.0);
    _stretchController.duration = Duration((velocity * 0.02).round());
    _stretchController.forward(0.0);
    _state = _StretchState.absorb;
}

void _StretchController::pull(double normalizedOverscroll) {
    assert(normalizedOverscroll >= 0.0);
    _pullDistance = normalizedOverscroll;
    _stretchSizeTween.begin = _stretchSize.value;
    double linearIntensity = _stretchIntensity * _pullDistance;
    double exponentialIntensity = _stretchIntensity * (1 - math.exp(-_pullDistance * _exponentialScalar));
    _stretchSizeTween.end = linearIntensity + exponentialIntensity;
    _stretchController.duration = _stretchDuration;
    if (_state != _StretchState.pull) {
        _stretchController.forward(0.0);
        _state = _StretchState.pull;
    } else {
        if (!_stretchController.isAnimating) {
            assert(_stretchController.value == 1.0);
            notifyListeners();
        }
    }
}

void _StretchController::scrollEnd() {
    if (_state == _StretchState.pull) {
        _recede(_stretchDuration);
    }
}

void _StretchController::dispose() {
    _stretchController.dispose();
    super.dispose();
}

String _StretchController::toString() {
    return "_StretchController()";
}

_StretchController::_StretchController(TickerProvider vsync) {
    {
        _stretchController = ;
        Animation<double> decelerator = ;
        _stretchSize = decelerator.drive(_stretchSizeTween);
    }
}

void _StretchController::_changePhase(AnimationStatus status) {
    if (status != AnimationStatus.completed) {
        return;
    }
    ;
}

void _StretchController::_recede(Duration duration) {
    if (_state == _StretchState.recede || _state == _StretchState.idle) {
        return;
    }
    _stretchSizeTween.begin = _stretchSize.value;
    _stretchSizeTween.end = 0.0;
    _stretchController.duration = duration;
    _stretchController.forward(0.0);
    _state = _StretchState.recede;
}

void OverscrollIndicatorNotification::disallowGlow() {
    accepted = false;
}

void OverscrollIndicatorNotification::disallowIndicator() {
    accepted = false;
}

void OverscrollIndicatorNotification::debugFillDescription(List<String> description) {
    super.debugFillDescription(description);
    description.add("side: ${leading ? "leading edge" : "trailing edge"}");
}
