#ifndef OVERFLOW_BAR_H
#define OVERFLOW_BAR_H
#include <memory>

#include <math/math.hpp>
#include <flutter/rendering.hpp>
#include "basic.hpp"
#include "framework.hpp"



enum OverflowBarAlignment{
    start,
    end,
    center,
} // end OverflowBarAlignment

class OverflowBar : MultiChildRenderObjectWidget {
public:
    double spacing;

    MainAxisAlignment alignment;

    double overflowSpacing;

    OverflowBarAlignment overflowAlignment;

    VerticalDirection overflowDirection;

    TextDirection textDirection;

    Clip clipBehavior;


     OverflowBar(MainAxisAlignment alignment, Unknown, Clip clipBehavior, Unknown, OverflowBarAlignment overflowAlignment, VerticalDirection overflowDirection, double overflowSpacing, double spacing, TextDirection textDirection);

    RenderObject createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderObject renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _OverflowBarParentData : ContainerBoxParentData<RenderBox> {
public:

private:

};

class _RenderOverflowBar : RenderBox {
public:

    double spacing();

    void  spacing(double value);

    MainAxisAlignment alignment();

    void  alignment(MainAxisAlignment value);

    double overflowSpacing();

    void  overflowSpacing(double value);

    OverflowBarAlignment overflowAlignment();

    void  overflowAlignment(OverflowBarAlignment value);

    VerticalDirection overflowDirection();

    void  overflowDirection(VerticalDirection value);

    TextDirection textDirection();

    void  textDirection(TextDirection value);

    Clip clipBehavior();

    void  clipBehavior(Clip value);

    void setupParentData(RenderBox child);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeDistanceToActualBaseline(TextBaseline baseline);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    void paint(PaintingContext context, Offset offset);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _spacing;

    MainAxisAlignment _alignment;

    double _overflowSpacing;

    OverflowBarAlignment _overflowAlignment;

    VerticalDirection _overflowDirection;

    TextDirection _textDirection;

    Clip _clipBehavior;


     _RenderOverflowBar(MainAxisAlignment alignment, List<RenderBox> children, Clip clipBehavior, OverflowBarAlignment overflowAlignment, VerticalDirection overflowDirection, double overflowSpacing, double spacing, TextDirection textDirection);

};

#endif