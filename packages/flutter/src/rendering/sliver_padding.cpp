#include "sliver_padding.hpp"
double RenderSliverEdgeInsetsPadding::beforePadding() {
    assert(constraints != nullptr);
    assert(constraints.axisDirection != nullptr);
    assert(constraints.growthDirection != nullptr);
    assert(resolvedPadding != nullptr);
    ;
}

double RenderSliverEdgeInsetsPadding::afterPadding() {
    assert(constraints != nullptr);
    assert(constraints.axisDirection != nullptr);
    assert(constraints.growthDirection != nullptr);
    assert(resolvedPadding != nullptr);
    ;
}

double RenderSliverEdgeInsetsPadding::mainAxisPadding() {
    assert(constraints != nullptr);
    assert(constraints.axis != nullptr);
    assert(resolvedPadding != nullptr);
    return resolvedPadding!.along(constraints.axis);
}

double RenderSliverEdgeInsetsPadding::crossAxisPadding() {
    assert(constraints != nullptr);
    assert(constraints.axis != nullptr);
    assert(resolvedPadding != nullptr);
    ;
}

void RenderSliverEdgeInsetsPadding::setupParentData(RenderObject child) {
    if (child.parentData is! SliverPhysicalParentData) {
        child.parentData = SliverPhysicalParentData();
    }
}

