#include "overlay.hpp"
OverlayEntryCls::OverlayEntryCls(WidgetBuilder builder, bool maintainState, bool opaque) {
    {
        assert(builder != nullptr);
        assert(opaque != nullptr);
        assert(maintainState != nullptr);
        _opaque = opaque;
        _maintainState = maintainState;
    }
}

bool OverlayEntryCls::opaque() {
    return _opaque;
}

void OverlayEntryCls::opaque(bool value) {
    assert(!_disposedByOwner);
    if (_opaque == value) {
        return;
    }
    _opaque = value;
    _overlay?->_didChangeEntryOpacity();
}

bool OverlayEntryCls::maintainState() {
    return _maintainState;
}

void OverlayEntryCls::maintainState(bool value) {
    assert(!_disposedByOwner);
    assert(_maintainState != nullptr);
    if (_maintainState == value) {
        return;
    }
    _maintainState = value;
    assert(_overlay != nullptr);
    _overlay!->_didChangeEntryOpacity();
}

bool OverlayEntryCls::mounted() {
    return _overlayStateMounted->value();
}

void OverlayEntryCls::addListener(VoidCallback listener) {
    assert(!_disposedByOwner);
    _overlayStateMounted->addListener(listener);
}

void OverlayEntryCls::removeListener(VoidCallback listener) {
    _overlayStateMounted->removeListener(listener);
}

void OverlayEntryCls::remove() {
    assert(_overlay != nullptr);
    assert(!_disposedByOwner);
    OverlayState overlay = _overlay!;
    _overlay = nullptr;
    if (!overlay->mounted()) {
        return;
    }
    overlay->_entries->remove(this);
    if (SchedulerBindingCls::instance->schedulerPhase == SchedulerPhaseCls::persistentCallbacks) {
        SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration duration) {
            overlay->_markDirty();
        });
    } else {
        overlay->_markDirty();
    }
}

void OverlayEntryCls::markNeedsBuild() {
    assert(!_disposedByOwner);
    _key->currentState()?->_markNeedsBuild();
}

void OverlayEntryCls::dispose() {
    assert(!_disposedByOwner);
    assert(_overlay == nullptr, __s("An OverlayEntry must first be removed from the Overlay before dispose is called."));
    _disposedByOwner = true;
    if (!mounted()) {
        _overlayStateMounted->dispose();
    }
}

String OverlayEntryCls::toString() {
    return __s("%s$%s$%s;");
}

void OverlayEntryCls::_didUnmount() {
    assert(!mounted());
    if (_disposedByOwner) {
        _overlayStateMounted->dispose();
    }
}

_OverlayEntryWidgetState _OverlayEntryWidgetCls::createState() {
    return make<_OverlayEntryWidgetStateCls>();
}

_OverlayEntryWidgetCls::_OverlayEntryWidgetCls(OverlayEntry entry, Key key, bool tickerEnabled) : StatefulWidget(key) {
    {
        assert(key != nullptr);
        assert(entry != nullptr);
        assert(tickerEnabled != nullptr);
    }
}

void _OverlayEntryWidgetStateCls::initState() {
    super->initState();
    widget()->entry->_overlayStateMounted->value = true;
}

void _OverlayEntryWidgetStateCls::dispose() {
    widget()->entry->_overlayStateMounted->value = false;
    widget()->entry->_didUnmount();
    super->dispose();
}

Widget _OverlayEntryWidgetStateCls::build(BuildContext context) {
    return make<TickerModeCls>(widget()->tickerEnabled, widget()->entry->builder(context));
}

void _OverlayEntryWidgetStateCls::_markNeedsBuild() {
    setState([=] () {
    });
}

OverlayCls::OverlayCls(Clip clipBehavior, List<OverlayEntry> initialEntries, Key key) {
    {
        assert(initialEntries != nullptr);
        assert(clipBehavior != nullptr);
    }
}

