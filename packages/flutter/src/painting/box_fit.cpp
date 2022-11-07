#include "box_fit.hpp"
FittedSizes applyBoxFit(BoxFit fit, Size inputSize, Size outputSize) {
    if (inputSize.height <= 0.0 || inputSize.width <= 0.0 || outputSize.height <= 0.0 || outputSize.width <= 0.0) {
        return const FittedSizes(Size.zero, Size.zero);
    }
    Size sourceSize, destinationSize;
    ;
    return FittedSizes(sourceSize, destinationSize);
}
