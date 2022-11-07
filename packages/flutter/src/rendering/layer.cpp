#include "layer.hpp"
AnnotationEntry::AnnotationEntry(T annotation, Offset localPosition) {
    {
        assert(localPosition != nullptr);
    }
}

String AnnotationEntry::toString() {
    return "${objectRuntimeType(this, 'AnnotationEntry')}(annotation: $annotation, localPosition: $localPosition)";
}

void AnnotationResult::add(AnnotationEntry<T> entry) {
    return _entries.add(entry);
}

Iterable<AnnotationEntry<T>> AnnotationResult::entries() {
    return _entries;
}

Iterable<T> AnnotationResult::annotations() {
    return _entries.map();
}

bool Layer::subtreeHasCompositionCallbacks() {
    return _compositionCallbackCount > 0;
}

Rect Layer::describeClipBounds() {
    return nullptr;
}

VoidCallback Layer::addCompositionCallback(CompositionCallback callback) {
    _updateSubtreeCompositionObserverCount(1);
    int callbackId = _nextCallbackId += 1;
    _callbacks[callbackId] = ;
    return ;
}

bool Layer::debugDisposed() {
    bool disposed;
    assert(());
    return disposed;
}

int Layer::debugHandleCount() {
    int count;
    assert(());
    return count;
}

void Layer::dispose() {
    assert(!_debugMutationsLocked);
    assert(!_debugDisposed, "Layers must only be disposed once. This is typically handled by LayerHandle and createHandle. Subclasses should not directly call dispose, except to call super.dispose() in an overridden dispose  method. Tests must only call dispose once.");
    assert(());
    _engineLayer?.dispose();
    _engineLayer = nullptr;
}

ContainerLayer Layer::parent() {
    return (;
}

void Layer::markNeedsAddToScene() {
    assert(!_debugMutationsLocked);
    assert(!alwaysNeedsAddToScene, "$runtimeType with alwaysNeedsAddToScene set called markNeedsAddToScene.\nThe layer's alwaysNeedsAddToScene is set to true, and therefore it should not call markNeedsAddToScene.");
    assert(!_debugDisposed);
    if (_needsAddToScene) {
        return;
    }
    _needsAddToScene = true;
}

void Layer::debugMarkClean() {
    assert(!_debugMutationsLocked);
    assert(());
}

bool Layer::alwaysNeedsAddToScene() {
    return false;
}

bool Layer::debugSubtreeNeedsAddToScene() {
    bool result;
    assert(());
    return result;
}

EngineLayer Layer::engineLayer() {
    return _engineLayer;
}

void Layer::engineLayer(EngineLayer value) {
    assert(!_debugMutationsLocked);
    assert(!_debugDisposed);
    _engineLayer?.dispose();
    _engineLayer = value;
    if (!alwaysNeedsAddToScene) {
        if (parent != nullptr && !parent!.alwaysNeedsAddToScene) {
            parent!.markNeedsAddToScene();
        }
    }
}

void Layer::updateSubtreeNeedsAddToScene() {
    assert(!_debugMutationsLocked);
    _needsAddToScene = _needsAddToScene || alwaysNeedsAddToScene;
}

Layer Layer::nextSibling() {
    return _nextSibling;
}

Layer Layer::previousSibling() {
    return _previousSibling;
}

void Layer::dropChild(Layer child) {
    assert(!_debugMutationsLocked);
    if (!alwaysNeedsAddToScene) {
        markNeedsAddToScene();
    }
    if (child._compositionCallbackCount != 0) {
        _updateSubtreeCompositionObserverCount(-child._compositionCallbackCount);
    }
    super.dropChild(child);
}

void Layer::adoptChild(Layer child) {
    assert(!_debugMutationsLocked);
    if (!alwaysNeedsAddToScene) {
        markNeedsAddToScene();
    }
    if (child._compositionCallbackCount != 0) {
        _updateSubtreeCompositionObserverCount(child._compositionCallbackCount);
    }
    super.adoptChild(child);
}

void Layer::remove() {
    assert(!_debugMutationsLocked);
    parent?._removeChild(this);
}

bool Layer::findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result) {
    return false;
}

S Layer::find<S extends Object>(Offset localPosition) {
    AnnotationResult<S> result = <S>AnnotationResult();
    <S>findAnnotations(result, localPositiontrue);
    return result.entries.isEmpty? nullptr : result.entries.first.annotation;
}

AnnotationResult<S> Layer::findAllAnnotations<S extends Object>(Offset localPosition) {
    AnnotationResult<S> result = <S>AnnotationResult();
    <S>findAnnotations(result, localPositionfalse);
    return result;
}

String Layer::toStringShort() {
    return "${super.toStringShort()}${ owner == null ? " DETACHED" : ""}";
}

void Layer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Object>DiagnosticsProperty("owner", ownerparent != nullptr? DiagnosticLevel.hidden : DiagnosticLevel.info, nullptr));
    properties.add(<Object>DiagnosticsProperty("creator", debugCreatornullptr, DiagnosticLevel.debug));
    if (_engineLayer != nullptr) {
        properties.add(<String>DiagnosticsProperty("engine layer", describeIdentity(_engineLayer)));
    }
    properties.add(<int>DiagnosticsProperty("handles", debugHandleCount));
}

