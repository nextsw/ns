#include "interactive_viewer.hpp"
InteractiveViewerCls::InteractiveViewerCls(bool alignPanAxis, EdgeInsets boundaryMargin, Widget child, Clip clipBehavior, bool constrained, Unknown key, double maxScale, double minScale, GestureScaleEndCallback onInteractionEnd, GestureScaleStartCallback onInteractionStart, GestureScaleUpdateCallback onInteractionUpdate, bool panEnabled, bool scaleEnabled, double scaleFactor, TransformationController transformationController) {
    {
        assert(alignPanAxis != nullptr);
        assert(child != nullptr);
        assert(constrained != nullptr);
        assert(minScale != nullptr);
        assert(minScale > 0);
        assert(minScale->isFinite);
        assert(maxScale != nullptr);
        assert(maxScale > 0);
        assert(!maxScale->isNaN);
        assert(maxScale >= minScale);
        assert(panEnabled != nullptr);
        assert(scaleEnabled != nullptr);
        assert((boundaryMargin->horizontal->isInfinite && boundaryMargin->vertical->isInfinite) || (boundaryMargin->top->isFinite && boundaryMargin->right->isFinite && boundaryMargin->bottom->isFinite && boundaryMargin->left->isFinite));
        builder = nullptr;
    }
}

void InteractiveViewerCls::builder(bool alignPanAxis, EdgeInsets boundaryMargin, InteractiveViewerWidgetBuilder builder, Clip clipBehavior, Unknown key, double maxScale, double minScale, GestureScaleEndCallback onInteractionEnd, GestureScaleStartCallback onInteractionStart, GestureScaleUpdateCallback onInteractionUpdate, bool panEnabled, bool scaleEnabled, double scaleFactor, TransformationController transformationController)

Vector3 InteractiveViewerCls::getNearestPointOnLine(Vector3 l1, Vector3 l2, Vector3 point) {
    double lengthSquared = math->pow(l2->x - l1->x, 2.0)->toDouble() + math->pow(l2->y - l1->y, 2.0)->toDouble();
    if (lengthSquared == 0) {
        return l1;
    }
    Vector3 l1P = point - l1;
    Vector3 l1L2 = l2 - l1;
    double fraction = clampDouble(l1P->dot(l1L2) / lengthSquared, 0.0, 1.0);
    return l1 + l1L2 * fraction;
}

Quad InteractiveViewerCls::getAxisAlignedBoundingBox(Quad quad) {
    double minX = math->min(quad->point0()->x, math->min(quad->point1()->x, math->min(quad->point2()->x, quad->point3()->x)));
    double minY = math->min(quad->point0()->y, math->min(quad->point1()->y, math->min(quad->point2()->y, quad->point3()->y)));
    double maxX = math->max(quad->point0()->x, math->max(quad->point1()->x, math->max(quad->point2()->x, quad->point3()->x)));
    double maxY = math->max(quad->point0()->y, math->max(quad->point1()->y, math->max(quad->point2()->y, quad->point3()->y)));
    return QuadCls->points(make<Vector3Cls>(minX, minY, 0), make<Vector3Cls>(maxX, minY, 0), make<Vector3Cls>(maxX, maxY, 0), make<Vector3Cls>(minX, maxY, 0));
}

bool InteractiveViewerCls::pointIsInside(Vector3 point, Quad quad) {
    Vector3 aM = point - quad->point0();
    Vector3 aB = quad->point1() - quad->point0();
    Vector3 aD = quad->point3() - quad->point0();
    double aMAB = aM->dot(aB);
    double aBAB = aB->dot(aB);
    double aMAD = aM->dot(aD);
    double aDAD = aD->dot(aD);
    return 0 <= aMAB && aMAB <= aBAB && 0 <= aMAD && aMAD <= aDAD;
}

Vector3 InteractiveViewerCls::getNearestPointInside(Vector3 point, Quad quad) {
    if (pointIsInside(point, quad)) {
        return point;
    }
    List<Vector3> closestPoints = makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem);
    double minDistance = double->infinity;
    Vector3 closestOverall;
    for (Vector3 closePoint : closestPoints) {
        double distance = math->sqrt(math->pow(point->x - closePoint->x, 2) + math->pow(point->y - closePoint->y, 2));
        if ( < minDistance) {
            minDistance = distance;
            closestOverall = closePoint;
        }
    }
    return closestOverall;
}

State<InteractiveViewer> InteractiveViewerCls::createState() {
    return make<_InteractiveViewerStateCls>();
}

