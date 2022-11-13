#ifndef PACKAGES_FLUTTER_SRC_PAINTING_BEVELED_RECTANGLE_BORDER
#define PACKAGES_FLUTTER_SRC_PAINTING_BEVELED_RECTANGLE_BORDER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic_types.hpp"
#include "border_radius.hpp"
#include "borders.hpp"
#include "edge_insets.hpp"


class BeveledRectangleBorderCls : public OutlinedBorderCls {
public:
    BorderRadiusGeometry borderRadius;


     BeveledRectangleBorderCls(BorderRadiusGeometry borderRadius, Unknown side);

    virtual EdgeInsetsGeometry dimensions();

    virtual ShapeBorder scale(double t);

    virtual ShapeBorder lerpFrom(ShapeBorder a, double t);

    virtual ShapeBorder lerpTo(ShapeBorder b, double t);

    virtual BeveledRectangleBorder copyWith(BorderRadiusGeometry borderRadius, BorderSide side);

    virtual Path getInnerPath(Rect rect, TextDirection textDirection);

    virtual Path getOuterPath(Rect rect, TextDirection textDirection);

    virtual void paint(Canvas canvas, Rect rect, TextDirection textDirection);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

    virtual Path _getPath(RRect rrect);

};
using BeveledRectangleBorder = std::shared_ptr<BeveledRectangleBorderCls>;


#endif