OverlayState OverlayCls::of(BuildContext context, Widget debugRequiredFor, bool rootOverlay) {
    OverlayState result = rootOverlay? context-><OverlayState>findRootAncestorStateOfType() : context-><OverlayState>findAncestorStateOfType();
    assert([=] () {
        if (debugRequiredFor != nullptr && result == nullptr) {
                    List<DiagnosticsNode> list1 = make<ListCls<>>();        list1.add(ArrayItem);        list1.add(ArrayItem);        list1.add(ArrayItem);        list1.add(ArrayItem);        if (context->widget() != debugRequiredFor) {            list1.add(ArrayItem);        }List<DiagnosticsNode> information = list1;
            throw FlutterErrorCls->fromParts(information);
        }
        return true;
    }());
    return result;
}

OverlayState OverlayCls::createState() {
    return make<OverlayStateCls>();
}

void OverlayStateCls::initState() {
    super->initState();
    insertAll(widget()->initialEntries);
}

void OverlayStateCls::insert(OverlayEntry entry, OverlayEntry above, OverlayEntry below) {
    assert(_debugVerifyInsertPosition(above, below));
    assert(!_entries->contains(entry), __s("The specified entry is already present in the Overlay."));
    assert(entry->_overlay == nullptr, __s("The specified entry is already present in another Overlay."));
    entry->_overlay = this;
    setState([=] () {
        _entries->insert(_insertionIndex(below, above), entry);
    });
}

void OverlayStateCls::insertAll(Iterable<OverlayEntry> entries, OverlayEntry above, OverlayEntry below) {
    assert(_debugVerifyInsertPosition(above, below));
    assert(entries->every([=] (OverlayEntry entry) {
        !_entries->contains(entry);
    }), __s("One or more of the specified entries are already present in the Overlay."));
    assert(entries->every([=] (OverlayEntry entry) {
        entry->_overlay == nullptr;
    }), __s("One or more of the specified entries are already present in another Overlay."));
    if (entries->isEmpty()) {
        return;
    }
    for (OverlayEntry entry : entries) {
        assert(entry->_overlay == nullptr);
        entry->_overlay = this;
    }
    setState([=] () {
        _entries->insertAll(_insertionIndex(below, above), entries);
    });
}

void OverlayStateCls::rearrange(Iterable<OverlayEntry> newEntries, OverlayEntry above, OverlayEntry below) {
    List<OverlayEntry> newEntriesList = is<List<OverlayEntry>>(newEntries)? newEntries : newEntries->toList(false);
    assert(_debugVerifyInsertPosition(above, below, newEntriesList));
    assert(newEntriesList->every([=] (OverlayEntry entry) {
        entry->_overlay == nullptr || entry->_overlay == this;
    }), __s("One or more of the specified entries are already present in another Overlay."));
    assert(newEntriesList->every([=] (OverlayEntry entry) {
        _entries->indexOf(entry) == _entries->lastIndexOf(entry);
    }), __s("One or more of the specified entries are specified multiple times."));
    if (newEntriesList->isEmpty()) {
        return;
    }
    if (listEquals(_entries, newEntriesList)) {
        return;
    }
    LinkedHashSet<OverlayEntry> old = <OverlayEntry>of(_entries);
    for (OverlayEntry entry : newEntriesList) {
        entry->_overlay |= this;
    }
    setState([=] () {
        _entries->clear();
        _entries->addAll(newEntriesList);
        old->removeAll(newEntriesList);
        _entries->insertAll(_insertionIndex(below, above), old);
    });
}

bool OverlayStateCls::debugIsVisible(OverlayEntry entry) {
    bool result = false;
    assert(_entries->contains(entry));
    assert([=] () {
        for (; i > 0; i -= 1) {
            OverlayEntry candidate = _entries[i];
            if (candidate == entry) {
                result = true;
                break;
            }
            if (candidate->opaque()) {
                break;
            }
        }
        return true;
    }());
    return result;
}