void _InteractiveViewerStateCls::initState() {
    super->initState();
    _transformationController = widget->transformationController or make<TransformationControllerCls>();
    _transformationController!->addListener(_onTransformationControllerChange);
    _controller = make<AnimationControllerCls>(this);
}

void _InteractiveViewerStateCls::didUpdateWidget(InteractiveViewer oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (oldWidget->transformationController == nullptr) {
        if (widget->transformationController != nullptr) {
            _transformationController!->removeListener(_onTransformationControllerChange);
            _transformationController!->dispose();
            _transformationController = widget->transformationController;
            _transformationController!->addListener(_onTransformationControllerChange);
        }
    } else {
        if (widget->transformationController == nullptr) {
            _transformationController!->removeListener(_onTransformationControllerChange);
            _transformationController = make<TransformationControllerCls>();
            _transformationController!->addListener(_onTransformationControllerChange);
        } else         {
            if (widget->transformationController != oldWidget->transformationController) {
            _transformationController!->removeListener(_onTransformationControllerChange);
            _transformationController = widget->transformationController;
            _transformationController!->addListener(_onTransformationControllerChange);
        }
;
        }    }
}

void _InteractiveViewerStateCls::dispose() {
    _controller->dispose();
    _transformationController!->removeListener(_onTransformationControllerChange);
    if (widget->transformationController == nullptr) {
        _transformationController!->dispose();
    }
    super->dispose();
}

Widget _InteractiveViewerStateCls::build(BuildContext context) {
    Widget child;
    if (widget->child != nullptr) {
        child = make<_InteractiveViewerBuiltCls>(_childKey, widget->clipBehavior, widget->constrained, _transformationController!->value, widget->child!);
    } else {
        assert(widget->builder != nullptr);
        assert(!widget->constrained);
        child = make<LayoutBuilderCls>([=] (BuildContext context,BoxConstraints constraints) {
            Matrix4 matrix = _transformationController!->value;
            return make<_InteractiveViewerBuiltCls>(_childKey, widget->clipBehavior, widget->constrained, matrix, widget->builder!(context, _transformViewport(matrix, OffsetCls::zero & constraints->biggest)));
        });
    }
    return make<ListenerCls>(_parentKey, _receivedPointerSignal, make<GestureDetectorCls>(HitTestBehaviorCls::opaque, _onScaleEnd, _onScaleStart, _onScaleUpdate, child));
}

Rect _InteractiveViewerStateCls::_boundaryRect() {
    assert(_childKey->currentContext() != nullptr);
    assert(!widget->boundaryMargin->left->isNaN);
    assert(!widget->boundaryMargin->right->isNaN);
    assert(!widget->boundaryMargin->top->isNaN);
    assert(!widget->boundaryMargin->bottom->isNaN);
    RenderBox childRenderBox = as<RenderBox>(_childKey->currentContext()!->findRenderObject()!);
    Size childSize = childRenderBox->size();
    Rect boundaryRect = widget->boundaryMargin->inflateRect(OffsetCls::zero & childSize);
    assert(!boundaryRect->isEmpty(), __s("InteractiveViewer's child must have nonzero dimensions."));
    assert(boundaryRect->isFinite() || (boundaryRect->left->isInfinite && boundaryRect->top->isInfinite && boundaryRect->right->isInfinite && boundaryRect->bottom->isInfinite), __s("boundaryRect must either be infinite in all directions or finite in all directions."));
    return boundaryRect;
}

Rect _InteractiveViewerStateCls::_viewport() {
    assert(_parentKey->currentContext() != nullptr);
    RenderBox parentRenderBox = as<RenderBox>(_parentKey->currentContext()!->findRenderObject()!);
    return OffsetCls::zero & parentRenderBox->size();
}

