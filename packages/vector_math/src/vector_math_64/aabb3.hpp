#ifndef AABB3_H
#define AABB3_H
#include <memory>




class Aabb3 {
public:

    Vector3 min();

    Vector3 max();

    Vector3 center();

     Aabb3();

    void  copy(Aabb3 other);

    void  minMax(Vector3 max, Vector3 min);

    void  fromSphere(Sphere sphere);

    void  fromTriangle(Triangle triangle);

    void  fromQuad(Quad quad);

    void  fromObb3(Obb3 obb);

    void  fromRay(double limitMax, double limitMin, Ray ray);

    void  centerAndHalfExtents(Vector3 center, Vector3 halfExtents);

    void  fromBuffer(ByteBuffer buffer, int offset);

    void setCenterAndHalfExtents(Vector3 center, Vector3 halfExtents);

    void setSphere(Sphere sphere);

    void setTriangle(Triangle triangle);

    void setQuad(Quad quad);

    void setObb3(Obb3 obb);

    void setRay(double limitMax, double limitMin, Ray ray);

    void copyCenterAndHalfExtents(Vector3 center, Vector3 halfExtents);

    void copyCenter(Vector3 center);

    void copyFrom(Aabb3 other);

    void transform(Matrix4 t);

    void rotate(Matrix4 t);

    Aabb3 transformed(Aabb3 out, Matrix4 t);

    Aabb3 rotated(Aabb3 out, Matrix4 t);

    void getPN(Vector3 outN, Vector3 outP, Vector3 planeNormal);

    void hull(Aabb3 other);

    void hullPoint(Vector3 point);

    bool containsAabb3(Aabb3 other);

    bool containsSphere(Sphere other);

    bool containsVector3(Vector3 other);

    bool containsTriangle(Triangle other);

    bool intersectsWithAabb3(Aabb3 other);

    bool intersectsWithSphere(Sphere other);

    bool intersectsWithVector3(Vector3 other);

    bool intersectsWithTriangle(double epsilon, Triangle other, IntersectionResult result);

    bool intersectsWithPlane(Plane other, IntersectionResult result);

    bool intersectsWithQuad(Quad other, IntersectionResult result);

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


    void _updateCenterAndHalfExtents();

};

#endif