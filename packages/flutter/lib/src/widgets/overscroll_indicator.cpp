#include "overscroll_indicator.hpp"
GlowingOverscrollIndicatorCls::GlowingOverscrollIndicatorCls(AxisDirection axisDirection, Widget child, Color color, Key key, ScrollNotificationPredicate notificationPredicate, bool showLeading, bool showTrailing) {
    {
        assert(showLeading != nullptr);
        assert(showTrailing != nullptr);
        assert(axisDirection != nullptr);
        assert(color != nullptr);
        assert(notificationPredicate != nullptr);
    }
}

Axis GlowingOverscrollIndicatorCls::axis() {
    return axisDirectionToAxis(axisDirection);
}

State<GlowingOverscrollIndicator> GlowingOverscrollIndicatorCls::createState() {
    return make<_GlowingOverscrollIndicatorStateCls>();
}

void GlowingOverscrollIndicatorCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AxisDirection>make<EnumPropertyCls>(__s("axisDirection"), axisDirection));
    String showDescription;
    if (showLeading && showTrailing) {
        showDescription = __s("both sides");
    } else {
        if (showLeading) {
        showDescription = __s("leading side only");
    } else {
        if (showTrailing) {
        showDescription = __s("trailing side only");
    } else {
        showDescription = __s("neither side (!)");
    }
;
    };
    }    properties->add(make<MessagePropertyCls>(__s("show"), showDescription));
    properties->add(make<ColorPropertyCls>(__s("color"), color, false));
}

void _GlowingOverscrollIndicatorStateCls::initState() {
    super->initState();
    _leadingController = make<_GlowControllerCls>(this, widget()->color, widget()->axis);
    _trailingController = make<_GlowControllerCls>(this, widget()->color, widget()->axis);
    _leadingAndTrailingListener = ListenableCls->merge(makeList(ArrayItem, ArrayItem));
}

void _GlowingOverscrollIndicatorStateCls::didUpdateWidget(GlowingOverscrollIndicator oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (oldWidget->color != widget()->color || oldWidget->axis() != widget()->axis) {
        _leadingController!->color() = widget()->color;
        _leadingController!->axis() = widget()->axis;
        _trailingController!->color() = widget()->color;
        _trailingController!->axis() = widget()->axis;
    }
}

void _GlowingOverscrollIndicatorStateCls::dispose() {
    _leadingController!->dispose();
    _trailingController!->dispose();
    super->dispose();
}

Widget _GlowingOverscrollIndicatorStateCls::build(BuildContext context) {
    return <ScrollNotification>make<NotificationListenerCls>(_handleScrollNotification, make<RepaintBoundaryCls>(make<CustomPaintCls>(make<_GlowingOverscrollIndicatorPainterCls>(widget()->showLeading? _leadingController : nullptr, widget()->showTrailing? _trailingController : nullptr, widget()->axisDirection, _leadingAndTrailingListener), make<RepaintBoundaryCls>(widget()->child))));
}

