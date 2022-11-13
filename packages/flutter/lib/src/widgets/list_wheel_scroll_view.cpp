#include "list_wheel_scroll_view.hpp"
int ListWheelChildDelegateCls::trueIndexOf(int index) {
    return index;
}

ListWheelChildListDelegateCls::ListWheelChildListDelegateCls(List<Widget> children) {
    {
        assert(children != nullptr);
    }
}

int ListWheelChildListDelegateCls::estimatedChildCount() {
    return children->length();
}

Widget ListWheelChildListDelegateCls::build(BuildContext context, int index) {
    if ( < 0 || index >= children->length()) {
        return nullptr;
    }
    return make<IndexedSemanticsCls>(index, children[index]);
}

bool ListWheelChildListDelegateCls::shouldRebuild(ListWheelChildListDelegate oldDelegate) {
    return children != oldDelegate->children;
}

ListWheelChildLoopingListDelegateCls::ListWheelChildLoopingListDelegateCls(List<Widget> children) {
    {
        assert(children != nullptr);
    }
}

int ListWheelChildLoopingListDelegateCls::estimatedChildCount() {
    return nullptr;
}

int ListWheelChildLoopingListDelegateCls::trueIndexOf(int index) {
    return index % children->length();
}

Widget ListWheelChildLoopingListDelegateCls::build(BuildContext context, int index) {
    if (children->isEmpty()) {
        return nullptr;
    }
    return make<IndexedSemanticsCls>(index, children[index % children->length()]);
}

bool ListWheelChildLoopingListDelegateCls::shouldRebuild(ListWheelChildLoopingListDelegate oldDelegate) {
    return children != oldDelegate->children;
}

ListWheelChildBuilderDelegateCls::ListWheelChildBuilderDelegateCls(NullableIndexedWidgetBuilder builder, int childCount) {
    {
        assert(builder != nullptr);
    }
}

int ListWheelChildBuilderDelegateCls::estimatedChildCount() {
    return childCount;
}

Widget ListWheelChildBuilderDelegateCls::build(BuildContext context, int index) {
    if (childCount == nullptr) {
        Widget child = builder(context, index);
        return child == nullptr? nullptr : make<IndexedSemanticsCls>(index, child);
    }
    if ( < 0 || index >= childCount!) {
        return nullptr;
    }
    return make<IndexedSemanticsCls>(index, builder(context, index));
}

bool ListWheelChildBuilderDelegateCls::shouldRebuild(ListWheelChildBuilderDelegate oldDelegate) {
    return builder != oldDelegate->builder || childCount != oldDelegate->childCount;
}

FixedExtentScrollControllerCls::FixedExtentScrollControllerCls(int initialItem) {
    {
        assert(initialItem != nullptr);
    }
}

int FixedExtentScrollControllerCls::selectedItem() {
    assert(positions()->isNotEmpty(), __s("FixedExtentScrollController.selectedItem cannot be accessed before a scroll view is built with it."));
    assert(positions()->length() == 1, __s("The selectedItem property cannot be read when multiple scroll views are attached to the same FixedExtentScrollController."));
    _FixedExtentScrollPosition position = as<_FixedExtentScrollPosition>(this->position());
    return position->itemIndex();
}

Future<void> FixedExtentScrollControllerCls::animateToItem(int itemIndex, Curve curve, Duration duration) {
    if (!hasClients()) {
        return;
    }
    List<Future<void>> list1 = make<ListCls<>>();for (_FixedExtentScrollPosition position : positions()-><_FixedExtentScrollPosition>cast()) {        ;    }{    list1.add(ArrayItem);}await FutureCls-><void>wait(list1);
}

void FixedExtentScrollControllerCls::jumpToItem(int itemIndex) {
    for (_FixedExtentScrollPosition position : positions()-><_FixedExtentScrollPosition>cast()) {
        position()->jumpTo(itemIndex * position()->itemExtent);
    }
}

ScrollPosition FixedExtentScrollControllerCls::createScrollPosition(ScrollPhysics physics, ScrollContext context, ScrollPosition oldPosition) {
    return make<_FixedExtentScrollPositionCls>(physics, context, initialItem, oldPosition);
}

