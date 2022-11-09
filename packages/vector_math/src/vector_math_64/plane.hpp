#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_PLANE
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_PLANE
#include <base.hpp>

#include <dart/core/core.hpp>


class PlaneCls : public ObjectCls {
public:
    double constant;


    static void intersection(Plane a, Plane b, Plane c, Vector3 result);

    virtual Vector3 normal();

     PlaneCls();

    virtual void  copy(Plane other);

    virtual void  components(double constant, double x, double y, double z);

    virtual void  normalconstant(double constant, Vector3 normal_);

    virtual void copyFrom(Plane o);

    virtual void setFromComponents(double w, double x, double y, double z);

    virtual void normalize();

    virtual double distanceToVector3(Vector3 point);

private:
    Vector3 _normal;


};
using Plane = std::shared_ptr<PlaneCls>;


#endif