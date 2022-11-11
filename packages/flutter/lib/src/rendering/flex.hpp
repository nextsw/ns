#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_FLEX
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_FLEX
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "box.hpp"
#include "debug_overflow_indicator.hpp"
#include "layer.hpp"
#include "layout_helper.hpp"
#include "object.hpp"


enum FlexFit{
    tight,
    loose,
} // end FlexFit

class FlexParentDataCls : public ContainerBoxParentDataCls<RenderBox> {
public:
    int flex;

    FlexFit fit;


    virtual String toString();

private:

};
using FlexParentData = std::shared_ptr<FlexParentDataCls>;

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


class RenderFlexCls : public RenderBoxCls {
public:

     RenderFlexCls(List<RenderBox> children, Clip clipBehavior, CrossAxisAlignment crossAxisAlignment, Axis direction, MainAxisAlignment mainAxisAlignment, MainAxisSize mainAxisSize, TextBaseline textBaseline, TextDirection textDirection, VerticalDirection verticalDirection);

    virtual Axis direction();

    virtual void  direction(Axis value);

    virtual MainAxisAlignment mainAxisAlignment();

    virtual void  mainAxisAlignment(MainAxisAlignment value);

    virtual MainAxisSize mainAxisSize();

    virtual void  mainAxisSize(MainAxisSize value);

    virtual CrossAxisAlignment crossAxisAlignment();

    virtual void  crossAxisAlignment(CrossAxisAlignment value);

    virtual TextDirection textDirection();

    virtual void  textDirection(TextDirection value);

    virtual VerticalDirection verticalDirection();

    virtual void  verticalDirection(VerticalDirection value);

    virtual TextBaseline textBaseline();

    virtual void  textBaseline(TextBaseline value);

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

    virtual bool hitTestChildren(BoxHitTestResult result, Offset position);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void dispose();

    virtual Rect describeApproximatePaintClip(RenderObject child);

    virtual String toStringShort();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

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


    virtual bool _debugHasNecessaryDirections();

    virtual bool _hasOverflow();

    virtual bool _canComputeIntrinsics();

    virtual double _getIntrinsicSize(_ChildSizingFunction childSize, double extent, Axis sizingDirection);

    virtual int _getFlex(RenderBox child);

    virtual FlexFit _getFit(RenderBox child);

    virtual double _getCrossSize(Size size);

    virtual double _getMainSize(Size size);

    virtual FlutterError _debugCheckConstraints(BoxConstraints constraints, bool reportParentConstraints);

    virtual _LayoutSizes _computeSizes(BoxConstraints constraints, ChildLayouter layoutChild);

};
using RenderFlex = std::shared_ptr<RenderFlexCls>;

class _LayoutSizesCls : public ObjectCls {
public:
    double mainSize;

    double crossSize;

    double allocatedSize;


private:

     _LayoutSizesCls(double allocatedSize, double crossSize, double mainSize);
};
using _LayoutSizes = std::shared_ptr<_LayoutSizesCls>;


#endif