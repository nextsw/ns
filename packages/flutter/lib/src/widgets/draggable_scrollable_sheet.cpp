#include "draggable_scrollable_sheet.hpp"
double DraggableScrollableControllerCls::size() {
    _assertAttached();
    return _attachedController!->extent->currentSize;
}

double DraggableScrollableControllerCls::pixels() {
    _assertAttached();
    return _attachedController!->extent->currentPixels;
}

double DraggableScrollableControllerCls::sizeToPixels(double size) {
    _assertAttached();
    return _attachedController!->extent->sizeToPixels(size);
}

bool DraggableScrollableControllerCls::isAttached() {
    return _attachedController != nullptr && _attachedController!->hasClients;
}

double DraggableScrollableControllerCls::pixelsToSize(double pixels) {
    _assertAttached();
    return _attachedController!->extent->pixelsToSize(pixels);
}

Future<void> DraggableScrollableControllerCls::animateTo(Curve curve, Duration duration, double size) {
    _assertAttached();
    assert(size >= 0 && size <= 1);
    assert(duration != DurationCls::zero);
    AnimationController animationController = AnimationControllerCls->unbounded(_attachedController!->position->context->vsync, _attachedController!->extent->currentSize);
    _animationControllers->add(animationController);
    _attachedController!->position->goIdle();
    _attachedController!->extent->hasDragged = false;
    _attachedController!->extent->startActivity([=] () {
        if (animationController->isAnimating) {
            animationController->stop();
        }
    });
    animationController->addListener([=] () {
        _attachedController!->extent->updateSize(animationController->value, _attachedController!->position->context->notificationContext!);
        if (animationController->value > _attachedController!->extent->maxSize || animationController->value < _attachedController!->extent->minSize) {
            animationController->stop(false);
        }
    });
    await await animationController->animateTo(sizeduration, curve);
}

void DraggableScrollableControllerCls::jumpTo(double size) {
    _assertAttached();
    assert(size >= 0 && size <= 1);
    _attachedController!->extent->startActivity([=] () {
    });
    _attachedController!->position->goIdle();
    _attachedController!->extent->hasDragged = false;
    _attachedController!->extent->updateSize(size, _attachedController!->position->context->notificationContext!);
}

void DraggableScrollableControllerCls::reset() {
    _assertAttached();
    _attachedController!->reset();
}

void DraggableScrollableControllerCls::_assertAttached() {
    assert(isAttached, "DraggableScrollableController is not attached to a sheet. A DraggableScrollableController must be used in a DraggableScrollableSheet before any of its methods are called.");
}

void DraggableScrollableControllerCls::_attach(_DraggableScrollableSheetScrollController scrollController) {
    assert(_attachedController == nullptr, "Draggable scrollable controller is already attached to a sheet.");
    _attachedController = scrollController;
    _attachedController!->extent->_currentSize->addListener(notifyListeners);
    _attachedController!->onPositionDetached = _disposeAnimationControllers;
}

void DraggableScrollableControllerCls::_onExtentReplaced(_DraggableSheetExtent previousExtent) {
    _attachedController!->extent->_currentSize->addListener(notifyListeners);
    if (previousExtent->currentSize != _attachedController!->extent->currentSize) {
        notifyListeners();
    }
}

void DraggableScrollableControllerCls::_detach() {
    _attachedController?->extent->_currentSize->removeListener(notifyListeners);
    _attachedController = nullptr;
}

void DraggableScrollableControllerCls::_disposeAnimationControllers() {
    for (AnimationController animationController : _animationControllers) {
        animationController->dispose();
    }
    _animationControllers->clear();
}

DraggableScrollableSheetCls::DraggableScrollableSheetCls(ScrollableWidgetBuilder builder, DraggableScrollableController controller, bool expand, double initialChildSize, Unknown key, double maxChildSize, double minChildSize, bool snap, List<double> snapSizes) {
    {
        assert(initialChildSize != nullptr);
        assert(minChildSize != nullptr);
        assert(maxChildSize != nullptr);
        assert(minChildSize >= 0.0);
        assert(maxChildSize <= 1.0);
        assert(minChildSize <= initialChildSize);
        assert(initialChildSize <= maxChildSize);
        assert(expand != nullptr);
        assert(builder != nullptr);
    }
}

