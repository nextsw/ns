#include "platform_views.hpp"
int PlatformViewsRegistry::getNextPlatformViewId() {
    return _nextPlatformViewId++;
}

AndroidViewController PlatformViewsService::initAndroidView(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, int id, TextDirection layoutDirection, VoidCallback onFocus, String viewType) {
    assert(id != nullptr);
    assert(viewType != nullptr);
    assert(layoutDirection != nullptr);
    assert(creationParams == nullptr || creationParamsCodec != nullptr);
    TextureAndroidViewController controller = TextureAndroidViewController._(id, viewType, layoutDirection, creationParams, creationParamsCodec);
    _instance._focusCallbacks[id] = onFocus ?? ;
    return controller;
}

SurfaceAndroidViewController PlatformViewsService::initSurfaceAndroidView(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, int id, TextDirection layoutDirection, VoidCallback onFocus, String viewType) {
    assert(id != nullptr);
    assert(viewType != nullptr);
    assert(layoutDirection != nullptr);
    assert(creationParams == nullptr || creationParamsCodec != nullptr);
    SurfaceAndroidViewController controller = SurfaceAndroidViewController._(id, viewType, layoutDirection, creationParams, creationParamsCodec);
    _instance._focusCallbacks[id] = onFocus ?? ;
    return controller;
}

ExpensiveAndroidViewController PlatformViewsService::initExpensiveAndroidView(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, int id, TextDirection layoutDirection, VoidCallback onFocus, String viewType) {
    ExpensiveAndroidViewController controller = ExpensiveAndroidViewController._(id, viewType, layoutDirection, creationParams, creationParamsCodec);
    _instance._focusCallbacks[id] = onFocus ?? ;
    return controller;
}

Future<void> PlatformViewsService::synchronizeToNativeViewHierarchy(bool yes) {
}

Future<UiKitViewController> PlatformViewsService::initUiKitView(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, int id, TextDirection layoutDirection, VoidCallback onFocus, String viewType) {
    assert(id != nullptr);
    assert(viewType != nullptr);
    assert(layoutDirection != nullptr);
    assert(creationParams == nullptr || creationParamsCodec != nullptr);
    Map<String, dynamic> args = ;
    if (creationParams != nullptr) {
        ByteData paramsByteData = creationParamsCodec!.encodeMessage(creationParams)!;
        args["params"] = Uint8List.view(paramsByteData.buffer, 0, paramsByteData.lengthInBytes);
    }
    await await SystemChannels.platform_views.<void>invokeMethod("create", args);
    if (onFocus != nullptr) {
        _instance._focusCallbacks[id] = onFocus;
    }
    return UiKitViewController._(id, layoutDirection);
}

void PlatformViewsService::_() {
    SystemChannels.platform_views.setMethodCallHandler(_onMethodCall);
}

Future<void> PlatformViewsService::_onMethodCall(MethodCall call) {
    ;
    return <void>value();
}

AndroidPointerProperties::AndroidPointerProperties(int id, int toolType) {
    {
        assert(id != nullptr);
        assert(toolType != nullptr);
    }
}

String AndroidPointerProperties::toString() {
    return "${objectRuntimeType(this, 'AndroidPointerProperties')}(id: $id, toolType: $toolType)";
}

List<int> AndroidPointerProperties::_asList() {
    return ;
}

AndroidPointerCoords::AndroidPointerCoords(double orientation, double pressure, double size, double toolMajor, double toolMinor, double touchMajor, double touchMinor, double x, double y) {
    {
        assert(orientation != nullptr);
        assert(pressure != nullptr);
        assert(size != nullptr);
        assert(toolMajor != nullptr);
        assert(toolMinor != nullptr);
        assert(touchMajor != nullptr);
        assert(touchMinor != nullptr);
        assert(x != nullptr);
        assert(y != nullptr);
    }
}

String AndroidPointerCoords::toString() {
    return "${objectRuntimeType(this, 'AndroidPointerCoords')}(orientation: $orientation, pressure: $pressure, size: $size, toolMajor: $toolMajor, toolMinor: $toolMinor, touchMajor: $touchMajor, touchMinor: $touchMinor, x: $x, y: $y)";
}

List<double> AndroidPointerCoords::_asList() {
    return ;
}

