#include "layer.hpp"
template<typename T>
AnnotationEntryCls<T>::AnnotationEntryCls(T annotation, Offset localPosition) {
    {
        assert(localPosition != nullptr);
    }
}

template<typename T>
String AnnotationEntryCls<T>::toString() {
    return __sf("%s(annotation: %s, localPosition: %s)", objectRuntimeType(this, __s("AnnotationEntry")), annotation, localPosition);
}

template<typename T>
void AnnotationResultCls<T>::add(AnnotationEntry<T> entry) {
    return _entries->add(entry);
}

template<typename T>
Iterable<AnnotationEntry<T>> AnnotationResultCls<T>::entries() {
    return _entries;
}

template<typename T>
Iterable<T> AnnotationResultCls<T>::annotations() {
    return _entries->map([=] (AnnotationEntry<T> entry) {
        entry->annotation;
    });
}

bool LayerCls::subtreeHasCompositionCallbacks() {
    return _compositionCallbackCount > 0;
}

Rect LayerCls::describeClipBounds() {
    return nullptr;
}

VoidCallback LayerCls::addCompositionCallback(CompositionCallback callback) {
    _updateSubtreeCompositionObserverCount(1);
    int callbackId = _nextCallbackId += 1;
    _callbacks[callbackId] = [=] () {
        assert([=] () {
            _debugMutationsLocked = true;
            return true;
        }());
        callback(this);
        assert([=] () {
            _debugMutationsLocked = false;
            return true;
        }());
    };
    return [=] () {
        assert(debugDisposed() || _callbacks->containsKey(callbackId));
        _callbacks->remove(callbackId);
        _updateSubtreeCompositionObserverCount(-1);
    };
}

bool LayerCls::debugDisposed() {
    bool disposed;
    assert([=] () {
        disposed = _debugDisposed;
        return true;
    }());
    return disposed;
}

int LayerCls::debugHandleCount() {
    int count;
    assert([=] () {
        count = _refCount;
        return true;
    }());
    return count;
}

void LayerCls::dispose() {
    assert(!_debugMutationsLocked);
    assert(!_debugDisposed, __s("Layers must only be disposed once. This is typically handled by LayerHandle and createHandle. Subclasses should not directly call dispose, except to call super.dispose() in an overridden dispose  method. Tests must only call dispose once."));
    assert([=] () {
        assert(_refCount == 0, __sf("Do not directly call dispose on a %s. Instead, use createHandle and LayerHandle.dispose.", runtimeType));
        _debugDisposed = true;
        return true;
    }());
    _engineLayer?->dispose();
    _engineLayer = nullptr;
}

ContainerLayer LayerCls::parent() {
    return as<ContainerLayer>(super->parent);
}

void LayerCls::markNeedsAddToScene() {
    assert(!_debugMutationsLocked);
    assert(!alwaysNeedsAddToScene(), __sf("%s with alwaysNeedsAddToScene set called markNeedsAddToScene.\nThe layer's alwaysNeedsAddToScene is set to true, and therefore it should not call markNeedsAddToScene.", runtimeType));
    assert(!_debugDisposed);
    if (_needsAddToScene) {
        return;
    }
    _needsAddToScene = true;
}

void LayerCls::debugMarkClean() {
    assert(!_debugMutationsLocked);
    assert([=] () {
        _needsAddToScene = false;
        return true;
    }());
}

bool LayerCls::alwaysNeedsAddToScene() {
    return false;
}

bool LayerCls::debugSubtreeNeedsAddToScene() {
    bool result;
    assert([=] () {
        result = _needsAddToScene;
        return true;
    }());
    return result;
}

EngineLayer LayerCls::engineLayer() {
    return _engineLayer;
}

void LayerCls::engineLayer(EngineLayer value) {
    assert(!_debugMutationsLocked);
    assert(!_debugDisposed);
    _engineLayer?->dispose();
    _engineLayer = value;
    if (!alwaysNeedsAddToScene()) {
        if (parent() != nullptr && !parent()!->alwaysNeedsAddToScene()) {
            parent()!->markNeedsAddToScene();
        }
    }
}

void LayerCls::updateSubtreeNeedsAddToScene() {
    assert(!_debugMutationsLocked);
    _needsAddToScene = _needsAddToScene || alwaysNeedsAddToScene();
}

Layer LayerCls::nextSibling() {
    return _nextSibling;
}

Layer LayerCls::previousSibling() {
    return _previousSibling;
}

void LayerCls::dropChild(Layer child) {
    assert(!_debugMutationsLocked);
    if (!alwaysNeedsAddToScene()) {
        markNeedsAddToScene();
    }
    if (child->_compositionCallbackCount != 0) {
        _updateSubtreeCompositionObserverCount(-child->_compositionCallbackCount);
    }
    super->dropChild(child);
}

void LayerCls::adoptChild(Layer child) {
    assert(!_debugMutationsLocked);
    if (!alwaysNeedsAddToScene()) {
        markNeedsAddToScene();
    }
    if (child->_compositionCallbackCount != 0) {
        _updateSubtreeCompositionObserverCount(child->_compositionCallbackCount);
    }
    super->adoptChild(child);
}

void LayerCls::remove() {
    assert(!_debugMutationsLocked);
    parent()?->_removeChild(this);
}

template<typename S>
bool LayerCls::findAnnotations(AnnotationResult<S> result, Offset localPosition, bool onlyFirst) {
    return false;
}

template<typename S>
S LayerCls::find(Offset localPosition) {
    AnnotationResult<S> result = <S>make<AnnotationResultCls>();
    <S>findAnnotations(result, localPosition, true);
    return result->entries()->isEmpty()? nullptr : result->entries()->first()->annotation;
}

template<typename S>
AnnotationResult<S> LayerCls::findAllAnnotations(Offset localPosition) {
    AnnotationResult<S> result = <S>make<AnnotationResultCls>();
    <S>findAnnotations(result, localPosition, false);
    return result;
}

String LayerCls::toStringShort() {
    return __sf("%s%s", super->toStringShort(), owner() == nullptr? __s(" DETACHED") : __s(""));
}

void LayerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Object>make<DiagnosticsPropertyCls>(__s("owner"), owner(), parent() != nullptr? DiagnosticLevelCls::hidden : DiagnosticLevelCls::info, nullptr));
    properties->add(<Object>make<DiagnosticsPropertyCls>(__s("creator"), debugCreator, nullptr, DiagnosticLevelCls::debug));
    if (_engineLayer != nullptr) {
        properties->add(<String>make<DiagnosticsPropertyCls>(__s("engine layer"), describeIdentity(_engineLayer)));
    }
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("handles"), debugHandleCount()));
}

void LayerCls::_updateSubtreeCompositionObserverCount(int delta) {
    assert(delta != 0);
    _compositionCallbackCount += delta;
    assert(_compositionCallbackCount >= 0);
    if (parent() != nullptr) {
        parent()!->_updateSubtreeCompositionObserverCount(delta);
    }
}

void LayerCls::_fireCompositionCallbacks(bool includeChildren) {
    for (VoidCallback callback : <VoidCallback>of(_callbacks->values())) {
        callback();
    }
}

void LayerCls::_unref() {
    assert(!_debugMutationsLocked);
    assert(_refCount > 0);
    _refCount -= 1;
    if (_refCount == 0) {
        dispose();
    }
}

void LayerCls::_addToSceneWithRetainedRendering(SceneBuilder builder) {
    assert(!_debugMutationsLocked);
    if (!_needsAddToScene && _engineLayer != nullptr) {
        builder->addRetained(_engineLayer!);
        return;
    }
    addToScene(builder);
    _needsAddToScene = false;
}

template<typename T>
LayerHandleCls<T>::LayerHandleCls(T _layer) {
    {
        if (_layer != nullptr) {
            _layer!->_refCount += 1;
        }
    }
}

template<typename T>
T LayerHandleCls<T>::layer() {
    return _layer;
}

template<typename T>
void LayerHandleCls<T>::layer(T layer) {
    assert(layer?->debugDisposed != true, __sf("Attempted to create a handle to an already disposed layer: %s.", layer));
    if (identical(layer, _layer)) {
        return;
    }
    _layer?->_unref();
    _layer = layer;
    if (_layer != nullptr) {
        _layer!->_refCount += 1;
    }
}

template<typename T>
String LayerHandleCls<T>::toString() {
    return __sf("LayerHandle(%s", _layer != nullptr? _layer->toString() : __s("DISPOSED)"));
}

Picture PictureLayerCls::picture() {
    return _picture;
}

void PictureLayerCls::picture(Picture picture) {
    assert(!_debugDisposed);
    markNeedsAddToScene();
    _picture?->dispose();
    _picture = picture;
}

bool PictureLayerCls::isComplexHint() {
    return _isComplexHint;
}

void PictureLayerCls::isComplexHint(bool value) {
    if (value != _isComplexHint) {
        _isComplexHint = value;
        markNeedsAddToScene();
    }
}

bool PictureLayerCls::willChangeHint() {
    return _willChangeHint;
}

void PictureLayerCls::willChangeHint(bool value) {
    if (value != _willChangeHint) {
        _willChangeHint = value;
        markNeedsAddToScene();
    }
}

void PictureLayerCls::dispose() {
    picture() = nullptr;
    super->dispose();
}

void PictureLayerCls::addToScene(SceneBuilder builder) {
    assert(picture() != nullptr);
    builder->addPicture(OffsetCls::zero, picture()!, isComplexHint(), willChangeHint());
}

void PictureLayerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Rect>make<DiagnosticsPropertyCls>(__s("paint bounds"), canvasBounds));
    properties->add(<String>make<DiagnosticsPropertyCls>(__s("picture"), describeIdentity(_picture)));
    properties->add(<String>make<DiagnosticsPropertyCls>(__s("raster cache hints"), __sf("isComplex = %s, willChange = %s", isComplexHint(), willChangeHint())));
}

template<typename S>
bool PictureLayerCls::findAnnotations(AnnotationResult<S> result, Offset localPosition, bool onlyFirst) {
    return false;
}

TextureLayerCls::TextureLayerCls(FilterQuality filterQuality, bool freeze, Rect rect, int textureId) {
    {
        assert(rect != nullptr);
        assert(textureId != nullptr);
    }
}

void TextureLayerCls::addToScene(SceneBuilder builder) {
    builder->addTexture(textureId, rect->topLeft(), rect->width(), rect->height(), freeze, filterQuality);
}

template<typename S>
bool TextureLayerCls::findAnnotations(AnnotationResult<S> result, Offset localPosition, bool onlyFirst) {
    return false;
}

PlatformViewLayerCls::PlatformViewLayerCls(Rect rect, int viewId) {
    {
        assert(rect != nullptr);
        assert(viewId != nullptr);
    }
}

void PlatformViewLayerCls::addToScene(SceneBuilder builder) {
    builder->addPlatformView(viewId, rect->topLeft(), rect->width(), rect->height());
}

PerformanceOverlayLayerCls::PerformanceOverlayLayerCls(bool checkerboardOffscreenLayers, bool checkerboardRasterCacheImages, int optionsMask, Rect overlayRect, int rasterizerThreshold) {
    {
        _overlayRect = overlayRect;
    }
}

Rect PerformanceOverlayLayerCls::overlayRect() {
    return _overlayRect;
}

void PerformanceOverlayLayerCls::overlayRect(Rect value) {
    if (value != _overlayRect) {
        _overlayRect = value;
        markNeedsAddToScene();
    }
}

void PerformanceOverlayLayerCls::addToScene(SceneBuilder builder) {
    assert(optionsMask != nullptr);
    builder->addPerformanceOverlay(optionsMask, overlayRect());
    builder->setRasterizerTracingThreshold(rasterizerThreshold);
    builder->setCheckerboardRasterCacheImages(checkerboardRasterCacheImages);
    builder->setCheckerboardOffscreenLayers(checkerboardOffscreenLayers);
}

template<typename S>
bool PerformanceOverlayLayerCls::findAnnotations(AnnotationResult<S> result, Offset localPosition, bool onlyFirst) {
    return false;
}

Layer ContainerLayerCls::firstChild() {
    return _firstChild;
}

Layer ContainerLayerCls::lastChild() {
    return _lastChild;
}

bool ContainerLayerCls::hasChildren() {
    return _firstChild != nullptr;
}

