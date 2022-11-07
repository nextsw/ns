#ifndef SCROLL_CONTROLLER_H
#define SCROLL_CONTROLLER_H
#include <memory>

#include <flutter/animation.hpp>
#include <flutter/foundation.hpp>
#include "scroll_context.hpp"
#include "scroll_physics.hpp"
#include "scroll_position.hpp"
#include "scroll_position_with_single_context.hpp"



class ScrollController : ChangeNotifier {
public:
    bool keepScrollOffset;

    String debugLabel;


     ScrollController(String debugLabel, double initialScrollOffset, bool keepScrollOffset);

    double initialScrollOffset();

    Iterable<ScrollPosition> positions();

    bool hasClients();

    ScrollPosition position();

    double offset();

    Future<void> animateTo(Curve curve, Duration duration, double offset);

    void jumpTo(double value);

    void attach(ScrollPosition position);

    void detach(ScrollPosition position);

    void dispose();

    ScrollPosition createScrollPosition(ScrollContext context, ScrollPosition oldPosition, ScrollPhysics physics);

    String toString();

    void debugFillDescription(List<String> description);

private:
    double _initialScrollOffset;

    List<ScrollPosition> _positions;


};

class TrackingScrollController : ScrollController {
public:

     TrackingScrollController(Unknown, Unknown, Unknown);

    ScrollPosition mostRecentlyUpdatedPosition();

    double initialScrollOffset();

    void attach(ScrollPosition position);

    void detach(ScrollPosition position);

    void dispose();

private:
    Map<ScrollPosition, VoidCallback> _positionToListener;

    ScrollPosition _lastUpdated;

    double _lastUpdatedOffset;


};

#endif