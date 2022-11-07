#ifndef WRAP_H
#define WRAP_H
#include <memory>

#include <math/math.hpp>
#include "box.hpp"
#include "layer.hpp"
#include "layout_helper.hpp"
#include "object.hpp"



enum WrapAlignment{
    start,
    end,
    center,
    spaceBetween,
    spaceAround,
    spaceEvenly,
} // end WrapAlignment

enum WrapCrossAlignment{
    start,
    end,
    center,
} // end WrapCrossAlignment

class _RunMetrics {
public:
    double mainAxisExtent;

    double crossAxisExtent;

    int childCount;


private:

     _RunMetrics(int childCount, double crossAxisExtent, double mainAxisExtent);

};

class WrapParentData : ContainerBoxParentData<RenderBox> {
public:

private:
    int _runIndex;


};

class RenderWrap : RenderBox {
public:

     RenderWrap(WrapAlignment alignment, List<RenderBox> children, Clip clipBehavior, WrapCrossAlignment crossAxisAlignment, Axis direction, WrapAlignment runAlignment, double runSpacing, double spacing, TextDirection textDirection, VerticalDirection verticalDirection);

    Axis direction();

    void  direction(Axis value);

    WrapAlignment alignment();

    void  alignment(WrapAlignment value);

    double spacing();

    void  spacing(double value);

    WrapAlignment runAlignment();

    void  runAlignment(WrapAlignment value);

    double runSpacing();

    void  runSpacing(double value);

    WrapCrossAlignment crossAxisAlignment();

    void  crossAxisAlignment(WrapCrossAlignment value);

    TextDirection textDirection();

    void  textDirection(TextDirection value);

    VerticalDirection verticalDirection();

    void  verticalDirection(VerticalDirection value);

    Clip clipBehavior();

    void  clipBehavior(Clip value);

    void setupParentData(RenderBox child);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    double computeDistanceToActualBaseline(TextBaseline baseline);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    void paint(PaintingContext context, Offset offset);

    void dispose();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Axis _direction;

    WrapAlignment _alignment;

    double _spacing;

    WrapAlignment _runAlignment;

    double _runSpacing;

    WrapCrossAlignment _crossAxisAlignment;

    TextDirection _textDirection;

    VerticalDirection _verticalDirection;

    Clip _clipBehavior;

    bool _hasVisualOverflow;

    LayerHandle<ClipRectLayer> _clipRectLayer;


    bool _debugHasNecessaryDirections();

    double _getMainAxisExtent(Size childSize);

    double _getCrossAxisExtent(Size childSize);

    Offset _getOffset(double crossAxisOffset, double mainAxisOffset);

    double _getChildCrossAxisOffset(double childCrossAxisExtent, bool flipCrossAxis, double runCrossAxisExtent);

    Size _computeDryLayout(BoxConstraints constraints, ChildLayouter layoutChild);

};

#endif