#ifndef VIEWPORT_H
#define VIEWPORT_H
#include <memory>

#include <math/math.hpp>
#include <flutter/animation.hpp>
#include <flutter/foundation.hpp>
#include <flutter/semantics.hpp>
#include "box.hpp"
#include "layer.hpp"
#include "object.hpp"
#include "sliver.hpp"
#include "viewport_offset.hpp"



enum CacheExtentStyle{
    pixel,
    viewport,
} // end CacheExtentStyle

class RenderAbstractViewport : RenderObject {
public:
    static const double defaultCacheExtent;


    static RenderAbstractViewport of(RenderObject object);

    RevealedOffset getOffsetToReveal(double alignment, Rect rect, RenderObject target);

private:

    void  _();

};

class RevealedOffset {
public:
    double offset;

    Rect rect;


     RevealedOffset(double offset, Rect rect);

    String toString();

private:

};

class RenderViewportBase<ParentDataClass extends ContainerParentDataMixin<RenderSliver>> : RenderBox {
public:

     RenderViewportBase(AxisDirection axisDirection, double cacheExtent, CacheExtentStyle cacheExtentStyle, Clip clipBehavior, AxisDirection crossAxisDirection, ViewportOffset offset);

    void describeSemanticsConfiguration(SemanticsConfiguration config);

    void visitChildrenForSemantics(RenderObjectVisitor visitor);

    AxisDirection axisDirection();

    void  axisDirection(AxisDirection value);

    AxisDirection crossAxisDirection();

    void  crossAxisDirection(AxisDirection value);

    Axis axis();

    ViewportOffset offset();

    void  offset(ViewportOffset value);

    double cacheExtent();

    void  cacheExtent(double value);

    CacheExtentStyle cacheExtentStyle();

    void  cacheExtentStyle(CacheExtentStyle value);

    Clip clipBehavior();

    void  clipBehavior(Clip value);

    void attach(PipelineOwner owner);

    void detach();

    bool debugThrowIfNotCheckingIntrinsics();

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    bool isRepaintBoundary();

    double layoutChildSequence(FunctionType advance, double cacheOrigin, RenderSliver child, double crossAxisExtent, GrowthDirection growthDirection, double layoutOffset, double mainAxisExtent, double overlap, double remainingCacheExtent, double remainingPaintExtent, double scrollOffset);

    Rect describeApproximatePaintClip(RenderSliver child);

    Rect describeSemanticsClip(RenderSliver child);

    void paint(PaintingContext context, Offset offset);

    void dispose();

    void debugPaintSize(PaintingContext context, Offset offset);

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    RevealedOffset getOffsetToReveal(double alignment, Rect rect, RenderObject target);

    Offset computeAbsolutePaintOffset(RenderSliver child, GrowthDirection growthDirection, double layoutOffset);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    List<DiagnosticsNode> debugDescribeChildren();

    bool hasVisualOverflow();

    void updateOutOfBandData(SliverGeometry childLayoutGeometry, GrowthDirection growthDirection);

    void updateChildLayoutOffset(RenderSliver child, GrowthDirection growthDirection, double layoutOffset);

    Offset paintOffsetOf(RenderSliver child);

    double scrollOffsetOf(RenderSliver child, double scrollOffsetWithinChild);

    double maxScrollObstructionExtentBefore(RenderSliver child);

    double computeChildMainAxisPosition(RenderSliver child, double parentMainAxisPosition);

    int indexOfFirstChild();

    String labelForChild(int index);

    Iterable<RenderSliver> childrenInPaintOrder();

    Iterable<RenderSliver> childrenInHitTestOrder();

    void showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect);

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


    void _paintContents(PaintingContext context, Offset offset);

};

class RenderViewport : RenderViewportBase<SliverPhysicalContainerParentData> {
public:
    static const SemanticsTag useTwoPaneSemantics;

    static const SemanticsTag excludeFromScrolling;


     RenderViewport(double anchor, Unknown, Unknown, Unknown, RenderSliver center, List<RenderSliver> children, Unknown, Unknown, Unknown);

    void setupParentData(RenderObject child);

    double anchor();

    void  anchor(double value);

    RenderSliver center();

    void  center(RenderSliver value);

    bool sizedByParent();

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    bool hasVisualOverflow();

    void updateOutOfBandData(SliverGeometry childLayoutGeometry, GrowthDirection growthDirection);

    void updateChildLayoutOffset(RenderSliver child, GrowthDirection growthDirection, double layoutOffset);

    Offset paintOffsetOf(RenderSliver child);

    double scrollOffsetOf(RenderSliver child, double scrollOffsetWithinChild);

    double maxScrollObstructionExtentBefore(RenderSliver child);

    void applyPaintTransform(RenderObject child, Matrix4 transform);

    double computeChildMainAxisPosition(RenderSliver child, double parentMainAxisPosition);

    int indexOfFirstChild();

    String labelForChild(int index);

    Iterable<RenderSliver> childrenInPaintOrder();

    Iterable<RenderSliver> childrenInHitTestOrder();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _anchor;

    RenderSliver _center;

    static const int _maxLayoutCycles;

    double _minScrollExtent;

    double _maxScrollExtent;

    bool _hasVisualOverflow;


    double _attemptLayout(double correctedOffset, double crossAxisExtent, double mainAxisExtent);

};

class RenderShrinkWrappingViewport : RenderViewportBase<SliverLogicalContainerParentData> {
public:

     RenderShrinkWrappingViewport(Unknown, List<RenderSliver> children, Unknown, Unknown, Unknown);

    void setupParentData(RenderObject child);

    bool debugThrowIfNotCheckingIntrinsics();

    void performLayout();

    bool hasVisualOverflow();

    void updateOutOfBandData(SliverGeometry childLayoutGeometry, GrowthDirection growthDirection);

    void updateChildLayoutOffset(RenderSliver child, GrowthDirection growthDirection, double layoutOffset);

    Offset paintOffsetOf(RenderSliver child);

    double scrollOffsetOf(RenderSliver child, double scrollOffsetWithinChild);

    double maxScrollObstructionExtentBefore(RenderSliver child);

    void applyPaintTransform(RenderObject child, Matrix4 transform);

    double computeChildMainAxisPosition(RenderSliver child, double parentMainAxisPosition);

    int indexOfFirstChild();

    String labelForChild(int index);

    Iterable<RenderSliver> childrenInPaintOrder();

    Iterable<RenderSliver> childrenInHitTestOrder();

private:
    double _maxScrollExtent;

    double _shrinkWrapExtent;

    bool _hasVisualOverflow;


    double _attemptLayout(double correctedOffset, double crossAxisExtent, double mainAxisExtent);

};

#endif