#include "nested_scroll_view.hpp"
NestedScrollViewCls::NestedScrollViewCls(Widget body, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, bool floatHeaderSlivers, NestedScrollViewHeaderSliversBuilder headerSliverBuilder, Key key, ScrollPhysics physics, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection) {
    {
        assert(scrollDirection != nullptr);
        assert(reverse != nullptr);
        assert(headerSliverBuilder != nullptr);
        assert(body != nullptr);
        assert(floatHeaderSlivers != nullptr);
        assert(clipBehavior != nullptr);
    }
}

SliverOverlapAbsorberHandle NestedScrollViewCls::sliverOverlapAbsorberHandleFor(BuildContext context) {
    _InheritedNestedScrollView target = context-><_InheritedNestedScrollView>dependOnInheritedWidgetOfExactType();
    assert(target != nullptr, __s("NestedScrollView.sliverOverlapAbsorberHandleFor must be called with a context that contains a NestedScrollView."));
    return target!->state->_absorberHandle;
}

NestedScrollViewState NestedScrollViewCls::createState() {
    return make<NestedScrollViewStateCls>();
}

List<Widget> NestedScrollViewCls::_buildSlivers(BuildContext context, ScrollController innerController, bool bodyIsScrolled) {
    List<Widget> list1 = make<ListCls<>>();for (auto _x1 : headerSliverBuilder(context, bodyIsScrolled)) {{    list1.add(_x1);}list1.add(ArrayItem);return list1;
}

ScrollController NestedScrollViewStateCls::innerController() {
    return _coordinator!->_innerController;
}

ScrollController NestedScrollViewStateCls::outerController() {
    return _coordinator!->_outerController;
}

void NestedScrollViewStateCls::initState() {
    super->initState();
    _coordinator = make<_NestedScrollCoordinatorCls>(this, widget()->controller, _handleHasScrolledBodyChanged, widget()->floatHeaderSlivers);
}

void NestedScrollViewStateCls::didChangeDependencies() {
    super->didChangeDependencies();
    _coordinator!->setParent(widget()->controller);
}

void NestedScrollViewStateCls::didUpdateWidget(NestedScrollView oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (oldWidget->controller != widget()->controller) {
        _coordinator!->setParent(widget()->controller);
    }
}

void NestedScrollViewStateCls::dispose() {
    _coordinator!->dispose();
    _coordinator = nullptr;
    super->dispose();
}

Widget NestedScrollViewStateCls::build(BuildContext context) {
    ScrollPhysics scrollPhysics = widget()->physics?->applyTo(make<ClampingScrollPhysicsCls>()) | widget()->scrollBehavior?->getScrollPhysics(context)->applyTo(make<ClampingScrollPhysicsCls>()) | make<ClampingScrollPhysicsCls>();
    return make<_InheritedNestedScrollViewCls>(this, make<BuilderCls>([=] (BuildContext context) {
        _lastHasScrolledBody = _coordinator!->hasScrolledBody();
        return make<_NestedScrollViewCustomScrollViewCls>(widget()->dragStartBehavior, widget()->scrollDirection, widget()->reverse, scrollPhysics, widget()->scrollBehavior | ScrollConfigurationCls->of(context)->copyWith(false), _coordinator!->_outerController, widget()->_buildSlivers(context, _coordinator!->_innerController, _lastHasScrolledBody!), _absorberHandle, widget()->clipBehavior, widget()->restorationId);
    }));
}

void NestedScrollViewStateCls::_handleHasScrolledBodyChanged() {
    if (!mounted()) {
        return;
    }
    bool newHasScrolledBody = _coordinator!->hasScrolledBody();
    if (_lastHasScrolledBody != newHasScrolledBody) {
        setState([=] () {
        });
    }
}

Widget _NestedScrollViewCustomScrollViewCls::buildViewport(BuildContext context, ViewportOffset offset, AxisDirection axisDirection, List<Widget> slivers) {
    assert(!shrinkWrap);
    return make<NestedScrollViewViewportCls>(axisDirection, offset, slivers, handle, clipBehavior);
}

bool _InheritedNestedScrollViewCls::updateShouldNotify(_InheritedNestedScrollView old) {
    return state != old->state;
}

_InheritedNestedScrollViewCls::_InheritedNestedScrollViewCls(Widget child, NestedScrollViewState state) {
    {
        assert(state != nullptr);
        assert(child != nullptr);
    }
}

_NestedScrollMetrics _NestedScrollMetricsCls::copyWith(AxisDirection axisDirection, double correctionOffset, double maxRange, double maxScrollExtent, double minRange, double minScrollExtent, double pixels, double viewportDimension) {
    return make<_NestedScrollMetricsCls>(minScrollExtent | (hasContentDimensions()? this->minScrollExtent : nullptr), maxScrollExtent | (hasContentDimensions()? this->maxScrollExtent : nullptr), pixels | (hasPixels()? this->pixels : nullptr), viewportDimension | (hasViewportDimension()? this->viewportDimension : nullptr), axisDirection | this->axisDirection, minRange | this->minRange, maxRange | this->maxRange, correctionOffset | this->correctionOffset);
}

bool _NestedScrollCoordinatorCls::canScrollBody() {
    _NestedScrollPosition outer = _outerPosition();
    if (outer == nullptr) {
        return true;
    }
    return outer->haveDimensions() && outer->extentAfter == 0.0;
}

bool _NestedScrollCoordinatorCls::hasScrolledBody() {
    for (_NestedScrollPosition position : _innerPositions()) {
        if (!position->hasContentDimensions || !position->hasPixels) {
            continue;
        } else {
            if (position->pixels > position->minScrollExtent) {
            return true;
        }
;
        }    }
    return false;
}

void _NestedScrollCoordinatorCls::updateShadow() {
    _onHasScrolledBodyChanged();
}

ScrollDirection _NestedScrollCoordinatorCls::userScrollDirection() {
    return _userScrollDirection;
}

void _NestedScrollCoordinatorCls::updateUserScrollDirection(ScrollDirection value) {
    assert(value != nullptr);
    if (userScrollDirection() == value) {
        return;
    }
    _userScrollDirection = value;
    _outerPosition()!->didUpdateScrollDirection(value);
    for (_NestedScrollPosition position : _innerPositions()) {
        position->didUpdateScrollDirection(value);
    }
}

void _NestedScrollCoordinatorCls::beginActivity(ScrollActivity newOuterActivity, _NestedScrollActivityGetter innerActivityGetter) {
    _outerPosition()!->beginActivity(newOuterActivity);
    bool scrolling = newOuterActivity->isScrolling();
    for (_NestedScrollPosition position : _innerPositions()) {
        ScrollActivity newInnerActivity = innerActivityGetter(position);
        position->beginActivity(newInnerActivity);
        scrolling = scrolling && newInnerActivity->isScrolling();
    }
    _currentDrag?->dispose();
    _currentDrag = nullptr;
    if (!scrolling) {
        updateUserScrollDirection(ScrollDirectionCls::idle);
    }
}

AxisDirection _NestedScrollCoordinatorCls::axisDirection() {
    return _outerPosition()!->axisDirection();
}

void _NestedScrollCoordinatorCls::goIdle() {
    beginActivity(_createIdleScrollActivity(_outerPosition()!), _createIdleScrollActivity);
}

void _NestedScrollCoordinatorCls::goBallistic(double velocity) {
    beginActivity(createOuterBallisticScrollActivity(velocity), [=] (_NestedScrollPosition position) {
        return createInnerBallisticScrollActivity(position, velocity);
    });
}

ScrollActivity _NestedScrollCoordinatorCls::createOuterBallisticScrollActivity(double velocity) {
    _NestedScrollPosition innerPosition;
    if (velocity != 0.0) {
        for (_NestedScrollPosition position : _innerPositions()) {
            if (innerPosition != nullptr) {
                if (velocity > 0.0) {
                    if (innerPosition->pixels() < position->pixels) {
                        continue;
                    }
                } else {
                    assert( < 0.0);
                    if (innerPosition->pixels() > position->pixels) {
                        continue;
                    }
                }
            }
            innerPosition = position;
        }
    }
    if (innerPosition == nullptr) {
        return _outerPosition()!->createBallisticScrollActivity(_outerPosition()!->physics->createBallisticSimulation(_outerPosition()!, velocity), _NestedBallisticScrollActivityModeCls::independent);
    }
    _NestedScrollMetrics metrics = _getMetrics(innerPosition, velocity);
    return _outerPosition()!->createBallisticScrollActivity(_outerPosition()!->physics->createBallisticSimulation(metrics, velocity), _NestedBallisticScrollActivityModeCls::outer, metrics);
}

ScrollActivity _NestedScrollCoordinatorCls::createInnerBallisticScrollActivity(_NestedScrollPosition position, double velocity) {
    return position->createBallisticScrollActivity(position->physics->createBallisticSimulation(_getMetrics(position, velocity), velocity), _NestedBallisticScrollActivityModeCls::inner);
}

double _NestedScrollCoordinatorCls::unnestOffset(double value, _NestedScrollPosition source) {
    if (source == _outerPosition()) {
        return clampDouble(value, _outerPosition()!->minScrollExtent(), _outerPosition()!->maxScrollExtent());
    }
    if ( < source->minScrollExtent()) {
        return value - source->minScrollExtent() + _outerPosition()!->minScrollExtent();
    }
    return value - source->minScrollExtent() + _outerPosition()!->maxScrollExtent();
}

double _NestedScrollCoordinatorCls::nestOffset(double value, _NestedScrollPosition target) {
    if (target == _outerPosition()) {
        return clampDouble(value, _outerPosition()!->minScrollExtent(), _outerPosition()!->maxScrollExtent());
    }
    if ( < _outerPosition()!->minScrollExtent()) {
        return value - _outerPosition()!->minScrollExtent() + target->minScrollExtent();
    }
    if (value > _outerPosition()!->maxScrollExtent()) {
        return value - _outerPosition()!->maxScrollExtent() + target->minScrollExtent();
    }
    return target->minScrollExtent();
}

void _NestedScrollCoordinatorCls::updateCanDrag() {
    if (!_outerPosition()!->haveDimensions()) {
        return;
    }
    double maxInnerExtent = 0.0;
    for (_NestedScrollPosition position : _innerPositions()) {
        if (!position->haveDimensions) {
            return;
        }
        maxInnerExtent = math->max(maxInnerExtent, position->maxScrollExtent - position->minScrollExtent);
    }
    _outerPosition()!->updateCanDrag(maxInnerExtent);
}

Future<void> _NestedScrollCoordinatorCls::animateTo(double to, Curve curve, Duration duration) {
    DrivenScrollActivity outerActivity = _outerPosition()!->createDrivenScrollActivity(nestOffset(to, _outerPosition()!), duration, curve);
    List<Future<void>> resultFutures = makeList(ArrayItem);
    beginActivity(outerActivity, [=] (_NestedScrollPosition position) {
        DrivenScrollActivity innerActivity = position->createDrivenScrollActivity(nestOffset(to, position), duration, curve);
        resultFutures->add(innerActivity->done());
        return innerActivity;
    });
    await FutureCls-><void>wait(resultFutures);
}

void _NestedScrollCoordinatorCls::jumpTo(double to) {
    goIdle();
    _outerPosition()!->localJumpTo(nestOffset(to, _outerPosition()!));
    for (_NestedScrollPosition position : _innerPositions()) {
        position->localJumpTo(nestOffset(to, position));
    }
    goBallistic(0.0);
}

void _NestedScrollCoordinatorCls::pointerScroll(double delta) {
    assert(delta != 0.0);
    goIdle();
    updateUserScrollDirection( < 0.0? ScrollDirectionCls::forward : ScrollDirectionCls::reverse);
    _outerPosition()!->isScrollingNotifier->value() = true;
    _outerPosition()!->didStartScroll();
    for (_NestedScrollPosition position : _innerPositions()) {
        position->isScrollingNotifier->value = true;
        position->didStartScroll();
    }
    if (_innerPositions()->isEmpty()) {
        _outerPosition()!->applyClampedPointerSignalUpdate(delta);
    } else {
        if (delta > 0.0) {
        double outerDelta = delta;
        for (_NestedScrollPosition position : _innerPositions()) {
            if (position->pixels < 0.0) {
                double potentialOuterDelta = position->applyClampedPointerSignalUpdate(delta);
                outerDelta = math->max(outerDelta, potentialOuterDelta);
            }
        }
        if (outerDelta != 0.0) {
            double innerDelta = _outerPosition()!->applyClampedPointerSignalUpdate(outerDelta);
            if (innerDelta != 0.0) {
                for (_NestedScrollPosition position : _innerPositions()) {
                    position->applyClampedPointerSignalUpdate(innerDelta);
                }
            }
        }
    } else {
        double innerDelta = delta;
        if (_floatHeaderSlivers) {
            innerDelta = _outerPosition()!->applyClampedPointerSignalUpdate(delta);
        }
        if (innerDelta != 0.0) {
            double outerDelta = 0.0;
            for (_NestedScrollPosition position : _innerPositions()) {
                double overscroll = position->applyClampedPointerSignalUpdate(innerDelta);
                outerDelta = math->min(outerDelta, overscroll);
            }
            if (outerDelta != 0.0) {
                _outerPosition()!->applyClampedPointerSignalUpdate(outerDelta);
            }
        }
    }
;
    }    _outerPosition()!->didEndScroll();
    for (_NestedScrollPosition position : _innerPositions()) {
        position->didEndScroll();
    }
    goBallistic(0.0);
}

double _NestedScrollCoordinatorCls::setPixels(double newPixels) {
    assert(false);
    return 0.0;
}

ScrollHoldController _NestedScrollCoordinatorCls::hold(VoidCallback holdCancelCallback) {
    beginActivity(make<HoldScrollActivityCls>(_outerPosition()!, holdCancelCallback), [=] (_NestedScrollPosition position) {
        make<HoldScrollActivityCls>(position);
    });
    return this;
}

void _NestedScrollCoordinatorCls::cancel() {
    goBallistic(0.0);
}

Drag _NestedScrollCoordinatorCls::drag(DragStartDetails details, VoidCallback dragCancelCallback) {
    ScrollDragController drag = make<ScrollDragControllerCls>(this, details, dragCancelCallback);
    beginActivity(make<DragScrollActivityCls>(_outerPosition()!, drag), [=] (_NestedScrollPosition position) {
        make<DragScrollActivityCls>(position, drag);
    });
    assert(_currentDrag == nullptr);
    _currentDrag = drag;
    return drag;
}

void _NestedScrollCoordinatorCls::applyUserOffset(double delta) {
    updateUserScrollDirection(delta > 0.0? ScrollDirectionCls::forward : ScrollDirectionCls::reverse);
    assert(delta != 0.0);
    if (_innerPositions()->isEmpty()) {
        _outerPosition()!->applyFullDragUpdate(delta);
    } else {
        if ( < 0.0) {
        double outerDelta = delta;
        for (_NestedScrollPosition position : _innerPositions()) {
            if (position->pixels < 0.0) {
                double potentialOuterDelta = position->applyClampedDragUpdate(delta);
                outerDelta = math->max(outerDelta, potentialOuterDelta);
            }
        }
        if (outerDelta != 0.0) {
            double innerDelta = _outerPosition()!->applyClampedDragUpdate(outerDelta);
            if (innerDelta != 0.0) {
                for (_NestedScrollPosition position : _innerPositions()) {
                    position->applyFullDragUpdate(innerDelta);
                }
            }
        }
    } else {
        double innerDelta = delta;
        if (_floatHeaderSlivers) {
            innerDelta = _outerPosition()!->applyClampedDragUpdate(delta);
        }
        if (innerDelta != 0.0) {
            double outerDelta = 0.0;
            List<double> overscrolls = makeList();
            List<_NestedScrollPosition> innerPositions = _innerPositions()->toList();
            for (_NestedScrollPosition position : innerPositions) {
                double overscroll = position->applyClampedDragUpdate(innerDelta);
                outerDelta = math->max(outerDelta, overscroll);
                overscrolls->add(overscroll);
            }
            if (outerDelta != 0.0) {
                outerDelta -= _outerPosition()!->applyClampedDragUpdate(outerDelta);
            }
            for (;  < innerPositions->length(); ++i) {
                double remainingDelta = overscrolls[i] - outerDelta;
                if (remainingDelta > 0.0) {
                    innerPositions[i]->applyFullDragUpdate(remainingDelta);
                }
            }
        }
    }
;
    }}

void _NestedScrollCoordinatorCls::setParent(ScrollController value) {
    _parent = value;
    updateParent();
}

void _NestedScrollCoordinatorCls::updateParent() {
    _outerPosition()?->setParent(_parent | PrimaryScrollControllerCls->of(_state->context()));
}

void _NestedScrollCoordinatorCls::dispose() {
    _currentDrag?->dispose();
    _currentDrag = nullptr;
    _outerController->dispose();
    _innerController->dispose();
}

String _NestedScrollCoordinatorCls::toString() {
    return __sf("%s(outer=%s; inner=%s)", objectRuntimeType(this, __s("_NestedScrollCoordinator")), _outerController, _innerController);
}

_NestedScrollCoordinatorCls::_NestedScrollCoordinatorCls(NestedScrollViewState _state, ScrollController _parent, VoidCallback _onHasScrolledBodyChanged, bool _floatHeaderSlivers) {
    {
        double initialScrollOffset = _parent?->initialScrollOffset() | 0.0;
        _outerController = make<_NestedScrollControllerCls>(this, initialScrollOffset, __s("outer"));
        _innerController = make<_NestedScrollControllerCls>(this, __s("inner"));
    }
}

_NestedScrollPosition _NestedScrollCoordinatorCls::_outerPosition() {
    if (!_outerController->hasClients()) {
        return nullptr;
    }
    return _outerController->nestedPositions()->single();
}

Iterable<_NestedScrollPosition> _NestedScrollCoordinatorCls::_innerPositions() {
    return _innerController->nestedPositions();
}

IdleScrollActivity _NestedScrollCoordinatorCls::_createIdleScrollActivity(_NestedScrollPosition position) {
    return make<IdleScrollActivityCls>(position);
}

_NestedScrollMetrics _NestedScrollCoordinatorCls::_getMetrics(_NestedScrollPosition innerPosition, double velocity) {
    assert(innerPosition != nullptr);
    double pixels, minRange, maxRange, correctionOffset;
    double extra = 0.0;
    if (innerPosition->pixels == innerPosition->minScrollExtent()) {
        pixels = clampDouble(_outerPosition()!->pixels, _outerPosition()!->minScrollExtent(), _outerPosition()!->maxScrollExtent());
        minRange = _outerPosition()!->minScrollExtent();
        maxRange = _outerPosition()!->maxScrollExtent();
        assert(minRange <= maxRange);
        correctionOffset = 0.0;
    } else {
        assert(innerPosition->pixels != innerPosition->minScrollExtent());
        if (innerPosition->pixels < innerPosition->minScrollExtent()) {
            pixels = innerPosition->pixels - innerPosition->minScrollExtent() + _outerPosition()!->minScrollExtent();
        } else {
            assert(innerPosition->pixels > innerPosition->minScrollExtent());
            pixels = innerPosition->pixels - innerPosition->minScrollExtent() + _outerPosition()!->maxScrollExtent();
        }
        if ((velocity > 0.0) && (innerPosition->pixels > innerPosition->minScrollExtent())) {
            extra = _outerPosition()!->maxScrollExtent() - _outerPosition()!->pixels;
            assert(extra >= 0.0);
            minRange = pixels;
            maxRange = pixels + extra;
            assert(minRange <= maxRange);
            correctionOffset = _outerPosition()!->pixels - pixels;
        } else {
            if (( < 0.0) && (innerPosition->pixels < innerPosition->minScrollExtent())) {
            extra = _outerPosition()!->pixels - _outerPosition()!->minScrollExtent();
            assert(extra >= 0.0);
            minRange = pixels - extra;
            maxRange = pixels;
            assert(minRange <= maxRange);
            correctionOffset = _outerPosition()!->pixels - pixels;
        } else {
            if (velocity > 0.0) {
                extra = _outerPosition()!->minScrollExtent() - _outerPosition()!->pixels;
            } else {
                if ( < 0.0) {
                extra = _outerPosition()!->pixels - (_outerPosition()!->maxScrollExtent() - _outerPosition()!->minScrollExtent());
            }
;
            }            assert(extra <= 0.0);
            minRange = _outerPosition()!->minScrollExtent();
            maxRange = _outerPosition()!->maxScrollExtent() + extra;
            assert(minRange <= maxRange);
            correctionOffset = 0.0;
        }
;
        }    }
    return make<_NestedScrollMetricsCls>(_outerPosition()!->minScrollExtent(), _outerPosition()!->maxScrollExtent() + innerPosition->maxScrollExtent() - innerPosition->minScrollExtent() + extra, pixels, _outerPosition()!->viewportDimension(), _outerPosition()!->axisDirection(), minRange, maxRange, correctionOffset);
}

ScrollPosition _NestedScrollControllerCls::createScrollPosition(ScrollPhysics physics, ScrollContext context, ScrollPosition oldPosition) {
    return make<_NestedScrollPositionCls>(coordinator, physics, context, initialScrollOffset(), oldPosition, debugLabel);
}

void _NestedScrollControllerCls::attach(ScrollPosition position) {
    assert(is<_NestedScrollPosition>(position));
    super->attach(position);
    coordinator->updateParent();
    coordinator->updateCanDrag();
    position->addListener(_scheduleUpdateShadow);
    _scheduleUpdateShadow();
}

void _NestedScrollControllerCls::detach(ScrollPosition position) {
    assert(is<_NestedScrollPosition>(position));
    (as<_NestedScrollPosition>(position))->setParent(nullptr);
    position->removeListener(_scheduleUpdateShadow);
    super->detach(position);
    _scheduleUpdateShadow();
}

Iterable<_NestedScrollPosition> _NestedScrollControllerCls::nestedPositions() {
    return IterableCls-><ScrollPosition, _NestedScrollPosition>castFrom(positions());
}

void _NestedScrollControllerCls::_scheduleUpdateShadow() {
    SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration timeStamp) {
        coordinator->updateShadow();
    });
}

