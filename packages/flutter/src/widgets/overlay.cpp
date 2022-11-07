#include "overlay.hpp"
OverlayEntry::OverlayEntry(WidgetBuilder builder, bool maintainState, bool opaque) {
    {
        assert(builder != nullptr);
        assert(opaque != nullptr);
        assert(maintainState != nullptr);
        _opaque = opaque;
        _maintainState = maintainState;
    }
}

bool OverlayEntry::opaque() {
    return _opaque;
}

void OverlayEntry::opaque(bool value) {
    assert(!_disposedByOwner);
    if (_opaque == value) {
        return;
    }
    _opaque = value;
    _overlay?._didChangeEntryOpacity();
}

bool OverlayEntry::maintainState() {
    return _maintainState;
}

void OverlayEntry::maintainState(bool value) {
    assert(!_disposedByOwner);
    assert(_maintainState != nullptr);
    if (_maintainState == value) {
        return;
    }
    _maintainState = value;
    assert(_overlay != nullptr);
    _overlay!._didChangeEntryOpacity();
}

bool OverlayEntry::mounted() {
    return _overlayStateMounted.value;
}

void OverlayEntry::addListener(VoidCallback listener) {
    assert(!_disposedByOwner);
    _overlayStateMounted.addListener(listener);
}

void OverlayEntry::removeListener(VoidCallback listener) {
    _overlayStateMounted.removeListener(listener);
}

void OverlayEntry::remove() {
    assert(_overlay != nullptr);
    assert(!_disposedByOwner);
    OverlayState overlay = _overlay!;
    _overlay = nullptr;
    if (!overlay.mounted) {
        return;
    }
    overlay._entries.remove(this);
    if (SchedulerBinding.instance.schedulerPhase == SchedulerPhase.persistentCallbacks) {
        SchedulerBinding.instance.addPostFrameCallback();
    } else {
        overlay._markDirty();
    }
}

void OverlayEntry::markNeedsBuild() {
    assert(!_disposedByOwner);
    _key.currentState?._markNeedsBuild();
}

void OverlayEntry::dispose() {
    assert(!_disposedByOwner);
    assert(_overlay == nullptr, "An OverlayEntry must first be removed from the Overlay before dispose is called.");
    _disposedByOwner = true;
    if (!mounted) {
        _overlayStateMounted.dispose();
    }
}

String OverlayEntry::toString() {
    return "${describeIdentity(this)}(opaque: $opaque; maintainState: $maintainState)";
}

void OverlayEntry::_didUnmount() {
    assert(!mounted);
    if (_disposedByOwner) {
        _overlayStateMounted.dispose();
    }
}

_OverlayEntryWidgetState _OverlayEntryWidget::createState() {
    return _OverlayEntryWidgetState();
}

_OverlayEntryWidget::_OverlayEntryWidget(OverlayEntry entry, Key key, bool tickerEnabled) {
    {
        assert(key != nullptr);
        assert(entry != nullptr);
        assert(tickerEnabled != nullptr);
        super(key);
    }
}

void _OverlayEntryWidgetState::initState() {
    super.initState();
    widget.entry._overlayStateMounted.value = true;
}

void _OverlayEntryWidgetState::dispose() {
    widget.entry._overlayStateMounted.value = false;
    widget.entry._didUnmount();
    super.dispose();
}

Widget _OverlayEntryWidgetState::build(BuildContext context) {
    return TickerMode(widget.tickerEnabled, widget.entry.builder(context));
}

void _OverlayEntryWidgetState::_markNeedsBuild() {
    setState();
}

Overlay::Overlay(Clip clipBehavior, List<OverlayEntry> initialEntries, Unknown) {
    {
        assert(initialEntries != nullptr);
        assert(clipBehavior != nullptr);
    }
}

OverlayState Overlay::of(BuildContext context, Widget debugRequiredFor, bool rootOverlay) {
    OverlayState result = rootOverlay? context.<OverlayState>findRootAncestorStateOfType() : context.<OverlayState>findAncestorStateOfType();
    assert(());
    return result;
}

