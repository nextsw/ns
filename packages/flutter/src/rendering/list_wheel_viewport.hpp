#ifndef LIST_WHEEL_VIEWPORT_H
#define LIST_WHEEL_VIEWPORT_H
#include <memory>

#include <math/math.hpp>
#include <flutter/animation.hpp>
#include <vector_math/vector_math_64.hpp>
#include "box.hpp"
#include "layer.hpp"
#include "object.hpp"
#include "viewport.hpp"
#include "viewport_offset.hpp"



class ListWheelChildManager {
public:

    int childCount();

    bool childExistsAt(int index);

    void createChild(RenderBox after, int index);

    void removeChild(RenderBox child);

private:

};

class ListWheelParentData : ContainerBoxParentData<RenderBox> {
public:
    int index;


private:

};

class RenderListWheelViewport : RenderBox {
public:
    static const double defaultDiameterRatio;

    static const double defaultPerspective;

    static const String diameterRatioZeroMessage;

    static const String perspectiveTooHighMessage;

    static const String clipBehaviorAndRenderChildrenOutsideViewportConflict;

    ListWheelChildManager childManager;


     RenderListWheelViewport(ListWheelChildManager childManager, List<RenderBox> children, Clip clipBehavior, double diameterRatio, double itemExtent, double magnification, double offAxisFraction, ViewportOffset offset, double overAndUnderCenterOpacity, double perspective, bool renderChildrenOutsideViewport, double squeeze, bool useMagnifier);

    ViewportOffset offset();

    void  offset(ViewportOffset value);

    double diameterRatio();

    void  diameterRatio(double value);

    double perspective();

    void  perspective(double value);

    double offAxisFraction();

    void  offAxisFraction(double value);

    bool useMagnifier();

    void  useMagnifier(bool value);

    double magnification();

    void  magnification(double value);

    double overAndUnderCenterOpacity();

    void  overAndUnderCenterOpacity(double value);

    double itemExtent();

    void  itemExtent(double value);

    double squeeze();

    void  squeeze(double value);

    bool renderChildrenOutsideViewport();

    void  renderChildrenOutsideViewport(bool value);

    Clip clipBehavior();

    void  clipBehavior(Clip value);

    void setupParentData(RenderObject child);

    void attach(PipelineOwner owner);

    void detach();

    bool isRepaintBoundary();

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    bool sizedByParent();

    Size computeDryLayout(BoxConstraints constraints);

    int indexOf(RenderBox child);

    int scrollOffsetToIndex(double scrollOffset);

    double indexToScrollOffset(int index);

    void performLayout();

    void paint(PaintingContext context, Offset offset);

    void dispose();

    void applyPaintTransform(RenderBox child, Matrix4 transform);

    Rect describeApproximatePaintClip(RenderObject child);

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    RevealedOffset getOffsetToReveal(double alignment, Rect rect, RenderObject target);

    void showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect);

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


    void _hasScrolled();

    double _viewportExtent();

    double _minEstimatedScrollExtent();

    double _maxEstimatedScrollExtent();

    double _topScrollMarginExtent();

    double _getUntransformedPaintingCoordinateY(double layoutCoordinateY);

    double _maxVisibleRadian();

    double _getIntrinsicCrossAxis(_ChildSizingFunction childSize);

    void _createChild(RenderBox after, int index);

    void _destroyChild(RenderBox child);

    void _layoutChild(RenderBox child, BoxConstraints constraints, int index);

    bool _shouldClipAtCurrentOffset();

    void _paintVisibleChildren(PaintingContext context, Offset offset);

    void _paintTransformedChild(RenderBox child, PaintingContext context, Offset layoutOffset, Offset offset);

    void _paintChildWithMagnifier(RenderBox child, PaintingContext context, Matrix4 cylindricalTransform, Offset offset, Offset offsetToCenter, Offset untransformedPaintingCoordinates);

    void _paintChildCylindrically(RenderBox child, PaintingContext context, Matrix4 cylindricalTransform, Offset offset, Offset offsetToCenter);

    Matrix4 _magnifyTransform();

    Matrix4 _centerOriginTransform(Matrix4 originalMatrix);

};

#endif