#include "scroll_activity.hpp"
ScrollActivityDelegate ScrollActivityCls::delegate() {
    return _delegate;
}

void ScrollActivityCls::updateDelegate(ScrollActivityDelegate value) {
    assert(_delegate != value);
    _delegate = value;
}

void ScrollActivityCls::resetActivity() {
}

void ScrollActivityCls::dispatchScrollStartNotification(ScrollMetrics metrics, BuildContext context) {
    make<ScrollStartNotificationCls>(metrics, context)->dispatch(context);
}

void ScrollActivityCls::dispatchScrollUpdateNotification(ScrollMetrics metrics, BuildContext context, double scrollDelta) {
    make<ScrollUpdateNotificationCls>(metrics, context, scrollDelta)->dispatch(context);
}

void ScrollActivityCls::dispatchOverscrollNotification(ScrollMetrics metrics, BuildContext context, double overscroll) {
    make<OverscrollNotificationCls>(metrics, context, overscroll)->dispatch(context);
}

void ScrollActivityCls::dispatchScrollEndNotification(ScrollMetrics metrics, BuildContext context) {
    make<ScrollEndNotificationCls>(metrics, context)->dispatch(context);
}

void ScrollActivityCls::applyNewDimensions() {
}

void ScrollActivityCls::dispose() {
}

String ScrollActivityCls::toString() {
    return describeIdentity(this);
}

void IdleScrollActivityCls::applyNewDimensions() {
    delegate->goBallistic(0.0);
}

bool IdleScrollActivityCls::shouldIgnorePointer() {
    return false;
}

bool IdleScrollActivityCls::isScrolling() {
    return false;
}

double IdleScrollActivityCls::velocity() {
    return 0.0;
}

HoldScrollActivityCls::HoldScrollActivityCls(ScrollActivityDelegate delegate, VoidCallback onHoldCanceled) : ScrollActivity(delegate) {
}

bool HoldScrollActivityCls::shouldIgnorePointer() {
    return false;
}

bool HoldScrollActivityCls::isScrolling() {
    return false;
}

double HoldScrollActivityCls::velocity() {
    return 0.0;
}

void HoldScrollActivityCls::cancel() {
    delegate->goBallistic(0.0);
}

void HoldScrollActivityCls::dispose() {
    onHoldCanceled?->call();
    super->dispose();
}

ScrollDragControllerCls::ScrollDragControllerCls(double carriedVelocity, ScrollActivityDelegate delegate, DragStartDetails details, double motionStartDistanceThreshold, VoidCallback onDragCanceled) {
    {
        assert(delegate != nullptr);
        assert(details != nullptr);
        assert(motionStartDistanceThreshold == nullptr || motionStartDistanceThreshold > 0.0, __s("motionStartDistanceThreshold must be a positive number or null"));
        _delegate = delegate;
        _lastDetails = details;
        _retainMomentum = carriedVelocity != nullptr && carriedVelocity != 0.0;
        _lastNonStationaryTimestamp = details->sourceTimeStamp;
        _offsetSinceLastStop = motionStartDistanceThreshold == nullptr? nullptr : 0.0;
    }
}

ScrollActivityDelegate ScrollDragControllerCls::delegate() {
    return _delegate;
}

void ScrollDragControllerCls::updateDelegate(ScrollActivityDelegate value) {
    assert(_delegate != value);
    _delegate = value;
}

void ScrollDragControllerCls::update(DragUpdateDetails details) {
    assert(details->primaryDelta != nullptr);
    _lastDetails = details;
    double offset = details->primaryDelta!;
    if (offset != 0.0) {
        _lastNonStationaryTimestamp = details->sourceTimeStamp;
    }
    _maybeLoseMomentum(offset, details->sourceTimeStamp);
    offset = _adjustForScrollStartThreshold(offset, details->sourceTimeStamp);
    if (offset == 0.0) {
        return;
    }
    if (_reversed()) {
        offset = -offset;
    }
    delegate()->applyUserOffset(offset);
}

