#ifndef SCROLL_VIEW_H
#define SCROLL_VIEW_H
#include <memory>

#include <math/math.hpp>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
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

class ScrollView : StatelessWidget {
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


     ScrollView(double anchor, double cacheExtent, Key center, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, Unknown, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, ScrollPhysics physics, bool primary, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection, int semanticChildCount, bool shrinkWrap);

    AxisDirection getDirection(BuildContext context);

    List<Widget> buildSlivers(BuildContext context);

    Widget buildViewport(AxisDirection axisDirection, BuildContext context, ViewportOffset offset, List<Widget> slivers);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class CustomScrollView : ScrollView {
public:
    List<Widget> slivers;


     CustomScrollView(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, List<Widget> slivers);

    List<Widget> buildSlivers(BuildContext context);

private:

};

class BoxScrollView : ScrollView {
public:
    EdgeInsetsGeometry padding;


     BoxScrollView(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, EdgeInsetsGeometry padding, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

    List<Widget> buildSlivers(BuildContext context);

    Widget buildChildLayout(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class ListView : BoxScrollView {
public:
    double itemExtent;

    Widget prototypeItem;

    SliverChildDelegate childrenDelegate;


     ListView(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown, List<Widget> children, Unknown, Unknown, Unknown, double itemExtent, Unknown, Unknown, Unknown, Unknown, Unknown, Widget prototypeItem, Unknown, Unknown, Unknown, int semanticChildCount, Unknown);

    void  builder(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown, Unknown, Unknown, Unknown, ChildIndexGetter findChildIndexCallback, IndexedWidgetBuilder itemBuilder, int itemCount, double itemExtent, Unknown, Unknown, Unknown, Unknown, Unknown, Widget prototypeItem, Unknown, Unknown, Unknown, int semanticChildCount, Unknown);

    void  separated(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown, Unknown, Unknown, Unknown, ChildIndexGetter findChildIndexCallback, IndexedWidgetBuilder itemBuilder, int itemCount, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, IndexedWidgetBuilder separatorBuilder, Unknown);

    void  custom(Unknown, SliverChildDelegate childrenDelegate, Unknown, Unknown, Unknown, double itemExtent, Unknown, Unknown, Unknown, Unknown, Unknown, Widget prototypeItem, Unknown, Unknown, Unknown, Unknown, Unknown);

    Widget buildChildLayout(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    static int _computeActualChildCount(int itemCount);

};

class GridView : BoxScrollView {
public:
    SliverGridDelegate gridDelegate;

    SliverChildDelegate childrenDelegate;


     GridView(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown, List<Widget> children, Unknown, Unknown, Unknown, SliverGridDelegate gridDelegate, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, int semanticChildCount, Unknown);

    void  builder(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown, Unknown, Unknown, Unknown, ChildIndexGetter findChildIndexCallback, SliverGridDelegate gridDelegate, IndexedWidgetBuilder itemBuilder, int itemCount, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, int semanticChildCount, Unknown);

    void  custom(Unknown, SliverChildDelegate childrenDelegate, Unknown, Unknown, Unknown, SliverGridDelegate gridDelegate, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

    void  count(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown, double childAspectRatio, List<Widget> children, Unknown, Unknown, int crossAxisCount, double crossAxisSpacing, Unknown, Unknown, Unknown, double mainAxisSpacing, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, int semanticChildCount, Unknown);

    void  extent(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown, double childAspectRatio, List<Widget> children, Unknown, Unknown, double crossAxisSpacing, Unknown, Unknown, Unknown, double mainAxisSpacing, double maxCrossAxisExtent, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, int semanticChildCount, Unknown);

    Widget buildChildLayout(BuildContext context);

private:

};

#endif