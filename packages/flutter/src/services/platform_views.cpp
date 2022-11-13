#include "platform_views.hpp"
int PlatformViewsRegistryCls::getNextPlatformViewId() {
    return _nextPlatformViewId++;
}

AndroidViewController PlatformViewsServiceCls::initAndroidView(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, int id, TextDirection layoutDirection, VoidCallback onFocus, String viewType) {
    assert(id != nullptr);
    assert(viewType != nullptr);
    assert(layoutDirection != nullptr);
    assert(creationParams == nullptr || creationParamsCodec != nullptr);
    TextureAndroidViewController controller = TextureAndroidViewControllerCls->_(id, viewType, layoutDirection, creationParams, creationParamsCodec);
    _instance->_focusCallbacks[id] = onFocus | [=] () {
    };
    return controller;
}

SurfaceAndroidViewController PlatformViewsServiceCls::initSurfaceAndroidView(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, int id, TextDirection layoutDirection, VoidCallback onFocus, String viewType) {
    assert(id != nullptr);
    assert(viewType != nullptr);
    assert(layoutDirection != nullptr);
    assert(creationParams == nullptr || creationParamsCodec != nullptr);
    SurfaceAndroidViewController controller = SurfaceAndroidViewControllerCls->_(id, viewType, layoutDirection, creationParams, creationParamsCodec);
    _instance->_focusCallbacks[id] = onFocus | [=] () {
    };
    return controller;
}

ExpensiveAndroidViewController PlatformViewsServiceCls::initExpensiveAndroidView(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, int id, TextDirection layoutDirection, VoidCallback onFocus, String viewType) {
    ExpensiveAndroidViewController controller = ExpensiveAndroidViewControllerCls->_(id, viewType, layoutDirection, creationParams, creationParamsCodec);
    _instance->_focusCallbacks[id] = onFocus | [=] () {
    };
    return controller;
}

Future<void> PlatformViewsServiceCls::synchronizeToNativeViewHierarchy(bool yes) {
}

Future<UiKitViewController> PlatformViewsServiceCls::initUiKitView(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, int id, TextDirection layoutDirection, VoidCallback onFocus, String viewType) {
    assert(id != nullptr);
    assert(viewType != nullptr);
    assert(layoutDirection != nullptr);
    assert(creationParams == nullptr || creationParamsCodec != nullptr);
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set(__s("id"), id);map1.set(__s("viewType"), viewType);Map<String, dynamic> args = list1;
    if (creationParams != nullptr) {
        ByteData paramsByteData = creationParamsCodec!->encodeMessage(creationParams)!;
        args[__s("params")] = Uint8ListCls->view(paramsByteData->buffer(), 0, paramsByteData->lengthInBytes());
    }
    await await SystemChannelsCls::platform_views-><void>invokeMethod(__s("create"), args);
    if (onFocus != nullptr) {
        _instance->_focusCallbacks[id] = onFocus;
    }
    return UiKitViewControllerCls->_(id, layoutDirection);
}

void PlatformViewsServiceCls::_() {
    SystemChannelsCls::platform_views->setMethodCallHandler(_onMethodCall);
}

Future<void> PlatformViewsServiceCls::_onMethodCall(MethodCall call) {
    ;
    return <void>value();
}

AndroidPointerPropertiesCls::AndroidPointerPropertiesCls(int id, int toolType) {
    {
        assert(id != nullptr);
        assert(toolType != nullptr);
    }
}

String AndroidPointerPropertiesCls::toString() {
    return __sf("%s(id: %s, toolType: %s)", objectRuntimeType(this, __s("AndroidPointerProperties")), id, toolType);
}

List<int> AndroidPointerPropertiesCls::_asList() {
    return makeList(ArrayItem, ArrayItem);
}

AndroidPointerCoordsCls::AndroidPointerCoordsCls(double orientation, double pressure, double size, double toolMajor, double toolMinor, double touchMajor, double touchMinor, double x, double y) {
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

String AndroidPointerCoordsCls::toString() {
    return __sf("%s(orientation: %s, pressure: %s, size: %s, toolMajor: %s, toolMinor: %s, touchMajor: %s, touchMinor: %s, x: %s, y: %s)", objectRuntimeType(this, __s("AndroidPointerCoords")), orientation, pressure, size, toolMajor, toolMinor, touchMajor, touchMinor, x, y);
}

List<double> AndroidPointerCoordsCls::_asList() {
    return makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem);
}

