#ifndef PACKAGES_FLUTTER_SRC_PHYSICS_TOLERANCE
#define PACKAGES_FLUTTER_SRC_PHYSICS_TOLERANCE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>


class ToleranceCls : public ObjectCls {
public:
    static Tolerance defaultTolerance;

    double distance;

    double time;

    double velocity;


     ToleranceCls(double distance, double time, double velocity);
    virtual String toString();

private:
    static double _epsilonDefault;


};
using Tolerance = std::shared_ptr<ToleranceCls>;


#endif