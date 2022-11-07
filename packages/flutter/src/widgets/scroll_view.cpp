#include "scroll_view.hpp"
ScrollView::ScrollView(double anchor, double cacheExtent, Key center, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, Unknown, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, ScrollPhysics physics, bool primary, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection, int semanticChildCount, bool shrinkWrap) {
    {
        assert(scrollDirection != nullptr);
        assert(reverse != nullptr);
        assert(shrinkWrap != nullptr);
        assert(dragStartBehavior != nullptr);
        assert(clipBehavior != nullptr);
        assert(!(controller != nullptr && (primary ?? false)), "Primary ScrollViews obtain their ScrollController via inheritance from a PrimaryScrollController widget. You cannot both set primary to true and pass an explicit controller.");
        assert(!shrinkWrap || center == nullptr);
        assert(anchor != nullptr);
        assert(anchor >= 0.0 && anchor <= 1.0);
        assert(semanticChildCount == nullptr || semanticChildCount >= 0);
        physics = physics ?? ((primary ?? false) || (primary == nullptr && controller == nullptr && identical(scrollDirection, Axis.vertical))? const AlwaysScrollableScrollPhysics() : nullptr);
    }
}

AxisDirection ScrollView::getDirection(BuildContext context) {
    return getAxisDirectionFromAxisReverseAndDirectionality(context, scrollDirection, reverse);
}

Widget ScrollView::buildViewport(AxisDirection axisDirection, BuildContext context, ViewportOffset offset, List<Widget> slivers) {
    assert(());
    if (shrinkWrap) {
        return ShrinkWrappingViewport(axisDirection, offset, slivers, clipBehavior);
    }
    return Viewport(axisDirection, offset, slivers, cacheExtent, center, anchor, clipBehavior);
}

Widget ScrollView::build(BuildContext context) {
    List<Widget> slivers = buildSlivers(context);
    AxisDirection axisDirection = getDirection(context);
    bool effectivePrimary = primary ?? controller == nullptr && PrimaryScrollController.shouldInherit(context, scrollDirection);
    ScrollController scrollController = effectivePrimary? PrimaryScrollController.of(context) : controller;
    Scrollable scrollable = Scrollable(dragStartBehavior, axisDirection, scrollController, physics, scrollBehavior, semanticChildCount, restorationId, , clipBehavior);
    Widget scrollableResult = effectivePrimary && scrollController != nullptr? PrimaryScrollController.none(scrollable) : scrollable;
    if (keyboardDismissBehavior == ScrollViewKeyboardDismissBehavior.onDrag) {
        return <ScrollUpdateNotification>NotificationListener(scrollableResult, );
    } else {
        return scrollableResult;
    }
}

void ScrollView::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Axis>EnumProperty("scrollDirection", scrollDirection));
    properties.add(FlagProperty("reverse"reverse, "reversed", true));
    properties.add(<ScrollController>DiagnosticsProperty("controller", controllerfalse, nullptr));
    properties.add(FlagProperty("primary"primary, "using primary controller", true));
    properties.add(<ScrollPhysics>DiagnosticsProperty("physics", physicsfalse, nullptr));
    properties.add(FlagProperty("shrinkWrap"shrinkWrap, "shrink-wrapping", true));
}

List<Widget> CustomScrollView::buildSlivers(BuildContext context) {
    return slivers;
}

List<Widget> BoxScrollView::buildSlivers(BuildContext context) {
    Widget sliver = buildChildLayout(context);
    EdgeInsetsGeometry effectivePadding = padding;
    if (padding == nullptr) {
        MediaQueryData mediaQuery = MediaQuery.maybeOf(context);
        if (mediaQuery != nullptr) {
            EdgeInsets mediaQueryHorizontalPadding = mediaQuery.padding.copyWith(0.0, 0.0);
            EdgeInsets mediaQueryVerticalPadding = mediaQuery.padding.copyWith(0.0, 0.0);
            effectivePadding = scrollDirection == Axis.vertical? mediaQueryVerticalPadding : mediaQueryHorizontalPadding;
            sliver = MediaQuery(mediaQuery.copyWith(scrollDirection == Axis.vertical? mediaQueryHorizontalPadding : mediaQueryVerticalPadding), sliver);
        }
    }
    if (effectivePadding != nullptr) {
        sliver = SliverPadding(effectivePadding, sliver);
    }
    return ;
}