void Layer::_updateSubtreeCompositionObserverCount(int delta) {
    assert(delta != 0);
    _compositionCallbackCount = delta;
    assert(_compositionCallbackCount >= 0);
    if (parent != nullptr) {
        parent!._updateSubtreeCompositionObserverCount(delta);
    }
}

void Layer::_fireCompositionCallbacks(bool includeChildren) {
    for (VoidCallback callback : <VoidCallback>of(_callbacks.values)) {
        callback();
    }
}

void Layer::_unref() {
    assert(!_debugMutationsLocked);
    assert(_refCount > 0);
    _refCount = 1;
    if (_refCount == 0) {
        dispose();
    }
}

void Layer::_addToSceneWithRetainedRendering(SceneBuilder builder) {
    assert(!_debugMutationsLocked);
    if (!_needsAddToScene && _engineLayer != nullptr) {
        builder.addRetained(_engineLayer!);
        return;
    }
    addToScene(builder);
    _needsAddToScene = false;
}

LayerHandle::LayerHandle(T _layer) {
    {
        if (_layer != nullptr) {
            _layer!._refCount = 1;
        }
    }
}

T LayerHandle::layer() {
    return _layer;
}

void LayerHandle::layer(T layer) {
    assert(layer?.debugDisposed != true, "Attempted to create a handle to an already disposed layer: $layer.");
    if (identical(layer, _layer)) {
        return;
    }
    _layer?._unref();
    _layer = layer;
    if (_layer != nullptr) {
        _layer!._refCount = 1;
    }
}

String LayerHandle::toString() {
    return "LayerHandle(${_layer != null ? _layer.toString() : 'DISPOSED'})";
}

Picture PictureLayer::picture() {
    return _picture;
}

void PictureLayer::picture(Picture picture) {
    assert(!_debugDisposed);
    markNeedsAddToScene();
    _picture?.dispose();
    _picture = picture;
}

bool PictureLayer::isComplexHint() {
    return _isComplexHint;
}

void PictureLayer::isComplexHint(bool value) {
    if (value != _isComplexHint) {
        _isComplexHint = value;
        markNeedsAddToScene();
    }
}

bool PictureLayer::willChangeHint() {
    return _willChangeHint;
}

void PictureLayer::willChangeHint(bool value) {
    if (value != _willChangeHint) {
        _willChangeHint = value;
        markNeedsAddToScene();
    }
}

void PictureLayer::dispose() {
    picture = nullptr;
    super.dispose();
}

void PictureLayer::addToScene(SceneBuilder builder) {
    assert(picture != nullptr);
    builder.addPicture(Offset.zero, picture!isComplexHint, willChangeHint);
}

void PictureLayer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Rect>DiagnosticsProperty("paint bounds", canvasBounds));
    properties.add(<String>DiagnosticsProperty("picture", describeIdentity(_picture)));
    properties.add(<String>DiagnosticsProperty("raster cache hints", "isComplex = $isComplexHint, willChange = $willChangeHint"));
}

bool PictureLayer::findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result) {
    return false;
}

TextureLayer::TextureLayer(FilterQuality filterQuality, bool freeze, Rect rect, int textureId) {
    {
        assert(rect != nullptr);
        assert(textureId != nullptr);
    }
}

void TextureLayer::addToScene(SceneBuilder builder) {
    builder.addTexture(textureIdrect.topLeft, rect.width, rect.height, freeze, filterQuality);
}

bool TextureLayer::findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result) {
    return false;
}

PlatformViewLayer::PlatformViewLayer(Rect rect, int viewId) {
    {
        assert(rect != nullptr);
        assert(viewId != nullptr);
    }
}

void PlatformViewLayer::addToScene(SceneBuilder builder) {
    builder.addPlatformView(viewIdrect.topLeft, rect.width, rect.height);
}

PerformanceOverlayLayer::PerformanceOverlayLayer(bool checkerboardOffscreenLayers, bool checkerboardRasterCacheImages, int optionsMask, Rect overlayRect, int rasterizerThreshold) {
    {
        _overlayRect = overlayRect;
    }
}

Rect PerformanceOverlayLayer::overlayRect() {
    return _overlayRect;
}

void PerformanceOverlayLayer::overlayRect(Rect value) {
    if (value != _overlayRect) {
        _overlayRect = value;
        markNeedsAddToScene();
    }
}

void PerformanceOverlayLayer::addToScene(SceneBuilder builder) {
    assert(optionsMask != nullptr);
    builder.addPerformanceOverlay(optionsMask, overlayRect);
    builder.setRasterizerTracingThreshold(rasterizerThreshold);
    builder.setCheckerboardRasterCacheImages(checkerboardRasterCacheImages);
    builder.setCheckerboardOffscreenLayers(checkerboardOffscreenLayers);
}

bool PerformanceOverlayLayer::findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result) {
    return false;
}

Layer ContainerLayer::firstChild() {
    return _firstChild;
}

Layer ContainerLayer::lastChild() {
    return _lastChild;
}

bool ContainerLayer::hasChildren() {
    return _firstChild != nullptr;
}

Scene ContainerLayer::buildScene(SceneBuilder builder) {
    updateSubtreeNeedsAddToScene();
    addToScene(builder);
    if (subtreeHasCompositionCallbacks) {
        _fireCompositionCallbacks(true);
    }
    _needsAddToScene = false;
    Scene scene = builder.build();
    return scene;
}

void ContainerLayer::dispose() {
    removeAllChildren();
    _callbacks.clear();
    super.dispose();
}