AndroidMotionEvent::AndroidMotionEvent(int action, int buttonState, int deviceId, int downTime, int edgeFlags, int eventTime, int flags, int metaState, int motionEventId, List<AndroidPointerCoords> pointerCoords, int pointerCount, List<AndroidPointerProperties> pointerProperties, int source, double xPrecision, double yPrecision) {
    {
        assert(downTime != nullptr);
        assert(eventTime != nullptr);
        assert(action != nullptr);
        assert(pointerCount != nullptr);
        assert(pointerProperties != nullptr);
        assert(pointerCoords != nullptr);
        assert(metaState != nullptr);
        assert(buttonState != nullptr);
        assert(xPrecision != nullptr);
        assert(yPrecision != nullptr);
        assert(deviceId != nullptr);
        assert(edgeFlags != nullptr);
        assert(source != nullptr);
        assert(flags != nullptr);
        assert(pointerProperties.length == pointerCount);
        assert(pointerCoords.length == pointerCount);
    }
}

String AndroidMotionEvent::toString() {
    return "AndroidPointerEvent(downTime: $downTime, eventTime: $eventTime, action: $action, pointerCount: $pointerCount, pointerProperties: $pointerProperties, pointerCoords: $pointerCoords, metaState: $metaState, buttonState: $buttonState, xPrecision: $xPrecision, yPrecision: $yPrecision, deviceId: $deviceId, edgeFlags: $edgeFlags, source: $source, flags: $flags, motionEventId: $motionEventId)";
}

List<dynamic> AndroidMotionEvent::_asList(int viewId) {
    return ;
}

PointTransformer _AndroidMotionEventConverter::pointTransformer() {
    return _pointTransformer;
}

void _AndroidMotionEventConverter::pointTransformer(PointTransformer transformer) {
    assert(transformer != nullptr);
    _pointTransformer = transformer;
}

void _AndroidMotionEventConverter::handlePointerDownEvent(PointerDownEvent event) {
    if (pointerProperties.isEmpty) {
        downTimeMillis = event.timeStamp.inMilliseconds;
    }
    int androidPointerId = 0;
    while (usedAndroidPointerIds.contains(androidPointerId)) {
        androidPointerId++;
    }
    usedAndroidPointerIds.add(androidPointerId);
    pointerProperties[event.pointer] = propertiesFor(event, androidPointerId);
}

void _AndroidMotionEventConverter::updatePointerPositions(PointerEvent event) {
    Offset position = _pointTransformer(event.position);
    pointerPositions[event.pointer] = AndroidPointerCoords(event.orientation, event.pressure, event.size, event.radiusMajor, event.radiusMinor, event.radiusMajor, event.radiusMinor, position.dx, position.dy);
}

void _AndroidMotionEventConverter::handlePointerUpEvent(PointerUpEvent event) {
    _remove(event.pointer);
}

void _AndroidMotionEventConverter::handlePointerCancelEvent(PointerCancelEvent event) {
    _remove(event.pointer);
}

AndroidMotionEvent _AndroidMotionEventConverter::toAndroidMotionEvent(PointerEvent event) {
    List<int> pointers = pointerPositions.keys.toList();
    int pointerIdx = pointers.indexOf(event.pointer);
    int numPointers = pointers.length;
    int kPointerDataFlagBatched = 1;
    if (event.platformData == kPointerDataFlagBatched || (isSinglePointerAction(event) &&  < numPointers - 1)) {
        return nullptr;
    }
    int action;
    if (event is PointerDownEvent) {
        action = numPointers == 1? AndroidViewController.kActionDown : AndroidViewController.pointerAction(pointerIdx, AndroidViewController.kActionPointerDown);
    } else     {
        if (event is PointerUpEvent) {
        action = numPointers == 1? AndroidViewController.kActionUp : AndroidViewController.pointerAction(pointerIdx, AndroidViewController.kActionPointerUp);
    } else     {
        if (event is PointerMoveEvent) {
        action = AndroidViewController.kActionMove;
    } else     {
        if (event is PointerCancelEvent) {
        action = AndroidViewController.kActionCancel;
    } else {
        return nullptr;
    }
;
    };
    };
    }    return AndroidMotionEvent(downTimeMillis!, event.timeStamp.inMilliseconds, action, pointerPositions.length, pointers.<AndroidPointerProperties>map().toList(), pointers.<AndroidPointerCoords>map().toList(), 0, 0, 1.0, 1.0, 0, 0, 0, 0, event.embedderId);
}

AndroidPointerProperties _AndroidMotionEventConverter::propertiesFor(PointerEvent event, int pointerId) {
    int toolType = AndroidPointerProperties.kToolTypeUnknown;
    ;
    return AndroidPointerProperties(pointerId, toolType);
}

