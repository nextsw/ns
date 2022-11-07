#include "scale.hpp"
String _PointerPanZoomData::toString() {
    return "_PointerPanZoomData(focalPoint: $focalPoint, scale: $scale, angle: $rotation)";
}

ScaleStartDetails::ScaleStartDetails(Offset focalPoint, Offset localFocalPoint, int pointerCount) {
    {
        assert(focalPoint != nullptr);
        localFocalPoint = localFocalPoint ?? focalPoint;
    }
}

String ScaleStartDetails::toString() {
    return "ScaleStartDetails(focalPoint: $focalPoint, localFocalPoint: $localFocalPoint, pointersCount: $pointerCount)";
}

ScaleUpdateDetails::ScaleUpdateDetails(Offset focalPoint, Offset focalPointDelta, double horizontalScale, Offset localFocalPoint, int pointerCount, double rotation, double scale, double verticalScale) {
    {
        assert(focalPoint != nullptr);
        assert(focalPointDelta != nullptr);
        assert(scale != nullptr && scale >= 0.0);
        assert(horizontalScale != nullptr && horizontalScale >= 0.0);
        assert(verticalScale != nullptr && verticalScale >= 0.0);
        assert(rotation != nullptr);
        localFocalPoint = localFocalPoint ?? focalPoint;
    }
}

String ScaleUpdateDetails::toString() {
    return "ScaleUpdateDetails(focalPoint: $focalPoint, localFocalPoint: $localFocalPoint, scale: $scale, horizontalScale: $horizontalScale, verticalScale: $verticalScale, rotation: $rotation, pointerCount: $pointerCount, focalPointDelta: $focalPointDelta)";
}

ScaleEndDetails::ScaleEndDetails(int pointerCount, Velocity velocity) {
    {
        assert(velocity != nullptr);
    }
}

String ScaleEndDetails::toString() {
    return "ScaleEndDetails(velocity: $velocity, pointerCount: $pointerCount)";
}

bool _isFlingGesture(Velocity velocity) {
    assert(velocity != nullptr);
    double speedSquared = velocity.pixelsPerSecond.distanceSquared;
    return speedSquared > kMinFlingVelocity * kMinFlingVelocity;
}

_LineBetweenPointers::_LineBetweenPointers(int pointerEndId, Offset pointerEndLocation, int pointerStartId, Offset pointerStartLocation) {
    {
        assert(pointerStartLocation != nullptr && pointerEndLocation != nullptr);
        assert(pointerStartId != nullptr && pointerEndId != nullptr);
        assert(pointerStartId != pointerEndId);
    }
}

ScaleGestureRecognizer::ScaleGestureRecognizer(Unknown, DragStartBehavior dragStartBehavior, Unknown, Unknown) {
    {
        assert(dragStartBehavior != nullptr);
    }
}

void ScaleGestureRecognizer::addAllowedPointer(PointerDownEvent event) {
    super.addAllowedPointer(event);
    _velocityTrackers[event.pointer] = VelocityTracker.withKind(event.kind);
    if (_state == _ScaleState.ready) {
        _state = _ScaleState.possible;
        _initialSpan = 0.0;
        _currentSpan = 0.0;
        _initialHorizontalSpan = 0.0;
        _currentHorizontalSpan = 0.0;
        _initialVerticalSpan = 0.0;
        _currentVerticalSpan = 0.0;
    }
}

bool ScaleGestureRecognizer::isPointerPanZoomAllowed(PointerPanZoomStartEvent event) {
    return true;
}

void ScaleGestureRecognizer::addAllowedPointerPanZoom(PointerPanZoomStartEvent event) {
    super.addAllowedPointerPanZoom(event);
    startTrackingPointer(event.pointer, event.transform);
    _velocityTrackers[event.pointer] = VelocityTracker.withKind(event.kind);
    if (_state == _ScaleState.ready) {
        _state = _ScaleState.possible;
        _initialPanZoomScaleFactor = 1.0;
        _initialPanZoomRotationFactor = 0.0;
    }
}

