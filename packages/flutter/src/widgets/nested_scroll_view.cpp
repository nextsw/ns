#include "nested_scroll_view.hpp"
NestedScrollView::NestedScrollView(Widget body, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, bool floatHeaderSlivers, NestedScrollViewHeaderSliversBuilder headerSliverBuilder, Unknown, ScrollPhysics physics, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection) {
    {
        assert(scrollDirection != nullptr);
        assert(reverse != nullptr);
        assert(headerSliverBuilder != nullptr);
        assert(body != nullptr);
        assert(floatHeaderSlivers != nullptr);
        assert(clipBehavior != nullptr);
    }
}

SliverOverlapAbsorberHandle NestedScrollView::sliverOverlapAbsorberHandleFor(BuildContext context) {
    _InheritedNestedScrollView target = context.<_InheritedNestedScrollView>dependOnInheritedWidgetOfExactType();
    assert(target != nullptr, "NestedScrollView.sliverOverlapAbsorberHandleFor must be called with a context that contains a NestedScrollView.");
    return target!.state._absorberHandle;
}

NestedScrollViewState NestedScrollView::createState() {
    return NestedScrollViewState();
}

List<Widget> NestedScrollView::_buildSlivers(bool bodyIsScrolled, BuildContext context, ScrollController innerController) {
    return ;
}

ScrollController NestedScrollViewState::innerController() {
    return _coordinator!._innerController;
}

ScrollController NestedScrollViewState::outerController() {
    return _coordinator!._outerController;
}

void NestedScrollViewState::initState() {
    super.initState();
    _coordinator = _NestedScrollCoordinator(this, widget.controller, _handleHasScrolledBodyChanged, widget.floatHeaderSlivers);
}

void NestedScrollViewState::didChangeDependencies() {
    super.didChangeDependencies();
    _coordinator!.setParent(widget.controller);
}

void NestedScrollViewState::didUpdateWidget(NestedScrollView oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (oldWidget.controller != widget.controller) {
        _coordinator!.setParent(widget.controller);
    }
}

void NestedScrollViewState::dispose() {
    _coordinator!.dispose();
    _coordinator = nullptr;
    super.dispose();
}

Widget NestedScrollViewState::build(BuildContext context) {
    ScrollPhysics scrollPhysics = widget.physics?.applyTo(const ClampingScrollPhysics()) ?? widget.scrollBehavior?.getScrollPhysics(context).applyTo(const ClampingScrollPhysics()) ?? const ClampingScrollPhysics();
    return _InheritedNestedScrollView(this, Builder());
}

void NestedScrollViewState::_handleHasScrolledBodyChanged() {
    if (!mounted) {
        return;
    }
    bool newHasScrolledBody = _coordinator!.hasScrolledBody;
    if (_lastHasScrolledBody != newHasScrolledBody) {
        setState();
    }
}

Widget _NestedScrollViewCustomScrollView::buildViewport(AxisDirection axisDirection, BuildContext context, ViewportOffset offset, List<Widget> slivers) {
    assert(!shrinkWrap);
    return NestedScrollViewViewport(axisDirection, offset, slivers, handle, clipBehavior);
}

bool _InheritedNestedScrollView::updateShouldNotify(_InheritedNestedScrollView old) {
    return state != old.state;
}

_InheritedNestedScrollView::_InheritedNestedScrollView(Unknown, NestedScrollViewState state) {
    {
        assert(state != nullptr);
        assert(child != nullptr);
    }
}

_NestedScrollMetrics _NestedScrollMetrics::copyWith(AxisDirection axisDirection, double correctionOffset, double maxRange, double maxScrollExtent, double minRange, double minScrollExtent, double pixels, double viewportDimension) {
    return _NestedScrollMetrics(minScrollExtent ?? (hasContentDimensions? this.minScrollExtent : nullptr), maxScrollExtent ?? (hasContentDimensions? this.maxScrollExtent : nullptr), pixels ?? (hasPixels? this.pixels : nullptr), viewportDimension ?? (hasViewportDimension? this.viewportDimension : nullptr), axisDirection ?? this.axisDirection, minRange ?? this.minRange, maxRange ?? this.maxRange, correctionOffset ?? this.correctionOffset);
}

bool _NestedScrollCoordinator::canScrollBody() {
    _NestedScrollPosition outer = _outerPosition;
    if (outer == nullptr) {
        return true;
    }
    return outer.haveDimensions && outer.extentAfter == 0.0;
}

bool _NestedScrollCoordinator::hasScrolledBody() {
    for (_NestedScrollPosition position : _innerPositions) {
        if (!position.hasContentDimensions || !position.hasPixels) {
            continue;
        } else         {
            if (position.pixels > position.minScrollExtent) {
            return true;
        }
;
        }    }
    return false;
}