Scene ContainerLayerCls::buildScene(SceneBuilder builder) {
    updateSubtreeNeedsAddToScene();
    addToScene(builder);
    if (subtreeHasCompositionCallbacks()) {
        _fireCompositionCallbacks(true);
    }
    _needsAddToScene = false;
    Scene scene = builder->build();
    return scene;
}

void ContainerLayerCls::dispose() {
    removeAllChildren();
    _callbacks->clear();
    super->dispose();
}

void ContainerLayerCls::updateSubtreeNeedsAddToScene() {
    super->updateSubtreeNeedsAddToScene();
    Layer child = firstChild();
    while (child != nullptr) {
        child->updateSubtreeNeedsAddToScene();
        _needsAddToScene = _needsAddToScene || child->_needsAddToScene;
        child = child->nextSibling();
    }
}

template<typename S>
bool ContainerLayerCls::findAnnotations(AnnotationResult<S> result, Offset localPosition, bool onlyFirst) {
    for (; child != nullptr; child = child->previousSibling) {
        bool isAbsorbed = child-><S>findAnnotations(result, localPosition, onlyFirst);
        if (isAbsorbed) {
            return true;
        }
        if (onlyFirst && result->entries()->isNotEmpty()) {
            return isAbsorbed;
        }
    }
    return false;
}

void ContainerLayerCls::attach(Object owner) {
    assert(!_debugMutationsLocked);
    super->attach(owner);
    Layer child = firstChild();
    while (child != nullptr) {
        child->attach(owner);
        child = child->nextSibling();
    }
}

void ContainerLayerCls::detach() {
    assert(!_debugMutationsLocked);
    super->detach();
    Layer child = firstChild();
    while (child != nullptr) {
        child->detach();
        child = child->nextSibling();
    }
    _fireCompositionCallbacks(false);
}

void ContainerLayerCls::append(Layer child) {
    assert(!_debugMutationsLocked);
    assert(child != this);
    assert(child != firstChild());
    assert(child != lastChild());
    assert(child->parent() == nullptr);
    assert(!child->attached());
    assert(child->nextSibling() == nullptr);
    assert(child->previousSibling() == nullptr);
    assert(child->_parentHandle->layer() == nullptr);
    assert([=] () {
        Layer node = this;
        while (node->parent() != nullptr) {
            node = node->parent()!;
        }
        assert(node != child);
        return true;
    }());
    adoptChild(child);
    child->_previousSibling = lastChild();
    if (lastChild() != nullptr) {
        lastChild()!->_nextSibling = child;
    }
    _lastChild = child;
    _firstChild |= child;
    child->_parentHandle->layer() = child;
    assert(child->attached() == attached());
}

void ContainerLayerCls::removeAllChildren() {
    assert(!_debugMutationsLocked);
    Layer child = firstChild();
    while (child != nullptr) {
        Layer next = child->nextSibling();
        child->_previousSibling = nullptr;
        child->_nextSibling = nullptr;
        assert(child->attached() == attached());
        dropChild(child);
        assert(child->_parentHandle != nullptr);
        child->_parentHandle->layer() = nullptr;
        child = next;
    }
    _firstChild = nullptr;
    _lastChild = nullptr;
}

void ContainerLayerCls::addToScene(SceneBuilder builder) {
    addChildrenToScene(builder);
}

void ContainerLayerCls::addChildrenToScene(SceneBuilder builder) {
    Layer child = firstChild();
    while (child != nullptr) {
        child->_addToSceneWithRetainedRendering(builder);
        child = child->nextSibling();
    }
}

void ContainerLayerCls::applyTransform(Layer child, Matrix4 transform) {
    assert(child != nullptr);
    assert(transform != nullptr);
}

List<Layer> ContainerLayerCls::depthFirstIterateChildren() {
    if (firstChild() == nullptr) {
        return makeList();
    }
    List<Layer> children = makeList();
    Layer child = firstChild();
    while (child != nullptr) {
        children->add(child);
        if (is<ContainerLayer>(child)) {
            children->addAll(as<ContainerLayerCls>(child)->depthFirstIterateChildren());
        }
        child = child->nextSibling();
    }
    return children;
}

List<DiagnosticsNode> ContainerLayerCls::debugDescribeChildren() {
    List<DiagnosticsNode> children = makeList();
    if (firstChild() == nullptr) {
        return children;
    }
    Layer child = firstChild();
    int count = 1;
    while (true) {
        children->add(child!->toDiagnosticsNode(__sf("child %s", count)));
        if (child == lastChild()) {
            break;
        }
        count += 1;
        child = child->nextSibling();
    }
    return children;
}

void ContainerLayerCls::_fireCompositionCallbacks(bool includeChildren) {
    super->_fireCompositionCallbacks(includeChildren);
    if (!includeChildren) {
        return;
    }
    Layer child = firstChild();
    while (child != nullptr) {
        child->_fireCompositionCallbacks(includeChildren);
        child = child->nextSibling();
    }
}

bool ContainerLayerCls::_debugUltimatePreviousSiblingOf(Layer child, Layer equals) {
    assert(child->attached() == attached());
    while (child->previousSibling() != nullptr) {
        assert(child->previousSibling() != child);
        child = child->previousSibling()!;
        assert(child->attached() == attached());
    }
    return child == equals;
}

bool ContainerLayerCls::_debugUltimateNextSiblingOf(Layer child, Layer equals) {
    assert(child->attached() == attached());
    while (child->_nextSibling != nullptr) {
        assert(child->_nextSibling != child);
        child = child->_nextSibling!;
        assert(child->attached() == attached());
    }
    return child == equals;
}

void ContainerLayerCls::_removeChild(Layer child) {
    assert(child->parent() == this);
    assert(child->attached() == attached());
    assert(_debugUltimatePreviousSiblingOf(child, firstChild()));
    assert(_debugUltimateNextSiblingOf(child, lastChild()));
    assert(child->_parentHandle->layer() != nullptr);
    if (child->_previousSibling == nullptr) {
        assert(_firstChild == child);
        _firstChild = child->_nextSibling;
    } else {
        child->_previousSibling!->_nextSibling = child->nextSibling();
    }
    if (child->_nextSibling == nullptr) {
        assert(lastChild() == child);
        _lastChild = child->previousSibling();
    } else {
        child->nextSibling()!->_previousSibling = child->previousSibling();
    }
    assert((firstChild() == nullptr) == (lastChild() == nullptr));
    assert(firstChild() == nullptr || firstChild()!->attached() == attached());
    assert(lastChild() == nullptr || lastChild()!->attached() == attached());
    assert(firstChild() == nullptr || _debugUltimateNextSiblingOf(firstChild()!, lastChild()));
    assert(lastChild() == nullptr || _debugUltimatePreviousSiblingOf(lastChild()!, firstChild()));
    child->_previousSibling = nullptr;
    child->_nextSibling = nullptr;
    dropChild(child);
    child->_parentHandle->layer() = nullptr;
    assert(!child->attached());
}

