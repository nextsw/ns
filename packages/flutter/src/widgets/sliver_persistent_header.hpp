#ifndef SLIVER_PERSISTENT_HEADER_H
#define SLIVER_PERSISTENT_HEADER_H
#include <memory>

#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include <flutter/scheduler.hpp>
#include "framework.hpp"
#include "scroll_position.hpp"
#include "scrollable.hpp"



class SliverPersistentHeaderDelegate {
public:

     SliverPersistentHeaderDelegate();

    Widget build(BuildContext context, bool overlapsContent, double shrinkOffset);

    double minExtent();

    double maxExtent();

    TickerProvider vsync();

    FloatingHeaderSnapConfiguration snapConfiguration();

    OverScrollHeaderStretchConfiguration stretchConfiguration();

    PersistentHeaderShowOnScreenConfiguration showOnScreenConfiguration();

    bool shouldRebuild(SliverPersistentHeaderDelegate oldDelegate);

private:

};

class SliverPersistentHeader : StatelessWidget {
public:
    SliverPersistentHeaderDelegate delegate;

    bool pinned;

    bool floating;


     SliverPersistentHeader(SliverPersistentHeaderDelegate delegate, bool floating, Unknown, bool pinned);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _FloatingHeader : StatefulWidget {
public:
    Widget child;


    _FloatingHeaderState createState();

private:

     _FloatingHeader(Widget child);

};

class _FloatingHeaderState : State<_FloatingHeader> {
public:

    void didChangeDependencies();

    void dispose();

    Widget build(BuildContext context);

private:
    ScrollPosition _position;


    RenderSliverFloatingPersistentHeader _headerRenderer();

    void _isScrollingListener();

};

class _SliverPersistentHeaderElement : RenderObjectElement {
public:
    bool floating;

    Element child;


    _RenderSliverPersistentHeaderForWidgetsMixin renderObject();

    void mount(Object newSlot, Element parent);

    void unmount();

    void update(_SliverPersistentHeaderRenderObjectWidget newWidget);

    void performRebuild();

    void forgetChild(Element child);

    void insertRenderObjectChild(RenderBox child, Object slot);

    void moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot);

    void removeRenderObjectChild(RenderObject child, Object slot);

    void visitChildren(ElementVisitor visitor);

private:

     _SliverPersistentHeaderElement(bool floating, _SliverPersistentHeaderRenderObjectWidget widget);

    void _build(bool overlapsContent, double shrinkOffset);

};

class _SliverPersistentHeaderRenderObjectWidget : RenderObjectWidget {
public:
    SliverPersistentHeaderDelegate delegate;

    bool floating;


    _SliverPersistentHeaderElement createElement();

    _RenderSliverPersistentHeaderForWidgetsMixin createRenderObject(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder description);

private:

     _SliverPersistentHeaderRenderObjectWidget(SliverPersistentHeaderDelegate delegate, bool floating);

};

class _RenderSliverPersistentHeaderForWidgetsMixin {
public:

    double minExtent();

    double maxExtent();

    void updateChild(bool overlapsContent, double shrinkOffset);

    void triggerRebuild();

private:
    _SliverPersistentHeaderElement _element;


};

class _SliverScrollingPersistentHeader : _SliverPersistentHeaderRenderObjectWidget {
public:

    _RenderSliverPersistentHeaderForWidgetsMixin createRenderObject(BuildContext context);

private:

     _SliverScrollingPersistentHeader(Unknown);

};

class _RenderSliverScrollingPersistentHeaderForWidgets : RenderSliverScrollingPersistentHeader {
public:

private:

     _RenderSliverScrollingPersistentHeaderForWidgets(Unknown);

};

class _SliverPinnedPersistentHeader : _SliverPersistentHeaderRenderObjectWidget {
public:

    _RenderSliverPersistentHeaderForWidgetsMixin createRenderObject(BuildContext context);

private:

     _SliverPinnedPersistentHeader(Unknown);

};

class _RenderSliverPinnedPersistentHeaderForWidgets : RenderSliverPinnedPersistentHeader {
public:

private:

     _RenderSliverPinnedPersistentHeaderForWidgets(Unknown, Unknown);

};

class _SliverFloatingPersistentHeader : _SliverPersistentHeaderRenderObjectWidget {
public:

    _RenderSliverPersistentHeaderForWidgetsMixin createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, _RenderSliverFloatingPersistentHeaderForWidgets renderObject);

private:

     _SliverFloatingPersistentHeader(Unknown);

};

class _RenderSliverFloatingPinnedPersistentHeaderForWidgets : RenderSliverFloatingPinnedPersistentHeader {
public:

private:

     _RenderSliverFloatingPinnedPersistentHeaderForWidgets(Unknown, Unknown, Unknown, Unknown);

};

class _SliverFloatingPinnedPersistentHeader : _SliverPersistentHeaderRenderObjectWidget {
public:

    _RenderSliverPersistentHeaderForWidgetsMixin createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, _RenderSliverFloatingPinnedPersistentHeaderForWidgets renderObject);

private:

     _SliverFloatingPinnedPersistentHeader(Unknown);

};

class _RenderSliverFloatingPersistentHeaderForWidgets : RenderSliverFloatingPersistentHeader {
public:

private:

     _RenderSliverFloatingPersistentHeaderForWidgets(Unknown, Unknown, Unknown, Unknown);

};

#endif