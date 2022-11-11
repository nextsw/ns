#include "edge_insets.hpp"
bool EdgeInsetsGeometryCls::isNonNegative() {
    return _left() >= 0.0 && _right() >= 0.0 && _start() >= 0.0 && _end() >= 0.0 && _top() >= 0.0 && _bottom() >= 0.0;
}

double EdgeInsetsGeometryCls::horizontal() {
    return _left() + _right() + _start() + _end();
}

double EdgeInsetsGeometryCls::vertical() {
    return _top() + _bottom();
}

double EdgeInsetsGeometryCls::along(Axis axis) {
    assert(axis != nullptr);
    ;
}

Size EdgeInsetsGeometryCls::collapsedSize() {
    return make<SizeCls>(horizontal(), vertical());
}

EdgeInsetsGeometry EdgeInsetsGeometryCls::flipped() {
    return _MixedEdgeInsetsCls->fromLRSETB(_right(), _left(), _end(), _start(), _bottom(), _top());
}

Size EdgeInsetsGeometryCls::inflateSize(Size size) {
    return make<SizeCls>(size->width() + horizontal(), size->height() + vertical());
}

Size EdgeInsetsGeometryCls::deflateSize(Size size) {
    return make<SizeCls>(size->width() - horizontal(), size->height() - vertical());
}

EdgeInsetsGeometry EdgeInsetsGeometryCls::subtract(EdgeInsetsGeometry other) {
    return _MixedEdgeInsetsCls->fromLRSETB(_left() - other->_left(), _right() - other->_right(), _start() - other->_start(), _end() - other->_end(), _top() - other->_top(), _bottom() - other->_bottom());
}

EdgeInsetsGeometry EdgeInsetsGeometryCls::add(EdgeInsetsGeometry other) {
    return _MixedEdgeInsetsCls->fromLRSETB(_left() + other->_left(), _right() + other->_right(), _start() + other->_start(), _end() + other->_end(), _top() + other->_top(), _bottom() + other->_bottom());
}

EdgeInsetsGeometry EdgeInsetsGeometryCls::clamp(EdgeInsetsGeometry max, EdgeInsetsGeometry min) {
    return _MixedEdgeInsetsCls->fromLRSETB(clampDouble(_left(), min->_left(), max->_left()), clampDouble(_right(), min->_right(), max->_right()), clampDouble(_start(), min->_start(), max->_start()), clampDouble(_end(), min->_end(), max->_end()), clampDouble(_top(), min->_top(), max->_top()), clampDouble(_bottom(), min->_bottom(), max->_bottom()));
}

EdgeInsetsGeometry EdgeInsetsGeometryCls::lerp(EdgeInsetsGeometry a, EdgeInsetsGeometry b, double t) {
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
    if (is<EdgeInsets>(a) && is<EdgeInsets>(b)) {
        return EdgeInsetsCls->lerp(a, b, t);
    }
    if (is<EdgeInsetsDirectional>(a) && is<EdgeInsetsDirectional>(b)) {
        return EdgeInsetsDirectionalCls->lerp(a, b, t);
    }
    return _MixedEdgeInsetsCls->fromLRSETB(ui->lerpDouble(a->_left(), b->_left(), t)!, ui->lerpDouble(a->_right(), b->_right(), t)!, ui->lerpDouble(a->_start(), b->_start(), t)!, ui->lerpDouble(a->_end(), b->_end(), t)!, ui->lerpDouble(a->_top(), b->_top(), t)!, ui->lerpDouble(a->_bottom(), b->_bottom(), t)!);
}

String EdgeInsetsGeometryCls::toString() {
    if (_start() == 0.0 && _end() == 0.0) {
        if (_left() == 0.0 && _right() == 0.0 && _top() == 0.0 && _bottom() == 0.0) {
            return __s("EdgeInsets.zero");
        }
        if (_left() == _right() && _right() == _top() && _top() == _bottom()) {
            return __s("EdgeInsets.all(${_left.toStringAsFixed(1)})");
        }
        return __s("EdgeInsets(${_left.toStringAsFixed(1)}, ${_top.toStringAsFixed(1)}, ${_right.toStringAsFixed(1)}, ${_bottom.toStringAsFixed(1)})");
    }
    if (_left() == 0.0 && _right() == 0.0) {
        return __s("EdgeInsetsDirectional(${_start.toStringAsFixed(1)}, ${_top.toStringAsFixed(1)}, ${_end.toStringAsFixed(1)}, ${_bottom.toStringAsFixed(1)})");
    }
    return __s("EdgeInsets(${_left.toStringAsFixed(1)}, ${_top.toStringAsFixed(1)}, ${_right.toStringAsFixed(1)}, ${_bottom.toStringAsFixed(1)}) + EdgeInsetsDirectional(${_start.toStringAsFixed(1)}, 0.0, ${_end.toStringAsFixed(1)}, 0.0)");
}

bool EdgeInsetsGeometryCls::==(Object other) {
    return is<EdgeInsetsGeometry>(other) && other->_left == _left() && other->_right == _right() && other->_start == _start() && other->_end == _end() && other->_top == _top() && other->_bottom == _bottom();
}

