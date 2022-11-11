#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_VIEWPORT
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_VIEWPORT
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "box.hpp"
#include "layer.hpp"
#include "object.hpp"
#include "sliver.hpp"
#include "viewport_offset.hpp"


enum CacheExtentStyle{
    pixel,
    viewport,
} // end CacheExtentStyle

class RenderAbstractViewportCls : public RenderObjectCls {
public:
    static double defaultCacheExtent;


    static RenderAbstractViewport of(RenderObject object);

    virtual RevealedOffset getOffsetToReveal(double alignment, Rect rect, RenderObject target);
private:

    virtual void  _();
};
using RenderAbstractViewport = std::shared_ptr<RenderAbstractViewportCls>;

class RevealedOffsetCls : public ObjectCls {
public:
    double offset;

    Rect rect;


     RevealedOffsetCls(double offset, Rect rect);

    virtual String toString();

private:

};
using RevealedOffset = std::shared_ptr<RevealedOffsetCls>;

template<typename ParentDataClass>
class RenderViewportBaseCls : public RenderBoxCls {
public:

     RenderViewportBaseCls(AxisDirection axisDirection, double cacheExtent, CacheExtentStyle cacheExtentStyle, Clip clipBehavior, AxisDirection crossAxisDirection, ViewportOffset offset);

    virtual void describeSemanticsConfiguration(SemanticsConfiguration config);

    virtual void visitChildrenForSemantics(RenderObjectVisitor visitor);

    virtual AxisDirection axisDirection();

    virtual void  axisDirection(AxisDirection value);

    virtual AxisDirection crossAxisDirection();

    virtual void  crossAxisDirection(AxisDirection value);

    virtual Axis axis();

    virtual ViewportOffset offset();

    virtual void  offset(ViewportOffset value);

    virtual double cacheExtent();

    virtual void  cacheExtent(double value);

    virtual CacheExtentStyle cacheExtentStyle();

    virtual void  cacheExtentStyle(CacheExtentStyle value);

    virtual Clip clipBehavior();

    virtual void  clipBehavior(Clip value);

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual bool debugThrowIfNotCheckingIntrinsics();

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual bool isRepaintBoundary();

    virtual double layoutChildSequence(std::function<RenderSliver(RenderSliver child)> advance, double cacheOrigin, RenderSliver child, double crossAxisExtent, GrowthDirection growthDirection, double layoutOffset, double mainAxisExtent, double overlap, double remainingCacheExtent, double remainingPaintExtent, double scrollOffset);

    virtual Rect describeApproximatePaintClip(RenderSliver child);

    virtual Rect describeSemanticsClip(RenderSliver child);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void dispose();

    virtual void debugPaintSize(PaintingContext context, Offset offset);

    virtual bool hitTestChildren(Offset position, BoxHitTestResult result);

    virtual RevealedOffset getOffsetToReveal(double alignment, Rect rect, RenderObject target);

    virtual Offset computeAbsolutePaintOffset(RenderSliver child, GrowthDirection growthDirection, double layoutOffset);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual List<DiagnosticsNode> debugDescribeChildren();

    virtual bool hasVisualOverflow();
    virtual void updateOutOfBandData(SliverGeometry childLayoutGeometry, GrowthDirection growthDirection);
    virtual void updateChildLayoutOffset(RenderSliver child, GrowthDirection growthDirection, double layoutOffset);
    virtual Offset paintOffsetOf(RenderSliver child);
    virtual double scrollOffsetOf(RenderSliver child, double scrollOffsetWithinChild);
    virtual double maxScrollObstructionExtentBefore(RenderSliver child);
    virtual double computeChildMainAxisPosition(RenderSliver child, double parentMainAxisPosition);
    virtual int indexOfFirstChild();
    virtual String labelForChild(int index);
    virtual Iterable<RenderSliver> childrenInPaintOrder();
    virtual Iterable<RenderSliver> childrenInHitTestOrder();
    virtual void showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect);

    static Rect showInViewport(Curve curve, RenderObject descendant, Duration duration, ViewportOffset offset, Rect rect, RenderAbstractViewport viewport);