TickerProvider _NestedScrollPositionCls::vsync() {
    return context->vsync();
}

void _NestedScrollPositionCls::setParent(ScrollController value) {
    _parent?->detach(this);
    _parent = value;
    _parent?->attach(this);
}

AxisDirection _NestedScrollPositionCls::axisDirection() {
    return context->axisDirection();
}

void _NestedScrollPositionCls::absorb(ScrollPosition other) {
    super->absorb(other);
    activity()!->updateDelegate(this);
}

void _NestedScrollPositionCls::restoreScrollOffset() {
    if (coordinator->canScrollBody()) {
        super->restoreScrollOffset();
    }
}

double _NestedScrollPositionCls::applyClampedDragUpdate(double delta) {
    assert(delta != 0.0);
    double min =  < 0.0? -double->infinity : math->min(minScrollExtent(), pixels());
    double max = delta > 0.0? double->infinity :  < 0.0? 0.0 : math->max(maxScrollExtent(), pixels());
    double oldPixels = pixels();
    double newPixels = clampDouble(pixels() - delta, min, max);
    double clampedDelta = newPixels - pixels();
    if (clampedDelta == 0.0) {
        return delta;
    }
    double overscroll = physics->applyBoundaryConditions(this, newPixels);
    double actualNewPixels = newPixels - overscroll;
    double offset = actualNewPixels - oldPixels;
    if (offset != 0.0) {
        forcePixels(actualNewPixels);
        didUpdateScrollPositionBy(offset);
    }
    return delta + offset;
}

