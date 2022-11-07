#include "tweens.hpp"
FractionalOffset FractionalOffsetTween::lerp(double t) {
    return FractionalOffset.lerp(begin, end, t);
}

Alignment AlignmentTween::lerp(double t) {
    return Alignment.lerp(begin, end, t)!;
}

AlignmentGeometry AlignmentGeometryTween::lerp(double t) {
    return AlignmentGeometry.lerp(begin, end, t);
}
