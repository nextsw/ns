#include "scroll_controller.hpp"
ScrollControllerCls::ScrollControllerCls(String debugLabel, double initialScrollOffset, bool keepScrollOffset) {
    {
        assert(initialScrollOffset != nullptr);
        assert(keepScrollOffset != nullptr);
        _initialScrollOffset = initialScrollOffset;
    }
}

double ScrollControllerCls::initialScrollOffset() {
    return _initialScrollOffset;
}

Iterable<ScrollPosition> ScrollControllerCls::positions() {
    return _positions;
}

bool ScrollControllerCls::hasClients() {
    return _positions->isNotEmpty;
}

ScrollPosition ScrollControllerCls::position() {
    assert(_positions->isNotEmpty, "ScrollController not attached to any scroll views.");
    assert(_positions->length == 1, "ScrollController attached to multiple scroll views.");
    return _positions->single;
}

double ScrollControllerCls::offset() {
    return position->pixels;
}

Future<void> ScrollControllerCls::animateTo(Curve curve, Duration duration, double offset) {
    assert(_positions->isNotEmpty, "ScrollController not attached to any scroll views.");
    List<Future<void>> list1 = make<ListCls<>>();for (;  < _positions->length; i = 1)     {        ;    }{    list1.add(ArrayItem);}await await FutureCls-><void>wait(list1);
}

void ScrollControllerCls::jumpTo(double value) {
    assert(_positions->isNotEmpty, "ScrollController not attached to any scroll views.");
    for (ScrollPosition position : <ScrollPosition>of(_positions)) {
        position->jumpTo(value);
    }
}

void ScrollControllerCls::attach(ScrollPosition position) {
    assert(!_positions->contains(position));
    _positions->add(position);
    position->addListener(notifyListeners);
}

void ScrollControllerCls::detach(ScrollPosition position) {
    assert(_positions->contains(position));
    position->removeListener(notifyListeners);
    _positions->remove(position);
}

void ScrollControllerCls::dispose() {
    for (ScrollPosition position : _positions) {
        position->removeListener(notifyListeners);
    }
    super->dispose();
}

ScrollPosition ScrollControllerCls::createScrollPosition(ScrollContext context, ScrollPosition oldPosition, ScrollPhysics physics) {
    return make<ScrollPositionWithSingleContextCls>(physics, context, initialScrollOffset, keepScrollOffset, oldPosition, debugLabel);
}

String ScrollControllerCls::toString() {
    List<String> description = makeList();
    debugFillDescription(description);
    return "${describeIdentity(this)}(${description.join(", ")})";
}

void ScrollControllerCls::debugFillDescription(List<String> description) {
    if (debugLabel != nullptr) {
        description->add(debugLabel!);
    }
    if (initialScrollOffset != 0.0) {
        description->add("initialScrollOffset: ${initialScrollOffset.toStringAsFixed(1)}, ");
    }
    if (_positions->isEmpty) {
        description->add("no clients");
    } else     {
        if (_positions->length == 1) {
        description->add("one client, offset ${offset.toStringAsFixed(1)}");
    } else {
        description->add("${_positions.length} clients");
    }
;
    }}

ScrollPosition TrackingScrollControllerCls::mostRecentlyUpdatedPosition() {
    return _lastUpdated;
}

double TrackingScrollControllerCls::initialScrollOffset() {
    return _lastUpdatedOffset ?? super->initialScrollOffset;
}

void TrackingScrollControllerCls::attach(ScrollPosition position) {
    super->attach(position);
    assert(!_positionToListener->containsKey(position));
    _positionToListener[position] = [=] () {
        _lastUpdated = position;
        _lastUpdatedOffset = position->pixels;
    };
    position->addListener(_positionToListener[position]!);
}

void TrackingScrollControllerCls::detach(ScrollPosition position) {
    super->detach(position);
    assert(_positionToListener->containsKey(position));
    position->removeListener(_positionToListener[position]!);
    _positionToListener->remove(position);
    if (_lastUpdated == position) {
        _lastUpdated = nullptr;
    }
    if (_positionToListener->isEmpty) {
        _lastUpdatedOffset = nullptr;
    }
}

void TrackingScrollControllerCls::dispose() {
    for (ScrollPosition position : positions) {
        assert(_positionToListener->containsKey(position));
        position->removeListener(_positionToListener[position]!);
    }
    super->dispose();
}