FixedExtentMetrics FixedExtentMetricsCls::copyWith(AxisDirection axisDirection, int itemIndex, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension) {
    return make<FixedExtentMetricsCls>(minScrollExtent | (hasContentDimensions()? this->minScrollExtent : nullptr), maxScrollExtent | (hasContentDimensions()? this->maxScrollExtent : nullptr), pixels | (hasPixels()? this->pixels : nullptr), viewportDimension | (hasViewportDimension()? this->viewportDimension : nullptr), axisDirection | this->axisDirection, itemIndex | this->itemIndex);
}

int _getItemFromOffset(double itemExtent, double maxScrollExtent, double minScrollExtent, double offset) {
    return (_clipOffsetToScrollableRange(offset, minScrollExtent, maxScrollExtent) / itemExtent)->round();
}

double _clipOffsetToScrollableRange(double offset, double minScrollExtent, double maxScrollExtent) {
    return math->min(math->max(offset, minScrollExtent), maxScrollExtent);
}

double _FixedExtentScrollPositionCls::itemExtent() {
    return _getItemExtentFromScrollContext(context);
}

int _FixedExtentScrollPositionCls::itemIndex() {
    return _getItemFromOffset(pixels(), itemExtent(), minScrollExtent(), maxScrollExtent());
}

FixedExtentMetrics _FixedExtentScrollPositionCls::copyWith(AxisDirection axisDirection, int itemIndex, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension) {
    return make<FixedExtentMetricsCls>(minScrollExtent | (hasContentDimensions()? this->minScrollExtent : nullptr), maxScrollExtent | (hasContentDimensions()? this->maxScrollExtent : nullptr), pixels | (hasPixels()? this->pixels : nullptr), viewportDimension | (hasViewportDimension()? this->viewportDimension : nullptr), axisDirection | this->axisDirection, itemIndex | this->itemIndex);
}

_FixedExtentScrollPositionCls::_FixedExtentScrollPositionCls(ScrollContext context, int initialItem, Unknown oldPosition, ScrollPhysics physics) : ScrollPositionWithSingleContext(_getItemExtentFromScrollContext(context) * initialItem) {
    {
        assert(is<_FixedExtentScrollableState>(context), __s("FixedExtentScrollController can only be used with ListWheelScrollViews"));
    }
}

double _FixedExtentScrollPositionCls::_getItemExtentFromScrollContext(ScrollContext context) {
    _FixedExtentScrollableState scrollable = as<_FixedExtentScrollableState>(context);
    return scrollable->itemExtent();
}

_FixedExtentScrollableState _FixedExtentScrollableCls::createState() {
    return make<_FixedExtentScrollableStateCls>();
}

double _FixedExtentScrollableStateCls::itemExtent() {
    _FixedExtentScrollable actualWidget = as<_FixedExtentScrollable>(widget());
    return actualWidget->itemExtent;
}

FixedExtentScrollPhysics FixedExtentScrollPhysicsCls::applyTo(ScrollPhysics ancestor) {
    return make<FixedExtentScrollPhysicsCls>(buildParent(ancestor));
}

Simulation FixedExtentScrollPhysicsCls::createBallisticSimulation(ScrollMetrics position, double velocity) {
    assert(is<_FixedExtentScrollPosition>(position), __s("FixedExtentScrollPhysics can only be used with Scrollables that uses the FixedExtentScrollController"));
    _FixedExtentScrollPosition metrics = as<_FixedExtentScrollPosition>(position);
    if ((velocity <= 0.0 && metrics->pixels() <= metrics->minScrollExtent()) || (velocity >= 0.0 && metrics->pixels() >= metrics->maxScrollExtent())) {
        return super->createBallisticSimulation(metrics, velocity);
    }
    Simulation testFrictionSimulation = super->createBallisticSimulation(metrics, velocity);
    if (testFrictionSimulation != nullptr && (testFrictionSimulation->x(double->infinity) == metrics->minScrollExtent() || testFrictionSimulation->x(double->infinity) == metrics->maxScrollExtent())) {
        return super->createBallisticSimulation(metrics, velocity);
    }
    int settlingItemIndex = _getItemFromOffset(testFrictionSimulation?->x(double->infinity) | metrics->pixels(), metrics->itemExtent(), metrics->minScrollExtent(), metrics->maxScrollExtent());
    double settlingPixels = settlingItemIndex * metrics->itemExtent();
    if (velocity->abs() < tolerance()->velocity && (settlingPixels - metrics->pixels())->abs() < tolerance()->distance) {
        return nullptr;
    }
    if (settlingItemIndex == metrics->itemIndex()) {
        return make<SpringSimulationCls>(spring(), metrics->pixels(), settlingPixels, velocity, tolerance());
    }
    return FrictionSimulationCls->through(metrics->pixels(), settlingPixels, velocity, tolerance()->velocity * velocity->sign());
}

