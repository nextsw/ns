#include "platform_view.hpp"
template<typename T>
bool _factoryTypesSetEquals(Set<Factory<T>> a, Set<Factory<T>> b) {
    if (a == b) {
        return true;
    }
    if (a == nullptr || b == nullptr) {
        return false;
    }
    return setEquals(_factoriesTypeSet(a), _factoriesTypeSet(b));
}

template<typename T>
Set<Type> _factoriesTypeSet(Set<Factory<T>> factories) {
    return factories-><Type>map([=] (Factory<T> factory) {
        factory->type;
    })->toSet();
}

RenderAndroidViewCls::RenderAndroidViewCls(Clip clipBehavior, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, AndroidViewController viewController) : PlatformViewRenderBox(viewController, hitTestBehavior, gestureRecognizers) {
    {
        assert(viewController != nullptr);
        assert(hitTestBehavior != nullptr);
        assert(gestureRecognizers != nullptr);
        assert(clipBehavior != nullptr);
        _viewController = viewController;
        _clipBehavior = clipBehavior;
    }
    {
        _viewController->pointTransformer() = [=] (Offset offset) {
            globalToLocal(offset);
        };
        updateGestureRecognizers(gestureRecognizers);
        _viewController->addOnPlatformViewCreatedListener(_onPlatformViewCreated);
        this->hitTestBehavior = hitTestBehavior;
        _setOffset();
    }
}

AndroidViewController RenderAndroidViewCls::controller() {
    return _viewController;
}

void RenderAndroidViewCls::controller(AndroidViewController controller) {
    assert(!_isDisposed);
    assert(_viewController != nullptr);
    assert(controller != nullptr);
    if (_viewController == controller) {
        return;
    }
    _viewController->removeOnPlatformViewCreatedListener(_onPlatformViewCreated);
    super->controller = controller;
    _viewController = controller;
    _viewController->pointTransformer() = [=] (Offset offset) {
        globalToLocal(offset);
    };
    _sizePlatformView();
    if (_viewController->isCreated()) {
        markNeedsSemanticsUpdate();
    }
    _viewController->addOnPlatformViewCreatedListener(_onPlatformViewCreated);
}

Clip RenderAndroidViewCls::clipBehavior() {
    return _clipBehavior;
}

void RenderAndroidViewCls::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

bool RenderAndroidViewCls::sizedByParent() {
    return true;
}

bool RenderAndroidViewCls::alwaysNeedsCompositing() {
    return true;
}

bool RenderAndroidViewCls::isRepaintBoundary() {
    return true;
}

Size RenderAndroidViewCls::computeDryLayout(BoxConstraints constraints) {
    return constraints->biggest();
}

void RenderAndroidViewCls::performResize() {
    super->performResize();
    _sizePlatformView();
}

void RenderAndroidViewCls::paint(PaintingContext context, Offset offset) {
    if (_viewController->textureId() == nullptr || _currentTextureSize == nullptr) {
        return;
    }
    bool isTextureLargerThanWidget = _currentTextureSize!->width() > size()->width() || _currentTextureSize!->height() > size()->height();
    if (isTextureLargerThanWidget && clipBehavior() != ClipCls::none) {
        _clipRectLayer->layer() = context->pushClipRect(true, offset, offset & size(), _paintTexture, clipBehavior(), _clipRectLayer->layer());
        return;
    }
    _clipRectLayer->layer() = nullptr;
    _paintTexture(context, offset);
}

void RenderAndroidViewCls::dispose() {
    _isDisposed = true;
    _clipRectLayer->layer() = nullptr;
    _viewController->removeOnPlatformViewCreatedListener(_onPlatformViewCreated);
    super->dispose();
}

void RenderAndroidViewCls::describeSemanticsConfiguration(SemanticsConfiguration config) {
    config->isSemanticBoundary() = true;
    if (_viewController->isCreated()) {
        config->platformViewId() = _viewController->viewId;
    }
}

void RenderAndroidViewCls::_onPlatformViewCreated(int id) {
    assert(!_isDisposed);
    markNeedsSemanticsUpdate();
}

Future<void> RenderAndroidViewCls::_sizePlatformView() {
    if (_state == _PlatformViewStateCls::resizing || size()->isEmpty()) {
        return;
    }
    _state = _PlatformViewStateCls::resizing;
    markNeedsPaint();
    Size targetSize;
    do {
        targetSize = size();
        _currentTextureSize = await _viewController->setSize(targetSize);
        if (_isDisposed) {
            return;
        }
    } while (size() != targetSize);
    _state = _PlatformViewStateCls::ready;
    markNeedsPaint();
}

