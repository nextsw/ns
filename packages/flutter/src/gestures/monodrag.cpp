#include "monodrag.hpp"
DragGestureRecognizerCls::DragGestureRecognizerCls(Object debugOwner, DragStartBehavior dragStartBehavior, Unknown kind, Unknown supportedDevices, GestureVelocityTrackerBuilder velocityTrackerBuilder) {
    {
        assert(dragStartBehavior != nullptr);
    }
}

bool DragGestureRecognizerCls::isPointerAllowed(PointerEvent event) {
    if (_initialButtons == nullptr) {
        ;
    } else {
        if (event->buttons != _initialButtons) {
            return false;
        }
    }
    return super->isPointerAllowed(as<PointerDownEvent>(event));
}

void DragGestureRecognizerCls::addAllowedPointer(PointerDownEvent event) {
    super->addAllowedPointer(event);
    if (_state == _DragStateCls::ready) {
        _initialButtons = event->buttons;
    }
    _addPointer(event);
}

void DragGestureRecognizerCls::addAllowedPointerPanZoom(PointerPanZoomStartEvent event) {
    super->addAllowedPointerPanZoom(event);
    startTrackingPointer(event->pointer, event->transform);
    if (_state == _DragStateCls::ready) {
        _initialButtons = kPrimaryButton;
    }
    _addPointer(event);
}

void DragGestureRecognizerCls::handleEvent(PointerEvent event) {
    assert(_state != _DragStateCls::ready);
    if (!event->synthesized && (is<PointerDownEvent>(event) || is<PointerMoveEvent>(event) || is<PointerPanZoomStartEvent>(event) || is<PointerPanZoomUpdateEvent>(event))) {
        VelocityTracker tracker = _velocityTrackers[event->pointer]!;
        assert(tracker != nullptr);
        if (is<PointerPanZoomStartEvent>(event)) {
            tracker->addPosition(as<PointerPanZoomStartEventCls>(event)->timeStamp, OffsetCls::zero);
        } else {
            if (is<PointerPanZoomUpdateEvent>(event)) {
            tracker->addPosition(as<PointerPanZoomUpdateEventCls>(event)->timeStamp, as<PointerPanZoomUpdateEventCls>(event)->pan);
        } else {
            tracker->addPosition(event->timeStamp, event->localPosition());
        }
;
        }    }
    if (is<PointerMoveEvent>(event) && event->buttons != _initialButtons) {
        _giveUpPointer(event->pointer);
        return;
    }
    if (is<PointerMoveEvent>(event) || is<PointerPanZoomUpdateEvent>(event)) {
        Offset delta = (is<PointerMoveEvent>(event))? event->delta : (as<PointerPanZoomUpdateEvent>(event))->panDelta;
        Offset localDelta = (is<PointerMoveEvent>(event))? event->localDelta() : (as<PointerPanZoomUpdateEvent>(event))->localPanDelta();
        Offset position = (is<PointerMoveEvent>(event))? event->position : (event->position + (as<PointerPanZoomUpdateEvent>(event))->pan);
        Offset localPosition = (is<PointerMoveEvent>(event))? event->localPosition() : (event->localPosition() + (as<PointerPanZoomUpdateEvent>(event))->localPan());
        if (_state == _DragStateCls::accepted) {
            _checkUpdate(event->timeStamp, _getDeltaForDetails(localDelta), _getPrimaryValueFromOffset(localDelta), position, localPosition);
        } else {
            _pendingDragOffset += make<OffsetPairCls>(localDelta, delta);
            _lastPendingEventTimestamp = event->timeStamp;
            _lastTransform = event->transform;
            Offset movedLocally = _getDeltaForDetails(localDelta);
            Matrix4 localToGlobalTransform = event->transform == nullptr? nullptr : Matrix4Cls->tryInvert(event->transform!);
            _globalDistanceMoved += PointerEventCls->transformDeltaViaPositions(localToGlobalTransform, movedLocally, localPosition)->distance * (_getPrimaryValueFromOffset(movedLocally) | 1)->sign();
            if (_hasSufficientGlobalDistanceToAccept(event->kind, gestureSettings?->touchSlop)) {
                resolve(GestureDispositionCls::accepted);
            }
        }
    }
    if (is<PointerUpEvent>(event) || is<PointerCancelEvent>(event) || is<PointerPanZoomEndEvent>(event)) {
        _giveUpPointer(event->pointer);
    }
}