void ScaleGestureRecognizer::handleEvent(PointerEvent event) {
    assert(_state != _ScaleState.ready);
    bool didChangeConfiguration = false;
    bool shouldStartIfAccepted = false;
    if (event is PointerMoveEvent) {
        VelocityTracker tracker = _velocityTrackers[event.pointer]!;
        if (!event.synthesized) {
            tracker.addPosition(event.timeStamp, event.position);
        }
        _pointerLocations[event.pointer] = event.position;
        shouldStartIfAccepted = true;
        _lastTransform = event.transform;
    } else     {
        if (event is PointerDownEvent) {
        _pointerLocations[event.pointer] = event.position;
        _pointerQueue.add(event.pointer);
        didChangeConfiguration = true;
        shouldStartIfAccepted = true;
        _lastTransform = event.transform;
    } else     {
        if (event is PointerUpEvent || event is PointerCancelEvent) {
        _pointerLocations.remove(event.pointer);
        _pointerQueue.remove(event.pointer);
        didChangeConfiguration = true;
        _lastTransform = event.transform;
    } else     {
        if (event is PointerPanZoomStartEvent) {
        assert(_pointerPanZooms[event.pointer] == nullptr);
        _pointerPanZooms[event.pointer] = _PointerPanZoomData(event.position, 1, 0);
        didChangeConfiguration = true;
        shouldStartIfAccepted = true;
    } else     {
        if (event is PointerPanZoomUpdateEvent) {
        assert(_pointerPanZooms[event.pointer] != nullptr);
        if (!event.synthesized) {
            _velocityTrackers[event.pointer]!.addPosition(event.timeStamp, event.pan);
        }
        _pointerPanZooms[event.pointer] = _PointerPanZoomData(event.position + event.pan, event.scale, event.rotation);
        _lastTransform = event.transform;
        shouldStartIfAccepted = true;
    } else     {
        if (event is PointerPanZoomEndEvent) {
        assert(_pointerPanZooms[event.pointer] != nullptr);
        _pointerPanZooms.remove(event.pointer);
        didChangeConfiguration = true;
    }
;
    };
    };
    };
    };
    }    _updateLines();
    _update();
    if (!didChangeConfiguration || _reconfigure(event.pointer)) {
        _advanceStateMachine(shouldStartIfAccepted, event.kind);
    }
    stopTrackingIfPointerNoLongerDown(event);
}

void ScaleGestureRecognizer::acceptGesture(int pointer) {
    if (_state == _ScaleState.possible) {
        _state = _ScaleState.started;
        _dispatchOnStartCallbackIfNeeded();
        if (dragStartBehavior == DragStartBehavior.start) {
            _initialFocalPoint = _currentFocalPoint!;
            _initialSpan = _currentSpan;
            _initialLine = _currentLine;
            _initialHorizontalSpan = _currentHorizontalSpan;
            _initialVerticalSpan = _currentVerticalSpan;
            if (_pointerPanZooms.isEmpty) {
                _initialPanZoomScaleFactor = 1.0;
                _initialPanZoomRotationFactor = 0.0;
            } else {
                _initialPanZoomScaleFactor = _scaleFactor / _pointerScaleFactor;
                _initialPanZoomRotationFactor = _pointerPanZooms.values.map().reduce();
            }
        }
    }
}

void ScaleGestureRecognizer::rejectGesture(int pointer) {
    _pointerPanZooms.remove(pointer);
    _pointerLocations.remove(pointer);
    _pointerQueue.remove(pointer);
    stopTrackingPointer(pointer);
}

void ScaleGestureRecognizer::didStopTrackingLastPointer(int pointer) {
    ;
    _state = _ScaleState.ready;
}

void ScaleGestureRecognizer::dispose() {
    _velocityTrackers.clear();
    super.dispose();
}

String ScaleGestureRecognizer::debugDescription() {
    return "scale";
}

double ScaleGestureRecognizer::_pointerScaleFactor() {
    return _initialSpan > 0.0? _currentSpan / _initialSpan : 1.0;
}

double ScaleGestureRecognizer::_pointerHorizontalScaleFactor() {
    return _initialHorizontalSpan > 0.0? _currentHorizontalSpan / _initialHorizontalSpan : 1.0;
}