Widget OverlayStateCls::build(BuildContext context) {
    List<Widget> children = makeList();
    bool onstage = true;
    int onstageCount = 0;
    for (; i >= 0; i -= 1) {
        OverlayEntry entry = _entries[i];
        if (onstage) {
            onstageCount += 1;
            children->add(make<_OverlayEntryWidgetCls>(entry->_key, entry));
            if (entry->opaque()) {
                onstage = false;
            }
        } else {
            if (entry->maintainState()) {
            children->add(make<_OverlayEntryWidgetCls>(entry->_key, entry, false));
        }
;
        }    }
    return make<_TheatreCls>(children->length() - onstageCount, widget()->clipBehavior, children->reversed()->toList(false));
}

void OverlayStateCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<List<OverlayEntry>>make<DiagnosticsPropertyCls>(__s("entries"), _entries));
}

int OverlayStateCls::_insertionIndex(OverlayEntry below, OverlayEntry above) {
    assert(above == nullptr || below == nullptr);
    if (below != nullptr) {
        return _entries->indexOf(below);
    }
    if (above != nullptr) {
        return _entries->indexOf(above) + 1;
    }
    return _entries->length();
}

bool OverlayStateCls::_debugVerifyInsertPosition(OverlayEntry above, OverlayEntry below, Iterable<OverlayEntry> newEntries) {
    assert(above == nullptr || below == nullptr, __s("Only one of `above` and `below` may be specified."));
    assert(above == nullptr || (above->_overlay == this && _entries->contains(above) && (newEntries?->contains(above) | true)), __s("The provided entry used for `above` must be present in the Overlay%s"));
    assert(below == nullptr || (below->_overlay == this && _entries->contains(below) && (newEntries?->contains(below) | true)), __s("The provided entry used for `below` must be present in the Overlay%s"));
    return true;
}

void OverlayStateCls::_markDirty() {
    if (mounted()) {
        setState([=] () {
        });
    }
}

void OverlayStateCls::_didChangeEntryOpacity() {
    setState([=] () {
    });
}

_TheatreElement _TheatreCls::createElement() {
    return make<_TheatreElementCls>(this);
}

_RenderTheatre _TheatreCls::createRenderObject(BuildContext context) {
    return make<_RenderTheatreCls>(skipCount, DirectionalityCls->of(context), clipBehavior);
}

void _TheatreCls::updateRenderObject(BuildContext context, _RenderTheatre renderObject) {
    auto _c1 = renderObject;_c1.skipCount = auto _c2 = skipCount;_c2.textDirection = auto _c3 = DirectionalityCls->of(context);_c3.clipBehavior = clipBehavior;_c3;_c2;_c1;
}

void _TheatreCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<IntPropertyCls>(__s("skipCount"), skipCount));
}

_TheatreCls::_TheatreCls(List<Widget> children, Clip clipBehavior, int skipCount) {
    {
        assert(skipCount != nullptr);
        assert(skipCount >= 0);
        assert(children != nullptr);
        assert(children->length() >= skipCount);
        assert(clipBehavior != nullptr);
    }
}

_RenderTheatre _TheatreElementCls::renderObject() {
    return as<_RenderTheatre>(super->renderObject);
}

void _TheatreElementCls::debugVisitOnstageChildren(ElementVisitor visitor) {
    _Theatre theatre = as<_Theatre>(widget());
    assert(children()->length() >= theatre->skipCount);
    children()->skip(theatre->skipCount)->forEach(visitor);
}

void _RenderTheatreCls::setupParentData(RenderBox child) {
    if (!is<StackParentData>(child->parentData)) {
        child->parentData = make<StackParentDataCls>();
    }
}

TextDirection _RenderTheatreCls::textDirection() {
    return _textDirection;
}

void _RenderTheatreCls::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    _markNeedResolution();
}

int _RenderTheatreCls::skipCount() {
    return _skipCount;
}

