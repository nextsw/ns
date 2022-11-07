#ifndef SLIVER_PROTOTYPE_EXTENT_LIST_H
#define SLIVER_PROTOTYPE_EXTENT_LIST_H
#include <memory>

#include <flutter/rendering.hpp>
#include "framework.hpp"
#include "sliver.hpp"



class SliverPrototypeExtentList : SliverMultiBoxAdaptorWidget {
public:
    Widget prototypeItem;


     SliverPrototypeExtentList(Unknown, Unknown, Widget prototypeItem);

    RenderSliverMultiBoxAdaptor createRenderObject(BuildContext context);

    SliverMultiBoxAdaptorElement createElement();

private:

};

class _SliverPrototypeExtentListElement : SliverMultiBoxAdaptorElement {
public:

    _RenderSliverPrototypeExtentList renderObject();

    void insertRenderObjectChild(RenderObject child, Object slot);

    void didAdoptChild(RenderBox child);

    void moveRenderObjectChild(RenderBox child, Object newSlot, Object oldSlot);

    void removeRenderObjectChild(RenderBox child, Object slot);

    void visitChildren(ElementVisitor visitor);

    void mount(Object newSlot, Element parent);

    void update(SliverPrototypeExtentList newWidget);

private:
    Element _prototype;

    static Object _prototypeSlot;


     _SliverPrototypeExtentListElement(SliverPrototypeExtentList widget);

};

class _RenderSliverPrototypeExtentList : RenderSliverFixedExtentBoxAdaptor {
public:

    RenderBox child();

    void  child(RenderBox value);

    void performLayout();

    void attach(PipelineOwner owner);

    void detach();

    void redepthChildren();

    void visitChildren(RenderObjectVisitor visitor);

    double itemExtent();

private:
    RenderBox _child;


     _RenderSliverPrototypeExtentList(_SliverPrototypeExtentListElement childManager);

};

#endif