void _NestedScrollCoordinator::updateShadow() {
    _onHasScrolledBodyChanged();
}

ScrollDirection _NestedScrollCoordinator::userScrollDirection() {
    return _userScrollDirection;
}

void _NestedScrollCoordinator::updateUserScrollDirection(ScrollDirection value) {
    assert(value != nullptr);
    if (userScrollDirection == value) {
        return;
    }
    _userScrollDirection = value;
    _outerPosition!.didUpdateScrollDirection(value);
    for (_NestedScrollPosition position : _innerPositions) {
        position.didUpdateScrollDirection(value);
    }
}

void _NestedScrollCoordinator::beginActivity(_NestedScrollActivityGetter innerActivityGetter, ScrollActivity newOuterActivity) {
    _outerPosition!.beginActivity(newOuterActivity);
    bool scrolling = newOuterActivity.isScrolling;
    for (_NestedScrollPosition position : _innerPositions) {
        ScrollActivity newInnerActivity = innerActivityGetter(position);
        position.beginActivity(newInnerActivity);
        scrolling = scrolling && newInnerActivity.isScrolling;
    }
    _currentDrag?.dispose();
    _currentDrag = nullptr;
    if (!scrolling) {
        updateUserScrollDirection(ScrollDirection.idle);
    }
}

AxisDirection _NestedScrollCoordinator::axisDirection() {
    return _outerPosition!.axisDirection;
}

void _NestedScrollCoordinator::goIdle() {
    beginActivity(_createIdleScrollActivity(_outerPosition!), _createIdleScrollActivity);
}

void _NestedScrollCoordinator::goBallistic(double velocity) {
    beginActivity(createOuterBallisticScrollActivity(velocity), );
}

ScrollActivity _NestedScrollCoordinator::createOuterBallisticScrollActivity(double velocity) {
    _NestedScrollPosition innerPosition;
    if (velocity != 0.0) {
        for (_NestedScrollPosition position : _innerPositions) {
            if (innerPosition != nullptr) {
                if (velocity > 0.0) {
                    if (innerPosition.pixels < position.pixels) {
                        continue;
                    }
                } else {
                    assert( < 0.0);
                    if (innerPosition.pixels > position.pixels) {
                        continue;
                    }
                }
            }
            innerPosition = position;
        }
    }
    if (innerPosition == nullptr) {
        return _outerPosition!.createBallisticScrollActivity(_outerPosition!.physics.createBallisticSimulation(_outerPosition!, velocity)_NestedBallisticScrollActivityMode.independent);
    }
    _NestedScrollMetrics metrics = _getMetrics(innerPosition, velocity);
    return _outerPosition!.createBallisticScrollActivity(_outerPosition!.physics.createBallisticSimulation(metrics, velocity)_NestedBallisticScrollActivityMode.outer, metrics);
}

ScrollActivity _NestedScrollCoordinator::createInnerBallisticScrollActivity(_NestedScrollPosition position, double velocity) {
    return position.createBallisticScrollActivity(position.physics.createBallisticSimulation(_getMetrics(position, velocity), velocity)_NestedBallisticScrollActivityMode.inner);
}

double _NestedScrollCoordinator::unnestOffset(_NestedScrollPosition source, double value) {
    if (source == _outerPosition) {
        return clampDouble(value, _outerPosition!.minScrollExtent, _outerPosition!.maxScrollExtent);
    }
    if ( < source.minScrollExtent) {
        return value - source.minScrollExtent + _outerPosition!.minScrollExtent;
    }
    return value - source.minScrollExtent + _outerPosition!.maxScrollExtent;
}

double _NestedScrollCoordinator::nestOffset(_NestedScrollPosition target, double value) {
    if (target == _outerPosition) {
        return clampDouble(value, _outerPosition!.minScrollExtent, _outerPosition!.maxScrollExtent);
    }
    if ( < _outerPosition!.minScrollExtent) {
        return value - _outerPosition!.minScrollExtent + target.minScrollExtent;
    }
    if (value > _outerPosition!.maxScrollExtent) {
        return value - _outerPosition!.maxScrollExtent + target.minScrollExtent;
    }
    return target.minScrollExtent;
}

void _NestedScrollCoordinator::updateCanDrag() {
    if (!_outerPosition!.haveDimensions) {
        return;
    }
    double maxInnerExtent = 0.0;
    for (_NestedScrollPosition position : _innerPositions) {
        if (!position.haveDimensions) {
            return;
        }
        maxInnerExtent = math.max(maxInnerExtent, position.maxScrollExtent - position.minScrollExtent);
    }
    _outerPosition!.updateCanDrag(maxInnerExtent);
}

