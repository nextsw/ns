#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include "basic_types.hpp"


Offset positionDependentBox(Size childSize, double margin, bool preferBelow, Size size, Offset target, double verticalOffset);


#endif