#include "viewport.hpp"
RenderAbstractViewport RenderAbstractViewport::of(RenderObject object) {
    while (object != nullptr) {
        if (object is RenderAbstractViewport) {
            return object;
        }
        object = (;
    }
    return nullptr;
}

RevealedOffset::RevealedOffset(double offset, Rect rect) {
    {
        assert(offset != nullptr);
        assert(rect != nullptr);
    }
}

String RevealedOffset::toString() {
    return "${objectRuntimeType(this, 'RevealedOffset')}(offset: $offset, rect: $rect)";
}

RenderViewportBase::RenderViewportBase(AxisDirection axisDirection, double cacheExtent, CacheExtentStyle cacheExtentStyle, Clip clipBehavior, AxisDirection crossAxisDirection, ViewportOffset offset) {
    {
        assert(axisDirection != nullptr);
        assert(crossAxisDirection != nullptr);
        assert(offset != nullptr);
        assert(axisDirectionToAxis(axisDirection) != axisDirectionToAxis(crossAxisDirection));
        assert(cacheExtentStyle != nullptr);
        assert(cacheExtent != nullptr || cacheExtentStyle == CacheExtentStyle.pixel);
        assert(clipBehavior != nullptr);
        _axisDirection = axisDirection;
        _crossAxisDirection = crossAxisDirection;
        _offset = offset;
        _cacheExtent = cacheExtent ?? RenderAbstractViewport.defaultCacheExtent;
        _cacheExtentStyle = cacheExtentStyle;
        _clipBehavior = clipBehavior;
    }
}

void RenderViewportBase::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super.describeSemanticsConfiguration(config);
    config.addTagForChildren(RenderViewport.useTwoPaneSemantics);
}

void RenderViewportBase::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    childrenInPaintOrder.where().forEach(visitor);
}

AxisDirection RenderViewportBase::axisDirection() {
    return _axisDirection;
}

void RenderViewportBase::axisDirection(AxisDirection value) {
    assert(value != nullptr);
    if (value == _axisDirection) {
        return;
    }
    _axisDirection = value;
    markNeedsLayout();
}

AxisDirection RenderViewportBase::crossAxisDirection() {
    return _crossAxisDirection;
}

void RenderViewportBase::crossAxisDirection(AxisDirection value) {
    assert(value != nullptr);
    if (value == _crossAxisDirection) {
        return;
    }
    _crossAxisDirection = value;
    markNeedsLayout();
}

Axis RenderViewportBase::axis() {
    return axisDirectionToAxis(axisDirection);
}

ViewportOffset RenderViewportBase::offset() {
    return _offset;
}

void RenderViewportBase::offset(ViewportOffset value) {
    assert(value != nullptr);
    if (value == _offset) {
        return;
    }
    if (attached) {
        _offset.removeListener(markNeedsLayout);
    }
    _offset = value;
    if (attached) {
        _offset.addListener(markNeedsLayout);
    }
    markNeedsLayout();
}

double RenderViewportBase::cacheExtent() {
    return _cacheExtent;
}

void RenderViewportBase::cacheExtent(double value) {
    value = RenderAbstractViewport.defaultCacheExtent;
    assert(value != nullptr);
    if (value == _cacheExtent) {
        return;
    }
    _cacheExtent = value;
    markNeedsLayout();
}

CacheExtentStyle RenderViewportBase::cacheExtentStyle() {
    return _cacheExtentStyle;
}

void RenderViewportBase::cacheExtentStyle(CacheExtentStyle value) {
    assert(value != nullptr);
    if (value == _cacheExtentStyle) {
        return;
    }
    _cacheExtentStyle = value;
    markNeedsLayout();
}

Clip RenderViewportBase::clipBehavior() {
    return _clipBehavior;
}

void RenderViewportBase::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

void RenderViewportBase::attach(PipelineOwner owner) {
    super.attach(owner);
    _offset.addListener(markNeedsLayout);
}

void RenderViewportBase::detach() {
    _offset.removeListener(markNeedsLayout);
    super.detach();
}

bool RenderViewportBase::debugThrowIfNotCheckingIntrinsics() {
    assert(());
    return true;
}

double RenderViewportBase::computeMinIntrinsicWidth(double height) {
    assert(debugThrowIfNotCheckingIntrinsics());
    return 0.0;
}

