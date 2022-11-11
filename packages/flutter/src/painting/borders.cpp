#include "borders.hpp"
BorderSideCls::BorderSideCls(Color color, StrokeAlign strokeAlign, BorderStyle style, double width) {
    {
        assert(color != nullptr);
        assert(width != nullptr);
        assert(width >= 0.0);
        assert(style != nullptr);
    }
}

BorderSide BorderSideCls::merge(BorderSide a, BorderSide b) {
    assert(a != nullptr);
    assert(b != nullptr);
    assert(canMerge(a, b));
    bool aIsNone = a->style == BorderStyleCls::none && a->width == 0.0;
    bool bIsNone = b->style == BorderStyleCls::none && b->width == 0.0;
    if (aIsNone && bIsNone) {
        return BorderSideCls::none;
    }
    if (aIsNone) {
        return b;
    }
    if (bIsNone) {
        return a;
    }
    assert(a->color == b->color);
    assert(a->style == b->style);
    return make<BorderSideCls>(a->color, a->width + b->width, a->style);
}

BorderSide BorderSideCls::copyWith(Color color, BorderStyle style, double width) {
    assert(width == nullptr || width >= 0.0);
    return make<BorderSideCls>(color | this->color, width | this->width, style | this->style);
}

BorderSide BorderSideCls::scale(double t) {
    assert(t != nullptr);
    return make<BorderSideCls>(color, math->max(0.0, width * t), t <= 0.0? BorderStyleCls::none : style);
}

Paint BorderSideCls::toPaint() {
    ;
}

bool BorderSideCls::canMerge(BorderSide a, BorderSide b) {
    assert(a != nullptr);
    assert(b != nullptr);
    if ((a->style == BorderStyleCls::none && a->width == 0.0) || (b->style == BorderStyleCls::none && b->width == 0.0)) {
        return true;
    }
    return a->style == b->style && a->color == b->color && a->strokeAlign == b->strokeAlign;
}

BorderSide BorderSideCls::lerp(BorderSide a, BorderSide b, double t) {
    assert(a != nullptr);
    assert(b != nullptr);
    assert(t != nullptr);
    if (t == 0.0) {
        return a;
    }
    if (t == 1.0) {
        return b;
    }
    double width = ui->lerpDouble(a->width, b->width, t)!;
    if ( < 0.0) {
        return BorderSideCls::none;
    }
    if (a->style == b->style && a->strokeAlign == b->strokeAlign) {
        return make<BorderSideCls>(ColorCls->lerp(a->color, b->color, t)!, width, a->style, a->strokeAlign);
    }
    Color colorA, colorB;
    ;
    ;
    if (a->strokeAlign != b->strokeAlign) {
        StrokeAlign strokeAlign = t > 0.5? b->strokeAlign : a->strokeAlign;
        return make<BorderSideCls>(ColorCls->lerp(colorA, colorB, t)!, t > 0.5? ui->lerpDouble(0, b->width, t * 2 - 1)! : ui->lerpDouble(a->width, 0, t * 2)!, strokeAlign);
    }
    return make<BorderSideCls>(ColorCls->lerp(colorA, colorB, t)!, width, a->strokeAlign);
}

bool BorderSideCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<BorderSide>(other) && other->color == color && other->width == width && other->style == style && other->strokeAlign == strokeAlign;
}

int BorderSideCls::hashCode() {
    return ObjectCls->hash(color, width, style, strokeAlign);
}

String BorderSideCls::toString() {
    if (strokeAlign == StrokeAlignCls::inside) {
        return __s("${objectRuntimeType(this, 'BorderSide')}($color, ${width.toStringAsFixed(1)}, $style)");
    }
    return __s("${objectRuntimeType(this, 'BorderSide')}($color, ${width.toStringAsFixed(1)}, $style, $strokeAlign)");
}

ShapeBorder ShapeBorderCls::add(ShapeBorder other, bool reversed) {
    return nullptr;
}

ShapeBorder ShapeBorderCls::+(ShapeBorder other) {
    return add(other) | other->add(thistrue) | make<_CompoundBorderCls>(makeList(ArrayItem, ArrayItem));
}

ShapeBorder ShapeBorderCls::lerpFrom(ShapeBorder a, double t) {
    if (a == nullptr) {
        return scale(t);
    }
    return nullptr;
}

ShapeBorder ShapeBorderCls::lerpTo(ShapeBorder b, double t) {
    if (b == nullptr) {
        return scale(1.0 - t);
    }
    return nullptr;
}

ShapeBorder ShapeBorderCls::lerp(ShapeBorder a, ShapeBorder b, double t) {
    assert(t != nullptr);
    ShapeBorder result;
    if (b != nullptr) {
        result = b->lerpFrom(a, t);
    }
    if (result == nullptr && a != nullptr) {
        result = a->lerpTo(b, t);
    }
    return result | ( < 0.5? a : b);
}

String ShapeBorderCls::toString() {
    return __s("${objectRuntimeType(this, 'ShapeBorder')}()");
}

OutlinedBorderCls::OutlinedBorderCls(BorderSide side) {
    {
        assert(side != nullptr);
    }
}

ShapeBorder OutlinedBorderCls::lerpFrom(ShapeBorder a, double t) {
    if (a == nullptr) {
        return scale(t);
    }
    return nullptr;
}

ShapeBorder OutlinedBorderCls::lerpTo(ShapeBorder b, double t) {
    if (b == nullptr) {
        return scale(1.0 - t);
    }
    return nullptr;
}

