#ifndef PACKAGES_FLUTTER_SRC_GESTURES_HIT_TEST
#define PACKAGES_FLUTTER_SRC_GESTURES_HIT_TEST
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "events.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "events.hpp"


class HitTestableCls : public ObjectCls {
public:

    virtual void hitTest(Offset position, HitTestResult result);
private:

    virtual void  _();
};
using HitTestable = std::shared_ptr<HitTestableCls>;

class HitTestDispatcherCls : public ObjectCls {
public:

    virtual void dispatchEvent(PointerEvent event, HitTestResult result);
private:

    virtual void  _();
};
using HitTestDispatcher = std::shared_ptr<HitTestDispatcherCls>;

class HitTestTargetCls : public ObjectCls {
public:

    virtual void handleEvent(HitTestEntry<HitTestTarget> entry, PointerEvent event);
private:

    virtual void  _();
};
using HitTestTarget = std::shared_ptr<HitTestTargetCls>;

template<typename T> class HitTestEntryCls : public ObjectCls {
public:
    T target;


     HitTestEntryCls(T target);
    virtual String toString();

    virtual Matrix4 transform();

private:
    Matrix4 _transform;


};
template<typename T> using HitTestEntry = std::shared_ptr<HitTestEntryCls<T>>;

class _TransformPartCls : public ObjectCls {
public:

    virtual Matrix4 multiply(Matrix4 rhs);
private:

     _TransformPartCls();
};
using _TransformPart = std::shared_ptr<_TransformPartCls>;

class _MatrixTransformPartCls : public _TransformPartCls {
public:
    Matrix4 matrix;


    virtual Matrix4 multiply(Matrix4 rhs);

private:

     _MatrixTransformPartCls(Matrix4 matrix);
};
using _MatrixTransformPart = std::shared_ptr<_MatrixTransformPartCls>;

class _OffsetTransformPartCls : public _TransformPartCls {
public:
    Offset offset;


    virtual Matrix4 multiply(Matrix4 rhs);

private:

     _OffsetTransformPartCls(Offset offset);
};
using _OffsetTransformPart = std::shared_ptr<_OffsetTransformPartCls>;

class HitTestResultCls : public ObjectCls {
public:

     HitTestResultCls();

    virtual void  wrap(HitTestResult result);

    virtual Iterable<HitTestEntry> path();

    virtual void add(HitTestEntry entry);

    virtual void pushTransform(Matrix4 transform);

    virtual void pushOffset(Offset offset);

    virtual void popTransform();

    virtual String toString();

private:
    List<HitTestEntry> _path;

    List<Matrix4> _transforms;

    List<_TransformPart> _localTransforms;


    virtual void _globalizeTransforms();

    virtual Matrix4 _lastTransform();

    virtual bool _debugVectorMoreOrLessEquals(Vector4 a, Vector4 b, double epsilon);

};
using HitTestResult = std::shared_ptr<HitTestResultCls>;


#endif