double _NestedScrollPositionCls::applyFullDragUpdate(double delta) {
    assert(delta != 0.0);
    double oldPixels = pixels();
    double newPixels = pixels() - physics->applyPhysicsToUserOffset(this, delta);
    if (oldPixels == newPixels) {
        return 0.0;
    }
    double overscroll = physics->applyBoundaryConditions(this, newPixels);
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

double _NestedScrollPositionCls::applyClampedPointerSignalUpdate(double delta) {
    assert(delta != 0.0);
    double min = delta > 0.0? -double->infinity : math->min(minScrollExtent(), pixels());
    double max =  < 0.0? double->infinity : math->max(maxScrollExtent(), pixels());
    double newPixels = clampDouble(pixels() + delta, min, max);
    double clampedDelta = newPixels - pixels();
    if (clampedDelta == 0.0) {
        return delta;
    }
    forcePixels(newPixels);
    didUpdateScrollPositionBy(clampedDelta);
    return delta - clampedDelta;
}

ScrollDirection _NestedScrollPositionCls::userScrollDirection() {
    return coordinator->userScrollDirection();
}

DrivenScrollActivity _NestedScrollPositionCls::createDrivenScrollActivity(double to, Duration duration, Curve curve) {
    return make<DrivenScrollActivityCls>(this, pixels(), to, duration, curve, vsync());
}

double _NestedScrollPositionCls::applyUserOffset(double delta) {
    assert(false);
    return 0.0;
}

void _NestedScrollPositionCls::goIdle() {
    beginActivity(make<IdleScrollActivityCls>(this));
}

void _NestedScrollPositionCls::goBallistic(double velocity) {
    Simulation simulation;
    if (velocity != 0.0 || outOfRange) {
        simulation = physics->createBallisticSimulation(this, velocity);
    }
    beginActivity(createBallisticScrollActivity(simulation, _NestedBallisticScrollActivityModeCls::independent));
}

ScrollActivity _NestedScrollPositionCls::createBallisticScrollActivity(Simulation simulation, _NestedScrollMetrics metrics, _NestedBallisticScrollActivityMode mode) {
    if (simulation == nullptr) {
        return make<IdleScrollActivityCls>(this);
    }
    assert(mode != nullptr);
    ;
}

Future<void> _NestedScrollPositionCls::animateTo(double to, Curve curve, Duration duration) {
    return coordinator->animateTo(coordinator->unnestOffset(to, this), duration, curve);
}

void _NestedScrollPositionCls::jumpTo(double value) {
    return coordinator->jumpTo(coordinator->unnestOffset(value, this));
}

void _NestedScrollPositionCls::pointerScroll(double delta) {
    return coordinator->pointerScroll(delta);
}

void _NestedScrollPositionCls::jumpToWithoutSettling(double value) {
    assert(false);
}

void _NestedScrollPositionCls::localJumpTo(double value) {
    if (pixels() != value) {
        double oldPixels = pixels();
        forcePixels(value);
        didStartScroll();
        didUpdateScrollPositionBy(pixels() - oldPixels);
        didEndScroll();
    }
}

void _NestedScrollPositionCls::applyNewDimensions() {
    super->applyNewDimensions();
    coordinator->updateCanDrag();
}

void _NestedScrollPositionCls::updateCanDrag(double totalExtent) {
    context->setCanDrag(totalExtent > (viewportDimension() - maxScrollExtent()) || minScrollExtent() != maxScrollExtent());
}

ScrollHoldController _NestedScrollPositionCls::hold(VoidCallback holdCancelCallback) {
    return coordinator->hold(holdCancelCallback);
}

Drag _NestedScrollPositionCls::drag(DragStartDetails details, VoidCallback dragCancelCallback) {
    return coordinator->drag(details, dragCancelCallback);
}

_NestedScrollPositionCls::_NestedScrollPositionCls(ScrollContext context, _NestedScrollCoordinator coordinator, String debugLabel, double initialPixels, ScrollPosition oldPosition, ScrollPhysics physics) {
    {
        if (!hasPixels() && initialPixels != nullptr) {
            correctPixels(initialPixels);
        }
        if (activity() == nullptr) {
            goIdle();
        }
        assert(activity() != nullptr);
        saveScrollOffset();
    }
}

_NestedScrollPosition _NestedInnerBallisticScrollActivityCls::delegate() {
    return as<_NestedScrollPosition>(super->delegate);
}

void _NestedInnerBallisticScrollActivityCls::resetActivity() {
    delegate()->beginActivity(coordinator->createInnerBallisticScrollActivity(delegate(), velocity()));
}

void _NestedInnerBallisticScrollActivityCls::applyNewDimensions() {
    delegate()->beginActivity(coordinator->createInnerBallisticScrollActivity(delegate(), velocity()));
}

bool _NestedInnerBallisticScrollActivityCls::applyMoveTo(double value) {
    return super->applyMoveTo(coordinator->nestOffset(value, delegate()));
}

_NestedInnerBallisticScrollActivityCls::_NestedInnerBallisticScrollActivityCls(_NestedScrollCoordinator coordinator, _NestedScrollPosition position, Simulation simulation, TickerProvider vsync) : BallisticScrollActivity(position, simulation, vsync) {
}

_NestedScrollPosition _NestedOuterBallisticScrollActivityCls::delegate() {
    return as<_NestedScrollPosition>(super->delegate);
}

void _NestedOuterBallisticScrollActivityCls::resetActivity() {
    delegate()->beginActivity(coordinator->createOuterBallisticScrollActivity(velocity()));
}

void _NestedOuterBallisticScrollActivityCls::applyNewDimensions() {
    delegate()->beginActivity(coordinator->createOuterBallisticScrollActivity(velocity()));
}

bool _NestedOuterBallisticScrollActivityCls::applyMoveTo(double value) {
    bool done = false;
    if (velocity() > 0.0) {
        if ( < metrics->minRange) {
            return true;
        }
        if (value > metrics->maxRange) {
            value = metrics->maxRange;
            done = true;
        }
    } else {
        if ( < 0.0) {
        if (value > metrics->maxRange) {
            return true;
        }
        if ( < metrics->minRange) {
            value = metrics->minRange;
            done = true;
        }
    } else {
        value = clampDouble(value, metrics->minRange, metrics->maxRange);
        done = true;
    }
;
    }    bool result = super->applyMoveTo(value + metrics->correctionOffset);
    assert(result);
    return !done;
}

String _NestedOuterBallisticScrollActivityCls::toString() {
    return __sf("%s(%s .. %s; correcting by %s)", objectRuntimeType(this, __s("_NestedOuterBallisticScrollActivity")), metrics->minRange, metrics->maxRange, metrics->correctionOffset);
}

_NestedOuterBallisticScrollActivityCls::_NestedOuterBallisticScrollActivityCls(_NestedScrollCoordinator coordinator, _NestedScrollPosition position, _NestedScrollMetrics metrics, Simulation simulation, TickerProvider vsync) : BallisticScrollActivity(position, simulation, vsync) {
    {
        assert(metrics->minRange != metrics->maxRange);
        assert(metrics->maxRange > metrics->minRange);
    }
}

double SliverOverlapAbsorberHandleCls::layoutExtent() {
    return _layoutExtent;
}

double SliverOverlapAbsorberHandleCls::scrollExtent() {
    return _scrollExtent;
}

String SliverOverlapAbsorberHandleCls::toString() {
    String extra;
    ;
    return __sf("%s(%s%s)", objectRuntimeType(this, __s("SliverOverlapAbsorberHandle")), layoutExtent(), extra);
}

void SliverOverlapAbsorberHandleCls::_setExtents(double layoutValue, double scrollValue) {
    assert(_writers == 1, __s("Multiple RenderSliverOverlapAbsorbers have been provided the same SliverOverlapAbsorberHandle."));
    _layoutExtent = layoutValue;
    _scrollExtent = scrollValue;
}

void SliverOverlapAbsorberHandleCls::_markNeedsLayout() {
    return notifyListeners();
}

SliverOverlapAbsorberCls::SliverOverlapAbsorberCls(SliverOverlapAbsorberHandle handle, Key key, Widget sliver) : SingleChildRenderObjectWidget(sliver) {
    {
        assert(handle != nullptr);
    }
}

RenderSliverOverlapAbsorber SliverOverlapAbsorberCls::createRenderObject(BuildContext context) {
    return make<RenderSliverOverlapAbsorberCls>(handle);
}

void SliverOverlapAbsorberCls::updateRenderObject(BuildContext context, RenderSliverOverlapAbsorber renderObject) {
    renderObject->handle = handle;
}

void SliverOverlapAbsorberCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<SliverOverlapAbsorberHandle>make<DiagnosticsPropertyCls>(__s("handle"), handle));
}

