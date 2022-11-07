#include "edge_insets.hpp"
bool EdgeInsetsGeometry::isNonNegative() {
    return _left >= 0.0 && _right >= 0.0 && _start >= 0.0 && _end >= 0.0 && _top >= 0.0 && _bottom >= 0.0;
}

double EdgeInsetsGeometry::horizontal() {
    return _left + _right + _start + _end;
}

double EdgeInsetsGeometry::vertical() {
    return _top + _bottom;
}

double EdgeInsetsGeometry::along(Axis axis) {
    assert(axis != nullptr);
    ;
}

Size EdgeInsetsGeometry::collapsedSize() {
    return Size(horizontal, vertical);
}

EdgeInsetsGeometry EdgeInsetsGeometry::flipped() {
    return _MixedEdgeInsets.fromLRSETB(_right, _left, _end, _start, _bottom, _top);
}

Size EdgeInsetsGeometry::inflateSize(Size size) {
    return Size(size.width + horizontal, size.height + vertical);
}

Size EdgeInsetsGeometry::deflateSize(Size size) {
    return Size(size.width - horizontal, size.height - vertical);
}

EdgeInsetsGeometry EdgeInsetsGeometry::subtract(EdgeInsetsGeometry other) {
    return _MixedEdgeInsets.fromLRSETB(_left - other._left, _right - other._right, _start - other._start, _end - other._end, _top - other._top, _bottom - other._bottom);
}

EdgeInsetsGeometry EdgeInsetsGeometry::add(EdgeInsetsGeometry other) {
    return _MixedEdgeInsets.fromLRSETB(_left + other._left, _right + other._right, _start + other._start, _end + other._end, _top + other._top, _bottom + other._bottom);
}

EdgeInsetsGeometry EdgeInsetsGeometry::clamp(EdgeInsetsGeometry max, EdgeInsetsGeometry min) {
    return _MixedEdgeInsets.fromLRSETB(clampDouble(_left, min._left, max._left), clampDouble(_right, min._right, max._right), clampDouble(_start, min._start, max._start), clampDouble(_end, min._end, max._end), clampDouble(_top, min._top, max._top), clampDouble(_bottom, min._bottom, max._bottom));
}

EdgeInsetsGeometry EdgeInsetsGeometry::lerp(EdgeInsetsGeometry a, EdgeInsetsGeometry b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b! * t;
    }
    if (b == nullptr) {
        return a * (1.0 - t);
    }
    if (a is EdgeInsets && b is EdgeInsets) {
        return EdgeInsets.lerp(a, b, t);
    }
    if (a is EdgeInsetsDirectional && b is EdgeInsetsDirectional) {
        return EdgeInsetsDirectional.lerp(a, b, t);
    }
    return _MixedEdgeInsets.fromLRSETB(ui.lerpDouble(a._left, b._left, t)!, ui.lerpDouble(a._right, b._right, t)!, ui.lerpDouble(a._start, b._start, t)!, ui.lerpDouble(a._end, b._end, t)!, ui.lerpDouble(a._top, b._top, t)!, ui.lerpDouble(a._bottom, b._bottom, t)!);
}

String EdgeInsetsGeometry::toString() {
    if (_start == 0.0 && _end == 0.0) {
        if (_left == 0.0 && _right == 0.0 && _top == 0.0 && _bottom == 0.0) {
            return "EdgeInsets.zero";
        }
        if (_left == _right && _right == _top && _top == _bottom) {
            return "EdgeInsets.all(${_left.toStringAsFixed(1)})";
        }
        return "EdgeInsets(${_left.toStringAsFixed(1)}, ${_top.toStringAsFixed(1)}, ${_right.toStringAsFixed(1)}, ${_bottom.toStringAsFixed(1)})";
    }
    if (_left == 0.0 && _right == 0.0) {
        return "EdgeInsetsDirectional(${_start.toStringAsFixed(1)}, ${_top.toStringAsFixed(1)}, ${_end.toStringAsFixed(1)}, ${_bottom.toStringAsFixed(1)})";
    }
    return "EdgeInsets(${_left.toStringAsFixed(1)}, ${_top.toStringAsFixed(1)}, ${_right.toStringAsFixed(1)}, ${_bottom.toStringAsFixed(1)}) + EdgeInsetsDirectional(${_start.toStringAsFixed(1)}, 0.0, ${_end.toStringAsFixed(1)}, 0.0)";
}

bool EdgeInsetsGeometry::==(Object other) {
    return other is EdgeInsetsGeometry && other._left == _left && other._right == _right && other._start == _start && other._end == _end && other._top == _top && other._bottom == _bottom;
}

