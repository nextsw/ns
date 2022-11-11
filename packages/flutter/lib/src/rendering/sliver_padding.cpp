#include "sliver_padding.hpp"
double RenderSliverEdgeInsetsPaddingCls::beforePadding() {
    assert(constraints() != nullptr);
    assert(constraints()->axisDirection != nullptr);
    assert(constraints()->growthDirection != nullptr);
    assert(resolvedPadding() != nullptr);
    ;
}

double RenderSliverEdgeInsetsPaddingCls::afterPadding() {
    assert(constraints() != nullptr);
    assert(constraints()->axisDirection != nullptr);
    assert(constraints()->growthDirection != nullptr);
    assert(resolvedPadding() != nullptr);
    ;
}

double RenderSliverEdgeInsetsPaddingCls::mainAxisPadding() {
    assert(constraints() != nullptr);
    assert(constraints()->axis() != nullptr);
    assert(resolvedPadding() != nullptr);
    return resolvedPadding()!->along(constraints()->axis());
}

double RenderSliverEdgeInsetsPaddingCls::crossAxisPadding() {
    assert(constraints() != nullptr);
    assert(constraints()->axis() != nullptr);
    assert(resolvedPadding() != nullptr);
    ;
}

void RenderSliverEdgeInsetsPaddingCls::setupParentData(RenderObject child) {
    if (!is<SliverPhysicalParentData>(child->parentData)) {
        child->parentData = make<SliverPhysicalParentDataCls>();
    }
}

void RenderSliverEdgeInsetsPaddingCls::performLayout() {
    SliverConstraints constraints = this->constraints();
    assert(resolvedPadding() != nullptr);
    double beforePadding = this->beforePadding();
    double afterPadding = this->afterPadding();
    double mainAxisPadding = this->mainAxisPadding();
    double crossAxisPadding = this->crossAxisPadding();
    if (child == nullptr) {
        double paintExtent = calculatePaintOffset(constraints, 0.0, mainAxisPadding);
        double cacheExtent = calculateCacheOffset(constraints, 0.0, mainAxisPadding);
        geometry() = make<SliverGeometryCls>(mainAxisPadding, math->min(paintExtent, constraints->remainingPaintExtent), mainAxisPadding, cacheExtent);
        return;
    }
    double beforePaddingPaintExtent = calculatePaintOffset(constraints, 0.0, beforePadding);
    double overlap = constraints->overlap;
    if (overlap > 0) {
        overlap = math->max(0.0, constraints->overlap - beforePaddingPaintExtent);
    }
    child!->layout(constraints->copyWith(math->max(0.0, constraints->scrollOffset - beforePadding), math->min(0.0, constraints->cacheOrigin + beforePadding), overlap, constraints->remainingPaintExtent - calculatePaintOffset(constraints, 0.0, beforePadding), constraints->remainingCacheExtent - calculateCacheOffset(constraints, 0.0, beforePadding), math->max(0.0, constraints->crossAxisExtent - crossAxisPadding), beforePadding + constraints->precedingScrollExtent), true);
    SliverGeometry childLayoutGeometry = child!->geometry!;
    if (childLayoutGeometry->scrollOffsetCorrection != nullptr) {
        geometry() = make<SliverGeometryCls>(childLayoutGeometry->scrollOffsetCorrection);
        return;
    }
    double afterPaddingPaintExtent = calculatePaintOffset(constraints, beforePadding + childLayoutGeometry->scrollExtent, mainAxisPadding + childLayoutGeometry->scrollExtent);
    double mainAxisPaddingPaintExtent = beforePaddingPaintExtent + afterPaddingPaintExtent;
    double beforePaddingCacheExtent = calculateCacheOffset(constraints, 0.0, beforePadding);
    double afterPaddingCacheExtent = calculateCacheOffset(constraints, beforePadding + childLayoutGeometry->scrollExtent, mainAxisPadding + childLayoutGeometry->scrollExtent);
    double mainAxisPaddingCacheExtent = afterPaddingCacheExtent + beforePaddingCacheExtent;
    double paintExtent = math->min(beforePaddingPaintExtent + math->max(childLayoutGeometry->paintExtent, childLayoutGeometry->layoutExtent + afterPaddingPaintExtent), constraints->remainingPaintExtent);
    geometry() = make<SliverGeometryCls>(childLayoutGeometry->paintOrigin, mainAxisPadding + childLayoutGeometry->scrollExtent, paintExtent, math->min(mainAxisPaddingPaintExtent + childLayoutGeometry->layoutExtent, paintExtent), math->min(mainAxisPaddingCacheExtent + childLayoutGeometry->cacheExtent, constraints->remainingCacheExtent), mainAxisPadding + childLayoutGeometry->maxPaintExtent, math->max(mainAxisPaddingPaintExtent + childLayoutGeometry->paintExtent, beforePaddingPaintExtent + childLayoutGeometry->hitTestExtent), childLayoutGeometry->hasVisualOverflow);
    SliverPhysicalParentData childParentData = as<SliverPhysicalParentData>(child!->parentData!);
    assert(constraints->axisDirection != nullptr);
    assert(constraints->growthDirection != nullptr);
    ;
    assert(childParentData->paintOffset != nullptr);
    assert(beforePadding == this->beforePadding);
    assert(afterPadding == this->afterPadding);
    assert(mainAxisPadding == this->mainAxisPadding);
    assert(crossAxisPadding == this->crossAxisPadding);
}