void ScrollDragControllerCls::end(DragEndDetails details) {
    assert(details->primaryVelocity != nullptr);
    double velocity = -details->primaryVelocity!;
    if (_reversed()) {
        velocity = -velocity;
    }
    _lastDetails = details;
    if (_retainMomentum) {
        bool isFlingingInSameDirection = velocity->sign() == carriedVelocity!->sign();
        bool isVelocityNotSubstantiallyLessThanCarriedMomentum = velocity->abs() > carriedVelocity!->abs() * momentumRetainVelocityThresholdFactor;
        if (isFlingingInSameDirection && isVelocityNotSubstantiallyLessThanCarriedMomentum) {
            velocity += carriedVelocity!;
        }
    }
    delegate()->goBallistic(velocity);
}

void ScrollDragControllerCls::cancel() {
    delegate()->goBallistic(0.0);
}

void ScrollDragControllerCls::dispose() {
    _lastDetails = nullptr;
    onDragCanceled?->call();
}

dynamic ScrollDragControllerCls::lastDetails() {
    return _lastDetails;
}

String ScrollDragControllerCls::toString() {
    return describeIdentity(this);
}

bool ScrollDragControllerCls::_reversed() {
    return axisDirectionIsReversed(delegate()->axisDirection());
}

void ScrollDragControllerCls::_maybeLoseMomentum(double offset, Duration timestamp) {
    if (_retainMomentum && offset == 0.0 && (timestamp == nullptr || timestamp - _lastNonStationaryTimestamp! > momentumRetainStationaryDurationThreshold)) {
        _retainMomentum = false;
    }
}

double ScrollDragControllerCls::_adjustForScrollStartThreshold(double offset, Duration timestamp) {
    if (timestamp == nullptr) {
        return offset;
    }
    if (offset == 0.0) {
        if (motionStartDistanceThreshold != nullptr && _offsetSinceLastStop == nullptr && timestamp - _lastNonStationaryTimestamp! > motionStoppedDurationThreshold) {
            _offsetSinceLastStop = 0.0;
        }
        return 0.0;
    } else {
        if (_offsetSinceLastStop == nullptr) {
            return offset;
        } else {
            _offsetSinceLastStop = _offsetSinceLastStop! + offset;
            if (_offsetSinceLastStop!->abs() > motionStartDistanceThreshold!) {
                _offsetSinceLastStop = nullptr;
                if (offset->abs() > _bigThresholdBreakDistance) {
                    return offset;
                } else {
                    return math->min(motionStartDistanceThreshold! / 3.0, offset->abs()) * offset->sign();
                }
            } else {
                return 0.0;
            }
        }
    }
}

DragScrollActivityCls::DragScrollActivityCls(Unknown delegate, ScrollDragController controller) {
    {
        _controller = controller;
    }
}

void DragScrollActivityCls::dispatchScrollStartNotification(ScrollMetrics metrics, BuildContext context) {
    dynamic lastDetails = _controller!->lastDetails();
    assert(is<DragStartDetails>(lastDetails));
    make<ScrollStartNotificationCls>(metrics, context, as<DragStartDetails>(lastDetails))->dispatch(context);
}

void DragScrollActivityCls::dispatchScrollUpdateNotification(ScrollMetrics metrics, BuildContext context, double scrollDelta) {
    dynamic lastDetails = _controller!->lastDetails();
    assert(is<DragUpdateDetails>(lastDetails));
    make<ScrollUpdateNotificationCls>(metrics, context, scrollDelta, as<DragUpdateDetails>(lastDetails))->dispatch(context);
}

void DragScrollActivityCls::dispatchOverscrollNotification(ScrollMetrics metrics, BuildContext context, double overscroll) {
    dynamic lastDetails = _controller!->lastDetails();
    assert(is<DragUpdateDetails>(lastDetails));
    make<OverscrollNotificationCls>(metrics, context, overscroll, as<DragUpdateDetails>(lastDetails))->dispatch(context);
}

void DragScrollActivityCls::dispatchScrollEndNotification(ScrollMetrics metrics, BuildContext context) {
    dynamic lastDetails = _controller!->lastDetails();
    make<ScrollEndNotificationCls>(metrics, context, is<DragEndDetails>(lastDetails)? lastDetails : nullptr)->dispatch(context);
}

