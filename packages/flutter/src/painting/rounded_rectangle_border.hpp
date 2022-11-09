#ifndef PACKAGES_FLUTTER_SRC_PAINTING_ROUNDED_RECTANGLE_BORDER
#define PACKAGES_FLUTTER_SRC_PAINTING_ROUNDED_RECTANGLE_BORDER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic_types.hpp"
#include "border_radius.hpp"
#include "borders.hpp"
#include "circle_border.hpp"
#include "edge_insets.hpp"


class RoundedRectangleBorderCls : public OutlinedBorderCls {
public:
    BorderRadiusGeometry borderRadius;


     RoundedRectangleBorderCls(BorderRadiusGeometry borderRadius, Unknown side);

    virtual EdgeInsetsGeometry dimensions();

    virtual ShapeBorder scale(double t);

    virtual ShapeBorder lerpFrom(ShapeBorder a, double t);

    virtual ShapeBorder lerpTo(ShapeBorder b, double t);

    virtual RoundedRectangleBorder copyWith(BorderRadiusGeometry borderRadius, BorderSide side);

    virtual Path getInnerPath(Rect rect, TextDirection textDirection);

    virtual Path getOuterPath(Rect rect, TextDirection textDirection);

    virtual void paint(Canvas canvas, Rect rect, TextDirection textDirection);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using RoundedRectangleBorder = std::shared_ptr<RoundedRectangleBorderCls>;

class _RoundedRectangleToCircleBorderCls : public OutlinedBorderCls {
public:
    BorderRadiusGeometry borderRadius;

    double circleness;


    virtual EdgeInsetsGeometry dimensions();

    virtual ShapeBorder scale(double t);

    virtual ShapeBorder lerpFrom(ShapeBorder a, double t);

    virtual ShapeBorder lerpTo(ShapeBorder b, double t);

    virtual Path getInnerPath(Rect rect, TextDirection textDirection);

    virtual Path getOuterPath(Rect rect, TextDirection textDirection);

    virtual _RoundedRectangleToCircleBorder copyWith(BorderRadiusGeometry borderRadius, double circleness, BorderSide side);

    virtual void paint(Canvas canvas, Rect rect, TextDirection textDirection);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

     _RoundedRectangleToCircleBorderCls(BorderRadiusGeometry borderRadius, double circleness, Unknown side);

    virtual Rect _adjustRect(Rect rect);

    virtual BorderRadius _adjustBorderRadius(Rect rect, TextDirection textDirection);

};
using _RoundedRectangleToCircleBorder = std::shared_ptr<_RoundedRectangleToCircleBorderCls>;


#endif