#ifndef FLOW_H
#define FLOW_H
#include <memory>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <vector_math/vector_math_64.hpp>
#include "box.hpp"
#include "layer.hpp"
#include "object.hpp"



class FlowPaintingContext {
public:

    Size size();

    int childCount();

    Size getChildSize(int i);

    void paintChild(int i, double opacity, Matrix4 transform);

private:

};

class FlowDelegate {
public:

     FlowDelegate(Listenable repaint);

    Size getSize(BoxConstraints constraints);

    BoxConstraints getConstraintsForChild(BoxConstraints constraints, int i);

    void paintChildren(FlowPaintingContext context);

    bool shouldRelayout(FlowDelegate oldDelegate);

    bool shouldRepaint(FlowDelegate oldDelegate);

    String toString();

private:
    Listenable _repaint;


};

class FlowParentData : ContainerBoxParentData<RenderBox> {
public:

private:
    Matrix4 _transform;


};

class RenderFlow : RenderBox {
public:

     RenderFlow(List<RenderBox> children, Clip clipBehavior, FlowDelegate delegate);

    void setupParentData(RenderBox child);

    FlowDelegate delegate();

    void  delegate(FlowDelegate newDelegate);

    Clip clipBehavior();

    void  clipBehavior(Clip value);

    void attach(PipelineOwner owner);

    void detach();

    bool isRepaintBoundary();

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    Size getChildSize(int i);

    void paintChild(int i, double opacity, Matrix4 transform);

    void paint(PaintingContext context, Offset offset);

    void dispose();

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    void applyPaintTransform(RenderBox child, Matrix4 transform);

private:
    FlowDelegate _delegate;

    Clip _clipBehavior;

    List<RenderBox> _randomAccessChildren;

    List<int> _lastPaintOrder;

    PaintingContext _paintingContext;

    Offset _paintingOffset;

    LayerHandle<ClipRectLayer> _clipRectLayer;


    Size _getSize(BoxConstraints constraints);

    void _paintWithDelegate(PaintingContext context, Offset offset);

};

#endif