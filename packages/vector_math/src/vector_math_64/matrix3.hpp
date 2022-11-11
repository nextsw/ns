#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_MATRIX3
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_MATRIX3
#include <base.hpp>

#include <dart/core/core.hpp>


class Matrix3Cls : public ObjectCls {
public:

    virtual Float64List storage();

    static void solve2(Matrix3 A, Vector2 x, Vector2 b);

    static void solve(Matrix3 A, Vector3 x, Vector3 b);

    virtual int index(int row, int col);

    virtual double entry(int row, int col);

    virtual void setEntry(int row, int col, double v);

     Matrix3Cls(double arg0, double arg1, double arg2, double arg3, double arg4, double arg5, double arg6, double arg7, double arg8);

    virtual void  fromList(List<double> values);

    virtual void  zero();

    virtual void  identity();

    virtual void  copy(Matrix3 other);

    virtual void  columns(Vector3 arg0, Vector3 arg1, Vector3 arg2);

    virtual void  outer(Vector3 u, Vector3 v);

    virtual void  rotationX(double radians);

    virtual void  rotationY(double radians);

    virtual void  rotationZ(double radians);

    virtual void setValues(double arg0, double arg1, double arg2, double arg3, double arg4, double arg5, double arg6, double arg7, double arg8);

    virtual void setColumns(Vector3 arg0, Vector3 arg1, Vector3 arg2);

    virtual void setFrom(Matrix3 arg);

    virtual void setOuter(Vector3 u, Vector3 v);

    virtual void splatDiagonal(double arg);

    virtual void setDiagonal(Vector3 arg);

    virtual void setUpper2x2(Matrix2 arg);

    virtual String toString();

    virtual int dimension();

    virtual double operator[](int i);

    virtual void operator[]=(int i, double v);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual Vector3 row0();

    virtual Vector3 row1();

    virtual Vector3 row2();

    virtual void  row0(Vector3 arg);

    virtual void  row1(Vector3 arg);

    virtual void  row2(Vector3 arg);

    virtual void setRow(int row, Vector3 arg);

    virtual Vector3 getRow(int row);

    virtual void setColumn(int column, Vector3 arg);

    virtual Vector3 getColumn(int column);

    virtual Matrix3 clone();

    virtual Matrix3 copyInto(Matrix3 arg);

    virtual dynamic operator*(dynamic arg);

    virtual Matrix3 operator+(Matrix3 arg);

    virtual Matrix3 operator-(Matrix3 arg);

    virtual Matrix3 operator-();

    virtual void setZero();

    virtual void setIdentity();

    virtual Matrix3 transposed();

    virtual void transpose();

    virtual Matrix3 absolute();

    virtual double determinant();

    virtual double dotRow(int i, Vector3 v);

    virtual double dotColumn(int j, Vector3 v);

    virtual double trace();

    virtual double infinityNorm();

    virtual double relativeError(Matrix3 correct);

    virtual double absoluteError(Matrix3 correct);

    virtual double invert();

    virtual double copyInverse(Matrix3 arg);

    virtual void copyNormalMatrix(Matrix4 arg);

    virtual void setRotationX(double radians);

    virtual void setRotationY(double radians);

    virtual void setRotationZ(double radians);

    virtual void scaleAdjoint(double scale);

    virtual Vector3 absoluteRotate(Vector3 arg);

    virtual Vector2 absoluteRotate2(Vector2 arg);

    virtual Vector2 transform2(Vector2 arg);

    virtual void scale(double scale);

    virtual Matrix3 scaled(double scale);

    virtual void add(Matrix3 o);

    virtual void sub(Matrix3 o);

    virtual void negate();

    virtual void multiply(Matrix3 arg);

    virtual Matrix3 multiplied(Matrix3 arg);

    virtual void transposeMultiply(Matrix3 arg);

    virtual void multiplyTranspose(Matrix3 arg);

    virtual Vector3 transform(Vector3 arg);

    virtual Vector3 transformed(Vector3 arg, Vector3 out);

    virtual void copyIntoArray(List<num> array, int offset);

    virtual void copyFromArray(List<double> array, int offset);

    virtual List<double> applyToVector3Array(List<double> array, int offset);

    virtual Vector3 right();

    virtual Vector3 up();

    virtual Vector3 forward();

    virtual bool isIdentity();

    virtual bool isZero();

private:
    Float64List _m3storage;


};
using Matrix3 = std::shared_ptr<Matrix3Cls>;


#endif