bool DragScrollActivityCls::shouldIgnorePointer() {
    return true;
}

bool DragScrollActivityCls::isScrolling() {
    return true;
}

double DragScrollActivityCls::velocity() {
    return 0.0;
}

void DragScrollActivityCls::dispose() {
    _controller = nullptr;
    super->dispose();
}

String DragScrollActivityCls::toString() {
    return __s("${describeIdentity(this)}($_controller)");
}

BallisticScrollActivityCls::BallisticScrollActivityCls(Unknown delegate, Simulation simulation, TickerProvider vsync) {
    {
            auto _c1 = AnimationControllerCls->unbounded(kDebugMode? objectRuntimeType(this, __s("BallisticScrollActivity")) : nullptr, vsync);    _c1.auto _c2 = addListener(_tick);    _c2.animateWith(simulation)->whenComplete(_end);    _c2;_controller = _c1;
    }
}

void BallisticScrollActivityCls::resetActivity() {
    delegate->goBallistic(velocity());
}

void BallisticScrollActivityCls::applyNewDimensions() {
    delegate->goBallistic(velocity());
}

bool BallisticScrollActivityCls::applyMoveTo(double value) {
    return delegate->setPixels(value)->abs() < precisionErrorTolerance;
}

void BallisticScrollActivityCls::dispatchOverscrollNotification(ScrollMetrics metrics, BuildContext context, double overscroll) {
    make<OverscrollNotificationCls>(metrics, context, overscroll, velocity())->dispatch(context);
}

bool BallisticScrollActivityCls::shouldIgnorePointer() {
    return true;
}

bool BallisticScrollActivityCls::isScrolling() {
    return true;
}

double BallisticScrollActivityCls::velocity() {
    return _controller->velocity();
}

void BallisticScrollActivityCls::dispose() {
    _controller->dispose();
    super->dispose();
}

String BallisticScrollActivityCls::toString() {
    return __s("${describeIdentity(this)}($_controller)");
}

void BallisticScrollActivityCls::_tick() {
    if (!applyMoveTo(_controller->value())) {
        delegate->goIdle();
    }
}

void BallisticScrollActivityCls::_end() {
    delegate->goBallistic(0.0);
}

DrivenScrollActivityCls::DrivenScrollActivityCls(Unknown delegate, Curve curve, Duration duration, double from, double to, TickerProvider vsync) {
    {
        assert(from != nullptr);
        assert(to != nullptr);
        assert(duration != nullptr);
        assert(duration > DurationCls::zero);
        assert(curve != nullptr);
    }
    {
        _completer = <void>make<CompleterCls>();
            auto _c1 = AnimationControllerCls->unbounded(from, objectRuntimeType(this, __s("DrivenScrollActivity")), vsync);    _c1.auto _c2 = addListener(_tick);    _c2.animateTo(to, duration, curve)->whenComplete(_end);    _c2;_controller = _c1;
    }
}

Future<void> DrivenScrollActivityCls::done() {
    return _completer->future;
}

void DrivenScrollActivityCls::dispatchOverscrollNotification(ScrollMetrics metrics, BuildContext context, double overscroll) {
    make<OverscrollNotificationCls>(metrics, context, overscroll, velocity())->dispatch(context);
}

bool DrivenScrollActivityCls::shouldIgnorePointer() {
    return true;
}

bool DrivenScrollActivityCls::isScrolling() {
    return true;
}

double DrivenScrollActivityCls::velocity() {
    return _controller->velocity();
}

void DrivenScrollActivityCls::dispose() {
    _completer->complete();
    _controller->dispose();
    super->dispose();
}

String DrivenScrollActivityCls::toString() {
    return __s("${describeIdentity(this)}($_controller)");
}

void DrivenScrollActivityCls::_tick() {
    if (delegate->setPixels(_controller->value()) != 0.0) {
        delegate->goIdle();
    }
}

void DrivenScrollActivityCls::_end() {
    delegate->goBallistic(velocity());
}
