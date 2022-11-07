#ifndef QUATERNION_H
#define QUATERNION_H
#include <memory>




class Quaternion {
public:

    Float64List storage();

    double x();

    void  x(double x);

    double y();

    void  y(double y);

    double z();

    void  z(double z);

    double w();

    void  w(double w);

     Quaternion(double w, double x, double y, double z);

    void  fromRotation(Matrix3 rotationMatrix);

    void  axisAngle(double angle, Vector3 axis);

    void  fromTwoVectors(Vector3 a, Vector3 b);

    void  copy(Quaternion original);

    void  random(Random rn);

    void  identity();

    void  dq(Vector3 omega, Quaternion q);

    void  euler(double pitch, double roll, double yaw);

    void  fromFloat64List(Float64List _qStorage);

    void  fromBuffer(ByteBuffer buffer, int offset);

    Quaternion clone();

    void setFrom(Quaternion source);

    void setValues(double w, double x, double y, double z);

    void setAxisAngle(Vector3 axis, double radians);

    void setFromRotation(Matrix3 rotationMatrix);

    void setFromTwoVectors(Vector3 a, Vector3 b);

    void setRandom(Random rn);

    void setDQ(Vector3 omega, Quaternion q);

    void setEuler(double pitch, double roll, double yaw);

    double normalize();

    void conjugate();

    void inverse();

    Quaternion normalized();

    Quaternion conjugated();

    Quaternion inverted();

    double radians();

    Vector3 axis();

    double length2();

    double length();

    Vector3 rotated(Vector3 v);

    Vector3 rotate(Vector3 v);

    void add(Quaternion arg);

    void sub(Quaternion arg);

    void scale(double scale);

    Quaternion scaled(double scale);

    Quaternion *(Quaternion other);

    Quaternion +(Quaternion other);

    Quaternion -(Quaternion other);

    Quaternion -();

    double [](int i);

    void []=(double arg, int i);

    Matrix3 asRotationMatrix();

    Matrix3 copyRotationInto(Matrix3 rotationMatrix);

    String toString();

    double relativeError(Quaternion correct);

    double absoluteError(Quaternion correct);

private:
    Float64List _qStorage;


    void  _();

};

#endif