#include "circle_border.hpp"
CircleBorderCls::CircleBorderCls(Unknown side) {
    {
        assert(side != nullptr);
    }
}

EdgeInsetsGeometry CircleBorderCls::dimensions() {
    ;
}

ShapeBorder CircleBorderCls::scale(double t) {
    return make<CircleBorderCls>(side->scale(t));
}

ShapeBorder CircleBorderCls::lerpFrom(ShapeBorder a, double t) {
    if (a is CircleBorder) {
        return make<CircleBorderCls>(BorderSideCls->lerp(a->side, side, t));
    }
    return super->lerpFrom(a, t);
}

ShapeBorder CircleBorderCls::lerpTo(ShapeBorder b, double t) {
    if (b is CircleBorder) {
        return make<CircleBorderCls>(BorderSideCls->lerp(side, b->side, t));
    }
    return super->lerpTo(b, t);
}

Path CircleBorderCls::getInnerPath(Rect rect, TextDirection textDirection) {
    double radius = rect->shortestSide / 2.0;
    double adjustedRadius;
    ;
    auto _c1 = make<PathCls>();_c1.addOval(RectCls->fromCircle(rect->center, math->max(0.0, adjustedRadius)));return _c1;
}

Path CircleBorderCls::getOuterPath(Rect rect, TextDirection textDirection) {
    auto _c1 = make<PathCls>();_c1.addOval(RectCls->fromCircle(rect->center, rect->shortestSide / 2.0));return _c1;
}

CircleBorder CircleBorderCls::copyWith(BorderSide side) {
    return make<CircleBorderCls>(side ?? this->side);
}

void CircleBorderCls::paint(Canvas canvas, Rect rect, TextDirection textDirection) {
    ;
}

bool CircleBorderCls::==(Object other) {
    if (other->runtimeType != runtimeType) {
        return false;
    }
    return other is CircleBorder && other->side == side;
}

int CircleBorderCls::hashCode() {
    return side->hashCode;
}

String CircleBorderCls::toString() {
    return "${objectRuntimeType(this, 'CircleBorder')}($side)";
}
