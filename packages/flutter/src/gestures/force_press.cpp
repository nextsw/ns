#include "force_press.hpp"
ForcePressDetails::ForcePressDetails(Offset globalPosition, Offset localPosition, double pressure) {
    {
        assert(globalPosition != nullptr);
        assert(pressure != nullptr);
        localPosition = localPosition ?? globalPosition;
    }
}

ForcePressGestureRecognizer::ForcePressGestureRecognizer(Unknown, GestureForceInterpolation interpolation, Unknown, double peakPressure, double startPressure, Unknown) {
    {
        assert(startPressure != nullptr);
        assert(peakPressure != nullptr);
        assert(interpolation != nullptr);
        assert(peakPressure > startPressure);
    }
}

void ForcePressGestureRecognizer::addAllowedPointer(PointerDownEvent event) {
    if (event.pressureMax <= 1.0) {
        resolve(GestureDisposition.rejected);
    } else {
        super.addAllowedPointer(event);
        if (_state == _ForceState.ready) {
            _state = _ForceState.possible;
            _lastPosition = OffsetPair.fromEventPosition(event);
        }
    }
}

void ForcePressGestureRecognizer::handleEvent(PointerEvent event) {
    assert(_state != _ForceState.ready);
    if (event is PointerMoveEvent || event is PointerDownEvent) {
        double pressure = interpolation(event.pressureMin, event.pressureMax, event.pressure);
        assert((pressure >= 0.0 && pressure <= 1.0) || pressure.isNaN);
        _lastPosition = OffsetPair.fromEventPosition(event);
        _lastPressure = pressure;
        if (_state == _ForceState.possible) {
            if (pressure > startPressure) {
                _state = _ForceState.started;
                resolve(GestureDisposition.accepted);
            } else             {
                if (event.delta.distanceSquared > computeHitSlop(event.kind, gestureSettings)) {
                resolve(GestureDisposition.rejected);
            }
;
            }        }
        if (pressure > startPressure && _state == _ForceState.accepted) {
            _state = _ForceState.started;
            if (onStart != nullptr) {
                <void>invokeCallback("onStart", );
            }
        }
        if (onPeak != nullptr && pressure > peakPressure && (_state == _ForceState.started)) {
            _state = _ForceState.peaked;
            if (onPeak != nullptr) {
                <void>invokeCallback("onPeak", );
            }
        }
        if (onUpdate != nullptr && !pressure.isNaN && (_state == _ForceState.started || _state == _ForceState.peaked)) {
            if (onUpdate != nullptr) {
                <void>invokeCallback("onUpdate", );
            }
        }
    }
    stopTrackingIfPointerNoLongerDown(event);
}

void ForcePressGestureRecognizer::acceptGesture(int pointer) {
    if (_state == _ForceState.possible) {
        _state = _ForceState.accepted;
    }
    if (onStart != nullptr && _state == _ForceState.started) {
        <void>invokeCallback("onStart", );
    }
}

void ForcePressGestureRecognizer::didStopTrackingLastPointer(int pointer) {
    bool wasAccepted = _state == _ForceState.started || _state == _ForceState.peaked;
    if (_state == _ForceState.possible) {
        resolve(GestureDisposition.rejected);
        return;
    }
    if (wasAccepted && onEnd != nullptr) {
        if (onEnd != nullptr) {
            <void>invokeCallback("onEnd", );
        }
    }
    _state = _ForceState.ready;
}

void ForcePressGestureRecognizer::rejectGesture(int pointer) {
    stopTrackingPointer(pointer);
    didStopTrackingLastPointer(pointer);
}

String ForcePressGestureRecognizer::debugDescription() {
    return "force press";
}

double ForcePressGestureRecognizer::_inverseLerp(double max, double min, double t) {
    assert(min <= max);
    double value = (t - min) / (max - min);
    if (!value.isNaN) {
        value = clampDouble(value, 0.0, 1.0);
    }
    return value;
}
