#include "point.hpp"
template<typename T>
PointCls<T>::PointCls(T x, T y) {
    {
        this->x = x;
        this->y = y;
    }
}

template<typename T>
String PointCls<T>::toString() {
    return __s("Point($x, $y)");
}

template<typename T>
bool PointCls<T>::==(Object other) {
    return is<Point>(other) && x == other->x && y == other->y;
}

template<typename T>
int PointCls<T>::hashCode() {
    return SystemHashCls->hash2(x->hashCode(), y->hashCode());
}

template<typename T>
Point<T> PointCls<T>::+(Point<T> other) {
    return <T>make<PointCls>(as<T>((x + other->x)), as<T>((y + other->y)));
}

template<typename T>
Point<T> PointCls<T>::-(Point<T> other) {
    return <T>make<PointCls>(as<T>((x - other->x)), as<T>((y - other->y)));
}

template<typename T>
Point<T> PointCls<T>::*(num factor) {
    return <T>make<PointCls>(as<T>((x * factor)), as<T>((y * factor)));
}

template<typename T>
double PointCls<T>::magnitude() {
    return sqrt(x * x + y * y);
}

template<typename T>
double PointCls<T>::distanceTo(Point<T> other) {
    auto dx = x - other->x;
    auto dy = y - other->y;
    return sqrt(dx * dx + dy * dy);
}

template<typename T>
T PointCls<T>::squaredDistanceTo(Point<T> other) {
    auto dx = x - other->x;
    auto dy = y - other->y;
    return as<T>((dx * dx + dy * dy));
}
