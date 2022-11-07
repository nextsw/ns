#ifndef BASIC_TYPES_H
#define BASIC_TYPES_H
#include <memory>
#include <ui.hpp>
#include <flutter/foundation.hpp>

#include <ui/ui.hpp>



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