bool _AndroidMotionEventConverter::isSinglePointerAction(PointerEvent event) {
    return event is! PointerDownEvent && event is! PointerUpEvent;
}

void _AndroidMotionEventConverter::_remove(int pointer) {
    pointerPositions.remove(pointer);
    usedAndroidPointerIds.remove(pointerProperties[pointer]!.id);
    pointerProperties.remove(pointer);
    if (pointerProperties.isEmpty) {
        downTimeMillis = nullptr;
    }
}

int AndroidViewController::pointerAction(int action, int pointerId) {
    return ((pointerId << 8) & 0xff00) | (action & 0xff);
}

bool AndroidViewController::awaitingCreation() {
    return _state == _AndroidViewState.waitingForSize;
}

Future<void> AndroidViewController::create(Size size) {
    assert(_state != _AndroidViewState.disposed, "trying to create a disposed Android view");
    assert(_state == _AndroidViewState.waitingForSize, "Android view is already sized. View id: $viewId");
    if (_createRequiresSize && size == nullptr) {
        return;
    }
    _state = _AndroidViewState.creating;
    await await _sendCreateMessage(size);
    _state = _AndroidViewState.created;
    for (PlatformViewCreatedCallback callback : _platformViewCreatedCallbacks) {
        callback(viewId);
    }
}

Future<Size> AndroidViewController::setSize(Size size) {
    assert(_state != _AndroidViewState.disposed, "Android view is disposed. View id: $viewId");
    if (_state == _AndroidViewState.waitingForSize) {
        await await create(size);
        return size;
    } else {
        return _sendResizeMessage(size);
    }
}

Future<void> AndroidViewController::sendMotionEvent(AndroidMotionEvent event) {
    await await SystemChannels.platform_views.<dynamic>invokeMethod("touch", event._asList(viewId));
}

PointTransformer AndroidViewController::pointTransformer() {
    return _motionEventConverter._pointTransformer;
}

void AndroidViewController::pointTransformer(PointTransformer transformer) {
    assert(transformer != nullptr);
    _motionEventConverter._pointTransformer = transformer;
}

bool AndroidViewController::isCreated() {
    return _state == _AndroidViewState.created;
}

void AndroidViewController::addOnPlatformViewCreatedListener(PlatformViewCreatedCallback listener) {
    assert(listener != nullptr);
    assert(_state != _AndroidViewState.disposed);
    _platformViewCreatedCallbacks.add(listener);
}

void AndroidViewController::removeOnPlatformViewCreatedListener(PlatformViewCreatedCallback listener) {
    assert(listener != nullptr);
    assert(_state != _AndroidViewState.disposed);
    _platformViewCreatedCallbacks.remove(listener);
}

List<PlatformViewCreatedCallback> AndroidViewController::createdCallbacks() {
    return _platformViewCreatedCallbacks;
}

Future<void> AndroidViewController::setLayoutDirection(TextDirection layoutDirection) {
    assert(_state != _AndroidViewState.disposed, "trying to set a layout direction for a disposed UIView. View id: $viewId");
    if (layoutDirection == _layoutDirection) {
        return;
    }
    assert(layoutDirection != nullptr);
    _layoutDirection = layoutDirection;
    if (_state == _AndroidViewState.waitingForSize) {
        return;
    }
    await await SystemChannels.platform_views.<void>invokeMethod("setDirection", );
}

Future<void> AndroidViewController::dispatchPointerEvent(PointerEvent event) {
    if (event is PointerHoverEvent) {
        return;
    }
    if (event is PointerDownEvent) {
        _motionEventConverter.handlePointerDownEvent(event);
    }
    _motionEventConverter.updatePointerPositions(event);
    AndroidMotionEvent androidEvent = _motionEventConverter.toAndroidMotionEvent(event);
    if (event is PointerUpEvent) {
        _motionEventConverter.handlePointerUpEvent(event);
    } else     {
        if (event is PointerCancelEvent) {
        _motionEventConverter.handlePointerCancelEvent(event);
    }
;
    }    if (androidEvent != nullptr) {
        await await sendMotionEvent(androidEvent);
    }
}

Future<void> AndroidViewController::clearFocus() {
    if (_state != _AndroidViewState.created) {
        return <void>value();
    }
    return SystemChannels.platform_views.<void>invokeMethod("clearFocus", viewId);
}

