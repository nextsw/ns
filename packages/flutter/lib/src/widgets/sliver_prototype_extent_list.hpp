#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SLIVER_PROTOTYPE_EXTENT_LIST
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SLIVER_PROTOTYPE_EXTENT_LIST
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "framework.hpp"
#include "sliver.hpp"


class SliverPrototypeExtentListCls : public SliverMultiBoxAdaptorWidgetCls {
public:
    Widget prototypeItem;


     SliverPrototypeExtentListCls(Unknown delegate, Unknown key, Widget prototypeItem);

    virtual RenderSliverMultiBoxAdaptor createRenderObject(BuildContext context);

    virtual SliverMultiBoxAdaptorElement createElement();

private:

};
using SliverPrototypeExtentList = std::shared_ptr<SliverPrototypeExtentListCls>;

class _SliverPrototypeExtentListElementCls : public SliverMultiBoxAdaptorElementCls {
public:

    virtual _RenderSliverPrototypeExtentList renderObject();

    virtual void insertRenderObjectChild(RenderObject child, Object slot);

    virtual void didAdoptChild(RenderBox child);

    virtual void moveRenderObjectChild(RenderBox child, Object newSlot, Object oldSlot);

    virtual void removeRenderObjectChild(RenderBox child, Object slot);

    virtual void visitChildren(ElementVisitor visitor);

    virtual void mount(Object newSlot, Element parent);

    virtual void update(SliverPrototypeExtentList newWidget);

private:
    Element _prototype;

    static Object _prototypeSlot;


     _SliverPrototypeExtentListElementCls(SliverPrototypeExtentList widget);
};
using _SliverPrototypeExtentListElement = std::shared_ptr<_SliverPrototypeExtentListElementCls>;

class _RenderSliverPrototypeExtentListCls : public RenderSliverFixedExtentBoxAdaptorCls {
public:

    virtual RenderBox child();

    virtual void  child(RenderBox value);

    virtual void performLayout();

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual void redepthChildren();

    virtual void visitChildren(RenderObjectVisitor visitor);

    virtual double itemExtent();

private:
    RenderBox _child;


     _RenderSliverPrototypeExtentListCls(_SliverPrototypeExtentListElement childManager);

};
using _RenderSliverPrototypeExtentList = std::shared_ptr<_RenderSliverPrototypeExtentListCls>;


#endif