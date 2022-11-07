#ifndef LAYOUT_BUILDER_H
#define LAYOUT_BUILDER_H
#include <memory>

#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include "debug.hpp"
#include "framework.hpp"



class ConstrainedLayoutBuilder<ConstraintType extends Constraints> : RenderObjectWidget {
public:
    FunctionType builder;


     ConstrainedLayoutBuilder(FunctionType builder, Unknown);

    RenderObjectElement createElement();

private:

};

class _LayoutBuilderElement<ConstraintType extends Constraints> : RenderObjectElement {
public:

    RenderConstrainedLayoutBuilder<ConstraintType, RenderObject> renderObject();

    void visitChildren(ElementVisitor visitor);

    void forgetChild(Element child);

    void mount(Object newSlot, Element parent);

    void update(ConstrainedLayoutBuilder<ConstraintType> newWidget);

    void performRebuild();

    void unmount();

    void insertRenderObjectChild(RenderObject child, Object slot);

    void moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot);

    void removeRenderObjectChild(RenderObject child, Object slot);

private:
    Element _child;


     _LayoutBuilderElement(ConstrainedLayoutBuilder<ConstraintType> widget);

    void _layout(ConstraintType constraints);

};

class RenderConstrainedLayoutBuilder<ConstraintType extends Constraints, ChildType extends RenderObject> {
public:

    void updateCallback(LayoutCallback<ConstraintType> value);

    void markNeedsBuild();

    void rebuildIfNecessary();

private:
    LayoutCallback<ConstraintType> _callback;

    bool _needsBuild;

    Constraints _previousConstraints;


};

class LayoutBuilder : ConstrainedLayoutBuilder<BoxConstraints> {
public:

     LayoutBuilder(Unknown, Unknown);

    LayoutWidgetBuilder builder();

    RenderObject createRenderObject(BuildContext context);

private:

};

class _RenderLayoutBuilder : RenderBox {
public:

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    double computeDistanceToActualBaseline(TextBaseline baseline);

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    void paint(PaintingContext context, Offset offset);

private:

    bool _debugThrowIfNotCheckingIntrinsics();

};
FlutterErrorDetails _debugReportException(DiagnosticsNode context, Object exception, InformationCollector informationCollector, StackTrace stack);


#endif