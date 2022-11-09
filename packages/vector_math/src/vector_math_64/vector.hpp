#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_VECTOR
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_VECTOR
#include <base.hpp>

#include <dart/core/core.hpp>

double dot2(Vector2 x, Vector2 y);

double dot3(Vector3 x, Vector3 y);

void cross3(Vector3 out, Vector3 x, Vector3 y);

double cross2(Vector2 x, Vector2 y);

void cross2A(Vector2 out, double x, Vector2 y);

void cross2B(Vector2 out, Vector2 x, double y);

void buildPlaneVectors(Vector3 planeNormal, Vector3 u, Vector3 v);


class VectorCls : public ObjectCls {
public:

    virtual List<double> storage();
private:

};
using Vector = std::shared_ptr<VectorCls>;


#endif