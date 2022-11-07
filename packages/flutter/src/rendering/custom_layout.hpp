#ifndef CUSTOM_LAYOUT_H
#define CUSTOM_LAYOUT_H
#include <memory>

#include <flutter/foundation.hpp>
#include "box.hpp"
#include "object.hpp"



class MultiChildLayoutParentData : ContainerBoxParentData<RenderBox> {
public:
    Object id;


    String toString();

private:

};

class MultiChildLayoutDelegate {
public:

     MultiChildLayoutDelegate(Listenable relayout);

    bool hasChild(Object childId);

    Size layoutChild(Object childId, BoxConstraints constraints);

    void positionChild(Object childId, Offset offset);

    Size getSize(BoxConstraints constraints);

    void performLayout(Size size);

    bool shouldRelayout(MultiChildLayoutDelegate oldDelegate);

    String toString();

private:
    Listenable _relayout;

    Map<Object, RenderBox> _idToChild;

    Set<RenderBox> _debugChildrenNeedingLayout;


    DiagnosticsNode _debugDescribeChild(RenderBox child);

    void _callPerformLayout(RenderBox firstChild, Size size);

};

class RenderCustomMultiChildLayoutBox : RenderBox {
public:

     RenderCustomMultiChildLayoutBox(List<RenderBox> children, MultiChildLayoutDelegate delegate);

    void setupParentData(RenderBox child);

    MultiChildLayoutDelegate delegate();

    void  delegate(MultiChildLayoutDelegate newDelegate);

    void attach(PipelineOwner owner);

    void detach();

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    void paint(PaintingContext context, Offset offset);

    bool hitTestChildren(Offset position, BoxHitTestResult result);

private:
    MultiChildLayoutDelegate _delegate;


    Size _getSize(BoxConstraints constraints);

};

#endif