void DragGestureRecognizerCls::acceptGesture(int pointer) {
    assert(!_acceptedActivePointers->contains(pointer));
    _acceptedActivePointers->add(pointer);
    if (_state != _DragStateCls::accepted) {
        _state = _DragStateCls::accepted;
        OffsetPair delta = _pendingDragOffset;
        Duration timestamp = _lastPendingEventTimestamp!;
        Matrix4 transform = _lastTransform;
        Offset localUpdateDelta;
        ;
        _pendingDragOffset = OffsetPairCls::zero;
        _lastPendingEventTimestamp = nullptr;
        _lastTransform = nullptr;
        _checkStart(timestamp, pointer);
        if (localUpdateDelta != OffsetCls::zero && onUpdate != nullptr) {
            Matrix4 localToGlobal = transform != nullptr? Matrix4Cls->tryInvert(transform) : nullptr;
            Offset correctedLocalPosition = _initialPosition->local + localUpdateDelta;
            Offset globalUpdateDelta = PointerEventCls->transformDeltaViaPositions(correctedLocalPosition, localUpdateDelta, localToGlobal);
            OffsetPair updateDelta = make<OffsetPairCls>(localUpdateDelta, globalUpdateDelta);
            OffsetPair correctedPosition = _initialPosition + updateDelta;
            _checkUpdate(timestamp, localUpdateDelta, _getPrimaryValueFromOffset(localUpdateDelta), correctedPosition->global, correctedPosition->local);
        }
        resolve(GestureDispositionCls::accepted);
    }
}

void DragGestureRecognizerCls::rejectGesture(int pointer) {
    _giveUpPointer(pointer);
}

void DragGestureRecognizerCls::didStopTrackingLastPointer(int pointer) {
    assert(_state != _DragStateCls::ready);
    ;
    _velocityTrackers->clear();
    _initialButtons = nullptr;
    _state = _DragStateCls::ready;
}

void DragGestureRecognizerCls::dispose() {
    _velocityTrackers->clear();
    super->dispose();
}

void DragGestureRecognizerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<DragStartBehavior>make<EnumPropertyCls>(__s("start behavior"), dragStartBehavior));
}

VelocityTracker DragGestureRecognizerCls::_defaultBuilder(PointerEvent event) {
    return VelocityTrackerCls->withKind(event->kind);
}

void DragGestureRecognizerCls::_addPointer(PointerEvent event) {
    _velocityTrackers[event->pointer] = velocityTrackerBuilder(event);
    if (_state == _DragStateCls::ready) {
        _state = _DragStateCls::possible;
        _initialPosition = make<OffsetPairCls>(event->position, event->localPosition());
        _pendingDragOffset = OffsetPairCls::zero;
        _globalDistanceMoved = 0.0;
        _lastPendingEventTimestamp = event->timeStamp;
        _lastTransform = event->transform;
        _checkDown();
    } else {
        if (_state == _DragStateCls::accepted) {
        resolve(GestureDispositionCls::accepted);
    }
;
    }}

void DragGestureRecognizerCls::_giveUpPointer(int pointer) {
    stopTrackingPointer(pointer);
    if (!_acceptedActivePointers->remove(pointer)) {
        resolvePointer(pointer, GestureDispositionCls::rejected);
    }
}

void DragGestureRecognizerCls::_checkDown() {
    assert(_initialButtons == kPrimaryButton);
    if (onDown != nullptr) {
        DragDownDetails details = make<DragDownDetailsCls>(_initialPosition->global, _initialPosition->local);
        <void>invokeCallback(__s("onDown"), [=] () {
            onDown!(details);
        });
    }
}

void DragGestureRecognizerCls::_checkStart(Duration timestamp, int pointer) {
    assert(_initialButtons == kPrimaryButton);
    if (onStart != nullptr) {
        DragStartDetails details = make<DragStartDetailsCls>(timestamp, _initialPosition->global, _initialPosition->local, getKindForPointer(pointer));
        <void>invokeCallback(__s("onStart"), [=] () {
            onStart!(details);
        });
    }
}

void DragGestureRecognizerCls::_checkUpdate(Offset delta, Offset globalPosition, Offset localPosition, double primaryDelta, Duration sourceTimeStamp) {
    assert(_initialButtons == kPrimaryButton);
    if (onUpdate != nullptr) {
        DragUpdateDetails details = make<DragUpdateDetailsCls>(sourceTimeStamp, delta, primaryDelta, globalPosition, localPosition);
        <void>invokeCallback(__s("onUpdate"), [=] () {
            onUpdate!(details);
        });
    }
}

