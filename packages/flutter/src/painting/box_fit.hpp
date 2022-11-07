#ifndef BOX_FIT_H
#define BOX_FIT_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include "basic_types.hpp"



enum BoxFit{
    fill,
    contain,
    cover,
    fitWidth,
    fitHeight,
    none,
    scaleDown,
} // end BoxFit

class FittedSizes {
public:
    Size source;

    Size destination;


     FittedSizes(Size destination, Size source);

private:

};
FittedSizes applyBoxFit(BoxFit fit, Size inputSize, Size outputSize);


#endif