ListWheelScrollViewCls::ListWheelScrollViewCls(List<Widget> children, Clip clipBehavior, ScrollController controller, double diameterRatio, double itemExtent, Key key, double magnification, double offAxisFraction, ValueChanged<int> onSelectedItemChanged, double overAndUnderCenterOpacity, double perspective, ScrollPhysics physics, bool renderChildrenOutsideViewport, String restorationId, ScrollBehavior scrollBehavior, double squeeze, bool useMagnifier) {
    {
        assert(children != nullptr);
        assert(diameterRatio != nullptr);
        assert(diameterRatio > 0.0, RenderListWheelViewportCls::diameterRatioZeroMessage);
        assert(perspective != nullptr);
        assert(perspective > 0);
        assert(perspective <= 0.01, RenderListWheelViewportCls::perspectiveTooHighMessage);
        assert(magnification > 0);
        assert(overAndUnderCenterOpacity != nullptr);
        assert(overAndUnderCenterOpacity >= 0 && overAndUnderCenterOpacity <= 1);
        assert(itemExtent != nullptr);
        assert(itemExtent > 0);
        assert(squeeze != nullptr);
        assert(squeeze > 0);
        assert(renderChildrenOutsideViewport != nullptr);
        assert(clipBehavior != nullptr);
        assert(!renderChildrenOutsideViewport || clipBehavior == ClipCls::none, RenderListWheelViewportCls::clipBehaviorAndRenderChildrenOutsideViewportConflict);
        childDelegate = make<ListWheelChildListDelegateCls>(children);
    }
}

void ListWheelScrollViewCls::useDelegate(ListWheelChildDelegate childDelegate, Clip clipBehavior, ScrollController controller, double diameterRatio, double itemExtent, Key key, double magnification, double offAxisFraction, ValueChanged<int> onSelectedItemChanged, double overAndUnderCenterOpacity, double perspective, ScrollPhysics physics, bool renderChildrenOutsideViewport, String restorationId, ScrollBehavior scrollBehavior, double squeeze, bool useMagnifier)

State<ListWheelScrollView> ListWheelScrollViewCls::createState() {
    return make<_ListWheelScrollViewStateCls>();
}

void _ListWheelScrollViewStateCls::initState() {
    super->initState();
    scrollController = widget()->controller | make<FixedExtentScrollControllerCls>();
    if (is<FixedExtentScrollController>(widget()->controller)) {
        FixedExtentScrollController controller = as<FixedExtentScrollController>(widget()->controller!);
        _lastReportedItemIndex = controller->initialItem;
    }
}

void _ListWheelScrollViewStateCls::didUpdateWidget(ListWheelScrollView oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (widget()->controller != nullptr && widget()->controller != scrollController) {
        ScrollController oldScrollController = scrollController;
        SchedulerBindingCls::instance->addPostFrameCallback([=] (Unknown  _) {
            oldScrollController!->dispose();
        });
        scrollController = widget()->controller;
    }
}

Widget _ListWheelScrollViewStateCls::build(BuildContext context) {
    return <ScrollNotification>make<NotificationListenerCls>(_handleScrollNotification, make<_FixedExtentScrollableCls>(scrollController, widget()->physics, widget()->itemExtent, widget()->restorationId, widget()->scrollBehavior | ScrollConfigurationCls->of(context)->copyWith(false), [=] (BuildContext context,ViewportOffset offset) {
        return make<ListWheelViewportCls>(widget()->diameterRatio, widget()->perspective, widget()->offAxisFraction, widget()->useMagnifier, widget()->magnification, widget()->overAndUnderCenterOpacity, widget()->itemExtent, widget()->squeeze, widget()->renderChildrenOutsideViewport, offset, widget()->childDelegate, widget()->clipBehavior);
    }));
}

