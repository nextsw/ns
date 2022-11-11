#include "stadium_border.hpp"
StadiumBorderCls::StadiumBorderCls(Unknown side) {
    {
        assert(side != nullptr);
    }
}

EdgeInsetsGeometry StadiumBorderCls::dimensions() {
    ;
}

ShapeBorder StadiumBorderCls::scale(double t) {
    return make<StadiumBorderCls>(side->scale(t));
}

ShapeBorder StadiumBorderCls::lerpFrom(ShapeBorder a, double t) {
    assert(t != nullptr);
    if (is<StadiumBorder>(a)) {
        return make<StadiumBorderCls>(BorderSideCls->lerp(as<StadiumBorderCls>(a)->side, side, t));
    }
    if (is<CircleBorder>(a)) {
        return make<_StadiumToCircleBorderCls>(BorderSideCls->lerp(as<CircleBorderCls>(a)->side, side, t), 1.0 - t);
    }
    if (is<RoundedRectangleBorder>(a)) {
        return make<_StadiumToRoundedRectangleBorderCls>(BorderSideCls->lerp(as<RoundedRectangleBorderCls>(a)->side, side, t), as<BorderRadius>(as<RoundedRectangleBorderCls>(a)->borderRadius), 1.0 - t);
    }
    return super->lerpFrom(a, t);
}

ShapeBorder StadiumBorderCls::lerpTo(ShapeBorder b, double t) {
    assert(t != nullptr);
    if (is<StadiumBorder>(b)) {
        return make<StadiumBorderCls>(BorderSideCls->lerp(side, as<StadiumBorderCls>(b)->side, t));
    }
    if (is<CircleBorder>(b)) {
        return make<_StadiumToCircleBorderCls>(BorderSideCls->lerp(side, as<CircleBorderCls>(b)->side, t), t);
    }
    if (is<RoundedRectangleBorder>(b)) {
        return make<_StadiumToRoundedRectangleBorderCls>(BorderSideCls->lerp(side, as<RoundedRectangleBorderCls>(b)->side, t), as<BorderRadius>(as<RoundedRectangleBorderCls>(b)->borderRadius), t);
    }
    return super->lerpTo(b, t);
}

StadiumBorder StadiumBorderCls::copyWith(BorderSide side) {
    return make<StadiumBorderCls>(side or this->side);
}

Path StadiumBorderCls::getInnerPath(Rect rect, TextDirection textDirection) {
    Radius radius = RadiusCls->circular(rect->shortestSide() / 2.0);
    RRect borderRect = RRectCls->fromRectAndRadius(rect, radius);
    RRect adjustedRect;
    ;
    auto _c1 = make<PathCls>();_c1.addRRect(adjustedRect);return _c1;
}

Path StadiumBorderCls::getOuterPath(Rect rect, TextDirection textDirection) {
    Radius radius = RadiusCls->circular(rect->shortestSide() / 2.0);
    auto _c1 = make<PathCls>();_c1.addRRect(RRectCls->fromRectAndRadius(rect, radius));return _c1;
}

void StadiumBorderCls::paint(Canvas canvas, Rect rect, TextDirection textDirection) {
    ;
}

bool StadiumBorderCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<StadiumBorder>(other) && other->side == side;
}

int StadiumBorderCls::hashCode() {
    return side->hashCode();
}

String StadiumBorderCls::toString() {
    return __s("${objectRuntimeType(this, 'StadiumBorder')}($side)");
}

EdgeInsetsGeometry _StadiumToCircleBorderCls::dimensions() {
    return EdgeInsetsCls->all(side->width);
}

ShapeBorder _StadiumToCircleBorderCls::scale(double t) {
    return make<_StadiumToCircleBorderCls>(side->scale(t), t);
}

ShapeBorder _StadiumToCircleBorderCls::lerpFrom(ShapeBorder a, double t) {
    assert(t != nullptr);
    if (is<StadiumBorder>(a)) {
        return make<_StadiumToCircleBorderCls>(BorderSideCls->lerp(as<StadiumBorderCls>(a)->side, side, t), circleness * t);
    }
    if (is<CircleBorder>(a)) {
        return make<_StadiumToCircleBorderCls>(BorderSideCls->lerp(as<CircleBorderCls>(a)->side, side, t), circleness + (1.0 - circleness) * (1.0 - t));
    }
    if (is<_StadiumToCircleBorder>(a)) {
        return make<_StadiumToCircleBorderCls>(BorderSideCls->lerp(as<_StadiumToCircleBorderCls>(a)->side, side, t), ui->lerpDouble(as<_StadiumToCircleBorderCls>(a)->circleness, circleness, t)!);
    }
    return super->lerpFrom(a, t);
}