AndroidMotionEventCls::AndroidMotionEventCls(int action, int buttonState, int deviceId, int downTime, int edgeFlags, int eventTime, int flags, int metaState, int motionEventId, List<AndroidPointerCoords> pointerCoords, int pointerCount, List<AndroidPointerProperties> pointerProperties, int source, double xPrecision, double yPrecision) {
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
        assert(pointerProperties->length() == pointerCount);
        assert(pointerCoords->length() == pointerCount);
    }
}

String AndroidMotionEventCls::toString() {
    return __sf("AndroidPointerEvent(downTime: %s, eventTime: %s, action: %s, pointerCount: %s, pointerProperties: %s, pointerCoords: %s, metaState: %s, buttonState: %s, xPrecision: %s, yPrecision: %s, deviceId: %s, edgeFlags: %s, source: %s, flags: %s, motionEventId: %s)", downTime, eventTime, action, pointerCount, pointerProperties, pointerCoords, metaState, buttonState, xPrecision, yPrecision, deviceId, edgeFlags, source, flags, motionEventId);
}

List<dynamic> AndroidMotionEventCls::_asList(int viewId) {
    return makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem);
}

PointTransformer _AndroidMotionEventConverterCls::pointTransformer() {
    return _pointTransformer;
}

void _AndroidMotionEventConverterCls::pointTransformer(PointTransformer transformer) {
    assert(transformer != nullptr);
    _pointTransformer = transformer;
}

void _AndroidMotionEventConverterCls::handlePointerDownEvent(PointerDownEvent event) {
    if (pointerProperties->isEmpty()) {
        downTimeMillis = event->timeStamp->inMilliseconds();
    }
    int androidPointerId = 0;
    while (usedAndroidPointerIds->contains(androidPointerId)) {
        androidPointerId++;
    }
    usedAndroidPointerIds->add(androidPointerId);
    pointerProperties[event->pointer] = propertiesFor(event, androidPointerId);
}

void _AndroidMotionEventConverterCls::updatePointerPositions(PointerEvent event) {
    Offset position = _pointTransformer(event->position);
    pointerPositions[event->pointer] = make<AndroidPointerCoordsCls>(event->orientation, event->pressure, event->size, event->radiusMajor, event->radiusMinor, event->radiusMajor, event->radiusMinor, position->dx(), position->dy());
}

void _AndroidMotionEventConverterCls::handlePointerUpEvent(PointerUpEvent event) {
    _remove(event->pointer);
}

void _AndroidMotionEventConverterCls::handlePointerCancelEvent(PointerCancelEvent event) {
    _remove(event->pointer);
}

AndroidMotionEvent _AndroidMotionEventConverterCls::toAndroidMotionEvent(PointerEvent event) {
    List<int> pointers = pointerPositions->keys()->toList();
    int pointerIdx = pointers->indexOf(event->pointer);
    int numPointers = pointers->length();
    int kPointerDataFlagBatched = 1;
    if (event->platformData == kPointerDataFlagBatched || (isSinglePointerAction(event) &&  < numPointers - 1)) {
        return nullptr;
    }
    int action;
    if (is<PointerDownEvent>(event)) {
        action = numPointers == 1? AndroidViewControllerCls::kActionDown : AndroidViewControllerCls->pointerAction(pointerIdx, AndroidViewControllerCls::kActionPointerDown);
    } else {
        if (is<PointerUpEvent>(event)) {
        action = numPointers == 1? AndroidViewControllerCls::kActionUp : AndroidViewControllerCls->pointerAction(pointerIdx, AndroidViewControllerCls::kActionPointerUp);
    } else {
        if (is<PointerMoveEvent>(event)) {
        action = AndroidViewControllerCls::kActionMove;
    } else {
        if (is<PointerCancelEvent>(event)) {
        action = AndroidViewControllerCls::kActionCancel;
    } else {
        return nullptr;
    }
;
    };
    };
    }    return make<AndroidMotionEventCls>(downTimeMillis!, event->timeStamp->inMilliseconds(), action, pointerPositions->length(), pointers-><AndroidPointerProperties>map([=] (int i) {
        pointerProperties[i]!;
    })->toList(), pointers-><AndroidPointerCoords>map([=] (int i) {
        pointerPositions[i]!;
    })->toList(), 0, 0, 1.0, 1.0, 0, 0, 0, 0, event->embedderId);
}

