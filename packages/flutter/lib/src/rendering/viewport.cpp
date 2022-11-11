#include "viewport.hpp"
RenderAbstractViewport RenderAbstractViewportCls::of(RenderObject object) {
    while (object != nullptr) {
        if (is<RenderAbstractViewport>(object)) {
            return as<RenderAbstractViewportCls>(object);
        }
        object = as<RenderObject>(object->parent);
    }
    return nullptr;
}

RevealedOffsetCls::RevealedOffsetCls(double offset, Rect rect) {
    {
        assert(offset != nullptr);
        assert(rect != nullptr);
    }
}

String RevealedOffsetCls::toString() {
    return __s("${objectRuntimeType(this, 'RevealedOffset')}(offset: $offset, rect: $rect)");
}

template<typename ParentDataClass>
RenderViewportBaseCls<ParentDataClass>::RenderViewportBaseCls(AxisDirection axisDirection, double cacheExtent, CacheExtentStyle cacheExtentStyle, Clip clipBehavior, AxisDirection crossAxisDirection, ViewportOffset offset) {
    {
        assert(axisDirection != nullptr);
        assert(crossAxisDirection != nullptr);
        assert(offset != nullptr);
        assert(axisDirectionToAxis(axisDirection) != axisDirectionToAxis(crossAxisDirection));
        assert(cacheExtentStyle != nullptr);
        assert(cacheExtent != nullptr || cacheExtentStyle == CacheExtentStyleCls::pixel);
        assert(clipBehavior != nullptr);
        _axisDirection = axisDirection;
        _crossAxisDirection = crossAxisDirection;
        _offset = offset;
        _cacheExtent = cacheExtent or RenderAbstractViewportCls::defaultCacheExtent;
        _cacheExtentStyle = cacheExtentStyle;
        _clipBehavior = clipBehavior;
    }
}

template<typename ParentDataClass>
void RenderViewportBaseCls<ParentDataClass>::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super->describeSemanticsConfiguration(config);
    config->addTagForChildren(RenderViewportCls::useTwoPaneSemantics);
}

template<typename ParentDataClass>
void RenderViewportBaseCls<ParentDataClass>::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    childrenInPaintOrder()->where([=] (RenderSliver sliver)     {
        sliver->geometry!->visible || sliver->geometry!->cacheExtent > 0.0;
    })->forEach(visitor);
}

template<typename ParentDataClass>
AxisDirection RenderViewportBaseCls<ParentDataClass>::axisDirection() {
    return _axisDirection;
}

template<typename ParentDataClass>
void RenderViewportBaseCls<ParentDataClass>::axisDirection(AxisDirection value) {
    assert(value != nullptr);
    if (value == _axisDirection) {
        return;
    }
    _axisDirection = value;
    markNeedsLayout();
}

template<typename ParentDataClass>
AxisDirection RenderViewportBaseCls<ParentDataClass>::crossAxisDirection() {
    return _crossAxisDirection;
}

template<typename ParentDataClass>
void RenderViewportBaseCls<ParentDataClass>::crossAxisDirection(AxisDirection value) {
    assert(value != nullptr);
    if (value == _crossAxisDirection) {
        return;
    }
    _crossAxisDirection = value;
    markNeedsLayout();
}

template<typename ParentDataClass>
Axis RenderViewportBaseCls<ParentDataClass>::axis() {
    return axisDirectionToAxis(axisDirection());
}

template<typename ParentDataClass>
ViewportOffset RenderViewportBaseCls<ParentDataClass>::offset() {
    return _offset;
}

template<typename ParentDataClass>
void RenderViewportBaseCls<ParentDataClass>::offset(ViewportOffset value) {
    assert(value != nullptr);
    if (value == _offset) {
        return;
    }
    if (attached) {
        _offset->removeListener(markNeedsLayout);
    }
    _offset = value;
    if (attached) {
        _offset->addListener(markNeedsLayout);
    }
    markNeedsLayout();
}

template<typename ParentDataClass>
double RenderViewportBaseCls<ParentDataClass>::cacheExtent() {
    return _cacheExtent;
}

template<typename ParentDataClass>
void RenderViewportBaseCls<ParentDataClass>::cacheExtent(double value) {
    value = RenderAbstractViewportCls::defaultCacheExtent;
    assert(value != nullptr);
    if (value == _cacheExtent) {
        return;
    }
    _cacheExtent = value;
    markNeedsLayout();
}

