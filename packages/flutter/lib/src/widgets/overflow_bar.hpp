#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_OVERFLOW_BAR
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_OVERFLOW_BAR
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "basic.hpp"
#include "framework.hpp"


enum OverflowBarAlignment{
    start,
    end,
    center,
} // end OverflowBarAlignment

class OverflowBarCls : public MultiChildRenderObjectWidgetCls {
public:
    double spacing;

    MainAxisAlignment alignment;

    double overflowSpacing;

    OverflowBarAlignment overflowAlignment;

    VerticalDirection overflowDirection;

    TextDirection textDirection;

    Clip clipBehavior;


     OverflowBarCls(MainAxisAlignment alignment, Unknown children, Clip clipBehavior, Unknown key, OverflowBarAlignment overflowAlignment, VerticalDirection overflowDirection, double overflowSpacing, double spacing, TextDirection textDirection);

    virtual RenderObject createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderObject renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using OverflowBar = std::shared_ptr<OverflowBarCls>;

class _OverflowBarParentDataCls : public ContainerBoxParentDataCls<RenderBox> {
public:

private:

};
using _OverflowBarParentData = std::shared_ptr<_OverflowBarParentDataCls>;

class _RenderOverflowBarCls : public RenderBoxCls {
public:

    virtual double spacing();

    virtual void  spacing(double value);

    virtual MainAxisAlignment alignment();

    virtual void  alignment(MainAxisAlignment value);

    virtual double overflowSpacing();

    virtual void  overflowSpacing(double value);

    virtual OverflowBarAlignment overflowAlignment();

    virtual void  overflowAlignment(OverflowBarAlignment value);

    virtual VerticalDirection overflowDirection();

    virtual void  overflowDirection(VerticalDirection value);

    virtual TextDirection textDirection();

    virtual void  textDirection(TextDirection value);

    virtual Clip clipBehavior();

    virtual void  clipBehavior(Clip value);

    virtual void setupParentData(RenderBox child);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeDistanceToActualBaseline(TextBaseline baseline);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual bool hitTestChildren(BoxHitTestResult result, Offset position);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _spacing;

    MainAxisAlignment _alignment;

    double _overflowSpacing;

    OverflowBarAlignment _overflowAlignment;

    VerticalDirection _overflowDirection;

    TextDirection _textDirection;

    Clip _clipBehavior;


     _RenderOverflowBarCls(MainAxisAlignment alignment, List<RenderBox> children, Clip clipBehavior, OverflowBarAlignment overflowAlignment, VerticalDirection overflowDirection, double overflowSpacing, double spacing, TextDirection textDirection);

};
using _RenderOverflowBar = std::shared_ptr<_RenderOverflowBarCls>;


#endif