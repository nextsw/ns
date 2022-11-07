#ifndef AABB2_H
#define AABB2_H
#include <memory>




class Aabb2 {
public:

    Vector2 min();

    Vector2 max();

    Vector2 center();

     Aabb2();

    void  copy(Aabb2 other);

    void  minMax(Vector2 max, Vector2 min);

    void  centerAndHalfExtents(Vector2 center, Vector2 halfExtents);

    void  fromBuffer(ByteBuffer buffer, int offset);

    void setCenterAndHalfExtents(Vector2 center, Vector2 halfExtents);

    void copyCenterAndHalfExtents(Vector2 center, Vector2 halfExtents);

    void copyFrom(Aabb2 other);

    void transform(Matrix3 t);

    void rotate(Matrix3 t);

    Aabb2 transformed(Aabb2 out, Matrix3 t);

    Aabb2 rotated(Aabb2 out, Matrix3 t);

    void hull(Aabb2 other);

    void hullPoint(Vector2 point);

    bool containsAabb2(Aabb2 other);

    bool containsVector2(Vector2 other);

    bool intersectsWithAabb2(Aabb2 other);

    bool intersectsWithVector2(Vector2 other);

private:
    Vector2 _min;

    Vector2 _max;

    static auto  _center;

    static auto  _halfExtents;


    void _updateCenterAndHalfExtents();

};

#endif