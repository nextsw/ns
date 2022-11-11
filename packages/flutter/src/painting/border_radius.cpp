#include "border_radius.hpp"
BorderRadiusGeometry BorderRadiusGeometryCls::subtract(BorderRadiusGeometry other) {
    return make<_MixedBorderRadiusCls>(_topLeft() - other->_topLeft(), _topRight() - other->_topRight(), _bottomLeft() - other->_bottomLeft(), _bottomRight() - other->_bottomRight(), _topStart() - other->_topStart(), _topEnd() - other->_topEnd(), _bottomStart() - other->_bottomStart(), _bottomEnd() - other->_bottomEnd());
}

BorderRadiusGeometry BorderRadiusGeometryCls::add(BorderRadiusGeometry other) {
    return make<_MixedBorderRadiusCls>(_topLeft() + other->_topLeft(), _topRight() + other->_topRight(), _bottomLeft() + other->_bottomLeft(), _bottomRight() + other->_bottomRight(), _topStart() + other->_topStart(), _topEnd() + other->_topEnd(), _bottomStart() + other->_bottomStart(), _bottomEnd() + other->_bottomEnd());
}

BorderRadiusGeometry BorderRadiusGeometryCls::lerp(BorderRadiusGeometry a, BorderRadiusGeometry b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    a |= BorderRadiusCls::zero;
    b |= BorderRadiusCls::zero;
    return a->add((b->subtract(a)) * t);
}

String BorderRadiusGeometryCls::toString() {
    String visual, logical;
    if (_topLeft() == _topRight() && _topRight() == _bottomLeft() && _bottomLeft() == _bottomRight()) {
        if (_topLeft() != RadiusCls::zero) {
            if (_topLeft()->x == _topLeft()->y) {
                visual = __s("BorderRadius.circular(${_topLeft.x.toStringAsFixed(1)})");
            } else {
                visual = __s("BorderRadius.all($_topLeft)");
            }
        }
    } else {
        StringBuffer result = make<StringBufferCls>();
        result->write(__s("BorderRadius.only("));
        bool comma = false;
        if (_topLeft() != RadiusCls::zero) {
            result->write(__s("topLeft: $_topLeft"));
            comma = true;
        }
        if (_topRight() != RadiusCls::zero) {
            if (comma) {
                result->write(__s(", "));
            }
            result->write(__s("topRight: $_topRight"));
            comma = true;
        }
        if (_bottomLeft() != RadiusCls::zero) {
            if (comma) {
                result->write(__s(", "));
            }
            result->write(__s("bottomLeft: $_bottomLeft"));
            comma = true;
        }
        if (_bottomRight() != RadiusCls::zero) {
            if (comma) {
                result->write(__s(", "));
            }
            result->write(__s("bottomRight: $_bottomRight"));
        }
        result->write(__s(")"));
        visual = result->toString();
    }
    if (_topStart() == _topEnd() && _topEnd() == _bottomEnd() && _bottomEnd() == _bottomStart()) {
        if (_topStart() != RadiusCls::zero) {
            if (_topStart()->x == _topStart()->y) {
                logical = __s("BorderRadiusDirectional.circular(${_topStart.x.toStringAsFixed(1)})");
            } else {
                logical = __s("BorderRadiusDirectional.all($_topStart)");
            }
        }
    } else {
        StringBuffer result = make<StringBufferCls>();
        result->write(__s("BorderRadiusDirectional.only("));
        bool comma = false;
        if (_topStart() != RadiusCls::zero) {
            result->write(__s("topStart: $_topStart"));
            comma = true;
        }
        if (_topEnd() != RadiusCls::zero) {
            if (comma) {
                result->write(__s(", "));
            }
            result->write(__s("topEnd: $_topEnd"));
            comma = true;
        }
        if (_bottomStart() != RadiusCls::zero) {
            if (comma) {
                result->write(__s(", "));
            }
            result->write(__s("bottomStart: $_bottomStart"));
            comma = true;
        }
        if (_bottomEnd() != RadiusCls::zero) {
            if (comma) {
                result->write(__s(", "));
            }
            result->write(__s("bottomEnd: $_bottomEnd"));
        }
        result->write(__s(")"));
        logical = result->toString();
    }
    if (visual != nullptr && logical != nullptr) {
        return __s("$visual + $logical");
    }
    if (visual != nullptr) {
        return visual;
    }
    if (logical != nullptr) {
        return logical;
    }
    return __s("BorderRadius.zero");
}

bool BorderRadiusGeometryCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<BorderRadiusGeometry>(other) && other->_topLeft == _topLeft() && other->_topRight == _topRight() && other->_bottomLeft == _bottomLeft() && other->_bottomRight == _bottomRight() && other->_topStart == _topStart() && other->_topEnd == _topEnd() && other->_bottomStart == _bottomStart() && other->_bottomEnd == _bottomEnd();
}

