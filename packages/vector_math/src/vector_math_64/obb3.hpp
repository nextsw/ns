#ifndef OBB3_H
#define OBB3_H
#include <memory>




class Obb3 {
public:

    Vector3 center();

    Vector3 halfExtents();

    Vector3 axis0();

    Vector3 axis1();

    Vector3 axis2();

     Obb3();

    void  copy(Obb3 other);

    void  centerExtentsAxes(Vector3 axis0, Vector3 axis1, Vector3 axis2, Vector3 center, Vector3 halfExtents);

    void copyFrom(Obb3 other);

    void copyInto(Obb3 other);

    void resetRotation();

    void translate(Vector3 offset);

    void rotate(Matrix3 t);

    void transform(Matrix4 t);

    void copyCorner(Vector3 corner, int cornerIndex);

    void closestPointTo(Vector3 p, Vector3 q);

    bool intersectsWithObb3(double epsilon, Obb3 other);

    bool intersectsWithTriangle(Triangle other, IntersectionResult result);

    bool intersectsWithVector3(Vector3 other);

    bool intersectsWithQuad(Quad other, IntersectionResult result);

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

#endif