#include "sliver.hpp"
int _kDefaultSemanticIndexCallback(Widget _, int localIndex) {
    return localIndex;
}

int SliverChildDelegateCls::estimatedChildCount() {
    return nullptr;
}

double SliverChildDelegateCls::estimateMaxScrollOffset(int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset) {
    return nullptr;
}

void SliverChildDelegateCls::didFinishLayout(int firstIndex, int lastIndex) {
}

int SliverChildDelegateCls::findIndexByKey(Key key) {
    return nullptr;
}

String SliverChildDelegateCls::toString() {
    List<String> description = makeList();
    debugFillDescription(description);
    return __s("${describeIdentity(this)}(${description.join(", ")})");
}

void SliverChildDelegateCls::debugFillDescription(List<String> description) {
    try {
        int children = estimatedChildCount();
        if (children != nullptr) {
            description->add(__s("estimated child count: $children"));
        }
    } catch (Unknown e) {
        description->add(__s("estimated child count: EXCEPTION (${e.runtimeType})"));
    };
}

_SaltedValueKeyCls::_SaltedValueKeyCls(Unknown key) {
    {
        assert(key != nullptr);
    }
}

SliverChildBuilderDelegateCls::SliverChildBuilderDelegateCls(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, NullableIndexedWidgetBuilder builder, int childCount, ChildIndexGetter findChildIndexCallback, SemanticIndexCallback semanticIndexCallback, int semanticIndexOffset) {
    {
        assert(builder != nullptr);
        assert(addAutomaticKeepAlives != nullptr);
        assert(addRepaintBoundaries != nullptr);
        assert(addSemanticIndexes != nullptr);
        assert(semanticIndexCallback != nullptr);
    }
}

int SliverChildBuilderDelegateCls::findIndexByKey(Key key) {
    if (findChildIndexCallback == nullptr) {
        return nullptr;
    }
    assert(key != nullptr);
    Key childKey;
    if (is<_SaltedValueKey>(key)) {
        _SaltedValueKey saltedValueKey = key;
        childKey = saltedValueKey->value;
    } else {
        childKey = key;
    }
    return findChildIndexCallback!(childKey);
}

Widget SliverChildBuilderDelegateCls::build(BuildContext context, int index) {
    assert(builder != nullptr);
    if ( < 0 || (childCount != nullptr && index >= childCount!)) {
        return nullptr;
    }
    Widget child;
    try {
        child = builder(context, index);
    } catch (Unknown exception) {
        child = _createErrorWidget(exception, stackTrace);
    };
    if (child == nullptr) {
        return nullptr;
    }
    Key key = child->key != nullptr? make<_SaltedValueKeyCls>(child->key!) : nullptr;
    if (addRepaintBoundaries) {
        child = make<RepaintBoundaryCls>(child);
    }
    if (addSemanticIndexes) {
        int semanticIndex = semanticIndexCallback(child, index);
        if (semanticIndex != nullptr) {
            child = make<IndexedSemanticsCls>(semanticIndex + semanticIndexOffset, child);
        }
    }
    if (addAutomaticKeepAlives) {
        child = make<AutomaticKeepAliveCls>(make<_SelectionKeepAliveCls>(child));
    }
    return make<KeyedSubtreeCls>(key, child);
}

int SliverChildBuilderDelegateCls::estimatedChildCount() {
    return childCount;
}

bool SliverChildBuilderDelegateCls::shouldRebuild(SliverChildBuilderDelegate oldDelegate) {
    return true;
}

SliverChildListDelegateCls::SliverChildListDelegateCls(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, List<Widget> children, SemanticIndexCallback semanticIndexCallback, int semanticIndexOffset) {
    {
        assert(children != nullptr);
        assert(addAutomaticKeepAlives != nullptr);
        assert(addRepaintBoundaries != nullptr);
        assert(addSemanticIndexes != nullptr);
        assert(semanticIndexCallback != nullptr);
            Map<Key, int> map1 = make<MapCls<>>();    map1.set(nullptr, 0);_keyToIndex = list1;
    }
}

void SliverChildListDelegateCls::fixed(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, List<Widget> children, SemanticIndexCallback semanticIndexCallback, int semanticIndexOffset)

int SliverChildListDelegateCls::findIndexByKey(Key key) {
    assert(key != nullptr);
    Key childKey;
    if (is<_SaltedValueKey>(key)) {
        _SaltedValueKey saltedValueKey = key;
        childKey = saltedValueKey->value;
    } else {
        childKey = key;
    }
    return _findChildIndex(childKey);
}

