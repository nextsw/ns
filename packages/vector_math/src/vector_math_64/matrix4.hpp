#ifndef MATRIX4_H
#define MATRIX4_H
#include <memory>




class Matrix4 {
public:

    Float64List storage();

    static void solve2(Matrix4 A, Vector2 b, Vector2 x);

    static void solve3(Matrix4 A, Vector3 b, Vector3 x);

    static void solve(Matrix4 A, Vector4 b, Vector4 x);

    static Matrix4 tryInvert(Matrix4 other);

    int index(int col, int row);

    double entry(int col, int row);

    void setEntry(int col, int row, double v);

     Matrix4(double arg0, double arg1, double arg10, double arg11, double arg12, double arg13, double arg14, double arg15, double arg2, double arg3, double arg4, double arg5, double arg6, double arg7, double arg8, double arg9);

    void  fromList(List<double> values);

    void  zero();

    void  identity();

    void  copy(Matrix4 other);

    void  inverted(Matrix4 other);

    void  columns(Vector4 arg0, Vector4 arg1, Vector4 arg2, Vector4 arg3);

    void  outer(Vector4 u, Vector4 v);

    void  rotationX(double radians);

    void  rotationY(double radians);

    void  rotationZ(double radians);

    void  translation(Vector3 translation);

    void  translationValues(double x, double y, double z);

    void  diagonal3(Vector3 scale);

    void  diagonal3Values(double x, double y, double z);

    void  skewX(double alpha);

    void  skewY(double beta);

    void  skew(double alpha, double beta);

    void  fromFloat64List(Float64List _m4storage);

    void  fromBuffer(ByteBuffer buffer, int offset);

    void  compose(Quaternion rotation, Vector3 scale, Vector3 translation);

    void splatDiagonal(double arg);

    void setValues(double arg0, double arg1, double arg10, double arg11, double arg12, double arg13, double arg14, double arg15, double arg2, double arg3, double arg4, double arg5, double arg6, double arg7, double arg8, double arg9);

    void setColumns(Vector4 arg0, Vector4 arg1, Vector4 arg2, Vector4 arg3);

    void setFrom(Matrix4 arg);

    void setFromTranslationRotation(Vector3 arg0, Quaternion arg1);

    void setFromTranslationRotationScale(Quaternion rotation, Vector3 scale, Vector3 translation);

    void setUpper2x2(Matrix2 arg);

    void setDiagonal(Vector4 arg);

    void setOuter(Vector4 u, Vector4 v);

    String toString();

    int dimension();

    double [](int i);

    void []=(int i, double v);

    bool ==(Object other);

    int hashCode();

    Vector4 row0();

    Vector4 row1();

    Vector4 row2();

    Vector4 row3();

    void  row0(Vector4 arg);

    void  row1(Vector4 arg);

    void  row2(Vector4 arg);

    void  row3(Vector4 arg);

    void setRow(Vector4 arg, int row);

    Vector4 getRow(int row);

    void setColumn(Vector4 arg, int column);

    Vector4 getColumn(int column);

    Matrix4 clone();

    Matrix4 copyInto(Matrix4 arg);

    Matrix4 -();

    dynamic *(dynamic arg);

    Matrix4 +(Matrix4 arg);

    Matrix4 -(Matrix4 arg);

    void translate(dynamic x, double y, double z);

    void leftTranslate(dynamic x, double y, double z);

    void rotate(double angle, Vector3 axis);

    void rotateX(double angle);

    void rotateY(double angle);

    void rotateZ(double angle);

    void scale(dynamic x, double y, double z);

    Matrix4 scaled(dynamic x, double y, double z);

    void setZero();

    void setIdentity();

    Matrix4 transposed();

    void transpose();

    Matrix4 absolute();

    double determinant();

    double dotRow(int i, Vector4 v);

    double dotColumn(int j, Vector4 v);

    double trace();

    double infinityNorm();

    double relativeError(Matrix4 correct);

    double absoluteError(Matrix4 correct);

    Vector3 getTranslation();

    void setTranslation(Vector3 t);

    void setTranslationRaw(double x, double y, double z);

    Matrix3 getRotation();

    void copyRotation(Matrix3 rotation);

    void setRotation(Matrix3 r);

    Matrix3 getNormalMatrix();

    double getMaxScaleOnAxis();

    void transposeRotation();

    double invert();

    double copyInverse(Matrix4 arg);

    double invertRotation();

    void setRotationX(double radians);

    void setRotationY(double radians);

    void setRotationZ(double radians);

    void scaleAdjoint(double scale);

    Vector3 absoluteRotate(Vector3 arg);

    void add(Matrix4 o);

    void sub(Matrix4 o);

    void negate();

    void multiply(Matrix4 arg);

    Matrix4 multiplied(Matrix4 arg);

    void transposeMultiply(Matrix4 arg);

    void multiplyTranspose(Matrix4 arg);

    void decompose(Quaternion rotation, Vector3 scale, Vector3 translation);

    Vector3 rotate3(Vector3 arg);

    Vector3 rotated3(Vector3 arg, Vector3 out);

    Vector3 transform3(Vector3 arg);

    Vector3 transformed3(Vector3 arg, Vector3 out);

    Vector4 transform(Vector4 arg);

    Vector3 perspectiveTransform(Vector3 arg);

    Vector4 transformed(Vector4 arg, Vector4 out);

    void copyIntoArray(List<num> array, int offset);

    void copyFromArray(List<double> array, int offset);

    List<double> applyToVector3Array(List<double> array, int offset);

    Vector3 right();

    Vector3 up();

    Vector3 forward();

    bool isIdentity();

    bool isZero();

private:
    Float64List _m4storage;

    static Vector3 _decomposeV;

    static Matrix4 _decomposeM;

    static Matrix3 _decomposeR;


};

#endif