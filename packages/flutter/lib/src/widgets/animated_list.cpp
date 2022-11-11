#include "animated_list.hpp"
void _ActiveItemCls::incoming(AnimationController controller, int itemIndex)

void _ActiveItemCls::index(int itemIndex)

int _ActiveItemCls::compareTo(_ActiveItem other) {
    return itemIndex - other->itemIndex;
}

AnimatedListCls::AnimatedListCls(Clip clipBehavior, ScrollController controller, int initialItemCount, AnimatedListItemBuilder itemBuilder, Unknown key, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, bool reverse, Axis scrollDirection, bool shrinkWrap) {
    {
        assert(itemBuilder != nullptr);
        assert(initialItemCount != nullptr && initialItemCount >= 0);
    }
}

AnimatedListState AnimatedListCls::of(BuildContext context) {
    assert(context != nullptr);
    AnimatedListState result = context-><AnimatedListState>findAncestorStateOfType();
    assert([=] () {
        if (result == nullptr) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));
        }
        return true;
    }());
    return result!;
}

AnimatedListState AnimatedListCls::maybeOf(BuildContext context) {
    assert(context != nullptr);
    return context-><AnimatedListState>findAncestorStateOfType();
}

AnimatedListState AnimatedListCls::createState() {
    return make<AnimatedListStateCls>();
}

void AnimatedListStateCls::insertItem(int index, Duration duration) {
    _sliverAnimatedListKey->currentState()!->insertItem(indexduration);
}

void AnimatedListStateCls::removeItem(int index, AnimatedListRemovedItemBuilder builder, Duration duration) {
    _sliverAnimatedListKey->currentState()!->removeItem(index, builderduration);
}

Widget AnimatedListStateCls::build(BuildContext context) {
    return make<CustomScrollViewCls>(widget->scrollDirection, widget->reverse, widget->controller, widget->primary, widget->physics, widget->shrinkWrap, widget->clipBehavior, makeList(ArrayItem));
}

SliverAnimatedListCls::SliverAnimatedListCls(ChildIndexGetter findChildIndexCallback, int initialItemCount, AnimatedListItemBuilder itemBuilder, Unknown key) {
    {
        assert(itemBuilder != nullptr);
        assert(initialItemCount != nullptr && initialItemCount >= 0);
    }
}

SliverAnimatedListState SliverAnimatedListCls::createState() {
    return make<SliverAnimatedListStateCls>();
}

SliverAnimatedListState SliverAnimatedListCls::of(BuildContext context) {
    assert(context != nullptr);
    SliverAnimatedListState result = context-><SliverAnimatedListState>findAncestorStateOfType();
    assert([=] () {
        if (result == nullptr) {
            throw make<FlutterErrorCls>(__s("SliverAnimatedList.of() called with a context that does not contain a SliverAnimatedList.\nNo SliverAnimatedListState ancestor could be found starting from the context that was passed to SliverAnimatedListState.of(). This can happen when the context provided is from the same StatefulWidget that built the AnimatedList. Please see the SliverAnimatedList documentation for examples of how to refer to an AnimatedListState object: https://api.flutter.dev/flutter/widgets/SliverAnimatedListState-class.html\nThe context used was:\n  $context"));
        }
        return true;
    }());
    return result!;
}

SliverAnimatedListState SliverAnimatedListCls::maybeOf(BuildContext context) {
    assert(context != nullptr);
    return context-><SliverAnimatedListState>findAncestorStateOfType();
}

void SliverAnimatedListStateCls::initState() {
    super->initState();
    _itemsCount = widget->initialItemCount;
}

void SliverAnimatedListStateCls::dispose() {
    for (_ActiveItem item : _incomingItems->followedBy(_outgoingItems)) {
        item->controller!->dispose();
    }
    super->dispose();
}

