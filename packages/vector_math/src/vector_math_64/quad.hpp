#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_QUAD
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_QUAD
#include <base.hpp>

#include <dart/core/core.hpp>


class QuadCls : public ObjectCls {
public:

    virtual Vector3 point0();

    virtual Vector3 point1();

    virtual Vector3 point2();

    virtual Vector3 point3();

     QuadCls();

    virtual void  copy(Quad other);

    virtual void  points(Vector3 point0, Vector3 point1, Vector3 point2, Vector3 point3);

    virtual void copyFrom(Quad other);

    virtual void copyNormalInto(Vector3 normal);

    virtual void copyTriangles(Triangle triangle0, Triangle triangle1);

    virtual void transform(Matrix4 t);

    virtual void translate(Vector3 offset);

private:
    Vector3 _point0;

    Vector3 _point1;

    Vector3 _point2;

    Vector3 _point3;


};
using Quad = std::shared_ptr<QuadCls>;


#endif