double RenderViewportBase::computeMaxIntrinsicWidth(double height) {
    assert(debugThrowIfNotCheckingIntrinsics());
    return 0.0;
}

double RenderViewportBase::computeMinIntrinsicHeight(double width) {
    assert(debugThrowIfNotCheckingIntrinsics());
    return 0.0;
}

double RenderViewportBase::computeMaxIntrinsicHeight(double width) {
    assert(debugThrowIfNotCheckingIntrinsics());
    return 0.0;
}

bool RenderViewportBase::isRepaintBoundary() {
    return true;
}

double RenderViewportBase::layoutChildSequence(FunctionType advance, double cacheOrigin, RenderSliver child, double crossAxisExtent, GrowthDirection growthDirection, double layoutOffset, double mainAxisExtent, double overlap, double remainingCacheExtent, double remainingPaintExtent, double scrollOffset) {
    assert(scrollOffset.isFinite);
    assert(scrollOffset >= 0.0);
    double initialLayoutOffset = layoutOffset;
    ScrollDirection adjustedUserScrollDirection = applyGrowthDirectionToScrollDirection(offset.userScrollDirection, growthDirection);
    assert(adjustedUserScrollDirection != nullptr);
    double maxPaintOffset = layoutOffset + overlap;
    double precedingScrollExtent = 0.0;
    while (child != nullptr) {
        double sliverScrollOffset = scrollOffset <= 0.0? 0.0 : scrollOffset;
        double correctedCacheOrigin = math.max(cacheOrigin, -sliverScrollOffset);
        double cacheExtentCorrection = cacheOrigin - correctedCacheOrigin;
        assert(sliverScrollOffset >= correctedCacheOrigin.abs());
        assert(correctedCacheOrigin <= 0.0);
        assert(sliverScrollOffset >= 0.0);
        assert(cacheExtentCorrection <= 0.0);
        child.layout(SliverConstraints(axisDirection, growthDirection, adjustedUserScrollDirection, sliverScrollOffset, precedingScrollExtent, maxPaintOffset - layoutOffset, math.max(0.0, remainingPaintExtent - layoutOffset + initialLayoutOffset), crossAxisExtent, crossAxisDirection, mainAxisExtent, math.max(0.0, remainingCacheExtent + cacheExtentCorrection), correctedCacheOrigin)true);
        SliverGeometry childLayoutGeometry = child.geometry!;
        assert(childLayoutGeometry.debugAssertIsValid());
        if (childLayoutGeometry.scrollOffsetCorrection != nullptr) {
            return childLayoutGeometry.scrollOffsetCorrection!;
        }
        double effectiveLayoutOffset = layoutOffset + childLayoutGeometry.paintOrigin;
        if (childLayoutGeometry.visible || scrollOffset > 0) {
            updateChildLayoutOffset(child, effectiveLayoutOffset, growthDirection);
        } else {
            updateChildLayoutOffset(child, -scrollOffset + initialLayoutOffset, growthDirection);
        }
        maxPaintOffset = math.max(effectiveLayoutOffset + childLayoutGeometry.paintExtent, maxPaintOffset);
        scrollOffset = childLayoutGeometry.scrollExtent;
        precedingScrollExtent = childLayoutGeometry.scrollExtent;
        layoutOffset = childLayoutGeometry.layoutExtent;
        if (childLayoutGeometry.cacheExtent != 0.0) {
            remainingCacheExtent = childLayoutGeometry.cacheExtent - cacheExtentCorrection;
            cacheOrigin = math.min(correctedCacheOrigin + childLayoutGeometry.cacheExtent, 0.0);
        }
        updateOutOfBandData(growthDirection, childLayoutGeometry);
        child = advance(child);
    }
    return 0.0;
}

Rect RenderViewportBase::describeApproximatePaintClip(RenderSliver child) {
    ;
    Rect viewportClip = Offset.zero & size;
    if (child.constraints.overlap == 0 || !child.constraints.viewportMainAxisExtent.isFinite) {
        return viewportClip;
    }
    double left = viewportClip.left;
    double right = viewportClip.right;
    double top = viewportClip.top;
    double bottom = viewportClip.bottom;
    double startOfOverlap = child.constraints.viewportMainAxisExtent - child.constraints.remainingPaintExtent;
    double overlapCorrection = startOfOverlap + child.constraints.overlap;
    ;
    return Rect.fromLTRB(left, top, right, bottom);
}

