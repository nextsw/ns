#ifndef NESTED_SCROLL_VIEW_H
#define NESTED_SCROLL_VIEW_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include <flutter/scheduler.hpp>
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



class NestedScrollView : StatefulWidget {
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


     NestedScrollView(Widget body, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, bool floatHeaderSlivers, NestedScrollViewHeaderSliversBuilder headerSliverBuilder, Unknown, ScrollPhysics physics, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection);

    static SliverOverlapAbsorberHandle sliverOverlapAbsorberHandleFor(BuildContext context);

    NestedScrollViewState createState();

private:

    List<Widget> _buildSlivers(bool bodyIsScrolled, BuildContext context, ScrollController innerController);

};

class NestedScrollViewState : State<NestedScrollView> {
public:

    ScrollController innerController();

    ScrollController outerController();

    void initState();

    void didChangeDependencies();

    void didUpdateWidget(NestedScrollView oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:
    SliverOverlapAbsorberHandle _absorberHandle;

    _NestedScrollCoordinator _coordinator;

    bool _lastHasScrolledBody;


    void _handleHasScrolledBodyChanged();

};

class _NestedScrollViewCustomScrollView : CustomScrollView {
public:
    SliverOverlapAbsorberHandle handle;


    Widget buildViewport(AxisDirection axisDirection, BuildContext context, ViewportOffset offset, List<Widget> slivers);

private:

     _NestedScrollViewCustomScrollView(Unknown, ScrollController controller, Unknown, SliverOverlapAbsorberHandle handle, ScrollPhysics physics, Unknown, Unknown, ScrollBehavior scrollBehavior, Unknown, Unknown);

};

class _InheritedNestedScrollView : InheritedWidget {
public:
    NestedScrollViewState state;


    bool updateShouldNotify(_InheritedNestedScrollView old);

private:

     _InheritedNestedScrollView(Unknown, NestedScrollViewState state);

};

class _NestedScrollMetrics : FixedScrollMetrics {
public:
    double minRange;

    double maxRange;

    double correctionOffset;


    _NestedScrollMetrics copyWith(AxisDirection axisDirection, double correctionOffset, double maxRange, double maxScrollExtent, double minRange, double minScrollExtent, double pixels, double viewportDimension);

private:

     _NestedScrollMetrics(Unknown, double correctionOffset, double maxRange, Unknown, double minRange, Unknown, Unknown, Unknown);

};

class _NestedScrollCoordinator {
public:

    bool canScrollBody();

    bool hasScrolledBody();

    void updateShadow();

    ScrollDirection userScrollDirection();

    void updateUserScrollDirection(ScrollDirection value);

    void beginActivity(_NestedScrollActivityGetter innerActivityGetter, ScrollActivity newOuterActivity);

    AxisDirection axisDirection();

    void goIdle();

    void goBallistic(double velocity);

    ScrollActivity createOuterBallisticScrollActivity(double velocity);

    ScrollActivity createInnerBallisticScrollActivity(_NestedScrollPosition position, double velocity);

    double unnestOffset(_NestedScrollPosition source, double value);

    double nestOffset(_NestedScrollPosition target, double value);

    void updateCanDrag();

    Future<void> animateTo(Curve curve, Duration duration, double to);

    void jumpTo(double to);

    void pointerScroll(double delta);

    double setPixels(double newPixels);

    ScrollHoldController hold(VoidCallback holdCancelCallback);

    void cancel();

    Drag drag(DragStartDetails details, VoidCallback dragCancelCallback);

    void applyUserOffset(double delta);

    void setParent(ScrollController value);

    void updateParent();

    void dispose();

    String toString();

private:
    NestedScrollViewState _state;

    ScrollController _parent;

    VoidCallback _onHasScrolledBodyChanged;

    bool _floatHeaderSlivers;

    _NestedScrollController _outerController;

    _NestedScrollController _innerController;

    ScrollDirection _userScrollDirection;

    ScrollDragController _currentDrag;


     _NestedScrollCoordinator(bool _floatHeaderSlivers, VoidCallback _onHasScrolledBodyChanged, ScrollController _parent, NestedScrollViewState _state);

    _NestedScrollPosition _outerPosition();

    Iterable<_NestedScrollPosition> _innerPositions();

    static IdleScrollActivity _createIdleScrollActivity(_NestedScrollPosition position);

    _NestedScrollMetrics _getMetrics(_NestedScrollPosition innerPosition, double velocity);

};

class _NestedScrollController : ScrollController {
public:
    _NestedScrollCoordinator coordinator;


    ScrollPosition createScrollPosition(ScrollContext context, ScrollPosition oldPosition, ScrollPhysics physics);

    void attach(ScrollPosition position);

    void detach(ScrollPosition position);

    Iterable<_NestedScrollPosition> nestedPositions();

private:

     _NestedScrollController(_NestedScrollCoordinator coordinator, Unknown, Unknown);

    void _scheduleUpdateShadow();

};

class _NestedScrollPosition : ScrollPosition {
public:
    _NestedScrollCoordinator coordinator;


    TickerProvider vsync();

    void setParent(ScrollController value);

    AxisDirection axisDirection();

