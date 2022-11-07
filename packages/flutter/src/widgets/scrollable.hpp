#ifndef SCROLLABLE_H
#define SCROLLABLE_H
#include <memory>
#include <flutter/physics.hpp>

#include <async/async.hpp>
#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include <flutter/scheduler.hpp>
#include <flutter/services.hpp>
#include "actions.hpp"
#include "basic.hpp"
#include "focus_manager.hpp"
#include "framework.hpp"
#include "gesture_detector.hpp"
#include "media_query.hpp"
#include "notification_listener.hpp"
#include "primary_scroll_controller.hpp"
#include "restoration.hpp"
#include "restoration_properties.hpp"
#include "scroll_activity.hpp"
#include "scroll_configuration.hpp"
#include "scroll_context.hpp"
#include "scroll_controller.hpp"
#include "scroll_metrics.hpp"
#include "scroll_physics.hpp"
#include "scroll_position.hpp"
#include "selectable_region.hpp"
#include "selection_container.hpp"
#include "ticker_provider.hpp"
#include "viewport.hpp"



class Scrollable : StatefulWidget {
public:
    AxisDirection axisDirection;

    ScrollController controller;

    ScrollPhysics physics;

    ViewportBuilder viewportBuilder;

    ScrollIncrementCalculator incrementCalculator;

    bool excludeFromSemantics;

    int semanticChildCount;

    DragStartBehavior dragStartBehavior;

    String restorationId;

    ScrollBehavior scrollBehavior;

    Clip clipBehavior;


     Scrollable(AxisDirection axisDirection, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, bool excludeFromSemantics, ScrollIncrementCalculator incrementCalculator, Unknown, ScrollPhysics physics, String restorationId, ScrollBehavior scrollBehavior, int semanticChildCount, ViewportBuilder viewportBuilder);

    Axis axis();

    ScrollableState createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    static ScrollableState of(BuildContext context);

    static bool recommendDeferredLoadingForContext(BuildContext context);

    static Future<void> ensureVisible(double alignment, ScrollPositionAlignmentPolicy alignmentPolicy, BuildContext context, Curve curve, Duration duration);

private:

};

class _ScrollableScope : InheritedWidget {
public:
    ScrollableState scrollable;

    ScrollPosition position;


    bool updateShouldNotify(_ScrollableScope old);

private:

     _ScrollableScope(Unknown, ScrollPosition position, ScrollableState scrollable);

};

class ScrollableState : State<Scrollable> {
public:

    ScrollPosition position();

    AxisDirection axisDirection();

    void restoreState(bool initialRestore, RestorationBucket oldBucket);

    void saveOffset(double offset);

    void initState();

    void didChangeDependencies();

    void didUpdateWidget(Scrollable oldWidget);

    void dispose();

    void setSemanticsActions(Set<SemanticsAction> actions);

    void setCanDrag(bool value);

    TickerProvider vsync();

    void setIgnorePointer(bool value);

    BuildContext notificationContext();

    BuildContext storageContext();

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    String restorationId();

private:
    ScrollPosition _position;

    _RestorableScrollOffset _persistedScrollOffset;

    ScrollBehavior _configuration;

    ScrollPhysics _physics;

    ScrollController _fallbackScrollController;

    MediaQueryData _mediaQueryData;

    GlobalKey _scrollSemanticsKey;

    GlobalKey<RawGestureDetectorState> _gestureDetectorKey;

    GlobalKey _ignorePointerKey;

    Map<Type, GestureRecognizerFactory> _gestureRecognizers;

    bool _shouldIgnorePointer;

    bool _lastCanDrag;

    Axis _lastAxisDirection;

    Drag _drag;

    ScrollHoldController _hold;


    ScrollController _effectiveScrollController();

    void _updatePosition();

    bool _shouldUpdatePosition(Scrollable oldWidget);

    void _handleDragDown(DragDownDetails details);

    void _handleDragStart(DragStartDetails details);

    void _handleDragUpdate(DragUpdateDetails details);

    void _handleDragEnd(DragEndDetails details);

    void _handleDragCancel();

    void _disposeHold();

    void _disposeDrag();

    double _targetScrollOffsetForPointerScroll(double delta);

    double _pointerSignalEventDelta(PointerScrollEvent event);

    void _receivedPointerSignal(PointerSignalEvent event);

    void _handlePointerScroll(PointerEvent event);

    bool _handleScrollMetricsNotification(ScrollMetricsNotification notification);

};

class _ScrollableSelectionHandler : StatefulWidget {
public:
    ScrollableState state;

    ScrollPosition position;

    Widget child;

    SelectionRegistrar registrar;


    _ScrollableSelectionHandlerState createState();

private:

     _ScrollableSelectionHandler(Widget child, ScrollPosition position, SelectionRegistrar registrar, ScrollableState state);

};

class _ScrollableSelectionHandlerState : State<_ScrollableSelectionHandler> {
public:

    void initState();

    void didUpdateWidget(_ScrollableSelectionHandler oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:
    _ScrollableSelectionContainerDelegate _selectionDelegate;


};

class EdgeDraggingAutoScroller {
public:
    ScrollableState scrollable;

