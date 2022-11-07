#ifndef VIEWPORT_H
#define VIEWPORT_H
#include <memory>
#include <flutter/rendering.hpp>

#include <flutter/rendering.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "scroll_notification.hpp"



class Viewport : MultiChildRenderObjectWidget {
public:
    AxisDirection axisDirection;

    AxisDirection crossAxisDirection;

    double anchor;

    ViewportOffset offset;

    Key center;

    double cacheExtent;

    CacheExtentStyle cacheExtentStyle;

    Clip clipBehavior;


     Viewport(double anchor, AxisDirection axisDirection, double cacheExtent, CacheExtentStyle cacheExtentStyle, Key center, Clip clipBehavior, AxisDirection crossAxisDirection, Unknown, ViewportOffset offset, List<Widget> slivers);

    static AxisDirection getDefaultCrossAxisDirection(AxisDirection axisDirection, BuildContext context);

    RenderViewport createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderViewport renderObject);

    MultiChildRenderObjectElement createElement();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _ViewportElement : MultiChildRenderObjectElement {
public:

    RenderViewport renderObject();

    void mount(Object newSlot, Element parent);

    void update(MultiChildRenderObjectWidget newWidget);

    void insertRenderObjectChild(RenderObject child, IndexedSlot<Element> slot);

    void moveRenderObjectChild(RenderObject child, IndexedSlot<Element> newSlot, IndexedSlot<Element> oldSlot);

    void removeRenderObjectChild(RenderObject child, Object slot);

    void debugVisitOnstageChildren(ElementVisitor visitor);

private:
    bool _doingMountOrUpdate;

    int _centerSlotIndex;


     _ViewportElement(Viewport widget);

    void _updateCenter();

};

class ShrinkWrappingViewport : MultiChildRenderObjectWidget {
public:
    AxisDirection axisDirection;

    AxisDirection crossAxisDirection;

    ViewportOffset offset;

    Clip clipBehavior;


     ShrinkWrappingViewport(AxisDirection axisDirection, Clip clipBehavior, AxisDirection crossAxisDirection, Unknown, ViewportOffset offset, List<Widget> slivers);

    RenderShrinkWrappingViewport createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderShrinkWrappingViewport renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

#endif