#include "scroll_view.hpp"
ScrollViewCls::ScrollViewCls(double anchor, double cacheExtent, Key center, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, Unknown key, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, ScrollPhysics physics, bool primary, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection, int semanticChildCount, bool shrinkWrap) {
    {
        assert(scrollDirection != nullptr);
        assert(reverse != nullptr);
        assert(shrinkWrap != nullptr);
        assert(dragStartBehavior != nullptr);
        assert(clipBehavior != nullptr);
        assert(!(controller != nullptr && (primary or false)), __s("Primary ScrollViews obtain their ScrollController via inheritance from a PrimaryScrollController widget. You cannot both set primary to true and pass an explicit controller."));
        assert(!shrinkWrap || center == nullptr);
        assert(anchor != nullptr);
        assert(anchor >= 0.0 && anchor <= 1.0);
        assert(semanticChildCount == nullptr || semanticChildCount >= 0);
        physics = physics or ((primary or false) || (primary == nullptr && controller == nullptr && identical(scrollDirection, AxisCls::vertical))? make<AlwaysScrollableScrollPhysicsCls>() : nullptr);
    }
}

AxisDirection ScrollViewCls::getDirection(BuildContext context) {
    return getAxisDirectionFromAxisReverseAndDirectionality(context, scrollDirection, reverse);
}

