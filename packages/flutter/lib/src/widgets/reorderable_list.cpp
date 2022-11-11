#include "reorderable_list.hpp"
ReorderableListCls::ReorderableListCls(double anchor, double cacheExtent, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, IndexedWidgetBuilder itemBuilder, int itemCount, double itemExtent, Unknown key, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, ReorderCallback onReorder, void Function(int index) onReorderEnd, void Function(int index) onReorderStart, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, Widget prototypeItem, ReorderItemProxyDecorator proxyDecorator, String restorationId, bool reverse, Axis scrollDirection, bool shrinkWrap) {
    {
        assert(itemCount >= 0);
        assert(itemExtent == nullptr || prototypeItem == nullptr, __s("You can only pass itemExtent or prototypeItem, not both"));
    }
}

ReorderableListState ReorderableListCls::of(BuildContext context) {
    assert(context != nullptr);
    ReorderableListState result = context-><ReorderableListState>findAncestorStateOfType();
    assert([=] () {
        if (result == nullptr) {
            ;
        }
        return true;
    }());
    return result!;
}

ReorderableListState ReorderableListCls::maybeOf(BuildContext context) {
    assert(context != nullptr);
    return context-><ReorderableListState>findAncestorStateOfType();
}

ReorderableListState ReorderableListCls::createState() {
    return make<ReorderableListStateCls>();
}

void ReorderableListStateCls::startItemDragReorder(PointerDownEvent event, int index, MultiDragGestureRecognizer recognizer) {
    _sliverReorderableListKey->currentState()!->startItemDragReorder(index, event, recognizer);
}

void ReorderableListStateCls::cancelReorder() {
    _sliverReorderableListKey->currentState()!->cancelReorder();
}

Widget ReorderableListStateCls::build(BuildContext context) {
    return make<CustomScrollViewCls>(widget->scrollDirection, widget->reverse, widget->controller, widget->primary, widget->physics, widget->shrinkWrap, widget->anchor, widget->cacheExtent, widget->dragStartBehavior, widget->keyboardDismissBehavior, widget->restorationId, widget->clipBehavior, makeList(ArrayItem));
}

SliverReorderableListCls::SliverReorderableListCls(ChildIndexGetter findChildIndexCallback, IndexedWidgetBuilder itemBuilder, int itemCount, double itemExtent, Unknown key, ReorderCallback onReorder, void Function(int ) onReorderEnd, void Function(int ) onReorderStart, Widget prototypeItem, ReorderItemProxyDecorator proxyDecorator) {
    {
        assert(itemCount >= 0);
        assert(itemExtent == nullptr || prototypeItem == nullptr, __s("You can only pass itemExtent or prototypeItem, not both"));
    }
}

SliverReorderableListState SliverReorderableListCls::createState() {
    return make<SliverReorderableListStateCls>();
}

SliverReorderableListState SliverReorderableListCls::of(BuildContext context) {
    assert(context != nullptr);
    SliverReorderableListState result = context-><SliverReorderableListState>findAncestorStateOfType();
    assert([=] () {
        if (result == nullptr) {
            ;
        }
        return true;
    }());
    return result!;
}

SliverReorderableListState SliverReorderableListCls::maybeOf(BuildContext context) {
    assert(context != nullptr);
    return context-><SliverReorderableListState>findAncestorStateOfType();
}

void SliverReorderableListStateCls::didChangeDependencies() {
    super->didChangeDependencies();
    _scrollable = ScrollableCls->of(context)!;
    if (_autoScroller?->scrollable != _scrollable) {
        _autoScroller?->stopAutoScroll();
        _autoScroller = make<EdgeDraggingAutoScrollerCls>(_scrollable_handleScrollableAutoScrolled);
    }
}

void SliverReorderableListStateCls::didUpdateWidget(SliverReorderableList oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (widget->itemCount != oldWidget->itemCount) {
        cancelReorder();
    }
}

void SliverReorderableListStateCls::dispose() {
    _dragReset();
    super->dispose();
}

void SliverReorderableListStateCls::startItemDragReorder(PointerDownEvent event, int index, MultiDragGestureRecognizer recognizer) {
    assert(0 <= index &&  < widget->itemCount);
    setState([=] () {
        if (_dragInfo != nullptr) {
            cancelReorder();
        } else         {
            if (_recognizer != nullptr && _recognizerPointer != event->pointer) {
            _recognizer!->dispose();
            _recognizer = nullptr;
            _recognizerPointer = nullptr;
        }
;
        }        if (_items->containsKey(index)) {
            _dragIndex = index;
                    auto _c1 = recognizer;        _c1.onStart = auto _c2 = _dragStart;        _c2.addPointer(event);        _c2;_recognizer = _c1;
            _recognizerPointer = event->pointer;
        } else {
            ;
        }
    });
}

