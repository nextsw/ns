#include "sliver.hpp"
AxisDirection applyGrowthDirectionToAxisDirection(AxisDirection axisDirection, GrowthDirection growthDirection) {
    assert(axisDirection != nullptr);
    assert(growthDirection != nullptr);
    ;
}

ScrollDirection applyGrowthDirectionToScrollDirection(GrowthDirection growthDirection, ScrollDirection scrollDirection) {
    assert(scrollDirection != nullptr);
    assert(growthDirection != nullptr);
    ;
}

SliverConstraints::SliverConstraints(AxisDirection axisDirection, double cacheOrigin, AxisDirection crossAxisDirection, double crossAxisExtent, GrowthDirection growthDirection, double overlap, double precedingScrollExtent, double remainingCacheExtent, double remainingPaintExtent, double scrollOffset, ScrollDirection userScrollDirection, double viewportMainAxisExtent) {
    {
        assert(axisDirection != nullptr);
        assert(growthDirection != nullptr);
        assert(userScrollDirection != nullptr);
        assert(scrollOffset != nullptr);
        assert(precedingScrollExtent != nullptr);
        assert(overlap != nullptr);
        assert(remainingPaintExtent != nullptr);
        assert(crossAxisExtent != nullptr);
        assert(crossAxisDirection != nullptr);
        assert(viewportMainAxisExtent != nullptr);
        assert(remainingCacheExtent != nullptr);
        assert(cacheOrigin != nullptr);
    }
}

SliverConstraints SliverConstraints::copyWith(AxisDirection axisDirection, double cacheOrigin, AxisDirection crossAxisDirection, double crossAxisExtent, GrowthDirection growthDirection, double overlap, double precedingScrollExtent, double remainingCacheExtent, double remainingPaintExtent, double scrollOffset, ScrollDirection userScrollDirection, double viewportMainAxisExtent) {
    return SliverConstraints(axisDirection ?? this.axisDirection, growthDirection ?? this.growthDirection, userScrollDirection ?? this.userScrollDirection, scrollOffset ?? this.scrollOffset, precedingScrollExtent ?? this.precedingScrollExtent, overlap ?? this.overlap, remainingPaintExtent ?? this.remainingPaintExtent, crossAxisExtent ?? this.crossAxisExtent, crossAxisDirection ?? this.crossAxisDirection, viewportMainAxisExtent ?? this.viewportMainAxisExtent, remainingCacheExtent ?? this.remainingCacheExtent, cacheOrigin ?? this.cacheOrigin);
}

Axis SliverConstraints::axis() {
    return axisDirectionToAxis(axisDirection);
}

GrowthDirection SliverConstraints::normalizedGrowthDirection() {
    assert(axisDirection != nullptr);
    ;
}

bool SliverConstraints::isTight() {
    return false;
}

bool SliverConstraints::isNormalized() {
    return scrollOffset >= 0.0 && crossAxisExtent >= 0.0 && axisDirectionToAxis(axisDirection) != axisDirectionToAxis(crossAxisDirection) && viewportMainAxisExtent >= 0.0 && remainingPaintExtent >= 0.0;
}

BoxConstraints SliverConstraints::asBoxConstraints(double crossAxisExtent, double maxExtent, double minExtent) {
    crossAxisExtent = this.crossAxisExtent;
    ;
}

bool SliverConstraints::debugAssertIsValid(InformationCollector informationCollector, bool isAppliedConstraint) {
    assert(());
    return true;
}

bool SliverConstraints::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other is! SliverConstraints) {
        return false;
    }
    assert(other.debugAssertIsValid());
    return other.axisDirection == axisDirection && other.growthDirection == growthDirection && other.scrollOffset == scrollOffset && other.overlap == overlap && other.remainingPaintExtent == remainingPaintExtent && other.crossAxisExtent == crossAxisExtent && other.crossAxisDirection == crossAxisDirection && other.viewportMainAxisExtent == viewportMainAxisExtent && other.remainingCacheExtent == remainingCacheExtent && other.cacheOrigin == cacheOrigin;
}

