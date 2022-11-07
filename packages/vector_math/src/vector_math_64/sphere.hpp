#ifndef SPHERE_H
#define SPHERE_H
#include <memory>




class Sphere {
public:
    double radius;


    Vector3 center();

     Sphere();

    void  copy(Sphere other);

    void  centerRadius(Vector3 center, double radius);

    void copyFrom(Sphere other);

    bool containsVector3(Vector3 other);

    bool intersectsWithVector3(Vector3 other);

    bool intersectsWithSphere(Sphere other);

private:
    Vector3 _center;


};

#endif