Widget ScrollViewCls::buildViewport(AxisDirection axisDirection, BuildContext context, ViewportOffset offset, List<Widget> slivers) {
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
    bool effectivePrimary = primary or controller == nullptr && PrimaryScrollControllerCls->shouldInherit(context, scrollDirection);
    ScrollController scrollController = effectivePrimary? PrimaryScrollControllerCls->of(context) : controller;
    Scrollable scrollable = make<ScrollableCls>(dragStartBehavior, axisDirection, scrollController, physics, scrollBehavior, semanticChildCount, restorationId, [=] (BuildContext context,ViewportOffset offset) {
    return buildViewport(context, offset, axisDirection, slivers);
}, clipBehavior);
    Widget scrollableResult = effectivePrimary && scrollController != nullptr? PrimaryScrollControllerCls->none(scrollable) : scrollable;
    if (keyboardDismissBehavior == ScrollViewKeyboardDismissBehaviorCls::onDrag) {
        return <ScrollUpdateNotification>make<NotificationListenerCls>(scrollableResult, [=] (ScrollUpdateNotification notification) {
            FocusScopeNode focusScope = FocusScopeCls->of(context);
            if (notification->dragDetails != nullptr && focusScope->hasFocus) {
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
    properties->add(make<FlagPropertyCls>(__s("reverse")reverse, __s("reversed"), true));
    properties->add(<ScrollController>make<DiagnosticsPropertyCls>(__s("controller"), controllerfalse, nullptr));
    properties->add(make<FlagPropertyCls>(__s("primary")primary, __s("using primary controller"), true));
    properties->add(<ScrollPhysics>make<DiagnosticsPropertyCls>(__s("physics"), physicsfalse, nullptr));
    properties->add(make<FlagPropertyCls>(__s("shrinkWrap")shrinkWrap, __s("shrink-wrapping"), true));
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
    properties->add(<EdgeInsetsGeometry>make<DiagnosticsPropertyCls>(__s("padding"), paddingnullptr));
}

ListViewCls::ListViewCls(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown cacheExtent, List<Widget> children, Unknown clipBehavior, Unknown controller, Unknown dragStartBehavior, double itemExtent, Unknown key, Unknown keyboardDismissBehavior, Unknown padding, Unknown physics, Unknown primary, Widget prototypeItem, Unknown restorationId, Unknown reverse, Unknown scrollDirection, int semanticChildCount, Unknown shrinkWrap) : BoxScrollView(semanticChildCount or children->length) {
    {
        assert(itemExtent == nullptr || prototypeItem == nullptr, __s("You can only pass itemExtent or prototypeItem, not both."));
        childrenDelegate = make<SliverChildListDelegateCls>(childrenaddAutomaticKeepAlives, addRepaintBoundaries, addSemanticIndexes);
    }
}

void ListViewCls::builder(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown cacheExtent, Unknown clipBehavior, Unknown controller, Unknown dragStartBehavior, ChildIndexGetter findChildIndexCallback, IndexedWidgetBuilder itemBuilder, int itemCount, double itemExtent, Unknown key, Unknown keyboardDismissBehavior, Unknown padding, Unknown physics, Unknown primary, Widget prototypeItem, Unknown restorationId, Unknown reverse, Unknown scrollDirection, int semanticChildCount, Unknown shrinkWrap)

void ListViewCls::separated(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown cacheExtent, Unknown clipBehavior, Unknown controller, Unknown dragStartBehavior, ChildIndexGetter findChildIndexCallback, IndexedWidgetBuilder itemBuilder, int itemCount, Unknown key, Unknown keyboardDismissBehavior, Unknown padding, Unknown physics, Unknown primary, Unknown restorationId, Unknown reverse, Unknown scrollDirection, IndexedWidgetBuilder separatorBuilder, Unknown shrinkWrap)

void ListViewCls::custom(Unknown cacheExtent, SliverChildDelegate childrenDelegate, Unknown clipBehavior, Unknown controller, Unknown dragStartBehavior, double itemExtent, Unknown key, Unknown keyboardDismissBehavior, Unknown padding, Unknown physics, Unknown primary, Widget prototypeItem, Unknown restorationId, Unknown reverse, Unknown scrollDirection, Unknown semanticChildCount, Unknown shrinkWrap)

Widget ListViewCls::buildChildLayout(BuildContext context) {
    if (itemExtent != nullptr) {
        return make<SliverFixedExtentListCls>(childrenDelegate, itemExtent!);
    } else     {
        if (prototypeItem != nullptr) {
        return make<SliverPrototypeExtentListCls>(childrenDelegate, prototypeItem!);
    }
;
    }    return make<SliverListCls>(childrenDelegate);
}

void ListViewCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("itemExtent"), itemExtentnullptr));
}

int ListViewCls::_computeActualChildCount(int itemCount) {
    return math->max(0, itemCount * 2 - 1);
}

GridViewCls::GridViewCls(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown cacheExtent, List<Widget> children, Unknown clipBehavior, Unknown controller, Unknown dragStartBehavior, SliverGridDelegate gridDelegate, Unknown key, Unknown keyboardDismissBehavior, Unknown padding, Unknown physics, Unknown primary, Unknown restorationId, Unknown reverse, Unknown scrollDirection, int semanticChildCount, Unknown shrinkWrap) : BoxScrollView(semanticChildCount or children->length) {
    {
        assert(gridDelegate != nullptr);
        childrenDelegate = make<SliverChildListDelegateCls>(childrenaddAutomaticKeepAlives, addRepaintBoundaries, addSemanticIndexes);
    }
}

void GridViewCls::builder(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown cacheExtent, Unknown clipBehavior, Unknown controller, Unknown dragStartBehavior, ChildIndexGetter findChildIndexCallback, SliverGridDelegate gridDelegate, IndexedWidgetBuilder itemBuilder, int itemCount, Unknown key, Unknown keyboardDismissBehavior, Unknown padding, Unknown physics, Unknown primary, Unknown restorationId, Unknown reverse, Unknown scrollDirection, int semanticChildCount, Unknown shrinkWrap)

void GridViewCls::custom(Unknown cacheExtent, SliverChildDelegate childrenDelegate, Unknown clipBehavior, Unknown controller, Unknown dragStartBehavior, SliverGridDelegate gridDelegate, Unknown key, Unknown keyboardDismissBehavior, Unknown padding, Unknown physics, Unknown primary, Unknown restorationId, Unknown reverse, Unknown scrollDirection, Unknown semanticChildCount, Unknown shrinkWrap)

void GridViewCls::count(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown cacheExtent, double childAspectRatio, List<Widget> children, Unknown clipBehavior, Unknown controller, int crossAxisCount, double crossAxisSpacing, Unknown dragStartBehavior, Unknown key, Unknown keyboardDismissBehavior, double mainAxisSpacing, Unknown padding, Unknown physics, Unknown primary, Unknown restorationId, Unknown reverse, Unknown scrollDirection, int semanticChildCount, Unknown shrinkWrap)

void GridViewCls::extent(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown cacheExtent, double childAspectRatio, List<Widget> children, Unknown clipBehavior, Unknown controller, double crossAxisSpacing, Unknown dragStartBehavior, Unknown key, Unknown keyboardDismissBehavior, double mainAxisSpacing, double maxCrossAxisExtent, Unknown padding, Unknown physics, Unknown primary, Unknown restorationId, Unknown reverse, Unknown scrollDirection, int semanticChildCount, Unknown shrinkWrap)

Widget GridViewCls::buildChildLayout(BuildContext context) {
    return make<SliverGridCls>(childrenDelegate, gridDelegate);
}
