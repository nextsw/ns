#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_MATRIX2
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_MATRIX2
#include <base.hpp>

#include <dart/core/core.hpp>


class Matrix2Cls : public ObjectCls {
public:

    virtual Float64List storage();

    static void solve(Matrix2 A, Vector2 b, Vector2 x);

    virtual int index(int col, int row);

    virtual double entry(int col, int row);

    virtual void setEntry(int col, int row, double v);

     Matrix2Cls(double arg0, double arg1, double arg2, double arg3);

    virtual void  fromList(List<double> values);

    virtual void  zero();

    virtual void  identity();

    virtual void  copy(Matrix2 other);

    virtual void  columns(Vector2 arg0, Vector2 arg1);

    virtual void  outer(Vector2 u, Vector2 v);

    virtual void  rotation(double radians);

    virtual void setValues(double arg0, double arg1, double arg2, double arg3);

    virtual void setColumns(Vector2 arg0, Vector2 arg1);

    virtual void setFrom(Matrix2 arg);

    virtual void setOuter(Vector2 u, Vector2 v);

    virtual void splatDiagonal(double arg);

    virtual void setDiagonal(Vector2 arg);

    virtual String toString();

    virtual int dimension();

    virtual double operator[](int i);

    virtual void operator[]=(int i, double v);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual Vector2 row0();

    virtual Vector2 row1();

    virtual void  row0(Vector2 arg);

    virtual void  row1(Vector2 arg);

    virtual void setRow(Vector2 arg, int row);

    virtual Vector2 getRow(int row);

    virtual void setColumn(Vector2 arg, int column);

    virtual Vector2 getColumn(int column);

    virtual Matrix2 clone();

    virtual Matrix2 copyInto(Matrix2 arg);

    virtual dynamic operator*(dynamic arg);

    virtual Matrix2 operator+(Matrix2 arg);

    virtual Matrix2 operator-(Matrix2 arg);

    virtual Matrix2 operator-();

    virtual void setZero();

    virtual void setIdentity();

    virtual Matrix2 transposed();

    virtual void transpose();

    virtual Matrix2 absolute();

    virtual double determinant();

    virtual double dotRow(int i, Vector2 v);

    virtual double dotColumn(int j, Vector2 v);

    virtual double trace();

    virtual double infinityNorm();

    virtual double relativeError(Matrix2 correct);

    virtual double absoluteError(Matrix2 correct);

    virtual double invert();

    virtual double copyInverse(Matrix2 arg);

    virtual void setRotation(double radians);

    virtual void scaleAdjoint(double scale);

    virtual void scale(double scale);

    virtual Matrix2 scaled(double scale);

    virtual void add(Matrix2 o);

    virtual void sub(Matrix2 o);

    virtual void negate();

    virtual void multiply(Matrix2 arg);

    virtual Matrix2 multiplied(Matrix2 arg);

    virtual void transposeMultiply(Matrix2 arg);

    virtual void multiplyTranspose(Matrix2 arg);

    virtual Vector2 transform(Vector2 arg);

    virtual Vector2 transformed(Vector2 arg, Vector2 out);

    virtual void copyIntoArray(List<num> array, int offset);

    virtual void copyFromArray(List<double> array, int offset);

private:
    Float64List _m2storage;


};
using Matrix2 = std::shared_ptr<Matrix2Cls>;


#endif