int BorderRadiusGeometryCls::hashCode() {
    return ObjectCls->hash(_topLeft(), _topRight(), _bottomLeft(), _bottomRight(), _topStart(), _topEnd(), _bottomStart(), _bottomEnd());
}

void BorderRadiusCls::all(Radius radius)

void BorderRadiusCls::circular(double radius)

void BorderRadiusCls::vertical(Radius bottom, Radius top)

void BorderRadiusCls::horizontal(Radius left, Radius right)

BorderRadius BorderRadiusCls::copyWith(Radius bottomLeft, Radius bottomRight, Radius topLeft, Radius topRight) {
    return BorderRadiusCls->only(topLeft | this->topLeft, topRight | this->topRight, bottomLeft | this->bottomLeft, bottomRight | this->bottomRight);
}

RRect BorderRadiusCls::toRRect(Rect rect) {
    return RRectCls->fromRectAndCorners(rect, topLeft, topRight, bottomLeft, bottomRight);
}

BorderRadiusGeometry BorderRadiusCls::subtract(BorderRadiusGeometry other) {
    if (is<BorderRadius>(other)) {
        return this - as<BorderRadiusCls>(other);
    }
    return super->subtract(other);
}

BorderRadiusGeometry BorderRadiusCls::add(BorderRadiusGeometry other) {
    if (is<BorderRadius>(other)) {
        return this + as<BorderRadiusCls>(other);
    }
    return super->add(other);
}

BorderRadius BorderRadiusCls::-(BorderRadius other) {
    return BorderRadiusCls->only(topLeft - other->topLeft, topRight - other->topRight, bottomLeft - other->bottomLeft, bottomRight - other->bottomRight);
}

BorderRadius BorderRadiusCls::+(BorderRadius other) {
    return BorderRadiusCls->only(topLeft + other->topLeft, topRight + other->topRight, bottomLeft + other->bottomLeft, bottomRight + other->bottomRight);
}

BorderRadius BorderRadiusCls::-() {
    return BorderRadiusCls->only(-topLeft, -topRight, -bottomLeft, -bottomRight);
}

BorderRadius BorderRadiusCls::*(double other) {
    return BorderRadiusCls->only(topLeft * other, topRight * other, bottomLeft * other, bottomRight * other);
}

BorderRadius BorderRadiusCls::/(double other) {
    return BorderRadiusCls->only(topLeft / other, topRight / other, bottomLeft / other, bottomRight / other);
}

BorderRadius BorderRadiusCls::~/(double other) {
    return BorderRadiusCls->only(topLeft ~/ other, topRight ~/ other, bottomLeft ~/ other, bottomRight ~/ other);
}

BorderRadius BorderRadiusCls::%(double other) {
    return BorderRadiusCls->only(topLeft % other, topRight % other, bottomLeft % other, bottomRight % other);
}

BorderRadius BorderRadiusCls::lerp(BorderRadius a, BorderRadius b, double t) {
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
    return BorderRadiusCls->only(RadiusCls->lerp(a->topLeft, b->topLeft, t)!, RadiusCls->lerp(a->topRight, b->topRight, t)!, RadiusCls->lerp(a->bottomLeft, b->bottomLeft, t)!, RadiusCls->lerp(a->bottomRight, b->bottomRight, t)!);
}

BorderRadius BorderRadiusCls::resolve(TextDirection direction) {
    return this;
}

Radius BorderRadiusCls::_topLeft() {
    return topLeft;
}

Radius BorderRadiusCls::_topRight() {
    return topRight;
}

Radius BorderRadiusCls::_bottomLeft() {
    return bottomLeft;
}

Radius BorderRadiusCls::_bottomRight() {
    return bottomRight;
}

Radius BorderRadiusCls::_topStart() {
    return RadiusCls::zero;
}

Radius BorderRadiusCls::_topEnd() {
    return RadiusCls::zero;
}

Radius BorderRadiusCls::_bottomStart() {
    return RadiusCls::zero;
}

Radius BorderRadiusCls::_bottomEnd() {
    return RadiusCls::zero;
}

void BorderRadiusDirectionalCls::all(Radius radius)

void BorderRadiusDirectionalCls::circular(double radius)

void BorderRadiusDirectionalCls::vertical(Radius bottom, Radius top)

void BorderRadiusDirectionalCls::horizontal(Radius end, Radius start)

BorderRadiusGeometry BorderRadiusDirectionalCls::subtract(BorderRadiusGeometry other) {
    if (is<BorderRadiusDirectional>(other)) {
        return this - as<BorderRadiusDirectionalCls>(other);
    }
    return super->subtract(other);
}

BorderRadiusGeometry BorderRadiusDirectionalCls::add(BorderRadiusGeometry other) {
    if (is<BorderRadiusDirectional>(other)) {
        return this + as<BorderRadiusDirectionalCls>(other);
    }
    return super->add(other);
}