Widget SliverChildListDelegateCls::build(BuildContext context, int index) {
    assert(children != nullptr);
    if ( < 0 || index >= children->length()) {
        return nullptr;
    }
    Widget child = children[index];
    Key key = child->key != nullptr? make<_SaltedValueKeyCls>(child->key!) : nullptr;
    assert(child != nullptr, __s("The sliver's children must not contain null values, but a null value was found at index $index"));
    if (addRepaintBoundaries) {
        child = make<RepaintBoundaryCls>(child);
    }
    if (addSemanticIndexes) {
        int semanticIndex = semanticIndexCallback(child, index);
        if (semanticIndex != nullptr) {
            child = make<IndexedSemanticsCls>(semanticIndex + semanticIndexOffset, child);
        }
    }
    if (addAutomaticKeepAlives) {
        child = make<AutomaticKeepAliveCls>(make<_SelectionKeepAliveCls>(child));
    }
    return make<KeyedSubtreeCls>(key, child);
}

int SliverChildListDelegateCls::estimatedChildCount() {
    return children->length();
}

bool SliverChildListDelegateCls::shouldRebuild(SliverChildListDelegate oldDelegate) {
    return children != oldDelegate->children;
}

bool SliverChildListDelegateCls::_isConstantInstance() {
    return _keyToIndex == nullptr;
}

