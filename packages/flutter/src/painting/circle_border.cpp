#include "circle_border.hpp"
CircleBorder::CircleBorder(Unknown) {
    {
        assert(side != nullptr);
    }
}

EdgeInsetsGeometry CircleBorder::dimensions() {
    ;
}

ShapeBorder CircleBorder::scale(double t) {
    return CircleBorder(side.scale(t));
}

ShapeBorder CircleBorder::lerpFrom(ShapeBorder a, double t) {
    if (a is CircleBorder) {
        return CircleBorder(BorderSide.lerp(a.side, side, t));
    }
    return super.lerpFrom(a, t);
}

ShapeBorder CircleBorder::lerpTo(ShapeBorder b, double t) {
    if (b is CircleBorder) {
        return CircleBorder(BorderSide.lerp(side, b.side, t));
    }
    return super.lerpTo(b, t);
}

Path CircleBorder::getInnerPath(Rect rect, TextDirection textDirection) {
    double radius = rect.shortestSide / 2.0;
    double adjustedRadius;
    ;
    return ;
}

Path CircleBorder::getOuterPath(Rect rect, TextDirection textDirection) {
    return ;
}

CircleBorder CircleBorder::copyWith(BorderSide side) {
    return CircleBorder(side ?? this.side);
}

void CircleBorder::paint(Canvas canvas, Rect rect, TextDirection textDirection) {
    ;
}

bool CircleBorder::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is CircleBorder && other.side == side;
}

int CircleBorder::hashCode() {
    return side.hashCode;
}

String CircleBorder::toString() {
    return "${objectRuntimeType(this, 'CircleBorder')}($side)";
}
