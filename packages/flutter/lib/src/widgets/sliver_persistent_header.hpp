#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SLIVER_PERSISTENT_HEADER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SLIVER_PERSISTENT_HEADER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include "framework.hpp"
#include "scroll_position.hpp"
#include "scrollable.hpp"


class SliverPersistentHeaderDelegateCls : public ObjectCls {
public:

     SliverPersistentHeaderDelegateCls();
    virtual Widget build(BuildContext context, double shrinkOffset, bool overlapsContent);
    virtual double minExtent();
    virtual double maxExtent();
    virtual TickerProvider vsync();

    virtual FloatingHeaderSnapConfiguration snapConfiguration();

    virtual OverScrollHeaderStretchConfiguration stretchConfiguration();

    virtual PersistentHeaderShowOnScreenConfiguration showOnScreenConfiguration();

    virtual bool shouldRebuild(SliverPersistentHeaderDelegate oldDelegate);
private:

};
using SliverPersistentHeaderDelegate = std::shared_ptr<SliverPersistentHeaderDelegateCls>;

class SliverPersistentHeaderCls : public StatelessWidgetCls {
public:
    SliverPersistentHeaderDelegate delegate;

    bool pinned;

    bool floating;


     SliverPersistentHeaderCls(SliverPersistentHeaderDelegate delegate, bool floating, Key key, bool pinned);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using SliverPersistentHeader = std::shared_ptr<SliverPersistentHeaderCls>;

class _FloatingHeaderCls : public StatefulWidgetCls {
public:
    Widget child;


    virtual _FloatingHeaderState createState();

private:

     _FloatingHeaderCls(Widget child);
};
using _FloatingHeader = std::shared_ptr<_FloatingHeaderCls>;

class _FloatingHeaderStateCls : public StateCls<_FloatingHeader> {
public:

    virtual void didChangeDependencies();

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    ScrollPosition _position;


    virtual RenderSliverFloatingPersistentHeader _headerRenderer();

    virtual void _isScrollingListener();

};
using _FloatingHeaderState = std::shared_ptr<_FloatingHeaderStateCls>;

class _SliverPersistentHeaderElementCls : public RenderObjectElementCls {
public:
    bool floating;

    Element child;


    virtual _RenderSliverPersistentHeaderForWidgetsMixin renderObject();

    virtual void mount(Element parent, Object newSlot);

    virtual void unmount();

    virtual void update(_SliverPersistentHeaderRenderObjectWidget newWidget);

    virtual void performRebuild();

    virtual void forgetChild(Element child);

    virtual void insertRenderObjectChild(RenderBox child, Object slot);

    virtual void moveRenderObjectChild(RenderObject child, Object oldSlot, Object newSlot);

    virtual void removeRenderObjectChild(RenderObject child, Object slot);

    virtual void visitChildren(ElementVisitor visitor);

private:

     _SliverPersistentHeaderElementCls(Widget widget, bool floating);

    virtual void _build(double shrinkOffset, bool overlapsContent);

};
using _SliverPersistentHeaderElement = std::shared_ptr<_SliverPersistentHeaderElementCls>;

class _SliverPersistentHeaderRenderObjectWidgetCls : public RenderObjectWidgetCls {
public:
    SliverPersistentHeaderDelegate delegate;

    bool floating;


    virtual _SliverPersistentHeaderElement createElement();

    virtual _RenderSliverPersistentHeaderForWidgetsMixin createRenderObject(BuildContext context) override;
    virtual void debugFillProperties(DiagnosticPropertiesBuilder description);

private:

     _SliverPersistentHeaderRenderObjectWidgetCls(SliverPersistentHeaderDelegate delegate, bool floating);

};
using _SliverPersistentHeaderRenderObjectWidget = std::shared_ptr<_SliverPersistentHeaderRenderObjectWidgetCls>;

class _RenderSliverPersistentHeaderForWidgetsMixinCls : public ObjectCls {
public:

    virtual double minExtent();

    virtual double maxExtent();

    virtual void updateChild(double shrinkOffset, bool overlapsContent);

    virtual void triggerRebuild();

private:
    _SliverPersistentHeaderElement _element;


};
using _RenderSliverPersistentHeaderForWidgetsMixin = std::shared_ptr<_RenderSliverPersistentHeaderForWidgetsMixinCls>;

class _SliverScrollingPersistentHeaderCls : public _SliverPersistentHeaderRenderObjectWidgetCls {
public:

    virtual _RenderSliverPersistentHeaderForWidgetsMixin createRenderObject(BuildContext context);

private:

     _SliverScrollingPersistentHeaderCls(SliverPersistentHeaderDelegate delegate);
};
using _SliverScrollingPersistentHeader = std::shared_ptr<_SliverScrollingPersistentHeaderCls>;

class _RenderSliverScrollingPersistentHeaderForWidgetsCls : public RenderSliverScrollingPersistentHeaderCls {
public:

private:

     _RenderSliverScrollingPersistentHeaderForWidgetsCls(OverScrollHeaderStretchConfiguration stretchConfiguration);
};
using _RenderSliverScrollingPersistentHeaderForWidgets = std::shared_ptr<_RenderSliverScrollingPersistentHeaderForWidgetsCls>;

class _SliverPinnedPersistentHeaderCls : public _SliverPersistentHeaderRenderObjectWidgetCls {
public:

    virtual _RenderSliverPersistentHeaderForWidgetsMixin createRenderObject(BuildContext context);

private:

     _SliverPinnedPersistentHeaderCls(SliverPersistentHeaderDelegate delegate);
};
using _SliverPinnedPersistentHeader = std::shared_ptr<_SliverPinnedPersistentHeaderCls>;

class _RenderSliverPinnedPersistentHeaderForWidgetsCls : public RenderSliverPinnedPersistentHeaderCls {
public:

private:

     _RenderSliverPinnedPersistentHeaderForWidgetsCls(PersistentHeaderShowOnScreenConfiguration showOnScreenConfiguration, OverScrollHeaderStretchConfiguration stretchConfiguration);
};
using _RenderSliverPinnedPersistentHeaderForWidgets = std::shared_ptr<_RenderSliverPinnedPersistentHeaderForWidgetsCls>;

class _SliverFloatingPersistentHeaderCls : public _SliverPersistentHeaderRenderObjectWidgetCls {
public:

    virtual _RenderSliverPersistentHeaderForWidgetsMixin createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, _RenderSliverFloatingPersistentHeaderForWidgets renderObject);

private:

     _SliverFloatingPersistentHeaderCls(SliverPersistentHeaderDelegate delegate);

};
using _SliverFloatingPersistentHeader = std::shared_ptr<_SliverFloatingPersistentHeaderCls>;

class _RenderSliverFloatingPinnedPersistentHeaderForWidgetsCls : public RenderSliverFloatingPinnedPersistentHeaderCls {
public:

private:

     _RenderSliverFloatingPinnedPersistentHeaderForWidgetsCls(PersistentHeaderShowOnScreenConfiguration showOnScreenConfiguration, FloatingHeaderSnapConfiguration snapConfiguration, OverScrollHeaderStretchConfiguration stretchConfiguration, TickerProvider vsync);
};
using _RenderSliverFloatingPinnedPersistentHeaderForWidgets = std::shared_ptr<_RenderSliverFloatingPinnedPersistentHeaderForWidgetsCls>;

class _SliverFloatingPinnedPersistentHeaderCls : public _SliverPersistentHeaderRenderObjectWidgetCls {
public:

    virtual _RenderSliverPersistentHeaderForWidgetsMixin createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, _RenderSliverFloatingPinnedPersistentHeaderForWidgets renderObject);

private:

     _SliverFloatingPinnedPersistentHeaderCls(SliverPersistentHeaderDelegate delegate);

};
using _SliverFloatingPinnedPersistentHeader = std::shared_ptr<_SliverFloatingPinnedPersistentHeaderCls>;

class _RenderSliverFloatingPersistentHeaderForWidgetsCls : public RenderSliverFloatingPersistentHeaderCls {
public:

private:

     _RenderSliverFloatingPersistentHeaderForWidgetsCls(PersistentHeaderShowOnScreenConfiguration showOnScreenConfiguration, FloatingHeaderSnapConfiguration snapConfiguration, OverScrollHeaderStretchConfiguration stretchConfiguration, TickerProvider vsync);
};
using _RenderSliverFloatingPersistentHeaderForWidgets = std::shared_ptr<_RenderSliverFloatingPersistentHeaderForWidgetsCls>;


#endif