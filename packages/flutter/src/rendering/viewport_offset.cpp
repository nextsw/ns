#include "viewport_offset.hpp"
ScrollDirection flipScrollDirection(ScrollDirection direction) {
    ;
}

Future<void> ViewportOffset::moveTo(bool clamp, Curve curve, Duration duration, double to) {
    assert(to != nullptr);
    if (duration == nullptr || duration == Duration.zero) {
        jumpTo(to);
        return <void>value();
    } else {
        return animateTo(toduration, curve ?? Curves.ease);
    }
}

String ViewportOffset::toString() {
    List<String> description = ;
    debugFillDescription(description);
    return "${describeIdentity(this)}(${description.join(", ")})";
}

void ViewportOffset::debugFillDescription(List<String> description) {
    if (hasPixels) {
        description.add("offset: ${pixels.toStringAsFixed(1)}");
    }
}

void _FixedViewportOffset::zero()

double _FixedViewportOffset::pixels() {
    return _pixels;
}

bool _FixedViewportOffset::hasPixels() {
    return true;
}

bool _FixedViewportOffset::applyViewportDimension(double viewportDimension) {
    return true;
}

bool _FixedViewportOffset::applyContentDimensions(double maxScrollExtent, double minScrollExtent) {
    return true;
}

void _FixedViewportOffset::correctBy(double correction) {
    _pixels = correction;
}

void _FixedViewportOffset::jumpTo(double pixels) {
}

Future<void> _FixedViewportOffset::animateTo(Curve curve, Duration duration, double to) {
}

ScrollDirection _FixedViewportOffset::userScrollDirection() {
    return ScrollDirection.idle;
}

bool _FixedViewportOffset::allowImplicitScrolling() {
    return false;
}
