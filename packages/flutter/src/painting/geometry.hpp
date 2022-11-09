#ifndef PACKAGES_FLUTTER_SRC_PAINTING_GEOMETRY
#define PACKAGES_FLUTTER_SRC_PAINTING_GEOMETRY
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic_types.hpp"

Offset positionDependentBox(Size childSize, double margin, bool preferBelow, Size size, Offset target, double verticalOffset);



#endif