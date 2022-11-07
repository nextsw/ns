#ifndef HIT_TEST_H
#define HIT_TEST_H
#include <memory>
#include <ui.hpp>
#include <vector_math/vector_math_64.hpp>
#include "events.hpp"

#include <flutter/foundation.hpp>
#include <vector_math/vector_math_64.hpp>
#include "events.hpp"



class HitTestable {
public:

    void hitTest(Offset position, HitTestResult result);

private:

    void  _();

};

class HitTestDispatcher {
public:

    void dispatchEvent(PointerEvent event, HitTestResult result);

private:

    void  _();

};

class HitTestTarget {
public:

    void handleEvent(HitTestEntry<HitTestTarget> entry, PointerEvent event);

private:

    void  _();

};

class HitTestEntry<T extends HitTestTarget> {
public:
    T target;


     HitTestEntry(T target);

    String toString();

    Matrix4 transform();

private:
    Matrix4 _transform;


};

class _TransformPart {
public:

    Matrix4 multiply(Matrix4 rhs);

private:

     _TransformPart();

};

class _MatrixTransformPart : _TransformPart {
public:
    Matrix4 matrix;


    Matrix4 multiply(Matrix4 rhs);

private:

     _MatrixTransformPart(Matrix4 matrix);

};

class _OffsetTransformPart : _TransformPart {
public:
    Offset offset;


    Matrix4 multiply(Matrix4 rhs);

private:

     _OffsetTransformPart(Offset offset);

};

class HitTestResult {
public:

     HitTestResult();

    void  wrap(HitTestResult result);

    Iterable<HitTestEntry> path();

    void add(HitTestEntry entry);

    void pushTransform(Matrix4 transform);

    void pushOffset(Offset offset);

    void popTransform();

    String toString();

private:
    List<HitTestEntry> _path;

    List<Matrix4> _transforms;

    List<_TransformPart> _localTransforms;


    void _globalizeTransforms();

    Matrix4 _lastTransform();

    bool _debugVectorMoreOrLessEquals(Vector4 a, Vector4 b, double epsilon);

};

#endif