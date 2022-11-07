#include "box_border.hpp"
BoxBorder BoxBorder::add(ShapeBorder other, bool reversed) {
    return nullptr;
}

BoxBorder BoxBorder::lerp(BoxBorder a, BoxBorder b, double t) {
    assert(t != nullptr);
    if ((a is Border) && (b is Border)) {
        return Border.lerp(a, b, t);
    }
    if ((a is BorderDirectional) && (b is BorderDirectional)) {
        return BorderDirectional.lerp(a, b, t);
    }
    if (b is Border && a is BorderDirectional) {
        BoxBorder c = b;
        b = a;
        a = c;
        t = 1.0 - t;
    }
    if (a is Border && b is BorderDirectional) {
        if (b.start == BorderSide.none && b.end == BorderSide.none) {
            return Border(BorderSide.lerp(a.top, b.top, t), BorderSide.lerp(a.right, BorderSide.none, t), BorderSide.lerp(a.bottom, b.bottom, t), BorderSide.lerp(a.left, BorderSide.none, t));
        }
        if (a.left == BorderSide.none && a.right == BorderSide.none) {
            return BorderDirectional(BorderSide.lerp(a.top, b.top, t), BorderSide.lerp(BorderSide.none, b.start, t), BorderSide.lerp(BorderSide.none, b.end, t), BorderSide.lerp(a.bottom, b.bottom, t));
        }
        if ( < 0.5) {
            return Border(BorderSide.lerp(a.top, b.top, t), BorderSide.lerp(a.right, BorderSide.none, t * 2.0), BorderSide.lerp(a.bottom, b.bottom, t), BorderSide.lerp(a.left, BorderSide.none, t * 2.0));
        }
        return BorderDirectional(BorderSide.lerp(a.top, b.top, t), BorderSide.lerp(BorderSide.none, b.start, (t - 0.5) * 2.0), BorderSide.lerp(BorderSide.none, b.end, (t - 0.5) * 2.0), BorderSide.lerp(a.bottom, b.bottom, t));
    }
    ;
}

Path BoxBorder::getInnerPath(Rect rect, TextDirection textDirection) {
    assert(textDirection != nullptr, "The textDirection argument to $runtimeType.getInnerPath must not be null.");
    return ;
}

Path BoxBorder::getOuterPath(Rect rect, TextDirection textDirection) {
    assert(textDirection != nullptr, "The textDirection argument to $runtimeType.getOuterPath must not be null.");
    return ;
}

void BoxBorder::_paintUniformBorderWithRadius(BorderRadius borderRadius, Canvas canvas, Rect rect, BorderSide side) {
    assert(side.style != BorderStyle.none);
    Paint paint = ;
    double width = side.width;
    if (width == 0.0) {
        ;
        canvas.drawRRect(borderRadius.toRRect(rect), paint);
    } else {
        if (side.strokeAlign == StrokeAlign.inside) {
            RRect outer = borderRadius.toRRect(rect);
            RRect inner = outer.deflate(width);
            canvas.drawDRRect(outer, inner, paint);
        } else {
            Rect inner;
            Rect outer;
            if (side.strokeAlign == StrokeAlign.center) {
                inner = rect.deflate(width / 2);
                outer = rect.inflate(width / 2);
            } else {
                inner = rect;
                outer = rect.inflate(width);
            }
            canvas.drawDRRect(borderRadius.toRRect(outer), borderRadius.toRRect(inner), paint);
        }
    }
}

void BoxBorder::_paintUniformBorderWithCircle(Canvas canvas, Rect rect, BorderSide side) {
    assert(side.style != BorderStyle.none);
    double width = side.width;
    Paint paint = side.toPaint();
    double radius;
    ;
    canvas.drawCircle(rect.center, radius, paint);
}

void BoxBorder::_paintUniformBorderWithRectangle(Canvas canvas, Rect rect, BorderSide side) {
    assert(side.style != BorderStyle.none);
    double width = side.width;
    Paint paint = side.toPaint();
    Rect rectToBeDrawn;
    ;
    canvas.drawRect(rectToBeDrawn, paint);
}

Border::Border(BorderSide bottom, BorderSide left, BorderSide right, BorderSide top) {
    {
        assert(top != nullptr);
        assert(right != nullptr);
        assert(bottom != nullptr);
        assert(left != nullptr);
    }
}

void Border::fromBorderSide(BorderSide side)

void Border::symmetric(BorderSide horizontal, BorderSide vertical)

void Border::all(Color color, StrokeAlign strokeAlign, BorderStyle style, double width) {
    BorderSide side = BorderSide(color, width, style, strokeAlign);
    return Border.fromBorderSide(side);
}