void ContainerLayer::updateSubtreeNeedsAddToScene() {
    super.updateSubtreeNeedsAddToScene();
    Layer child = firstChild;
    while (child != nullptr) {
        child.updateSubtreeNeedsAddToScene();
        _needsAddToScene = _needsAddToScene || child._needsAddToScene;
        child = child.nextSibling;
    }
}

bool ContainerLayer::findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result) {
    for (; child != nullptr; child = child.previousSibling) {
        bool isAbsorbed = child.<S>findAnnotations(result, localPositiononlyFirst);
        if (isAbsorbed) {
            return true;
        }
        if (onlyFirst && result.entries.isNotEmpty) {
            return isAbsorbed;
        }
    }
    return false;
}

void ContainerLayer::attach(Object owner) {
    assert(!_debugMutationsLocked);
    super.attach(owner);
    Layer child = firstChild;
    while (child != nullptr) {
        child.attach(owner);
        child = child.nextSibling;
    }
}

void ContainerLayer::detach() {
    assert(!_debugMutationsLocked);
    super.detach();
    Layer child = firstChild;
    while (child != nullptr) {
        child.detach();
        child = child.nextSibling;
    }
    _fireCompositionCallbacks(false);
}

void ContainerLayer::append(Layer child) {
    assert(!_debugMutationsLocked);
    assert(child != this);
    assert(child != firstChild);
    assert(child != lastChild);
    assert(child.parent == nullptr);
    assert(!child.attached);
    assert(child.nextSibling == nullptr);
    assert(child.previousSibling == nullptr);
    assert(child._parentHandle.layer == nullptr);
    assert(());
    adoptChild(child);
    child._previousSibling = lastChild;
    if (lastChild != nullptr) {
        lastChild!._nextSibling = child;
    }
    _lastChild = child;
    _firstChild = child;
    child._parentHandle.layer = child;
    assert(child.attached == attached);
}

void ContainerLayer::removeAllChildren() {
    assert(!_debugMutationsLocked);
    Layer child = firstChild;
    while (child != nullptr) {
        Layer next = child.nextSibling;
        child._previousSibling = nullptr;
        child._nextSibling = nullptr;
        assert(child.attached == attached);
        dropChild(child);
        assert(child._parentHandle != nullptr);
        child._parentHandle.layer = nullptr;
        child = next;
    }
    _firstChild = nullptr;
    _lastChild = nullptr;
}

void ContainerLayer::addToScene(SceneBuilder builder) {
    addChildrenToScene(builder);
}

void ContainerLayer::addChildrenToScene(SceneBuilder builder) {
    Layer child = firstChild;
    while (child != nullptr) {
        child._addToSceneWithRetainedRendering(builder);
        child = child.nextSibling;
    }
}

void ContainerLayer::applyTransform(Layer child, Matrix4 transform) {
    assert(child != nullptr);
    assert(transform != nullptr);
}

List<Layer> ContainerLayer::depthFirstIterateChildren() {
    if (firstChild == nullptr) {
        return ;
    }
    List<Layer> children = ;
    Layer child = firstChild;
    while (child != nullptr) {
        children.add(child);
        if (child is ContainerLayer) {
            children.addAll(child.depthFirstIterateChildren());
        }
        child = child.nextSibling;
    }
    return children;
}

List<DiagnosticsNode> ContainerLayer::debugDescribeChildren() {
    List<DiagnosticsNode> children = ;
    if (firstChild == nullptr) {
        return children;
    }
    Layer child = firstChild;
    int count = 1;
    while (true) {
        children.add(child!.toDiagnosticsNode("child $count"));
        if (child == lastChild) {
                        break;
        }
        count = 1;
        child = child.nextSibling;
    }
    return children;
}

void ContainerLayer::_fireCompositionCallbacks(bool includeChildren) {
    super._fireCompositionCallbacks(includeChildren);
    if (!includeChildren) {
        return;
    }
    Layer child = firstChild;
    while (child != nullptr) {
        child._fireCompositionCallbacks(includeChildren);
        child = child.nextSibling;
    }
}

bool ContainerLayer::_debugUltimatePreviousSiblingOf(Layer child, Layer equals) {
    assert(child.attached == attached);
    while (child.previousSibling != nullptr) {
        assert(child.previousSibling != child);
        child = child.previousSibling!;
        assert(child.attached == attached);
    }
    return child == equals;
}

bool ContainerLayer::_debugUltimateNextSiblingOf(Layer child, Layer equals) {
    assert(child.attached == attached);
    while (child._nextSibling != nullptr) {
        assert(child._nextSibling != child);
        child = child._nextSibling!;
        assert(child.attached == attached);
    }
    return child == equals;
}

