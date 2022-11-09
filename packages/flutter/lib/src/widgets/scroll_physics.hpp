#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_PHYSICS
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_PHYSICS
#include <base.hpp>
#include <packages/flutter/flutter.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "binding.hpp"
#include "framework.hpp"
#include "overscroll_indicator.hpp"
#include "scroll_metrics.hpp"
#include "scroll_simulation.hpp"


class ScrollPhysicsCls : public ObjectCls {
public:
    ScrollPhysics parent;


     ScrollPhysicsCls(ScrollPhysics parent);
    virtual ScrollPhysics buildParent(ScrollPhysics ancestor);

    virtual ScrollPhysics applyTo(ScrollPhysics ancestor);

    virtual double applyPhysicsToUserOffset(double offset, ScrollMetrics position);

    virtual bool shouldAcceptUserOffset(ScrollMetrics position);

    virtual bool recommendDeferredLoading(BuildContext context, ScrollMetrics metrics, double velocity);

    virtual double applyBoundaryConditions(ScrollMetrics position, double value);

    virtual double adjustPositionForNewDimensions(bool isScrolling, ScrollMetrics newPosition, ScrollMetrics oldPosition, double velocity);

    virtual Simulation createBallisticSimulation(ScrollMetrics position, double velocity);

    virtual SpringDescription spring();

    virtual Tolerance tolerance();

    virtual double minFlingDistance();

    virtual double minFlingVelocity();

    virtual double maxFlingVelocity();

    virtual double carriedMomentum(double existingVelocity);

    virtual double dragStartDistanceMotionThreshold();

    virtual bool allowImplicitScrolling();

    virtual String toString();

private:
    static SpringDescription _kDefaultSpring;

    static Tolerance _kDefaultTolerance;


};
using ScrollPhysics = std::shared_ptr<ScrollPhysicsCls>;

class RangeMaintainingScrollPhysicsCls : public ScrollPhysicsCls {
public:

     RangeMaintainingScrollPhysicsCls(Unknown parent);
    virtual RangeMaintainingScrollPhysics applyTo(ScrollPhysics ancestor);

    virtual double adjustPositionForNewDimensions(bool isScrolling, ScrollMetrics newPosition, ScrollMetrics oldPosition, double velocity);

private:

};
using RangeMaintainingScrollPhysics = std::shared_ptr<RangeMaintainingScrollPhysicsCls>;

class BouncingScrollPhysicsCls : public ScrollPhysicsCls {
public:

     BouncingScrollPhysicsCls(Unknown parent);
    virtual BouncingScrollPhysics applyTo(ScrollPhysics ancestor);

    virtual double frictionFactor(double overscrollFraction);

    virtual double applyPhysicsToUserOffset(double offset, ScrollMetrics position);

    virtual double applyBoundaryConditions(ScrollMetrics position, double value);

    virtual Simulation createBallisticSimulation(ScrollMetrics position, double velocity);

    virtual double minFlingVelocity();

    virtual double carriedMomentum(double existingVelocity);

    virtual double dragStartDistanceMotionThreshold();

private:

    static double _applyFriction(double absDelta, double extentOutside, double gamma);

};
using BouncingScrollPhysics = std::shared_ptr<BouncingScrollPhysicsCls>;

class ClampingScrollPhysicsCls : public ScrollPhysicsCls {
public:

     ClampingScrollPhysicsCls(Unknown parent);
    virtual ClampingScrollPhysics applyTo(ScrollPhysics ancestor);

    virtual double applyBoundaryConditions(ScrollMetrics position, double value);

    virtual Simulation createBallisticSimulation(ScrollMetrics position, double velocity);

private:

};
using ClampingScrollPhysics = std::shared_ptr<ClampingScrollPhysicsCls>;

class AlwaysScrollableScrollPhysicsCls : public ScrollPhysicsCls {
public:

     AlwaysScrollableScrollPhysicsCls(Unknown parent);
    virtual AlwaysScrollableScrollPhysics applyTo(ScrollPhysics ancestor);

    virtual bool shouldAcceptUserOffset(ScrollMetrics position);

private:

};
using AlwaysScrollableScrollPhysics = std::shared_ptr<AlwaysScrollableScrollPhysicsCls>;

class NeverScrollableScrollPhysicsCls : public ScrollPhysicsCls {
public:

     NeverScrollableScrollPhysicsCls(Unknown parent);
    virtual NeverScrollableScrollPhysics applyTo(ScrollPhysics ancestor);

    virtual bool shouldAcceptUserOffset(ScrollMetrics position);

    virtual bool allowImplicitScrolling();

private:

};
using NeverScrollableScrollPhysics = std::shared_ptr<NeverScrollableScrollPhysicsCls>;


#endif