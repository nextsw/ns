#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_FLOW
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_FLOW
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "box.hpp"
#include "layer.hpp"
#include "object.hpp"


class FlowPaintingContextCls : public ObjectCls {
public:

    virtual Size size();
    virtual int childCount();
    virtual Size getChildSize(int i);
    virtual void paintChild(int i, double opacity, Matrix4 transform);
private:

};
using FlowPaintingContext = std::shared_ptr<FlowPaintingContextCls>;

class FlowDelegateCls : public ObjectCls {
public:

     FlowDelegateCls(Listenable repaint);

    virtual Size getSize(BoxConstraints constraints);

    virtual BoxConstraints getConstraintsForChild(BoxConstraints constraints, int i);

    virtual void paintChildren(FlowPaintingContext context);
    virtual bool shouldRelayout(FlowDelegate oldDelegate);

    virtual bool shouldRepaint(FlowDelegate oldDelegate);
    virtual String toString();

private:
    Listenable _repaint;


};
using FlowDelegate = std::shared_ptr<FlowDelegateCls>;

class FlowParentDataCls : public ContainerBoxParentDataCls<RenderBox> {
public:

private:
    Matrix4 _transform;


};
using FlowParentData = std::shared_ptr<FlowParentDataCls>;

class RenderFlowCls : public RenderBoxCls {
public:

     RenderFlowCls(List<RenderBox> children, Clip clipBehavior, FlowDelegate delegate);

    virtual void setupParentData(RenderBox child);

    virtual FlowDelegate delegate();

    virtual void  delegate(FlowDelegate newDelegate);

    virtual Clip clipBehavior();

    virtual void  clipBehavior(Clip value);

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual bool isRepaintBoundary();

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual Size getChildSize(int i);

    virtual void paintChild(int i, double opacity, Matrix4 transform);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void dispose();

    virtual bool hitTestChildren(Offset position, BoxHitTestResult result);

    virtual void applyPaintTransform(RenderBox child, Matrix4 transform);

private:
    FlowDelegate _delegate;

    Clip _clipBehavior;

    List<RenderBox> _randomAccessChildren;

    List<int> _lastPaintOrder;

    PaintingContext _paintingContext;

    Offset _paintingOffset;

    LayerHandle<ClipRectLayer> _clipRectLayer;


    virtual Size _getSize(BoxConstraints constraints);

    virtual void _paintWithDelegate(PaintingContext context, Offset offset);

};
using RenderFlow = std::shared_ptr<RenderFlowCls>;


#endif