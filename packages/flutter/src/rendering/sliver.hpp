#ifndef SLIVER_H
#define SLIVER_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include "box.hpp"
#include "debug.hpp"
#include "object.hpp"
#include "viewport.hpp"
#include "viewport_offset.hpp"



enum GrowthDirection{
    forward,
    reverse,
} // end GrowthDirection
AxisDirection applyGrowthDirectionToAxisDirection(AxisDirection axisDirection, GrowthDirection growthDirection);

ScrollDirection applyGrowthDirectionToScrollDirection(GrowthDirection growthDirection, ScrollDirection scrollDirection);


class SliverConstraints : Constraints {
public:
    AxisDirection axisDirection;

    GrowthDirection growthDirection;

    ScrollDirection userScrollDirection;

    double scrollOffset;

    double precedingScrollExtent;

    double overlap;

    double remainingPaintExtent;

    double crossAxisExtent;

    AxisDirection crossAxisDirection;

    double viewportMainAxisExtent;

    double cacheOrigin;

    double remainingCacheExtent;


     SliverConstraints(AxisDirection axisDirection, double cacheOrigin, AxisDirection crossAxisDirection, double crossAxisExtent, GrowthDirection growthDirection, double overlap, double precedingScrollExtent, double remainingCacheExtent, double remainingPaintExtent, double scrollOffset, ScrollDirection userScrollDirection, double viewportMainAxisExtent);

    SliverConstraints copyWith(AxisDirection axisDirection, double cacheOrigin, AxisDirection crossAxisDirection, double crossAxisExtent, GrowthDirection growthDirection, double overlap, double precedingScrollExtent, double remainingCacheExtent, double remainingPaintExtent, double scrollOffset, ScrollDirection userScrollDirection, double viewportMainAxisExtent);

    Axis axis();

    GrowthDirection normalizedGrowthDirection();

    bool isTight();

    bool isNormalized();

    BoxConstraints asBoxConstraints(double crossAxisExtent, double maxExtent, double minExtent);

    bool debugAssertIsValid(InformationCollector informationCollector, bool isAppliedConstraint);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class SliverGeometry {
public:
    static const SliverGeometry zero;

    double scrollExtent;

    double paintOrigin;

    double paintExtent;

    double layoutExtent;

    double maxPaintExtent;

    double maxScrollObstructionExtent;

    double hitTestExtent;

    bool visible;

    bool hasVisualOverflow;

    double scrollOffsetCorrection;

    double cacheExtent;


     SliverGeometry(double cacheExtent, bool hasVisualOverflow, double hitTestExtent, double layoutExtent, double maxPaintExtent, double maxScrollObstructionExtent, double paintExtent, double paintOrigin, double scrollExtent, double scrollOffsetCorrection, bool visible);

    bool debugAssertIsValid(InformationCollector informationCollector);

    String toStringShort();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class SliverHitTestResult : HitTestResult {
public:

     SliverHitTestResult();

    void  wrap(Unknown);

    bool addWithAxisOffset(double crossAxisOffset, double crossAxisPosition, SliverHitTest hitTest, double mainAxisOffset, double mainAxisPosition, Offset paintOffset);

private:

};

class SliverHitTestEntry : HitTestEntry<RenderSliver> {
public:
    double mainAxisPosition;

    double crossAxisPosition;


     SliverHitTestEntry(double crossAxisPosition, double mainAxisPosition, Unknown);

    String toString();

private:

};

class SliverLogicalParentData : ParentData {
public:
    double layoutOffset;


    String toString();

private:

};

class SliverLogicalContainerParentData : SliverLogicalParentData {
public:

private:

};

class SliverPhysicalParentData : ParentData {
public:
    Offset paintOffset;


    void applyPaintTransform(Matrix4 transform);

    String toString();

private:

};

class SliverPhysicalContainerParentData : SliverPhysicalParentData {
public:

private:

};
List<DiagnosticsNode> _debugCompareFloats(String labelA, String labelB, double valueA, double valueB);


class RenderSliver : RenderObject {
public:

    SliverConstraints constraints();

    SliverGeometry geometry();

    void  geometry(SliverGeometry value);

    Rect semanticBounds();

    Rect paintBounds();

    void debugResetSize();

    void debugAssertDoesMeetConstraints();

    void performResize();

    double centerOffsetAdjustment();

    bool hitTest(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result);

    bool hitTestSelf(double crossAxisPosition, double mainAxisPosition);

    bool hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result);

    double calculatePaintOffset(SliverConstraints constraints, double from, double to);

    double calculateCacheOffset(SliverConstraints constraints, double from, double to);

    double childMainAxisPosition(RenderObject child);

    double childCrossAxisPosition(RenderObject child);

    double childScrollOffset(RenderObject child);

    void applyPaintTransform(RenderObject child, Matrix4 transform);

    Size getAbsoluteSizeRelativeToOrigin();

    Size getAbsoluteSize();

    void debugPaint(PaintingContext context, Offset offset);

    void handleEvent(SliverHitTestEntry entry, PointerEvent event);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    SliverGeometry _geometry;


    void _debugDrawArrow(Canvas canvas, GrowthDirection direction, Offset p0, Offset p1, Paint paint);

};

class RenderSliverHelpers {
public:

    bool hitTestBoxChild(RenderBox child, double crossAxisPosition, double mainAxisPosition, BoxHitTestResult result);

    void applyPaintTransformForBoxChild(RenderBox child, Matrix4 transform);

private:

    bool _getRightWayUp(SliverConstraints constraints);

};

class RenderSliverSingleBoxAdapter : RenderSliver {
public:

     RenderSliverSingleBoxAdapter(RenderBox child);

    void setupParentData(RenderObject child);

    void setChildParentData(RenderObject child, SliverConstraints constraints, SliverGeometry geometry);

    bool hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result);

    double childMainAxisPosition(RenderBox child);

    void applyPaintTransform(RenderObject child, Matrix4 transform);

    void paint(PaintingContext context, Offset offset);

private:

};

class RenderSliverToBoxAdapter : RenderSliverSingleBoxAdapter {
public:

     RenderSliverToBoxAdapter(Unknown);

    void performLayout();

private:

};

#endif