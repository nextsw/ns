#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_MATRIX4
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_MATRIX4
#include <base.hpp>

#include <dart/core/core.hpp>


class Matrix4Cls : public ObjectCls {
public:

    virtual Float64List storage();

    static void solve2(Matrix4 A, Vector2 x, Vector2 b);

    static void solve3(Matrix4 A, Vector3 x, Vector3 b);

    static void solve(Matrix4 A, Vector4 x, Vector4 b);

    static Matrix4 tryInvert(Matrix4 other);

    virtual int index(int row, int col);

    virtual double entry(int row, int col);

    virtual void setEntry(int row, int col, double v);

     Matrix4Cls(double arg0, double arg1, double arg2, double arg3, double arg4, double arg5, double arg6, double arg7, double arg8, double arg9, double arg10, double arg11, double arg12, double arg13, double arg14, double arg15);

    virtual void  fromList(List<double> values);

    virtual void  zero();

    virtual void  identity();

    virtual void  copy(Matrix4 other);

    virtual void  inverted(Matrix4 other);

    virtual void  columns(Vector4 arg0, Vector4 arg1, Vector4 arg2, Vector4 arg3);

    virtual void  outer(Vector4 u, Vector4 v);

    virtual void  rotationX(double radians);

    virtual void  rotationY(double radians);

    virtual void  rotationZ(double radians);

    virtual void  translation(Vector3 translation);

    virtual void  translationValues(double x, double y, double z);

    virtual void  diagonal3(Vector3 scale);

    virtual void  diagonal3Values(double x, double y, double z);

    virtual void  skewX(double alpha);

    virtual void  skewY(double beta);

    virtual void  skew(double alpha, double beta);

    virtual void  fromFloat64List(Float64List _m4storage);
    virtual void  fromBuffer(ByteBuffer buffer, int offset);

    virtual void  compose(Vector3 translation, Quaternion rotation, Vector3 scale);

    virtual void splatDiagonal(double arg);

    virtual void setValues(double arg0, double arg1, double arg2, double arg3, double arg4, double arg5, double arg6, double arg7, double arg8, double arg9, double arg10, double arg11, double arg12, double arg13, double arg14, double arg15);

    virtual void setColumns(Vector4 arg0, Vector4 arg1, Vector4 arg2, Vector4 arg3);

    virtual void setFrom(Matrix4 arg);

    virtual void setFromTranslationRotation(Vector3 arg0, Quaternion arg1);

    virtual void setFromTranslationRotationScale(Vector3 translation, Quaternion rotation, Vector3 scale);

    virtual void setUpper2x2(Matrix2 arg);

    virtual void setDiagonal(Vector4 arg);

    virtual void setOuter(Vector4 u, Vector4 v);

    virtual String toString();

    virtual int dimension();

    virtual double operator[](int i);

    virtual void operator[]=(int i, double v);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual Vector4 row0();

    virtual Vector4 row1();

    virtual Vector4 row2();

    virtual Vector4 row3();

    virtual void  row0(Vector4 arg);

    virtual void  row1(Vector4 arg);

    virtual void  row2(Vector4 arg);

    virtual void  row3(Vector4 arg);

    virtual void setRow(int row, Vector4 arg);

    virtual Vector4 getRow(int row);

    virtual void setColumn(int column, Vector4 arg);

    virtual Vector4 getColumn(int column);

    virtual Matrix4 clone();

    virtual Matrix4 copyInto(Matrix4 arg);

    virtual Matrix4 operator-();

    virtual dynamic operator*(dynamic arg);

    virtual Matrix4 operator+(Matrix4 arg);

    virtual Matrix4 operator-(Matrix4 arg);

    virtual void translate(dynamic x, double y, double z);

    virtual void leftTranslate(dynamic x, double y, double z);

    virtual void rotate(Vector3 axis, double angle);

    virtual void rotateX(double angle);

    virtual void rotateY(double angle);

    virtual void rotateZ(double angle);

    virtual void scale(dynamic x, double y, double z);

    virtual Matrix4 scaled(dynamic x, double y, double z);

    virtual void setZero();

    virtual void setIdentity();

    virtual Matrix4 transposed();

    virtual void transpose();

    virtual Matrix4 absolute();

    virtual double determinant();

    virtual double dotRow(int i, Vector4 v);

    virtual double dotColumn(int j, Vector4 v);

    virtual double trace();

    virtual double infinityNorm();

    virtual double relativeError(Matrix4 correct);

    virtual double absoluteError(Matrix4 correct);

    virtual Vector3 getTranslation();

    virtual void setTranslation(Vector3 t);

    virtual void setTranslationRaw(double x, double y, double z);

    virtual Matrix3 getRotation();

    virtual void copyRotation(Matrix3 rotation);

    virtual void setRotation(Matrix3 r);

    virtual Matrix3 getNormalMatrix();

    virtual double getMaxScaleOnAxis();

    virtual void transposeRotation();

    virtual double invert();

    virtual double copyInverse(Matrix4 arg);

    virtual double invertRotation();

    virtual void setRotationX(double radians);

    virtual void setRotationY(double radians);

    virtual void setRotationZ(double radians);

    virtual void scaleAdjoint(double scale);

    virtual Vector3 absoluteRotate(Vector3 arg);

    virtual void add(Matrix4 o);

    virtual void sub(Matrix4 o);

    virtual void negate();

    virtual void multiply(Matrix4 arg);

    virtual Matrix4 multiplied(Matrix4 arg);

    virtual void transposeMultiply(Matrix4 arg);

    virtual void multiplyTranspose(Matrix4 arg);

    virtual void decompose(Vector3 translation, Quaternion rotation, Vector3 scale);

    virtual Vector3 rotate3(Vector3 arg);

    virtual Vector3 rotated3(Vector3 arg, Vector3 out);

    virtual Vector3 transform3(Vector3 arg);

    virtual Vector3 transformed3(Vector3 arg, Vector3 out);

    virtual Vector4 transform(Vector4 arg);

    virtual Vector3 perspectiveTransform(Vector3 arg);

    virtual Vector4 transformed(Vector4 arg, Vector4 out);

    virtual void copyIntoArray(List<num> array, int offset);

    virtual void copyFromArray(List<double> array, int offset);

    virtual List<double> applyToVector3Array(List<double> array, int offset);

    virtual Vector3 right();

    virtual Vector3 up();

    virtual Vector3 forward();

    virtual bool isIdentity();

    virtual bool isZero();

private:
    Float64List _m4storage;

    static Vector3 _decomposeV;

    static Matrix4 _decomposeM;

    static Matrix3 _decomposeR;


};
using Matrix4 = std::shared_ptr<Matrix4Cls>;


#endif