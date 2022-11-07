#ifndef CONTINUOUS_RECTANGLE_BORDER_H
#define CONTINUOUS_RECTANGLE_BORDER_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include "basic_types.hpp"
#include "border_radius.hpp"
#include "borders.hpp"
#include "edge_insets.hpp"



class ContinuousRectangleBorder : OutlinedBorder {
public:
    BorderRadiusGeometry borderRadius;


     ContinuousRectangleBorder(BorderRadiusGeometry borderRadius, Unknown);

    EdgeInsetsGeometry dimensions();

    ShapeBorder scale(double t);

    ShapeBorder lerpFrom(ShapeBorder a, double t);

    ShapeBorder lerpTo(ShapeBorder b, double t);

    Path getInnerPath(Rect rect, TextDirection textDirection);

    Path getOuterPath(Rect rect, TextDirection textDirection);

    ContinuousRectangleBorder copyWith(BorderRadiusGeometry borderRadius, BorderSide side);

    void paint(Canvas canvas, Rect rect, TextDirection textDirection);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

    double _clampToShortest(RRect rrect, double value);

    Path _getPath(RRect rrect);

};

#endif