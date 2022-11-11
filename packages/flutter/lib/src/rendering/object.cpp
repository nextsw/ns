#include "object.hpp"
void ParentDataCls::detach() {
}

String ParentDataCls::toString() {
    return __s("<none>");
}

PaintingContextCls::PaintingContextCls(ContainerLayer _containerLayer, Rect estimatedBounds) {
    {
        assert(_containerLayer != nullptr);
        assert(estimatedBounds != nullptr);
    }
}

void PaintingContextCls::repaintCompositedChild(RenderObject child, bool debugAlsoPaintedParent) {
    assert(child->_needsPaint);
    _repaintCompositedChild(child, debugAlsoPaintedParent);
}

void PaintingContextCls::updateLayerProperties(RenderObject child) {
    assert(child->isRepaintBoundary() && child->_wasRepaintBoundary);
    assert(!child->_needsPaint);
    assert(child->_layerHandle->layer() != nullptr);
    OffsetLayer childLayer = as<OffsetLayer>(child->_layerHandle->layer()!);
    Offset debugOldOffset;
    assert([=] () {
        debugOldOffset = childLayer->offset();
        return true;
    }());
    OffsetLayer updatedLayer = child->updateCompositedLayer(childLayer);
    assert(identical(updatedLayer, childLayer), __s("$child created a new layer instance $updatedLayer instead of reusing the existing layer $childLayer. See the documentation of RenderObject.updateCompositedLayer for more information on how to correctly implement this method."));
    assert(debugOldOffset == updatedLayer->offset());
    child->_needsCompositedLayerUpdate = false;
}

void PaintingContextCls::debugInstrumentRepaintCompositedChild(RenderObject child, PaintingContext customContext, bool debugAlsoPaintedParent) {
    assert([=] () {
        _repaintCompositedChild(child, debugAlsoPaintedParent, customContext);
        return true;
    }());
}

void PaintingContextCls::paintChild(RenderObject child, Offset offset) {
    assert([=] () {
        debugOnProfilePaint?->call(child);
        return true;
    }());
    if (child->isRepaintBoundary()) {
        stopRecordingIfNeeded();
        _compositeChild(child, offset);
    } else {
        if (child->_wasRepaintBoundary) {
        assert(is<OffsetLayer>(child->_layerHandle->layer()));
        child->_layerHandle->layer() = nullptr;
        child->_paintWithContext(this, offset);
    } else {
        child->_paintWithContext(this, offset);
    }
;
    }}

void PaintingContextCls::appendLayer(Layer layer) {
    assert(!_isRecording());
    layer->remove();
    _containerLayer->append(layer);
}

Canvas PaintingContextCls::canvas() {
    if (_canvas == nullptr) {
        _startRecording();
    }
    assert(_currentLayer != nullptr);
    return _canvas!;
}

VoidCallback PaintingContextCls::addCompositionCallback(CompositionCallback callback) {
    return _containerLayer->addCompositionCallback(callback);
}

void PaintingContextCls::stopRecordingIfNeeded() {
    if (!_isRecording()) {
        return;
    }
    assert([=] () {
        if (debugRepaintRainbowEnabled) {
                    auto _c1 = make<PaintCls>();        _c1.style = auto _c2 = PaintingStyleCls::stroke;        _c2.strokeWidth = auto _c3 = 6.0;        _c3.color = debugCurrentRepaintColor->toColor();        _c3;        _c2;Paint paint = _c1;
            canvas()->drawRect(estimatedBounds->deflate(3.0), paint);
        }
        if (debugPaintLayerBordersEnabled) {
                    auto _c4 = make<PaintCls>();        _c4.style = auto _c5 = PaintingStyleCls::stroke;        _c5.strokeWidth = auto _c6 = 1.0;        _c6.color = make<ColorCls>(0xFFFF9800);        _c6;        _c5;Paint paint = _c4;
            canvas()->drawRect(estimatedBounds, paint);
        }
        return true;
    }());
    _currentLayer!->picture() = _recorder!->endRecording();
    _currentLayer = nullptr;
    _recorder = nullptr;
    _canvas = nullptr;
}

void PaintingContextCls::setIsComplexHint() {
    _currentLayer?->isComplexHint() = true;
}

void PaintingContextCls::setWillChangeHint() {
    _currentLayer?->willChangeHint() = true;
}

void PaintingContextCls::addLayer(Layer layer) {
    stopRecordingIfNeeded();
    appendLayer(layer);
}

void PaintingContextCls::pushLayer(ContainerLayer childLayer, PaintingContextCallback painter, Offset offset, Rect childPaintBounds) {
    assert(painter != nullptr);
    if (childLayer->hasChildren()) {
        childLayer->removeAllChildren();
    }
    stopRecordingIfNeeded();
    appendLayer(childLayer);
    PaintingContext childContext = createChildContext(childLayer, childPaintBounds | estimatedBounds);
    painter(childContext, offset);
    childContext->stopRecordingIfNeeded();
}

PaintingContext PaintingContextCls::createChildContext(ContainerLayer childLayer, Rect bounds) {
    return make<PaintingContextCls>(childLayer, bounds);
}

ClipRectLayer PaintingContextCls::pushClipRect(bool needsCompositing, Offset offset, Rect clipRect, PaintingContextCallback painter, Clip clipBehavior, ClipRectLayer oldLayer) {
    if (clipBehavior == ClipCls::none) {
        painter(this, offset);
        return nullptr;
    }
    Rect offsetClipRect = clipRect->shift(offset);
    if (needsCompositing) {
        ClipRectLayer layer = oldLayer | make<ClipRectLayerCls>();
            auto _c1 = layer;    _c1.clipRect = auto _c2 = offsetClipRect;    _c2.clipBehavior = clipBehavior;    _c2;_c1;
        pushLayer(layer, painter, offset, offsetClipRect);
        return layer;
    } else {
        clipRectAndPaint(offsetClipRect, clipBehavior, offsetClipRect, [=] () {
            painter(this, offset);
        });
        return nullptr;
    }
}

ClipRRectLayer PaintingContextCls::pushClipRRect(bool needsCompositing, Offset offset, Rect bounds, RRect clipRRect, PaintingContextCallback painter, Clip clipBehavior, ClipRRectLayer oldLayer) {
    assert(clipBehavior != nullptr);
    if (clipBehavior == ClipCls::none) {
        painter(this, offset);
        return nullptr;
    }
    Rect offsetBounds = bounds->shift(offset);
    RRect offsetClipRRect = clipRRect->shift(offset);
    if (needsCompositing) {
        ClipRRectLayer layer = oldLayer | make<ClipRRectLayerCls>();
            auto _c1 = layer;    _c1.clipRRect = auto _c2 = offsetClipRRect;    _c2.clipBehavior = clipBehavior;    _c2;_c1;
        pushLayer(layer, painter, offset, offsetBounds);
        return layer;
    } else {
        clipRRectAndPaint(offsetClipRRect, clipBehavior, offsetBounds, [=] () {
            painter(this, offset);
        });
        return nullptr;
    }
}

ClipPathLayer PaintingContextCls::pushClipPath(bool needsCompositing, Offset offset, Rect bounds, Path clipPath, PaintingContextCallback painter, Clip clipBehavior, ClipPathLayer oldLayer) {
    assert(clipBehavior != nullptr);
    if (clipBehavior == ClipCls::none) {
        painter(this, offset);
        return nullptr;
    }
    Rect offsetBounds = bounds->shift(offset);
    Path offsetClipPath = clipPath->shift(offset);
    if (needsCompositing) {
        ClipPathLayer layer = oldLayer | make<ClipPathLayerCls>();
            auto _c1 = layer;    _c1.clipPath = auto _c2 = offsetClipPath;    _c2.clipBehavior = clipBehavior;    _c2;_c1;
        pushLayer(layer, painter, offset, offsetBounds);
        return layer;
    } else {
        clipPathAndPaint(offsetClipPath, clipBehavior, offsetBounds, [=] () {
            painter(this, offset);
        });
        return nullptr;
    }
}

ColorFilterLayer PaintingContextCls::pushColorFilter(Offset offset, ColorFilter colorFilter, PaintingContextCallback painter, ColorFilterLayer oldLayer) {
    assert(colorFilter != nullptr);
    ColorFilterLayer layer = oldLayer | make<ColorFilterLayerCls>();
    layer->colorFilter = colorFilter;
    pushLayer(layer, painter, offset);
    return layer;
}

TransformLayer PaintingContextCls::pushTransform(bool needsCompositing, Offset offset, Matrix4 transform, PaintingContextCallback painter, TransformLayer oldLayer) {
    auto _c1 = Matrix4Cls->translationValues(offset->dx(), offset->dy(), 0.0);_c1.auto _c2 = multiply(transform);_c2.translate(-offset->dx(), -offset->dy());_c2;Matrix4 effectiveTransform = _c1;
    if (needsCompositing) {
        TransformLayer layer = oldLayer | make<TransformLayerCls>();
        layer->transform = effectiveTransform;
        pushLayer(layer, painter, offset, MatrixUtilsCls->inverseTransformRect(effectiveTransform, estimatedBounds));
        return layer;
    } else {
            auto _c3 = canvas();    _c3.auto _c4 = save();    _c4.transform(effectiveTransform->storage());    _c4;_c3;
        painter(this, offset);
        canvas()->restore();
        return nullptr;
    }
}

OpacityLayer PaintingContextCls::pushOpacity(Offset offset, int alpha, PaintingContextCallback painter, OpacityLayer oldLayer) {
    OpacityLayer layer = oldLayer | make<OpacityLayerCls>();
    auto _c1 = layer;_c1.alpha = auto _c2 = alpha;_c2.offset = offset;_c2;_c1;
    pushLayer(layer, painter, OffsetCls::zero);
    return layer;
}

String PaintingContextCls::toString() {
    return __s("${objectRuntimeType(this, 'PaintingContext')}#$hashCode(layer: $_containerLayer, canvas bounds: $estimatedBounds)");
}

