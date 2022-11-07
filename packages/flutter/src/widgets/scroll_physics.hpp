#ifndef SCROLL_PHYSICS_H
#define SCROLL_PHYSICS_H
#include <memory>
#include <flutter/physics.hpp>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/physics.hpp>
#include "binding.hpp"
#include "framework.hpp"
#include "overscroll_indicator.hpp"
#include "scroll_metrics.hpp"
#include "scroll_simulation.hpp"



class ScrollPhysics {
public:
    ScrollPhysics parent;


     ScrollPhysics(ScrollPhysics parent);

    ScrollPhysics buildParent(ScrollPhysics ancestor);

    ScrollPhysics applyTo(ScrollPhysics ancestor);

    double applyPhysicsToUserOffset(double offset, ScrollMetrics position);

    bool shouldAcceptUserOffset(ScrollMetrics position);

    bool recommendDeferredLoading(BuildContext context, ScrollMetrics metrics, double velocity);

    double applyBoundaryConditions(ScrollMetrics position, double value);

    double adjustPositionForNewDimensions(bool isScrolling, ScrollMetrics newPosition, ScrollMetrics oldPosition, double velocity);

    Simulation createBallisticSimulation(ScrollMetrics position, double velocity);

    SpringDescription spring();

    Tolerance tolerance();

    double minFlingDistance();

    double minFlingVelocity();

    double maxFlingVelocity();

    double carriedMomentum(double existingVelocity);

    double dragStartDistanceMotionThreshold();

    bool allowImplicitScrolling();

    String toString();

private:
    static SpringDescription _kDefaultSpring;

    static Tolerance _kDefaultTolerance;


};

class RangeMaintainingScrollPhysics : ScrollPhysics {
public:

     RangeMaintainingScrollPhysics(Unknown);

    RangeMaintainingScrollPhysics applyTo(ScrollPhysics ancestor);

    double adjustPositionForNewDimensions(bool isScrolling, ScrollMetrics newPosition, ScrollMetrics oldPosition, double velocity);

private:

};

class BouncingScrollPhysics : ScrollPhysics {
public:

     BouncingScrollPhysics(Unknown);

    BouncingScrollPhysics applyTo(ScrollPhysics ancestor);

    double frictionFactor(double overscrollFraction);

    double applyPhysicsToUserOffset(double offset, ScrollMetrics position);

    double applyBoundaryConditions(ScrollMetrics position, double value);

    Simulation createBallisticSimulation(ScrollMetrics position, double velocity);

    double minFlingVelocity();

    double carriedMomentum(double existingVelocity);

    double dragStartDistanceMotionThreshold();

private:

    static double _applyFriction(double absDelta, double extentOutside, double gamma);

};

class ClampingScrollPhysics : ScrollPhysics {
public:

     ClampingScrollPhysics(Unknown);

    ClampingScrollPhysics applyTo(ScrollPhysics ancestor);

    double applyBoundaryConditions(ScrollMetrics position, double value);

    Simulation createBallisticSimulation(ScrollMetrics position, double velocity);

private:

};

class AlwaysScrollableScrollPhysics : ScrollPhysics {
public:

     AlwaysScrollableScrollPhysics(Unknown);

    AlwaysScrollableScrollPhysics applyTo(ScrollPhysics ancestor);

    bool shouldAcceptUserOffset(ScrollMetrics position);

private:

};

class NeverScrollableScrollPhysics : ScrollPhysics {
public:

     NeverScrollableScrollPhysics(Unknown);

    NeverScrollableScrollPhysics applyTo(ScrollPhysics ancestor);

    bool shouldAcceptUserOffset(ScrollMetrics position);

    bool allowImplicitScrolling();

private:

};

#endif