bool _GlowingOverscrollIndicatorStateCls::_handleScrollNotification(ScrollNotification notification) {
    if (!widget()->notificationPredicate(notification)) {
        return false;
    }
    _leadingController!->_paintOffsetScrollPixels = -math->min(notification->metrics->pixels() - notification->metrics->minScrollExtent(), _leadingController!->_paintOffset);
    _trailingController!->_paintOffsetScrollPixels = -math->min(notification->metrics->maxScrollExtent() - notification->metrics->pixels(), _trailingController!->_paintOffset);
    if (is<OverscrollNotification>(notification)) {
        _GlowController controller;
        if (as<OverscrollNotificationCls>(notification)->overscroll < 0.0) {
            controller = _leadingController;
        } else {
            if (notification->overscroll > 0.0) {
            controller = _trailingController;
        } else {
            assert(false);
        }
;
        }        bool isLeading = controller == _leadingController;
        if (!is<OverscrollNotification>(_lastNotificationType)) {
            OverscrollIndicatorNotification confirmationNotification = make<OverscrollIndicatorNotificationCls>(isLeading);
            confirmationNotification->dispatch(context());
            _accepted[isLeading] = confirmationNotification->accepted;
            if (_accepted[isLeading]!) {
                controller!->_paintOffset = confirmationNotification->paintOffset;
            }
        }
        assert(controller != nullptr);
        assert(as<OverscrollNotificationCls>(notification)->metrics->axis() == widget()->axis);
        if (_accepted[isLeading]!) {
            if (notification->velocity != 0.0) {
                assert(notification->dragDetails == nullptr);
                controller!->absorbImpact(notification->velocity->abs());
            } else {
                assert(notification->overscroll != 0.0);
                if (notification->dragDetails != nullptr) {
                    assert(notification->dragDetails!->globalPosition != nullptr);
                    RenderBox renderer = as<RenderBox>(notification->context!->findRenderObject()!);
                    assert(renderer != nullptr);
                    assert(renderer->hasSize());
                    Size size = renderer->size();
                    Offset position = renderer->globalToLocal(notification->dragDetails!->globalPosition);
                    ;
                }
            }
        }
    } else {
        if (is<ScrollEndNotification>(notification) || is<ScrollUpdateNotification>(notification)) {
        if ((as<dynamic>(notification))->dragDetails != nullptr) {
            _leadingController!->scrollEnd();
            _trailingController!->scrollEnd();
        }
    }
;
    }    _lastNotificationType = notification->runtimeType;
    return false;
}

Color _GlowControllerCls::color() {
    return _color;
}

void _GlowControllerCls::color(Color value) {
    assert(color() != nullptr);
    if (color() == value) {
        return;
    }
    _color = value;
    notifyListeners();
}

Axis _GlowControllerCls::axis() {
    return _axis;
}

void _GlowControllerCls::axis(Axis value) {
    assert(axis() != nullptr);
    if (axis() == value) {
        return;
    }
    _axis = value;
    notifyListeners();
}

void _GlowControllerCls::dispose() {
    _glowController->dispose();
    _displacementTicker->dispose();
    _pullRecedeTimer?->cancel();
    super->dispose();
}

void _GlowControllerCls::absorbImpact(double velocity) {
    assert(velocity >= 0.0);
    _pullRecedeTimer?->cancel();
    _pullRecedeTimer = nullptr;
    velocity = clampDouble(velocity, _minVelocity, _maxVelocity);
    _glowOpacityTween->begin = _state == _GlowStateCls::idle? 0.3 : _glowOpacity->value();
    _glowOpacityTween->end = clampDouble(velocity * _velocityGlowFactor, _glowOpacityTween->begin!, _maxOpacity);
    _glowSizeTween->begin = _glowSize->value();
    _glowSizeTween->end = math->min(0.025 + 7.5e-7 * velocity * velocity, 1.0);
    _glowController->duration = make<DurationCls>((0.15 + velocity * 0.02)->round());
    _glowController->forward(0.0);
    _displacement = 0.5;
    _state = _GlowStateCls::absorb;
}

void _GlowControllerCls::pull(double overscroll, double extent, double crossAxisOffset, double crossExtent) {
    _pullRecedeTimer?->cancel();
    _pullDistance += overscroll / 200.0;
    _glowOpacityTween->begin = _glowOpacity->value();
    _glowOpacityTween->end = math->min(_glowOpacity->value() + overscroll / extent * _pullOpacityGlowFactor, _maxOpacity);
    double height = math->min(extent, crossExtent * _widthToHeightFactor);
    _glowSizeTween->begin = _glowSize->value();
    _glowSizeTween->end = math->max(1.0 - 1.0 / (0.7 * math->sqrt(_pullDistance * height)), _glowSize->value());
    _displacementTarget = crossAxisOffset / crossExtent;
    if (_displacementTarget != _displacement) {
        if (!_displacementTicker->isTicking()) {
            assert(_displacementTickerLastElapsed == nullptr);
            _displacementTicker->start();
        }
    } else {
        _displacementTicker->stop();
        _displacementTickerLastElapsed = nullptr;
    }
    _glowController->duration = _pullTime;
    if (_state != _GlowStateCls::pull) {
        _glowController->forward(0.0);
        _state = _GlowStateCls::pull;
    } else {
        if (!_glowController->isAnimating()) {
            assert(_glowController->value() == 1.0);
            notifyListeners();
        }
    }
    _pullRecedeTimer = make<TimerCls>(_pullHoldTime, [=] () {
        _recede(_pullDecayTime);
    });
}