Future<void> _NestedScrollCoordinator::animateTo(Curve curve, Duration duration, double to) {
    DrivenScrollActivity outerActivity = _outerPosition!.createDrivenScrollActivity(nestOffset(to, _outerPosition!), duration, curve);
    List<Future<void>> resultFutures = ;
    beginActivity(outerActivity, );
    await await Future.<void>wait(resultFutures);
}

void _NestedScrollCoordinator::jumpTo(double to) {
    goIdle();
    _outerPosition!.localJumpTo(nestOffset(to, _outerPosition!));
    for (_NestedScrollPosition position : _innerPositions) {
        position.localJumpTo(nestOffset(to, position));
    }
    goBallistic(0.0);
}

void _NestedScrollCoordinator::pointerScroll(double delta) {
    assert(delta != 0.0);
    goIdle();
    updateUserScrollDirection( < 0.0? ScrollDirection.forward : ScrollDirection.reverse);
    _outerPosition!.isScrollingNotifier.value = true;
    _outerPosition!.didStartScroll();
    for (_NestedScrollPosition position : _innerPositions) {
        position.isScrollingNotifier.value = true;
        position.didStartScroll();
    }
    if (_innerPositions.isEmpty) {
        _outerPosition!.applyClampedPointerSignalUpdate(delta);
    } else     {
        if (delta > 0.0) {
        double outerDelta = delta;
        for (_NestedScrollPosition position : _innerPositions) {
            if (position.pixels < 0.0) {
                double potentialOuterDelta = position.applyClampedPointerSignalUpdate(delta);
                outerDelta = math.max(outerDelta, potentialOuterDelta);
            }
        }
        if (outerDelta != 0.0) {
            double innerDelta = _outerPosition!.applyClampedPointerSignalUpdate(outerDelta);
            if (innerDelta != 0.0) {
                for (_NestedScrollPosition position : _innerPositions) {
                    position.applyClampedPointerSignalUpdate(innerDelta);
                }
            }
        }
    } else {
        double innerDelta = delta;
        if (_floatHeaderSlivers) {
            innerDelta = _outerPosition!.applyClampedPointerSignalUpdate(delta);
        }
        if (innerDelta != 0.0) {
            double outerDelta = 0.0;
            for (_NestedScrollPosition position : _innerPositions) {
                double overscroll = position.applyClampedPointerSignalUpdate(innerDelta);
                outerDelta = math.min(outerDelta, overscroll);
            }
            if (outerDelta != 0.0) {
                _outerPosition!.applyClampedPointerSignalUpdate(outerDelta);
            }
        }
    }
;
    }    _outerPosition!.didEndScroll();
    for (_NestedScrollPosition position : _innerPositions) {
        position.didEndScroll();
    }
    goBallistic(0.0);
}

double _NestedScrollCoordinator::setPixels(double newPixels) {
    assert(false);
    return 0.0;
}

ScrollHoldController _NestedScrollCoordinator::hold(VoidCallback holdCancelCallback) {
    beginActivity(HoldScrollActivity(_outerPosition!, holdCancelCallback), );
    return this;
}

void _NestedScrollCoordinator::cancel() {
    goBallistic(0.0);
}

Drag _NestedScrollCoordinator::drag(DragStartDetails details, VoidCallback dragCancelCallback) {
    ScrollDragController drag = ScrollDragController(this, details, dragCancelCallback);
    beginActivity(DragScrollActivity(_outerPosition!, drag), );
    assert(_currentDrag == nullptr);
    _currentDrag = drag;
    return drag;
}

void _NestedScrollCoordinator::applyUserOffset(double delta) {
    updateUserScrollDirection(delta > 0.0? ScrollDirection.forward : ScrollDirection.reverse);
    assert(delta != 0.0);
    if (_innerPositions.isEmpty) {
        _outerPosition!.applyFullDragUpdate(delta);
    } else     {
        if ( < 0.0) {
        double outerDelta = delta;
        for (_NestedScrollPosition position : _innerPositions) {
            if (position.pixels < 0.0) {
                double potentialOuterDelta = position.applyClampedDragUpdate(delta);
                outerDelta = math.max(outerDelta, potentialOuterDelta);
            }
        }
        if (outerDelta != 0.0) {
            double innerDelta = _outerPosition!.applyClampedDragUpdate(outerDelta);
            if (innerDelta != 0.0) {
                for (_NestedScrollPosition position : _innerPositions) {
                    position.applyFullDragUpdate(innerDelta);
                }
            }
        }
    } else {
        double innerDelta = delta;
        if (_floatHeaderSlivers) {
            innerDelta = _outerPosition!.applyClampedDragUpdate(delta);
        }
        if (innerDelta != 0.0) {
            double outerDelta = 0.0;
            List<double> overscrolls = ;
            List<_NestedScrollPosition> innerPositions = _innerPositions.toList();
            for (_NestedScrollPosition position : innerPositions) {
                double overscroll = position.applyClampedDragUpdate(innerDelta);
                outerDelta = math.max(outerDelta, overscroll);
                overscrolls.add(overscroll);
            }
            if (outerDelta != 0.0) {
                outerDelta = _outerPosition!.applyClampedDragUpdate(outerDelta);
            }
            for (;  < innerPositions.length; ++i) {
                double remainingDelta = overscrolls[i] - outerDelta;
                if (remainingDelta > 0.0) {
                    innerPositions[i].applyFullDragUpdate(remainingDelta);
                }
            }
        }
    }
;
    }}

