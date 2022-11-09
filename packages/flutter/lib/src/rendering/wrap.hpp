#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_WRAP
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_WRAP
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
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

class _RunMetricsCls : public ObjectCls {
public:
    double mainAxisExtent;

    double crossAxisExtent;

    int childCount;


private:

     _RunMetricsCls(int childCount, double crossAxisExtent, double mainAxisExtent);
};
using _RunMetrics = std::shared_ptr<_RunMetricsCls>;

class WrapParentDataCls : public ContainerBoxParentDataCls<RenderBox> {
public:

private:
    int _runIndex;


};
using WrapParentData = std::shared_ptr<WrapParentDataCls>;

class RenderWrapCls : public RenderBoxCls {
public:

     RenderWrapCls(WrapAlignment alignment, List<RenderBox> children, Clip clipBehavior, WrapCrossAlignment crossAxisAlignment, Axis direction, WrapAlignment runAlignment, double runSpacing, double spacing, TextDirection textDirection, VerticalDirection verticalDirection);

    virtual Axis direction();

    virtual void  direction(Axis value);

    virtual WrapAlignment alignment();

    virtual void  alignment(WrapAlignment value);

    virtual double spacing();

    virtual void  spacing(double value);

    virtual WrapAlignment runAlignment();

    virtual void  runAlignment(WrapAlignment value);

    virtual double runSpacing();

    virtual void  runSpacing(double value);

    virtual WrapCrossAlignment crossAxisAlignment();

    virtual void  crossAxisAlignment(WrapCrossAlignment value);

    virtual TextDirection textDirection();

    virtual void  textDirection(TextDirection value);

    virtual VerticalDirection verticalDirection();

    virtual void  verticalDirection(VerticalDirection value);

    virtual Clip clipBehavior();

    virtual void  clipBehavior(Clip value);

    virtual void setupParentData(RenderBox child);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual double computeDistanceToActualBaseline(TextBaseline baseline);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual bool hitTestChildren(Offset position, BoxHitTestResult result);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void dispose();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

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


    virtual bool _debugHasNecessaryDirections();

    virtual double _getMainAxisExtent(Size childSize);

    virtual double _getCrossAxisExtent(Size childSize);

    virtual Offset _getOffset(double crossAxisOffset, double mainAxisOffset);

    virtual double _getChildCrossAxisOffset(double childCrossAxisExtent, bool flipCrossAxis, double runCrossAxisExtent);

    virtual Size _computeDryLayout(BoxConstraints constraints, ChildLayouter layoutChild);

};
using RenderWrap = std::shared_ptr<RenderWrapCls>;


#endif