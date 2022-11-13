#include "scale.hpp"
String _PointerPanZoomDataCls::toString() {
    return __sf("_PointerPanZoomData(focalPoint: %s, scale: %s, angle: %s)", focalPoint, scale, rotation);
}

ScaleStartDetailsCls::ScaleStartDetailsCls(Offset focalPoint, Offset localFocalPoint, int pointerCount) {
    {
        assert(focalPoint != nullptr);
        localFocalPoint = localFocalPoint | focalPoint;
    }
}

String ScaleStartDetailsCls::toString() {
    return __sf("ScaleStartDetails(focalPoint: %s, localFocalPoint: %s, pointersCount: %s)", focalPoint, localFocalPoint, pointerCount);
}

ScaleUpdateDetailsCls::ScaleUpdateDetailsCls(Offset focalPoint, Offset focalPointDelta, double horizontalScale, Offset localFocalPoint, int pointerCount, double rotation, double scale, double verticalScale) {
    {
        assert(focalPoint != nullptr);
        assert(focalPointDelta != nullptr);
        assert(scale != nullptr && scale >= 0.0);
        assert(horizontalScale != nullptr && horizontalScale >= 0.0);
        assert(verticalScale != nullptr && verticalScale >= 0.0);
        assert(rotation != nullptr);
        localFocalPoint = localFocalPoint | focalPoint;
    }
}

String ScaleUpdateDetailsCls::toString() {
    return __sf("ScaleUpdateDetails(focalPoint: %s, localFocalPoint: %s, scale: %s, horizontalScale: %s, verticalScale: %s, rotation: %s, pointerCount: %s, focalPointDelta: %s)", focalPoint, localFocalPoint, scale, horizontalScale, verticalScale, rotation, pointerCount, focalPointDelta);
}

ScaleEndDetailsCls::ScaleEndDetailsCls(int pointerCount, Velocity velocity) {
    {
        assert(velocity != nullptr);
    }
}

String ScaleEndDetailsCls::toString() {
    return __sf("ScaleEndDetails(velocity: %s, pointerCount: %s)", velocity, pointerCount);
}

bool _isFlingGesture(Velocity velocity) {
    assert(velocity != nullptr);
    double speedSquared = velocity->pixelsPerSecond->distanceSquared();
    return speedSquared > kMinFlingVelocity * kMinFlingVelocity;
}

_LineBetweenPointersCls::_LineBetweenPointersCls(int pointerEndId, Offset pointerEndLocation, int pointerStartId, Offset pointerStartLocation) {
    {
        assert(pointerStartLocation != nullptr && pointerEndLocation != nullptr);
        assert(pointerStartId != nullptr && pointerEndId != nullptr);
        assert(pointerStartId != pointerEndId);
    }
}

ScaleGestureRecognizerCls::ScaleGestureRecognizerCls(Object debugOwner, DragStartBehavior dragStartBehavior, PointerDeviceKind kind, Set<PointerDeviceKind> supportedDevices) {
    {
        assert(dragStartBehavior != nullptr);
    }
}

void ScaleGestureRecognizerCls::addAllowedPointer(PointerDownEvent event) {
    super->addAllowedPointer(event);
    _velocityTrackers[event->pointer] = VelocityTrackerCls->withKind(event->kind);
    if (_state == _ScaleStateCls::ready) {
        _state = _ScaleStateCls::possible;
        _initialSpan = 0.0;
        _currentSpan = 0.0;
        _initialHorizontalSpan = 0.0;
        _currentHorizontalSpan = 0.0;
        _initialVerticalSpan = 0.0;
        _currentVerticalSpan = 0.0;
    }
}

bool ScaleGestureRecognizerCls::isPointerPanZoomAllowed(PointerPanZoomStartEvent event) {
    return true;
}

void ScaleGestureRecognizerCls::addAllowedPointerPanZoom(PointerPanZoomStartEvent event) {
    super->addAllowedPointerPanZoom(event);
    startTrackingPointer(event->pointer, event->transform);
    _velocityTrackers[event->pointer] = VelocityTrackerCls->withKind(event->kind);
    if (_state == _ScaleStateCls::ready) {
        _state = _ScaleStateCls::possible;
        _initialPanZoomScaleFactor = 1.0;
        _initialPanZoomRotationFactor = 0.0;
    }
}

