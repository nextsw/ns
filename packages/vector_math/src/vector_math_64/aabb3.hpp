#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_AABB3
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_AABB3
#include <base.hpp>

#include <dart/core/core.hpp>


class Aabb3Cls : public ObjectCls {
public:

    virtual Vector3 min();

    virtual Vector3 max();

    virtual Vector3 center();

     Aabb3Cls();

    virtual void  copy(Aabb3 other);

    virtual void  minMax(Vector3 max, Vector3 min);

    virtual void  fromSphere(Sphere sphere);

    virtual void  fromTriangle(Triangle triangle);

    virtual void  fromQuad(Quad quad);

    virtual void  fromObb3(Obb3 obb);

    virtual void  fromRay(double limitMax, double limitMin, Ray ray);

    virtual void  centerAndHalfExtents(Vector3 center, Vector3 halfExtents);

    virtual void  fromBuffer(ByteBuffer buffer, int offset);

    virtual void setCenterAndHalfExtents(Vector3 center, Vector3 halfExtents);

    virtual void setSphere(Sphere sphere);

    virtual void setTriangle(Triangle triangle);

    virtual void setQuad(Quad quad);

    virtual void setObb3(Obb3 obb);

    virtual void setRay(double limitMax, double limitMin, Ray ray);

    virtual void copyCenterAndHalfExtents(Vector3 center, Vector3 halfExtents);

    virtual void copyCenter(Vector3 center);

    virtual void copyFrom(Aabb3 other);

    virtual void transform(Matrix4 t);

    virtual void rotate(Matrix4 t);

    virtual Aabb3 transformed(Aabb3 out, Matrix4 t);

    virtual Aabb3 rotated(Aabb3 out, Matrix4 t);

    virtual void getPN(Vector3 outN, Vector3 outP, Vector3 planeNormal);

    virtual void hull(Aabb3 other);

    virtual void hullPoint(Vector3 point);

    virtual bool containsAabb3(Aabb3 other);

    virtual bool containsSphere(Sphere other);

    virtual bool containsVector3(Vector3 other);

    virtual bool containsTriangle(Triangle other);

    virtual bool intersectsWithAabb3(Aabb3 other);

    virtual bool intersectsWithSphere(Sphere other);

    virtual bool intersectsWithVector3(Vector3 other);

    virtual bool intersectsWithTriangle(double epsilon, Triangle other, IntersectionResult result);

    virtual bool intersectsWithPlane(Plane other, IntersectionResult result);

    virtual bool intersectsWithQuad(Quad other, IntersectionResult result);

private:
    Vector3 _min;

    Vector3 _max;

    static auto  _center;

    static auto  _halfExtents;

    static auto  _aabbCenter;

    static auto  _aabbHalfExtents;

    static auto  _v0;

    static auto  _v1;

    static auto  _v2;

    static auto  _f0;

    static auto  _f1;

    static auto  _f2;

    static auto  _trianglePlane;

    static auto  _u0;

    static auto  _u1;

    static auto  _u2;

    static auto  _quadTriangle0;

    static auto  _quadTriangle1;


    virtual void _updateCenterAndHalfExtents();

};
using Aabb3 = std::shared_ptr<Aabb3Cls>;


#endif