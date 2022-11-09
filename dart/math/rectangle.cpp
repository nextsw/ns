#include "rectangle.hpp"
template<typename T : num> T _RectangleBaseCls<T>::right() {
    return ((T)(left + width));
}

template<typename T : num> T _RectangleBaseCls<T>::bottom() {
    return ((T)(top + height));
}

template<typename T : num> String _RectangleBaseCls<T>::toString() {
    return "Rectangle ($left, $top) $width x $height";
}

template<typename T : num> bool _RectangleBaseCls<T>::==(Object other) {
    return other is Rectangle && left == other->left && top == other->top && right == other->right && bottom == other->bottom;
}

template<typename T : num> int _RectangleBaseCls<T>::hashCode() {
    return SystemHashCls->hash4(left->hashCode, top->hashCode, right->hashCode, bottom->hashCode);
}

template<typename T : num> Rectangle<T> _RectangleBaseCls<T>::intersection(Rectangle<T> other) {
    auto x0 = max(left, other->left);
    auto x1 = min(left + width, other->left + other->width);
    if (x0 <= x1) {
        auto y0 = max(top, other->top);
        auto y1 = min(top + height, other->top + other->height);
        if (y0 <= y1) {
            return <T>make<RectangleCls>(x0, y0, ((T)(x1 - x0)), ((T)(y1 - y0)));
        }
    }
    return nullptr;
}

template<typename T : num> bool _RectangleBaseCls<T>::intersects(Rectangle<num> other) {
    return (left <= other->left + other->width && other->left <= left + width && top <= other->top + other->height && other->top <= top + height);
}

template<typename T : num> Rectangle<T> _RectangleBaseCls<T>::boundingBox(Rectangle<T> other) {
    auto right = max(this->left + this->width, other->left + other->width);
    auto bottom = max(this->top + this->height, other->top + other->height);
    auto left = min(this->left, other->left);
    auto top = min(this->top, other->top);
    return <T>make<RectangleCls>(left, top, ((T)(right - left)), ((T)(bottom - top)));
}

template<typename T : num> bool _RectangleBaseCls<T>::containsRectangle(Rectangle<num> another) {
    return left <= another->left && left + width >= another->left + another->width && top <= another->top && top + height >= another->top + another->height;
}

template<typename T : num> bool _RectangleBaseCls<T>::containsPoint(Point<num> another) {
    return another->x >= left && another->x <= left + width && another->y >= top && another->y <= top + height;
}

template<typename T : num> Point<T> _RectangleBaseCls<T>::topLeft() {
    return <T>make<PointCls>(this->left, this->top);
}

template<typename T : num> Point<T> _RectangleBaseCls<T>::topRight() {
    return <T>make<PointCls>(((T)(this->left + this->width)), this->top);
}

template<typename T : num> Point<T> _RectangleBaseCls<T>::bottomRight() {
    return <T>make<PointCls>(((T)(this->left + this->width)), ((T)(this->top + this->height)));
}

template<typename T : num> Point<T> _RectangleBaseCls<T>::bottomLeft() {
    return <T>make<PointCls>(this->left, ((T)(this->top + this->height)));
}

template<typename T : num> RectangleCls<T>::RectangleCls(T height, T left, T top, T width) {
    {
        width = ( < 0)? ((dynamic)(width == double->negativeInfinity? 0.0 : (-width * 0))) : (((dynamic)width + 0));
        height = ( < 0)? ((dynamic)(height == double->negativeInfinity? 0.0 : (-height * 0))) : (((dynamic)height + 0));
    }
}

template<typename T : num> void RectangleCls<T>::fromPoints(Point<T> a, Point<T> b) {
    T left = min(a->x, b->x);
    T width = ((T)(max(a->x, b->x) - left));
    T top = min(a->y, b->y);
    T height = ((T)(max(a->y, b->y) - top));
    return <T>make<RectangleCls>(left, top, width, height);
}

template<typename T : num> MutableRectangleCls<T>::MutableRectangleCls(T height, T left, T top, T width) {
    {
        this->_width = ( < 0)? <T>_clampToZero(width) : (((dynamic)width + 0));
        this->_height = ( < 0)? <T>_clampToZero(height) : (((dynamic)height + 0));
    }
}

template<typename T : num> void MutableRectangleCls<T>::fromPoints(Point<T> a, Point<T> b) {
    T left = min(a->x, b->x);
    T width = ((T)(max(a->x, b->x) - left));
    T top = min(a->y, b->y);
    T height = ((T)(max(a->y, b->y) - top));
    return <T>make<MutableRectangleCls>(left, top, width, height);
}

template<typename T : num> T MutableRectangleCls<T>::width() {
    return _width;
}

template<typename T : num> void MutableRectangleCls<T>::width(T width) {
    if ( < 0)     {
        width = <T>_clampToZero(width);
    }
    _width = width;
}

template<typename T : num> T MutableRectangleCls<T>::height() {
    return _height;
}

template<typename T : num> void MutableRectangleCls<T>::height(T height) {
    if ( < 0)     {
        height = <T>_clampToZero(height);
    }
    _height = height;
}

T _clampToZerotemplate<typename T : num> (T value) {
    assert( < 0);
    if (value == double->negativeInfinity)     {
        return ((dynamic)0.0);
    }
    return ((dynamic)(-value * 0));
}
