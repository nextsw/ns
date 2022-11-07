#include "stadium_border.hpp"
StadiumBorder::StadiumBorder(Unknown) {
    {
        assert(side != nullptr);
    }
}

EdgeInsetsGeometry StadiumBorder::dimensions() {
    ;
}

ShapeBorder StadiumBorder::scale(double t) {
    return StadiumBorder(side.scale(t));
}

ShapeBorder StadiumBorder::lerpFrom(ShapeBorder a, double t) {
    assert(t != nullptr);
    if (a is StadiumBorder) {
        return StadiumBorder(BorderSide.lerp(a.side, side, t));
    }
    if (a is CircleBorder) {
        return _StadiumToCircleBorder(BorderSide.lerp(a.side, side, t), 1.0 - t);
    }
    if (a is RoundedRectangleBorder) {
        return _StadiumToRoundedRectangleBorder(BorderSide.lerp(a.side, side, t), (, 1.0 - t);
    }
    return super.lerpFrom(a, t);
}

ShapeBorder StadiumBorder::lerpTo(ShapeBorder b, double t) {
    assert(t != nullptr);
    if (b is StadiumBorder) {
        return StadiumBorder(BorderSide.lerp(side, b.side, t));
    }
    if (b is CircleBorder) {
        return _StadiumToCircleBorder(BorderSide.lerp(side, b.side, t), t);
    }
    if (b is RoundedRectangleBorder) {
        return _StadiumToRoundedRectangleBorder(BorderSide.lerp(side, b.side, t), (, t);
    }
    return super.lerpTo(b, t);
}

StadiumBorder StadiumBorder::copyWith(BorderSide side) {
    return StadiumBorder(side ?? this.side);
}

Path StadiumBorder::getInnerPath(Rect rect, TextDirection textDirection) {
    Radius radius = Radius.circular(rect.shortestSide / 2.0);
    RRect borderRect = RRect.fromRectAndRadius(rect, radius);
    RRect adjustedRect;
    ;
    return ;
}

Path StadiumBorder::getOuterPath(Rect rect, TextDirection textDirection) {
    Radius radius = Radius.circular(rect.shortestSide / 2.0);
    return ;
}

void StadiumBorder::paint(Canvas canvas, Rect rect, TextDirection textDirection) {
    ;
}

bool StadiumBorder::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is StadiumBorder && other.side == side;
}

int StadiumBorder::hashCode() {
    return side.hashCode;
}

String StadiumBorder::toString() {
    return "${objectRuntimeType(this, 'StadiumBorder')}($side)";
}

EdgeInsetsGeometry _StadiumToCircleBorder::dimensions() {
    return EdgeInsets.all(side.width);
}

ShapeBorder _StadiumToCircleBorder::scale(double t) {
    return _StadiumToCircleBorder(side.scale(t), t);
}

ShapeBorder _StadiumToCircleBorder::lerpFrom(ShapeBorder a, double t) {
    assert(t != nullptr);
    if (a is StadiumBorder) {
        return _StadiumToCircleBorder(BorderSide.lerp(a.side, side, t), circleness * t);
    }
    if (a is CircleBorder) {
        return _StadiumToCircleBorder(BorderSide.lerp(a.side, side, t), circleness + (1.0 - circleness) * (1.0 - t));
    }
    if (a is _StadiumToCircleBorder) {
        return _StadiumToCircleBorder(BorderSide.lerp(a.side, side, t), ui.lerpDouble(a.circleness, circleness, t)!);
    }
    return super.lerpFrom(a, t);
}

ShapeBorder _StadiumToCircleBorder::lerpTo(ShapeBorder b, double t) {
    assert(t != nullptr);
    if (b is StadiumBorder) {
        return _StadiumToCircleBorder(BorderSide.lerp(side, b.side, t), circleness * (1.0 - t));
    }
    if (b is CircleBorder) {
        return _StadiumToCircleBorder(BorderSide.lerp(side, b.side, t), circleness + (1.0 - circleness) * t);
    }
    if (b is _StadiumToCircleBorder) {
        return _StadiumToCircleBorder(BorderSide.lerp(side, b.side, t), ui.lerpDouble(circleness, b.circleness, t)!);
    }
    return super.lerpTo(b, t);
}

Path _StadiumToCircleBorder::getInnerPath(Rect rect, TextDirection textDirection) {
    return ;
}

Path _StadiumToCircleBorder::getOuterPath(Rect rect, TextDirection textDirection) {
    return ;
}

_StadiumToCircleBorder _StadiumToCircleBorder::copyWith(double circleness, BorderSide side) {
    return _StadiumToCircleBorder(side ?? this.side, circleness ?? this.circleness);
}

void _StadiumToCircleBorder::paint(Canvas canvas, Rect rect, TextDirection textDirection) {
    ;
}

bool _StadiumToCircleBorder::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is _StadiumToCircleBorder && other.side == side && other.circleness == circleness;
}

int _StadiumToCircleBorder::hashCode() {
    return Object.hash(side, circleness);
}

