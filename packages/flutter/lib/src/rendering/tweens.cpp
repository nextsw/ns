#include "tweens.hpp"
FractionalOffset FractionalOffsetTweenCls::lerp(double t) {
    return FractionalOffsetCls->lerp(begin, end, t);
}

Alignment AlignmentTweenCls::lerp(double t) {
    return AlignmentCls->lerp(begin, end, t)!;
}

AlignmentGeometry AlignmentGeometryTweenCls::lerp(double t) {
    return AlignmentGeometryCls->lerp(begin, end, t);
}
