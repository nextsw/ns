#ifndef DRAG_DETAILS_H
#define DRAG_DETAILS_H
#include <memory>
#include <ui.hpp>
#include "velocity_tracker.hpp"

#include <flutter/foundation.hpp>
#include "velocity_tracker.hpp"



class DragDownDetails {
public:
    Offset globalPosition;

    Offset localPosition;


     DragDownDetails(Offset globalPosition, Offset localPosition);

    String toString();

private:

};

class DragStartDetails {
public:
    Duration sourceTimeStamp;

    Offset globalPosition;

    Offset localPosition;

    PointerDeviceKind kind;


     DragStartDetails(Offset globalPosition, PointerDeviceKind kind, Offset localPosition, Duration sourceTimeStamp);

    String toString();

private:

};

class DragUpdateDetails {
public:
    Duration sourceTimeStamp;

    Offset delta;

    double primaryDelta;

    Offset globalPosition;

    Offset localPosition;


     DragUpdateDetails(Offset delta, Offset globalPosition, Offset localPosition, double primaryDelta, Duration sourceTimeStamp);

    String toString();

private:

};

class DragEndDetails {
public:
    Velocity velocity;

    double primaryVelocity;


     DragEndDetails(double primaryVelocity, Velocity velocity);

    String toString();

private:

};

#endif