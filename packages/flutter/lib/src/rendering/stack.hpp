#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_STACK
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_STACK
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "box.hpp"
#include "layer.hpp"
#include "layout_helper.hpp"
#include "object.hpp"


class RelativeRectCls : public ObjectCls {
public:
    static RelativeRect fill;

    double left;

    double top;

    double right;

    double bottom;


    virtual void  fromLTRB(double left, double top, double right, double bottom);

    virtual void  fromSize(Rect rect, Size container);

    virtual void  fromRect(Rect rect, Rect container);

    virtual void  fromDirectional(double bottom, double end, double start, TextDirection textDirection, double top);

    virtual bool hasInsets();

    virtual RelativeRect shift(Offset offset);

    virtual RelativeRect inflate(double delta);

    virtual RelativeRect deflate(double delta);

    virtual RelativeRect intersect(RelativeRect other);

    virtual Rect toRect(Rect container);

    virtual Size toSize(Size container);

    static RelativeRect lerp(RelativeRect a, RelativeRect b, double t);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using RelativeRect = std::shared_ptr<RelativeRectCls>;

class StackParentDataCls : public ContainerBoxParentDataCls<RenderBox> {
public:
    double top;

    double right;

    double bottom;

    double left;

    double width;

    double height;


    virtual RelativeRect rect();

    virtual void  rect(RelativeRect value);

    virtual bool isPositioned();

    virtual String toString();

private:

};
using StackParentData = std::shared_ptr<StackParentDataCls>;

enum StackFit{
    loose,
    expand,
    passthrough,
} // end StackFit

class RenderStackCls : public RenderBoxCls {
public:

     RenderStackCls(AlignmentGeometry alignment, List<RenderBox> children, Clip clipBehavior, StackFit fit, TextDirection textDirection);

    virtual void setupParentData(RenderBox child);

    virtual AlignmentGeometry alignment();

    virtual void  alignment(AlignmentGeometry value);

    virtual TextDirection textDirection();

    virtual void  textDirection(TextDirection value);

    virtual StackFit fit();

    virtual void  fit(StackFit value);

    virtual Clip clipBehavior();

    virtual void  clipBehavior(Clip value);

    static double getIntrinsicDimension(RenderBox firstChild, std::function<double(RenderBox child)> mainChildSizeGetter);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual double computeDistanceToActualBaseline(TextBaseline baseline);

    static bool layoutPositionedChild(RenderBox child, StackParentData childParentData, Size size, Alignment alignment);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual bool hitTestChildren(BoxHitTestResult result, Offset position);

    virtual void paintStack(PaintingContext context, Offset offset);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void dispose();

    virtual Rect describeApproximatePaintClip(RenderObject child);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    bool _hasVisualOverflow;

    Alignment _resolvedAlignment;

    AlignmentGeometry _alignment;

    TextDirection _textDirection;

    StackFit _fit;

    Clip _clipBehavior;

    LayerHandle<ClipRectLayer> _clipRectLayer;


    virtual void _resolve();

    virtual void _markNeedResolution();

    virtual Size _computeSize(BoxConstraints constraints, ChildLayouter layoutChild);

};
using RenderStack = std::shared_ptr<RenderStackCls>;

class RenderIndexedStackCls : public RenderStackCls {
public:

     RenderIndexedStackCls(Unknown alignment, Unknown children, int index, Unknown textDirection);

    virtual void visitChildrenForSemantics(RenderObjectVisitor visitor);

    virtual int index();

    virtual void  index(int value);

    virtual bool hitTestChildren(BoxHitTestResult result, Offset position);

    virtual void paintStack(PaintingContext context, Offset offset);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual List<DiagnosticsNode> debugDescribeChildren();

private:
    int _index;


    virtual RenderBox _childAtIndex();

};
using RenderIndexedStack = std::shared_ptr<RenderIndexedStackCls>;


#endif