void _RenderTheatreCls::skipCount(int value) {
    assert(value != nullptr);
    if (_skipCount != value) {
        _skipCount = value;
        markNeedsLayout();
    }
}

Clip _RenderTheatreCls::clipBehavior() {
    return _clipBehavior;
}

void _RenderTheatreCls::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

double _RenderTheatreCls::computeMinIntrinsicWidth(double height) {
    return RenderStackCls->getIntrinsicDimension(_firstOnstageChild(), [=] (RenderBox child) {
        child->getMinIntrinsicWidth(height);
    });
}

double _RenderTheatreCls::computeMaxIntrinsicWidth(double height) {
    return RenderStackCls->getIntrinsicDimension(_firstOnstageChild(), [=] (RenderBox child) {
        child->getMaxIntrinsicWidth(height);
    });
}

double _RenderTheatreCls::computeMinIntrinsicHeight(double width) {
    return RenderStackCls->getIntrinsicDimension(_firstOnstageChild(), [=] (RenderBox child) {
        child->getMinIntrinsicHeight(width);
    });
}

double _RenderTheatreCls::computeMaxIntrinsicHeight(double width) {
    return RenderStackCls->getIntrinsicDimension(_firstOnstageChild(), [=] (RenderBox child) {
        child->getMaxIntrinsicHeight(width);
    });
}

double _RenderTheatreCls::computeDistanceToActualBaseline(TextBaseline baseline) {
    assert(!debugNeedsLayout());
    double result;
    RenderBox child = _firstOnstageChild();
    while (child != nullptr) {
        assert(!child->debugNeedsLayout());
        StackParentData childParentData = as<StackParentData>(child->parentData!);
        double candidate = child->getDistanceToActualBaseline(baseline);
        if (candidate != nullptr) {
            candidate += childParentData->offset->dy();
            if (result != nullptr) {
                result = math->min(result, candidate);
            } else {
                result = candidate;
            }
        }
        child = childParentData->nextSibling;
    }
    return result;
}

bool _RenderTheatreCls::sizedByParent() {
    return true;
}

Size _RenderTheatreCls::computeDryLayout(BoxConstraints constraints) {
    assert(constraints->biggest()->isFinite());
    return constraints->biggest();
}

void _RenderTheatreCls::performLayout() {
    _hasVisualOverflow = false;
    if (_onstageChildCount() == 0) {
        return;
    }
    _resolve();
    assert(_resolvedAlignment != nullptr);
    BoxConstraints nonPositionedConstraints = BoxConstraintsCls->tight(constraints()->biggest());
    RenderBox child = _firstOnstageChild();
    while (child != nullptr) {
        StackParentData childParentData = as<StackParentData>(child->parentData!);
        if (!childParentData->isPositioned()) {
            child->layout(nonPositionedConstraints, true);
            childParentData->offset = _resolvedAlignment!->alongOffset(as<Offset>(size() - child->size()));
        } else {
            _hasVisualOverflow = RenderStackCls->layoutPositionedChild(child, childParentData, size(), _resolvedAlignment!) || _hasVisualOverflow;
        }
        assert(child->parentData == childParentData);
        child = childParentData->nextSibling;
    }
}

bool _RenderTheatreCls::hitTestChildren(BoxHitTestResult result, Offset position) {
    RenderBox child = _lastOnstageChild();
    for (;  < _onstageChildCount(); i++) {
        assert(child != nullptr);
        StackParentData childParentData = as<StackParentData>(child!->parentData!);
        bool isHit = result->addWithPaintOffset(childParentData->offset, position, [=] (BoxHitTestResult result,Offset transformed) {
    assert(transformed == position - childParentData->offset);
    return child!->hitTest(result, transformed);
});
        if (isHit) {
            return true;
        }
        child = childParentData->previousSibling;
    }
    return false;
}

