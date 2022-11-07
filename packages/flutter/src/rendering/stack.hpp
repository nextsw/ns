#ifndef STACK_H
#define STACK_H
#include <memory>

#include <math/math.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "box.hpp"
#include "layer.hpp"
#include "layout_helper.hpp"
#include "object.hpp"



class RelativeRect {
public:
    static const RelativeRect fill;

    double left;

    double top;

    double right;

    double bottom;


    void  fromLTRB(double bottom, double left, double right, double top);

    void  fromSize(Size container, Rect rect);

    void  fromRect(Rect container, Rect rect);

    void  fromDirectional(double bottom, double end, double start, TextDirection textDirection, double top);

    bool hasInsets();

    RelativeRect shift(Offset offset);

    RelativeRect inflate(double delta);

    RelativeRect deflate(double delta);

    RelativeRect intersect(RelativeRect other);

    Rect toRect(Rect container);

    Size toSize(Size container);

    static RelativeRect lerp(RelativeRect a, RelativeRect b, double t);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class StackParentData : ContainerBoxParentData<RenderBox> {
public:
    double top;

    double right;

    double bottom;

    double left;

    double width;

    double height;


    RelativeRect rect();

    void  rect(RelativeRect value);

    bool isPositioned();

    String toString();

private:

};

enum StackFit{
    loose,
    expand,
    passthrough,
} // end StackFit

class RenderStack : RenderBox {
public:

     RenderStack(AlignmentGeometry alignment, List<RenderBox> children, Clip clipBehavior, StackFit fit, TextDirection textDirection);

    void setupParentData(RenderBox child);

    AlignmentGeometry alignment();

    void  alignment(AlignmentGeometry value);

    TextDirection textDirection();

    void  textDirection(TextDirection value);

    StackFit fit();

    void  fit(StackFit value);

    Clip clipBehavior();

    void  clipBehavior(Clip value);

    static double getIntrinsicDimension(RenderBox firstChild, FunctionType mainChildSizeGetter);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    double computeDistanceToActualBaseline(TextBaseline baseline);

    static bool layoutPositionedChild(Alignment alignment, RenderBox child, StackParentData childParentData, Size size);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    void paintStack(PaintingContext context, Offset offset);

    void paint(PaintingContext context, Offset offset);

    void dispose();

    Rect describeApproximatePaintClip(RenderObject child);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    bool _hasVisualOverflow;

    Alignment _resolvedAlignment;

    AlignmentGeometry _alignment;

    TextDirection _textDirection;

    StackFit _fit;

    Clip _clipBehavior;

    LayerHandle<ClipRectLayer> _clipRectLayer;


    void _resolve();

    void _markNeedResolution();

    Size _computeSize(BoxConstraints constraints, ChildLayouter layoutChild);

};

class RenderIndexedStack : RenderStack {
public:

     RenderIndexedStack(Unknown, Unknown, int index, Unknown);

    void visitChildrenForSemantics(RenderObjectVisitor visitor);

    int index();

    void  index(int value);

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    void paintStack(PaintingContext context, Offset offset);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    List<DiagnosticsNode> debugDescribeChildren();

private:
    int _index;


    RenderBox _childAtIndex();

};

#endif