Future<void> AndroidViewController::dispose() {
    if (_state == _AndroidViewState.creating || _state == _AndroidViewState.created) {
        await await _sendDisposeMessage();
    }
    _platformViewCreatedCallbacks.clear();
    _state = _AndroidViewState.disposed;
    PlatformViewsService._instance._focusCallbacks.remove(viewId);
}

void AndroidViewController::_(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, TextDirection layoutDirection, int viewId, String viewType)

int AndroidViewController::_getAndroidDirection(TextDirection direction) {
    assert(direction != nullptr);
    ;
}

void SurfaceAndroidViewController::_(Unknown, Unknown, Unknown, Unknown, Unknown)

int ExpensiveAndroidViewController::textureId() {
    ;
}

Future<void> ExpensiveAndroidViewController::setOffset(Offset off) {
    ;
}

void ExpensiveAndroidViewController::_(Unknown, Unknown, Unknown, Unknown, Unknown)

bool ExpensiveAndroidViewController::_createRequiresSize() {
    return false;
}

Future<void> ExpensiveAndroidViewController::_sendCreateMessage(Size size) {
    Map<String, dynamic> args = ;
    if (_creationParams != nullptr) {
        ByteData paramsByteData = _creationParamsCodec!.encodeMessage(_creationParams)!;
        args["params"] = Uint8List.view(paramsByteData.buffer, 0, paramsByteData.lengthInBytes);
    }
    await await SystemChannels.platform_views.<void>invokeMethod("create", args);
}

Future<void> ExpensiveAndroidViewController::_sendDisposeMessage() {
    return SystemChannels.platform_views.<void>invokeMethod("dispose", );
}

Future<Size> ExpensiveAndroidViewController::_sendResizeMessage(Size size) {
    ;
}

int TextureAndroidViewController::textureId() {
    return _textureId;
}

Future<void> TextureAndroidViewController::setOffset(Offset off) {
    if (off == _off) {
        return;
    }
    if (_state != _AndroidViewState.created) {
        return;
    }
    _off = off;
    await await SystemChannels.platform_views.<void>invokeMethod("offset", );
}

void TextureAndroidViewController::_(Unknown, Unknown, Unknown, Unknown, Unknown)

Future<Size> TextureAndroidViewController::_sendResizeMessage(Size size) {
    assert(_state != _AndroidViewState.waitingForSize, "Android view must have an initial size. View id: $viewId");
    assert(size != nullptr);
    assert(!size.isEmpty);
    Map<Object, Object> meta = await SystemChannels.platform_views.<Object, Object>invokeMapMethod("resize", );
    assert(meta != nullptr);
    assert(meta!.containsKey("width"));
    assert(meta!.containsKey("height"));
    return Size((, ();
}

bool TextureAndroidViewController::_createRequiresSize() {
    return true;
}

Future<void> TextureAndroidViewController::_sendCreateMessage(Size size) {
    assert(!size.isEmpty, "trying to create $TextureAndroidViewController without setting a valid size.");
    Map<String, dynamic> args = ;
    if (_creationParams != nullptr) {
        ByteData paramsByteData = _creationParamsCodec!.encodeMessage(_creationParams)!;
        args["params"] = Uint8List.view(paramsByteData.buffer, 0, paramsByteData.lengthInBytes);
    }
    _textureId = await SystemChannels.platform_views.<int>invokeMethod("create", args);
}

Future<void> TextureAndroidViewController::_sendDisposeMessage() {
    return SystemChannels.platform_views.<void>invokeMethod("dispose", );
}

Future<void> UiKitViewController::setLayoutDirection(TextDirection layoutDirection) {
    assert(!_debugDisposed, "trying to set a layout direction for a disposed iOS UIView. View id: $id");
    if (layoutDirection == _layoutDirection) {
        return;
    }
    assert(layoutDirection != nullptr);
    _layoutDirection = layoutDirection;
}

Future<void> UiKitViewController::acceptGesture() {
    Map<String, dynamic> args = ;
    return SystemChannels.platform_views.invokeMethod("acceptGesture", args);
}

Future<void> UiKitViewController::rejectGesture() {
    Map<String, dynamic> args = ;
    return SystemChannels.platform_views.invokeMethod("rejectGesture", args);
}

Future<void> UiKitViewController::dispose() {
    _debugDisposed = true;
    await await SystemChannels.platform_views.<void>invokeMethod("dispose", id);
}

void UiKitViewController::_(int id, TextDirection layoutDirection)

bool PlatformViewController::awaitingCreation() {
    return false;
}

Future<void> PlatformViewController::create(Size size) {
}
