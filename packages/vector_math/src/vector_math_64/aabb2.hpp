#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_AABB2
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_AABB2
#include <base.hpp>

#include <dart/core/core.hpp>


class Aabb2Cls : public ObjectCls {
public:

    virtual Vector2 min();

    virtual Vector2 max();

    virtual Vector2 center();

     Aabb2Cls();

    virtual void  copy(Aabb2 other);

    virtual void  minMax(Vector2 max, Vector2 min);

    virtual void  centerAndHalfExtents(Vector2 center, Vector2 halfExtents);

    virtual void  fromBuffer(ByteBuffer buffer, int offset);

    virtual void setCenterAndHalfExtents(Vector2 center, Vector2 halfExtents);

    virtual void copyCenterAndHalfExtents(Vector2 center, Vector2 halfExtents);

    virtual void copyFrom(Aabb2 other);

    virtual void transform(Matrix3 t);

    virtual void rotate(Matrix3 t);

    virtual Aabb2 transformed(Aabb2 out, Matrix3 t);

    virtual Aabb2 rotated(Aabb2 out, Matrix3 t);

    virtual void hull(Aabb2 other);

    virtual void hullPoint(Vector2 point);

    virtual bool containsAabb2(Aabb2 other);

    virtual bool containsVector2(Vector2 other);

    virtual bool intersectsWithAabb2(Aabb2 other);

    virtual bool intersectsWithVector2(Vector2 other);

private:
    Vector2 _min;

    Vector2 _max;

    static auto  _center;

    static auto  _halfExtents;


    virtual void _updateCenterAndHalfExtents();

};
using Aabb2 = std::shared_ptr<Aabb2Cls>;


#endif