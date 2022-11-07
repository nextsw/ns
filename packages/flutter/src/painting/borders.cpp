#include "borders.hpp"
BorderSide::BorderSide(Color color, StrokeAlign strokeAlign, BorderStyle style, double width) {
    {
        assert(color != nullptr);
        assert(width != nullptr);
        assert(width >= 0.0);
        assert(style != nullptr);
    }
}

BorderSide BorderSide::merge(BorderSide a, BorderSide b) {
    assert(a != nullptr);
    assert(b != nullptr);
    assert(canMerge(a, b));
    bool aIsNone = a.style == BorderStyle.none && a.width == 0.0;
    bool bIsNone = b.style == BorderStyle.none && b.width == 0.0;
    if (aIsNone && bIsNone) {
        return BorderSide.none;
    }
    if (aIsNone) {
        return b;
    }
    if (bIsNone) {
        return a;
    }
    assert(a.color == b.color);
    assert(a.style == b.style);
    return BorderSide(a.color, a.width + b.width, a.style);
}

BorderSide BorderSide::copyWith(Color color, BorderStyle style, double width) {
    assert(width == nullptr || width >= 0.0);
    return BorderSide(color ?? this.color, width ?? this.width, style ?? this.style);
}

BorderSide BorderSide::scale(double t) {
    assert(t != nullptr);
    return BorderSide(color, math.max(0.0, width * t), t <= 0.0? BorderStyle.none : style);
}

Paint BorderSide::toPaint() {
    ;
}

bool BorderSide::canMerge(BorderSide a, BorderSide b) {
    assert(a != nullptr);
    assert(b != nullptr);
    if ((a.style == BorderStyle.none && a.width == 0.0) || (b.style == BorderStyle.none && b.width == 0.0)) {
        return true;
    }
    return a.style == b.style && a.color == b.color && a.strokeAlign == b.strokeAlign;
}

BorderSide BorderSide::lerp(BorderSide a, BorderSide b, double t) {
    assert(a != nullptr);
    assert(b != nullptr);
    assert(t != nullptr);
    if (t == 0.0) {
        return a;
    }
    if (t == 1.0) {
        return b;
    }
    double width = ui.lerpDouble(a.width, b.width, t)!;
    if ( < 0.0) {
        return BorderSide.none;
    }
    if (a.style == b.style && a.strokeAlign == b.strokeAlign) {
        return BorderSide(Color.lerp(a.color, b.color, t)!, width, a.style, a.strokeAlign);
    }
    Color colorA, colorB;
    ;
    ;
    if (a.strokeAlign != b.strokeAlign) {
        StrokeAlign strokeAlign = t > 0.5? b.strokeAlign : a.strokeAlign;
        return BorderSide(Color.lerp(colorA, colorB, t)!, t > 0.5? ui.lerpDouble(0, b.width, t * 2 - 1)! : ui.lerpDouble(a.width, 0, t * 2)!, strokeAlign);
    }
    return BorderSide(Color.lerp(colorA, colorB, t)!, width, a.strokeAlign);
}

bool BorderSide::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is BorderSide && other.color == color && other.width == width && other.style == style && other.strokeAlign == strokeAlign;
}

int BorderSide::hashCode() {
    return Object.hash(color, width, style, strokeAlign);
}

String BorderSide::toString() {
    if (strokeAlign == StrokeAlign.inside) {
        return "${objectRuntimeType(this, 'BorderSide')}($color, ${width.toStringAsFixed(1)}, $style)";
    }
    return "${objectRuntimeType(this, 'BorderSide')}($color, ${width.toStringAsFixed(1)}, $style, $strokeAlign)";
}

ShapeBorder ShapeBorder::add(ShapeBorder other, bool reversed) {
    return nullptr;
}

ShapeBorder ShapeBorder::+(ShapeBorder other) {
    return add(other) ?? other.add(thistrue) ?? _CompoundBorder();
}

ShapeBorder ShapeBorder::lerpFrom(ShapeBorder a, double t) {
    if (a == nullptr) {
        return scale(t);
    }
    return nullptr;
}

ShapeBorder ShapeBorder::lerpTo(ShapeBorder b, double t) {
    if (b == nullptr) {
        return scale(1.0 - t);
    }
    return nullptr;
}

ShapeBorder ShapeBorder::lerp(ShapeBorder a, ShapeBorder b, double t) {
    assert(t != nullptr);
    ShapeBorder result;
    if (b != nullptr) {
        result = b.lerpFrom(a, t);
    }
    if (result == nullptr && a != nullptr) {
        result = a.lerpTo(b, t);
    }
    return result ?? ( < 0.5? a : b);
}

String ShapeBorder::toString() {
    return "${objectRuntimeType(this, 'ShapeBorder')}()";
}

