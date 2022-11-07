#include "sliver.hpp"
int _kDefaultSemanticIndexCallback(Widget _, int localIndex) {
    return localIndex;
}

int SliverChildDelegate::estimatedChildCount() {
    return nullptr;
}

double SliverChildDelegate::estimateMaxScrollOffset(int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset) {
    return nullptr;
}

void SliverChildDelegate::didFinishLayout(int firstIndex, int lastIndex) {
}

int SliverChildDelegate::findIndexByKey(Key key) {
    return nullptr;
}

String SliverChildDelegate::toString() {
    List<String> description = ;
    debugFillDescription(description);
    return "${describeIdentity(this)}(${description.join(", ")})";
}

void SliverChildDelegate::debugFillDescription(List<String> description) {
    ;
}

_SaltedValueKey::_SaltedValueKey(Unknown) {
    {
        assert(key != nullptr);
    }
}

SliverChildBuilderDelegate::SliverChildBuilderDelegate(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, NullableIndexedWidgetBuilder builder, int childCount, ChildIndexGetter findChildIndexCallback, SemanticIndexCallback semanticIndexCallback, int semanticIndexOffset) {
    {
        assert(builder != nullptr);
        assert(addAutomaticKeepAlives != nullptr);
        assert(addRepaintBoundaries != nullptr);
        assert(addSemanticIndexes != nullptr);
        assert(semanticIndexCallback != nullptr);
    }
}

int SliverChildBuilderDelegate::findIndexByKey(Key key) {
    if (findChildIndexCallback == nullptr) {
        return nullptr;
    }
    assert(key != nullptr);
    Key childKey;
    if (key is _SaltedValueKey) {
        _SaltedValueKey saltedValueKey = key;
        childKey = saltedValueKey.value;
    } else {
        childKey = key;
    }
    return findChildIndexCallback!(childKey);
}

Widget SliverChildBuilderDelegate::build(BuildContext context, int index) {
    assert(builder != nullptr);
    if ( < 0 || (childCount != nullptr && index >= childCount!)) {
        return nullptr;
    }
    Widget child;
    ;
    if (child == nullptr) {
        return nullptr;
    }
    Key key = child.key != nullptr? _SaltedValueKey(child.key!) : nullptr;
    if (addRepaintBoundaries) {
        child = RepaintBoundary(child);
    }
    if (addSemanticIndexes) {
        int semanticIndex = semanticIndexCallback(child, index);
        if (semanticIndex != nullptr) {
            child = IndexedSemantics(semanticIndex + semanticIndexOffset, child);
        }
    }
    if (addAutomaticKeepAlives) {
        child = AutomaticKeepAlive(_SelectionKeepAlive(child));
    }
    return KeyedSubtree(key, child);
}

int SliverChildBuilderDelegate::estimatedChildCount() {
    return childCount;
}

bool SliverChildBuilderDelegate::shouldRebuild(SliverChildBuilderDelegate oldDelegate) {
    return true;
}

SliverChildListDelegate::SliverChildListDelegate(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, List<Widget> children, SemanticIndexCallback semanticIndexCallback, int semanticIndexOffset) {
    {
        assert(children != nullptr);
        assert(addAutomaticKeepAlives != nullptr);
        assert(addRepaintBoundaries != nullptr);
        assert(addSemanticIndexes != nullptr);
        assert(semanticIndexCallback != nullptr);
        _keyToIndex = ;
    }
}

void SliverChildListDelegate::fixed(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, List<Widget> children, SemanticIndexCallback semanticIndexCallback, int semanticIndexOffset)

int SliverChildListDelegate::findIndexByKey(Key key) {
    assert(key != nullptr);
    Key childKey;
    if (key is _SaltedValueKey) {
        _SaltedValueKey saltedValueKey = key;
        childKey = saltedValueKey.value;
    } else {
        childKey = key;
    }
    return _findChildIndex(childKey);
}