Rect RenderViewportBase::describeSemanticsClip(RenderSliver child) {
    assert(axis != nullptr);
    if (_calculatedCacheExtent == nullptr) {
        return semanticBounds;
    }
    ;
}

void RenderViewportBase::paint(PaintingContext context, Offset offset) {
    if (firstChild == nullptr) {
        return;
    }
    if (hasVisualOverflow && clipBehavior != Clip.none) {
        _clipRectLayer.layer = context.pushClipRect(needsCompositing, offset, Offset.zero & size, _paintContentsclipBehavior, _clipRectLayer.layer);
    } else {
        _clipRectLayer.layer = nullptr;
        _paintContents(context, offset);
    }
}

void RenderViewportBase::dispose() {
    _clipRectLayer.layer = nullptr;
    super.dispose();
}

void RenderViewportBase::debugPaintSize(PaintingContext context, Offset offset) {
    assert(());
}

bool RenderViewportBase::hitTestChildren(Offset position, BoxHitTestResult result) {
    double mainAxisPosition, crossAxisPosition;
    ;
    assert(mainAxisPosition != nullptr);
    assert(crossAxisPosition != nullptr);
    SliverHitTestResult sliverResult = SliverHitTestResult.wrap(result);
    for (RenderSliver child : childrenInHitTestOrder) {
        if (!child.geometry!.visible) {
            continue;
        }
        Matrix4 transform = Matrix4.identity();
        applyPaintTransform(child, transform);
        bool isHit = result.addWithOutOfBandPosition(transform, );
        if (isHit) {
            return true;
        }
    }
    return false;
}

