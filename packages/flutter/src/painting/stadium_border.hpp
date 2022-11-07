#ifndef STADIUM_BORDER_H
#define STADIUM_BORDER_H
#include <memory>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "basic_types.hpp"
#include "border_radius.hpp"
#include "borders.hpp"
#include "circle_border.hpp"
#include "edge_insets.hpp"
#include "rounded_rectangle_border.hpp"



class StadiumBorder : OutlinedBorder {
public:

     StadiumBorder(Unknown);

    EdgeInsetsGeometry dimensions();

    ShapeBorder scale(double t);

    ShapeBorder lerpFrom(ShapeBorder a, double t);

    ShapeBorder lerpTo(ShapeBorder b, double t);

    StadiumBorder copyWith(BorderSide side);

    Path getInnerPath(Rect rect, TextDirection textDirection);

    Path getOuterPath(Rect rect, TextDirection textDirection);

    void paint(Canvas canvas, Rect rect, TextDirection textDirection);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class _StadiumToCircleBorder : OutlinedBorder {
public:
    double circleness;


    EdgeInsetsGeometry dimensions();

    ShapeBorder scale(double t);

    ShapeBorder lerpFrom(ShapeBorder a, double t);

    ShapeBorder lerpTo(ShapeBorder b, double t);

    Path getInnerPath(Rect rect, TextDirection textDirection);

    Path getOuterPath(Rect rect, TextDirection textDirection);

    _StadiumToCircleBorder copyWith(double circleness, BorderSide side);

    void paint(Canvas canvas, Rect rect, TextDirection textDirection);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

     _StadiumToCircleBorder(double circleness, Unknown);

    Rect _adjustRect(Rect rect);

    BorderRadius _adjustBorderRadius(Rect rect);

};

class _StadiumToRoundedRectangleBorder : OutlinedBorder {
public:
    BorderRadius borderRadius;

    double rectness;


    EdgeInsetsGeometry dimensions();

    ShapeBorder scale(double t);

    ShapeBorder lerpFrom(ShapeBorder a, double t);

    ShapeBorder lerpTo(ShapeBorder b, double t);

    Path getInnerPath(Rect rect, TextDirection textDirection);

    Path getOuterPath(Rect rect, TextDirection textDirection);

    _StadiumToRoundedRectangleBorder copyWith(BorderRadius borderRadius, double rectness, BorderSide side);

    void paint(Canvas canvas, Rect rect, TextDirection textDirection);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

     _StadiumToRoundedRectangleBorder(BorderRadius borderRadius, double rectness, Unknown);

    BorderRadius _adjustBorderRadius(Rect rect);

};

#endif