BorderRadiusDirectional BorderRadiusDirectionalCls::-(BorderRadiusDirectional other) {
    return BorderRadiusDirectionalCls->only(topStart - other->topStart, topEnd - other->topEnd, bottomStart - other->bottomStart, bottomEnd - other->bottomEnd);
}

BorderRadiusDirectional BorderRadiusDirectionalCls::+(BorderRadiusDirectional other) {
    return BorderRadiusDirectionalCls->only(topStart + other->topStart, topEnd + other->topEnd, bottomStart + other->bottomStart, bottomEnd + other->bottomEnd);
}

BorderRadiusDirectional BorderRadiusDirectionalCls::-() {
    return BorderRadiusDirectionalCls->only(-topStart, -topEnd, -bottomStart, -bottomEnd);
}

BorderRadiusDirectional BorderRadiusDirectionalCls::*(double other) {
    return BorderRadiusDirectionalCls->only(topStart * other, topEnd * other, bottomStart * other, bottomEnd * other);
}

BorderRadiusDirectional BorderRadiusDirectionalCls::/(double other) {
    return BorderRadiusDirectionalCls->only(topStart / other, topEnd / other, bottomStart / other, bottomEnd / other);
}

BorderRadiusDirectional BorderRadiusDirectionalCls::~/(double other) {
    return BorderRadiusDirectionalCls->only(topStart ~/ other, topEnd ~/ other, bottomStart ~/ other, bottomEnd ~/ other);
}

BorderRadiusDirectional BorderRadiusDirectionalCls::%(double other) {
    return BorderRadiusDirectionalCls->only(topStart % other, topEnd % other, bottomStart % other, bottomEnd % other);
}

BorderRadiusDirectional BorderRadiusDirectionalCls::lerp(BorderRadiusDirectional a, BorderRadiusDirectional b, double t) {
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
    return BorderRadiusDirectionalCls->only(RadiusCls->lerp(a->topStart, b->topStart, t)!, RadiusCls->lerp(a->topEnd, b->topEnd, t)!, RadiusCls->lerp(a->bottomStart, b->bottomStart, t)!, RadiusCls->lerp(a->bottomEnd, b->bottomEnd, t)!);
}

BorderRadius BorderRadiusDirectionalCls::resolve(TextDirection direction) {
    assert(direction != nullptr);
    ;
}

Radius BorderRadiusDirectionalCls::_topStart() {
    return topStart;
}

Radius BorderRadiusDirectionalCls::_topEnd() {
    return topEnd;
}

Radius BorderRadiusDirectionalCls::_bottomStart() {
    return bottomStart;
}

Radius BorderRadiusDirectionalCls::_bottomEnd() {
    return bottomEnd;
}

Radius BorderRadiusDirectionalCls::_topLeft() {
    return RadiusCls::zero;
}

Radius BorderRadiusDirectionalCls::_topRight() {
    return RadiusCls::zero;
}

Radius BorderRadiusDirectionalCls::_bottomLeft() {
    return RadiusCls::zero;
}

Radius BorderRadiusDirectionalCls::_bottomRight() {
    return RadiusCls::zero;
}

_MixedBorderRadius _MixedBorderRadiusCls::-() {
    return make<_MixedBorderRadiusCls>(-_topLeft, -_topRight, -_bottomLeft, -_bottomRight, -_topStart, -_topEnd, -_bottomStart, -_bottomEnd);
}

_MixedBorderRadius _MixedBorderRadiusCls::*(double other) {
    return make<_MixedBorderRadiusCls>(_topLeft * other, _topRight * other, _bottomLeft * other, _bottomRight * other, _topStart * other, _topEnd * other, _bottomStart * other, _bottomEnd * other);
}

_MixedBorderRadius _MixedBorderRadiusCls::/(double other) {
    return make<_MixedBorderRadiusCls>(_topLeft / other, _topRight / other, _bottomLeft / other, _bottomRight / other, _topStart / other, _topEnd / other, _bottomStart / other, _bottomEnd / other);
}

_MixedBorderRadius _MixedBorderRadiusCls::~/(double other) {
    return make<_MixedBorderRadiusCls>(_topLeft ~/ other, _topRight ~/ other, _bottomLeft ~/ other, _bottomRight ~/ other, _topStart ~/ other, _topEnd ~/ other, _bottomStart ~/ other, _bottomEnd ~/ other);
}

_MixedBorderRadius _MixedBorderRadiusCls::%(double other) {
    return make<_MixedBorderRadiusCls>(_topLeft % other, _topRight % other, _bottomLeft % other, _bottomRight % other, _topStart % other, _topEnd % other, _bottomStart % other, _bottomEnd % other);
}

BorderRadius _MixedBorderRadiusCls::resolve(TextDirection direction) {
    assert(direction != nullptr);
    ;
}