void _NestedScrollCoordinator::setParent(ScrollController value) {
    _parent = value;
    updateParent();
}

void _NestedScrollCoordinator::updateParent() {
    _outerPosition?.setParent(_parent ?? PrimaryScrollController.of(_state.context));
}

void _NestedScrollCoordinator::dispose() {
    _currentDrag?.dispose();
    _currentDrag = nullptr;
    _outerController.dispose();
    _innerController.dispose();
}

String _NestedScrollCoordinator::toString() {
    return "${objectRuntimeType(this, '_NestedScrollCoordinator')}(outer=$_outerController; inner=$_innerController)";
}

_NestedScrollCoordinator::_NestedScrollCoordinator(bool _floatHeaderSlivers, VoidCallback _onHasScrolledBodyChanged, ScrollController _parent, NestedScrollViewState _state) {
    {
        double initialScrollOffset = _parent?.initialScrollOffset ?? 0.0;
        _outerController = _NestedScrollController(thisinitialScrollOffset, "outer");
        _innerController = _NestedScrollController(this"inner");
    }
}

_NestedScrollPosition _NestedScrollCoordinator::_outerPosition() {
    if (!_outerController.hasClients) {
        return nullptr;
    }
    return _outerController.nestedPositions.single;
}

Iterable<_NestedScrollPosition> _NestedScrollCoordinator::_innerPositions() {
    return _innerController.nestedPositions;
}

IdleScrollActivity _NestedScrollCoordinator::_createIdleScrollActivity(_NestedScrollPosition position) {
    return IdleScrollActivity(position);
}

_NestedScrollMetrics _NestedScrollCoordinator::_getMetrics(_NestedScrollPosition innerPosition, double velocity) {
    assert(innerPosition != nullptr);
    double pixels, minRange, maxRange, correctionOffset;
    double extra = 0.0;
    if (innerPosition.pixels == innerPosition.minScrollExtent) {
        pixels = clampDouble(_outerPosition!.pixels, _outerPosition!.minScrollExtent, _outerPosition!.maxScrollExtent);
        minRange = _outerPosition!.minScrollExtent;
        maxRange = _outerPosition!.maxScrollExtent;
        assert(minRange <= maxRange);
        correctionOffset = 0.0;
    } else {
        assert(innerPosition.pixels != innerPosition.minScrollExtent);
        if (innerPosition.pixels < innerPosition.minScrollExtent) {
            pixels = innerPosition.pixels - innerPosition.minScrollExtent + _outerPosition!.minScrollExtent;
        } else {
            assert(innerPosition.pixels > innerPosition.minScrollExtent);
            pixels = innerPosition.pixels - innerPosition.minScrollExtent + _outerPosition!.maxScrollExtent;
        }
        if ((velocity > 0.0) && (innerPosition.pixels > innerPosition.minScrollExtent)) {
            extra = _outerPosition!.maxScrollExtent - _outerPosition!.pixels;
            assert(extra >= 0.0);
            minRange = pixels;
            maxRange = pixels + extra;
            assert(minRange <= maxRange);
            correctionOffset = _outerPosition!.pixels - pixels;
        } else         {
            if (( < 0.0) && (innerPosition.pixels < innerPosition.minScrollExtent)) {
            extra = _outerPosition!.pixels - _outerPosition!.minScrollExtent;
            assert(extra >= 0.0);
            minRange = pixels - extra;
            maxRange = pixels;
            assert(minRange <= maxRange);
            correctionOffset = _outerPosition!.pixels - pixels;
        } else {
            if (velocity > 0.0) {
                extra = _outerPosition!.minScrollExtent - _outerPosition!.pixels;
            } else             {
                if ( < 0.0) {
                extra = _outerPosition!.pixels - (_outerPosition!.maxScrollExtent - _outerPosition!.minScrollExtent);
            }
;
            }            assert(extra <= 0.0);
            minRange = _outerPosition!.minScrollExtent;
            maxRange = _outerPosition!.maxScrollExtent + extra;
            assert(minRange <= maxRange);
            correctionOffset = 0.0;
        }
;
        }    }
    return _NestedScrollMetrics(_outerPosition!.minScrollExtent, _outerPosition!.maxScrollExtent + innerPosition.maxScrollExtent - innerPosition.minScrollExtent + extra, pixels, _outerPosition!.viewportDimension, _outerPosition!.axisDirection, minRange, maxRange, correctionOffset);
}

