#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_VIEWPORT
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_VIEWPORT
#include <base.hpp>
#include <packages/flutter/lib/rendering.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "scroll_notification.hpp"


class ViewportCls : public MultiChildRenderObjectWidgetCls {
public:
    AxisDirection axisDirection;

    AxisDirection crossAxisDirection;

    double anchor;

    ViewportOffset offset;

    Key center;

    double cacheExtent;

    CacheExtentStyle cacheExtentStyle;

    Clip clipBehavior;


     ViewportCls(double anchor, AxisDirection axisDirection, double cacheExtent, CacheExtentStyle cacheExtentStyle, Key center, Clip clipBehavior, AxisDirection crossAxisDirection, Unknown key, ViewportOffset offset, List<Widget> slivers);

    static AxisDirection getDefaultCrossAxisDirection(AxisDirection axisDirection, BuildContext context);

    virtual RenderViewport createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderViewport renderObject);

    virtual MultiChildRenderObjectElement createElement();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using Viewport = std::shared_ptr<ViewportCls>;

class _ViewportElementCls : public MultiChildRenderObjectElementCls {
public:

    virtual RenderViewport renderObject();

    virtual void mount(Object newSlot, Element parent);

    virtual void update(MultiChildRenderObjectWidget newWidget);

    virtual void insertRenderObjectChild(RenderObject child, IndexedSlot<Element> slot);

    virtual void moveRenderObjectChild(RenderObject child, IndexedSlot<Element> newSlot, IndexedSlot<Element> oldSlot);

    virtual void removeRenderObjectChild(RenderObject child, Object slot);

    virtual void debugVisitOnstageChildren(ElementVisitor visitor);

private:
    bool _doingMountOrUpdate;

    int _centerSlotIndex;


     _ViewportElementCls(Viewport widget);
    virtual void _updateCenter();

};
using _ViewportElement = std::shared_ptr<_ViewportElementCls>;

class ShrinkWrappingViewportCls : public MultiChildRenderObjectWidgetCls {
public:
    AxisDirection axisDirection;

    AxisDirection crossAxisDirection;

    ViewportOffset offset;

    Clip clipBehavior;


     ShrinkWrappingViewportCls(AxisDirection axisDirection, Clip clipBehavior, AxisDirection crossAxisDirection, Unknown key, ViewportOffset offset, List<Widget> slivers);

    virtual RenderShrinkWrappingViewport createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderShrinkWrappingViewport renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using ShrinkWrappingViewport = std::shared_ptr<ShrinkWrappingViewportCls>;


#endif