#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_RAY
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_RAY
#include <base.hpp>

#include <dart/core/core.hpp>


class RayCls : public ObjectCls {
public:

    virtual Vector3 origin();

    virtual Vector3 direction();

     RayCls();

    virtual void  copy(Ray other);

    virtual void  originDirection(Vector3 direction, Vector3 origin);

    virtual void copyFrom(Ray other);

    virtual Vector3 at(double t);

    virtual void copyAt(Vector3 other, double t);

    virtual double intersectsWithSphere(Sphere other);

    virtual double intersectsWithTriangle(Triangle other);

    virtual double intersectsWithQuad(Quad other);

    virtual double intersectsWithAabb3(Aabb3 other);

private:
    Vector3 _origin;

    Vector3 _direction;

    static auto  _e1;

    static auto  _e2;

    static auto  _q;

    static auto  _s;

    static auto  _r;


};
using Ray = std::shared_ptr<RayCls>;


#endif