void SliverReorderableListStateCls::cancelReorder() {
    setState([=] () {
        _dragReset();
    });
}

Widget SliverReorderableListStateCls::build(BuildContext context) {
    assert(debugCheckHasOverlay(context));
    SliverChildBuilderDelegate childrenDelegate = make<SliverChildBuilderDelegateCls>(_itemBuilderwidget->itemCount + (_dragInfo != nullptr? 1 : 0), widget->findChildIndexCallback);
    if (widget->itemExtent != nullptr) {
        return make<SliverFixedExtentListCls>(childrenDelegate, widget->itemExtent!);
    } else     {
        if (widget->prototypeItem != nullptr) {
        return make<SliverPrototypeExtentListCls>(childrenDelegate, widget->prototypeItem!);
    }
;
    }    return make<SliverListCls>(childrenDelegate);
}

Axis SliverReorderableListStateCls::_scrollDirection() {
    return axisDirectionToAxis(_scrollable->axisDirection());
}

bool SliverReorderableListStateCls::_reverse() {
    return _scrollable->axisDirection() == AxisDirectionCls::up || _scrollable->axisDirection() == AxisDirectionCls::left;
}

void SliverReorderableListStateCls::_registerItem(_ReorderableItemState item) {
    _items[item->index()] = item;
    if (item->index() == _dragInfo?->index) {
        item->dragging() = true;
        item->rebuild();
    }
}

void SliverReorderableListStateCls::_unregisterItem(int index, _ReorderableItemState item) {
    _ReorderableItemState currentItem = _items[index];
    if (currentItem == item) {
        _items->remove(index);
    }
}

Drag SliverReorderableListStateCls::_dragStart(Offset position) {
    assert(_dragInfo == nullptr);
    _ReorderableItemState item = _items[_dragIndex!]!;
    item->dragging() = true;
    widget->onReorderStart?->call(_dragIndex!);
    item->rebuild();
    _dragStartTransitionComplete = false;
    SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration duration) {
        _dragStartTransitionComplete = true;
    });
    _insertIndex = item->index();
    _dragInfo = make<_DragInfoCls>(item, position, _scrollDirection(), _dragUpdate, _dragCancel, _dragEnd, _dropCompleted, widget->proxyDecorator, this);
    _dragInfo!->startDrag();
    OverlayState overlay = OverlayCls->of(context)!;
    assert(_overlayEntry == nullptr);
    _overlayEntry = make<OverlayEntryCls>(_dragInfo!->createProxy);
    overlay->insert(_overlayEntry!);
    for (_ReorderableItemState childItem : _items->values()) {
        if (childItem == item || !childItem->mounted) {
            continue;
        }
        childItem->updateForGap(_insertIndex!, _dragInfo!->itemExtent, false, _reverse());
    }
    return _dragInfo;
}

void SliverReorderableListStateCls::_dragUpdate(Offset delta, _DragInfo item, Offset position) {
    setState([=] () {
        _overlayEntry?->markNeedsBuild();
        _dragUpdateItems();
        _autoScroller?->startAutoScrollIfNecessary(_dragTargetRect());
    });
}

void SliverReorderableListStateCls::_dragCancel(_DragInfo item) {
    setState([=] () {
        _dragReset();
    });
}

void SliverReorderableListStateCls::_dragEnd(_DragInfo item) {
    setState([=] () {
        if (_insertIndex! < widget->itemCount - 1) {
            _finalDropPosition = _itemOffsetAt(_insertIndex! + (_reverse()? 1 : 0));
        } else {
            int itemIndex = _items->length() > 1? _insertIndex! - 1 : _insertIndex!;
            if (_reverse()) {
                _finalDropPosition = _itemOffsetAt(itemIndex) - _extentOffset(item->itemExtent, _scrollDirection());
            } else {
                _finalDropPosition = _itemOffsetAt(itemIndex) + _extentOffset(item->itemExtent, _scrollDirection());
            }
        }
    });
    widget->onReorderEnd?->call(_insertIndex!);
}

void SliverReorderableListStateCls::_dropCompleted() {
    int fromIndex = _dragIndex!;
    int toIndex = _insertIndex!;
    if (fromIndex != toIndex) {
        widget->onReorder->call(fromIndex, toIndex);
    }
    setState([=] () {
        _dragReset();
    });
}

