#include "scroll_physics.hpp"
ScrollPhysics ScrollPhysicsCls::buildParent(ScrollPhysics ancestor) {
    return parent?->applyTo(ancestor) or ancestor;
}

ScrollPhysics ScrollPhysicsCls::applyTo(ScrollPhysics ancestor) {
    return make<ScrollPhysicsCls>(buildParent(ancestor));
}

double ScrollPhysicsCls::applyPhysicsToUserOffset(double offset, ScrollMetrics position) {
    if (parent == nullptr) {
        return offset;
    }
    return parent!->applyPhysicsToUserOffset(position, offset);
}

bool ScrollPhysicsCls::shouldAcceptUserOffset(ScrollMetrics position) {
    if (parent == nullptr) {
        return position->pixels() != 0.0 || position->minScrollExtent() != position->maxScrollExtent();
    }
    return parent!->shouldAcceptUserOffset(position);
}

bool ScrollPhysicsCls::recommendDeferredLoading(BuildContext context, ScrollMetrics metrics, double velocity) {
    assert(velocity != nullptr);
    assert(metrics != nullptr);
    assert(context != nullptr);
    if (parent == nullptr) {
        double maxPhysicalPixels = WidgetsBindingCls::instance->window->physicalSize->longestSide;
        return velocity->abs() > maxPhysicalPixels;
    }
    return parent!->recommendDeferredLoading(velocity, metrics, context);
}

double ScrollPhysicsCls::applyBoundaryConditions(ScrollMetrics position, double value) {
    if (parent == nullptr) {
        return 0.0;
    }
    return parent!->applyBoundaryConditions(position, value);
}

double ScrollPhysicsCls::adjustPositionForNewDimensions(bool isScrolling, ScrollMetrics newPosition, ScrollMetrics oldPosition, double velocity) {
    if (parent == nullptr) {
        return newPosition->pixels();
    }
    return parent!->adjustPositionForNewDimensions(oldPosition, newPosition, isScrolling, velocity);
}

Simulation ScrollPhysicsCls::createBallisticSimulation(ScrollMetrics position, double velocity) {
    if (parent == nullptr) {
        return nullptr;
    }
    return parent!->createBallisticSimulation(position, velocity);
}

SpringDescription ScrollPhysicsCls::spring() {
    return parent?->spring() or _kDefaultSpring;
}

Tolerance ScrollPhysicsCls::tolerance() {
    return parent?->tolerance() or _kDefaultTolerance;
}

double ScrollPhysicsCls::minFlingDistance() {
    return parent?->minFlingDistance() or kTouchSlop;
}

double ScrollPhysicsCls::minFlingVelocity() {
    return parent?->minFlingVelocity() or kMinFlingVelocity;
}

double ScrollPhysicsCls::maxFlingVelocity() {
    return parent?->maxFlingVelocity() or kMaxFlingVelocity;
}

double ScrollPhysicsCls::carriedMomentum(double existingVelocity) {
    if (parent == nullptr) {
        return 0.0;
    }
    return parent!->carriedMomentum(existingVelocity);
}

double ScrollPhysicsCls::dragStartDistanceMotionThreshold() {
    return parent?->dragStartDistanceMotionThreshold();
}

bool ScrollPhysicsCls::allowImplicitScrolling() {
    return true;
}

String ScrollPhysicsCls::toString() {
    if (parent == nullptr) {
        return objectRuntimeType(this, __s("ScrollPhysics"));
    }
    return __s("${objectRuntimeType(this, 'ScrollPhysics')} -> $parent");
}

RangeMaintainingScrollPhysics RangeMaintainingScrollPhysicsCls::applyTo(ScrollPhysics ancestor) {
    return make<RangeMaintainingScrollPhysicsCls>(buildParent(ancestor));
}

double RangeMaintainingScrollPhysicsCls::adjustPositionForNewDimensions(bool isScrolling, ScrollMetrics newPosition, ScrollMetrics oldPosition, double velocity) {
    bool maintainOverscroll = true;
    bool enforceBoundary = true;
    if (velocity != 0.0) {
        maintainOverscroll = false;
        enforceBoundary = false;
    }
    if ((oldPosition->minScrollExtent() == newPosition->minScrollExtent()) && (oldPosition->maxScrollExtent() == newPosition->maxScrollExtent())) {
        maintainOverscroll = false;
    }
    if (oldPosition->pixels() != newPosition->pixels()) {
        maintainOverscroll = false;
        if (oldPosition->minScrollExtent()->isFinite && oldPosition->maxScrollExtent()->isFinite && newPosition->minScrollExtent()->isFinite && newPosition->maxScrollExtent()->isFinite) {
            enforceBoundary = false;
        }
    }
    if ((oldPosition->pixels() < oldPosition->minScrollExtent()) || (oldPosition->pixels() > oldPosition->maxScrollExtent())) {
        enforceBoundary = false;
    }
    if (maintainOverscroll) {
        if (oldPosition->pixels() < oldPosition->minScrollExtent() && newPosition->minScrollExtent() > oldPosition->minScrollExtent()) {
            double oldDelta = oldPosition->minScrollExtent() - oldPosition->pixels();
            return newPosition->minScrollExtent() - oldDelta;
        }
        if (oldPosition->pixels() > oldPosition->maxScrollExtent() && newPosition->maxScrollExtent() < oldPosition->maxScrollExtent()) {
            double oldDelta = oldPosition->pixels() - oldPosition->maxScrollExtent();
            return newPosition->maxScrollExtent() + oldDelta;
        }
    }
    double result = super->adjustPositionForNewDimensions(oldPosition, newPosition, isScrolling, velocity);
    if (enforceBoundary) {
        result = clampDouble(result, newPosition->minScrollExtent(), newPosition->maxScrollExtent());
    }
    return result;
}

