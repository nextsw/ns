#include "border_radius.hpp"
BorderRadiusGeometry BorderRadiusGeometry::subtract(BorderRadiusGeometry other) {
    return _MixedBorderRadius(_topLeft - other._topLeft, _topRight - other._topRight, _bottomLeft - other._bottomLeft, _bottomRight - other._bottomRight, _topStart - other._topStart, _topEnd - other._topEnd, _bottomStart - other._bottomStart, _bottomEnd - other._bottomEnd);
}

BorderRadiusGeometry BorderRadiusGeometry::add(BorderRadiusGeometry other) {
    return _MixedBorderRadius(_topLeft + other._topLeft, _topRight + other._topRight, _bottomLeft + other._bottomLeft, _bottomRight + other._bottomRight, _topStart + other._topStart, _topEnd + other._topEnd, _bottomStart + other._bottomStart, _bottomEnd + other._bottomEnd);
}

BorderRadiusGeometry BorderRadiusGeometry::lerp(BorderRadiusGeometry a, BorderRadiusGeometry b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    a = BorderRadius.zero;
    b = BorderRadius.zero;
    return a.add((b.subtract(a)) * t);
}

String BorderRadiusGeometry::toString() {
    String visual, logical;
    if (_topLeft == _topRight && _topRight == _bottomLeft && _bottomLeft == _bottomRight) {
        if (_topLeft != Radius.zero) {
            if (_topLeft.x == _topLeft.y) {
                visual = "BorderRadius.circular(${_topLeft.x.toStringAsFixed(1)})";
            } else {
                visual = "BorderRadius.all($_topLeft)";
            }
        }
    } else {
        StringBuffer result = StringBuffer();
        result.write("BorderRadius.only(");
        bool comma = false;
        if (_topLeft != Radius.zero) {
            result.write("topLeft: $_topLeft");
            comma = true;
        }
        if (_topRight != Radius.zero) {
            if (comma) {
                result.write(", ");
            }
            result.write("topRight: $_topRight");
            comma = true;
        }
        if (_bottomLeft != Radius.zero) {
            if (comma) {
                result.write(", ");
            }
            result.write("bottomLeft: $_bottomLeft");
            comma = true;
        }
        if (_bottomRight != Radius.zero) {
            if (comma) {
                result.write(", ");
            }
            result.write("bottomRight: $_bottomRight");
        }
        result.write(")");
        visual = result.toString();
    }
    if (_topStart == _topEnd && _topEnd == _bottomEnd && _bottomEnd == _bottomStart) {
        if (_topStart != Radius.zero) {
            if (_topStart.x == _topStart.y) {
                logical = "BorderRadiusDirectional.circular(${_topStart.x.toStringAsFixed(1)})";
            } else {
                logical = "BorderRadiusDirectional.all($_topStart)";
            }
        }
    } else {
        StringBuffer result = StringBuffer();
        result.write("BorderRadiusDirectional.only(");
        bool comma = false;
        if (_topStart != Radius.zero) {
            result.write("topStart: $_topStart");
            comma = true;
        }
        if (_topEnd != Radius.zero) {
            if (comma) {
                result.write(", ");
            }
            result.write("topEnd: $_topEnd");
            comma = true;
        }
        if (_bottomStart != Radius.zero) {
            if (comma) {
                result.write(", ");
            }
            result.write("bottomStart: $_bottomStart");
            comma = true;
        }
        if (_bottomEnd != Radius.zero) {
            if (comma) {
                result.write(", ");
            }
            result.write("bottomEnd: $_bottomEnd");
        }
        result.write(")");
        logical = result.toString();
    }
    if (visual != nullptr && logical != nullptr) {
        return "$visual + $logical";
    }
    if (visual != nullptr) {
        return visual;
    }
    if (logical != nullptr) {
        return logical;
    }
    return "BorderRadius.zero";
}

bool BorderRadiusGeometry::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is BorderRadiusGeometry && other._topLeft == _topLeft && other._topRight == _topRight && other._bottomLeft == _bottomLeft && other._bottomRight == _bottomRight && other._topStart == _topStart && other._topEnd == _topEnd && other._bottomStart == _bottomStart && other._bottomEnd == _bottomEnd;
}

int BorderRadiusGeometry::hashCode() {
    return Object.hash(_topLeft, _topRight, _bottomLeft, _bottomRight, _topStart, _topEnd, _bottomStart, _bottomEnd);
}

