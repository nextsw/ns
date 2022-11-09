#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_LIST_WHEEL_VIEWPORT
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_LIST_WHEEL_VIEWPORT
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "box.hpp"
#include "layer.hpp"
#include "object.hpp"
#include "viewport.hpp"
#include "viewport_offset.hpp"


class ListWheelChildManagerCls : public ObjectCls {
public:

    virtual int childCount();
    virtual bool childExistsAt(int index);
    virtual void createChild(RenderBox after, int index);
    virtual void removeChild(RenderBox child);
private:

};
using ListWheelChildManager = std::shared_ptr<ListWheelChildManagerCls>;

class ListWheelParentDataCls : public ContainerBoxParentDataCls<RenderBox> {
public:
    int index;


private:

};
using ListWheelParentData = std::shared_ptr<ListWheelParentDataCls>;

class RenderListWheelViewportCls : public RenderBoxCls {
public:
    static double defaultDiameterRatio;

    static double defaultPerspective;

    static String diameterRatioZeroMessage;

    static String perspectiveTooHighMessage;

    static String clipBehaviorAndRenderChildrenOutsideViewportConflict;

    ListWheelChildManager childManager;


     RenderListWheelViewportCls(ListWheelChildManager childManager, List<RenderBox> children, Clip clipBehavior, double diameterRatio, double itemExtent, double magnification, double offAxisFraction, ViewportOffset offset, double overAndUnderCenterOpacity, double perspective, bool renderChildrenOutsideViewport, double squeeze, bool useMagnifier);

    virtual ViewportOffset offset();

    virtual void  offset(ViewportOffset value);

    virtual double diameterRatio();

    virtual void  diameterRatio(double value);

    virtual double perspective();

    virtual void  perspective(double value);

    virtual double offAxisFraction();

    virtual void  offAxisFraction(double value);

    virtual bool useMagnifier();

    virtual void  useMagnifier(bool value);

    virtual double magnification();

    virtual void  magnification(double value);

    virtual double overAndUnderCenterOpacity();

    virtual void  overAndUnderCenterOpacity(double value);

    virtual double itemExtent();

    virtual void  itemExtent(double value);

    virtual double squeeze();

    virtual void  squeeze(double value);

    virtual bool renderChildrenOutsideViewport();

    virtual void  renderChildrenOutsideViewport(bool value);

    virtual Clip clipBehavior();

    virtual void  clipBehavior(Clip value);

    virtual void setupParentData(RenderObject child);

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual bool isRepaintBoundary();

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual bool sizedByParent();

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual int indexOf(RenderBox child);

    virtual int scrollOffsetToIndex(double scrollOffset);

    virtual double indexToScrollOffset(int index);

    virtual void performLayout();

    virtual void paint(PaintingContext context, Offset offset);

    virtual void dispose();

    virtual void applyPaintTransform(RenderBox child, Matrix4 transform);

    virtual Rect describeApproximatePaintClip(RenderObject child);

    virtual bool hitTestChildren(Offset position, BoxHitTestResult result);

    virtual RevealedOffset getOffsetToReveal(double alignment, Rect rect, RenderObject target);

    virtual void showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect);

private:
    ViewportOffset _offset;

    double _diameterRatio;

    double _perspective;

    double _offAxisFraction;

    bool _useMagnifier;

    double _magnification;

    double _overAndUnderCenterOpacity;

    double _itemExtent;

    double _squeeze;

    bool _renderChildrenOutsideViewport;

    Clip _clipBehavior;

    LayerHandle<ClipRectLayer> _clipRectLayer;


    virtual void _hasScrolled();

    virtual double _viewportExtent();

    virtual double _minEstimatedScrollExtent();

    virtual double _maxEstimatedScrollExtent();

    virtual double _topScrollMarginExtent();

    virtual double _getUntransformedPaintingCoordinateY(double layoutCoordinateY);

    virtual double _maxVisibleRadian();

    virtual double _getIntrinsicCrossAxis(_ChildSizingFunction childSize);

    virtual void _createChild(RenderBox after, int index);

    virtual void _destroyChild(RenderBox child);

    virtual void _layoutChild(RenderBox child, BoxConstraints constraints, int index);

    virtual bool _shouldClipAtCurrentOffset();

    virtual void _paintVisibleChildren(PaintingContext context, Offset offset);

    virtual void _paintTransformedChild(RenderBox child, PaintingContext context, Offset layoutOffset, Offset offset);

    virtual void _paintChildWithMagnifier(RenderBox child, PaintingContext context, Matrix4 cylindricalTransform, Offset offset, Offset offsetToCenter, Offset untransformedPaintingCoordinates);

    virtual void _paintChildCylindrically(RenderBox child, PaintingContext context, Matrix4 cylindricalTransform, Offset offset, Offset offsetToCenter);

    virtual Matrix4 _magnifyTransform();

    virtual Matrix4 _centerOriginTransform(Matrix4 originalMatrix);

};
using RenderListWheelViewport = std::shared_ptr<RenderListWheelViewportCls>;


#endif