    void absorb(ScrollPosition other);

    void restoreScrollOffset();

    double applyClampedDragUpdate(double delta);

    double applyFullDragUpdate(double delta);

    double applyClampedPointerSignalUpdate(double delta);

    ScrollDirection userScrollDirection();

    DrivenScrollActivity createDrivenScrollActivity(Curve curve, Duration duration, double to);

    double applyUserOffset(double delta);

    void goIdle();

    void goBallistic(double velocity);

    ScrollActivity createBallisticScrollActivity(_NestedScrollMetrics metrics, _NestedBallisticScrollActivityMode mode, Simulation simulation);

    Future<void> animateTo(Curve curve, Duration duration, double to);

    void jumpTo(double value);

    void pointerScroll(double delta);

    void jumpToWithoutSettling(double value);

    void localJumpTo(double value);

    void applyNewDimensions();

    void updateCanDrag(double totalExtent);

    ScrollHoldController hold(VoidCallback holdCancelCallback);

    Drag drag(DragStartDetails details, VoidCallback dragCancelCallback);

private:
    ScrollController _parent;


     _NestedScrollPosition(Unknown, _NestedScrollCoordinator coordinator, Unknown, double initialPixels, Unknown, Unknown);

};

enum _NestedBallisticScrollActivityMode{
    outer,
    inner,
    independent,
} // end _NestedBallisticScrollActivityMode

class _NestedInnerBallisticScrollActivity : BallisticScrollActivity {
public:
    _NestedScrollCoordinator coordinator;


    _NestedScrollPosition delegate();

    void resetActivity();

    void applyNewDimensions();

    bool applyMoveTo(double value);

private:

     _NestedInnerBallisticScrollActivity(_NestedScrollCoordinator coordinator, _NestedScrollPosition position, Simulation simulation, TickerProvider vsync);

};

class _NestedOuterBallisticScrollActivity : BallisticScrollActivity {
public:
    _NestedScrollCoordinator coordinator;

    _NestedScrollMetrics metrics;


    _NestedScrollPosition delegate();

    void resetActivity();

    void applyNewDimensions();

    bool applyMoveTo(double value);

    String toString();

private:

     _NestedOuterBallisticScrollActivity(_NestedScrollCoordinator coordinator, _NestedScrollMetrics metrics, _NestedScrollPosition position, Simulation simulation, TickerProvider vsync);

};

class SliverOverlapAbsorberHandle : ChangeNotifier {
public:

    double layoutExtent();

    double scrollExtent();

    String toString();

private:
    int _writers;

    double _layoutExtent;

    double _scrollExtent;


    void _setExtents(double layoutValue, double scrollValue);

    void _markNeedsLayout();

};

class SliverOverlapAbsorber : SingleChildRenderObjectWidget {
public:
    SliverOverlapAbsorberHandle handle;


     SliverOverlapAbsorber(SliverOverlapAbsorberHandle handle, Unknown, Widget sliver);

    RenderSliverOverlapAbsorber createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderSliverOverlapAbsorber renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class RenderSliverOverlapAbsorber : RenderSliver {
public:

     RenderSliverOverlapAbsorber(SliverOverlapAbsorberHandle handle, RenderSliver sliver);

    SliverOverlapAbsorberHandle handle();

    void  handle(SliverOverlapAbsorberHandle value);

    void attach(PipelineOwner owner);

    void detach();

    void performLayout();

    void applyPaintTransform(RenderObject child, Matrix4 transform);

    bool hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result);

    void paint(PaintingContext context, Offset offset);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    SliverOverlapAbsorberHandle _handle;


};

class SliverOverlapInjector : SingleChildRenderObjectWidget {
public:
    SliverOverlapAbsorberHandle handle;


     SliverOverlapInjector(SliverOverlapAbsorberHandle handle, Unknown, Widget sliver);

    RenderSliverOverlapInjector createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderSliverOverlapInjector renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class RenderSliverOverlapInjector : RenderSliver {
public:

     RenderSliverOverlapInjector(SliverOverlapAbsorberHandle handle);

    SliverOverlapAbsorberHandle handle();

    void  handle(SliverOverlapAbsorberHandle value);

    void attach(PipelineOwner owner);

    void detach();

    void performLayout();

    void debugPaint(PaintingContext context, Offset offset);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _currentLayoutExtent;

    double _currentMaxExtent;

    SliverOverlapAbsorberHandle _handle;


};

class NestedScrollViewViewport : Viewport {
public:
    SliverOverlapAbsorberHandle handle;


     NestedScrollViewViewport(Unknown, Unknown, Unknown, Unknown, Unknown, SliverOverlapAbsorberHandle handle, Unknown, Unknown, Unknown);

    RenderNestedScrollViewViewport createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderNestedScrollViewViewport renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class RenderNestedScrollViewViewport : RenderViewport {
public:

     RenderNestedScrollViewViewport(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, SliverOverlapAbsorberHandle handle, Unknown);

    SliverOverlapAbsorberHandle handle();

    void  handle(SliverOverlapAbsorberHandle value);

    void markNeedsLayout();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    SliverOverlapAbsorberHandle _handle;


};

#endif