bool RenderSliverEdgeInsetsPaddingCls::hitTestChildren(SliverHitTestResult result, double crossAxisPosition, double mainAxisPosition) {
    if (child != nullptr && child!->geometry!->hitTestExtent > 0.0) {
        SliverPhysicalParentData childParentData = as<SliverPhysicalParentData>(child!->parentData!);
        result->addWithAxisOffset(mainAxisPosition, crossAxisPosition, childMainAxisPosition(child!), childCrossAxisPosition(child!), childParentData->paintOffset, child!->hitTest);
    }
    return false;
}

double RenderSliverEdgeInsetsPaddingCls::childMainAxisPosition(RenderSliver child) {
    assert(child != nullptr);
    assert(child == this->child);
    return calculatePaintOffset(constraints(), 0.0, beforePadding());
}

double RenderSliverEdgeInsetsPaddingCls::childCrossAxisPosition(RenderSliver child) {
    assert(child != nullptr);
    assert(child == this->child);
    assert(constraints() != nullptr);
    assert(constraints()->axisDirection != nullptr);
    assert(constraints()->growthDirection != nullptr);
    assert(resolvedPadding() != nullptr);
    ;
}

double RenderSliverEdgeInsetsPaddingCls::childScrollOffset(RenderObject child) {
    assert(child->parent() == this);
    return beforePadding();
}

void RenderSliverEdgeInsetsPaddingCls::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(child != nullptr);
    assert(child == this->child);
    SliverPhysicalParentData childParentData = as<SliverPhysicalParentData>(child->parentData!);
    childParentData->applyPaintTransform(transform);
}

void RenderSliverEdgeInsetsPaddingCls::paint(PaintingContext context, Offset offset) {
    if (child != nullptr && child!->geometry!->visible) {
        SliverPhysicalParentData childParentData = as<SliverPhysicalParentData>(child!->parentData!);
        context->paintChild(child!, offset + childParentData->paintOffset);
    }
}

void RenderSliverEdgeInsetsPaddingCls::debugPaint(PaintingContext context, Offset offset) {
    super->debugPaint(context, offset);
    assert([=] () {
        if (debugPaintSizeEnabled) {
            Size parentSize = getAbsoluteSize();
            Rect outerRect = offset & parentSize;
            Rect innerRect;
            if (child != nullptr) {
                Size childSize = child!->getAbsoluteSize();
                SliverPhysicalParentData childParentData = as<SliverPhysicalParentData>(child!->parentData!);
                innerRect = (offset + childParentData->paintOffset) & childSize;
                assert(innerRect->top >= outerRect->top);
                assert(innerRect->left >= outerRect->left);
                assert(innerRect->right <= outerRect->right);
                assert(innerRect->bottom <= outerRect->bottom);
            }
            debugPaintPadding(context->canvas(), outerRect, innerRect);
        }
        return true;
    }());
}

RenderSliverPaddingCls::RenderSliverPaddingCls(RenderSliver child, EdgeInsetsGeometry padding, TextDirection textDirection) {
    {
        assert(padding != nullptr);
        assert(padding->isNonNegative());
        _padding = padding;
        _textDirection = textDirection;
    }
    {
        this->child = child;
    }
}

EdgeInsets RenderSliverPaddingCls::resolvedPadding() {
    return _resolvedPadding;
}

EdgeInsetsGeometry RenderSliverPaddingCls::padding() {
    return _padding;
}

void RenderSliverPaddingCls::padding(EdgeInsetsGeometry value) {
    assert(value != nullptr);
    assert(padding()->isNonNegative());
    if (_padding == value) {
        return;
    }
    _padding = value;
    _markNeedsResolution();
}

TextDirection RenderSliverPaddingCls::textDirection() {
    return _textDirection;
}

void RenderSliverPaddingCls::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    _markNeedsResolution();
}

void RenderSliverPaddingCls::performLayout() {
    _resolve();
    super->performLayout();
}

void RenderSliverPaddingCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<EdgeInsetsGeometry>make<DiagnosticsPropertyCls>(__s("padding"), padding()));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection(), nullptr));
}

void RenderSliverPaddingCls::_resolve() {
    if (resolvedPadding() != nullptr) {
        return;
    }
    _resolvedPadding = padding()->resolve(textDirection());
    assert(resolvedPadding()!->isNonNegative());
}

void RenderSliverPaddingCls::_markNeedsResolution() {
    _resolvedPadding = nullptr;
    markNeedsLayout();
}