void ScaleGestureRecognizerCls::handleEvent(PointerEvent event) {
    assert(_state != _ScaleStateCls::ready);
    bool didChangeConfiguration = false;
    bool shouldStartIfAccepted = false;
    if (is<PointerMoveEvent>(event)) {
        VelocityTracker tracker = _velocityTrackers[as<PointerMoveEventCls>(event)->pointer]!;
        if (!as<PointerMoveEventCls>(event)->synthesized) {
            tracker->addPosition(event->timeStamp, event->position);
        }
        _pointerLocations[as<PointerMoveEventCls>(event)->pointer] = as<PointerMoveEventCls>(event)->position;
        shouldStartIfAccepted = true;
        _lastTransform = as<PointerMoveEventCls>(event)->transform;
    } else {
        if (is<PointerDownEvent>(event)) {
        _pointerLocations[as<PointerDownEventCls>(event)->pointer] = as<PointerDownEventCls>(event)->position;
        _pointerQueue->add(as<PointerDownEventCls>(event)->pointer);
        didChangeConfiguration = true;
        shouldStartIfAccepted = true;
        _lastTransform = as<PointerDownEventCls>(event)->transform;
    } else {
        if (is<PointerUpEvent>(event) || is<PointerCancelEvent>(event)) {
        _pointerLocations->remove(event->pointer);
        _pointerQueue->remove(event->pointer);
        didChangeConfiguration = true;
        _lastTransform = event->transform;
    } else {
        if (is<PointerPanZoomStartEvent>(event)) {
        assert(_pointerPanZooms[as<PointerPanZoomStartEventCls>(event)->pointer] == nullptr);
        _pointerPanZooms[as<PointerPanZoomStartEventCls>(event)->pointer] = make<_PointerPanZoomDataCls>(as<PointerPanZoomStartEventCls>(event)->position, 1, 0);
        didChangeConfiguration = true;
        shouldStartIfAccepted = true;
    } else {
        if (is<PointerPanZoomUpdateEvent>(event)) {
        assert(_pointerPanZooms[as<PointerPanZoomUpdateEventCls>(event)->pointer] != nullptr);
        if (!as<PointerPanZoomUpdateEventCls>(event)->synthesized) {
            _velocityTrackers[event->pointer]!->addPosition(event->timeStamp, event->pan);
        }
        _pointerPanZooms[as<PointerPanZoomUpdateEventCls>(event)->pointer] = make<_PointerPanZoomDataCls>(as<PointerPanZoomUpdateEventCls>(event)->position + as<PointerPanZoomUpdateEventCls>(event)->pan, as<PointerPanZoomUpdateEventCls>(event)->scale, as<PointerPanZoomUpdateEventCls>(event)->rotation);
        _lastTransform = as<PointerPanZoomUpdateEventCls>(event)->transform;
        shouldStartIfAccepted = true;
    } else {
        if (is<PointerPanZoomEndEvent>(event)) {
        assert(_pointerPanZooms[as<PointerPanZoomEndEventCls>(event)->pointer] != nullptr);
        _pointerPanZooms->remove(as<PointerPanZoomEndEventCls>(event)->pointer);
        didChangeConfiguration = true;
    }
;
    };
    };
    };
    };
    }    _updateLines();
    _update();
    if (!didChangeConfiguration || _reconfigure(event->pointer)) {
        _advanceStateMachine(shouldStartIfAccepted, event->kind);
    }
    stopTrackingIfPointerNoLongerDown(event);
}

void ScaleGestureRecognizerCls::acceptGesture(int pointer) {
    if (_state == _ScaleStateCls::possible) {
        _state = _ScaleStateCls::started;
        _dispatchOnStartCallbackIfNeeded();
        if (dragStartBehavior == DragStartBehaviorCls::start) {
            _initialFocalPoint = _currentFocalPoint!;
            _initialSpan = _currentSpan;
            _initialLine = _currentLine;
            _initialHorizontalSpan = _currentHorizontalSpan;
            _initialVerticalSpan = _currentVerticalSpan;
            if (_pointerPanZooms->isEmpty()) {
                _initialPanZoomScaleFactor = 1.0;
                _initialPanZoomRotationFactor = 0.0;
            } else {
                _initialPanZoomScaleFactor = _scaleFactor() / _pointerScaleFactor();
                _initialPanZoomRotationFactor = _pointerPanZooms->values()->map([=] (_PointerPanZoomData x) {
                    x->rotation;
                })->reduce([=] (double a,double b) {
                    a + b;
                });
            }
        }
    }
}

void ScaleGestureRecognizerCls::rejectGesture(int pointer) {
    _pointerPanZooms->remove(pointer);
    _pointerLocations->remove(pointer);
    _pointerQueue->remove(pointer);
    stopTrackingPointer(pointer);
}

void ScaleGestureRecognizerCls::didStopTrackingLastPointer(int pointer) {
    ;
    _state = _ScaleStateCls::ready;
}

void ScaleGestureRecognizerCls::dispose() {
    _velocityTrackers->clear();
    super->dispose();
}

String ScaleGestureRecognizerCls::debugDescription() {
    return __s("scale");
}