int SliverConstraints::hashCode() {
    return Object.hash(axisDirection, growthDirection, scrollOffset, overlap, remainingPaintExtent, crossAxisExtent, crossAxisDirection, viewportMainAxisExtent, remainingCacheExtent, cacheOrigin);
}

String SliverConstraints::toString() {
    List<String> properties = ;
    return "SliverConstraints(${properties.join(', ')})";
}

SliverGeometry::SliverGeometry(double cacheExtent, bool hasVisualOverflow, double hitTestExtent, double layoutExtent, double maxPaintExtent, double maxScrollObstructionExtent, double paintExtent, double paintOrigin, double scrollExtent, double scrollOffsetCorrection, bool visible) {
    {
        assert(scrollExtent != nullptr);
        assert(paintExtent != nullptr);
        assert(paintOrigin != nullptr);
        assert(maxPaintExtent != nullptr);
        assert(hasVisualOverflow != nullptr);
        assert(scrollOffsetCorrection != 0.0);
        layoutExtent = layoutExtent ?? paintExtent;
        hitTestExtent = hitTestExtent ?? paintExtent;
        cacheExtent = cacheExtent ?? layoutExtent ?? paintExtent;
        visible = visible ?? paintExtent > 0.0;
    }
}

bool SliverGeometry::debugAssertIsValid(InformationCollector informationCollector) {
    assert(());
    return true;
}

String SliverGeometry::toStringShort() {
    return objectRuntimeType(this, "SliverGeometry");
}

void SliverGeometry::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("scrollExtent", scrollExtent));
    if (paintExtent > 0.0) {
        properties.add(DoubleProperty("paintExtent", paintExtentvisible? nullptr : " but not painting"));
    } else     {
        if (paintExtent == 0.0) {
        if (visible) {
            properties.add(DoubleProperty("paintExtent", paintExtentvisible? nullptr : " but visible"));
        }
        properties.add(FlagProperty("visible"visible, "hidden"));
    } else {
        properties.add(DoubleProperty("paintExtent", paintExtent"!"));
    }
;
    }    properties.add(DoubleProperty("paintOrigin", paintOrigin0.0));
    properties.add(DoubleProperty("layoutExtent", layoutExtentpaintExtent));
    properties.add(DoubleProperty("maxPaintExtent", maxPaintExtent));
    properties.add(DoubleProperty("hitTestExtent", hitTestExtentpaintExtent));
    properties.add(<bool>DiagnosticsProperty("hasVisualOverflow", hasVisualOverflowfalse));
    properties.add(DoubleProperty("scrollOffsetCorrection", scrollOffsetCorrectionnullptr));
    properties.add(DoubleProperty("cacheExtent", cacheExtent0.0));
}

SliverHitTestResult::SliverHitTestResult() {
    {
        super();
    }
}

void SliverHitTestResult::wrap(Unknown)

bool SliverHitTestResult::addWithAxisOffset(double crossAxisOffset, double crossAxisPosition, SliverHitTest hitTest, double mainAxisOffset, double mainAxisPosition, Offset paintOffset) {
    assert(mainAxisOffset != nullptr);
    assert(crossAxisOffset != nullptr);
    assert(mainAxisPosition != nullptr);
    assert(crossAxisPosition != nullptr);
    assert(hitTest != nullptr);
    if (paintOffset != nullptr) {
        pushOffset(-paintOffset);
    }
    bool isHit = hitTest(thismainAxisPosition - mainAxisOffset, crossAxisPosition - crossAxisOffset);
    if (paintOffset != nullptr) {
        popTransform();
    }
    return isHit;
}

SliverHitTestEntry::SliverHitTestEntry(double crossAxisPosition, double mainAxisPosition, Unknown) {
    {
        assert(mainAxisPosition != nullptr);
        assert(crossAxisPosition != nullptr);
    }
}

