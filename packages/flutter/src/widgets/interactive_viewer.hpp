#ifndef INTERACTIVE_VIEWER_H
#define INTERACTIVE_VIEWER_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/physics.hpp>
#include <vector_math/vector_math_64.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "gesture_detector.hpp"
#include "layout_builder.hpp"
#include "ticker_provider.hpp"



class InteractiveViewer : StatefulWidget {
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


     InteractiveViewer(bool alignPanAxis, EdgeInsets boundaryMargin, Widget child, Clip clipBehavior, bool constrained, Unknown, double maxScale, double minScale, GestureScaleEndCallback onInteractionEnd, GestureScaleStartCallback onInteractionStart, GestureScaleUpdateCallback onInteractionUpdate, bool panEnabled, bool scaleEnabled, double scaleFactor, TransformationController transformationController);

    void  builder(bool alignPanAxis, EdgeInsets boundaryMargin, InteractiveViewerWidgetBuilder builder, Clip clipBehavior, Unknown, double maxScale, double minScale, GestureScaleEndCallback onInteractionEnd, GestureScaleStartCallback onInteractionStart, GestureScaleUpdateCallback onInteractionUpdate, bool panEnabled, bool scaleEnabled, double scaleFactor, TransformationController transformationController);

    static Vector3 getNearestPointOnLine(Vector3 l1, Vector3 l2, Vector3 point);

    static Quad getAxisAlignedBoundingBox(Quad quad);

    static bool pointIsInside(Vector3 point, Quad quad);

    static Vector3 getNearestPointInside(Vector3 point, Quad quad);

    State<InteractiveViewer> createState();

private:

};

class _InteractiveViewerState : State<InteractiveViewer> {
public:

    void initState();

    void didUpdateWidget(InteractiveViewer oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:
    TransformationController _transformationController;

    GlobalKey _childKey;

    GlobalKey _parentKey;

    Animation<Offset> _animation;

    AnimationController _controller;

    Axis _panAxis;

    Offset _referenceFocalPoint;

    double _scaleStart;

    double _rotationStart;

    double _currentRotation;

    _GestureType _gestureType;

    bool _rotateEnabled;

    static const double _kDrag;


    Rect _boundaryRect();

    Rect _viewport();

    Matrix4 _matrixTranslate(Matrix4 matrix, Offset translation);

    Matrix4 _matrixScale(Matrix4 matrix, double scale);

    Matrix4 _matrixRotate(Offset focalPoint, Matrix4 matrix, double rotation);

    bool _gestureIsSupported(_GestureType gestureType);

    _GestureType _getGestureType(ScaleUpdateDetails details);

    void _onScaleStart(ScaleStartDetails details);

    void _onScaleUpdate(ScaleUpdateDetails details);

    void _onScaleEnd(ScaleEndDetails details);

    void _receivedPointerSignal(PointerSignalEvent event);

    void _onAnimate();

    void _onTransformationControllerChange();

};

class _InteractiveViewerBuilt : StatelessWidget {
public:
    Widget child;

    GlobalKey childKey;

    Clip clipBehavior;

    bool constrained;

    Matrix4 matrix;


    Widget build(BuildContext context);

private:

     _InteractiveViewerBuilt(Widget child, GlobalKey childKey, Clip clipBehavior, bool constrained, Matrix4 matrix);

};

class TransformationController : ValueNotifier<Matrix4> {
public:

     TransformationController(Matrix4 value);

    Offset toScene(Offset viewportPoint);

private:

};

enum _GestureType{
    pan,
    scale,
    rotate,
} // end _GestureType
double _getFinalTime(double drag, double velocity);

Offset _getMatrixTranslation(Matrix4 matrix);

Quad _transformViewport(Matrix4 matrix, Rect viewport);

Quad _getAxisAlignedBoundingBoxWithRotation(Rect rect, double rotation);

Offset _exceedsBy(Quad boundary, Quad viewport);

Offset _round(Offset offset);

Offset _alignAxis(Axis axis, Offset offset);

Axis _getPanAxis(Offset point1, Offset point2);


#endif