ShapeBorder _StadiumToCircleBorderCls::lerpTo(ShapeBorder b, double t) {
    assert(t != nullptr);
    if (is<StadiumBorder>(b)) {
        return make<_StadiumToCircleBorderCls>(BorderSideCls->lerp(side, as<StadiumBorderCls>(b)->side, t), circleness * (1.0 - t));
    }
    if (is<CircleBorder>(b)) {
        return make<_StadiumToCircleBorderCls>(BorderSideCls->lerp(side, as<CircleBorderCls>(b)->side, t), circleness + (1.0 - circleness) * t);
    }
    if (is<_StadiumToCircleBorder>(b)) {
        return make<_StadiumToCircleBorderCls>(BorderSideCls->lerp(side, as<_StadiumToCircleBorderCls>(b)->side, t), ui->lerpDouble(circleness, as<_StadiumToCircleBorderCls>(b)->circleness, t)!);
    }
    return super->lerpTo(b, t);
}

Path _StadiumToCircleBorderCls::getInnerPath(Rect rect, TextDirection textDirection) {
    auto _c1 = make<PathCls>();_c1.addRRect(_adjustBorderRadius(rect)->toRRect(_adjustRect(rect))->deflate(side->width));return _c1;
}

Path _StadiumToCircleBorderCls::getOuterPath(Rect rect, TextDirection textDirection) {
    auto _c1 = make<PathCls>();_c1.addRRect(_adjustBorderRadius(rect)->toRRect(_adjustRect(rect)));return _c1;
}

_StadiumToCircleBorder _StadiumToCircleBorderCls::copyWith(double circleness, BorderSide side) {
    return make<_StadiumToCircleBorderCls>(side or this->side, circleness or this->circleness);
}

void _StadiumToCircleBorderCls::paint(Canvas canvas, Rect rect, TextDirection textDirection) {
    ;
}

bool _StadiumToCircleBorderCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<_StadiumToCircleBorder>(other) && other->side == side && other->circleness == circleness;
}

int _StadiumToCircleBorderCls::hashCode() {
    return ObjectCls->hash(side, circleness);
}

String _StadiumToCircleBorderCls::toString() {
    return __s("StadiumBorder($side, ${(circleness * 100).toStringAsFixed(1)}% of the way to being a CircleBorder)");
}

_StadiumToCircleBorderCls::_StadiumToCircleBorderCls(double circleness, Unknown side) {
    {
        assert(side != nullptr);
        assert(circleness != nullptr);
    }
}

Rect _StadiumToCircleBorderCls::_adjustRect(Rect rect) {
    if (circleness == 0.0 || rect->width() == rect->height()) {
        return rect;
    }
    if (rect->width() < rect->height()) {
        double delta = circleness * (rect->height() - rect->width()) / 2.0;
        return RectCls->fromLTRB(rect->left, rect->top + delta, rect->right, rect->bottom - delta);
    } else {
        double delta = circleness * (rect->width() - rect->height()) / 2.0;
        return RectCls->fromLTRB(rect->left + delta, rect->top, rect->right - delta, rect->bottom);
    }
}

BorderRadius _StadiumToCircleBorderCls::_adjustBorderRadius(Rect rect) {
    return BorderRadiusCls->circular(rect->shortestSide() / 2.0);
}

EdgeInsetsGeometry _StadiumToRoundedRectangleBorderCls::dimensions() {
    return EdgeInsetsCls->all(side->width);
}

ShapeBorder _StadiumToRoundedRectangleBorderCls::scale(double t) {
    return make<_StadiumToRoundedRectangleBorderCls>(side->scale(t), borderRadius * t, t);
}