OverlayState Overlay::createState() {
    return OverlayState();
}

void OverlayState::initState() {
    super.initState();
    insertAll(widget.initialEntries);
}

void OverlayState::insert(OverlayEntry above, OverlayEntry below, OverlayEntry entry) {
    assert(_debugVerifyInsertPosition(above, below));
    assert(!_entries.contains(entry), "The specified entry is already present in the Overlay.");
    assert(entry._overlay == nullptr, "The specified entry is already present in another Overlay.");
    entry._overlay = this;
    setState();
}

void OverlayState::insertAll(OverlayEntry above, OverlayEntry below, Iterable<OverlayEntry> entries) {
    assert(_debugVerifyInsertPosition(above, below));
    assert(entries.every(), "One or more of the specified entries are already present in the Overlay.");
    assert(entries.every(), "One or more of the specified entries are already present in another Overlay.");
    if (entries.isEmpty) {
        return;
    }
    for (OverlayEntry entry : entries) {
        assert(entry._overlay == nullptr);
        entry._overlay = this;
    }
    setState();
}

void OverlayState::rearrange(OverlayEntry above, OverlayEntry below, Iterable<OverlayEntry> newEntries) {
    List<OverlayEntry> newEntriesList = newEntries is List<OverlayEntry>? newEntries : newEntries.toList(false);
    assert(_debugVerifyInsertPosition(above, belownewEntriesList));
    assert(newEntriesList.every(), "One or more of the specified entries are already present in another Overlay.");
    assert(newEntriesList.every(), "One or more of the specified entries are specified multiple times.");
    if (newEntriesList.isEmpty) {
        return;
    }
    if (listEquals(_entries, newEntriesList)) {
        return;
    }
    LinkedHashSet<OverlayEntry> old = <OverlayEntry>of(_entries);
    for (OverlayEntry entry : newEntriesList) {
        entry._overlay = this;
    }
    setState();
}

bool OverlayState::debugIsVisible(OverlayEntry entry) {
    bool result = false;
    assert(_entries.contains(entry));
    assert(());
    return result;
}

Widget OverlayState::build(BuildContext context) {
    List<Widget> children = ;
    bool onstage = true;
    int onstageCount = 0;
    for (; i >= 0; i = 1) {
        OverlayEntry entry = _entries[i];
        if (onstage) {
            onstageCount = 1;
            children.add(_OverlayEntryWidget(entry._key, entry));
            if (entry.opaque) {
                onstage = false;
            }
        } else         {
            if (entry.maintainState) {
            children.add(_OverlayEntryWidget(entry._key, entry, false));
        }
;
        }    }
    return _Theatre(children.length - onstageCount, widget.clipBehavior, children.reversed.toList(false));
}

void OverlayState::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<List<OverlayEntry>>DiagnosticsProperty("entries", _entries));
}

int OverlayState::_insertionIndex(OverlayEntry above, OverlayEntry below) {
    assert(above == nullptr || below == nullptr);
    if (below != nullptr) {
        return _entries.indexOf(below);
    }
    if (above != nullptr) {
        return _entries.indexOf(above) + 1;
    }
    return _entries.length;
}

bool OverlayState::_debugVerifyInsertPosition(OverlayEntry above, OverlayEntry below, Iterable<OverlayEntry> newEntries) {
    assert(above == nullptr || below == nullptr, "Only one of `above` and `below` may be specified.");
    assert(above == nullptr || (above._overlay == this && _entries.contains(above) && (newEntries?.contains(above) ?? true)), "The provided entry used for `above` must be present in the Overlay${newEntries != null ? ' and in the `newEntriesList`' : ''}.");
    assert(below == nullptr || (below._overlay == this && _entries.contains(below) && (newEntries?.contains(below) ?? true)), "The provided entry used for `below` must be present in the Overlay${newEntries != null ? ' and in the `newEntriesList`' : ''}.");
    return true;
}