double ScaleGestureRecognizer::_pointerVerticalScaleFactor() {
    return _initialVerticalSpan > 0.0? _currentVerticalSpan / _initialVerticalSpan : 1.0;
}

double ScaleGestureRecognizer::_scaleFactor() {
    double scale = _pointerScaleFactor;
    for (_PointerPanZoomData p : _pointerPanZooms.values) {
        scale = p.scale / _initialPanZoomScaleFactor;
    }
    return scale;
}

double ScaleGestureRecognizer::_horizontalScaleFactor() {
    double scale = _pointerHorizontalScaleFactor;
    for (_PointerPanZoomData p : _pointerPanZooms.values) {
        scale = p.scale / _initialPanZoomScaleFactor;
    }
    return scale;
}

double ScaleGestureRecognizer::_verticalScaleFactor() {
    double scale = _pointerVerticalScaleFactor;
    for (_PointerPanZoomData p : _pointerPanZooms.values) {
        scale = p.scale / _initialPanZoomScaleFactor;
    }
    return scale;
}

int ScaleGestureRecognizer::_pointerCount() {
    return _pointerPanZooms.length + _pointerQueue.length;
}

double ScaleGestureRecognizer::_computeRotationFactor() {
    double factor = 0.0;
    if (_initialLine != nullptr && _currentLine != nullptr) {
        double fx = _initialLine!.pointerStartLocation.dx;
        double fy = _initialLine!.pointerStartLocation.dy;
        double sx = _initialLine!.pointerEndLocation.dx;
        double sy = _initialLine!.pointerEndLocation.dy;
        double nfx = _currentLine!.pointerStartLocation.dx;
        double nfy = _currentLine!.pointerStartLocation.dy;
        double nsx = _currentLine!.pointerEndLocation.dx;
        double nsy = _currentLine!.pointerEndLocation.dy;
        double angle1 = math.atan2(fy - sy, fx - sx);
        double angle2 = math.atan2(nfy - nsy, nfx - nsx);
        factor = angle2 - angle1;
    }
    for (_PointerPanZoomData p : _pointerPanZooms.values) {
        factor = p.rotation;
    }
    factor = _initialPanZoomRotationFactor;
    return factor;
}

void ScaleGestureRecognizer::_update() {
    Offset previousFocalPoint = _currentFocalPoint;
    Offset focalPoint = Offset.zero;
    for (int pointer : _pointerLocations.keys) {
        focalPoint = _pointerLocations[pointer]!;
    }
    for (_PointerPanZoomData p : _pointerPanZooms.values) {
        focalPoint = p.focalPoint;
    }
    _currentFocalPoint = _pointerCount > 0? focalPoint / _pointerCount.toDouble() : Offset.zero;
    if (previousFocalPoint == nullptr) {
        _localFocalPoint = PointerEvent.transformPosition(_lastTransform, _currentFocalPoint!);
        _delta = Offset.zero;
    } else {
        Offset localPreviousFocalPoint = _localFocalPoint;
        _localFocalPoint = PointerEvent.transformPosition(_lastTransform, _currentFocalPoint!);
        _delta = _localFocalPoint - localPreviousFocalPoint;
    }
    int count = _pointerLocations.keys.length;
    Offset pointerFocalPoint = Offset.zero;
    for (int pointer : _pointerLocations.keys) {
        pointerFocalPoint = _pointerLocations[pointer]!;
    }
    if (count > 0) {
        pointerFocalPoint = pointerFocalPoint / count.toDouble();
    }
    double totalDeviation = 0.0;
    double totalHorizontalDeviation = 0.0;
    double totalVerticalDeviation = 0.0;
    for (int pointer : _pointerLocations.keys) {
        totalDeviation = (pointerFocalPoint - _pointerLocations[pointer]!).distance;
        totalHorizontalDeviation = (pointerFocalPoint.dx - _pointerLocations[pointer]!.dx).abs();
        totalVerticalDeviation = (pointerFocalPoint.dy - _pointerLocations[pointer]!.dy).abs();
    }
    _currentSpan = count > 0? totalDeviation / count : 0.0;
    _currentHorizontalSpan = count > 0? totalHorizontalDeviation / count : 0.0;
    _currentVerticalSpan = count > 0? totalVerticalDeviation / count : 0.0;
}

