#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_QUATERNION
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_QUATERNION
#include <base.hpp>

#include <dart/core/core.hpp>


class QuaternionCls : public ObjectCls {
public:

    virtual Float64List storage();

    virtual double x();

    virtual void  x(double x);

    virtual double y();

    virtual void  y(double y);

    virtual double z();

    virtual void  z(double z);

    virtual double w();

    virtual void  w(double w);

     QuaternionCls(double x, double y, double z, double w);

    virtual void  fromRotation(Matrix3 rotationMatrix);

    virtual void  axisAngle(Vector3 axis, double angle);

    virtual void  fromTwoVectors(Vector3 a, Vector3 b);

    virtual void  copy(Quaternion original);

    virtual void  random(Random rn);

    virtual void  identity();

    virtual void  dq(Quaternion q, Vector3 omega);

    virtual void  euler(double yaw, double pitch, double roll);

    virtual void  fromFloat64List(Float64List _qStorage);
    virtual void  fromBuffer(ByteBuffer buffer, int offset);

    virtual Quaternion clone();

    virtual void setFrom(Quaternion source);

    virtual void setValues(double x, double y, double z, double w);

    virtual void setAxisAngle(Vector3 axis, double radians);

    virtual void setFromRotation(Matrix3 rotationMatrix);

    virtual void setFromTwoVectors(Vector3 a, Vector3 b);

    virtual void setRandom(Random rn);

    virtual void setDQ(Quaternion q, Vector3 omega);

    virtual void setEuler(double yaw, double pitch, double roll);

    virtual double normalize();

    virtual void conjugate();

    virtual void inverse();

    virtual Quaternion normalized();

    virtual Quaternion conjugated();

    virtual Quaternion inverted();

    virtual double radians();

    virtual Vector3 axis();

    virtual double length2();

    virtual double length();

    virtual Vector3 rotated(Vector3 v);

    virtual Vector3 rotate(Vector3 v);

    virtual void add(Quaternion arg);

    virtual void sub(Quaternion arg);

    virtual void scale(double scale);

    virtual Quaternion scaled(double scale);

    virtual Quaternion operator*(Quaternion other);

    virtual Quaternion operator+(Quaternion other);

    virtual Quaternion operator-(Quaternion other);

    virtual Quaternion operator-();

    virtual double operator[](int i);

    virtual void operator[]=(int i, double arg);

    virtual Matrix3 asRotationMatrix();

    virtual Matrix3 copyRotationInto(Matrix3 rotationMatrix);

    virtual String toString();

    virtual double relativeError(Quaternion correct);

    virtual double absoluteError(Quaternion correct);

private:
    Float64List _qStorage;


    virtual void  _();

};
using Quaternion = std::shared_ptr<QuaternionCls>;


#endif