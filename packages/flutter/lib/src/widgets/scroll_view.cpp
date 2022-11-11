#include "scroll_view.hpp"
ScrollViewCls::ScrollViewCls(double anchor, double cacheExtent, Key center, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, Key key, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, ScrollPhysics physics, bool primary, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection, int semanticChildCount, bool shrinkWrap) {
    {
        assert(scrollDirection != nullptr);
        assert(reverse != nullptr);
        assert(shrinkWrap != nullptr);
        assert(dragStartBehavior != nullptr);
        assert(clipBehavior != nullptr);
        assert(!(controller != nullptr && (primary | false)), __s("Primary ScrollViews obtain their ScrollController via inheritance from a PrimaryScrollController widget. You cannot both set primary to true and pass an explicit controller."));
        assert(!shrinkWrap || center == nullptr);
        assert(anchor != nullptr);
        assert(anchor >= 0.0 && anchor <= 1.0);
        assert(semanticChildCount == nullptr || semanticChildCount >= 0);
        physics = physics | ((primary | false) || (primary == nullptr && controller == nullptr && identical(scrollDirection, AxisCls::vertical))? make<AlwaysScrollableScrollPhysicsCls>() : nullptr);
    }
}

AxisDirection ScrollViewCls::getDirection(BuildContext context) {
    return getAxisDirectionFromAxisReverseAndDirectionality(context, scrollDirection, reverse);
}

Widget ScrollViewCls::buildViewport(BuildContext context, ViewportOffset offset, AxisDirection axisDirection, List<Widget> slivers) {
    assert([=] () {
        ;
    }());
    if (shrinkWrap) {
        return make<ShrinkWrappingViewportCls>(axisDirection, offset, slivers, clipBehavior);
    }
    return make<ViewportCls>(axisDirection, offset, slivers, cacheExtent, center, anchor, clipBehavior);
}

Widget ScrollViewCls::build(BuildContext context) {
    List<Widget> slivers = buildSlivers(context);
    AxisDirection axisDirection = getDirection(context);
    bool effectivePrimary = primary | controller == nullptr && PrimaryScrollControllerCls->shouldInherit(context, scrollDirection);
    ScrollController scrollController = effectivePrimary? PrimaryScrollControllerCls->of(context) : controller;
    Scrollable scrollable = make<ScrollableCls>(dragStartBehavior, axisDirection, scrollController, physics, scrollBehavior, semanticChildCount, restorationId, [=] (BuildContext context,ViewportOffset offset) {
    return buildViewport(context, offset, axisDirection, slivers);
}, clipBehavior);
    Widget scrollableResult = effectivePrimary && scrollController != nullptr? PrimaryScrollControllerCls->none(scrollable) : scrollable;
    if (keyboardDismissBehavior == ScrollViewKeyboardDismissBehaviorCls::onDrag) {
        return <ScrollUpdateNotification>make<NotificationListenerCls>(scrollableResult, [=] (ScrollUpdateNotification notification) {
            FocusScopeNode focusScope = FocusScopeCls->of(context);
            if (notification->dragDetails != nullptr && focusScope->hasFocus()) {
                focusScope->unfocus();
            }
            return false;
        });
    } else {
        return scrollableResult;
    }
}

void ScrollViewCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Axis>make<EnumPropertyCls>(__s("scrollDirection"), scrollDirection));
    properties->add(make<FlagPropertyCls>(__s("reverse"), reverse, __s("reversed"), true));
    properties->add(<ScrollController>make<DiagnosticsPropertyCls>(__s("controller"), controller, false, nullptr));
    properties->add(make<FlagPropertyCls>(__s("primary"), primary, __s("using primary controller"), true));
    properties->add(<ScrollPhysics>make<DiagnosticsPropertyCls>(__s("physics"), physics, false, nullptr));
    properties->add(make<FlagPropertyCls>(__s("shrinkWrap"), shrinkWrap, __s("shrink-wrapping"), true));
}

List<Widget> CustomScrollViewCls::buildSlivers(BuildContext context) {
    return slivers;
}

List<Widget> BoxScrollViewCls::buildSlivers(BuildContext context) {
    Widget sliver = buildChildLayout(context);
    EdgeInsetsGeometry effectivePadding = padding;
    if (padding == nullptr) {
        MediaQueryData mediaQuery = MediaQueryCls->maybeOf(context);
        if (mediaQuery != nullptr) {
            EdgeInsets mediaQueryHorizontalPadding = mediaQuery->padding->copyWith(0.0, 0.0);
            EdgeInsets mediaQueryVerticalPadding = mediaQuery->padding->copyWith(0.0, 0.0);
            effectivePadding = scrollDirection == AxisCls::vertical? mediaQueryVerticalPadding : mediaQueryHorizontalPadding;
            sliver = make<MediaQueryCls>(mediaQuery->copyWith(scrollDirection == AxisCls::vertical? mediaQueryHorizontalPadding : mediaQueryVerticalPadding), sliver);
        }
    }
    if (effectivePadding != nullptr) {
        sliver = make<SliverPaddingCls>(effectivePadding, sliver);
    }
    return makeList(ArrayItem);
}

void BoxScrollViewCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<EdgeInsetsGeometry>make<DiagnosticsPropertyCls>(__s("padding"), padding, nullptr));
}

ListViewCls::ListViewCls(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, double cacheExtent, List<Widget> children, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, double itemExtent, Key key, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, Widget prototypeItem, String restorationId, bool reverse, Axis scrollDirection, int semanticChildCount, bool shrinkWrap) : BoxScrollView(semanticChildCount | children->length()) {
    {
        assert(itemExtent == nullptr || prototypeItem == nullptr, __s("You can only pass itemExtent or prototypeItem, not both."));
        childrenDelegate = make<SliverChildListDelegateCls>(children, addAutomaticKeepAlives, addRepaintBoundaries, addSemanticIndexes);
    }
}

void ListViewCls::builder(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, double cacheExtent, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, ChildIndexGetter findChildIndexCallback, IndexedWidgetBuilder itemBuilder, int itemCount, double itemExtent, Key key, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, Widget prototypeItem, String restorationId, bool reverse, Axis scrollDirection, int semanticChildCount, bool shrinkWrap)

void ListViewCls::separated(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, double cacheExtent, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, ChildIndexGetter findChildIndexCallback, IndexedWidgetBuilder itemBuilder, int itemCount, Key key, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, String restorationId, bool reverse, Axis scrollDirection, IndexedWidgetBuilder separatorBuilder, bool shrinkWrap)

void ListViewCls::custom(double cacheExtent, SliverChildDelegate childrenDelegate, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, double itemExtent, Key key, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, Widget prototypeItem, String restorationId, bool reverse, Axis scrollDirection, int semanticChildCount, bool shrinkWrap)

Widget ListViewCls::buildChildLayout(BuildContext context) {
    if (itemExtent != nullptr) {
        return make<SliverFixedExtentListCls>(childrenDelegate, itemExtent!);
    } else {
        if (prototypeItem != nullptr) {
        return make<SliverPrototypeExtentListCls>(childrenDelegate, prototypeItem!);
    }
;
    }    return make<SliverListCls>(childrenDelegate);
}

void ListViewCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("itemExtent"), itemExtent, nullptr));
}

int ListViewCls::_computeActualChildCount(int itemCount) {
    return math->max(0, itemCount * 2 - 1);
}

GridViewCls::GridViewCls(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, double cacheExtent, List<Widget> children, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, SliverGridDelegate gridDelegate, Key key, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, String restorationId, bool reverse, Axis scrollDirection, int semanticChildCount, bool shrinkWrap) : BoxScrollView(semanticChildCount | children->length()) {
    {
        assert(gridDelegate != nullptr);
        childrenDelegate = make<SliverChildListDelegateCls>(children, addAutomaticKeepAlives, addRepaintBoundaries, addSemanticIndexes);
    }
}

void GridViewCls::builder(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, double cacheExtent, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, ChildIndexGetter findChildIndexCallback, SliverGridDelegate gridDelegate, IndexedWidgetBuilder itemBuilder, int itemCount, Key key, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, String restorationId, bool reverse, Axis scrollDirection, int semanticChildCount, bool shrinkWrap)

void GridViewCls::custom(double cacheExtent, SliverChildDelegate childrenDelegate, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, SliverGridDelegate gridDelegate, Key key, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, String restorationId, bool reverse, Axis scrollDirection, int semanticChildCount, bool shrinkWrap)

void GridViewCls::count(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, double cacheExtent, double childAspectRatio, List<Widget> children, Clip clipBehavior, ScrollController controller, int crossAxisCount, double crossAxisSpacing, DragStartBehavior dragStartBehavior, Key key, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, double mainAxisSpacing, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, String restorationId, bool reverse, Axis scrollDirection, int semanticChildCount, bool shrinkWrap)

void GridViewCls::extent(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, double cacheExtent, double childAspectRatio, List<Widget> children, Clip clipBehavior, ScrollController controller, double crossAxisSpacing, DragStartBehavior dragStartBehavior, Key key, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, double mainAxisSpacing, double maxCrossAxisExtent, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, String restorationId, bool reverse, Axis scrollDirection, int semanticChildCount, bool shrinkWrap)

Widget GridViewCls::buildChildLayout(BuildContext context) {
    return make<SliverGridCls>(childrenDelegate, gridDelegate);
}
