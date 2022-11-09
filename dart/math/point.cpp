#include "point.hpp"
template<typename T : num> PointCls<T>::PointCls(T x, T y) {
    {
        this->x = x;
        this->y = y;
    }
}

template<typename T : num> String PointCls<T>::toString() {
    return "Point($x, $y)";
}

template<typename T : num> bool PointCls<T>::==(Object other) {
    return other is Point && x == other->x && y == other->y;
}

template<typename T : num> int PointCls<T>::hashCode() {
    return SystemHashCls->hash2(x->hashCode, y->hashCode);
}

template<typename T : num> Point<T> PointCls<T>::+(Point<T> other) {
    return <T>make<PointCls>(((T)(x + other->x)), ((T)(y + other->y)));
}

template<typename T : num> Point<T> PointCls<T>::-(Point<T> other) {
    return <T>make<PointCls>(((T)(x - other->x)), ((T)(y - other->y)));
}

template<typename T : num> Point<T> PointCls<T>::*(num factor) {
    return <T>make<PointCls>(((T)(x * factor)), ((T)(y * factor)));
}

template<typename T : num> double PointCls<T>::magnitude() {
    return sqrt(x * x + y * y);
}

template<typename T : num> double PointCls<T>::distanceTo(Point<T> other) {
    auto dx = x - other->x;
    auto dy = y - other->y;
    return sqrt(dx * dx + dy * dy);
}

template<typename T : num> T PointCls<T>::squaredDistanceTo(Point<T> other) {
    auto dx = x - other->x;
    auto dy = y - other->y;
    return ((T)(dx * dx + dy * dy));
}