void _GlowControllerCls::scrollEnd() {
    if (_state == _GlowStateCls::pull) {
        _recede(_recedeTime);
    }
}

void _GlowControllerCls::paint(Canvas canvas, Size size) {
    if (_glowOpacity->value() == 0.0) {
        return;
    }
    double baseGlowScale = size->width() > size->height()? size->height() / size->width() : 1.0;
    double radius = size->width() * 3.0 / 2.0;
    double height = math->min(size->height(), size->width() * _widthToHeightFactor);
    double scaleY = _glowSize->value() * baseGlowScale;
    Rect rect = RectCls->fromLTWH(0.0, 0.0, size->width(), height);
    Offset center = make<OffsetCls>((size->width() / 2.0) * (0.5 + _displacement), height - radius);
    auto _c1 = make<PaintCls>();_c1.color() = color()->withOpacity(_glowOpacity->value());Paint paint = _c1;
    canvas->save();
    canvas->translate(0.0, _paintOffset + _paintOffsetScrollPixels);
    canvas->scale(1.0, scaleY);
    canvas->clipRect(rect);
    canvas->drawCircle(center, radius, paint);
    canvas->restore();
}

String _GlowControllerCls::toString() {
    return __sf("_GlowController(color: %s, axis: %s)", color(), describeEnum(axis()));
}

_GlowControllerCls::_GlowControllerCls(Axis axis, Color color, TickerProvider vsync) {
    {
        assert(vsync != nullptr);
        assert(color != nullptr);
        assert(axis != nullptr);
        _color = color;
        _axis = axis;
    }
    {
            auto _c1 = make<AnimationControllerCls>(vsync);    _c1.addStatusListener(_changePhase);_glowController = _c1;
            auto _c2 = make<CurvedAnimationCls>(_glowController, CurvesCls::decelerate);    _c2.addListener(notifyListeners);Animation<double> decelerator = _c2;
        _glowOpacity = decelerator->drive(_glowOpacityTween);
        _glowSize = decelerator->drive(_glowSizeTween);
        _displacementTicker = vsync->createTicker(_tickDisplacement);
    }
}

void _GlowControllerCls::_changePhase(AnimationStatus status) {
    if (status != AnimationStatusCls::completed) {
        return;
    }
    ;
}

void _GlowControllerCls::_recede(Duration duration) {
    if (_state == _GlowStateCls::recede || _state == _GlowStateCls::idle) {
        return;
    }
    _pullRecedeTimer?->cancel();
    _pullRecedeTimer = nullptr;
    _glowOpacityTween->begin = _glowOpacity->value();
    _glowOpacityTween->end = 0.0;
    _glowSizeTween->begin = _glowSize->value();
    _glowSizeTween->end = 0.0;
    _glowController->duration = duration;
    _glowController->forward(0.0);
    _state = _GlowStateCls::recede;
}

void _GlowControllerCls::_tickDisplacement(Duration elapsed) {
    if (_displacementTickerLastElapsed != nullptr) {
        double t = (elapsed->inMicroseconds() - _displacementTickerLastElapsed!->inMicroseconds())->toDouble();
        _displacement = _displacementTarget - (_displacementTarget - _displacement) * math->pow(2.0, -t / _crossAxisHalfTime->inMicroseconds());
        notifyListeners();
    }
    if (nearEqual(_displacementTarget, _displacement, ToleranceCls::defaultTolerance->distance)) {
        _displacementTicker->stop();
        _displacementTickerLastElapsed = nullptr;
    } else {
        _displacementTickerLastElapsed = elapsed;
    }
}