OffsetLayerCls::OffsetLayerCls(Offset offset) {
    {
        _offset = offset;
    }
}

Offset OffsetLayerCls::offset() {
    return _offset;
}

void OffsetLayerCls::offset(Offset value) {
    if (value != _offset) {
        markNeedsAddToScene();
    }
    _offset = value;
}

template<typename S>
bool OffsetLayerCls::findAnnotations(AnnotationResult<S> result, Offset localPosition, bool onlyFirst) {
    return super-><S>findAnnotations(result, localPosition - offset(), onlyFirst);
}

void OffsetLayerCls::applyTransform(Layer child, Matrix4 transform) {
    assert(child != nullptr);
    assert(transform != nullptr);
    transform->translate(offset()->dx(), offset()->dy());
}

void OffsetLayerCls::addToScene(SceneBuilder builder) {
    engineLayer() = builder->pushOffset(offset()->dx(), offset()->dy(), as<OffsetEngineLayer>(_engineLayer));
    addChildrenToScene(builder);
    builder->pop();
}

void OffsetLayerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Offset>make<DiagnosticsPropertyCls>(__s("offset"), offset()));
}

Future<Image> OffsetLayerCls::toImage(Rect bounds, double pixelRatio) {
    assert(bounds != nullptr);
    assert(pixelRatio != nullptr);
    SceneBuilder builder = ui->make<SceneBuilderCls>();
    Matrix4 transform = Matrix4Cls->translationValues((-bounds->left - offset()->dx()) * pixelRatio, (-bounds->top - offset()->dy()) * pixelRatio, 0.0);
    transform->scale(pixelRatio, pixelRatio);
    builder->pushTransform(transform->storage());
    Scene scene = buildScene(builder);
    try {
        return await scene->toImage((pixelRatio * bounds->width())->ceil(), (pixelRatio * bounds->height())->ceil());
    } finally {
        scene->dispose();
    };
}

ClipRectLayerCls::ClipRectLayerCls(Clip clipBehavior, Rect clipRect) {
    {
        _clipRect = clipRect;
        _clipBehavior = clipBehavior;
        assert(clipBehavior != nullptr);
        assert(clipBehavior != ClipCls::none);
    }
}

Rect ClipRectLayerCls::clipRect() {
    return _clipRect;
}

void ClipRectLayerCls::clipRect(Rect value) {
    if (value != _clipRect) {
        _clipRect = value;
        markNeedsAddToScene();
    }
}

Rect ClipRectLayerCls::describeClipBounds() {
    return clipRect();
}

Clip ClipRectLayerCls::clipBehavior() {
    return _clipBehavior;
}

void ClipRectLayerCls::clipBehavior(Clip value) {
    assert(value != nullptr);
    assert(value != ClipCls::none);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsAddToScene();
    }
}

template<typename S>
bool ClipRectLayerCls::findAnnotations(AnnotationResult<S> result, Offset localPosition, bool onlyFirst) {
    if (!clipRect()!->contains(localPosition)) {
        return false;
    }
    return super-><S>findAnnotations(result, localPosition, onlyFirst);
}

void ClipRectLayerCls::addToScene(SceneBuilder builder) {
    assert(clipRect() != nullptr);
    assert(clipBehavior() != nullptr);
    bool enabled = true;
    assert([=] () {
        enabled = !debugDisableClipLayers;
        return true;
    }());
    if (enabled) {
        engineLayer() = builder->pushClipRect(clipRect()!, clipBehavior(), as<ClipRectEngineLayer>(_engineLayer));
    } else {
        engineLayer() = nullptr;
    }
    addChildrenToScene(builder);
    if (enabled) {
        builder->pop();
    }
}

void ClipRectLayerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Rect>make<DiagnosticsPropertyCls>(__s("clipRect"), clipRect()));
    properties->add(<Clip>make<DiagnosticsPropertyCls>(__s("clipBehavior"), clipBehavior()));
}

ClipRRectLayerCls::ClipRRectLayerCls(Clip clipBehavior, RRect clipRRect) {
    {
        _clipRRect = clipRRect;
        _clipBehavior = clipBehavior;
        assert(clipBehavior != nullptr);
        assert(clipBehavior != ClipCls::none);
    }
}

RRect ClipRRectLayerCls::clipRRect() {
    return _clipRRect;
}

void ClipRRectLayerCls::clipRRect(RRect value) {
    if (value != _clipRRect) {
        _clipRRect = value;
        markNeedsAddToScene();
    }
}

Rect ClipRRectLayerCls::describeClipBounds() {
    return clipRRect()?->outerRect();
}

Clip ClipRRectLayerCls::clipBehavior() {
    return _clipBehavior;
}

void ClipRRectLayerCls::clipBehavior(Clip value) {
    assert(value != nullptr);
    assert(value != ClipCls::none);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsAddToScene();
    }
}

template<typename S>
bool ClipRRectLayerCls::findAnnotations(AnnotationResult<S> result, Offset localPosition, bool onlyFirst) {
    if (!clipRRect()!->contains(localPosition)) {
        return false;
    }
    return super-><S>findAnnotations(result, localPosition, onlyFirst);
}

void ClipRRectLayerCls::addToScene(SceneBuilder builder) {
    assert(clipRRect() != nullptr);
    assert(clipBehavior() != nullptr);
    bool enabled = true;
    assert([=] () {
        enabled = !debugDisableClipLayers;
        return true;
    }());
    if (enabled) {
        engineLayer() = builder->pushClipRRect(clipRRect()!, clipBehavior(), as<ClipRRectEngineLayer>(_engineLayer));
    } else {
        engineLayer() = nullptr;
    }
    addChildrenToScene(builder);
    if (enabled) {
        builder->pop();
    }
}

void ClipRRectLayerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<RRect>make<DiagnosticsPropertyCls>(__s("clipRRect"), clipRRect()));
    properties->add(<Clip>make<DiagnosticsPropertyCls>(__s("clipBehavior"), clipBehavior()));
}

ClipPathLayerCls::ClipPathLayerCls(Clip clipBehavior, Path clipPath) {
    {
        _clipPath = clipPath;
        _clipBehavior = clipBehavior;
        assert(clipBehavior != nullptr);
        assert(clipBehavior != ClipCls::none);
    }
}

Path ClipPathLayerCls::clipPath() {
    return _clipPath;
}

void ClipPathLayerCls::clipPath(Path value) {
    if (value != _clipPath) {
        _clipPath = value;
        markNeedsAddToScene();
    }
}

Rect ClipPathLayerCls::describeClipBounds() {
    return clipPath()?->getBounds();
}

Clip ClipPathLayerCls::clipBehavior() {
    return _clipBehavior;
}

void ClipPathLayerCls::clipBehavior(Clip value) {
    assert(value != nullptr);
    assert(value != ClipCls::none);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsAddToScene();
    }
}

template<typename S>
bool ClipPathLayerCls::findAnnotations(AnnotationResult<S> result, Offset localPosition, bool onlyFirst) {
    if (!clipPath()!->contains(localPosition)) {
        return false;
    }
    return super-><S>findAnnotations(result, localPosition, onlyFirst);
}

void ClipPathLayerCls::addToScene(SceneBuilder builder) {
    assert(clipPath() != nullptr);
    assert(clipBehavior() != nullptr);
    bool enabled = true;
    assert([=] () {
        enabled = !debugDisableClipLayers;
        return true;
    }());
    if (enabled) {
        engineLayer() = builder->pushClipPath(clipPath()!, clipBehavior(), as<ClipPathEngineLayer>(_engineLayer));
    } else {
        engineLayer() = nullptr;
    }
    addChildrenToScene(builder);
    if (enabled) {
        builder->pop();
    }
}

void ClipPathLayerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Clip>make<DiagnosticsPropertyCls>(__s("clipBehavior"), clipBehavior()));
}

ColorFilterLayerCls::ColorFilterLayerCls(ColorFilter colorFilter) {
    {
        _colorFilter = colorFilter;
    }
}

ColorFilter ColorFilterLayerCls::colorFilter() {
    return _colorFilter;
}

void ColorFilterLayerCls::colorFilter(ColorFilter value) {
    assert(value != nullptr);
    if (value != _colorFilter) {
        _colorFilter = value;
        markNeedsAddToScene();
    }
}

void ColorFilterLayerCls::addToScene(SceneBuilder builder) {
    assert(colorFilter() != nullptr);
    engineLayer() = builder->pushColorFilter(colorFilter()!, as<ColorFilterEngineLayer>(_engineLayer));
    addChildrenToScene(builder);
    builder->pop();
}

void ColorFilterLayerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<ColorFilter>make<DiagnosticsPropertyCls>(__s("colorFilter"), colorFilter()));
}

ImageFilterLayerCls::ImageFilterLayerCls(ImageFilter imageFilter) {
    {
        _imageFilter = imageFilter;
    }
}

ImageFilter ImageFilterLayerCls::imageFilter() {
    return _imageFilter;
}

void ImageFilterLayerCls::imageFilter(ImageFilter value) {
    assert(value != nullptr);
    if (value != _imageFilter) {
        _imageFilter = value;
        markNeedsAddToScene();
    }
}

void ImageFilterLayerCls::addToScene(SceneBuilder builder) {
    assert(imageFilter() != nullptr);
    engineLayer() = builder->pushImageFilter(imageFilter()!, as<ImageFilterEngineLayer>(_engineLayer));
    addChildrenToScene(builder);
    builder->pop();
}

void ImageFilterLayerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<ImageFilter>make<DiagnosticsPropertyCls>(__s("imageFilter"), imageFilter()));
}

TransformLayerCls::TransformLayerCls(Offset offset, Matrix4 transform) {
    {
        _transform = transform;
    }
}

Matrix4 TransformLayerCls::transform() {
    return _transform;
}

void TransformLayerCls::transform(Matrix4 value) {
    assert(value != nullptr);
    assert(value!->storage()->every([=] (double component) {
        component->isFinite;
    }));
    if (value == _transform) {
        return;
    }
    _transform = value;
    _inverseDirty = true;
    markNeedsAddToScene();
}

void TransformLayerCls::addToScene(SceneBuilder builder) {
    assert(transform() != nullptr);
    _lastEffectiveTransform = transform();
    if (offset() != OffsetCls::zero) {
            auto _c1 = Matrix4Cls->translationValues(offset()->dx(), offset()->dy(), 0.0);    _c1.multiply(_lastEffectiveTransform!);_lastEffectiveTransform = _c1;
    }
    engineLayer() = builder->pushTransform(_lastEffectiveTransform!->storage(), as<TransformEngineLayer>(_engineLayer));
    addChildrenToScene(builder);
    builder->pop();
}

template<typename S>
bool TransformLayerCls::findAnnotations(AnnotationResult<S> result, Offset localPosition, bool onlyFirst) {
    Offset transformedOffset = _transformOffset(localPosition);
    if (transformedOffset == nullptr) {
        return false;
    }
    return super-><S>findAnnotations(result, transformedOffset, onlyFirst);
}

void TransformLayerCls::applyTransform(Layer child, Matrix4 transform) {
    assert(child != nullptr);
    assert(transform != nullptr);
    assert(_lastEffectiveTransform != nullptr || this->transform != nullptr);
    if (_lastEffectiveTransform == nullptr) {
        transform->multiply(this->transform!);
    } else {
        transform->multiply(_lastEffectiveTransform!);
    }
}

void TransformLayerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<TransformPropertyCls>(__s("transform"), transform()));
}

Offset TransformLayerCls::_transformOffset(Offset localPosition) {
    if (_inverseDirty) {
        _invertedTransform = Matrix4Cls->tryInvert(PointerEventCls->removePerspectiveTransform(transform()!));
        _inverseDirty = false;
    }
    if (_invertedTransform == nullptr) {
        return nullptr;
    }
    return MatrixUtilsCls->transformPoint(_invertedTransform!, localPosition);
}

OpacityLayerCls::OpacityLayerCls(int alpha, Offset offset) {
    {
        _alpha = alpha;
    }
}