void DragGestureRecognizerCls::_checkEnd(int pointer) {
    assert(_initialButtons == kPrimaryButton);
    if (onEnd == nullptr) {
        return;
    }
    VelocityTracker tracker = _velocityTrackers[pointer]!;
    assert(tracker != nullptr);
    DragEndDetails details;
    std::function<String()> debugReport;
    VelocityEstimate estimate = tracker->getVelocityEstimate();
    if (estimate != nullptr && isFlingGesture(estimate, tracker->kind)) {
        Velocity velocity = make<VelocityCls>(estimate->pixelsPerSecond)->clampMagnitude(minFlingVelocity | kMinFlingVelocity, maxFlingVelocity | kMaxFlingVelocity);
        details = make<DragEndDetailsCls>(velocity, _getPrimaryValueFromOffset(velocity->pixelsPerSecond));
        debugReport = [=] () {
            return __s("%s$%s;");
        };
    } else {
        details = make<DragEndDetailsCls>(0.0);
        debugReport = [=] () {
            if (estimate == nullptr) {
                return __s("Could not estimate velocity.");
            }
            return __s("%s;");
        };
    }
    <void>invokeCallback(__s("onEnd"), [=] () {
        onEnd!(details);
    }, debugReport);
}

void DragGestureRecognizerCls::_checkCancel() {
    assert(_initialButtons == kPrimaryButton);
    if (onCancel != nullptr) {
        <void>invokeCallback(__s("onCancel"), onCancel!);
    }
}

bool VerticalDragGestureRecognizerCls::isFlingGesture(VelocityEstimate estimate, PointerDeviceKind kind) {
    double minVelocity = minFlingVelocity | kMinFlingVelocity;
    double minDistance = minFlingDistance | computeHitSlop(kind, gestureSettings);
    return estimate->pixelsPerSecond->dy()->abs() > minVelocity && estimate->offset->dy()->abs() > minDistance;
}

String VerticalDragGestureRecognizerCls::debugDescription() {
    return __s("vertical drag");
}

bool VerticalDragGestureRecognizerCls::_hasSufficientGlobalDistanceToAccept(PointerDeviceKind pointerDeviceKind, double deviceTouchSlop) {
    return _globalDistanceMoved->abs() > computeHitSlop(pointerDeviceKind, gestureSettings);
}

Offset VerticalDragGestureRecognizerCls::_getDeltaForDetails(Offset delta) {
    return make<OffsetCls>(0.0, delta->dy());
}

double VerticalDragGestureRecognizerCls::_getPrimaryValueFromOffset(Offset value) {
    return value->dy();
}

bool HorizontalDragGestureRecognizerCls::isFlingGesture(VelocityEstimate estimate, PointerDeviceKind kind) {
    double minVelocity = minFlingVelocity | kMinFlingVelocity;
    double minDistance = minFlingDistance | computeHitSlop(kind, gestureSettings);
    return estimate->pixelsPerSecond->dx()->abs() > minVelocity && estimate->offset->dx()->abs() > minDistance;
}

String HorizontalDragGestureRecognizerCls::debugDescription() {
    return __s("horizontal drag");
}

bool HorizontalDragGestureRecognizerCls::_hasSufficientGlobalDistanceToAccept(PointerDeviceKind pointerDeviceKind, double deviceTouchSlop) {
    return _globalDistanceMoved->abs() > computeHitSlop(pointerDeviceKind, gestureSettings);
}

Offset HorizontalDragGestureRecognizerCls::_getDeltaForDetails(Offset delta) {
    return make<OffsetCls>(delta->dx(), 0.0);
}

double HorizontalDragGestureRecognizerCls::_getPrimaryValueFromOffset(Offset value) {
    return value->dx();
}

bool PanGestureRecognizerCls::isFlingGesture(VelocityEstimate estimate, PointerDeviceKind kind) {
    double minVelocity = minFlingVelocity | kMinFlingVelocity;
    double minDistance = minFlingDistance | computeHitSlop(kind, gestureSettings);
    return estimate->pixelsPerSecond->distanceSquared() > minVelocity * minVelocity && estimate->offset->distanceSquared() > minDistance * minDistance;
}

String PanGestureRecognizerCls::debugDescription() {
    return __s("pan");
}

bool PanGestureRecognizerCls::_hasSufficientGlobalDistanceToAccept(PointerDeviceKind pointerDeviceKind, double deviceTouchSlop) {
    return _globalDistanceMoved->abs() > computePanSlop(pointerDeviceKind, gestureSettings);
}

Offset PanGestureRecognizerCls::_getDeltaForDetails(Offset delta) {
    return delta;
}

double PanGestureRecognizerCls::_getPrimaryValueFromOffset(Offset value) {
    return nullptr;
}