template<typename ParentDataClass>
CacheExtentStyle RenderViewportBaseCls<ParentDataClass>::cacheExtentStyle() {
    return _cacheExtentStyle;
}

template<typename ParentDataClass>
void RenderViewportBaseCls<ParentDataClass>::cacheExtentStyle(CacheExtentStyle value) {
    assert(value != nullptr);
    if (value == _cacheExtentStyle) {
        return;
    }
    _cacheExtentStyle = value;
    markNeedsLayout();
}

template<typename ParentDataClass>
Clip RenderViewportBaseCls<ParentDataClass>::clipBehavior() {
    return _clipBehavior;
}

template<typename ParentDataClass>
void RenderViewportBaseCls<ParentDataClass>::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

template<typename ParentDataClass>
void RenderViewportBaseCls<ParentDataClass>::attach(PipelineOwner owner) {
    super->attach(owner);
    _offset->addListener(markNeedsLayout);
}

template<typename ParentDataClass>
void RenderViewportBaseCls<ParentDataClass>::detach() {
    _offset->removeListener(markNeedsLayout);
    super->detach();
}

template<typename ParentDataClass>
bool RenderViewportBaseCls<ParentDataClass>::debugThrowIfNotCheckingIntrinsics() {
    assert([=] () {
        if (!RenderObjectCls->debugCheckingIntrinsics) {
            assert(!is<RenderShrinkWrappingViewport>(this));
            ;
        }
        return true;
    }());
    return true;
}

template<typename ParentDataClass>
double RenderViewportBaseCls<ParentDataClass>::computeMinIntrinsicWidth(double height) {
    assert(debugThrowIfNotCheckingIntrinsics());
    return 0.0;
}

template<typename ParentDataClass>
double RenderViewportBaseCls<ParentDataClass>::computeMaxIntrinsicWidth(double height) {
    assert(debugThrowIfNotCheckingIntrinsics());
    return 0.0;
}

template<typename ParentDataClass>
double RenderViewportBaseCls<ParentDataClass>::computeMinIntrinsicHeight(double width) {
    assert(debugThrowIfNotCheckingIntrinsics());
    return 0.0;
}

template<typename ParentDataClass>
double RenderViewportBaseCls<ParentDataClass>::computeMaxIntrinsicHeight(double width) {
    assert(debugThrowIfNotCheckingIntrinsics());
    return 0.0;
}

template<typename ParentDataClass>
bool RenderViewportBaseCls<ParentDataClass>::isRepaintBoundary() {
    return true;
}

template<typename ParentDataClass>
double RenderViewportBaseCls<ParentDataClass>::layoutChildSequence(std::function<RenderSliver(RenderSliver child)> advance, double cacheOrigin, RenderSliver child, double crossAxisExtent, GrowthDirection growthDirection, double layoutOffset, double mainAxisExtent, double overlap, double remainingCacheExtent, double remainingPaintExtent, double scrollOffset) {
    assert(scrollOffset->isFinite);
    assert(scrollOffset >= 0.0);
    double initialLayoutOffset = layoutOffset;
    ScrollDirection adjustedUserScrollDirection = applyGrowthDirectionToScrollDirection(offset()->userScrollDirection(), growthDirection);
    assert(adjustedUserScrollDirection != nullptr);
    double maxPaintOffset = layoutOffset + overlap;
    double precedingScrollExtent = 0.0;
    while (child != nullptr) {
        double sliverScrollOffset = scrollOffset <= 0.0? 0.0 : scrollOffset;
        double correctedCacheOrigin = math->max(cacheOrigin, -sliverScrollOffset);
        double cacheExtentCorrection = cacheOrigin - correctedCacheOrigin;
        assert(sliverScrollOffset >= correctedCacheOrigin->abs());
        assert(correctedCacheOrigin <= 0.0);
        assert(sliverScrollOffset >= 0.0);
        assert(cacheExtentCorrection <= 0.0);
        child->layout(make<SliverConstraintsCls>(axisDirection(), growthDirection, adjustedUserScrollDirection, sliverScrollOffset, precedingScrollExtent, maxPaintOffset - layoutOffset, math->max(0.0, remainingPaintExtent - layoutOffset + initialLayoutOffset), crossAxisExtent, crossAxisDirection(), mainAxisExtent, math->max(0.0, remainingCacheExtent + cacheExtentCorrection), correctedCacheOrigin)true);
        SliverGeometry childLayoutGeometry = child->geometry()!;
        assert(childLayoutGeometry->debugAssertIsValid());
        if (childLayoutGeometry->scrollOffsetCorrection != nullptr) {
            return childLayoutGeometry->scrollOffsetCorrection!;
        }
        double effectiveLayoutOffset = layoutOffset + childLayoutGeometry->paintOrigin;
        if (childLayoutGeometry->visible || scrollOffset > 0) {
            updateChildLayoutOffset(child, effectiveLayoutOffset, growthDirection);
        } else {
            updateChildLayoutOffset(child, -scrollOffset + initialLayoutOffset, growthDirection);
        }
        maxPaintOffset = math->max(effectiveLayoutOffset + childLayoutGeometry->paintExtent, maxPaintOffset);
        scrollOffset = childLayoutGeometry->scrollExtent;
        precedingScrollExtent = childLayoutGeometry->scrollExtent;
        layoutOffset = childLayoutGeometry->layoutExtent;
        if (childLayoutGeometry->cacheExtent != 0.0) {
            remainingCacheExtent = childLayoutGeometry->cacheExtent - cacheExtentCorrection;
            cacheOrigin = math->min(correctedCacheOrigin + childLayoutGeometry->cacheExtent, 0.0);
        }
        updateOutOfBandData(growthDirection, childLayoutGeometry);
        child = advance(child);
    }
    return 0.0;
}

