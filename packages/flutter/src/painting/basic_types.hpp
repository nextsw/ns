#ifndef PACKAGES_FLUTTER_SRC_PAINTING_BASIC_TYPES
#define PACKAGES_FLUTTER_SRC_PAINTING_BASIC_TYPES
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>


enum RenderComparison{
    identical,
    metadata,
    paint,
    layout,
} // end RenderComparison

enum Axis{
    horizontal,
    vertical,
} // end Axis
Axis flipAxis(Axis direction);


enum VerticalDirection{
    up,
    down,
} // end VerticalDirection

enum AxisDirection{
    up,
    right,
    down,
    left,
} // end AxisDirection
Axis axisDirectionToAxis(AxisDirection axisDirection);

AxisDirection textDirectionToAxisDirection(TextDirection textDirection);

AxisDirection flipAxisDirection(AxisDirection axisDirection);

bool axisDirectionIsReversed(AxisDirection axisDirection);



#endif