int EdgeInsetsGeometry::hashCode() {
    return Object.hash(_left, _right, _start, _end, _top, _bottom);
}

void EdgeInsets::all(double value)

void EdgeInsets::symmetric(double horizontal, double vertical)

void EdgeInsets::fromWindowPadding(double devicePixelRatio, WindowPadding padding)

Offset EdgeInsets::topLeft() {
    return Offset(left, top);
}

Offset EdgeInsets::topRight() {
    return Offset(-right, top);
}

Offset EdgeInsets::bottomLeft() {
    return Offset(left, -bottom);
}

Offset EdgeInsets::bottomRight() {
    return Offset(-right, -bottom);
}

EdgeInsets EdgeInsets::flipped() {
    return EdgeInsets.fromLTRB(right, bottom, left, top);
}

Rect EdgeInsets::inflateRect(Rect rect) {
    return Rect.fromLTRB(rect.left - left, rect.top - top, rect.right + right, rect.bottom + bottom);
}

Rect EdgeInsets::deflateRect(Rect rect) {
    return Rect.fromLTRB(rect.left + left, rect.top + top, rect.right - right, rect.bottom - bottom);
}

EdgeInsetsGeometry EdgeInsets::subtract(EdgeInsetsGeometry other) {
    if (other is EdgeInsets) {
        return this - other;
    }
    return super.subtract(other);
}

EdgeInsetsGeometry EdgeInsets::add(EdgeInsetsGeometry other) {
    if (other is EdgeInsets) {
        return this + other;
    }
    return super.add(other);
}

EdgeInsetsGeometry EdgeInsets::clamp(EdgeInsetsGeometry max, EdgeInsetsGeometry min) {
    return EdgeInsets.fromLTRB(clampDouble(_left, min._left, max._left), clampDouble(_top, min._top, max._top), clampDouble(_right, min._right, max._right), clampDouble(_bottom, min._bottom, max._bottom));
}

EdgeInsets EdgeInsets::-(EdgeInsets other) {
    return EdgeInsets.fromLTRB(left - other.left, top - other.top, right - other.right, bottom - other.bottom);
}

EdgeInsets EdgeInsets::+(EdgeInsets other) {
    return EdgeInsets.fromLTRB(left + other.left, top + other.top, right + other.right, bottom + other.bottom);
}

EdgeInsets EdgeInsets::-() {
    return EdgeInsets.fromLTRB(-left, -top, -right, -bottom);
}

EdgeInsets EdgeInsets::*(double other) {
    return EdgeInsets.fromLTRB(left * other, top * other, right * other, bottom * other);
}

EdgeInsets EdgeInsets::/(double other) {
    return EdgeInsets.fromLTRB(left / other, top / other, right / other, bottom / other);
}

EdgeInsets EdgeInsets::~/(double other) {
    return EdgeInsets.fromLTRB((left ~/ other).toDouble(), (top ~/ other).toDouble(), (right ~/ other).toDouble(), (bottom ~/ other).toDouble());
}

EdgeInsets EdgeInsets::%(double other) {
    return EdgeInsets.fromLTRB(left % other, top % other, right % other, bottom % other);
}

EdgeInsets EdgeInsets::lerp(EdgeInsets a, EdgeInsets b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b! * t;
    }
    if (b == nullptr) {
        return a * (1.0 - t);
    }
    return EdgeInsets.fromLTRB(ui.lerpDouble(a.left, b.left, t)!, ui.lerpDouble(a.top, b.top, t)!, ui.lerpDouble(a.right, b.right, t)!, ui.lerpDouble(a.bottom, b.bottom, t)!);
}

EdgeInsets EdgeInsets::resolve(TextDirection direction) {
    return this;
}

EdgeInsets EdgeInsets::copyWith(double bottom, double left, double right, double top) {
    return EdgeInsets.only(left ?? this.left, top ?? this.top, right ?? this.right, bottom ?? this.bottom);
}

double EdgeInsets::_left() {
    return left;
}

double EdgeInsets::_top() {
    return top;
}

double EdgeInsets::_right() {
    return right;
}

double EdgeInsets::_bottom() {
    return bottom;
}

double EdgeInsets::_start() {
    return 0.0;
}

double EdgeInsets::_end() {
    return 0.0;
}

void EdgeInsetsDirectional::all(double value)

bool EdgeInsetsDirectional::isNonNegative() {
    return start >= 0.0 && top >= 0.0 && end >= 0.0 && bottom >= 0.0;
}

EdgeInsetsDirectional EdgeInsetsDirectional::flipped() {
    return EdgeInsetsDirectional.fromSTEB(end, bottom, start, top);
}

