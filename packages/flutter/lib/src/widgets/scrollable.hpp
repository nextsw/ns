#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLLABLE
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLLABLE
#include <base.hpp>
#include <packages/flutter/flutter.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
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


class ScrollableCls : public StatefulWidgetCls {
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


     ScrollableCls(AxisDirection axisDirection, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, bool excludeFromSemantics, ScrollIncrementCalculator incrementCalculator, Unknown key, ScrollPhysics physics, String restorationId, ScrollBehavior scrollBehavior, int semanticChildCount, ViewportBuilder viewportBuilder);

    virtual Axis axis();

    virtual ScrollableState createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    static ScrollableState of(BuildContext context);

    static bool recommendDeferredLoadingForContext(BuildContext context);

    static Future<void> ensureVisible(double alignment, ScrollPositionAlignmentPolicy alignmentPolicy, BuildContext context, Curve curve, Duration duration);

private:

};
using Scrollable = std::shared_ptr<ScrollableCls>;

class _ScrollableScopeCls : public InheritedWidgetCls {
public:
    ScrollableState scrollable;

    ScrollPosition position;


    virtual bool updateShouldNotify(_ScrollableScope old);

private:

     _ScrollableScopeCls(Unknown child, ScrollPosition position, ScrollableState scrollable);

};
using _ScrollableScope = std::shared_ptr<_ScrollableScopeCls>;

class ScrollableStateCls : public StateCls<Scrollable> {
public:

    virtual ScrollPosition position();

    virtual AxisDirection axisDirection();

    virtual void restoreState(bool initialRestore, RestorationBucket oldBucket);

    virtual void saveOffset(double offset);

    virtual void initState();

    virtual void didChangeDependencies();

    virtual void didUpdateWidget(Scrollable oldWidget);

    virtual void dispose();

    virtual void setSemanticsActions(Set<SemanticsAction> actions);

    virtual void setCanDrag(bool value);

    virtual TickerProvider vsync();

    virtual void setIgnorePointer(bool value);

    virtual BuildContext notificationContext();

    virtual BuildContext storageContext();

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual String restorationId();

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


    virtual ScrollController _effectiveScrollController();

    virtual void _updatePosition();

    virtual bool _shouldUpdatePosition(Scrollable oldWidget);

    virtual void _handleDragDown(DragDownDetails details);

    virtual void _handleDragStart(DragStartDetails details);

    virtual void _handleDragUpdate(DragUpdateDetails details);

    virtual void _handleDragEnd(DragEndDetails details);

    virtual void _handleDragCancel();

    virtual void _disposeHold();

    virtual void _disposeDrag();

    virtual double _targetScrollOffsetForPointerScroll(double delta);

    virtual double _pointerSignalEventDelta(PointerScrollEvent event);

    virtual void _receivedPointerSignal(PointerSignalEvent event);

    virtual void _handlePointerScroll(PointerEvent event);

    virtual bool _handleScrollMetricsNotification(ScrollMetricsNotification notification);

};
using ScrollableState = std::shared_ptr<ScrollableStateCls>;

class _ScrollableSelectionHandlerCls : public StatefulWidgetCls {
public:
    ScrollableState state;

    ScrollPosition position;

    Widget child;

    SelectionRegistrar registrar;


    virtual _ScrollableSelectionHandlerState createState();

private:

     _ScrollableSelectionHandlerCls(Widget child, ScrollPosition position, SelectionRegistrar registrar, ScrollableState state);
};
using _ScrollableSelectionHandler = std::shared_ptr<_ScrollableSelectionHandlerCls>;

class _ScrollableSelectionHandlerStateCls : public StateCls<_ScrollableSelectionHandler> {
public:

    virtual void initState();

    virtual void didUpdateWidget(_ScrollableSelectionHandler oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    _ScrollableSelectionContainerDelegate _selectionDelegate;


};
using _ScrollableSelectionHandlerState = std::shared_ptr<_ScrollableSelectionHandlerStateCls>;

class EdgeDraggingAutoScrollerCls : public ObjectCls {
public:
    ScrollableState scrollable;

    VoidCallback onScrollViewScrolled;

    double velocityScalar;


     EdgeDraggingAutoScrollerCls(VoidCallback onScrollViewScrolled, ScrollableState scrollable, double velocityScalar);
    virtual bool scrolling();

    virtual void startAutoScrollIfNecessary(Rect dragTarget);

    virtual void stopAutoScroll();

private:
    static double _kDefaultAutoScrollVelocityScalar;

    Rect _dragTargetRelatedToScrollOrigin;

    bool _scrolling;


    virtual double _offsetExtent(Offset offset, Axis scrollDirection);

    virtual double _sizeExtent(Axis scrollDirection, Size size);

    virtual AxisDirection _axisDirection();

    virtual Axis _scrollDirection();

    virtual Future<void> _scroll();

};
using EdgeDraggingAutoScroller = std::shared_ptr<EdgeDraggingAutoScrollerCls>;

class _ScrollableSelectionContainerDelegateCls : public MultiSelectableSelectionContainerDelegateCls {
public:
    ScrollableState state;


    virtual ScrollPosition position();

    virtual void  position(ScrollPosition other);