int SliverChildListDelegateCls::_findChildIndex(Key key) {
    if (_isConstantInstance()) {
        return nullptr;
    }
    if (!_keyToIndex!->containsKey(key)) {
        int index = _keyToIndex![nullptr]!;
        while ( < children->length()) {
            Widget child = children[index];
            if (child->key != nullptr) {
                _keyToIndex![child->key] = index;
            }
            if (child->key == key) {
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

State<_SelectionKeepAlive> _SelectionKeepAliveCls::createState() {
    return make<_SelectionKeepAliveStateCls>();
}

bool _SelectionKeepAliveStateCls::wantKeepAlive() {
    return _wantKeepAlive;
}

void _SelectionKeepAliveStateCls::wantKeepAlive(bool value) {
    if (_wantKeepAlive != value) {
        _wantKeepAlive = value;
        updateKeepAlive();
    }
}

VoidCallback _SelectionKeepAliveStateCls::listensTo(Selectable selectable) {
    return [=] () {
        if (selectable->value->hasSelection) {
            _updateSelectablesWithSelections(selectabletrue);
        } else {
            _updateSelectablesWithSelections(selectablefalse);
        }
    };
}

void _SelectionKeepAliveStateCls::didChangeDependencies() {
    super->didChangeDependencies();
    SelectionRegistrar newRegistrar = SelectionContainerCls->maybeOf(context);
    if (_registrar != newRegistrar) {
        if (_registrar != nullptr) {
            _selectableAttachments?->keys()->forEach(_registrar!->remove);
        }
        _registrar = newRegistrar;
        if (_registrar != nullptr) {
            _selectableAttachments?->keys()->forEach(_registrar!->add);
        }
    }
}

void _SelectionKeepAliveStateCls::add(Selectable selectable) {
    VoidCallback attachment = listensTo(selectable);
    selectable->addListener(attachment);
    _selectableAttachments = makeMap(makeList(), makeList();
    _selectableAttachments![selectable] = attachment;
    _registrar!->add(selectable);
    if (selectable->value->hasSelection) {
        _updateSelectablesWithSelections(selectabletrue);
    }
}

void _SelectionKeepAliveStateCls::remove(Selectable selectable) {
    if (_selectableAttachments == nullptr) {
        return;
    }
    assert(_selectableAttachments!->containsKey(selectable));
    VoidCallback attachment = _selectableAttachments!->remove(selectable)!;
    selectable->removeListener(attachment);
    _registrar!->remove(selectable);
    _updateSelectablesWithSelections(selectablefalse);
}

void _SelectionKeepAliveStateCls::dispose() {
    if (_selectableAttachments != nullptr) {
        for (Selectable selectable : _selectableAttachments!->keys()) {
            _registrar!->remove(selectable);
            selectable->removeListener(_selectableAttachments![selectable]!);
        }
        _selectableAttachments = nullptr;
    }
    _selectablesWithSelections = nullptr;
    super->dispose();
}

Widget _SelectionKeepAliveStateCls::build(BuildContext context) {
    super->build(context);
    if (_registrar == nullptr) {
        return widget->child;
    }
    return make<SelectionRegistrarScopeCls>(this, widget->child);
}

void _SelectionKeepAliveStateCls::_updateSelectablesWithSelections(bool add, Selectable selectable) {
    if (add) {
        assert(selectable->value->hasSelection);
        _selectablesWithSelections = makeSet();
        _selectablesWithSelections!->add(selectable);
    } else {
        _selectablesWithSelections?->remove(selectable);
    }
    wantKeepAlive() = _selectablesWithSelections?->isNotEmpty or false;
}

SliverMultiBoxAdaptorWidgetCls::SliverMultiBoxAdaptorWidgetCls(SliverChildDelegate delegate, Unknown key) {
    {
        assert(delegate != nullptr);
    }
}

SliverMultiBoxAdaptorElement SliverMultiBoxAdaptorWidgetCls::createElement() {
    return make<SliverMultiBoxAdaptorElementCls>(this);
}

double SliverMultiBoxAdaptorWidgetCls::estimateMaxScrollOffset(SliverConstraints constraints, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset) {
    assert(lastIndex >= firstIndex);
    return delegate->estimateMaxScrollOffset(firstIndex, lastIndex, leadingScrollOffset, trailingScrollOffset);
}

void SliverMultiBoxAdaptorWidgetCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<SliverChildDelegate>make<DiagnosticsPropertyCls>(__s("delegate"), delegate));
}

SliverMultiBoxAdaptorElement SliverListCls::createElement() {
    return make<SliverMultiBoxAdaptorElementCls>(thistrue);
}

RenderSliverList SliverListCls::createRenderObject(BuildContext context) {
    SliverMultiBoxAdaptorElement element = as<SliverMultiBoxAdaptorElement>(context);
    return make<RenderSliverListCls>(element);
}

RenderSliverFixedExtentList SliverFixedExtentListCls::createRenderObject(BuildContext context) {
    SliverMultiBoxAdaptorElement element = as<SliverMultiBoxAdaptorElement>(context);
    return make<RenderSliverFixedExtentListCls>(element, itemExtent);
}

void SliverFixedExtentListCls::updateRenderObject(BuildContext context, RenderSliverFixedExtentList renderObject) {
    renderObject->itemExtent = itemExtent;
}

void SliverGridCls::count(double childAspectRatio, List<Widget> children, int crossAxisCount, double crossAxisSpacing, Unknown key, double mainAxisSpacing)

void SliverGridCls::extent(double childAspectRatio, List<Widget> children, double crossAxisSpacing, Unknown key, double mainAxisSpacing, double maxCrossAxisExtent)

RenderSliverGrid SliverGridCls::createRenderObject(BuildContext context) {
    SliverMultiBoxAdaptorElement element = as<SliverMultiBoxAdaptorElement>(context);
    return make<RenderSliverGridCls>(element, gridDelegate);
}

void SliverGridCls::updateRenderObject(BuildContext context, RenderSliverGrid renderObject) {
    renderObject->gridDelegate = gridDelegate;
}

double SliverGridCls::estimateMaxScrollOffset(SliverConstraints constraints, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset) {
    return super->estimateMaxScrollOffset(constraints, firstIndex, lastIndex, leadingScrollOffset, trailingScrollOffset) or gridDelegate->getLayout(constraints!)->computeMaxScrollOffset(delegate->estimatedChildCount!);
}

SliverMultiBoxAdaptorElementCls::SliverMultiBoxAdaptorElementCls(bool replaceMovedChildren, SliverMultiBoxAdaptorWidget widget) {
    {
        _replaceMovedChildren = replaceMovedChildren;
    }
}

RenderSliverMultiBoxAdaptor SliverMultiBoxAdaptorElementCls::renderObject() {
    return as<RenderSliverMultiBoxAdaptor>(super->renderObject);
}

void SliverMultiBoxAdaptorElementCls::update(SliverMultiBoxAdaptorWidget newWidget) {
    SliverMultiBoxAdaptorWidget oldWidget = as<SliverMultiBoxAdaptorWidget>(widget);
    super->update(newWidget);
    SliverChildDelegate newDelegate = newWidget->delegate;
    SliverChildDelegate oldDelegate = oldWidget->delegate;
    if (newDelegate != oldDelegate && (newDelegate->runtimeType() != oldDelegate->runtimeType() || newDelegate->shouldRebuild(oldDelegate))) {
        performRebuild();
    }
}

void SliverMultiBoxAdaptorElementCls::performRebuild() {
    super->performRebuild();
    _currentBeforeChild = nullptr;
    bool childrenUpdated = false;
    assert(_currentlyUpdatingChildIndex == nullptr);
    try {
        SplayTreeMap<int, Element> newChildren = <int, Element>make<SplayTreeMapCls>();
        Map<int, double> indexToLayoutOffset = <int, double>make<HashMapCls>();
        SliverMultiBoxAdaptorWidget adaptorWidget = as<SliverMultiBoxAdaptorWidget>(widget);
        InlineMethod;
        for (int index : _childElements->keys()->toList()) {
            Key key = _childElements[index]!->widget->key;
            int newIndex = key == nullptr? nullptr : adaptorWidget->delegate->findIndexByKey(key);
            SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(_childElements[index]!->renderObject?->parentData);
            if (childParentData != nullptr && childParentData->layoutOffset != nullptr) {
                indexToLayoutOffset[index] = childParentData->layoutOffset!;
            }
            if (newIndex != nullptr && newIndex != index) {
                if (childParentData != nullptr) {
                    childParentData->layoutOffset = nullptr;
                }
                newChildren[newIndex] = _childElements[index];
                if (_replaceMovedChildren) {
                    newChildren->putIfAbsent(index, [=] ()                     {
                        nullptr;
                    });
                }
                _childElements->remove(index);
            } else {
                newChildren->putIfAbsent(index, [=] ()                 {
                    _childElements[index];
                });
            }
        }
        renderObject()->debugChildIntegrityEnabled() = false;
        newChildren->keys->forEach(processElement);
        if (!childrenUpdated && _didUnderflow) {
            int lastKey = _childElements->lastKey() or -1;
            int rightBoundary = lastKey + 1;
            newChildren[rightBoundary] = _childElements[rightBoundary];
            processElement(rightBoundary);
        }
    } finally {
        _currentlyUpdatingChildIndex = nullptr;
        renderObject()->debugChildIntegrityEnabled() = true;
    };
}

void SliverMultiBoxAdaptorElementCls::createChild(RenderBox after, int index) {
    assert(_currentlyUpdatingChildIndex == nullptr);
    owner!->buildScope(this, [=] () {
        bool insertFirst = after == nullptr;
        assert(insertFirst || _childElements[index - 1] != nullptr);
        _currentBeforeChild = insertFirst? nullptr : (as<RenderBox>(_childElements[index - 1]!->renderObject));
        Element newChild;
        try {
            SliverMultiBoxAdaptorWidget adaptorWidget = as<SliverMultiBoxAdaptorWidget>(widget);
            _currentlyUpdatingChildIndex = index;
            newChild = updateChild(_childElements[index], _build(index, adaptorWidget), index);
        } finally {
            _currentlyUpdatingChildIndex = nullptr;
        };
        if (newChild != nullptr) {
            _childElements[index] = newChild;
        } else {
            _childElements->remove(index);
        }
    });
}

Element SliverMultiBoxAdaptorElementCls::updateChild(Element child, Object newSlot, Widget newWidget) {
    SliverMultiBoxAdaptorParentData oldParentData = as<SliverMultiBoxAdaptorParentData>(child?->renderObject?->parentData);
    Element newChild = super->updateChild(child, newWidget, newSlot);
    SliverMultiBoxAdaptorParentData newParentData = as<SliverMultiBoxAdaptorParentData>(newChild?->renderObject?->parentData);
    if (oldParentData != newParentData && oldParentData != nullptr && newParentData != nullptr) {
        newParentData->layoutOffset = oldParentData->layoutOffset;
    }
    return newChild;
}

void SliverMultiBoxAdaptorElementCls::forgetChild(Element child) {
    assert(child != nullptr);
    assert(child->slot != nullptr);
    assert(_childElements->containsKey(child->slot));
    _childElements->remove(child->slot);
    super->forgetChild(child);
}

void SliverMultiBoxAdaptorElementCls::removeChild(RenderBox child) {
    int index = renderObject()->indexOf(child);
    assert(_currentlyUpdatingChildIndex == nullptr);
    assert(index >= 0);
    owner!->buildScope(this, [=] () {
        assert(_childElements->containsKey(index));
        try {
            _currentlyUpdatingChildIndex = index;
            Element result = updateChild(_childElements[index], nullptr, index);
            assert(result == nullptr);
        } finally {
            _currentlyUpdatingChildIndex = nullptr;
        };
        _childElements->remove(index);
        assert(!_childElements->containsKey(index));
    });
}

double SliverMultiBoxAdaptorElementCls::estimateMaxScrollOffset(SliverConstraints constraints, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset) {
    int childCount = estimatedChildCount();
    if (childCount() == nullptr) {
        return double->infinity;
    }
    return (as<SliverMultiBoxAdaptorWidget>(widget))->estimateMaxScrollOffset(constraints, firstIndex!, lastIndex!, leadingScrollOffset!, trailingScrollOffset!) or _extrapolateMaxScrollOffset(firstIndex, lastIndex, leadingScrollOffset, trailingScrollOffset, childCount());
}

int SliverMultiBoxAdaptorElementCls::estimatedChildCount() {
    return (as<SliverMultiBoxAdaptorWidget>(widget))->delegate->estimatedChildCount();
}

int SliverMultiBoxAdaptorElementCls::childCount() {
    int result = estimatedChildCount();
    if (result == nullptr) {
        int lo = 0;
        int hi = 1;
        SliverMultiBoxAdaptorWidget adaptorWidget = as<SliverMultiBoxAdaptorWidget>(widget);
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

void SliverMultiBoxAdaptorElementCls::didStartLayout() {
    assert(debugAssertChildListLocked());
}

void SliverMultiBoxAdaptorElementCls::didFinishLayout() {
    assert(debugAssertChildListLocked());
    int firstIndex = _childElements->firstKey() or 0;
    int lastIndex = _childElements->lastKey() or 0;
    (as<SliverMultiBoxAdaptorWidget>(widget))->delegate->didFinishLayout(firstIndex, lastIndex);
}

bool SliverMultiBoxAdaptorElementCls::debugAssertChildListLocked() {
    assert(_currentlyUpdatingChildIndex == nullptr);
    return true;
}

void SliverMultiBoxAdaptorElementCls::didAdoptChild(RenderBox child) {
    assert(_currentlyUpdatingChildIndex != nullptr);
    SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(child->parentData!);
    childParentData->index = _currentlyUpdatingChildIndex;
}

void SliverMultiBoxAdaptorElementCls::setDidUnderflow(bool value) {
    _didUnderflow = value;
}

void SliverMultiBoxAdaptorElementCls::insertRenderObjectChild(RenderObject child, int slot) {
    assert(slot != nullptr);
    assert(_currentlyUpdatingChildIndex == slot);
    assert(renderObject()->debugValidateChild(child));
    renderObject()->insert(as<RenderBox>(child)_currentBeforeChild);
    assert([=] () {
        SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(child->parentData!);
        assert(slot == childParentData->index);
        return true;
    }());
}

void SliverMultiBoxAdaptorElementCls::moveRenderObjectChild(RenderObject child, int newSlot, int oldSlot) {
    assert(newSlot != nullptr);
    assert(_currentlyUpdatingChildIndex == newSlot);
    renderObject()->move(as<RenderBox>(child)_currentBeforeChild);
}

void SliverMultiBoxAdaptorElementCls::removeRenderObjectChild(RenderObject child, int slot) {
    assert(_currentlyUpdatingChildIndex != nullptr);
    renderObject()->remove(as<RenderBox>(child));
}

void SliverMultiBoxAdaptorElementCls::visitChildren(ElementVisitor visitor) {
    assert(!_childElements->values()->any([=] (Element child)     {
        child == nullptr;
    }));
    _childElements->values()-><Element>cast()->toList()->forEach(visitor);
}

void SliverMultiBoxAdaptorElementCls::debugVisitOnstageChildren(ElementVisitor visitor) {
    _childElements->values()-><Element>cast()->where([=] (Element child) {
        SliverMultiBoxAdaptorParentData parentData = as<SliverMultiBoxAdaptorParentData>(child->renderObject!->parentData!);
        double itemExtent;
        ;
        return parentData->layoutOffset != nullptr && parentData->layoutOffset! < renderObject()->constraints->scrollOffset + renderObject()->constraints->remainingPaintExtent && parentData->layoutOffset! + itemExtent > renderObject()->constraints->scrollOffset;
    })->forEach(visitor);
}

Widget SliverMultiBoxAdaptorElementCls::_build(int index, SliverMultiBoxAdaptorWidget widget) {
    return widget->delegate->build(this, index);
}

double SliverMultiBoxAdaptorElementCls::_extrapolateMaxScrollOffset(int childCount, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset) {
    if (lastIndex == childCount - 1) {
        return trailingScrollOffset;
    }
    int reifiedCount = lastIndex - firstIndex + 1;
    double averageExtent = (trailingScrollOffset - leadingScrollOffset) / reifiedCount;
    int remainingCount = childCount - lastIndex - 1;
    return trailingScrollOffset + averageExtent * remainingCount;
}

SliverOpacityCls::SliverOpacityCls(bool alwaysIncludeSemantics, Unknown key, double opacity, Widget sliver) : SingleChildRenderObjectWidget(sliver) {
    {
        assert(opacity != nullptr && opacity >= 0.0 && opacity <= 1.0);
        assert(alwaysIncludeSemantics != nullptr);
    }
}

RenderSliverOpacity SliverOpacityCls::createRenderObject(BuildContext context) {
    return make<RenderSliverOpacityCls>(opacity, alwaysIncludeSemantics);
}

void SliverOpacityCls::updateRenderObject(BuildContext context, RenderSliverOpacity renderObject) {
    auto _c1 = renderObject;_c1.opacity = auto _c2 = opacity;_c2.alwaysIncludeSemantics = alwaysIncludeSemantics;_c2;_c1;
}

void SliverOpacityCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<double>make<DiagnosticsPropertyCls>(__s("opacity"), opacity));
    properties->add(make<FlagPropertyCls>(__s("alwaysIncludeSemantics")alwaysIncludeSemantics, __s("alwaysIncludeSemantics")));
}

SliverIgnorePointerCls::SliverIgnorePointerCls(bool ignoring, bool ignoringSemantics, Unknown key, Widget sliver) : SingleChildRenderObjectWidget(sliver) {
    {
        assert(ignoring != nullptr);
    }
}

RenderSliverIgnorePointer SliverIgnorePointerCls::createRenderObject(BuildContext context) {
    return make<RenderSliverIgnorePointerCls>(ignoring, ignoringSemantics);
}

void SliverIgnorePointerCls::updateRenderObject(BuildContext context, RenderSliverIgnorePointer renderObject) {
    auto _c1 = renderObject;_c1.ignoring = auto _c2 = ignoring;_c2.ignoringSemantics = ignoringSemantics;_c2;_c1;
}

void SliverIgnorePointerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("ignoring"), ignoring));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("ignoringSemantics"), ignoringSemanticsnullptr));
}