EdgeInsetsGeometry EdgeInsetsDirectional::subtract(EdgeInsetsGeometry other) {
    if (other is EdgeInsetsDirectional) {
        return this - other;
    }
    return super.subtract(other);
}

EdgeInsetsGeometry EdgeInsetsDirectional::add(EdgeInsetsGeometry other) {
    if (other is EdgeInsetsDirectional) {
        return this + other;
    }
    return super.add(other);
}

EdgeInsetsDirectional EdgeInsetsDirectional::-(EdgeInsetsDirectional other) {
    return EdgeInsetsDirectional.fromSTEB(start - other.start, top - other.top, end - other.end, bottom - other.bottom);
}

EdgeInsetsDirectional EdgeInsetsDirectional::+(EdgeInsetsDirectional other) {
    return EdgeInsetsDirectional.fromSTEB(start + other.start, top + other.top, end + other.end, bottom + other.bottom);
}

EdgeInsetsDirectional EdgeInsetsDirectional::-() {
    return EdgeInsetsDirectional.fromSTEB(-start, -top, -end, -bottom);
}

EdgeInsetsDirectional EdgeInsetsDirectional::*(double other) {
    return EdgeInsetsDirectional.fromSTEB(start * other, top * other, end * other, bottom * other);
}

EdgeInsetsDirectional EdgeInsetsDirectional::/(double other) {
    return EdgeInsetsDirectional.fromSTEB(start / other, top / other, end / other, bottom / other);
}

EdgeInsetsDirectional EdgeInsetsDirectional::~/(double other) {
    return EdgeInsetsDirectional.fromSTEB((start ~/ other).toDouble(), (top ~/ other).toDouble(), (end ~/ other).toDouble(), (bottom ~/ other).toDouble());
}

EdgeInsetsDirectional EdgeInsetsDirectional::%(double other) {
    return EdgeInsetsDirectional.fromSTEB(start % other, top % other, end % other, bottom % other);
}

EdgeInsetsDirectional EdgeInsetsDirectional::lerp(EdgeInsetsDirectional a, EdgeInsetsDirectional b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b! * t;
    }
    if (b == nullptr) {
        return a * (1.0 - t);
    }
    return EdgeInsetsDirectional.fromSTEB(ui.lerpDouble(a.start, b.start, t)!, ui.lerpDouble(a.top, b.top, t)!, ui.lerpDouble(a.end, b.end, t)!, ui.lerpDouble(a.bottom, b.bottom, t)!);
}

EdgeInsets EdgeInsetsDirectional::resolve(TextDirection direction) {
    assert(direction != nullptr);
    ;
}

double EdgeInsetsDirectional::_start() {
    return start;
}

double EdgeInsetsDirectional::_top() {
    return top;
}

double EdgeInsetsDirectional::_end() {
    return end;
}

double EdgeInsetsDirectional::_bottom() {
    return bottom;
}

double EdgeInsetsDirectional::_left() {
    return 0.0;
}

double EdgeInsetsDirectional::_right() {
    return 0.0;
}

bool _MixedEdgeInsets::isNonNegative() {
    return _left >= 0.0 && _right >= 0.0 && _start >= 0.0 && _end >= 0.0 && _top >= 0.0 && _bottom >= 0.0;
}

_MixedEdgeInsets _MixedEdgeInsets::-() {
    return _MixedEdgeInsets.fromLRSETB(-_left, -_right, -_start, -_end, -_top, -_bottom);
}

_MixedEdgeInsets _MixedEdgeInsets::*(double other) {
    return _MixedEdgeInsets.fromLRSETB(_left * other, _right * other, _start * other, _end * other, _top * other, _bottom * other);
}

_MixedEdgeInsets _MixedEdgeInsets::/(double other) {
    return _MixedEdgeInsets.fromLRSETB(_left / other, _right / other, _start / other, _end / other, _top / other, _bottom / other);
}

_MixedEdgeInsets _MixedEdgeInsets::~/(double other) {
    return _MixedEdgeInsets.fromLRSETB((_left ~/ other).toDouble(), (_right ~/ other).toDouble(), (_start ~/ other).toDouble(), (_end ~/ other).toDouble(), (_top ~/ other).toDouble(), (_bottom ~/ other).toDouble());
}

_MixedEdgeInsets _MixedEdgeInsets::%(double other) {
    return _MixedEdgeInsets.fromLRSETB(_left % other, _right % other, _start % other, _end % other, _top % other, _bottom % other);
}

EdgeInsets _MixedEdgeInsets::resolve(TextDirection direction) {
    assert(direction != nullptr);
    ;
}