int OpacityLayerCls::alpha() {
    return _alpha;
}

void OpacityLayerCls::alpha(int value) {
    assert(value != nullptr);
    if (value != _alpha) {
        if (value == 255 || _alpha == 255) {
            engineLayer() = nullptr;
        }
        _alpha = value;
        markNeedsAddToScene();
    }
}

void OpacityLayerCls::addToScene(SceneBuilder builder) {
    assert(alpha() != nullptr);
    bool enabled = firstChild() != nullptr;
    if (!enabled) {
        engineLayer() = nullptr;
        return;
    }
    assert([=] () {
        enabled = enabled && !debugDisableOpacityLayers;
        return true;
    }());
    int realizedAlpha = alpha()!;
    if (enabled &&  < 255) {
        assert(is<OpacityEngineLayer>(_engineLayer));
        engineLayer() = builder->pushOpacity(realizedAlpha, offset(), as<OpacityEngineLayer>(_engineLayer));
    } else {
        assert(is<OffsetEngineLayer>(_engineLayer));
        engineLayer() = builder->pushOffset(offset()->dx(), offset()->dy(), as<OffsetEngineLayer>(_engineLayer));
    }
    addChildrenToScene(builder);
    builder->pop();
}

void OpacityLayerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<IntPropertyCls>(__s("alpha"), alpha()));
}

ShaderMaskLayerCls::ShaderMaskLayerCls(BlendMode blendMode, Rect maskRect, Shader shader) {
    {
        _shader = shader;
        _maskRect = maskRect;
        _blendMode = blendMode;
    }
}

Shader ShaderMaskLayerCls::shader() {
    return _shader;
}

void ShaderMaskLayerCls::shader(Shader value) {
    if (value != _shader) {
        _shader = value;
        markNeedsAddToScene();
    }
}

Rect ShaderMaskLayerCls::maskRect() {
    return _maskRect;
}

void ShaderMaskLayerCls::maskRect(Rect value) {
    if (value != _maskRect) {
        _maskRect = value;
        markNeedsAddToScene();
    }
}

BlendMode ShaderMaskLayerCls::blendMode() {
    return _blendMode;
}

void ShaderMaskLayerCls::blendMode(BlendMode value) {
    if (value != _blendMode) {
        _blendMode = value;
        markNeedsAddToScene();
    }
}

void ShaderMaskLayerCls::addToScene(SceneBuilder builder) {
    assert(shader() != nullptr);
    assert(maskRect() != nullptr);
    assert(blendMode() != nullptr);
    engineLayer() = builder->pushShaderMask(shader()!, maskRect()!, blendMode()!, as<ShaderMaskEngineLayer>(_engineLayer));
    addChildrenToScene(builder);
    builder->pop();
}

void ShaderMaskLayerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Shader>make<DiagnosticsPropertyCls>(__s("shader"), shader()));
    properties->add(<Rect>make<DiagnosticsPropertyCls>(__s("maskRect"), maskRect()));
    properties->add(<BlendMode>make<EnumPropertyCls>(__s("blendMode"), blendMode()));
}

BackdropFilterLayerCls::BackdropFilterLayerCls(BlendMode blendMode, ImageFilter filter) {
    {
        _filter = filter;
        _blendMode = blendMode;
    }
}

ImageFilter BackdropFilterLayerCls::filter() {
    return _filter;
}

void BackdropFilterLayerCls::filter(ImageFilter value) {
    if (value != _filter) {
        _filter = value;
        markNeedsAddToScene();
    }
}

BlendMode BackdropFilterLayerCls::blendMode() {
    return _blendMode;
}

void BackdropFilterLayerCls::blendMode(BlendMode value) {
    if (value != _blendMode) {
        _blendMode = value;
        markNeedsAddToScene();
    }
}

void BackdropFilterLayerCls::addToScene(SceneBuilder builder) {
    assert(filter() != nullptr);
    engineLayer() = builder->pushBackdropFilter(filter()!, blendMode(), as<BackdropFilterEngineLayer>(_engineLayer));
    addChildrenToScene(builder);
    builder->pop();
}

void BackdropFilterLayerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<ImageFilter>make<DiagnosticsPropertyCls>(__s("filter"), filter()));
    properties->add(<BlendMode>make<EnumPropertyCls>(__s("blendMode"), blendMode()));
}

PhysicalModelLayerCls::PhysicalModelLayerCls(Clip clipBehavior, Path clipPath, Color color, double elevation, Color shadowColor) {
    {
        _clipPath = clipPath;
        _clipBehavior = clipBehavior;
        _elevation = elevation;
        _color = color;
        _shadowColor = shadowColor;
    }
}

Path PhysicalModelLayerCls::clipPath() {
    return _clipPath;
}

void PhysicalModelLayerCls::clipPath(Path value) {
    if (value != _clipPath) {
        _clipPath = value;
        markNeedsAddToScene();
    }
}

Clip PhysicalModelLayerCls::clipBehavior() {
    return _clipBehavior;
}

void PhysicalModelLayerCls::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsAddToScene();
    }
}

double PhysicalModelLayerCls::elevation() {
    return _elevation;
}

void PhysicalModelLayerCls::elevation(double value) {
    if (value != _elevation) {
        _elevation = value;
        markNeedsAddToScene();
    }
}

Color PhysicalModelLayerCls::color() {
    return _color;
}

void PhysicalModelLayerCls::color(Color value) {
    if (value != _color) {
        _color = value;
        markNeedsAddToScene();
    }
}

Color PhysicalModelLayerCls::shadowColor() {
    return _shadowColor;
}

void PhysicalModelLayerCls::shadowColor(Color value) {
    if (value != _shadowColor) {
        _shadowColor = value;
        markNeedsAddToScene();
    }
}

template<typename S>
bool PhysicalModelLayerCls::findAnnotations(AnnotationResult<S> result, Offset localPosition, bool onlyFirst) {
    if (!clipPath()!->contains(localPosition)) {
        return false;
    }
    return super-><S>findAnnotations(result, localPosition, onlyFirst);
}

