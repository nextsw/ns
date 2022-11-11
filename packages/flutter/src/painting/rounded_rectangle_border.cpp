#include "rounded_rectangle_border.hpp"
RoundedRectangleBorderCls::RoundedRectangleBorderCls(BorderRadiusGeometry borderRadius, Unknown side) {
    {
        assert(side != nullptr);
        assert(borderRadius != nullptr);
    }
}

EdgeInsetsGeometry RoundedRectangleBorderCls::dimensions() {
    ;
}

ShapeBorder RoundedRectangleBorderCls::scale(double t) {
    return make<RoundedRectangleBorderCls>(side->scale(t), borderRadius * t);
}

ShapeBorder RoundedRectangleBorderCls::lerpFrom(ShapeBorder a, double t) {
    assert(t != nullptr);
    if (is<RoundedRectangleBorder>(a)) {
        return make<RoundedRectangleBorderCls>(BorderSideCls->lerp(as<RoundedRectangleBorderCls>(a)->side, side, t), BorderRadiusGeometryCls->lerp(as<RoundedRectangleBorderCls>(a)->borderRadius, borderRadius, t)!);
    }
    if (is<CircleBorder>(a)) {
        return make<_RoundedRectangleToCircleBorderCls>(BorderSideCls->lerp(as<CircleBorderCls>(a)->side, side, t), borderRadius, 1.0 - t);
    }
    return super->lerpFrom(a, t);
}

ShapeBorder RoundedRectangleBorderCls::lerpTo(ShapeBorder b, double t) {
    assert(t != nullptr);
    if (is<RoundedRectangleBorder>(b)) {
        return make<RoundedRectangleBorderCls>(BorderSideCls->lerp(side, as<RoundedRectangleBorderCls>(b)->side, t), BorderRadiusGeometryCls->lerp(borderRadius, as<RoundedRectangleBorderCls>(b)->borderRadius, t)!);
    }
    if (is<CircleBorder>(b)) {
        return make<_RoundedRectangleToCircleBorderCls>(BorderSideCls->lerp(side, as<CircleBorderCls>(b)->side, t), borderRadius, t);
    }
    return super->lerpTo(b, t);
}

RoundedRectangleBorder RoundedRectangleBorderCls::copyWith(BorderRadiusGeometry borderRadius, BorderSide side) {
    return make<RoundedRectangleBorderCls>(side or this->side, borderRadius or this->borderRadius);
}

Path RoundedRectangleBorderCls::getInnerPath(Rect rect, TextDirection textDirection) {
    RRect borderRect = borderRadius->resolve(textDirection)->toRRect(rect);
    RRect adjustedRect;
    ;
    auto _c1 = make<PathCls>();_c1.addRRect(adjustedRect);return _c1;
}

Path RoundedRectangleBorderCls::getOuterPath(Rect rect, TextDirection textDirection) {
    auto _c1 = make<PathCls>();_c1.addRRect(borderRadius->resolve(textDirection)->toRRect(rect));return _c1;
}

void RoundedRectangleBorderCls::paint(Canvas canvas, Rect rect, TextDirection textDirection) {
    ;
}

bool RoundedRectangleBorderCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<RoundedRectangleBorder>(other) && other->side == side && other->borderRadius == borderRadius;
}

int RoundedRectangleBorderCls::hashCode() {
    return ObjectCls->hash(side, borderRadius);
}

String RoundedRectangleBorderCls::toString() {
    return __s("${objectRuntimeType(this, 'RoundedRectangleBorder')}($side, $borderRadius)");
}

EdgeInsetsGeometry _RoundedRectangleToCircleBorderCls::dimensions() {
    return EdgeInsetsCls->all(side->width);
}

ShapeBorder _RoundedRectangleToCircleBorderCls::scale(double t) {
    return make<_RoundedRectangleToCircleBorderCls>(side->scale(t), borderRadius * t, t);
}

ShapeBorder _RoundedRectangleToCircleBorderCls::lerpFrom(ShapeBorder a, double t) {
    assert(t != nullptr);
    if (is<RoundedRectangleBorder>(a)) {
        return make<_RoundedRectangleToCircleBorderCls>(BorderSideCls->lerp(as<RoundedRectangleBorderCls>(a)->side, side, t), BorderRadiusGeometryCls->lerp(as<RoundedRectangleBorderCls>(a)->borderRadius, borderRadius, t)!, circleness * t);
    }
    if (is<CircleBorder>(a)) {
        return make<_RoundedRectangleToCircleBorderCls>(BorderSideCls->lerp(as<CircleBorderCls>(a)->side, side, t), borderRadius, circleness + (1.0 - circleness) * (1.0 - t));
    }
    if (is<_RoundedRectangleToCircleBorder>(a)) {
        return make<_RoundedRectangleToCircleBorderCls>(BorderSideCls->lerp(as<_RoundedRectangleToCircleBorderCls>(a)->side, side, t), BorderRadiusGeometryCls->lerp(as<_RoundedRectangleToCircleBorderCls>(a)->borderRadius, borderRadius, t)!, ui->lerpDouble(as<_RoundedRectangleToCircleBorderCls>(a)->circleness, circleness, t)!);
    }
    return super->lerpFrom(a, t);
}