RenderSliverOverlapAbsorberCls::RenderSliverOverlapAbsorberCls(SliverOverlapAbsorberHandle handle, RenderSliver sliver) {
    {
        assert(handle != nullptr);
        _handle = handle;
    }
    {
        child = sliver;
    }
}

SliverOverlapAbsorberHandle RenderSliverOverlapAbsorberCls::handle() {
    return _handle;
}

void RenderSliverOverlapAbsorberCls::handle(SliverOverlapAbsorberHandle value) {
    assert(value != nullptr);
    if (handle() == value) {
        return;
    }
    if (attached()) {
        handle()->_writers -= 1;
        value->_writers += 1;
        value->_setExtents(handle()->layoutExtent(), handle()->scrollExtent());
    }
    _handle = value;
}

void RenderSliverOverlapAbsorberCls::attach(PipelineOwner owner) {
    super->attach(owner);
    handle()->_writers += 1;
}

void RenderSliverOverlapAbsorberCls::detach() {
    handle()->_writers -= 1;
    super->detach();
}

void RenderSliverOverlapAbsorberCls::performLayout() {
    assert(handle()->_writers == 1, __s("A SliverOverlapAbsorberHandle cannot be passed to multiple RenderSliverOverlapAbsorber objects at the same time."));
    if (child == nullptr) {
        geometry() = SliverGeometryCls::zero;
        return;
    }
    child!->layout(constraints(), true);
    SliverGeometry childLayoutGeometry = child!->geometry!;
    geometry() = make<SliverGeometryCls>(childLayoutGeometry->scrollExtent - childLayoutGeometry->maxScrollObstructionExtent, childLayoutGeometry->paintExtent, childLayoutGeometry->paintOrigin, math->max(0, childLayoutGeometry->paintExtent - childLayoutGeometry->maxScrollObstructionExtent), childLayoutGeometry->maxPaintExtent, childLayoutGeometry->maxScrollObstructionExtent, childLayoutGeometry->hitTestExtent, childLayoutGeometry->visible, childLayoutGeometry->hasVisualOverflow, childLayoutGeometry->scrollOffsetCorrection);
    handle()->_setExtents(childLayoutGeometry->maxScrollObstructionExtent, childLayoutGeometry->maxScrollObstructionExtent);
}

