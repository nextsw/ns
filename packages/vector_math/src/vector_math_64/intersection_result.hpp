#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_INTERSECTION_RESULT
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_INTERSECTION_RESULT
#include <base.hpp>

#include <dart/core/core.hpp>


class IntersectionResultCls : public ObjectCls {
public:
    auto  axis;


    virtual double depth();

     IntersectionResultCls();
private:
    double _depth;


};
using IntersectionResult = std::shared_ptr<IntersectionResultCls>;


#endif