void PaintingContextCls::_repaintCompositedChild(RenderObject child, PaintingContext childContext, bool debugAlsoPaintedParent) {
    assert(child->isRepaintBoundary());
    assert([=] () {
        child->debugRegisterRepaintBoundaryPaint(debugAlsoPaintedParent, true);
        return true;
    }());
    OffsetLayer childLayer = as<OffsetLayer>(child->_layerHandle->layer());
    if (childLayer == nullptr) {
        assert(debugAlsoPaintedParent);
        assert(child->_layerHandle->layer() == nullptr);
        OffsetLayer layer = child->updateCompositedLayer(nullptr);
        child->_layerHandle->layer = childLayer = layer;
    } else {
        assert(debugAlsoPaintedParent || childLayer->attached());
        Offset debugOldOffset;
        assert([=] () {
            debugOldOffset = childLayer!->offset();
            return true;
        }());
        childLayer->removeAllChildren();
        OffsetLayer updatedLayer = child->updateCompositedLayer(childLayer);
        assert(identical(updatedLayer, childLayer), __s("$child created a new layer instance $updatedLayer instead of reusing the existing layer $childLayer. See the documentation of RenderObject.updateCompositedLayer for more information on how to correctly implement this method."));
        assert(debugOldOffset == updatedLayer->offset());
    }
    child->_needsCompositedLayerUpdate = false;
    assert(identical(childLayer, child->_layerHandle->layer()));
    assert(is<OffsetLayer>(child->_layerHandle->layer()));
    assert([=] () {
        childLayer!->debugCreator = child->debugCreator | child->runtimeType;
        return true;
    }());
    childContext |= make<PaintingContextCls>(childLayer, child->paintBounds());
    child->_paintWithContext(childContext, OffsetCls::zero);
    assert(identical(childLayer, child->_layerHandle->layer()));
    childContext->stopRecordingIfNeeded();
}

void PaintingContextCls::_compositeChild(RenderObject child, Offset offset) {
    assert(!_isRecording());
    assert(child->isRepaintBoundary());
    assert(_canvas == nullptr || _canvas!->getSaveCount() == 1);
    if (child->_needsPaint || !child->_wasRepaintBoundary) {
        repaintCompositedChild(child, true);
    } else {
        if (child->_needsCompositedLayerUpdate) {
            updateLayerProperties(child);
        }
        assert([=] () {
            child->debugRegisterRepaintBoundaryPaint();
            child->_layerHandle->layer()!->debugCreator = child->debugCreator | child;
            return true;
        }());
    }
    assert(is<OffsetLayer>(child->_layerHandle->layer()));
    OffsetLayer childOffsetLayer = as<OffsetLayer>(child->_layerHandle->layer()!);
    childOffsetLayer->offset = offset;
    appendLayer(childOffsetLayer);
}

bool PaintingContextCls::_isRecording() {
    bool hasCanvas = _canvas != nullptr;
    assert([=] () {
        if (hasCanvas) {
            assert(_currentLayer != nullptr);
            assert(_recorder != nullptr);
            assert(_canvas != nullptr);
        } else {
            assert(_currentLayer == nullptr);
            assert(_recorder == nullptr);
            assert(_canvas == nullptr);
        }
        return true;
    }());
    return hasCanvas;
}

void PaintingContextCls::_startRecording() {
    assert(!_isRecording());
    _currentLayer = make<PictureLayerCls>(estimatedBounds);
    _recorder = ui->make<PictureRecorderCls>();
    _canvas = make<CanvasCls>(_recorder!);
    _containerLayer->append(_currentLayer!);
}

bool ConstraintsCls::debugAssertIsValid(InformationCollector informationCollector, bool isAppliedConstraint) {
    assert(isNormalized());
    return isNormalized();
}

void SemanticsHandleCls::dispose() {
    if (listener != nullptr) {
        _owner->semanticsOwner()!->removeListener(listener!);
    }
    _owner->_didDisposeSemanticsHandle();
}

void SemanticsHandleCls::_(PipelineOwner owner, VoidCallback listener) {
    if (listener != nullptr) {
        _owner->semanticsOwner()!->addListener(listener!);
    }
}

void PipelineOwnerCls::requestVisualUpdate() {
    onNeedVisualUpdate?->call();
}

AbstractNode PipelineOwnerCls::rootNode() {
    return _rootNode;
}

void PipelineOwnerCls::rootNode(AbstractNode value) {
    if (_rootNode == value) {
        return;
    }
    _rootNode?->detach();
    _rootNode = value;
    _rootNode?->attach(this);
}

bool PipelineOwnerCls::debugDoingLayout() {
    return _debugDoingLayout;
}

void PipelineOwnerCls::flushLayout() {
    if (!kReleaseMode) {
        Map<String, String> debugTimelineArguments;
        assert([=] () {
            if (debugEnhanceLayoutTimelineArguments) {
                            Map<String, String> map1 = make<MapCls<>>();            map1.set(__s("dirty count"), __s("${_nodesNeedingLayout.length}"));            map1.set(__s("dirty list"), __s("$_nodesNeedingLayout"));debugTimelineArguments = list1;
            }
            return true;
        }());
        TimelineCls->startSync(__s("LAYOUT"), debugTimelineArguments);
    }
    assert([=] () {
        _debugDoingLayout = true;
        return true;
    }());
    try {
        while (_nodesNeedingLayout->isNotEmpty()) {
            assert(!_shouldMergeDirtyNodes);
            List<RenderObject> dirtyNodes = _nodesNeedingLayout;
            _nodesNeedingLayout = makeList();
            dirtyNodes->sort([=] (RenderObject a,RenderObject b) {
                a->depth - b->depth;
            });
            for (;  < dirtyNodes->length(); i++) {
                if (_shouldMergeDirtyNodes) {
                    _shouldMergeDirtyNodes = false;
                    if (_nodesNeedingLayout->isNotEmpty()) {
                        _nodesNeedingLayout->addAll(dirtyNodes->getRange(i, dirtyNodes->length()));
                        break;
                    }
                }
                RenderObject node = dirtyNodes[i];
                if (node->_needsLayout && node->owner() == this) {
                    node->_layoutWithoutResize();
                }
            }
            _shouldMergeDirtyNodes = false;
        }
    } finally {
        _shouldMergeDirtyNodes = false;
        assert([=] () {
            _debugDoingLayout = false;
            return true;
        }());
        if (!kReleaseMode) {
            TimelineCls->finishSync();
        }
    };
}

void PipelineOwnerCls::flushCompositingBits() {
    if (!kReleaseMode) {
        TimelineCls->startSync(__s("UPDATING COMPOSITING BITS"));
    }
    _nodesNeedingCompositingBitsUpdate->sort([=] (RenderObject a,RenderObject b) {
        a->depth - b->depth;
    });
    for (RenderObject node : _nodesNeedingCompositingBitsUpdate) {
        if (node->_needsCompositingBitsUpdate && node->owner == this) {
            node->_updateCompositingBits();
        }
    }
    _nodesNeedingCompositingBitsUpdate->clear();
    if (!kReleaseMode) {
        TimelineCls->finishSync();
    }
}

bool PipelineOwnerCls::debugDoingPaint() {
    return _debugDoingPaint;
}

void PipelineOwnerCls::flushPaint() {
    if (!kReleaseMode) {
        Map<String, String> debugTimelineArguments;
        assert([=] () {
            if (debugEnhancePaintTimelineArguments) {
                            Map<String, String> map1 = make<MapCls<>>();            map1.set(__s("dirty count"), __s("${_nodesNeedingPaint.length}"));            map1.set(__s("dirty list"), __s("$_nodesNeedingPaint"));debugTimelineArguments = list1;
            }
            return true;
        }());
        TimelineCls->startSync(__s("PAINT"), debugTimelineArguments);
    }
    try {
        assert([=] () {
            _debugDoingPaint = true;
            return true;
        }());
        List<RenderObject> dirtyNodes = _nodesNeedingPaint;
        _nodesNeedingPaint = makeList();
        for (RenderObject node : _c2) {
                    auto _c2 = dirtyNodes;        _c2.sort([=] (RenderObject a,RenderObject b) {                    b->depth - a->depth;                });assert(node->_layerHandle->layer != nullptr);
            if ((node->_needsPaint || node->_needsCompositedLayerUpdate) && node->owner == this) {
                if (node->_layerHandle->layer!->attached) {
                    assert(node->isRepaintBoundary);
                    if (node->_needsPaint) {
                        PaintingContextCls->repaintCompositedChild(node);
                    } else {
                        PaintingContextCls->updateLayerProperties(node);
                    }
                } else {
                    node->_skippedPaintingOnLayer();
                }
            }
        }
        assert(_nodesNeedingPaint->isEmpty());
    } finally {
        assert([=] () {
            _debugDoingPaint = false;
            return true;
        }());
        if (!kReleaseMode) {
            TimelineCls->finishSync();
        }
    };
}

SemanticsOwner PipelineOwnerCls::semanticsOwner() {
    return _semanticsOwner;
}

int PipelineOwnerCls::debugOutstandingSemanticsHandles() {
    return _outstandingSemanticsHandles;
}

SemanticsHandle PipelineOwnerCls::ensureSemantics(VoidCallback listener) {
    _outstandingSemanticsHandles += 1;
    if (_outstandingSemanticsHandles == 1) {
        assert(_semanticsOwner == nullptr);
        _semanticsOwner = make<SemanticsOwnerCls>();
        onSemanticsOwnerCreated?->call();
    }
    return SemanticsHandleCls->_(this, listener);
}

void PipelineOwnerCls::flushSemantics() {
    if (_semanticsOwner == nullptr) {
        return;
    }
    if (!kReleaseMode) {
        TimelineCls->startSync(__s("SEMANTICS"));
    }
    assert(_semanticsOwner != nullptr);
    assert([=] () {
        _debugDoingSemantics = true;
        return true;
    }());
    try {
            auto _c1 = _nodesNeedingSemantics->toList();    _c1.sort([=] (RenderObject a,RenderObject b) {        a->depth - b->depth;    });List<RenderObject> nodesToProcess = _c1;
        _nodesNeedingSemantics->clear();
        for (RenderObject node : nodesToProcess) {
            if (node->_needsSemanticsUpdate && node->owner == this) {
                node->_updateSemantics();
            }
        }
        _semanticsOwner!->sendSemanticsUpdate();
    } finally {
        assert(_nodesNeedingSemantics->isEmpty());
        assert([=] () {
            _debugDoingSemantics = false;
            return true;
        }());
        if (!kReleaseMode) {
            TimelineCls->finishSync();
        }
    };
}