void RenderSliverEdgeInsetsPadding::performLayout() {
    SliverConstraints constraints = this.constraints;
    assert(resolvedPadding != nullptr);
    double beforePadding = this.beforePadding;
    double afterPadding = this.afterPadding;
    double mainAxisPadding = this.mainAxisPadding;
    double crossAxisPadding = this.crossAxisPadding;
    if (child == nullptr) {
        double paintExtent = calculatePaintOffset(constraints0.0, mainAxisPadding);
        double cacheExtent = calculateCacheOffset(constraints0.0, mainAxisPadding);
        geometry = SliverGeometry(mainAxisPadding, math.min(paintExtent, constraints.remainingPaintExtent), mainAxisPadding, cacheExtent);
        return;
    }
    double beforePaddingPaintExtent = calculatePaintOffset(constraints0.0, beforePadding);
    double overlap = constraints.overlap;
    if (overlap > 0) {
        overlap = math.max(0.0, constraints.overlap - beforePaddingPaintExtent);
    }
    child!.layout(constraints.copyWith(math.max(0.0, constraints.scrollOffset - beforePadding), math.min(0.0, constraints.cacheOrigin + beforePadding), overlap, constraints.remainingPaintExtent - calculatePaintOffset(constraints0.0, beforePadding), constraints.remainingCacheExtent - calculateCacheOffset(constraints0.0, beforePadding), math.max(0.0, constraints.crossAxisExtent - crossAxisPadding), beforePadding + constraints.precedingScrollExtent)true);
    SliverGeometry childLayoutGeometry = child!.geometry!;
    if (childLayoutGeometry.scrollOffsetCorrection != nullptr) {
        geometry = SliverGeometry(childLayoutGeometry.scrollOffsetCorrection);
        return;
    }
    double afterPaddingPaintExtent = calculatePaintOffset(constraintsbeforePadding + childLayoutGeometry.scrollExtent, mainAxisPadding + childLayoutGeometry.scrollExtent);
    double mainAxisPaddingPaintExtent = beforePaddingPaintExtent + afterPaddingPaintExtent;
    double beforePaddingCacheExtent = calculateCacheOffset(constraints0.0, beforePadding);
    double afterPaddingCacheExtent = calculateCacheOffset(constraintsbeforePadding + childLayoutGeometry.scrollExtent, mainAxisPadding + childLayoutGeometry.scrollExtent);
    double mainAxisPaddingCacheExtent = afterPaddingCacheExtent + beforePaddingCacheExtent;
    double paintExtent = math.min(beforePaddingPaintExtent + math.max(childLayoutGeometry.paintExtent, childLayoutGeometry.layoutExtent + afterPaddingPaintExtent), constraints.remainingPaintExtent);
    geometry = SliverGeometry(childLayoutGeometry.paintOrigin, mainAxisPadding + childLayoutGeometry.scrollExtent, paintExtent, math.min(mainAxisPaddingPaintExtent + childLayoutGeometry.layoutExtent, paintExtent), math.min(mainAxisPaddingCacheExtent + childLayoutGeometry.cacheExtent, constraints.remainingCacheExtent), mainAxisPadding + childLayoutGeometry.maxPaintExtent, math.max(mainAxisPaddingPaintExtent + childLayoutGeometry.paintExtent, beforePaddingPaintExtent + childLayoutGeometry.hitTestExtent), childLayoutGeometry.hasVisualOverflow);
    SliverPhysicalParentData childParentData = (;
    assert(constraints.axisDirection != nullptr);
    assert(constraints.growthDirection != nullptr);
    ;
    assert(childParentData.paintOffset != nullptr);
    assert(beforePadding == this.beforePadding);
    assert(afterPadding == this.afterPadding);
    assert(mainAxisPadding == this.mainAxisPadding);
    assert(crossAxisPadding == this.crossAxisPadding);
}

bool RenderSliverEdgeInsetsPadding::hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result) {
    if (child != nullptr && child!.geometry!.hitTestExtent > 0.0) {
        SliverPhysicalParentData childParentData = (;
        result.addWithAxisOffset(mainAxisPosition, crossAxisPosition, childMainAxisPosition(child!), childCrossAxisPosition(child!), childParentData.paintOffset, child!.hitTest);
    }
    return false;
}

double RenderSliverEdgeInsetsPadding::childMainAxisPosition(RenderSliver child) {
    assert(child != nullptr);
    assert(child == this.child);
    return calculatePaintOffset(constraints0.0, beforePadding);
}

double RenderSliverEdgeInsetsPadding::childCrossAxisPosition(RenderSliver child) {
    assert(child != nullptr);
    assert(child == this.child);
    assert(constraints != nullptr);
    assert(constraints.axisDirection != nullptr);
    assert(constraints.growthDirection != nullptr);
    assert(resolvedPadding != nullptr);
    ;
}

double RenderSliverEdgeInsetsPadding::childScrollOffset(RenderObject child) {
    assert(child.parent == this);
    return beforePadding;
}

void RenderSliverEdgeInsetsPadding::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(child != nullptr);
    assert(child == this.child);
    SliverPhysicalParentData childParentData = (;
    childParentData.applyPaintTransform(transform);
}

void RenderSliverEdgeInsetsPadding::paint(PaintingContext context, Offset offset) {
    if (child != nullptr && child!.geometry!.visible) {
        SliverPhysicalParentData childParentData = (;
        context.paintChild(child!, offset + childParentData.paintOffset);
    }
}

void RenderSliverEdgeInsetsPadding::debugPaint(PaintingContext context, Offset offset) {
    super.debugPaint(context, offset);
    assert(());
}

RenderSliverPadding::RenderSliverPadding(RenderSliver child, EdgeInsetsGeometry padding, TextDirection textDirection) {
    {
        assert(padding != nullptr);
        assert(padding.isNonNegative);
        _padding = padding;
        _textDirection = textDirection;
    }
    {
        this.child = child;
    }
}

EdgeInsets RenderSliverPadding::resolvedPadding() {
    return _resolvedPadding;
}

EdgeInsetsGeometry RenderSliverPadding::padding() {
    return _padding;
}

void RenderSliverPadding::padding(EdgeInsetsGeometry value) {
    assert(value != nullptr);
    assert(padding.isNonNegative);
    if (_padding == value) {
        return;
    }
    _padding = value;
    _markNeedsResolution();
}

TextDirection RenderSliverPadding::textDirection() {
    return _textDirection;
}

void RenderSliverPadding::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    _markNeedsResolution();
}

void RenderSliverPadding::performLayout() {
    _resolve();
    super.performLayout();
}

void RenderSliverPadding::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<EdgeInsetsGeometry>DiagnosticsProperty("padding", padding));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
}

void RenderSliverPadding::_resolve() {
    if (resolvedPadding != nullptr) {
        return;
    }
    _resolvedPadding = padding.resolve(textDirection);
    assert(resolvedPadding!.isNonNegative);
}

void RenderSliverPadding::_markNeedsResolution() {
    _resolvedPadding = nullptr;
    markNeedsLayout();
}