template<typename ParentDataClass>
Rect RenderViewportBaseCls<ParentDataClass>::describeApproximatePaintClip(RenderSliver child) {
    ;
    Rect viewportClip = OffsetCls::zero & size;
    if (child->constraints()->overlap == 0 || !child->constraints()->viewportMainAxisExtent->isFinite) {
        return viewportClip;
    }
    double left = viewportClip->left;
    double right = viewportClip->right;
    double top = viewportClip->top;
    double bottom = viewportClip->bottom;
    double startOfOverlap = child->constraints()->viewportMainAxisExtent - child->constraints()->remainingPaintExtent;
    double overlapCorrection = startOfOverlap + child->constraints()->overlap;
    ;
    return RectCls->fromLTRB(left, top, right, bottom);
}

template<typename ParentDataClass>
Rect RenderViewportBaseCls<ParentDataClass>::describeSemanticsClip(RenderSliver child) {
    assert(axis() != nullptr);
    if (_calculatedCacheExtent == nullptr) {
        return semanticBounds;
    }
    ;
}

template<typename ParentDataClass>
void RenderViewportBaseCls<ParentDataClass>::paint(PaintingContext context, Offset offset) {
    if (firstChild == nullptr) {
        return;
    }
    if (hasVisualOverflow() && clipBehavior() != ClipCls::none) {
        _clipRectLayer->layer() = context->pushClipRect(needsCompositing, offset, OffsetCls::zero & size, _paintContentsclipBehavior(), _clipRectLayer->layer());
    } else {
        _clipRectLayer->layer() = nullptr;
        _paintContents(context, offset);
    }
}

template<typename ParentDataClass>
void RenderViewportBaseCls<ParentDataClass>::dispose() {
    _clipRectLayer->layer() = nullptr;
    super->dispose();
}

template<typename ParentDataClass>
void RenderViewportBaseCls<ParentDataClass>::debugPaintSize(PaintingContext context, Offset offset) {
    assert([=] () {
        super->debugPaintSize(context, offset);
            auto _c1 = make<PaintCls>();    _c1.style = auto _c2 = PaintingStyleCls::stroke;    _c2.strokeWidth = auto _c3 = 1.0;    _c3.color = make<ColorCls>(0xFF00FF00);    _c3;    _c2;Paint paint = _c1;
        Canvas canvas = context->canvas();
        RenderSliver child = firstChild;
        while (child != nullptr) {
            Size size;
            ;
            assert(size != nullptr);
            canvas->drawRect(((offset + paintOffsetOf(child)) & size)->deflate(0.5), paint);
            child = childAfter(child);
        }
        return true;
    }());
}

template<typename ParentDataClass>
bool RenderViewportBaseCls<ParentDataClass>::hitTestChildren(Offset position, BoxHitTestResult result) {
    double mainAxisPosition, crossAxisPosition;
    ;
    assert(mainAxisPosition != nullptr);
    assert(crossAxisPosition != nullptr);
    SliverHitTestResult sliverResult = SliverHitTestResultCls->wrap(result);
    for (RenderSliver child : childrenInHitTestOrder()) {
        if (!child->geometry!->visible) {
            continue;
        }
        Matrix4 transform = Matrix4Cls->identity();
        applyPaintTransform(child, transform);
        bool isHit = result->addWithOutOfBandPosition(transform, [=] (BoxHitTestResult result) {
    return child->hitTest(sliverResultcomputeChildMainAxisPosition(child, mainAxisPosition), crossAxisPosition);
});
        if (isHit) {
            return true;
        }
    }
    return false;
}

