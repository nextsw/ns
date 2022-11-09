#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_OBB3
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_OBB3
#include <base.hpp>

#include <dart/core/core.hpp>


class Obb3Cls : public ObjectCls {
public:

    virtual Vector3 center();

    virtual Vector3 halfExtents();

    virtual Vector3 axis0();

    virtual Vector3 axis1();

    virtual Vector3 axis2();

     Obb3Cls();

    virtual void  copy(Obb3 other);

    virtual void  centerExtentsAxes(Vector3 axis0, Vector3 axis1, Vector3 axis2, Vector3 center, Vector3 halfExtents);

    virtual void copyFrom(Obb3 other);

    virtual void copyInto(Obb3 other);

    virtual void resetRotation();

    virtual void translate(Vector3 offset);

    virtual void rotate(Matrix3 t);

    virtual void transform(Matrix4 t);

    virtual void copyCorner(Vector3 corner, int cornerIndex);

    virtual void closestPointTo(Vector3 p, Vector3 q);

    virtual bool intersectsWithObb3(double epsilon, Obb3 other);

    virtual bool intersectsWithTriangle(Triangle other, IntersectionResult result);

    virtual bool intersectsWithVector3(Vector3 other);

    virtual bool intersectsWithQuad(Quad other, IntersectionResult result);

private:
    Vector3 _center;

    Vector3 _halfExtents;

    Vector3 _axis0;

    Vector3 _axis1;

    Vector3 _axis2;

    static auto  _r;

    static auto  _absR;

    static auto  _t;

    static auto  _triangle;

    static auto  _aabb3;

    static auto  _zeroVector;

    static auto  _vector;

    static auto  _quadTriangle0;

    static auto  _quadTriangle1;


};
using Obb3 = std::shared_ptr<Obb3Cls>;


#endif