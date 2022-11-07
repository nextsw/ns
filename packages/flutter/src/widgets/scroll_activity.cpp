#include "scroll_activity.hpp"
ScrollActivityDelegate ScrollActivity::delegate() {
    return _delegate;
}

void ScrollActivity::updateDelegate(ScrollActivityDelegate value) {
    assert(_delegate != value);
    _delegate = value;
}

void ScrollActivity::resetActivity() {
}

void ScrollActivity::dispatchScrollStartNotification(BuildContext context, ScrollMetrics metrics) {
    ScrollStartNotification(metrics, context).dispatch(context);
}

void ScrollActivity::dispatchScrollUpdateNotification(BuildContext context, ScrollMetrics metrics, double scrollDelta) {
    ScrollUpdateNotification(metrics, context, scrollDelta).dispatch(context);
}

void ScrollActivity::dispatchOverscrollNotification(BuildContext context, ScrollMetrics metrics, double overscroll) {
    OverscrollNotification(metrics, context, overscroll).dispatch(context);
}

void ScrollActivity::dispatchScrollEndNotification(BuildContext context, ScrollMetrics metrics) {
    ScrollEndNotification(metrics, context).dispatch(context);
}

void ScrollActivity::applyNewDimensions() {
}

void ScrollActivity::dispose() {
}

String ScrollActivity::toString() {
    return describeIdentity(this);
}

void IdleScrollActivity::applyNewDimensions() {
    delegate.goBallistic(0.0);
}

bool IdleScrollActivity::shouldIgnorePointer() {
    return false;
}

bool IdleScrollActivity::isScrolling() {
    return false;
}

double IdleScrollActivity::velocity() {
    return 0.0;
}

HoldScrollActivity::HoldScrollActivity(ScrollActivityDelegate delegate, VoidCallback onHoldCanceled) {
    {
        super(delegate);
    }
}

bool HoldScrollActivity::shouldIgnorePointer() {
    return false;
}

bool HoldScrollActivity::isScrolling() {
    return false;
}

double HoldScrollActivity::velocity() {
    return 0.0;
}

void HoldScrollActivity::cancel() {
    delegate.goBallistic(0.0);
}

void HoldScrollActivity::dispose() {
    onHoldCanceled?.call();
    super.dispose();
}

ScrollDragController::ScrollDragController(double carriedVelocity, ScrollActivityDelegate delegate, DragStartDetails details, double motionStartDistanceThreshold, VoidCallback onDragCanceled) {
    {
        assert(delegate != nullptr);
        assert(details != nullptr);
        assert(motionStartDistanceThreshold == nullptr || motionStartDistanceThreshold > 0.0, "motionStartDistanceThreshold must be a positive number or null");
        _delegate = delegate;
        _lastDetails = details;
        _retainMomentum = carriedVelocity != nullptr && carriedVelocity != 0.0;
        _lastNonStationaryTimestamp = details.sourceTimeStamp;
        _offsetSinceLastStop = motionStartDistanceThreshold == nullptr? nullptr : 0.0;
    }
}

ScrollActivityDelegate ScrollDragController::delegate() {
    return _delegate;
}

void ScrollDragController::updateDelegate(ScrollActivityDelegate value) {
    assert(_delegate != value);
    _delegate = value;
}

void ScrollDragController::update(DragUpdateDetails details) {
    assert(details.primaryDelta != nullptr);
    _lastDetails = details;
    double offset = details.primaryDelta!;
    if (offset != 0.0) {
        _lastNonStationaryTimestamp = details.sourceTimeStamp;
    }
    _maybeLoseMomentum(offset, details.sourceTimeStamp);
    offset = _adjustForScrollStartThreshold(offset, details.sourceTimeStamp);
    if (offset == 0.0) {
        return;
    }
    if (_reversed) {
        offset = -offset;
    }
    delegate.applyUserOffset(offset);
}

void ScrollDragController::end(DragEndDetails details) {
    assert(details.primaryVelocity != nullptr);
    double velocity = -details.primaryVelocity!;
    if (_reversed) {
        velocity = -velocity;
    }
    _lastDetails = details;
    if (_retainMomentum) {
        bool isFlingingInSameDirection = velocity.sign == carriedVelocity!.sign;
        bool isVelocityNotSubstantiallyLessThanCarriedMomentum = velocity.abs() > carriedVelocity!.abs() * momentumRetainVelocityThresholdFactor;
        if (isFlingingInSameDirection && isVelocityNotSubstantiallyLessThanCarriedMomentum) {
            velocity = carriedVelocity!;
        }
    }
    delegate.goBallistic(velocity);
}

void ScrollDragController::cancel() {
    delegate.goBallistic(0.0);
}

void ScrollDragController::dispose() {
    _lastDetails = nullptr;
    onDragCanceled?.call();
}

dynamic ScrollDragController::lastDetails() {
    return _lastDetails;
}

String ScrollDragController::toString() {
    return describeIdentity(this);
}

bool ScrollDragController::_reversed() {
    return axisDirectionIsReversed(delegate.axisDirection);
}

