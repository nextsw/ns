#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_REORDERABLE_LIST
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_REORDERABLE_LIST
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "inherited_theme.hpp"
#include "media_query.hpp"
#include "overlay.hpp"
#include "scroll_controller.hpp"
#include "scroll_physics.hpp"
#include "scroll_view.hpp"
#include "scrollable.hpp"
#include "sliver.hpp"
#include "sliver_prototype_extent_list.hpp"
#include "ticker_provider.hpp"
#include "transitions.hpp"


class ReorderableListCls : public StatefulWidgetCls {
public:
    IndexedWidgetBuilder itemBuilder;

    int itemCount;

    ReorderCallback onReorder;

    void Function(int index) onReorderStart;

    void Function(int index) onReorderEnd;

    ReorderItemProxyDecorator proxyDecorator;

    EdgeInsetsGeometry padding;

    Axis scrollDirection;

    bool reverse;

    ScrollController controller;

    bool primary;

    ScrollPhysics physics;

    bool shrinkWrap;

    double anchor;

    double cacheExtent;

    DragStartBehavior dragStartBehavior;

    ScrollViewKeyboardDismissBehavior keyboardDismissBehavior;

    String restorationId;

    Clip clipBehavior;

    double itemExtent;

    Widget prototypeItem;


     ReorderableListCls(double anchor, double cacheExtent, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, IndexedWidgetBuilder itemBuilder, int itemCount, double itemExtent, Unknown key, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, ReorderCallback onReorder, void Function(int index) onReorderEnd, void Function(int index) onReorderStart, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, Widget prototypeItem, ReorderItemProxyDecorator proxyDecorator, String restorationId, bool reverse, Axis scrollDirection, bool shrinkWrap);

    static ReorderableListState of(BuildContext context);

    static ReorderableListState maybeOf(BuildContext context);

    virtual ReorderableListState createState();

private:

};
using ReorderableList = std::shared_ptr<ReorderableListCls>;

class ReorderableListStateCls : public StateCls<ReorderableList> {
public:

    virtual void startItemDragReorder(PointerDownEvent event, int index, MultiDragGestureRecognizer recognizer);

    virtual void cancelReorder();

    virtual Widget build(BuildContext context);

private:
    GlobalKey<SliverReorderableListState> _sliverReorderableListKey;


};
using ReorderableListState = std::shared_ptr<ReorderableListStateCls>;

class SliverReorderableListCls : public StatefulWidgetCls {
public:
    IndexedWidgetBuilder itemBuilder;

    ChildIndexGetter findChildIndexCallback;

    int itemCount;

    ReorderCallback onReorder;

    void Function(int ) onReorderStart;

    void Function(int ) onReorderEnd;

    ReorderItemProxyDecorator proxyDecorator;

    double itemExtent;

    Widget prototypeItem;


     SliverReorderableListCls(ChildIndexGetter findChildIndexCallback, IndexedWidgetBuilder itemBuilder, int itemCount, double itemExtent, Unknown key, ReorderCallback onReorder, void Function(int ) onReorderEnd, void Function(int ) onReorderStart, Widget prototypeItem, ReorderItemProxyDecorator proxyDecorator);

    virtual SliverReorderableListState createState();

    static SliverReorderableListState of(BuildContext context);

    static SliverReorderableListState maybeOf(BuildContext context);

private:

};
using SliverReorderableList = std::shared_ptr<SliverReorderableListCls>;

class SliverReorderableListStateCls : public StateCls<SliverReorderableList> {
public:

    virtual void didChangeDependencies();

    virtual void didUpdateWidget(SliverReorderableList oldWidget);

    virtual void dispose();

    virtual void startItemDragReorder(PointerDownEvent event, int index, MultiDragGestureRecognizer recognizer);

    virtual void cancelReorder();

    virtual Widget build(BuildContext context);

private:
    Map<int, _ReorderableItemState> _items;

    OverlayEntry _overlayEntry;

    int _dragIndex;

    _DragInfo _dragInfo;

    int _insertIndex;

    Offset _finalDropPosition;

    MultiDragGestureRecognizer _recognizer;

    int _recognizerPointer;

    bool _dragStartTransitionComplete;

    EdgeDraggingAutoScroller _autoScroller;

    ScrollableState _scrollable;


    virtual Axis _scrollDirection();

    virtual bool _reverse();

    virtual void _registerItem(_ReorderableItemState item);

    virtual void _unregisterItem(int index, _ReorderableItemState item);

    virtual Drag _dragStart(Offset position);

    virtual void _dragUpdate(Offset delta, _DragInfo item, Offset position);

    virtual void _dragCancel(_DragInfo item);

    virtual void _dragEnd(_DragInfo item);

    virtual void _dropCompleted();

    virtual void _dragReset();

    virtual void _resetItemGap();

    virtual void _handleScrollableAutoScrolled();

    virtual void _dragUpdateItems();

    virtual Rect _dragTargetRect();