Widget SliverChildListDelegate::build(BuildContext context, int index) {
    assert(children != nullptr);
    if ( < 0 || index >= children.length) {
        return nullptr;
    }
    Widget child = children[index];
    Key key = child.key != nullptr? _SaltedValueKey(child.key!) : nullptr;
    assert(child != nullptr, "The sliver's children must not contain null values, but a null value was found at index $index");
    if (addRepaintBoundaries) {
        child = RepaintBoundary(child);
    }
    if (addSemanticIndexes) {
        int semanticIndex = semanticIndexCallback(child, index);
        if (semanticIndex != nullptr) {
            child = IndexedSemantics(semanticIndex + semanticIndexOffset, child);
        }
    }
    if (addAutomaticKeepAlives) {
        child = AutomaticKeepAlive(_SelectionKeepAlive(child));
    }
    return KeyedSubtree(key, child);
}

int SliverChildListDelegate::estimatedChildCount() {
    return children.length;
}

bool SliverChildListDelegate::shouldRebuild(SliverChildListDelegate oldDelegate) {
    return children != oldDelegate.children;
}

bool SliverChildListDelegate::_isConstantInstance() {
    return _keyToIndex == nullptr;
}

int SliverChildListDelegate::_findChildIndex(Key key) {
    if (_isConstantInstance) {
        return nullptr;
    }
    if (!_keyToIndex!.containsKey(key)) {
        int index = _keyToIndex![nullptr]!;
        while ( < children.length) {
            Widget child = children[index];
            if (child.key != nullptr) {
                _keyToIndex![child.key] = index;
            }
            if (child.key == key) {
                _keyToIndex![nullptr] = index + 1;
                return index;
            }
            index = 1;
        }
        _keyToIndex![nullptr] = index;
    } else {
        return _keyToIndex![key];
    }
    return nullptr;
}

State<_SelectionKeepAlive> _SelectionKeepAlive::createState() {
    return _SelectionKeepAliveState();
}

bool _SelectionKeepAliveState::wantKeepAlive() {
    return _wantKeepAlive;
}

void _SelectionKeepAliveState::wantKeepAlive(bool value) {
    if (_wantKeepAlive != value) {
        _wantKeepAlive = value;
        updateKeepAlive();
    }
}

VoidCallback _SelectionKeepAliveState::listensTo(Selectable selectable) {
    return ;
}

void _SelectionKeepAliveState::didChangeDependencies() {
    super.didChangeDependencies();
    SelectionRegistrar newRegistrar = SelectionContainer.maybeOf(context);
    if (_registrar != newRegistrar) {
        if (_registrar != nullptr) {
            _selectableAttachments?.keys.forEach(_registrar!.remove);
        }
        _registrar = newRegistrar;
        if (_registrar != nullptr) {
            _selectableAttachments?.keys.forEach(_registrar!.add);
        }
    }
}

void _SelectionKeepAliveState::add(Selectable selectable) {
    VoidCallback attachment = listensTo(selectable);
    selectable.addListener(attachment);
    _selectableAttachments = ;
    _selectableAttachments![selectable] = attachment;
    _registrar!.add(selectable);
    if (selectable.value.hasSelection) {
        _updateSelectablesWithSelections(selectabletrue);
    }
}

void _SelectionKeepAliveState::remove(Selectable selectable) {
    if (_selectableAttachments == nullptr) {
        return;
    }
    assert(_selectableAttachments!.containsKey(selectable));
    VoidCallback attachment = _selectableAttachments!.remove(selectable)!;
    selectable.removeListener(attachment);
    _registrar!.remove(selectable);
    _updateSelectablesWithSelections(selectablefalse);
}

void _SelectionKeepAliveState::dispose() {
    if (_selectableAttachments != nullptr) {
        for (Selectable selectable : _selectableAttachments!.keys) {
            _registrar!.remove(selectable);
            selectable.removeListener(_selectableAttachments![selectable]!);
        }
        _selectableAttachments = nullptr;
    }
    _selectablesWithSelections = nullptr;
    super.dispose();
}

Widget _SelectionKeepAliveState::build(BuildContext context) {
    super.build(context);
    if (_registrar == nullptr) {
        return widget.child;
    }
    return SelectionRegistrarScope(this, widget.child);
}

void _SelectionKeepAliveState::_updateSelectablesWithSelections(bool add, Selectable selectable) {
    if (add) {
        assert(selectable.value.hasSelection);
        _selectablesWithSelections = ;
        _selectablesWithSelections!.add(selectable);
    } else {
        _selectablesWithSelections?.remove(selectable);
    }
    wantKeepAlive = _selectablesWithSelections?.isNotEmpty ?? false;
}