template<typename ParentDataClass>
RevealedOffset RenderViewportBaseCls<ParentDataClass>::getOffsetToReveal(double alignment, Rect rect, RenderObject target) {
    double leadingScrollOffset = 0.0;
    RenderObject child = target;
    RenderBox pivot;
    bool onlySlivers = is<RenderSliver>(target);
    while (child->parent != this) {
        RenderObject parent = as<RenderObject>(child->parent!);
        assert(parent != nullptr, __s("$target must be a descendant of $this"));
        if (is<RenderBox>(child)) {
            pivot = as<RenderBoxCls>(child);
        }
        if (is<RenderSliver>(parent)) {
            leadingScrollOffset = as<RenderSliverCls>(parent)->childScrollOffset(child)!;
        } else {
            onlySlivers = false;
            leadingScrollOffset = 0.0;
        }
        child = parent;
    }
    Rect rectLocal;
    double pivotExtent;
    GrowthDirection growthDirection;
    if (pivot != nullptr) {
        assert(pivot->parent != nullptr);
        assert(pivot->parent != this);
        assert(pivot != this);
        assert(is<RenderSliver>(pivot->parent));
        RenderSliver pivotParent = as<RenderSliver>(pivot->parent!);
        growthDirection = pivotParent->constraints()->growthDirection;
        ;
        rect = target->paintBounds();
        rectLocal = MatrixUtilsCls->transformRect(target->getTransformTo(pivot), rect);
    } else     {
        if (onlySlivers) {
        RenderSliver targetSliver = as<RenderSliver>(target);
        growthDirection = targetSliver->constraints()->growthDirection;
        pivotExtent = targetSliver->geometry()!->scrollExtent;
        if (rect == nullptr) {
            ;
        }
        rectLocal = rect;
    } else {
        assert(rect != nullptr);
        return make<RevealedOffsetCls>(offset()->pixels(), rect!);
    }
;
    }    assert(pivotExtent != nullptr);
    assert(rect != nullptr);
    assert(rectLocal != nullptr);
    assert(growthDirection != nullptr);
    assert(child->parent == this);
    assert(is<RenderSliver>(child));
    RenderSliver sliver = as<RenderSliver>(child);
    double targetMainAxisExtent;
    ;
    bool isPinned = sliver->geometry()!->maxScrollObstructionExtent > 0 && leadingScrollOffset >= 0;
    leadingScrollOffset = scrollOffsetOf(sliver, leadingScrollOffset);
    Matrix4 transform = target->getTransformTo(this);
    Rect targetRect = MatrixUtilsCls->transformRect(transform, rect);
    double extentOfPinnedSlivers = maxScrollObstructionExtentBefore(sliver);
    ;
    double mainAxisExtent;
    ;
    double targetOffset = leadingScrollOffset - (mainAxisExtent - targetMainAxisExtent) * alignment;
    double offsetDifference = offset()->pixels() - targetOffset;
    ;
    return make<RevealedOffsetCls>(targetOffset, targetRect);
}

template<typename ParentDataClass>
Offset RenderViewportBaseCls<ParentDataClass>::computeAbsolutePaintOffset(RenderSliver child, GrowthDirection growthDirection, double layoutOffset) {
    assert(hasSize);
    assert(axisDirection() != nullptr);
    assert(growthDirection != nullptr);
    assert(child != nullptr);
    assert(child->geometry() != nullptr);
    ;
}

template<typename ParentDataClass>
void RenderViewportBaseCls<ParentDataClass>::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AxisDirection>make<EnumPropertyCls>(__s("axisDirection"), axisDirection()));
    properties->add(<AxisDirection>make<EnumPropertyCls>(__s("crossAxisDirection"), crossAxisDirection()));
    properties->add(<ViewportOffset>make<DiagnosticsPropertyCls>(__s("offset"), offset()));
}

template<typename ParentDataClass>
List<DiagnosticsNode> RenderViewportBaseCls<ParentDataClass>::debugDescribeChildren() {
    List<DiagnosticsNode> children = makeList();
    RenderSliver child = firstChild;
    if (child == nullptr) {
        return children;
    }
    int count = indexOfFirstChild();
    while (true) {
        children->add(child!->toDiagnosticsNode(labelForChild(count)));
        if (child == lastChild) {
            break;
        }
        count = 1;
        child = childAfter(child);
    }
    return children;
}