Matrix4 _InteractiveViewerStateCls::_matrixTranslate(Matrix4 matrix, Offset translation) {
    if (translation == OffsetCls::zero) {
        return matrix->clone();
    }
    Offset alignedTranslation = widget->alignPanAxis && _panAxis != nullptr? _alignAxis(translation, _panAxis!) : translation;
    auto _c1 = matrix->clone();_c1.translate(alignedTranslation->dx(), alignedTranslation->dy());Matrix4 nextMatrix = _c1;
    Quad nextViewport = _transformViewport(nextMatrix, _viewport());
    if (_boundaryRect()->isInfinite()) {
        return nextMatrix;
    }
    Quad boundariesAabbQuad = _getAxisAlignedBoundingBoxWithRotation(_boundaryRect(), _currentRotation);
    Offset offendingDistance = _exceedsBy(boundariesAabbQuad, nextViewport);
    if (offendingDistance == OffsetCls::zero) {
        return nextMatrix;
    }
    Offset nextTotalTranslation = _getMatrixTranslation(nextMatrix);
    double currentScale = matrix->getMaxScaleOnAxis();
    Offset correctedTotalTranslation = make<OffsetCls>(nextTotalTranslation->dx() - offendingDistance->dx() * currentScale, nextTotalTranslation->dy() - offendingDistance->dy() * currentScale);
    auto _c2 = matrix->clone();_c2.setTranslation(make<Vector3Cls>(correctedTotalTranslation->dx(), correctedTotalTranslation->dy(), 0.0));Matrix4 correctedMatrix = _c2;
    Quad correctedViewport = _transformViewport(correctedMatrix, _viewport());
    Offset offendingCorrectedDistance = _exceedsBy(boundariesAabbQuad, correctedViewport);
    if (offendingCorrectedDistance == OffsetCls::zero) {
        return correctedMatrix;
    }
    if (offendingCorrectedDistance->dx() != 0.0 && offendingCorrectedDistance->dy() != 0.0) {
        return matrix->clone();
    }
    Offset unidirectionalCorrectedTotalTranslation = make<OffsetCls>(offendingCorrectedDistance->dx() == 0.0? correctedTotalTranslation->dx() : 0.0, offendingCorrectedDistance->dy() == 0.0? correctedTotalTranslation->dy() : 0.0);
    auto _c3 = matrix->clone();_c3.setTranslation(make<Vector3Cls>(unidirectionalCorrectedTotalTranslation->dx(), unidirectionalCorrectedTotalTranslation->dy(), 0.0));return _c3;
}

Matrix4 _InteractiveViewerStateCls::_matrixScale(Matrix4 matrix, double scale) {
    if (scale == 1.0) {
        return matrix->clone();
    }
    assert(scale != 0.0);
    double currentScale = _transformationController!->value->getMaxScaleOnAxis();
    double totalScale = math->max(currentScale * scale, math->max(_viewport()->width() / _boundaryRect()->width(), _viewport()->height() / _boundaryRect()->height()));
    double clampedTotalScale = clampDouble(totalScale, widget->minScale, widget->maxScale);
    double clampedScale = clampedTotalScale / currentScale;
    auto _c1 = matrix->clone();_c1.scale(clampedScale);return _c1;
}

Matrix4 _InteractiveViewerStateCls::_matrixRotate(Offset focalPoint, Matrix4 matrix, double rotation) {
    if (rotation == 0) {
        return matrix->clone();
    }
    Offset focalPointScene = _transformationController!->toScene(focalPoint);
    auto _c1 = matrix->clone();_c1.auto _c2 = translate(focalPointScene->dx(), focalPointScene->dy());_c2.auto _c3 = rotateZ(-rotation);_c3.translate(-focalPointScene->dx(), -focalPointScene->dy());_c3;_c2;return _c1;
}

bool _InteractiveViewerStateCls::_gestureIsSupported(_GestureType gestureType) {
    ;
}

_GestureType _InteractiveViewerStateCls::_getGestureType(ScaleUpdateDetails details) {
    double scale = !widget->scaleEnabled? 1.0 : details->scale;
    double rotation = !_rotateEnabled? 0.0 : details->rotation;
    if ((scale - 1)->abs() > rotation->abs()) {
        return _GestureTypeCls::scale;
    } else     {
        if (rotation != 0.0) {
        return _GestureTypeCls::rotate;
    } else {
        return _GestureTypeCls::pan;
    }
;
    }}

void _InteractiveViewerStateCls::_onScaleStart(ScaleStartDetails details) {
    widget->onInteractionStart?->call(details);
    if (_controller->isAnimating()) {
        _controller->stop();
        _controller->reset();
        _animation?->removeListener(_onAnimate);
        _animation = nullptr;
    }
    _gestureType = nullptr;
    _panAxis = nullptr;
    _scaleStart = _transformationController!->value->getMaxScaleOnAxis();
    _referenceFocalPoint = _transformationController!->toScene(details->localFocalPoint);
    _rotationStart = _currentRotation;
}

