#ifndef FLEX_H
#define FLEX_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include "box.hpp"
#include "debug_overflow_indicator.hpp"
#include "layer.hpp"
#include "layout_helper.hpp"
#include "object.hpp"



enum FlexFit{
    tight,
    loose,
} // end FlexFit

class FlexParentData : ContainerBoxParentData<RenderBox> {
public:
    int flex;

    FlexFit fit;


    String toString();

private:

};

enum MainAxisSize{
    min,
    max,
} // end MainAxisSize

enum MainAxisAlignment{
    start,
    end,
    center,
    spaceBetween,
    spaceAround,
    spaceEvenly,
} // end MainAxisAlignment

enum CrossAxisAlignment{
    start,
    end,
    center,
    stretch,
    baseline,
} // end CrossAxisAlignment
bool _startIsTopLeft(Axis direction, TextDirection textDirection, VerticalDirection verticalDirection);


class RenderFlex : RenderBox {
public:

     RenderFlex(List<RenderBox> children, Clip clipBehavior, CrossAxisAlignment crossAxisAlignment, Axis direction, MainAxisAlignment mainAxisAlignment, MainAxisSize mainAxisSize, TextBaseline textBaseline, TextDirection textDirection, VerticalDirection verticalDirection);

    Axis direction();

    void  direction(Axis value);

    MainAxisAlignment mainAxisAlignment();

    void  mainAxisAlignment(MainAxisAlignment value);

    MainAxisSize mainAxisSize();

    void  mainAxisSize(MainAxisSize value);

    CrossAxisAlignment crossAxisAlignment();

    void  crossAxisAlignment(CrossAxisAlignment value);

    TextDirection textDirection();

    void  textDirection(TextDirection value);

    VerticalDirection verticalDirection();

    void  verticalDirection(VerticalDirection value);

    TextBaseline textBaseline();

    void  textBaseline(TextBaseline value);

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

    Rect describeApproximatePaintClip(RenderObject child);

    String toStringShort();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Axis _direction;

    MainAxisAlignment _mainAxisAlignment;

    MainAxisSize _mainAxisSize;

    CrossAxisAlignment _crossAxisAlignment;

    TextDirection _textDirection;

    VerticalDirection _verticalDirection;

    TextBaseline _textBaseline;

    double _overflow;

    Clip _clipBehavior;

    LayerHandle<ClipRectLayer> _clipRectLayer;


    bool _debugHasNecessaryDirections();

    bool _hasOverflow();

    bool _canComputeIntrinsics();

    double _getIntrinsicSize(_ChildSizingFunction childSize, double extent, Axis sizingDirection);

    int _getFlex(RenderBox child);

    FlexFit _getFit(RenderBox child);

    double _getCrossSize(Size size);

    double _getMainSize(Size size);

    FlutterError _debugCheckConstraints(BoxConstraints constraints, bool reportParentConstraints);

    _LayoutSizes _computeSizes(BoxConstraints constraints, ChildLayouter layoutChild);

};

class _LayoutSizes {
public:
    double mainSize;

    double crossSize;

    double allocatedSize;


private:

     _LayoutSizes(double allocatedSize, double crossSize, double mainSize);

};

#endif