SliverMultiBoxAdaptorWidget::SliverMultiBoxAdaptorWidget(SliverChildDelegate delegate, Unknown) {
    {
        assert(delegate != nullptr);
    }
}

SliverMultiBoxAdaptorElement SliverMultiBoxAdaptorWidget::createElement() {
    return SliverMultiBoxAdaptorElement(this);
}

double SliverMultiBoxAdaptorWidget::estimateMaxScrollOffset(SliverConstraints constraints, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset) {
    assert(lastIndex >= firstIndex);
    return delegate.estimateMaxScrollOffset(firstIndex, lastIndex, leadingScrollOffset, trailingScrollOffset);
}

void SliverMultiBoxAdaptorWidget::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<SliverChildDelegate>DiagnosticsProperty("delegate", delegate));
}

SliverMultiBoxAdaptorElement SliverList::createElement() {
    return SliverMultiBoxAdaptorElement(thistrue);
}

RenderSliverList SliverList::createRenderObject(BuildContext context) {
    SliverMultiBoxAdaptorElement element = (;
    return RenderSliverList(element);
}

RenderSliverFixedExtentList SliverFixedExtentList::createRenderObject(BuildContext context) {
    SliverMultiBoxAdaptorElement element = (;
    return RenderSliverFixedExtentList(element, itemExtent);
}

void SliverFixedExtentList::updateRenderObject(BuildContext context, RenderSliverFixedExtentList renderObject) {
    renderObject.itemExtent = itemExtent;
}

void SliverGrid::count(double childAspectRatio, List<Widget> children, int crossAxisCount, double crossAxisSpacing, Unknown, double mainAxisSpacing)

void SliverGrid::extent(double childAspectRatio, List<Widget> children, double crossAxisSpacing, Unknown, double mainAxisSpacing, double maxCrossAxisExtent)

RenderSliverGrid SliverGrid::createRenderObject(BuildContext context) {
    SliverMultiBoxAdaptorElement element = (;
    return RenderSliverGrid(element, gridDelegate);
}

void SliverGrid::updateRenderObject(BuildContext context, RenderSliverGrid renderObject) {
    renderObject.gridDelegate = gridDelegate;
}

double SliverGrid::estimateMaxScrollOffset(SliverConstraints constraints, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset) {
    return super.estimateMaxScrollOffset(constraints, firstIndex, lastIndex, leadingScrollOffset, trailingScrollOffset) ?? gridDelegate.getLayout(constraints!).computeMaxScrollOffset(delegate.estimatedChildCount!);
}

SliverMultiBoxAdaptorElement::SliverMultiBoxAdaptorElement(bool replaceMovedChildren, SliverMultiBoxAdaptorWidget widget) {
    {
        _replaceMovedChildren = replaceMovedChildren;
    }
}

RenderSliverMultiBoxAdaptor SliverMultiBoxAdaptorElement::renderObject() {
    return (;
}

void SliverMultiBoxAdaptorElement::update(SliverMultiBoxAdaptorWidget newWidget) {
    SliverMultiBoxAdaptorWidget oldWidget = (;
    super.update(newWidget);
    SliverChildDelegate newDelegate = newWidget.delegate;
    SliverChildDelegate oldDelegate = oldWidget.delegate;
    if (newDelegate != oldDelegate && (newDelegate.runtimeType != oldDelegate.runtimeType || newDelegate.shouldRebuild(oldDelegate))) {
        performRebuild();
    }
}

void SliverMultiBoxAdaptorElement::performRebuild() {
    super.performRebuild();
    _currentBeforeChild = nullptr;
    bool childrenUpdated = false;
    assert(_currentlyUpdatingChildIndex == nullptr);
    ;
}

void SliverMultiBoxAdaptorElement::createChild(RenderBox after, int index) {
    assert(_currentlyUpdatingChildIndex == nullptr);
    owner!.buildScope(this, );
}

Element SliverMultiBoxAdaptorElement::updateChild(Element child, Object newSlot, Widget newWidget) {
    SliverMultiBoxAdaptorParentData oldParentData = (;
    Element newChild = super.updateChild(child, newWidget, newSlot);
    SliverMultiBoxAdaptorParentData newParentData = (;
    if (oldParentData != newParentData && oldParentData != nullptr && newParentData != nullptr) {
        newParentData.layoutOffset = oldParentData.layoutOffset;
    }
    return newChild;
}

void SliverMultiBoxAdaptorElement::forgetChild(Element child) {
    assert(child != nullptr);
    assert(child.slot != nullptr);
    assert(_childElements.containsKey(child.slot));
    _childElements.remove(child.slot);
    super.forgetChild(child);
}

void SliverMultiBoxAdaptorElement::removeChild(RenderBox child) {
    int index = renderObject.indexOf(child);
    assert(_currentlyUpdatingChildIndex == nullptr);
    assert(index >= 0);
    owner!.buildScope(this, );
}

double SliverMultiBoxAdaptorElement::estimateMaxScrollOffset(SliverConstraints constraints, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset) {
    int childCount = estimatedChildCount;
    if (childCount == nullptr) {
        return double.infinity;
    }
    return (().estimateMaxScrollOffset(constraints, firstIndex!, lastIndex!, leadingScrollOffset!, trailingScrollOffset!) ?? _extrapolateMaxScrollOffset(firstIndex, lastIndex, leadingScrollOffset, trailingScrollOffset, childCount);
}

int SliverMultiBoxAdaptorElement::estimatedChildCount() {
    return (().delegate.estimatedChildCount;
}

int SliverMultiBoxAdaptorElement::childCount() {
    int result = estimatedChildCount;
    if (result == nullptr) {
        int lo = 0;
        int hi = 1;
        SliverMultiBoxAdaptorWidget adaptorWidget = (;
        int max = kIsWeb? 9007199254740992 : ((1 << 63) - 1);
        while (_build(hi - 1, adaptorWidget) != nullptr) {
            lo = hi - 1;
            if ( < max ~/ 2) {
                hi = 2;
            } else             {
                if ( < max) {
                hi = max;
            } else {
                ;
            }
;
            }        }
        while (hi - lo > 1) {
            int mid = (hi - lo) ~/ 2 + lo;
            if (_build(mid - 1, adaptorWidget) == nullptr) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        result = lo;
    }
    return result;
}

void SliverMultiBoxAdaptorElement::didStartLayout() {
    assert(debugAssertChildListLocked());
}

void SliverMultiBoxAdaptorElement::didFinishLayout() {
    assert(debugAssertChildListLocked());
    int firstIndex = _childElements.firstKey() ?? 0;
    int lastIndex = _childElements.lastKey() ?? 0;
    (().delegate.didFinishLayout(firstIndex, lastIndex);
}

bool SliverMultiBoxAdaptorElement::debugAssertChildListLocked() {
    assert(_currentlyUpdatingChildIndex == nullptr);
    return true;
}

void SliverMultiBoxAdaptorElement::didAdoptChild(RenderBox child) {
    assert(_currentlyUpdatingChildIndex != nullptr);
    SliverMultiBoxAdaptorParentData childParentData = (;
    childParentData.index = _currentlyUpdatingChildIndex;
}

void SliverMultiBoxAdaptorElement::setDidUnderflow(bool value) {
    _didUnderflow = value;
}

void SliverMultiBoxAdaptorElement::insertRenderObjectChild(RenderObject child, int slot) {
    assert(slot != nullptr);
    assert(_currentlyUpdatingChildIndex == slot);
    assert(renderObject.debugValidateChild(child));
    renderObject.insert((_currentBeforeChild);
    assert(());
}

void SliverMultiBoxAdaptorElement::moveRenderObjectChild(RenderObject child, int newSlot, int oldSlot) {
    assert(newSlot != nullptr);
    assert(_currentlyUpdatingChildIndex == newSlot);
    renderObject.move((_currentBeforeChild);
}

void SliverMultiBoxAdaptorElement::removeRenderObjectChild(RenderObject child, int slot) {
    assert(_currentlyUpdatingChildIndex != nullptr);
    renderObject.remove(();
}

void SliverMultiBoxAdaptorElement::visitChildren(ElementVisitor visitor) {
    assert(!_childElements.values.any());
    _childElements.values.<Element>cast().toList().forEach(visitor);
}

void SliverMultiBoxAdaptorElement::debugVisitOnstageChildren(ElementVisitor visitor) {
    _childElements.values.<Element>cast().where().forEach(visitor);
}

Widget SliverMultiBoxAdaptorElement::_build(int index, SliverMultiBoxAdaptorWidget widget) {
    return widget.delegate.build(this, index);
}

double SliverMultiBoxAdaptorElement::_extrapolateMaxScrollOffset(int childCount, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset) {
    if (lastIndex == childCount - 1) {
        return trailingScrollOffset;
    }
    int reifiedCount = lastIndex - firstIndex + 1;
    double averageExtent = (trailingScrollOffset - leadingScrollOffset) / reifiedCount;
    int remainingCount = childCount - lastIndex - 1;
    return trailingScrollOffset + averageExtent * remainingCount;
}

SliverOpacity::SliverOpacity(bool alwaysIncludeSemantics, Unknown, double opacity, Widget sliver) {
    {
        assert(opacity != nullptr && opacity >= 0.0 && opacity <= 1.0);
        assert(alwaysIncludeSemantics != nullptr);
        super(sliver);
    }
}

RenderSliverOpacity SliverOpacity::createRenderObject(BuildContext context) {
    return RenderSliverOpacity(opacity, alwaysIncludeSemantics);
}

void SliverOpacity::updateRenderObject(BuildContext context, RenderSliverOpacity renderObject) {
    ;
}

void SliverOpacity::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<double>DiagnosticsProperty("opacity", opacity));
    properties.add(FlagProperty("alwaysIncludeSemantics"alwaysIncludeSemantics, "alwaysIncludeSemantics"));
}

SliverIgnorePointer::SliverIgnorePointer(bool ignoring, bool ignoringSemantics, Unknown, Widget sliver) {
    {
        assert(ignoring != nullptr);
        super(sliver);
    }
}

RenderSliverIgnorePointer SliverIgnorePointer::createRenderObject(BuildContext context) {
    return RenderSliverIgnorePointer(ignoring, ignoringSemantics);
}

void SliverIgnorePointer::updateRenderObject(BuildContext context, RenderSliverIgnorePointer renderObject) {
    ;
}

void SliverIgnorePointer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<bool>DiagnosticsProperty("ignoring", ignoring));
    properties.add(<bool>DiagnosticsProperty("ignoringSemantics", ignoringSemanticsnullptr));
}

SliverOffstage::SliverOffstage(Unknown, bool offstage, Widget sliver) {
    {
        assert(offstage != nullptr);
        super(sliver);
    }
}

RenderSliverOffstage SliverOffstage::createRenderObject(BuildContext context) {
    return RenderSliverOffstage(offstage);
}

void SliverOffstage::updateRenderObject(BuildContext context, RenderSliverOffstage renderObject) {
    renderObject.offstage = offstage;
}

void SliverOffstage::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<bool>DiagnosticsProperty("offstage", offstage));
}

SingleChildRenderObjectElement SliverOffstage::createElement() {
    return _SliverOffstageElement(this);
}

void _SliverOffstageElement::debugVisitOnstageChildren(ElementVisitor visitor) {
    if (!(().offstage) {
        super.debugVisitOnstageChildren(visitor);
    }
}

KeepAlive::KeepAlive(Unknown, bool keepAlive, Unknown) {
    {
        assert(child != nullptr);
        assert(keepAlive != nullptr);
    }
}

void KeepAlive::applyParentData(RenderObject renderObject) {
    assert(renderObject.parentData is KeepAliveParentDataMixin);
    KeepAliveParentDataMixin parentData = (;
    if (parentData.keepAlive != keepAlive) {
        parentData.keepAlive = keepAlive;
        AbstractNode targetParent = renderObject.parent;
        if (targetParent is RenderObject && !keepAlive) {
            targetParent.markNeedsLayout();
        }
    }
}

bool KeepAlive::debugCanApplyOutOfTurn() {
    return keepAlive;
}

Type KeepAlive::debugTypicalAncestorWidgetClass() {
    return SliverWithKeepAliveWidget;
}

void KeepAlive::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<bool>DiagnosticsProperty("keepAlive", keepAlive));
}

Widget _createErrorWidget(Object exception, StackTrace stackTrace) {
    FlutterErrorDetails details = FlutterErrorDetails(exception, stackTrace, "widgets library", ErrorDescription("building"));
    FlutterError.reportError(details);
    return ErrorWidget.builder(details);
}
