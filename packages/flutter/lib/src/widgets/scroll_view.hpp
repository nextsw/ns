#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_VIEW
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_VIEW
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "focus_manager.hpp"
#include "focus_scope.hpp"
#include "framework.hpp"
#include "media_query.hpp"
#include "notification_listener.hpp"
#include "primary_scroll_controller.hpp"
#include "scroll_configuration.hpp"
#include "scroll_controller.hpp"
#include "scroll_notification.hpp"
#include "scroll_physics.hpp"
#include "scrollable.hpp"
#include "sliver.hpp"
#include "sliver_prototype_extent_list.hpp"
#include "viewport.hpp"


enum ScrollViewKeyboardDismissBehavior{
    manual,
    onDrag,
} // end ScrollViewKeyboardDismissBehavior

class ScrollViewCls : public StatelessWidgetCls {
public:
    Axis scrollDirection;

    bool reverse;

    ScrollController controller;

    bool primary;

    ScrollPhysics physics;

    ScrollBehavior scrollBehavior;

    bool shrinkWrap;

    Key center;

    double anchor;

    double cacheExtent;

    int semanticChildCount;

    DragStartBehavior dragStartBehavior;

    ScrollViewKeyboardDismissBehavior keyboardDismissBehavior;

    String restorationId;

    Clip clipBehavior;


     ScrollViewCls(double anchor, double cacheExtent, Key center, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, Unknown key, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, ScrollPhysics physics, bool primary, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection, int semanticChildCount, bool shrinkWrap);

    virtual AxisDirection getDirection(BuildContext context);

    virtual List<Widget> buildSlivers(BuildContext context);
    virtual Widget buildViewport(BuildContext context, ViewportOffset offset, AxisDirection axisDirection, List<Widget> slivers);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using ScrollView = std::shared_ptr<ScrollViewCls>;

class CustomScrollViewCls : public ScrollViewCls {
public:
    List<Widget> slivers;


     CustomScrollViewCls(Unknown anchor, Unknown cacheExtent, Unknown center, Unknown clipBehavior, Unknown controller, Unknown dragStartBehavior, Unknown key, Unknown keyboardDismissBehavior, Unknown physics, Unknown primary, Unknown restorationId, Unknown reverse, Unknown scrollBehavior, Unknown scrollDirection, Unknown semanticChildCount, Unknown shrinkWrap, List<Widget> slivers);
    virtual List<Widget> buildSlivers(BuildContext context);

private:

};
using CustomScrollView = std::shared_ptr<CustomScrollViewCls>;

class BoxScrollViewCls : public ScrollViewCls {
public:
    EdgeInsetsGeometry padding;


     BoxScrollViewCls(Unknown cacheExtent, Unknown clipBehavior, Unknown controller, Unknown dragStartBehavior, Unknown key, Unknown keyboardDismissBehavior, EdgeInsetsGeometry padding, Unknown physics, Unknown primary, Unknown restorationId, Unknown reverse, Unknown scrollDirection, Unknown semanticChildCount, Unknown shrinkWrap);
    virtual List<Widget> buildSlivers(BuildContext context);

    virtual Widget buildChildLayout(BuildContext context);
    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using BoxScrollView = std::shared_ptr<BoxScrollViewCls>;

class ListViewCls : public BoxScrollViewCls {
public:
    double itemExtent;

    Widget prototypeItem;

    SliverChildDelegate childrenDelegate;


     ListViewCls(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown cacheExtent, List<Widget> children, Unknown clipBehavior, Unknown controller, Unknown dragStartBehavior, double itemExtent, Unknown key, Unknown keyboardDismissBehavior, Unknown padding, Unknown physics, Unknown primary, Widget prototypeItem, Unknown restorationId, Unknown reverse, Unknown scrollDirection, int semanticChildCount, Unknown shrinkWrap);