void SliverReorderableListStateCls::_dragReset() {
    if (_dragInfo != nullptr) {
        if (_dragIndex != nullptr && _items->containsKey(_dragIndex)) {
            _ReorderableItemState dragItem = _items[_dragIndex!]!;
            dragItem->_dragging = false;
            dragItem->rebuild();
            _dragIndex = nullptr;
        }
        _dragInfo?->dispose();
        _dragInfo = nullptr;
        _autoScroller?->stopAutoScroll();
        _resetItemGap();
        _recognizer?->dispose();
        _recognizer = nullptr;
        _overlayEntry?->remove();
        _overlayEntry = nullptr;
        _finalDropPosition = nullptr;
    }
}

void SliverReorderableListStateCls::_resetItemGap() {
    for (_ReorderableItemState item : _items->values()) {
        item->resetGap();
    }
}

void SliverReorderableListStateCls::_handleScrollableAutoScrolled() {
    if (_dragInfo == nullptr) {
        return;
    }
    _dragUpdateItems();
    _autoScroller?->startAutoScrollIfNecessary(_dragTargetRect());
}

void SliverReorderableListStateCls::_dragUpdateItems() {
    assert(_dragInfo != nullptr);
    double gapExtent = _dragInfo!->itemExtent;
    double proxyItemStart = _offsetExtent(_dragInfo!->dragPosition - _dragInfo!->dragOffset, _scrollDirection());
    double proxyItemEnd = proxyItemStart + gapExtent;
    int newIndex = _insertIndex!;
    for (_ReorderableItemState item : _items->values()) {
        if (item->index == _dragIndex! || !item->mounted) {
            continue;
        }
        Rect geometry = item->targetGeometry();
        if (!_dragStartTransitionComplete && _dragIndex! <= item->index) {
            Offset transitionOffset = _extentOffset(_reverse()? -gapExtent : gapExtent, _scrollDirection());
            geometry = (geometry->topLeft() - transitionOffset) & geometry->size();
        }
        double itemStart = _scrollDirection() == AxisCls::vertical? geometry->top : geometry->left;
        double itemExtent = _scrollDirection() == AxisCls::vertical? geometry->height() : geometry->width();
        double itemEnd = itemStart + itemExtent;
        double itemMiddle = itemStart + itemExtent / 2;
        if (_reverse()) {
            if (itemEnd >= proxyItemEnd && proxyItemEnd >= itemMiddle) {
                newIndex = item->index;
                                break;
            } else             {
                if (itemMiddle >= proxyItemStart && proxyItemStart >= itemStart) {
                newIndex = item->index + 1;
                                break;
            } else             {
                if (itemStart > proxyItemEnd &&  < (item->index + 1)) {
                newIndex = item->index + 1;
            } else             {
                if (proxyItemStart > itemEnd && newIndex > item->index) {
                newIndex = item->index;
            }
;
            };
            };
            }        } else {
            if (itemStart <= proxyItemStart && proxyItemStart <= itemMiddle) {
                newIndex = item->index;
                                break;
            } else             {
                if (itemMiddle <= proxyItemEnd && proxyItemEnd <= itemEnd) {
                newIndex = item->index + 1;
                                break;
            } else             {
                if ( < proxyItemStart &&  < (item->index + 1)) {
                newIndex = item->index + 1;
            } else             {
                if ( < itemStart && newIndex > item->index) {
                newIndex = item->index;
            }
;
            };
            };
            }        }
    }
    if (newIndex != _insertIndex) {
        _insertIndex = newIndex;
        for (_ReorderableItemState item : _items->values()) {
            if (item->index == _dragIndex! || !item->mounted) {
                continue;
            }
            item->updateForGap(newIndex, gapExtent, true, _reverse());
        }
    }
}

Rect SliverReorderableListStateCls::_dragTargetRect() {
    Offset origin = _dragInfo!->dragPosition - _dragInfo!->dragOffset;
    return RectCls->fromLTWH(origin->dx(), origin->dy(), _dragInfo!->itemSize->width(), _dragInfo!->itemSize->height());
}

Offset SliverReorderableListStateCls::_itemOffsetAt(int index) {
    RenderBox itemRenderBox = as<RenderBox>(_items[index]!->context->findRenderObject()!);
    return itemRenderBox->localToGlobal(OffsetCls::zero);
}

Widget SliverReorderableListStateCls::_itemBuilder(BuildContext context, int index) {
    if (_dragInfo != nullptr && index >= widget->itemCount) {
        ;
    }
    Widget child = widget->itemBuilder(context, index);
    assert(child->key != nullptr, __s("All list items must have a key"));
    OverlayState overlay = OverlayCls->of(context)!;
    return make<_ReorderableItemCls>(make<_ReorderableItemGlobalKeyCls>(child->key!, index, this), index, InheritedThemeCls->capture(context, overlay->context), child);
}

