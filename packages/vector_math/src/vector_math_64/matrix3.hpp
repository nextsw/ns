#ifndef MATRIX3_H
#define MATRIX3_H
#include <memory>




class Matrix3 {
public:

    Float64List storage();

    static void solve2(Matrix3 A, Vector2 b, Vector2 x);

    static void solve(Matrix3 A, Vector3 b, Vector3 x);

    int index(int col, int row);

    double entry(int col, int row);

    void setEntry(int col, int row, double v);

     Matrix3(double arg0, double arg1, double arg2, double arg3, double arg4, double arg5, double arg6, double arg7, double arg8);

    void  fromList(List<double> values);

    void  zero();

    void  identity();

    void  copy(Matrix3 other);

    void  columns(Vector3 arg0, Vector3 arg1, Vector3 arg2);

    void  outer(Vector3 u, Vector3 v);

    void  rotationX(double radians);

    void  rotationY(double radians);

    void  rotationZ(double radians);

    void setValues(double arg0, double arg1, double arg2, double arg3, double arg4, double arg5, double arg6, double arg7, double arg8);

    void setColumns(Vector3 arg0, Vector3 arg1, Vector3 arg2);

    void setFrom(Matrix3 arg);

    void setOuter(Vector3 u, Vector3 v);

    void splatDiagonal(double arg);

    void setDiagonal(Vector3 arg);

    void setUpper2x2(Matrix2 arg);

    String toString();

    int dimension();

    double [](int i);

    void []=(int i, double v);

    bool ==(Object other);

    int hashCode();

    Vector3 row0();

    Vector3 row1();

    Vector3 row2();

    void  row0(Vector3 arg);

    void  row1(Vector3 arg);

    void  row2(Vector3 arg);

    void setRow(Vector3 arg, int row);

    Vector3 getRow(int row);

    void setColumn(Vector3 arg, int column);

    Vector3 getColumn(int column);

    Matrix3 clone();

    Matrix3 copyInto(Matrix3 arg);

    dynamic *(dynamic arg);

    Matrix3 +(Matrix3 arg);

    Matrix3 -(Matrix3 arg);

    Matrix3 -();

    void setZero();

    void setIdentity();

    Matrix3 transposed();

    void transpose();

    Matrix3 absolute();

    double determinant();

    double dotRow(int i, Vector3 v);

    double dotColumn(int j, Vector3 v);

    double trace();

    double infinityNorm();

    double relativeError(Matrix3 correct);

    double absoluteError(Matrix3 correct);

    double invert();

    double copyInverse(Matrix3 arg);

    void copyNormalMatrix(Matrix4 arg);

    void setRotationX(double radians);

    void setRotationY(double radians);

    void setRotationZ(double radians);

    void scaleAdjoint(double scale);

    Vector3 absoluteRotate(Vector3 arg);

    Vector2 absoluteRotate2(Vector2 arg);

    Vector2 transform2(Vector2 arg);

    void scale(double scale);

    Matrix3 scaled(double scale);

    void add(Matrix3 o);

    void sub(Matrix3 o);

    void negate();

    void multiply(Matrix3 arg);

    Matrix3 multiplied(Matrix3 arg);

    void transposeMultiply(Matrix3 arg);

    void multiplyTranspose(Matrix3 arg);

    Vector3 transform(Vector3 arg);

    Vector3 transformed(Vector3 arg, Vector3 out);

    void copyIntoArray(List<num> array, int offset);

    void copyFromArray(List<double> array, int offset);

    List<double> applyToVector3Array(List<double> array, int offset);

    Vector3 right();

    Vector3 up();

    Vector3 forward();

    bool isIdentity();

    bool isZero();

private:
    Float64List _m3storage;


};

#endif