void PhysicalModelLayerCls::addToScene(SceneBuilder builder) {
    assert(clipPath() != nullptr);
    assert(clipBehavior() != nullptr);
    assert(elevation() != nullptr);
    assert(color() != nullptr);
    assert(shadowColor() != nullptr);
    bool enabled = true;
    assert([=] () {
        enabled = !debugDisablePhysicalShapeLayers;
        return true;
    }());
    if (enabled) {
        engineLayer() = builder->pushPhysicalShape(clipPath()!, elevation()!, color()!, shadowColor(), clipBehavior(), as<PhysicalShapeEngineLayer>(_engineLayer));
    } else {
        engineLayer() = nullptr;
    }
    addChildrenToScene(builder);
    if (enabled) {
        builder->pop();
    }
}

void PhysicalModelLayerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("elevation"), elevation()));
    properties->add(make<ColorPropertyCls>(__s("color"), color()));
}

LeaderLayer LayerLinkCls::leader() {
    return _leader;
}

String LayerLinkCls::toString() {
    return __sf("%s(%s", describeIdentity(this), _leader != nullptr? __s("<linked>") : __s("<dangling>)"));
}

void LayerLinkCls::_registerLeader(LeaderLayer leader) {
    assert(_leader != leader);
    assert([=] () {
        if (_leader != nullptr) {
            _debugPreviousLeaders |= makeSet();
            _debugScheduleLeadersCleanUpCheck();
            return _debugPreviousLeaders!->add(_leader!);
        }
        return true;
    }());
    _leader = leader;
}

void LayerLinkCls::_unregisterLeader(LeaderLayer leader) {
    if (_leader == leader) {
        _leader = nullptr;
    } else {
        assert(_debugPreviousLeaders!->remove(leader));
    }
}

void LayerLinkCls::_debugScheduleLeadersCleanUpCheck() {
    assert(_debugPreviousLeaders != nullptr);
    assert([=] () {
        if (_debugLeaderCheckScheduled) {
            return true;
        }
        _debugLeaderCheckScheduled = true;
        SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration timeStamp) {
            _debugLeaderCheckScheduled = false;
            assert(_debugPreviousLeaders!->isEmpty());
        });
        return true;
    }());
}

LeaderLayerCls::LeaderLayerCls(LayerLink link, Offset offset) {
    {
        assert(link != nullptr);
        _link = link;
        _offset = offset;
    }
}

LayerLink LeaderLayerCls::link() {
    return _link;
}

void LeaderLayerCls::link(LayerLink value) {
    assert(value != nullptr);
    if (_link == value) {
        return;
    }
    if (attached()) {
        _link->_unregisterLeader(this);
        value->_registerLeader(this);
    }
    _link = value;
}

Offset LeaderLayerCls::offset() {
    return _offset;
}

void LeaderLayerCls::offset(Offset value) {
    assert(value != nullptr);
    if (value == _offset) {
        return;
    }
    _offset = value;
    if (!alwaysNeedsAddToScene()) {
        markNeedsAddToScene();
    }
}

void LeaderLayerCls::attach(Object owner) {
    super->attach(owner);
    _link->_registerLeader(this);
}

void LeaderLayerCls::detach() {
    _link->_unregisterLeader(this);
    super->detach();
}

template<typename S>
bool LeaderLayerCls::findAnnotations(AnnotationResult<S> result, Offset localPosition, bool onlyFirst) {
    return super-><S>findAnnotations(result, localPosition - offset(), onlyFirst);
}

void LeaderLayerCls::addToScene(SceneBuilder builder) {
    assert(offset() != nullptr);
    if (offset() != OffsetCls::zero) {
        engineLayer() = builder->pushTransform(Matrix4Cls->translationValues(offset()->dx(), offset()->dy(), 0.0)->storage, as<TransformEngineLayer>(_engineLayer));
    }
    addChildrenToScene(builder);
    if (offset() != OffsetCls::zero) {
        builder->pop();
    }
}

void LeaderLayerCls::applyTransform(Layer child, Matrix4 transform) {
    if (offset() != OffsetCls::zero) {
        transform->translate(offset()->dx(), offset()->dy());
    }
}

void LeaderLayerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Offset>make<DiagnosticsPropertyCls>(__s("offset"), offset()));
    properties->add(<LayerLink>make<DiagnosticsPropertyCls>(__s("link"), link()));
}

FollowerLayerCls::FollowerLayerCls(LayerLink link, Offset linkedOffset, bool showWhenUnlinked, Offset unlinkedOffset) {
    {
        assert(link != nullptr);
        _link = link;
    }
}

LayerLink FollowerLayerCls::link() {
    return _link;
}

void FollowerLayerCls::link(LayerLink value) {
    assert(value != nullptr);
    _link = value;
}

template<typename S>
bool FollowerLayerCls::findAnnotations(AnnotationResult<S> result, Offset localPosition, bool onlyFirst) {
    if (_link->leader() == nullptr) {
        if (showWhenUnlinked!) {
            return super->findAnnotations(result, localPosition - unlinkedOffset!, onlyFirst);
        }
        return false;
    }
    Offset transformedOffset = _transformOffset(localPosition);
    if (transformedOffset == nullptr) {
        return false;
    }
    return super-><S>findAnnotations(result, transformedOffset, onlyFirst);
}

Matrix4 FollowerLayerCls::getLastTransform() {
    if (_lastTransform == nullptr) {
        return nullptr;
    }
    Matrix4 result = Matrix4Cls->translationValues(-_lastOffset!->dx(), -_lastOffset!->dy(), 0.0);
    result->multiply(_lastTransform!);
    return result;
}

bool FollowerLayerCls::alwaysNeedsAddToScene() {
    return true;
}

void FollowerLayerCls::addToScene(SceneBuilder builder) {
    assert(link() != nullptr);
    assert(showWhenUnlinked != nullptr);
    if (_link->leader() == nullptr && !showWhenUnlinked!) {
        _lastTransform = nullptr;
        _lastOffset = nullptr;
        _inverseDirty = true;
        engineLayer() = nullptr;
        return;
    }
    _establishTransform();
    if (_lastTransform != nullptr) {
        _lastOffset = unlinkedOffset;
        engineLayer() = builder->pushTransform(_lastTransform!->storage(), as<TransformEngineLayer>(_engineLayer));
        addChildrenToScene(builder);
        builder->pop();
    } else {
        _lastOffset = nullptr;
        Matrix4 matrix = Matrix4Cls->translationValues(unlinkedOffset!->dx(), unlinkedOffset!->dy(), .0);
        engineLayer() = builder->pushTransform(matrix->storage(), as<TransformEngineLayer>(_engineLayer));
        addChildrenToScene(builder);
        builder->pop();
    }
    _inverseDirty = true;
}