void ContainerLayer::_removeChild(Layer child) {
    assert(child.parent == this);
    assert(child.attached == attached);
    assert(_debugUltimatePreviousSiblingOf(childfirstChild));
    assert(_debugUltimateNextSiblingOf(childlastChild));
    assert(child._parentHandle.layer != nullptr);
    if (child._previousSibling == nullptr) {
        assert(_firstChild == child);
        _firstChild = child._nextSibling;
    } else {
        child._previousSibling!._nextSibling = child.nextSibling;
    }
    if (child._nextSibling == nullptr) {
        assert(lastChild == child);
        _lastChild = child.previousSibling;
    } else {
        child.nextSibling!._previousSibling = child.previousSibling;
    }
    assert((firstChild == nullptr) == (lastChild == nullptr));
    assert(firstChild == nullptr || firstChild!.attached == attached);
    assert(lastChild == nullptr || lastChild!.attached == attached);
    assert(firstChild == nullptr || _debugUltimateNextSiblingOf(firstChild!lastChild));
    assert(lastChild == nullptr || _debugUltimatePreviousSiblingOf(lastChild!firstChild));
    child._previousSibling = nullptr;
    child._nextSibling = nullptr;
    dropChild(child);
    child._parentHandle.layer = nullptr;
    assert(!child.attached);
}

OffsetLayer::OffsetLayer(Offset offset) {
    {
        _offset = offset;
    }
}

Offset OffsetLayer::offset() {
    return _offset;
}

void OffsetLayer::offset(Offset value) {
    if (value != _offset) {
        markNeedsAddToScene();
    }
    _offset = value;
}

bool OffsetLayer::findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result) {
    return super.<S>findAnnotations(result, localPosition - offsetonlyFirst);
}

void OffsetLayer::applyTransform(Layer child, Matrix4 transform) {
    assert(child != nullptr);
    assert(transform != nullptr);
    transform.translate(offset.dx, offset.dy);
}

void OffsetLayer::addToScene(SceneBuilder builder) {
    engineLayer = builder.pushOffset(offset.dx, offset.dy();
    addChildrenToScene(builder);
    builder.pop();
}

void OffsetLayer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Offset>DiagnosticsProperty("offset", offset));
}

Future<Image> OffsetLayer::toImage(Rect bounds, double pixelRatio) {
    assert(bounds != nullptr);
    assert(pixelRatio != nullptr);
    SceneBuilder builder = ui.SceneBuilder();
    Matrix4 transform = Matrix4.translationValues((-bounds.left - offset.dx) * pixelRatio, (-bounds.top - offset.dy) * pixelRatio, 0.0);
    transform.scale(pixelRatio, pixelRatio);
    builder.pushTransform(transform.storage);
    Scene scene = buildScene(builder);
    ;
}

ClipRectLayer::ClipRectLayer(Clip clipBehavior, Rect clipRect) {
    {
        _clipRect = clipRect;
        _clipBehavior = clipBehavior;
        assert(clipBehavior != nullptr);
        assert(clipBehavior != Clip.none);
    }
}

Rect ClipRectLayer::clipRect() {
    return _clipRect;
}

void ClipRectLayer::clipRect(Rect value) {
    if (value != _clipRect) {
        _clipRect = value;
        markNeedsAddToScene();
    }
}

Rect ClipRectLayer::describeClipBounds() {
    return clipRect;
}

Clip ClipRectLayer::clipBehavior() {
    return _clipBehavior;
}

void ClipRectLayer::clipBehavior(Clip value) {
    assert(value != nullptr);
    assert(value != Clip.none);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsAddToScene();
    }
}

bool ClipRectLayer::findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result) {
    if (!clipRect!.contains(localPosition)) {
        return false;
    }
    return super.<S>findAnnotations(result, localPositiononlyFirst);
}

void ClipRectLayer::addToScene(SceneBuilder builder) {
    assert(clipRect != nullptr);
    assert(clipBehavior != nullptr);
    bool enabled = true;
    assert(());
    if (enabled) {
        engineLayer = builder.pushClipRect(clipRect!clipBehavior, ();
    } else {
        engineLayer = nullptr;
    }
    addChildrenToScene(builder);
    if (enabled) {
        builder.pop();
    }
}

void ClipRectLayer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Rect>DiagnosticsProperty("clipRect", clipRect));
    properties.add(<Clip>DiagnosticsProperty("clipBehavior", clipBehavior));
}

ClipRRectLayer::ClipRRectLayer(Clip clipBehavior, RRect clipRRect) {
    {
        _clipRRect = clipRRect;
        _clipBehavior = clipBehavior;
        assert(clipBehavior != nullptr);
        assert(clipBehavior != Clip.none);
    }
}

RRect ClipRRectLayer::clipRRect() {
    return _clipRRect;
}

void ClipRRectLayer::clipRRect(RRect value) {
    if (value != _clipRRect) {
        _clipRRect = value;
        markNeedsAddToScene();
    }
}

Rect ClipRRectLayer::describeClipBounds() {
    return clipRRect?.outerRect;
}

Clip ClipRRectLayer::clipBehavior() {
    return _clipBehavior;
}

void ClipRRectLayer::clipBehavior(Clip value) {
    assert(value != nullptr);
    assert(value != Clip.none);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsAddToScene();
    }
}

bool ClipRRectLayer::findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result) {
    if (!clipRRect!.contains(localPosition)) {
        return false;
    }
    return super.<S>findAnnotations(result, localPositiononlyFirst);
}

void ClipRRectLayer::addToScene(SceneBuilder builder) {
    assert(clipRRect != nullptr);
    assert(clipBehavior != nullptr);
    bool enabled = true;
    assert(());
    if (enabled) {
        engineLayer = builder.pushClipRRect(clipRRect!clipBehavior, ();
    } else {
        engineLayer = nullptr;
    }
    addChildrenToScene(builder);
    if (enabled) {
        builder.pop();
    }
}

void ClipRRectLayer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<RRect>DiagnosticsProperty("clipRRect", clipRRect));
    properties.add(<Clip>DiagnosticsProperty("clipBehavior", clipBehavior));
}

