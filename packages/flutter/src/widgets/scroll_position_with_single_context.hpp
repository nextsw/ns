#ifndef SCROLL_POSITION_WITH_SINGLE_CONTEXT_H
#define SCROLL_POSITION_WITH_SINGLE_CONTEXT_H
#include <memory>

#include <math/math.hpp>
#include <flutter/gestures.hpp>
#include <flutter/physics.hpp>
#include <flutter/rendering.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "scroll_activity.hpp"
#include "scroll_context.hpp"
#include "scroll_notification.hpp"
#include "scroll_physics.hpp"
#include "scroll_position.hpp"



class ScrollPositionWithSingleContext : ScrollPosition {
public:

     ScrollPositionWithSingleContext(Unknown, Unknown, double initialPixels, Unknown, Unknown, Unknown);

    AxisDirection axisDirection();

    double setPixels(double newPixels);

    void absorb(ScrollPosition other);

    void applyNewDimensions();

    void beginActivity(ScrollActivity newActivity);

    void applyUserOffset(double delta);

    void goIdle();

    void goBallistic(double velocity);

    ScrollDirection userScrollDirection();

    void updateUserScrollDirection(ScrollDirection value);

    Future<void> animateTo(Curve curve, Duration duration, double to);

    void jumpTo(double value);

    void pointerScroll(double delta);

    void jumpToWithoutSettling(double value);

    ScrollHoldController hold(VoidCallback holdCancelCallback);

    Drag drag(DragStartDetails details, VoidCallback dragCancelCallback);

    void dispose();

    void debugFillDescription(List<String> description);

private:
    double _heldPreviousVelocity;

    ScrollDirection _userScrollDirection;

    ScrollDragController _currentDrag;


};

#endif