#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_NESTED_SCROLL_VIEW
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_NESTED_SCROLL_VIEW
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "primary_scroll_controller.hpp"
#include "scroll_activity.hpp"
#include "scroll_configuration.hpp"
#include "scroll_context.hpp"
#include "scroll_controller.hpp"
#include "scroll_metrics.hpp"
#include "scroll_physics.hpp"
#include "scroll_position.hpp"
#include "scroll_view.hpp"
#include "sliver_fill.hpp"
#include "viewport.hpp"


class NestedScrollViewCls : public StatefulWidgetCls {
public:
    ScrollController controller;

    Axis scrollDirection;

    bool reverse;

    ScrollPhysics physics;

    NestedScrollViewHeaderSliversBuilder headerSliverBuilder;

    Widget body;

    DragStartBehavior dragStartBehavior;

    bool floatHeaderSlivers;

    Clip clipBehavior;

    String restorationId;

    ScrollBehavior scrollBehavior;


     NestedScrollViewCls(Widget body, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, bool floatHeaderSlivers, NestedScrollViewHeaderSliversBuilder headerSliverBuilder, Unknown key, ScrollPhysics physics, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection);

    static SliverOverlapAbsorberHandle sliverOverlapAbsorberHandleFor(BuildContext context);

    virtual NestedScrollViewState createState();

private:

    virtual List<Widget> _buildSlivers(bool bodyIsScrolled, BuildContext context, ScrollController innerController);

};
using NestedScrollView = std::shared_ptr<NestedScrollViewCls>;

class NestedScrollViewStateCls : public StateCls<NestedScrollView> {
public:

    virtual ScrollController innerController();

    virtual ScrollController outerController();

    virtual void initState();

    virtual void didChangeDependencies();

    virtual void didUpdateWidget(NestedScrollView oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    SliverOverlapAbsorberHandle _absorberHandle;

    _NestedScrollCoordinator _coordinator;

    bool _lastHasScrolledBody;


    virtual void _handleHasScrolledBodyChanged();

};
using NestedScrollViewState = std::shared_ptr<NestedScrollViewStateCls>;

class _NestedScrollViewCustomScrollViewCls : public CustomScrollViewCls {
public:
    SliverOverlapAbsorberHandle handle;


    virtual Widget buildViewport(AxisDirection axisDirection, BuildContext context, ViewportOffset offset, List<Widget> slivers);

private:

     _NestedScrollViewCustomScrollViewCls(Unknown clipBehavior, ScrollController controller, Unknown dragStartBehavior, SliverOverlapAbsorberHandle handle, ScrollPhysics physics, Unknown restorationId, Unknown reverse, ScrollBehavior scrollBehavior, Unknown scrollDirection, Unknown slivers);
};
using _NestedScrollViewCustomScrollView = std::shared_ptr<_NestedScrollViewCustomScrollViewCls>;

class _InheritedNestedScrollViewCls : public InheritedWidgetCls {
public:
    NestedScrollViewState state;


    virtual bool updateShouldNotify(_InheritedNestedScrollView old);

private:

     _InheritedNestedScrollViewCls(Unknown child, NestedScrollViewState state);

};
using _InheritedNestedScrollView = std::shared_ptr<_InheritedNestedScrollViewCls>;

class _NestedScrollMetricsCls : public FixedScrollMetricsCls {
public:
    double minRange;

    double maxRange;

    double correctionOffset;


    virtual _NestedScrollMetrics copyWith(AxisDirection axisDirection, double correctionOffset, double maxRange, double maxScrollExtent, double minRange, double minScrollExtent, double pixels, double viewportDimension);

private:

     _NestedScrollMetricsCls(Unknown axisDirection, double correctionOffset, double maxRange, Unknown maxScrollExtent, double minRange, Unknown minScrollExtent, Unknown pixels, Unknown viewportDimension);
};
using _NestedScrollMetrics = std::shared_ptr<_NestedScrollMetricsCls>;

class _NestedScrollCoordinatorCls : public ObjectCls {
public:

    virtual bool canScrollBody();

    virtual bool hasScrolledBody();

    virtual void updateShadow();

    virtual ScrollDirection userScrollDirection();

    virtual void updateUserScrollDirection(ScrollDirection value);

    virtual void beginActivity(_NestedScrollActivityGetter innerActivityGetter, ScrollActivity newOuterActivity);

    virtual AxisDirection axisDirection();

    virtual void goIdle();

    virtual void goBallistic(double velocity);

    virtual ScrollActivity createOuterBallisticScrollActivity(double velocity);

    virtual ScrollActivity createInnerBallisticScrollActivity(_NestedScrollPosition position, double velocity);

    virtual double unnestOffset(_NestedScrollPosition source, double value);