ClipPathLayer::ClipPathLayer(Clip clipBehavior, Path clipPath) {
    {
        _clipPath = clipPath;
        _clipBehavior = clipBehavior;
        assert(clipBehavior != nullptr);
        assert(clipBehavior != Clip.none);
    }
}

Path ClipPathLayer::clipPath() {
    return _clipPath;
}

void ClipPathLayer::clipPath(Path value) {
    if (value != _clipPath) {
        _clipPath = value;
        markNeedsAddToScene();
    }
}

Rect ClipPathLayer::describeClipBounds() {
    return clipPath?.getBounds();
}

Clip ClipPathLayer::clipBehavior() {
    return _clipBehavior;
}

void ClipPathLayer::clipBehavior(Clip value) {
    assert(value != nullptr);
    assert(value != Clip.none);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsAddToScene();
    }
}

bool ClipPathLayer::findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result) {
    if (!clipPath!.contains(localPosition)) {
        return false;
    }
    return super.<S>findAnnotations(result, localPositiononlyFirst);
}

void ClipPathLayer::addToScene(SceneBuilder builder) {
    assert(clipPath != nullptr);
    assert(clipBehavior != nullptr);
    bool enabled = true;
    assert(());
    if (enabled) {
        engineLayer = builder.pushClipPath(clipPath!clipBehavior, ();
    } else {
        engineLayer = nullptr;
    }
    addChildrenToScene(builder);
    if (enabled) {
        builder.pop();
    }
}

void ClipPathLayer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Clip>DiagnosticsProperty("clipBehavior", clipBehavior));
}

ColorFilterLayer::ColorFilterLayer(ColorFilter colorFilter) {
    {
        _colorFilter = colorFilter;
    }
}

ColorFilter ColorFilterLayer::colorFilter() {
    return _colorFilter;
}

void ColorFilterLayer::colorFilter(ColorFilter value) {
    assert(value != nullptr);
    if (value != _colorFilter) {
        _colorFilter = value;
        markNeedsAddToScene();
    }
}

void ColorFilterLayer::addToScene(SceneBuilder builder) {
    assert(colorFilter != nullptr);
    engineLayer = builder.pushColorFilter(colorFilter!();
    addChildrenToScene(builder);
    builder.pop();
}

void ColorFilterLayer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<ColorFilter>DiagnosticsProperty("colorFilter", colorFilter));
}

ImageFilterLayer::ImageFilterLayer(ImageFilter imageFilter) {
    {
        _imageFilter = imageFilter;
    }
}

ImageFilter ImageFilterLayer::imageFilter() {
    return _imageFilter;
}

void ImageFilterLayer::imageFilter(ImageFilter value) {
    assert(value != nullptr);
    if (value != _imageFilter) {
        _imageFilter = value;
        markNeedsAddToScene();
    }
}

void ImageFilterLayer::addToScene(SceneBuilder builder) {
    assert(imageFilter != nullptr);
    engineLayer = builder.pushImageFilter(imageFilter!();
    addChildrenToScene(builder);
    builder.pop();
}

void ImageFilterLayer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<ImageFilter>DiagnosticsProperty("imageFilter", imageFilter));
}

TransformLayer::TransformLayer(Unknown, Matrix4 transform) {
    {
        _transform = transform;
    }
}

Matrix4 TransformLayer::transform() {
    return _transform;
}

void TransformLayer::transform(Matrix4 value) {
    assert(value != nullptr);
    assert(value!.storage.every());
    if (value == _transform) {
        return;
    }
    _transform = value;
    _inverseDirty = true;
    markNeedsAddToScene();
}

void TransformLayer::addToScene(SceneBuilder builder) {
    assert(transform != nullptr);
    _lastEffectiveTransform = transform;
    if (offset != Offset.zero) {
        _lastEffectiveTransform = ;
    }
    engineLayer = builder.pushTransform(_lastEffectiveTransform!.storage();
    addChildrenToScene(builder);
    builder.pop();
}

bool TransformLayer::findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result) {
    Offset transformedOffset = _transformOffset(localPosition);
    if (transformedOffset == nullptr) {
        return false;
    }
    return super.<S>findAnnotations(result, transformedOffsetonlyFirst);
}

void TransformLayer::applyTransform(Layer child, Matrix4 transform) {
    assert(child != nullptr);
    assert(transform != nullptr);
    assert(_lastEffectiveTransform != nullptr || this.transform != nullptr);
    if (_lastEffectiveTransform == nullptr) {
        transform.multiply(this.transform!);
    } else {
        transform.multiply(_lastEffectiveTransform!);
    }
}

void TransformLayer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(TransformProperty("transform", transform));
}

Offset TransformLayer::_transformOffset(Offset localPosition) {
    if (_inverseDirty) {
        _invertedTransform = Matrix4.tryInvert(PointerEvent.removePerspectiveTransform(transform!));
        _inverseDirty = false;
    }
    if (_invertedTransform == nullptr) {
        return nullptr;
    }
    return MatrixUtils.transformPoint(_invertedTransform!, localPosition);
}

OpacityLayer::OpacityLayer(int alpha, Unknown) {
    {
        _alpha = alpha;
    }
}

int OpacityLayer::alpha() {
    return _alpha;
}

