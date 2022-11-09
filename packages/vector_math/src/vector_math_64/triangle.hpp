#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_TRIANGLE
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_TRIANGLE
#include <base.hpp>

#include <dart/core/core.hpp>


class TriangleCls : public ObjectCls {
public:

    virtual Vector3 point0();

    virtual Vector3 point1();

    virtual Vector3 point2();

     TriangleCls();

    virtual void  copy(Triangle other);

    virtual void  points(Vector3 point0, Vector3 point1, Vector3 point2);

    virtual void copyFrom(Triangle other);

    virtual void copyNormalInto(Vector3 normal);

    virtual void transform(Matrix4 t);

    virtual void translate(Vector3 offset);

private:
    Vector3 _point0;

    Vector3 _point1;

    Vector3 _point2;


};
using Triangle = std::shared_ptr<TriangleCls>;


#endif