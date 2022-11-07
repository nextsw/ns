#ifndef BOX_BORDER_H
#define BOX_BORDER_H
#include <memory>

#include <flutter/foundation.hpp>
#include "basic_types.hpp"
#include "border_radius.hpp"
#include "borders.hpp"
#include "edge_insets.hpp"



enum BoxShape{
    rectangle,
    circle,
} // end BoxShape

class BoxBorder : ShapeBorder {
public:

     BoxBorder();

    BorderSide top();

    BorderSide bottom();

    bool isUniform();

    BoxBorder add(ShapeBorder other, bool reversed);

    static BoxBorder lerp(BoxBorder a, BoxBorder b, double t);

    Path getInnerPath(Rect rect, TextDirection textDirection);

    Path getOuterPath(Rect rect, TextDirection textDirection);

    void paint(BorderRadius borderRadius, Canvas canvas, Rect rect, BoxShape shape, TextDirection textDirection);

private:

    static void _paintUniformBorderWithRadius(BorderRadius borderRadius, Canvas canvas, Rect rect, BorderSide side);

    static void _paintUniformBorderWithCircle(Canvas canvas, Rect rect, BorderSide side);

    static void _paintUniformBorderWithRectangle(Canvas canvas, Rect rect, BorderSide side);

};

class Border : BoxBorder {
public:
    BorderSide top;

    BorderSide right;

    BorderSide bottom;

    BorderSide left;


     Border(BorderSide bottom, BorderSide left, BorderSide right, BorderSide top);

    void  fromBorderSide(BorderSide side);

    void  symmetric(BorderSide horizontal, BorderSide vertical);

    void  all(Color color, StrokeAlign strokeAlign, BorderStyle style, double width);

    static Border merge(Border a, Border b);

    EdgeInsetsGeometry dimensions();

    bool isUniform();

    Border add(ShapeBorder other, bool reversed);

    Border scale(double t);

    ShapeBorder lerpFrom(ShapeBorder a, double t);

    ShapeBorder lerpTo(ShapeBorder b, double t);

    static Border lerp(Border a, Border b, double t);

    void paint(BorderRadius borderRadius, Canvas canvas, Rect rect, BoxShape shape, TextDirection textDirection);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

    bool _colorIsUniform();

    bool _widthIsUniform();

    bool _styleIsUniform();

    bool _strokeAlignIsUniform();

};

class BorderDirectional : BoxBorder {
public:
    BorderSide top;

    BorderSide start;

    BorderSide end;

    BorderSide bottom;


     BorderDirectional(BorderSide bottom, BorderSide end, BorderSide start, BorderSide top);

    static BorderDirectional merge(BorderDirectional a, BorderDirectional b);

    EdgeInsetsGeometry dimensions();

    bool isUniform();

    BoxBorder add(ShapeBorder other, bool reversed);

    BorderDirectional scale(double t);

    ShapeBorder lerpFrom(ShapeBorder a, double t);

    ShapeBorder lerpTo(ShapeBorder b, double t);

    static BorderDirectional lerp(BorderDirectional a, BorderDirectional b, double t);

    void paint(BorderRadius borderRadius, Canvas canvas, Rect rect, BoxShape shape, TextDirection textDirection);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

    bool _strokeAlignIsUniform();

};

#endif