int EdgeInsetsGeometryCls::hashCode() {
    return ObjectCls->hash(_left(), _right(), _start(), _end(), _top(), _bottom());
}

void EdgeInsetsCls::all(double value)

void EdgeInsetsCls::symmetric(double horizontal, double vertical)

void EdgeInsetsCls::fromWindowPadding(double devicePixelRatio, WindowPadding padding)

Offset EdgeInsetsCls::topLeft() {
    return make<OffsetCls>(left, top);
}

Offset EdgeInsetsCls::topRight() {
    return make<OffsetCls>(-right, top);
}

Offset EdgeInsetsCls::bottomLeft() {
    return make<OffsetCls>(left, -bottom);
}

Offset EdgeInsetsCls::bottomRight() {
    return make<OffsetCls>(-right, -bottom);
}

EdgeInsets EdgeInsetsCls::flipped() {
    return EdgeInsetsCls->fromLTRB(right, bottom, left, top);
}

Rect EdgeInsetsCls::inflateRect(Rect rect) {
    return RectCls->fromLTRB(rect->left - left, rect->top - top, rect->right + right, rect->bottom + bottom);
}

Rect EdgeInsetsCls::deflateRect(Rect rect) {
    return RectCls->fromLTRB(rect->left + left, rect->top + top, rect->right - right, rect->bottom - bottom);
}

EdgeInsetsGeometry EdgeInsetsCls::subtract(EdgeInsetsGeometry other) {
    if (is<EdgeInsets>(other)) {
        return this - as<EdgeInsetsCls>(other);
    }
    return super->subtract(other);
}

EdgeInsetsGeometry EdgeInsetsCls::add(EdgeInsetsGeometry other) {
    if (is<EdgeInsets>(other)) {
        return this + as<EdgeInsetsCls>(other);
    }
    return super->add(other);
}

EdgeInsetsGeometry EdgeInsetsCls::clamp(EdgeInsetsGeometry max, EdgeInsetsGeometry min) {
    return EdgeInsetsCls->fromLTRB(clampDouble(_left(), min->_left(), max->_left()), clampDouble(_top(), min->_top(), max->_top()), clampDouble(_right(), min->_right(), max->_right()), clampDouble(_bottom(), min->_bottom(), max->_bottom()));
}

EdgeInsets EdgeInsetsCls::-(EdgeInsets other) {
    return EdgeInsetsCls->fromLTRB(left - other->left, top - other->top, right - other->right, bottom - other->bottom);
}

EdgeInsets EdgeInsetsCls::+(EdgeInsets other) {
    return EdgeInsetsCls->fromLTRB(left + other->left, top + other->top, right + other->right, bottom + other->bottom);
}

EdgeInsets EdgeInsetsCls::-() {
    return EdgeInsetsCls->fromLTRB(-left, -top, -right, -bottom);
}

EdgeInsets EdgeInsetsCls::*(double other) {
    return EdgeInsetsCls->fromLTRB(left * other, top * other, right * other, bottom * other);
}

EdgeInsets EdgeInsetsCls::/(double other) {
    return EdgeInsetsCls->fromLTRB(left / other, top / other, right / other, bottom / other);
}

EdgeInsets EdgeInsetsCls::~/(double other) {
    return EdgeInsetsCls->fromLTRB((left ~/ other)->toDouble(), (top ~/ other)->toDouble(), (right ~/ other)->toDouble(), (bottom ~/ other)->toDouble());
}

EdgeInsets EdgeInsetsCls::%(double other) {
    return EdgeInsetsCls->fromLTRB(left % other, top % other, right % other, bottom % other);
}

EdgeInsets EdgeInsetsCls::lerp(EdgeInsets a, EdgeInsets b, double t) {
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
    return EdgeInsetsCls->fromLTRB(ui->lerpDouble(a->left, b->left, t)!, ui->lerpDouble(a->top, b->top, t)!, ui->lerpDouble(a->right, b->right, t)!, ui->lerpDouble(a->bottom, b->bottom, t)!);
}

EdgeInsets EdgeInsetsCls::resolve(TextDirection direction) {
    return this;
}

EdgeInsets EdgeInsetsCls::copyWith(double bottom, double left, double right, double top) {
    return EdgeInsetsCls->only(left or this->left, top or this->top, right or this->right, bottom or this->bottom);
}

double EdgeInsetsCls::_left() {
    return left;
}

double EdgeInsetsCls::_top() {
    return top;
}

double EdgeInsetsCls::_right() {
    return right;
}

double EdgeInsetsCls::_bottom() {
    return bottom;
}

double EdgeInsetsCls::_start() {
    return 0.0;
}

double EdgeInsetsCls::_end() {
    return 0.0;
}

void EdgeInsetsDirectionalCls::all(double value)

bool EdgeInsetsDirectionalCls::isNonNegative() {
    return start >= 0.0 && top >= 0.0 && end >= 0.0 && bottom >= 0.0;
}

