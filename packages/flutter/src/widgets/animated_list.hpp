#ifndef ANIMATED_LIST_H
#define ANIMATED_LIST_H
#include <memory>

#include <flutter/foundation.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "scroll_controller.hpp"
#include "scroll_physics.hpp"
#include "scroll_view.hpp"
#include "sliver.hpp"
#include "ticker_provider.hpp"


const Duration _kDuration;


class _ActiveItem {
public:
    AnimationController controller;

    AnimatedListRemovedItemBuilder removedItemBuilder;

    int itemIndex;


    void  incoming(AnimationController controller, int itemIndex);

    void  outgoing(AnimationController controller, int itemIndex, AnimatedListRemovedItemBuilder removedItemBuilder);

    void  index(int itemIndex);

    int compareTo(_ActiveItem other);

private:

};

class AnimatedList : StatefulWidget {
public:
    AnimatedListItemBuilder itemBuilder;

    int initialItemCount;

    Axis scrollDirection;

    bool reverse;

    ScrollController controller;

    bool primary;

    ScrollPhysics physics;

    bool shrinkWrap;

    EdgeInsetsGeometry padding;

    Clip clipBehavior;


     AnimatedList(Clip clipBehavior, ScrollController controller, int initialItemCount, AnimatedListItemBuilder itemBuilder, Unknown, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, bool reverse, Axis scrollDirection, bool shrinkWrap);

    static AnimatedListState of(BuildContext context);

    static AnimatedListState maybeOf(BuildContext context);

    AnimatedListState createState();

private:

};

class AnimatedListState : State<AnimatedList> {
public:

    void insertItem(Duration duration, int index);

    void removeItem(AnimatedListRemovedItemBuilder builder, Duration duration, int index);

    Widget build(BuildContext context);

private:
    GlobalKey<SliverAnimatedListState> _sliverAnimatedListKey;


};

class SliverAnimatedList : StatefulWidget {
public:
    AnimatedListItemBuilder itemBuilder;

    ChildIndexGetter findChildIndexCallback;

    int initialItemCount;


     SliverAnimatedList(ChildIndexGetter findChildIndexCallback, int initialItemCount, AnimatedListItemBuilder itemBuilder, Unknown);

    SliverAnimatedListState createState();

    static SliverAnimatedListState of(BuildContext context);

    static SliverAnimatedListState maybeOf(BuildContext context);

private:

};

class SliverAnimatedListState : State<SliverAnimatedList> {
public:

    void initState();

    void dispose();

    void insertItem(Duration duration, int index);

    void removeItem(AnimatedListRemovedItemBuilder builder, Duration duration, int index);

    Widget build(BuildContext context);

private:
    List<_ActiveItem> _incomingItems;

    List<_ActiveItem> _outgoingItems;

    int _itemsCount;


    _ActiveItem _removeActiveItemAt(int itemIndex, List<_ActiveItem> items);

    _ActiveItem _activeItemAt(int itemIndex, List<_ActiveItem> items);

    int _indexToItemIndex(int index);

    int _itemIndexToIndex(int itemIndex);

    SliverChildDelegate _createDelegate();

    Widget _itemBuilder(BuildContext context, int itemIndex);

};

#endif