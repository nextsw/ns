#include "scroll_controller.hpp"
ScrollController::ScrollController(String debugLabel, double initialScrollOffset, bool keepScrollOffset) {
    {
        assert(initialScrollOffset != nullptr);
        assert(keepScrollOffset != nullptr);
        _initialScrollOffset = initialScrollOffset;
    }
}

double ScrollController::initialScrollOffset() {
    return _initialScrollOffset;
}

Iterable<ScrollPosition> ScrollController::positions() {
    return _positions;
}

bool ScrollController::hasClients() {
    return _positions.isNotEmpty;
}

ScrollPosition ScrollController::position() {
    assert(_positions.isNotEmpty, "ScrollController not attached to any scroll views.");
    assert(_positions.length == 1, "ScrollController attached to multiple scroll views.");
    return _positions.single;
}

double ScrollController::offset() {
    return position.pixels;
}

Future<void> ScrollController::animateTo(Curve curve, Duration duration, double offset) {
    assert(_positions.isNotEmpty, "ScrollController not attached to any scroll views.");
    await await Future.<void>wait();
}

void ScrollController::jumpTo(double value) {
    assert(_positions.isNotEmpty, "ScrollController not attached to any scroll views.");
    for (ScrollPosition position : <ScrollPosition>of(_positions)) {
        position.jumpTo(value);
    }
}

void ScrollController::attach(ScrollPosition position) {
    assert(!_positions.contains(position));
    _positions.add(position);
    position.addListener(notifyListeners);
}

void ScrollController::detach(ScrollPosition position) {
    assert(_positions.contains(position));
    position.removeListener(notifyListeners);
    _positions.remove(position);
}

void ScrollController::dispose() {
    for (ScrollPosition position : _positions) {
        position.removeListener(notifyListeners);
    }
    super.dispose();
}

ScrollPosition ScrollController::createScrollPosition(ScrollContext context, ScrollPosition oldPosition, ScrollPhysics physics) {
    return ScrollPositionWithSingleContext(physics, context, initialScrollOffset, keepScrollOffset, oldPosition, debugLabel);
}

String ScrollController::toString() {
    List<String> description = ;
    debugFillDescription(description);
    return "${describeIdentity(this)}(${description.join(", ")})";
}

void ScrollController::debugFillDescription(List<String> description) {
    if (debugLabel != nullptr) {
        description.add(debugLabel!);
    }
    if (initialScrollOffset != 0.0) {
        description.add("initialScrollOffset: ${initialScrollOffset.toStringAsFixed(1)}, ");
    }
    if (_positions.isEmpty) {
        description.add("no clients");
    } else     {
        if (_positions.length == 1) {
        description.add("one client, offset ${offset.toStringAsFixed(1)}");
    } else {
        description.add("${_positions.length} clients");
    }
;
    }}

ScrollPosition TrackingScrollController::mostRecentlyUpdatedPosition() {
    return _lastUpdated;
}

double TrackingScrollController::initialScrollOffset() {
    return _lastUpdatedOffset ?? super.initialScrollOffset;
}

void TrackingScrollController::attach(ScrollPosition position) {
    super.attach(position);
    assert(!_positionToListener.containsKey(position));
    _positionToListener[position] = ;
    position.addListener(_positionToListener[position]!);
}

void TrackingScrollController::detach(ScrollPosition position) {
    super.detach(position);
    assert(_positionToListener.containsKey(position));
    position.removeListener(_positionToListener[position]!);
    _positionToListener.remove(position);
    if (_lastUpdated == position) {
        _lastUpdated = nullptr;
    }
    if (_positionToListener.isEmpty) {
        _lastUpdatedOffset = nullptr;
    }
}

void TrackingScrollController::dispose() {
    for (ScrollPosition position : positions) {
        assert(_positionToListener.containsKey(position));
        position.removeListener(_positionToListener[position]!);
    }
    super.dispose();
}
