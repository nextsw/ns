#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_INTERACTIVE_VIEWER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_INTERACTIVE_VIEWER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "gesture_detector.hpp"
#include "layout_builder.hpp"
#include "ticker_provider.hpp"


class InteractiveViewerCls : public StatefulWidgetCls {
public:
    Clip clipBehavior;

    bool alignPanAxis;

    EdgeInsets boundaryMargin;

    InteractiveViewerWidgetBuilder builder;

    Widget child;

    bool constrained;

    bool panEnabled;

    bool scaleEnabled;

    double scaleFactor;

    double maxScale;

    double minScale;

    GestureScaleEndCallback onInteractionEnd;

    GestureScaleStartCallback onInteractionStart;

    GestureScaleUpdateCallback onInteractionUpdate;

    TransformationController transformationController;


     InteractiveViewerCls(bool alignPanAxis, EdgeInsets boundaryMargin, Widget child, Clip clipBehavior, bool constrained, Key key, double maxScale, double minScale, GestureScaleEndCallback onInteractionEnd, GestureScaleStartCallback onInteractionStart, GestureScaleUpdateCallback onInteractionUpdate, bool panEnabled, bool scaleEnabled, double scaleFactor, TransformationController transformationController);

    virtual void  builder(Unknown alignPanAxis, Unknown boundaryMargin, InteractiveViewerWidgetBuilder builder, Unknown clipBehavior, Unknown key, Unknown maxScale, Unknown minScale, Unknown onInteractionEnd, Unknown onInteractionStart, Unknown onInteractionUpdate, Unknown panEnabled, Unknown scaleEnabled, Unknown scaleFactor, Unknown transformationController);

    static Vector3 getNearestPointOnLine(Vector3 point, Vector3 l1, Vector3 l2);

    static Quad getAxisAlignedBoundingBox(Quad quad);

    static bool pointIsInside(Vector3 point, Quad quad);

    static Vector3 getNearestPointInside(Vector3 point, Quad quad);

    virtual State<InteractiveViewer> createState();

private:

};
using InteractiveViewer = std::shared_ptr<InteractiveViewerCls>;

class _InteractiveViewerStateCls : public StateCls<InteractiveViewer> {
public:

    virtual void initState();

    virtual void didUpdateWidget(InteractiveViewer oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    TransformationController _transformationController;

    GlobalKey<any> _childKey;

    GlobalKey<any> _parentKey;

    Animation<Offset> _animation;

    AnimationController _controller;

    Axis _panAxis;

    Offset _referenceFocalPoint;

    double _scaleStart;

    double _rotationStart;

    double _currentRotation;

    _GestureType _gestureType;

    bool _rotateEnabled;

    static double _kDrag;


    virtual Rect _boundaryRect();

    virtual Rect _viewport();

    virtual Matrix4 _matrixTranslate(Matrix4 matrix, Offset translation);

    virtual Matrix4 _matrixScale(Matrix4 matrix, double scale);

    virtual Matrix4 _matrixRotate(Matrix4 matrix, double rotation, Offset focalPoint);

    virtual bool _gestureIsSupported(_GestureType gestureType);

    virtual _GestureType _getGestureType(ScaleUpdateDetails details);

    virtual void _onScaleStart(ScaleStartDetails details);

    virtual void _onScaleUpdate(ScaleUpdateDetails details);

    virtual void _onScaleEnd(ScaleEndDetails details);

    virtual void _receivedPointerSignal(PointerSignalEvent event);

    virtual void _onAnimate();

    virtual void _onTransformationControllerChange();

};
using _InteractiveViewerState = std::shared_ptr<_InteractiveViewerStateCls>;

class _InteractiveViewerBuiltCls : public StatelessWidgetCls {
public:
    Widget child;

    GlobalKey<any> childKey;

    Clip clipBehavior;

    bool constrained;

    Matrix4 matrix;


    virtual Widget build(BuildContext context);

private:

     _InteractiveViewerBuiltCls(Widget child, GlobalKey<any> childKey, Clip clipBehavior, bool constrained, Matrix4 matrix);
};
using _InteractiveViewerBuilt = std::shared_ptr<_InteractiveViewerBuiltCls>;

class TransformationControllerCls : public ValueNotifierCls<Matrix4> {
public:

     TransformationControllerCls(Matrix4 value);

    virtual Offset toScene(Offset viewportPoint);

private:

};
using TransformationController = std::shared_ptr<TransformationControllerCls>;

enum _GestureType{
    pan,
    scale,
    rotate,
} // end _GestureType
double _getFinalTime(double velocity, double drag);

Offset _getMatrixTranslation(Matrix4 matrix);

Quad _transformViewport(Matrix4 matrix, Rect viewport);

Quad _getAxisAlignedBoundingBoxWithRotation(Rect rect, double rotation);

Offset _exceedsBy(Quad boundary, Quad viewport);

Offset _round(Offset offset);

Offset _alignAxis(Offset offset, Axis axis);

Axis _getPanAxis(Offset point1, Offset point2);



#endif