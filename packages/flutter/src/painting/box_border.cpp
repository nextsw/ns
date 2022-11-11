#include "box_border.hpp"
BoxBorder BoxBorderCls::add(ShapeBorder other, bool reversed) {
    return nullptr;
}

BoxBorder BoxBorderCls::lerp(BoxBorder a, BoxBorder b, double t) {
    assert(t != nullptr);
    if ((is<Border>(a)) && (is<Border>(b))) {
        return BorderCls->lerp(a, b, t);
    }
    if ((is<BorderDirectional>(a)) && (is<BorderDirectional>(b))) {
        return BorderDirectionalCls->lerp(a, b, t);
    }
    if (is<Border>(b) && is<BorderDirectional>(a)) {
        BoxBorder c = b;
        b = a;
        a = c;
        t = 1.0 - t;
    }
    if (is<Border>(a) && is<BorderDirectional>(b)) {
        if (b->start == BorderSideCls::none && b->end == BorderSideCls::none) {
            return make<BorderCls>(BorderSideCls->lerp(a->top(), b->top(), t), BorderSideCls->lerp(a->right, BorderSideCls::none, t), BorderSideCls->lerp(a->bottom(), b->bottom(), t), BorderSideCls->lerp(a->left, BorderSideCls::none, t));
        }
        if (a->left == BorderSideCls::none && a->right == BorderSideCls::none) {
            return make<BorderDirectionalCls>(BorderSideCls->lerp(a->top(), b->top(), t), BorderSideCls->lerp(BorderSideCls::none, b->start, t), BorderSideCls->lerp(BorderSideCls::none, b->end, t), BorderSideCls->lerp(a->bottom(), b->bottom(), t));
        }
        if ( < 0.5) {
            return make<BorderCls>(BorderSideCls->lerp(a->top(), b->top(), t), BorderSideCls->lerp(a->right, BorderSideCls::none, t * 2.0), BorderSideCls->lerp(a->bottom(), b->bottom(), t), BorderSideCls->lerp(a->left, BorderSideCls::none, t * 2.0));
        }
        return make<BorderDirectionalCls>(BorderSideCls->lerp(a->top(), b->top(), t), BorderSideCls->lerp(BorderSideCls::none, b->start, (t - 0.5) * 2.0), BorderSideCls->lerp(BorderSideCls::none, b->end, (t - 0.5) * 2.0), BorderSideCls->lerp(a->bottom(), b->bottom(), t));
    }
    ;
}

Path BoxBorderCls::getInnerPath(Rect rect, TextDirection textDirection) {
    assert(textDirection != nullptr, __s("The textDirection argument to $runtimeType.getInnerPath must not be null."));
    auto _c1 = make<PathCls>();_c1.addRect(dimensions->resolve(textDirection)->deflateRect(rect));return _c1;
}

Path BoxBorderCls::getOuterPath(Rect rect, TextDirection textDirection) {
    assert(textDirection != nullptr, __s("The textDirection argument to $runtimeType.getOuterPath must not be null."));
    auto _c1 = make<PathCls>();_c1.addRect(rect);return _c1;
}

void BoxBorderCls::_paintUniformBorderWithRadius(BorderRadius borderRadius, Canvas canvas, Rect rect, BorderSide side) {
    assert(side->style != BorderStyleCls::none);
    auto _c1 = make<PaintCls>();_c1.color = side->color;Paint paint = _c1;
    double width = side->width;
    if (width == 0.0) {
            auto _c2 = paint;    _c2.style = auto _c3 = PaintingStyleCls::stroke;    _c3.strokeWidth = 0.0;    _c3;_c2;
        canvas->drawRRect(borderRadius->toRRect(rect), paint);
    } else {
        if (side->strokeAlign == StrokeAlignCls::inside) {
            RRect outer = borderRadius->toRRect(rect);
            RRect inner = outer->deflate(width);
            canvas->drawDRRect(outer, inner, paint);
        } else {
            Rect inner;
            Rect outer;
            if (side->strokeAlign == StrokeAlignCls::center) {
                inner = rect->deflate(width / 2);
                outer = rect->inflate(width / 2);
            } else {
                inner = rect;
                outer = rect->inflate(width);
            }
            canvas->drawDRRect(borderRadius->toRRect(outer), borderRadius->toRRect(inner), paint);
        }
    }
}