void PipelineOwnerCls::_enableMutationsToDirtySubtrees(VoidCallback callback) {
    assert(_debugDoingLayout);
    bool oldState;
    assert([=] () {
        oldState = _debugAllowMutationsToDirtySubtrees;
        _debugAllowMutationsToDirtySubtrees = true;
        return true;
    }());
    try {
        callback();
    } finally {
        _shouldMergeDirtyNodes = true;
        assert([=] () {
            _debugAllowMutationsToDirtySubtrees = oldState!;
            return true;
        }());
    };
}

void PipelineOwnerCls::_didDisposeSemanticsHandle() {
    assert(_semanticsOwner != nullptr);
    _outstandingSemanticsHandles -= 1;
    if (_outstandingSemanticsHandles == 0) {
        _semanticsOwner!->dispose();
        _semanticsOwner = nullptr;
        onSemanticsOwnerDisposed?->call();
    }
}

RenderObjectCls::RenderObjectCls() {
    {
        _needsCompositing = isRepaintBoundary() || alwaysNeedsCompositing();
        _wasRepaintBoundary = isRepaintBoundary();
    }
}

void RenderObjectCls::reassemble() {
    markNeedsLayout();
    markNeedsCompositingBitsUpdate();
    markNeedsPaint();
    markNeedsSemanticsUpdate();
    visitChildren([=] (RenderObject child) {
        child->reassemble();
    });
}

bool RenderObjectCls::debugDisposed() {
    bool disposed;
    assert([=] () {
        disposed = _debugDisposed;
        return true;
    }());
    return disposed;
}

void RenderObjectCls::dispose() {
    assert(!_debugDisposed);
    _layerHandle->layer() = nullptr;
    assert([=] () {
        _debugDisposed = true;
        return true;
    }());
}

void RenderObjectCls::setupParentData(RenderObject child) {
    assert(_debugCanPerformMutations());
    if (!is<ParentData>(child->parentData)) {
        child->parentData = make<ParentDataCls>();
    }
}

void RenderObjectCls::adoptChild(RenderObject child) {
    assert(_debugCanPerformMutations());
    assert(child != nullptr);
    setupParentData(child);
    markNeedsLayout();
    markNeedsCompositingBitsUpdate();
    markNeedsSemanticsUpdate();
    super->adoptChild(child);
}

void RenderObjectCls::dropChild(RenderObject child) {
    assert(_debugCanPerformMutations());
    assert(child != nullptr);
    assert(child->parentData != nullptr);
    child->_cleanRelayoutBoundary();
    child->parentData!->detach();
    child->parentData = nullptr;
    super->dropChild(child);
    markNeedsLayout();
    markNeedsCompositingBitsUpdate();
    markNeedsSemanticsUpdate();
}

void RenderObjectCls::visitChildren(RenderObjectVisitor visitor) {
}

bool RenderObjectCls::debugDoingThisResize() {
    return _debugDoingThisResize;
}

bool RenderObjectCls::debugDoingThisLayout() {
    return _debugDoingThisLayout;
}

RenderObject RenderObjectCls::debugActiveLayout() {
    return _debugActiveLayout;
}

bool RenderObjectCls::debugCanParentUseSize() {
    return _debugCanParentUseSize!;
}

PipelineOwner RenderObjectCls::owner() {
    return as<PipelineOwner>(super->owner);
}

void RenderObjectCls::attach(PipelineOwner owner) {
    assert(!_debugDisposed);
    super->attach(owner);
    if (_needsLayout && _relayoutBoundary != nullptr) {
        _needsLayout = false;
        markNeedsLayout();
    }
    if (_needsCompositingBitsUpdate) {
        _needsCompositingBitsUpdate = false;
        markNeedsCompositingBitsUpdate();
    }
    if (_needsPaint && _layerHandle->layer() != nullptr) {
        _needsPaint = false;
        markNeedsPaint();
    }
    if (_needsSemanticsUpdate && _semanticsConfiguration()->isSemanticBoundary()) {
        _needsSemanticsUpdate = false;
        markNeedsSemanticsUpdate();
    }
}

bool RenderObjectCls::debugNeedsLayout() {
    bool result;
    assert([=] () {
        result = _needsLayout;
        return true;
    }());
    return result;
}

bool RenderObjectCls::debugDoingThisLayoutWithCallback() {
    return _doingThisLayoutWithCallback;
}

Constraints RenderObjectCls::constraints() {
    if (_constraints == nullptr) {
        throw make<StateErrorCls>(__s("A RenderObject does not have any constraints before it has been laid out."));
    }
    return _constraints!;
}

void RenderObjectCls::markNeedsLayout() {
    assert(_debugCanPerformMutations());
    if (_needsLayout) {
        assert(_debugSubtreeRelayoutRootAlreadyMarkedNeedsLayout());
        return;
    }
    if (_relayoutBoundary == nullptr) {
        _needsLayout = true;
        if (parent() != nullptr) {
            markParentNeedsLayout();
        }
        return;
    }
    if (_relayoutBoundary != this) {
        markParentNeedsLayout();
    } else {
        _needsLayout = true;
        if (owner() != nullptr) {
            assert([=] () {
                if (debugPrintMarkNeedsLayoutStacks) {
                    debugPrintStack(__s("markNeedsLayout() called for $this"));
                }
                return true;
            }());
            owner()!->_nodesNeedingLayout->add(this);
            owner()!->requestVisualUpdate();
        }
    }
}

void RenderObjectCls::markParentNeedsLayout() {
    assert(_debugCanPerformMutations());
    _needsLayout = true;
    assert(this->parent() != nullptr);
    RenderObject parent = as<RenderObject>(this->parent()!);
    if (!_doingThisLayoutWithCallback) {
        parent->markNeedsLayout();
    } else {
        assert(parent->_debugDoingThisLayout);
    }
    assert(parent == this->parent);
}

void RenderObjectCls::markNeedsLayoutForSizedByParentChange() {
    markNeedsLayout();
    markParentNeedsLayout();
}

void RenderObjectCls::scheduleInitialLayout() {
    assert(!_debugDisposed);
    assert(attached());
    assert(!is<RenderObject>(parent()));
    assert(!owner()!->_debugDoingLayout);
    assert(_relayoutBoundary == nullptr);
    _relayoutBoundary = this;
    assert([=] () {
        _debugCanParentUseSize = false;
        return true;
    }());
    owner()!->_nodesNeedingLayout->add(this);
}

