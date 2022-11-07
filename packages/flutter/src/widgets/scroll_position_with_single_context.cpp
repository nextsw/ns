#include "scroll_position_with_single_context.hpp"
ScrollPositionWithSingleContext::ScrollPositionWithSingleContext(Unknown, Unknown, double initialPixels, Unknown, Unknown, Unknown) {
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

AxisDirection ScrollPositionWithSingleContext::axisDirection() {
    return context.axisDirection;
}

double ScrollPositionWithSingleContext::setPixels(double newPixels) {
    assert(activity!.isScrolling);
    return super.setPixels(newPixels);
}

void ScrollPositionWithSingleContext::absorb(ScrollPosition other) {
    super.absorb(other);
    if (other is! ScrollPositionWithSingleContext) {
        goIdle();
        return;
    }
    activity!.updateDelegate(this);
    _userScrollDirection = other._userScrollDirection;
    assert(_currentDrag == nullptr);
    if (other._currentDrag != nullptr) {
        _currentDrag = other._currentDrag;
        _currentDrag!.updateDelegate(this);
        other._currentDrag = nullptr;
    }
}

void ScrollPositionWithSingleContext::applyNewDimensions() {
    super.applyNewDimensions();
    context.setCanDrag(physics.shouldAcceptUserOffset(this));
}

void ScrollPositionWithSingleContext::beginActivity(ScrollActivity newActivity) {
    _heldPreviousVelocity = 0.0;
    if (newActivity == nullptr) {
        return;
    }
    assert(newActivity.delegate == this);
    super.beginActivity(newActivity);
    _currentDrag?.dispose();
    _currentDrag = nullptr;
    if (!activity!.isScrolling) {
        updateUserScrollDirection(ScrollDirection.idle);
    }
}

void ScrollPositionWithSingleContext::applyUserOffset(double delta) {
    updateUserScrollDirection(delta > 0.0? ScrollDirection.forward : ScrollDirection.reverse);
    setPixels(pixels - physics.applyPhysicsToUserOffset(this, delta));
}

void ScrollPositionWithSingleContext::goIdle() {
    beginActivity(IdleScrollActivity(this));
}

void ScrollPositionWithSingleContext::goBallistic(double velocity) {
    assert(hasPixels);
    Simulation simulation = physics.createBallisticSimulation(this, velocity);
    if (simulation != nullptr) {
        beginActivity(BallisticScrollActivity(this, simulation, context.vsync));
    } else {
        goIdle();
    }
}

ScrollDirection ScrollPositionWithSingleContext::userScrollDirection() {
    return _userScrollDirection;
}

void ScrollPositionWithSingleContext::updateUserScrollDirection(ScrollDirection value) {
    assert(value != nullptr);
    if (userScrollDirection == value) {
        return;
    }
    _userScrollDirection = value;
    didUpdateScrollDirection(value);
}

Future<void> ScrollPositionWithSingleContext::animateTo(Curve curve, Duration duration, double to) {
    if (nearEqual(to, pixels, physics.tolerance.distance)) {
        jumpTo(to);
        return <void>value();
    }
    DrivenScrollActivity activity = DrivenScrollActivity(thispixels, to, duration, curve, context.vsync);
    beginActivity(activity);
    return activity.done;
}

void ScrollPositionWithSingleContext::jumpTo(double value) {
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

void ScrollPositionWithSingleContext::pointerScroll(double delta) {
    assert(delta != 0.0);
    double targetPixels = math.min(math.max(pixels + delta, minScrollExtent), maxScrollExtent);
    if (targetPixels != pixels) {
        goIdle();
        updateUserScrollDirection(-delta > 0.0? ScrollDirection.forward : ScrollDirection.reverse);
        double oldPixels = pixels;
        forcePixels(targetPixels);
        isScrollingNotifier.value = true;
        didStartScroll();
        didUpdateScrollPositionBy(pixels - oldPixels);
        didEndScroll();
        goBallistic(0.0);
    }
}

void ScrollPositionWithSingleContext::jumpToWithoutSettling(double value) {
    goIdle();
    if (pixels != value) {
        double oldPixels = pixels;
        forcePixels(value);
        didStartScroll();
        didUpdateScrollPositionBy(pixels - oldPixels);
        didEndScroll();
    }
}

ScrollHoldController ScrollPositionWithSingleContext::hold(VoidCallback holdCancelCallback) {
    double previousVelocity = activity!.velocity;
    HoldScrollActivity holdActivity = HoldScrollActivity(this, holdCancelCallback);
    beginActivity(holdActivity);
    _heldPreviousVelocity = previousVelocity;
    return holdActivity;
}

Drag ScrollPositionWithSingleContext::drag(DragStartDetails details, VoidCallback dragCancelCallback) {
    ScrollDragController drag = ScrollDragController(this, details, dragCancelCallback, physics.carriedMomentum(_heldPreviousVelocity), physics.dragStartDistanceMotionThreshold);
    beginActivity(DragScrollActivity(this, drag));
    assert(_currentDrag == nullptr);
    _currentDrag = drag;
    return drag;
}

void ScrollPositionWithSingleContext::dispose() {
    _currentDrag?.dispose();
    _currentDrag = nullptr;
    super.dispose();
}

void ScrollPositionWithSingleContext::debugFillDescription(List<String> description) {
    super.debugFillDescription(description);
    description.add("${context.runtimeType}");
    description.add("$physics");
    description.add("$activity");
    description.add("$userScrollDirection");
}
