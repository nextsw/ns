#include "animated_list.hpp"
void _ActiveItem::incoming(AnimationController controller, int itemIndex)

void _ActiveItem::index(int itemIndex)

int _ActiveItem::compareTo(_ActiveItem other) {
    return itemIndex - other.itemIndex;
}

AnimatedList::AnimatedList(Clip clipBehavior, ScrollController controller, int initialItemCount, AnimatedListItemBuilder itemBuilder, Unknown, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, bool reverse, Axis scrollDirection, bool shrinkWrap) {
    {
        assert(itemBuilder != nullptr);
        assert(initialItemCount != nullptr && initialItemCount >= 0);
    }
}

AnimatedListState AnimatedList::of(BuildContext context) {
    assert(context != nullptr);
    AnimatedListState result = context.<AnimatedListState>findAncestorStateOfType();
    assert(());
    return result!;
}

AnimatedListState AnimatedList::maybeOf(BuildContext context) {
    assert(context != nullptr);
    return context.<AnimatedListState>findAncestorStateOfType();
}

AnimatedListState AnimatedList::createState() {
    return AnimatedListState();
}

void AnimatedListState::insertItem(Duration duration, int index) {
    _sliverAnimatedListKey.currentState!.insertItem(indexduration);
}

void AnimatedListState::removeItem(AnimatedListRemovedItemBuilder builder, Duration duration, int index) {
    _sliverAnimatedListKey.currentState!.removeItem(index, builderduration);
}

Widget AnimatedListState::build(BuildContext context) {
    return CustomScrollView(widget.scrollDirection, widget.reverse, widget.controller, widget.primary, widget.physics, widget.shrinkWrap, widget.clipBehavior, );
}

SliverAnimatedList::SliverAnimatedList(ChildIndexGetter findChildIndexCallback, int initialItemCount, AnimatedListItemBuilder itemBuilder, Unknown) {
    {
        assert(itemBuilder != nullptr);
        assert(initialItemCount != nullptr && initialItemCount >= 0);
    }
}

SliverAnimatedListState SliverAnimatedList::createState() {
    return SliverAnimatedListState();
}

SliverAnimatedListState SliverAnimatedList::of(BuildContext context) {
    assert(context != nullptr);
    SliverAnimatedListState result = context.<SliverAnimatedListState>findAncestorStateOfType();
    assert(());
    return result!;
}

SliverAnimatedListState SliverAnimatedList::maybeOf(BuildContext context) {
    assert(context != nullptr);
    return context.<SliverAnimatedListState>findAncestorStateOfType();
}

void SliverAnimatedListState::initState() {
    super.initState();
    _itemsCount = widget.initialItemCount;
}

void SliverAnimatedListState::dispose() {
    for (_ActiveItem item : _incomingItems.followedBy(_outgoingItems)) {
        item.controller!.dispose();
    }
    super.dispose();
}

void SliverAnimatedListState::insertItem(Duration duration, int index) {
    assert(index != nullptr && index >= 0);
    assert(duration != nullptr);
    int itemIndex = _indexToItemIndex(index);
    assert(itemIndex >= 0 && itemIndex <= _itemsCount);
    for (_ActiveItem item : _incomingItems) {
        if (item.itemIndex >= itemIndex) {
            item.itemIndex = 1;
        }
    }
    for (_ActiveItem item : _outgoingItems) {
        if (item.itemIndex >= itemIndex) {
            item.itemIndex = 1;
        }
    }
    AnimationController controller = AnimationController(duration, this);
    _ActiveItem incomingItem = _ActiveItem.incoming(controller, itemIndex);
    setState();
    controller.forward().<void>then();
}

void SliverAnimatedListState::removeItem(AnimatedListRemovedItemBuilder builder, Duration duration, int index) {
    assert(index != nullptr && index >= 0);
    assert(builder != nullptr);
    assert(duration != nullptr);
    int itemIndex = _indexToItemIndex(index);
    assert(itemIndex >= 0 &&  < _itemsCount);
    assert(_activeItemAt(_outgoingItems, itemIndex) == nullptr);
    _ActiveItem incomingItem = _removeActiveItemAt(_incomingItems, itemIndex);
    AnimationController controller = incomingItem?.controller ?? AnimationController(duration, 1.0, this);
    _ActiveItem outgoingItem = _ActiveItem.outgoing(controller, itemIndex, builder);
    setState();
    controller.reverse().<void>then();
}

Widget SliverAnimatedListState::build(BuildContext context) {
    return SliverList(_createDelegate());
}

_ActiveItem SliverAnimatedListState::_removeActiveItemAt(int itemIndex, List<_ActiveItem> items) {
    int i = binarySearch(items, _ActiveItem.index(itemIndex));
    return i == -1? nullptr : items.removeAt(i);
}

_ActiveItem SliverAnimatedListState::_activeItemAt(int itemIndex, List<_ActiveItem> items) {
    int i = binarySearch(items, _ActiveItem.index(itemIndex));
    return i == -1? nullptr : items[i];
}

int SliverAnimatedListState::_indexToItemIndex(int index) {
    int itemIndex = index;
    for (_ActiveItem item : _outgoingItems) {
        if (item.itemIndex <= itemIndex) {
            itemIndex = 1;
        } else {
                        break;
        }
    }
    return itemIndex;
}

int SliverAnimatedListState::_itemIndexToIndex(int itemIndex) {
    int index = itemIndex;
    for (_ActiveItem item : _outgoingItems) {
        assert(item.itemIndex != itemIndex);
        if (item.itemIndex < itemIndex) {
            index = 1;
        } else {
                        break;
        }
    }
    return index;
}

SliverChildDelegate SliverAnimatedListState::_createDelegate() {
    return SliverChildBuilderDelegate(_itemBuilder_itemsCount, widget.findChildIndexCallback);
}

Widget SliverAnimatedListState::_itemBuilder(BuildContext context, int itemIndex) {
    _ActiveItem outgoingItem = _activeItemAt(_outgoingItems, itemIndex);
    if (outgoingItem != nullptr) {
        return outgoingItem.removedItemBuilder!(context, outgoingItem.controller!.view);
    }
    _ActiveItem incomingItem = _activeItemAt(_incomingItems, itemIndex);
    Animation<double> animation = incomingItem?.controller?.view ?? kAlwaysCompleteAnimation;
    return widget.itemBuilder(context, _itemIndexToIndex(itemIndex), animation);
}
