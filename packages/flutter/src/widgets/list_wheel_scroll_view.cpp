#include "list_wheel_scroll_view.hpp"
int ListWheelChildDelegate::trueIndexOf(int index) {
    return index;
}

ListWheelChildListDelegate::ListWheelChildListDelegate(List<Widget> children) {
    {
        assert(children != nullptr);
    }
}

int ListWheelChildListDelegate::estimatedChildCount() {
    return children.length;
}

Widget ListWheelChildListDelegate::build(BuildContext context, int index) {
    if ( < 0 || index >= children.length) {
        return nullptr;
    }
    return IndexedSemantics(index, children[index]);
}

bool ListWheelChildListDelegate::shouldRebuild(ListWheelChildListDelegate oldDelegate) {
    return children != oldDelegate.children;
}

ListWheelChildLoopingListDelegate::ListWheelChildLoopingListDelegate(List<Widget> children) {
    {
        assert(children != nullptr);
    }
}

int ListWheelChildLoopingListDelegate::estimatedChildCount() {
    return nullptr;
}

int ListWheelChildLoopingListDelegate::trueIndexOf(int index) {
    return index % children.length;
}

Widget ListWheelChildLoopingListDelegate::build(BuildContext context, int index) {
    if (children.isEmpty) {
        return nullptr;
    }
    return IndexedSemantics(index, children[index % children.length]);
}

bool ListWheelChildLoopingListDelegate::shouldRebuild(ListWheelChildLoopingListDelegate oldDelegate) {
    return children != oldDelegate.children;
}

ListWheelChildBuilderDelegate::ListWheelChildBuilderDelegate(NullableIndexedWidgetBuilder builder, int childCount) {
    {
        assert(builder != nullptr);
    }
}

int ListWheelChildBuilderDelegate::estimatedChildCount() {
    return childCount;
}

Widget ListWheelChildBuilderDelegate::build(BuildContext context, int index) {
    if (childCount == nullptr) {
        Widget child = builder(context, index);
        return child == nullptr? nullptr : IndexedSemantics(index, child);
    }
    if ( < 0 || index >= childCount!) {
        return nullptr;
    }
    return IndexedSemantics(index, builder(context, index));
}

bool ListWheelChildBuilderDelegate::shouldRebuild(ListWheelChildBuilderDelegate oldDelegate) {
    return builder != oldDelegate.builder || childCount != oldDelegate.childCount;
}

FixedExtentScrollController::FixedExtentScrollController(int initialItem) {
    {
        assert(initialItem != nullptr);
    }
}