void SliverAnimatedListStateCls::insertItem(int index, Duration duration) {
    assert(index != nullptr && index >= 0);
    assert(duration != nullptr);
    int itemIndex = _indexToItemIndex(index);
    assert(itemIndex >= 0 && itemIndex <= _itemsCount);
    for (_ActiveItem item : _incomingItems) {
        if (item->itemIndex >= itemIndex) {
            item->itemIndex += 1;
        }
    }
    for (_ActiveItem item : _outgoingItems) {
        if (item->itemIndex >= itemIndex) {
            item->itemIndex += 1;
        }
    }
    AnimationController controller = make<AnimationControllerCls>(duration, this);
    _ActiveItem incomingItem = _ActiveItemCls->incoming(controller, itemIndex);
    setState([=] () {
            auto _c1 = _incomingItems;    _c1.auto _c2 = add(incomingItem);    _c2.sort();    _c2;_c1;
        _itemsCount += 1;
    });
    controller->forward()-><void>then([=] () {
        _removeActiveItemAt(_incomingItems, incomingItem->itemIndex)!->controller!->dispose();
    });
}

void SliverAnimatedListStateCls::removeItem(int index, AnimatedListRemovedItemBuilder builder, Duration duration) {
    assert(index != nullptr && index >= 0);
    assert(builder != nullptr);
    assert(duration != nullptr);
    int itemIndex = _indexToItemIndex(index);
    assert(itemIndex >= 0 &&  < _itemsCount);
    assert(_activeItemAt(_outgoingItems, itemIndex) == nullptr);
    _ActiveItem incomingItem = _removeActiveItemAt(_incomingItems, itemIndex);
    AnimationController controller = incomingItem?->controller | make<AnimationControllerCls>(duration, 1.0, this);
    _ActiveItem outgoingItem = _ActiveItemCls->outgoing(controller, itemIndex, builder);
    setState([=] () {
            auto _c1 = _outgoingItems;    _c1.auto _c2 = add(outgoingItem);    _c2.sort();    _c2;_c1;
    });
    controller->reverse()-><void>then([=] (void value) {
        _removeActiveItemAt(_outgoingItems, outgoingItem->itemIndex)!->controller!->dispose();
        for (_ActiveItem item : _incomingItems) {
            if (item->itemIndex > outgoingItem->itemIndex) {
                item->itemIndex -= 1;
            }
        }
        for (_ActiveItem item : _outgoingItems) {
            if (item->itemIndex > outgoingItem->itemIndex) {
                item->itemIndex -= 1;
            }
        }
        setState([=] ()         {
            _itemsCount -= 1;
        });
    });
}

Widget SliverAnimatedListStateCls::build(BuildContext context) {
    return make<SliverListCls>(_createDelegate());
}

_ActiveItem SliverAnimatedListStateCls::_removeActiveItemAt(List<_ActiveItem> items, int itemIndex) {
    int i = binarySearch(items, _ActiveItemCls->index(itemIndex));
    return i == -1? nullptr : items->removeAt(i);
}

_ActiveItem SliverAnimatedListStateCls::_activeItemAt(List<_ActiveItem> items, int itemIndex) {
    int i = binarySearch(items, _ActiveItemCls->index(itemIndex));
    return i == -1? nullptr : items[i];
}

int SliverAnimatedListStateCls::_indexToItemIndex(int index) {
    int itemIndex = index;
    for (_ActiveItem item : _outgoingItems) {
        if (item->itemIndex <= itemIndex) {
            itemIndex += 1;
        } else {
            break;
        }
    }
    return itemIndex;
}

int SliverAnimatedListStateCls::_itemIndexToIndex(int itemIndex) {
    int index = itemIndex;
    for (_ActiveItem item : _outgoingItems) {
        assert(item->itemIndex != itemIndex);
        if (item->itemIndex < itemIndex) {
            index -= 1;
        } else {
            break;
        }
    }
    return index;
}

SliverChildDelegate SliverAnimatedListStateCls::_createDelegate() {
    return make<SliverChildBuilderDelegateCls>(_itemBuilder_itemsCount, widget->findChildIndexCallback);
}

Widget SliverAnimatedListStateCls::_itemBuilder(BuildContext context, int itemIndex) {
    _ActiveItem outgoingItem = _activeItemAt(_outgoingItems, itemIndex);
    if (outgoingItem != nullptr) {
        return outgoingItem->removedItemBuilder!(context, outgoingItem->controller!->view());
    }
    _ActiveItem incomingItem = _activeItemAt(_incomingItems, itemIndex);
    Animation<double> animation = incomingItem?->controller?->view() | kAlwaysCompleteAnimation;
    return widget->itemBuilder(context, _itemIndexToIndex(itemIndex), animation);
}
