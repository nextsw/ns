#include "hit_test.hpp"
String HitTestEntry::toString() {
    return "${describeIdentity(this)}($target)";
}

Matrix4 HitTestEntry::transform() {
    return _transform;
}

Matrix4 _MatrixTransformPart::multiply(Matrix4 rhs) {
    return matrix.multiplied(rhs);
}

Matrix4 _OffsetTransformPart::multiply(Matrix4 rhs) {
    return ;
}

HitTestResult::HitTestResult() {
    {
        _path = ;
        _transforms = ;
        _localTransforms = ;
    }
}

void HitTestResult::wrap(HitTestResult result)

Iterable<HitTestEntry> HitTestResult::path() {
    return _path;
}

void HitTestResult::add(HitTestEntry entry) {
    assert(entry._transform == nullptr);
    entry._transform = _lastTransform;
    _path.add(entry);
}

void HitTestResult::pushTransform(Matrix4 transform) {
    assert(transform != nullptr);
    assert(_debugVectorMoreOrLessEquals(transform.getRow(2), Vector4(0, 0, 1, 0)) && _debugVectorMoreOrLessEquals(transform.getColumn(2), Vector4(0, 0, 1, 0)), "The third row and third column of a transform matrix for pointer events must be Vector4(0, 0, 1, 0) to ensure that a transformed point is directly under the pointing device. Did you forget to run the paint matrix through PointerEvent.removePerspectiveTransform? The provided matrix is:\n$transform");
    _localTransforms.add(_MatrixTransformPart(transform));
}

void HitTestResult::pushOffset(Offset offset) {
    assert(offset != nullptr);
    _localTransforms.add(_OffsetTransformPart(offset));
}

void HitTestResult::popTransform() {
    if (_localTransforms.isNotEmpty) {
        _localTransforms.removeLast();
    } else {
        _transforms.removeLast();
    }
    assert(_transforms.isNotEmpty);
}

String HitTestResult::toString() {
    return "HitTestResult(${_path.isEmpty ? "<empty path>" : _path.join(", ")})";
}

void HitTestResult::_globalizeTransforms() {
    if (_localTransforms.isEmpty) {
        return;
    }
    Matrix4 last = _transforms.last;
    for (_TransformPart part : _localTransforms) {
        last = part.multiply(last);
        _transforms.add(last);
    }
    _localTransforms.clear();
}

Matrix4 HitTestResult::_lastTransform() {
    _globalizeTransforms();
    assert(_localTransforms.isEmpty);
    return _transforms.last;
}

bool HitTestResult::_debugVectorMoreOrLessEquals(Vector4 a, Vector4 b, double epsilon) {
    bool result = true;
    assert(());
    return result;
}