template<typename ParentDataClass>
void RenderViewportBaseCls<ParentDataClass>::showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect) {
    if (!offset()->allowImplicitScrolling()) {
        return super->showOnScreen(descendant, rect, duration, curve);
    }
    Rect newRect = RenderViewportBaseCls->showInViewport(descendant, this, offset(), rect, duration, curve);
    super->showOnScreen(newRect, duration, curve);
}

template<typename ParentDataClass>
Rect RenderViewportBaseCls<ParentDataClass>::showInViewport(Curve curve, RenderObject descendant, Duration duration, ViewportOffset offset, Rect rect, RenderAbstractViewport viewport) {
    assert(viewport != nullptr);
    assert(offset != nullptr);
    if (descendant == nullptr) {
        return rect;
    }
    RevealedOffset leadingEdgeOffset = viewport->getOffsetToReveal(descendant, 0.0rect);
    RevealedOffset trailingEdgeOffset = viewport->getOffsetToReveal(descendant, 1.0rect);
    double currentOffset = offset->pixels();
    RevealedOffset targetOffset;
    if (leadingEdgeOffset->offset < trailingEdgeOffset->offset) {
        double leadingEdgeDiff = (offset->pixels() - leadingEdgeOffset->offset)->abs();
        double trailingEdgeDiff = (offset->pixels() - trailingEdgeOffset->offset)->abs();
        targetOffset =  < trailingEdgeDiff? leadingEdgeOffset : trailingEdgeOffset;
    } else     {
        if (currentOffset > leadingEdgeOffset->offset) {
        targetOffset = leadingEdgeOffset;
    } else     {
        if ( < trailingEdgeOffset->offset) {
        targetOffset = trailingEdgeOffset;
    } else {
        Matrix4 transform = descendant->getTransformTo(as<RenderObject>(viewport->parent!));
        return MatrixUtilsCls->transformRect(transform, rect or descendant->paintBounds());
    }
;
    };
    }    assert(targetOffset != nullptr);
    offset->moveTo(targetOffset->offsetduration, curve);
    return targetOffset->rect;
}

template<typename ParentDataClass>
void RenderViewportBaseCls<ParentDataClass>::_paintContents(PaintingContext context, Offset offset) {
    for (RenderSliver child : childrenInPaintOrder()) {
        if (child->geometry!->visible) {
            context->paintChild(child, offset + paintOffsetOf(child));
        }
    }
}

RenderViewportCls::RenderViewportCls(double anchor, Unknown axisDirection, Unknown cacheExtent, Unknown cacheExtentStyle, RenderSliver center, List<RenderSliver> children, Unknown clipBehavior, Unknown crossAxisDirection, Unknown offset) {
    {
        assert(anchor != nullptr);
        assert(anchor >= 0.0 && anchor <= 1.0);
        assert(cacheExtentStyle != CacheExtentStyleCls::viewport || cacheExtent != nullptr);
        assert(clipBehavior != nullptr);
        _anchor = anchor;
        _center = center;
    }
    {
        addAll(children);
        if (center == nullptr && firstChild != nullptr) {
            _center = firstChild;
        }
    }
}

void RenderViewportCls::setupParentData(RenderObject child) {
    if (!is<SliverPhysicalContainerParentData>(child->parentData)) {
        child->parentData = make<SliverPhysicalContainerParentDataCls>();
    }
}

double RenderViewportCls::anchor() {
    return _anchor;
}

void RenderViewportCls::anchor(double value) {
    assert(value != nullptr);
    assert(value >= 0.0 && value <= 1.0);
    if (value == _anchor) {
        return;
    }
    _anchor = value;
    markNeedsLayout();
}

RenderSliver RenderViewportCls::center() {
    return _center;
}

void RenderViewportCls::center(RenderSliver value) {
    if (value == _center) {
        return;
    }
    _center = value;
    markNeedsLayout();
}

bool RenderViewportCls::sizedByParent() {
    return true;
}

Size RenderViewportCls::computeDryLayout(BoxConstraints constraints) {
    assert([=] () {
        if (!constraints->hasBoundedHeight() || !constraints->hasBoundedWidth()) {
            ;
        }
        return true;
    }());
    return constraints->biggest();
}

