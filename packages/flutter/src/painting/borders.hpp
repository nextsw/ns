#ifndef PACKAGES_FLUTTER_SRC_PAINTING_BORDERS
#define PACKAGES_FLUTTER_SRC_PAINTING_BORDERS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
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

class BorderSideCls : public ObjectCls {
public:
    Color color;

    double width;

    BorderStyle style;

    static BorderSide none;

    StrokeAlign strokeAlign;


     BorderSideCls(Color color, StrokeAlign strokeAlign, BorderStyle style, double width);

    static BorderSide merge(BorderSide a, BorderSide b);

    virtual BorderSide copyWith(Color color, BorderStyle style, double width);

    virtual BorderSide scale(double t);

    virtual Paint toPaint();

    static bool canMerge(BorderSide a, BorderSide b);

    static BorderSide lerp(BorderSide a, BorderSide b, double t);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using BorderSide = std::shared_ptr<BorderSideCls>;

class ShapeBorderCls : public ObjectCls {
public:

     ShapeBorderCls();
    virtual EdgeInsetsGeometry dimensions();
    virtual ShapeBorder add(ShapeBorder other, bool reversed);

    virtual ShapeBorder operator+(ShapeBorder other);

    virtual ShapeBorder scale(double t);
    virtual ShapeBorder lerpFrom(ShapeBorder a, double t);

    virtual ShapeBorder lerpTo(ShapeBorder b, double t);

    static ShapeBorder lerp(ShapeBorder a, ShapeBorder b, double t);

    virtual Path getOuterPath(Rect rect, TextDirection textDirection);
    virtual Path getInnerPath(Rect rect, TextDirection textDirection);
    virtual void paint(Canvas canvas, Rect rect, TextDirection textDirection);
    virtual String toString();

private:

};
using ShapeBorder = std::shared_ptr<ShapeBorderCls>;

class OutlinedBorderCls : public ShapeBorderCls {
public:
    BorderSide side;


     OutlinedBorderCls(BorderSide side);

    virtual OutlinedBorder copyWith(BorderSide side);
    virtual ShapeBorder scale(double t) override;
    virtual ShapeBorder lerpFrom(ShapeBorder a, double t);

    virtual ShapeBorder lerpTo(ShapeBorder b, double t);

    static OutlinedBorder lerp(OutlinedBorder a, OutlinedBorder b, double t);

private:

};
using OutlinedBorder = std::shared_ptr<OutlinedBorderCls>;

class _CompoundBorderCls : public ShapeBorderCls {
public:
    List<ShapeBorder> borders;


    virtual EdgeInsetsGeometry dimensions();

    virtual ShapeBorder add(ShapeBorder other, bool reversed);

    virtual ShapeBorder scale(double t);

    virtual ShapeBorder lerpFrom(ShapeBorder a, double t);

    virtual ShapeBorder lerpTo(ShapeBorder b, double t);

    static _CompoundBorder lerp(ShapeBorder a, ShapeBorder b, double t);

    virtual Path getInnerPath(Rect rect, TextDirection textDirection);

    virtual Path getOuterPath(Rect rect, TextDirection textDirection);

    virtual void paint(Canvas canvas, Rect rect, TextDirection textDirection);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

     _CompoundBorderCls(List<ShapeBorder> borders);

};
using _CompoundBorder = std::shared_ptr<_CompoundBorderCls>;
void paintBorder(BorderSide bottom, Canvas canvas, BorderSide left, Rect rect, BorderSide right, BorderSide top);



#endif