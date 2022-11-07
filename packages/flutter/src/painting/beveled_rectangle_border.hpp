#ifndef BEVELED_RECTANGLE_BORDER_H
#define BEVELED_RECTANGLE_BORDER_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include "basic_types.hpp"
#include "border_radius.hpp"
#include "borders.hpp"
#include "edge_insets.hpp"



class BeveledRectangleBorder : OutlinedBorder {
public:
    BorderRadiusGeometry borderRadius;


     BeveledRectangleBorder(BorderRadiusGeometry borderRadius, Unknown);

    EdgeInsetsGeometry dimensions();

    ShapeBorder scale(double t);

    ShapeBorder lerpFrom(ShapeBorder a, double t);

    ShapeBorder lerpTo(ShapeBorder b, double t);

    BeveledRectangleBorder copyWith(BorderRadiusGeometry borderRadius, BorderSide side);

    Path getInnerPath(Rect rect, TextDirection textDirection);

    Path getOuterPath(Rect rect, TextDirection textDirection);

    void paint(Canvas canvas, Rect rect, TextDirection textDirection);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

    Path _getPath(RRect rrect);

};

#endif