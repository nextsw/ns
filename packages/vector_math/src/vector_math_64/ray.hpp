#ifndef RAY_H
#define RAY_H
#include <memory>




class Ray {
public:

    Vector3 origin();

    Vector3 direction();

     Ray();

    void  copy(Ray other);

    void  originDirection(Vector3 direction, Vector3 origin);

    void copyFrom(Ray other);

    Vector3 at(double t);

    void copyAt(Vector3 other, double t);

    double intersectsWithSphere(Sphere other);

    double intersectsWithTriangle(Triangle other);

    double intersectsWithQuad(Quad other);

    double intersectsWithAabb3(Aabb3 other);

private:
    Vector3 _origin;

    Vector3 _direction;

    static auto  _e1;

    static auto  _e2;

    static auto  _q;

    static auto  _s;

    static auto  _r;


};

#endif