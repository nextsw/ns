#ifndef BORDERS_H
#define BORDERS_H
#include <memory>

#include <math/math.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "basic_types.hpp"
#include "edge_insets.hpp"



enum BorderStyle{
    none,
    solid,
} // end BorderStyle

enum StrokeAlign{
    inside,
    center,
    outside,
} // end StrokeAlign

class BorderSide {
public:
    Color color;

    double width;

    BorderStyle style;

    static const BorderSide none;

    StrokeAlign strokeAlign;


     BorderSide(Color color, StrokeAlign strokeAlign, BorderStyle style, double width);

    static BorderSide merge(BorderSide a, BorderSide b);

    BorderSide copyWith(Color color, BorderStyle style, double width);

    BorderSide scale(double t);

    Paint toPaint();

    static bool canMerge(BorderSide a, BorderSide b);

    static BorderSide lerp(BorderSide a, BorderSide b, double t);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class ShapeBorder {
public:

     ShapeBorder();

    EdgeInsetsGeometry dimensions();

    ShapeBorder add(ShapeBorder other, bool reversed);

    ShapeBorder +(ShapeBorder other);

    ShapeBorder scale(double t);

    ShapeBorder lerpFrom(ShapeBorder a, double t);

    ShapeBorder lerpTo(ShapeBorder b, double t);

    static ShapeBorder lerp(ShapeBorder a, ShapeBorder b, double t);

    Path getOuterPath(Rect rect, TextDirection textDirection);

    Path getInnerPath(Rect rect, TextDirection textDirection);

    void paint(Canvas canvas, Rect rect, TextDirection textDirection);

    String toString();

private:

};

class OutlinedBorder : ShapeBorder {
public:
    BorderSide side;


     OutlinedBorder(BorderSide side);

    OutlinedBorder copyWith(BorderSide side);

    ShapeBorder scale(double t);

    ShapeBorder lerpFrom(ShapeBorder a, double t);

    ShapeBorder lerpTo(ShapeBorder b, double t);

    static OutlinedBorder lerp(OutlinedBorder a, OutlinedBorder b, double t);

private:

};

class _CompoundBorder : ShapeBorder {
public:
    List<ShapeBorder> borders;


    EdgeInsetsGeometry dimensions();

    ShapeBorder add(ShapeBorder other, bool reversed);

    ShapeBorder scale(double t);

    ShapeBorder lerpFrom(ShapeBorder a, double t);

    ShapeBorder lerpTo(ShapeBorder b, double t);

    static _CompoundBorder lerp(ShapeBorder a, ShapeBorder b, double t);

    Path getInnerPath(Rect rect, TextDirection textDirection);

    Path getOuterPath(Rect rect, TextDirection textDirection);

    void paint(Canvas canvas, Rect rect, TextDirection textDirection);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

     _CompoundBorder(List<ShapeBorder> borders);

};
void paintBorder(BorderSide bottom, Canvas canvas, BorderSide left, Rect rect, BorderSide right, BorderSide top);


#endif