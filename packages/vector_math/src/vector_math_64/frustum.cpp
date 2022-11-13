#include "frustum.hpp"
Plane FrustumCls::plane0() {
    return _plane0;
}

Plane FrustumCls::plane1() {
    return _plane1;
}

Plane FrustumCls::plane2() {
    return _plane2;
}

Plane FrustumCls::plane3() {
    return _plane3;
}

Plane FrustumCls::plane4() {
    return _plane4;
}

Plane FrustumCls::plane5() {
    return _plane5;
}

FrustumCls::FrustumCls() {
    {
        _plane0 = make<PlaneCls>();
        _plane1 = make<PlaneCls>();
        _plane2 = make<PlaneCls>();
        _plane3 = make<PlaneCls>();
        _plane4 = make<PlaneCls>();
        _plane5 = make<PlaneCls>();
    }
}

void FrustumCls::copy(Frustum other) {
    return _c1;
}

void FrustumCls::matrix(Matrix4 matrix) {
    return _c1;
}

void FrustumCls::copyFrom(Frustum other) {
    auto _c1 = make<FrustumCls>();_c1.copyFrom(other);auto _c1 = make<FrustumCls>();_c1.setFromMatrix(matrix);_plane0->copyFrom(other->_plane0);
    _plane1->copyFrom(other->_plane1);
    _plane2->copyFrom(other->_plane2);
    _plane3->copyFrom(other->_plane3);
    _plane4->copyFrom(other->_plane4);
    _plane5->copyFrom(other->_plane5);
}

void FrustumCls::setFromMatrix(Matrix4 matrix) {
    auto me = matrix->storage();
    auto me0 = me[0], me1 = me[1], me2 = me[2], me3 = me[3];
    auto me4 = me[4], me5 = me[5], me6 = me[6], me7 = me[7];
    auto me8 = me[8], me9 = me[9], me10 = me[10], me11 = me[11];
    auto me12 = me[12], me13 = me[13], me14 = me[14], me15 = me[15];
    auto _c1 = _plane0;_c1.auto _c2 = setFromComponents(me3 - me0, me7 - me4, me11 - me8, me15 - me12);_c2.normalize();_c2;_c1;
    auto _c3 = _plane1;_c3.auto _c4 = setFromComponents(me3 + me0, me7 + me4, me11 + me8, me15 + me12);_c4.normalize();_c4;_c3;
    auto _c5 = _plane2;_c5.auto _c6 = setFromComponents(me3 + me1, me7 + me5, me11 + me9, me15 + me13);_c6.normalize();_c6;_c5;
    auto _c7 = _plane3;_c7.auto _c8 = setFromComponents(me3 - me1, me7 - me5, me11 - me9, me15 - me13);_c8.normalize();_c8;_c7;
    auto _c9 = _plane4;_c9.auto _c10 = setFromComponents(me3 - me2, me7 - me6, me11 - me10, me15 - me14);_c10.normalize();_c10;_c9;
    auto _c11 = _plane5;_c11.auto _c12 = setFromComponents(me3 + me2, me7 + me6, me11 + me10, me15 + me14);_c12.normalize();_c12;_c11;
}

bool FrustumCls::containsVector3(Vector3 point) {
    if (_plane0->distanceToVector3(point) < 0.0) {
        return false;
    }
    if (_plane1->distanceToVector3(point) < 0.0) {
        return false;
    }
    if (_plane2->distanceToVector3(point) < 0.0) {
        return false;
    }
    if (_plane3->distanceToVector3(point) < 0.0) {
        return false;
    }
    if (_plane4->distanceToVector3(point) < 0.0) {
        return false;
    }
    if (_plane5->distanceToVector3(point) < 0.0) {
        return false;
    }
    return true;
}

bool FrustumCls::intersectsWithAabb3(Aabb3 aabb) {
    if (_intersectsWithAabb3CheckPlane(aabb, _plane0)) {
        return false;
    }
    if (_intersectsWithAabb3CheckPlane(aabb, _plane1)) {
        return false;
    }
    if (_intersectsWithAabb3CheckPlane(aabb, _plane2)) {
        return false;
    }
    if (_intersectsWithAabb3CheckPlane(aabb, _plane3)) {
        return false;
    }
    if (_intersectsWithAabb3CheckPlane(aabb, _plane4)) {
        return false;
    }
    if (_intersectsWithAabb3CheckPlane(aabb, _plane5)) {
        return false;
    }
    return true;
}

bool FrustumCls::intersectsWithSphere(Sphere sphere) {
    auto negativeRadius = -sphere->radius;
    auto center = sphere->center();
    if (_plane0->distanceToVector3(center) < negativeRadius) {
        return false;
    }
    if (_plane1->distanceToVector3(center) < negativeRadius) {
        return false;
    }
    if (_plane2->distanceToVector3(center) < negativeRadius) {
        return false;
    }
    if (_plane3->distanceToVector3(center) < negativeRadius) {
        return false;
    }
    if (_plane4->distanceToVector3(center) < negativeRadius) {
        return false;
    }
    if (_plane5->distanceToVector3(center) < negativeRadius) {
        return false;
    }
    return true;
}

void FrustumCls::calculateCorners(Vector3 corner0, Vector3 corner1, Vector3 corner2, Vector3 corner3, Vector3 corner4, Vector3 corner5, Vector3 corner6, Vector3 corner7) {
    PlaneCls->intersection(_plane0, _plane2, _plane4, corner0);
    PlaneCls->intersection(_plane0, _plane3, _plane4, corner1);
    PlaneCls->intersection(_plane0, _plane3, _plane5, corner2);
    PlaneCls->intersection(_plane0, _plane2, _plane5, corner3);
    PlaneCls->intersection(_plane1, _plane2, _plane4, corner4);
    PlaneCls->intersection(_plane1, _plane3, _plane4, corner5);
    PlaneCls->intersection(_plane1, _plane3, _plane5, corner6);
    PlaneCls->intersection(_plane1, _plane2, _plane5, corner7);
}

bool FrustumCls::_intersectsWithAabb3CheckPlane(Aabb3 aabb, Plane plane) {
    double outPx, outPy, outPz, outNx, outNy, outNz;
    if (plane->_normal->x < 0.0) {
        outPx = aabb->min()->x;
        outNx = aabb->max()->x;
    } else {
        outPx = aabb->max()->x;
        outNx = aabb->min()->x;
    }
    if (plane->_normal->y < 0.0) {
        outPy = aabb->min()->y;
        outNy = aabb->max()->y;
    } else {
        outPy = aabb->max()->y;
        outNy = aabb->min()->y;
    }
    if (plane->_normal->z < 0.0) {
        outPz = aabb->min()->z;
        outNz = aabb->max()->z;
    } else {
        outPz = aabb->max()->z;
        outNz = aabb->min()->z;
    }
    auto d1 = plane->_normal->x * outPx + plane->_normal->y * outPy + plane->_normal->z * outPz + plane->constant;
    auto d2 = plane->_normal->x * outNx + plane->_normal->y * outNy + plane->_normal->z * outNz + plane->constant;
    return  < 0 &&  < 0;
}
