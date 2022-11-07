#include "platform_view.hpp"
bool _factoryTypesSetEquals<T>(Set<Factory<T>> a, Set<Factory<T>> b) {
    if (a == b) {
        return true;
    }
    if (a == nullptr || b == nullptr) {
        return false;
    }
    return setEquals(_factoriesTypeSet(a), _factoriesTypeSet(b));
}

Set<Type> _factoriesTypeSet<T>(Set<Factory<T>> factories) {
    return factories.<Type>map().toSet();
}

RenderAndroidView::RenderAndroidView(Clip clipBehavior, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, AndroidViewController viewController) {
    {
        assert(viewController != nullptr);
        assert(hitTestBehavior != nullptr);
        assert(gestureRecognizers != nullptr);
        assert(clipBehavior != nullptr);
        _viewController = viewController;
        _clipBehavior = clipBehavior;
        super(viewController, hitTestBehavior, gestureRecognizers);
    }
    {
        _viewController.pointTransformer = ;
        updateGestureRecognizers(gestureRecognizers);
        _viewController.addOnPlatformViewCreatedListener(_onPlatformViewCreated);
        this.hitTestBehavior = hitTestBehavior;
        _setOffset();
    }
}

AndroidViewController RenderAndroidView::controller() {
    return _viewController;
}

void RenderAndroidView::controller(AndroidViewController controller) {
    assert(!_isDisposed);
    assert(_viewController != nullptr);
    assert(controller != nullptr);
    if (_viewController == controller) {
        return;
    }
    _viewController.removeOnPlatformViewCreatedListener(_onPlatformViewCreated);
    super.controller = controller;
    _viewController = controller;
    _viewController.pointTransformer = ;
    _sizePlatformView();
    if (_viewController.isCreated) {
        markNeedsSemanticsUpdate();
    }
    _viewController.addOnPlatformViewCreatedListener(_onPlatformViewCreated);
}

Clip RenderAndroidView::clipBehavior() {
    return _clipBehavior;
}

void RenderAndroidView::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

bool RenderAndroidView::sizedByParent() {
    return true;
}

bool RenderAndroidView::alwaysNeedsCompositing() {
    return true;
}

bool RenderAndroidView::isRepaintBoundary() {
    return true;
}

Size RenderAndroidView::computeDryLayout(BoxConstraints constraints) {
    return constraints.biggest;
}

void RenderAndroidView::performResize() {
    super.performResize();
    _sizePlatformView();
}

void RenderAndroidView::paint(PaintingContext context, Offset offset) {
    if (_viewController.textureId == nullptr || _currentTextureSize == nullptr) {
        return;
    }
    bool isTextureLargerThanWidget = _currentTextureSize!.width > size.width || _currentTextureSize!.height > size.height;
    if (isTextureLargerThanWidget && clipBehavior != Clip.none) {
        _clipRectLayer.layer = context.pushClipRect(true, offset, offset & size, _paintTextureclipBehavior, _clipRectLayer.layer);
        return;
    }
    _clipRectLayer.layer = nullptr;
    _paintTexture(context, offset);
}

void RenderAndroidView::dispose() {
    _isDisposed = true;
    _clipRectLayer.layer = nullptr;
    _viewController.removeOnPlatformViewCreatedListener(_onPlatformViewCreated);
    super.dispose();
}

void RenderAndroidView::describeSemanticsConfiguration(SemanticsConfiguration config) {
    config.isSemanticBoundary = true;
    if (_viewController.isCreated) {
        config.platformViewId = _viewController.viewId;
    }
}

void RenderAndroidView::_onPlatformViewCreated(int id) {
    assert(!_isDisposed);
    markNeedsSemanticsUpdate();
}

Future<void> RenderAndroidView::_sizePlatformView() {
    if (_state == _PlatformViewState.resizing || size.isEmpty) {
        return;
    }
    _state = _PlatformViewState.resizing;
    markNeedsPaint();
    Size targetSize;
    do {
        targetSize = size;
        _currentTextureSize = await _viewController.setSize(targetSize);
        if (_isDisposed) {
            return;
        }
    } while (size != targetSize);
    _state = _PlatformViewState.ready;
    markNeedsPaint();
}

