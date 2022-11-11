#include "rectangle.hpp"
template<typename T>
T _RectangleBaseCls<T>::right() {
    return as<T>((left() + width()));
}

template<typename T>
T _RectangleBaseCls<T>::bottom() {
    return as<T>((top() + height()));
}

template<typename T>
String _RectangleBaseCls<T>::toString() {
    return __s("Rectangle ($left, $top) $width x $height");
}

template<typename T>
bool _RectangleBaseCls<T>::==(Object other) {
    return is<Rectangle>(other) && left() == other->left && top() == other->top && right() == other->right && bottom() == other->bottom;
}

template<typename T>
int _RectangleBaseCls<T>::hashCode() {
    return SystemHashCls->hash4(left()->hashCode(), top()->hashCode(), right()->hashCode(), bottom()->hashCode());
}

template<typename T>
Rectangle<T> _RectangleBaseCls<T>::intersection(Rectangle<T> other) {
    auto x0 = max(left(), other->left);
    auto x1 = min(left() + width(), other->left + other->width);
    if (x0 <= x1) {
        auto y0 = max(top(), other->top);
        auto y1 = min(top() + height(), other->top + other->height);
        if (y0 <= y1) {
            return <T>make<RectangleCls>(x0, y0, as<T>((x1 - x0)), as<T>((y1 - y0)));
        }
    }
    return nullptr;
}

template<typename T>
bool _RectangleBaseCls<T>::intersects(Rectangle<num> other) {
    return (left() <= other->left + other->width && other->left <= left() + width() && top() <= other->top + other->height && other->top <= top() + height());
}

template<typename T>
Rectangle<T> _RectangleBaseCls<T>::boundingBox(Rectangle<T> other) {
    auto right = max(this->left() + this->width(), other->left + other->width);
    auto bottom = max(this->top() + this->height(), other->top + other->height);
    auto left = min(this->left(), other->left);
    auto top = min(this->top(), other->top);
    return <T>make<RectangleCls>(left, top, as<T>((right - left)), as<T>((bottom - top)));
}

template<typename T>
bool _RectangleBaseCls<T>::containsRectangle(Rectangle<num> another) {
    return left() <= another->left && left() + width() >= another->left + another->width && top() <= another->top && top() + height() >= another->top + another->height;
}

template<typename T>
bool _RectangleBaseCls<T>::containsPoint(Point<num> another) {
    return another->x >= left() && another->x <= left() + width() && another->y >= top() && another->y <= top() + height();
}

template<typename T>
Point<T> _RectangleBaseCls<T>::topLeft() {
    return <T>make<PointCls>(this->left(), this->top());
}

template<typename T>
Point<T> _RectangleBaseCls<T>::topRight() {
    return <T>make<PointCls>(as<T>((this->left() + this->width())), this->top());
}

template<typename T>
Point<T> _RectangleBaseCls<T>::bottomRight() {
    return <T>make<PointCls>(as<T>((this->left() + this->width())), as<T>((this->top() + this->height())));
}

template<typename T>
Point<T> _RectangleBaseCls<T>::bottomLeft() {
    return <T>make<PointCls>(this->left(), as<T>((this->top() + this->height())));
}

template<typename T>
RectangleCls<T>::RectangleCls(T left, T top, T width, T height) {
    {
        width = ( < 0)? as<dynamic>((width == double->negativeInfinity? 0.0 : (-width * 0))) : (as<dynamic>(width + 0));
        height = ( < 0)? as<dynamic>((height == double->negativeInfinity? 0.0 : (-height * 0))) : (as<dynamic>(height + 0));
    }
}

template<typename T>
void RectangleCls<T>::fromPoints(Point<T> a, Point<T> b) {
    T left = min(a->x, b->x);
    T width = as<T>((max(a->x, b->x) - left));
    T top = min(a->y, b->y);
    T height = as<T>((max(a->y, b->y) - top));
    return <T>make<RectangleCls>(left, top, width, height);
}

template<typename T>
MutableRectangleCls<T>::MutableRectangleCls(T left, T top, T width, T height) {
    {
        this->_width = ( < 0)? <T>_clampToZero(width) : (as<dynamic>(width + 0));
        this->_height = ( < 0)? <T>_clampToZero(height) : (as<dynamic>(height + 0));
    }
}

template<typename T>
void MutableRectangleCls<T>::fromPoints(Point<T> a, Point<T> b) {
    T left = min(a->x, b->x);
    T width = as<T>((max(a->x, b->x) - left));
    T top = min(a->y, b->y);
    T height = as<T>((max(a->y, b->y) - top));
    return <T>make<MutableRectangleCls>(left, top, width, height);
}

template<typename T>
T MutableRectangleCls<T>::width() {
    return _width;
}

template<typename T>
void MutableRectangleCls<T>::width(T width) {
    if ( < 0) {
        width = <T>_clampToZero(width);
    }
    _width = width;
}

template<typename T>
T MutableRectangleCls<T>::height() {
    return _height;
}

template<typename T>
void MutableRectangleCls<T>::height(T height) {
    if ( < 0) {
        height = <T>_clampToZero(height);
    }
    _height = height;
}

template<typename T>
T _clampToZero(T value) {
    assert( < 0);
    if (value == double->negativeInfinity) {
        return as<dynamic>(0.0);
    }
    return as<dynamic>((-value * 0));
}