String _StadiumToCircleBorder::toString() {
    return "StadiumBorder($side, ${(circleness * 100).toStringAsFixed(1)}% of the way to being a CircleBorder)";
}

_StadiumToCircleBorder::_StadiumToCircleBorder(double circleness, Unknown) {
    {
        assert(side != nullptr);
        assert(circleness != nullptr);
    }
}

Rect _StadiumToCircleBorder::_adjustRect(Rect rect) {
    if (circleness == 0.0 || rect.width == rect.height) {
        return rect;
    }
    if (rect.width < rect.height) {
        double delta = circleness * (rect.height - rect.width) / 2.0;
        return Rect.fromLTRB(rect.left, rect.top + delta, rect.right, rect.bottom - delta);
    } else {
        double delta = circleness * (rect.width - rect.height) / 2.0;
        return Rect.fromLTRB(rect.left + delta, rect.top, rect.right - delta, rect.bottom);
    }
}

BorderRadius _StadiumToCircleBorder::_adjustBorderRadius(Rect rect) {
    return BorderRadius.circular(rect.shortestSide / 2.0);
}

EdgeInsetsGeometry _StadiumToRoundedRectangleBorder::dimensions() {
    return EdgeInsets.all(side.width);
}

ShapeBorder _StadiumToRoundedRectangleBorder::scale(double t) {
    return _StadiumToRoundedRectangleBorder(side.scale(t), borderRadius * t, t);
}

ShapeBorder _StadiumToRoundedRectangleBorder::lerpFrom(ShapeBorder a, double t) {
    assert(t != nullptr);
    if (a is StadiumBorder) {
        return _StadiumToRoundedRectangleBorder(BorderSide.lerp(a.side, side, t), borderRadius, rectness * t);
    }
    if (a is RoundedRectangleBorder) {
        return _StadiumToRoundedRectangleBorder(BorderSide.lerp(a.side, side, t), borderRadius, rectness + (1.0 - rectness) * (1.0 - t));
    }
    if (a is _StadiumToRoundedRectangleBorder) {
        return _StadiumToRoundedRectangleBorder(BorderSide.lerp(a.side, side, t), BorderRadius.lerp(a.borderRadius, borderRadius, t)!, ui.lerpDouble(a.rectness, rectness, t)!);
    }
    return super.lerpFrom(a, t);
}

ShapeBorder _StadiumToRoundedRectangleBorder::lerpTo(ShapeBorder b, double t) {
    assert(t != nullptr);
    if (b is StadiumBorder) {
        return _StadiumToRoundedRectangleBorder(BorderSide.lerp(side, b.side, t), borderRadius, rectness * (1.0 - t));
    }
    if (b is RoundedRectangleBorder) {
        return _StadiumToRoundedRectangleBorder(BorderSide.lerp(side, b.side, t), borderRadius, rectness + (1.0 - rectness) * t);
    }
    if (b is _StadiumToRoundedRectangleBorder) {
        return _StadiumToRoundedRectangleBorder(BorderSide.lerp(side, b.side, t), BorderRadius.lerp(borderRadius, b.borderRadius, t)!, ui.lerpDouble(rectness, b.rectness, t)!);
    }
    return super.lerpTo(b, t);
}

Path _StadiumToRoundedRectangleBorder::getInnerPath(Rect rect, TextDirection textDirection) {
    RRect borderRect = _adjustBorderRadius(rect).toRRect(rect);
    RRect adjustedRect;
    ;
    return ;
}

Path _StadiumToRoundedRectangleBorder::getOuterPath(Rect rect, TextDirection textDirection) {
    return ;
}

_StadiumToRoundedRectangleBorder _StadiumToRoundedRectangleBorder::copyWith(BorderRadius borderRadius, double rectness, BorderSide side) {
    return _StadiumToRoundedRectangleBorder(side ?? this.side, borderRadius ?? this.borderRadius, rectness ?? this.rectness);
}

void _StadiumToRoundedRectangleBorder::paint(Canvas canvas, Rect rect, TextDirection textDirection) {
    ;
}

bool _StadiumToRoundedRectangleBorder::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is _StadiumToRoundedRectangleBorder && other.side == side && other.borderRadius == borderRadius && other.rectness == rectness;
}

int _StadiumToRoundedRectangleBorder::hashCode() {
    return Object.hash(side, borderRadius, rectness);
}

String _StadiumToRoundedRectangleBorder::toString() {
    return "StadiumBorder($side, $borderRadius, ${(rectness * 100).toStringAsFixed(1)}% of the way to being a RoundedRectangleBorder)";
}

_StadiumToRoundedRectangleBorder::_StadiumToRoundedRectangleBorder(BorderRadius borderRadius, double rectness, Unknown) {
    {
        assert(side != nullptr);
        assert(borderRadius != nullptr);
        assert(rectness != nullptr);
    }
}

BorderRadius _StadiumToRoundedRectangleBorder::_adjustBorderRadius(Rect rect) {
    return BorderRadius.lerp(borderRadius, BorderRadius.all(Radius.circular(rect.shortestSide / 2.0)), 1.0 - rectness)!;
}
