#ifndef PACKAGES_FLUTTER_SRC_GESTURES_DRAG_DETAILS
#define PACKAGES_FLUTTER_SRC_GESTURES_DRAG_DETAILS
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include "velocity_tracker.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "velocity_tracker.hpp"


class DragDownDetailsCls : public ObjectCls {
public:
    Offset globalPosition;

    Offset localPosition;


     DragDownDetailsCls(Offset globalPosition, Offset localPosition);

    virtual String toString();

private:

};
using DragDownDetails = std::shared_ptr<DragDownDetailsCls>;

class DragStartDetailsCls : public ObjectCls {
public:
    Duration sourceTimeStamp;

    Offset globalPosition;

    Offset localPosition;

    PointerDeviceKind kind;


     DragStartDetailsCls(Offset globalPosition, PointerDeviceKind kind, Offset localPosition, Duration sourceTimeStamp);

    virtual String toString();

private:

};
using DragStartDetails = std::shared_ptr<DragStartDetailsCls>;

class DragUpdateDetailsCls : public ObjectCls {
public:
    Duration sourceTimeStamp;

    Offset delta;

    double primaryDelta;

    Offset globalPosition;

    Offset localPosition;


     DragUpdateDetailsCls(Offset delta, Offset globalPosition, Offset localPosition, double primaryDelta, Duration sourceTimeStamp);

    virtual String toString();

private:

};
using DragUpdateDetails = std::shared_ptr<DragUpdateDetailsCls>;

class DragEndDetailsCls : public ObjectCls {
public:
    Velocity velocity;

    double primaryVelocity;


     DragEndDetailsCls(double primaryVelocity, Velocity velocity);

    virtual String toString();

private:

};
using DragEndDetails = std::shared_ptr<DragEndDetailsCls>;


#endif