State<DraggableScrollableSheet> DraggableScrollableSheetCls::createState() {
    return make<_DraggableScrollableSheetStateCls>();
}

DraggableScrollableNotificationCls::DraggableScrollableNotificationCls(BuildContext context, double extent, double initialExtent, double maxExtent, double minExtent) {
    {
        assert(extent != nullptr);
        assert(initialExtent != nullptr);
        assert(minExtent != nullptr);
        assert(maxExtent != nullptr);
        assert(0.0 <= minExtent);
        assert(maxExtent <= 1.0);
        assert(minExtent <= extent);
        assert(minExtent <= initialExtent);
        assert(extent <= maxExtent);
        assert(initialExtent <= maxExtent);
        assert(context != nullptr);
    }
}

void DraggableScrollableNotificationCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    description->add("minExtent: $minExtent, extent: $extent, maxExtent: $maxExtent, initialExtent: $initialExtent");
}

bool _DraggableSheetExtentCls::isAtMin() {
    return minSize >= _currentSize->value;
}

bool _DraggableSheetExtentCls::isAtMax() {
    return maxSize <= _currentSize->value;
}

double _DraggableSheetExtentCls::currentSize() {
    return _currentSize->value;
}

double _DraggableSheetExtentCls::currentPixels() {
    return sizeToPixels(_currentSize->value);
}

double _DraggableSheetExtentCls::additionalMinSize() {
    return isAtMin? 0.0 : 1.0;
}

double _DraggableSheetExtentCls::additionalMaxSize() {
    return isAtMax? 0.0 : 1.0;
}

List<double> _DraggableSheetExtentCls::pixelSnapSizes() {
    return snapSizes->map(sizeToPixels)->toList();
}

void _DraggableSheetExtentCls::startActivity(VoidCallback onCanceled) {
    _cancelActivity?->call();
    _cancelActivity = onCanceled;
}

void _DraggableSheetExtentCls::addPixelDelta(BuildContext context, double delta) {
    _cancelActivity?->call();
    _cancelActivity = nullptr;
    hasDragged = true;
    if (availablePixels == 0) {
        return;
    }
    updateSize(currentSize + pixelsToSize(delta), context);
}

void _DraggableSheetExtentCls::updateSize(BuildContext context, double newSize) {
    assert(newSize != nullptr);
    _currentSize->value = clampDouble(newSize, minSize, maxSize);
    make<DraggableScrollableNotificationCls>(minSize, maxSize, currentSize, initialSize, context)->dispatch(context);
}

double _DraggableSheetExtentCls::pixelsToSize(double pixels) {
    return pixels / availablePixels * maxSize;
}

double _DraggableSheetExtentCls::sizeToPixels(double size) {
    return size / maxSize * availablePixels;
}

void _DraggableSheetExtentCls::dispose() {
    _currentSize->removeListener(onSizeChanged);
}

_DraggableSheetExtent _DraggableSheetExtentCls::copyWith(double initialSize, double maxSize, double minSize, VoidCallback onSizeChanged, bool snap, List<double> snapSizes) {
    return make<_DraggableSheetExtentCls>(minSize, maxSize, snap, snapSizes, initialSize, onSizeChanged, <double>make<ValueNotifierCls>(hasDragged? clampDouble(_currentSize->value, minSize, maxSize) : initialSize), hasDragged);
}

_DraggableSheetExtentCls::_DraggableSheetExtentCls(ValueNotifier<double> currentSize, bool hasDragged, double initialSize, double maxSize, double minSize, VoidCallback onSizeChanged, bool snap, List<double> snapSizes) {
    {
        assert(minSize != nullptr);
        assert(maxSize != nullptr);
        assert(initialSize != nullptr);
        assert(minSize >= 0);
        assert(maxSize <= 1);
        assert(minSize <= initialSize);
        assert(initialSize <= maxSize);
            auto _c1 = (currentSize ?? <double>make<ValueNotifierCls>(initialSize));    _c1.addListener(onSizeChanged);_currentSize = _c1;
        availablePixels = double->infinity;
        hasDragged = hasDragged ?? false;
    }
}

