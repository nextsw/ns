#include "reorderable_list.hpp"
ReorderableList::ReorderableList(double anchor, double cacheExtent, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, IndexedWidgetBuilder itemBuilder, int itemCount, double itemExtent, Unknown, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, ReorderCallback onReorder, FunctionType onReorderEnd, FunctionType onReorderStart, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, Widget prototypeItem, ReorderItemProxyDecorator proxyDecorator, String restorationId, bool reverse, Axis scrollDirection, bool shrinkWrap) {
    {
        assert(itemCount >= 0);
        assert(itemExtent == nullptr || prototypeItem == nullptr, "You can only pass itemExtent or prototypeItem, not both");
    }
}

ReorderableListState ReorderableList::of(BuildContext context) {
    assert(context != nullptr);
    ReorderableListState result = context.<ReorderableListState>findAncestorStateOfType();
    assert(());
    return result!;
}

ReorderableListState ReorderableList::maybeOf(BuildContext context) {
    assert(context != nullptr);
    return context.<ReorderableListState>findAncestorStateOfType();
}

ReorderableListState ReorderableList::createState() {
    return ReorderableListState();
}

void ReorderableListState::startItemDragReorder(PointerDownEvent event, int index, MultiDragGestureRecognizer recognizer) {
    _sliverReorderableListKey.currentState!.startItemDragReorder(index, event, recognizer);
}

void ReorderableListState::cancelReorder() {
    _sliverReorderableListKey.currentState!.cancelReorder();
}

Widget ReorderableListState::build(BuildContext context) {
    return CustomScrollView(widget.scrollDirection, widget.reverse, widget.controller, widget.primary, widget.physics, widget.shrinkWrap, widget.anchor, widget.cacheExtent, widget.dragStartBehavior, widget.keyboardDismissBehavior, widget.restorationId, widget.clipBehavior, );
}

SliverReorderableList::SliverReorderableList(ChildIndexGetter findChildIndexCallback, IndexedWidgetBuilder itemBuilder, int itemCount, double itemExtent, Unknown, ReorderCallback onReorder, FunctionType onReorderEnd, FunctionType onReorderStart, Widget prototypeItem, ReorderItemProxyDecorator proxyDecorator) {
    {
        assert(itemCount >= 0);
        assert(itemExtent == nullptr || prototypeItem == nullptr, "You can only pass itemExtent or prototypeItem, not both");
    }
}

SliverReorderableListState SliverReorderableList::createState() {
    return SliverReorderableListState();
}

SliverReorderableListState SliverReorderableList::of(BuildContext context) {
    assert(context != nullptr);
    SliverReorderableListState result = context.<SliverReorderableListState>findAncestorStateOfType();
    assert(());
    return result!;
}

SliverReorderableListState SliverReorderableList::maybeOf(BuildContext context) {
    assert(context != nullptr);
    return context.<SliverReorderableListState>findAncestorStateOfType();
}

void SliverReorderableListState::didChangeDependencies() {
    super.didChangeDependencies();
    _scrollable = Scrollable.of(context)!;
    if (_autoScroller?.scrollable != _scrollable) {
        _autoScroller?.stopAutoScroll();
        _autoScroller = EdgeDraggingAutoScroller(_scrollable_handleScrollableAutoScrolled);
    }
}

void SliverReorderableListState::didUpdateWidget(SliverReorderableList oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (widget.itemCount != oldWidget.itemCount) {
        cancelReorder();
    }
}

void SliverReorderableListState::dispose() {
    _dragReset();
    super.dispose();
}

void SliverReorderableListState::startItemDragReorder(PointerDownEvent event, int index, MultiDragGestureRecognizer recognizer) {
    assert(0 <= index &&  < widget.itemCount);
    setState();
}

void SliverReorderableListState::cancelReorder() {
    setState();
}

Widget SliverReorderableListState::build(BuildContext context) {
    assert(debugCheckHasOverlay(context));
    SliverChildBuilderDelegate childrenDelegate = SliverChildBuilderDelegate(_itemBuilderwidget.itemCount + (_dragInfo != nullptr? 1 : 0), widget.findChildIndexCallback);
    if (widget.itemExtent != nullptr) {
        return SliverFixedExtentList(childrenDelegate, widget.itemExtent!);
    } else     {
        if (widget.prototypeItem != nullptr) {
        return SliverPrototypeExtentList(childrenDelegate, widget.prototypeItem!);
    }
;
    }    return SliverList(childrenDelegate);
}

Axis SliverReorderableListState::_scrollDirection() {
    return axisDirectionToAxis(_scrollable.axisDirection);
}