OutlinedBorder::OutlinedBorder(BorderSide side) {
    {
        assert(side != nullptr);
    }
}

ShapeBorder OutlinedBorder::lerpFrom(ShapeBorder a, double t) {
    if (a == nullptr) {
        return scale(t);
    }
    return nullptr;
}

ShapeBorder OutlinedBorder::lerpTo(ShapeBorder b, double t) {
    if (b == nullptr) {
        return scale(1.0 - t);
    }
    return nullptr;
}

OutlinedBorder OutlinedBorder::lerp(OutlinedBorder a, OutlinedBorder b, double t) {
    assert(t != nullptr);
    ShapeBorder result;
    if (b != nullptr) {
        result = b.lerpFrom(a, t);
    }
    if (result == nullptr && a != nullptr) {
        result = a.lerpTo(b, t);
    }
    return ( ?? ( < 0.5? a : b);
}

EdgeInsetsGeometry _CompoundBorder::dimensions() {
    return borders.<EdgeInsetsGeometry>fold(EdgeInsets.zero, );
}

ShapeBorder _CompoundBorder::add(ShapeBorder other, bool reversed) {
    if (other is! _CompoundBorder) {
        ShapeBorder ours = reversed? borders.last : borders.first;
        ShapeBorder merged = ours.add(otherreversed) ?? other.add(ours!reversed);
        if (merged != nullptr) {
            List<ShapeBorder> result = ;
            result[reversed? result.length - 1 : 0] = merged;
            return _CompoundBorder(result);
        }
    }
    List<ShapeBorder> mergedBorders = ;
    return _CompoundBorder(mergedBorders);
}

ShapeBorder _CompoundBorder::scale(double t) {
    return _CompoundBorder(borders.<ShapeBorder>map().toList());
}

ShapeBorder _CompoundBorder::lerpFrom(ShapeBorder a, double t) {
    return _CompoundBorder.lerp(a, this, t);
}

ShapeBorder _CompoundBorder::lerpTo(ShapeBorder b, double t) {
    return _CompoundBorder.lerp(this, b, t);
}

_CompoundBorder _CompoundBorder::lerp(ShapeBorder a, ShapeBorder b, double t) {
    assert(t != nullptr);
    assert(a is _CompoundBorder || b is _CompoundBorder);
    List<ShapeBorder> aList = a is _CompoundBorder? a.borders : ;
    List<ShapeBorder> bList = b is _CompoundBorder? b.borders : ;
    List<ShapeBorder> results = ;
    int length = math.max(aList.length, bList.length);
    for (;  < length; index = 1) {
        ShapeBorder localA =  < aList.length? aList[index] : nullptr;
        ShapeBorder localB =  < bList.length? bList[index] : nullptr;
        if (localA != nullptr && localB != nullptr) {
            ShapeBorder localResult = localA.lerpTo(localB, t) ?? localB.lerpFrom(localA, t);
            if (localResult != nullptr) {
                results.add(localResult);
                continue;
            }
        }
        if (localB != nullptr) {
            results.add(localB.scale(t));
        }
        if (localA != nullptr) {
            results.add(localA.scale(1.0 - t));
        }
    }
    return _CompoundBorder(results);
}

Path _CompoundBorder::getInnerPath(Rect rect, TextDirection textDirection) {
    for (;  < borders.length - 1; index = 1) {
        rect = borders[index].dimensions.resolve(textDirection).deflateRect(rect);
    }
    return borders.last.getInnerPath(recttextDirection);
}

Path _CompoundBorder::getOuterPath(Rect rect, TextDirection textDirection) {
    return borders.first.getOuterPath(recttextDirection);
}

void _CompoundBorder::paint(Canvas canvas, Rect rect, TextDirection textDirection) {
    for (ShapeBorder border : borders) {
        border.paint(canvas, recttextDirection);
        rect = border.dimensions.resolve(textDirection).deflateRect(rect);
    }
}

bool _CompoundBorder::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is _CompoundBorder && <ShapeBorder>listEquals(other.borders, borders);
}

int _CompoundBorder::hashCode() {
    return Object.hashAll(borders);
}

String _CompoundBorder::toString() {
    return borders.reversed.<String>map().join(" + ");
}

_CompoundBorder::_CompoundBorder(List<ShapeBorder> borders) {
    {
        assert(borders != nullptr);
        assert(borders.length >= 2);
        assert(!borders.any());
    }
}

void paintBorder(BorderSide bottom, Canvas canvas, BorderSide left, Rect rect, BorderSide right, BorderSide top) {
    assert(canvas != nullptr);
    assert(rect != nullptr);
    assert(top != nullptr);
    assert(right != nullptr);
    assert(bottom != nullptr);
    assert(left != nullptr);
    Paint paint = ;
    Path path = Path();
    ;
    ;
    ;
    ;
}
