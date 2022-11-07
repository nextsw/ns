#ifndef ROUNDED_RECTANGLE_BORDER_H
#define ROUNDED_RECTANGLE_BORDER_H
#include <memory>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "basic_types.hpp"
#include "border_radius.hpp"
#include "borders.hpp"
#include "circle_border.hpp"
#include "edge_insets.hpp"



class RoundedRectangleBorder : OutlinedBorder {
public:
    BorderRadiusGeometry borderRadius;


     RoundedRectangleBorder(BorderRadiusGeometry borderRadius, Unknown);

    EdgeInsetsGeometry dimensions();

    ShapeBorder scale(double t);

    ShapeBorder lerpFrom(ShapeBorder a, double t);

    ShapeBorder lerpTo(ShapeBorder b, double t);

    RoundedRectangleBorder copyWith(BorderRadiusGeometry borderRadius, BorderSide side);

    Path getInnerPath(Rect rect, TextDirection textDirection);

    Path getOuterPath(Rect rect, TextDirection textDirection);

    void paint(Canvas canvas, Rect rect, TextDirection textDirection);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class _RoundedRectangleToCircleBorder : OutlinedBorder {
public:
    BorderRadiusGeometry borderRadius;

    double circleness;


    EdgeInsetsGeometry dimensions();

    ShapeBorder scale(double t);

    ShapeBorder lerpFrom(ShapeBorder a, double t);

    ShapeBorder lerpTo(ShapeBorder b, double t);

    Path getInnerPath(Rect rect, TextDirection textDirection);

    Path getOuterPath(Rect rect, TextDirection textDirection);

    _RoundedRectangleToCircleBorder copyWith(BorderRadiusGeometry borderRadius, double circleness, BorderSide side);

    void paint(Canvas canvas, Rect rect, TextDirection textDirection);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

     _RoundedRectangleToCircleBorder(BorderRadiusGeometry borderRadius, double circleness, Unknown);

    Rect _adjustRect(Rect rect);

    BorderRadius _adjustBorderRadius(Rect rect, TextDirection textDirection);

};

#endif