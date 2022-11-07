#include "ray.hpp"
Vector3 Ray::origin() {
    return _origin;
}

Vector3 Ray::direction() {
    return _direction;
}

Ray::Ray() {
    {
        _origin = Vector3.zero();
        _direction = Vector3.zero();
    }
}

void Ray::copy(Ray other)

void Ray::originDirection(Vector3 direction, Vector3 origin)

void Ray::copyFrom(Ray other) {
    _origin.setFrom(other._origin);
    _direction.setFrom(other._direction);
}

Vector3 Ray::at(double t) {
    return ;
}

void Ray::copyAt(Vector3 other, double t) {
    ;
}

double Ray::intersectsWithSphere(Sphere other) {
    Unknown r = other.radius;
    Unknown r2 = r * r;
    Unknown l = ;
    Unknown s = l.dot(_direction);
    Unknown l2 = l.dot(l);
    if ( < 0 && l2 > r2) {
        return nullptr;
    }
    Unknown m2 = l2 - s * s;
    if (m2 > r2) {
        return nullptr;
    }
    Unknown q = math.sqrt(r2 - m2);
    return (l2 > r2)? s - q : s + q;
}

double Ray::intersectsWithTriangle(Triangle other) {
    const epsilon = 10e-6;
    Unknown point0 = other._point0;
    Unknown point1 = other._point1;
    Unknown point2 = other._point2;
    ;
    ;
    _direction.crossInto(_e2, _q);
    Unknown a = _e1.dot(_q);
    if (a > -epsilon &&  < epsilon) {
        return nullptr;
    }
    Unknown f = 1 / a;
    ;
    Unknown u = f * (_s.dot(_q));
    if ( < 0.0) {
        return nullptr;
    }
    _s.crossInto(_e1, _r);
    Unknown v = f * (_direction.dot(_r));
    if ( < -epsilon || u + v > 1.0 + epsilon) {
        return nullptr;
    }
    Unknown t = f * (_e2.dot(_r));
    return t;
}

double Ray::intersectsWithQuad(Quad other) {
    const epsilon = 10e-6;
    auto point0 = other._point0;
    auto point1 = other._point1;
    auto point2 = other._point2;
    ;
    ;
    _direction.crossInto(_e2, _q);
    Unknown a0 = _e1.dot(_q);
    if (!(a0 > -epsilon &&  < epsilon)) {
        Unknown f = 1 / a0;
        ;
        Unknown u = f * (_s.dot(_q));
        if (u >= 0.0) {
            _s.crossInto(_e1, _r);
            Unknown v = f * (_direction.dot(_r));
            if (!( < -epsilon || u + v > 1.0 + epsilon)) {
                Unknown t = f * (_e2.dot(_r));
                return t;
            }
        }
    }
    point0 = other._point3;
    point1 = other._point0;
    point2 = other._point2;
    ;
    ;
    _direction.crossInto(_e2, _q);
    Unknown a1 = _e1.dot(_q);
    if (!(a1 > -epsilon &&  < epsilon)) {
        Unknown f = 1 / a1;
        ;
        Unknown u = f * (_s.dot(_q));
        if (u >= 0.0) {
            _s.crossInto(_e1, _r);
            Unknown v = f * (_direction.dot(_r));
            if (!( < -epsilon || u + v > 1.0 + epsilon)) {
                Unknown t = f * (_e2.dot(_r));
                return t;
            }
        }
    }
    return nullptr;
}

double Ray::intersectsWithAabb3(Aabb3 other) {
    Unknown otherMin = other.min;
    Unknown otherMax = other.max;
    auto tNear = -double.maxFinite;
    auto tFar = double.maxFinite;
    for (;  < 3; ++i) {
        if (_direction[i] == 0.0) {
            if (_origin[i] < otherMin[i] || _origin[i] > otherMax[i]) {
                return nullptr;
            }
        } else {
            auto t1 = (otherMin[i] - _origin[i]) / _direction[i];
            auto t2 = (otherMax[i] - _origin[i]) / _direction[i];
            if (t1 > t2) {
                Unknown temp = t1;
                t1 = t2;
                t2 = temp;
            }
            if (t1 > tNear) {
                tNear = t1;
            }
            if ( < tFar) {
                tFar = t2;
            }
            if (tNear > tFar ||  < 0) {
                return nullptr;
            }
        }
    }
    return tNear;
}