_ReorderableItemState _ReorderableItemCls::createState() {
    return make<_ReorderableItemStateCls>();
}

_ReorderableItemCls::_ReorderableItemCls(CapturedThemes capturedThemes, Widget child, int index, Key key) : StatefulWidget(key) {
}

Key _ReorderableItemStateCls::key() {
    return widget->key!;
}

int _ReorderableItemStateCls::index() {
    return widget->index;
}

bool _ReorderableItemStateCls::dragging() {
    return _dragging;
}

void _ReorderableItemStateCls::dragging(bool dragging) {
    if (mounted) {
        setState([=] () {
            _dragging = dragging;
        });
    }
}

void _ReorderableItemStateCls::initState() {
    _listState = SliverReorderableListCls->of(context);
    _listState->_registerItem(this);
    super->initState();
}

void _ReorderableItemStateCls::dispose() {
    _offsetAnimation?->dispose();
    _listState->_unregisterItem(index(), this);
    super->dispose();
}

void _ReorderableItemStateCls::didUpdateWidget(_ReorderableItem oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (oldWidget->index != widget->index) {
        _listState->_unregisterItem(oldWidget->index, this);
        _listState->_registerItem(this);
    }
}

Widget _ReorderableItemStateCls::build(BuildContext context) {
    if (_dragging) {
        return make<SizedBoxCls>();
    }
    _listState->_registerItem(this);
    return make<TransformCls>(Matrix4Cls->translationValues(offset()->dx(), offset()->dy(), 0.0), widget->child);
}

void _ReorderableItemStateCls::deactivate() {
    _listState->_unregisterItem(index(), this);
    super->deactivate();
}

Offset _ReorderableItemStateCls::offset() {
    if (_offsetAnimation != nullptr) {
        double animValue = CurvesCls::easeInOut->transform(_offsetAnimation!->value());
        return OffsetCls->lerp(_startOffset, _targetOffset, animValue)!;
    }
    return _targetOffset;
}

void _ReorderableItemStateCls::updateForGap(bool animate, double gapExtent, int gapIndex, bool reverse) {
    Offset newTargetOffset = (gapIndex <= index())? _extentOffset(reverse? -gapExtent : gapExtent, _listState->_scrollDirection()) : OffsetCls::zero;
    if (newTargetOffset != _targetOffset) {
        _targetOffset = newTargetOffset;
        if (animate) {
            if (_offsetAnimation == nullptr) {
                                            });            _c3.forward();            _c3;            _c2;_offsetAnimation =                                     }                    auto _c1 = make<AnimationControllerCls>(_listState, make<DurationCls>(250));                    _c1.auto _c2 = addListener(rebuild);                    _c2.auto _c3 = addStatusListener([=] (AnimationStatus status) {                                        if (status == AnimationStatusCls::completed) {                                            _startOffset = _targetOffset;                                            _offsetAnimation!->dispose();                                            _offsetAnimation = nullptr;_c1;
            } else {
                _startOffset = offset();
                _offsetAnimation!->forward(0.0);
            }
        } else {
            if (_offsetAnimation != nullptr) {
                _offsetAnimation!->dispose();
                _offsetAnimation = nullptr;
            }
            _startOffset = _targetOffset;
        }
        rebuild();
    }
}

void _ReorderableItemStateCls::resetGap() {
    if (_offsetAnimation != nullptr) {
        _offsetAnimation!->dispose();
        _offsetAnimation = nullptr;
    }
    _startOffset = OffsetCls::zero;
    _targetOffset = OffsetCls::zero;
    rebuild();
}

Rect _ReorderableItemStateCls::targetGeometry() {
    RenderBox itemRenderBox = as<RenderBox>(context->findRenderObject()!);
    Offset itemPosition = itemRenderBox->localToGlobal(OffsetCls::zero) + _targetOffset;
    return itemPosition & itemRenderBox->size();
}

void _ReorderableItemStateCls::rebuild() {
    if (mounted) {
        setState([=] () {
        });
    }
}

Widget ReorderableDragStartListenerCls::build(BuildContext context) {
    return make<ListenerCls>(enabled? [=] (PointerDownEvent event)     {
        _startDragging(context, event);
    } : nullptr, child);
}

MultiDragGestureRecognizer ReorderableDragStartListenerCls::createRecognizer() {
    return make<ImmediateMultiDragGestureRecognizerCls>(this);
}

