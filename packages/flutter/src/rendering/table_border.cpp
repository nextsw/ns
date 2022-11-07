#include "table_border.hpp"
void TableBorder::all(BorderRadius borderRadius, Color color, BorderStyle style, double width) {
    BorderSide side = BorderSide(color, width, style);
    return TableBorder(side, side, side, side, side, side, borderRadius);
}

void TableBorder::symmetric(BorderSide inside, BorderSide outside) {
    return TableBorder(outside, outside, outside, outside, inside, inside);
}

EdgeInsets TableBorder::dimensions() {
    return EdgeInsets.fromLTRB(left.width, top.width, right.width, bottom.width);
}

bool TableBorder::isUniform() {
    assert(top != nullptr);
    assert(right != nullptr);
    assert(bottom != nullptr);
    assert(left != nullptr);
    assert(horizontalInside != nullptr);
    assert(verticalInside != nullptr);
    Color topColor = top.color;
    if (right.color != topColor || bottom.color != topColor || left.color != topColor || horizontalInside.color != topColor || verticalInside.color != topColor) {
        return false;
    }
    double topWidth = top.width;
    if (right.width != topWidth || bottom.width != topWidth || left.width != topWidth || horizontalInside.width != topWidth || verticalInside.width != topWidth) {
        return false;
    }
    BorderStyle topStyle = top.style;
    if (right.style != topStyle || bottom.style != topStyle || left.style != topStyle || horizontalInside.style != topStyle || verticalInside.style != topStyle) {
        return false;
    }
    return true;
}

TableBorder TableBorder::scale(double t) {
    return TableBorder(top.scale(t), right.scale(t), bottom.scale(t), left.scale(t), horizontalInside.scale(t), verticalInside.scale(t));
}

TableBorder TableBorder::lerp(TableBorder a, TableBorder b, double t) {
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
    return TableBorder(BorderSide.lerp(a.top, b.top, t), BorderSide.lerp(a.right, b.right, t), BorderSide.lerp(a.bottom, b.bottom, t), BorderSide.lerp(a.left, b.left, t), BorderSide.lerp(a.horizontalInside, b.horizontalInside, t), BorderSide.lerp(a.verticalInside, b.verticalInside, t));
}

void TableBorder::paint(Canvas canvas, Iterable<double> columns, Rect rect, Iterable<double> rows) {
    assert(top != nullptr);
    assert(right != nullptr);
    assert(bottom != nullptr);
    assert(left != nullptr);
    assert(horizontalInside != nullptr);
    assert(verticalInside != nullptr);
    assert(canvas != nullptr);
    assert(rect != nullptr);
    assert(rows != nullptr);
    assert(rows.isEmpty || (rows.first >= 0.0 && rows.last <= rect.height));
    assert(columns != nullptr);
    assert(columns.isEmpty || (columns.first >= 0.0 && columns.last <= rect.width));
    if (columns.isNotEmpty || rows.isNotEmpty) {
        Paint paint = Paint();
        Path path = Path();
        if (columns.isNotEmpty) {
            ;
        }
        if (rows.isNotEmpty) {
            ;
        }
    }
    if (!isUniform || borderRadius == BorderRadius.zero) {
        paintBorder(canvas, recttop, right, bottom, left);
    } else {
        RRect outer = borderRadius.toRRect(rect);
        RRect inner = outer.deflate(top.width);
        Paint paint = ;
        canvas.drawDRRect(outer, inner, paint);
    }
}

bool TableBorder::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is TableBorder && other.top == top && other.right == right && other.bottom == bottom && other.left == left && other.horizontalInside == horizontalInside && other.verticalInside == verticalInside && other.borderRadius == borderRadius;
}

int TableBorder::hashCode() {
    return Object.hash(top, right, bottom, left, horizontalInside, verticalInside, borderRadius);
}

String TableBorder::toString() {
    return "TableBorder($top, $right, $bottom, $left, $horizontalInside, $verticalInside, $borderRadius)";
}
