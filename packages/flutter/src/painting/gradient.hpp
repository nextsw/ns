#ifndef PACKAGES_FLUTTER_SRC_PAINTING_GRADIENT
#define PACKAGES_FLUTTER_SRC_PAINTING_GRADIENT
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <dart/math/math.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "alignment.hpp"
#include "basic_types.hpp"


class _ColorsAndStopsCls : public ObjectCls {
public:
    List<Color> colors;

    List<double> stops;


private:

     _ColorsAndStopsCls(List<Color> colors, List<double> stops);
};
using _ColorsAndStops = std::shared_ptr<_ColorsAndStopsCls>;
Color _sample(List<Color> colors, List<double> stops, double t);

_ColorsAndStops _interpolateColorsAndStops(List<Color> aColors, List<double> aStops, List<Color> bColors, List<double> bStops, double t);


class GradientTransformCls : public ObjectCls {
public:

     GradientTransformCls();
    virtual Matrix4 transform(Rect bounds, TextDirection textDirection);
private:

};
using GradientTransform = std::shared_ptr<GradientTransformCls>;

class GradientRotationCls : public GradientTransformCls {
public:
    double radians;


     GradientRotationCls(double radians);
    virtual Matrix4 transform(Rect bounds, TextDirection textDirection);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using GradientRotation = std::shared_ptr<GradientRotationCls>;

class GradientCls : public ObjectCls {
public:
    List<Color> colors;

    List<double> stops;

    GradientTransform transform;


     GradientCls(List<Color> colors, List<double> stops, GradientTransform transform);

    virtual Shader createShader(Rect rect, TextDirection textDirection);
    virtual Gradient scale(double factor);
    virtual Gradient lerpFrom(Gradient a, double t);

    virtual Gradient lerpTo(Gradient b, double t);

    static Gradient lerp(Gradient a, Gradient b, double t);

private:

    virtual List<double> _impliedStops();

    virtual Float64List _resolveTransform(Rect bounds, TextDirection textDirection);

};
using Gradient = std::shared_ptr<GradientCls>;

class LinearGradientCls : public GradientCls {
public:
    AlignmentGeometry begin;

    AlignmentGeometry end;

    TileMode tileMode;


     LinearGradientCls(AlignmentGeometry begin, Unknown colors, AlignmentGeometry end, Unknown stops, TileMode tileMode, Unknown transform);

    virtual Shader createShader(Rect rect, TextDirection textDirection);

    virtual LinearGradient scale(double factor);

    virtual Gradient lerpFrom(Gradient a, double t);

    virtual Gradient lerpTo(Gradient b, double t);

    static LinearGradient lerp(LinearGradient a, LinearGradient b, double t);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using LinearGradient = std::shared_ptr<LinearGradientCls>;

class RadialGradientCls : public GradientCls {
public:
    AlignmentGeometry center;

    double radius;

    TileMode tileMode;

    AlignmentGeometry focal;

    double focalRadius;


     RadialGradientCls(AlignmentGeometry center, Unknown colors, AlignmentGeometry focal, double focalRadius, double radius, Unknown stops, TileMode tileMode, Unknown transform);

    virtual Shader createShader(Rect rect, TextDirection textDirection);

    virtual RadialGradient scale(double factor);

    virtual Gradient lerpFrom(Gradient a, double t);

    virtual Gradient lerpTo(Gradient b, double t);

    static RadialGradient lerp(RadialGradient a, RadialGradient b, double t);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using RadialGradient = std::shared_ptr<RadialGradientCls>;

class SweepGradientCls : public GradientCls {
public:
    AlignmentGeometry center;

    double startAngle;

    double endAngle;

    TileMode tileMode;


     SweepGradientCls(AlignmentGeometry center, Unknown colors, double endAngle, double startAngle, Unknown stops, TileMode tileMode, Unknown transform);

    virtual Shader createShader(Rect rect, TextDirection textDirection);

    virtual SweepGradient scale(double factor);

    virtual Gradient lerpFrom(Gradient a, double t);

    virtual Gradient lerpTo(Gradient b, double t);

    static SweepGradient lerp(SweepGradient a, SweepGradient b, double t);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using SweepGradient = std::shared_ptr<SweepGradientCls>;


#endif