void OpacityLayer::alpha(int value) {
    assert(value != nullptr);
    if (value != _alpha) {
        if (value == 255 || _alpha == 255) {
            engineLayer = nullptr;
        }
        _alpha = value;
        markNeedsAddToScene();
    }
}

void OpacityLayer::addToScene(SceneBuilder builder) {
    assert(alpha != nullptr);
    bool enabled = firstChild != nullptr;
    if (!enabled) {
        engineLayer = nullptr;
        return;
    }
    assert(());
    int realizedAlpha = alpha!;
    if (enabled &&  < 255) {
        assert(_engineLayer is OpacityEngineLayer);
        engineLayer = builder.pushOpacity(realizedAlphaoffset, ();
    } else {
        assert(_engineLayer is OffsetEngineLayer);
        engineLayer = builder.pushOffset(offset.dx, offset.dy();
    }
    addChildrenToScene(builder);
    builder.pop();
}

void OpacityLayer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(IntProperty("alpha", alpha));
}

ShaderMaskLayer::ShaderMaskLayer(BlendMode blendMode, Rect maskRect, Shader shader) {
    {
        _shader = shader;
        _maskRect = maskRect;
        _blendMode = blendMode;
    }
}

Shader ShaderMaskLayer::shader() {
    return _shader;
}

void ShaderMaskLayer::shader(Shader value) {
    if (value != _shader) {
        _shader = value;
        markNeedsAddToScene();
    }
}

Rect ShaderMaskLayer::maskRect() {
    return _maskRect;
}

void ShaderMaskLayer::maskRect(Rect value) {
    if (value != _maskRect) {
        _maskRect = value;
        markNeedsAddToScene();
    }
}

BlendMode ShaderMaskLayer::blendMode() {
    return _blendMode;
}

void ShaderMaskLayer::blendMode(BlendMode value) {
    if (value != _blendMode) {
        _blendMode = value;
        markNeedsAddToScene();
    }
}

void ShaderMaskLayer::addToScene(SceneBuilder builder) {
    assert(shader != nullptr);
    assert(maskRect != nullptr);
    assert(blendMode != nullptr);
    engineLayer = builder.pushShaderMask(shader!, maskRect!, blendMode!();
    addChildrenToScene(builder);
    builder.pop();
}

void ShaderMaskLayer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Shader>DiagnosticsProperty("shader", shader));
    properties.add(<Rect>DiagnosticsProperty("maskRect", maskRect));
    properties.add(<BlendMode>EnumProperty("blendMode", blendMode));
}

BackdropFilterLayer::BackdropFilterLayer(BlendMode blendMode, ImageFilter filter) {
    {
        _filter = filter;
        _blendMode = blendMode;
    }
}

ImageFilter BackdropFilterLayer::filter() {
    return _filter;
}

void BackdropFilterLayer::filter(ImageFilter value) {
    if (value != _filter) {
        _filter = value;
        markNeedsAddToScene();
    }
}

BlendMode BackdropFilterLayer::blendMode() {
    return _blendMode;
}

void BackdropFilterLayer::blendMode(BlendMode value) {
    if (value != _blendMode) {
        _blendMode = value;
        markNeedsAddToScene();
    }
}

void BackdropFilterLayer::addToScene(SceneBuilder builder) {
    assert(filter != nullptr);
    engineLayer = builder.pushBackdropFilter(filter!blendMode, ();
    addChildrenToScene(builder);
    builder.pop();
}

void BackdropFilterLayer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<ImageFilter>DiagnosticsProperty("filter", filter));
    properties.add(<BlendMode>EnumProperty("blendMode", blendMode));
}

PhysicalModelLayer::PhysicalModelLayer(Clip clipBehavior, Path clipPath, Color color, double elevation, Color shadowColor) {
    {
        _clipPath = clipPath;
        _clipBehavior = clipBehavior;
        _elevation = elevation;
        _color = color;
        _shadowColor = shadowColor;
    }
}

Path PhysicalModelLayer::clipPath() {
    return _clipPath;
}

void PhysicalModelLayer::clipPath(Path value) {
    if (value != _clipPath) {
        _clipPath = value;
        markNeedsAddToScene();
    }
}

Clip PhysicalModelLayer::clipBehavior() {
    return _clipBehavior;
}

void PhysicalModelLayer::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsAddToScene();
    }
}

double PhysicalModelLayer::elevation() {
    return _elevation;
}

void PhysicalModelLayer::elevation(double value) {
    if (value != _elevation) {
        _elevation = value;
        markNeedsAddToScene();
    }
}

Color PhysicalModelLayer::color() {
    return _color;
}

void PhysicalModelLayer::color(Color value) {
    if (value != _color) {
        _color = value;
        markNeedsAddToScene();
    }
}

Color PhysicalModelLayer::shadowColor() {
    return _shadowColor;
}

void PhysicalModelLayer::shadowColor(Color value) {
    if (value != _shadowColor) {
        _shadowColor = value;
        markNeedsAddToScene();
    }
}

bool PhysicalModelLayer::findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result) {
    if (!clipPath!.contains(localPosition)) {
        return false;
    }
    return super.<S>findAnnotations(result, localPositiononlyFirst);
}