void BoxScrollView::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<EdgeInsetsGeometry>DiagnosticsProperty("padding", paddingnullptr));
}

ListView::ListView(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown, List<Widget> children, Unknown, Unknown, Unknown, double itemExtent, Unknown, Unknown, Unknown, Unknown, Unknown, Widget prototypeItem, Unknown, Unknown, Unknown, int semanticChildCount, Unknown) {
    {
        assert(itemExtent == nullptr || prototypeItem == nullptr, "You can only pass itemExtent or prototypeItem, not both.");
        childrenDelegate = SliverChildListDelegate(childrenaddAutomaticKeepAlives, addRepaintBoundaries, addSemanticIndexes);
        super(semanticChildCount ?? children.length);
    }
}

void ListView::builder(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown, Unknown, Unknown, Unknown, ChildIndexGetter findChildIndexCallback, IndexedWidgetBuilder itemBuilder, int itemCount, double itemExtent, Unknown, Unknown, Unknown, Unknown, Unknown, Widget prototypeItem, Unknown, Unknown, Unknown, int semanticChildCount, Unknown)

void ListView::separated(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown, Unknown, Unknown, Unknown, ChildIndexGetter findChildIndexCallback, IndexedWidgetBuilder itemBuilder, int itemCount, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, IndexedWidgetBuilder separatorBuilder, Unknown)

void ListView::custom(Unknown, SliverChildDelegate childrenDelegate, Unknown, Unknown, Unknown, double itemExtent, Unknown, Unknown, Unknown, Unknown, Unknown, Widget prototypeItem, Unknown, Unknown, Unknown, Unknown, Unknown)

Widget ListView::buildChildLayout(BuildContext context) {
    if (itemExtent != nullptr) {
        return SliverFixedExtentList(childrenDelegate, itemExtent!);
    } else     {
        if (prototypeItem != nullptr) {
        return SliverPrototypeExtentList(childrenDelegate, prototypeItem!);
    }
;
    }    return SliverList(childrenDelegate);
}

void ListView::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("itemExtent", itemExtentnullptr));
}

int ListView::_computeActualChildCount(int itemCount) {
    return math.max(0, itemCount * 2 - 1);
}

GridView::GridView(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown, List<Widget> children, Unknown, Unknown, Unknown, SliverGridDelegate gridDelegate, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, int semanticChildCount, Unknown) {
    {
        assert(gridDelegate != nullptr);
        childrenDelegate = SliverChildListDelegate(childrenaddAutomaticKeepAlives, addRepaintBoundaries, addSemanticIndexes);
        super(semanticChildCount ?? children.length);
    }
}

void GridView::builder(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown, Unknown, Unknown, Unknown, ChildIndexGetter findChildIndexCallback, SliverGridDelegate gridDelegate, IndexedWidgetBuilder itemBuilder, int itemCount, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, int semanticChildCount, Unknown)

void GridView::custom(Unknown, SliverChildDelegate childrenDelegate, Unknown, Unknown, Unknown, SliverGridDelegate gridDelegate, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown)

void GridView::count(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown, double childAspectRatio, List<Widget> children, Unknown, Unknown, int crossAxisCount, double crossAxisSpacing, Unknown, Unknown, Unknown, double mainAxisSpacing, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, int semanticChildCount, Unknown)

void GridView::extent(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, Unknown, double childAspectRatio, List<Widget> children, Unknown, Unknown, double crossAxisSpacing, Unknown, Unknown, Unknown, double mainAxisSpacing, double maxCrossAxisExtent, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, int semanticChildCount, Unknown)

Widget GridView::buildChildLayout(BuildContext context) {
    return SliverGrid(childrenDelegate, gridDelegate);
}