void RenderObjectCls::layout(Constraints constraints, bool parentUsesSize) {
    assert(!_debugDisposed);
    if (!kReleaseMode && debugProfileLayoutsEnabled) {
        Map<String, String> debugTimelineArguments;
        assert([=] () {
            if (debugEnhanceLayoutTimelineArguments) {
                debugTimelineArguments = toDiagnosticsNode()->toTimelineArguments();
            }
            return true;
        }());
        TimelineCls->startSync(__s("$runtimeType"), debugTimelineArguments);
    }
    assert(constraints != nullptr);
    assert(constraints->debugAssertIsValid(true, [=] () {
        List<String> stack = StackTraceCls::current->toString()->split(__s("\n"));
        int targetFrame;
        Pattern layoutFramePattern = make<RegExpCls>(__s("^#[0-9]+ +RenderObject.layout \("));
        for (;  < stack->length(); i += 1) {
            if (layoutFramePattern->matchAsPrefix(stack[i]) != nullptr) {
                targetFrame = i + 1;
                break;
            }
        }
        if (targetFrame != nullptr &&  < stack->length()) {
            Pattern targetFramePattern = make<RegExpCls>(__s("^#[0-9]+ +(.+)$"));
            Match targetFrameMatch = targetFramePattern->matchAsPrefix(stack[targetFrame]);
            String problemFunction = (targetFrameMatch != nullptr && targetFrameMatch->groupCount() > 0)? targetFrameMatch->group(1) : stack[targetFrame]->trim();
            return makeList(ArrayItem);
        }
        return makeList();
    }));
    assert(!_debugDoingThisResize);
    assert(!_debugDoingThisLayout);
    bool isRelayoutBoundary = !parentUsesSize || sizedByParent() || constraints->isTight() || !is<RenderObject>(parent());
    RenderObject relayoutBoundary = isRelayoutBoundary? this : (as<RenderObject>(parent()!))->_relayoutBoundary!;
    assert([=] () {
        _debugCanParentUseSize = parentUsesSize;
        return true;
    }());
    if (!_needsLayout && constraints == _constraints) {
        assert([=] () {
            _debugDoingThisResize = sizedByParent();
            _debugDoingThisLayout = !sizedByParent();
            RenderObject debugPreviousActiveLayout = _debugActiveLayout;
            _debugActiveLayout = this;
            debugResetSize();
            _debugActiveLayout = debugPreviousActiveLayout;
            _debugDoingThisLayout = false;
            _debugDoingThisResize = false;
            return true;
        }());
        if (relayoutBoundary != _relayoutBoundary) {
            _relayoutBoundary = relayoutBoundary;
            visitChildren(_propagateRelayoutBoundaryToChild);
        }
        if (!kReleaseMode && debugProfileLayoutsEnabled) {
            TimelineCls->finishSync();
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
    assert([=] () {
        _debugMutationsLocked = true;
        if (debugPrintLayouts) {
            debugPrint(__s("Laying out (${sizedByParent ? "with separate resize" : "with resize allowed"}) $this"));
        }
        return true;
    }());
    if (sizedByParent()) {
        assert([=] () {
            _debugDoingThisResize = true;
            return true;
        }());
        try {
            performResize();
            assert([=] () {
                debugAssertDoesMeetConstraints();
                return true;
            }());
        } catch (Unknown e) {
            _debugReportException(__s("performResize"), e, stack);
        };
        assert([=] () {
            _debugDoingThisResize = false;
            return true;
        }());
    }
    RenderObject debugPreviousActiveLayout;
    assert([=] () {
        _debugDoingThisLayout = true;
        debugPreviousActiveLayout = _debugActiveLayout;
        _debugActiveLayout = this;
        return true;
    }());
    try {
        performLayout();
        markNeedsSemanticsUpdate();
        assert([=] () {
            debugAssertDoesMeetConstraints();
            return true;
        }());
    } catch (Unknown e) {
        _debugReportException(__s("performLayout"), e, stack);
    };
    assert([=] () {
        _debugActiveLayout = debugPreviousActiveLayout;
        _debugDoingThisLayout = false;
        _debugMutationsLocked = false;
        return true;
    }());
    _needsLayout = false;
    markNeedsPaint();
    if (!kReleaseMode && debugProfileLayoutsEnabled) {
        TimelineCls->finishSync();
    }
}

void RenderObjectCls::debugResetSize() {
}

bool RenderObjectCls::sizedByParent() {
    return false;
}

template<typename T>
void RenderObjectCls::invokeLayoutCallback(LayoutCallback<T> callback) {
    assert(_debugMutationsLocked);
    assert(_debugDoingThisLayout);
    assert(!_doingThisLayoutWithCallback);
    _doingThisLayoutWithCallback = true;
    try {
        owner()!->_enableMutationsToDirtySubtrees([=] () {
            callback(as<T>(constraints()));
        });
    } finally {
        _doingThisLayoutWithCallback = false;
    };
}

bool RenderObjectCls::debugDoingThisPaint() {
    return _debugDoingThisPaint;
}

RenderObject RenderObjectCls::debugActivePaint() {
    return _debugActivePaint;
}

bool RenderObjectCls::isRepaintBoundary() {
    return false;
}

void RenderObjectCls::debugRegisterRepaintBoundaryPaint(bool includedChild, bool includedParent) {
}

bool RenderObjectCls::alwaysNeedsCompositing() {
    return false;
}

OffsetLayer RenderObjectCls::updateCompositedLayer(OffsetLayer oldLayer) {
    assert(isRepaintBoundary());
    return oldLayer | make<OffsetLayerCls>();
}

ContainerLayer RenderObjectCls::layer() {
    assert(!isRepaintBoundary() || _layerHandle->layer() == nullptr || is<OffsetLayer>(_layerHandle->layer()));
    return _layerHandle->layer();
}

void RenderObjectCls::layer(ContainerLayer newLayer) {
    assert(!isRepaintBoundary(), __s("Attempted to set a layer to a repaint boundary render object.\nThe framework creates and assigns an OffsetLayer to a repaint boundary automatically."));
    _layerHandle->layer() = newLayer;
}

ContainerLayer RenderObjectCls::debugLayer() {
    ContainerLayer result;
    assert([=] () {
        result = _layerHandle->layer();
        return true;
    }());
    return result;
}

void RenderObjectCls::markNeedsCompositingBitsUpdate() {
    assert(!_debugDisposed);
    if (_needsCompositingBitsUpdate) {
        return;
    }
    _needsCompositingBitsUpdate = true;
    if (is<RenderObject>(parent())) {
        RenderObject parent = as<RenderObject>(this->as<RenderObjectCls>(parent)!);
        if (as<RenderObjectCls>(parent)->_needsCompositingBitsUpdate) {
            return;
        }
        if ((!_wasRepaintBoundary || !isRepaintBoundary()) && !as<RenderObjectCls>(parent)->isRepaintBoundary()) {
            parent->markNeedsCompositingBitsUpdate();
            return;
        }
    }
    if (owner() != nullptr) {
        owner()!->_nodesNeedingCompositingBitsUpdate->add(this);
    }
}

bool RenderObjectCls::needsCompositing() {
    assert(!_needsCompositingBitsUpdate);
    return _needsCompositing;
}

bool RenderObjectCls::debugNeedsPaint() {
    bool result;
    assert([=] () {
        result = _needsPaint;
        return true;
    }());
    return result;
}

bool RenderObjectCls::debugNeedsCompositedLayerUpdate() {
    bool result;
    assert([=] () {
        result = _needsCompositedLayerUpdate;
        return true;
    }());
    return result;
}

void RenderObjectCls::markNeedsPaint() {
    assert(!_debugDisposed);
    assert(owner() == nullptr || !owner()!->debugDoingPaint());
    if (_needsPaint) {
        return;
    }
    _needsPaint = true;
    if (isRepaintBoundary() && _wasRepaintBoundary) {
        assert([=] () {
            if (debugPrintMarkNeedsPaintStacks) {
                debugPrintStack(__s("markNeedsPaint() called for $this"));
            }
            return true;
        }());
        assert(is<OffsetLayer>(_layerHandle->layer()));
        if (owner() != nullptr) {
            owner()!->_nodesNeedingPaint->add(this);
            owner()!->requestVisualUpdate();
        }
    } else {
        if (is<RenderObject>(parent())) {
        RenderObject parent = as<RenderObject>(this->as<RenderObjectCls>(parent)!);
        as<RenderObjectCls>(parent)->markNeedsPaint();
        assert(as<RenderObjectCls>(parent) == this->as<RenderObjectCls>(parent));
    } else {
        assert([=] () {
            if (debugPrintMarkNeedsPaintStacks) {
                debugPrintStack(__s("markNeedsPaint() called for $this (root of render tree)"));
            }
            return true;
        }());
        if (owner() != nullptr) {
            owner()!->requestVisualUpdate();
        }
    }
;
    }}

void RenderObjectCls::markNeedsCompositedLayerUpdate() {
    assert(!_debugDisposed);
    assert(owner() == nullptr || !owner()!->debugDoingPaint());
    if (_needsCompositedLayerUpdate || _needsPaint) {
        return;
    }
    _needsCompositedLayerUpdate = true;
    if (isRepaintBoundary() && _wasRepaintBoundary) {
        assert(_layerHandle->layer() != nullptr);
        if (owner() != nullptr) {
            owner()!->_nodesNeedingPaint->add(this);
            owner()!->requestVisualUpdate();
        }
    } else {
        markNeedsPaint();
    }
}

void RenderObjectCls::scheduleInitialPaint(ContainerLayer rootLayer) {
    assert(rootLayer->attached());
    assert(attached());
    assert(!is<RenderObject>(parent()));
    assert(!owner()!->_debugDoingPaint);
    assert(isRepaintBoundary());
    assert(_layerHandle->layer() == nullptr);
    _layerHandle->layer() = rootLayer;
    assert(_needsPaint);
    owner()!->_nodesNeedingPaint->add(this);
}

void RenderObjectCls::replaceRootLayer(OffsetLayer rootLayer) {
    assert(!_debugDisposed);
    assert(rootLayer->attached());
    assert(attached());
    assert(!is<RenderObject>(parent()));
    assert(!owner()!->_debugDoingPaint);
    assert(isRepaintBoundary());
    assert(_layerHandle->layer() != nullptr);
    _layerHandle->layer()!->detach();
    _layerHandle->layer() = rootLayer;
    markNeedsPaint();
}

void RenderObjectCls::debugPaint(PaintingContext context, Offset offset) {
}

void RenderObjectCls::paint(PaintingContext context, Offset offset) {
}

void RenderObjectCls::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(child->parent() == this);
}

bool RenderObjectCls::paintsChild(RenderObject child) {
    assert(child->parent() == this);
    return true;
}

Matrix4 RenderObjectCls::getTransformTo(RenderObject ancestor) {
    bool ancestorSpecified = ancestor != nullptr;
    assert(attached());
    if (ancestor == nullptr) {
        AbstractNode rootNode = owner()!->rootNode();
        if (is<RenderObject>(rootNode)) {
            ancestor = as<RenderObjectCls>(rootNode);
        }
    }
    List<RenderObject> renderers = makeList();
    for (; renderer != ancestor; renderer = as<RenderObject>(renderer->parent!)) {
        renderers->add(renderer);
        assert(renderer->parent != nullptr);
    }
    if (ancestorSpecified) {
        renderers->add(ancestor!);
    }
    Matrix4 transform = Matrix4Cls->identity();
    for (; index > 0; index -= 1) {
        renderers[index]->applyPaintTransform(renderers[index - 1], transform);
    }
    return transform;
}

Rect RenderObjectCls::describeApproximatePaintClip(RenderObject child) {
    return nullptr;
}

Rect RenderObjectCls::describeSemanticsClip(RenderObject child) {
    return nullptr;
}

void RenderObjectCls::scheduleInitialSemantics() {
    assert(!_debugDisposed);
    assert(attached());
    assert(!is<RenderObject>(parent()));
    assert(!owner()!->_debugDoingSemantics);
    assert(_semantics == nullptr);
    assert(_needsSemanticsUpdate);
    assert(owner()!->_semanticsOwner != nullptr);
    owner()!->_nodesNeedingSemantics->add(this);
    owner()!->requestVisualUpdate();
}

void RenderObjectCls::describeSemanticsConfiguration(SemanticsConfiguration config) {
}

void RenderObjectCls::sendSemanticsEvent(SemanticsEvent semanticsEvent) {
    if (owner()!->semanticsOwner() == nullptr) {
        return;
    }
    if (_semantics != nullptr && !_semantics!->isMergedIntoParent()) {
        _semantics!->sendEvent(semanticsEvent);
    } else {
        if (parent() != nullptr) {
        RenderObject renderParent = as<RenderObject>(parent()!);
        renderParent->sendSemanticsEvent(semanticsEvent);
    }
;
    }}

SemanticsNode RenderObjectCls::debugSemantics() {
    if (!kReleaseMode) {
        return _semantics;
    }
    return nullptr;
}

void RenderObjectCls::clearSemantics() {
    _needsSemanticsUpdate = true;
    _semantics = nullptr;
    visitChildren([=] (RenderObject child) {
        child->clearSemantics();
    });
}

void RenderObjectCls::markNeedsSemanticsUpdate() {
    assert(!_debugDisposed);
    assert(!attached() || !owner()!->_debugDoingSemantics);
    if (!attached() || owner()!->_semanticsOwner == nullptr) {
        _cachedSemanticsConfiguration = nullptr;
        return;
    }
    bool wasSemanticsBoundary = _semantics != nullptr && (_cachedSemanticsConfiguration?->isSemanticBoundary() | false);
    _cachedSemanticsConfiguration = nullptr;
    bool isEffectiveSemanticsBoundary = _semanticsConfiguration()->isSemanticBoundary() && wasSemanticsBoundary;
    RenderObject node = this;
    while (!isEffectiveSemanticsBoundary && is<RenderObject>(node->parent())) {
        if (node != this && node->_needsSemanticsUpdate) {
            break;
        }
        node->_needsSemanticsUpdate = true;
        node = as<RenderObject>(node->parent()!);
        isEffectiveSemanticsBoundary = node->_semanticsConfiguration()->isSemanticBoundary();
        if (isEffectiveSemanticsBoundary && node->_semantics == nullptr) {
            return;
        }
    }
    if (node != this && _semantics != nullptr && _needsSemanticsUpdate) {
        owner()!->_nodesNeedingSemantics->remove(this);
    }
    if (!node->_needsSemanticsUpdate) {
        node->_needsSemanticsUpdate = true;
        if (owner() != nullptr) {
            assert(node->_semanticsConfiguration()->isSemanticBoundary() || !is<RenderObject>(node->parent()));
            owner()!->_nodesNeedingSemantics->add(node);
            owner()!->requestVisualUpdate();
        }
    }
}

void RenderObjectCls::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    visitChildren(visitor);
}