ShapeBorder _StadiumToRoundedRectangleBorderCls::lerpFrom(ShapeBorder a, double t) {
    assert(t != nullptr);
    if (is<StadiumBorder>(a)) {
        return make<_StadiumToRoundedRectangleBorderCls>(BorderSideCls->lerp(as<StadiumBorderCls>(a)->side, side, t), borderRadius, rectness * t);
    }
    if (is<RoundedRectangleBorder>(a)) {
        return make<_StadiumToRoundedRectangleBorderCls>(BorderSideCls->lerp(as<RoundedRectangleBorderCls>(a)->side, side, t), borderRadius, rectness + (1.0 - rectness) * (1.0 - t));
    }
    if (is<_StadiumToRoundedRectangleBorder>(a)) {
        return make<_StadiumToRoundedRectangleBorderCls>(BorderSideCls->lerp(as<_StadiumToRoundedRectangleBorderCls>(a)->side, side, t), BorderRadiusCls->lerp(as<_StadiumToRoundedRectangleBorderCls>(a)->borderRadius, borderRadius, t)!, ui->lerpDouble(as<_StadiumToRoundedRectangleBorderCls>(a)->rectness, rectness, t)!);
    }
    return super->lerpFrom(a, t);
}

ShapeBorder _StadiumToRoundedRectangleBorderCls::lerpTo(ShapeBorder b, double t) {
    assert(t != nullptr);
    if (is<StadiumBorder>(b)) {
        return make<_StadiumToRoundedRectangleBorderCls>(BorderSideCls->lerp(side, as<StadiumBorderCls>(b)->side, t), borderRadius, rectness * (1.0 - t));
    }
    if (is<RoundedRectangleBorder>(b)) {
        return make<_StadiumToRoundedRectangleBorderCls>(BorderSideCls->lerp(side, as<RoundedRectangleBorderCls>(b)->side, t), borderRadius, rectness + (1.0 - rectness) * t);
    }
    if (is<_StadiumToRoundedRectangleBorder>(b)) {
        return make<_StadiumToRoundedRectangleBorderCls>(BorderSideCls->lerp(side, as<_StadiumToRoundedRectangleBorderCls>(b)->side, t), BorderRadiusCls->lerp(borderRadius, as<_StadiumToRoundedRectangleBorderCls>(b)->borderRadius, t)!, ui->lerpDouble(rectness, as<_StadiumToRoundedRectangleBorderCls>(b)->rectness, t)!);
    }
    return super->lerpTo(b, t);
}

Path _StadiumToRoundedRectangleBorderCls::getInnerPath(Rect rect, TextDirection textDirection) {
    RRect borderRect = _adjustBorderRadius(rect)->toRRect(rect);
    RRect adjustedRect;
    ;
    auto _c1 = make<PathCls>();_c1.addRRect(adjustedRect);return _c1;
}

Path _StadiumToRoundedRectangleBorderCls::getOuterPath(Rect rect, TextDirection textDirection) {
    auto _c1 = make<PathCls>();_c1.addRRect(_adjustBorderRadius(rect)->toRRect(rect));return _c1;
}

_StadiumToRoundedRectangleBorder _StadiumToRoundedRectangleBorderCls::copyWith(BorderRadius borderRadius, double rectness, BorderSide side) {
    return make<_StadiumToRoundedRectangleBorderCls>(side or this->side, borderRadius or this->borderRadius, rectness or this->rectness);
}

void _StadiumToRoundedRectangleBorderCls::paint(Canvas canvas, Rect rect, TextDirection textDirection) {
    ;
}

bool _StadiumToRoundedRectangleBorderCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<_StadiumToRoundedRectangleBorder>(other) && other->side == side && other->borderRadius == borderRadius && other->rectness == rectness;
}

int _StadiumToRoundedRectangleBorderCls::hashCode() {
    return ObjectCls->hash(side, borderRadius, rectness);
}

String _StadiumToRoundedRectangleBorderCls::toString() {
    return __s("StadiumBorder($side, $borderRadius, ${(rectness * 100).toStringAsFixed(1)}% of the way to being a RoundedRectangleBorder)");
}

_StadiumToRoundedRectangleBorderCls::_StadiumToRoundedRectangleBorderCls(BorderRadius borderRadius, double rectness, Unknown side) {
    {
        assert(side != nullptr);
        assert(borderRadius != nullptr);
        assert(rectness != nullptr);
    }
}

BorderRadius _StadiumToRoundedRectangleBorderCls::_adjustBorderRadius(Rect rect) {
    return BorderRadiusCls->lerp(borderRadius, BorderRadiusCls->all(RadiusCls->circular(rect->shortestSide() / 2.0)), 1.0 - rectness)!;
}