SliverOffstageCls::SliverOffstageCls(Unknown key, bool offstage, Widget sliver) : SingleChildRenderObjectWidget(sliver) {
    {
        assert(offstage != nullptr);
    }
}

RenderSliverOffstage SliverOffstageCls::createRenderObject(BuildContext context) {
    return make<RenderSliverOffstageCls>(offstage);
}

void SliverOffstageCls::updateRenderObject(BuildContext context, RenderSliverOffstage renderObject) {
    renderObject->offstage = offstage;
}

void SliverOffstageCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("offstage"), offstage));
}

SingleChildRenderObjectElement SliverOffstageCls::createElement() {
    return make<_SliverOffstageElementCls>(this);
}

void _SliverOffstageElementCls::debugVisitOnstageChildren(ElementVisitor visitor) {
    if (!(as<SliverOffstage>(widget))->offstage) {
        super->debugVisitOnstageChildren(visitor);
    }
}

KeepAliveCls::KeepAliveCls(Unknown child, bool keepAlive, Unknown key) {
    {
        assert(child != nullptr);
        assert(keepAlive != nullptr);
    }
}

void KeepAliveCls::applyParentData(RenderObject renderObject) {
    assert(is<KeepAliveParentDataMixin>(renderObject->parentData));
    KeepAliveParentDataMixin parentData = as<KeepAliveParentDataMixin>(renderObject->parentData!);
    if (parentData->keepAlive != keepAlive) {
        parentData->keepAlive = keepAlive;
        AbstractNode targetParent = renderObject->parent;
        if (is<RenderObject>(targetParent) && !keepAlive) {
            targetParent->markNeedsLayout();
        }
    }
}

bool KeepAliveCls::debugCanApplyOutOfTurn() {
    return keepAlive;
}

Type KeepAliveCls::debugTypicalAncestorWidgetClass() {
    return SliverWithKeepAliveWidgetCls;
}

void KeepAliveCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("keepAlive"), keepAlive));
}

Widget _createErrorWidget(Object exception, StackTrace stackTrace) {
    FlutterErrorDetails details = make<FlutterErrorDetailsCls>(exception, stackTrace, __s("widgets library"), make<ErrorDescriptionCls>(__s("building")));
    FlutterErrorCls->reportError(details);
    return ErrorWidgetCls->builder(details);
}