void _DraggableScrollableSheetStateCls::initState() {
    super->initState();
    _extent = make<_DraggableSheetExtentCls>(widget->minChildSize, widget->maxChildSize, widget->snap, _impliedSnapSizes(), widget->initialChildSize, _setExtent);
    _scrollController = make<_DraggableScrollableSheetScrollControllerCls>(_extent);
    widget->controller?->_attach(_scrollController);
}

void _DraggableScrollableSheetStateCls::didUpdateWidget(DraggableScrollableSheet oldWidget) {
    super->didUpdateWidget(oldWidget);
    _replaceExtent(oldWidget);
}

void _DraggableScrollableSheetStateCls::didChangeDependencies() {
    super->didChangeDependencies();
    if (_InheritedResetNotifierCls->shouldReset(context)) {
        _scrollController->reset();
    }
}

Widget _DraggableScrollableSheetStateCls::build(BuildContext context) {
    return make<LayoutBuilderCls>([=] (BuildContext context,BoxConstraints constraints) {
        _extent->availablePixels = widget->maxChildSize * constraints->biggest->height;
        Widget sheet = make<FractionallySizedBoxCls>(_extent->currentSize, AlignmentCls::bottomCenter, widget->builder(context, _scrollController));
        return widget->expand? SizedBoxCls->expand(sheet) : sheet;
    });
}

void _DraggableScrollableSheetStateCls::dispose() {
    widget->controller?->_detach();
    _scrollController->dispose();
    _extent->dispose();
    super->dispose();
}

List<double> _DraggableScrollableSheetStateCls::_impliedSnapSizes() {
    for (;  < (widget->snapSizes?->length ?? 0); index = 1) {
        double snapSize = widget->snapSizes![index];
        assert(snapSize >= widget->minChildSize && snapSize <= widget->maxChildSize, "${_snapSizeErrorMessage(index)}\nSnap sizes must be between `minChildSize` and `maxChildSize`. ");
        assert(index == 0 || snapSize > widget->snapSizes![index - 1], "${_snapSizeErrorMessage(index)}\nSnap sizes must be in ascending order. ");
    }
    if (widget->snapSizes == nullptr || widget->snapSizes!->isEmpty) {
        return makeList(ArrayItem, ArrayItem);
    }
    List<double> list1 = make<ListCls<>>();if (widget->snapSizes!->first != widget->minChildSize) {    list1.add(ArrayItem);}for (auto _x1 : widget->snapSizes!) {{    list1.add(_x1);}if (widget->snapSizes!->last != widget->maxChildSize) {    list1.add(ArrayItem);}return list1;
}

void _DraggableScrollableSheetStateCls::_setExtent() {
    setState([=] () {
    });
}

void _DraggableScrollableSheetStateCls::_replaceExtent(DraggableScrollableSheet oldWidget) {
    _DraggableSheetExtent previousExtent = _extent;
    _extent->dispose();
    _extent = _extent->copyWith(widget->minChildSize, widget->maxChildSize, widget->snap, _impliedSnapSizes(), widget->initialChildSize, _setExtent);
    _scrollController->extent = _extent;
    widget->controller?->_onExtentReplaced(previousExtent);
    if (widget->snap && (widget->snap != oldWidget->snap || widget->snapSizes != oldWidget->snapSizes) && _scrollController->hasClients) {
        WidgetsBindingCls::instance->addPostFrameCallback([=] (Duration timeStamp) {
            for (;  < _scrollController->positions->length; index++) {
                _DraggableScrollableSheetScrollPosition position = ((_DraggableScrollableSheetScrollPosition)_scrollController->positions->elementAt(index));
                position->goBallistic(0);
            }
        });
    }
}

String _DraggableScrollableSheetStateCls::_snapSizeErrorMessage(int invalidIndex) {
    List<String> snapSizesWithIndicator = widget->snapSizes!->asMap()->keys->map([=] (int index) {
    String snapSizeString = widget->snapSizes![index]->toString();
    if (index == invalidIndex) {
        return ">>> $snapSizeString <<<";
    }
    return snapSizeString;
})->toList();
    return "Invalid snapSize '${widget.snapSizes![invalidIndex]}' at index $invalidIndex of:\n  $snapSizesWithIndicator";
}

_DraggableScrollableSheetScrollPosition _DraggableScrollableSheetScrollControllerCls::createScrollPosition(ScrollContext context, ScrollPosition oldPosition, ScrollPhysics physics) {
    return make<_DraggableScrollableSheetScrollPositionCls>(physics, context, oldPosition, [=] ()     {
        extent;
    });
}

void _DraggableScrollableSheetScrollControllerCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    description->add("extent: $extent");
}

