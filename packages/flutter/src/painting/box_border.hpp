#ifndef PACKAGES_FLUTTER_SRC_PAINTING_BOX_BORDER
#define PACKAGES_FLUTTER_SRC_PAINTING_BOX_BORDER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic_types.hpp"
#include "border_radius.hpp"
#include "borders.hpp"
#include "edge_insets.hpp"


enum BoxShape{
    rectangle,
    circle,
} // end BoxShape

class BoxBorderCls : public ShapeBorderCls {
public:

     BoxBorderCls();
    virtual BorderSide top();
    virtual BorderSide bottom();
    virtual bool isUniform();
    virtual BoxBorder add(ShapeBorder other, bool reversed);

    static BoxBorder lerp(BoxBorder a, BoxBorder b, double t);

    virtual Path getInnerPath(Rect rect, TextDirection textDirection);

    virtual Path getOuterPath(Rect rect, TextDirection textDirection);

    virtual void paint(Canvas canvas, Rect rect, BorderRadius borderRadius, BoxShape shape, TextDirection textDirection) override;
private:

    static void _paintUniformBorderWithRadius(Canvas canvas, Rect rect, BorderSide side, BorderRadius borderRadius);

    static void _paintUniformBorderWithCircle(Canvas canvas, Rect rect, BorderSide side);

    static void _paintUniformBorderWithRectangle(Canvas canvas, Rect rect, BorderSide side);

};
using BoxBorder = std::shared_ptr<BoxBorderCls>;

class BorderCls : public BoxBorderCls {
public:
    BorderSide top;

    BorderSide right;

    BorderSide bottom;

    BorderSide left;


     BorderCls(BorderSide bottom, BorderSide left, BorderSide right, BorderSide top);

    virtual void  fromBorderSide(BorderSide side);

    virtual void  symmetric(BorderSide horizontal, BorderSide vertical);

    virtual void  all(Color color, StrokeAlign strokeAlign, BorderStyle style, double width);

    static Border merge(Border a, Border b);

    virtual EdgeInsetsGeometry dimensions();

    virtual bool isUniform();

    virtual Border add(ShapeBorder other, bool reversed);

    virtual Border scale(double t);

    virtual ShapeBorder lerpFrom(ShapeBorder a, double t);

    virtual ShapeBorder lerpTo(ShapeBorder b, double t);

    static Border lerp(Border a, Border b, double t);

    virtual void paint(Canvas canvas, Rect rect, BorderRadius borderRadius, BoxShape shape, TextDirection textDirection);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

    virtual bool _colorIsUniform();

    virtual bool _widthIsUniform();

    virtual bool _styleIsUniform();

    virtual bool _strokeAlignIsUniform();

};
using Border = std::shared_ptr<BorderCls>;

class BorderDirectionalCls : public BoxBorderCls {
public:
    BorderSide top;

    BorderSide start;

    BorderSide end;

    BorderSide bottom;


     BorderDirectionalCls(BorderSide bottom, BorderSide end, BorderSide start, BorderSide top);

    static BorderDirectional merge(BorderDirectional a, BorderDirectional b);

    virtual EdgeInsetsGeometry dimensions();

    virtual bool isUniform();

    virtual BoxBorder add(ShapeBorder other, bool reversed);

    virtual BorderDirectional scale(double t);

    virtual ShapeBorder lerpFrom(ShapeBorder a, double t);

    virtual ShapeBorder lerpTo(ShapeBorder b, double t);

    static BorderDirectional lerp(BorderDirectional a, BorderDirectional b, double t);

    virtual void paint(Canvas canvas, Rect rect, BorderRadius borderRadius, BoxShape shape, TextDirection textDirection);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

    virtual bool _strokeAlignIsUniform();

};
using BorderDirectional = std::shared_ptr<BorderDirectionalCls>;


#endif