void BorderRadius::all(Radius radius)

void BorderRadius::circular(double radius)

void BorderRadius::vertical(Radius bottom, Radius top)

void BorderRadius::horizontal(Radius left, Radius right)

BorderRadius BorderRadius::copyWith(Radius bottomLeft, Radius bottomRight, Radius topLeft, Radius topRight) {
    return BorderRadius.only(topLeft ?? this.topLeft, topRight ?? this.topRight, bottomLeft ?? this.bottomLeft, bottomRight ?? this.bottomRight);
}

RRect BorderRadius::toRRect(Rect rect) {
    return RRect.fromRectAndCorners(recttopLeft, topRight, bottomLeft, bottomRight);
}

BorderRadiusGeometry BorderRadius::subtract(BorderRadiusGeometry other) {
    if (other is BorderRadius) {
        return this - other;
    }
    return super.subtract(other);
}

BorderRadiusGeometry BorderRadius::add(BorderRadiusGeometry other) {
    if (other is BorderRadius) {
        return this + other;
    }
    return super.add(other);
}

BorderRadius BorderRadius::-(BorderRadius other) {
    return BorderRadius.only(topLeft - other.topLeft, topRight - other.topRight, bottomLeft - other.bottomLeft, bottomRight - other.bottomRight);
}

BorderRadius BorderRadius::+(BorderRadius other) {
    return BorderRadius.only(topLeft + other.topLeft, topRight + other.topRight, bottomLeft + other.bottomLeft, bottomRight + other.bottomRight);
}

BorderRadius BorderRadius::-() {
    return BorderRadius.only(-topLeft, -topRight, -bottomLeft, -bottomRight);
}

BorderRadius BorderRadius::*(double other) {
    return BorderRadius.only(topLeft * other, topRight * other, bottomLeft * other, bottomRight * other);
}

BorderRadius BorderRadius::/(double other) {
    return BorderRadius.only(topLeft / other, topRight / other, bottomLeft / other, bottomRight / other);
}

BorderRadius BorderRadius::~/(double other) {
    return BorderRadius.only(topLeft ~/ other, topRight ~/ other, bottomLeft ~/ other, bottomRight ~/ other);
}

BorderRadius BorderRadius::%(double other) {
    return BorderRadius.only(topLeft % other, topRight % other, bottomLeft % other, bottomRight % other);
}

BorderRadius BorderRadius::lerp(BorderRadius a, BorderRadius b, double t) {
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
    return BorderRadius.only(Radius.lerp(a.topLeft, b.topLeft, t)!, Radius.lerp(a.topRight, b.topRight, t)!, Radius.lerp(a.bottomLeft, b.bottomLeft, t)!, Radius.lerp(a.bottomRight, b.bottomRight, t)!);
}

BorderRadius BorderRadius::resolve(TextDirection direction) {
    return this;
}

Radius BorderRadius::_topLeft() {
    return topLeft;
}

Radius BorderRadius::_topRight() {
    return topRight;
}

Radius BorderRadius::_bottomLeft() {
    return bottomLeft;
}

Radius BorderRadius::_bottomRight() {
    return bottomRight;
}

Radius BorderRadius::_topStart() {
    return Radius.zero;
}

Radius BorderRadius::_topEnd() {
    return Radius.zero;
}

Radius BorderRadius::_bottomStart() {
    return Radius.zero;
}

Radius BorderRadius::_bottomEnd() {
    return Radius.zero;
}

void BorderRadiusDirectional::all(Radius radius)

void BorderRadiusDirectional::circular(double radius)

void BorderRadiusDirectional::vertical(Radius bottom, Radius top)

void BorderRadiusDirectional::horizontal(Radius end, Radius start)

BorderRadiusGeometry BorderRadiusDirectional::subtract(BorderRadiusGeometry other) {
    if (other is BorderRadiusDirectional) {
        return this - other;
    }
    return super.subtract(other);
}

BorderRadiusGeometry BorderRadiusDirectional::add(BorderRadiusGeometry other) {
    if (other is BorderRadiusDirectional) {
        return this + other;
    }
    return super.add(other);
}

