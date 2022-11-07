#include "scroll_metrics.hpp"
ScrollMetrics ScrollMetrics::copyWith(AxisDirection axisDirection, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension) {
    return FixedScrollMetrics(minScrollExtent ?? (hasContentDimensions? this.minScrollExtent : nullptr), maxScrollExtent ?? (hasContentDimensions? this.maxScrollExtent : nullptr), pixels ?? (hasPixels? this.pixels : nullptr), viewportDimension ?? (hasViewportDimension? this.viewportDimension : nullptr), axisDirection ?? this.axisDirection);
}

Axis ScrollMetrics::axis() {
    return axisDirectionToAxis(axisDirection);
}

bool ScrollMetrics::outOfRange() {
    return  < minScrollExtent || pixels > maxScrollExtent;
}

bool ScrollMetrics::atEdge() {
    return pixels == minScrollExtent || pixels == maxScrollExtent;
}

double ScrollMetrics::extentBefore() {
    return math.max(pixels - minScrollExtent, 0.0);
}

double ScrollMetrics::extentInside() {
    assert(minScrollExtent <= maxScrollExtent);
    return viewportDimension - clampDouble(minScrollExtent - pixels, 0, viewportDimension) - clampDouble(pixels - maxScrollExtent, 0, viewportDimension);
}

double ScrollMetrics::extentAfter() {
    return math.max(maxScrollExtent - pixels, 0.0);
}

FixedScrollMetrics::FixedScrollMetrics(AxisDirection axisDirection, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension) {
    {
        _minScrollExtent = minScrollExtent;
        _maxScrollExtent = maxScrollExtent;
        _pixels = pixels;
        _viewportDimension = viewportDimension;
    }
}

double FixedScrollMetrics::minScrollExtent() {
    return _minScrollExtent!;
}

double FixedScrollMetrics::maxScrollExtent() {
    return _maxScrollExtent!;
}

bool FixedScrollMetrics::hasContentDimensions() {
    return _minScrollExtent != nullptr && _maxScrollExtent != nullptr;
}

double FixedScrollMetrics::pixels() {
    return _pixels!;
}

bool FixedScrollMetrics::hasPixels() {
    return _pixels != nullptr;
}

double FixedScrollMetrics::viewportDimension() {
    return _viewportDimension!;
}

bool FixedScrollMetrics::hasViewportDimension() {
    return _viewportDimension != nullptr;
}

String FixedScrollMetrics::toString() {
    return "${objectRuntimeType(this, 'FixedScrollMetrics')}(${extentBefore.toStringAsFixed(1)}..[${extentInside.toStringAsFixed(1)}]..${extentAfter.toStringAsFixed(1)})";
}
