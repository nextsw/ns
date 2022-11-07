#include "rectangle.hpp"
T _RectangleBase::right() {
    return (;
}

T _RectangleBase::bottom() {
    return (;
}

String _RectangleBase::toString() {
    return "Rectangle ($left, $top) $width x $height";
}

bool _RectangleBase::==(Object other) {
    return other is Rectangle && left == other.left && top == other.top && right == other.right && bottom == other.bottom;
}

int _RectangleBase::hashCode() {
    return SystemHash.hash4(left.hashCode, top.hashCode, right.hashCode, bottom.hashCode);
}

Rectangle<T> _RectangleBase::intersection(Rectangle<T> other) {
    auto x0 = max(left, other.left);
    auto x1 = min(left + width, other.left + other.width);
    if (x0 <= x1) {
        auto y0 = max(top, other.top);
        auto y1 = min(top + height, other.top + other.height);
        if (y0 <= y1) {
            return <T>Rectangle(x0, y0, (, ();
        }
    }
    return nullptr;
}

bool _RectangleBase::intersects(Rectangle<num> other) {
    return (left <= other.left + other.width && other.left <= left + width && top <= other.top + other.height && other.top <= top + height);
}

Rectangle<T> _RectangleBase::boundingBox(Rectangle<T> other) {
    auto right = max(this.left + this.width, other.left + other.width);
    auto bottom = max(this.top + this.height, other.top + other.height);
    auto left = min(this.left, other.left);
    auto top = min(this.top, other.top);
    return <T>Rectangle(left, top, (, ();
}

bool _RectangleBase::containsRectangle(Rectangle<num> another) {
    return left <= another.left && left + width >= another.left + another.width && top <= another.top && top + height >= another.top + another.height;
}

bool _RectangleBase::containsPoint(Point<num> another) {
    return another.x >= left && another.x <= left + width && another.y >= top && another.y <= top + height;
}

Point<T> _RectangleBase::topLeft() {
    return <T>Point(this.left, this.top);
}

Point<T> _RectangleBase::topRight() {
    return <T>Point((, this.top);
}

Point<T> _RectangleBase::bottomRight() {
    return <T>Point((, ();
}

Point<T> _RectangleBase::bottomLeft() {
    return <T>Point(this.left, ();
}

Rectangle::Rectangle(T height, T left, T top, T width) {
    {
        width = ( < 0)? ( : (();
        height = ( < 0)? ( : (();
    }
}

void Rectangle::fromPoints(Point<T> a, Point<T> b) {
    T left = min(a.x, b.x);
    T width = (;
    T top = min(a.y, b.y);
    T height = (;
    return <T>Rectangle(left, top, width, height);
}

MutableRectangle::MutableRectangle(T height, T left, T top, T width) {
    {
        this._width = ( < 0)? <T>_clampToZero(width) : (();
        this._height = ( < 0)? <T>_clampToZero(height) : (();
    }
}

void MutableRectangle::fromPoints(Point<T> a, Point<T> b) {
    T left = min(a.x, b.x);
    T width = (;
    T top = min(a.y, b.y);
    T height = (;
    return <T>MutableRectangle(left, top, width, height);
}

T MutableRectangle::width() {
    return _width;
}

void MutableRectangle::width(T width) {
    if ( < 0)     {
        width = <T>_clampToZero(width);
    }
    _width = width;
}

T MutableRectangle::height() {
    return _height;
}

void MutableRectangle::height(T height) {
    if ( < 0)     {
        height = <T>_clampToZero(height);
    }
    _height = height;
}

T _clampToZero<T extends num>(T value) {
    assert( < 0);
    if (value == double.negativeInfinity)     {
        return (;
    }
    return (;
}
