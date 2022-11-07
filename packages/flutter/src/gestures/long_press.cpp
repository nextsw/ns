#include "long_press.hpp"
LongPressDownDetails::LongPressDownDetails(Offset globalPosition, PointerDeviceKind kind, Offset localPosition) {
    {
        assert(globalPosition != nullptr);
        localPosition = localPosition ?? globalPosition;
    }
}

LongPressStartDetails::LongPressStartDetails(Offset globalPosition, Offset localPosition) {
    {
        assert(globalPosition != nullptr);
        localPosition = localPosition ?? globalPosition;
    }
}

LongPressMoveUpdateDetails::LongPressMoveUpdateDetails(Offset globalPosition, Offset localOffsetFromOrigin, Offset localPosition, Offset offsetFromOrigin) {
    {
        assert(globalPosition != nullptr);
        assert(offsetFromOrigin != nullptr);
        localPosition = localPosition ?? globalPosition;
        localOffsetFromOrigin = localOffsetFromOrigin ?? offsetFromOrigin;
    }
}

LongPressEndDetails::LongPressEndDetails(Offset globalPosition, Offset localPosition, Velocity velocity) {
    {
        assert(globalPosition != nullptr);
        localPosition = localPosition ?? globalPosition;
    }
}

LongPressGestureRecognizer::LongPressGestureRecognizer(Unknown, Duration duration, Unknown, Unknown, Unknown) {
    {
        super(duration ?? kLongPressTimeout);
    }
}

bool LongPressGestureRecognizer::isPointerAllowed(PointerDownEvent event) {
    ;
    return super.isPointerAllowed(event);
}

void LongPressGestureRecognizer::didExceedDeadline() {
    resolve(GestureDisposition.accepted);
    _longPressAccepted = true;
    super.acceptGesture(primaryPointer!);
    _checkLongPressStart();
}

void LongPressGestureRecognizer::handlePrimaryPointer(PointerEvent event) {
    if (!event.synthesized) {
        if (event is PointerDownEvent) {
            _velocityTracker = VelocityTracker.withKind(event.kind);
            _velocityTracker!.addPosition(event.timeStamp, event.localPosition);
        }
        if (event is PointerMoveEvent) {
            assert(_velocityTracker != nullptr);
            _velocityTracker!.addPosition(event.timeStamp, event.localPosition);
        }
    }
    if (event is PointerUpEvent) {
        if (_longPressAccepted == true) {
            _checkLongPressEnd(event);
        } else {
            resolve(GestureDisposition.rejected);
        }
        _reset();
    } else     {
        if (event is PointerCancelEvent) {
        _checkLongPressCancel();
        _reset();
    } else     {
        if (event is PointerDownEvent) {
        _longPressOrigin = OffsetPair.fromEventPosition(event);
        _initialButtons = event.buttons;
        _checkLongPressDown(event);
    } else     {
        if (event is PointerMoveEvent) {
        if (event.buttons != _initialButtons) {
            resolve(GestureDisposition.rejected);
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

void LongPressGestureRecognizer::resolve(GestureDisposition disposition) {
    if (disposition == GestureDisposition.rejected) {
        if (_longPressAccepted) {
            _reset();
        } else {
            _checkLongPressCancel();
        }
    }
    super.resolve(disposition);
}

void LongPressGestureRecognizer::acceptGesture(int pointer) {
}

String LongPressGestureRecognizer::debugDescription() {
    return "long press";
}

void LongPressGestureRecognizer::_checkLongPressDown(PointerDownEvent event) {
    assert(_longPressOrigin != nullptr);
    LongPressDownDetails details = LongPressDownDetails(_longPressOrigin!.global, _longPressOrigin!.local, getKindForPointer(event.pointer));
    ;
}

void LongPressGestureRecognizer::_checkLongPressCancel() {
    if (state == GestureRecognizerState.possible) {
        ;
    }
}

void LongPressGestureRecognizer::_checkLongPressStart() {
    ;
}

void LongPressGestureRecognizer::_checkLongPressMoveUpdate(PointerEvent event) {
    LongPressMoveUpdateDetails details = LongPressMoveUpdateDetails(event.position, event.localPosition, event.position - _longPressOrigin!.global, event.localPosition - _longPressOrigin!.local);
    ;
}

void LongPressGestureRecognizer::_checkLongPressEnd(PointerEvent event) {
    VelocityEstimate estimate = _velocityTracker!.getVelocityEstimate();
    Velocity velocity = estimate == nullptr? Velocity.zero : Velocity(estimate.pixelsPerSecond);
    LongPressEndDetails details = LongPressEndDetails(event.position, event.localPosition, velocity);
    _velocityTracker = nullptr;
    ;
}

void LongPressGestureRecognizer::_reset() {
    _longPressAccepted = false;
    _longPressOrigin = nullptr;
    _initialButtons = nullptr;
    _velocityTracker = nullptr;
}