void BoxBorderCls::_paintUniformBorderWithCircle(Canvas canvas, Rect rect, BorderSide side) {
    assert(side->style != BorderStyleCls::none);
    double width = side->width;
    Paint paint = side->toPaint();
    double radius;
    ;
    canvas->drawCircle(rect->center(), radius, paint);
}

void BoxBorderCls::_paintUniformBorderWithRectangle(Canvas canvas, Rect rect, BorderSide side) {
    assert(side->style != BorderStyleCls::none);
    double width = side->width;
    Paint paint = side->toPaint();
    Rect rectToBeDrawn;
    ;
    canvas->drawRect(rectToBeDrawn, paint);
}

BorderCls::BorderCls(BorderSide bottom, BorderSide left, BorderSide right, BorderSide top) {
    {
        assert(top != nullptr);
        assert(right != nullptr);
        assert(bottom != nullptr);
        assert(left != nullptr);
    }
}

void BorderCls::fromBorderSide(BorderSide side)

void BorderCls::symmetric(BorderSide horizontal, BorderSide vertical)

void BorderCls::all(Color color, StrokeAlign strokeAlign, BorderStyle style, double width) {
    BorderSide side = make<BorderSideCls>(color, width, style, strokeAlign);
    return BorderCls->fromBorderSide(side);
}

Border BorderCls::merge(Border a, Border b) {
    assert(a != nullptr);
    assert(b != nullptr);
    assert(BorderSideCls->canMerge(a->top, b->top));
    assert(BorderSideCls->canMerge(a->right, b->right));
    assert(BorderSideCls->canMerge(a->bottom, b->bottom));
    assert(BorderSideCls->canMerge(a->left, b->left));
    return make<BorderCls>(BorderSideCls->merge(a->top, b->top), BorderSideCls->merge(a->right, b->right), BorderSideCls->merge(a->bottom, b->bottom), BorderSideCls->merge(a->left, b->left));
}

EdgeInsetsGeometry BorderCls::dimensions() {
    if (isUniform()) {
        ;
    }
    return EdgeInsetsCls->fromLTRB(left->width, top->width, right->width, bottom->width);
}

bool BorderCls::isUniform() {
    return _colorIsUniform() && _widthIsUniform() && _styleIsUniform() && _strokeAlignIsUniform();
}

Border BorderCls::add(ShapeBorder other, bool reversed) {
    if (is<Border>(other) && BorderSideCls->canMerge(top, other->top) && BorderSideCls->canMerge(right, other->right) && BorderSideCls->canMerge(bottom, other->bottom) && BorderSideCls->canMerge(left, other->left)) {
        return BorderCls->merge(this, other);
    }
    return nullptr;
}

Border BorderCls::scale(double t) {
    return make<BorderCls>(top->scale(t), right->scale(t), bottom->scale(t), left->scale(t));
}

ShapeBorder BorderCls::lerpFrom(ShapeBorder a, double t) {
    if (is<Border>(a)) {
        return BorderCls->lerp(as<BorderCls>(a), this, t);
    }
    return super->lerpFrom(a, t);
}

ShapeBorder BorderCls::lerpTo(ShapeBorder b, double t) {
    if (is<Border>(b)) {
        return BorderCls->lerp(this, as<BorderCls>(b), t);
    }
    return super->lerpTo(b, t);
}

Border BorderCls::lerp(Border a, Border b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b!->scale(t);
    }
    if (b == nullptr) {
        return a->scale(1.0 - t);
    }
    return make<BorderCls>(BorderSideCls->lerp(a->top, b->top, t), BorderSideCls->lerp(a->right, b->right, t), BorderSideCls->lerp(a->bottom, b->bottom, t), BorderSideCls->lerp(a->left, b->left, t));
}

void BorderCls::paint(BorderRadius borderRadius, Canvas canvas, Rect rect, BoxShape shape, TextDirection textDirection) {
    if (isUniform()) {
        ;
    }
    assert([=] () {
        if (borderRadius != nullptr) {
            ;
        }
        return true;
    }());
    assert([=] () {
        if (shape != BoxShapeCls::rectangle) {
            ;
        }
        return true;
    }());
    assert([=] () {
        if (!_strokeAlignIsUniform() || top->strokeAlign != StrokeAlignCls::inside) {
            ;
        }
        return true;
    }());
    paintBorder(canvas, recttop, right, bottom, left);
}