RevealedOffset RenderViewportBase::getOffsetToReveal(double alignment, Rect rect, RenderObject target) {
    double leadingScrollOffset = 0.0;
    RenderObject child = target;
    RenderBox pivot;
    bool onlySlivers = target is RenderSliver;
    while (child.parent != this) {
        RenderObject parent = (;
        assert(parent != nullptr, "$target must be a descendant of $this");
        if (child is RenderBox) {
            pivot = child;
        }
        if (parent is RenderSliver) {
            leadingScrollOffset = parent.childScrollOffset(child)!;
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
        assert(pivot.parent != nullptr);
        assert(pivot.parent != this);
        assert(pivot != this);
        assert(pivot.parent is RenderSliver);
        RenderSliver pivotParent = (;
        growthDirection = pivotParent.constraints.growthDirection;
        ;
        rect = target.paintBounds;
        rectLocal = MatrixUtils.transformRect(target.getTransformTo(pivot), rect);
    } else     {
        if (onlySlivers) {
        RenderSliver targetSliver = (;
        growthDirection = targetSliver.constraints.growthDirection;
        pivotExtent = targetSliver.geometry!.scrollExtent;
        if (rect == nullptr) {
            ;
        }
        rectLocal = rect;
    } else {
        assert(rect != nullptr);
        return RevealedOffset(offset.pixels, rect!);
    }
;
    }    assert(pivotExtent != nullptr);
    assert(rect != nullptr);
    assert(rectLocal != nullptr);
    assert(growthDirection != nullptr);
    assert(child.parent == this);
    assert(child is RenderSliver);
    RenderSliver sliver = (;
    double targetMainAxisExtent;
    ;
    bool isPinned = sliver.geometry!.maxScrollObstructionExtent > 0 && leadingScrollOffset >= 0;
    leadingScrollOffset = scrollOffsetOf(sliver, leadingScrollOffset);
    Matrix4 transform = target.getTransformTo(this);
    Rect targetRect = MatrixUtils.transformRect(transform, rect);
    double extentOfPinnedSlivers = maxScrollObstructionExtentBefore(sliver);
    ;
    double mainAxisExtent;
    ;
    double targetOffset = leadingScrollOffset - (mainAxisExtent - targetMainAxisExtent) * alignment;
    double offsetDifference = offset.pixels - targetOffset;
    ;
    return RevealedOffset(targetOffset, targetRect);
}

Offset RenderViewportBase::computeAbsolutePaintOffset(RenderSliver child, GrowthDirection growthDirection, double layoutOffset) {
    assert(hasSize);
    assert(axisDirection != nullptr);
    assert(growthDirection != nullptr);
    assert(child != nullptr);
    assert(child.geometry != nullptr);
    ;
}

void RenderViewportBase::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AxisDirection>EnumProperty("axisDirection", axisDirection));
    properties.add(<AxisDirection>EnumProperty("crossAxisDirection", crossAxisDirection));
    properties.add(<ViewportOffset>DiagnosticsProperty("offset", offset));
}

List<DiagnosticsNode> RenderViewportBase::debugDescribeChildren() {
    List<DiagnosticsNode> children = ;
    RenderSliver child = firstChild;
    if (child == nullptr) {
        return children;
    }
    int count = indexOfFirstChild;
    while (true) {
        children.add(child!.toDiagnosticsNode(labelForChild(count)));
        if (child == lastChild) {
                        break;
        }
        count = 1;
        child = childAfter(child);
    }
    return children;
}

void RenderViewportBase::showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect) {
    if (!offset.allowImplicitScrolling) {
        return super.showOnScreen(descendant, rect, duration, curve);
    }
    Rect newRect = RenderViewportBase.showInViewport(descendant, this, offset, rect, duration, curve);
    super.showOnScreen(newRect, duration, curve);
}

Rect RenderViewportBase::showInViewport(Curve curve, RenderObject descendant, Duration duration, ViewportOffset offset, Rect rect, RenderAbstractViewport viewport) {
    assert(viewport != nullptr);
    assert(offset != nullptr);
    if (descendant == nullptr) {
        return rect;
    }
    RevealedOffset leadingEdgeOffset = viewport.getOffsetToReveal(descendant, 0.0rect);
    RevealedOffset trailingEdgeOffset = viewport.getOffsetToReveal(descendant, 1.0rect);
    double currentOffset = offset.pixels;
    RevealedOffset targetOffset;
    if (leadingEdgeOffset.offset < trailingEdgeOffset.offset) {
        double leadingEdgeDiff = (offset.pixels - leadingEdgeOffset.offset).abs();
        double trailingEdgeDiff = (offset.pixels - trailingEdgeOffset.offset).abs();
        targetOffset =  < trailingEdgeDiff? leadingEdgeOffset : trailingEdgeOffset;
    } else     {
        if (currentOffset > leadingEdgeOffset.offset) {
        targetOffset = leadingEdgeOffset;
    } else     {
        if ( < trailingEdgeOffset.offset) {
        targetOffset = trailingEdgeOffset;
    } else {
        Matrix4 transform = descendant.getTransformTo(();
        return MatrixUtils.transformRect(transform, rect ?? descendant.paintBounds);
    }
;
    };
    }    assert(targetOffset != nullptr);
    offset.moveTo(targetOffset.offsetduration, curve);
    return targetOffset.rect;
}

void RenderViewportBase::_paintContents(PaintingContext context, Offset offset) {
    for (RenderSliver child : childrenInPaintOrder) {
        if (child.geometry!.visible) {
            context.paintChild(child, offset + paintOffsetOf(child));
        }
    }
}

RenderViewport::RenderViewport(double anchor, Unknown, Unknown, Unknown, RenderSliver center, List<RenderSliver> children, Unknown, Unknown, Unknown) {
    {
        assert(anchor != nullptr);
        assert(anchor >= 0.0 && anchor <= 1.0);
        assert(cacheExtentStyle != CacheExtentStyle.viewport || cacheExtent != nullptr);
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

void RenderViewport::setupParentData(RenderObject child) {
    if (child.parentData is! SliverPhysicalContainerParentData) {
        child.parentData = SliverPhysicalContainerParentData();
    }
}

double RenderViewport::anchor() {
    return _anchor;
}

void RenderViewport::anchor(double value) {
    assert(value != nullptr);
    assert(value >= 0.0 && value <= 1.0);
    if (value == _anchor) {
        return;
    }
    _anchor = value;
    markNeedsLayout();
}

RenderSliver RenderViewport::center() {
    return _center;
}

void RenderViewport::center(RenderSliver value) {
    if (value == _center) {
        return;
    }
    _center = value;
    markNeedsLayout();
}

bool RenderViewport::sizedByParent() {
    return true;
}

Size RenderViewport::computeDryLayout(BoxConstraints constraints) {
    assert(());
    return constraints.biggest;
}

void RenderViewport::performLayout() {
    ;
    if (center == nullptr) {
        assert(firstChild == nullptr);
        _minScrollExtent = 0.0;
        _maxScrollExtent = 0.0;
        _hasVisualOverflow = false;
        offset.applyContentDimensions(0.0, 0.0);
        return;
    }
    assert(center!.parent == this);
    double mainAxisExtent;
    double crossAxisExtent;
    ;
    double centerOffsetAdjustment = center!.centerOffsetAdjustment;
    double correction;
    int count = 0;
    do {
        assert(offset.pixels != nullptr);
        correction = _attemptLayout(mainAxisExtent, crossAxisExtent, offset.pixels + centerOffsetAdjustment);
        if (correction != 0.0) {
            offset.correctBy(correction);
        } else {
            if (offset.applyContentDimensions(math.min(0.0, _minScrollExtent + mainAxisExtent * anchor), math.max(0.0, _maxScrollExtent - mainAxisExtent * (1.0 - anchor)))) {
                                break;
            }
        }
        count = 1;
    } while ( < _maxLayoutCycles);
    assert(());
}

bool RenderViewport::hasVisualOverflow() {
    return _hasVisualOverflow;
}

void RenderViewport::updateOutOfBandData(SliverGeometry childLayoutGeometry, GrowthDirection growthDirection) {
    ;
    if (childLayoutGeometry.hasVisualOverflow) {
        _hasVisualOverflow = true;
    }
}

void RenderViewport::updateChildLayoutOffset(RenderSliver child, GrowthDirection growthDirection, double layoutOffset) {
    SliverPhysicalParentData childParentData = (;
    childParentData.paintOffset = computeAbsolutePaintOffset(child, layoutOffset, growthDirection);
}

Offset RenderViewport::paintOffsetOf(RenderSliver child) {
    SliverPhysicalParentData childParentData = (;
    return childParentData.paintOffset;
}

double RenderViewport::scrollOffsetOf(RenderSliver child, double scrollOffsetWithinChild) {
    assert(child.parent == this);
    GrowthDirection growthDirection = child.constraints.growthDirection;
    assert(growthDirection != nullptr);
    ;
}

double RenderViewport::maxScrollObstructionExtentBefore(RenderSliver child) {
    assert(child.parent == this);
    GrowthDirection growthDirection = child.constraints.growthDirection;
    assert(growthDirection != nullptr);
    ;
}

void RenderViewport::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(child != nullptr);
    SliverPhysicalParentData childParentData = (;
    childParentData.applyPaintTransform(transform);
}

double RenderViewport::computeChildMainAxisPosition(RenderSliver child, double parentMainAxisPosition) {
    assert(child != nullptr);
    assert(child.constraints != nullptr);
    SliverPhysicalParentData childParentData = (;
    ;
}

int RenderViewport::indexOfFirstChild() {
    assert(center != nullptr);
    assert(center!.parent == this);
    assert(firstChild != nullptr);
    int count = 0;
    RenderSliver child = center;
    while (child != firstChild) {
        count = 1;
        child = childBefore(child!);
    }
    return count;
}

String RenderViewport::labelForChild(int index) {
    if (index == 0) {
        return "center child";
    }
    return "child $index";
}

Iterable<RenderSliver> RenderViewport::childrenInPaintOrder() {
    List<RenderSliver> children = ;
    if (firstChild == nullptr) {
        return children;
    }
    RenderSliver child = firstChild;
    while (child != center) {
        children.add(child!);
        child = childAfter(child);
    }
    child = lastChild;
    while (true) {
        children.add(child!);
        if (child == center) {
            return children;
        }
        child = childBefore(child);
    }
}

Iterable<RenderSliver> RenderViewport::childrenInHitTestOrder() {
    List<RenderSliver> children = ;
    if (firstChild == nullptr) {
        return children;
    }
    RenderSliver child = center;
    while (child != nullptr) {
        children.add(child);
        child = childAfter(child);
    }
    child = childBefore(center!);
    while (child != nullptr) {
        children.add(child);
        child = childBefore(child);
    }
    return children;
}

void RenderViewport::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("anchor", anchor));
}

double RenderViewport::_attemptLayout(double correctedOffset, double crossAxisExtent, double mainAxisExtent) {
    assert(!mainAxisExtent.isNaN);
    assert(mainAxisExtent >= 0.0);
    assert(crossAxisExtent.isFinite);
    assert(crossAxisExtent >= 0.0);
    assert(correctedOffset.isFinite);
    _minScrollExtent = 0.0;
    _maxScrollExtent = 0.0;
    _hasVisualOverflow = false;
    double centerOffset = mainAxisExtent * anchor - correctedOffset;
    double reverseDirectionRemainingPaintExtent = clampDouble(centerOffset, 0.0, mainAxisExtent);
    double forwardDirectionRemainingPaintExtent = clampDouble(mainAxisExtent - centerOffset, 0.0, mainAxisExtent);
    ;
    double fullCacheExtent = mainAxisExtent + 2 * _calculatedCacheExtent!;
    double centerCacheOffset = centerOffset + _calculatedCacheExtent!;
    double reverseDirectionRemainingCacheExtent = clampDouble(centerCacheOffset, 0.0, fullCacheExtent);
    double forwardDirectionRemainingCacheExtent = clampDouble(fullCacheExtent - centerCacheOffset, 0.0, fullCacheExtent);
    RenderSliver leadingNegativeChild = childBefore(center!);
    if (leadingNegativeChild != nullptr) {
        double result = layoutChildSequence(leadingNegativeChild, math.max(mainAxisExtent, centerOffset) - mainAxisExtent, 0.0, forwardDirectionRemainingPaintExtent, reverseDirectionRemainingPaintExtent, mainAxisExtent, crossAxisExtent, GrowthDirection.reverse, childBefore, reverseDirectionRemainingCacheExtent, clampDouble(mainAxisExtent - centerOffset, -_calculatedCacheExtent!, 0.0));
        if (result != 0.0) {
            return -result;
        }
    }
    return layoutChildSequence(center, math.max(0.0, -centerOffset), leadingNegativeChild == nullptr? math.min(0.0, -centerOffset) : 0.0, centerOffset >= mainAxisExtent? centerOffset : reverseDirectionRemainingPaintExtent, forwardDirectionRemainingPaintExtent, mainAxisExtent, crossAxisExtent, GrowthDirection.forward, childAfter, forwardDirectionRemainingCacheExtent, clampDouble(centerOffset, -_calculatedCacheExtent!, 0.0));
}

RenderShrinkWrappingViewport::RenderShrinkWrappingViewport(Unknown, List<RenderSliver> children, Unknown, Unknown, Unknown) {
    {
        addAll(children);
    }
}

void RenderShrinkWrappingViewport::setupParentData(RenderObject child) {
    if (child.parentData is! SliverLogicalContainerParentData) {
        child.parentData = SliverLogicalContainerParentData();
    }
}

bool RenderShrinkWrappingViewport::debugThrowIfNotCheckingIntrinsics() {
    assert(());
    return true;
}

void RenderShrinkWrappingViewport::performLayout() {
    BoxConstraints constraints = this.constraints;
    if (firstChild == nullptr) {
        ;
        offset.applyViewportDimension(0.0);
        _maxScrollExtent = 0.0;
        _shrinkWrapExtent = 0.0;
        _hasVisualOverflow = false;
        offset.applyContentDimensions(0.0, 0.0);
        return;
    }
    double mainAxisExtent;
    double crossAxisExtent;
    ;
    double correction;
    double effectiveExtent;
    do {
        assert(offset.pixels != nullptr);
        correction = _attemptLayout(mainAxisExtent, crossAxisExtent, offset.pixels);
        if (correction != 0.0) {
            offset.correctBy(correction);
        } else {
            ;
            bool didAcceptViewportDimension = offset.applyViewportDimension(effectiveExtent);
            bool didAcceptContentDimension = offset.applyContentDimensions(0.0, math.max(0.0, _maxScrollExtent - effectiveExtent));
            if (didAcceptViewportDimension && didAcceptContentDimension) {
                                break;
            }
        }
    } while (true);
    ;
}

bool RenderShrinkWrappingViewport::hasVisualOverflow() {
    return _hasVisualOverflow;
}

void RenderShrinkWrappingViewport::updateOutOfBandData(SliverGeometry childLayoutGeometry, GrowthDirection growthDirection) {
    assert(growthDirection == GrowthDirection.forward);
    _maxScrollExtent = childLayoutGeometry.scrollExtent;
    if (childLayoutGeometry.hasVisualOverflow) {
        _hasVisualOverflow = true;
    }
    _shrinkWrapExtent = childLayoutGeometry.maxPaintExtent;
}

void RenderShrinkWrappingViewport::updateChildLayoutOffset(RenderSliver child, GrowthDirection growthDirection, double layoutOffset) {
    assert(growthDirection == GrowthDirection.forward);
    SliverLogicalParentData childParentData = (;
    childParentData.layoutOffset = layoutOffset;
}

Offset RenderShrinkWrappingViewport::paintOffsetOf(RenderSliver child) {
    SliverLogicalParentData childParentData = (;
    return computeAbsolutePaintOffset(child, childParentData.layoutOffset!, GrowthDirection.forward);
}

double RenderShrinkWrappingViewport::scrollOffsetOf(RenderSliver child, double scrollOffsetWithinChild) {
    assert(child.parent == this);
    assert(child.constraints.growthDirection == GrowthDirection.forward);
    double scrollOffsetToChild = 0.0;
    RenderSliver current = firstChild;
    while (current != child) {
        scrollOffsetToChild = current!.geometry!.scrollExtent;
        current = childAfter(current);
    }
    return scrollOffsetToChild + scrollOffsetWithinChild;
}

double RenderShrinkWrappingViewport::maxScrollObstructionExtentBefore(RenderSliver child) {
    assert(child.parent == this);
    assert(child.constraints.growthDirection == GrowthDirection.forward);
    double pinnedExtent = 0.0;
    RenderSliver current = firstChild;
    while (current != child) {
        pinnedExtent = current!.geometry!.maxScrollObstructionExtent;
        current = childAfter(current);
    }
    return pinnedExtent;
}

void RenderShrinkWrappingViewport::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(child != nullptr);
    Offset offset = paintOffsetOf(();
    transform.translate(offset.dx, offset.dy);
}

double RenderShrinkWrappingViewport::computeChildMainAxisPosition(RenderSliver child, double parentMainAxisPosition) {
    assert(child != nullptr);
    assert(child.constraints != nullptr);
    assert(hasSize);
    SliverLogicalParentData childParentData = (;
    ;
}

int RenderShrinkWrappingViewport::indexOfFirstChild() {
    return 0;
}

String RenderShrinkWrappingViewport::labelForChild(int index) {
    return "child $index";
}

Iterable<RenderSliver> RenderShrinkWrappingViewport::childrenInPaintOrder() {
    List<RenderSliver> children = ;
    RenderSliver child = lastChild;
    while (child != nullptr) {
        children.add(child);
        child = childBefore(child);
    }
    return children;
}

Iterable<RenderSliver> RenderShrinkWrappingViewport::childrenInHitTestOrder() {
    List<RenderSliver> children = ;
    RenderSliver child = firstChild;
    while (child != nullptr) {
        children.add(child);
        child = childAfter(child);
    }
    return children;
}

double RenderShrinkWrappingViewport::_attemptLayout(double correctedOffset, double crossAxisExtent, double mainAxisExtent) {
    assert(!mainAxisExtent.isNaN);
    assert(mainAxisExtent >= 0.0);
    assert(crossAxisExtent.isFinite);
    assert(crossAxisExtent >= 0.0);
    assert(correctedOffset.isFinite);
    _maxScrollExtent = 0.0;
    _shrinkWrapExtent = 0.0;
    _hasVisualOverflow =  < 0.0;
    ;
    return layoutChildSequence(firstChild, math.max(0.0, correctedOffset), math.min(0.0, correctedOffset), math.max(0.0, -correctedOffset), mainAxisExtent + math.min(0.0, correctedOffset), mainAxisExtent, crossAxisExtent, GrowthDirection.forward, childAfter, mainAxisExtent + 2 * _calculatedCacheExtent!, -_calculatedCacheExtent!);
}