String SliverHitTestEntry::toString() {
    return "${target.runtimeType}@(mainAxis: $mainAxisPosition, crossAxis: $crossAxisPosition)";
}

String SliverLogicalParentData::toString() {
    return "layoutOffset=${layoutOffset == null ? 'None': layoutOffset!.toStringAsFixed(1)}";
}

void SliverPhysicalParentData::applyPaintTransform(Matrix4 transform) {
    transform.translate(paintOffset.dx, paintOffset.dy);
}

String SliverPhysicalParentData::toString() {
    return "paintOffset=$paintOffset";
}

List<DiagnosticsNode> _debugCompareFloats(String labelA, String labelB, double valueA, double valueB) {
    return ;
}

SliverConstraints RenderSliver::constraints() {
    return (;
}

SliverGeometry RenderSliver::geometry() {
    return _geometry;
}

void RenderSliver::geometry(SliverGeometry value) {
    assert(!(debugDoingThisResize && debugDoingThisLayout));
    assert(sizedByParent || !debugDoingThisResize);
    assert(());
    _geometry = value;
}

Rect RenderSliver::semanticBounds() {
    return paintBounds;
}

Rect RenderSliver::paintBounds() {
    assert(constraints.axis != nullptr);
    ;
}

void RenderSliver::debugResetSize() {
}

void RenderSliver::debugAssertDoesMeetConstraints() {
    assert(geometry!.debugAssertIsValid());
    assert(());
}

void RenderSliver::performResize() {
    assert(false);
}

double RenderSliver::centerOffsetAdjustment() {
    return 0.0;
}

bool RenderSliver::hitTest(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result) {
    if (mainAxisPosition >= 0.0 &&  < geometry!.hitTestExtent && crossAxisPosition >= 0.0 &&  < constraints.crossAxisExtent) {
        if (hitTestChildren(resultmainAxisPosition, crossAxisPosition) || hitTestSelf(mainAxisPosition, crossAxisPosition)) {
            result.add(SliverHitTestEntry(thismainAxisPosition, crossAxisPosition));
            return true;
        }
    }
    return false;
}

bool RenderSliver::hitTestSelf(double crossAxisPosition, double mainAxisPosition) {
    return false;
}

bool RenderSliver::hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result) {
    return false;
}

double RenderSliver::calculatePaintOffset(SliverConstraints constraints, double from, double to) {
    assert(from <= to);
    double a = constraints.scrollOffset;
    double b = constraints.scrollOffset + constraints.remainingPaintExtent;
    return clampDouble(clampDouble(to, a, b) - clampDouble(from, a, b), 0.0, constraints.remainingPaintExtent);
}

double RenderSliver::calculateCacheOffset(SliverConstraints constraints, double from, double to) {
    assert(from <= to);
    double a = constraints.scrollOffset + constraints.cacheOrigin;
    double b = constraints.scrollOffset + constraints.remainingCacheExtent;
    return clampDouble(clampDouble(to, a, b) - clampDouble(from, a, b), 0.0, constraints.remainingCacheExtent);
}

double RenderSliver::childMainAxisPosition(RenderObject child) {
    assert(());
    return 0.0;
}

double RenderSliver::childCrossAxisPosition(RenderObject child) {
    return 0.0;
}

double RenderSliver::childScrollOffset(RenderObject child) {
    assert(child.parent == this);
    return 0.0;
}

void RenderSliver::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(());
}

Size RenderSliver::getAbsoluteSizeRelativeToOrigin() {
    assert(geometry != nullptr);
    assert(!debugNeedsLayout);
    ;
}

Size RenderSliver::getAbsoluteSize() {
    assert(geometry != nullptr);
    assert(!debugNeedsLayout);
    ;
}

void RenderSliver::debugPaint(PaintingContext context, Offset offset) {
    assert(());
}

void RenderSliver::handleEvent(SliverHitTestEntry entry, PointerEvent event) {
}

void RenderSliver::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<SliverGeometry>DiagnosticsProperty("geometry", geometry));
}