bool BorderCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<Border>(other) && other->top == top && other->right == right && other->bottom == bottom && other->left == left;
}

int BorderCls::hashCode() {
    return ObjectCls->hash(top, right, bottom, left);
}

String BorderCls::toString() {
    if (isUniform()) {
        return __s("${objectRuntimeType(this, 'Border')}.all($top)");
    }
    List<String> list1 = make<ListCls<>>();if (top != BorderSideCls::none) {    list1.add(ArrayItem);}if (right != BorderSideCls::none) {    list1.add(ArrayItem);}if (bottom != BorderSideCls::none) {    list1.add(ArrayItem);}if (left != BorderSideCls::none) {    list1.add(ArrayItem);}List<String> arguments = list1;
    return __s("${objectRuntimeType(this, 'Border')}(${arguments.join(", ")})");
}

bool BorderCls::_colorIsUniform() {
    Color topColor = top->color;
    return right->color == topColor && bottom->color == topColor && left->color == topColor;
}

bool BorderCls::_widthIsUniform() {
    double topWidth = top->width;
    return right->width == topWidth && bottom->width == topWidth && left->width == topWidth;
}

bool BorderCls::_styleIsUniform() {
    BorderStyle topStyle = top->style;
    return right->style == topStyle && bottom->style == topStyle && left->style == topStyle;
}

bool BorderCls::_strokeAlignIsUniform() {
    StrokeAlign topStrokeAlign = top->strokeAlign;
    return right->strokeAlign == topStrokeAlign && bottom->strokeAlign == topStrokeAlign && left->strokeAlign == topStrokeAlign;
}

BorderDirectionalCls::BorderDirectionalCls(BorderSide bottom, BorderSide end, BorderSide start, BorderSide top) {
    {
        assert(top != nullptr);
        assert(start != nullptr);
        assert(end != nullptr);
        assert(bottom != nullptr);
    }
}

BorderDirectional BorderDirectionalCls::merge(BorderDirectional a, BorderDirectional b) {
    assert(a != nullptr);
    assert(b != nullptr);
    assert(BorderSideCls->canMerge(a->top, b->top));
    assert(BorderSideCls->canMerge(a->start, b->start));
    assert(BorderSideCls->canMerge(a->end, b->end));
    assert(BorderSideCls->canMerge(a->bottom, b->bottom));
    return make<BorderDirectionalCls>(BorderSideCls->merge(a->top, b->top), BorderSideCls->merge(a->start, b->start), BorderSideCls->merge(a->end, b->end), BorderSideCls->merge(a->bottom, b->bottom));
}

EdgeInsetsGeometry BorderDirectionalCls::dimensions() {
    if (isUniform()) {
        ;
    }
    return EdgeInsetsDirectionalCls->fromSTEB(start->width, top->width, end->width, bottom->width);
}

bool BorderDirectionalCls::isUniform() {
    Color topColor = top->color;
    if (start->color != topColor || end->color != topColor || bottom->color != topColor) {
        return false;
    }
    double topWidth = top->width;
    if (start->width != topWidth || end->width != topWidth || bottom->width != topWidth) {
        return false;
    }
    BorderStyle topStyle = top->style;
    if (start->style != topStyle || end->style != topStyle || bottom->style != topStyle) {
        return false;
    }
    if (_strokeAlignIsUniform() == false) {
        return false;
    }
    return true;
}