    virtual void  builder(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown cacheExtent, Unknown clipBehavior, Unknown controller, Unknown dragStartBehavior, ChildIndexGetter findChildIndexCallback, IndexedWidgetBuilder itemBuilder, int itemCount, double itemExtent, Unknown key, Unknown keyboardDismissBehavior, Unknown padding, Unknown physics, Unknown primary, Widget prototypeItem, Unknown restorationId, Unknown reverse, Unknown scrollDirection, int semanticChildCount, Unknown shrinkWrap);

    virtual void  separated(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown cacheExtent, Unknown clipBehavior, Unknown controller, Unknown dragStartBehavior, ChildIndexGetter findChildIndexCallback, IndexedWidgetBuilder itemBuilder, int itemCount, Unknown key, Unknown keyboardDismissBehavior, Unknown padding, Unknown physics, Unknown primary, Unknown restorationId, Unknown reverse, Unknown scrollDirection, IndexedWidgetBuilder separatorBuilder, Unknown shrinkWrap);

    virtual void  custom(Unknown cacheExtent, SliverChildDelegate childrenDelegate, Unknown clipBehavior, Unknown controller, Unknown dragStartBehavior, double itemExtent, Unknown key, Unknown keyboardDismissBehavior, Unknown padding, Unknown physics, Unknown primary, Widget prototypeItem, Unknown restorationId, Unknown reverse, Unknown scrollDirection, Unknown semanticChildCount, Unknown shrinkWrap);

    virtual Widget buildChildLayout(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    static int _computeActualChildCount(int itemCount);

};
using ListView = std::shared_ptr<ListViewCls>;

class GridViewCls : public BoxScrollViewCls {
public:
    SliverGridDelegate gridDelegate;

    SliverChildDelegate childrenDelegate;


     GridViewCls(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown cacheExtent, List<Widget> children, Unknown clipBehavior, Unknown controller, Unknown dragStartBehavior, SliverGridDelegate gridDelegate, Unknown key, Unknown keyboardDismissBehavior, Unknown padding, Unknown physics, Unknown primary, Unknown restorationId, Unknown reverse, Unknown scrollDirection, int semanticChildCount, Unknown shrinkWrap);

    virtual void  builder(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown cacheExtent, Unknown clipBehavior, Unknown controller, Unknown dragStartBehavior, ChildIndexGetter findChildIndexCallback, SliverGridDelegate gridDelegate, IndexedWidgetBuilder itemBuilder, int itemCount, Unknown key, Unknown keyboardDismissBehavior, Unknown padding, Unknown physics, Unknown primary, Unknown restorationId, Unknown reverse, Unknown scrollDirection, int semanticChildCount, Unknown shrinkWrap);

    virtual void  custom(Unknown cacheExtent, SliverChildDelegate childrenDelegate, Unknown clipBehavior, Unknown controller, Unknown dragStartBehavior, SliverGridDelegate gridDelegate, Unknown key, Unknown keyboardDismissBehavior, Unknown padding, Unknown physics, Unknown primary, Unknown restorationId, Unknown reverse, Unknown scrollDirection, Unknown semanticChildCount, Unknown shrinkWrap);

    virtual void  count(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown cacheExtent, double childAspectRatio, List<Widget> children, Unknown clipBehavior, Unknown controller, int crossAxisCount, double crossAxisSpacing, Unknown dragStartBehavior, Unknown key, Unknown keyboardDismissBehavior, double mainAxisSpacing, Unknown padding, Unknown physics, Unknown primary, Unknown restorationId, Unknown reverse, Unknown scrollDirection, int semanticChildCount, Unknown shrinkWrap);

    virtual void  extent(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown cacheExtent, double childAspectRatio, List<Widget> children, Unknown clipBehavior, Unknown controller, double crossAxisSpacing, Unknown dragStartBehavior, Unknown key, Unknown keyboardDismissBehavior, double mainAxisSpacing, double maxCrossAxisExtent, Unknown padding, Unknown physics, Unknown primary, Unknown restorationId, Unknown reverse, Unknown scrollDirection, int semanticChildCount, Unknown shrinkWrap);

    virtual Widget buildChildLayout(BuildContext context);

private:

};
using GridView = std::shared_ptr<GridViewCls>;


#endif