ScrollPosition _NestedScrollController::createScrollPosition(ScrollContext context, ScrollPosition oldPosition, ScrollPhysics physics) {
    return _NestedScrollPosition(coordinator, physics, context, initialScrollOffset, oldPosition, debugLabel);
}

void _NestedScrollController::attach(ScrollPosition position) {
    assert(position is _NestedScrollPosition);
    super.attach(position);
    coordinator.updateParent();
    coordinator.updateCanDrag();
    position.addListener(_scheduleUpdateShadow);
    _scheduleUpdateShadow();
}

void _NestedScrollController::detach(ScrollPosition position) {
    assert(position is _NestedScrollPosition);
    (().setParent(nullptr);
    position.removeListener(_scheduleUpdateShadow);
    super.detach(position);
    _scheduleUpdateShadow();
}

Iterable<_NestedScrollPosition> _NestedScrollController::nestedPositions() {
    return Iterable.<ScrollPosition, _NestedScrollPosition>castFrom(positions);
}

void _NestedScrollController::_scheduleUpdateShadow() {
    SchedulerBinding.instance.addPostFrameCallback();
}

TickerProvider _NestedScrollPosition::vsync() {
    return context.vsync;
}

void _NestedScrollPosition::setParent(ScrollController value) {
    _parent?.detach(this);
    _parent = value;
    _parent?.attach(this);
}

AxisDirection _NestedScrollPosition::axisDirection() {
    return context.axisDirection;
}

void _NestedScrollPosition::absorb(ScrollPosition other) {
    super.absorb(other);
    activity!.updateDelegate(this);
}

void _NestedScrollPosition::restoreScrollOffset() {
    if (coordinator.canScrollBody) {
        super.restoreScrollOffset();
    }
}

double _NestedScrollPosition::applyClampedDragUpdate(double delta) {
    assert(delta != 0.0);
    double min =  < 0.0? -double.infinity : math.min(minScrollExtent, pixels);
    double max = delta > 0.0? double.infinity :  < 0.0? 0.0 : math.max(maxScrollExtent, pixels);
    double oldPixels = pixels;
    double newPixels = clampDouble(pixels - delta, min, max);
    double clampedDelta = newPixels - pixels;
    if (clampedDelta == 0.0) {
        return delta;
    }
    double overscroll = physics.applyBoundaryConditions(this, newPixels);
    double actualNewPixels = newPixels - overscroll;
    double offset = actualNewPixels - oldPixels;
    if (offset != 0.0) {
        forcePixels(actualNewPixels);
        didUpdateScrollPositionBy(offset);
    }
    return delta + offset;
}

double _NestedScrollPosition::applyFullDragUpdate(double delta) {
    assert(delta != 0.0);
    double oldPixels = pixels;
    double newPixels = pixels - physics.applyPhysicsToUserOffset(this, delta);
    if (oldPixels == newPixels) {
        return 0.0;
    }
    double overscroll = physics.applyBoundaryConditions(this, newPixels);
    double actualNewPixels = newPixels - overscroll;
    if (actualNewPixels != oldPixels) {
        forcePixels(actualNewPixels);
        didUpdateScrollPositionBy(actualNewPixels - oldPixels);
    }
    if (overscroll != 0.0) {
        didOverscrollBy(overscroll);
        return overscroll;
    }
    return 0.0;
}

double _NestedScrollPosition::applyClampedPointerSignalUpdate(double delta) {
    assert(delta != 0.0);
    double min = delta > 0.0? -double.infinity : math.min(minScrollExtent, pixels);
    double max =  < 0.0? double.infinity : math.max(maxScrollExtent, pixels);
    double newPixels = clampDouble(pixels + delta, min, max);
    double clampedDelta = newPixels - pixels;
    if (clampedDelta == 0.0) {
        return delta;
    }
    forcePixels(newPixels);
    didUpdateScrollPositionBy(clampedDelta);
    return delta - clampedDelta;
}

ScrollDirection _NestedScrollPosition::userScrollDirection() {
    return coordinator.userScrollDirection;
}

DrivenScrollActivity _NestedScrollPosition::createDrivenScrollActivity(Curve curve, Duration duration, double to) {
    return DrivenScrollActivity(thispixels, to, duration, curve, vsync);
}

double _NestedScrollPosition::applyUserOffset(double delta) {
    assert(false);
    return 0.0;
}

void _NestedScrollPosition::goIdle() {
    beginActivity(IdleScrollActivity(this));
}

void _NestedScrollPosition::goBallistic(double velocity) {
    Simulation simulation;
    if (velocity != 0.0 || outOfRange) {
        simulation = physics.createBallisticSimulation(this, velocity);
    }
    beginActivity(createBallisticScrollActivity(simulation_NestedBallisticScrollActivityMode.independent));
}

ScrollActivity _NestedScrollPosition::createBallisticScrollActivity(_NestedScrollMetrics metrics, _NestedBallisticScrollActivityMode mode, Simulation simulation) {
    if (simulation == nullptr) {
        return IdleScrollActivity(this);
    }
    assert(mode != nullptr);
    ;
}

Future<void> _NestedScrollPosition::animateTo(Curve curve, Duration duration, double to) {
    return coordinator.animateTo(coordinator.unnestOffset(to, this)duration, curve);
}

void _NestedScrollPosition::jumpTo(double value) {
    return coordinator.jumpTo(coordinator.unnestOffset(value, this));
}

void _NestedScrollPosition::pointerScroll(double delta) {
    return coordinator.pointerScroll(delta);
}

void _NestedScrollPosition::jumpToWithoutSettling(double value) {
    assert(false);
}

void _NestedScrollPosition::localJumpTo(double value) {
    if (pixels != value) {
        double oldPixels = pixels;
        forcePixels(value);
        didStartScroll();
        didUpdateScrollPositionBy(pixels - oldPixels);
        didEndScroll();
    }
}

void _NestedScrollPosition::applyNewDimensions() {
    super.applyNewDimensions();
    coordinator.updateCanDrag();
}

void _NestedScrollPosition::updateCanDrag(double totalExtent) {
    context.setCanDrag(totalExtent > (viewportDimension - maxScrollExtent) || minScrollExtent != maxScrollExtent);
}

ScrollHoldController _NestedScrollPosition::hold(VoidCallback holdCancelCallback) {
    return coordinator.hold(holdCancelCallback);
}

Drag _NestedScrollPosition::drag(DragStartDetails details, VoidCallback dragCancelCallback) {
    return coordinator.drag(details, dragCancelCallback);
}

_NestedScrollPosition::_NestedScrollPosition(Unknown, _NestedScrollCoordinator coordinator, Unknown, double initialPixels, Unknown, Unknown) {
    {
        if (!hasPixels && initialPixels != nullptr) {
            correctPixels(initialPixels);
        }
        if (activity == nullptr) {
            goIdle();
        }
        assert(activity != nullptr);
        saveScrollOffset();
    }
}

_NestedScrollPosition _NestedInnerBallisticScrollActivity::delegate() {
    return (;
}

void _NestedInnerBallisticScrollActivity::resetActivity() {
    delegate.beginActivity(coordinator.createInnerBallisticScrollActivity(delegate, velocity));
}

void _NestedInnerBallisticScrollActivity::applyNewDimensions() {
    delegate.beginActivity(coordinator.createInnerBallisticScrollActivity(delegate, velocity));
}

bool _NestedInnerBallisticScrollActivity::applyMoveTo(double value) {
    return super.applyMoveTo(coordinator.nestOffset(value, delegate));
}

_NestedInnerBallisticScrollActivity::_NestedInnerBallisticScrollActivity(_NestedScrollCoordinator coordinator, _NestedScrollPosition position, Simulation simulation, TickerProvider vsync) {
    {
        super(position, simulation, vsync);
    }
}

_NestedScrollPosition _NestedOuterBallisticScrollActivity::delegate() {
    return (;
}

void _NestedOuterBallisticScrollActivity::resetActivity() {
    delegate.beginActivity(coordinator.createOuterBallisticScrollActivity(velocity));
}

void _NestedOuterBallisticScrollActivity::applyNewDimensions() {
    delegate.beginActivity(coordinator.createOuterBallisticScrollActivity(velocity));
}

bool _NestedOuterBallisticScrollActivity::applyMoveTo(double value) {
    bool done = false;
    if (velocity > 0.0) {
        if ( < metrics.minRange) {
            return true;
        }
        if (value > metrics.maxRange) {
            value = metrics.maxRange;
            done = true;
        }
    } else     {
        if ( < 0.0) {
        if (value > metrics.maxRange) {
            return true;
        }
        if ( < metrics.minRange) {
            value = metrics.minRange;
            done = true;
        }
    } else {
        value = clampDouble(value, metrics.minRange, metrics.maxRange);
        done = true;
    }
;
    }    bool result = super.applyMoveTo(value + metrics.correctionOffset);
    assert(result);
    return !done;
}

String _NestedOuterBallisticScrollActivity::toString() {
    return "${objectRuntimeType(this, '_NestedOuterBallisticScrollActivity')}(${metrics.minRange} .. ${metrics.maxRange}; correcting by ${metrics.correctionOffset})";
}

_NestedOuterBallisticScrollActivity::_NestedOuterBallisticScrollActivity(_NestedScrollCoordinator coordinator, _NestedScrollMetrics metrics, _NestedScrollPosition position, Simulation simulation, TickerProvider vsync) {
    {
        assert(metrics.minRange != metrics.maxRange);
        assert(metrics.maxRange > metrics.minRange);
        super(position, simulation, vsync);
    }
}

double SliverOverlapAbsorberHandle::layoutExtent() {
    return _layoutExtent;
}

double SliverOverlapAbsorberHandle::scrollExtent() {
    return _scrollExtent;
}

String SliverOverlapAbsorberHandle::toString() {
    String extra;
    ;
    return "${objectRuntimeType(this, 'SliverOverlapAbsorberHandle')}($layoutExtent$extra)";
}

void SliverOverlapAbsorberHandle::_setExtents(double layoutValue, double scrollValue) {
    assert(_writers == 1, "Multiple RenderSliverOverlapAbsorbers have been provided the same SliverOverlapAbsorberHandle.");
    _layoutExtent = layoutValue;
    _scrollExtent = scrollValue;
}

void SliverOverlapAbsorberHandle::_markNeedsLayout() {
    return notifyListeners();
}

SliverOverlapAbsorber::SliverOverlapAbsorber(SliverOverlapAbsorberHandle handle, Unknown, Widget sliver) {
    {
        assert(handle != nullptr);
        super(sliver);
    }
}

RenderSliverOverlapAbsorber SliverOverlapAbsorber::createRenderObject(BuildContext context) {
    return RenderSliverOverlapAbsorber(handle);
}

void SliverOverlapAbsorber::updateRenderObject(BuildContext context, RenderSliverOverlapAbsorber renderObject) {
    renderObject.handle = handle;
}

void SliverOverlapAbsorber::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<SliverOverlapAbsorberHandle>DiagnosticsProperty("handle", handle));
}

RenderSliverOverlapAbsorber::RenderSliverOverlapAbsorber(SliverOverlapAbsorberHandle handle, RenderSliver sliver) {
    {
        assert(handle != nullptr);
        _handle = handle;
    }
    {
        child = sliver;
    }
}

SliverOverlapAbsorberHandle RenderSliverOverlapAbsorber::handle() {
    return _handle;
}

void RenderSliverOverlapAbsorber::handle(SliverOverlapAbsorberHandle value) {
    assert(value != nullptr);
    if (handle == value) {
        return;
    }
    if (attached) {
        handle._writers = 1;
        value._writers = 1;
        value._setExtents(handle.layoutExtent, handle.scrollExtent);
    }
    _handle = value;
}

void RenderSliverOverlapAbsorber::attach(PipelineOwner owner) {
    super.attach(owner);
    handle._writers = 1;
}

void RenderSliverOverlapAbsorber::detach() {
    handle._writers = 1;
    super.detach();
}

void RenderSliverOverlapAbsorber::performLayout() {
    assert(handle._writers == 1, "A SliverOverlapAbsorberHandle cannot be passed to multiple RenderSliverOverlapAbsorber objects at the same time.");
    if (child == nullptr) {
        geometry = SliverGeometry.zero;
        return;
    }
    child!.layout(constraintstrue);
    SliverGeometry childLayoutGeometry = child!.geometry!;
    geometry = SliverGeometry(childLayoutGeometry.scrollExtent - childLayoutGeometry.maxScrollObstructionExtent, childLayoutGeometry.paintExtent, childLayoutGeometry.paintOrigin, math.max(0, childLayoutGeometry.paintExtent - childLayoutGeometry.maxScrollObstructionExtent), childLayoutGeometry.maxPaintExtent, childLayoutGeometry.maxScrollObstructionExtent, childLayoutGeometry.hitTestExtent, childLayoutGeometry.visible, childLayoutGeometry.hasVisualOverflow, childLayoutGeometry.scrollOffsetCorrection);
    handle._setExtents(childLayoutGeometry.maxScrollObstructionExtent, childLayoutGeometry.maxScrollObstructionExtent);
}

void RenderSliverOverlapAbsorber::applyPaintTransform(RenderObject child, Matrix4 transform) {
}

bool RenderSliverOverlapAbsorber::hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result) {
    if (child != nullptr) {
        return child!.hitTest(resultmainAxisPosition, crossAxisPosition);
    }
    return false;
}