void RenderSliver::_debugDrawArrow(Canvas canvas, GrowthDirection direction, Offset p0, Offset p1, Paint paint) {
    assert(());
}

bool RenderSliverHelpers::hitTestBoxChild(RenderBox child, double crossAxisPosition, double mainAxisPosition, BoxHitTestResult result) {
    bool rightWayUp = _getRightWayUp(constraints);
    double delta = childMainAxisPosition(child);
    double crossAxisDelta = childCrossAxisPosition(child);
    double absolutePosition = mainAxisPosition - delta;
    double absoluteCrossAxisPosition = crossAxisPosition - crossAxisDelta;
    Offset paintOffset, transformedPosition;
    assert(constraints.axis != nullptr);
    ;
    assert(paintOffset != nullptr);
    assert(transformedPosition != nullptr);
    return result.addWithOutOfBandPosition(paintOffset, );
}

void RenderSliverHelpers::applyPaintTransformForBoxChild(RenderBox child, Matrix4 transform) {
    bool rightWayUp = _getRightWayUp(constraints);
    double delta = childMainAxisPosition(child);
    double crossAxisDelta = childCrossAxisPosition(child);
    assert(constraints.axis != nullptr);
    ;
}

bool RenderSliverHelpers::_getRightWayUp(SliverConstraints constraints) {
    assert(constraints != nullptr);
    assert(constraints.axisDirection != nullptr);
    bool rightWayUp;
    ;
    assert(constraints.growthDirection != nullptr);
    ;
    assert(rightWayUp != nullptr);
    return rightWayUp;
}

RenderSliverSingleBoxAdapter::RenderSliverSingleBoxAdapter(RenderBox child) {
    {
        this.child = child;
    }
}

void RenderSliverSingleBoxAdapter::setupParentData(RenderObject child) {
    if (child.parentData is! SliverPhysicalParentData) {
        child.parentData = SliverPhysicalParentData();
    }
}

void RenderSliverSingleBoxAdapter::setChildParentData(RenderObject child, SliverConstraints constraints, SliverGeometry geometry) {
    SliverPhysicalParentData childParentData = (;
    assert(constraints.axisDirection != nullptr);
    assert(constraints.growthDirection != nullptr);
    ;
    assert(childParentData.paintOffset != nullptr);
}

bool RenderSliverSingleBoxAdapter::hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result) {
    assert(geometry!.hitTestExtent > 0.0);
    if (child != nullptr) {
        return hitTestBoxChild(BoxHitTestResult.wrap(result), child!mainAxisPosition, crossAxisPosition);
    }
    return false;
}

double RenderSliverSingleBoxAdapter::childMainAxisPosition(RenderBox child) {
    return -constraints.scrollOffset;
}

void RenderSliverSingleBoxAdapter::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(child != nullptr);
    assert(child == this.child);
    SliverPhysicalParentData childParentData = (;
    childParentData.applyPaintTransform(transform);
}

void RenderSliverSingleBoxAdapter::paint(PaintingContext context, Offset offset) {
    if (child != nullptr && geometry!.visible) {
        SliverPhysicalParentData childParentData = (;
        context.paintChild(child!, offset + childParentData.paintOffset);
    }
}

void RenderSliverToBoxAdapter::performLayout() {
    if (child == nullptr) {
        geometry = SliverGeometry.zero;
        return;
    }
    SliverConstraints constraints = this.constraints;
    child!.layout(constraints.asBoxConstraints()true);
    double childExtent;
    ;
    assert(childExtent != nullptr);
    double paintedChildSize = calculatePaintOffset(constraints0.0, childExtent);
    double cacheExtent = calculateCacheOffset(constraints0.0, childExtent);
    assert(paintedChildSize.isFinite);
    assert(paintedChildSize >= 0.0);
    geometry = SliverGeometry(childExtent, paintedChildSize, cacheExtent, childExtent, paintedChildSize, childExtent > constraints.remainingPaintExtent || constraints.scrollOffset > 0.0);
    setChildParentData(child!, constraints, geometry!);
}
