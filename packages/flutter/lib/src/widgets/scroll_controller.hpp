#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_CONTROLLER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_CONTROLLER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "scroll_context.hpp"
#include "scroll_physics.hpp"
#include "scroll_position.hpp"
#include "scroll_position_with_single_context.hpp"


class ScrollControllerCls : public ChangeNotifierCls {
public:
    bool keepScrollOffset;

    String debugLabel;


     ScrollControllerCls(String debugLabel, double initialScrollOffset, bool keepScrollOffset);

    virtual double initialScrollOffset();

    virtual Iterable<ScrollPosition> positions();

    virtual bool hasClients();

    virtual ScrollPosition position();

    virtual double offset();

    virtual Future<void> animateTo(double offset, Curve curve, Duration duration);

    virtual void jumpTo(double value);

    virtual void attach(ScrollPosition position);

    virtual void detach(ScrollPosition position);

    virtual void dispose();

    virtual ScrollPosition createScrollPosition(ScrollPhysics physics, ScrollContext context, ScrollPosition oldPosition);

    virtual String toString();

    virtual void debugFillDescription(List<String> description);

private:
    double _initialScrollOffset;

    List<ScrollPosition> _positions;


};
using ScrollController = std::shared_ptr<ScrollControllerCls>;

class TrackingScrollControllerCls : public ScrollControllerCls {
public:

     TrackingScrollControllerCls(String debugLabel, Unknown initialScrollOffset, bool keepScrollOffset);
    virtual ScrollPosition mostRecentlyUpdatedPosition();

    virtual double initialScrollOffset();

    virtual void attach(ScrollPosition position);

    virtual void detach(ScrollPosition position);

    virtual void dispose();

private:
    Map<ScrollPosition, VoidCallback> _positionToListener;

    ScrollPosition _lastUpdated;

    double _lastUpdatedOffset;


};
using TrackingScrollController = std::shared_ptr<TrackingScrollControllerCls>;


#endif