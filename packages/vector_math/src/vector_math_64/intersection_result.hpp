#ifndef INTERSECTION_RESULT_H
#define INTERSECTION_RESULT_H
#include <memory>




class IntersectionResult {
public:
    auto  axis;


    double depth();

     IntersectionResult();

private:
    double _depth;


};

#endif