double ScaleGestureRecognizerCls::_pointerScaleFactor() {
    return _initialSpan > 0.0? _currentSpan / _initialSpan : 1.0;
}

double ScaleGestureRecognizerCls::_pointerHorizontalScaleFactor() {
    return _initialHorizontalSpan > 0.0? _currentHorizontalSpan / _initialHorizontalSpan : 1.0;
}

double ScaleGestureRecognizerCls::_pointerVerticalScaleFactor() {
    return _initialVerticalSpan > 0.0? _currentVerticalSpan / _initialVerticalSpan : 1.0;
}

double ScaleGestureRecognizerCls::_scaleFactor() {
    double scale = _pointerScaleFactor();
    for (_PointerPanZoomData p : _pointerPanZooms->values()) {
        scale *= p->scale / _initialPanZoomScaleFactor;
    }
    return scale;
}

double ScaleGestureRecognizerCls::_horizontalScaleFactor() {
    double scale = _pointerHorizontalScaleFactor();
    for (_PointerPanZoomData p : _pointerPanZooms->values()) {
        scale *= p->scale / _initialPanZoomScaleFactor;
    }
    return scale;
}

double ScaleGestureRecognizerCls::_verticalScaleFactor() {
    double scale = _pointerVerticalScaleFactor();
    for (_PointerPanZoomData p : _pointerPanZooms->values()) {
        scale *= p->scale / _initialPanZoomScaleFactor;
    }
    return scale;
}

int ScaleGestureRecognizerCls::_pointerCount() {
    return _pointerPanZooms->length() + _pointerQueue->length();
}

double ScaleGestureRecognizerCls::_computeRotationFactor() {
    double factor = 0.0;
    if (_initialLine != nullptr && _currentLine != nullptr) {
        double fx = _initialLine!->pointerStartLocation->dx();
        double fy = _initialLine!->pointerStartLocation->dy();
        double sx = _initialLine!->pointerEndLocation->dx();
        double sy = _initialLine!->pointerEndLocation->dy();
        double nfx = _currentLine!->pointerStartLocation->dx();
        double nfy = _currentLine!->pointerStartLocation->dy();
        double nsx = _currentLine!->pointerEndLocation->dx();
        double nsy = _currentLine!->pointerEndLocation->dy();
        double angle1 = math->atan2(fy - sy, fx - sx);
        double angle2 = math->atan2(nfy - nsy, nfx - nsx);
        factor = angle2 - angle1;
    }
    for (_PointerPanZoomData p : _pointerPanZooms->values()) {
        factor += p->rotation;
    }
    factor -= _initialPanZoomRotationFactor;
    return factor;
}

void ScaleGestureRecognizerCls::_update() {
    Offset previousFocalPoint = _currentFocalPoint;
    Offset focalPoint = OffsetCls::zero;
    for (int pointer : _pointerLocations->keys()) {
        focalPoint += _pointerLocations[pointer]!;
    }
    for (_PointerPanZoomData p : _pointerPanZooms->values()) {
        focalPoint += p->focalPoint;
    }
    _currentFocalPoint = _pointerCount() > 0? focalPoint / _pointerCount()->toDouble() : OffsetCls::zero;
    if (previousFocalPoint == nullptr) {
        _localFocalPoint = PointerEventCls->transformPosition(_lastTransform, _currentFocalPoint!);
        _delta = OffsetCls::zero;
    } else {
        Offset localPreviousFocalPoint = _localFocalPoint;
        _localFocalPoint = PointerEventCls->transformPosition(_lastTransform, _currentFocalPoint!);
        _delta = _localFocalPoint - localPreviousFocalPoint;
    }
    int count = _pointerLocations->keys()->length();
    Offset pointerFocalPoint = OffsetCls::zero;
    for (int pointer : _pointerLocations->keys()) {
        pointerFocalPoint += _pointerLocations[pointer]!;
    }
    if (count > 0) {
        pointerFocalPoint = pointerFocalPoint / count->toDouble();
    }
    double totalDeviation = 0.0;
    double totalHorizontalDeviation = 0.0;
    double totalVerticalDeviation = 0.0;
    for (int pointer : _pointerLocations->keys()) {
        totalDeviation += (pointerFocalPoint - _pointerLocations[pointer]!)->distance();
        totalHorizontalDeviation += (pointerFocalPoint->dx() - _pointerLocations[pointer]!->dx)->abs();
        totalVerticalDeviation += (pointerFocalPoint->dy() - _pointerLocations[pointer]!->dy)->abs();
    }
    _currentSpan = count > 0? totalDeviation / count : 0.0;
    _currentHorizontalSpan = count > 0? totalHorizontalDeviation / count : 0.0;
    _currentVerticalSpan = count > 0? totalVerticalDeviation / count : 0.0;
}