bool _ListWheelScrollViewStateCls::_handleScrollNotification(ScrollNotification notification) {
    if (notification->depth == 0 && widget()->onSelectedItemChanged != nullptr && is<ScrollUpdateNotification>(notification) && is<FixedExtentMetrics>(notification->metrics)) {
        FixedExtentMetrics metrics = as<FixedExtentMetrics>(notification->metrics);
        int currentItemIndex = metrics->itemIndex;
        if (currentItemIndex != _lastReportedItemIndex) {
            _lastReportedItemIndex = currentItemIndex;
            int trueIndex = widget()->childDelegate->trueIndexOf(currentItemIndex);
            widget()->onSelectedItemChanged!(trueIndex);
        }
    }
    return false;
}

RenderListWheelViewport ListWheelElementCls::renderObject() {
    return as<RenderListWheelViewport>(super->renderObject);
}

void ListWheelElementCls::update(ListWheelViewport newWidget) {
    ListWheelViewport oldWidget = as<ListWheelViewport>(widget());
    super->update(newWidget);
    ListWheelChildDelegate newDelegate = newWidget->childDelegate;
    ListWheelChildDelegate oldDelegate = oldWidget->childDelegate;
    if (newDelegate != oldDelegate && (newDelegate->runtimeType != oldDelegate->runtimeType || newDelegate->shouldRebuild(oldDelegate))) {
        performRebuild();
        renderObject()->markNeedsLayout();
    }
}

int ListWheelElementCls::childCount() {
    return (as<ListWheelViewport>(widget()))->childDelegate->estimatedChildCount();
}

void ListWheelElementCls::performRebuild() {
    _childWidgets->clear();
    super->performRebuild();
    if (_childElements->isEmpty()) {
        return;
    }
    int firstIndex = _childElements->firstKey()!;
    int lastIndex = _childElements->lastKey()!;
    for (; index <= lastIndex; ++index) {
        Element newChild = updateChild(_childElements[index], retrieveWidget(index), index);
        if (newChild != nullptr) {
            _childElements[index] = newChild;
        } else {
            _childElements->remove(index);
        }
    }
}

Widget ListWheelElementCls::retrieveWidget(int index) {
    return _childWidgets->putIfAbsent(index, [=] () {
        (as<ListWheelViewport>(widget()))->childDelegate->build(this, index);
    });
}

bool ListWheelElementCls::childExistsAt(int index) {
    return retrieveWidget(index) != nullptr;
}

void ListWheelElementCls::createChild(int index, RenderBox after) {
    owner()!->buildScope(this, [=] () {
        bool insertFirst = after == nullptr;
        assert(insertFirst || _childElements[index - 1] != nullptr);
        Element newChild = updateChild(_childElements[index], retrieveWidget(index), index);
        if (newChild != nullptr) {
            _childElements[index] = newChild;
        } else {
            _childElements->remove(index);
        }
    });
}

void ListWheelElementCls::removeChild(RenderBox child) {
    int index = renderObject()->indexOf(child);
    owner()!->buildScope(this, [=] () {
        assert(_childElements->containsKey(index));
        Element result = updateChild(_childElements[index], nullptr, index);
        assert(result == nullptr);
        _childElements->remove(index);
        assert(!_childElements->containsKey(index));
    });
}

Element ListWheelElementCls::updateChild(Element child, Widget newWidget, Object newSlot) {
    ListWheelParentData oldParentData = as<ListWheelParentData>(child?->renderObject()?->parentData);
    Element newChild = super->updateChild(child, newWidget, newSlot);
    ListWheelParentData newParentData = as<ListWheelParentData>(newChild?->renderObject()?->parentData);
    if (newParentData != nullptr) {
        newParentData->index = as<int>(newSlot!);
        if (oldParentData != nullptr) {
            newParentData->offset = oldParentData->offset;
        }
    }
    return newChild;
}