ShapeBorder _RoundedRectangleToCircleBorderCls::lerpTo(ShapeBorder b, double t) {
    if (is<RoundedRectangleBorder>(b)) {
        return make<_RoundedRectangleToCircleBorderCls>(BorderSideCls->lerp(side, as<RoundedRectangleBorderCls>(b)->side, t), BorderRadiusGeometryCls->lerp(borderRadius, as<RoundedRectangleBorderCls>(b)->borderRadius, t)!, circleness * (1.0 - t));
    }
    if (is<CircleBorder>(b)) {
        return make<_RoundedRectangleToCircleBorderCls>(BorderSideCls->lerp(side, as<CircleBorderCls>(b)->side, t), borderRadius, circleness + (1.0 - circleness) * t);
    }
    if (is<_RoundedRectangleToCircleBorder>(b)) {
        return make<_RoundedRectangleToCircleBorderCls>(BorderSideCls->lerp(side, as<_RoundedRectangleToCircleBorderCls>(b)->side, t), BorderRadiusGeometryCls->lerp(borderRadius, as<_RoundedRectangleToCircleBorderCls>(b)->borderRadius, t)!, ui->lerpDouble(circleness, as<_RoundedRectangleToCircleBorderCls>(b)->circleness, t)!);
    }
    return super->lerpTo(b, t);
}

Path _RoundedRectangleToCircleBorderCls::getInnerPath(Rect rect, TextDirection textDirection) {
    RRect borderRect = _adjustBorderRadius(rect, textDirection)!->toRRect(_adjustRect(rect));
    RRect adjustedRect;
    ;
    auto _c1 = make<PathCls>();_c1.addRRect(adjustedRect);return _c1;
}

Path _RoundedRectangleToCircleBorderCls::getOuterPath(Rect rect, TextDirection textDirection) {
    auto _c1 = make<PathCls>();_c1.addRRect(_adjustBorderRadius(rect, textDirection)!->toRRect(_adjustRect(rect)));return _c1;
}

_RoundedRectangleToCircleBorder _RoundedRectangleToCircleBorderCls::copyWith(BorderRadiusGeometry borderRadius, double circleness, BorderSide side) {
    return make<_RoundedRectangleToCircleBorderCls>(side or this->side, borderRadius or this->borderRadius, circleness or this->circleness);
}

void _RoundedRectangleToCircleBorderCls::paint(Canvas canvas, Rect rect, TextDirection textDirection) {
    ;
}

bool _RoundedRectangleToCircleBorderCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<_RoundedRectangleToCircleBorder>(other) && other->side == side && other->borderRadius == borderRadius && other->circleness == circleness;
}

int _RoundedRectangleToCircleBorderCls::hashCode() {
    return ObjectCls->hash(side, borderRadius, circleness);
}

String _RoundedRectangleToCircleBorderCls::toString() {
    return __s("RoundedRectangleBorder($side, $borderRadius, ${(circleness * 100).toStringAsFixed(1)}% of the way to being a CircleBorder)");
}

_RoundedRectangleToCircleBorderCls::_RoundedRectangleToCircleBorderCls(BorderRadiusGeometry borderRadius, double circleness, Unknown side) {
    {
        assert(side != nullptr);
        assert(borderRadius != nullptr);
        assert(circleness != nullptr);
    }
}

Rect _RoundedRectangleToCircleBorderCls::_adjustRect(Rect rect) {
    if (circleness == 0.0 || rect->width == rect->height) {
        return rect;
    }
    if (rect->width < rect->height) {
        double delta = circleness * (rect->height - rect->width) / 2.0;
        return RectCls->fromLTRB(rect->left, rect->top + delta, rect->right, rect->bottom - delta);
    } else {
        double delta = circleness * (rect->width - rect->height) / 2.0;
        return RectCls->fromLTRB(rect->left + delta, rect->top, rect->right - delta, rect->bottom);
    }
}

BorderRadius _RoundedRectangleToCircleBorderCls::_adjustBorderRadius(Rect rect, TextDirection textDirection) {
    BorderRadius resolvedRadius = borderRadius->resolve(textDirection);
    if (circleness == 0.0) {
        return resolvedRadius;
    }
    return BorderRadiusCls->lerp(resolvedRadius, BorderRadiusCls->circular(rect->shortestSide() / 2.0), circleness);
}
