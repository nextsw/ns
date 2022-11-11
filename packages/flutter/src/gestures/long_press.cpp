#include "long_press.hpp"
LongPressDownDetailsCls::LongPressDownDetailsCls(Offset globalPosition, PointerDeviceKind kind, Offset localPosition) {
    {
        assert(globalPosition != nullptr);
        localPosition = localPosition or globalPosition;
    }
}

LongPressStartDetailsCls::LongPressStartDetailsCls(Offset globalPosition, Offset localPosition) {
    {
        assert(globalPosition != nullptr);
        localPosition = localPosition or globalPosition;
    }
}

LongPressMoveUpdateDetailsCls::LongPressMoveUpdateDetailsCls(Offset globalPosition, Offset localOffsetFromOrigin, Offset localPosition, Offset offsetFromOrigin) {
    {
        assert(globalPosition != nullptr);
        assert(offsetFromOrigin != nullptr);
        localPosition = localPosition or globalPosition;
        localOffsetFromOrigin = localOffsetFromOrigin or offsetFromOrigin;
    }
}

LongPressEndDetailsCls::LongPressEndDetailsCls(Offset globalPosition, Offset localPosition, Velocity velocity) {
    {
        assert(globalPosition != nullptr);
        localPosition = localPosition or globalPosition;
    }
}

LongPressGestureRecognizerCls::LongPressGestureRecognizerCls(Unknown debugOwner, Duration duration, Unknown kind, Unknown postAcceptSlopTolerance, Unknown supportedDevices) {
}

bool LongPressGestureRecognizerCls::isPointerAllowed(PointerDownEvent event) {
    ;
    return super->isPointerAllowed(event);
}

void LongPressGestureRecognizerCls::didExceedDeadline() {
    resolve(GestureDispositionCls::accepted);
    _longPressAccepted = true;
    super->acceptGesture(primaryPointer!);
    _checkLongPressStart();
}

void LongPressGestureRecognizerCls::handlePrimaryPointer(PointerEvent event) {
    if (!event->synthesized) {
        if (is<PointerDownEvent>(event)) {
            _velocityTracker = VelocityTrackerCls->withKind(as<PointerDownEventCls>(event)->kind);
            _velocityTracker!->addPosition(as<PointerDownEventCls>(event)->timeStamp, as<PointerDownEventCls>(event)->localPosition);
        }
        if (is<PointerMoveEvent>(event)) {
            assert(_velocityTracker != nullptr);
            _velocityTracker!->addPosition(as<PointerMoveEventCls>(event)->timeStamp, as<PointerMoveEventCls>(event)->localPosition);
        }
    }
    if (is<PointerUpEvent>(event)) {
        if (_longPressAccepted == true) {
            _checkLongPressEnd(event);
        } else {
            resolve(GestureDispositionCls::rejected);
        }
        _reset();
    } else     {
        if (is<PointerCancelEvent>(event)) {
        _checkLongPressCancel();
        _reset();
    } else     {
        if (is<PointerDownEvent>(event)) {
        _longPressOrigin = OffsetPairCls->fromEventPosition(as<PointerDownEventCls>(event));
        _initialButtons = as<PointerDownEventCls>(event)->buttons;
        _checkLongPressDown(as<PointerDownEventCls>(event));
    } else     {
        if (is<PointerMoveEvent>(event)) {
        if (as<PointerMoveEventCls>(event)->buttons != _initialButtons) {
            resolve(GestureDispositionCls::rejected);
            stopTrackingPointer(primaryPointer!);
        } else         {
            if (_longPressAccepted) {
            _checkLongPressMoveUpdate(event);
        }
;
        }    }
;
    };
    };
    }}

void LongPressGestureRecognizerCls::resolve(GestureDisposition disposition) {
    if (disposition == GestureDispositionCls::rejected) {
        if (_longPressAccepted) {
            _reset();
        } else {
            _checkLongPressCancel();
        }
    }
    super->resolve(disposition);
}

void LongPressGestureRecognizerCls::acceptGesture(int pointer) {
}

String LongPressGestureRecognizerCls::debugDescription() {
    return __s("long press");
}

void LongPressGestureRecognizerCls::_checkLongPressDown(PointerDownEvent event) {
    assert(_longPressOrigin != nullptr);
    LongPressDownDetails details = make<LongPressDownDetailsCls>(_longPressOrigin!->global, _longPressOrigin!->local, getKindForPointer(event->pointer));
    ;
}

void LongPressGestureRecognizerCls::_checkLongPressCancel() {
    if (state == GestureRecognizerStateCls::possible) {
        ;
    }
}

void LongPressGestureRecognizerCls::_checkLongPressStart() {
    ;
}

void LongPressGestureRecognizerCls::_checkLongPressMoveUpdate(PointerEvent event) {
    LongPressMoveUpdateDetails details = make<LongPressMoveUpdateDetailsCls>(event->position, event->localPosition(), event->position - _longPressOrigin!->global, event->localPosition() - _longPressOrigin!->local);
    ;
}

void LongPressGestureRecognizerCls::_checkLongPressEnd(PointerEvent event) {
    VelocityEstimate estimate = _velocityTracker!->getVelocityEstimate();
    Velocity velocity = estimate == nullptr? VelocityCls::zero : make<VelocityCls>(estimate->pixelsPerSecond);
    LongPressEndDetails details = make<LongPressEndDetailsCls>(event->position, event->localPosition(), velocity);
    _velocityTracker = nullptr;
    ;
}

void LongPressGestureRecognizerCls::_reset() {
    _longPressAccepted = false;
    _longPressOrigin = nullptr;
    _initialButtons = nullptr;
    _velocityTracker = nullptr;
}