int FixedExtentScrollController::selectedItem() {
    assert(positions.isNotEmpty, "FixedExtentScrollController.selectedItem cannot be accessed before a scroll view is built with it.");
    assert(positions.length == 1, "The selectedItem property cannot be read when multiple scroll views are attached to the same FixedExtentScrollController.");
    _FixedExtentScrollPosition position = (;
    return position.itemIndex;
}

Future<void> FixedExtentScrollController::animateToItem(Curve curve, Duration duration, int itemIndex) {
    if (!hasClients) {
        return;
    }
    await await Future.<void>wait();
}

void FixedExtentScrollController::jumpToItem(int itemIndex) {
    for (_FixedExtentScrollPosition position : positions.<_FixedExtentScrollPosition>cast()) {
        position.jumpTo(itemIndex * position.itemExtent);
    }
}

ScrollPosition FixedExtentScrollController::createScrollPosition(ScrollContext context, ScrollPosition oldPosition, ScrollPhysics physics) {
    return _FixedExtentScrollPosition(physics, context, initialItem, oldPosition);
}

FixedExtentMetrics FixedExtentMetrics::copyWith(AxisDirection axisDirection, int itemIndex, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension) {
    return FixedExtentMetrics(minScrollExtent ?? (hasContentDimensions? this.minScrollExtent : nullptr), maxScrollExtent ?? (hasContentDimensions? this.maxScrollExtent : nullptr), pixels ?? (hasPixels? this.pixels : nullptr), viewportDimension ?? (hasViewportDimension? this.viewportDimension : nullptr), axisDirection ?? this.axisDirection, itemIndex ?? this.itemIndex);
}

int _getItemFromOffset(double itemExtent, double maxScrollExtent, double minScrollExtent, double offset) {
    return (_clipOffsetToScrollableRange(offset, minScrollExtent, maxScrollExtent) / itemExtent).round();
}

double _clipOffsetToScrollableRange(double maxScrollExtent, double minScrollExtent, double offset) {
    return math.min(math.max(offset, minScrollExtent), maxScrollExtent);
}

double _FixedExtentScrollPosition::itemExtent() {
    return _getItemExtentFromScrollContext(context);
}

int _FixedExtentScrollPosition::itemIndex() {
    return _getItemFromOffset(pixels, itemExtent, minScrollExtent, maxScrollExtent);
}

FixedExtentMetrics _FixedExtentScrollPosition::copyWith(AxisDirection axisDirection, int itemIndex, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension) {
    return FixedExtentMetrics(minScrollExtent ?? (hasContentDimensions? this.minScrollExtent : nullptr), maxScrollExtent ?? (hasContentDimensions? this.maxScrollExtent : nullptr), pixels ?? (hasPixels? this.pixels : nullptr), viewportDimension ?? (hasViewportDimension? this.viewportDimension : nullptr), axisDirection ?? this.axisDirection, itemIndex ?? this.itemIndex);
}

_FixedExtentScrollPosition::_FixedExtentScrollPosition(Unknown, int initialItem, Unknown, Unknown) {
    {
        assert(context is _FixedExtentScrollableState, "FixedExtentScrollController can only be used with ListWheelScrollViews");
        super(_getItemExtentFromScrollContext(context) * initialItem);
    }
}

double _FixedExtentScrollPosition::_getItemExtentFromScrollContext(ScrollContext context) {
    _FixedExtentScrollableState scrollable = (;
    return scrollable.itemExtent;
}

_FixedExtentScrollableState _FixedExtentScrollable::createState() {
    return _FixedExtentScrollableState();
}

double _FixedExtentScrollableState::itemExtent() {
    _FixedExtentScrollable actualWidget = (;
    return actualWidget.itemExtent;
}

FixedExtentScrollPhysics FixedExtentScrollPhysics::applyTo(ScrollPhysics ancestor) {
    return FixedExtentScrollPhysics(buildParent(ancestor));
}

Simulation FixedExtentScrollPhysics::createBallisticSimulation(ScrollMetrics position, double velocity) {
    assert(position is _FixedExtentScrollPosition, "FixedExtentScrollPhysics can only be used with Scrollables that uses the FixedExtentScrollController");
    _FixedExtentScrollPosition metrics = (;
    if ((velocity <= 0.0 && metrics.pixels <= metrics.minScrollExtent) || (velocity >= 0.0 && metrics.pixels >= metrics.maxScrollExtent)) {
        return super.createBallisticSimulation(metrics, velocity);
    }
    Simulation testFrictionSimulation = super.createBallisticSimulation(metrics, velocity);
    if (testFrictionSimulation != nullptr && (testFrictionSimulation.x(double.infinity) == metrics.minScrollExtent || testFrictionSimulation.x(double.infinity) == metrics.maxScrollExtent)) {
        return super.createBallisticSimulation(metrics, velocity);
    }
    int settlingItemIndex = _getItemFromOffset(testFrictionSimulation?.x(double.infinity) ?? metrics.pixels, metrics.itemExtent, metrics.minScrollExtent, metrics.maxScrollExtent);
    double settlingPixels = settlingItemIndex * metrics.itemExtent;
    if (velocity.abs() < tolerance.velocity && (settlingPixels - metrics.pixels).abs() < tolerance.distance) {
        return nullptr;
    }
    if (settlingItemIndex == metrics.itemIndex) {
        return SpringSimulation(spring, metrics.pixels, settlingPixels, velocitytolerance);
    }
    return FrictionSimulation.through(metrics.pixels, settlingPixels, velocity, tolerance.velocity * velocity.sign);
}

ListWheelScrollView::ListWheelScrollView(List<Widget> children, Clip clipBehavior, ScrollController controller, double diameterRatio, double itemExtent, Unknown, double magnification, double offAxisFraction, ValueChanged<int> onSelectedItemChanged, double overAndUnderCenterOpacity, double perspective, ScrollPhysics physics, bool renderChildrenOutsideViewport, String restorationId, ScrollBehavior scrollBehavior, double squeeze, bool useMagnifier) {
    {
        assert(children != nullptr);
        assert(diameterRatio != nullptr);
        assert(diameterRatio > 0.0, RenderListWheelViewport.diameterRatioZeroMessage);
        assert(perspective != nullptr);
        assert(perspective > 0);
        assert(perspective <= 0.01, RenderListWheelViewport.perspectiveTooHighMessage);
        assert(magnification > 0);
        assert(overAndUnderCenterOpacity != nullptr);
        assert(overAndUnderCenterOpacity >= 0 && overAndUnderCenterOpacity <= 1);
        assert(itemExtent != nullptr);
        assert(itemExtent > 0);
        assert(squeeze != nullptr);
        assert(squeeze > 0);
        assert(renderChildrenOutsideViewport != nullptr);
        assert(clipBehavior != nullptr);
        assert(!renderChildrenOutsideViewport || clipBehavior == Clip.none, RenderListWheelViewport.clipBehaviorAndRenderChildrenOutsideViewportConflict);
        childDelegate = ListWheelChildListDelegate(children);
    }
}

void ListWheelScrollView::useDelegate(ListWheelChildDelegate childDelegate, Clip clipBehavior, ScrollController controller, double diameterRatio, double itemExtent, Unknown, double magnification, double offAxisFraction, ValueChanged<int> onSelectedItemChanged, double overAndUnderCenterOpacity, double perspective, ScrollPhysics physics, bool renderChildrenOutsideViewport, String restorationId, ScrollBehavior scrollBehavior, double squeeze, bool useMagnifier)

State<ListWheelScrollView> ListWheelScrollView::createState() {
    return _ListWheelScrollViewState();
}

void _ListWheelScrollViewState::initState() {
    super.initState();
    scrollController = widget.controller ?? FixedExtentScrollController();
    if (widget.controller is FixedExtentScrollController) {
        FixedExtentScrollController controller = (;
        _lastReportedItemIndex = controller.initialItem;
    }
}

void _ListWheelScrollViewState::didUpdateWidget(ListWheelScrollView oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (widget.controller != nullptr && widget.controller != scrollController) {
        ScrollController oldScrollController = scrollController;
        SchedulerBinding.instance.addPostFrameCallback();
        scrollController = widget.controller;
    }
}

Widget _ListWheelScrollViewState::build(BuildContext context) {
    return <ScrollNotification>NotificationListener(_handleScrollNotification, _FixedExtentScrollable(scrollController, widget.physics, widget.itemExtent, widget.restorationId, widget.scrollBehavior ?? ScrollConfiguration.of(context).copyWith(false), ));
}

bool _ListWheelScrollViewState::_handleScrollNotification(ScrollNotification notification) {
    if (notification.depth == 0 && widget.onSelectedItemChanged != nullptr && notification is ScrollUpdateNotification && notification.metrics is FixedExtentMetrics) {
        FixedExtentMetrics metrics = (;
        int currentItemIndex = metrics.itemIndex;
        if (currentItemIndex != _lastReportedItemIndex) {
            _lastReportedItemIndex = currentItemIndex;
            int trueIndex = widget.childDelegate.trueIndexOf(currentItemIndex);
            widget.onSelectedItemChanged!(trueIndex);
        }
    }
    return false;
}

RenderListWheelViewport ListWheelElement::renderObject() {
    return (;
}

void ListWheelElement::update(ListWheelViewport newWidget) {
    ListWheelViewport oldWidget = (;
    super.update(newWidget);
    ListWheelChildDelegate newDelegate = newWidget.childDelegate;
    ListWheelChildDelegate oldDelegate = oldWidget.childDelegate;
    if (newDelegate != oldDelegate && (newDelegate.runtimeType != oldDelegate.runtimeType || newDelegate.shouldRebuild(oldDelegate))) {
        performRebuild();
        renderObject.markNeedsLayout();
    }
}

int ListWheelElement::childCount() {
    return (().childDelegate.estimatedChildCount;
}

void ListWheelElement::performRebuild() {
    _childWidgets.clear();
    super.performRebuild();
    if (_childElements.isEmpty) {
        return;
    }
    int firstIndex = _childElements.firstKey()!;
    int lastIndex = _childElements.lastKey()!;
    for (; index <= lastIndex; ++index) {
        Element newChild = updateChild(_childElements[index], retrieveWidget(index), index);
        if (newChild != nullptr) {
            _childElements[index] = newChild;
        } else {
            _childElements.remove(index);
        }
    }
}

Widget ListWheelElement::retrieveWidget(int index) {
    return _childWidgets.putIfAbsent(index, );
}

bool ListWheelElement::childExistsAt(int index) {
    return retrieveWidget(index) != nullptr;
}

void ListWheelElement::createChild(RenderBox after, int index) {
    owner!.buildScope(this, );
}

void ListWheelElement::removeChild(RenderBox child) {
    int index = renderObject.indexOf(child);
    owner!.buildScope(this, );
}

Element ListWheelElement::updateChild(Element child, Object newSlot, Widget newWidget) {
    ListWheelParentData oldParentData = (;
    Element newChild = super.updateChild(child, newWidget, newSlot);
    ListWheelParentData newParentData = (;
    if (newParentData != nullptr) {
        newParentData.index = (;
        if (oldParentData != nullptr) {
            newParentData.offset = oldParentData.offset;
        }
    }
    return newChild;
}

void ListWheelElement::insertRenderObjectChild(RenderObject child, int slot) {
    RenderListWheelViewport renderObject = this.renderObject;
    assert(renderObject.debugValidateChild(child));
    renderObject.insert((();
    assert(renderObject == this.renderObject);
}

void ListWheelElement::moveRenderObjectChild(RenderObject child, int newSlot, int oldSlot) {
    String moveChildRenderObjectErrorMessage = "Currently we maintain the list in contiguous increasing order, so moving children around is not allowed.";
    assert(false, moveChildRenderObjectErrorMessage);
}

void ListWheelElement::removeRenderObjectChild(RenderObject child, int slot) {
    assert(child.parent == renderObject);
    renderObject.remove(();
}

void ListWheelElement::visitChildren(ElementVisitor visitor) {
    _childElements.forEach();
}

void ListWheelElement::forgetChild(Element child) {
    _childElements.remove(child.slot);
    super.forgetChild(child);
}

ListWheelViewport::ListWheelViewport(ListWheelChildDelegate childDelegate, Clip clipBehavior, double diameterRatio, double itemExtent, Unknown, double magnification, double offAxisFraction, ViewportOffset offset, double overAndUnderCenterOpacity, double perspective, bool renderChildrenOutsideViewport, double squeeze, bool useMagnifier) {
    {
        assert(childDelegate != nullptr);
        assert(offset != nullptr);
        assert(diameterRatio != nullptr);
        assert(diameterRatio > 0, RenderListWheelViewport.diameterRatioZeroMessage);
        assert(perspective != nullptr);
        assert(perspective > 0);
        assert(perspective <= 0.01, RenderListWheelViewport.perspectiveTooHighMessage);
        assert(overAndUnderCenterOpacity != nullptr);
        assert(overAndUnderCenterOpacity >= 0 && overAndUnderCenterOpacity <= 1);
        assert(itemExtent != nullptr);
        assert(itemExtent > 0);
        assert(squeeze != nullptr);
        assert(squeeze > 0);
        assert(renderChildrenOutsideViewport != nullptr);
        assert(clipBehavior != nullptr);
        assert(!renderChildrenOutsideViewport || clipBehavior == Clip.none, RenderListWheelViewport.clipBehaviorAndRenderChildrenOutsideViewportConflict);
    }
}

ListWheelElement ListWheelViewport::createElement() {
    return ListWheelElement(this);
}

RenderListWheelViewport ListWheelViewport::createRenderObject(BuildContext context) {
    ListWheelElement childManager = (;
    return RenderListWheelViewport(childManager, offset, diameterRatio, perspective, offAxisFraction, useMagnifier, magnification, overAndUnderCenterOpacity, itemExtent, squeeze, renderChildrenOutsideViewport, clipBehavior);
}

void ListWheelViewport::updateRenderObject(BuildContext context, RenderListWheelViewport renderObject) {
    ;
}
