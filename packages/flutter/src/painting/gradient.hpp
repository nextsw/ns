#ifndef GRADIENT_H
#define GRADIENT_H
#include <memory>

#include <collection/collection.hpp>
#include <math/math.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <vector_math/vector_math_64.hpp>
#include "alignment.hpp"
#include "basic_types.hpp"



class _ColorsAndStops {
public:
    List<Color> colors;

    List<double> stops;


private:

     _ColorsAndStops(List<Color> colors, List<double> stops);

};
Color _sample(List<Color> colors, List<double> stops, double t);

_ColorsAndStops _interpolateColorsAndStops(List<Color> aColors, List<double> aStops, List<Color> bColors, List<double> bStops, double t);


class GradientTransform {
public:

     GradientTransform();

    Matrix4 transform(Rect bounds, TextDirection textDirection);

private:

};

class GradientRotation : GradientTransform {
public:
    double radians;


     GradientRotation(double radians);

    Matrix4 transform(Rect bounds, TextDirection textDirection);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class Gradient {
public:
    List<Color> colors;

    List<double> stops;

    GradientTransform transform;


     Gradient(List<Color> colors, List<double> stops, GradientTransform transform);

    Shader createShader(Rect rect, TextDirection textDirection);

    Gradient scale(double factor);

    Gradient lerpFrom(Gradient a, double t);

    Gradient lerpTo(Gradient b, double t);

    static Gradient lerp(Gradient a, Gradient b, double t);

private:

    List<double> _impliedStops();

    Float64List _resolveTransform(Rect bounds, TextDirection textDirection);

};

class LinearGradient : Gradient {
public:
    AlignmentGeometry begin;

    AlignmentGeometry end;

    TileMode tileMode;


     LinearGradient(AlignmentGeometry begin, Unknown, AlignmentGeometry end, Unknown, TileMode tileMode, Unknown);

    Shader createShader(Rect rect, TextDirection textDirection);

    LinearGradient scale(double factor);

    Gradient lerpFrom(Gradient a, double t);

    Gradient lerpTo(Gradient b, double t);

    static LinearGradient lerp(LinearGradient a, LinearGradient b, double t);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class RadialGradient : Gradient {
public:
    AlignmentGeometry center;

    double radius;

    TileMode tileMode;

    AlignmentGeometry focal;

    double focalRadius;


     RadialGradient(AlignmentGeometry center, Unknown, AlignmentGeometry focal, double focalRadius, double radius, Unknown, TileMode tileMode, Unknown);

    Shader createShader(Rect rect, TextDirection textDirection);

    RadialGradient scale(double factor);

    Gradient lerpFrom(Gradient a, double t);

    Gradient lerpTo(Gradient b, double t);

    static RadialGradient lerp(RadialGradient a, RadialGradient b, double t);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class SweepGradient : Gradient {
public:
    AlignmentGeometry center;

    double startAngle;

    double endAngle;

    TileMode tileMode;


     SweepGradient(AlignmentGeometry center, Unknown, double endAngle, double startAngle, Unknown, TileMode tileMode, Unknown);

    Shader createShader(Rect rect, TextDirection textDirection);

    SweepGradient scale(double factor);

    Gradient lerpFrom(Gradient a, double t);

    Gradient lerpTo(Gradient b, double t);

    static SweepGradient lerp(SweepGradient a, SweepGradient b, double t);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

#endif