void PhysicalModelLayer::addToScene(SceneBuilder builder) {
    assert(clipPath != nullptr);
    assert(clipBehavior != nullptr);
    assert(elevation != nullptr);
    assert(color != nullptr);
    assert(shadowColor != nullptr);
    bool enabled = true;
    assert(());
    if (enabled) {
        engineLayer = builder.pushPhysicalShape(clipPath!, elevation!, color!, shadowColor, clipBehavior, ();
    } else {
        engineLayer = nullptr;
    }
    addChildrenToScene(builder);
    if (enabled) {
        builder.pop();
    }
}

void PhysicalModelLayer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("elevation", elevation));
    properties.add(ColorProperty("color", color));
}

LeaderLayer LayerLink::leader() {
    return _leader;
}

String LayerLink::toString() {
    return "${describeIdentity(this)}(${ _leader != null ? "<linked>" : "<dangling>" })";
}

void LayerLink::_registerLeader(LeaderLayer leader) {
    assert(_leader != leader);
    assert(());
    _leader = leader;
}

void LayerLink::_unregisterLeader(LeaderLayer leader) {
    if (_leader == leader) {
        _leader = nullptr;
    } else {
        assert(_debugPreviousLeaders!.remove(leader));
    }
}

void LayerLink::_debugScheduleLeadersCleanUpCheck() {
    assert(_debugPreviousLeaders != nullptr);
    assert(());
}

LeaderLayer::LeaderLayer(LayerLink link, Offset offset) {
    {
        assert(link != nullptr);
        _link = link;
        _offset = offset;
    }
}

LayerLink LeaderLayer::link() {
    return _link;
}

void LeaderLayer::link(LayerLink value) {
    assert(value != nullptr);
    if (_link == value) {
        return;
    }
    if (attached) {
        _link._unregisterLeader(this);
        value._registerLeader(this);
    }
    _link = value;
}

Offset LeaderLayer::offset() {
    return _offset;
}

void LeaderLayer::offset(Offset value) {
    assert(value != nullptr);
    if (value == _offset) {
        return;
    }
    _offset = value;
    if (!alwaysNeedsAddToScene) {
        markNeedsAddToScene();
    }
}

void LeaderLayer::attach(Object owner) {
    super.attach(owner);
    _link._registerLeader(this);
}

void LeaderLayer::detach() {
    _link._unregisterLeader(this);
    super.detach();
}

bool LeaderLayer::findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result) {
    return super.<S>findAnnotations(result, localPosition - offsetonlyFirst);
}

void LeaderLayer::addToScene(SceneBuilder builder) {
    assert(offset != nullptr);
    if (offset != Offset.zero) {
        engineLayer = builder.pushTransform(Matrix4.translationValues(offset.dx, offset.dy, 0.0).storage();
    }
    addChildrenToScene(builder);
    if (offset != Offset.zero) {
        builder.pop();
    }
}

void LeaderLayer::applyTransform(Layer child, Matrix4 transform) {
    if (offset != Offset.zero) {
        transform.translate(offset.dx, offset.dy);
    }
}

void LeaderLayer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Offset>DiagnosticsProperty("offset", offset));
    properties.add(<LayerLink>DiagnosticsProperty("link", link));
}

FollowerLayer::FollowerLayer(LayerLink link, Offset linkedOffset, bool showWhenUnlinked, Offset unlinkedOffset) {
    {
        assert(link != nullptr);
        _link = link;
    }
}

LayerLink FollowerLayer::link() {
    return _link;
}

void FollowerLayer::link(LayerLink value) {
    assert(value != nullptr);
    _link = value;
}

bool FollowerLayer::findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result) {
    if (_link.leader == nullptr) {
        if (showWhenUnlinked!) {
            return super.findAnnotations(result, localPosition - unlinkedOffset!onlyFirst);
        }
        return false;
    }
    Offset transformedOffset = _transformOffset(localPosition);
    if (transformedOffset == nullptr) {
        return false;
    }
    return super.<S>findAnnotations(result, transformedOffsetonlyFirst);
}

Matrix4 FollowerLayer::getLastTransform() {
    if (_lastTransform == nullptr) {
        return nullptr;
    }
    Matrix4 result = Matrix4.translationValues(-_lastOffset!.dx, -_lastOffset!.dy, 0.0);
    result.multiply(_lastTransform!);
    return result;
}

bool FollowerLayer::alwaysNeedsAddToScene() {
    return true;
}

void FollowerLayer::addToScene(SceneBuilder builder) {
    assert(link != nullptr);
    assert(showWhenUnlinked != nullptr);
    if (_link.leader == nullptr && !showWhenUnlinked!) {
        _lastTransform = nullptr;
        _lastOffset = nullptr;
        _inverseDirty = true;
        engineLayer = nullptr;
        return;
    }
    _establishTransform();
    if (_lastTransform != nullptr) {
        _lastOffset = unlinkedOffset;
        engineLayer = builder.pushTransform(_lastTransform!.storage();
        addChildrenToScene(builder);
        builder.pop();
    } else {
        _lastOffset = nullptr;
        Matrix4 matrix = Matrix4.translationValues(unlinkedOffset!.dx, unlinkedOffset!.dy, .0);
        engineLayer = builder.pushTransform(matrix.storage();
        addChildrenToScene(builder);
        builder.pop();
    }
    _inverseDirty = true;
}

void FollowerLayer::applyTransform(Layer child, Matrix4 transform) {
    assert(child != nullptr);
    assert(transform != nullptr);
    if (_lastTransform != nullptr) {
        transform.multiply(_lastTransform!);
    } else {
        transform.multiply(Matrix4.translationValues(unlinkedOffset!.dx, unlinkedOffset!.dy, 0));
    }
}

void FollowerLayer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<LayerLink>DiagnosticsProperty("link", link));
    properties.add(TransformProperty("transform", getLastTransform()nullptr));
}