void RenderSliverOverlapAbsorber::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        context.paintChild(child!, offset);
    }
}

void RenderSliverOverlapAbsorber::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<SliverOverlapAbsorberHandle>DiagnosticsProperty("handle", handle));
}

SliverOverlapInjector::SliverOverlapInjector(SliverOverlapAbsorberHandle handle, Unknown, Widget sliver) {
    {
        assert(handle != nullptr);
        super(sliver);
    }
}

RenderSliverOverlapInjector SliverOverlapInjector::createRenderObject(BuildContext context) {
    return RenderSliverOverlapInjector(handle);
}

void SliverOverlapInjector::updateRenderObject(BuildContext context, RenderSliverOverlapInjector renderObject) {
    renderObject.handle = handle;
}

void SliverOverlapInjector::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<SliverOverlapAbsorberHandle>DiagnosticsProperty("handle", handle));
}

RenderSliverOverlapInjector::RenderSliverOverlapInjector(SliverOverlapAbsorberHandle handle) {
    {
        assert(handle != nullptr);
        _handle = handle;
    }
}

SliverOverlapAbsorberHandle RenderSliverOverlapInjector::handle() {
    return _handle;
}

void RenderSliverOverlapInjector::handle(SliverOverlapAbsorberHandle value) {
    assert(value != nullptr);
    if (handle == value) {
        return;
    }
    if (attached) {
        handle.removeListener(markNeedsLayout);
    }
    _handle = value;
    if (attached) {
        handle.addListener(markNeedsLayout);
        if (handle.layoutExtent != _currentLayoutExtent || handle.scrollExtent != _currentMaxExtent) {
            markNeedsLayout();
        }
    }
}

