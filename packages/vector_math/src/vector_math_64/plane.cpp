#include "plane.hpp"
void PlaneCls::intersection(Plane a, Plane b, Plane c, Vector3 result) {
    Unknown cross = Vector3Cls->zero();
    b->normal->crossInto(c->normal, cross);
    Unknown f = -a->normal->dot(cross);
    Unknown v1 = cross->scaled(a->constant);
    c->normal->crossInto(a->normal, cross);
    Unknown v2 = cross->scaled(b->constant);
    a->normal->crossInto(b->normal, cross);
    Unknown v3 = cross->scaled(c->constant);
    auto _c1 = result;_c1.x = auto _c2 = (v1->x + v2->x + v3->x) / f;_c2.y = auto _c3 = (v1->y + v2->y + v3->y) / f;_c3.z = (v1->z + v2->z + v3->z) / f;_c3;_c2;_c1;
}

Vector3 PlaneCls::normal() {
    return _normal;
}

PlaneCls::PlaneCls() {
    {
        _normal = Vector3Cls->zero();
        constant = 0.0;
    }
}

void PlaneCls::copy(Plane other)

void PlaneCls::components(double constant, double x, double y, double z)

void PlaneCls::normalconstant(double constant, Vector3 normal_)

void PlaneCls::copyFrom(Plane o) {
    _normal->setFrom(o->_normal);
    constant = o->constant;
}

void PlaneCls::setFromComponents(double w, double x, double y, double z) {
    _normal->setValues(x, y, z);
    constant = w;
}

void PlaneCls::normalize() {
    Unknown inverseLength = 1.0 / normal()->length;
    _normal->scale(inverseLength);
    constant = inverseLength;
}

double PlaneCls::distanceToVector3(Vector3 point) {
    return _normal->dot(point) + constant;
}