AndroidPointerProperties _AndroidMotionEventConverterCls::propertiesFor(PointerEvent event, int pointerId) {
    int toolType = AndroidPointerPropertiesCls::kToolTypeUnknown;
    ;
    return make<AndroidPointerPropertiesCls>(pointerId, toolType);
}

bool _AndroidMotionEventConverterCls::isSinglePointerAction(PointerEvent event) {
    return !is<PointerDownEvent>(event) && !is<PointerUpEvent>(event);
}

void _AndroidMotionEventConverterCls::_remove(int pointer) {
    pointerPositions->remove(pointer);
    usedAndroidPointerIds->remove(pointerProperties[pointer]!->id);
    pointerProperties->remove(pointer);
    if (pointerProperties->isEmpty()) {
        downTimeMillis = nullptr;
    }
}

int AndroidViewControllerCls::pointerAction(int pointerId, int action) {
    return ((pointerId << 8) & 0xff00) | (action & 0xff);
}

bool AndroidViewControllerCls::awaitingCreation() {
    return _state == _AndroidViewStateCls::waitingForSize;
}

Future<void> AndroidViewControllerCls::create(Size size) {
    assert(_state != _AndroidViewStateCls::disposed, __s("trying to create a disposed Android view"));
    assert(_state == _AndroidViewStateCls::waitingForSize, __sf("Android view is already sized. View id: %s", viewId));
    if (_createRequiresSize() && size == nullptr) {
        return;
    }
    _state = _AndroidViewStateCls::creating;
    await await _sendCreateMessage(size);
    _state = _AndroidViewStateCls::created;
    for (PlatformViewCreatedCallback callback : _platformViewCreatedCallbacks) {
        callback(viewId);
    }
}

Future<Size> AndroidViewControllerCls::setSize(Size size) {
    assert(_state != _AndroidViewStateCls::disposed, __sf("Android view is disposed. View id: %s", viewId));
    if (_state == _AndroidViewStateCls::waitingForSize) {
        await await create(size);
        return size;
    } else {
        return _sendResizeMessage(size);
    }
}

Future<void> AndroidViewControllerCls::sendMotionEvent(AndroidMotionEvent event) {
    await await SystemChannelsCls::platform_views-><dynamic>invokeMethod(__s("touch"), event->_asList(viewId));
}

PointTransformer AndroidViewControllerCls::pointTransformer() {
    return _motionEventConverter->_pointTransformer;
}

void AndroidViewControllerCls::pointTransformer(PointTransformer transformer) {
    assert(transformer != nullptr);
    _motionEventConverter->_pointTransformer = transformer;
}

bool AndroidViewControllerCls::isCreated() {
    return _state == _AndroidViewStateCls::created;
}

void AndroidViewControllerCls::addOnPlatformViewCreatedListener(PlatformViewCreatedCallback listener) {
    assert(listener != nullptr);
    assert(_state != _AndroidViewStateCls::disposed);
    _platformViewCreatedCallbacks->add(listener);
}

void AndroidViewControllerCls::removeOnPlatformViewCreatedListener(PlatformViewCreatedCallback listener) {
    assert(listener != nullptr);
    assert(_state != _AndroidViewStateCls::disposed);
    _platformViewCreatedCallbacks->remove(listener);
}

List<PlatformViewCreatedCallback> AndroidViewControllerCls::createdCallbacks() {
    return _platformViewCreatedCallbacks;
}