void RenderViewportCls::performLayout() {
    ;
    if (center() == nullptr) {
        assert(firstChild == nullptr);
        _minScrollExtent = 0.0;
        _maxScrollExtent = 0.0;
        _hasVisualOverflow = false;
        offset->applyContentDimensions(0.0, 0.0);
        return;
    }
    assert(center()!->parent == this);
    double mainAxisExtent;
    double crossAxisExtent;
    ;
    double centerOffsetAdjustment = center()!->centerOffsetAdjustment();
    double correction;
    int count = 0;
    do {
        assert(offset->pixels != nullptr);
        correction = _attemptLayout(mainAxisExtent, crossAxisExtent, offset->pixels + centerOffsetAdjustment);
        if (correction != 0.0) {
            offset->correctBy(correction);
        } else {
            if (offset->applyContentDimensions(math->min(0.0, _minScrollExtent + mainAxisExtent * anchor()), math->max(0.0, _maxScrollExtent - mainAxisExtent * (1.0 - anchor())))) {
                break;
            }
        }
        count = 1;
    } while ( < _maxLayoutCycles);
    assert([=] () {
        if (count >= _maxLayoutCycles) {
            assert(count != 1);
            ;
        }
        return true;
    }());
}

bool RenderViewportCls::hasVisualOverflow() {
    return _hasVisualOverflow;
}

void RenderViewportCls::updateOutOfBandData(SliverGeometry childLayoutGeometry, GrowthDirection growthDirection) {
    ;
    if (childLayoutGeometry->hasVisualOverflow) {
        _hasVisualOverflow = true;
    }
}

void RenderViewportCls::updateChildLayoutOffset(RenderSliver child, GrowthDirection growthDirection, double layoutOffset) {
    SliverPhysicalParentData childParentData = as<SliverPhysicalParentData>(child->parentData!);
    childParentData->paintOffset = computeAbsolutePaintOffset(child, layoutOffset, growthDirection);
}

Offset RenderViewportCls::paintOffsetOf(RenderSliver child) {
    SliverPhysicalParentData childParentData = as<SliverPhysicalParentData>(child->parentData!);
    return childParentData->paintOffset;
}

double RenderViewportCls::scrollOffsetOf(RenderSliver child, double scrollOffsetWithinChild) {
    assert(child->parent == this);
    GrowthDirection growthDirection = child->constraints()->growthDirection;
    assert(growthDirection != nullptr);
    ;
}

double RenderViewportCls::maxScrollObstructionExtentBefore(RenderSliver child) {
    assert(child->parent == this);
    GrowthDirection growthDirection = child->constraints()->growthDirection;
    assert(growthDirection != nullptr);
    ;
}

void RenderViewportCls::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(child != nullptr);
    SliverPhysicalParentData childParentData = as<SliverPhysicalParentData>(child->parentData!);
    childParentData->applyPaintTransform(transform);
}

double RenderViewportCls::computeChildMainAxisPosition(RenderSliver child, double parentMainAxisPosition) {
    assert(child != nullptr);
    assert(child->constraints() != nullptr);
    SliverPhysicalParentData childParentData = as<SliverPhysicalParentData>(child->parentData!);
    ;
}

int RenderViewportCls::indexOfFirstChild() {
    assert(center() != nullptr);
    assert(center()!->parent == this);
    assert(firstChild != nullptr);
    int count = 0;
    RenderSliver child = center();
    while (child != firstChild) {
        count = 1;
        child = childBefore(child!);
    }
    return count;
}

String RenderViewportCls::labelForChild(int index) {
    if (index == 0) {
        return __s("center child");
    }
    return __s("child $index");
}

Iterable<RenderSliver> RenderViewportCls::childrenInPaintOrder() {
    List<RenderSliver> children = makeList();
    if (firstChild == nullptr) {
        return children;
    }
    RenderSliver child = firstChild;
    while (child != center()) {
        children->add(child!);
        child = childAfter(child);
    }
    child = lastChild;
    while (true) {
        children->add(child!);
        if (child == center()) {
            return children;
        }
        child = childBefore(child);
    }
}

Iterable<RenderSliver> RenderViewportCls::childrenInHitTestOrder() {
    List<RenderSliver> children = makeList();
    if (firstChild == nullptr) {
        return children;
    }
    RenderSliver child = center();
    while (child != nullptr) {
        children->add(child);
        child = childAfter(child);
    }
    child = childBefore(center()!);
    while (child != nullptr) {
        children->add(child);
        child = childBefore(child);
    }
    return children;
}

void RenderViewportCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("anchor"), anchor()));
}

double RenderViewportCls::_attemptLayout(double correctedOffset, double crossAxisExtent, double mainAxisExtent) {
    assert(!mainAxisExtent->isNaN);
    assert(mainAxisExtent >= 0.0);
    assert(crossAxisExtent->isFinite);
    assert(crossAxisExtent >= 0.0);
    assert(correctedOffset->isFinite);
    _minScrollExtent = 0.0;
    _maxScrollExtent = 0.0;
    _hasVisualOverflow = false;
    double centerOffset = mainAxisExtent * anchor() - correctedOffset;
    double reverseDirectionRemainingPaintExtent = clampDouble(centerOffset, 0.0, mainAxisExtent);
    double forwardDirectionRemainingPaintExtent = clampDouble(mainAxisExtent - centerOffset, 0.0, mainAxisExtent);
    ;
    double fullCacheExtent = mainAxisExtent + 2 * _calculatedCacheExtent!;
    double centerCacheOffset = centerOffset + _calculatedCacheExtent!;
    double reverseDirectionRemainingCacheExtent = clampDouble(centerCacheOffset, 0.0, fullCacheExtent);
    double forwardDirectionRemainingCacheExtent = clampDouble(fullCacheExtent - centerCacheOffset, 0.0, fullCacheExtent);
    RenderSliver leadingNegativeChild = childBefore(center()!);
    if (leadingNegativeChild != nullptr) {
        double result = layoutChildSequence(leadingNegativeChild, math->max(mainAxisExtent, centerOffset) - mainAxisExtent, 0.0, forwardDirectionRemainingPaintExtent, reverseDirectionRemainingPaintExtent, mainAxisExtent, crossAxisExtent, GrowthDirectionCls::reverse, childBefore, reverseDirectionRemainingCacheExtent, clampDouble(mainAxisExtent - centerOffset, -_calculatedCacheExtent!, 0.0));
        if (result != 0.0) {
            return -result;
        }
    }
    return layoutChildSequence(center(), math->max(0.0, -centerOffset), leadingNegativeChild == nullptr? math->min(0.0, -centerOffset) : 0.0, centerOffset >= mainAxisExtent? centerOffset : reverseDirectionRemainingPaintExtent, forwardDirectionRemainingPaintExtent, mainAxisExtent, crossAxisExtent, GrowthDirectionCls::forward, childAfter, forwardDirectionRemainingCacheExtent, clampDouble(centerOffset, -_calculatedCacheExtent!, 0.0));
}

RenderShrinkWrappingViewportCls::RenderShrinkWrappingViewportCls(Unknown axisDirection, List<RenderSliver> children, Unknown clipBehavior, Unknown crossAxisDirection, Unknown offset) {
    {
        addAll(children);
    }
}

void RenderShrinkWrappingViewportCls::setupParentData(RenderObject child) {
    if (!is<SliverLogicalContainerParentData>(child->parentData)) {
        child->parentData = make<SliverLogicalContainerParentDataCls>();
    }
}

bool RenderShrinkWrappingViewportCls::debugThrowIfNotCheckingIntrinsics() {
    assert([=] () {
        if (!RenderObjectCls->debugCheckingIntrinsics) {
            ;
        }
        return true;
    }());
    return true;
}

void RenderShrinkWrappingViewportCls::performLayout() {
    BoxConstraints constraints = this->constraints;
    if (firstChild == nullptr) {
        ;
        offset->applyViewportDimension(0.0);
        _maxScrollExtent = 0.0;
        _shrinkWrapExtent = 0.0;
        _hasVisualOverflow = false;
        offset->applyContentDimensions(0.0, 0.0);
        return;
    }
    double mainAxisExtent;
    double crossAxisExtent;
    ;
    double correction;
    double effectiveExtent;
    do {
        assert(offset->pixels != nullptr);
        correction = _attemptLayout(mainAxisExtent, crossAxisExtent, offset->pixels);
        if (correction != 0.0) {
            offset->correctBy(correction);
        } else {
            ;
            bool didAcceptViewportDimension = offset->applyViewportDimension(effectiveExtent);
            bool didAcceptContentDimension = offset->applyContentDimensions(0.0, math->max(0.0, _maxScrollExtent - effectiveExtent));
            if (didAcceptViewportDimension && didAcceptContentDimension) {
                break;
            }
        }
    } while (true);
    ;
}

bool RenderShrinkWrappingViewportCls::hasVisualOverflow() {
    return _hasVisualOverflow;
}

