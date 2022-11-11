#include "scroll_metrics.hpp"
ScrollMetrics ScrollMetricsCls::copyWith(AxisDirection axisDirection, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension) {
    return make<FixedScrollMetricsCls>(minScrollExtent or (hasContentDimensions()? this->minScrollExtent : nullptr), maxScrollExtent or (hasContentDimensions()? this->maxScrollExtent : nullptr), pixels or (hasPixels()? this->pixels : nullptr), viewportDimension or (hasViewportDimension()? this->viewportDimension : nullptr), axisDirection or this->axisDirection);
}

Axis ScrollMetricsCls::axis() {
    return axisDirectionToAxis(axisDirection);
}

bool ScrollMetricsCls::outOfRange() {
    return  < minScrollExtent || pixels > maxScrollExtent;
}

bool ScrollMetricsCls::atEdge() {
    return pixels == minScrollExtent || pixels == maxScrollExtent;
}

double ScrollMetricsCls::extentBefore() {
    return math->max(pixels - minScrollExtent, 0.0);
}

double ScrollMetricsCls::extentInside() {
    assert(minScrollExtent <= maxScrollExtent);
    return viewportDimension - clampDouble(minScrollExtent - pixels, 0, viewportDimension) - clampDouble(pixels - maxScrollExtent, 0, viewportDimension);
}

double ScrollMetricsCls::extentAfter() {
    return math->max(maxScrollExtent - pixels, 0.0);
}

FixedScrollMetricsCls::FixedScrollMetricsCls(AxisDirection axisDirection, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension) {
    {
        _minScrollExtent = minScrollExtent;
        _maxScrollExtent = maxScrollExtent;
        _pixels = pixels;
        _viewportDimension = viewportDimension;
    }
}

double FixedScrollMetricsCls::minScrollExtent() {
    return _minScrollExtent!;
}

double FixedScrollMetricsCls::maxScrollExtent() {
    return _maxScrollExtent!;
}

bool FixedScrollMetricsCls::hasContentDimensions() {
    return _minScrollExtent != nullptr && _maxScrollExtent != nullptr;
}

double FixedScrollMetricsCls::pixels() {
    return _pixels!;
}

bool FixedScrollMetricsCls::hasPixels() {
    return _pixels != nullptr;
}

double FixedScrollMetricsCls::viewportDimension() {
    return _viewportDimension!;
}

bool FixedScrollMetricsCls::hasViewportDimension() {
    return _viewportDimension != nullptr;
}

String FixedScrollMetricsCls::toString() {
    return __s("${objectRuntimeType(this, 'FixedScrollMetrics')}(${extentBefore.toStringAsFixed(1)}..[${extentInside.toStringAsFixed(1)}]..${extentAfter.toStringAsFixed(1)})");
}