void RenderAndroidViewCls::_setOffset() {
    SchedulerBindingCls::instance->addPostFrameCallback([=] () {
        if (!_isDisposed) {
            if (attached()) {
                await await _viewController->setOffset(localToGlobal(OffsetCls::zero));
            }
            _setOffset();
        }
    });
}

void RenderAndroidViewCls::_paintTexture(PaintingContext context, Offset offset) {
    if (_currentTextureSize == nullptr) {
        return;
    }
    context->addLayer(make<TextureLayerCls>(offset & _currentTextureSize!, _viewController->textureId()!));
}

RenderUiKitViewCls::RenderUiKitViewCls(Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, UiKitViewController viewController) {
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

UiKitViewController RenderUiKitViewCls::viewController() {
    return _viewController;
}

void RenderUiKitViewCls::viewController(UiKitViewController viewController) {
    assert(viewController != nullptr);
    bool needsSemanticsUpdate = _viewController->id != viewController->id;
    _viewController = viewController;
    markNeedsPaint();
    if (needsSemanticsUpdate) {
        markNeedsSemanticsUpdate();
    }
}

void RenderUiKitViewCls::updateGestureRecognizers(Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers) {
    assert(gestureRecognizers != nullptr);
    assert(_factoriesTypeSet(gestureRecognizers)->length() == gestureRecognizers->length(), __s("There were multiple gesture recognizer factories for the same type, there must only be a single gesture recognizer factory for each gesture recognizer type."));
    if (_factoryTypesSetEquals(gestureRecognizers, _gestureRecognizer?->gestureRecognizerFactories)) {
        return;
    }
    _gestureRecognizer?->dispose();
    _gestureRecognizer = make<_UiKitViewGestureRecognizerCls>(viewController(), gestureRecognizers);
}

bool RenderUiKitViewCls::sizedByParent() {
    return true;
}

bool RenderUiKitViewCls::alwaysNeedsCompositing() {
    return true;
}

bool RenderUiKitViewCls::isRepaintBoundary() {
    return true;
}

Size RenderUiKitViewCls::computeDryLayout(BoxConstraints constraints) {
    return constraints->biggest();
}

void RenderUiKitViewCls::paint(PaintingContext context, Offset offset) {
    context->addLayer(make<PlatformViewLayerCls>(offset & size(), _viewController->id));
}

bool RenderUiKitViewCls::hitTest(BoxHitTestResult result, Offset position) {
    if (hitTestBehavior == PlatformViewHitTestBehaviorCls::transparent || !size()->contains(position!)) {
        return false;
    }
    result->add(make<BoxHitTestEntryCls>(this, position));
    return hitTestBehavior == PlatformViewHitTestBehaviorCls::opaque;
}

bool RenderUiKitViewCls::hitTestSelf(Offset position) {
    return hitTestBehavior != PlatformViewHitTestBehaviorCls::transparent;
}

void RenderUiKitViewCls::handleEvent(PointerEvent event, HitTestEntry entry) {
    if (!is<PointerDownEvent>(event)) {
        return;
    }
    _gestureRecognizer!->addPointer(event);
    _lastPointerDownEvent = event->original | event;
}

void RenderUiKitViewCls::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super->describeSemanticsConfiguration(config);
    config->isSemanticBoundary() = true;
    config->platformViewId() = _viewController->id;
}

void RenderUiKitViewCls::attach(PipelineOwner owner) {
    super->attach(owner);
    GestureBindingCls::instance->pointerRouter->addGlobalRoute(_handleGlobalPointerEvent);
}

void RenderUiKitViewCls::detach() {
    GestureBindingCls::instance->pointerRouter->removeGlobalRoute(_handleGlobalPointerEvent);
    _gestureRecognizer!->reset();
    super->detach();
}

void RenderUiKitViewCls::_handleGlobalPointerEvent(PointerEvent event) {
    if (!is<PointerDownEvent>(event)) {
        return;
    }
    if (!(OffsetCls::zero & size())->contains(globalToLocal(event->position))) {
        return;
    }
    if ((event->original | event) != _lastPointerDownEvent) {
        _viewController->rejectGesture();
    }
    _lastPointerDownEvent = nullptr;
}

void _UiKitViewGestureRecognizerCls::addAllowedPointer(PointerDownEvent event) {
    super->addAllowedPointer(event);
    for (OneSequenceGestureRecognizer recognizer : _gestureRecognizers) {
        recognizer->addPointer(event);
    }
}

String _UiKitViewGestureRecognizerCls::debugDescription() {
    return __s("UIKit view");
}

void _UiKitViewGestureRecognizerCls::didStopTrackingLastPointer(int pointer) {
}

void _UiKitViewGestureRecognizerCls::handleEvent(PointerEvent event) {
    stopTrackingIfPointerNoLongerDown(event);
}