OutlinedBorder OutlinedBorderCls::lerp(OutlinedBorder a, OutlinedBorder b, double t) {
    assert(t != nullptr);
    ShapeBorder result;
    if (b != nullptr) {
        result = b->lerpFrom(a, t);
    }
    if (result == nullptr && a != nullptr) {
        result = a->lerpTo(b, t);
    }
    return as<OutlinedBorder>(result) | ( < 0.5? a : b);
}

EdgeInsetsGeometry _CompoundBorderCls::dimensions() {
    return borders-><EdgeInsetsGeometry>fold(EdgeInsetsCls::zero, [=] (EdgeInsetsGeometry previousValue,ShapeBorder border) {
        return previousValue->add(border->dimensions);
    });
}

ShapeBorder _CompoundBorderCls::add(ShapeBorder other, bool reversed) {
    if (!is<_CompoundBorder>(other)) {
        ShapeBorder ours = reversed? borders->last : borders->first;
        ShapeBorder merged = ours->add(as<_CompoundBorderCls>(other)reversed) | as<_CompoundBorderCls>(other)->add(ours!reversed);
        if (merged != nullptr) {
                    List<ShapeBorder> list1 = make<ListCls<>>();        for (auto _x1 : borders) {        {            list1.add(_x1);        }List<ShapeBorder> result = list1;
            result[reversed? result->length() - 1 : 0] = merged;
            return make<_CompoundBorderCls>(result);
        }
    }
    List<ShapeBorder> list2 = make<ListCls<>>();if (reversed) {    list2.add(ArrayItem);}if (is<_CompoundBorder>(other)) {    list2.add(ArrayItem);} else {    list2.add(ArrayItem);}if (!reversed) {    list2.add(ArrayItem);}List<ShapeBorder> mergedBorders = list2;
    return make<_CompoundBorderCls>(mergedBorders);
}

ShapeBorder _CompoundBorderCls::scale(double t) {
    return make<_CompoundBorderCls>(borders-><ShapeBorder>map([=] (ShapeBorder border)     {
        border->scale(t);
    })->toList());
}

ShapeBorder _CompoundBorderCls::lerpFrom(ShapeBorder a, double t) {
    return _CompoundBorderCls->lerp(a, this, t);
}

ShapeBorder _CompoundBorderCls::lerpTo(ShapeBorder b, double t) {
    return _CompoundBorderCls->lerp(this, b, t);
}

_CompoundBorder _CompoundBorderCls::lerp(ShapeBorder a, ShapeBorder b, double t) {
    assert(t != nullptr);
    assert(is<_CompoundBorder>(a) || is<_CompoundBorder>(b));
    List<ShapeBorder> aList = is<_CompoundBorder>(a)? a->borders : makeList(ArrayItem);
    List<ShapeBorder> bList = is<_CompoundBorder>(b)? b->borders : makeList(ArrayItem);
    List<ShapeBorder> results = makeList();
    int length = math->max(aList->length(), bList->length());
    for (;  < length; index += 1) {
        ShapeBorder localA =  < aList->length? aList[index] : nullptr;
        ShapeBorder localB =  < bList->length? bList[index] : nullptr;
        if (localA != nullptr && localB != nullptr) {
            ShapeBorder localResult = localA->lerpTo(localB, t) | localB->lerpFrom(localA, t);
            if (localResult != nullptr) {
                results->add(localResult);
                continue;
            }
        }
        if (localB != nullptr) {
            results->add(localB->scale(t));
        }
        if (localA != nullptr) {
            results->add(localA->scale(1.0 - t));
        }
    }
    return make<_CompoundBorderCls>(results);
}

Path _CompoundBorderCls::getInnerPath(Rect rect, TextDirection textDirection) {
    for (;  < borders->length() - 1; index += 1) {
        rect = borders[index]->dimensions()->resolve(textDirection)->deflateRect(rect);
    }
    return borders->last->getInnerPath(recttextDirection);
}

Path _CompoundBorderCls::getOuterPath(Rect rect, TextDirection textDirection) {
    return borders->first->getOuterPath(recttextDirection);
}

void _CompoundBorderCls::paint(Canvas canvas, Rect rect, TextDirection textDirection) {
    for (ShapeBorder border : borders) {
        border->paint(canvas, recttextDirection);
        rect = border->dimensions->resolve(textDirection)->deflateRect(rect);
    }
}

bool _CompoundBorderCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<_CompoundBorder>(other) && <ShapeBorder>listEquals(other->borders, borders);
}

int _CompoundBorderCls::hashCode() {
    return ObjectCls->hashAll(borders);
}

String _CompoundBorderCls::toString() {
    return borders->reversed()-><String>map([=] (ShapeBorder border)     {
        border->toString();
    })->join(__s(" + "));
}

_CompoundBorderCls::_CompoundBorderCls(List<ShapeBorder> borders) {
    {
        assert(borders != nullptr);
        assert(borders->length() >= 2);
        assert(!borders->any([=] (ShapeBorder border)         {
            is<_CompoundBorder>(border);
        }));
    }
}

void paintBorder(Canvas canvas, Rect rect, BorderSide bottom, BorderSide left, BorderSide right, BorderSide top) {
    assert(canvas != nullptr);
    assert(rect != nullptr);
    assert(top != nullptr);
    assert(right != nullptr);
    assert(bottom != nullptr);
    assert(left != nullptr);
    auto _c1 = make<PaintCls>();_c1.strokeWidth = 0.0;Paint paint = _c1;
    Path path = make<PathCls>();
    ;
    ;
    ;
    ;
}