    VoidCallback onScrollViewScrolled;

    double velocityScalar;


     EdgeDraggingAutoScroller(VoidCallback onScrollViewScrolled, ScrollableState scrollable, double velocityScalar);

    bool scrolling();

    void startAutoScrollIfNecessary(Rect dragTarget);

    void stopAutoScroll();

private:
    static const double _kDefaultAutoScrollVelocityScalar;

    Rect _dragTargetRelatedToScrollOrigin;

    bool _scrolling;


    double _offsetExtent(Offset offset, Axis scrollDirection);

    double _sizeExtent(Axis scrollDirection, Size size);

    AxisDirection _axisDirection();

    Axis _scrollDirection();

    Future<void> _scroll();

};

class _ScrollableSelectionContainerDelegate : MultiSelectableSelectionContainerDelegate {
public:
    ScrollableState state;


    ScrollPosition position();

    void  position(ScrollPosition other);

    void didChangeSelectables();

    SelectionResult handleClearSelection(ClearSelectionEvent event);

    SelectionResult handleSelectionEdgeUpdate(SelectionEdgeUpdateEvent event);

    SelectionResult handleSelectAll(SelectAllSelectionEvent event);

    SelectionResult handleSelectWord(SelectWordSelectionEvent event);

    SelectionResult dispatchSelectionEventToChild(SelectionEvent event, Selectable selectable);

    void ensureChildUpdated(Selectable selectable);

    void dispose();

private:
    static const double _kDefaultDragTargetSize;

    static const double _kDefaultSelectToScrollVelocityScalar;

    EdgeDraggingAutoScroller _autoScroller;

    bool _scheduledLayoutChange;

    Offset _currentDragStartRelatedToOrigin;

    Offset _currentDragEndRelatedToOrigin;

    bool _selectionStartsInScrollable;

    ScrollPosition _position;

    Map<Selectable, double> _selectableStartEdgeUpdateRecords;

    Map<Selectable, double> _selectableEndEdgeUpdateRecords;


     _ScrollableSelectionContainerDelegate(ScrollPosition position, ScrollableState state);

    void _scheduleLayoutChange();

    Offset _inferPositionRelatedToOrigin(Offset globalPosition);

    void _updateDragLocationsFromGeometries();

    bool _globalPositionInScrollable(Offset globalPosition);

    Rect _dragTargetFromEvent(SelectionEdgeUpdateEvent event);

};
Offset _getDeltaToScrollOrigin(ScrollableState scrollableState);


class ScrollableDetails {
public:
    AxisDirection direction;

    ScrollController controller;

    Clip clipBehavior;


     ScrollableDetails(Clip clipBehavior, ScrollController controller, AxisDirection direction);

private:

};

class _ScrollSemantics : SingleChildRenderObjectWidget {
public:
    ScrollPosition position;

    bool allowImplicitScrolling;

    int semanticChildCount;


    _RenderScrollSemantics createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, _RenderScrollSemantics renderObject);

private:

     _ScrollSemantics(bool allowImplicitScrolling, Unknown, Unknown, ScrollPosition position, int semanticChildCount);

};

class _RenderScrollSemantics : RenderProxyBox {
public:

    ScrollPosition position();

    void  position(ScrollPosition value);

    bool allowImplicitScrolling();

    void  allowImplicitScrolling(bool value);

    int semanticChildCount();

    void  semanticChildCount(int value);

    void describeSemanticsConfiguration(SemanticsConfiguration config);

    void assembleSemanticsNode(Iterable<SemanticsNode> children, SemanticsConfiguration config, SemanticsNode node);

    void clearSemantics();

private:
    ScrollPosition _position;

    bool _allowImplicitScrolling;

    int _semanticChildCount;

    SemanticsNode _innerNode;


     _RenderScrollSemantics(bool allowImplicitScrolling, RenderBox child, ScrollPosition position, int semanticChildCount);

};

enum ScrollIncrementType{
    line,
    page,
} // end ScrollIncrementType

class ScrollIncrementDetails {
public:
    ScrollIncrementType type;

    ScrollMetrics metrics;


     ScrollIncrementDetails(ScrollMetrics metrics, ScrollIncrementType type);

private:

};

class ScrollIntent : Intent {
public:
    AxisDirection direction;

    ScrollIncrementType type;


     ScrollIntent(AxisDirection direction, ScrollIncrementType type);

private:

};

class ScrollAction : Action<ScrollIntent> {
public:

    bool isEnabled(ScrollIntent intent);

    void invoke(ScrollIntent intent);

private:

    double _calculateScrollIncrement(ScrollableState state, ScrollIncrementType type);

    double _getIncrement(ScrollIntent intent, ScrollableState state);

};

class _RestorableScrollOffset : RestorableValue<double> {
public:

    double createDefaultValue();

    void didUpdateValue(double oldValue);

    double fromPrimitives(Object data);

    Object toPrimitives();

    bool enabled();

private:

};

#endif