Border Border::merge(Border a, Border b) {
    assert(a != nullptr);
    assert(b != nullptr);
    assert(BorderSide.canMerge(a.top, b.top));
    assert(BorderSide.canMerge(a.right, b.right));
    assert(BorderSide.canMerge(a.bottom, b.bottom));
    assert(BorderSide.canMerge(a.left, b.left));
    return Border(BorderSide.merge(a.top, b.top), BorderSide.merge(a.right, b.right), BorderSide.merge(a.bottom, b.bottom), BorderSide.merge(a.left, b.left));
}

EdgeInsetsGeometry Border::dimensions() {
    if (isUniform) {
        ;
    }
    return EdgeInsets.fromLTRB(left.width, top.width, right.width, bottom.width);
}

bool Border::isUniform() {
    return _colorIsUniform && _widthIsUniform && _styleIsUniform && _strokeAlignIsUniform;
}

Border Border::add(ShapeBorder other, bool reversed) {
    if (other is Border && BorderSide.canMerge(top, other.top) && BorderSide.canMerge(right, other.right) && BorderSide.canMerge(bottom, other.bottom) && BorderSide.canMerge(left, other.left)) {
        return Border.merge(this, other);
    }
    return nullptr;
}

Border Border::scale(double t) {
    return Border(top.scale(t), right.scale(t), bottom.scale(t), left.scale(t));
}

ShapeBorder Border::lerpFrom(ShapeBorder a, double t) {
    if (a is Border) {
        return Border.lerp(a, this, t);
    }
    return super.lerpFrom(a, t);
}

ShapeBorder Border::lerpTo(ShapeBorder b, double t) {
    if (b is Border) {
        return Border.lerp(this, b, t);
    }
    return super.lerpTo(b, t);
}

Border Border::lerp(Border a, Border b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b!.scale(t);
    }
    if (b == nullptr) {
        return a.scale(1.0 - t);
    }
    return Border(BorderSide.lerp(a.top, b.top, t), BorderSide.lerp(a.right, b.right, t), BorderSide.lerp(a.bottom, b.bottom, t), BorderSide.lerp(a.left, b.left, t));
}

void Border::paint(BorderRadius borderRadius, Canvas canvas, Rect rect, BoxShape shape, TextDirection textDirection) {
    if (isUniform) {
        ;
    }
    assert(());
    assert(());
    assert(());
    paintBorder(canvas, recttop, right, bottom, left);
}

bool Border::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is Border && other.top == top && other.right == right && other.bottom == bottom && other.left == left;
}

int Border::hashCode() {
    return Object.hash(top, right, bottom, left);
}

String Border::toString() {
    if (isUniform) {
        return "${objectRuntimeType(this, 'Border')}.all($top)";
    }
    List<String> arguments = ;
    return "${objectRuntimeType(this, 'Border')}(${arguments.join(", ")})";
}

bool Border::_colorIsUniform() {
    Color topColor = top.color;
    return right.color == topColor && bottom.color == topColor && left.color == topColor;
}

bool Border::_widthIsUniform() {
    double topWidth = top.width;
    return right.width == topWidth && bottom.width == topWidth && left.width == topWidth;
}

bool Border::_styleIsUniform() {
    BorderStyle topStyle = top.style;
    return right.style == topStyle && bottom.style == topStyle && left.style == topStyle;
}

bool Border::_strokeAlignIsUniform() {
    StrokeAlign topStrokeAlign = top.strokeAlign;
    return right.strokeAlign == topStrokeAlign && bottom.strokeAlign == topStrokeAlign && left.strokeAlign == topStrokeAlign;
}

BorderDirectional::BorderDirectional(BorderSide bottom, BorderSide end, BorderSide start, BorderSide top) {
    {
        assert(top != nullptr);
        assert(start != nullptr);
        assert(end != nullptr);
        assert(bottom != nullptr);
    }
}

BorderDirectional BorderDirectional::merge(BorderDirectional a, BorderDirectional b) {
    assert(a != nullptr);
    assert(b != nullptr);
    assert(BorderSide.canMerge(a.top, b.top));
    assert(BorderSide.canMerge(a.start, b.start));
    assert(BorderSide.canMerge(a.end, b.end));
    assert(BorderSide.canMerge(a.bottom, b.bottom));
    return BorderDirectional(BorderSide.merge(a.top, b.top), BorderSide.merge(a.start, b.start), BorderSide.merge(a.end, b.end), BorderSide.merge(a.bottom, b.bottom));
}

