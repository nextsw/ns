#include "viewport_offset.hpp"
ScrollDirection flipScrollDirection(ScrollDirection direction) {
    ;
}

Future<void> ViewportOffsetCls::moveTo(double to, bool clamp, Curve curve, Duration duration) {
    assert(to != nullptr);
    if (duration == nullptr || duration == DurationCls::zero) {
        jumpTo(to);
        return <void>value();
    } else {
        return animateTo(toduration, curve | CurvesCls::ease);
    }
}

String ViewportOffsetCls::toString() {
    List<String> description = makeList();
    debugFillDescription(description);
    return __s("${describeIdentity(this)}(${description.join(", ")})");
}

void ViewportOffsetCls::debugFillDescription(List<String> description) {
    if (hasPixels()) {
        description->add(__s("offset: ${pixels.toStringAsFixed(1)}"));
    }
}

void _FixedViewportOffsetCls::zero()

double _FixedViewportOffsetCls::pixels() {
    return _pixels;
}

bool _FixedViewportOffsetCls::hasPixels() {
    return true;
}

bool _FixedViewportOffsetCls::applyViewportDimension(double viewportDimension) {
    return true;
}

bool _FixedViewportOffsetCls::applyContentDimensions(double minScrollExtent, double maxScrollExtent) {
    return true;
}

void _FixedViewportOffsetCls::correctBy(double correction) {
    _pixels += correction;
}

void _FixedViewportOffsetCls::jumpTo(double pixels) {
}

Future<void> _FixedViewportOffsetCls::animateTo(double to, Curve curve, Duration duration) {
}

ScrollDirection _FixedViewportOffsetCls::userScrollDirection() {
    return ScrollDirectionCls::idle;
}

bool _FixedViewportOffsetCls::allowImplicitScrolling() {
    return false;
}
