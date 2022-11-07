#include "point.hpp"
Point::Point(T x, T y) {
    {
        this.x = x;
        this.y = y;
    }
}

String Point::toString() {
    return "Point($x, $y)";
}

bool Point::==(Object other) {
    return other is Point && x == other.x && y == other.y;
}

int Point::hashCode() {
    return SystemHash.hash2(x.hashCode, y.hashCode);
}

Point<T> Point::+(Point<T> other) {
    return <T>Point((, ();
}

Point<T> Point::-(Point<T> other) {
    return <T>Point((, ();
}

Point<T> Point::*(num factor) {
    return <T>Point((, ();
}

double Point::magnitude() {
    return sqrt(x * x + y * y);
}

double Point::distanceTo(Point<T> other) {
    auto dx = x - other.x;
    auto dy = y - other.y;
    return sqrt(dx * dx + dy * dy);
}

T Point::squaredDistanceTo(Point<T> other) {
    auto dx = x - other.x;
    auto dy = y - other.y;
    return (;
}
