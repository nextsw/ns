#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_CUSTOM_LAYOUT
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_CUSTOM_LAYOUT
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "box.hpp"
#include "object.hpp"


class MultiChildLayoutParentDataCls : public ContainerBoxParentDataCls<RenderBox> {
public:
    Object id;


    virtual String toString();

private:

};
using MultiChildLayoutParentData = std::shared_ptr<MultiChildLayoutParentDataCls>;

class MultiChildLayoutDelegateCls : public ObjectCls {
public:

     MultiChildLayoutDelegateCls(Listenable relayout);

    virtual bool hasChild(Object childId);

    virtual Size layoutChild(Object childId, BoxConstraints constraints);

    virtual void positionChild(Object childId, Offset offset);

    virtual Size getSize(BoxConstraints constraints);

    virtual void performLayout(Size size);
    virtual bool shouldRelayout(MultiChildLayoutDelegate oldDelegate);
    virtual String toString();

private:
    Listenable _relayout;

    Map<Object, RenderBox> _idToChild;

    Set<RenderBox> _debugChildrenNeedingLayout;


    virtual DiagnosticsNode _debugDescribeChild(RenderBox child);

    virtual void _callPerformLayout(RenderBox firstChild, Size size);

};
using MultiChildLayoutDelegate = std::shared_ptr<MultiChildLayoutDelegateCls>;

class RenderCustomMultiChildLayoutBoxCls : public RenderBoxCls {
public:

     RenderCustomMultiChildLayoutBoxCls(List<RenderBox> children, MultiChildLayoutDelegate delegate);

    virtual void setupParentData(RenderBox child);

    virtual MultiChildLayoutDelegate delegate();

    virtual void  delegate(MultiChildLayoutDelegate newDelegate);

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual void paint(PaintingContext context, Offset offset);

    virtual bool hitTestChildren(Offset position, BoxHitTestResult result);

private:
    MultiChildLayoutDelegate _delegate;


    virtual Size _getSize(BoxConstraints constraints);

};
using RenderCustomMultiChildLayoutBox = std::shared_ptr<RenderCustomMultiChildLayoutBoxCls>;


#endif