void OverlayState::_markDirty() {
    if (mounted) {
        setState();
    }
}

void OverlayState::_didChangeEntryOpacity() {
    setState();
}

_TheatreElement _Theatre::createElement() {
    return _TheatreElement(this);
}

_RenderTheatre _Theatre::createRenderObject(BuildContext context) {
    return _RenderTheatre(skipCount, Directionality.of(context), clipBehavior);
}

void _Theatre::updateRenderObject(BuildContext context, _RenderTheatre renderObject) {
    ;
}

void _Theatre::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(IntProperty("skipCount", skipCount));
}

_Theatre::_Theatre(Unknown, Clip clipBehavior, int skipCount) {
    {
        assert(skipCount != nullptr);
        assert(skipCount >= 0);
        assert(children != nullptr);
        assert(children.length >= skipCount);
        assert(clipBehavior != nullptr);
    }
}

_RenderTheatre _TheatreElement::renderObject() {
    return (;
}

void _TheatreElement::debugVisitOnstageChildren(ElementVisitor visitor) {
    _Theatre theatre = (;
    assert(children.length >= theatre.skipCount);
    children.skip(theatre.skipCount).forEach(visitor);
}

void _RenderTheatre::setupParentData(RenderBox child) {
    if (child.parentData is! StackParentData) {
        child.parentData = StackParentData();
    }
}

TextDirection _RenderTheatre::textDirection() {
    return _textDirection;
}

void _RenderTheatre::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    _markNeedResolution();
}

int _RenderTheatre::skipCount() {
    return _skipCount;
}

void _RenderTheatre::skipCount(int value) {
    assert(value != nullptr);
    if (_skipCount != value) {
        _skipCount = value;
        markNeedsLayout();
    }
}

Clip _RenderTheatre::clipBehavior() {
    return _clipBehavior;
}

void _RenderTheatre::clipBehavior(Clip value) {
    assert(value != nullptr);
    if (value != _clipBehavior) {
        _clipBehavior = value;
        markNeedsPaint();
        markNeedsSemanticsUpdate();
    }
}

double _RenderTheatre::computeMinIntrinsicWidth(double height) {
    return RenderStack.getIntrinsicDimension(_firstOnstageChild, );
}

double _RenderTheatre::computeMaxIntrinsicWidth(double height) {
    return RenderStack.getIntrinsicDimension(_firstOnstageChild, );
}

double _RenderTheatre::computeMinIntrinsicHeight(double width) {
    return RenderStack.getIntrinsicDimension(_firstOnstageChild, );
}

double _RenderTheatre::computeMaxIntrinsicHeight(double width) {
    return RenderStack.getIntrinsicDimension(_firstOnstageChild, );
}

double _RenderTheatre::computeDistanceToActualBaseline(TextBaseline baseline) {
    assert(!debugNeedsLayout);
    double result;
    RenderBox child = _firstOnstageChild;
    while (child != nullptr) {
        assert(!child.debugNeedsLayout);
        StackParentData childParentData = (;
        double candidate = child.getDistanceToActualBaseline(baseline);
        if (candidate != nullptr) {
            candidate = childParentData.offset.dy;
            if (result != nullptr) {
                result = math.min(result, candidate);
            } else {
                result = candidate;
            }
        }
        child = childParentData.nextSibling;
    }
    return result;
}

bool _RenderTheatre::sizedByParent() {
    return true;
}

Size _RenderTheatre::computeDryLayout(BoxConstraints constraints) {
    assert(constraints.biggest.isFinite);
    return constraints.biggest;
}

void _RenderTheatre::performLayout() {
    _hasVisualOverflow = false;
    if (_onstageChildCount == 0) {
        return;
    }
    _resolve();
    assert(_resolvedAlignment != nullptr);
    BoxConstraints nonPositionedConstraints = BoxConstraints.tight(constraints.biggest);
    RenderBox child = _firstOnstageChild;
    while (child != nullptr) {
        StackParentData childParentData = (;
        if (!childParentData.isPositioned) {
            child.layout(nonPositionedConstraintstrue);
            childParentData.offset = _resolvedAlignment!.alongOffset(();
        } else {
            _hasVisualOverflow = RenderStack.layoutPositionedChild(child, childParentData, size, _resolvedAlignment!) || _hasVisualOverflow;
        }
        assert(child.parentData == childParentData);
        child = childParentData.nextSibling;
    }
}

bool _RenderTheatre::hitTestChildren(Offset position, BoxHitTestResult result) {
    RenderBox child = _lastOnstageChild;
    for (;  < _onstageChildCount; i++) {
        assert(child != nullptr);
        StackParentData childParentData = (;
        bool isHit = result.addWithPaintOffset(childParentData.offset, position, );
        if (isHit) {
            return true;
        }
        child = childParentData.previousSibling;
    }
    return false;
}

void _RenderTheatre::paintStack(PaintingContext context, Offset offset) {
    RenderBox child = _firstOnstageChild;
    while (child != nullptr) {
        StackParentData childParentData = (;
        context.paintChild(child, childParentData.offset + offset);
        child = childParentData.nextSibling;
    }
}

void _RenderTheatre::paint(PaintingContext context, Offset offset) {
    if (_hasVisualOverflow && clipBehavior != Clip.none) {
        _clipRectLayer.layer = context.pushClipRect(needsCompositing, offset, Offset.zero & size, paintStackclipBehavior, _clipRectLayer.layer);
    } else {
        _clipRectLayer.layer = nullptr;
        paintStack(context, offset);
    }
}

void _RenderTheatre::dispose() {
    _clipRectLayer.layer = nullptr;
    super.dispose();
}

void _RenderTheatre::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    RenderBox child = _firstOnstageChild;
    while (child != nullptr) {
        visitor(child);
        StackParentData childParentData = (;
        child = childParentData.nextSibling;
    }
}

Rect _RenderTheatre::describeApproximatePaintClip(RenderObject child) {
    ;
}

void _RenderTheatre::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(IntProperty("skipCount", skipCount));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirection));
}

List<DiagnosticsNode> _RenderTheatre::debugDescribeChildren() {
    List<DiagnosticsNode> offstageChildren = ;
    List<DiagnosticsNode> onstageChildren = ;
    int count = 1;
    bool onstage = false;
    RenderBox child = firstChild;
    RenderBox firstOnstageChild = _firstOnstageChild;
    while (child != nullptr) {
        if (child == firstOnstageChild) {
            onstage = true;
            count = 1;
        }
        if (onstage) {
            onstageChildren.add(child.toDiagnosticsNode("onstage $count"));
        } else {
            offstageChildren.add(child.toDiagnosticsNode("offstage $count", DiagnosticsTreeStyle.offstage));
        }
        StackParentData childParentData = (;
        child = childParentData.nextSibling;
        count = 1;
    }
    return ;
}

_RenderTheatre::_RenderTheatre(List<RenderBox> children, Clip clipBehavior, int skipCount, TextDirection textDirection) {
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

void _RenderTheatre::_resolve() {
    if (_resolvedAlignment != nullptr) {
        return;
    }
    _resolvedAlignment = AlignmentDirectional.topStart.resolve(textDirection);
}

void _RenderTheatre::_markNeedResolution() {
    _resolvedAlignment = nullptr;
    markNeedsLayout();
}

RenderBox _RenderTheatre::_firstOnstageChild() {
    if (skipCount == super.childCount) {
        return nullptr;
    }
    RenderBox child = super.firstChild;
    for (; toSkip > 0; toSkip--) {
        StackParentData childParentData = (;
        child = childParentData.nextSibling;
        assert(child != nullptr);
    }
    return child;
}

RenderBox _RenderTheatre::_lastOnstageChild() {
    return skipCount == super.childCount? nullptr : lastChild;
}

int _RenderTheatre::_onstageChildCount() {
    return childCount - skipCount;
}
