#include "scroll_physics.hpp"
ScrollPhysics ScrollPhysics::buildParent(ScrollPhysics ancestor) {
    return parent?.applyTo(ancestor) ?? ancestor;
}

ScrollPhysics ScrollPhysics::applyTo(ScrollPhysics ancestor) {
    return ScrollPhysics(buildParent(ancestor));
}

double ScrollPhysics::applyPhysicsToUserOffset(double offset, ScrollMetrics position) {
    if (parent == nullptr) {
        return offset;
    }
    return parent!.applyPhysicsToUserOffset(position, offset);
}

bool ScrollPhysics::shouldAcceptUserOffset(ScrollMetrics position) {
    if (parent == nullptr) {
        return position.pixels != 0.0 || position.minScrollExtent != position.maxScrollExtent;
    }
    return parent!.shouldAcceptUserOffset(position);
}

bool ScrollPhysics::recommendDeferredLoading(BuildContext context, ScrollMetrics metrics, double velocity) {
    assert(velocity != nullptr);
    assert(metrics != nullptr);
    assert(context != nullptr);
    if (parent == nullptr) {
        double maxPhysicalPixels = WidgetsBinding.instance.window.physicalSize.longestSide;
        return velocity.abs() > maxPhysicalPixels;
    }
    return parent!.recommendDeferredLoading(velocity, metrics, context);
}

double ScrollPhysics::applyBoundaryConditions(ScrollMetrics position, double value) {
    if (parent == nullptr) {
        return 0.0;
    }
    return parent!.applyBoundaryConditions(position, value);
}

double ScrollPhysics::adjustPositionForNewDimensions(bool isScrolling, ScrollMetrics newPosition, ScrollMetrics oldPosition, double velocity) {
    if (parent == nullptr) {
        return newPosition.pixels;
    }
    return parent!.adjustPositionForNewDimensions(oldPosition, newPosition, isScrolling, velocity);
}

Simulation ScrollPhysics::createBallisticSimulation(ScrollMetrics position, double velocity) {
    if (parent == nullptr) {
        return nullptr;
    }
    return parent!.createBallisticSimulation(position, velocity);
}

SpringDescription ScrollPhysics::spring() {
    return parent?.spring ?? _kDefaultSpring;
}

Tolerance ScrollPhysics::tolerance() {
    return parent?.tolerance ?? _kDefaultTolerance;
}

double ScrollPhysics::minFlingDistance() {
    return parent?.minFlingDistance ?? kTouchSlop;
}

double ScrollPhysics::minFlingVelocity() {
    return parent?.minFlingVelocity ?? kMinFlingVelocity;
}

double ScrollPhysics::maxFlingVelocity() {
    return parent?.maxFlingVelocity ?? kMaxFlingVelocity;
}

double ScrollPhysics::carriedMomentum(double existingVelocity) {
    if (parent == nullptr) {
        return 0.0;
    }
    return parent!.carriedMomentum(existingVelocity);
}

double ScrollPhysics::dragStartDistanceMotionThreshold() {
    return parent?.dragStartDistanceMotionThreshold;
}

bool ScrollPhysics::allowImplicitScrolling() {
    return true;
}

String ScrollPhysics::toString() {
    if (parent == nullptr) {
        return objectRuntimeType(this, "ScrollPhysics");
    }
    return "${objectRuntimeType(this, 'ScrollPhysics')} -> $parent";
}

RangeMaintainingScrollPhysics RangeMaintainingScrollPhysics::applyTo(ScrollPhysics ancestor) {
    return RangeMaintainingScrollPhysics(buildParent(ancestor));
}

double RangeMaintainingScrollPhysics::adjustPositionForNewDimensions(bool isScrolling, ScrollMetrics newPosition, ScrollMetrics oldPosition, double velocity) {
    bool maintainOverscroll = true;
    bool enforceBoundary = true;
    if (velocity != 0.0) {
        maintainOverscroll = false;
        enforceBoundary = false;
    }
    if ((oldPosition.minScrollExtent == newPosition.minScrollExtent) && (oldPosition.maxScrollExtent == newPosition.maxScrollExtent)) {
        maintainOverscroll = false;
    }
    if (oldPosition.pixels != newPosition.pixels) {
        maintainOverscroll = false;
        if (oldPosition.minScrollExtent.isFinite && oldPosition.maxScrollExtent.isFinite && newPosition.minScrollExtent.isFinite && newPosition.maxScrollExtent.isFinite) {
            enforceBoundary = false;
        }
    }
    if ((oldPosition.pixels < oldPosition.minScrollExtent) || (oldPosition.pixels > oldPosition.maxScrollExtent)) {
        enforceBoundary = false;
    }
    if (maintainOverscroll) {
        if (oldPosition.pixels < oldPosition.minScrollExtent && newPosition.minScrollExtent > oldPosition.minScrollExtent) {
            double oldDelta = oldPosition.minScrollExtent - oldPosition.pixels;
            return newPosition.minScrollExtent - oldDelta;
        }
        if (oldPosition.pixels > oldPosition.maxScrollExtent && newPosition.maxScrollExtent < oldPosition.maxScrollExtent) {
            double oldDelta = oldPosition.pixels - oldPosition.maxScrollExtent;
            return newPosition.maxScrollExtent + oldDelta;
        }
    }
    double result = super.adjustPositionForNewDimensions(oldPosition, newPosition, isScrolling, velocity);
    if (enforceBoundary) {
        result = clampDouble(result, newPosition.minScrollExtent, newPosition.maxScrollExtent);
    }
    return result;
}

