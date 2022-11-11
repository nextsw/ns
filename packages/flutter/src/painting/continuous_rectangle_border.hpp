#ifndef PACKAGES_FLUTTER_SRC_PAINTING_CONTINUOUS_RECTANGLE_BORDER
#define PACKAGES_FLUTTER_SRC_PAINTING_CONTINUOUS_RECTANGLE_BORDER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic_types.hpp"
#include "border_radius.hpp"
#include "borders.hpp"
#include "edge_insets.hpp"


class ContinuousRectangleBorderCls : public OutlinedBorderCls {
public:
    BorderRadiusGeometry borderRadius;


     ContinuousRectangleBorderCls(BorderRadiusGeometry borderRadius, BorderSide side);

    virtual EdgeInsetsGeometry dimensions();

    virtual ShapeBorder scale(double t);

    virtual ShapeBorder lerpFrom(ShapeBorder a, double t);

    virtual ShapeBorder lerpTo(ShapeBorder b, double t);

    virtual Path getInnerPath(Rect rect, TextDirection textDirection);

    virtual Path getOuterPath(Rect rect, TextDirection textDirection);

    virtual ContinuousRectangleBorder copyWith(BorderRadiusGeometry borderRadius, BorderSide side);

    virtual void paint(Canvas canvas, Rect rect, TextDirection textDirection);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

    virtual double _clampToShortest(RRect rrect, double value);

    virtual Path _getPath(RRect rrect);

};
using ContinuousRectangleBorder = std::shared_ptr<ContinuousRectangleBorderCls>;


#endif