EdgeInsetsGeometry BorderDirectional::dimensions() {
    if (isUniform) {
        ;
    }
    return EdgeInsetsDirectional.fromSTEB(start.width, top.width, end.width, bottom.width);
}

bool BorderDirectional::isUniform() {
    Color topColor = top.color;
    if (start.color != topColor || end.color != topColor || bottom.color != topColor) {
        return false;
    }
    double topWidth = top.width;
    if (start.width != topWidth || end.width != topWidth || bottom.width != topWidth) {
        return false;
    }
    BorderStyle topStyle = top.style;
    if (start.style != topStyle || end.style != topStyle || bottom.style != topStyle) {
        return false;
    }
    if (_strokeAlignIsUniform == false) {
        return false;
    }
    return true;
}

BoxBorder BorderDirectional::add(ShapeBorder other, bool reversed) {
    if (other is BorderDirectional) {
        BorderDirectional typedOther = other;
        if (BorderSide.canMerge(top, typedOther.top) && BorderSide.canMerge(start, typedOther.start) && BorderSide.canMerge(end, typedOther.end) && BorderSide.canMerge(bottom, typedOther.bottom)) {
            return BorderDirectional.merge(this, typedOther);
        }
        return nullptr;
    }
    if (other is Border) {
        Border typedOther = other;
        if (!BorderSide.canMerge(typedOther.top, top) || !BorderSide.canMerge(typedOther.bottom, bottom)) {
            return nullptr;
        }
        if (start != BorderSide.none || end != BorderSide.none) {
            if (typedOther.left != BorderSide.none || typedOther.right != BorderSide.none) {
                return nullptr;
            }
            assert(typedOther.left == BorderSide.none);
            assert(typedOther.right == BorderSide.none);
            return BorderDirectional(BorderSide.merge(typedOther.top, top), start, end, BorderSide.merge(typedOther.bottom, bottom));
        }
        assert(start == BorderSide.none);
        assert(end == BorderSide.none);
        return Border(BorderSide.merge(typedOther.top, top), typedOther.right, BorderSide.merge(typedOther.bottom, bottom), typedOther.left);
    }
    return nullptr;
}

BorderDirectional BorderDirectional::scale(double t) {
    return BorderDirectional(top.scale(t), start.scale(t), end.scale(t), bottom.scale(t));
}

ShapeBorder BorderDirectional::lerpFrom(ShapeBorder a, double t) {
    if (a is BorderDirectional) {
        return BorderDirectional.lerp(a, this, t);
    }
    return super.lerpFrom(a, t);
}

ShapeBorder BorderDirectional::lerpTo(ShapeBorder b, double t) {
    if (b is BorderDirectional) {
        return BorderDirectional.lerp(this, b, t);
    }
    return super.lerpTo(b, t);
}

BorderDirectional BorderDirectional::lerp(BorderDirectional a, BorderDirectional b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b!.scale(t);
    }
    if (b == nullptr) {
        return a.scale(1.0 - t);
    }
    return BorderDirectional(BorderSide.lerp(a.top, b.top, t), BorderSide.lerp(a.end, b.end, t), BorderSide.lerp(a.bottom, b.bottom, t), BorderSide.lerp(a.start, b.start, t));
}

void BorderDirectional::paint(BorderRadius borderRadius, Canvas canvas, Rect rect, BoxShape shape, TextDirection textDirection) {
    if (isUniform) {
        ;
    }
    assert(borderRadius == nullptr, "A borderRadius can only be given for uniform borders.");
    assert(shape == BoxShape.rectangle, "A border can only be drawn as a circle if it is uniform.");
    assert(_strokeAlignIsUniform && top.strokeAlign == StrokeAlign.inside, "A Border can only draw strokeAlign different than StrokeAlign.inside on uniform borders.");
    BorderSide left, right;
    assert(textDirection != nullptr, "Non-uniform BorderDirectional objects require a TextDirection when painting.");
    ;
    paintBorder(canvas, recttop, left, bottom, right);
}

bool BorderDirectional::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is BorderDirectional && other.top == top && other.start == start && other.end == end && other.bottom == bottom;
}

int BorderDirectional::hashCode() {
    return Object.hash(top, start, end, bottom);
}

String BorderDirectional::toString() {
    List<String> arguments = ;
    return "${objectRuntimeType(this, 'BorderDirectional')}(${arguments.join(", ")})";
}

bool BorderDirectional::_strokeAlignIsUniform() {
    StrokeAlign topStrokeAlign = top.strokeAlign;
    return start.strokeAlign == topStrokeAlign && bottom.strokeAlign == topStrokeAlign && end.strokeAlign == topStrokeAlign;
}