void RenderSliverOverlapAbsorberCls::applyPaintTransform(RenderObject child, Matrix4 transform) {
}

bool RenderSliverOverlapAbsorberCls::hitTestChildren(SliverHitTestResult result, double crossAxisPosition, double mainAxisPosition) {
    if (child != nullptr) {
        return child!->hitTest(result, mainAxisPosition, crossAxisPosition);
    }
    return false;
}

void RenderSliverOverlapAbsorberCls::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        context->paintChild(child!, offset);
    }
}

void RenderSliverOverlapAbsorberCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<SliverOverlapAbsorberHandle>make<DiagnosticsPropertyCls>(__s("handle"), handle()));
}

SliverOverlapInjectorCls::SliverOverlapInjectorCls(SliverOverlapAbsorberHandle handle, Key key, Widget sliver) : SingleChildRenderObjectWidget(sliver) {
    {
        assert(handle != nullptr);
    }
}

RenderSliverOverlapInjector SliverOverlapInjectorCls::createRenderObject(BuildContext context) {
    return make<RenderSliverOverlapInjectorCls>(handle);
}

void SliverOverlapInjectorCls::updateRenderObject(BuildContext context, RenderSliverOverlapInjector renderObject) {
    renderObject->handle = handle;
}

void SliverOverlapInjectorCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<SliverOverlapAbsorberHandle>make<DiagnosticsPropertyCls>(__s("handle"), handle));
}