void ScrollDragController::_maybeLoseMomentum(double offset, Duration timestamp) {
    if (_retainMomentum && offset == 0.0 && (timestamp == nullptr || timestamp - _lastNonStationaryTimestamp! > momentumRetainStationaryDurationThreshold)) {
        _retainMomentum = false;
    }
}

double ScrollDragController::_adjustForScrollStartThreshold(double offset, Duration timestamp) {
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
            if (_offsetSinceLastStop!.abs() > motionStartDistanceThreshold!) {
                _offsetSinceLastStop = nullptr;
                if (offset.abs() > _bigThresholdBreakDistance) {
                    return offset;
                } else {
                    return math.min(motionStartDistanceThreshold! / 3.0, offset.abs()) * offset.sign;
                }
            } else {
                return 0.0;
            }
        }
    }
}

DragScrollActivity::DragScrollActivity(ScrollDragController controller, Unknown) {
    {
        _controller = controller;
    }
}

void DragScrollActivity::dispatchScrollStartNotification(BuildContext context, ScrollMetrics metrics) {
    dynamic lastDetails = _controller!.lastDetails;
    assert(lastDetails is DragStartDetails);
    ScrollStartNotification(metrics, context, ().dispatch(context);
}

void DragScrollActivity::dispatchScrollUpdateNotification(BuildContext context, ScrollMetrics metrics, double scrollDelta) {
    dynamic lastDetails = _controller!.lastDetails;
    assert(lastDetails is DragUpdateDetails);
    ScrollUpdateNotification(metrics, context, scrollDelta, ().dispatch(context);
}

void DragScrollActivity::dispatchOverscrollNotification(BuildContext context, ScrollMetrics metrics, double overscroll) {
    dynamic lastDetails = _controller!.lastDetails;
    assert(lastDetails is DragUpdateDetails);
    OverscrollNotification(metrics, context, overscroll, ().dispatch(context);
}

void DragScrollActivity::dispatchScrollEndNotification(BuildContext context, ScrollMetrics metrics) {
    dynamic lastDetails = _controller!.lastDetails;
    ScrollEndNotification(metrics, context, lastDetails is DragEndDetails? lastDetails : nullptr).dispatch(context);
}

bool DragScrollActivity::shouldIgnorePointer() {
    return true;
}

bool DragScrollActivity::isScrolling() {
    return true;
}

double DragScrollActivity::velocity() {
    return 0.0;
}

void DragScrollActivity::dispose() {
    _controller = nullptr;
    super.dispose();
}

String DragScrollActivity::toString() {
    return "${describeIdentity(this)}($_controller)";
}

BallisticScrollActivity::BallisticScrollActivity(Unknown, Simulation simulation, TickerProvider vsync) {
    {
        _controller = ;
    }
}

void BallisticScrollActivity::resetActivity() {
    delegate.goBallistic(velocity);
}

void BallisticScrollActivity::applyNewDimensions() {
    delegate.goBallistic(velocity);
}

bool BallisticScrollActivity::applyMoveTo(double value) {
    return delegate.setPixels(value).abs() < precisionErrorTolerance;
}

void BallisticScrollActivity::dispatchOverscrollNotification(BuildContext context, ScrollMetrics metrics, double overscroll) {
    OverscrollNotification(metrics, context, overscroll, velocity).dispatch(context);
}

bool BallisticScrollActivity::shouldIgnorePointer() {
    return true;
}

bool BallisticScrollActivity::isScrolling() {
    return true;
}

double BallisticScrollActivity::velocity() {
    return _controller.velocity;
}

void BallisticScrollActivity::dispose() {
    _controller.dispose();
    super.dispose();
}

String BallisticScrollActivity::toString() {
    return "${describeIdentity(this)}($_controller)";
}

void BallisticScrollActivity::_tick() {
    if (!applyMoveTo(_controller.value)) {
        delegate.goIdle();
    }
}

void BallisticScrollActivity::_end() {
    delegate.goBallistic(0.0);
}

DrivenScrollActivity::DrivenScrollActivity(Curve curve, Unknown, Duration duration, double from, double to, TickerProvider vsync) {
    {
        assert(from != nullptr);
        assert(to != nullptr);
        assert(duration != nullptr);
        assert(duration > Duration.zero);
        assert(curve != nullptr);
    }
    {
        _completer = <void>Completer();
        _controller = ;
    }
}

Future<void> DrivenScrollActivity::done() {
    return _completer.future;
}

void DrivenScrollActivity::dispatchOverscrollNotification(BuildContext context, ScrollMetrics metrics, double overscroll) {
    OverscrollNotification(metrics, context, overscroll, velocity).dispatch(context);
}

bool DrivenScrollActivity::shouldIgnorePointer() {
    return true;
}

bool DrivenScrollActivity::isScrolling() {
    return true;
}

double DrivenScrollActivity::velocity() {
    return _controller.velocity;
}

void DrivenScrollActivity::dispose() {
    _completer.complete();
    _controller.dispose();
    super.dispose();
}

String DrivenScrollActivity::toString() {
    return "${describeIdentity(this)}($_controller)";
}

void DrivenScrollActivity::_tick() {
    if (delegate.setPixels(_controller.value) != 0.0) {
        delegate.goIdle();
    }
}

void DrivenScrollActivity::_end() {
    delegate.goBallistic(velocity);
}