    virtual void didChangeSelectables();

    virtual SelectionResult handleClearSelection(ClearSelectionEvent event);

    virtual SelectionResult handleSelectionEdgeUpdate(SelectionEdgeUpdateEvent event);

    virtual SelectionResult handleSelectAll(SelectAllSelectionEvent event);

    virtual SelectionResult handleSelectWord(SelectWordSelectionEvent event);

    virtual SelectionResult dispatchSelectionEventToChild(SelectionEvent event, Selectable selectable);

    virtual void ensureChildUpdated(Selectable selectable);

    virtual void dispose();

private:
    static double _kDefaultDragTargetSize;

    static double _kDefaultSelectToScrollVelocityScalar;

    EdgeDraggingAutoScroller _autoScroller;

    bool _scheduledLayoutChange;

    Offset _currentDragStartRelatedToOrigin;

    Offset _currentDragEndRelatedToOrigin;

    bool _selectionStartsInScrollable;

    ScrollPosition _position;

    Map<Selectable, double> _selectableStartEdgeUpdateRecords;

    Map<Selectable, double> _selectableEndEdgeUpdateRecords;


     _ScrollableSelectionContainerDelegateCls(ScrollPosition position, ScrollableState state);

    virtual void _scheduleLayoutChange();

    virtual Offset _inferPositionRelatedToOrigin(Offset globalPosition);

    virtual void _updateDragLocationsFromGeometries();

    virtual bool _globalPositionInScrollable(Offset globalPosition);

    virtual Rect _dragTargetFromEvent(SelectionEdgeUpdateEvent event);

};
using _ScrollableSelectionContainerDelegate = std::shared_ptr<_ScrollableSelectionContainerDelegateCls>;
Offset _getDeltaToScrollOrigin(ScrollableState scrollableState);


class ScrollableDetailsCls : public ObjectCls {
public:
    AxisDirection direction;

    ScrollController controller;

    Clip clipBehavior;


     ScrollableDetailsCls(Clip clipBehavior, ScrollController controller, AxisDirection direction);
private:

};
using ScrollableDetails = std::shared_ptr<ScrollableDetailsCls>;

class _ScrollSemanticsCls : public SingleChildRenderObjectWidgetCls {
public:
    ScrollPosition position;

    bool allowImplicitScrolling;

    int semanticChildCount;


    virtual _RenderScrollSemantics createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, _RenderScrollSemantics renderObject);

private:

     _ScrollSemanticsCls(bool allowImplicitScrolling, Unknown child, Unknown key, ScrollPosition position, int semanticChildCount);

};
using _ScrollSemantics = std::shared_ptr<_ScrollSemanticsCls>;

class _RenderScrollSemanticsCls : public RenderProxyBoxCls {
public:

    virtual ScrollPosition position();

    virtual void  position(ScrollPosition value);

    virtual bool allowImplicitScrolling();

    virtual void  allowImplicitScrolling(bool value);

    virtual int semanticChildCount();

    virtual void  semanticChildCount(int value);

    virtual void describeSemanticsConfiguration(SemanticsConfiguration config);

    virtual void assembleSemanticsNode(Iterable<SemanticsNode> children, SemanticsConfiguration config, SemanticsNode node);

    virtual void clearSemantics();

private:
    ScrollPosition _position;

    bool _allowImplicitScrolling;

    int _semanticChildCount;

    SemanticsNode _innerNode;


     _RenderScrollSemanticsCls(bool allowImplicitScrolling, RenderBox child, ScrollPosition position, int semanticChildCount);

};
using _RenderScrollSemantics = std::shared_ptr<_RenderScrollSemanticsCls>;

enum ScrollIncrementType{
    line,
    page,
} // end ScrollIncrementType

class ScrollIncrementDetailsCls : public ObjectCls {
public:
    ScrollIncrementType type;

    ScrollMetrics metrics;


     ScrollIncrementDetailsCls(ScrollMetrics metrics, ScrollIncrementType type);

private:

};
using ScrollIncrementDetails = std::shared_ptr<ScrollIncrementDetailsCls>;

class ScrollIntentCls : public IntentCls {
public:
    AxisDirection direction;

    ScrollIncrementType type;


     ScrollIntentCls(AxisDirection direction, ScrollIncrementType type);

private:

};
using ScrollIntent = std::shared_ptr<ScrollIntentCls>;

class ScrollActionCls : public ActionCls<ScrollIntent> {
public:

    virtual bool isEnabled(ScrollIntent intent);

    virtual void invoke(ScrollIntent intent);

private:

    virtual double _calculateScrollIncrement(ScrollableState state, ScrollIncrementType type);

    virtual double _getIncrement(ScrollIntent intent, ScrollableState state);

};
using ScrollAction = std::shared_ptr<ScrollActionCls>;

class _RestorableScrollOffsetCls : public RestorableValueCls<double> {
public:

    virtual double createDefaultValue();

    virtual void didUpdateValue(double oldValue);

    virtual double fromPrimitives(Object data);

    virtual Object toPrimitives();

    virtual bool enabled();

private:

};
using _RestorableScrollOffset = std::shared_ptr<_RestorableScrollOffsetCls>;


#endif