void RenderSliverOverlapInjector::attach(PipelineOwner owner) {
    super.attach(owner);
    handle.addListener(markNeedsLayout);
    if (handle.layoutExtent != _currentLayoutExtent || handle.scrollExtent != _currentMaxExtent) {
        markNeedsLayout();
    }
}

void RenderSliverOverlapInjector::detach() {
    handle.removeListener(markNeedsLayout);
    super.detach();
}

void RenderSliverOverlapInjector::performLayout() {
    _currentLayoutExtent = handle.layoutExtent;
    _currentMaxExtent = handle.layoutExtent;
    double clampedLayoutExtent = math.min(_currentLayoutExtent! - constraints.scrollOffset, constraints.remainingPaintExtent);
    geometry = SliverGeometry(_currentLayoutExtent!, math.max(0.0, clampedLayoutExtent), _currentMaxExtent!);
}

void RenderSliverOverlapInjector::debugPaint(PaintingContext context, Offset offset) {
    assert(());
}

void RenderSliverOverlapInjector::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<SliverOverlapAbsorberHandle>DiagnosticsProperty("handle", handle));
}

NestedScrollViewViewport::NestedScrollViewViewport(Unknown, Unknown, Unknown, Unknown, Unknown, SliverOverlapAbsorberHandle handle, Unknown, Unknown, Unknown) {
    {
        assert(handle != nullptr);
    }
}