void RenderShrinkWrappingViewportCls::updateOutOfBandData(SliverGeometry childLayoutGeometry, GrowthDirection growthDirection) {
    assert(growthDirection == GrowthDirectionCls::forward);
    _maxScrollExtent = childLayoutGeometry->scrollExtent;
    if (childLayoutGeometry->hasVisualOverflow) {
        _hasVisualOverflow = true;
    }
    _shrinkWrapExtent = childLayoutGeometry->maxPaintExtent;
}

void RenderShrinkWrappingViewportCls::updateChildLayoutOffset(RenderSliver child, GrowthDirection growthDirection, double layoutOffset) {
    assert(growthDirection == GrowthDirectionCls::forward);
    SliverLogicalParentData childParentData = as<SliverLogicalParentData>(child->parentData!);
    childParentData->layoutOffset = layoutOffset;
}

Offset RenderShrinkWrappingViewportCls::paintOffsetOf(RenderSliver child) {
    SliverLogicalParentData childParentData = as<SliverLogicalParentData>(child->parentData!);
    return computeAbsolutePaintOffset(child, childParentData->layoutOffset!, GrowthDirectionCls::forward);
}

double RenderShrinkWrappingViewportCls::scrollOffsetOf(RenderSliver child, double scrollOffsetWithinChild) {
    assert(child->parent == this);
    assert(child->constraints()->growthDirection == GrowthDirectionCls::forward);
    double scrollOffsetToChild = 0.0;
    RenderSliver current = firstChild;
    while (current != child) {
        scrollOffsetToChild = current!->geometry()!->scrollExtent;
        current = childAfter(current);
    }
    return scrollOffsetToChild + scrollOffsetWithinChild;
}

double RenderShrinkWrappingViewportCls::maxScrollObstructionExtentBefore(RenderSliver child) {
    assert(child->parent == this);
    assert(child->constraints()->growthDirection == GrowthDirectionCls::forward);
    double pinnedExtent = 0.0;
    RenderSliver current = firstChild;
    while (current != child) {
        pinnedExtent = current!->geometry()!->maxScrollObstructionExtent;
        current = childAfter(current);
    }
    return pinnedExtent;
}

void RenderShrinkWrappingViewportCls::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(child != nullptr);
    Offset offset = paintOffsetOf(as<RenderSliver>(child));
    transform->translate(offset->dx(), offset->dy());
}

double RenderShrinkWrappingViewportCls::computeChildMainAxisPosition(RenderSliver child, double parentMainAxisPosition) {
    assert(child != nullptr);
    assert(child->constraints() != nullptr);
    assert(hasSize);
    SliverLogicalParentData childParentData = as<SliverLogicalParentData>(child->parentData!);
    ;
}

int RenderShrinkWrappingViewportCls::indexOfFirstChild() {
    return 0;
}

String RenderShrinkWrappingViewportCls::labelForChild(int index) {
    return __s("child $index");
}

Iterable<RenderSliver> RenderShrinkWrappingViewportCls::childrenInPaintOrder() {
    List<RenderSliver> children = makeList();
    RenderSliver child = lastChild;
    while (child != nullptr) {
        children->add(child);
        child = childBefore(child);
    }
    return children;
}

Iterable<RenderSliver> RenderShrinkWrappingViewportCls::childrenInHitTestOrder() {
    List<RenderSliver> children = makeList();
    RenderSliver child = firstChild;
    while (child != nullptr) {
        children->add(child);
        child = childAfter(child);
    }
    return children;
}

double RenderShrinkWrappingViewportCls::_attemptLayout(double correctedOffset, double crossAxisExtent, double mainAxisExtent) {
    assert(!mainAxisExtent->isNaN);
    assert(mainAxisExtent >= 0.0);
    assert(crossAxisExtent->isFinite);
    assert(crossAxisExtent >= 0.0);
    assert(correctedOffset->isFinite);
    _maxScrollExtent = 0.0;
    _shrinkWrapExtent = 0.0;
    _hasVisualOverflow =  < 0.0;
    ;
    return layoutChildSequence(firstChild, math->max(0.0, correctedOffset), math->min(0.0, correctedOffset), math->max(0.0, -correctedOffset), mainAxisExtent + math->min(0.0, correctedOffset), mainAxisExtent, crossAxisExtent, GrowthDirectionCls::forward, childAfter, mainAxisExtent + 2 * _calculatedCacheExtent!, -_calculatedCacheExtent!);
}