void RenderAndroidView::_setOffset() {
    SchedulerBinding.instance.addPostFrameCallback();
}

void RenderAndroidView::_paintTexture(PaintingContext context, Offset offset) {
    if (_currentTextureSize == nullptr) {
        return;
    }
    context.addLayer(TextureLayer(offset & _currentTextureSize!, _viewController.textureId!));
}

RenderUiKitView::RenderUiKitView(Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, UiKitViewController viewController) {
    {
        assert(viewController != nullptr);
        assert(hitTestBehavior != nullptr);
        assert(gestureRecognizers != nullptr);
        _viewController = viewController;
    }
    {
        updateGestureRecognizers(gestureRecognizers);
    }
}

UiKitViewController RenderUiKitView::viewController() {
    return _viewController;
}

void RenderUiKitView::viewController(UiKitViewController viewController) {
    assert(viewController != nullptr);
    bool needsSemanticsUpdate = _viewController.id != viewController.id;
    _viewController = viewController;
    markNeedsPaint();
    if (needsSemanticsUpdate) {
        markNeedsSemanticsUpdate();
    }
}

void RenderUiKitView::updateGestureRecognizers(Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers) {
    assert(gestureRecognizers != nullptr);
    assert(_factoriesTypeSet(gestureRecognizers).length == gestureRecognizers.length, "There were multiple gesture recognizer factories for the same type, there must only be a single gesture recognizer factory for each gesture recognizer type.");
    if (_factoryTypesSetEquals(gestureRecognizers, _gestureRecognizer?.gestureRecognizerFactories)) {
        return;
    }
    _gestureRecognizer?.dispose();
    _gestureRecognizer = _UiKitViewGestureRecognizer(viewController, gestureRecognizers);
}

bool RenderUiKitView::sizedByParent() {
    return true;
}

bool RenderUiKitView::alwaysNeedsCompositing() {
    return true;
}

bool RenderUiKitView::isRepaintBoundary() {
    return true;
}

Size RenderUiKitView::computeDryLayout(BoxConstraints constraints) {
    return constraints.biggest;
}

void RenderUiKitView::paint(PaintingContext context, Offset offset) {
    context.addLayer(PlatformViewLayer(offset & size, _viewController.id));
}

bool RenderUiKitView::hitTest(Offset position, BoxHitTestResult result) {
    if (hitTestBehavior == PlatformViewHitTestBehavior.transparent || !size.contains(position!)) {
        return false;
    }
    result.add(BoxHitTestEntry(this, position));
    return hitTestBehavior == PlatformViewHitTestBehavior.opaque;
}

bool RenderUiKitView::hitTestSelf(Offset position) {
    return hitTestBehavior != PlatformViewHitTestBehavior.transparent;
}

void RenderUiKitView::handleEvent(HitTestEntry entry, PointerEvent event) {
    if (event is! PointerDownEvent) {
        return;
    }
    _gestureRecognizer!.addPointer(event);
    _lastPointerDownEvent = event.original ?? event;
}

void RenderUiKitView::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super.describeSemanticsConfiguration(config);
    config.isSemanticBoundary = true;
    config.platformViewId = _viewController.id;
}

void RenderUiKitView::attach(PipelineOwner owner) {
    super.attach(owner);
    GestureBinding.instance.pointerRouter.addGlobalRoute(_handleGlobalPointerEvent);
}

void RenderUiKitView::detach() {
    GestureBinding.instance.pointerRouter.removeGlobalRoute(_handleGlobalPointerEvent);
    _gestureRecognizer!.reset();
    super.detach();
}

void RenderUiKitView::_handleGlobalPointerEvent(PointerEvent event) {
    if (event is! PointerDownEvent) {
        return;
    }
    if (!(Offset.zero & size).contains(globalToLocal(event.position))) {
        return;
    }
    if ((event.original ?? event) != _lastPointerDownEvent) {
        _viewController.rejectGesture();
    }
    _lastPointerDownEvent = nullptr;
}