RenderNestedScrollViewViewport NestedScrollViewViewport::createRenderObject(BuildContext context) {
    return RenderNestedScrollViewViewport(axisDirection, crossAxisDirection ?? Viewport.getDefaultCrossAxisDirection(context, axisDirection), anchor, offset, handle, clipBehavior);
}

void NestedScrollViewViewport::updateRenderObject(BuildContext context, RenderNestedScrollViewViewport renderObject) {
    ;
}

void NestedScrollViewViewport::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<SliverOverlapAbsorberHandle>DiagnosticsProperty("handle", handle));
}

RenderNestedScrollViewViewport::RenderNestedScrollViewViewport(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, SliverOverlapAbsorberHandle handle, Unknown) {
    {
        assert(handle != nullptr);
        _handle = handle;
    }
}

SliverOverlapAbsorberHandle RenderNestedScrollViewViewport::handle() {
    return _handle;
}

void RenderNestedScrollViewViewport::handle(SliverOverlapAbsorberHandle value) {
    assert(value != nullptr);
    if (handle == value) {
        return;
    }
    _handle = value;
    handle._markNeedsLayout();
}

void RenderNestedScrollViewViewport::markNeedsLayout() {
    handle._markNeedsLayout();
    super.markNeedsLayout();
}

void RenderNestedScrollViewViewport::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<SliverOverlapAbsorberHandle>DiagnosticsProperty("handle", handle));
}
