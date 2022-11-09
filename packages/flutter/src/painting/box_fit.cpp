#include "box_fit.hpp"
FittedSizes applyBoxFit(BoxFit fit, Size inputSize, Size outputSize) {
    if (inputSize->height <= 0.0 || inputSize->width <= 0.0 || outputSize->height <= 0.0 || outputSize->width <= 0.0) {
        return make<FittedSizesCls>(SizeCls::zero, SizeCls::zero);
    }
    Size sourceSize, destinationSize;
    ;
    return make<FittedSizesCls>(sourceSize, destinationSize);
}