void ReorderableDragStartListenerCls::_startDragging(BuildContext context, PointerDownEvent event) {
    DeviceGestureSettings gestureSettings = MediaQueryCls->maybeOf(context)?->gestureSettings;
    SliverReorderableListState list = SliverReorderableListCls->maybeOf(context);
    auto _c1 = createRecognizer();_c1.gestureSettings = gestureSettings;list?->startItemDragReorder(index, event, _c1);
}

MultiDragGestureRecognizer ReorderableDelayedDragStartListenerCls::createRecognizer() {
    return make<DelayedMultiDragGestureRecognizerCls>(this);
}

void _DragInfoCls::dispose() {
    _proxyAnimation?->dispose();
}

void _DragInfoCls::startDrag() {
        });_c2.forward();_c2;_proxyAnimation =             }        auto _c1 = make<AnimationControllerCls>(tickerProvider, make<DurationCls>(250));        _c1.auto _c2 = addStatusListener([=] (AnimationStatus status) {                if (status == AnimationStatusCls::dismissed) {                    _dropCompleted();_c1;
}

void _DragInfoCls::update(DragUpdateDetails details) {
    Offset delta = _restrictAxis(details->delta, scrollDirection);
    dragPosition = delta;
    onUpdate?->call(this, dragPosition, details->delta);
}

void _DragInfoCls::end(DragEndDetails details) {
    _proxyAnimation!->reverse();
    onEnd?->call(this);
}

void _DragInfoCls::cancel() {
    _proxyAnimation?->dispose();
    _proxyAnimation = nullptr;
    onCancel?->call(this);
}

Widget _DragInfoCls::createProxy(BuildContext context) {
    return capturedThemes->wrap(make<_DragItemProxyCls>(listState, index, itemSize, _proxyAnimation!, dragPosition - dragOffset - _overlayOrigin(context), proxyDecorator, child));
}

_DragInfoCls::_DragInfoCls(Offset initialPosition, _ReorderableItemState item, _DragItemCallback onCancel, VoidCallback onDropCompleted, _DragItemCallback onEnd, _DragItemUpdate onUpdate, ReorderItemProxyDecorator proxyDecorator, Axis scrollDirection, TickerProvider tickerProvider) {
    {
        RenderBox itemRenderBox = as<RenderBox>(item->context->findRenderObject()!);
        listState = item->_listState;
        index = item->index;
        child = item->widget->child;
        capturedThemes = item->widget->capturedThemes;
        dragPosition = initialPosition;
        dragOffset = itemRenderBox->globalToLocal(initialPosition);
        itemSize = item->context->size!;
        itemExtent = _sizeExtent(itemSize, scrollDirection);
        scrollable = ScrollableCls->of(item->context);
    }
}

void _DragInfoCls::_dropCompleted() {
    _proxyAnimation?->dispose();
    _proxyAnimation = nullptr;
    onDropCompleted?->call();
}

Offset _overlayOrigin(BuildContext context) {
    OverlayState overlay = OverlayCls->of(context)!;
    RenderBox overlayBox = as<RenderBox>(overlay->context->findRenderObject()!);
    return overlayBox->localToGlobal(OffsetCls::zero);
}

Widget _DragItemProxyCls::build(BuildContext context) {
    Widget proxyChild = proxyDecorator?->call(child, index, animation->view()) or child;
    Offset overlayOrigin = _overlayOrigin(context);
    return make<MediaQueryCls>(MediaQueryCls->of(context)->removePadding(true), make<AnimatedBuilderCls>(animation, [=] (BuildContext context,Widget child) {
        Offset effectivePosition = position;
        Offset dropPosition = listState->_finalDropPosition;
        if (dropPosition != nullptr) {
            effectivePosition = OffsetCls->lerp(dropPosition - overlayOrigin, effectivePosition, CurvesCls::easeOut->transform(animation->value()))!;
        }
        return make<PositionedCls>(effectivePosition->dx(), effectivePosition->dy(), make<SizedBoxCls>(size->width(), size->height(), child));
    }, proxyChild));
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

bool _ReorderableItemGlobalKeyCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<_ReorderableItemGlobalKey>(other) && other->subKey == subKey && other->index == index && other->state == state;
}

int _ReorderableItemGlobalKeyCls::hashCode() {
    return ObjectCls->hash(subKey, index, state);
}

_ReorderableItemGlobalKeyCls::_ReorderableItemGlobalKeyCls(int index, SliverReorderableListState state, Key subKey) : GlobalObjectKey(subKey) {
}
