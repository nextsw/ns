#ifndef PACKAGES_FLUTTER_SRC_PAINTING_MATRIX_UTILS
#define PACKAGES_FLUTTER_SRC_PAINTING_MATRIX_UTILS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "basic_types.hpp"


class MatrixUtilsCls : public ObjectCls {
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


    virtual void  _();
    static Rect _safeTransformRect(Rect rect, Matrix4 transform);

    static void _accumulate(bool first, bool isAffine, Float64List m, double x, double y);

    static double _min4(double a, double b, double c, double d);

    static double _max4(double a, double b, double c, double d);

};
using MatrixUtils = std::shared_ptr<MatrixUtilsCls>;
List<String> debugDescribeTransform(Matrix4 transform);


class TransformPropertyCls : public DiagnosticsPropertyCls<Matrix4> {
public:

     TransformPropertyCls(Unknown defaultValue, Unknown level, String name, Unknown showName, Unknown value);

    virtual String valueToString(TextTreeConfiguration parentConfiguration);

private:

};
using TransformProperty = std::shared_ptr<TransformPropertyCls>;


#endif