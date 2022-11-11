#include "scroll_position_with_single_context.hpp"
ScrollPositionWithSingleContextCls::ScrollPositionWithSingleContextCls(Unknown context, Unknown debugLabel, double initialPixels, Unknown keepScrollOffset, Unknown oldPosition, Unknown physics) {
    {
        if (!hasPixels && initialPixels != nullptr) {
            correctPixels(initialPixels);
        }
        if (activity == nullptr) {
            goIdle();
        }
        assert(activity != nullptr);
    }
}

AxisDirection ScrollPositionWithSingleContextCls::axisDirection() {
    return context->axisDirection;
}

double ScrollPositionWithSingleContextCls::setPixels(double newPixels) {
    assert(activity!->isScrolling);
    return super->setPixels(newPixels);
}

void ScrollPositionWithSingleContextCls::absorb(ScrollPosition other) {
    super->absorb(other);
    if (!is<ScrollPositionWithSingleContext>(other)) {
        goIdle();
        return;
    }
    activity!->updateDelegate(this);
    _userScrollDirection = other->_userScrollDirection;
    assert(_currentDrag == nullptr);
    if (other->_currentDrag != nullptr) {
        _currentDrag = other->_currentDrag;
        _currentDrag!->updateDelegate(this);
        other->_currentDrag = nullptr;
    }
}

void ScrollPositionWithSingleContextCls::applyNewDimensions() {
    super->applyNewDimensions();
    context->setCanDrag(physics->shouldAcceptUserOffset(this));
}

void ScrollPositionWithSingleContextCls::beginActivity(ScrollActivity newActivity) {
    _heldPreviousVelocity = 0.0;
    if (newActivity == nullptr) {
        return;
    }
    assert(newActivity->delegate() == this);
    super->beginActivity(newActivity);
    _currentDrag?->dispose();
    _currentDrag = nullptr;
    if (!activity!->isScrolling) {
        updateUserScrollDirection(ScrollDirectionCls::idle);
    }
}

void ScrollPositionWithSingleContextCls::applyUserOffset(double delta) {
    updateUserScrollDirection(delta > 0.0? ScrollDirectionCls::forward : ScrollDirectionCls::reverse);
    setPixels(pixels - physics->applyPhysicsToUserOffset(this, delta));
}

void ScrollPositionWithSingleContextCls::goIdle() {
    beginActivity(make<IdleScrollActivityCls>(this));
}

void ScrollPositionWithSingleContextCls::goBallistic(double velocity) {
    assert(hasPixels);
    Simulation simulation = physics->createBallisticSimulation(this, velocity);
    if (simulation != nullptr) {
        beginActivity(make<BallisticScrollActivityCls>(this, simulation, context->vsync));
    } else {
        goIdle();
    }
}

ScrollDirection ScrollPositionWithSingleContextCls::userScrollDirection() {
    return _userScrollDirection;
}

void ScrollPositionWithSingleContextCls::updateUserScrollDirection(ScrollDirection value) {
    assert(value != nullptr);
    if (userScrollDirection() == value) {
        return;
    }
    _userScrollDirection = value;
    didUpdateScrollDirection(value);
}

Future<void> ScrollPositionWithSingleContextCls::animateTo(Curve curve, Duration duration, double to) {
    if (nearEqual(to, pixels, physics->tolerance->distance)) {
        jumpTo(to);
        return <void>value();
    }
    DrivenScrollActivity activity = make<DrivenScrollActivityCls>(thispixels, to, duration, curve, context->vsync);
    beginActivity(activity);
    return activity->done();
}

void ScrollPositionWithSingleContextCls::jumpTo(double value) {
    goIdle();
    if (pixels != value) {
        double oldPixels = pixels;
        forcePixels(value);
        didStartScroll();
        didUpdateScrollPositionBy(pixels - oldPixels);
        didEndScroll();
    }
    goBallistic(0.0);
}

void ScrollPositionWithSingleContextCls::pointerScroll(double delta) {
    assert(delta != 0.0);
    double targetPixels = math->min(math->max(pixels + delta, minScrollExtent), maxScrollExtent);
    if (targetPixels != pixels) {
        goIdle();
        updateUserScrollDirection(-delta > 0.0? ScrollDirectionCls::forward : ScrollDirectionCls::reverse);
        double oldPixels = pixels;
        forcePixels(targetPixels);
        isScrollingNotifier->value = true;
        didStartScroll();
        didUpdateScrollPositionBy(pixels - oldPixels);
        didEndScroll();
        goBallistic(0.0);
    }
}

void ScrollPositionWithSingleContextCls::jumpToWithoutSettling(double value) {
    goIdle();
    if (pixels != value) {
        double oldPixels = pixels;
        forcePixels(value);
        didStartScroll();
        didUpdateScrollPositionBy(pixels - oldPixels);
        didEndScroll();
    }
}

ScrollHoldController ScrollPositionWithSingleContextCls::hold(VoidCallback holdCancelCallback) {
    double previousVelocity = activity!->velocity;
    HoldScrollActivity holdActivity = make<HoldScrollActivityCls>(this, holdCancelCallback);
    beginActivity(holdActivity);
    _heldPreviousVelocity = previousVelocity;
    return holdActivity;
}

Drag ScrollPositionWithSingleContextCls::drag(DragStartDetails details, VoidCallback dragCancelCallback) {
    ScrollDragController drag = make<ScrollDragControllerCls>(this, details, dragCancelCallback, physics->carriedMomentum(_heldPreviousVelocity), physics->dragStartDistanceMotionThreshold);
    beginActivity(make<DragScrollActivityCls>(this, drag));
    assert(_currentDrag == nullptr);
    _currentDrag = drag;
    return drag;
}

void ScrollPositionWithSingleContextCls::dispose() {
    _currentDrag?->dispose();
    _currentDrag = nullptr;
    super->dispose();
}

void ScrollPositionWithSingleContextCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    description->add(__s("${context.runtimeType}"));
    description->add(__s("$physics"));
    description->add(__s("$activity"));
    description->add(__s("$userScrollDirection"));
}