void _UiKitViewGestureRecognizer::addAllowedPointer(PointerDownEvent event) {
    super.addAllowedPointer(event);
    for (OneSequenceGestureRecognizer recognizer : _gestureRecognizers) {
        recognizer.addPointer(event);
    }
}

String _UiKitViewGestureRecognizer::debugDescription() {
    return "UIKit view";
}

void _UiKitViewGestureRecognizer::didStopTrackingLastPointer(int pointer) {
}

void _UiKitViewGestureRecognizer::handleEvent(PointerEvent event) {
    stopTrackingIfPointerNoLongerDown(event);
}

void _UiKitViewGestureRecognizer::acceptGesture(int pointer) {
    controller.acceptGesture();
}

void _UiKitViewGestureRecognizer::rejectGesture(int pointer) {
    controller.rejectGesture();
}

void _UiKitViewGestureRecognizer::reset() {
    resolve(GestureDisposition.rejected);
}

_UiKitViewGestureRecognizer::_UiKitViewGestureRecognizer(UiKitViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizerFactories) {
    {
        team = ;
        _gestureRecognizers = gestureRecognizerFactories.map().toSet();
    }
}

void _PlatformViewGestureRecognizer::addAllowedPointer(PointerDownEvent event) {
    super.addAllowedPointer(event);
    for (OneSequenceGestureRecognizer recognizer : _gestureRecognizers) {
        recognizer.addPointer(event);
    }
}

String _PlatformViewGestureRecognizer::debugDescription() {
    return "Platform view";
}

void _PlatformViewGestureRecognizer::didStopTrackingLastPointer(int pointer) {
}

void _PlatformViewGestureRecognizer::handleEvent(PointerEvent event) {
    if (!forwardedPointers.contains(event.pointer)) {
        _cacheEvent(event);
    } else {
        _handlePointerEvent(event);
    }
    stopTrackingIfPointerNoLongerDown(event);
}

void _PlatformViewGestureRecognizer::acceptGesture(int pointer) {
    _flushPointerCache(pointer);
    forwardedPointers.add(pointer);
}

void _PlatformViewGestureRecognizer::rejectGesture(int pointer) {
    stopTrackingPointer(pointer);
    cachedEvents.remove(pointer);
}

void _PlatformViewGestureRecognizer::stopTrackingPointer(int pointer) {
    super.stopTrackingPointer(pointer);
    forwardedPointers.remove(pointer);
}

void _PlatformViewGestureRecognizer::reset() {
    forwardedPointers.forEach(super.stopTrackingPointer);
    forwardedPointers.clear();
    cachedEvents.keys.forEach(super.stopTrackingPointer);
    cachedEvents.clear();
    resolve(GestureDisposition.rejected);
}

_PlatformViewGestureRecognizer::_PlatformViewGestureRecognizer(Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizerFactories, _HandlePointerEvent handlePointerEvent) {
    {
        team = ;
        _gestureRecognizers = gestureRecognizerFactories.map().toSet();
        _handlePointerEvent = handlePointerEvent;
    }
}

void _PlatformViewGestureRecognizer::_cacheEvent(PointerEvent event) {
    if (!cachedEvents.containsKey(event.pointer)) {
        cachedEvents[event.pointer] = ;
    }
    cachedEvents[event.pointer]!.add(event);
}

void _PlatformViewGestureRecognizer::_flushPointerCache(int pointer) {
    cachedEvents.remove(pointer)?.forEach(_handlePointerEvent);
}

PlatformViewRenderBox::PlatformViewRenderBox(PlatformViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior) {
    {
        assert(controller != nullptr && controller.viewId != nullptr && controller.viewId > -1);
        assert(hitTestBehavior != nullptr);
        assert(gestureRecognizers != nullptr);
        _controller = controller;
    }
    {
        this.hitTestBehavior = hitTestBehavior;
        updateGestureRecognizers(gestureRecognizers);
    }
}

