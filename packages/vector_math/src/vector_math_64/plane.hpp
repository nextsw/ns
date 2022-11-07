#ifndef PLANE_H
#define PLANE_H
#include <memory>




class Plane {
public:
    double constant;


    static void intersection(Plane a, Plane b, Plane c, Vector3 result);

    Vector3 normal();

     Plane();

    void  copy(Plane other);

    void  components(double constant, double x, double y, double z);

    void  normalconstant(double constant, Vector3 normal_);

    void copyFrom(Plane o);

    void setFromComponents(double w, double x, double y, double z);

    void normalize();

    double distanceToVector3(Vector3 point);

private:
    Vector3 _normal;


};

#endif