void _InteractiveViewerStateCls::_onScaleUpdate(ScaleUpdateDetails details) {
    double scale = _transformationController!->value->getMaxScaleOnAxis();
    Offset focalPointScene = _transformationController!->toScene(details->localFocalPoint);
    if (_gestureType == _GestureTypeCls::pan) {
        _gestureType = _getGestureType(details);
    } else {
        _gestureType = _getGestureType(details);
    }
    if (!_gestureIsSupported(_gestureType)) {
        widget->onInteractionUpdate?->call(details);
        return;
    }
    ;
    widget->onInteractionUpdate?->call(details);
}

void _InteractiveViewerStateCls::_onScaleEnd(ScaleEndDetails details) {
    widget->onInteractionEnd?->call(details);
    _scaleStart = nullptr;
    _rotationStart = nullptr;
    _referenceFocalPoint = nullptr;
    _animation?->removeListener(_onAnimate);
    _controller->reset();
    if (!_gestureIsSupported(_gestureType)) {
        _panAxis = nullptr;
        return;
    }
    if (_gestureType != _GestureTypeCls::pan || details->velocity->pixelsPerSecond->distance() < kMinFlingVelocity) {
        _panAxis = nullptr;
        return;
    }
    Vector3 translationVector = _transformationController!->value->getTranslation();
    Offset translation = make<OffsetCls>(translationVector->x, translationVector->y);
    FrictionSimulation frictionSimulationX = make<FrictionSimulationCls>(_kDrag, translation->dx(), details->velocity->pixelsPerSecond->dx());
    FrictionSimulation frictionSimulationY = make<FrictionSimulationCls>(_kDrag, translation->dy(), details->velocity->pixelsPerSecond->dy());
    double tFinal = _getFinalTime(details->velocity->pixelsPerSecond->distance(), _kDrag);
    _animation = <Offset>make<TweenCls>(translation, make<OffsetCls>(frictionSimulationX->finalX(), frictionSimulationY->finalX()))->animate(make<CurvedAnimationCls>(_controller, CurvesCls::decelerate));
    _controller->duration = make<DurationCls>((tFinal * 1000)->round());
    _animation!->addListener(_onAnimate);
    _controller->forward();
}

void _InteractiveViewerStateCls::_receivedPointerSignal(PointerSignalEvent event) {
    if (is<PointerScrollEvent>(event)) {
        if (as<PointerScrollEventCls>(event)->scrollDelta->dy() == 0.0) {
            return;
        }
        widget->onInteractionStart?->call(make<ScaleStartDetailsCls>(as<PointerScrollEventCls>(event)->position, as<PointerScrollEventCls>(event)->localPosition));
        double scaleChange = math->exp(-as<PointerScrollEventCls>(event)->scrollDelta->dy() / widget->scaleFactor);
        if (!_gestureIsSupported(_GestureTypeCls::scale)) {
            widget->onInteractionUpdate?->call(make<ScaleUpdateDetailsCls>(event->position, event->localPosition, scaleChange));
            widget->onInteractionEnd?->call(make<ScaleEndDetailsCls>());
            return;
        }
        Offset focalPointScene = _transformationController!->toScene(as<PointerScrollEventCls>(event)->localPosition);
        _transformationController!->value = _matrixScale(_transformationController!->value, scaleChange);
        Offset focalPointSceneScaled = _transformationController!->toScene(as<PointerScrollEventCls>(event)->localPosition);
        _transformationController!->value = _matrixTranslate(_transformationController!->value, focalPointSceneScaled - focalPointScene);
        widget->onInteractionUpdate?->call(make<ScaleUpdateDetailsCls>(as<PointerScrollEventCls>(event)->position, as<PointerScrollEventCls>(event)->localPosition, scaleChange));
        widget->onInteractionEnd?->call(make<ScaleEndDetailsCls>());
    }
}

void _InteractiveViewerStateCls::_onAnimate() {
    if (!_controller->isAnimating()) {
        _panAxis = nullptr;
        _animation?->removeListener(_onAnimate);
        _animation = nullptr;
        _controller->reset();
        return;
    }
    Vector3 translationVector = _transformationController!->value->getTranslation();
    Offset translation = make<OffsetCls>(translationVector->x, translationVector->y);
    Offset translationScene = _transformationController!->toScene(translation);
    Offset animationScene = _transformationController!->toScene(_animation!->value());
    Offset translationChangeScene = animationScene - translationScene;
    _transformationController!->value = _matrixTranslate(_transformationController!->value, translationChangeScene);
}

void _InteractiveViewerStateCls::_onTransformationControllerChange() {
    setState([=] () {
    });
}