BouncingScrollPhysics BouncingScrollPhysicsCls::applyTo(ScrollPhysics ancestor) {
    return make<BouncingScrollPhysicsCls>(buildParent(ancestor));
}

double BouncingScrollPhysicsCls::frictionFactor(double overscrollFraction) {
    return 0.52 * math->pow(1 - overscrollFraction, 2);
}

double BouncingScrollPhysicsCls::applyPhysicsToUserOffset(double offset, ScrollMetrics position) {
    assert(offset != 0.0);
    assert(position->minScrollExtent() <= position->maxScrollExtent());
    if (!position->outOfRange()) {
        return offset;
    }
    double overscrollPastStart = math->max(position->minScrollExtent() - position->pixels(), 0.0);
    double overscrollPastEnd = math->max(position->pixels() - position->maxScrollExtent(), 0.0);
    double overscrollPast = math->max(overscrollPastStart, overscrollPastEnd);
    bool easing = (overscrollPastStart > 0.0 &&  < 0.0) || (overscrollPastEnd > 0.0 && offset > 0.0);
    double friction = easing? frictionFactor((overscrollPast - offset->abs()) / position->viewportDimension()) : frictionFactor(overscrollPast / position->viewportDimension());
    double direction = offset->sign();
    return direction * _applyFriction(overscrollPast, offset->abs(), friction);
}

double BouncingScrollPhysicsCls::applyBoundaryConditions(ScrollMetrics position, double value) {
    return 0.0;
}

Simulation BouncingScrollPhysicsCls::createBallisticSimulation(ScrollMetrics position, double velocity) {
    Tolerance tolerance = this->tolerance;
    if (velocity->abs() >= tolerance->velocity || position->outOfRange()) {
        return make<BouncingScrollSimulationCls>(spring, position->pixels(), velocity, position->minScrollExtent(), position->maxScrollExtent(), tolerance);
    }
    return nullptr;
}

double BouncingScrollPhysicsCls::minFlingVelocity() {
    return kMinFlingVelocity * 2.0;
}

double BouncingScrollPhysicsCls::carriedMomentum(double existingVelocity) {
    return existingVelocity->sign() * math->min(0.000816 * math->pow(existingVelocity->abs(), 1.967)->toDouble(), 40000.0);
}

double BouncingScrollPhysicsCls::dragStartDistanceMotionThreshold() {
    return 3.5;
}

double BouncingScrollPhysicsCls::_applyFriction(double absDelta, double extentOutside, double gamma) {
    assert(absDelta > 0);
    double total = 0.0;
    if (extentOutside > 0) {
        double deltaToLimit = extentOutside / gamma;
        if ( < deltaToLimit) {
            return absDelta * gamma;
        }
        total = extentOutside;
        absDelta = deltaToLimit;
    }
    return total + absDelta;
}

ClampingScrollPhysics ClampingScrollPhysicsCls::applyTo(ScrollPhysics ancestor) {
    return make<ClampingScrollPhysicsCls>(buildParent(ancestor));
}

double ClampingScrollPhysicsCls::applyBoundaryConditions(ScrollMetrics position, double value) {
    assert([=] () {
        if (value == position->pixels()) {
            ;
        }
        return true;
    }());
    if ( < position->pixels() && position->pixels() <= position->minScrollExtent()) {
        return value - position->pixels();
    }
    if (position->maxScrollExtent() <= position->pixels() && position->pixels() < value) {
        return value - position->pixels();
    }
    if ( < position->minScrollExtent() && position->minScrollExtent() < position->pixels()) {
        return value - position->minScrollExtent();
    }
    if (position->pixels() < position->maxScrollExtent() && position->maxScrollExtent() < value) {
        return value - position->maxScrollExtent();
    }
    return 0.0;
}

Simulation ClampingScrollPhysicsCls::createBallisticSimulation(ScrollMetrics position, double velocity) {
    Tolerance tolerance = this->tolerance;
    if (position->outOfRange()) {
        double end;
        if (position->pixels() > position->maxScrollExtent()) {
            end = position->maxScrollExtent();
        }
        if (position->pixels() < position->minScrollExtent()) {
            end = position->minScrollExtent();
        }
        assert(end != nullptr);
        return make<ScrollSpringSimulationCls>(spring, position->pixels(), end!, math->min(0.0, velocity)tolerance);
    }
    if (velocity->abs() < tolerance->velocity) {
        return nullptr;
    }
    if (velocity > 0.0 && position->pixels() >= position->maxScrollExtent()) {
        return nullptr;
    }
    if ( < 0.0 && position->pixels() <= position->minScrollExtent()) {
        return nullptr;
    }
    return make<ClampingScrollSimulationCls>(position->pixels(), velocity, tolerance);
}

AlwaysScrollableScrollPhysics AlwaysScrollableScrollPhysicsCls::applyTo(ScrollPhysics ancestor) {
    return make<AlwaysScrollableScrollPhysicsCls>(buildParent(ancestor));
}

bool AlwaysScrollableScrollPhysicsCls::shouldAcceptUserOffset(ScrollMetrics position) {
    return true;
}

NeverScrollableScrollPhysics NeverScrollableScrollPhysicsCls::applyTo(ScrollPhysics ancestor) {
    return make<NeverScrollableScrollPhysicsCls>(buildParent(ancestor));
}

bool NeverScrollableScrollPhysicsCls::shouldAcceptUserOffset(ScrollMetrics position) {
    return false;
}

bool NeverScrollableScrollPhysicsCls::allowImplicitScrolling() {
    return false;
}