BoxBorder BorderDirectionalCls::add(ShapeBorder other, bool reversed) {
    if (is<BorderDirectional>(other)) {
        BorderDirectional typedOther = as<BorderDirectionalCls>(other);
        if (BorderSideCls->canMerge(top, typedOther->top) && BorderSideCls->canMerge(start, typedOther->start) && BorderSideCls->canMerge(end, typedOther->end) && BorderSideCls->canMerge(bottom, typedOther->bottom)) {
            return BorderDirectionalCls->merge(this, typedOther);
        }
        return nullptr;
    }
    if (is<Border>(other)) {
        Border typedOther = as<BorderCls>(other);
        if (!BorderSideCls->canMerge(typedOther->top, top) || !BorderSideCls->canMerge(typedOther->bottom, bottom)) {
            return nullptr;
        }
        if (start != BorderSideCls::none || end != BorderSideCls::none) {
            if (typedOther->left != BorderSideCls::none || typedOther->right != BorderSideCls::none) {
                return nullptr;
            }
            assert(typedOther->left == BorderSideCls::none);
            assert(typedOther->right == BorderSideCls::none);
            return make<BorderDirectionalCls>(BorderSideCls->merge(typedOther->top, top), start, end, BorderSideCls->merge(typedOther->bottom, bottom));
        }
        assert(start == BorderSideCls::none);
        assert(end == BorderSideCls::none);
        return make<BorderCls>(BorderSideCls->merge(typedOther->top, top), typedOther->right, BorderSideCls->merge(typedOther->bottom, bottom), typedOther->left);
    }
    return nullptr;
}

BorderDirectional BorderDirectionalCls::scale(double t) {
    return make<BorderDirectionalCls>(top->scale(t), start->scale(t), end->scale(t), bottom->scale(t));
}

ShapeBorder BorderDirectionalCls::lerpFrom(ShapeBorder a, double t) {
    if (is<BorderDirectional>(a)) {
        return BorderDirectionalCls->lerp(as<BorderDirectionalCls>(a), this, t);
    }
    return super->lerpFrom(a, t);
}

ShapeBorder BorderDirectionalCls::lerpTo(ShapeBorder b, double t) {
    if (is<BorderDirectional>(b)) {
        return BorderDirectionalCls->lerp(this, as<BorderDirectionalCls>(b), t);
    }
    return super->lerpTo(b, t);
}

BorderDirectional BorderDirectionalCls::lerp(BorderDirectional a, BorderDirectional b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b!->scale(t);
    }
    if (b == nullptr) {
        return a->scale(1.0 - t);
    }
    return make<BorderDirectionalCls>(BorderSideCls->lerp(a->top, b->top, t), BorderSideCls->lerp(a->end, b->end, t), BorderSideCls->lerp(a->bottom, b->bottom, t), BorderSideCls->lerp(a->start, b->start, t));
}

void BorderDirectionalCls::paint(BorderRadius borderRadius, Canvas canvas, Rect rect, BoxShape shape, TextDirection textDirection) {
    if (isUniform()) {
        ;
    }
    assert(borderRadius == nullptr, __s("A borderRadius can only be given for uniform borders."));
    assert(shape == BoxShapeCls::rectangle, __s("A border can only be drawn as a circle if it is uniform."));
    assert(_strokeAlignIsUniform() && top->strokeAlign == StrokeAlignCls::inside, __s("A Border can only draw strokeAlign different than StrokeAlign.inside on uniform borders."));
    BorderSide left, right;
    assert(textDirection != nullptr, __s("Non-uniform BorderDirectional objects require a TextDirection when painting."));
    ;
    paintBorder(canvas, recttop, left, bottom, right);
}

bool BorderDirectionalCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<BorderDirectional>(other) && other->top == top && other->start == start && other->end == end && other->bottom == bottom;
}

int BorderDirectionalCls::hashCode() {
    return ObjectCls->hash(top, start, end, bottom);
}

String BorderDirectionalCls::toString() {
    List<String> list1 = make<ListCls<>>();if (top != BorderSideCls::none) {    list1.add(ArrayItem);}if (start != BorderSideCls::none) {    list1.add(ArrayItem);}if (end != BorderSideCls::none) {    list1.add(ArrayItem);}if (bottom != BorderSideCls::none) {    list1.add(ArrayItem);}List<String> arguments = list1;
    return __s("${objectRuntimeType(this, 'BorderDirectional')}(${arguments.join(", ")})");
}

bool BorderDirectionalCls::_strokeAlignIsUniform() {
    StrokeAlign topStrokeAlign = top->strokeAlign;
    return start->strokeAlign == topStrokeAlign && bottom->strokeAlign == topStrokeAlign && end->strokeAlign == topStrokeAlign;
}