void RenderObjectCls::assembleSemanticsNode(SemanticsNode node, SemanticsConfiguration config, Iterable<SemanticsNode> children) {
    assert(node == _semantics);
    node->updateWith(config, as<List<SemanticsNode>>(children));
}

void RenderObjectCls::handleEvent(PointerEvent event, HitTestEntry<any> entry) {
}

String RenderObjectCls::toStringShort() {
    String header = describeIdentity(this);
    if (!kReleaseMode) {
        if (_debugDisposed) {
            header += __s(" DISPOSED");
            return header;
        }
        if (_relayoutBoundary != nullptr && _relayoutBoundary != this) {
            int count = 1;
            RenderObject target = as<RenderObject>(parent());
            while (target != nullptr && target != _relayoutBoundary) {
                target = as<RenderObject>(target->parent());
                count += 1;
            }
            header += __s(" relayoutBoundary=up$count");
        }
        if (_needsLayout) {
            header += __s(" NEEDS-LAYOUT");
        }
        if (_needsPaint) {
            header += __s(" NEEDS-PAINT");
        }
        if (_needsCompositingBitsUpdate) {
            header += __s(" NEEDS-COMPOSITING-BITS-UPDATE");
        }
        if (!attached()) {
            header += __s(" DETACHED");
        }
    }
    return header;
}

String RenderObjectCls::toString(DiagnosticLevel minLevel) {
    return toStringShort();
}

String RenderObjectCls::toStringDeep(DiagnosticLevel minLevel, String prefixLineOne, String prefixOtherLines) {
    RenderObject debugPreviousActiveLayout;
    assert([=] () {
        debugPreviousActiveLayout = _debugActiveLayout;
        _debugActiveLayout = nullptr;
        return true;
    }());
    String result = super->toStringDeep(prefixLineOne, prefixOtherLines, minLevel);
    assert([=] () {
        _debugActiveLayout = debugPreviousActiveLayout;
        return true;
    }());
    return result;
}

String RenderObjectCls::toStringShallow(String joiner, DiagnosticLevel minLevel) {
    RenderObject debugPreviousActiveLayout;
    assert([=] () {
        debugPreviousActiveLayout = _debugActiveLayout;
        _debugActiveLayout = nullptr;
        return true;
    }());
    String result = super->toStringShallow(joiner, minLevel);
    assert([=] () {
        _debugActiveLayout = debugPreviousActiveLayout;
        return true;
    }());
    return result;
}

void RenderObjectCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<FlagPropertyCls>(__s("needsCompositing"), _needsCompositing, __s("needs compositing")));
    properties->add(<Object>make<DiagnosticsPropertyCls>(__s("creator"), debugCreator, nullptr, DiagnosticLevelCls::debug));
    properties->add(<ParentData>make<DiagnosticsPropertyCls>(__s("parentData"), parentData, (_debugCanParentUseSize | false)? __s("can use size") : nullptr, true));
    properties->add(<Constraints>make<DiagnosticsPropertyCls>(__s("constraints"), _constraints, true));
    properties->add(<ContainerLayer>make<DiagnosticsPropertyCls>(__s("layer"), _layerHandle->layer(), nullptr));
    properties->add(<SemanticsNode>make<DiagnosticsPropertyCls>(__s("semantics node"), _semantics, nullptr));
    properties->add(make<FlagPropertyCls>(__s("isBlockingSemanticsOfPreviouslyPaintedNodes"), _semanticsConfiguration()->isBlockingSemanticsOfPreviouslyPaintedNodes, __s("blocks semantics of earlier render objects below the common boundary")));
    properties->add(make<FlagPropertyCls>(__s("isSemanticBoundary"), _semanticsConfiguration()->isSemanticBoundary(), __s("semantic boundary")));
}

List<DiagnosticsNode> RenderObjectCls::debugDescribeChildren() {
    return makeList();
}

void RenderObjectCls::showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect) {
    if (is<RenderObject>(parent())) {
        RenderObject renderParent = as<RenderObject>(as<RenderObjectCls>(parent)!);
        renderParent->showOnScreen(descendant | this, rect, duration, curve);
    }
}

DiagnosticsNode RenderObjectCls::describeForError(String name, DiagnosticsTreeStyle style) {
    return toDiagnosticsNode(name, style);
}

void RenderObjectCls::_debugReportException(String method, Object exception, StackTrace stack) {
    List<DiagnosticsNode> list1 = make<ListCls<>>();if (kDebugMode && debugCreator != nullptr) {    list1.add(ArrayItem);}list1.add(ArrayItem);list1.add(ArrayItem);FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("rendering library"), make<ErrorDescriptionCls>(__s("during $method()")), [=] () {
        list1;
    }));
}

bool RenderObjectCls::_debugCanPerformMutations() {
    bool result;
    assert([=] () {
        if (_debugDisposed) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem));
        }
        PipelineOwner owner = this->owner();
        if (owner == nullptr || !owner->debugDoingLayout()) {
            result = true;
            return true;
        }
        RenderObject activeLayoutRoot = this;
        while (activeLayoutRoot != nullptr) {
            bool mutationsToDirtySubtreesAllowed = activeLayoutRoot->owner?->_debugAllowMutationsToDirtySubtrees | false;
            bool doingLayoutWithCallback = activeLayoutRoot->_doingThisLayoutWithCallback;
            if (doingLayoutWithCallback || mutationsToDirtySubtreesAllowed && activeLayoutRoot->_needsLayout) {
                result = true;
                return true;
            }
            if (!activeLayoutRoot->_debugMutationsLocked) {
                AbstractNode p = activeLayoutRoot->parent();
                activeLayoutRoot = is<RenderObject>(p)? p : nullptr;
            } else {
                break;
            }
        }
        RenderObject debugActiveLayout = RenderObjectCls::debugActiveLayout!;
        String culpritMethodName = debugActiveLayout->debugDoingThisLayout()? __s("performLayout") : __s("performResize");
        String culpritFullMethodName = __s("${debugActiveLayout.runtimeType}.$culpritMethodName");
        result = false;
        if (activeLayoutRoot == nullptr) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));
        }
        if (activeLayoutRoot == this) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));
        }
        ErrorSummary summary = make<ErrorSummaryCls>(__s("A $runtimeType was mutated in $culpritFullMethodName."));
        bool isMutatedByAncestor = activeLayoutRoot == debugActiveLayout;
        String description = isMutatedByAncestor? __s("A RenderObject must not mutate its descendants in its $culpritMethodName method.") : __s("A RenderObject must not mutate another RenderObject from a different render subtree in its $culpritMethodName method.");
            List<DiagnosticsNode> list1 = make<ListCls<>>();    list1.add(ArrayItem);    list1.add(ArrayItem);    list1.add(ArrayItem);    list1.add(ArrayItem);    if (!isMutatedByAncestor) {        list1.add(ArrayItem);    }list1.add(ArrayItem);throw FlutterErrorCls->fromParts(list1);
    }());
    return result;
}

bool RenderObjectCls::_debugSubtreeRelayoutRootAlreadyMarkedNeedsLayout() {
    if (_relayoutBoundary == nullptr) {
        return true;
    }
    RenderObject node = this;
    while (node != _relayoutBoundary) {
        assert(node->_relayoutBoundary == _relayoutBoundary);
        assert(node->parent() != nullptr);
        node = as<RenderObject>(node->parent()!);
        if ((!node->_needsLayout) && (!node->_debugDoingThisLayout)) {
            return false;
        }
    }
    assert(node->_relayoutBoundary == node);
    return true;
}

void RenderObjectCls::_cleanRelayoutBoundary() {
    if (_relayoutBoundary != this) {
        _relayoutBoundary = nullptr;
        visitChildren(_cleanChildRelayoutBoundary);
    }
}

void RenderObjectCls::_propagateRelayoutBoundary() {
    if (_relayoutBoundary == this) {
        return;
    }
    RenderObject parentRelayoutBoundary = (as<RenderObject>(parent()))?->_relayoutBoundary;
    assert(parentRelayoutBoundary != nullptr);
    if (parentRelayoutBoundary != _relayoutBoundary) {
        _relayoutBoundary = parentRelayoutBoundary;
        visitChildren(_propagateRelayoutBoundaryToChild);
    }
}

void RenderObjectCls::_cleanChildRelayoutBoundary(RenderObject child) {
    child->_cleanRelayoutBoundary();
}

void RenderObjectCls::_propagateRelayoutBoundaryToChild(RenderObject child) {
    child->_propagateRelayoutBoundary();
}

void RenderObjectCls::_layoutWithoutResize() {
    assert(_relayoutBoundary == this);
    RenderObject debugPreviousActiveLayout;
    assert(!_debugMutationsLocked);
    assert(!_doingThisLayoutWithCallback);
    assert(_debugCanParentUseSize != nullptr);
    assert([=] () {
        _debugMutationsLocked = true;
        _debugDoingThisLayout = true;
        debugPreviousActiveLayout = _debugActiveLayout;
        _debugActiveLayout = this;
        if (debugPrintLayouts) {
            debugPrint(__s("Laying out (without resize) $this"));
        }
        return true;
    }());
    try {
        performLayout();
        markNeedsSemanticsUpdate();
    } catch (Unknown e) {
        _debugReportException(__s("performLayout"), e, stack);
    };
    assert([=] () {
        _debugActiveLayout = debugPreviousActiveLayout;
        _debugDoingThisLayout = false;
        _debugMutationsLocked = false;
        return true;
    }());
    _needsLayout = false;
    markNeedsPaint();
}