void FollowerLayerCls::applyTransform(Layer child, Matrix4 transform) {
    assert(child != nullptr);
    assert(transform != nullptr);
    if (_lastTransform != nullptr) {
        transform->multiply(_lastTransform!);
    } else {
        transform->multiply(Matrix4Cls->translationValues(unlinkedOffset!->dx(), unlinkedOffset!->dy(), 0));
    }
}

void FollowerLayerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<LayerLink>make<DiagnosticsPropertyCls>(__s("link"), link()));
    properties->add(make<TransformPropertyCls>(__s("transform"), getLastTransform(), nullptr));
}

Offset FollowerLayerCls::_transformOffset(Offset localPosition) {
    if (_inverseDirty) {
        _invertedTransform = Matrix4Cls->tryInvert(getLastTransform()!);
        _inverseDirty = false;
    }
    if (_invertedTransform == nullptr) {
        return nullptr;
    }
    Vector4 vector = make<Vector4Cls>(localPosition->dx(), localPosition->dy(), 0.0, 1.0);
    Vector4 result = _invertedTransform!->transform(vector);
    return make<OffsetCls>(result[0] - linkedOffset!->dx(), result[1] - linkedOffset!->dy());
}

Matrix4 FollowerLayerCls::_collectTransformForLayerChain(List<ContainerLayer> layers) {
    Matrix4 result = Matrix4Cls->identity();
    for (; index > 0; index -= 1) {
        layers[index]?->applyTransform(layers[index - 1], result);
    }
    return result;
}

Layer FollowerLayerCls::_pathsToCommonAncestor(Layer a, Layer b, List<ContainerLayer> ancestorsA, List<ContainerLayer> ancestorsB) {
    if (a == nullptr || b == nullptr) {
        return nullptr;
    }
    if (identical(a, b)) {
        return a;
    }
    if (a->depth() < b->depth()) {
        ancestorsB->add(b->parent());
        return _pathsToCommonAncestor(a, b->parent(), ancestorsA, ancestorsB);
    } else {
        if (a->depth() > b->depth()) {
        ancestorsA->add(a->parent());
        return _pathsToCommonAncestor(a->parent(), b, ancestorsA, ancestorsB);
    }
;
    }    ancestorsA->add(a->parent());
    ancestorsB->add(b->parent());
    return _pathsToCommonAncestor(a->parent(), b->parent(), ancestorsA, ancestorsB);
}

bool FollowerLayerCls::_debugCheckLeaderBeforeFollower(List<ContainerLayer> leaderToCommonAncestor, List<ContainerLayer> followerToCommonAncestor) {
    if (followerToCommonAncestor->length() <= 1) {
        return false;
    }
    if (leaderToCommonAncestor->length() <= 1) {
        return true;
    }
    ContainerLayer leaderSubtreeBelowAncestor = leaderToCommonAncestor[leaderToCommonAncestor->length() - 2];
    ContainerLayer followerSubtreeBelowAncestor = followerToCommonAncestor[followerToCommonAncestor->length() - 2];
    Layer sibling = leaderSubtreeBelowAncestor;
    while (sibling != nullptr) {
        if (sibling == followerSubtreeBelowAncestor) {
            return true;
        }
        sibling = sibling->nextSibling();
    }
    return false;
}

void FollowerLayerCls::_establishTransform() {
    assert(link() != nullptr);
    _lastTransform = nullptr;
    LeaderLayer leader = _link->leader();
    if (leader == nullptr) {
        return;
    }
    assert(leader->owner() == owner(), __s("Linked LeaderLayer anchor is not in the same layer tree as the FollowerLayer."));
    List<ContainerLayer> forwardLayers = makeList(ArrayItem);
    List<ContainerLayer> inverseLayers = makeList(ArrayItem);
    Layer ancestor = _pathsToCommonAncestor(leader, this, forwardLayers, inverseLayers);
    assert(ancestor != nullptr, __s("LeaderLayer and FollowerLayer do not have a common ancestor."));
    assert(_debugCheckLeaderBeforeFollower(forwardLayers, inverseLayers), __s("LeaderLayer anchor must come before FollowerLayer in paint order, but the reverse was true."));
    Matrix4 forwardTransform = _collectTransformForLayerChain(forwardLayers);
    leader->applyTransform(nullptr, forwardTransform);
    forwardTransform->translate(linkedOffset!->dx(), linkedOffset!->dy());
    Matrix4 inverseTransform = _collectTransformForLayerChain(inverseLayers);
    if (inverseTransform->invert() == 0.0) {
        return;
    }
    inverseTransform->multiply(forwardTransform);
    _lastTransform = inverseTransform;
    _inverseDirty = true;
}

template<typename T>
AnnotatedRegionLayerCls<T>::AnnotatedRegionLayerCls(T value, Offset offset, bool opaque, Size size) {
    {
        assert(value != nullptr);
        assert(opaque != nullptr);
        offset = offset | OffsetCls::zero;
    }
}

template<typename T>
template<typename S>
bool AnnotatedRegionLayerCls<T>::findAnnotations(AnnotationResult<S> result, Offset localPosition, bool onlyFirst) {
    bool isAbsorbed = super->findAnnotations(result, localPosition, onlyFirst);
    if (result->entries()->isNotEmpty() && onlyFirst) {
        return isAbsorbed;
    }
    if (size != nullptr && !(offset & size!)->contains(localPosition)) {
        return isAbsorbed;
    }
    if (T == S) {
        isAbsorbed = isAbsorbed || opaque;
        Object untypedValue = value;
        S typedValue = as<S>(untypedValue);
        result->add(<S>make<AnnotationEntryCls>(typedValue, localPosition - offset));
    }
    return isAbsorbed;
}

template<typename T>
void AnnotatedRegionLayerCls<T>::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<T>make<DiagnosticsPropertyCls>(__s("value"), value));
    properties->add(<Size>make<DiagnosticsPropertyCls>(__s("size"), size, nullptr));
    properties->add(<Offset>make<DiagnosticsPropertyCls>(__s("offset"), offset, nullptr));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("opaque"), opaque, false));
}
