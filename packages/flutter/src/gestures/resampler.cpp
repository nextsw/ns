#include "resampler.hpp"
void PointerEventResampler::addEvent(PointerEvent event) {
    _queuedEvents.add(event);
}

void PointerEventResampler::sample(HandleEventCallback callback, Duration nextSampleTime, Duration sampleTime) {
    _processPointerEvents(sampleTime);
    _dequeueAndSampleNonHoverOrMovePointerEventsUntil(sampleTime, nextSampleTime, callback);
    if (_isTracked) {
        _samplePointerPosition(sampleTime, callback);
    }
}

void PointerEventResampler::stop(HandleEventCallback callback) {
    while (_queuedEvents.isNotEmpty) {
        callback(_queuedEvents.removeFirst());
    }
    _pointerIdentifier = 0;
    _isDown = false;
    _isTracked = false;
    _position = Offset.zero;
    _next = nullptr;
    _last = nullptr;
}

bool PointerEventResampler::hasPendingEvents() {
    return _queuedEvents.isNotEmpty;
}

bool PointerEventResampler::isTracked() {
    return _isTracked;
}

bool PointerEventResampler::isDown() {
    return _isDown;
}

PointerEvent PointerEventResampler::_toHoverEvent(int buttons, Offset delta, PointerEvent event, Offset position, Duration timeStamp) {
    return PointerHoverEvent(timeStamp, event.kind, event.device, position, delta, event.buttons, event.obscured, event.pressureMin, event.pressureMax, event.distance, event.distanceMax, event.size, event.radiusMajor, event.radiusMinor, event.radiusMin, event.radiusMax, event.orientation, event.tilt, event.synthesized, event.embedderId);
}

PointerEvent PointerEventResampler::_toMoveEvent(int buttons, Offset delta, PointerEvent event, int pointerIdentifier, Offset position, Duration timeStamp) {
    return PointerMoveEvent(timeStamp, pointerIdentifier, event.kind, event.device, position, delta, buttons, event.obscured, event.pressure, event.pressureMin, event.pressureMax, event.distanceMax, event.size, event.radiusMajor, event.radiusMinor, event.radiusMin, event.radiusMax, event.orientation, event.tilt, event.platformData, event.synthesized, event.embedderId);
}

PointerEvent PointerEventResampler::_toMoveOrHoverEvent(int buttons, Offset delta, PointerEvent event, bool isDown, int pointerIdentifier, Offset position, Duration timeStamp) {
    return isDown? _toMoveEvent(event, position, delta, pointerIdentifier, timeStamp, buttons) : _toHoverEvent(event, position, delta, timeStamp, buttons);
}

Offset PointerEventResampler::_positionAt(Duration sampleTime) {
    double x = _next?.position.dx ?? 0.0;
    double y = _next?.position.dy ?? 0.0;
    Duration nextTimeStamp = _next?.timeStamp ?? Duration.zero;
    Duration lastTimeStamp = _last?.timeStamp ?? Duration.zero;
    if (nextTimeStamp > sampleTime && nextTimeStamp > lastTimeStamp) {
        double interval = (nextTimeStamp - lastTimeStamp).inMicroseconds.toDouble();
        double scalar = (sampleTime - lastTimeStamp).inMicroseconds.toDouble() / interval;
        double lastX = _last?.position.dx ?? 0.0;
        double lastY = _last?.position.dy ?? 0.0;
        x = lastX + (x - lastX) * scalar;
        y = lastY + (y - lastY) * scalar;
    }
    return Offset(x, y);
}

void PointerEventResampler::_processPointerEvents(Duration sampleTime) {
    Iterator<PointerEvent> it = _queuedEvents.iterator;
    while (it.moveNext()) {
        PointerEvent event = it.current;
        if (event.timeStamp <= sampleTime || _last == nullptr) {
            _last = event;
            _next = event;
            continue;
        }
        Duration nextTimeStamp = _next?.timeStamp ?? Duration.zero;
        if ( < sampleTime) {
            _next = event;
                        break;
        }
    }
}

void PointerEventResampler::_dequeueAndSampleNonHoverOrMovePointerEventsUntil(HandleEventCallback callback, Duration nextSampleTime, Duration sampleTime) {
    Duration endTime = sampleTime;
    Iterator<PointerEvent> it = _queuedEvents.iterator;
    while (it.moveNext()) {
        PointerEvent event = it.current;
        if (event.timeStamp > sampleTime) {
            if (event.timeStamp >= nextSampleTime) {
                                break;
            }
            if (event is PointerUpEvent || event is PointerRemovedEvent) {
                endTime = event.timeStamp;
                continue;
            }
            if (event is! PointerMoveEvent && event is! PointerHoverEvent) {
                                break;
            }
        }
    }
    while (_queuedEvents.isNotEmpty) {
        PointerEvent event = _queuedEvents.first;
        if (event.timeStamp > endTime) {
                        break;
        }
        bool wasTracked = _isTracked;
        bool wasDown = _isDown;
        int hadButtons = _hasButtons;
        _isTracked = event is! PointerRemovedEvent;
        _isDown = event.down;
        _hasButtons = event.buttons;
        Offset position = _positionAt(sampleTime);
        if (_isTracked && !wasTracked) {
            _position = position;
        }
        int pointerIdentifier = event.pointer;
        assert(!wasDown || _pointerIdentifier == pointerIdentifier);
        _pointerIdentifier = pointerIdentifier;
        if (event is! PointerMoveEvent && event is! PointerHoverEvent) {
            if (position != _position) {
                Offset delta = position - _position;
                callback(_toMoveOrHoverEvent(event, position, delta, _pointerIdentifier, sampleTime, wasDown, hadButtons));
                _position = position;
            }
            callback(event.copyWith(position, Offset.zero, pointerIdentifier, sampleTime));
        }
        _queuedEvents.removeFirst();
    }
}

void PointerEventResampler::_samplePointerPosition(HandleEventCallback callback, Duration sampleTime) {
    Offset position = _positionAt(sampleTime);
    PointerEvent next = _next;
    if (position != _position && next != nullptr) {
        Offset delta = position - _position;
        callback(_toMoveOrHoverEvent(next, position, delta, _pointerIdentifier, sampleTime, _isDown, _hasButtons));
        _position = position;
    }
}