Widget _InteractiveViewerBuiltCls::build(BuildContext context) {
    Widget child = make<TransformCls>(matrix, make<KeyedSubtreeCls>(childKey, this->child));
    if (!constrained) {
        child = make<OverflowBoxCls>(AlignmentCls::topLeft, 0.0, 0.0, double->infinity, double->infinity, child);
    }
    return make<ClipRectCls>(clipBehavior, child);
}

TransformationControllerCls::TransformationControllerCls(Matrix4 value) : ValueNotifier<Matrix4>(value or Matrix4Cls->identity()) {
}

Offset TransformationControllerCls::toScene(Offset viewportPoint) {
    Matrix4 inverseMatrix = Matrix4Cls->inverted(value);
    Vector3 untransformed = inverseMatrix->transform3(make<Vector3Cls>(viewportPoint->dx(), viewportPoint->dy(), 0));
    return make<OffsetCls>(untransformed->x, untransformed->y);
}

double _getFinalTime(double drag, double velocity) {
    double effectivelyMotionless = 10.0;
    return math->log(effectivelyMotionless / velocity) / math->log(drag / 100);
}

Offset _getMatrixTranslation(Matrix4 matrix) {
    Vector3 nextTranslation = matrix->getTranslation();
    return make<OffsetCls>(nextTranslation->x, nextTranslation->y);
}

Quad _transformViewport(Matrix4 matrix, Rect viewport) {
    auto _c1 = matrix->clone();_c1.invert();Matrix4 inverseMatrix = _c1;
    return QuadCls->points(inverseMatrix->transform3(make<Vector3Cls>(viewport->topLeft()->dx(), viewport->topLeft()->dy(), 0.0)), inverseMatrix->transform3(make<Vector3Cls>(viewport->topRight()->dx(), viewport->topRight()->dy(), 0.0)), inverseMatrix->transform3(make<Vector3Cls>(viewport->bottomRight()->dx(), viewport->bottomRight()->dy(), 0.0)), inverseMatrix->transform3(make<Vector3Cls>(viewport->bottomLeft()->dx(), viewport->bottomLeft()->dy(), 0.0)));
}

Quad _getAxisAlignedBoundingBoxWithRotation(Rect rect, double rotation) {
    auto _c1 = Matrix4Cls->identity();_c1.auto _c2 = translate(rect->size()->width() / 2, rect->size()->height() / 2);_c2.auto _c3 = rotateZ(rotation);_c3.translate(-rect->size()->width() / 2, -rect->size()->height() / 2);_c3;_c2;Matrix4 rotationMatrix = _c1;
    Quad boundariesRotated = QuadCls->points(rotationMatrix->transform3(make<Vector3Cls>(rect->left, rect->top, 0.0)), rotationMatrix->transform3(make<Vector3Cls>(rect->right, rect->top, 0.0)), rotationMatrix->transform3(make<Vector3Cls>(rect->right, rect->bottom, 0.0)), rotationMatrix->transform3(make<Vector3Cls>(rect->left, rect->bottom, 0.0)));
    return InteractiveViewerCls->getAxisAlignedBoundingBox(boundariesRotated);
}

Offset _exceedsBy(Quad boundary, Quad viewport) {
    List<Vector3> viewportPoints = makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem);
    Offset largestExcess = OffsetCls::zero;
    for (Vector3 point : viewportPoints) {
        Vector3 pointInside = InteractiveViewerCls->getNearestPointInside(point, boundary);
        Offset excess = make<OffsetCls>(pointInside->x - point->x, pointInside->y - point->y);
        if (excess->dx()->abs() > largestExcess->dx()->abs()) {
            largestExcess = make<OffsetCls>(excess->dx(), largestExcess->dy());
        }
        if (excess->dy()->abs() > largestExcess->dy()->abs()) {
            largestExcess = make<OffsetCls>(largestExcess->dx(), excess->dy());
        }
    }
    return _round(largestExcess);
}

Offset _round(Offset offset) {
    return make<OffsetCls>(double->parse(offset->dx()->toStringAsFixed(9)), double->parse(offset->dy()->toStringAsFixed(9)));
}

Offset _alignAxis(Axis axis, Offset offset) {
    ;
}

Axis _getPanAxis(Offset point1, Offset point2) {
    if (point1 == point2) {
        return nullptr;
    }
    double x = point2->dx() - point1->dx();
    double y = point2->dy() - point1->dy();
    return x->abs() > y->abs()? AxisCls::horizontal : AxisCls::vertical;
}