void RenderObjectCls::_updateCompositingBits() {
    if (!_needsCompositingBitsUpdate) {
        return;
    }
    bool oldNeedsCompositing = _needsCompositing;
    _needsCompositing = false;
    visitChildren([=] (RenderObject child) {
        child->_updateCompositingBits();
        if (child->needsCompositing) {
            _needsCompositing = true;
        }
    });
    if (isRepaintBoundary() || alwaysNeedsCompositing()) {
        _needsCompositing = true;
    }
    if (!isRepaintBoundary() && _wasRepaintBoundary) {
        _needsPaint = false;
        _needsCompositedLayerUpdate = false;
        owner()?->_nodesNeedingPaint->remove(this);
        _needsCompositingBitsUpdate = false;
        markNeedsPaint();
    } else {
        if (oldNeedsCompositing != _needsCompositing) {
        _needsCompositingBitsUpdate = false;
        markNeedsPaint();
    } else {
        _needsCompositingBitsUpdate = false;
    }
;
    }}

void RenderObjectCls::_skippedPaintingOnLayer() {
    assert(attached());
    assert(isRepaintBoundary());
    assert(_needsPaint || _needsCompositedLayerUpdate);
    assert(_layerHandle->layer() != nullptr);
    assert(!_layerHandle->layer()!->attached());
    AbstractNode node = parent();
    while (is<RenderObject>(node)) {
        if (node->isRepaintBoundary) {
            if (node->_layerHandle->layer() == nullptr) {
                break;
            }
            if (node->_layerHandle->layer()!->attached()) {
                break;
            }
            node->_needsPaint = true;
        }
        node = node->parent();
    }
}

void RenderObjectCls::_paintWithContext(PaintingContext context, Offset offset) {
    assert(!_debugDisposed);
    assert([=] () {
        if (_debugDoingThisPaint) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
        }
        return true;
    }());
    if (_needsLayout) {
        return;
    }
    if (!kReleaseMode && debugProfilePaintsEnabled) {
        Map<String, String> debugTimelineArguments;
        assert([=] () {
            if (debugEnhancePaintTimelineArguments) {
                debugTimelineArguments = toDiagnosticsNode()->toTimelineArguments();
            }
            return true;
        }());
        TimelineCls->startSync(__s("$runtimeType"), debugTimelineArguments);
    }
    assert([=] () {
        if (_needsCompositingBitsUpdate) {
            if (is<RenderObject>(parent())) {
                RenderObject parent = as<RenderObject>(this->as<RenderObjectCls>(parent)!);
                bool visitedByParent = false;
                as<RenderObjectCls>(parent)->visitChildren([=] (RenderObject child) {
                    if (child == this) {
                        visitedByParent = true;
                    }
                });
                if (!visitedByParent) {
                    throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem));
                }
            }
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));
        }
        return true;
    }());
    RenderObject debugLastActivePaint;
    assert([=] () {
        _debugDoingThisPaint = true;
        debugLastActivePaint = _debugActivePaint;
        _debugActivePaint = this;
        assert(!isRepaintBoundary() || _layerHandle->layer() != nullptr);
        return true;
    }());
    _needsPaint = false;
    _needsCompositedLayerUpdate = false;
    _wasRepaintBoundary = isRepaintBoundary();
    try {
        paint(context, offset);
        assert(!_needsLayout);
        assert(!_needsPaint);
    } catch (Unknown e) {
        _debugReportException(__s("paint"), e, stack);
    };
    assert([=] () {
        debugPaint(context, offset);
        _debugActivePaint = debugLastActivePaint;
        _debugDoingThisPaint = false;
        return true;
    }());
    if (!kReleaseMode && debugProfilePaintsEnabled) {
        TimelineCls->finishSync();
    }
}

SemanticsConfiguration RenderObjectCls::_semanticsConfiguration() {
    if (_cachedSemanticsConfiguration == nullptr) {
        _cachedSemanticsConfiguration = make<SemanticsConfigurationCls>();
        describeSemanticsConfiguration(_cachedSemanticsConfiguration!);
    }
    return _cachedSemanticsConfiguration!;
}

void RenderObjectCls::_updateSemantics() {
    assert(_semanticsConfiguration()->isSemanticBoundary() || !is<RenderObject>(parent()));
    if (_needsLayout) {
        return;
    }
    _SemanticsFragment fragment = _getSemanticsForParent(_semantics?->parent()?->isPartOfNodeMerging() | false);
    assert(is<_InterestingSemanticsFragment>(fragment));
    _InterestingSemanticsFragment interestingFragment = as<_InterestingSemanticsFragment>(fragment);
    List<SemanticsNode> result = makeList();
    interestingFragment->compileChildren(_semantics?->parentSemanticsClipRect, _semantics?->parentPaintClipRect, _semantics?->elevationAdjustment | 0.0, result);
    SemanticsNode node = result->single();
    assert(interestingFragment->config() == nullptr && node == _semantics);
}

_SemanticsFragment RenderObjectCls::_getSemanticsForParent(bool mergeIntoParent) {
    assert(mergeIntoParent != nullptr);
    assert(!_needsLayout, __s("Updated layout information required for $this to calculate semantics."));
    SemanticsConfiguration config = _semanticsConfiguration();
    bool dropSemanticsOfPreviousSiblings = config->isBlockingSemanticsOfPreviouslyPaintedNodes;
    bool producesForkingFragment = !config->hasBeenAnnotated() && !config->isSemanticBoundary();
    List<_InterestingSemanticsFragment> fragments = makeList();
    Set<_InterestingSemanticsFragment> toBeMarkedExplicit = makeSet();
    bool childrenMergeIntoParent = mergeIntoParent || config->isMergingSemanticsOfDescendants();
    visitChildrenForSemantics([=] (RenderObject renderChild) {
        assert(!_needsLayout);
        _SemanticsFragment parentFragment = renderChild->_getSemanticsForParent(childrenMergeIntoParent);
        if (parentFragment->dropsSemanticsOfPreviousSiblings) {
            fragments->clear();
            toBeMarkedExplicit->clear();
            if (!config->isSemanticBoundary()) {
                dropSemanticsOfPreviousSiblings = true;
            }
        }
        for (_InterestingSemanticsFragment fragment : parentFragment->interestingFragments()) {
            fragments->add(fragment);
            fragment->addAncestor(this);
            fragment->addTags(config->tagsForChildren());
            if (config->explicitChildNodes || !is<RenderObject>(parent())) {
                fragment->markAsExplicit();
                continue;
            }
            if (!fragment->hasConfigForParent || producesForkingFragment) {
                continue;
            }
            if (!config->isCompatibleWith(fragment->config)) {
                toBeMarkedExplicit->add(fragment);
            }
            int siblingLength = fragments->length() - 1;
            for (;  < siblingLength; i += 1) {
                _InterestingSemanticsFragment siblingFragment = fragments[i];
                if (!fragment->config!->isCompatibleWith(siblingFragment->config)) {
                    toBeMarkedExplicit->add(fragment);
                    toBeMarkedExplicit->add(siblingFragment);
                }
            }
        }
    });
    for (_InterestingSemanticsFragment fragment : toBeMarkedExplicit) {
        fragment->markAsExplicit();
    }
    _needsSemanticsUpdate = false;
    _SemanticsFragment result;
    if (!is<RenderObject>(parent())) {
        assert(!config->hasBeenAnnotated());
        assert(!mergeIntoParent);
        result = make<_RootSemanticsFragmentCls>(this, dropSemanticsOfPreviousSiblings);
    } else {
        if (producesForkingFragment) {
        result = make<_ContainerSemanticsFragmentCls>(dropSemanticsOfPreviousSiblings);
    } else {
        result = make<_SwitchableSemanticsFragmentCls>(config, mergeIntoParent, this, dropSemanticsOfPreviousSiblings);
        if (config->isSemanticBoundary()) {
            _SwitchableSemanticsFragment fragment = as<_SwitchableSemanticsFragment>(result);
            fragment->markAsExplicit();
        }
    }
;
    }    result->addAll(fragments);
    return result;
}

template<typename ChildType>
bool RenderObjectWithChildMixinCls<ChildType>::debugValidateChild(RenderObject child) {
    assert([=] () {
        if (!is<ChildType>(child)) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem));
        }
        return true;
    }());
    return true;
}

template<typename ChildType>
ChildType RenderObjectWithChildMixinCls<ChildType>::child() {
    return _child;
}

template<typename ChildType>
void RenderObjectWithChildMixinCls<ChildType>::child(ChildType value) {
    if (_child != nullptr) {
        dropChild(_child!);
    }
    _child = value;
    if (_child != nullptr) {
        adoptChild(_child!);
    }
}

template<typename ChildType>
void RenderObjectWithChildMixinCls<ChildType>::attach(PipelineOwner owner) {
    super->attach(owner);
    if (_child != nullptr) {
        _child!->attach(owner);
    }
}

template<typename ChildType>
void RenderObjectWithChildMixinCls<ChildType>::detach() {
    super->detach();
    if (_child != nullptr) {
        _child!->detach();
    }
}

template<typename ChildType>
void RenderObjectWithChildMixinCls<ChildType>::redepthChildren() {
    if (_child != nullptr) {
        redepthChild(_child!);
    }
}

template<typename ChildType>
void RenderObjectWithChildMixinCls<ChildType>::visitChildren(RenderObjectVisitor visitor) {
    if (_child != nullptr) {
        visitor(_child!);
    }
}

template<typename ChildType>
List<DiagnosticsNode> RenderObjectWithChildMixinCls<ChildType>::debugDescribeChildren() {
    return child() != nullptr? makeList(ArrayItem) : makeList();
}

template<typename ChildType>
void ContainerParentDataMixinCls<ChildType>::detach() {
    assert(previousSibling == nullptr, __s("Pointers to siblings must be nulled before detaching ParentData."));
    assert(nextSibling == nullptr, __s("Pointers to siblings must be nulled before detaching ParentData."));
    super->detach();
}

template<typename ChildType, typename ParentDataType>
int ContainerRenderObjectMixinCls<ChildType, ParentDataType>::childCount() {
    return _childCount;
}

template<typename ChildType, typename ParentDataType>
bool ContainerRenderObjectMixinCls<ChildType, ParentDataType>::debugValidateChild(RenderObject child) {
    assert([=] () {
        if (!is<ChildType>(child)) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem));
        }
        return true;
    }());
    return true;
}

