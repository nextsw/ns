#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ANIMATED_LIST
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ANIMATED_LIST
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "scroll_controller.hpp"
#include "scroll_physics.hpp"
#include "scroll_view.hpp"
#include "sliver.hpp"
#include "ticker_provider.hpp"

Duration _kDuration;


class _ActiveItemCls : public ObjectCls {
public:
    AnimationController controller;

    AnimatedListRemovedItemBuilder removedItemBuilder;

    int itemIndex;


    virtual void  incoming(Unknown controller, Unknown itemIndex);

    virtual void  outgoing(Unknown controller, Unknown itemIndex, Unknown removedItemBuilder);
    virtual void  index(Unknown itemIndex);

    virtual int compareTo(_ActiveItem other);

private:

};
using _ActiveItem = std::shared_ptr<_ActiveItemCls>;

class AnimatedListCls : public StatefulWidgetCls {
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


     AnimatedListCls(Clip clipBehavior, ScrollController controller, int initialItemCount, AnimatedListItemBuilder itemBuilder, Key key, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, bool reverse, Axis scrollDirection, bool shrinkWrap);

    static AnimatedListState of(BuildContext context);

    static AnimatedListState maybeOf(BuildContext context);

    virtual AnimatedListState createState();

private:

};
using AnimatedList = std::shared_ptr<AnimatedListCls>;

class AnimatedListStateCls : public StateCls<AnimatedList> {
public:

    virtual void insertItem(int index, Duration duration);

    virtual void removeItem(int index, AnimatedListRemovedItemBuilder builder, Duration duration);

    virtual Widget build(BuildContext context);

private:
    GlobalKey<SliverAnimatedListState> _sliverAnimatedListKey;


};
using AnimatedListState = std::shared_ptr<AnimatedListStateCls>;

class SliverAnimatedListCls : public StatefulWidgetCls {
public:
    AnimatedListItemBuilder itemBuilder;

    ChildIndexGetter findChildIndexCallback;

    int initialItemCount;


     SliverAnimatedListCls(ChildIndexGetter findChildIndexCallback, int initialItemCount, AnimatedListItemBuilder itemBuilder, Key key);

    virtual SliverAnimatedListState createState();

    static SliverAnimatedListState of(BuildContext context);

    static SliverAnimatedListState maybeOf(BuildContext context);

private:

};
using SliverAnimatedList = std::shared_ptr<SliverAnimatedListCls>;

class SliverAnimatedListStateCls : public StateCls<SliverAnimatedList> {
public:

    virtual void initState();

    virtual void dispose();

    virtual void insertItem(int index, Duration duration);

    virtual void removeItem(int index, AnimatedListRemovedItemBuilder builder, Duration duration);

    virtual Widget build(BuildContext context);

private:
    List<_ActiveItem> _incomingItems;

    List<_ActiveItem> _outgoingItems;

    int _itemsCount;


    virtual _ActiveItem _removeActiveItemAt(List<_ActiveItem> items, int itemIndex);

    virtual _ActiveItem _activeItemAt(List<_ActiveItem> items, int itemIndex);

    virtual int _indexToItemIndex(int index);

    virtual int _itemIndexToIndex(int itemIndex);

    virtual SliverChildDelegate _createDelegate();

    virtual Widget _itemBuilder(BuildContext context, int itemIndex);

};
using SliverAnimatedListState = std::shared_ptr<SliverAnimatedListStateCls>;


#endif