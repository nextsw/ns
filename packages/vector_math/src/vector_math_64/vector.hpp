#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_VECTOR
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_VECTOR
#include <base.hpp>

#include <dart/core/core.hpp>

double dot2(Vector2 x, Vector2 y);

double dot3(Vector3 x, Vector3 y);

void cross3(Vector3 x, Vector3 y, Vector3 out);

double cross2(Vector2 x, Vector2 y);

void cross2A(double x, Vector2 y, Vector2 out);

void cross2B(Vector2 x, double y, Vector2 out);

void buildPlaneVectors(Vector3 planeNormal, Vector3 u, Vector3 v);


class VectorCls : public ObjectCls {
public:

    virtual List<double> storage();
private:

};
using Vector = std::shared_ptr<VectorCls>;


#endif