template<typename ChildType, typename ParentDataType>
void ContainerRenderObjectMixinCls<ChildType, ParentDataType>::insert(ChildType child, ChildType after) {
    assert(child != this, __s("A RenderObject cannot be inserted into itself."));
    assert(after != this, __s("A RenderObject cannot simultaneously be both the parent and the sibling of another RenderObject."));
    assert(child != after, __s("A RenderObject cannot be inserted after itself."));
    assert(child != _firstChild);
    assert(child != _lastChild);
    adoptChild(child);
    _insertIntoChildList(child, after);
}

template<typename ChildType, typename ParentDataType>
void ContainerRenderObjectMixinCls<ChildType, ParentDataType>::add(ChildType child) {
    insert(child, _lastChild);
}

template<typename ChildType, typename ParentDataType>
void ContainerRenderObjectMixinCls<ChildType, ParentDataType>::addAll(List<ChildType> children) {
    children?->forEach(add);
}

template<typename ChildType, typename ParentDataType>
void ContainerRenderObjectMixinCls<ChildType, ParentDataType>::remove(ChildType child) {
    _removeFromChildList(child);
    dropChild(child);
}

template<typename ChildType, typename ParentDataType>
void ContainerRenderObjectMixinCls<ChildType, ParentDataType>::removeAll() {
    ChildType child = _firstChild;
    while (child != nullptr) {
        ParentDataType childParentData = as<ParentDataType>(child->parentData!);
        ChildType next = childParentData->nextSibling;
        childParentData->previousSibling = nullptr;
        childParentData->nextSibling = nullptr;
        dropChild(child);
        child = next;
    }
    _firstChild = nullptr;
    _lastChild = nullptr;
    _childCount = 0;
}

template<typename ChildType, typename ParentDataType>
void ContainerRenderObjectMixinCls<ChildType, ParentDataType>::move(ChildType child, ChildType after) {
    assert(child != this);
    assert(after != this);
    assert(child != after);
    assert(child->parent == this);
    ParentDataType childParentData = as<ParentDataType>(child->parentData!);
    if (childParentData->previousSibling == after) {
        return;
    }
    _removeFromChildList(child);
    _insertIntoChildList(child, after);
    markNeedsLayout();
}

template<typename ChildType, typename ParentDataType>
void ContainerRenderObjectMixinCls<ChildType, ParentDataType>::attach(PipelineOwner owner) {
    super->attach(owner);
    ChildType child = _firstChild;
    while (child != nullptr) {
        child->attach(owner);
        ParentDataType childParentData = as<ParentDataType>(child->parentData!);
        child = childParentData->nextSibling;
    }
}

template<typename ChildType, typename ParentDataType>
void ContainerRenderObjectMixinCls<ChildType, ParentDataType>::detach() {
    super->detach();
    ChildType child = _firstChild;
    while (child != nullptr) {
        child->detach();
        ParentDataType childParentData = as<ParentDataType>(child->parentData!);
        child = childParentData->nextSibling;
    }
}

template<typename ChildType, typename ParentDataType>
void ContainerRenderObjectMixinCls<ChildType, ParentDataType>::redepthChildren() {
    ChildType child = _firstChild;
    while (child != nullptr) {
        redepthChild(child);
        ParentDataType childParentData = as<ParentDataType>(child->parentData!);
        child = childParentData->nextSibling;
    }
}

template<typename ChildType, typename ParentDataType>
void ContainerRenderObjectMixinCls<ChildType, ParentDataType>::visitChildren(RenderObjectVisitor visitor) {
    ChildType child = _firstChild;
    while (child != nullptr) {
        visitor(child);
        ParentDataType childParentData = as<ParentDataType>(child->parentData!);
        child = childParentData->nextSibling;
    }
}

template<typename ChildType, typename ParentDataType>
ChildType ContainerRenderObjectMixinCls<ChildType, ParentDataType>::firstChild() {
    return _firstChild;
}

template<typename ChildType, typename ParentDataType>
ChildType ContainerRenderObjectMixinCls<ChildType, ParentDataType>::lastChild() {
    return _lastChild;
}

template<typename ChildType, typename ParentDataType>
ChildType ContainerRenderObjectMixinCls<ChildType, ParentDataType>::childBefore(ChildType child) {
    assert(child != nullptr);
    assert(child->parent == this);
    ParentDataType childParentData = as<ParentDataType>(child->parentData!);
    return childParentData->previousSibling;
}

template<typename ChildType, typename ParentDataType>
ChildType ContainerRenderObjectMixinCls<ChildType, ParentDataType>::childAfter(ChildType child) {
    assert(child != nullptr);
    assert(child->parent == this);
    ParentDataType childParentData = as<ParentDataType>(child->parentData!);
    return childParentData->nextSibling;
}

template<typename ChildType, typename ParentDataType>
List<DiagnosticsNode> ContainerRenderObjectMixinCls<ChildType, ParentDataType>::debugDescribeChildren() {
    List<DiagnosticsNode> children = makeList();
    if (firstChild() != nullptr) {
        ChildType child = firstChild()!;
        int count = 1;
        while (true) {
            children->add(child->toDiagnosticsNode(__s("child $count")));
            if (child == lastChild()) {
                break;
            }
            count += 1;
            ParentDataType childParentData = as<ParentDataType>(child->parentData!);
            child = childParentData->nextSibling!;
        }
    }
    return children;
}

template<typename ChildType, typename ParentDataType>
bool ContainerRenderObjectMixinCls<ChildType, ParentDataType>::_debugUltimatePreviousSiblingOf(ChildType child, ChildType equals) {
    ParentDataType childParentData = as<ParentDataType>(child->parentData!);
    while (childParentData->previousSibling != nullptr) {
        assert(childParentData->previousSibling != child);
        child = childParentData->previousSibling!;
        childParentData = as<ParentDataType>(child->parentData!);
    }
    return child == equals;
}

template<typename ChildType, typename ParentDataType>
bool ContainerRenderObjectMixinCls<ChildType, ParentDataType>::_debugUltimateNextSiblingOf(ChildType child, ChildType equals) {
    ParentDataType childParentData = as<ParentDataType>(child->parentData!);
    while (childParentData->nextSibling != nullptr) {
        assert(childParentData->nextSibling != child);
        child = childParentData->nextSibling!;
        childParentData = as<ParentDataType>(child->parentData!);
    }
    return child == equals;
}

template<typename ChildType, typename ParentDataType>
void ContainerRenderObjectMixinCls<ChildType, ParentDataType>::_insertIntoChildList(ChildType child, ChildType after) {
    ParentDataType childParentData = as<ParentDataType>(child->parentData!);
    assert(childParentData->nextSibling == nullptr);
    assert(childParentData->previousSibling == nullptr);
    _childCount += 1;
    assert(_childCount > 0);
    if (after == nullptr) {
        childParentData->nextSibling = _firstChild;
        if (_firstChild != nullptr) {
            ParentDataType firstChildParentData = as<ParentDataType>(_firstChild!->parentData!);
            firstChildParentData->previousSibling = child;
        }
        _firstChild = child;
        _lastChild |= child;
    } else {
        assert(_firstChild != nullptr);
        assert(_lastChild != nullptr);
        assert(_debugUltimatePreviousSiblingOf(after, _firstChild));
        assert(_debugUltimateNextSiblingOf(after, _lastChild));
        ParentDataType afterParentData = as<ParentDataType>(after->parentData!);
        if (afterParentData->nextSibling == nullptr) {
            assert(after == _lastChild);
            childParentData->previousSibling = after;
            afterParentData->nextSibling = child;
            _lastChild = child;
        } else {
            childParentData->nextSibling = afterParentData->nextSibling;
            childParentData->previousSibling = after;
            ParentDataType childPreviousSiblingParentData = as<ParentDataType>(childParentData->previousSibling!->parentData!);
            ParentDataType childNextSiblingParentData = as<ParentDataType>(childParentData->nextSibling!->parentData!);
            childPreviousSiblingParentData->nextSibling = child;
            childNextSiblingParentData->previousSibling = child;
            assert(afterParentData->nextSibling == child);
        }
    }
}

template<typename ChildType, typename ParentDataType>
void ContainerRenderObjectMixinCls<ChildType, ParentDataType>::_removeFromChildList(ChildType child) {
    ParentDataType childParentData = as<ParentDataType>(child->parentData!);
    assert(_debugUltimatePreviousSiblingOf(child, _firstChild));
    assert(_debugUltimateNextSiblingOf(child, _lastChild));
    assert(_childCount >= 0);
    if (childParentData->previousSibling == nullptr) {
        assert(_firstChild == child);
        _firstChild = childParentData->nextSibling;
    } else {
        ParentDataType childPreviousSiblingParentData = as<ParentDataType>(childParentData->previousSibling!->parentData!);
        childPreviousSiblingParentData->nextSibling = childParentData->nextSibling;
    }
    if (childParentData->nextSibling == nullptr) {
        assert(_lastChild == child);
        _lastChild = childParentData->previousSibling;
    } else {
        ParentDataType childNextSiblingParentData = as<ParentDataType>(childParentData->nextSibling!->parentData!);
        childNextSiblingParentData->previousSibling = childParentData->previousSibling;
    }
    childParentData->previousSibling = nullptr;
    childParentData->nextSibling = nullptr;
    _childCount -= 1;
}

void RelayoutWhenSystemFontsChangeMixinCls::systemFontsDidChange() {
    markNeedsLayout();
}

void RelayoutWhenSystemFontsChangeMixinCls::attach(PipelineOwner owner) {
    super->attach(owner);
    PaintingBindingCls::instance->systemFonts->addListener(systemFontsDidChange);
}

void RelayoutWhenSystemFontsChangeMixinCls::detach() {
    PaintingBindingCls::instance->systemFonts->removeListener(systemFontsDidChange);
    super->detach();
}

_SemanticsFragmentCls::_SemanticsFragmentCls(bool dropsSemanticsOfPreviousSiblings) {
    {
        assert(dropsSemanticsOfPreviousSiblings != nullptr);
    }
}

void _ContainerSemanticsFragmentCls::addAll(Iterable<_InterestingSemanticsFragment> fragments) {
    interestingFragments->addAll(fragments);
}

RenderObject _InterestingSemanticsFragmentCls::owner() {
    return _ancestorChain->first;
}

bool _InterestingSemanticsFragmentCls::hasConfigForParent() {
    return config() != nullptr;
}