PlatformViewController PlatformViewRenderBox::controller() {
    return _controller;
}

void PlatformViewRenderBox::controller(PlatformViewController controller) {
    assert(controller != nullptr);
    assert(controller.viewId != nullptr && controller.viewId > -1);
    if (_controller == controller) {
        return;
    }
    bool needsSemanticsUpdate = _controller.viewId != controller.viewId;
    _controller = controller;
    markNeedsPaint();
    if (needsSemanticsUpdate) {
        markNeedsSemanticsUpdate();
    }
}

void PlatformViewRenderBox::updateGestureRecognizers(Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers) {
    _updateGestureRecognizersWithCallBack(gestureRecognizers, _controller.dispatchPointerEvent);
}

bool PlatformViewRenderBox::sizedByParent() {
    return true;
}

bool PlatformViewRenderBox::alwaysNeedsCompositing() {
    return true;
}

bool PlatformViewRenderBox::isRepaintBoundary() {
    return true;
}

Size PlatformViewRenderBox::computeDryLayout(BoxConstraints constraints) {
    return constraints.biggest;
}

void PlatformViewRenderBox::paint(PaintingContext context, Offset offset) {
    assert(_controller.viewId != nullptr);
    context.addLayer(PlatformViewLayer(offset & size, _controller.viewId));
}

void PlatformViewRenderBox::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super.describeSemanticsConfiguration(config);
    assert(_controller.viewId != nullptr);
    config.isSemanticBoundary = true;
    config.platformViewId = _controller.viewId;
}

void _PlatformViewGestureMixin::hitTestBehavior(PlatformViewHitTestBehavior value) {
    if (value != _hitTestBehavior) {
        _hitTestBehavior = value;
        if (owner != nullptr) {
            markNeedsPaint();
        }
    }
}

bool _PlatformViewGestureMixin::hitTest(Offset position, BoxHitTestResult result) {
    if (_hitTestBehavior == PlatformViewHitTestBehavior.transparent || !size.contains(position)) {
        return false;
    }
    result.add(BoxHitTestEntry(this, position));
    return _hitTestBehavior == PlatformViewHitTestBehavior.opaque;
}

bool _PlatformViewGestureMixin::hitTestSelf(Offset position) {
    return _hitTestBehavior != PlatformViewHitTestBehavior.transparent;
}

PointerEnterEventListener _PlatformViewGestureMixin::onEnter() {
    return nullptr;
}

PointerExitEventListener _PlatformViewGestureMixin::onExit() {
    return nullptr;
}

MouseCursor _PlatformViewGestureMixin::cursor() {
    return MouseCursor.uncontrolled;
}

bool _PlatformViewGestureMixin::validForMouseTracker() {
    return true;
}

void _PlatformViewGestureMixin::handleEvent(HitTestEntry entry, PointerEvent event) {
    if (event is PointerDownEvent) {
        _gestureRecognizer!.addPointer(event);
    }
    if (event is PointerHoverEvent) {
        _handlePointerEvent?.call(event);
    }
}

void _PlatformViewGestureMixin::detach() {
    _gestureRecognizer!.reset();
    super.detach();
}

void _PlatformViewGestureMixin::_updateGestureRecognizersWithCallBack(Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, _HandlePointerEvent handlePointerEvent) {
    assert(gestureRecognizers != nullptr);
    assert(_factoriesTypeSet(gestureRecognizers).length == gestureRecognizers.length, "There were multiple gesture recognizer factories for the same type, there must only be a single gesture recognizer factory for each gesture recognizer type.");
    if (_factoryTypesSetEquals(gestureRecognizers, _gestureRecognizer?.gestureRecognizerFactories)) {
        return;
    }
    _gestureRecognizer?.dispose();
    _gestureRecognizer = _PlatformViewGestureRecognizer(handlePointerEvent, gestureRecognizers);
    _handlePointerEvent = handlePointerEvent;
}
