#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_METRICS
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_METRICS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>


class ScrollMetricsCls : public ObjectCls {
public:

    virtual ScrollMetrics copyWith(AxisDirection axisDirection, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension);

    virtual double minScrollExtent();
    virtual double maxScrollExtent();
    virtual bool hasContentDimensions();
    virtual double pixels();
    virtual bool hasPixels();
    virtual double viewportDimension();
    virtual bool hasViewportDimension();
    virtual AxisDirection axisDirection();
    virtual Axis axis();

    virtual bool outOfRange();

    virtual bool atEdge();

    virtual double extentBefore();

    virtual double extentInside();

    virtual double extentAfter();

private:

};
using ScrollMetrics = std::shared_ptr<ScrollMetricsCls>;

class FixedScrollMetricsCls : public ObjectCls {
public:
    AxisDirection axisDirection;


     FixedScrollMetricsCls(AxisDirection axisDirection, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension);

    virtual double minScrollExtent();

    virtual double maxScrollExtent();

    virtual bool hasContentDimensions();

    virtual double pixels();

    virtual bool hasPixels();

    virtual double viewportDimension();

    virtual bool hasViewportDimension();

    virtual String toString();

private:
    double _minScrollExtent;

    double _maxScrollExtent;

    double _pixels;

    double _viewportDimension;


};
using FixedScrollMetrics = std::shared_ptr<FixedScrollMetricsCls>;


#endif