RenderSliverOverlapInjectorCls::RenderSliverOverlapInjectorCls(SliverOverlapAbsorberHandle handle) {
    {
        assert(handle != nullptr);
        _handle = handle;
    }
}

SliverOverlapAbsorberHandle RenderSliverOverlapInjectorCls::handle() {
    return _handle;
}

void RenderSliverOverlapInjectorCls::handle(SliverOverlapAbsorberHandle value) {
    assert(value != nullptr);
    if (handle() == value) {
        return;
    }
    if (attached()) {
        handle()->removeListener(markNeedsLayout);
    }
    _handle = value;
    if (attached()) {
        handle()->addListener(markNeedsLayout);
        if (handle()->layoutExtent() != _currentLayoutExtent || handle()->scrollExtent() != _currentMaxExtent) {
            markNeedsLayout();
        }
    }
}

void RenderSliverOverlapInjectorCls::attach(PipelineOwner owner) {
    super->attach(owner);
    handle()->addListener(markNeedsLayout);
    if (handle()->layoutExtent() != _currentLayoutExtent || handle()->scrollExtent() != _currentMaxExtent) {
        markNeedsLayout();
    }
}

void RenderSliverOverlapInjectorCls::detach() {
    handle()->removeListener(markNeedsLayout);
    super->detach();
}