private:
    AxisDirection _axisDirection;

    AxisDirection _crossAxisDirection;

    ViewportOffset _offset;

    double _cacheExtent;

    double _calculatedCacheExtent;

    CacheExtentStyle _cacheExtentStyle;

    Clip _clipBehavior;

    LayerHandle<ClipRectLayer> _clipRectLayer;


    virtual void _paintContents(PaintingContext context, Offset offset);

};
template<typename ParentDataClass>
using RenderViewportBase = std::shared_ptr<RenderViewportBaseCls<ParentDataClass>>;

class RenderViewportCls : public RenderViewportBaseCls<SliverPhysicalContainerParentData> {
public:
    static SemanticsTag useTwoPaneSemantics;

    static SemanticsTag excludeFromScrolling;


     RenderViewportCls(double anchor, Unknown axisDirection, Unknown cacheExtent, Unknown cacheExtentStyle, RenderSliver center, List<RenderSliver> children, Unknown clipBehavior, Unknown crossAxisDirection, Unknown offset);

    virtual void setupParentData(RenderObject child);

    virtual double anchor();

    virtual void  anchor(double value);

    virtual RenderSliver center();

    virtual void  center(RenderSliver value);

    virtual bool sizedByParent();

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual bool hasVisualOverflow();

    virtual void updateOutOfBandData(SliverGeometry childLayoutGeometry, GrowthDirection growthDirection);

    virtual void updateChildLayoutOffset(RenderSliver child, GrowthDirection growthDirection, double layoutOffset);

    virtual Offset paintOffsetOf(RenderSliver child);

    virtual double scrollOffsetOf(RenderSliver child, double scrollOffsetWithinChild);

    virtual double maxScrollObstructionExtentBefore(RenderSliver child);

    virtual void applyPaintTransform(RenderObject child, Matrix4 transform);

    virtual double computeChildMainAxisPosition(RenderSliver child, double parentMainAxisPosition);

    virtual int indexOfFirstChild();

    virtual String labelForChild(int index);

    virtual Iterable<RenderSliver> childrenInPaintOrder();

    virtual Iterable<RenderSliver> childrenInHitTestOrder();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _anchor;

    RenderSliver _center;

    static int _maxLayoutCycles;

    double _minScrollExtent;

    double _maxScrollExtent;

    bool _hasVisualOverflow;


    virtual double _attemptLayout(double correctedOffset, double crossAxisExtent, double mainAxisExtent);

};
using RenderViewport = std::shared_ptr<RenderViewportCls>;

class RenderShrinkWrappingViewportCls : public RenderViewportBaseCls<SliverLogicalContainerParentData> {
public:

     RenderShrinkWrappingViewportCls(Unknown axisDirection, List<RenderSliver> children, Unknown clipBehavior, Unknown crossAxisDirection, Unknown offset);

    virtual void setupParentData(RenderObject child);

    virtual bool debugThrowIfNotCheckingIntrinsics();

    virtual void performLayout();

    virtual bool hasVisualOverflow();

    virtual void updateOutOfBandData(SliverGeometry childLayoutGeometry, GrowthDirection growthDirection);

    virtual void updateChildLayoutOffset(RenderSliver child, GrowthDirection growthDirection, double layoutOffset);

    virtual Offset paintOffsetOf(RenderSliver child);

    virtual double scrollOffsetOf(RenderSliver child, double scrollOffsetWithinChild);

    virtual double maxScrollObstructionExtentBefore(RenderSliver child);

    virtual void applyPaintTransform(RenderObject child, Matrix4 transform);

    virtual double computeChildMainAxisPosition(RenderSliver child, double parentMainAxisPosition);

    virtual int indexOfFirstChild();

    virtual String labelForChild(int index);

    virtual Iterable<RenderSliver> childrenInPaintOrder();

    virtual Iterable<RenderSliver> childrenInHitTestOrder();

private:
    double _maxScrollExtent;

    double _shrinkWrapExtent;

    bool _hasVisualOverflow;


    virtual double _attemptLayout(double correctedOffset, double crossAxisExtent, double mainAxisExtent);

};
using RenderShrinkWrappingViewport = std::shared_ptr<RenderShrinkWrappingViewportCls>;


#endif