void _GlowingOverscrollIndicatorPainterCls::paint(Canvas canvas, Size size) {
    _paintSide(canvas, size, leadingController, axisDirection, GrowthDirectionCls::reverse);
    _paintSide(canvas, size, trailingController, axisDirection, GrowthDirectionCls::forward);
}

bool _GlowingOverscrollIndicatorPainterCls::shouldRepaint(_GlowingOverscrollIndicatorPainter oldDelegate) {
    return oldDelegate->leadingController != leadingController || oldDelegate->trailingController != trailingController;
}

String _GlowingOverscrollIndicatorPainterCls::toString() {
    return __sf("_GlowingOverscrollIndicatorPainter(%s, %s)", leadingController, trailingController);
}

void _GlowingOverscrollIndicatorPainterCls::_paintSide(Canvas canvas, Size size, _GlowController controller, AxisDirection axisDirection, GrowthDirection growthDirection) {
    if (controller == nullptr) {
        return;
    }
    ;
}

StretchingOverscrollIndicatorCls::StretchingOverscrollIndicatorCls(AxisDirection axisDirection, Widget child, Clip clipBehavior, Key key, ScrollNotificationPredicate notificationPredicate) {
    {
        assert(axisDirection != nullptr);
        assert(notificationPredicate != nullptr);
        assert(clipBehavior != nullptr);
    }
}

Axis StretchingOverscrollIndicatorCls::axis() {
    return axisDirectionToAxis(axisDirection);
}

State<StretchingOverscrollIndicator> StretchingOverscrollIndicatorCls::createState() {
    return make<_StretchingOverscrollIndicatorStateCls>();
}

void StretchingOverscrollIndicatorCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AxisDirection>make<EnumPropertyCls>(__s("axisDirection"), axisDirection));
}

void _StretchingOverscrollIndicatorStateCls::dispose() {
    _stretchController->dispose();
    super->dispose();
}

Widget _StretchingOverscrollIndicatorStateCls::build(BuildContext context) {
    Size size = MediaQueryCls->of(context)->size;
    double mainAxisSize;
    return <ScrollNotification>make<NotificationListenerCls>(_handleScrollNotification, make<AnimatedBuilderCls>(_stretchController, [=] (BuildContext context,Widget child) {
        double stretch = _stretchController->value();
        double x = 1.0;
        double y = 1.0;
        ;
        AlignmentDirectional alignment = _getAlignmentForAxisDirection(_lastOverscrollNotification?->overscroll | 0.0);
        double viewportDimension = _lastOverscrollNotification?->metrics->viewportDimension() | mainAxisSize;
        Widget transform = make<TransformCls>(alignment, Matrix4Cls->diagonal3Values(x, y, 1.0), widget()->child);
        return make<ClipRectCls>(stretch != 0.0 && viewportDimension != mainAxisSize? widget()->clipBehavior : ClipCls::none, transform);
    }));
}

bool _StretchingOverscrollIndicatorStateCls::_handleScrollNotification(ScrollNotification notification) {
    if (!widget()->notificationPredicate(notification)) {
        return false;
    }
    if (is<OverscrollNotification>(notification)) {
        _lastOverscrollNotification = as<OverscrollNotificationCls>(notification);
        if (!is<OverscrollNotification>(_lastNotification->runtimeType)) {
            OverscrollIndicatorNotification confirmationNotification = make<OverscrollIndicatorNotificationCls>(notification->overscroll < 0.0);
            confirmationNotification->dispatch(context());
            _accepted = confirmationNotification->accepted;
        }
        assert(as<OverscrollNotificationCls>(notification)->metrics->axis() == widget()->axis);
        if (_accepted) {
            if (notification->velocity != 0.0) {
                assert(notification->dragDetails == nullptr);
                _stretchController->absorbImpact(notification->velocity->abs());
            } else {
                assert(notification->overscroll != 0.0);
                if (notification->dragDetails != nullptr) {
                    double viewportDimension = notification->metrics->viewportDimension();
                    double distanceForPull = (notification->overscroll->abs() / viewportDimension) + _stretchController->pullDistance();
                    double clampedOverscroll = clampDouble(distanceForPull, 0, 1.0);
                    _stretchController->pull(clampedOverscroll);
                }
            }
        }
    } else {
        if (is<ScrollEndNotification>(notification) || is<ScrollUpdateNotification>(notification)) {
        _stretchController->scrollEnd();
    }
;
    }    _lastNotification = notification;
    return false;
}

