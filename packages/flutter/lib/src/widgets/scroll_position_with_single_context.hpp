#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_POSITION_WITH_SINGLE_CONTEXT
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_POSITION_WITH_SINGLE_CONTEXT
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "scroll_activity.hpp"
#include "scroll_context.hpp"
#include "scroll_notification.hpp"
#include "scroll_physics.hpp"
#include "scroll_position.hpp"


class ScrollPositionWithSingleContextCls : public ScrollPositionCls {
public:

     ScrollPositionWithSingleContextCls(Unknown context, Unknown debugLabel, double initialPixels, Unknown keepScrollOffset, Unknown oldPosition, Unknown physics);

    virtual AxisDirection axisDirection();

    virtual double setPixels(double newPixels);

    virtual void absorb(ScrollPosition other);

    virtual void applyNewDimensions();

    virtual void beginActivity(ScrollActivity newActivity);

    virtual void applyUserOffset(double delta);

    virtual void goIdle();

    virtual void goBallistic(double velocity);

    virtual ScrollDirection userScrollDirection();

    virtual void updateUserScrollDirection(ScrollDirection value);

    virtual Future<void> animateTo(double to, Curve curve, Duration duration);

    virtual void jumpTo(double value);

    virtual void pointerScroll(double delta);

    virtual void jumpToWithoutSettling(double value);

    virtual ScrollHoldController hold(VoidCallback holdCancelCallback);

    virtual Drag drag(DragStartDetails details, VoidCallback dragCancelCallback);

    virtual void dispose();

    virtual void debugFillDescription(List<String> description);

private:
    double _heldPreviousVelocity;

    ScrollDirection _userScrollDirection;

    ScrollDragController _currentDrag;


};
using ScrollPositionWithSingleContext = std::shared_ptr<ScrollPositionWithSingleContextCls>;


#endif