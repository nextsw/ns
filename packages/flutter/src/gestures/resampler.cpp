#include "resampler.hpp"
void PointerEventResamplerCls::addEvent(PointerEvent event) {
    _queuedEvents->add(event);
}

void PointerEventResamplerCls::sample(Duration sampleTime, Duration nextSampleTime, HandleEventCallback callback) {
    _processPointerEvents(sampleTime);
    _dequeueAndSampleNonHoverOrMovePointerEventsUntil(sampleTime, nextSampleTime, callback);
    if (_isTracked) {
        _samplePointerPosition(sampleTime, callback);
    }
}

void PointerEventResamplerCls::stop(HandleEventCallback callback) {
    while (_queuedEvents->isNotEmpty) {
        callback(_queuedEvents->removeFirst());
    }
    _pointerIdentifier = 0;
    _isDown = false;
    _isTracked = false;
    _position = OffsetCls::zero;
    _next = nullptr;
    _last = nullptr;
}

bool PointerEventResamplerCls::hasPendingEvents() {
    return _queuedEvents->isNotEmpty;
}

bool PointerEventResamplerCls::isTracked() {
    return _isTracked;
}

bool PointerEventResamplerCls::isDown() {
    return _isDown;
}

PointerEvent PointerEventResamplerCls::_toHoverEvent(PointerEvent event, Offset position, Offset delta, Duration timeStamp, int buttons) {
    return make<PointerHoverEventCls>(timeStamp, event->kind, event->device, position, delta, event->buttons, event->obscured, event->pressureMin, event->pressureMax, event->distance, event->distanceMax, event->size, event->radiusMajor, event->radiusMinor, event->radiusMin, event->radiusMax, event->orientation, event->tilt, event->synthesized, event->embedderId);
}

PointerEvent PointerEventResamplerCls::_toMoveEvent(PointerEvent event, Offset position, Offset delta, int pointerIdentifier, Duration timeStamp, int buttons) {
    return make<PointerMoveEventCls>(timeStamp, pointerIdentifier, event->kind, event->device, position, delta, buttons, event->obscured, event->pressure, event->pressureMin, event->pressureMax, event->distanceMax, event->size, event->radiusMajor, event->radiusMinor, event->radiusMin, event->radiusMax, event->orientation, event->tilt, event->platformData, event->synthesized, event->embedderId);
}

PointerEvent PointerEventResamplerCls::_toMoveOrHoverEvent(PointerEvent event, Offset position, Offset delta, int pointerIdentifier, Duration timeStamp, bool isDown, int buttons) {
    return isDown? _toMoveEvent(event, position, delta, pointerIdentifier, timeStamp, buttons) : _toHoverEvent(event, position, delta, timeStamp, buttons);
}

Offset PointerEventResamplerCls::_positionAt(Duration sampleTime) {
    double x = _next?->position->dx() | 0.0;
    double y = _next?->position->dy() | 0.0;
    Duration nextTimeStamp = _next?->timeStamp | DurationCls::zero;
    Duration lastTimeStamp = _last?->timeStamp | DurationCls::zero;
    if (nextTimeStamp > sampleTime && nextTimeStamp > lastTimeStamp) {
        double interval = (nextTimeStamp - lastTimeStamp)->inMicroseconds()->toDouble();
        double scalar = (sampleTime - lastTimeStamp)->inMicroseconds()->toDouble() / interval;
        double lastX = _last?->position->dx() | 0.0;
        double lastY = _last?->position->dy() | 0.0;
        x = lastX + (x - lastX) * scalar;
        y = lastY + (y - lastY) * scalar;
    }
    return make<OffsetCls>(x, y);
}

void PointerEventResamplerCls::_processPointerEvents(Duration sampleTime) {
    Iterator<PointerEvent> it = _queuedEvents->iterator;
    while (it->moveNext()) {
        PointerEvent event = it->current();
        if (event->timeStamp <= sampleTime || _last == nullptr) {
            _last = event;
            _next = event;
            continue;
        }
        Duration nextTimeStamp = _next?->timeStamp | DurationCls::zero;
        if ( < sampleTime) {
            _next = event;
            break;
        }
    }
}

void PointerEventResamplerCls::_dequeueAndSampleNonHoverOrMovePointerEventsUntil(Duration sampleTime, Duration nextSampleTime, HandleEventCallback callback) {
    Duration endTime = sampleTime;
    Iterator<PointerEvent> it = _queuedEvents->iterator;
    while (it->moveNext()) {
        PointerEvent event = it->current();
        if (event->timeStamp > sampleTime) {
            if (event->timeStamp >= nextSampleTime) {
                break;
            }
            if (is<PointerUpEvent>(event) || is<PointerRemovedEvent>(event)) {
                endTime = event->timeStamp;
                continue;
            }
            if (!is<PointerMoveEvent>(event) && !is<PointerHoverEvent>(event)) {
                break;
            }
        }
    }
    while (_queuedEvents->isNotEmpty) {
        PointerEvent event = _queuedEvents->first;
        if (event->timeStamp > endTime) {
            break;
        }
        bool wasTracked = _isTracked;
        bool wasDown = _isDown;
        int hadButtons = _hasButtons;
        _isTracked = !is<PointerRemovedEvent>(event);
        _isDown = event->down;
        _hasButtons = event->buttons;
        Offset position = _positionAt(sampleTime);
        if (_isTracked && !wasTracked) {
            _position = position;
        }
        int pointerIdentifier = event->pointer;
        assert(!wasDown || _pointerIdentifier == pointerIdentifier);
        _pointerIdentifier = pointerIdentifier;
        if (!is<PointerMoveEvent>(event) && !is<PointerHoverEvent>(event)) {
            if (position != _position) {
                Offset delta = position - _position;
                callback(_toMoveOrHoverEvent(event, position, delta, _pointerIdentifier, sampleTime, wasDown, hadButtons));
                _position = position;
            }
            callback(event->copyWith(position, OffsetCls::zero, pointerIdentifier, sampleTime));
        }
        _queuedEvents->removeFirst();
    }
}

void PointerEventResamplerCls::_samplePointerPosition(Duration sampleTime, HandleEventCallback callback) {
    Offset position = _positionAt(sampleTime);
    PointerEvent next = _next;
    if (position != _position && next != nullptr) {
        Offset delta = position - _position;
        callback(_toMoveOrHoverEvent(next, position, delta, _pointerIdentifier, sampleTime, _isDown, _hasButtons));
        _position = position;
    }
}