AlignmentDirectional _StretchingOverscrollIndicatorStateCls::_getAlignmentForAxisDirection(double overscroll) {
    ;
}

double _StretchControllerCls::pullDistance() {
    return _pullDistance;
}

double _StretchControllerCls::value() {
    return _stretchSize->value();
}

void _StretchControllerCls::absorbImpact(double velocity) {
    assert(velocity >= 0.0);
    velocity = clampDouble(velocity, 1, 10000);
    _stretchSizeTween->begin = _stretchSize->value();
    _stretchSizeTween->end = math->min(_stretchIntensity + (_flingFriction / velocity), 1.0);
    _stretchController->duration = make<DurationCls>((velocity * 0.02)->round());
    _stretchController->forward(0.0);
    _state = _StretchStateCls::absorb;
}

void _StretchControllerCls::pull(double normalizedOverscroll) {
    assert(normalizedOverscroll >= 0.0);
    _pullDistance = normalizedOverscroll;
    _stretchSizeTween->begin = _stretchSize->value();
    double linearIntensity = _stretchIntensity * _pullDistance;
    double exponentialIntensity = _stretchIntensity * (1 - math->exp(-_pullDistance * _exponentialScalar));
    _stretchSizeTween->end = linearIntensity + exponentialIntensity;
    _stretchController->duration = _stretchDuration;
    if (_state != _StretchStateCls::pull) {
        _stretchController->forward(0.0);
        _state = _StretchStateCls::pull;
    } else {
        if (!_stretchController->isAnimating()) {
            assert(_stretchController->value() == 1.0);
            notifyListeners();
        }
    }
}

void _StretchControllerCls::scrollEnd() {
    if (_state == _StretchStateCls::pull) {
        _recede(_stretchDuration);
    }
}

void _StretchControllerCls::dispose() {
    _stretchController->dispose();
    super->dispose();
}

String _StretchControllerCls::toString() {
    return __s("_StretchController()");
}

_StretchControllerCls::_StretchControllerCls(TickerProvider vsync) {
    {
            auto _c1 = make<AnimationControllerCls>(vsync);    _c1.addStatusListener(_changePhase);_stretchController = _c1;
            auto _c2 = make<CurvedAnimationCls>(_stretchController, CurvesCls::decelerate);    _c2.addListener(notifyListeners);Animation<double> decelerator = _c2;
        _stretchSize = decelerator->drive(_stretchSizeTween);
    }
}

void _StretchControllerCls::_changePhase(AnimationStatus status) {
    if (status != AnimationStatusCls::completed) {
        return;
    }
    ;
}

void _StretchControllerCls::_recede(Duration duration) {
    if (_state == _StretchStateCls::recede || _state == _StretchStateCls::idle) {
        return;
    }
    _stretchSizeTween->begin = _stretchSize->value();
    _stretchSizeTween->end = 0.0;
    _stretchController->duration = duration;
    _stretchController->forward(0.0);
    _state = _StretchStateCls::recede;
}

void OverscrollIndicatorNotificationCls::disallowGlow() {
    accepted = false;
}

void OverscrollIndicatorNotificationCls::disallowIndicator() {
    accepted = false;
}

void OverscrollIndicatorNotificationCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    description->add(__sf("side: %s", leading? __s("leading edge") : __s("trailing edge")));
}
