#ifndef PACKAGES_FLUTTER_SRC_PAINTING_STADIUM_BORDER
#define PACKAGES_FLUTTER_SRC_PAINTING_STADIUM_BORDER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic_types.hpp"
#include "border_radius.hpp"
#include "borders.hpp"
#include "circle_border.hpp"
#include "edge_insets.hpp"
#include "rounded_rectangle_border.hpp"


class StadiumBorderCls : public OutlinedBorderCls {
public:

     StadiumBorderCls(BorderSide side);

    virtual EdgeInsetsGeometry dimensions();

    virtual ShapeBorder scale(double t);

    virtual ShapeBorder lerpFrom(ShapeBorder a, double t);

    virtual ShapeBorder lerpTo(ShapeBorder b, double t);

    virtual StadiumBorder copyWith(BorderSide side);

    virtual Path getInnerPath(Rect rect, TextDirection textDirection);

    virtual Path getOuterPath(Rect rect, TextDirection textDirection);

    virtual void paint(Canvas canvas, Rect rect, TextDirection textDirection);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using StadiumBorder = std::shared_ptr<StadiumBorderCls>;

class _StadiumToCircleBorderCls : public OutlinedBorderCls {
public:
    double circleness;


    virtual EdgeInsetsGeometry dimensions();

    virtual ShapeBorder scale(double t);

    virtual ShapeBorder lerpFrom(ShapeBorder a, double t);

    virtual ShapeBorder lerpTo(ShapeBorder b, double t);

    virtual Path getInnerPath(Rect rect, TextDirection textDirection);

    virtual Path getOuterPath(Rect rect, TextDirection textDirection);

    virtual _StadiumToCircleBorder copyWith(double circleness, BorderSide side);

    virtual void paint(Canvas canvas, Rect rect, TextDirection textDirection);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

     _StadiumToCircleBorderCls(double circleness, BorderSide side);

    virtual Rect _adjustRect(Rect rect);

    virtual BorderRadius _adjustBorderRadius(Rect rect);

};
using _StadiumToCircleBorder = std::shared_ptr<_StadiumToCircleBorderCls>;

class _StadiumToRoundedRectangleBorderCls : public OutlinedBorderCls {
public:
    BorderRadius borderRadius;

    double rectness;


    virtual EdgeInsetsGeometry dimensions();

    virtual ShapeBorder scale(double t);

    virtual ShapeBorder lerpFrom(ShapeBorder a, double t);

    virtual ShapeBorder lerpTo(ShapeBorder b, double t);

    virtual Path getInnerPath(Rect rect, TextDirection textDirection);

    virtual Path getOuterPath(Rect rect, TextDirection textDirection);

    virtual _StadiumToRoundedRectangleBorder copyWith(BorderRadius borderRadius, double rectness, BorderSide side);

    virtual void paint(Canvas canvas, Rect rect, TextDirection textDirection);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

     _StadiumToRoundedRectangleBorderCls(BorderRadius borderRadius, double rectness, BorderSide side);

    virtual BorderRadius _adjustBorderRadius(Rect rect);

};
using _StadiumToRoundedRectangleBorder = std::shared_ptr<_StadiumToRoundedRectangleBorderCls>;


#endif