void _UiKitViewGestureRecognizerCls::acceptGesture(int pointer) {
    controller->acceptGesture();
}

void _UiKitViewGestureRecognizerCls::rejectGesture(int pointer) {
    controller->rejectGesture();
}

void _UiKitViewGestureRecognizerCls::reset() {
    resolve(GestureDispositionCls::rejected);
}

_UiKitViewGestureRecognizerCls::_UiKitViewGestureRecognizerCls(UiKitViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizerFactories) {
    {
            auto _c1 = make<GestureArenaTeamCls>();    _c1.captain = this;team() = _c1;
        _gestureRecognizers = gestureRecognizerFactories->map([=] (Factory<OneSequenceGestureRecognizer> recognizerFactory) {
            OneSequenceGestureRecognizer gestureRecognizer = recognizerFactory->constructor();
            gestureRecognizer->team() = team();
            if (is<LongPressGestureRecognizer>(gestureRecognizer)) {
                as<LongPressGestureRecognizerCls>(gestureRecognizer)->onLongPress |= [=] () {
                };
            } else {
                if (is<DragGestureRecognizer>(gestureRecognizer)) {
                gestureRecognizer->onDown |= [=] () {
                };
            } else {
                if (is<TapGestureRecognizer>(gestureRecognizer)) {
                as<TapGestureRecognizerCls>(gestureRecognizer)->onTapDown |= [=] () {
                };
            }
;
            };
            }            return gestureRecognizer;
        })->toSet();
    }
}

void _PlatformViewGestureRecognizerCls::addAllowedPointer(PointerDownEvent event) {
    super->addAllowedPointer(event);
    for (OneSequenceGestureRecognizer recognizer : _gestureRecognizers) {
        recognizer->addPointer(event);
    }
}

String _PlatformViewGestureRecognizerCls::debugDescription() {
    return __s("Platform view");
}

void _PlatformViewGestureRecognizerCls::didStopTrackingLastPointer(int pointer) {
}

void _PlatformViewGestureRecognizerCls::handleEvent(PointerEvent event) {
    if (!forwardedPointers->contains(event->pointer)) {
        _cacheEvent(event);
    } else {
        _handlePointerEvent(event);
    }
    stopTrackingIfPointerNoLongerDown(event);
}

void _PlatformViewGestureRecognizerCls::acceptGesture(int pointer) {
    _flushPointerCache(pointer);
    forwardedPointers->add(pointer);
}

void _PlatformViewGestureRecognizerCls::rejectGesture(int pointer) {
    stopTrackingPointer(pointer);
    cachedEvents->remove(pointer);
}

void _PlatformViewGestureRecognizerCls::stopTrackingPointer(int pointer) {
    super->stopTrackingPointer(pointer);
    forwardedPointers->remove(pointer);
}

void _PlatformViewGestureRecognizerCls::reset() {
    forwardedPointers->forEach(super->stopTrackingPointer);
    forwardedPointers->clear();
    cachedEvents->keys()->forEach(super->stopTrackingPointer);
    cachedEvents->clear();
    resolve(GestureDispositionCls::rejected);
}

_PlatformViewGestureRecognizerCls::_PlatformViewGestureRecognizerCls(_HandlePointerEvent handlePointerEvent, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizerFactories) {
    {
            auto _c1 = make<GestureArenaTeamCls>();    _c1.captain = this;team() = _c1;
        _gestureRecognizers = gestureRecognizerFactories->map([=] (Factory<OneSequenceGestureRecognizer> recognizerFactory) {
            OneSequenceGestureRecognizer gestureRecognizer = recognizerFactory->constructor();
            gestureRecognizer->team() = team();
            if (is<LongPressGestureRecognizer>(gestureRecognizer)) {
                as<LongPressGestureRecognizerCls>(gestureRecognizer)->onLongPress |= [=] () {
                };
            } else {
                if (is<DragGestureRecognizer>(gestureRecognizer)) {
                gestureRecognizer->onDown |= [=] () {
                };
            } else {
                if (is<TapGestureRecognizer>(gestureRecognizer)) {
                as<TapGestureRecognizerCls>(gestureRecognizer)->onTapDown |= [=] () {
                };
            }
;
            };
            }            return gestureRecognizer;
        })->toSet();
        _handlePointerEvent = handlePointerEvent;
    }
}

void _PlatformViewGestureRecognizerCls::_cacheEvent(PointerEvent event) {
    if (!cachedEvents->containsKey(event->pointer)) {
        cachedEvents[event->pointer] = makeList();
    }
    cachedEvents[event->pointer]!->add(event);
}

void _PlatformViewGestureRecognizerCls::_flushPointerCache(int pointer) {
    cachedEvents->remove(pointer)?->forEach(_handlePointerEvent);
}

