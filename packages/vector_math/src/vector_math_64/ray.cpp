#include "ray.hpp"
Vector3 RayCls::origin() {
    return _origin;
}

Vector3 RayCls::direction() {
    return _direction;
}

RayCls::RayCls() {
    {
        _origin = Vector3Cls->zero();
        _direction = Vector3Cls->zero();
    }
}

void RayCls::copy(Ray other)

void RayCls::originDirection(Vector3 direction, Vector3 origin)

void RayCls::copyFrom(Ray other) {
    _origin->setFrom(other->_origin);
    _direction->setFrom(other->_direction);
}

Vector3 RayCls::at(double t) {
    return _c1;
}

void RayCls::copyAt(Vector3 other, double t) {
    auto _c1 = _direction->scaled(t);_c1.add(_origin);auto _c1 = other;_c1.auto _c2 = setFrom(_direction);_c2.auto _c3 = scale(t);_c3.add(_origin);_c3;_c2;_c1;
}

double RayCls::intersectsWithSphere(Sphere other) {
    Unknown r = other->radius;
    Unknown r2 = r * r;
    auto _c1 = other->_center->clone();_c1.sub(_origin);Unknown l = _c1;
    Unknown s = l->dot(_direction);
    Unknown l2 = l->dot(l);
    if ( < 0 && l2 > r2) {
        return nullptr;
    }
    Unknown m2 = l2 - s * s;
    if (m2 > r2) {
        return nullptr;
    }
    Unknown q = math->sqrt(r2 - m2);
    return (l2 > r2)? s - q : s + q;
}

double RayCls::intersectsWithTriangle(Triangle other) {
    epsilon = 10e-6;
    Unknown point0 = other->_point0;
    Unknown point1 = other->_point1;
    Unknown point2 = other->_point2;
    auto _c1 = _e1;_c1.auto _c2 = setFrom(point1);_c2.sub(point0);_c2;_c1;
    auto _c3 = _e2;_c3.auto _c4 = setFrom(point2);_c4.sub(point0);_c4;_c3;
    _direction->crossInto(_e2, _q);
    Unknown a = _e1->dot(_q);
    if (a > -epsilon &&  < epsilon) {
        return nullptr;
    }
    Unknown f = 1 / a;
    auto _c5 = _s;_c5.auto _c6 = setFrom(_origin);_c6.sub(point0);_c6;_c5;
    Unknown u = f * (_s->dot(_q));
    if ( < 0.0) {
        return nullptr;
    }
    _s->crossInto(_e1, _r);
    Unknown v = f * (_direction->dot(_r));
    if ( < -epsilon || u + v > 1.0 + epsilon) {
        return nullptr;
    }
    Unknown t = f * (_e2->dot(_r));
    return t;
}

double RayCls::intersectsWithQuad(Quad other) {
    epsilon = 10e-6;
    auto point0 = other->_point0;
    auto point1 = other->_point1;
    auto point2 = other->_point2;
    auto _c1 = _e1;_c1.auto _c2 = setFrom(point1);_c2.sub(point0);_c2;_c1;
    auto _c3 = _e2;_c3.auto _c4 = setFrom(point2);_c4.sub(point0);_c4;_c3;
    _direction->crossInto(_e2, _q);
    Unknown a0 = _e1->dot(_q);
    if (!(a0 > -epsilon &&  < epsilon)) {
        Unknown f = 1 / a0;
            auto _c5 = _s;    _c5.auto _c6 = setFrom(_origin);    _c6.sub(point0);    _c6;_c5;
        Unknown u = f * (_s->dot(_q));
        if (u >= 0.0) {
            _s->crossInto(_e1, _r);
            Unknown v = f * (_direction->dot(_r));
            if (!( < -epsilon || u + v > 1.0 + epsilon)) {
                Unknown t = f * (_e2->dot(_r));
                return t;
            }
        }
    }
    point0 = other->_point3;
    point1 = other->_point0;
    point2 = other->_point2;
    auto _c7 = _e1;_c7.auto _c8 = setFrom(point1);_c8.sub(point0);_c8;_c7;
    auto _c9 = _e2;_c9.auto _c10 = setFrom(point2);_c10.sub(point0);_c10;_c9;
    _direction->crossInto(_e2, _q);
    Unknown a1 = _e1->dot(_q);
    if (!(a1 > -epsilon &&  < epsilon)) {
        Unknown f = 1 / a1;
            auto _c11 = _s;    _c11.auto _c12 = setFrom(_origin);    _c12.sub(point0);    _c12;_c11;
        Unknown u = f * (_s->dot(_q));
        if (u >= 0.0) {
            _s->crossInto(_e1, _r);
            Unknown v = f * (_direction->dot(_r));
            if (!( < -epsilon || u + v > 1.0 + epsilon)) {
                Unknown t = f * (_e2->dot(_r));
                return t;
            }
        }
    }
    return nullptr;
}

double RayCls::intersectsWithAabb3(Aabb3 other) {
    Unknown otherMin = other->min;
    Unknown otherMax = other->max;
    auto tNear = -double->maxFinite;
    auto tFar = double->maxFinite;
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
