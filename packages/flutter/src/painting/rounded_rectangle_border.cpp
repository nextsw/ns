#include "rounded_rectangle_border.hpp"
RoundedRectangleBorder::RoundedRectangleBorder(BorderRadiusGeometry borderRadius, Unknown) {
    {
        assert(side != nullptr);
        assert(borderRadius != nullptr);
    }
}

EdgeInsetsGeometry RoundedRectangleBorder::dimensions() {
    ;
}

ShapeBorder RoundedRectangleBorder::scale(double t) {
    return RoundedRectangleBorder(side.scale(t), borderRadius * t);
}

ShapeBorder RoundedRectangleBorder::lerpFrom(ShapeBorder a, double t) {
    assert(t != nullptr);
    if (a is RoundedRectangleBorder) {
        return RoundedRectangleBorder(BorderSide.lerp(a.side, side, t), BorderRadiusGeometry.lerp(a.borderRadius, borderRadius, t)!);
    }
    if (a is CircleBorder) {
        return _RoundedRectangleToCircleBorder(BorderSide.lerp(a.side, side, t), borderRadius, 1.0 - t);
    }
    return super.lerpFrom(a, t);
}

ShapeBorder RoundedRectangleBorder::lerpTo(ShapeBorder b, double t) {
    assert(t != nullptr);
    if (b is RoundedRectangleBorder) {
        return RoundedRectangleBorder(BorderSide.lerp(side, b.side, t), BorderRadiusGeometry.lerp(borderRadius, b.borderRadius, t)!);
    }
    if (b is CircleBorder) {
        return _RoundedRectangleToCircleBorder(BorderSide.lerp(side, b.side, t), borderRadius, t);
    }
    return super.lerpTo(b, t);
}

RoundedRectangleBorder RoundedRectangleBorder::copyWith(BorderRadiusGeometry borderRadius, BorderSide side) {
    return RoundedRectangleBorder(side ?? this.side, borderRadius ?? this.borderRadius);
}

Path RoundedRectangleBorder::getInnerPath(Rect rect, TextDirection textDirection) {
    RRect borderRect = borderRadius.resolve(textDirection).toRRect(rect);
    RRect adjustedRect;
    ;
    return ;
}

Path RoundedRectangleBorder::getOuterPath(Rect rect, TextDirection textDirection) {
    return ;
}

void RoundedRectangleBorder::paint(Canvas canvas, Rect rect, TextDirection textDirection) {
    ;
}

bool RoundedRectangleBorder::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is RoundedRectangleBorder && other.side == side && other.borderRadius == borderRadius;
}

int RoundedRectangleBorder::hashCode() {
    return Object.hash(side, borderRadius);
}

String RoundedRectangleBorder::toString() {
    return "${objectRuntimeType(this, 'RoundedRectangleBorder')}($side, $borderRadius)";
}

EdgeInsetsGeometry _RoundedRectangleToCircleBorder::dimensions() {
    return EdgeInsets.all(side.width);
}

ShapeBorder _RoundedRectangleToCircleBorder::scale(double t) {
    return _RoundedRectangleToCircleBorder(side.scale(t), borderRadius * t, t);
}

ShapeBorder _RoundedRectangleToCircleBorder::lerpFrom(ShapeBorder a, double t) {
    assert(t != nullptr);
    if (a is RoundedRectangleBorder) {
        return _RoundedRectangleToCircleBorder(BorderSide.lerp(a.side, side, t), BorderRadiusGeometry.lerp(a.borderRadius, borderRadius, t)!, circleness * t);
    }
    if (a is CircleBorder) {
        return _RoundedRectangleToCircleBorder(BorderSide.lerp(a.side, side, t), borderRadius, circleness + (1.0 - circleness) * (1.0 - t));
    }
    if (a is _RoundedRectangleToCircleBorder) {
        return _RoundedRectangleToCircleBorder(BorderSide.lerp(a.side, side, t), BorderRadiusGeometry.lerp(a.borderRadius, borderRadius, t)!, ui.lerpDouble(a.circleness, circleness, t)!);
    }
    return super.lerpFrom(a, t);
}

ShapeBorder _RoundedRectangleToCircleBorder::lerpTo(ShapeBorder b, double t) {
    if (b is RoundedRectangleBorder) {
        return _RoundedRectangleToCircleBorder(BorderSide.lerp(side, b.side, t), BorderRadiusGeometry.lerp(borderRadius, b.borderRadius, t)!, circleness * (1.0 - t));
    }
    if (b is CircleBorder) {
        return _RoundedRectangleToCircleBorder(BorderSide.lerp(side, b.side, t), borderRadius, circleness + (1.0 - circleness) * t);
    }
    if (b is _RoundedRectangleToCircleBorder) {
        return _RoundedRectangleToCircleBorder(BorderSide.lerp(side, b.side, t), BorderRadiusGeometry.lerp(borderRadius, b.borderRadius, t)!, ui.lerpDouble(circleness, b.circleness, t)!);
    }
    return super.lerpTo(b, t);
}

Path _RoundedRectangleToCircleBorder::getInnerPath(Rect rect, TextDirection textDirection) {
    RRect borderRect = _adjustBorderRadius(rect, textDirection)!.toRRect(_adjustRect(rect));
    RRect adjustedRect;
    ;
    return ;
}

Path _RoundedRectangleToCircleBorder::getOuterPath(Rect rect, TextDirection textDirection) {
    return ;
}

_RoundedRectangleToCircleBorder _RoundedRectangleToCircleBorder::copyWith(BorderRadiusGeometry borderRadius, double circleness, BorderSide side) {
    return _RoundedRectangleToCircleBorder(side ?? this.side, borderRadius ?? this.borderRadius, circleness ?? this.circleness);
}

void _RoundedRectangleToCircleBorder::paint(Canvas canvas, Rect rect, TextDirection textDirection) {
    ;
}

bool _RoundedRectangleToCircleBorder::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is _RoundedRectangleToCircleBorder && other.side == side && other.borderRadius == borderRadius && other.circleness == circleness;
}

int _RoundedRectangleToCircleBorder::hashCode() {
    return Object.hash(side, borderRadius, circleness);
}

String _RoundedRectangleToCircleBorder::toString() {
    return "RoundedRectangleBorder($side, $borderRadius, ${(circleness * 100).toStringAsFixed(1)}% of the way to being a CircleBorder)";
}

_RoundedRectangleToCircleBorder::_RoundedRectangleToCircleBorder(BorderRadiusGeometry borderRadius, double circleness, Unknown) {
    {
        assert(side != nullptr);
        assert(borderRadius != nullptr);
        assert(circleness != nullptr);
    }
}

Rect _RoundedRectangleToCircleBorder::_adjustRect(Rect rect) {
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

BorderRadius _RoundedRectangleToCircleBorder::_adjustBorderRadius(Rect rect, TextDirection textDirection) {
    BorderRadius resolvedRadius = borderRadius.resolve(textDirection);
    if (circleness == 0.0) {
        return resolvedRadius;
    }
    return BorderRadius.lerp(resolvedRadius, BorderRadius.circular(rect.shortestSide / 2.0), circleness);
}