bool SliverReorderableListState::_reverse() {
    return _scrollable.axisDirection == AxisDirection.up || _scrollable.axisDirection == AxisDirection.left;
}

void SliverReorderableListState::_registerItem(_ReorderableItemState item) {
    _items[item.index] = item;
    if (item.index == _dragInfo?.index) {
        item.dragging = true;
        item.rebuild();
    }
}

void SliverReorderableListState::_unregisterItem(int index, _ReorderableItemState item) {
    _ReorderableItemState currentItem = _items[index];
    if (currentItem == item) {
        _items.remove(index);
    }
}

Drag SliverReorderableListState::_dragStart(Offset position) {
    assert(_dragInfo == nullptr);
    _ReorderableItemState item = _items[_dragIndex!]!;
    item.dragging = true;
    widget.onReorderStart?.call(_dragIndex!);
    item.rebuild();
    _dragStartTransitionComplete = false;
    SchedulerBinding.instance.addPostFrameCallback();
    _insertIndex = item.index;
    _dragInfo = _DragInfo(item, position, _scrollDirection, _dragUpdate, _dragCancel, _dragEnd, _dropCompleted, widget.proxyDecorator, this);
    _dragInfo!.startDrag();
    OverlayState overlay = Overlay.of(context)!;
    assert(_overlayEntry == nullptr);
    _overlayEntry = OverlayEntry(_dragInfo!.createProxy);
    overlay.insert(_overlayEntry!);
    for (_ReorderableItemState childItem : _items.values) {
        if (childItem == item || !childItem.mounted) {
            continue;
        }
        childItem.updateForGap(_insertIndex!, _dragInfo!.itemExtent, false, _reverse);
    }
    return _dragInfo;
}

void SliverReorderableListState::_dragUpdate(Offset delta, _DragInfo item, Offset position) {
    setState();
}

void SliverReorderableListState::_dragCancel(_DragInfo item) {
    setState();
}

void SliverReorderableListState::_dragEnd(_DragInfo item) {
    setState();
    widget.onReorderEnd?.call(_insertIndex!);
}

void SliverReorderableListState::_dropCompleted() {
    int fromIndex = _dragIndex!;
    int toIndex = _insertIndex!;
    if (fromIndex != toIndex) {
        widget.onReorder.call(fromIndex, toIndex);
    }
    setState();
}

void SliverReorderableListState::_dragReset() {
    if (_dragInfo != nullptr) {
        if (_dragIndex != nullptr && _items.containsKey(_dragIndex)) {
            _ReorderableItemState dragItem = _items[_dragIndex!]!;
            dragItem._dragging = false;
            dragItem.rebuild();
            _dragIndex = nullptr;
        }
        _dragInfo?.dispose();
        _dragInfo = nullptr;
        _autoScroller?.stopAutoScroll();
        _resetItemGap();
        _recognizer?.dispose();
        _recognizer = nullptr;
        _overlayEntry?.remove();
        _overlayEntry = nullptr;
        _finalDropPosition = nullptr;
    }
}

void SliverReorderableListState::_resetItemGap() {
    for (_ReorderableItemState item : _items.values) {
        item.resetGap();
    }
}

void SliverReorderableListState::_handleScrollableAutoScrolled() {
    if (_dragInfo == nullptr) {
        return;
    }
    _dragUpdateItems();
    _autoScroller?.startAutoScrollIfNecessary(_dragTargetRect);
}

void SliverReorderableListState::_dragUpdateItems() {
    assert(_dragInfo != nullptr);
    double gapExtent = _dragInfo!.itemExtent;
    double proxyItemStart = _offsetExtent(_dragInfo!.dragPosition - _dragInfo!.dragOffset, _scrollDirection);
    double proxyItemEnd = proxyItemStart + gapExtent;
    int newIndex = _insertIndex!;
    for (_ReorderableItemState item : _items.values) {
        if (item.index == _dragIndex! || !item.mounted) {
            continue;
        }
        Rect geometry = item.targetGeometry();
        if (!_dragStartTransitionComplete && _dragIndex! <= item.index) {
            Offset transitionOffset = _extentOffset(_reverse? -gapExtent : gapExtent, _scrollDirection);
            geometry = (geometry.topLeft - transitionOffset) & geometry.size;
        }
        double itemStart = _scrollDirection == Axis.vertical? geometry.top : geometry.left;
        double itemExtent = _scrollDirection == Axis.vertical? geometry.height : geometry.width;
        double itemEnd = itemStart + itemExtent;
        double itemMiddle = itemStart + itemExtent / 2;
        if (_reverse) {
            if (itemEnd >= proxyItemEnd && proxyItemEnd >= itemMiddle) {
                newIndex = item.index;
                                break;
            } else             {
                if (itemMiddle >= proxyItemStart && proxyItemStart >= itemStart) {
                newIndex = item.index + 1;
                                break;
            } else             {
                if (itemStart > proxyItemEnd &&  < (item.index + 1)) {
                newIndex = item.index + 1;
            } else             {
                if (proxyItemStart > itemEnd && newIndex > item.index) {
                newIndex = item.index;
            }
;
            };
            };
            }        } else {
            if (itemStart <= proxyItemStart && proxyItemStart <= itemMiddle) {
                newIndex = item.index;
                                break;
            } else             {
                if (itemMiddle <= proxyItemEnd && proxyItemEnd <= itemEnd) {
                newIndex = item.index + 1;
                                break;
            } else             {
                if ( < proxyItemStart &&  < (item.index + 1)) {
                newIndex = item.index + 1;
            } else             {
                if ( < itemStart && newIndex > item.index) {
                newIndex = item.index;
            }
;
            };
            };
            }        }
    }
    if (newIndex != _insertIndex) {
        _insertIndex = newIndex;
        for (_ReorderableItemState item : _items.values) {
            if (item.index == _dragIndex! || !item.mounted) {
                continue;
            }
            item.updateForGap(newIndex, gapExtent, true, _reverse);
        }
    }
}

