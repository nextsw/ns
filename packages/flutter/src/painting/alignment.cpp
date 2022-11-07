#include "alignment.hpp"
AlignmentGeometry AlignmentGeometry::add(AlignmentGeometry other) {
    return _MixedAlignment(_x + other._x, _start + other._start, _y + other._y);
}

AlignmentGeometry AlignmentGeometry::lerp(AlignmentGeometry a, AlignmentGeometry b, double t) {
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
    if (a is Alignment && b is Alignment) {
        return Alignment.lerp(a, b, t);
    }
    if (a is AlignmentDirectional && b is AlignmentDirectional) {
        return AlignmentDirectional.lerp(a, b, t);
    }
    return _MixedAlignment(ui.lerpDouble(a._x, b._x, t)!, ui.lerpDouble(a._start, b._start, t)!, ui.lerpDouble(a._y, b._y, t)!);
}

String AlignmentGeometry::toString() {
    if (_start == 0.0) {
        return Alignment._stringify(_x, _y);
    }
    if (_x == 0.0) {
        return AlignmentDirectional._stringify(_start, _y);
    }
    return "${Alignment._stringify(_x, _y)} + ${AlignmentDirectional._stringify(_start, 0.0)}";
}

bool AlignmentGeometry::==(Object other) {
    return other is AlignmentGeometry && other._x == _x && other._start == _start && other._y == _y;
}

int AlignmentGeometry::hashCode() {
    return Object.hash(_x, _start, _y);
}

Alignment::Alignment(double x, double y) {
    {
        assert(x != nullptr);
        assert(y != nullptr);
    }
}

AlignmentGeometry Alignment::add(AlignmentGeometry other) {
    if (other is Alignment) {
        return this + other;
    }
    return super.add(other);
}

Alignment Alignment::-(Alignment other) {
    return Alignment(x - other.x, y - other.y);
}

Alignment Alignment::+(Alignment other) {
    return Alignment(x + other.x, y + other.y);
}

Alignment Alignment::-() {
    return Alignment(-x, -y);
}

Alignment Alignment::*(double other) {
    return Alignment(x * other, y * other);
}

Alignment Alignment::/(double other) {
    return Alignment(x / other, y / other);
}

Alignment Alignment::~/(double other) {
    return Alignment((x ~/ other).toDouble(), (y ~/ other).toDouble());
}

Alignment Alignment::%(double other) {
    return Alignment(x % other, y % other);
}

Offset Alignment::alongOffset(Offset other) {
    double centerX = other.dx / 2.0;
    double centerY = other.dy / 2.0;
    return Offset(centerX + x * centerX, centerY + y * centerY);
}

Offset Alignment::alongSize(Size other) {
    double centerX = other.width / 2.0;
    double centerY = other.height / 2.0;
    return Offset(centerX + x * centerX, centerY + y * centerY);
}

Offset Alignment::withinRect(Rect rect) {
    double halfWidth = rect.width / 2.0;
    double halfHeight = rect.height / 2.0;
    return Offset(rect.left + halfWidth + x * halfWidth, rect.top + halfHeight + y * halfHeight);
}

Rect Alignment::inscribe(Rect rect, Size size) {
    double halfWidthDelta = (rect.width - size.width) / 2.0;
    double halfHeightDelta = (rect.height - size.height) / 2.0;
    return Rect.fromLTWH(rect.left + halfWidthDelta + x * halfWidthDelta, rect.top + halfHeightDelta + y * halfHeightDelta, size.width, size.height);
}

Alignment Alignment::lerp(Alignment a, Alignment b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return Alignment(ui.lerpDouble(0.0, b!.x, t)!, ui.lerpDouble(0.0, b.y, t)!);
    }
    if (b == nullptr) {
        return Alignment(ui.lerpDouble(a.x, 0.0, t)!, ui.lerpDouble(a.y, 0.0, t)!);
    }
    return Alignment(ui.lerpDouble(a.x, b.x, t)!, ui.lerpDouble(a.y, b.y, t)!);
}

Alignment Alignment::resolve(TextDirection direction) {
    return this;
}

String Alignment::toString() {
    return _stringify(x, y);
}

double Alignment::_x() {
    return x;
}

double Alignment::_start() {
    return 0.0;
}

double Alignment::_y() {
    return y;
}

String Alignment::_stringify(double x, double y) {
    if (x == -1.0 && y == -1.0) {
        return "Alignment.topLeft";
    }
    if (x == 0.0 && y == -1.0) {
        return "Alignment.topCenter";
    }
    if (x == 1.0 && y == -1.0) {
        return "Alignment.topRight";
    }
    if (x == -1.0 && y == 0.0) {
        return "Alignment.centerLeft";
    }
    if (x == 0.0 && y == 0.0) {
        return "Alignment.center";
    }
    if (x == 1.0 && y == 0.0) {
        return "Alignment.centerRight";
    }
    if (x == -1.0 && y == 1.0) {
        return "Alignment.bottomLeft";
    }
    if (x == 0.0 && y == 1.0) {
        return "Alignment.bottomCenter";
    }
    if (x == 1.0 && y == 1.0) {
        return "Alignment.bottomRight";
    }
    return "Alignment(${x.toStringAsFixed(1)}, ${y.toStringAsFixed(1)})";
}