BouncingScrollPhysics BouncingScrollPhysics::applyTo(ScrollPhysics ancestor) {
    return BouncingScrollPhysics(buildParent(ancestor));
}

double BouncingScrollPhysics::frictionFactor(double overscrollFraction) {
    return 0.52 * math.pow(1 - overscrollFraction, 2);
}

double BouncingScrollPhysics::applyPhysicsToUserOffset(double offset, ScrollMetrics position) {
    assert(offset != 0.0);
    assert(position.minScrollExtent <= position.maxScrollExtent);
    if (!position.outOfRange) {
        return offset;
    }
    double overscrollPastStart = math.max(position.minScrollExtent - position.pixels, 0.0);
    double overscrollPastEnd = math.max(position.pixels - position.maxScrollExtent, 0.0);
    double overscrollPast = math.max(overscrollPastStart, overscrollPastEnd);
    bool easing = (overscrollPastStart > 0.0 &&  < 0.0) || (overscrollPastEnd > 0.0 && offset > 0.0);
    double friction = easing? frictionFactor((overscrollPast - offset.abs()) / position.viewportDimension) : frictionFactor(overscrollPast / position.viewportDimension);
    double direction = offset.sign;
    return direction * _applyFriction(overscrollPast, offset.abs(), friction);
}

double BouncingScrollPhysics::applyBoundaryConditions(ScrollMetrics position, double value) {
    return 0.0;
}

Simulation BouncingScrollPhysics::createBallisticSimulation(ScrollMetrics position, double velocity) {
    Tolerance tolerance = this.tolerance;
    if (velocity.abs() >= tolerance.velocity || position.outOfRange) {
        return BouncingScrollSimulation(spring, position.pixels, velocity, position.minScrollExtent, position.maxScrollExtent, tolerance);
    }
    return nullptr;
}

double BouncingScrollPhysics::minFlingVelocity() {
    return kMinFlingVelocity * 2.0;
}

double BouncingScrollPhysics::carriedMomentum(double existingVelocity) {
    return existingVelocity.sign * math.min(0.000816 * math.pow(existingVelocity.abs(), 1.967).toDouble(), 40000.0);
}

double BouncingScrollPhysics::dragStartDistanceMotionThreshold() {
    return 3.5;
}

double BouncingScrollPhysics::_applyFriction(double absDelta, double extentOutside, double gamma) {
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

ClampingScrollPhysics ClampingScrollPhysics::applyTo(ScrollPhysics ancestor) {
    return ClampingScrollPhysics(buildParent(ancestor));
}

double ClampingScrollPhysics::applyBoundaryConditions(ScrollMetrics position, double value) {
    assert(());
    if ( < position.pixels && position.pixels <= position.minScrollExtent) {
        return value - position.pixels;
    }
    if (position.maxScrollExtent <= position.pixels && position.pixels < value) {
        return value - position.pixels;
    }
    if ( < position.minScrollExtent && position.minScrollExtent < position.pixels) {
        return value - position.minScrollExtent;
    }
    if (position.pixels < position.maxScrollExtent && position.maxScrollExtent < value) {
        return value - position.maxScrollExtent;
    }
    return 0.0;
}

Simulation ClampingScrollPhysics::createBallisticSimulation(ScrollMetrics position, double velocity) {
    Tolerance tolerance = this.tolerance;
    if (position.outOfRange) {
        double end;
        if (position.pixels > position.maxScrollExtent) {
            end = position.maxScrollExtent;
        }
        if (position.pixels < position.minScrollExtent) {
            end = position.minScrollExtent;
        }
        assert(end != nullptr);
        return ScrollSpringSimulation(spring, position.pixels, end!, math.min(0.0, velocity)tolerance);
    }
    if (velocity.abs() < tolerance.velocity) {
        return nullptr;
    }
    if (velocity > 0.0 && position.pixels >= position.maxScrollExtent) {
        return nullptr;
    }
    if ( < 0.0 && position.pixels <= position.minScrollExtent) {
        return nullptr;
    }
    return ClampingScrollSimulation(position.pixels, velocity, tolerance);
}

AlwaysScrollableScrollPhysics AlwaysScrollableScrollPhysics::applyTo(ScrollPhysics ancestor) {
    return AlwaysScrollableScrollPhysics(buildParent(ancestor));
}

bool AlwaysScrollableScrollPhysics::shouldAcceptUserOffset(ScrollMetrics position) {
    return true;
}

NeverScrollableScrollPhysics NeverScrollableScrollPhysics::applyTo(ScrollPhysics ancestor) {
    return NeverScrollableScrollPhysics(buildParent(ancestor));
}

bool NeverScrollableScrollPhysics::shouldAcceptUserOffset(ScrollMetrics position) {
    return false;
}

bool NeverScrollableScrollPhysics::allowImplicitScrolling() {
    return false;
}
