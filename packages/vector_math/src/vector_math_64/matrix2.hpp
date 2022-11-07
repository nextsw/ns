#ifndef MATRIX2_H
#define MATRIX2_H
#include <memory>




class Matrix2 {
public:

    Float64List storage();

    static void solve(Matrix2 A, Vector2 b, Vector2 x);

    int index(int col, int row);

    double entry(int col, int row);

    void setEntry(int col, int row, double v);

     Matrix2(double arg0, double arg1, double arg2, double arg3);

    void  fromList(List<double> values);

    void  zero();

    void  identity();

    void  copy(Matrix2 other);

    void  columns(Vector2 arg0, Vector2 arg1);

    void  outer(Vector2 u, Vector2 v);

    void  rotation(double radians);

    void setValues(double arg0, double arg1, double arg2, double arg3);

    void setColumns(Vector2 arg0, Vector2 arg1);

    void setFrom(Matrix2 arg);

    void setOuter(Vector2 u, Vector2 v);

    void splatDiagonal(double arg);

    void setDiagonal(Vector2 arg);

    String toString();

    int dimension();

    double [](int i);

    void []=(int i, double v);

    bool ==(Object other);

    int hashCode();

    Vector2 row0();

    Vector2 row1();

    void  row0(Vector2 arg);

    void  row1(Vector2 arg);

    void setRow(Vector2 arg, int row);

    Vector2 getRow(int row);

    void setColumn(Vector2 arg, int column);

    Vector2 getColumn(int column);

    Matrix2 clone();

    Matrix2 copyInto(Matrix2 arg);

    dynamic *(dynamic arg);

    Matrix2 +(Matrix2 arg);

    Matrix2 -(Matrix2 arg);

    Matrix2 -();

    void setZero();

    void setIdentity();

    Matrix2 transposed();

    void transpose();

    Matrix2 absolute();

    double determinant();

    double dotRow(int i, Vector2 v);

    double dotColumn(int j, Vector2 v);

    double trace();

    double infinityNorm();

    double relativeError(Matrix2 correct);

    double absoluteError(Matrix2 correct);

    double invert();

    double copyInverse(Matrix2 arg);

    void setRotation(double radians);

    void scaleAdjoint(double scale);

    void scale(double scale);

    Matrix2 scaled(double scale);

    void add(Matrix2 o);

    void sub(Matrix2 o);

    void negate();

    void multiply(Matrix2 arg);

    Matrix2 multiplied(Matrix2 arg);

    void transposeMultiply(Matrix2 arg);

    void multiplyTranspose(Matrix2 arg);

    Vector2 transform(Vector2 arg);

    Vector2 transformed(Vector2 arg, Vector2 out);

    void copyIntoArray(List<num> array, int offset);

    void copyFromArray(List<double> array, int offset);

private:
    Float64List _m2storage;


};

#endif