#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_SPHERE
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_SPHERE
#include <base.hpp>

#include <dart/core/core.hpp>


class SphereCls : public ObjectCls {
public:
    double radius;


    virtual Vector3 center();

     SphereCls();

    virtual void  copy(Sphere other);

    virtual void  centerRadius(Vector3 center, double radius);

    virtual void copyFrom(Sphere other);

    virtual bool containsVector3(Vector3 other);

    virtual bool intersectsWithVector3(Vector3 other);

    virtual bool intersectsWithSphere(Sphere other);

private:
    Vector3 _center;


};
using Sphere = std::shared_ptr<SphereCls>;


#endif