void ScaleGestureRecognizerCls::_updateLines() {
    int count = _pointerLocations->keys()->length();
    assert(_pointerQueue->length() >= count);
    if ( < 2) {
        _initialLine = _currentLine;
    } else {
        if (_initialLine != nullptr && _initialLine!->pointerStartId == _pointerQueue[0] && _initialLine!->pointerEndId == _pointerQueue[1]) {
        _currentLine = make<_LineBetweenPointersCls>(_pointerQueue[0], _pointerLocations[_pointerQueue[0]]!, _pointerQueue[1], _pointerLocations[_pointerQueue[1]]!);
    } else {
        _initialLine = make<_LineBetweenPointersCls>(_pointerQueue[0], _pointerLocations[_pointerQueue[0]]!, _pointerQueue[1], _pointerLocations[_pointerQueue[1]]!);
        _currentLine = _initialLine;
    }
;
    }}

bool ScaleGestureRecognizerCls::_reconfigure(int pointer) {
    _initialFocalPoint = _currentFocalPoint!;
    _initialSpan = _currentSpan;
    _initialLine = _currentLine;
    _initialHorizontalSpan = _currentHorizontalSpan;
    _initialVerticalSpan = _currentVerticalSpan;
    if (_pointerPanZooms->isEmpty()) {
        _initialPanZoomScaleFactor = 1.0;
        _initialPanZoomRotationFactor = 0.0;
    } else {
        _initialPanZoomScaleFactor = _scaleFactor() / _pointerScaleFactor();
        _initialPanZoomRotationFactor = _pointerPanZooms->values()->map([=] (_PointerPanZoomData x) {
            x->rotation;
        })->reduce([=] (double a,double b) {
            a + b;
        });
    }
    if (_state == _ScaleStateCls::started) {
        if (onEnd != nullptr) {
            VelocityTracker tracker = _velocityTrackers[pointer]!;
            Velocity velocity = tracker->getVelocity();
            if (_isFlingGesture(velocity)) {
                Offset pixelsPerSecond = velocity->pixelsPerSecond;
                if (pixelsPerSecond->distanceSquared() > kMaxFlingVelocity * kMaxFlingVelocity) {
                    velocity = make<VelocityCls>((pixelsPerSecond / pixelsPerSecond->distance()) * kMaxFlingVelocity);
                }
                <void>invokeCallback(__s("onEnd"), [=] () {
                    onEnd!(make<ScaleEndDetailsCls>(velocity, _pointerCount()));
                });
            } else {
                <void>invokeCallback(__s("onEnd"), [=] () {
                    onEnd!(make<ScaleEndDetailsCls>(_pointerCount()));
                });
            }
        }
        _state = _ScaleStateCls::accepted;
        return false;
    }
    return true;
}

void ScaleGestureRecognizerCls::_advanceStateMachine(bool shouldStartIfAccepted, PointerDeviceKind pointerDeviceKind) {
    if (_state == _ScaleStateCls::ready) {
        _state = _ScaleStateCls::possible;
    }
    if (_state == _ScaleStateCls::possible) {
        double spanDelta = (_currentSpan - _initialSpan)->abs();
        double focalPointDelta = (_currentFocalPoint! - _initialFocalPoint)->distance();
        if (spanDelta > computeScaleSlop(pointerDeviceKind) || focalPointDelta > computePanSlop(pointerDeviceKind, gestureSettings) || math->max(_scaleFactor() / _pointerScaleFactor(), _pointerScaleFactor() / _scaleFactor()) > 1.05) {
            resolve(GestureDispositionCls::accepted);
        }
    } else {
        if (_state->index >= _ScaleStateCls::accepted->index) {
        resolve(GestureDispositionCls::accepted);
    }
;
    }    if (_state == _ScaleStateCls::accepted && shouldStartIfAccepted) {
        _state = _ScaleStateCls::started;
        _dispatchOnStartCallbackIfNeeded();
    }
    if (_state == _ScaleStateCls::started && onUpdate != nullptr) {
        <void>invokeCallback(__s("onUpdate"), [=] () {
            onUpdate!(make<ScaleUpdateDetailsCls>(_scaleFactor(), _horizontalScaleFactor(), _verticalScaleFactor(), _currentFocalPoint!, _localFocalPoint, _computeRotationFactor(), _pointerCount(), _delta));
        });
    }
}

void ScaleGestureRecognizerCls::_dispatchOnStartCallbackIfNeeded() {
    assert(_state == _ScaleStateCls::started);
    if (onStart != nullptr) {
        <void>invokeCallback(__s("onStart"), [=] () {
            onStart!(make<ScaleStartDetailsCls>(_currentFocalPoint!, _localFocalPoint, _pointerCount()));
        });
    }
}
