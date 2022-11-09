#ifndef PACKAGES_FLUTTER_SRC_PAINTING_BOX_FIT
#define PACKAGES_FLUTTER_SRC_PAINTING_BOX_FIT
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
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

class FittedSizesCls : public ObjectCls {
public:
    Size source;

    Size destination;


     FittedSizesCls(Size destination, Size source);
private:

};
using FittedSizes = std::shared_ptr<FittedSizesCls>;
FittedSizes applyBoxFit(BoxFit fit, Size inputSize, Size outputSize);



#endif