void RenderSliverOverlapInjectorCls::performLayout() {
    _currentLayoutExtent = handle()->layoutExtent();
    _currentMaxExtent = handle()->layoutExtent();
    double clampedLayoutExtent = math->min(_currentLayoutExtent! - constraints()->scrollOffset, constraints()->remainingPaintExtent);
    geometry() = make<SliverGeometryCls>(_currentLayoutExtent!, math->max(0.0, clampedLayoutExtent), _currentMaxExtent!);
}

void RenderSliverOverlapInjectorCls::debugPaint(PaintingContext context, Offset offset) {
    assert([=] () {
        if (debugPaintSizeEnabled) {
                    auto _c1 = make<PaintCls>();        _c1.color = auto _c2 = make<ColorCls>(0xFFCC9933);        _c2.strokeWidth = auto _c3 = 3.0;        _c3.style = PaintingStyleCls::stroke;        _c3;        _c2;Paint paint = _c1;
            Offset start, end, delta;
            ;
            for (; index <= 2; index += 1) {
                paintZigZag(context->canvas(), paint, start - delta * index->toDouble(), end - delta * index->toDouble(), 10, 10.0);
            }
        }
        return true;
    }());
}

void RenderSliverOverlapInjectorCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<SliverOverlapAbsorberHandle>make<DiagnosticsPropertyCls>(__s("handle"), handle()));
}

