#ifndef SHIFTED_BOX_H
#define SHIFTED_BOX_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include "box.hpp"
#include "debug.hpp"
#include "debug_overflow_indicator.hpp"
#include "layer.hpp"
#include "object.hpp"
#include "stack.hpp"



class RenderShiftedBox : RenderBox {
public:

     RenderShiftedBox(RenderBox child);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    double computeDistanceToActualBaseline(TextBaseline baseline);

    void paint(PaintingContext context, Offset offset);

    bool hitTestChildren(Offset position, BoxHitTestResult result);

private:

};

class RenderPadding : RenderShiftedBox {
public:

     RenderPadding(RenderBox child, EdgeInsetsGeometry padding, TextDirection textDirection);

    EdgeInsetsGeometry padding();

    void  padding(EdgeInsetsGeometry value);

    TextDirection textDirection();

    void  textDirection(TextDirection value);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    void debugPaintSize(PaintingContext context, Offset offset);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    EdgeInsets _resolvedPadding;

    EdgeInsetsGeometry _padding;

    TextDirection _textDirection;


    void _resolve();

    void _markNeedResolution();

};

class RenderAligningShiftedBox : RenderShiftedBox {
public:

     RenderAligningShiftedBox(AlignmentGeometry alignment, RenderBox child, TextDirection textDirection);

    AlignmentGeometry alignment();

    void  alignment(AlignmentGeometry value);

    TextDirection textDirection();

    void  textDirection(TextDirection value);

    void alignChild();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Alignment _resolvedAlignment;

    AlignmentGeometry _alignment;

    TextDirection _textDirection;


    void _resolve();

    void _markNeedResolution();

};

class RenderPositionedBox : RenderAligningShiftedBox {
public:

     RenderPositionedBox(Unknown, Unknown, double heightFactor, Unknown, double widthFactor);

    double widthFactor();

    void  widthFactor(double value);

    double heightFactor();

    void  heightFactor(double value);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    void debugPaintSize(PaintingContext context, Offset offset);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _widthFactor;

    double _heightFactor;


};

class RenderConstrainedOverflowBox : RenderAligningShiftedBox {
public:

     RenderConstrainedOverflowBox(Unknown, Unknown, double maxHeight, double maxWidth, double minHeight, double minWidth, Unknown);

    double minWidth();

    void  minWidth(double value);

    double maxWidth();

    void  maxWidth(double value);

    double minHeight();

    void  minHeight(double value);

    double maxHeight();

    void  maxHeight(double value);

    bool sizedByParent();

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _minWidth;

    double _maxWidth;

    double _minHeight;

    double _maxHeight;


    BoxConstraints _getInnerConstraints(BoxConstraints constraints);

};

class RenderConstraintsTransformBox : RenderAligningShiftedBox {
public:

     RenderConstraintsTransformBox(Unknown, Unknown, Clip clipBehavior, BoxConstraintsTransform constraintsTransform, Unknown);

    BoxConstraintsTransform constraintsTransform();

    void  constraintsTransform(BoxConstraintsTransform value);

    Clip clipBehavior();

    void  clipBehavior(Clip value);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    void paint(PaintingContext context, Offset offset);

    void dispose();

    Rect describeApproximatePaintClip(RenderObject child);

    String toStringShort();

private:
    BoxConstraintsTransform _constraintsTransform;

    Clip _clipBehavior;

    Rect _overflowContainerRect;

    Rect _overflowChildRect;

    bool _isOverflowing;

    BoxConstraints _childConstraints;

    LayerHandle<ClipRectLayer> _clipRectLayer;


};

class RenderUnconstrainedBox : RenderConstraintsTransformBox {
public:

     RenderUnconstrainedBox(Unknown, Unknown, Unknown, Axis constrainedAxis, Unknown);

    Axis constrainedAxis();

    void  constrainedAxis(Axis value);

private:
    Axis _constrainedAxis;


    static BoxConstraints _unconstrained(BoxConstraints constraints);

    static BoxConstraints _widthConstrained(BoxConstraints constraints);

    static BoxConstraints _heightConstrained(BoxConstraints constraints);

    static BoxConstraintsTransform _convertAxis(Axis constrainedAxis);

};

class RenderSizedOverflowBox : RenderAligningShiftedBox {
public:

     RenderSizedOverflowBox(Unknown, Unknown, Size requestedSize, Unknown);

    Size requestedSize();

    void  requestedSize(Size value);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    double computeDistanceToActualBaseline(TextBaseline baseline);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

private:
    Size _requestedSize;


};

class RenderFractionallySizedOverflowBox : RenderAligningShiftedBox {
public:

     RenderFractionallySizedOverflowBox(Unknown, Unknown, double heightFactor, Unknown, double widthFactor);

    double widthFactor();

    void  widthFactor(double value);

    double heightFactor();

    void  heightFactor(double value);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _widthFactor;

    double _heightFactor;


    BoxConstraints _getInnerConstraints(BoxConstraints constraints);

};

class SingleChildLayoutDelegate {
public:

     SingleChildLayoutDelegate(Listenable relayout);

    Size getSize(BoxConstraints constraints);

    BoxConstraints getConstraintsForChild(BoxConstraints constraints);

    Offset getPositionForChild(Size childSize, Size size);

    bool shouldRelayout(SingleChildLayoutDelegate oldDelegate);

private:
    Listenable _relayout;


};

class RenderCustomSingleChildLayoutBox : RenderShiftedBox {
public:

     RenderCustomSingleChildLayoutBox(RenderBox child, SingleChildLayoutDelegate delegate);

    SingleChildLayoutDelegate delegate();

    void  delegate(SingleChildLayoutDelegate newDelegate);

    void attach(PipelineOwner owner);

    void detach();

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

private:
    SingleChildLayoutDelegate _delegate;


    Size _getSize(BoxConstraints constraints);

};

class RenderBaseline : RenderShiftedBox {
public:

     RenderBaseline(double baseline, TextBaseline baselineType, RenderBox child);

    double baseline();

    void  baseline(double value);

    TextBaseline baselineType();

    void  baselineType(TextBaseline value);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _baseline;

    TextBaseline _baselineType;


};

#endif