    virtual Offset _itemOffsetAt(int index);

    virtual Widget _itemBuilder(BuildContext context, int index);

};
using SliverReorderableListState = std::shared_ptr<SliverReorderableListStateCls>;

class _ReorderableItemCls : public StatefulWidgetCls {
public:
    int index;

    Widget child;

    CapturedThemes capturedThemes;


    virtual _ReorderableItemState createState();

private:

     _ReorderableItemCls(CapturedThemes capturedThemes, Widget child, int index, Key key);

};
using _ReorderableItem = std::shared_ptr<_ReorderableItemCls>;

class _ReorderableItemStateCls : public StateCls<_ReorderableItem> {
public:

    virtual Key key();

    virtual int index();

    virtual bool dragging();

    virtual void  dragging(bool dragging);

    virtual void initState();

    virtual void dispose();

    virtual void didUpdateWidget(_ReorderableItem oldWidget);

    virtual Widget build(BuildContext context);

    virtual void deactivate();

    virtual Offset offset();

    virtual void updateForGap(bool animate, double gapExtent, int gapIndex, bool reverse);

    virtual void resetGap();

    virtual Rect targetGeometry();

    virtual void rebuild();

private:
    SliverReorderableListState _listState;

    Offset _startOffset;

    Offset _targetOffset;

    AnimationController _offsetAnimation;

    bool _dragging;


};
using _ReorderableItemState = std::shared_ptr<_ReorderableItemStateCls>;

class ReorderableDragStartListenerCls : public StatelessWidgetCls {
public:
    Widget child;

    int index;

    bool enabled;


     ReorderableDragStartListenerCls(Widget child, bool enabled, int index, Unknown key);
    virtual Widget build(BuildContext context);

    virtual MultiDragGestureRecognizer createRecognizer();

private:

    virtual void _startDragging(BuildContext context, PointerDownEvent event);

};
using ReorderableDragStartListener = std::shared_ptr<ReorderableDragStartListenerCls>;

class ReorderableDelayedDragStartListenerCls : public ReorderableDragStartListenerCls {
public:

     ReorderableDelayedDragStartListenerCls(Unknown child, Unknown enabled, Unknown index, Unknown key);
    virtual MultiDragGestureRecognizer createRecognizer();

private:

};
using ReorderableDelayedDragStartListener = std::shared_ptr<ReorderableDelayedDragStartListenerCls>;

class _DragInfoCls : public DragCls {
public:
    Axis scrollDirection;

    _DragItemUpdate onUpdate;

    _DragItemCallback onEnd;

    _DragItemCallback onCancel;

    VoidCallback onDropCompleted;

    ReorderItemProxyDecorator proxyDecorator;

    TickerProvider tickerProvider;

    SliverReorderableListState listState;

    int index;

    Widget child;

    Offset dragPosition;

    Offset dragOffset;

    Size itemSize;

    double itemExtent;

    CapturedThemes capturedThemes;

    ScrollableState scrollable;


    virtual void dispose();

    virtual void startDrag();

    virtual void update(DragUpdateDetails details);

    virtual void end(DragEndDetails details);

    virtual void cancel();

    virtual Widget createProxy(BuildContext context);

private:
    AnimationController _proxyAnimation;


     _DragInfoCls(Offset initialPosition, _ReorderableItemState item, _DragItemCallback onCancel, VoidCallback onDropCompleted, _DragItemCallback onEnd, _DragItemUpdate onUpdate, ReorderItemProxyDecorator proxyDecorator, Axis scrollDirection, TickerProvider tickerProvider);

    virtual void _dropCompleted();

};
using _DragInfo = std::shared_ptr<_DragInfoCls>;
Offset _overlayOrigin(BuildContext context);


class _DragItemProxyCls : public StatelessWidgetCls {
public:
    SliverReorderableListState listState;

    int index;

    Widget child;

    Offset position;

    Size size;

    AnimationController animation;

    ReorderItemProxyDecorator proxyDecorator;


    virtual Widget build(BuildContext context);

private:

     _DragItemProxyCls(AnimationController animation, Widget child, int index, SliverReorderableListState listState, Offset position, ReorderItemProxyDecorator proxyDecorator, Size size);
};
using _DragItemProxy = std::shared_ptr<_DragItemProxyCls>;
double _sizeExtent(Axis scrollDirection, Size size);

double _offsetExtent(Offset offset, Axis scrollDirection);

Offset _extentOffset(double extent, Axis scrollDirection);

Offset _restrictAxis(Offset offset, Axis scrollDirection);


class _ReorderableItemGlobalKeyCls : public GlobalObjectKeyCls {
public:
    Key subKey;

    int index;

    SliverReorderableListState state;


    virtual bool operator==(Object other);

    virtual int hashCode();

private:

     _ReorderableItemGlobalKeyCls(int index, SliverReorderableListState state, Key subKey);

};
using _ReorderableItemGlobalKey = std::shared_ptr<_ReorderableItemGlobalKeyCls>;


#endif