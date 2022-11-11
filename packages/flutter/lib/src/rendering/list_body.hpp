#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_LIST_BODY
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_LIST_BODY
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include "box.hpp"
#include "object.hpp"


class ListBodyParentDataCls : public ContainerBoxParentDataCls<RenderBox> {
public:

private:

};
using ListBodyParentData = std::shared_ptr<ListBodyParentDataCls>;

class RenderListBodyCls : public RenderBoxCls {
public:

     RenderListBodyCls(AxisDirection axisDirection, List<RenderBox> children);

    virtual void setupParentData(RenderBox child);

    virtual AxisDirection axisDirection();

    virtual void  axisDirection(AxisDirection value);

    virtual Axis mainAxis();

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual double computeDistanceToActualBaseline(TextBaseline baseline);

    virtual void paint(PaintingContext context, Offset offset);

    virtual bool hitTestChildren(BoxHitTestResult result, Offset position);

private:
    AxisDirection _axisDirection;


    virtual bool _debugCheckConstraints(BoxConstraints constraints);

    virtual double _getIntrinsicCrossAxis(_ChildSizingFunction childSize);

    virtual double _getIntrinsicMainAxis(_ChildSizingFunction childSize);

};
using RenderListBody = std::shared_ptr<RenderListBodyCls>;


#endif