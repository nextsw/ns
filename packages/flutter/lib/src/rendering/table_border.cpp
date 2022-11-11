#include "table_border.hpp"
void TableBorderCls::all(BorderRadius borderRadius, Color color, BorderStyle style, double width) {
    BorderSide side = make<BorderSideCls>(color, width, style);
    return make<TableBorderCls>(side, side, side, side, side, side, borderRadius);
}

void TableBorderCls::symmetric(BorderSide inside, BorderSide outside) {
    return make<TableBorderCls>(outside, outside, outside, outside, inside, inside);
}

EdgeInsets TableBorderCls::dimensions() {
    return EdgeInsetsCls->fromLTRB(left->width, top->width, right->width, bottom->width);
}

bool TableBorderCls::isUniform() {
    assert(top != nullptr);
    assert(right != nullptr);
    assert(bottom != nullptr);
    assert(left != nullptr);
    assert(horizontalInside != nullptr);
    assert(verticalInside != nullptr);
    Color topColor = top->color;
    if (right->color != topColor || bottom->color != topColor || left->color != topColor || horizontalInside->color != topColor || verticalInside->color != topColor) {
        return false;
    }
    double topWidth = top->width;
    if (right->width != topWidth || bottom->width != topWidth || left->width != topWidth || horizontalInside->width != topWidth || verticalInside->width != topWidth) {
        return false;
    }
    BorderStyle topStyle = top->style;
    if (right->style != topStyle || bottom->style != topStyle || left->style != topStyle || horizontalInside->style != topStyle || verticalInside->style != topStyle) {
        return false;
    }
    return true;
}

TableBorder TableBorderCls::scale(double t) {
    return make<TableBorderCls>(top->scale(t), right->scale(t), bottom->scale(t), left->scale(t), horizontalInside->scale(t), verticalInside->scale(t));
}

TableBorder TableBorderCls::lerp(TableBorder a, TableBorder b, double t) {
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
    return make<TableBorderCls>(BorderSideCls->lerp(a->top, b->top, t), BorderSideCls->lerp(a->right, b->right, t), BorderSideCls->lerp(a->bottom, b->bottom, t), BorderSideCls->lerp(a->left, b->left, t), BorderSideCls->lerp(a->horizontalInside, b->horizontalInside, t), BorderSideCls->lerp(a->verticalInside, b->verticalInside, t));
}

void TableBorderCls::paint(Canvas canvas, Iterable<double> columns, Rect rect, Iterable<double> rows) {
    assert(top != nullptr);
    assert(right != nullptr);
    assert(bottom != nullptr);
    assert(left != nullptr);
    assert(horizontalInside != nullptr);
    assert(verticalInside != nullptr);
    assert(canvas != nullptr);
    assert(rect != nullptr);
    assert(rows != nullptr);
    assert(rows->isEmpty() || (rows->first() >= 0.0 && rows->last() <= rect->height()));
    assert(columns != nullptr);
    assert(columns->isEmpty() || (columns->first() >= 0.0 && columns->last() <= rect->width()));
    if (columns->isNotEmpty() || rows->isNotEmpty()) {
        Paint paint = make<PaintCls>();
        Path path = make<PathCls>();
        if (columns->isNotEmpty()) {
            ;
        }
        if (rows->isNotEmpty()) {
            ;
        }
    }
    if (!isUniform() || borderRadius == BorderRadiusCls::zero) {
        paintBorder(canvas, recttop, right, bottom, left);
    } else {
        RRect outer = borderRadius->toRRect(rect);
        RRect inner = outer->deflate(top->width);
            auto _c1 = make<PaintCls>();    _c1.color = top->color;Paint paint = _c1;
        canvas->drawDRRect(outer, inner, paint);
    }
}

bool TableBorderCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<TableBorder>(other) && other->top == top && other->right == right && other->bottom == bottom && other->left == left && other->horizontalInside == horizontalInside && other->verticalInside == verticalInside && other->borderRadius == borderRadius;
}

int TableBorderCls::hashCode() {
    return ObjectCls->hash(top, right, bottom, left, horizontalInside, verticalInside, borderRadius);
}

String TableBorderCls::toString() {
    return __s("TableBorder($top, $right, $bottom, $left, $horizontalInside, $verticalInside, $borderRadius)");
}