BorderRadiusDirectional BorderRadiusDirectional::-(BorderRadiusDirectional other) {
    return BorderRadiusDirectional.only(topStart - other.topStart, topEnd - other.topEnd, bottomStart - other.bottomStart, bottomEnd - other.bottomEnd);
}

BorderRadiusDirectional BorderRadiusDirectional::+(BorderRadiusDirectional other) {
    return BorderRadiusDirectional.only(topStart + other.topStart, topEnd + other.topEnd, bottomStart + other.bottomStart, bottomEnd + other.bottomEnd);
}

BorderRadiusDirectional BorderRadiusDirectional::-() {
    return BorderRadiusDirectional.only(-topStart, -topEnd, -bottomStart, -bottomEnd);
}

BorderRadiusDirectional BorderRadiusDirectional::*(double other) {
    return BorderRadiusDirectional.only(topStart * other, topEnd * other, bottomStart * other, bottomEnd * other);
}

BorderRadiusDirectional BorderRadiusDirectional::/(double other) {
    return BorderRadiusDirectional.only(topStart / other, topEnd / other, bottomStart / other, bottomEnd / other);
}

BorderRadiusDirectional BorderRadiusDirectional::~/(double other) {
    return BorderRadiusDirectional.only(topStart ~/ other, topEnd ~/ other, bottomStart ~/ other, bottomEnd ~/ other);
}

BorderRadiusDirectional BorderRadiusDirectional::%(double other) {
    return BorderRadiusDirectional.only(topStart % other, topEnd % other, bottomStart % other, bottomEnd % other);
}

BorderRadiusDirectional BorderRadiusDirectional::lerp(BorderRadiusDirectional a, BorderRadiusDirectional b, double t) {
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
    return BorderRadiusDirectional.only(Radius.lerp(a.topStart, b.topStart, t)!, Radius.lerp(a.topEnd, b.topEnd, t)!, Radius.lerp(a.bottomStart, b.bottomStart, t)!, Radius.lerp(a.bottomEnd, b.bottomEnd, t)!);
}

BorderRadius BorderRadiusDirectional::resolve(TextDirection direction) {
    assert(direction != nullptr);
    ;
}

Radius BorderRadiusDirectional::_topStart() {
    return topStart;
}

Radius BorderRadiusDirectional::_topEnd() {
    return topEnd;
}

Radius BorderRadiusDirectional::_bottomStart() {
    return bottomStart;
}

Radius BorderRadiusDirectional::_bottomEnd() {
    return bottomEnd;
}

Radius BorderRadiusDirectional::_topLeft() {
    return Radius.zero;
}

Radius BorderRadiusDirectional::_topRight() {
    return Radius.zero;
}

Radius BorderRadiusDirectional::_bottomLeft() {
    return Radius.zero;
}

Radius BorderRadiusDirectional::_bottomRight() {
    return Radius.zero;
}

_MixedBorderRadius _MixedBorderRadius::-() {
    return _MixedBorderRadius(-_topLeft, -_topRight, -_bottomLeft, -_bottomRight, -_topStart, -_topEnd, -_bottomStart, -_bottomEnd);
}

_MixedBorderRadius _MixedBorderRadius::*(double other) {
    return _MixedBorderRadius(_topLeft * other, _topRight * other, _bottomLeft * other, _bottomRight * other, _topStart * other, _topEnd * other, _bottomStart * other, _bottomEnd * other);
}

_MixedBorderRadius _MixedBorderRadius::/(double other) {
    return _MixedBorderRadius(_topLeft / other, _topRight / other, _bottomLeft / other, _bottomRight / other, _topStart / other, _topEnd / other, _bottomStart / other, _bottomEnd / other);
}

_MixedBorderRadius _MixedBorderRadius::~/(double other) {
    return _MixedBorderRadius(_topLeft ~/ other, _topRight ~/ other, _bottomLeft ~/ other, _bottomRight ~/ other, _topStart ~/ other, _topEnd ~/ other, _bottomStart ~/ other, _bottomEnd ~/ other);
}

_MixedBorderRadius _MixedBorderRadius::%(double other) {
    return _MixedBorderRadius(_topLeft % other, _topRight % other, _bottomLeft % other, _bottomRight % other, _topStart % other, _topEnd % other, _bottomStart % other, _bottomEnd % other);
}

BorderRadius _MixedBorderRadius::resolve(TextDirection direction) {
    assert(direction != nullptr);
    ;
}
