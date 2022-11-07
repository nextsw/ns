#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H
#include <memory>

#include <flutter/foundation.hpp>
#include <vector_math/vector_math_64.hpp>
#include "basic_types.hpp"



class MatrixUtils {
public:

    static Offset getAsTranslation(Matrix4 transform);

    static double getAsScale(Matrix4 transform);

    static bool matrixEquals(Matrix4 a, Matrix4 b);

    static bool isIdentity(Matrix4 a);

    static Offset transformPoint(Offset point, Matrix4 transform);

    static Rect transformRect(Rect rect, Matrix4 transform);

    static Rect inverseTransformRect(Rect rect, Matrix4 transform);

    static Matrix4 createCylindricalProjectionTransform(double angle, Axis orientation, double perspective, double radius);

    static Matrix4 forceToPoint(Offset offset);

private:
    static Float64List _minMax;


    void  _();

    static Rect _safeTransformRect(Rect rect, Matrix4 transform);

    static void _accumulate(bool first, bool isAffine, Float64List m, double x, double y);

    static double _min4(double a, double b, double c, double d);

    static double _max4(double a, double b, double c, double d);

};
List<String> debugDescribeTransform(Matrix4 transform);


class TransformProperty : DiagnosticsProperty<Matrix4> {
public:

     TransformProperty(Unknown, Unknown, String name, Unknown, Unknown);

    String valueToString(TextTreeConfiguration parentConfiguration);

private:

};

#endif