void ScaleGestureRecognizer::_updateLines() {
    int count = _pointerLocations.keys.length;
    assert(_pointerQueue.length >= count);
    if ( < 2) {
        _initialLine = _currentLine;
    } else     {
        if (_initialLine != nullptr && _initialLine!.pointerStartId == _pointerQueue[0] && _initialLine!.pointerEndId == _pointerQueue[1]) {
        _currentLine = _LineBetweenPointers(_pointerQueue[0], _pointerLocations[_pointerQueue[0]]!, _pointerQueue[1], _pointerLocations[_pointerQueue[1]]!);
    } else {
        _initialLine = _LineBetweenPointers(_pointerQueue[0], _pointerLocations[_pointerQueue[0]]!, _pointerQueue[1], _pointerLocations[_pointerQueue[1]]!);
        _currentLine = _initialLine;
    }
;
    }}

bool ScaleGestureRecognizer::_reconfigure(int pointer) {
    _initialFocalPoint = _currentFocalPoint!;
    _initialSpan = _currentSpan;
    _initialLine = _currentLine;
    _initialHorizontalSpan = _currentHorizontalSpan;
    _initialVerticalSpan = _currentVerticalSpan;
    if (_pointerPanZooms.isEmpty) {
        _initialPanZoomScaleFactor = 1.0;
        _initialPanZoomRotationFactor = 0.0;
    } else {
        _initialPanZoomScaleFactor = _scaleFactor / _pointerScaleFactor;
        _initialPanZoomRotationFactor = _pointerPanZooms.values.map().reduce();
    }
    if (_state == _ScaleState.started) {
        if (onEnd != nullptr) {
            VelocityTracker tracker = _velocityTrackers[pointer]!;
            Velocity velocity = tracker.getVelocity();
            if (_isFlingGesture(velocity)) {
                Offset pixelsPerSecond = velocity.pixelsPerSecond;
                if (pixelsPerSecond.distanceSquared > kMaxFlingVelocity * kMaxFlingVelocity) {
                    velocity = Velocity((pixelsPerSecond / pixelsPerSecond.distance) * kMaxFlingVelocity);
                }
                <void>invokeCallback("onEnd", );
            } else {
                <void>invokeCallback("onEnd", );
            }
        }
        _state = _ScaleState.accepted;
        return false;
    }
    return true;
}

void ScaleGestureRecognizer::_advanceStateMachine(PointerDeviceKind pointerDeviceKind, bool shouldStartIfAccepted) {
    if (_state == _ScaleState.ready) {
        _state = _ScaleState.possible;
    }
    if (_state == _ScaleState.possible) {
        double spanDelta = (_currentSpan - _initialSpan).abs();
        double focalPointDelta = (_currentFocalPoint! - _initialFocalPoint).distance;
        if (spanDelta > computeScaleSlop(pointerDeviceKind) || focalPointDelta > computePanSlop(pointerDeviceKind, gestureSettings) || math.max(_scaleFactor / _pointerScaleFactor, _pointerScaleFactor / _scaleFactor) > 1.05) {
            resolve(GestureDisposition.accepted);
        }
    } else     {
        if (_state.index >= _ScaleState.accepted.index) {
        resolve(GestureDisposition.accepted);
    }
;
    }    if (_state == _ScaleState.accepted && shouldStartIfAccepted) {
        _state = _ScaleState.started;
        _dispatchOnStartCallbackIfNeeded();
    }
    if (_state == _ScaleState.started && onUpdate != nullptr) {
        <void>invokeCallback("onUpdate", );
    }
}

void ScaleGestureRecognizer::_dispatchOnStartCallbackIfNeeded() {
    assert(_state == _ScaleState.started);
    if (onStart != nullptr) {
        <void>invokeCallback("onStart", );
    }
}