EdgeInsetsDirectional EdgeInsetsDirectionalCls::flipped() {
    return EdgeInsetsDirectionalCls->fromSTEB(end, bottom, start, top);
}

EdgeInsetsGeometry EdgeInsetsDirectionalCls::subtract(EdgeInsetsGeometry other) {
    if (is<EdgeInsetsDirectional>(other)) {
        return this - as<EdgeInsetsDirectionalCls>(other);
    }
    return super->subtract(other);
}

EdgeInsetsGeometry EdgeInsetsDirectionalCls::add(EdgeInsetsGeometry other) {
    if (is<EdgeInsetsDirectional>(other)) {
        return this + as<EdgeInsetsDirectionalCls>(other);
    }
    return super->add(other);
}

EdgeInsetsDirectional EdgeInsetsDirectionalCls::-(EdgeInsetsDirectional other) {
    return EdgeInsetsDirectionalCls->fromSTEB(start - other->start, top - other->top, end - other->end, bottom - other->bottom);
}

EdgeInsetsDirectional EdgeInsetsDirectionalCls::+(EdgeInsetsDirectional other) {
    return EdgeInsetsDirectionalCls->fromSTEB(start + other->start, top + other->top, end + other->end, bottom + other->bottom);
}

EdgeInsetsDirectional EdgeInsetsDirectionalCls::-() {
    return EdgeInsetsDirectionalCls->fromSTEB(-start, -top, -end, -bottom);
}

EdgeInsetsDirectional EdgeInsetsDirectionalCls::*(double other) {
    return EdgeInsetsDirectionalCls->fromSTEB(start * other, top * other, end * other, bottom * other);
}

EdgeInsetsDirectional EdgeInsetsDirectionalCls::/(double other) {
    return EdgeInsetsDirectionalCls->fromSTEB(start / other, top / other, end / other, bottom / other);
}

EdgeInsetsDirectional EdgeInsetsDirectionalCls::~/(double other) {
    return EdgeInsetsDirectionalCls->fromSTEB((start ~/ other)->toDouble(), (top ~/ other)->toDouble(), (end ~/ other)->toDouble(), (bottom ~/ other)->toDouble());
}

EdgeInsetsDirectional EdgeInsetsDirectionalCls::%(double other) {
    return EdgeInsetsDirectionalCls->fromSTEB(start % other, top % other, end % other, bottom % other);
}

EdgeInsetsDirectional EdgeInsetsDirectionalCls::lerp(EdgeInsetsDirectional a, EdgeInsetsDirectional b, double t) {
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
    return EdgeInsetsDirectionalCls->fromSTEB(ui->lerpDouble(a->start, b->start, t)!, ui->lerpDouble(a->top, b->top, t)!, ui->lerpDouble(a->end, b->end, t)!, ui->lerpDouble(a->bottom, b->bottom, t)!);
}

EdgeInsets EdgeInsetsDirectionalCls::resolve(TextDirection direction) {
    assert(direction != nullptr);
    ;
}

double EdgeInsetsDirectionalCls::_start() {
    return start;
}

double EdgeInsetsDirectionalCls::_top() {
    return top;
}

double EdgeInsetsDirectionalCls::_end() {
    return end;
}

double EdgeInsetsDirectionalCls::_bottom() {
    return bottom;
}

double EdgeInsetsDirectionalCls::_left() {
    return 0.0;
}

double EdgeInsetsDirectionalCls::_right() {
    return 0.0;
}

bool _MixedEdgeInsetsCls::isNonNegative() {
    return _left >= 0.0 && _right >= 0.0 && _start >= 0.0 && _end >= 0.0 && _top >= 0.0 && _bottom >= 0.0;
}

_MixedEdgeInsets _MixedEdgeInsetsCls::-() {
    return _MixedEdgeInsetsCls->fromLRSETB(-_left, -_right, -_start, -_end, -_top, -_bottom);
}

_MixedEdgeInsets _MixedEdgeInsetsCls::*(double other) {
    return _MixedEdgeInsetsCls->fromLRSETB(_left * other, _right * other, _start * other, _end * other, _top * other, _bottom * other);
}

_MixedEdgeInsets _MixedEdgeInsetsCls::/(double other) {
    return _MixedEdgeInsetsCls->fromLRSETB(_left / other, _right / other, _start / other, _end / other, _top / other, _bottom / other);
}

_MixedEdgeInsets _MixedEdgeInsetsCls::~/(double other) {
    return _MixedEdgeInsetsCls->fromLRSETB((_left ~/ other)->toDouble(), (_right ~/ other)->toDouble(), (_start ~/ other)->toDouble(), (_end ~/ other)->toDouble(), (_top ~/ other)->toDouble(), (_bottom ~/ other)->toDouble());
}

_MixedEdgeInsets _MixedEdgeInsetsCls::%(double other) {
    return _MixedEdgeInsetsCls->fromLRSETB(_left % other, _right % other, _start % other, _end % other, _top % other, _bottom % other);
}

EdgeInsets _MixedEdgeInsetsCls::resolve(TextDirection direction) {
    assert(direction != nullptr);
    ;
}
