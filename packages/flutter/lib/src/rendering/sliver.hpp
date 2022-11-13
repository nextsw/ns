#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_SLIVER
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_SLIVER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
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

ScrollDirection applyGrowthDirectionToScrollDirection(ScrollDirection scrollDirection, GrowthDirection growthDirection);


class SliverConstraintsCls : public ConstraintsCls {
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


     SliverConstraintsCls(AxisDirection axisDirection, double cacheOrigin, AxisDirection crossAxisDirection, double crossAxisExtent, GrowthDirection growthDirection, double overlap, double precedingScrollExtent, double remainingCacheExtent, double remainingPaintExtent, double scrollOffset, ScrollDirection userScrollDirection, double viewportMainAxisExtent);

    virtual SliverConstraints copyWith(AxisDirection axisDirection, double cacheOrigin, AxisDirection crossAxisDirection, double crossAxisExtent, GrowthDirection growthDirection, double overlap, double precedingScrollExtent, double remainingCacheExtent, double remainingPaintExtent, double scrollOffset, ScrollDirection userScrollDirection, double viewportMainAxisExtent);

    virtual Axis axis();

    virtual GrowthDirection normalizedGrowthDirection();

    virtual bool isTight();

    virtual bool isNormalized();

    virtual BoxConstraints asBoxConstraints(double crossAxisExtent, double maxExtent, double minExtent);

    virtual bool debugAssertIsValid(InformationCollector informationCollector, bool isAppliedConstraint);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using SliverConstraints = std::shared_ptr<SliverConstraintsCls>;

class SliverGeometryCls : public ObjectCls {
public:
    static SliverGeometry zero;

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


     SliverGeometryCls(double cacheExtent, bool hasVisualOverflow, double hitTestExtent, double layoutExtent, double maxPaintExtent, double maxScrollObstructionExtent, double paintExtent, double paintOrigin, double scrollExtent, double scrollOffsetCorrection, bool visible);

    virtual bool debugAssertIsValid(InformationCollector informationCollector);

    virtual String toStringShort();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using SliverGeometry = std::shared_ptr<SliverGeometryCls>;

class SliverHitTestResultCls : public HitTestResultCls {
public:

     SliverHitTestResultCls();

    virtual void  wrap(Unknown result);

    virtual bool addWithAxisOffset(double crossAxisOffset, double crossAxisPosition, SliverHitTest hitTest, double mainAxisOffset, double mainAxisPosition, Offset paintOffset);

private:

};
using SliverHitTestResult = std::shared_ptr<SliverHitTestResultCls>;

class SliverHitTestEntryCls : public HitTestEntryCls<RenderSliver> {
public:
    double mainAxisPosition;

    double crossAxisPosition;


     SliverHitTestEntryCls(T target, double crossAxisPosition, double mainAxisPosition);

    virtual String toString();

private:

};
using SliverHitTestEntry = std::shared_ptr<SliverHitTestEntryCls>;

class SliverLogicalParentDataCls : public ParentDataCls {
public:
    double layoutOffset;


    virtual String toString();

private:

};
using SliverLogicalParentData = std::shared_ptr<SliverLogicalParentDataCls>;

class SliverLogicalContainerParentDataCls : public SliverLogicalParentDataCls {
public:

private:

};
using SliverLogicalContainerParentData = std::shared_ptr<SliverLogicalContainerParentDataCls>;

class SliverPhysicalParentDataCls : public ParentDataCls {
public:
    Offset paintOffset;


    virtual void applyPaintTransform(Matrix4 transform);

    virtual String toString();

private:

};
using SliverPhysicalParentData = std::shared_ptr<SliverPhysicalParentDataCls>;

class SliverPhysicalContainerParentDataCls : public SliverPhysicalParentDataCls {
public:

private:

};
using SliverPhysicalContainerParentData = std::shared_ptr<SliverPhysicalContainerParentDataCls>;
List<DiagnosticsNode> _debugCompareFloats(String labelA, double valueA, String labelB, double valueB);


class RenderSliverCls : public RenderObjectCls {
public:

    virtual SliverConstraints constraints();

    virtual SliverGeometry geometry();

    virtual void  geometry(SliverGeometry value);

    virtual Rect semanticBounds();

    virtual Rect paintBounds();

    virtual void debugResetSize();

    virtual void debugAssertDoesMeetConstraints();

    virtual void performResize();

    virtual double centerOffsetAdjustment();

    virtual bool hitTest(SliverHitTestResult result, double crossAxisPosition, double mainAxisPosition);

    virtual bool hitTestSelf(double crossAxisPosition, double mainAxisPosition);

    virtual bool hitTestChildren(SliverHitTestResult result, double crossAxisPosition, double mainAxisPosition);

    virtual double calculatePaintOffset(SliverConstraints constraints, double from, double to);

    virtual double calculateCacheOffset(SliverConstraints constraints, double from, double to);

    virtual double childMainAxisPosition(RenderObject child);

    virtual double childCrossAxisPosition(RenderObject child);

    virtual double childScrollOffset(RenderObject child);

    virtual void applyPaintTransform(RenderObject child, Matrix4 transform);

    virtual Size getAbsoluteSizeRelativeToOrigin();

    virtual Size getAbsoluteSize();

    virtual void debugPaint(PaintingContext context, Offset offset);

    virtual void handleEvent(PointerEvent event, SliverHitTestEntry entry);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    SliverGeometry _geometry;


    virtual void _debugDrawArrow(Canvas canvas, Paint paint, Offset p0, Offset p1, GrowthDirection direction);

};
using RenderSliver = std::shared_ptr<RenderSliverCls>;

class RenderSliverHelpersCls : public ObjectCls {
public:

    virtual bool hitTestBoxChild(BoxHitTestResult result, RenderBox child, double crossAxisPosition, double mainAxisPosition);

    virtual void applyPaintTransformForBoxChild(RenderBox child, Matrix4 transform);

private:

    virtual bool _getRightWayUp(SliverConstraints constraints);

};
using RenderSliverHelpers = std::shared_ptr<RenderSliverHelpersCls>;

class RenderSliverSingleBoxAdapterCls : public RenderSliverCls {
public:

     RenderSliverSingleBoxAdapterCls(RenderBox child);

    virtual void setupParentData(RenderObject child);

    virtual void setChildParentData(RenderObject child, SliverConstraints constraints, SliverGeometry geometry);

    virtual bool hitTestChildren(SliverHitTestResult result, double crossAxisPosition, double mainAxisPosition);

    virtual double childMainAxisPosition(RenderBox child);

    virtual void applyPaintTransform(RenderObject child, Matrix4 transform);

    virtual void paint(PaintingContext context, Offset offset);

private:

};
using RenderSliverSingleBoxAdapter = std::shared_ptr<RenderSliverSingleBoxAdapterCls>;

class RenderSliverToBoxAdapterCls : public RenderSliverSingleBoxAdapterCls {
public:

     RenderSliverToBoxAdapterCls(RenderBox child);
    virtual void performLayout();

private:

};
using RenderSliverToBoxAdapter = std::shared_ptr<RenderSliverToBoxAdapterCls>;


#endif