    virtual double nestOffset(_NestedScrollPosition target, double value);

    virtual void updateCanDrag();

    virtual Future<void> animateTo(Curve curve, Duration duration, double to);

    virtual void jumpTo(double to);

    virtual void pointerScroll(double delta);

    virtual double setPixels(double newPixels);

    virtual ScrollHoldController hold(VoidCallback holdCancelCallback);

    virtual void cancel();

    virtual Drag drag(DragStartDetails details, VoidCallback dragCancelCallback);

    virtual void applyUserOffset(double delta);

    virtual void setParent(ScrollController value);

    virtual void updateParent();

    virtual void dispose();

    virtual String toString();

private:
    NestedScrollViewState _state;

    ScrollController _parent;

    VoidCallback _onHasScrolledBodyChanged;

    bool _floatHeaderSlivers;

    _NestedScrollController _outerController;

    _NestedScrollController _innerController;

    ScrollDirection _userScrollDirection;

    ScrollDragController _currentDrag;


     _NestedScrollCoordinatorCls(bool _floatHeaderSlivers, VoidCallback _onHasScrolledBodyChanged, ScrollController _parent, NestedScrollViewState _state);

    virtual _NestedScrollPosition _outerPosition();

    virtual Iterable<_NestedScrollPosition> _innerPositions();

    static IdleScrollActivity _createIdleScrollActivity(_NestedScrollPosition position);

    virtual _NestedScrollMetrics _getMetrics(_NestedScrollPosition innerPosition, double velocity);

};
using _NestedScrollCoordinator = std::shared_ptr<_NestedScrollCoordinatorCls>;

class _NestedScrollControllerCls : public ScrollControllerCls {
public:
    _NestedScrollCoordinator coordinator;


    virtual ScrollPosition createScrollPosition(ScrollContext context, ScrollPosition oldPosition, ScrollPhysics physics);

    virtual void attach(ScrollPosition position);

    virtual void detach(ScrollPosition position);

    virtual Iterable<_NestedScrollPosition> nestedPositions();

private:

     _NestedScrollControllerCls(_NestedScrollCoordinator coordinator, Unknown debugLabel, Unknown initialScrollOffset);
    virtual void _scheduleUpdateShadow();

};
using _NestedScrollController = std::shared_ptr<_NestedScrollControllerCls>;

class _NestedScrollPositionCls : public ScrollPositionCls {
public:
    _NestedScrollCoordinator coordinator;


    virtual TickerProvider vsync();

    virtual void setParent(ScrollController value);

    virtual AxisDirection axisDirection();

    virtual void absorb(ScrollPosition other);

    virtual void restoreScrollOffset();

    virtual double applyClampedDragUpdate(double delta);

    virtual double applyFullDragUpdate(double delta);

    virtual double applyClampedPointerSignalUpdate(double delta);

    virtual ScrollDirection userScrollDirection();

    virtual DrivenScrollActivity createDrivenScrollActivity(Curve curve, Duration duration, double to);

    virtual double applyUserOffset(double delta);

    virtual void goIdle();

    virtual void goBallistic(double velocity);

    virtual ScrollActivity createBallisticScrollActivity(_NestedScrollMetrics metrics, _NestedBallisticScrollActivityMode mode, Simulation simulation);

    virtual Future<void> animateTo(Curve curve, Duration duration, double to);

    virtual void jumpTo(double value);

    virtual void pointerScroll(double delta);

    virtual void jumpToWithoutSettling(double value);

    virtual void localJumpTo(double value);

    virtual void applyNewDimensions();

    virtual void updateCanDrag(double totalExtent);

    virtual ScrollHoldController hold(VoidCallback holdCancelCallback);

    virtual Drag drag(DragStartDetails details, VoidCallback dragCancelCallback);

private:
    ScrollController _parent;


     _NestedScrollPositionCls(Unknown context, _NestedScrollCoordinator coordinator, Unknown debugLabel, double initialPixels, Unknown oldPosition, Unknown physics);

};
using _NestedScrollPosition = std::shared_ptr<_NestedScrollPositionCls>;

enum _NestedBallisticScrollActivityMode{
    outer,
    inner,
    independent,
} // end _NestedBallisticScrollActivityMode

class _NestedInnerBallisticScrollActivityCls : public BallisticScrollActivityCls {
public:
    _NestedScrollCoordinator coordinator;


    virtual _NestedScrollPosition delegate();

    virtual void resetActivity();

    virtual void applyNewDimensions();

    virtual bool applyMoveTo(double value);

private:

     _NestedInnerBallisticScrollActivityCls(_NestedScrollCoordinator coordinator, _NestedScrollPosition position, Simulation simulation, TickerProvider vsync);

};
using _NestedInnerBallisticScrollActivity = std::shared_ptr<_NestedInnerBallisticScrollActivityCls>;

class _NestedOuterBallisticScrollActivityCls : public BallisticScrollActivityCls {
public:
    _NestedScrollCoordinator coordinator;

    _NestedScrollMetrics metrics;


    virtual _NestedScrollPosition delegate();

    virtual void resetActivity();

    virtual void applyNewDimensions();

    virtual bool applyMoveTo(double value);

    virtual String toString();

private:

     _NestedOuterBallisticScrollActivityCls(_NestedScrollCoordinator coordinator, _NestedScrollMetrics metrics, _NestedScrollPosition position, Simulation simulation, TickerProvider vsync);

};
using _NestedOuterBallisticScrollActivity = std::shared_ptr<_NestedOuterBallisticScrollActivityCls>;

class SliverOverlapAbsorberHandleCls : public ChangeNotifierCls {
public:

    virtual double layoutExtent();

    virtual double scrollExtent();

    virtual String toString();

private:
    int _writers;

    double _layoutExtent;

    double _scrollExtent;


    virtual void _setExtents(double layoutValue, double scrollValue);

    virtual void _markNeedsLayout();

};
using SliverOverlapAbsorberHandle = std::shared_ptr<SliverOverlapAbsorberHandleCls>;

class SliverOverlapAbsorberCls : public SingleChildRenderObjectWidgetCls {
public:
    SliverOverlapAbsorberHandle handle;


     SliverOverlapAbsorberCls(SliverOverlapAbsorberHandle handle, Unknown key, Widget sliver);

    virtual RenderSliverOverlapAbsorber createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderSliverOverlapAbsorber renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using SliverOverlapAbsorber = std::shared_ptr<SliverOverlapAbsorberCls>;

class RenderSliverOverlapAbsorberCls : public RenderSliverCls {
public:

     RenderSliverOverlapAbsorberCls(SliverOverlapAbsorberHandle handle, RenderSliver sliver);

    virtual SliverOverlapAbsorberHandle handle();

    virtual void  handle(SliverOverlapAbsorberHandle value);

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual void performLayout();

    virtual void applyPaintTransform(RenderObject child, Matrix4 transform);

    virtual bool hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    SliverOverlapAbsorberHandle _handle;


};
using RenderSliverOverlapAbsorber = std::shared_ptr<RenderSliverOverlapAbsorberCls>;

class SliverOverlapInjectorCls : public SingleChildRenderObjectWidgetCls {
public:
    SliverOverlapAbsorberHandle handle;


     SliverOverlapInjectorCls(SliverOverlapAbsorberHandle handle, Unknown key, Widget sliver);

    virtual RenderSliverOverlapInjector createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderSliverOverlapInjector renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using SliverOverlapInjector = std::shared_ptr<SliverOverlapInjectorCls>;

class RenderSliverOverlapInjectorCls : public RenderSliverCls {
public:

     RenderSliverOverlapInjectorCls(SliverOverlapAbsorberHandle handle);

    virtual SliverOverlapAbsorberHandle handle();

    virtual void  handle(SliverOverlapAbsorberHandle value);

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual void performLayout();

    virtual void debugPaint(PaintingContext context, Offset offset);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _currentLayoutExtent;

    double _currentMaxExtent;

    SliverOverlapAbsorberHandle _handle;


};
using RenderSliverOverlapInjector = std::shared_ptr<RenderSliverOverlapInjectorCls>;

class NestedScrollViewViewportCls : public ViewportCls {
public:
    SliverOverlapAbsorberHandle handle;


     NestedScrollViewViewportCls(Unknown anchor, Unknown axisDirection, Unknown center, Unknown clipBehavior, Unknown crossAxisDirection, SliverOverlapAbsorberHandle handle, Unknown key, Unknown offset, Unknown slivers);

    virtual RenderNestedScrollViewViewport createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderNestedScrollViewViewport renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using NestedScrollViewViewport = std::shared_ptr<NestedScrollViewViewportCls>;

class RenderNestedScrollViewViewportCls : public RenderViewportCls {
public:

     RenderNestedScrollViewViewportCls(Unknown anchor, Unknown axisDirection, Unknown center, Unknown children, Unknown clipBehavior, Unknown crossAxisDirection, SliverOverlapAbsorberHandle handle, Unknown offset);

    virtual SliverOverlapAbsorberHandle handle();

    virtual void  handle(SliverOverlapAbsorberHandle value);

    virtual void markNeedsLayout();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    SliverOverlapAbsorberHandle _handle;


};
using RenderNestedScrollViewViewport = std::shared_ptr<RenderNestedScrollViewViewportCls>;


#endif