NestedScrollViewViewportCls::NestedScrollViewViewportCls(double anchor, AxisDirection axisDirection, Key center, Clip clipBehavior, AxisDirection crossAxisDirection, SliverOverlapAbsorberHandle handle, Key key, ViewportOffset offset, List<Widget> slivers) {
    {
        assert(handle != nullptr);
    }
}

RenderNestedScrollViewViewport NestedScrollViewViewportCls::createRenderObject(BuildContext context) {
    return make<RenderNestedScrollViewViewportCls>(axisDirection, crossAxisDirection | ViewportCls->getDefaultCrossAxisDirection(context, axisDirection), anchor, offset, handle, clipBehavior);
}

void NestedScrollViewViewportCls::updateRenderObject(BuildContext context, RenderNestedScrollViewViewport renderObject) {
    auto _c1 = renderObject;_c1.axisDirection = auto _c2 = axisDirection;_c2.crossAxisDirection = auto _c3 = crossAxisDirection | ViewportCls->getDefaultCrossAxisDirection(context, axisDirection);_c3.anchor = auto _c4 = anchor;_c4.offset = auto _c5 = offset;_c5.handle = auto _c6 = handle;_c6.clipBehavior = clipBehavior;_c6;_c5;_c4;_c3;_c2;_c1;
}

void NestedScrollViewViewportCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<SliverOverlapAbsorberHandle>make<DiagnosticsPropertyCls>(__s("handle"), handle));
}

RenderNestedScrollViewViewportCls::RenderNestedScrollViewViewportCls(double anchor, AxisDirection axisDirection, RenderSliver center, List<RenderSliver> children, Clip clipBehavior, AxisDirection crossAxisDirection, SliverOverlapAbsorberHandle handle, ViewportOffset offset) {
    {
        assert(handle != nullptr);
        _handle = handle;
    }
}

SliverOverlapAbsorberHandle RenderNestedScrollViewViewportCls::handle() {
    return _handle;
}

void RenderNestedScrollViewViewportCls::handle(SliverOverlapAbsorberHandle value) {
    assert(value != nullptr);
    if (handle() == value) {
        return;
    }
    _handle = value;
    handle()->_markNeedsLayout();
}

void RenderNestedScrollViewViewportCls::markNeedsLayout() {
    handle()->_markNeedsLayout();
    super->markNeedsLayout();
}

void RenderNestedScrollViewViewportCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<SliverOverlapAbsorberHandle>make<DiagnosticsPropertyCls>(__s("handle"), handle()));
}