Rect SliverReorderableListState::_dragTargetRect() {
    Offset origin = _dragInfo!.dragPosition - _dragInfo!.dragOffset;
    return Rect.fromLTWH(origin.dx, origin.dy, _dragInfo!.itemSize.width, _dragInfo!.itemSize.height);
}

Offset SliverReorderableListState::_itemOffsetAt(int index) {
    RenderBox itemRenderBox = (;
    return itemRenderBox.localToGlobal(Offset.zero);
}

Widget SliverReorderableListState::_itemBuilder(BuildContext context, int index) {
    if (_dragInfo != nullptr && index >= widget.itemCount) {
        ;
    }
    Widget child = widget.itemBuilder(context, index);
    assert(child.key != nullptr, "All list items must have a key");
    OverlayState overlay = Overlay.of(context)!;
    return _ReorderableItem(_ReorderableItemGlobalKey(child.key!, index, this), index, InheritedTheme.capture(context, overlay.context), child);
}

_ReorderableItemState _ReorderableItem::createState() {
    return _ReorderableItemState();
}

_ReorderableItem::_ReorderableItem(CapturedThemes capturedThemes, Widget child, int index, Key key) {
    {
        super(key);
    }
}

Key _ReorderableItemState::key() {
    return widget.key!;
}

int _ReorderableItemState::index() {
    return widget.index;
}

bool _ReorderableItemState::dragging() {
    return _dragging;
}

void _ReorderableItemState::dragging(bool dragging) {
    if (mounted) {
        setState();
    }
}

void _ReorderableItemState::initState() {
    _listState = SliverReorderableList.of(context);
    _listState._registerItem(this);
    super.initState();
}

void _ReorderableItemState::dispose() {
    _offsetAnimation?.dispose();
    _listState._unregisterItem(index, this);
    super.dispose();
}

void _ReorderableItemState::didUpdateWidget(_ReorderableItem oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (oldWidget.index != widget.index) {
        _listState._unregisterItem(oldWidget.index, this);
        _listState._registerItem(this);
    }
}

Widget _ReorderableItemState::build(BuildContext context) {
    if (_dragging) {
        return const SizedBox();
    }
    _listState._registerItem(this);
    return Transform(Matrix4.translationValues(offset.dx, offset.dy, 0.0), widget.child);
}

void _ReorderableItemState::deactivate() {
    _listState._unregisterItem(index, this);
    super.deactivate();
}

Offset _ReorderableItemState::offset() {
    if (_offsetAnimation != nullptr) {
        double animValue = Curves.easeInOut.transform(_offsetAnimation!.value);
        return Offset.lerp(_startOffset, _targetOffset, animValue)!;
    }
    return _targetOffset;
}

void _ReorderableItemState::updateForGap(bool animate, double gapExtent, int gapIndex, bool reverse) {
    Offset newTargetOffset = (gapIndex <= index)? _extentOffset(reverse? -gapExtent : gapExtent, _listState._scrollDirection) : Offset.zero;
    if (newTargetOffset != _targetOffset) {
        _targetOffset = newTargetOffset;
        if (animate) {
            if (_offsetAnimation == nullptr) {
                _offsetAnimation = ;
            } else {
                _startOffset = offset;
                _offsetAnimation!.forward(0.0);
            }
        } else {
            if (_offsetAnimation != nullptr) {
                _offsetAnimation!.dispose();
                _offsetAnimation = nullptr;
            }
            _startOffset = _targetOffset;
        }
        rebuild();
    }
}

void _ReorderableItemState::resetGap() {
    if (_offsetAnimation != nullptr) {
        _offsetAnimation!.dispose();
        _offsetAnimation = nullptr;
    }
    _startOffset = Offset.zero;
    _targetOffset = Offset.zero;
    rebuild();
}

Rect _ReorderableItemState::targetGeometry() {
    RenderBox itemRenderBox = (;
    Offset itemPosition = itemRenderBox.localToGlobal(Offset.zero) + _targetOffset;
    return itemPosition & itemRenderBox.size;
}

void _ReorderableItemState::rebuild() {
    if (mounted) {
        setState();
    }
}

Widget ReorderableDragStartListener::build(BuildContext context) {
    return Listener(enabled?  : nullptr, child);
}

MultiDragGestureRecognizer ReorderableDragStartListener::createRecognizer() {
    return ImmediateMultiDragGestureRecognizer(this);
}

void ReorderableDragStartListener::_startDragging(BuildContext context, PointerDownEvent event) {
    DeviceGestureSettings gestureSettings = MediaQuery.maybeOf(context)?.gestureSettings;
    SliverReorderableListState list = SliverReorderableList.maybeOf(context);
    list?.startItemDragReorder(index, event, );
}

MultiDragGestureRecognizer ReorderableDelayedDragStartListener::createRecognizer() {
    return DelayedMultiDragGestureRecognizer(this);
}

void _DragInfo::dispose() {
    _proxyAnimation?.dispose();
}

void _DragInfo::startDrag() {
    _proxyAnimation = ;
}

void _DragInfo::update(DragUpdateDetails details) {
    Offset delta = _restrictAxis(details.delta, scrollDirection);
    dragPosition = delta;
    onUpdate?.call(this, dragPosition, details.delta);
}

void _DragInfo::end(DragEndDetails details) {
    _proxyAnimation!.reverse();
    onEnd?.call(this);
}

void _DragInfo::cancel() {
    _proxyAnimation?.dispose();
    _proxyAnimation = nullptr;
    onCancel?.call(this);
}

Widget _DragInfo::createProxy(BuildContext context) {
    return capturedThemes.wrap(_DragItemProxy(listState, index, itemSize, _proxyAnimation!, dragPosition - dragOffset - _overlayOrigin(context), proxyDecorator, child));
}

_DragInfo::_DragInfo(Offset initialPosition, _ReorderableItemState item, _DragItemCallback onCancel, VoidCallback onDropCompleted, _DragItemCallback onEnd, _DragItemUpdate onUpdate, ReorderItemProxyDecorator proxyDecorator, Axis scrollDirection, TickerProvider tickerProvider) {
    {
        RenderBox itemRenderBox = (;
        listState = item._listState;
        index = item.index;
        child = item.widget.child;
        capturedThemes = item.widget.capturedThemes;
        dragPosition = initialPosition;
        dragOffset = itemRenderBox.globalToLocal(initialPosition);
        itemSize = item.context.size!;
        itemExtent = _sizeExtent(itemSize, scrollDirection);
        scrollable = Scrollable.of(item.context);
    }
}

void _DragInfo::_dropCompleted() {
    _proxyAnimation?.dispose();
    _proxyAnimation = nullptr;
    onDropCompleted?.call();
}

Offset _overlayOrigin(BuildContext context) {
    OverlayState overlay = Overlay.of(context)!;
    RenderBox overlayBox = (;
    return overlayBox.localToGlobal(Offset.zero);
}

Widget _DragItemProxy::build(BuildContext context) {
    Widget proxyChild = proxyDecorator?.call(child, index, animation.view) ?? child;
    Offset overlayOrigin = _overlayOrigin(context);
    return MediaQuery(MediaQuery.of(context).removePadding(true), AnimatedBuilder(animation, , proxyChild));
}

double _sizeExtent(Axis scrollDirection, Size size) {
    ;
}

double _offsetExtent(Offset offset, Axis scrollDirection) {
    ;
}

Offset _extentOffset(double extent, Axis scrollDirection) {
    ;
}

Offset _restrictAxis(Offset offset, Axis scrollDirection) {
    ;
}

bool _ReorderableItemGlobalKey::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is _ReorderableItemGlobalKey && other.subKey == subKey && other.index == index && other.state == state;
}

int _ReorderableItemGlobalKey::hashCode() {
    return Object.hash(subKey, index, state);
}

_ReorderableItemGlobalKey::_ReorderableItemGlobalKey(int index, SliverReorderableListState state, Key subKey) {
    {
        super(subKey);
    }
}