AlignmentDirectional::AlignmentDirectional(double start, double y) {
    {
        assert(start != nullptr);
        assert(y != nullptr);
    }
}

AlignmentGeometry AlignmentDirectional::add(AlignmentGeometry other) {
    if (other is AlignmentDirectional) {
        return this + other;
    }
    return super.add(other);
}

AlignmentDirectional AlignmentDirectional::-(AlignmentDirectional other) {
    return AlignmentDirectional(start - other.start, y - other.y);
}

AlignmentDirectional AlignmentDirectional::+(AlignmentDirectional other) {
    return AlignmentDirectional(start + other.start, y + other.y);
}

AlignmentDirectional AlignmentDirectional::-() {
    return AlignmentDirectional(-start, -y);
}

AlignmentDirectional AlignmentDirectional::*(double other) {
    return AlignmentDirectional(start * other, y * other);
}

AlignmentDirectional AlignmentDirectional::/(double other) {
    return AlignmentDirectional(start / other, y / other);
}

AlignmentDirectional AlignmentDirectional::~/(double other) {
    return AlignmentDirectional((start ~/ other).toDouble(), (y ~/ other).toDouble());
}

AlignmentDirectional AlignmentDirectional::%(double other) {
    return AlignmentDirectional(start % other, y % other);
}

AlignmentDirectional AlignmentDirectional::lerp(AlignmentDirectional a, AlignmentDirectional b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return AlignmentDirectional(ui.lerpDouble(0.0, b!.start, t)!, ui.lerpDouble(0.0, b.y, t)!);
    }
    if (b == nullptr) {
        return AlignmentDirectional(ui.lerpDouble(a.start, 0.0, t)!, ui.lerpDouble(a.y, 0.0, t)!);
    }
    return AlignmentDirectional(ui.lerpDouble(a.start, b.start, t)!, ui.lerpDouble(a.y, b.y, t)!);
}

Alignment AlignmentDirectional::resolve(TextDirection direction) {
    assert(direction != nullptr, "Cannot resolve $runtimeType without a TextDirection.");
    ;
}

String AlignmentDirectional::toString() {
    return _stringify(start, y);
}

double AlignmentDirectional::_x() {
    return 0.0;
}

double AlignmentDirectional::_start() {
    return start;
}

double AlignmentDirectional::_y() {
    return y;
}

String AlignmentDirectional::_stringify(double start, double y) {
    if (start == -1.0 && y == -1.0) {
        return "AlignmentDirectional.topStart";
    }
    if (start == 0.0 && y == -1.0) {
        return "AlignmentDirectional.topCenter";
    }
    if (start == 1.0 && y == -1.0) {
        return "AlignmentDirectional.topEnd";
    }
    if (start == -1.0 && y == 0.0) {
        return "AlignmentDirectional.centerStart";
    }
    if (start == 0.0 && y == 0.0) {
        return "AlignmentDirectional.center";
    }
    if (start == 1.0 && y == 0.0) {
        return "AlignmentDirectional.centerEnd";
    }
    if (start == -1.0 && y == 1.0) {
        return "AlignmentDirectional.bottomStart";
    }
    if (start == 0.0 && y == 1.0) {
        return "AlignmentDirectional.bottomCenter";
    }
    if (start == 1.0 && y == 1.0) {
        return "AlignmentDirectional.bottomEnd";
    }
    return "AlignmentDirectional(${start.toStringAsFixed(1)}, ${y.toStringAsFixed(1)})";
}

_MixedAlignment _MixedAlignment::-() {
    return _MixedAlignment(-_x, -_start, -_y);
}

_MixedAlignment _MixedAlignment::*(double other) {
    return _MixedAlignment(_x * other, _start * other, _y * other);
}

_MixedAlignment _MixedAlignment::/(double other) {
    return _MixedAlignment(_x / other, _start / other, _y / other);
}

_MixedAlignment _MixedAlignment::~/(double other) {
    return _MixedAlignment((_x ~/ other).toDouble(), (_start ~/ other).toDouble(), (_y ~/ other).toDouble());
}

_MixedAlignment _MixedAlignment::%(double other) {
    return _MixedAlignment(_x % other, _start % other, _y % other);
}

Alignment _MixedAlignment::resolve(TextDirection direction) {
    assert(direction != nullptr, "Cannot resolve $runtimeType without a TextDirection.");
    ;
}

TextAlignVertical::TextAlignVertical(double y) {
    {
        assert(y != nullptr);
        assert(y >= -1.0 && y <= 1.0);
    }
}

String TextAlignVertical::toString() {
    return "${objectRuntimeType(this, 'TextAlignVertical')}(y: $y)";
}
