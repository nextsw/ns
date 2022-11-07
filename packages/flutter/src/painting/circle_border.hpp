#ifndef CIRCLE_BORDER_H
#define CIRCLE_BORDER_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include "basic_types.hpp"
#include "borders.hpp"
#include "edge_insets.hpp"



class CircleBorder : OutlinedBorder {
public:

     CircleBorder(Unknown);

    EdgeInsetsGeometry dimensions();

    ShapeBorder scale(double t);

    ShapeBorder lerpFrom(ShapeBorder a, double t);

    ShapeBorder lerpTo(ShapeBorder b, double t);

    Path getInnerPath(Rect rect, TextDirection textDirection);

    Path getOuterPath(Rect rect, TextDirection textDirection);

    CircleBorder copyWith(BorderSide side);

    void paint(Canvas canvas, Rect rect, TextDirection textDirection);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

#endif