void _RenderTheatreCls::paintStack(PaintingContext context, Offset offset) {
    RenderBox child = _firstOnstageChild();
    while (child != nullptr) {
        StackParentData childParentData = as<StackParentData>(child->parentData!);
        context->paintChild(child, childParentData->offset + offset);
        child = childParentData->nextSibling;
    }
}

void _RenderTheatreCls::paint(PaintingContext context, Offset offset) {
    if (_hasVisualOverflow && clipBehavior() != ClipCls::none) {
        _clipRectLayer->layer() = context->pushClipRect(needsCompositing(), offset, OffsetCls::zero & size(), paintStack, clipBehavior(), _clipRectLayer->layer());
    } else {
        _clipRectLayer->layer() = nullptr;
        paintStack(context, offset);
    }
}

void _RenderTheatreCls::dispose() {
    _clipRectLayer->layer() = nullptr;
    super->dispose();
}

void _RenderTheatreCls::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    RenderBox child = _firstOnstageChild();
    while (child != nullptr) {
        visitor(child);
        StackParentData childParentData = as<StackParentData>(child->parentData!);
        child = childParentData->nextSibling;
    }
}

Rect _RenderTheatreCls::describeApproximatePaintClip(RenderObject child) {
    ;
}

void _RenderTheatreCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<IntPropertyCls>(__s("skipCount"), skipCount()));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection()));
}

List<DiagnosticsNode> _RenderTheatreCls::debugDescribeChildren() {
    List<DiagnosticsNode> offstageChildren = makeList();
    List<DiagnosticsNode> onstageChildren = makeList();
    int count = 1;
    bool onstage = false;
    RenderBox child = firstChild;
    RenderBox firstOnstageChild = _firstOnstageChild();
    while (child != nullptr) {
        if (child == firstOnstageChild) {
            onstage = true;
            count = 1;
        }
        if (onstage) {
            onstageChildren->add(child->toDiagnosticsNode(__s("onstage %s,")));
        } else {
            offstageChildren->add(child->toDiagnosticsNode(__s("offstage %s,"), DiagnosticsTreeStyleCls::offstage));
        }
        StackParentData childParentData = as<StackParentData>(child->parentData!);
        child = childParentData->nextSibling;
        count += 1;
    }
    List<DiagnosticsNode> list1 = make<ListCls<>>();for (auto _x1 : onstageChildren) {{    list1.add(_x1);}if (offstageChildren->isNotEmpty()) {    list1.add(ArrayItem);} else {    list1.add(ArrayItem);}return list1;
}

_RenderTheatreCls::_RenderTheatreCls(List<RenderBox> children, Clip clipBehavior, int skipCount, TextDirection textDirection) {
    {
        assert(skipCount != nullptr);
        assert(skipCount >= 0);
        assert(textDirection != nullptr);
        assert(clipBehavior != nullptr);
        _textDirection = textDirection;
        _skipCount = skipCount;
        _clipBehavior = clipBehavior;
    }
    {
        addAll(children);
    }
}

void _RenderTheatreCls::_resolve() {
    if (_resolvedAlignment != nullptr) {
        return;
    }
    _resolvedAlignment = AlignmentDirectionalCls::topStart->resolve(textDirection());
}

void _RenderTheatreCls::_markNeedResolution() {
    _resolvedAlignment = nullptr;
    markNeedsLayout();
}

RenderBox _RenderTheatreCls::_firstOnstageChild() {
    if (skipCount() == super->childCount) {
        return nullptr;
    }
    RenderBox child = super->firstChild;
    for (; toSkip > 0; toSkip--) {
        StackParentData childParentData = as<StackParentData>(child!->parentData!);
        child = childParentData->nextSibling;
        assert(child != nullptr);
    }
    return child;
}

RenderBox _RenderTheatreCls::_lastOnstageChild() {
    return skipCount() == super->childCount? nullptr : lastChild;
}

int _RenderTheatreCls::_onstageChildCount() {
    return childCount - skipCount();
}
