#ifndef SCROLL_METRICS_H
#define SCROLL_METRICS_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>



class ScrollMetrics {
public:

    ScrollMetrics copyWith(AxisDirection axisDirection, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension);

    double minScrollExtent();

    double maxScrollExtent();

    bool hasContentDimensions();

    double pixels();

    bool hasPixels();

    double viewportDimension();

    bool hasViewportDimension();

    AxisDirection axisDirection();

    Axis axis();

    bool outOfRange();

    bool atEdge();

    double extentBefore();

    double extentInside();

    double extentAfter();

private:

};

class FixedScrollMetrics {
public:
    AxisDirection axisDirection;


     FixedScrollMetrics(AxisDirection axisDirection, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension);

    double minScrollExtent();

    double maxScrollExtent();

    bool hasContentDimensions();

    double pixels();

    bool hasPixels();

    double viewportDimension();

    bool hasViewportDimension();

    String toString();

private:
    double _minScrollExtent;

    double _maxScrollExtent;

    double _pixels;

    double _viewportDimension;


};

#endif