void ListWheelElementCls::insertRenderObjectChild(RenderObject child, int slot) {
    RenderListWheelViewport renderObject = this->renderObject();
    assert(renderObject->debugValidateChild(child));
    renderObject->insert(as<RenderBox>(child), as<RenderBox>(_childElements[slot - 1]?->renderObject));
    assert(renderObject == this->renderObject);
}

void ListWheelElementCls::moveRenderObjectChild(RenderObject child, int oldSlot, int newSlot) {
    String moveChildRenderObjectErrorMessage = __s("Currently we maintain the list in contiguous increasing order, so moving children around is not allowed.");
    assert(false, moveChildRenderObjectErrorMessage);
}

void ListWheelElementCls::removeRenderObjectChild(RenderObject child, int slot) {
    assert(child->parent() == renderObject());
    renderObject()->remove(as<RenderBox>(child));
}

void ListWheelElementCls::visitChildren(ElementVisitor visitor) {
    _childElements->forEach([=] (int key,Element child) {
        visitor(child);
    });
}

void ListWheelElementCls::forgetChild(Element child) {
    _childElements->remove(child->slot());
    super->forgetChild(child);
}

ListWheelViewportCls::ListWheelViewportCls(ListWheelChildDelegate childDelegate, Clip clipBehavior, double diameterRatio, double itemExtent, Key key, double magnification, double offAxisFraction, ViewportOffset offset, double overAndUnderCenterOpacity, double perspective, bool renderChildrenOutsideViewport, double squeeze, bool useMagnifier) {
    {
        assert(childDelegate != nullptr);
        assert(offset != nullptr);
        assert(diameterRatio != nullptr);
        assert(diameterRatio > 0, RenderListWheelViewportCls::diameterRatioZeroMessage);
        assert(perspective != nullptr);
        assert(perspective > 0);
        assert(perspective <= 0.01, RenderListWheelViewportCls::perspectiveTooHighMessage);
        assert(overAndUnderCenterOpacity != nullptr);
        assert(overAndUnderCenterOpacity >= 0 && overAndUnderCenterOpacity <= 1);
        assert(itemExtent != nullptr);
        assert(itemExtent > 0);
        assert(squeeze != nullptr);
        assert(squeeze > 0);
        assert(renderChildrenOutsideViewport != nullptr);
        assert(clipBehavior != nullptr);
        assert(!renderChildrenOutsideViewport || clipBehavior == ClipCls::none, RenderListWheelViewportCls::clipBehaviorAndRenderChildrenOutsideViewportConflict);
    }
}

ListWheelElement ListWheelViewportCls::createElement() {
    return make<ListWheelElementCls>(this);
}

RenderListWheelViewport ListWheelViewportCls::createRenderObject(BuildContext context) {
    ListWheelElement childManager = as<ListWheelElement>(context);
    return make<RenderListWheelViewportCls>(childManager, offset, diameterRatio, perspective, offAxisFraction, useMagnifier, magnification, overAndUnderCenterOpacity, itemExtent, squeeze, renderChildrenOutsideViewport, clipBehavior);
}

void ListWheelViewportCls::updateRenderObject(BuildContext context, RenderListWheelViewport renderObject) {
    auto _c1 = renderObject;_c1.offset = auto _c2 = offset;_c2.diameterRatio = auto _c3 = diameterRatio;_c3.perspective = auto _c4 = perspective;_c4.offAxisFraction = auto _c5 = offAxisFraction;_c5.useMagnifier = auto _c6 = useMagnifier;_c6.magnification = auto _c7 = magnification;_c7.overAndUnderCenterOpacity = auto _c8 = overAndUnderCenterOpacity;_c8.itemExtent = auto _c9 = itemExtent;_c9.squeeze = auto _c10 = squeeze;_c10.renderChildrenOutsideViewport = auto _c11 = renderChildrenOutsideViewport;_c11.clipBehavior = clipBehavior;_c11;_c10;_c9;_c8;_c7;_c6;_c5;_c4;_c3;_c2;_c1;
}
