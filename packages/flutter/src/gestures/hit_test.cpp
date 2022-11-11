#include "hit_test.hpp"
template<typename T>
String HitTestEntryCls<T>::toString() {
    return __s("${describeIdentity(this)}($target)");
}

template<typename T>
Matrix4 HitTestEntryCls<T>::transform() {
    return _transform;
}

Matrix4 _MatrixTransformPartCls::multiply(Matrix4 rhs) {
    return matrix->multiplied(rhs);
}

Matrix4 _OffsetTransformPartCls::multiply(Matrix4 rhs) {
    auto _c1 = rhs->clone();_c1.leftTranslate(offset->dx(), offset->dy());return _c1;
}

HitTestResultCls::HitTestResultCls() {
    {
        _path = makeList();
        _transforms = makeList(ArrayItem);
        _localTransforms = makeList();
    }
}

void HitTestResultCls::wrap(HitTestResult result)

Iterable<HitTestEntry<any>> HitTestResultCls::path() {
    return _path;
}

void HitTestResultCls::add(HitTestEntry<any> entry) {
    assert(entry->_transform == nullptr);
    entry->_transform = _lastTransform();
    _path->add(entry);
}

void HitTestResultCls::pushTransform(Matrix4 transform) {
    assert(transform != nullptr);
    assert(_debugVectorMoreOrLessEquals(transform->getRow(2), make<Vector4Cls>(0, 0, 1, 0)) && _debugVectorMoreOrLessEquals(transform->getColumn(2), make<Vector4Cls>(0, 0, 1, 0)), __s("The third row and third column of a transform matrix for pointer events must be Vector4(0, 0, 1, 0) to ensure that a transformed point is directly under the pointing device. Did you forget to run the paint matrix through PointerEvent.removePerspectiveTransform? The provided matrix is:\n$transform"));
    _localTransforms->add(make<_MatrixTransformPartCls>(transform));
}

void HitTestResultCls::pushOffset(Offset offset) {
    assert(offset != nullptr);
    _localTransforms->add(make<_OffsetTransformPartCls>(offset));
}

void HitTestResultCls::popTransform() {
    if (_localTransforms->isNotEmpty()) {
        _localTransforms->removeLast();
    } else {
        _transforms->removeLast();
    }
    assert(_transforms->isNotEmpty());
}

String HitTestResultCls::toString() {
    return __s("HitTestResult(${_path.isEmpty ? "<empty path>" : _path.join(", ")})");
}

void HitTestResultCls::_globalizeTransforms() {
    if (_localTransforms->isEmpty()) {
        return;
    }
    Matrix4 last = _transforms->last;
    for (_TransformPart part : _localTransforms) {
        last = part->multiply(last);
        _transforms->add(last);
    }
    _localTransforms->clear();
}

Matrix4 HitTestResultCls::_lastTransform() {
    _globalizeTransforms();
    assert(_localTransforms->isEmpty());
    return _transforms->last;
}

bool HitTestResultCls::_debugVectorMoreOrLessEquals(Vector4 a, Vector4 b, double epsilon) {
    bool result = true;
    assert([=] () {
        Vector4 difference = a - b;
        result = difference->storage()->every([=] (double component) {
            component->abs() < epsilon;
        });
        return true;
    }());
    return result;
}
