#include "draggable_scrollable_sheet.hpp"
double DraggableScrollableController::size() {
    _assertAttached();
    return _attachedController!.extent.currentSize;
}

double DraggableScrollableController::pixels() {
    _assertAttached();
    return _attachedController!.extent.currentPixels;
}

double DraggableScrollableController::sizeToPixels(double size) {
    _assertAttached();
    return _attachedController!.extent.sizeToPixels(size);
}

bool DraggableScrollableController::isAttached() {
    return _attachedController != nullptr && _attachedController!.hasClients;
}

double DraggableScrollableController::pixelsToSize(double pixels) {
    _assertAttached();
    return _attachedController!.extent.pixelsToSize(pixels);
}

Future<void> DraggableScrollableController::animateTo(Curve curve, Duration duration, double size) {
    _assertAttached();
    assert(size >= 0 && size <= 1);
    assert(duration != Duration.zero);
    AnimationController animationController = AnimationController.unbounded(_attachedController!.position.context.vsync, _attachedController!.extent.currentSize);
    _animationControllers.add(animationController);
    _attachedController!.position.goIdle();
    _attachedController!.extent.hasDragged = false;
    _attachedController!.extent.startActivity();
    animationController.addListener();
    await await animationController.animateTo(sizeduration, curve);
}

void DraggableScrollableController::jumpTo(double size) {
    _assertAttached();
    assert(size >= 0 && size <= 1);
    _attachedController!.extent.startActivity();
    _attachedController!.position.goIdle();
    _attachedController!.extent.hasDragged = false;
    _attachedController!.extent.updateSize(size, _attachedController!.position.context.notificationContext!);
}

void DraggableScrollableController::reset() {
    _assertAttached();
    _attachedController!.reset();
}

void DraggableScrollableController::_assertAttached() {
    assert(isAttached, "DraggableScrollableController is not attached to a sheet. A DraggableScrollableController must be used in a DraggableScrollableSheet before any of its methods are called.");
}

void DraggableScrollableController::_attach(_DraggableScrollableSheetScrollController scrollController) {
    assert(_attachedController == nullptr, "Draggable scrollable controller is already attached to a sheet.");
    _attachedController = scrollController;
    _attachedController!.extent._currentSize.addListener(notifyListeners);
    _attachedController!.onPositionDetached = _disposeAnimationControllers;
}

void DraggableScrollableController::_onExtentReplaced(_DraggableSheetExtent previousExtent) {
    _attachedController!.extent._currentSize.addListener(notifyListeners);
    if (previousExtent.currentSize != _attachedController!.extent.currentSize) {
        notifyListeners();
    }
}

void DraggableScrollableController::_detach() {
    _attachedController?.extent._currentSize.removeListener(notifyListeners);
    _attachedController = nullptr;
}

void DraggableScrollableController::_disposeAnimationControllers() {
    for (AnimationController animationController : _animationControllers) {
        animationController.dispose();
    }
    _animationControllers.clear();
}

