#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_LAYOUT_BUILDER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_LAYOUT_BUILDER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "debug.hpp"
#include "framework.hpp"


template<typename ConstraintType>
class ConstrainedLayoutBuilderCls : public RenderObjectWidgetCls {
public:
    std::function<Widget(BuildContext , ConstraintType )> builder;


     ConstrainedLayoutBuilderCls(std::function<Widget(BuildContext , ConstraintType )> builder, Unknown key);

    virtual RenderObjectElement createElement();

private:

};
template<typename ConstraintType>
using ConstrainedLayoutBuilder = std::shared_ptr<ConstrainedLayoutBuilderCls<ConstraintType>>;

template<typename ConstraintType>
class _LayoutBuilderElementCls : public RenderObjectElementCls {
public:

    virtual RenderConstrainedLayoutBuilder<ConstraintType, RenderObject> renderObject();

    virtual void visitChildren(ElementVisitor visitor);

    virtual void forgetChild(Element child);

    virtual void mount(Object newSlot, Element parent);

    virtual void update(ConstrainedLayoutBuilder<ConstraintType> newWidget);

    virtual void performRebuild();

    virtual void unmount();

    virtual void insertRenderObjectChild(RenderObject child, Object slot);

    virtual void moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot);

    virtual void removeRenderObjectChild(RenderObject child, Object slot);

private:
    Element _child;


     _LayoutBuilderElementCls(ConstrainedLayoutBuilder<ConstraintType> widget);
    virtual void _layout(ConstraintType constraints);

};
template<typename ConstraintType>
using _LayoutBuilderElement = std::shared_ptr<_LayoutBuilderElementCls<ConstraintType>>;

template<typename ConstraintType, typename ChildType>
class RenderConstrainedLayoutBuilderCls : public ObjectCls {
public:

    virtual void updateCallback(LayoutCallback<ConstraintType> value);

    virtual void markNeedsBuild();

    virtual void rebuildIfNecessary();

private:
    LayoutCallback<ConstraintType> _callback;

    bool _needsBuild;

    Constraints _previousConstraints;


};
template<typename ConstraintType, typename ChildType>
using RenderConstrainedLayoutBuilder = std::shared_ptr<RenderConstrainedLayoutBuilderCls<ConstraintType, ChildType>>;

class LayoutBuilderCls : public ConstrainedLayoutBuilderCls<BoxConstraints> {
public:

     LayoutBuilderCls(Unknown builder, Unknown key);

    virtual LayoutWidgetBuilder builder();

    virtual RenderObject createRenderObject(BuildContext context);

private:

};
using LayoutBuilder = std::shared_ptr<LayoutBuilderCls>;

class _RenderLayoutBuilderCls : public RenderBoxCls {
public:

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual double computeDistanceToActualBaseline(TextBaseline baseline);

    virtual bool hitTestChildren(Offset position, BoxHitTestResult result);

    virtual void paint(PaintingContext context, Offset offset);

private:

    virtual bool _debugThrowIfNotCheckingIntrinsics();

};
using _RenderLayoutBuilder = std::shared_ptr<_RenderLayoutBuilderCls>;
FlutterErrorDetails _debugReportException(DiagnosticsNode context, Object exception, InformationCollector informationCollector, StackTrace stack);



#endif