Offset FollowerLayer::_transformOffset(Offset localPosition) {
    if (_inverseDirty) {
        _invertedTransform = Matrix4.tryInvert(getLastTransform()!);
        _inverseDirty = false;
    }
    if (_invertedTransform == nullptr) {
        return nullptr;
    }
    Vector4 vector = Vector4(localPosition.dx, localPosition.dy, 0.0, 1.0);
    Vector4 result = _invertedTransform!.transform(vector);
    return Offset(result[0] - linkedOffset!.dx, result[1] - linkedOffset!.dy);
}

Matrix4 FollowerLayer::_collectTransformForLayerChain(List<ContainerLayer> layers) {
    Matrix4 result = Matrix4.identity();
    for (; index > 0; index = 1) {
        layers[index]?.applyTransform(layers[index - 1], result);
    }
    return result;
}

Layer FollowerLayer::_pathsToCommonAncestor(Layer a, List<ContainerLayer> ancestorsA, List<ContainerLayer> ancestorsB, Layer b) {
    if (a == nullptr || b == nullptr) {
        return nullptr;
    }
    if (identical(a, b)) {
        return a;
    }
    if (a.depth < b.depth) {
        ancestorsB.add(b.parent);
        return _pathsToCommonAncestor(a, b.parent, ancestorsA, ancestorsB);
    } else     {
        if (a.depth > b.depth) {
        ancestorsA.add(a.parent);
        return _pathsToCommonAncestor(a.parent, b, ancestorsA, ancestorsB);
    }
;
    }    ancestorsA.add(a.parent);
    ancestorsB.add(b.parent);
    return _pathsToCommonAncestor(a.parent, b.parent, ancestorsA, ancestorsB);
}

bool FollowerLayer::_debugCheckLeaderBeforeFollower(List<ContainerLayer> followerToCommonAncestor, List<ContainerLayer> leaderToCommonAncestor) {
    if (followerToCommonAncestor.length <= 1) {
        return false;
    }
    if (leaderToCommonAncestor.length <= 1) {
        return true;
    }
    ContainerLayer leaderSubtreeBelowAncestor = leaderToCommonAncestor[leaderToCommonAncestor.length - 2];
    ContainerLayer followerSubtreeBelowAncestor = followerToCommonAncestor[followerToCommonAncestor.length - 2];
    Layer sibling = leaderSubtreeBelowAncestor;
    while (sibling != nullptr) {
        if (sibling == followerSubtreeBelowAncestor) {
            return true;
        }
        sibling = sibling.nextSibling;
    }
    return false;
}

void FollowerLayer::_establishTransform() {
    assert(link != nullptr);
    _lastTransform = nullptr;
    LeaderLayer leader = _link.leader;
    if (leader == nullptr) {
        return;
    }
    assert(leader.owner == owner, "Linked LeaderLayer anchor is not in the same layer tree as the FollowerLayer.");
    List<ContainerLayer> forwardLayers = ;
    List<ContainerLayer> inverseLayers = ;
    Layer ancestor = _pathsToCommonAncestor(leader, this, forwardLayers, inverseLayers);
    assert(ancestor != nullptr, "LeaderLayer and FollowerLayer do not have a common ancestor.");
    assert(_debugCheckLeaderBeforeFollower(forwardLayers, inverseLayers), "LeaderLayer anchor must come before FollowerLayer in paint order, but the reverse was true.");
    Matrix4 forwardTransform = _collectTransformForLayerChain(forwardLayers);
    leader.applyTransform(nullptr, forwardTransform);
    forwardTransform.translate(linkedOffset!.dx, linkedOffset!.dy);
    Matrix4 inverseTransform = _collectTransformForLayerChain(inverseLayers);
    if (inverseTransform.invert() == 0.0) {
        return;
    }
    inverseTransform.multiply(forwardTransform);
    _lastTransform = inverseTransform;
    _inverseDirty = true;
}

AnnotatedRegionLayer::AnnotatedRegionLayer(Offset offset, bool opaque, Size size, T value) {
    {
        assert(value != nullptr);
        assert(opaque != nullptr);
        offset = offset ?? Offset.zero;
    }
}

bool AnnotatedRegionLayer::findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result) {
    bool isAbsorbed = super.findAnnotations(result, localPositiononlyFirst);
    if (result.entries.isNotEmpty && onlyFirst) {
        return isAbsorbed;
    }
    if (size != nullptr && !(offset & size!).contains(localPosition)) {
        return isAbsorbed;
    }
    if (T == S) {
        isAbsorbed = isAbsorbed || opaque;
        Object untypedValue = value;
        S typedValue = (;
        result.add(<S>AnnotationEntry(typedValue, localPosition - offset));
    }
    return isAbsorbed;
}

void AnnotatedRegionLayer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<T>DiagnosticsProperty("value", value));
    properties.add(<Size>DiagnosticsProperty("size", sizenullptr));
    properties.add(<Offset>DiagnosticsProperty("offset", offsetnullptr));
    properties.add(<bool>DiagnosticsProperty("opaque", opaquefalse));
}
