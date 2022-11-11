#include "force_press.hpp"
ForcePressDetailsCls::ForcePressDetailsCls(Offset globalPosition, Offset localPosition, double pressure) {
    {
        assert(globalPosition != nullptr);
        assert(pressure != nullptr);
        localPosition = localPosition or globalPosition;
    }
}

ForcePressGestureRecognizerCls::ForcePressGestureRecognizerCls(Unknown debugOwner, GestureForceInterpolation interpolation, Unknown kind, double peakPressure, double startPressure, Unknown supportedDevices) {
    {
        assert(startPressure != nullptr);
        assert(peakPressure != nullptr);
        assert(interpolation != nullptr);
        assert(peakPressure > startPressure);
    }
}

void ForcePressGestureRecognizerCls::addAllowedPointer(PointerDownEvent event) {
    if (event->pressureMax <= 1.0) {
        resolve(GestureDispositionCls::rejected);
    } else {
        super->addAllowedPointer(event);
        if (_state == _ForceStateCls::ready) {
            _state = _ForceStateCls::possible;
            _lastPosition = OffsetPairCls->fromEventPosition(event);
        }
    }
}

void ForcePressGestureRecognizerCls::handleEvent(PointerEvent event) {
    assert(_state != _ForceStateCls::ready);
    if (is<PointerMoveEvent>(event) || is<PointerDownEvent>(event)) {
        double pressure = interpolation(event->pressureMin, event->pressureMax, event->pressure);
        assert((pressure >= 0.0 && pressure <= 1.0) || pressure->isNaN);
        _lastPosition = OffsetPairCls->fromEventPosition(event);
        _lastPressure = pressure;
        if (_state == _ForceStateCls::possible) {
            if (pressure > startPressure) {
                _state = _ForceStateCls::started;
                resolve(GestureDispositionCls::accepted);
            } else             {
                if (event->delta->distanceSquared() > computeHitSlop(event->kind, gestureSettings)) {
                resolve(GestureDispositionCls::rejected);
            }
;
            }        }
        if (pressure > startPressure && _state == _ForceStateCls::accepted) {
            _state = _ForceStateCls::started;
            if (onStart != nullptr) {
                <void>invokeCallback(__s("onStart"), [=] ()                 {
                    onStart!(make<ForcePressDetailsCls>(pressure, _lastPosition->global, _lastPosition->local));
                });
            }
        }
        if (onPeak != nullptr && pressure > peakPressure && (_state == _ForceStateCls::started)) {
            _state = _ForceStateCls::peaked;
            if (onPeak != nullptr) {
                <void>invokeCallback(__s("onPeak"), [=] ()                 {
                    onPeak!(make<ForcePressDetailsCls>(pressure, event->position, event->localPosition));
                });
            }
        }
        if (onUpdate != nullptr && !pressure->isNaN && (_state == _ForceStateCls::started || _state == _ForceStateCls::peaked)) {
            if (onUpdate != nullptr) {
                <void>invokeCallback(__s("onUpdate"), [=] ()                 {
                    onUpdate!(make<ForcePressDetailsCls>(pressure, event->position, event->localPosition));
                });
            }
        }
    }
    stopTrackingIfPointerNoLongerDown(event);
}

void ForcePressGestureRecognizerCls::acceptGesture(int pointer) {
    if (_state == _ForceStateCls::possible) {
        _state = _ForceStateCls::accepted;
    }
    if (onStart != nullptr && _state == _ForceStateCls::started) {
        <void>invokeCallback(__s("onStart"), [=] ()         {
            onStart!(make<ForcePressDetailsCls>(_lastPressure, _lastPosition->global, _lastPosition->local));
        });
    }
}

void ForcePressGestureRecognizerCls::didStopTrackingLastPointer(int pointer) {
    bool wasAccepted = _state == _ForceStateCls::started || _state == _ForceStateCls::peaked;
    if (_state == _ForceStateCls::possible) {
        resolve(GestureDispositionCls::rejected);
        return;
    }
    if (wasAccepted && onEnd != nullptr) {
        if (onEnd != nullptr) {
            <void>invokeCallback(__s("onEnd"), [=] ()             {
                onEnd!(make<ForcePressDetailsCls>(0.0, _lastPosition->global, _lastPosition->local));
            });
        }
    }
    _state = _ForceStateCls::ready;
}

void ForcePressGestureRecognizerCls::rejectGesture(int pointer) {
    stopTrackingPointer(pointer);
    didStopTrackingLastPointer(pointer);
}

String ForcePressGestureRecognizerCls::debugDescription() {
    return __s("force press");
}

double ForcePressGestureRecognizerCls::_inverseLerp(double max, double min, double t) {
    assert(min <= max);
    double value = (t - min) / (max - min);
    if (!value->isNaN) {
        value = clampDouble(value, 0.0, 1.0);
    }
    return value;
}