PlatformViewRenderBoxCls::PlatformViewRenderBoxCls(PlatformViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior) {
    {
        assert(controller != nullptr && controller->viewId() != nullptr && controller->viewId() > -1);
        assert(hitTestBehavior != nullptr);
        assert(gestureRecognizers != nullptr);
        _controller = controller;
    }
    {
        this->hitTestBehavior = hitTestBehavior;
        updateGestureRecognizers(gestureRecognizers);
    }
}

PlatformViewController PlatformViewRenderBoxCls::controller() {
    return _controller;
}

void PlatformViewRenderBoxCls::controller(PlatformViewController controller) {
    assert(controller != nullptr);
    assert(controller->viewId() != nullptr && controller->viewId() > -1);
    if (_controller == controller) {
        return;
    }
    bool needsSemanticsUpdate = _controller->viewId() != controller->viewId();
    _controller = controller;
    markNeedsPaint();
    if (needsSemanticsUpdate) {
        markNeedsSemanticsUpdate();
    }
}

void PlatformViewRenderBoxCls::updateGestureRecognizers(Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers) {
    _updateGestureRecognizersWithCallBack(gestureRecognizers, _controller->dispatchPointerEvent);
}

bool PlatformViewRenderBoxCls::sizedByParent() {
    return true;
}

bool PlatformViewRenderBoxCls::alwaysNeedsCompositing() {
    return true;
}

bool PlatformViewRenderBoxCls::isRepaintBoundary() {
    return true;
}

Size PlatformViewRenderBoxCls::computeDryLayout(BoxConstraints constraints) {
    return constraints->biggest();
}

void PlatformViewRenderBoxCls::paint(PaintingContext context, Offset offset) {
    assert(_controller->viewId() != nullptr);
    context->addLayer(make<PlatformViewLayerCls>(offset & size(), _controller->viewId()));
}

void PlatformViewRenderBoxCls::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super->describeSemanticsConfiguration(config);
    assert(_controller->viewId() != nullptr);
    config->isSemanticBoundary() = true;
    config->platformViewId() = _controller->viewId();
}

void _PlatformViewGestureMixinCls::hitTestBehavior(PlatformViewHitTestBehavior value) {
    if (value != _hitTestBehavior) {
        _hitTestBehavior = value;
        if (owner != nullptr) {
            markNeedsPaint();
        }
    }
}

bool _PlatformViewGestureMixinCls::hitTest(BoxHitTestResult result, Offset position) {
    if (_hitTestBehavior == PlatformViewHitTestBehaviorCls::transparent || !size->contains(position)) {
        return false;
    }
    result->add(make<BoxHitTestEntryCls>(this, position));
    return _hitTestBehavior == PlatformViewHitTestBehaviorCls::opaque;
}

bool _PlatformViewGestureMixinCls::hitTestSelf(Offset position) {
    return _hitTestBehavior != PlatformViewHitTestBehaviorCls::transparent;
}

PointerEnterEventListener _PlatformViewGestureMixinCls::onEnter() {
    return nullptr;
}

PointerExitEventListener _PlatformViewGestureMixinCls::onExit() {
    return nullptr;
}

MouseCursor _PlatformViewGestureMixinCls::cursor() {
    return MouseCursorCls::uncontrolled;
}

bool _PlatformViewGestureMixinCls::validForMouseTracker() {
    return true;
}

void _PlatformViewGestureMixinCls::handleEvent(PointerEvent event, HitTestEntry entry) {
    if (is<PointerDownEvent>(event)) {
        _gestureRecognizer!->addPointer(as<PointerDownEventCls>(event));
    }
    if (is<PointerHoverEvent>(event)) {
        _handlePointerEvent?->call(as<PointerHoverEventCls>(event));
    }
}

void _PlatformViewGestureMixinCls::detach() {
    _gestureRecognizer!->reset();
    super->detach();
}

void _PlatformViewGestureMixinCls::_updateGestureRecognizersWithCallBack(Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, _HandlePointerEvent handlePointerEvent) {
    assert(gestureRecognizers != nullptr);
    assert(_factoriesTypeSet(gestureRecognizers)->length() == gestureRecognizers->length(), __s("There were multiple gesture recognizer factories for the same type, there must only be a single gesture recognizer factory for each gesture recognizer type."));
    if (_factoryTypesSetEquals(gestureRecognizers, _gestureRecognizer?->gestureRecognizerFactories)) {
        return;
    }
    _gestureRecognizer?->dispose();
    _gestureRecognizer = make<_PlatformViewGestureRecognizerCls>(handlePointerEvent, gestureRecognizers);
    _handlePointerEvent = handlePointerEvent;
}