Future<void> AndroidViewControllerCls::setLayoutDirection(TextDirection layoutDirection) {
    assert(_state != _AndroidViewStateCls::disposed, __sf("trying to set a layout direction for a disposed UIView. View id: %s", viewId));
    if (layoutDirection == _layoutDirection) {
        return;
    }
    assert(layoutDirection != nullptr);
    _layoutDirection = layoutDirection;
    if (_state == _AndroidViewStateCls::waitingForSize) {
        return;
    }
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set(__s("id"), viewId);map1.set(__s("direction"), _getAndroidDirection(layoutDirection));await await SystemChannelsCls::platform_views-><void>invokeMethod(__s("setDirection"), list1);
}

Future<void> AndroidViewControllerCls::dispatchPointerEvent(PointerEvent event) {
    if (is<PointerHoverEvent>(event)) {
        return;
    }
    if (is<PointerDownEvent>(event)) {
        _motionEventConverter->handlePointerDownEvent(as<PointerDownEventCls>(event));
    }
    _motionEventConverter->updatePointerPositions(event);
    AndroidMotionEvent androidEvent = _motionEventConverter->toAndroidMotionEvent(event);
    if (is<PointerUpEvent>(event)) {
        _motionEventConverter->handlePointerUpEvent(as<PointerUpEventCls>(event));
    } else {
        if (is<PointerCancelEvent>(event)) {
        _motionEventConverter->handlePointerCancelEvent(as<PointerCancelEventCls>(event));
    }
;
    }    if (androidEvent != nullptr) {
        await await sendMotionEvent(androidEvent);
    }
}

Future<void> AndroidViewControllerCls::clearFocus() {
    if (_state != _AndroidViewStateCls::created) {
        return <void>value();
    }
    return SystemChannelsCls::platform_views-><void>invokeMethod(__s("clearFocus"), viewId);
}

Future<void> AndroidViewControllerCls::dispose() {
    if (_state == _AndroidViewStateCls::creating || _state == _AndroidViewStateCls::created) {
        await await _sendDisposeMessage();
    }
    _platformViewCreatedCallbacks->clear();
    _state = _AndroidViewStateCls::disposed;
    PlatformViewsServiceCls::_instance->_focusCallbacks->remove(viewId);
}

void AndroidViewControllerCls::_(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, TextDirection layoutDirection, int viewId, String viewType)

int AndroidViewControllerCls::_getAndroidDirection(TextDirection direction) {
    assert(direction != nullptr);
    ;
}

void SurfaceAndroidViewControllerCls::_(Unknown creationParams, Unknown creationParamsCodec, Unknown layoutDirection, int viewId, Unknown viewType)

int ExpensiveAndroidViewControllerCls::textureId() {
    throw make<UnimplementedErrorCls>(__sf("Not supported for %s.", SurfaceAndroidViewControllerCls));
}

Future<void> ExpensiveAndroidViewControllerCls::setOffset(Offset off) {
    throw make<UnimplementedErrorCls>(__sf("Not supported for %s.", SurfaceAndroidViewControllerCls));
}

void ExpensiveAndroidViewControllerCls::_(Unknown creationParams, Unknown creationParamsCodec, Unknown layoutDirection, int viewId, Unknown viewType)

bool ExpensiveAndroidViewControllerCls::_createRequiresSize() {
    return false;
}

Future<void> ExpensiveAndroidViewControllerCls::_sendCreateMessage(Size size) {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set(__s("id"), viewId);map1.set(__s("viewType"), _viewType);map1.set(__s("direction"), AndroidViewControllerCls->_getAndroidDirection(_layoutDirection));map1.set(__s("hybrid"), true);Map<String, dynamic> args = list1;
    if (_creationParams != nullptr) {
        ByteData paramsByteData = _creationParamsCodec!->encodeMessage(_creationParams)!;
        args[__s("params")] = Uint8ListCls->view(paramsByteData->buffer(), 0, paramsByteData->lengthInBytes());
    }
    await await SystemChannelsCls::platform_views-><void>invokeMethod(__s("create"), args);
}

Future<void> ExpensiveAndroidViewControllerCls::_sendDisposeMessage() {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set(__s("id"), viewId);map1.set(__s("hybrid"), true);return SystemChannelsCls::platform_views-><void>invokeMethod(__s("dispose"), list1);
}

