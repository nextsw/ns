#ifndef PACKAGES_FLUTTER_SRC_PAINTING_CIRCLE_BORDER
#define PACKAGES_FLUTTER_SRC_PAINTING_CIRCLE_BORDER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic_types.hpp"
#include "borders.hpp"
#include "edge_insets.hpp"


class CircleBorderCls : public OutlinedBorderCls {
public:

     CircleBorderCls(BorderSide side);

    virtual EdgeInsetsGeometry dimensions();

    virtual ShapeBorder scale(double t);

    virtual ShapeBorder lerpFrom(ShapeBorder a, double t);

    virtual ShapeBorder lerpTo(ShapeBorder b, double t);

    virtual Path getInnerPath(Rect rect, TextDirection textDirection);

    virtual Path getOuterPath(Rect rect, TextDirection textDirection);

    virtual CircleBorder copyWith(BorderSide side);

    virtual void paint(Canvas canvas, Rect rect, TextDirection textDirection);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using CircleBorder = std::shared_ptr<CircleBorderCls>;


#endif