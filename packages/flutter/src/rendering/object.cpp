#include "object.hpp"
void ParentData::detach() {
}

String ParentData::toString() {
    return "<none>";
}

PaintingContext::PaintingContext(ContainerLayer _containerLayer, Rect estimatedBounds) {
    {
        assert(_containerLayer != nullptr);
        assert(estimatedBounds != nullptr);
    }
}

void PaintingContext::repaintCompositedChild(RenderObject child, bool debugAlsoPaintedParent) {
    assert(child._needsPaint);
    _repaintCompositedChild(childdebugAlsoPaintedParent);
}

void PaintingContext::updateLayerProperties(RenderObject child) {
    assert(child.isRepaintBoundary && child._wasRepaintBoundary);
    assert(!child._needsPaint);
    assert(child._layerHandle.layer != nullptr);
    OffsetLayer childLayer = (;
    Offset debugOldOffset;
    assert(());
    OffsetLayer updatedLayer = child.updateCompositedLayer(childLayer);
    assert(identical(updatedLayer, childLayer), "$child created a new layer instance $updatedLayer instead of reusing the existing layer $childLayer. See the documentation of RenderObject.updateCompositedLayer for more information on how to correctly implement this method.");
    assert(debugOldOffset == updatedLayer.offset);
    child._needsCompositedLayerUpdate = false;
}

void PaintingContext::debugInstrumentRepaintCompositedChild(RenderObject child, PaintingContext customContext, bool debugAlsoPaintedParent) {
    assert(());
}

void PaintingContext::paintChild(RenderObject child, Offset offset) {
    assert(());
    if (child.isRepaintBoundary) {
        stopRecordingIfNeeded();
        _compositeChild(child, offset);
    } else     {
        if (child._wasRepaintBoundary) {
        assert(child._layerHandle.layer is OffsetLayer);
        child._layerHandle.layer = nullptr;
        child._paintWithContext(this, offset);
    } else {
        child._paintWithContext(this, offset);
    }
;
    }}

void PaintingContext::appendLayer(Layer layer) {
    assert(!_isRecording);
    layer.remove();
    _containerLayer.append(layer);
}

Canvas PaintingContext::canvas() {
    if (_canvas == nullptr) {
        _startRecording();
    }
    assert(_currentLayer != nullptr);
    return _canvas!;
}

VoidCallback PaintingContext::addCompositionCallback(CompositionCallback callback) {
    return _containerLayer.addCompositionCallback(callback);
}

void PaintingContext::stopRecordingIfNeeded() {
    if (!_isRecording) {
        return;
    }
    assert(());
    _currentLayer!.picture = _recorder!.endRecording();
    _currentLayer = nullptr;
    _recorder = nullptr;
    _canvas = nullptr;
}

void PaintingContext::setIsComplexHint() {
    _currentLayer?.isComplexHint = true;
}

void PaintingContext::setWillChangeHint() {
    _currentLayer?.willChangeHint = true;
}

void PaintingContext::addLayer(Layer layer) {
    stopRecordingIfNeeded();
    appendLayer(layer);
}

void PaintingContext::pushLayer(ContainerLayer childLayer, Rect childPaintBounds, Offset offset, PaintingContextCallback painter) {
    assert(painter != nullptr);
    if (childLayer.hasChildren) {
        childLayer.removeAllChildren();
    }
    stopRecordingIfNeeded();
    appendLayer(childLayer);
    PaintingContext childContext = createChildContext(childLayer, childPaintBounds ?? estimatedBounds);
    painter(childContext, offset);
    childContext.stopRecordingIfNeeded();
}

PaintingContext PaintingContext::createChildContext(Rect bounds, ContainerLayer childLayer) {
    return PaintingContext(childLayer, bounds);
}

ClipRectLayer PaintingContext::pushClipRect(Clip clipBehavior, Rect clipRect, bool needsCompositing, Offset offset, ClipRectLayer oldLayer, PaintingContextCallback painter) {
    if (clipBehavior == Clip.none) {
        painter(this, offset);
        return nullptr;
    }
    Rect offsetClipRect = clipRect.shift(offset);
    if (needsCompositing) {
        ClipRectLayer layer = oldLayer ?? ClipRectLayer();
        ;
        pushLayer(layer, painter, offsetoffsetClipRect);
        return layer;
    } else {
        clipRectAndPaint(offsetClipRect, clipBehavior, offsetClipRect, );
        return nullptr;
    }
}

ClipRRectLayer PaintingContext::pushClipRRect(Rect bounds, Clip clipBehavior, RRect clipRRect, bool needsCompositing, Offset offset, ClipRRectLayer oldLayer, PaintingContextCallback painter) {
    assert(clipBehavior != nullptr);
    if (clipBehavior == Clip.none) {
        painter(this, offset);
        return nullptr;
    }
    Rect offsetBounds = bounds.shift(offset);
    RRect offsetClipRRect = clipRRect.shift(offset);
    if (needsCompositing) {
        ClipRRectLayer layer = oldLayer ?? ClipRRectLayer();
        ;
        pushLayer(layer, painter, offsetoffsetBounds);
        return layer;
    } else {
        clipRRectAndPaint(offsetClipRRect, clipBehavior, offsetBounds, );
        return nullptr;
    }
}

ClipPathLayer PaintingContext::pushClipPath(Rect bounds, Clip clipBehavior, Path clipPath, bool needsCompositing, Offset offset, ClipPathLayer oldLayer, PaintingContextCallback painter) {
    assert(clipBehavior != nullptr);
    if (clipBehavior == Clip.none) {
        painter(this, offset);
        return nullptr;
    }
    Rect offsetBounds = bounds.shift(offset);
    Path offsetClipPath = clipPath.shift(offset);
    if (needsCompositing) {
        ClipPathLayer layer = oldLayer ?? ClipPathLayer();
        ;
        pushLayer(layer, painter, offsetoffsetBounds);
        return layer;
    } else {
        clipPathAndPaint(offsetClipPath, clipBehavior, offsetBounds, );
        return nullptr;
    }
}

ColorFilterLayer PaintingContext::pushColorFilter(ColorFilter colorFilter, Offset offset, ColorFilterLayer oldLayer, PaintingContextCallback painter) {
    assert(colorFilter != nullptr);
    ColorFilterLayer layer = oldLayer ?? ColorFilterLayer();
    layer.colorFilter = colorFilter;
    pushLayer(layer, painter, offset);
    return layer;
}

TransformLayer PaintingContext::pushTransform(bool needsCompositing, Offset offset, TransformLayer oldLayer, PaintingContextCallback painter, Matrix4 transform) {
    Matrix4 effectiveTransform = ;
    if (needsCompositing) {
        TransformLayer layer = oldLayer ?? TransformLayer();
        layer.transform = effectiveTransform;
        pushLayer(layer, painter, offsetMatrixUtils.inverseTransformRect(effectiveTransform, estimatedBounds));
        return layer;
    } else {
        ;
        painter(this, offset);
        canvas.restore();
        return nullptr;
    }
}

OpacityLayer PaintingContext::pushOpacity(int alpha, Offset offset, OpacityLayer oldLayer, PaintingContextCallback painter) {
    OpacityLayer layer = oldLayer ?? OpacityLayer();
    ;
    pushLayer(layer, painter, Offset.zero);
    return layer;
}

String PaintingContext::toString() {
    return "${objectRuntimeType(this, 'PaintingContext')}#$hashCode(layer: $_containerLayer, canvas bounds: $estimatedBounds)";
}

void PaintingContext::_repaintCompositedChild(RenderObject child, PaintingContext childContext, bool debugAlsoPaintedParent) {
    assert(child.isRepaintBoundary);
    assert(());
    OffsetLayer childLayer = (;
    if (childLayer == nullptr) {
        assert(debugAlsoPaintedParent);
        assert(child._layerHandle.layer == nullptr);
        OffsetLayer layer = child.updateCompositedLayer(nullptr);
        child._layerHandle.layer = childLayer = layer;
    } else {
        assert(debugAlsoPaintedParent || childLayer.attached);
        Offset debugOldOffset;
        assert(());
        childLayer.removeAllChildren();
        OffsetLayer updatedLayer = child.updateCompositedLayer(childLayer);
        assert(identical(updatedLayer, childLayer), "$child created a new layer instance $updatedLayer instead of reusing the existing layer $childLayer. See the documentation of RenderObject.updateCompositedLayer for more information on how to correctly implement this method.");
        assert(debugOldOffset == updatedLayer.offset);
    }
    child._needsCompositedLayerUpdate = false;
    assert(identical(childLayer, child._layerHandle.layer));
    assert(child._layerHandle.layer is OffsetLayer);
    assert(());
    childContext = PaintingContext(childLayer, child.paintBounds);
    child._paintWithContext(childContext, Offset.zero);
    assert(identical(childLayer, child._layerHandle.layer));
    childContext.stopRecordingIfNeeded();
}

void PaintingContext::_compositeChild(RenderObject child, Offset offset) {
    assert(!_isRecording);
    assert(child.isRepaintBoundary);
    assert(_canvas == nullptr || _canvas!.getSaveCount() == 1);
    if (child._needsPaint || !child._wasRepaintBoundary) {
        repaintCompositedChild(childtrue);
    } else {
        if (child._needsCompositedLayerUpdate) {
            updateLayerProperties(child);
        }
        assert(());
    }
    assert(child._layerHandle.layer is OffsetLayer);
    OffsetLayer childOffsetLayer = (;
    childOffsetLayer.offset = offset;
    appendLayer(childOffsetLayer);
}

bool PaintingContext::_isRecording() {
    bool hasCanvas = _canvas != nullptr;
    assert(());
    return hasCanvas;
}

void PaintingContext::_startRecording() {
    assert(!_isRecording);
    _currentLayer = PictureLayer(estimatedBounds);
    _recorder = ui.PictureRecorder();
    _canvas = Canvas(_recorder!);
    _containerLayer.append(_currentLayer!);
}

bool Constraints::debugAssertIsValid(InformationCollector informationCollector, bool isAppliedConstraint) {
    assert(isNormalized);
    return isNormalized;
}

void SemanticsHandle::dispose() {
    if (listener != nullptr) {
        _owner.semanticsOwner!.removeListener(listener!);
    }
    _owner._didDisposeSemanticsHandle();
}

void SemanticsHandle::_(VoidCallback listener, PipelineOwner owner) {
    if (listener != nullptr) {
        _owner.semanticsOwner!.addListener(listener!);
    }
}

void PipelineOwner::requestVisualUpdate() {
    onNeedVisualUpdate?.call();
}

AbstractNode PipelineOwner::rootNode() {
    return _rootNode;
}

void PipelineOwner::rootNode(AbstractNode value) {
    if (_rootNode == value) {
        return;
    }
    _rootNode?.detach();
    _rootNode = value;
    _rootNode?.attach(this);
}

bool PipelineOwner::debugDoingLayout() {
    return _debugDoingLayout;
}

void PipelineOwner::flushLayout() {
    if (!kReleaseMode) {
        Map<String, String> debugTimelineArguments;
        assert(());
        Timeline.startSync("LAYOUT"debugTimelineArguments);
    }
    assert(());
    ;
}

void PipelineOwner::flushCompositingBits() {
    if (!kReleaseMode) {
        Timeline.startSync("UPDATING COMPOSITING BITS");
    }
    _nodesNeedingCompositingBitsUpdate.sort();
    for (RenderObject node : _nodesNeedingCompositingBitsUpdate) {
        if (node._needsCompositingBitsUpdate && node.owner == this) {
            node._updateCompositingBits();
        }
    }
    _nodesNeedingCompositingBitsUpdate.clear();
    if (!kReleaseMode) {
        Timeline.finishSync();
    }
}

bool PipelineOwner::debugDoingPaint() {
    return _debugDoingPaint;
}

void PipelineOwner::flushPaint() {
    if (!kReleaseMode) {
        Map<String, String> debugTimelineArguments;
        assert(());
        Timeline.startSync("PAINT"debugTimelineArguments);
    }
    ;
}

SemanticsOwner PipelineOwner::semanticsOwner() {
    return _semanticsOwner;
}

int PipelineOwner::debugOutstandingSemanticsHandles() {
    return _outstandingSemanticsHandles;
}

SemanticsHandle PipelineOwner::ensureSemantics(VoidCallback listener) {
    _outstandingSemanticsHandles = 1;
    if (_outstandingSemanticsHandles == 1) {
        assert(_semanticsOwner == nullptr);
        _semanticsOwner = SemanticsOwner();
        onSemanticsOwnerCreated?.call();
    }
    return SemanticsHandle._(this, listener);
}

void PipelineOwner::flushSemantics() {
    if (_semanticsOwner == nullptr) {
        return;
    }
    if (!kReleaseMode) {
        Timeline.startSync("SEMANTICS");
    }
    assert(_semanticsOwner != nullptr);
    assert(());
    ;
}

void PipelineOwner::_enableMutationsToDirtySubtrees(VoidCallback callback) {
    assert(_debugDoingLayout);
    bool oldState;
    assert(());
    ;
}

void PipelineOwner::_didDisposeSemanticsHandle() {
    assert(_semanticsOwner != nullptr);
    _outstandingSemanticsHandles = 1;
    if (_outstandingSemanticsHandles == 0) {
        _semanticsOwner!.dispose();
        _semanticsOwner = nullptr;
        onSemanticsOwnerDisposed?.call();
    }
}

RenderObject::RenderObject() {
    {
        _needsCompositing = isRepaintBoundary || alwaysNeedsCompositing;
        _wasRepaintBoundary = isRepaintBoundary;
    }
}

void RenderObject::reassemble() {
    markNeedsLayout();
    markNeedsCompositingBitsUpdate();
    markNeedsPaint();
    markNeedsSemanticsUpdate();
    visitChildren();
}

bool RenderObject::debugDisposed() {
    bool disposed;
    assert(());
    return disposed;
}

void RenderObject::dispose() {
    assert(!_debugDisposed);
    _layerHandle.layer = nullptr;
    assert(());
}

void RenderObject::setupParentData(RenderObject child) {
    assert(_debugCanPerformMutations);
    if (child.parentData is! ParentData) {
        child.parentData = ParentData();
    }
}

void RenderObject::adoptChild(RenderObject child) {
    assert(_debugCanPerformMutations);
    assert(child != nullptr);
    setupParentData(child);
    markNeedsLayout();
    markNeedsCompositingBitsUpdate();
    markNeedsSemanticsUpdate();
    super.adoptChild(child);
}

void RenderObject::dropChild(RenderObject child) {
    assert(_debugCanPerformMutations);
    assert(child != nullptr);
    assert(child.parentData != nullptr);
    child._cleanRelayoutBoundary();
    child.parentData!.detach();
    child.parentData = nullptr;
    super.dropChild(child);
    markNeedsLayout();
    markNeedsCompositingBitsUpdate();
    markNeedsSemanticsUpdate();
}

void RenderObject::visitChildren(RenderObjectVisitor visitor) {
}

bool RenderObject::debugDoingThisResize() {
    return _debugDoingThisResize;
}

bool RenderObject::debugDoingThisLayout() {
    return _debugDoingThisLayout;
}

RenderObject RenderObject::debugActiveLayout() {
    return _debugActiveLayout;
}

bool RenderObject::debugCanParentUseSize() {
    return _debugCanParentUseSize!;
}

PipelineOwner RenderObject::owner() {
    return (;
}

void RenderObject::attach(PipelineOwner owner) {
    assert(!_debugDisposed);
    super.attach(owner);
    if (_needsLayout && _relayoutBoundary != nullptr) {
        _needsLayout = false;
        markNeedsLayout();
    }
    if (_needsCompositingBitsUpdate) {
        _needsCompositingBitsUpdate = false;
        markNeedsCompositingBitsUpdate();
    }
    if (_needsPaint && _layerHandle.layer != nullptr) {
        _needsPaint = false;
        markNeedsPaint();
    }
    if (_needsSemanticsUpdate && _semanticsConfiguration.isSemanticBoundary) {
        _needsSemanticsUpdate = false;
        markNeedsSemanticsUpdate();
    }
}

bool RenderObject::debugNeedsLayout() {
    bool result;
    assert(());
    return result;
}

bool RenderObject::debugDoingThisLayoutWithCallback() {
    return _doingThisLayoutWithCallback;
}

Constraints RenderObject::constraints() {
    if (_constraints == nullptr) {
        ;
    }
    return _constraints!;
}

void RenderObject::markNeedsLayout() {
    assert(_debugCanPerformMutations);
    if (_needsLayout) {
        assert(_debugSubtreeRelayoutRootAlreadyMarkedNeedsLayout());
        return;
    }
    if (_relayoutBoundary == nullptr) {
        _needsLayout = true;
        if (parent != nullptr) {
            markParentNeedsLayout();
        }
        return;
    }
    if (_relayoutBoundary != this) {
        markParentNeedsLayout();
    } else {
        _needsLayout = true;
        if (owner != nullptr) {
            assert(());
            owner!._nodesNeedingLayout.add(this);
            owner!.requestVisualUpdate();
        }
    }
}

void RenderObject::markParentNeedsLayout() {
    assert(_debugCanPerformMutations);
    _needsLayout = true;
    assert(this.parent != nullptr);
    RenderObject parent = (;
    if (!_doingThisLayoutWithCallback) {
        parent.markNeedsLayout();
    } else {
        assert(parent._debugDoingThisLayout);
    }
    assert(parent == this.parent);
}

void RenderObject::markNeedsLayoutForSizedByParentChange() {
    markNeedsLayout();
    markParentNeedsLayout();
}

void RenderObject::scheduleInitialLayout() {
    assert(!_debugDisposed);
    assert(attached);
    assert(parent is! RenderObject);
    assert(!owner!._debugDoingLayout);
    assert(_relayoutBoundary == nullptr);
    _relayoutBoundary = this;
    assert(());
    owner!._nodesNeedingLayout.add(this);
}

void RenderObject::layout(Constraints constraints, bool parentUsesSize) {
    assert(!_debugDisposed);
    if (!kReleaseMode && debugProfileLayoutsEnabled) {
        Map<String, String> debugTimelineArguments;
        assert(());
        Timeline.startSync("$runtimeType"debugTimelineArguments);
    }
    assert(constraints != nullptr);
    assert(constraints.debugAssertIsValid(true, ));
    assert(!_debugDoingThisResize);
    assert(!_debugDoingThisLayout);
    bool isRelayoutBoundary = !parentUsesSize || sizedByParent || constraints.isTight || parent is! RenderObject;
    RenderObject relayoutBoundary = isRelayoutBoundary? this : (()._relayoutBoundary!;
    assert(());
    if (!_needsLayout && constraints == _constraints) {
        assert(());
        if (relayoutBoundary != _relayoutBoundary) {
            _relayoutBoundary = relayoutBoundary;
            visitChildren(_propagateRelayoutBoundaryToChild);
        }
        if (!kReleaseMode && debugProfileLayoutsEnabled) {
            Timeline.finishSync();
        }
        return;
    }
    _constraints = constraints;
    if (_relayoutBoundary != nullptr && relayoutBoundary != _relayoutBoundary) {
        visitChildren(_cleanChildRelayoutBoundary);
    }
    _relayoutBoundary = relayoutBoundary;
    assert(!_debugMutationsLocked);
    assert(!_doingThisLayoutWithCallback);
    assert(());
    if (sizedByParent) {
        assert(());
        ;
        assert(());
    }
    RenderObject debugPreviousActiveLayout;
    assert(());
    ;
    assert(());
    _needsLayout = false;
    markNeedsPaint();
    if (!kReleaseMode && debugProfileLayoutsEnabled) {
        Timeline.finishSync();
    }
}

void RenderObject::debugResetSize() {
}

bool RenderObject::sizedByParent() {
    return false;
}

void RenderObject::invokeLayoutCallback<T extends Constraints>(LayoutCallback<T> callback) {
    assert(_debugMutationsLocked);
    assert(_debugDoingThisLayout);
    assert(!_doingThisLayoutWithCallback);
    _doingThisLayoutWithCallback = true;
    ;
}

bool RenderObject::debugDoingThisPaint() {
    return _debugDoingThisPaint;
}

RenderObject RenderObject::debugActivePaint() {
    return _debugActivePaint;
}

bool RenderObject::isRepaintBoundary() {
    return false;
}

void RenderObject::debugRegisterRepaintBoundaryPaint(bool includedChild, bool includedParent) {
}

bool RenderObject::alwaysNeedsCompositing() {
    return false;
}

OffsetLayer RenderObject::updateCompositedLayer(OffsetLayer oldLayer) {
    assert(isRepaintBoundary);
    return oldLayer ?? OffsetLayer();
}

ContainerLayer RenderObject::layer() {
    assert(!isRepaintBoundary || _layerHandle.layer == nullptr || _layerHandle.layer is OffsetLayer);
    return _layerHandle.layer;
}

void RenderObject::layer(ContainerLayer newLayer) {
    assert(!isRepaintBoundary, "Attempted to set a layer to a repaint boundary render object.\nThe framework creates and assigns an OffsetLayer to a repaint boundary automatically.");
    _layerHandle.layer = newLayer;
}

ContainerLayer RenderObject::debugLayer() {
    ContainerLayer result;
    assert(());
    return result;
}

void RenderObject::markNeedsCompositingBitsUpdate() {
    assert(!_debugDisposed);
    if (_needsCompositingBitsUpdate) {
        return;
    }
    _needsCompositingBitsUpdate = true;
    if (parent is RenderObject) {
        RenderObject parent = (;
        if (parent._needsCompositingBitsUpdate) {
            return;
        }
        if ((!_wasRepaintBoundary || !isRepaintBoundary) && !parent.isRepaintBoundary) {
            parent.markNeedsCompositingBitsUpdate();
            return;
        }
    }
    if (owner != nullptr) {
        owner!._nodesNeedingCompositingBitsUpdate.add(this);
    }
}

bool RenderObject::needsCompositing() {
    assert(!_needsCompositingBitsUpdate);
    return _needsCompositing;
}

bool RenderObject::debugNeedsPaint() {
    bool result;
    assert(());
    return result;
}

bool RenderObject::debugNeedsCompositedLayerUpdate() {
    bool result;
    assert(());
    return result;
}

void RenderObject::markNeedsPaint() {
    assert(!_debugDisposed);
    assert(owner == nullptr || !owner!.debugDoingPaint);
    if (_needsPaint) {
        return;
    }
    _needsPaint = true;
    if (isRepaintBoundary && _wasRepaintBoundary) {
        assert(());
        assert(_layerHandle.layer is OffsetLayer);
        if (owner != nullptr) {
            owner!._nodesNeedingPaint.add(this);
            owner!.requestVisualUpdate();
        }
    } else     {
        if (parent is RenderObject) {
        RenderObject parent = (;
        parent.markNeedsPaint();
        assert(parent == this.parent);
    } else {
        assert(());
        if (owner != nullptr) {
            owner!.requestVisualUpdate();
        }
    }
;
    }}

void RenderObject::markNeedsCompositedLayerUpdate() {
    assert(!_debugDisposed);
    assert(owner == nullptr || !owner!.debugDoingPaint);
    if (_needsCompositedLayerUpdate || _needsPaint) {
        return;
    }
    _needsCompositedLayerUpdate = true;
    if (isRepaintBoundary && _wasRepaintBoundary) {
        assert(_layerHandle.layer != nullptr);
        if (owner != nullptr) {
            owner!._nodesNeedingPaint.add(this);
            owner!.requestVisualUpdate();
        }
    } else {
        markNeedsPaint();
    }
}

void RenderObject::scheduleInitialPaint(ContainerLayer rootLayer) {
    assert(rootLayer.attached);
    assert(attached);
    assert(parent is! RenderObject);
    assert(!owner!._debugDoingPaint);
    assert(isRepaintBoundary);
    assert(_layerHandle.layer == nullptr);
    _layerHandle.layer = rootLayer;
    assert(_needsPaint);
    owner!._nodesNeedingPaint.add(this);
}

void RenderObject::replaceRootLayer(OffsetLayer rootLayer) {
    assert(!_debugDisposed);
    assert(rootLayer.attached);
    assert(attached);
    assert(parent is! RenderObject);
    assert(!owner!._debugDoingPaint);
    assert(isRepaintBoundary);
    assert(_layerHandle.layer != nullptr);
    _layerHandle.layer!.detach();
    _layerHandle.layer = rootLayer;
    markNeedsPaint();
}

void RenderObject::debugPaint(PaintingContext context, Offset offset) {
}

void RenderObject::paint(PaintingContext context, Offset offset) {
}

void RenderObject::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(child.parent == this);
}

bool RenderObject::paintsChild(RenderObject child) {
    assert(child.parent == this);
    return true;
}

Matrix4 RenderObject::getTransformTo(RenderObject ancestor) {
    bool ancestorSpecified = ancestor != nullptr;
    assert(attached);
    if (ancestor == nullptr) {
        AbstractNode rootNode = owner!.rootNode;
        if (rootNode is RenderObject) {
            ancestor = rootNode;
        }
    }
    List<RenderObject> renderers = ;
    for (; renderer != ancestor; renderer = () {
        renderers.add(renderer);
        assert(renderer.parent != nullptr);
    }
    if (ancestorSpecified) {
        renderers.add(ancestor!);
    }
    Matrix4 transform = Matrix4.identity();
    for (; index > 0; index = 1) {
        renderers[index].applyPaintTransform(renderers[index - 1], transform);
    }
    return transform;
}

Rect RenderObject::describeApproximatePaintClip(RenderObject child) {
    return nullptr;
}

Rect RenderObject::describeSemanticsClip(RenderObject child) {
    return nullptr;
}

void RenderObject::scheduleInitialSemantics() {
    assert(!_debugDisposed);
    assert(attached);
    assert(parent is! RenderObject);
    assert(!owner!._debugDoingSemantics);
    assert(_semantics == nullptr);
    assert(_needsSemanticsUpdate);
    assert(owner!._semanticsOwner != nullptr);
    owner!._nodesNeedingSemantics.add(this);
    owner!.requestVisualUpdate();
}

void RenderObject::describeSemanticsConfiguration(SemanticsConfiguration config) {
}

void RenderObject::sendSemanticsEvent(SemanticsEvent semanticsEvent) {
    if (owner!.semanticsOwner == nullptr) {
        return;
    }
    if (_semantics != nullptr && !_semantics!.isMergedIntoParent) {
        _semantics!.sendEvent(semanticsEvent);
    } else     {
        if (parent != nullptr) {
        RenderObject renderParent = (;
        renderParent.sendSemanticsEvent(semanticsEvent);
    }
;
    }}

SemanticsNode RenderObject::debugSemantics() {
    if (!kReleaseMode) {
        return _semantics;
    }
    return nullptr;
}

void RenderObject::clearSemantics() {
    _needsSemanticsUpdate = true;
    _semantics = nullptr;
    visitChildren();
}

void RenderObject::markNeedsSemanticsUpdate() {
    assert(!_debugDisposed);
    assert(!attached || !owner!._debugDoingSemantics);
    if (!attached || owner!._semanticsOwner == nullptr) {
        _cachedSemanticsConfiguration = nullptr;
        return;
    }
    bool wasSemanticsBoundary = _semantics != nullptr && (_cachedSemanticsConfiguration?.isSemanticBoundary ?? false);
    _cachedSemanticsConfiguration = nullptr;
    bool isEffectiveSemanticsBoundary = _semanticsConfiguration.isSemanticBoundary && wasSemanticsBoundary;
    RenderObject node = this;
    while (!isEffectiveSemanticsBoundary && node.parent is RenderObject) {
        if (node != this && node._needsSemanticsUpdate) {
                        break;
        }
        node._needsSemanticsUpdate = true;
        node = (;
        isEffectiveSemanticsBoundary = node._semanticsConfiguration.isSemanticBoundary;
        if (isEffectiveSemanticsBoundary && node._semantics == nullptr) {
            return;
        }
    }
    if (node != this && _semantics != nullptr && _needsSemanticsUpdate) {
        owner!._nodesNeedingSemantics.remove(this);
    }
    if (!node._needsSemanticsUpdate) {
        node._needsSemanticsUpdate = true;
        if (owner != nullptr) {
            assert(node._semanticsConfiguration.isSemanticBoundary || node.parent is! RenderObject);
            owner!._nodesNeedingSemantics.add(node);
            owner!.requestVisualUpdate();
        }
    }
}

void RenderObject::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    visitChildren(visitor);
}

void RenderObject::assembleSemanticsNode(Iterable<SemanticsNode> children, SemanticsConfiguration config, SemanticsNode node) {
    assert(node == _semantics);
    node.updateWith(config, ();
}

void RenderObject::handleEvent(HitTestEntry entry, PointerEvent event) {
}

String RenderObject::toStringShort() {
    String header = describeIdentity(this);
    if (!kReleaseMode) {
        if (_debugDisposed) {
            header = " DISPOSED";
            return header;
        }
        if (_relayoutBoundary != nullptr && _relayoutBoundary != this) {
            int count = 1;
            RenderObject target = (;
            while (target != nullptr && target != _relayoutBoundary) {
                target = (;
                count = 1;
            }
            header = " relayoutBoundary=up$count";
        }
        if (_needsLayout) {
            header = " NEEDS-LAYOUT";
        }
        if (_needsPaint) {
            header = " NEEDS-PAINT";
        }
        if (_needsCompositingBitsUpdate) {
            header = " NEEDS-COMPOSITING-BITS-UPDATE";
        }
        if (!attached) {
            header = " DETACHED";
        }
    }
    return header;
}

String RenderObject::toString(DiagnosticLevel minLevel) {
    return toStringShort();
}

String RenderObject::toStringDeep(DiagnosticLevel minLevel, String prefixLineOne, String prefixOtherLines) {
    RenderObject debugPreviousActiveLayout;
    assert(());
    String result = super.toStringDeep(prefixLineOne, prefixOtherLines, minLevel);
    assert(());
    return result;
}

String RenderObject::toStringShallow(String joiner, DiagnosticLevel minLevel) {
    RenderObject debugPreviousActiveLayout;
    assert(());
    String result = super.toStringShallow(joiner, minLevel);
    assert(());
    return result;
}

void RenderObject::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(FlagProperty("needsCompositing"_needsCompositing, "needs compositing"));
    properties.add(<Object>DiagnosticsProperty("creator", debugCreatornullptr, DiagnosticLevel.debug));
    properties.add(<ParentData>DiagnosticsProperty("parentData", parentData(_debugCanParentUseSize ?? false)? "can use size" : nullptr, true));
    properties.add(<Constraints>DiagnosticsProperty("constraints", _constraintstrue));
    properties.add(<ContainerLayer>DiagnosticsProperty("layer", _layerHandle.layernullptr));
    properties.add(<SemanticsNode>DiagnosticsProperty("semantics node", _semanticsnullptr));
    properties.add(FlagProperty("isBlockingSemanticsOfPreviouslyPaintedNodes"_semanticsConfiguration.isBlockingSemanticsOfPreviouslyPaintedNodes, "blocks semantics of earlier render objects below the common boundary"));
    properties.add(FlagProperty("isSemanticBoundary"_semanticsConfiguration.isSemanticBoundary, "semantic boundary"));
}

List<DiagnosticsNode> RenderObject::debugDescribeChildren() {
    return ;
}

void RenderObject::showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect) {
    if (parent is RenderObject) {
        RenderObject renderParent = (;
        renderParent.showOnScreen(descendant ?? this, rect, duration, curve);
    }
}

DiagnosticsNode RenderObject::describeForError(String name, DiagnosticsTreeStyle style) {
    return toDiagnosticsNode(name, style);
}

void RenderObject::_debugReportException(Object exception, String method, StackTrace stack) {
    FlutterError.reportError(FlutterErrorDetails(exception, stack, "rendering library", ErrorDescription("during $method()"), ));
}

bool RenderObject::_debugCanPerformMutations() {
    bool result;
    assert(());
    return result;
}

bool RenderObject::_debugSubtreeRelayoutRootAlreadyMarkedNeedsLayout() {
    if (_relayoutBoundary == nullptr) {
        return true;
    }
    RenderObject node = this;
    while (node != _relayoutBoundary) {
        assert(node._relayoutBoundary == _relayoutBoundary);
        assert(node.parent != nullptr);
        node = (;
        if ((!node._needsLayout) && (!node._debugDoingThisLayout)) {
            return false;
        }
    }
    assert(node._relayoutBoundary == node);
    return true;
}

void RenderObject::_cleanRelayoutBoundary() {
    if (_relayoutBoundary != this) {
        _relayoutBoundary = nullptr;
        visitChildren(_cleanChildRelayoutBoundary);
    }
}

void RenderObject::_propagateRelayoutBoundary() {
    if (_relayoutBoundary == this) {
        return;
    }
    RenderObject parentRelayoutBoundary = (()?._relayoutBoundary;
    assert(parentRelayoutBoundary != nullptr);
    if (parentRelayoutBoundary != _relayoutBoundary) {
        _relayoutBoundary = parentRelayoutBoundary;
        visitChildren(_propagateRelayoutBoundaryToChild);
    }
}

void RenderObject::_cleanChildRelayoutBoundary(RenderObject child) {
    child._cleanRelayoutBoundary();
}

void RenderObject::_propagateRelayoutBoundaryToChild(RenderObject child) {
    child._propagateRelayoutBoundary();
}

void RenderObject::_layoutWithoutResize() {
    assert(_relayoutBoundary == this);
    RenderObject debugPreviousActiveLayout;
    assert(!_debugMutationsLocked);
    assert(!_doingThisLayoutWithCallback);
    assert(_debugCanParentUseSize != nullptr);
    assert(());
    ;
    assert(());
    _needsLayout = false;
    markNeedsPaint();
}

void RenderObject::_updateCompositingBits() {
    if (!_needsCompositingBitsUpdate) {
        return;
    }
    bool oldNeedsCompositing = _needsCompositing;
    _needsCompositing = false;
    visitChildren();
    if (isRepaintBoundary || alwaysNeedsCompositing) {
        _needsCompositing = true;
    }
    if (!isRepaintBoundary && _wasRepaintBoundary) {
        _needsPaint = false;
        _needsCompositedLayerUpdate = false;
        owner?._nodesNeedingPaint.remove(this);
        _needsCompositingBitsUpdate = false;
        markNeedsPaint();
    } else     {
        if (oldNeedsCompositing != _needsCompositing) {
        _needsCompositingBitsUpdate = false;
        markNeedsPaint();
    } else {
        _needsCompositingBitsUpdate = false;
    }
;
    }}

void RenderObject::_skippedPaintingOnLayer() {
    assert(attached);
    assert(isRepaintBoundary);
    assert(_needsPaint || _needsCompositedLayerUpdate);
    assert(_layerHandle.layer != nullptr);
    assert(!_layerHandle.layer!.attached);
    AbstractNode node = parent;
    while (node is RenderObject) {
        if (node.isRepaintBoundary) {
            if (node._layerHandle.layer == nullptr) {
                                break;
            }
            if (node._layerHandle.layer!.attached) {
                                break;
            }
            node._needsPaint = true;
        }
        node = node.parent;
    }
}

void RenderObject::_paintWithContext(PaintingContext context, Offset offset) {
    assert(!_debugDisposed);
    assert(());
    if (_needsLayout) {
        return;
    }
    if (!kReleaseMode && debugProfilePaintsEnabled) {
        Map<String, String> debugTimelineArguments;
        assert(());
        Timeline.startSync("$runtimeType"debugTimelineArguments);
    }
    assert(());
    RenderObject debugLastActivePaint;
    assert(());
    _needsPaint = false;
    _needsCompositedLayerUpdate = false;
    _wasRepaintBoundary = isRepaintBoundary;
    ;
    assert(());
    if (!kReleaseMode && debugProfilePaintsEnabled) {
        Timeline.finishSync();
    }
}

SemanticsConfiguration RenderObject::_semanticsConfiguration() {
    if (_cachedSemanticsConfiguration == nullptr) {
        _cachedSemanticsConfiguration = SemanticsConfiguration();
        describeSemanticsConfiguration(_cachedSemanticsConfiguration!);
    }
    return _cachedSemanticsConfiguration!;
}

void RenderObject::_updateSemantics() {
    assert(_semanticsConfiguration.isSemanticBoundary || parent is! RenderObject);
    if (_needsLayout) {
        return;
    }
    _SemanticsFragment fragment = _getSemanticsForParent(_semantics?.parent?.isPartOfNodeMerging ?? false);
    assert(fragment is _InterestingSemanticsFragment);
    _InterestingSemanticsFragment interestingFragment = (;
    List<SemanticsNode> result = ;
    interestingFragment.compileChildren(_semantics?.parentSemanticsClipRect, _semantics?.parentPaintClipRect, _semantics?.elevationAdjustment ?? 0.0, result);
    SemanticsNode node = result.single;
    assert(interestingFragment.config == nullptr && node == _semantics);
}

_SemanticsFragment RenderObject::_getSemanticsForParent(bool mergeIntoParent) {
    assert(mergeIntoParent != nullptr);
    assert(!_needsLayout, "Updated layout information required for $this to calculate semantics.");
    SemanticsConfiguration config = _semanticsConfiguration;
    bool dropSemanticsOfPreviousSiblings = config.isBlockingSemanticsOfPreviouslyPaintedNodes;
    bool producesForkingFragment = !config.hasBeenAnnotated && !config.isSemanticBoundary;
    List<_InterestingSemanticsFragment> fragments = ;
    Set<_InterestingSemanticsFragment> toBeMarkedExplicit = ;
    bool childrenMergeIntoParent = mergeIntoParent || config.isMergingSemanticsOfDescendants;
    visitChildrenForSemantics();
    for (_InterestingSemanticsFragment fragment : toBeMarkedExplicit) {
        fragment.markAsExplicit();
    }
    _needsSemanticsUpdate = false;
    _SemanticsFragment result;
    if (parent is! RenderObject) {
        assert(!config.hasBeenAnnotated);
        assert(!mergeIntoParent);
        result = _RootSemanticsFragment(this, dropSemanticsOfPreviousSiblings);
    } else     {
        if (producesForkingFragment) {
        result = _ContainerSemanticsFragment(dropSemanticsOfPreviousSiblings);
    } else {
        result = _SwitchableSemanticsFragment(config, mergeIntoParent, this, dropSemanticsOfPreviousSiblings);
        if (config.isSemanticBoundary) {
            _SwitchableSemanticsFragment fragment = (;
            fragment.markAsExplicit();
        }
    }
;
    }    result.addAll(fragments);
    return result;
}

bool RenderObjectWithChildMixin::debugValidateChild(RenderObject child) {
    assert(());
    return true;
}

ChildType RenderObjectWithChildMixin::child() {
    return _child;
}

void RenderObjectWithChildMixin::child(ChildType value) {
    if (_child != nullptr) {
        dropChild(_child!);
    }
    _child = value;
    if (_child != nullptr) {
        adoptChild(_child!);
    }
}

void RenderObjectWithChildMixin::attach(PipelineOwner owner) {
    super.attach(owner);
    if (_child != nullptr) {
        _child!.attach(owner);
    }
}

void RenderObjectWithChildMixin::detach() {
    super.detach();
    if (_child != nullptr) {
        _child!.detach();
    }
}

void RenderObjectWithChildMixin::redepthChildren() {
    if (_child != nullptr) {
        redepthChild(_child!);
    }
}

void RenderObjectWithChildMixin::visitChildren(RenderObjectVisitor visitor) {
    if (_child != nullptr) {
        visitor(_child!);
    }
}

List<DiagnosticsNode> RenderObjectWithChildMixin::debugDescribeChildren() {
    return child != nullptr?  : ;
}

void ContainerParentDataMixin::detach() {
    assert(previousSibling == nullptr, "Pointers to siblings must be nulled before detaching ParentData.");
    assert(nextSibling == nullptr, "Pointers to siblings must be nulled before detaching ParentData.");
    super.detach();
}

int ContainerRenderObjectMixin::childCount() {
    return _childCount;
}

bool ContainerRenderObjectMixin::debugValidateChild(RenderObject child) {
    assert(());
    return true;
}

void ContainerRenderObjectMixin::insert(ChildType after, ChildType child) {
    assert(child != this, "A RenderObject cannot be inserted into itself.");
    assert(after != this, "A RenderObject cannot simultaneously be both the parent and the sibling of another RenderObject.");
    assert(child != after, "A RenderObject cannot be inserted after itself.");
    assert(child != _firstChild);
    assert(child != _lastChild);
    adoptChild(child);
    _insertIntoChildList(childafter);
}

void ContainerRenderObjectMixin::add(ChildType child) {
    insert(child_lastChild);
}

void ContainerRenderObjectMixin::addAll(List<ChildType> children) {
    children?.forEach(add);
}

void ContainerRenderObjectMixin::remove(ChildType child) {
    _removeFromChildList(child);
    dropChild(child);
}

void ContainerRenderObjectMixin::removeAll() {
    ChildType child = _firstChild;
    while (child != nullptr) {
        ParentDataType childParentData = (;
        ChildType next = childParentData.nextSibling;
        childParentData.previousSibling = nullptr;
        childParentData.nextSibling = nullptr;
        dropChild(child);
        child = next;
    }
    _firstChild = nullptr;
    _lastChild = nullptr;
    _childCount = 0;
}

void ContainerRenderObjectMixin::move(ChildType after, ChildType child) {
    assert(child != this);
    assert(after != this);
    assert(child != after);
    assert(child.parent == this);
    ParentDataType childParentData = (;
    if (childParentData.previousSibling == after) {
        return;
    }
    _removeFromChildList(child);
    _insertIntoChildList(childafter);
    markNeedsLayout();
}

void ContainerRenderObjectMixin::attach(PipelineOwner owner) {
    super.attach(owner);
    ChildType child = _firstChild;
    while (child != nullptr) {
        child.attach(owner);
        ParentDataType childParentData = (;
        child = childParentData.nextSibling;
    }
}

void ContainerRenderObjectMixin::detach() {
    super.detach();
    ChildType child = _firstChild;
    while (child != nullptr) {
        child.detach();
        ParentDataType childParentData = (;
        child = childParentData.nextSibling;
    }
}

void ContainerRenderObjectMixin::redepthChildren() {
    ChildType child = _firstChild;
    while (child != nullptr) {
        redepthChild(child);
        ParentDataType childParentData = (;
        child = childParentData.nextSibling;
    }
}

void ContainerRenderObjectMixin::visitChildren(RenderObjectVisitor visitor) {
    ChildType child = _firstChild;
    while (child != nullptr) {
        visitor(child);
        ParentDataType childParentData = (;
        child = childParentData.nextSibling;
    }
}

ChildType ContainerRenderObjectMixin::firstChild() {
    return _firstChild;
}

ChildType ContainerRenderObjectMixin::lastChild() {
    return _lastChild;
}

ChildType ContainerRenderObjectMixin::childBefore(ChildType child) {
    assert(child != nullptr);
    assert(child.parent == this);
    ParentDataType childParentData = (;
    return childParentData.previousSibling;
}

ChildType ContainerRenderObjectMixin::childAfter(ChildType child) {
    assert(child != nullptr);
    assert(child.parent == this);
    ParentDataType childParentData = (;
    return childParentData.nextSibling;
}

List<DiagnosticsNode> ContainerRenderObjectMixin::debugDescribeChildren() {
    List<DiagnosticsNode> children = ;
    if (firstChild != nullptr) {
        ChildType child = firstChild!;
        int count = 1;
        while (true) {
            children.add(child.toDiagnosticsNode("child $count"));
            if (child == lastChild) {
                                break;
            }
            count = 1;
            ParentDataType childParentData = (;
            child = childParentData.nextSibling!;
        }
    }
    return children;
}

bool ContainerRenderObjectMixin::_debugUltimatePreviousSiblingOf(ChildType child, ChildType equals) {
    ParentDataType childParentData = (;
    while (childParentData.previousSibling != nullptr) {
        assert(childParentData.previousSibling != child);
        child = childParentData.previousSibling!;
        childParentData = (;
    }
    return child == equals;
}

bool ContainerRenderObjectMixin::_debugUltimateNextSiblingOf(ChildType child, ChildType equals) {
    ParentDataType childParentData = (;
    while (childParentData.nextSibling != nullptr) {
        assert(childParentData.nextSibling != child);
        child = childParentData.nextSibling!;
        childParentData = (;
    }
    return child == equals;
}

void ContainerRenderObjectMixin::_insertIntoChildList(ChildType after, ChildType child) {
    ParentDataType childParentData = (;
    assert(childParentData.nextSibling == nullptr);
    assert(childParentData.previousSibling == nullptr);
    _childCount = 1;
    assert(_childCount > 0);
    if (after == nullptr) {
        childParentData.nextSibling = _firstChild;
        if (_firstChild != nullptr) {
            ParentDataType firstChildParentData = (;
            firstChildParentData.previousSibling = child;
        }
        _firstChild = child;
        _lastChild = child;
    } else {
        assert(_firstChild != nullptr);
        assert(_lastChild != nullptr);
        assert(_debugUltimatePreviousSiblingOf(after_firstChild));
        assert(_debugUltimateNextSiblingOf(after_lastChild));
        ParentDataType afterParentData = (;
        if (afterParentData.nextSibling == nullptr) {
            assert(after == _lastChild);
            childParentData.previousSibling = after;
            afterParentData.nextSibling = child;
            _lastChild = child;
        } else {
            childParentData.nextSibling = afterParentData.nextSibling;
            childParentData.previousSibling = after;
            ParentDataType childPreviousSiblingParentData = (;
            ParentDataType childNextSiblingParentData = (;
            childPreviousSiblingParentData.nextSibling = child;
            childNextSiblingParentData.previousSibling = child;
            assert(afterParentData.nextSibling == child);
        }
    }
}

void ContainerRenderObjectMixin::_removeFromChildList(ChildType child) {
    ParentDataType childParentData = (;
    assert(_debugUltimatePreviousSiblingOf(child_firstChild));
    assert(_debugUltimateNextSiblingOf(child_lastChild));
    assert(_childCount >= 0);
    if (childParentData.previousSibling == nullptr) {
        assert(_firstChild == child);
        _firstChild = childParentData.nextSibling;
    } else {
        ParentDataType childPreviousSiblingParentData = (;
        childPreviousSiblingParentData.nextSibling = childParentData.nextSibling;
    }
    if (childParentData.nextSibling == nullptr) {
        assert(_lastChild == child);
        _lastChild = childParentData.previousSibling;
    } else {
        ParentDataType childNextSiblingParentData = (;
        childNextSiblingParentData.previousSibling = childParentData.previousSibling;
    }
    childParentData.previousSibling = nullptr;
    childParentData.nextSibling = nullptr;
    _childCount = 1;
}

void RelayoutWhenSystemFontsChangeMixin::systemFontsDidChange() {
    markNeedsLayout();
}

void RelayoutWhenSystemFontsChangeMixin::attach(PipelineOwner owner) {
    super.attach(owner);
    PaintingBinding.instance.systemFonts.addListener(systemFontsDidChange);
}

void RelayoutWhenSystemFontsChangeMixin::detach() {
    PaintingBinding.instance.systemFonts.removeListener(systemFontsDidChange);
    super.detach();
}

_SemanticsFragment::_SemanticsFragment(bool dropsSemanticsOfPreviousSiblings) {
    {
        assert(dropsSemanticsOfPreviousSiblings != nullptr);
    }
}

void _ContainerSemanticsFragment::addAll(Iterable<_InterestingSemanticsFragment> fragments) {
    interestingFragments.addAll(fragments);
}

RenderObject _InterestingSemanticsFragment::owner() {
    return _ancestorChain.first;
}

bool _InterestingSemanticsFragment::hasConfigForParent() {
    return config != nullptr;
}

List<_InterestingSemanticsFragment> _InterestingSemanticsFragment::interestingFragments() {
    return ;
}

void _InterestingSemanticsFragment::addTags(Iterable<SemanticsTag> tags) {
    if (tags == nullptr || tags.isEmpty) {
        return;
    }
    _tagsForChildren = ;
    _tagsForChildren!.addAll(tags);
}

void _InterestingSemanticsFragment::addAncestor(RenderObject ancestor) {
    _ancestorChain.add(ancestor);
}

_InterestingSemanticsFragment::_InterestingSemanticsFragment(Unknown, RenderObject owner) {
    {
        assert(owner != nullptr);
        _ancestorChain = ;
    }
}

void _RootSemanticsFragment::compileChildren(double elevationAdjustment, Rect parentPaintClipRect, Rect parentSemanticsClipRect, List<SemanticsNode> result) {
    assert(_tagsForChildren == nullptr || _tagsForChildren!.isEmpty);
    assert(parentSemanticsClipRect == nullptr);
    assert(parentPaintClipRect == nullptr);
    assert(_ancestorChain.length == 1);
    assert(elevationAdjustment == 0.0);
    owner._semantics = SemanticsNode.root(owner.showOnScreen, owner.owner!.semanticsOwner!);
    SemanticsNode node = owner._semantics!;
    assert(MatrixUtils.matrixEquals(node.transform, Matrix4.identity()));
    assert(node.parentSemanticsClipRect == nullptr);
    assert(node.parentPaintClipRect == nullptr);
    node.rect = owner.semanticBounds;
    List<SemanticsNode> children = ;
    for (_InterestingSemanticsFragment fragment : _children) {
        assert(fragment.config == nullptr);
        fragment.compileChildren(parentSemanticsClipRect, parentPaintClipRect, 0.0, children);
    }
    node.updateWith(nullptr, children);
    assert(!node.isInvisible || children.isEmpty);
    result.add(node);
}

SemanticsConfiguration _RootSemanticsFragment::config() {
    return nullptr;
}

void _RootSemanticsFragment::markAsExplicit() {
}

void _RootSemanticsFragment::addAll(Iterable<_InterestingSemanticsFragment> fragments) {
    _children.addAll(fragments);
}

void _SwitchableSemanticsFragment::compileChildren(double elevationAdjustment, Rect parentPaintClipRect, Rect parentSemanticsClipRect, List<SemanticsNode> result) {
    if (!_isExplicit) {
        owner._semantics = nullptr;
        for (_InterestingSemanticsFragment fragment : _children) {
            assert(_ancestorChain.first == fragment._ancestorChain.last);
            fragment._ancestorChain.addAll(_ancestorChain.skip(1));
            fragment.compileChildren(parentSemanticsClipRect, parentPaintClipRect, elevationAdjustment + _config.elevation, result);
        }
        return;
    }
    _SemanticsGeometry geometry = _needsGeometryUpdate? _SemanticsGeometry(parentSemanticsClipRect, parentPaintClipRect, _ancestorChain) : nullptr;
    if (!_mergeIntoParent && (geometry?.dropFromTree ?? false)) {
        return;
    }
    owner._semantics = SemanticsNode(owner.showOnScreen);
    SemanticsNode node = ;
    node.elevationAdjustment = elevationAdjustment;
    if (elevationAdjustment != 0.0) {
        _ensureConfigIsWritable();
        _config.elevation = elevationAdjustment;
    }
    if (geometry != nullptr) {
        assert(_needsGeometryUpdate);
        ;
        if (!_mergeIntoParent && geometry.markAsHidden) {
            _ensureConfigIsWritable();
            _config.isHidden = true;
        }
    }
    List<SemanticsNode> children = ;
    for (_InterestingSemanticsFragment fragment : _children) {
        fragment.compileChildren(node.parentSemanticsClipRect, node.parentPaintClipRect, 0.0, children);
    }
    if (_config.isSemanticBoundary) {
        owner.assembleSemanticsNode(node, _config, children);
    } else {
        node.updateWith(_config, children);
    }
    result.add(node);
}

SemanticsConfiguration _SwitchableSemanticsFragment::config() {
    return _isExplicit? nullptr : _config;
}

void _SwitchableSemanticsFragment::addAll(Iterable<_InterestingSemanticsFragment> fragments) {
    for (_InterestingSemanticsFragment fragment : fragments) {
        _children.add(fragment);
        if (fragment.config == nullptr) {
            continue;
        }
        _ensureConfigIsWritable();
        _config.absorb(fragment.config!);
    }
}

void _SwitchableSemanticsFragment::markAsExplicit() {
    _isExplicit = true;
}

_SwitchableSemanticsFragment::_SwitchableSemanticsFragment(SemanticsConfiguration config, Unknown, bool mergeIntoParent, Unknown) {
    {
        _mergeIntoParent = mergeIntoParent;
        _config = config;
        assert(mergeIntoParent != nullptr);
        assert(config != nullptr);
    }
}

void _SwitchableSemanticsFragment::_ensureConfigIsWritable() {
    if (!_isConfigWritable) {
        _config = _config.copy();
        _isConfigWritable = true;
    }
}

bool _SwitchableSemanticsFragment::_needsGeometryUpdate() {
    return _ancestorChain.length > 1;
}

Matrix4 _SemanticsGeometry::transform() {
    return _transform;
}

Rect _SemanticsGeometry::semanticsClipRect() {
    return _semanticsClipRect;
}

Rect _SemanticsGeometry::paintClipRect() {
    return _paintClipRect;
}

Rect _SemanticsGeometry::rect() {
    return _rect;
}

bool _SemanticsGeometry::dropFromTree() {
    return _rect.isEmpty || _transform.isZero();
}

bool _SemanticsGeometry::markAsHidden() {
    return _markAsHidden;
}

_SemanticsGeometry::_SemanticsGeometry(List<RenderObject> ancestors, Rect parentPaintClipRect, Rect parentSemanticsClipRect) {
    {
        _computeValues(parentSemanticsClipRect, parentPaintClipRect, ancestors);
    }
}

void _SemanticsGeometry::_computeValues(List<RenderObject> ancestors, Rect parentPaintClipRect, Rect parentSemanticsClipRect) {
    assert(ancestors.length > 1);
    _transform = Matrix4.identity();
    _semanticsClipRect = parentSemanticsClipRect;
    _paintClipRect = parentPaintClipRect;
    for (; index > 0; index = 1) {
        RenderObject parent = ancestors[index];
        RenderObject child = ancestors[index - 1];
        Rect parentSemanticsClipRect = parent.describeSemanticsClip(child);
        if (parentSemanticsClipRect != nullptr) {
            _semanticsClipRect = parentSemanticsClipRect;
            _paintClipRect = _intersectRects(_paintClipRect, parent.describeApproximatePaintClip(child));
        } else {
            _semanticsClipRect = _intersectRects(_semanticsClipRect, parent.describeApproximatePaintClip(child));
        }
        _temporaryTransformHolder.setIdentity();
        _applyIntermediatePaintTransforms(parent, child, _transform, _temporaryTransformHolder);
        _semanticsClipRect = _transformRect(_semanticsClipRect, _temporaryTransformHolder);
        _paintClipRect = _transformRect(_paintClipRect, _temporaryTransformHolder);
    }
    RenderObject owner = ancestors.first;
    _rect = _semanticsClipRect == nullptr? owner.semanticBounds : _semanticsClipRect!.intersect(owner.semanticBounds);
    if (_paintClipRect != nullptr) {
        Rect paintRect = _paintClipRect!.intersect(_rect);
        _markAsHidden = paintRect.isEmpty && !_rect.isEmpty;
        if (!_markAsHidden) {
            _rect = paintRect;
        }
    }
}

Rect _SemanticsGeometry::_transformRect(Rect rect, Matrix4 transform) {
    assert(transform != nullptr);
    if (rect == nullptr) {
        return nullptr;
    }
    if (rect.isEmpty || transform.isZero()) {
        return Rect.zero;
    }
    return MatrixUtils.inverseTransformRect(transform, rect);
}

void _SemanticsGeometry::_applyIntermediatePaintTransforms(RenderObject ancestor, RenderObject child, Matrix4 clipRectTransform, Matrix4 transform) {
    assert(ancestor != nullptr);
    assert(child != nullptr);
    assert(transform != nullptr);
    assert(clipRectTransform != nullptr);
    assert(clipRectTransform.isIdentity());
    RenderObject intermediateParent = (;
    assert(intermediateParent != nullptr);
    while (intermediateParent != ancestor) {
        intermediateParent.applyPaintTransform(child, transform);
        intermediateParent = (;
        child = (;
        assert(intermediateParent != nullptr);
    }
    ancestor.applyPaintTransform(child, transform);
    ancestor.applyPaintTransform(child, clipRectTransform);
}

Rect _SemanticsGeometry::_intersectRects(Rect a, Rect b) {
    if (a == nullptr) {
        return b;
    }
    if (b == nullptr) {
        return a;
    }
    return a.intersect(b);
}

DiagnosticsDebugCreator::DiagnosticsDebugCreator(Object value) {
    {
        assert(value != nullptr);
        super("debugCreator", valueDiagnosticLevel.hidden);
    }
}