_DraggableScrollableSheetScrollPosition _DraggableScrollableSheetScrollControllerCls::position() {
    return ((_DraggableScrollableSheetScrollPosition)super->position);
}

void _DraggableScrollableSheetScrollControllerCls::reset() {
    extent->_cancelActivity?->call();
    extent->hasDragged = false;
    if (offset != 0.0) {
        animateTo(0.0make<DurationCls>(1), CurvesCls::linear);
    }
    extent->updateSize(extent->initialSize, position->context->notificationContext!);
}

void _DraggableScrollableSheetScrollControllerCls::detach(ScrollPosition position) {
    onPositionDetached?->call();
    super->detach(position);
}

_DraggableScrollableSheetScrollControllerCls::_DraggableScrollableSheetScrollControllerCls(_DraggableSheetExtent extent) {
    {
        assert(extent != nullptr);
    }
}

bool _DraggableScrollableSheetScrollPositionCls::listShouldScroll() {
    return pixels > 0.0;
}

_DraggableSheetExtent _DraggableScrollableSheetScrollPositionCls::extent() {
    return getExtent();
}

void _DraggableScrollableSheetScrollPositionCls::absorb(ScrollPosition other) {
    super->absorb(other);
    assert(_dragCancelCallback == nullptr);
    if (other is! _DraggableScrollableSheetScrollPosition) {
        return;
    }
    if (other->_dragCancelCallback != nullptr) {
        _dragCancelCallback = other->_dragCancelCallback;
        other->_dragCancelCallback = nullptr;
    }
}

void _DraggableScrollableSheetScrollPositionCls::beginActivity(ScrollActivity newActivity) {
    for (AnimationController ballisticController : _ballisticControllers) {
        ballisticController->stop();
    }
    super->beginActivity(newActivity);
}

bool _DraggableScrollableSheetScrollPositionCls::applyContentDimensions(double maxScrollSize, double minScrollSize) {
    return super->applyContentDimensions(minScrollSize - extent->additionalMinSize, maxScrollSize + extent->additionalMaxSize);
}

void _DraggableScrollableSheetScrollPositionCls::applyUserOffset(double delta) {
    if (!listShouldScroll && (!(extent->isAtMin || extent->isAtMax) || (extent->isAtMin &&  < 0) || (extent->isAtMax && delta > 0))) {
        extent->addPixelDelta(-delta, context->notificationContext!);
    } else {
        super->applyUserOffset(delta);
    }
}

void _DraggableScrollableSheetScrollPositionCls::dispose() {
    for (AnimationController ballisticController : _ballisticControllers) {
        ballisticController->dispose();
    }
    _ballisticControllers->clear();
    super->dispose();
}

