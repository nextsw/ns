#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_FRUSTUM
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_FRUSTUM
#include <base.hpp>

#include <dart/core/core.hpp>


class FrustumCls : public ObjectCls {
public:

    virtual Plane plane0();

    virtual Plane plane1();

    virtual Plane plane2();

    virtual Plane plane3();

    virtual Plane plane4();

    virtual Plane plane5();

     FrustumCls();

    virtual void  copy(Frustum other);

    virtual void  matrix(Matrix4 matrix);

    virtual void copyFrom(Frustum other);

    virtual void setFromMatrix(Matrix4 matrix);

    virtual bool containsVector3(Vector3 point);

    virtual bool intersectsWithAabb3(Aabb3 aabb);

    virtual bool intersectsWithSphere(Sphere sphere);

    virtual void calculateCorners(Vector3 corner0, Vector3 corner1, Vector3 corner2, Vector3 corner3, Vector3 corner4, Vector3 corner5, Vector3 corner6, Vector3 corner7);

private:
    Plane _plane0;

    Plane _plane1;

    Plane _plane2;

    Plane _plane3;

    Plane _plane4;

    Plane _plane5;


    virtual bool _intersectsWithAabb3CheckPlane(Aabb3 aabb, Plane plane);

};
using Frustum = std::shared_ptr<FrustumCls>;


#endif