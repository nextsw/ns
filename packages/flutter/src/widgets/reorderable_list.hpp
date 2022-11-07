#ifndef REORDERABLE_LIST_H
#define REORDERABLE_LIST_H
#include <memory>

#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include <flutter/scheduler.hpp>
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



class ReorderableList : StatefulWidget {
public:
    IndexedWidgetBuilder itemBuilder;

    int itemCount;

    ReorderCallback onReorder;

    FunctionType onReorderStart;

    FunctionType onReorderEnd;

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


     ReorderableList(double anchor, double cacheExtent, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, IndexedWidgetBuilder itemBuilder, int itemCount, double itemExtent, Unknown, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, ReorderCallback onReorder, FunctionType onReorderEnd, FunctionType onReorderStart, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, Widget prototypeItem, ReorderItemProxyDecorator proxyDecorator, String restorationId, bool reverse, Axis scrollDirection, bool shrinkWrap);

    static ReorderableListState of(BuildContext context);

    static ReorderableListState maybeOf(BuildContext context);

    ReorderableListState createState();

private:

};

class ReorderableListState : State<ReorderableList> {
public:

    void startItemDragReorder(PointerDownEvent event, int index, MultiDragGestureRecognizer recognizer);

    void cancelReorder();

    Widget build(BuildContext context);

private:
    GlobalKey<SliverReorderableListState> _sliverReorderableListKey;


};

class SliverReorderableList : StatefulWidget {
public:
    IndexedWidgetBuilder itemBuilder;

    ChildIndexGetter findChildIndexCallback;

    int itemCount;

    ReorderCallback onReorder;

    FunctionType onReorderStart;

    FunctionType onReorderEnd;

    ReorderItemProxyDecorator proxyDecorator;

    double itemExtent;

    Widget prototypeItem;


     SliverReorderableList(ChildIndexGetter findChildIndexCallback, IndexedWidgetBuilder itemBuilder, int itemCount, double itemExtent, Unknown, ReorderCallback onReorder, FunctionType onReorderEnd, FunctionType onReorderStart, Widget prototypeItem, ReorderItemProxyDecorator proxyDecorator);

    SliverReorderableListState createState();

    static SliverReorderableListState of(BuildContext context);

    static SliverReorderableListState maybeOf(BuildContext context);

private:

};

class SliverReorderableListState : State<SliverReorderableList> {
public:

    void didChangeDependencies();

    void didUpdateWidget(SliverReorderableList oldWidget);

    void dispose();

    void startItemDragReorder(PointerDownEvent event, int index, MultiDragGestureRecognizer recognizer);

    void cancelReorder();

    Widget build(BuildContext context);

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


    Axis _scrollDirection();

    bool _reverse();

    void _registerItem(_ReorderableItemState item);

    void _unregisterItem(int index, _ReorderableItemState item);

    Drag _dragStart(Offset position);

    void _dragUpdate(Offset delta, _DragInfo item, Offset position);

    void _dragCancel(_DragInfo item);

    void _dragEnd(_DragInfo item);

    void _dropCompleted();

    void _dragReset();

    void _resetItemGap();

    void _handleScrollableAutoScrolled();

    void _dragUpdateItems();

    Rect _dragTargetRect();

    Offset _itemOffsetAt(int index);

    Widget _itemBuilder(BuildContext context, int index);

};

class _ReorderableItem : StatefulWidget {
public:
    int index;

    Widget child;

    CapturedThemes capturedThemes;


    _ReorderableItemState createState();

private:

     _ReorderableItem(CapturedThemes capturedThemes, Widget child, int index, Key key);

};

class _ReorderableItemState : State<_ReorderableItem> {
public:

    Key key();

    int index();

    bool dragging();

    void  dragging(bool dragging);

    void initState();

    void dispose();

    void didUpdateWidget(_ReorderableItem oldWidget);

    Widget build(BuildContext context);

    void deactivate();

    Offset offset();

    void updateForGap(bool animate, double gapExtent, int gapIndex, bool reverse);

    void resetGap();

    Rect targetGeometry();

    void rebuild();

private:
    SliverReorderableListState _listState;

    Offset _startOffset;

    Offset _targetOffset;

    AnimationController _offsetAnimation;

    bool _dragging;


};

class ReorderableDragStartListener : StatelessWidget {
public:
    Widget child;

    int index;

    bool enabled;


     ReorderableDragStartListener(Widget child, bool enabled, int index, Unknown);

    Widget build(BuildContext context);

    MultiDragGestureRecognizer createRecognizer();

private:

    void _startDragging(BuildContext context, PointerDownEvent event);

};

class ReorderableDelayedDragStartListener : ReorderableDragStartListener {
public:

     ReorderableDelayedDragStartListener(Unknown, Unknown, Unknown, Unknown);

    MultiDragGestureRecognizer createRecognizer();

private:

};

class _DragInfo : Drag {
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


    void dispose();

    void startDrag();

    void update(DragUpdateDetails details);

    void end(DragEndDetails details);

    void cancel();

    Widget createProxy(BuildContext context);

private:
    AnimationController _proxyAnimation;


     _DragInfo(Offset initialPosition, _ReorderableItemState item, _DragItemCallback onCancel, VoidCallback onDropCompleted, _DragItemCallback onEnd, _DragItemUpdate onUpdate, ReorderItemProxyDecorator proxyDecorator, Axis scrollDirection, TickerProvider tickerProvider);

    void _dropCompleted();

};
Offset _overlayOrigin(BuildContext context);


class _DragItemProxy : StatelessWidget {
public:
    SliverReorderableListState listState;

    int index;

    Widget child;

    Offset position;

    Size size;

    AnimationController animation;

    ReorderItemProxyDecorator proxyDecorator;


    Widget build(BuildContext context);

private:

     _DragItemProxy(AnimationController animation, Widget child, int index, SliverReorderableListState listState, Offset position, ReorderItemProxyDecorator proxyDecorator, Size size);

};
double _sizeExtent(Axis scrollDirection, Size size);

double _offsetExtent(Offset offset, Axis scrollDirection);

Offset _extentOffset(double extent, Axis scrollDirection);

Offset _restrictAxis(Offset offset, Axis scrollDirection);


class _ReorderableItemGlobalKey : GlobalObjectKey {
public:
    Key subKey;

    int index;

    SliverReorderableListState state;


    bool ==(Object other);

    int hashCode();

private:

     _ReorderableItemGlobalKey(int index, SliverReorderableListState state, Key subKey);

};

#endif