DraggableScrollableSheet::DraggableScrollableSheet(ScrollableWidgetBuilder builder, DraggableScrollableController controller, bool expand, double initialChildSize, Unknown, double maxChildSize, double minChildSize, bool snap, List<double> snapSizes) {
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

State<DraggableScrollableSheet> DraggableScrollableSheet::createState() {
    return _DraggableScrollableSheetState();
}

DraggableScrollableNotification::DraggableScrollableNotification(BuildContext context, double extent, double initialExtent, double maxExtent, double minExtent) {
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

void DraggableScrollableNotification::debugFillDescription(List<String> description) {
    super.debugFillDescription(description);
    description.add("minExtent: $minExtent, extent: $extent, maxExtent: $maxExtent, initialExtent: $initialExtent");
}

bool _DraggableSheetExtent::isAtMin() {
    return minSize >= _currentSize.value;
}

bool _DraggableSheetExtent::isAtMax() {
    return maxSize <= _currentSize.value;
}

double _DraggableSheetExtent::currentSize() {
    return _currentSize.value;
}

double _DraggableSheetExtent::currentPixels() {
    return sizeToPixels(_currentSize.value);
}

double _DraggableSheetExtent::additionalMinSize() {
    return isAtMin? 0.0 : 1.0;
}

double _DraggableSheetExtent::additionalMaxSize() {
    return isAtMax? 0.0 : 1.0;
}

List<double> _DraggableSheetExtent::pixelSnapSizes() {
    return snapSizes.map(sizeToPixels).toList();
}

void _DraggableSheetExtent::startActivity(VoidCallback onCanceled) {
    _cancelActivity?.call();
    _cancelActivity = onCanceled;
}

void _DraggableSheetExtent::addPixelDelta(BuildContext context, double delta) {
    _cancelActivity?.call();
    _cancelActivity = nullptr;
    hasDragged = true;
    if (availablePixels == 0) {
        return;
    }
    updateSize(currentSize + pixelsToSize(delta), context);
}

void _DraggableSheetExtent::updateSize(BuildContext context, double newSize) {
    assert(newSize != nullptr);
    _currentSize.value = clampDouble(newSize, minSize, maxSize);
    DraggableScrollableNotification(minSize, maxSize, currentSize, initialSize, context).dispatch(context);
}

double _DraggableSheetExtent::pixelsToSize(double pixels) {
    return pixels / availablePixels * maxSize;
}

double _DraggableSheetExtent::sizeToPixels(double size) {
    return size / maxSize * availablePixels;
}

void _DraggableSheetExtent::dispose() {
    _currentSize.removeListener(onSizeChanged);
}

_DraggableSheetExtent _DraggableSheetExtent::copyWith(double initialSize, double maxSize, double minSize, VoidCallback onSizeChanged, bool snap, List<double> snapSizes) {
    return _DraggableSheetExtent(minSize, maxSize, snap, snapSizes, initialSize, onSizeChanged, <double>ValueNotifier(hasDragged? clampDouble(_currentSize.value, minSize, maxSize) : initialSize), hasDragged);
}

_DraggableSheetExtent::_DraggableSheetExtent(ValueNotifier<double> currentSize, bool hasDragged, double initialSize, double maxSize, double minSize, VoidCallback onSizeChanged, bool snap, List<double> snapSizes) {
    {
        assert(minSize != nullptr);
        assert(maxSize != nullptr);
        assert(initialSize != nullptr);
        assert(minSize >= 0);
        assert(maxSize <= 1);
        assert(minSize <= initialSize);
        assert(initialSize <= maxSize);
        _currentSize = ;
        availablePixels = double.infinity;
        hasDragged = hasDragged ?? false;
    }
}

void _DraggableScrollableSheetState::initState() {
    super.initState();
    _extent = _DraggableSheetExtent(widget.minChildSize, widget.maxChildSize, widget.snap, _impliedSnapSizes(), widget.initialChildSize, _setExtent);
    _scrollController = _DraggableScrollableSheetScrollController(_extent);
    widget.controller?._attach(_scrollController);
}

void _DraggableScrollableSheetState::didUpdateWidget(DraggableScrollableSheet oldWidget) {
    super.didUpdateWidget(oldWidget);
    _replaceExtent(oldWidget);
}

void _DraggableScrollableSheetState::didChangeDependencies() {
    super.didChangeDependencies();
    if (_InheritedResetNotifier.shouldReset(context)) {
        _scrollController.reset();
    }
}

Widget _DraggableScrollableSheetState::build(BuildContext context) {
    return LayoutBuilder();
}

void _DraggableScrollableSheetState::dispose() {
    widget.controller?._detach();
    _scrollController.dispose();
    _extent.dispose();
    super.dispose();
}

List<double> _DraggableScrollableSheetState::_impliedSnapSizes() {
    for (;  < (widget.snapSizes?.length ?? 0); index = 1) {
        double snapSize = widget.snapSizes![index];
        assert(snapSize >= widget.minChildSize && snapSize <= widget.maxChildSize, "${_snapSizeErrorMessage(index)}\nSnap sizes must be between `minChildSize` and `maxChildSize`. ");
        assert(index == 0 || snapSize > widget.snapSizes![index - 1], "${_snapSizeErrorMessage(index)}\nSnap sizes must be in ascending order. ");
    }
    if (widget.snapSizes == nullptr || widget.snapSizes!.isEmpty) {
        return ;
    }
    return ;
}

void _DraggableScrollableSheetState::_setExtent() {
    setState();
}

void _DraggableScrollableSheetState::_replaceExtent(DraggableScrollableSheet oldWidget) {
    _DraggableSheetExtent previousExtent = _extent;
    _extent.dispose();
    _extent = _extent.copyWith(widget.minChildSize, widget.maxChildSize, widget.snap, _impliedSnapSizes(), widget.initialChildSize, _setExtent);
    _scrollController.extent = _extent;
    widget.controller?._onExtentReplaced(previousExtent);
    if (widget.snap && (widget.snap != oldWidget.snap || widget.snapSizes != oldWidget.snapSizes) && _scrollController.hasClients) {
        WidgetsBinding.instance.addPostFrameCallback();
    }
}

String _DraggableScrollableSheetState::_snapSizeErrorMessage(int invalidIndex) {
    List<String> snapSizesWithIndicator = widget.snapSizes!.asMap().keys.map().toList();
    return "Invalid snapSize '${widget.snapSizes![invalidIndex]}' at index $invalidIndex of:\n  $snapSizesWithIndicator";
}

_DraggableScrollableSheetScrollPosition _DraggableScrollableSheetScrollController::createScrollPosition(ScrollContext context, ScrollPosition oldPosition, ScrollPhysics physics) {
    return _DraggableScrollableSheetScrollPosition(physics, context, oldPosition, );
}

void _DraggableScrollableSheetScrollController::debugFillDescription(List<String> description) {
    super.debugFillDescription(description);
    description.add("extent: $extent");
}

_DraggableScrollableSheetScrollPosition _DraggableScrollableSheetScrollController::position() {
    return (;
}

void _DraggableScrollableSheetScrollController::reset() {
    extent._cancelActivity?.call();
    extent.hasDragged = false;
    if (offset != 0.0) {
        animateTo(0.0const Duration(1), Curves.linear);
    }
    extent.updateSize(extent.initialSize, position.context.notificationContext!);
}

void _DraggableScrollableSheetScrollController::detach(ScrollPosition position) {
    onPositionDetached?.call();
    super.detach(position);
}

_DraggableScrollableSheetScrollController::_DraggableScrollableSheetScrollController(_DraggableSheetExtent extent) {
    {
        assert(extent != nullptr);
    }
}

bool _DraggableScrollableSheetScrollPosition::listShouldScroll() {
    return pixels > 0.0;
}

_DraggableSheetExtent _DraggableScrollableSheetScrollPosition::extent() {
    return getExtent();
}

void _DraggableScrollableSheetScrollPosition::absorb(ScrollPosition other) {
    super.absorb(other);
    assert(_dragCancelCallback == nullptr);
    if (other is! _DraggableScrollableSheetScrollPosition) {
        return;
    }
    if (other._dragCancelCallback != nullptr) {
        _dragCancelCallback = other._dragCancelCallback;
        other._dragCancelCallback = nullptr;
    }
}

void _DraggableScrollableSheetScrollPosition::beginActivity(ScrollActivity newActivity) {
    for (AnimationController ballisticController : _ballisticControllers) {
        ballisticController.stop();
    }
    super.beginActivity(newActivity);
}

bool _DraggableScrollableSheetScrollPosition::applyContentDimensions(double maxScrollSize, double minScrollSize) {
    return super.applyContentDimensions(minScrollSize - extent.additionalMinSize, maxScrollSize + extent.additionalMaxSize);
}

void _DraggableScrollableSheetScrollPosition::applyUserOffset(double delta) {
    if (!listShouldScroll && (!(extent.isAtMin || extent.isAtMax) || (extent.isAtMin &&  < 0) || (extent.isAtMax && delta > 0))) {
        extent.addPixelDelta(-delta, context.notificationContext!);
    } else {
        super.applyUserOffset(delta);
    }
}

void _DraggableScrollableSheetScrollPosition::dispose() {
    for (AnimationController ballisticController : _ballisticControllers) {
        ballisticController.dispose();
    }
    _ballisticControllers.clear();
    super.dispose();
}

void _DraggableScrollableSheetScrollPosition::goBallistic(double velocity) {
    if ((velocity == 0.0 && !_shouldSnap) || ( < 0.0 && listShouldScroll) || (velocity > 0.0 && extent.isAtMax)) {
        super.goBallistic(velocity);
        return;
    }
    _dragCancelCallback?.call();
    _dragCancelCallback = nullptr;
    Simulation simulation;
    if (extent.snap) {
        simulation = _SnappingSimulation(extent.currentPixels, velocity, extent.pixelSnapSizes, physics.tolerance);
    } else {
        simulation = ClampingScrollSimulation(extent.currentPixels, velocity, physics.tolerance);
    }
    AnimationController ballisticController = AnimationController.unbounded(objectRuntimeType(this, "_DraggableScrollableSheetPosition"), context.vsync);
    _ballisticControllers.add(ballisticController);
    double lastPosition = extent.currentPixels;
    ;
    ;
}

Drag _DraggableScrollableSheetScrollPosition::drag(DragStartDetails details, VoidCallback dragCancelCallback) {
    _dragCancelCallback = dragCancelCallback;
    return super.drag(details, dragCancelCallback);
}

bool _DraggableScrollableSheetScrollPosition::_isAtSnapSize() {
    return extent.snapSizes.any();
}

bool _DraggableScrollableSheetScrollPosition::_shouldSnap() {
    return extent.snap && extent.hasDragged && !_isAtSnapSize;
}

bool DraggableScrollableActuator::reset(BuildContext context) {
    _InheritedResetNotifier notifier = context.<_InheritedResetNotifier>dependOnInheritedWidgetOfExactType();
    if (notifier == nullptr) {
        return false;
    }
    return notifier._sendReset();
}

Widget DraggableScrollableActuator::build(BuildContext context) {
    return _InheritedResetNotifier(_notifier, child);
}

bool _ResetNotifier::sendReset() {
    if (!hasListeners) {
        return false;
    }
    _wasCalled = true;
    notifyListeners();
    return true;
}

bool _InheritedResetNotifier::shouldReset(BuildContext context) {
    InheritedWidget widget = context.<_InheritedResetNotifier>dependOnInheritedWidgetOfExactType();
    if (widget == nullptr) {
        return false;
    }
    assert(widget is _InheritedResetNotifier);
    _InheritedResetNotifier inheritedNotifier = (;
    bool wasCalled = inheritedNotifier.notifier!._wasCalled;
    inheritedNotifier.notifier!._wasCalled = false;
    return wasCalled;
}

bool _InheritedResetNotifier::_sendReset() {
    return notifier!.sendReset();
}

double _SnappingSimulation::dx(double time) {
    if (isDone(time)) {
        return 0;
    }
    return velocity;
}

bool _SnappingSimulation::isDone(double time) {
    return x(time) == _pixelSnapSize;
}

double _SnappingSimulation::x(double time) {
    double newPosition = position + velocity * time;
    if ((velocity >= 0 && newPosition > _pixelSnapSize) || ( < 0 &&  < _pixelSnapSize)) {
        return _pixelSnapSize;
    }
    return newPosition;
}

_SnappingSimulation::_SnappingSimulation(double initialVelocity, List<double> pixelSnapSize, double position, Unknown) {
    {
        _pixelSnapSize = _getSnapSize(initialVelocity, pixelSnapSize);
        if ( < position) {
            velocity = math.min(-minimumSpeed, initialVelocity);
        } else {
            velocity = math.max(minimumSpeed, initialVelocity);
        }
    }
}

double _SnappingSimulation::_getSnapSize(double initialVelocity, List<double> pixelSnapSizes) {
    int indexOfNextSize = pixelSnapSizes.indexWhere();
    if (indexOfNextSize == 0) {
        return pixelSnapSizes.first;
    }
    double nextSize = pixelSnapSizes[indexOfNextSize];
    double previousSize = pixelSnapSizes[indexOfNextSize - 1];
    if (initialVelocity.abs() <= tolerance.velocity) {
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