Future<Size> ExpensiveAndroidViewControllerCls::_sendResizeMessage(Size size) {
    throw make<UnimplementedErrorCls>(__sf("Not supported for %s.", SurfaceAndroidViewControllerCls));
}

int TextureAndroidViewControllerCls::textureId() {
    return _textureId;
}

Future<void> TextureAndroidViewControllerCls::setOffset(Offset off) {
    if (off == _off) {
        return;
    }
    if (_state != _AndroidViewStateCls::created) {
        return;
    }
    _off = off;
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set(__s("id"), viewId);map1.set(__s("top"), off->dy());map1.set(__s("left"), off->dx());await await SystemChannelsCls::platform_views-><void>invokeMethod(__s("offset"), list1);
}

void TextureAndroidViewControllerCls::_(Unknown creationParams, Unknown creationParamsCodec, Unknown layoutDirection, int viewId, Unknown viewType)

Future<Size> TextureAndroidViewControllerCls::_sendResizeMessage(Size size) {
    assert(_state != _AndroidViewStateCls::waitingForSize, __sf("Android view must have an initial size. View id: %s", viewId));
    assert(size != nullptr);
    assert(!size->isEmpty());
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set(__s("id"), viewId);map1.set(__s("width"), size->width());map1.set(__s("height"), size->height());Map<Object, Object> meta = await SystemChannelsCls::platform_views-><Object, Object>invokeMapMethod(__s("resize"), list1);
    assert(meta != nullptr);
    assert(meta!->containsKey(__s("width")));
    assert(meta!->containsKey(__s("height")));
    return make<SizeCls>(as<double>(meta![__s("width")]!), as<double>(meta[__s("height")]!));
}

bool TextureAndroidViewControllerCls::_createRequiresSize() {
    return true;
}

Future<void> TextureAndroidViewControllerCls::_sendCreateMessage(Size size) {
    assert(!size->isEmpty(), __sf("trying to create %s without setting a valid size.", TextureAndroidViewControllerCls));
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set(__s("id"), viewId);map1.set(__s("viewType"), _viewType);map1.set(__s("width"), size->width());map1.set(__s("height"), size->height());map1.set(__s("direction"), AndroidViewControllerCls->_getAndroidDirection(_layoutDirection));Map<String, dynamic> args = list1;
    if (_creationParams != nullptr) {
        ByteData paramsByteData = _creationParamsCodec!->encodeMessage(_creationParams)!;
        args[__s("params")] = Uint8ListCls->view(paramsByteData->buffer(), 0, paramsByteData->lengthInBytes());
    }
    _textureId = await SystemChannelsCls::platform_views-><int>invokeMethod(__s("create"), args);
}

Future<void> TextureAndroidViewControllerCls::_sendDisposeMessage() {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set(__s("id"), viewId);map1.set(__s("hybrid"), false);return SystemChannelsCls::platform_views-><void>invokeMethod(__s("dispose"), list1);
}

Future<void> UiKitViewControllerCls::setLayoutDirection(TextDirection layoutDirection) {
    assert(!_debugDisposed, __sf("trying to set a layout direction for a disposed iOS UIView. View id: %s", id));
    if (layoutDirection == _layoutDirection) {
        return;
    }
    assert(layoutDirection != nullptr);
    _layoutDirection = layoutDirection;
}

Future<void> UiKitViewControllerCls::acceptGesture() {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set(__s("id"), id);Map<String, dynamic> args = list1;
    return SystemChannelsCls::platform_views->invokeMethod(__s("acceptGesture"), args);
}

Future<void> UiKitViewControllerCls::rejectGesture() {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set(__s("id"), id);Map<String, dynamic> args = list1;
    return SystemChannelsCls::platform_views->invokeMethod(__s("rejectGesture"), args);
}

Future<void> UiKitViewControllerCls::dispose() {
    _debugDisposed = true;
    await await SystemChannelsCls::platform_views-><void>invokeMethod(__s("dispose"), id);
}

void UiKitViewControllerCls::_(int id, TextDirection layoutDirection)

bool PlatformViewControllerCls::awaitingCreation() {
    return false;
}

Future<void> PlatformViewControllerCls::create(Size size) {
}