void _DraggableScrollableSheetScrollPositionCls::goBallistic(double velocity) {
    if ((velocity == 0.0 && !_shouldSnap) || ( < 0.0 && listShouldScroll) || (velocity > 0.0 && extent->isAtMax)) {
        super->goBallistic(velocity);
        return;
    }
    _dragCancelCallback?->call();
    _dragCancelCallback = nullptr;
    Simulation simulation;
    if (extent->snap) {
        simulation = make<_SnappingSimulationCls>(extent->currentPixels, velocity, extent->pixelSnapSizes, physics->tolerance);
    } else {
        simulation = make<ClampingScrollSimulationCls>(extent->currentPixels, velocity, physics->tolerance);
    }
    AnimationController ballisticController = AnimationControllerCls->unbounded(objectRuntimeType(this, "_DraggableScrollableSheetPosition"), context->vsync);
    _ballisticControllers->add(ballisticController);
    double lastPosition = extent->currentPixels;
    InlineMethod;
        });_c2;            }        auto _c1 = ballisticController;        _c1.auto _c2 = addListener(tick);        _c2.animateWith(simulation)->whenCompleteOrCancel([=] () {                if (_ballisticControllers->contains(ballisticController)) {                    _ballisticControllers->remove(ballisticController);                    ballisticController->dispose();_c1;
}

Drag _DraggableScrollableSheetScrollPositionCls::drag(DragStartDetails details, VoidCallback dragCancelCallback) {
    _dragCancelCallback = dragCancelCallback;
    return super->drag(details, dragCancelCallback);
}

bool _DraggableScrollableSheetScrollPositionCls::_isAtSnapSize() {
    return extent->snapSizes->any([=] (double snapSize) {
        return (extent->currentSize - snapSize)->abs() <= extent->pixelsToSize(physics->tolerance->distance);
    });
}

bool _DraggableScrollableSheetScrollPositionCls::_shouldSnap() {
    return extent->snap && extent->hasDragged && !_isAtSnapSize;
}

bool DraggableScrollableActuatorCls::reset(BuildContext context) {
    _InheritedResetNotifier notifier = context-><_InheritedResetNotifier>dependOnInheritedWidgetOfExactType();
    if (notifier == nullptr) {
        return false;
    }
    return notifier->_sendReset();
}

Widget DraggableScrollableActuatorCls::build(BuildContext context) {
    return make<_InheritedResetNotifierCls>(_notifier, child);
}

bool _ResetNotifierCls::sendReset() {
    if (!hasListeners) {
        return false;
    }
    _wasCalled = true;
    notifyListeners();
    return true;
}

bool _InheritedResetNotifierCls::shouldReset(BuildContext context) {
    InheritedWidget widget = context-><_InheritedResetNotifier>dependOnInheritedWidgetOfExactType();
    if (widget == nullptr) {
        return false;
    }
    assert(widget is _InheritedResetNotifier);
    _InheritedResetNotifier inheritedNotifier = ((_InheritedResetNotifier)widget);
    bool wasCalled = inheritedNotifier->notifier!->_wasCalled;
    inheritedNotifier->notifier!->_wasCalled = false;
    return wasCalled;
}

bool _InheritedResetNotifierCls::_sendReset() {
    return notifier!->sendReset();
}

double _SnappingSimulationCls::dx(double time) {
    if (isDone(time)) {
        return 0;
    }
    return velocity;
}

bool _SnappingSimulationCls::isDone(double time) {
    return x(time) == _pixelSnapSize;
}

double _SnappingSimulationCls::x(double time) {
    double newPosition = position + velocity * time;
    if ((velocity >= 0 && newPosition > _pixelSnapSize) || ( < 0 &&  < _pixelSnapSize)) {
        return _pixelSnapSize;
    }
    return newPosition;
}

_SnappingSimulationCls::_SnappingSimulationCls(double initialVelocity, List<double> pixelSnapSize, double position, Unknown tolerance) {
    {
        _pixelSnapSize = _getSnapSize(initialVelocity, pixelSnapSize);
        if ( < position) {
            velocity = math->min(-minimumSpeed, initialVelocity);
        } else {
            velocity = math->max(minimumSpeed, initialVelocity);
        }
    }
}

double _SnappingSimulationCls::_getSnapSize(double initialVelocity, List<double> pixelSnapSizes) {
    int indexOfNextSize = pixelSnapSizes->indexWhere([=] (double size) {
    size >= position;
});
    if (indexOfNextSize == 0) {
        return pixelSnapSizes->first;
    }
    double nextSize = pixelSnapSizes[indexOfNextSize];
    double previousSize = pixelSnapSizes[indexOfNextSize - 1];
    if (initialVelocity->abs() <= tolerance->velocity) {
        if (position -  < nextSize - position) {
            return previousSize;
        } else {
            return nextSize;
        }
    }
    if ( < 0.0) {
        return pixelSnapSizes[indexOfNextSize - 1];
    }
    return pixelSnapSizes[indexOfNextSize];
}
