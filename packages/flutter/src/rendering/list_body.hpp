#ifndef LIST_BODY_H
#define LIST_BODY_H
#include <memory>

#include <math/math.hpp>
#include "box.hpp"
#include "object.hpp"



class ListBodyParentData : ContainerBoxParentData<RenderBox> {
public:

private:

};

class RenderListBody : RenderBox {
public:

     RenderListBody(AxisDirection axisDirection, List<RenderBox> children);

    void setupParentData(RenderBox child);

    AxisDirection axisDirection();

    void  axisDirection(AxisDirection value);

    Axis mainAxis();

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    double computeDistanceToActualBaseline(TextBaseline baseline);

    void paint(PaintingContext context, Offset offset);

    bool hitTestChildren(Offset position, BoxHitTestResult result);

private:
    AxisDirection _axisDirection;


    bool _debugCheckConstraints(BoxConstraints constraints);

    double _getIntrinsicCrossAxis(_ChildSizingFunction childSize);

    double _getIntrinsicMainAxis(_ChildSizingFunction childSize);

};

#endif