List<_InterestingSemanticsFragment> _InterestingSemanticsFragmentCls::interestingFragments() {
    return makeList(ArrayItem);
}

void _InterestingSemanticsFragmentCls::addTags(Iterable<SemanticsTag> tags) {
    if (tags == nullptr || tags->isEmpty()) {
        return;
    }
    _tagsForChildren |= makeSet();
    _tagsForChildren!->addAll(tags);
}

void _InterestingSemanticsFragmentCls::addAncestor(RenderObject ancestor) {
    _ancestorChain->add(ancestor);
}

_InterestingSemanticsFragmentCls::_InterestingSemanticsFragmentCls(bool dropsSemanticsOfPreviousSiblings, RenderObject owner) {
    {
        assert(owner != nullptr);
        _ancestorChain = makeList(ArrayItem);
    }
}

void _RootSemanticsFragmentCls::compileChildren(double elevationAdjustment, Rect parentPaintClipRect, Rect parentSemanticsClipRect, List<SemanticsNode> result) {
    assert(_tagsForChildren == nullptr || _tagsForChildren!->isEmpty());
    assert(parentSemanticsClipRect == nullptr);
    assert(parentPaintClipRect == nullptr);
    assert(_ancestorChain->length() == 1);
    assert(elevationAdjustment == 0.0);
    owner()->_semantics |= SemanticsNodeCls->root(owner()->showOnScreen, owner()->owner()!->semanticsOwner()!);
    SemanticsNode node = owner()->_semantics!;
    assert(MatrixUtilsCls->matrixEquals(node->transform(), Matrix4Cls->identity()));
    assert(node->parentSemanticsClipRect == nullptr);
    assert(node->parentPaintClipRect == nullptr);
    node->rect() = owner()->semanticBounds();
    List<SemanticsNode> children = makeList();
    for (_InterestingSemanticsFragment fragment : _children) {
        assert(fragment->config == nullptr);
        fragment->compileChildren(parentSemanticsClipRect, parentPaintClipRect, 0.0, children);
    }
    node->updateWith(nullptr, children);
    assert(!node->isInvisible() || children->isEmpty());
    result->add(node);
}

SemanticsConfiguration _RootSemanticsFragmentCls::config() {
    return nullptr;
}

void _RootSemanticsFragmentCls::markAsExplicit() {
}

void _RootSemanticsFragmentCls::addAll(Iterable<_InterestingSemanticsFragment> fragments) {
    _children->addAll(fragments);
}

void _SwitchableSemanticsFragmentCls::compileChildren(double elevationAdjustment, Rect parentPaintClipRect, Rect parentSemanticsClipRect, List<SemanticsNode> result) {
    if (!_isExplicit) {
        owner()->_semantics = nullptr;
        for (_InterestingSemanticsFragment fragment : _children) {
            assert(_ancestorChain->first == fragment->_ancestorChain->last);
            fragment->_ancestorChain->addAll(_ancestorChain->skip(1));
            fragment->compileChildren(parentSemanticsClipRect, parentPaintClipRect, elevationAdjustment + _config->elevation(), result);
        }
        return;
    }
    _SemanticsGeometry geometry = _needsGeometryUpdate()? make<_SemanticsGeometryCls>(parentSemanticsClipRect, parentPaintClipRect, _ancestorChain) : nullptr;
    if (!_mergeIntoParent && (geometry?->dropFromTree() | false)) {
        return;
    }
    owner()->_semantics |= make<SemanticsNodeCls>(owner()->showOnScreen);
    auto _c1 = owner()->_semantics!;_c1.isMergedIntoParent = auto _c2 = _mergeIntoParent;_c2.tags = _tagsForChildren;_c2;SemanticsNode node = _c1;
    node->elevationAdjustment = elevationAdjustment;
    if (elevationAdjustment != 0.0) {
        _ensureConfigIsWritable();
        _config->elevation() += elevationAdjustment;
    }
    if (geometry != nullptr) {
        assert(_needsGeometryUpdate());
            auto _c3 = node;    _c3.rect = auto _c4 = geometry->rect();    _c4.transform = auto _c5 = geometry->transform();    _c5.parentSemanticsClipRect = auto _c6 = geometry->semanticsClipRect();    _c6.parentPaintClipRect = geometry->paintClipRect();    _c6;    _c5;    _c4;_c3;
        if (!_mergeIntoParent && geometry->markAsHidden()) {
            _ensureConfigIsWritable();
            _config->isHidden() = true;
        }
    }
    List<SemanticsNode> children = makeList();
    for (_InterestingSemanticsFragment fragment : _children) {
        fragment->compileChildren(node->parentSemanticsClipRect, node->parentPaintClipRect, 0.0, children);
    }
    if (_config->isSemanticBoundary()) {
        owner()->assembleSemanticsNode(node, _config, children);
    } else {
        node->updateWith(_config, children);
    }
    result->add(node);
}

SemanticsConfiguration _SwitchableSemanticsFragmentCls::config() {
    return _isExplicit? nullptr : _config;
}

void _SwitchableSemanticsFragmentCls::addAll(Iterable<_InterestingSemanticsFragment> fragments) {
    for (_InterestingSemanticsFragment fragment : fragments) {
        _children->add(fragment);
        if (fragment->config == nullptr) {
            continue;
        }
        _ensureConfigIsWritable();
        _config->absorb(fragment->config!);
    }
}

void _SwitchableSemanticsFragmentCls::markAsExplicit() {
    _isExplicit = true;
}

_SwitchableSemanticsFragmentCls::_SwitchableSemanticsFragmentCls(SemanticsConfiguration config, bool dropsSemanticsOfPreviousSiblings, bool mergeIntoParent, Unknown owner) {
    {
        _mergeIntoParent = mergeIntoParent;
        _config = config;
        assert(mergeIntoParent != nullptr);
        assert(config != nullptr);
    }
}

void _SwitchableSemanticsFragmentCls::_ensureConfigIsWritable() {
    if (!_isConfigWritable) {
        _config = _config->copy();
        _isConfigWritable = true;
    }
}

bool _SwitchableSemanticsFragmentCls::_needsGeometryUpdate() {
    return _ancestorChain->length() > 1;
}

Matrix4 _SemanticsGeometryCls::transform() {
    return _transform;
}

Rect _SemanticsGeometryCls::semanticsClipRect() {
    return _semanticsClipRect;
}

Rect _SemanticsGeometryCls::paintClipRect() {
    return _paintClipRect;
}

Rect _SemanticsGeometryCls::rect() {
    return _rect;
}

bool _SemanticsGeometryCls::dropFromTree() {
    return _rect->isEmpty() || _transform->isZero();
}

bool _SemanticsGeometryCls::markAsHidden() {
    return _markAsHidden;
}

_SemanticsGeometryCls::_SemanticsGeometryCls(List<RenderObject> ancestors, Rect parentPaintClipRect, Rect parentSemanticsClipRect) {
    {
        _computeValues(parentSemanticsClipRect, parentPaintClipRect, ancestors);
    }
}

void _SemanticsGeometryCls::_computeValues(Rect parentSemanticsClipRect, Rect parentPaintClipRect, List<RenderObject> ancestors) {
    assert(ancestors->length() > 1);
    _transform = Matrix4Cls->identity();
    _semanticsClipRect = parentSemanticsClipRect;
    _paintClipRect = parentPaintClipRect;
    for (; index > 0; index -= 1) {
        RenderObject parent = ancestors[index];
        RenderObject child = ancestors[index - 1];
        Rect parentSemanticsClipRect = parent->describeSemanticsClip(child);
        if (parentSemanticsClipRect != nullptr) {
            _semanticsClipRect = parentSemanticsClipRect;
            _paintClipRect = _intersectRects(_paintClipRect, parent->describeApproximatePaintClip(child));
        } else {
            _semanticsClipRect = _intersectRects(_semanticsClipRect, parent->describeApproximatePaintClip(child));
        }
        _temporaryTransformHolder->setIdentity();
        _applyIntermediatePaintTransforms(parent, child, _transform, _temporaryTransformHolder);
        _semanticsClipRect = _transformRect(_semanticsClipRect, _temporaryTransformHolder);
        _paintClipRect = _transformRect(_paintClipRect, _temporaryTransformHolder);
    }
    RenderObject owner = ancestors->first;
    _rect = _semanticsClipRect == nullptr? owner->semanticBounds() : _semanticsClipRect!->intersect(owner->semanticBounds());
    if (_paintClipRect != nullptr) {
        Rect paintRect = _paintClipRect!->intersect(_rect);
        _markAsHidden = paintRect->isEmpty() && !_rect->isEmpty();
        if (!_markAsHidden) {
            _rect = paintRect;
        }
    }
}

Rect _SemanticsGeometryCls::_transformRect(Rect rect, Matrix4 transform) {
    assert(transform != nullptr);
    if (rect == nullptr) {
        return nullptr;
    }
    if (rect->isEmpty() || transform->isZero()) {
        return RectCls::zero;
    }
    return MatrixUtilsCls->inverseTransformRect(transform, rect);
}

void _SemanticsGeometryCls::_applyIntermediatePaintTransforms(RenderObject ancestor, RenderObject child, Matrix4 transform, Matrix4 clipRectTransform) {
    assert(ancestor != nullptr);
    assert(child != nullptr);
    assert(transform != nullptr);
    assert(clipRectTransform != nullptr);
    assert(clipRectTransform->isIdentity());
    RenderObject intermediateParent = as<RenderObject>(child->parent()!);
    assert(intermediateParent != nullptr);
    while (intermediateParent != ancestor) {
        intermediateParent->applyPaintTransform(child, transform);
        intermediateParent = as<RenderObject>(intermediateParent->parent()!);
        child = as<RenderObject>(child->parent()!);
        assert(intermediateParent != nullptr);
    }
    ancestor->applyPaintTransform(child, transform);
    ancestor->applyPaintTransform(child, clipRectTransform);
}

Rect _SemanticsGeometryCls::_intersectRects(Rect a, Rect b) {
    if (a == nullptr) {
        return b;
    }
    if (b == nullptr) {
        return a;
    }
    return a->intersect(b);
}

DiagnosticsDebugCreatorCls::DiagnosticsDebugCreatorCls(Object value) : DiagnosticsProperty<Object>(__s("debugCreator"), valueDiagnosticLevelCls::hidden) {
    {
        assert(value != nullptr);
    }
}
