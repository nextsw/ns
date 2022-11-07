#include "framework.hpp"
bool ObjectKey::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is ObjectKey && identical(other.value, value);
}

int ObjectKey::hashCode() {
    return Object.hash(runtimeType, identityHashCode(value));
}

String ObjectKey::toString() {
    if (runtimeType == ObjectKey) {
        return "[${describeIdentity(value)}]";
    }
    return "[${objectRuntimeType(this, 'ObjectKey')} ${describeIdentity(value)}]";
}

GlobalKey::GlobalKey(String debugLabel) {
}

void GlobalKey::constructor()

BuildContext GlobalKey::currentContext() {
    return _currentElement;
}

Widget GlobalKey::currentWidget() {
    return _currentElement?.widget;
}

T GlobalKey::currentState() {
    Element element = _currentElement;
    if (element is StatefulElement) {
        StatefulElement statefulElement = element;
        State state = statefulElement.state;
        if (state is T) {
            return state;
        }
    }
    return nullptr;
}

Element GlobalKey::_currentElement() {
    return WidgetsBinding.instance.buildOwner!._globalKeyRegistry[this];
}

LabeledGlobalKey::LabeledGlobalKey(String _debugLabel) {
    {
        super.constructor();
    }
}

String LabeledGlobalKey::toString() {
    String label = _debugLabel != nullptr? " $_debugLabel" : "";
    if (runtimeType == LabeledGlobalKey) {
        return "[GlobalKey#${shortHash(this)}$label]";
    }
    return "[${describeIdentity(this)}$label]";
}

GlobalObjectKey::GlobalObjectKey(Object value) {
    {
        super.constructor();
    }
}

bool GlobalObjectKey::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is GlobalObjectKey<T> && identical(other.value, value);
}

int GlobalObjectKey::hashCode() {
    return identityHashCode(value);
}

String GlobalObjectKey::toString() {
    String selfType = objectRuntimeType(this, "GlobalObjectKey");
    String suffix = "<State<StatefulWidget>>";
    if (selfType.endsWith(suffix)) {
        selfType = selfType.substring(0, selfType.length - suffix.length);
    }
    return "[$selfType ${describeIdentity(value)}]";
}

String Widget::toStringShort() {
    String type = objectRuntimeType(this, "Widget");
    return key == nullptr? type : "$type-$key";
}

void Widget::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.defaultDiagnosticsTreeStyle = DiagnosticsTreeStyle.dense;
}

bool Widget::==(Object other) {
    return super == other;
}

int Widget::hashCode() {
    return super.hashCode;
}

bool Widget::canUpdate(Widget newWidget, Widget oldWidget) {
    return oldWidget.runtimeType == newWidget.runtimeType && oldWidget.key == newWidget.key;
}

int Widget::_debugConcreteSubtype(Widget widget) {
    return widget is StatefulWidget? 1 : widget is StatelessWidget? 2 : 0;
}

StatelessElement StatelessWidget::createElement() {
    return StatelessElement(this);
}

StatefulElement StatefulWidget::createElement() {
    return StatefulElement(this);
}

T State::widget() {
    return _widget!;
}

BuildContext State::context() {
    assert(());
    return _element!;
}

bool State::mounted() {
    return _element != nullptr;
}

void State::initState() {
    assert(_debugLifecycleState == _StateLifecycle.created);
}

void State::didUpdateWidget(T oldWidget) {
}

void State::reassemble() {
}

void State::setState(VoidCallback fn) {
    assert(fn != nullptr);
    assert(());
    Object result = (;
    assert(());
    _element!.markNeedsBuild();
}

void State::deactivate() {
}

void State::activate() {
}

void State::dispose() {
    assert(_debugLifecycleState == _StateLifecycle.ready);
    assert(());
}

void State::didChangeDependencies() {
}

void State::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    assert(());
    properties.add(<T>ObjectFlagProperty("_widget", _widget"no widget"));
    properties.add(<StatefulElement>ObjectFlagProperty("_element", _element"not mounted"));
}

bool State::_debugTypesAreRight(Widget widget) {
    return widget is T;
}

ParentDataElement<T> ParentDataWidget::createElement() {
    return <T>ParentDataElement(this);
}

bool ParentDataWidget::debugIsValidRenderObject(RenderObject renderObject) {
    assert(T != dynamic);
    assert(T != ParentData);
    return renderObject.parentData is T;
}

bool ParentDataWidget::debugCanApplyOutOfTurn() {
    return false;
}

Iterable<DiagnosticsNode> ParentDataWidget::_debugDescribeIncorrectParentDataType(DiagnosticsNode ownershipChain, ParentData parentData, RenderObjectWidget parentDataCreator) {
    assert(T != dynamic);
    assert(T != ParentData);
    assert(debugTypicalAncestorWidgetClass != nullptr);
    String description = "The ParentDataWidget $this wants to apply ParentData of type $T to a RenderObject";
    return ;
}

InheritedElement InheritedWidget::createElement() {
    return InheritedElement(this);
}

void RenderObjectWidget::updateRenderObject(BuildContext context, RenderObject renderObject) {
}

void RenderObjectWidget::didUnmountRenderObject(RenderObject renderObject) {
}

LeafRenderObjectElement LeafRenderObjectWidget::createElement() {
    return LeafRenderObjectElement(this);
}

SingleChildRenderObjectElement SingleChildRenderObjectWidget::createElement() {
    return SingleChildRenderObjectElement(this);
}

MultiChildRenderObjectWidget::MultiChildRenderObjectWidget(List<Widget> children, Unknown) {
    {
        assert(children != nullptr);
    }
    {
        assert(());
    }
}

MultiChildRenderObjectElement MultiChildRenderObjectWidget::createElement() {
    return MultiChildRenderObjectElement(this);
}

void _InactiveElements::add(Element element) {
    assert(!_locked);
    assert(!_elements.contains(element));
    assert(element._parent == nullptr);
    if (element._lifecycleState == _ElementLifecycle.active) {
        _deactivateRecursively(element);
    }
    _elements.add(element);
}

void _InactiveElements::remove(Element element) {
    assert(!_locked);
    assert(_elements.contains(element));
    assert(element._parent == nullptr);
    _elements.remove(element);
    assert(element._lifecycleState != _ElementLifecycle.active);
}

bool _InactiveElements::debugContains(Element element) {
    bool result;
    assert(());
    return result;
}

void _InactiveElements::_unmount(Element element) {
    assert(element._lifecycleState == _ElementLifecycle.inactive);
    assert(());
    element.visitChildren();
    element.unmount();
    assert(element._lifecycleState == _ElementLifecycle.defunct);
}

void _InactiveElements::_unmountAll() {
    _locked = true;
    List<Element> elements = ;
    _elements.clear();
    ;
}

void _InactiveElements::_deactivateRecursively(Element element) {
    assert(element._lifecycleState == _ElementLifecycle.active);
    element.deactivate();
    assert(element._lifecycleState == _ElementLifecycle.inactive);
    element.visitChildren(_deactivateRecursively);
    assert(());
}

BuildOwner::BuildOwner(FocusManager focusManager, VoidCallback onBuildScheduled) {
    {
        focusManager = focusManager ?? ();
    }
}

void BuildOwner::scheduleBuildFor(Element element) {
    assert(element != nullptr);
    assert(element.owner == this);
    assert(());
    if (element._inDirtyList) {
        assert(());
        _dirtyElementsNeedsResorting = true;
        return;
    }
    if (!_scheduledFlushDirtyElements && onBuildScheduled != nullptr) {
        _scheduledFlushDirtyElements = true;
        onBuildScheduled!();
    }
    _dirtyElements.add(element);
    element._inDirtyList = true;
    assert(());
}

bool BuildOwner::debugBuilding() {
    return _debugBuilding;
}

void BuildOwner::lockState(VoidCallback callback) {
    assert(callback != nullptr);
    assert(_debugStateLockLevel >= 0);
    assert(());
    ;
    assert(_debugStateLockLevel >= 0);
}

void BuildOwner::buildScope(VoidCallback callback, Element context) {
    if (callback == nullptr && _dirtyElements.isEmpty) {
        return;
    }
    assert(context != nullptr);
    assert(_debugStateLockLevel >= 0);
    assert(!_debugBuilding);
    assert(());
    if (!kReleaseMode) {
        Map<String, String> debugTimelineArguments;
        assert(());
        Timeline.startSync("BUILD"debugTimelineArguments);
    }
    ;
    assert(_debugStateLockLevel >= 0);
}

int BuildOwner::globalKeyCount() {
    return _globalKeyRegistry.length;
}

void BuildOwner::finalizeTree() {
    if (!kReleaseMode) {
        Timeline.startSync("FINALIZE TREE");
    }
    ;
}

void BuildOwner::reassemble(DebugReassembleConfig reassembleConfig, Element root) {
    if (!kReleaseMode) {
        Timeline.startSync("Preparing Hot Reload (widgets)");
    }
    ;
}

bool BuildOwner::_debugIsInBuildScope() {
    return _dirtyElementsNeedsResorting != nullptr;
}

bool BuildOwner::_debugStateLocked() {
    return _debugStateLockLevel > 0;
}

void BuildOwner::_debugTrackElementThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans(GlobalKey key, Element node) {
    _debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans = <Element, Set<GlobalKey>>HashMap();
    Set<GlobalKey> keys = _debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans!.putIfAbsent(node, );
    keys.add(key);
}

void BuildOwner::_debugElementWasRebuilt(Element node) {
    _debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans?.remove(node);
}

void BuildOwner::_debugRemoveGlobalKeyReservationFor(Element child, Element parent) {
    assert(());
}

void BuildOwner::_registerGlobalKey(Element element, GlobalKey key) {
    assert(());
    _globalKeyRegistry[key] = element;
}

void BuildOwner::_unregisterGlobalKey(Element element, GlobalKey key) {
    assert(());
    if (_globalKeyRegistry[key] == element) {
        _globalKeyRegistry.remove(key);
    }
}

void BuildOwner::_debugReserveGlobalKeyFor(Element child, GlobalKey key, Element parent) {
    assert(());
}

void BuildOwner::_debugVerifyGlobalKeyReservation() {
    assert(());
}

void BuildOwner::_debugVerifyIllFatedPopulation() {
    assert(());
}

void NotifiableElementMixin::attachNotificationTree() {
    _notificationTree = _NotificationNode(_parent?._notificationTree, this);
}

void _NotificationNode::dispatchNotification(Notification notification) {
    if (current?.onNotification(notification) ?? true) {
        return;
    }
    parent?.dispatchNotification(notification);
}

bool _isProfileBuildsEnabledFor(Widget widget) {
    return debugProfileBuildsEnabled || (debugProfileBuildsEnabledUserWidgets && debugIsWidgetLocalCreation(widget));
}

Element::Element(Widget widget) {
    {
        assert(widget != nullptr);
        _widget = widget;
    }
}

bool Element::==(Object other) {
    return identical(this, other);
}

Object Element::slot() {
    return _slot;
}

int Element::depth() {
    assert(());
    return _depth;
}

Widget Element::widget() {
    return _widget!;
}

bool Element::debugIsDefunct() {
    bool isDefunct = false;
    assert(());
    return isDefunct;
}

bool Element::debugIsActive() {
    bool isActive = false;
    assert(());
    return isActive;
}

BuildOwner Element::owner() {
    return _owner;
}

void Element::reassemble() {
    if (_debugShouldReassemble(_debugReassembleConfig, _widget)) {
        markNeedsBuild();
        _debugReassembleConfig = nullptr;
    }
    visitChildren();
    _debugReassembleConfig = nullptr;
}

RenderObject Element::renderObject() {
    RenderObject result;
    ;
    visit(this);
    return result;
}

List<DiagnosticsNode> Element::describeMissingAncestor(Type expectedAncestorType) {
    List<DiagnosticsNode> information = ;
    List<Element> ancestors = ;
    visitAncestorElements();
    information.add(<Element>DiagnosticsProperty("The specific widget that could not find a $expectedAncestorType ancestor was", thisDiagnosticsTreeStyle.errorProperty));
    if (ancestors.isNotEmpty) {
        information.add(describeElements("The ancestors of this widget were", ancestors));
    } else {
        information.add(ErrorDescription("This widget is the root of the tree, so it has no ancestors, let alone a "$expectedAncestorType" ancestor."));
    }
    return information;
}

DiagnosticsNode Element::describeElements(Iterable<Element> elements, String name) {
    return DiagnosticsBlock(name, elements.<DiagnosticsNode>map().toList(), true);
}

DiagnosticsNode Element::describeElement(String name, DiagnosticsTreeStyle style) {
    return <Element>DiagnosticsProperty(name, thisstyle);
}

DiagnosticsNode Element::describeWidget(String name, DiagnosticsTreeStyle style) {
    return <Element>DiagnosticsProperty(name, thisstyle);
}

DiagnosticsNode Element::describeOwnershipChain(String name) {
    return StringProperty(name, debugGetCreatorChain(10));
}

void Element::visitChildren(ElementVisitor visitor) {
}

void Element::debugVisitOnstageChildren(ElementVisitor visitor) {
    return visitChildren(visitor);
}

void Element::visitChildElements(ElementVisitor visitor) {
    assert(());
    visitChildren(visitor);
}

Element Element::updateChild(Element child, Object newSlot, Widget newWidget) {
    if (newWidget == nullptr) {
        if (child != nullptr) {
            deactivateChild(child);
        }
        return nullptr;
    }
    Element newChild;
    if (child != nullptr) {
        bool hasSameSuperclass = true;
        assert(());
        if (hasSameSuperclass && child.widget == newWidget) {
            if (child.slot != newSlot) {
                updateSlotForChild(child, newSlot);
            }
            newChild = child;
        } else         {
            if (hasSameSuperclass && Widget.canUpdate(child.widget, newWidget)) {
            if (child.slot != newSlot) {
                updateSlotForChild(child, newSlot);
            }
            bool isTimelineTracked = !kReleaseMode && _isProfileBuildsEnabledFor(newWidget);
            if (isTimelineTracked) {
                Map<String, String> debugTimelineArguments;
                assert(());
                Timeline.startSync("${newWidget.runtimeType}"debugTimelineArguments);
            }
            child.update(newWidget);
            if (isTimelineTracked) {
                Timeline.finishSync();
            }
            assert(child.widget == newWidget);
            assert(());
            newChild = child;
        } else {
            deactivateChild(child);
            assert(child._parent == nullptr);
            newChild = inflateWidget(newWidget, newSlot);
        }
;
        }    } else {
        newChild = inflateWidget(newWidget, newSlot);
    }
    assert(());
    return newChild;
}

void Element::mount(Object newSlot, Element parent) {
    assert(_lifecycleState == _ElementLifecycle.initial);
    assert(widget != nullptr);
    assert(_parent == nullptr);
    assert(parent == nullptr || parent._lifecycleState == _ElementLifecycle.active);
    assert(slot == nullptr);
    _parent = parent;
    _slot = newSlot;
    _lifecycleState = _ElementLifecycle.active;
    _depth = _parent != nullptr? _parent!.depth + 1 : 1;
    if (parent != nullptr) {
        _owner = parent.owner;
    }
    assert(owner != nullptr);
    Key key = widget.key;
    if (key is GlobalKey) {
        owner!._registerGlobalKey(key, this);
    }
    _updateInheritance();
    attachNotificationTree();
}

void Element::update(Widget newWidget) {
    assert(_lifecycleState == _ElementLifecycle.active && widget != nullptr && newWidget != nullptr && newWidget != widget && depth != nullptr && Widget.canUpdate(widget, newWidget));
    assert(());
    _widget = newWidget;
}

void Element::updateSlotForChild(Element child, Object newSlot) {
    assert(_lifecycleState == _ElementLifecycle.active);
    assert(child != nullptr);
    assert(child._parent == this);
    ;
    visit(child);
}

void Element::detachRenderObject() {
    visitChildren();
    _slot = nullptr;
}

void Element::attachRenderObject(Object newSlot) {
    assert(_slot == nullptr);
    visitChildren();
    _slot = newSlot;
}

Element Element::inflateWidget(Object newSlot, Widget newWidget) {
    assert(newWidget != nullptr);
    bool isTimelineTracked = !kReleaseMode && _isProfileBuildsEnabledFor(newWidget);
    if (isTimelineTracked) {
        Map<String, String> debugTimelineArguments;
        assert(());
        Timeline.startSync("${newWidget.runtimeType}"debugTimelineArguments);
    }
    ;
}

void Element::deactivateChild(Element child) {
    assert(child != nullptr);
    assert(child._parent == this);
    child._parent = nullptr;
    child.detachRenderObject();
    owner!._inactiveElements.add(child);
    assert(());
}

void Element::forgetChild(Element child) {
    assert(());
}

void Element::activate() {
    assert(_lifecycleState == _ElementLifecycle.inactive);
    assert(widget != nullptr);
    assert(owner != nullptr);
    assert(depth != nullptr);
    bool hadDependencies = (_dependencies != nullptr && _dependencies!.isNotEmpty) || _hadUnsatisfiedDependencies;
    _lifecycleState = _ElementLifecycle.active;
    _dependencies?.clear();
    _hadUnsatisfiedDependencies = false;
    _updateInheritance();
    attachNotificationTree();
    if (_dirty) {
        owner!.scheduleBuildFor(this);
    }
    if (hadDependencies) {
        didChangeDependencies();
    }
}

void Element::deactivate() {
    assert(_lifecycleState == _ElementLifecycle.active);
    assert(_widget != nullptr);
    assert(depth != nullptr);
    if (_dependencies != nullptr && _dependencies!.isNotEmpty) {
        for (InheritedElement dependency : _dependencies!) {
            dependency._dependents.remove(this);
        }
    }
    _inheritedWidgets = nullptr;
    _lifecycleState = _ElementLifecycle.inactive;
}

void Element::debugDeactivated() {
    assert(_lifecycleState == _ElementLifecycle.inactive);
}

void Element::unmount() {
    assert(_lifecycleState == _ElementLifecycle.inactive);
    assert(_widget != nullptr);
    assert(depth != nullptr);
    assert(owner != nullptr);
    Key key = _widget?.key;
    if (key is GlobalKey) {
        owner!._unregisterGlobalKey(key, this);
    }
    _widget = nullptr;
    _dependencies = nullptr;
    _lifecycleState = _ElementLifecycle.defunct;
}

RenderObject Element::findRenderObject() {
    assert(());
    return renderObject;
}

Size Element::size() {
    assert(());
    RenderObject renderObject = findRenderObject();
    assert(());
    if (renderObject is RenderBox) {
        return renderObject.size;
    }
    return nullptr;
}

bool Element::doesDependOnInheritedElement(InheritedElement ancestor) {
    return _dependencies != nullptr && _dependencies!.contains(ancestor);
}

InheritedWidget Element::dependOnInheritedElement(InheritedElement ancestor, Object aspect) {
    assert(ancestor != nullptr);
    _dependencies = <InheritedElement>HashSet();
    _dependencies!.add(ancestor);
    ancestor.updateDependencies(this, aspect);
    return (;
}

T Element::dependOnInheritedWidgetOfExactType<T extends InheritedWidget>(Object aspect) {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    InheritedElement ancestor = _inheritedWidgets == nullptr? nullptr : _inheritedWidgets![T];
    if (ancestor != nullptr) {
        return (;
    }
    _hadUnsatisfiedDependencies = true;
    return nullptr;
}

InheritedElement Element::getElementForInheritedWidgetOfExactType<T extends InheritedWidget>() {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    InheritedElement ancestor = _inheritedWidgets == nullptr? nullptr : _inheritedWidgets![T];
    return ancestor;
}

void Element::attachNotificationTree() {
    _notificationTree = _parent?._notificationTree;
}

T Element::findAncestorWidgetOfExactType<T extends Widget>() {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    Element ancestor = _parent;
    while (ancestor != nullptr && ancestor.widget.runtimeType != T) {
        ancestor = ancestor._parent;
    }
    return (;
}

T Element::findAncestorStateOfType<T extends State<StatefulWidget>>() {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    Element ancestor = _parent;
    while (ancestor != nullptr) {
        if (ancestor is StatefulElement && ancestor.state is T) {
                        break;
        }
        ancestor = ancestor._parent;
    }
    StatefulElement statefulAncestor = (;
    return (;
}

T Element::findRootAncestorStateOfType<T extends State<StatefulWidget>>() {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    Element ancestor = _parent;
    StatefulElement statefulAncestor;
    while (ancestor != nullptr) {
        if (ancestor is StatefulElement && ancestor.state is T) {
            statefulAncestor = ancestor;
        }
        ancestor = ancestor._parent;
    }
    return (;
}

T Element::findAncestorRenderObjectOfType<T extends RenderObject>() {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    Element ancestor = _parent;
    while (ancestor != nullptr) {
        if (ancestor is RenderObjectElement && ancestor.renderObject is T) {
            return (;
        }
        ancestor = ancestor._parent;
    }
    return nullptr;
}

void Element::visitAncestorElements(FunctionType visitor) {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    Element ancestor = _parent;
    while (ancestor != nullptr && visitor(ancestor)) {
        ancestor = ancestor._parent;
    }
}

void Element::didChangeDependencies() {
    assert(_lifecycleState == _ElementLifecycle.active);
    assert(_debugCheckOwnerBuildTargetExists("didChangeDependencies"));
    markNeedsBuild();
}

String Element::debugGetCreatorChain(int limit) {
    List<String> chain = ;
    Element node = this;
    while (chain.length < limit && node != nullptr) {
        chain.add(node.toStringShort());
        node = node._parent;
    }
    if (node != nullptr) {
        chain.add("\u22EF");
    }
    return chain.join(" \u2190 ");
}

List<Element> Element::debugGetDiagnosticChain() {
    List<Element> chain = ;
    Element node = _parent;
    while (node != nullptr) {
        chain.add(node);
        node = node._parent;
    }
    return chain;
}

void Element::dispatchNotification(Notification notification) {
    _notificationTree?.dispatchNotification(notification);
}

String Element::toStringShort() {
    return _widget?.toStringShort() ?? "${describeIdentity(this)}(DEFUNCT)";
}

DiagnosticsNode Element::toDiagnosticsNode(String name, DiagnosticsTreeStyle style) {
    return _ElementDiagnosticableTreeNode(name, this, style);
}

void Element::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.defaultDiagnosticsTreeStyle = DiagnosticsTreeStyle.dense;
    if (_lifecycleState != _ElementLifecycle.initial) {
        properties.add(<int>ObjectFlagProperty("depth", depth"no depth"));
    }
    properties.add(<Widget>ObjectFlagProperty("widget", _widget"no widget"));
    properties.add(<Key>DiagnosticsProperty("key", _widget?.keyfalse, nullptr, DiagnosticLevel.hidden));
    _widget?.debugFillProperties(properties);
    properties.add(FlagProperty("dirty"dirty, "dirty"));
    Set<InheritedElement> deps = _dependencies;
    if (deps != nullptr && deps.isNotEmpty) {
        List<InheritedElement> sortedDependencies = ;
        List<DiagnosticsNode> diagnosticsDependencies = sortedDependencies.map().toList();
        properties.add(<List<DiagnosticsNode>>DiagnosticsProperty("dependencies", diagnosticsDependencies));
    }
}

List<DiagnosticsNode> Element::debugDescribeChildren() {
    List<DiagnosticsNode> children = ;
    visitChildren();
    return children;
}

bool Element::dirty() {
    return _dirty;
}

void Element::markNeedsBuild() {
    assert(_lifecycleState != _ElementLifecycle.defunct);
    if (_lifecycleState != _ElementLifecycle.active) {
        return;
    }
    assert(owner != nullptr);
    assert(_lifecycleState == _ElementLifecycle.active);
    assert(());
    if (dirty) {
        return;
    }
    _dirty = true;
    owner!.scheduleBuildFor(this);
}

void Element::rebuild() {
    assert(_lifecycleState != _ElementLifecycle.initial);
    if (_lifecycleState != _ElementLifecycle.active || !_dirty) {
        return;
    }
    assert(());
    assert(_lifecycleState == _ElementLifecycle.active);
    assert(owner!._debugStateLocked);
    Element debugPreviousBuildTarget;
    assert(());
    performRebuild();
    assert(());
    assert(!_dirty);
}

int Element::_sort(Element a, Element b) {
    int diff = a.depth - b.depth;
    if (diff != 0) {
        return diff;
    }
    bool isBDirty = b.dirty;
    if (a.dirty != isBDirty) {
        return isBDirty? -1 : 1;
    }
    return 0;
}

int Element::_debugConcreteSubtype(Element element) {
    return element is StatefulElement? 1 : element is StatelessElement? 2 : 0;
}

bool Element::_debugIsInScope(Element target) {
    Element current = this;
    while (current != nullptr) {
        if (target == current) {
            return true;
        }
        current = current._parent;
    }
    return false;
}

void Element::_debugRemoveGlobalKeyReservation(Element child) {
    assert(owner != nullptr);
    owner!._debugRemoveGlobalKeyReservationFor(this, child);
}

void Element::_updateSlot(Object newSlot) {
    assert(_lifecycleState == _ElementLifecycle.active);
    assert(widget != nullptr);
    assert(_parent != nullptr);
    assert(_parent!._lifecycleState == _ElementLifecycle.active);
    assert(depth != nullptr);
    _slot = newSlot;
}

void Element::_updateDepth(int parentDepth) {
    int expectedDepth = parentDepth + 1;
    if ( < expectedDepth) {
        _depth = expectedDepth;
        visitChildren();
    }
}

Element Element::_retakeInactiveElement(GlobalKey key, Widget newWidget) {
    Element element = key._currentElement;
    if (element == nullptr) {
        return nullptr;
    }
    if (!Widget.canUpdate(element.widget, newWidget)) {
        return nullptr;
    }
    assert(());
    Element parent = element._parent;
    if (parent != nullptr) {
        assert(());
        parent.forgetChild(element);
        parent.deactivateChild(element);
    }
    assert(element._parent == nullptr);
    owner!._inactiveElements.remove(element);
    return element;
}

void Element::_debugCheckForCycles(Element newChild) {
    assert(newChild._parent == nullptr);
    assert(());
}

void Element::_activateWithParent(Object newSlot, Element parent) {
    assert(_lifecycleState == _ElementLifecycle.inactive);
    _parent = parent;
    assert(());
    _updateDepth(_parent!.depth);
    _activateRecursively(this);
    attachRenderObject(newSlot);
    assert(_lifecycleState == _ElementLifecycle.active);
}

void Element::_activateRecursively(Element element) {
    assert(element._lifecycleState == _ElementLifecycle.inactive);
    element.activate();
    assert(element._lifecycleState == _ElementLifecycle.active);
    element.visitChildren(_activateRecursively);
}

bool Element::_debugCheckStateIsActiveForAncestorLookup() {
    assert(());
    return true;
}

void Element::_updateInheritance() {
    assert(_lifecycleState == _ElementLifecycle.active);
    _inheritedWidgets = _parent?._inheritedWidgets;
}

bool Element::_debugCheckOwnerBuildTargetExists(String methodName) {
    assert(());
    return true;
}

bool Element::_debugSetAllowIgnoredCallsToMarkNeedsBuild(bool value) {
    assert(_debugAllowIgnoredCallsToMarkNeedsBuild == !value);
    _debugAllowIgnoredCallsToMarkNeedsBuild = value;
    return true;
}

Map<String, Object> _ElementDiagnosticableTreeNode::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> json = super.toJsonMap(delegate);
    Element element = (;
    if (!element.debugIsDefunct) {
        json["widgetRuntimeType"] = element.widget.runtimeType.toString();
    }
    json["stateful"] = stateful;
    return json;
}

ErrorWidget::ErrorWidget(Object exception) {
    {
        message = _stringify(exception);
        _flutterError = exception is FlutterError? exception : nullptr;
        super(UniqueKey());
    }
}

void ErrorWidget::withDetails(FlutterError error, String message)

RenderBox ErrorWidget::createRenderObject(BuildContext context) {
    return RenderErrorBox(message);
}

void ErrorWidget::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    if (_flutterError == nullptr) {
        properties.add(StringProperty("message", messagefalse));
    } else {
        properties.add(_flutterError!.toDiagnosticsNode(DiagnosticsTreeStyle.whitespace));
    }
}

Widget ErrorWidget::_defaultErrorWidgetBuilder(FlutterErrorDetails details) {
    String message = "";
    assert(());
    Object exception = details.exception;
    return ErrorWidget.withDetails(message, exception is FlutterError? exception : nullptr);
}

String ErrorWidget::_stringify(Object exception) {
    ;
    return "Error";
}

bool ComponentElement::debugDoingBuild() {
    return _debugDoingBuild;
}

void ComponentElement::mount(Object newSlot, Element parent) {
    super.mount(parent, newSlot);
    assert(_child == nullptr);
    assert(_lifecycleState == _ElementLifecycle.active);
    _firstBuild();
    assert(_child != nullptr);
}

void ComponentElement::performRebuild() {
    assert(_debugSetAllowIgnoredCallsToMarkNeedsBuild(true));
    Widget built;
    ;
    ;
}

void ComponentElement::visitChildren(ElementVisitor visitor) {
    if (_child != nullptr) {
        visitor(_child!);
    }
}

void ComponentElement::forgetChild(Element child) {
    assert(child == _child);
    _child = nullptr;
    super.forgetChild(child);
}

void ComponentElement::_firstBuild() {
    rebuild();
}

Widget StatelessElement::build() {
    return (().build(this);
}

void StatelessElement::update(StatelessWidget newWidget) {
    super.update(newWidget);
    assert(widget == newWidget);
    _dirty = true;
    rebuild();
}

StatefulElement::StatefulElement(StatefulWidget widget) {
    {
        _state = widget.createState();
        super(widget);
    }
    {
        assert(());
        assert(state._element == nullptr);
        state._element = this;
        assert(state._widget == nullptr, "The createState function for $widget returned an old or invalid state instance: ${state._widget}, which is not null, violating the contract for createState.");
        state._widget = widget;
        assert(state._debugLifecycleState == _StateLifecycle.created);
    }
}

Widget StatefulElement::build() {
    return state.build(this);
}

State<StatefulWidget> StatefulElement::state() {
    return _state!;
}

void StatefulElement::reassemble() {
    if (_debugShouldReassemble(_debugReassembleConfig, _widget)) {
        state.reassemble();
    }
    super.reassemble();
}

void StatefulElement::performRebuild() {
    if (_didChangeDependencies) {
        state.didChangeDependencies();
        _didChangeDependencies = false;
    }
    super.performRebuild();
}

void StatefulElement::update(StatefulWidget newWidget) {
    super.update(newWidget);
    assert(widget == newWidget);
    StatefulWidget oldWidget = state._widget!;
    _dirty = true;
    state._widget = (;
    ;
    rebuild();
}

void StatefulElement::activate() {
    super.activate();
    state.activate();
    assert(_lifecycleState == _ElementLifecycle.active);
    markNeedsBuild();
}

void StatefulElement::deactivate() {
    state.deactivate();
    super.deactivate();
}

void StatefulElement::unmount() {
    super.unmount();
    state.dispose();
    assert(());
    state._element = nullptr;
    _state = nullptr;
}

InheritedWidget StatefulElement::dependOnInheritedElement(Element ancestor, Object aspect) {
    assert(ancestor != nullptr);
    assert(());
    return super.dependOnInheritedElement((aspect);
}

void StatefulElement::didChangeDependencies() {
    super.didChangeDependencies();
    _didChangeDependencies = true;
}

DiagnosticsNode StatefulElement::toDiagnosticsNode(String name, DiagnosticsTreeStyle style) {
    return _ElementDiagnosticableTreeNode(name, this, style, true);
}

void StatefulElement::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<State<StatefulWidget>>DiagnosticsProperty("state", _statenullptr));
}

void StatefulElement::_firstBuild() {
    assert(state._debugLifecycleState == _StateLifecycle.created);
    ;
    assert(());
    state.didChangeDependencies();
    assert(());
    super._firstBuild();
}

Widget ProxyElement::build() {
    return (().child;
}

void ProxyElement::update(ProxyWidget newWidget) {
    ProxyWidget oldWidget = (;
    assert(widget != nullptr);
    assert(widget != newWidget);
    super.update(newWidget);
    assert(widget == newWidget);
    updated(oldWidget);
    _dirty = true;
    rebuild();
}

void ProxyElement::updated(ProxyWidget oldWidget) {
    notifyClients(oldWidget);
}

void ParentDataElement::applyWidgetOutOfTurn(ParentDataWidget<T> newWidget) {
    assert(newWidget != nullptr);
    assert(newWidget.debugCanApplyOutOfTurn());
    assert(newWidget.child == (().child);
    _applyParentData(newWidget);
}

void ParentDataElement::notifyClients(ParentDataWidget<T> oldWidget) {
    _applyParentData(();
}

void ParentDataElement::_applyParentData(ParentDataWidget<T> widget) {
    ;
    visitChildren(applyParentDataToChild);
}

void InheritedElement::debugDeactivated() {
    assert(());
    super.debugDeactivated();
}

Object InheritedElement::getDependencies(Element dependent) {
    return _dependents[dependent];
}

void InheritedElement::setDependencies(Element dependent, Object value) {
    _dependents[dependent] = value;
}

void InheritedElement::updateDependencies(Object aspect, Element dependent) {
    setDependencies(dependent, nullptr);
}

void InheritedElement::notifyDependent(Element dependent, InheritedWidget oldWidget) {
    dependent.didChangeDependencies();
}

void InheritedElement::updated(InheritedWidget oldWidget) {
    if ((().updateShouldNotify(oldWidget)) {
        super.updated(oldWidget);
    }
}

void InheritedElement::notifyClients(InheritedWidget oldWidget) {
    assert(_debugCheckOwnerBuildTargetExists("notifyClients"));
    for (Element dependent : _dependents.keys) {
        assert(());
        assert(dependent._dependencies!.contains(this));
        notifyDependent(oldWidget, dependent);
    }
}

void InheritedElement::_updateInheritance() {
    assert(_lifecycleState == _ElementLifecycle.active);
    Map<Type, InheritedElement> incomingWidgets = _parent?._inheritedWidgets;
    if (incomingWidgets != nullptr) {
        _inheritedWidgets = <Type, InheritedElement>of(incomingWidgets);
    } else {
        _inheritedWidgets = <Type, InheritedElement>HashMap();
    }
    _inheritedWidgets![widget.runtimeType] = this;
}

RenderObject RenderObjectElement::renderObject() {
    assert(_renderObject != nullptr, "$runtimeType unmounted");
    return _renderObject!;
}

bool RenderObjectElement::debugDoingBuild() {
    return _debugDoingBuild;
}

void RenderObjectElement::mount(Object newSlot, Element parent) {
    super.mount(parent, newSlot);
    assert(());
    _renderObject = (().createRenderObject(this);
    assert(!_renderObject!.debugDisposed!);
    assert(());
    assert(());
    assert(_slot == newSlot);
    attachRenderObject(newSlot);
    _dirty = false;
}

void RenderObjectElement::update(RenderObjectWidget newWidget) {
    super.update(newWidget);
    assert(widget == newWidget);
    assert(());
    _performRebuild();
}

void RenderObjectElement::performRebuild() {
    _performRebuild();
}

List<Element> RenderObjectElement::updateChildren(Set<Element> forgottenChildren, List<Widget> newWidgets, List<Element> oldChildren, List<Object> slots) {
    assert(oldChildren != nullptr);
    assert(newWidgets != nullptr);
    assert(slots == nullptr || newWidgets.length == slots.length);
    ;
    ;
    int newChildrenTop = 0;
    int oldChildrenTop = 0;
    int newChildrenBottom = newWidgets.length - 1;
    int oldChildrenBottom = oldChildren.length - 1;
    List<Element> newChildren = oldChildren.length == newWidgets.length? oldChildren : <Element>filled(newWidgets.length, _NullElement.instance);
    Element previousChild;
    while ((oldChildrenTop <= oldChildrenBottom) && (newChildrenTop <= newChildrenBottom)) {
        Element oldChild = replaceWithNullIfForgotten(oldChildren[oldChildrenTop]);
        Widget newWidget = newWidgets[newChildrenTop];
        assert(oldChild == nullptr || oldChild._lifecycleState == _ElementLifecycle.active);
        if (oldChild == nullptr || !Widget.canUpdate(oldChild.widget, newWidget)) {
                        break;
        }
        Element newChild = updateChild(oldChild, newWidget, slotFor(newChildrenTop, previousChild))!;
        assert(newChild._lifecycleState == _ElementLifecycle.active);
        newChildren[newChildrenTop] = newChild;
        previousChild = newChild;
        newChildrenTop = 1;
        oldChildrenTop = 1;
    }
    while ((oldChildrenTop <= oldChildrenBottom) && (newChildrenTop <= newChildrenBottom)) {
        Element oldChild = replaceWithNullIfForgotten(oldChildren[oldChildrenBottom]);
        Widget newWidget = newWidgets[newChildrenBottom];
        assert(oldChild == nullptr || oldChild._lifecycleState == _ElementLifecycle.active);
        if (oldChild == nullptr || !Widget.canUpdate(oldChild.widget, newWidget)) {
                        break;
        }
        oldChildrenBottom = 1;
        newChildrenBottom = 1;
    }
    bool haveOldChildren = oldChildrenTop <= oldChildrenBottom;
    Map<Key, Element> oldKeyedChildren;
    if (haveOldChildren) {
        oldKeyedChildren = ;
        while (oldChildrenTop <= oldChildrenBottom) {
            Element oldChild = replaceWithNullIfForgotten(oldChildren[oldChildrenTop]);
            assert(oldChild == nullptr || oldChild._lifecycleState == _ElementLifecycle.active);
            if (oldChild != nullptr) {
                if (oldChild.widget.key != nullptr) {
                    oldKeyedChildren[oldChild.widget.key!] = oldChild;
                } else {
                    deactivateChild(oldChild);
                }
            }
            oldChildrenTop = 1;
        }
    }
    while (newChildrenTop <= newChildrenBottom) {
        Element oldChild;
        Widget newWidget = newWidgets[newChildrenTop];
        if (haveOldChildren) {
            Key key = newWidget.key;
            if (key != nullptr) {
                oldChild = oldKeyedChildren![key];
                if (oldChild != nullptr) {
                    if (Widget.canUpdate(oldChild.widget, newWidget)) {
                        oldKeyedChildren.remove(key);
                    } else {
                        oldChild = nullptr;
                    }
                }
            }
        }
        assert(oldChild == nullptr || Widget.canUpdate(oldChild.widget, newWidget));
        Element newChild = updateChild(oldChild, newWidget, slotFor(newChildrenTop, previousChild))!;
        assert(newChild._lifecycleState == _ElementLifecycle.active);
        assert(oldChild == newChild || oldChild == nullptr || oldChild._lifecycleState != _ElementLifecycle.active);
        newChildren[newChildrenTop] = newChild;
        previousChild = newChild;
        newChildrenTop = 1;
    }
    assert(oldChildrenTop == oldChildrenBottom + 1);
    assert(newChildrenTop == newChildrenBottom + 1);
    assert(newWidgets.length - newChildrenTop == oldChildren.length - oldChildrenTop);
    newChildrenBottom = newWidgets.length - 1;
    oldChildrenBottom = oldChildren.length - 1;
    while ((oldChildrenTop <= oldChildrenBottom) && (newChildrenTop <= newChildrenBottom)) {
        Element oldChild = oldChildren[oldChildrenTop];
        assert(replaceWithNullIfForgotten(oldChild) != nullptr);
        assert(oldChild._lifecycleState == _ElementLifecycle.active);
        Widget newWidget = newWidgets[newChildrenTop];
        assert(Widget.canUpdate(oldChild.widget, newWidget));
        Element newChild = updateChild(oldChild, newWidget, slotFor(newChildrenTop, previousChild))!;
        assert(newChild._lifecycleState == _ElementLifecycle.active);
        assert(oldChild == newChild || oldChild == nullptr || oldChild._lifecycleState != _ElementLifecycle.active);
        newChildren[newChildrenTop] = newChild;
        previousChild = newChild;
        newChildrenTop = 1;
        oldChildrenTop = 1;
    }
    if (haveOldChildren && oldKeyedChildren!.isNotEmpty) {
        for (Element oldChild : oldKeyedChildren.values) {
            if (forgottenChildren == nullptr || !forgottenChildren.contains(oldChild)) {
                deactivateChild(oldChild);
            }
        }
    }
    assert(newChildren.every());
    return newChildren;
}

void RenderObjectElement::deactivate() {
    super.deactivate();
    assert(!renderObject.attached, "A RenderObject was still attached when attempting to deactivate its RenderObjectElement: $renderObject");
}

void RenderObjectElement::unmount() {
    assert(!renderObject.debugDisposed!, "A RenderObject was disposed prior to its owning element being unmounted: $renderObject");
    RenderObjectWidget oldWidget = (;
    super.unmount();
    assert(!renderObject.attached, "A RenderObject was still attached when attempting to unmount its RenderObjectElement: $renderObject");
    oldWidget.didUnmountRenderObject(renderObject);
    _renderObject!.dispose();
    _renderObject = nullptr;
}

void RenderObjectElement::attachRenderObject(Object newSlot) {
    assert(_ancestorRenderObjectElement == nullptr);
    _slot = newSlot;
    _ancestorRenderObjectElement = _findAncestorRenderObjectElement();
    _ancestorRenderObjectElement?.insertRenderObjectChild(renderObject, newSlot);
    ParentDataElement<ParentData> parentDataElement = _findAncestorParentDataElement();
    if (parentDataElement != nullptr) {
        _updateParentData(();
    }
}

void RenderObjectElement::detachRenderObject() {
    if (_ancestorRenderObjectElement != nullptr) {
        _ancestorRenderObjectElement!.removeRenderObjectChild(renderObject, slot);
        _ancestorRenderObjectElement = nullptr;
    }
    _slot = nullptr;
}

void RenderObjectElement::insertRenderObjectChild(RenderObject child, Object slot) {
    assert(());
}

void RenderObjectElement::moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot) {
    assert(());
}

void RenderObjectElement::removeRenderObjectChild(RenderObject child, Object slot) {
    assert(());
}

void RenderObjectElement::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<RenderObject>DiagnosticsProperty("renderObject", _renderObjectnullptr));
}

RenderObjectElement RenderObjectElement::_findAncestorRenderObjectElement() {
    Element ancestor = _parent;
    while (ancestor != nullptr && ancestor is! RenderObjectElement) {
        ancestor = ancestor._parent;
    }
    return (;
}

ParentDataElement<ParentData> RenderObjectElement::_findAncestorParentDataElement() {
    Element ancestor = _parent;
    ParentDataElement<ParentData> result;
    while (ancestor != nullptr && ancestor is! RenderObjectElement) {
        if (ancestor is ParentDataElement<ParentData>) {
            result = ancestor;
                        break;
        }
        ancestor = ancestor._parent;
    }
    assert(());
    return result;
}

void RenderObjectElement::_debugUpdateRenderObjectOwner() {
    assert(());
}

void RenderObjectElement::_performRebuild() {
    assert(());
    (().updateRenderObject(this, renderObject);
    assert(());
    _dirty = false;
}

void RenderObjectElement::_updateParentData(ParentDataWidget<ParentData> parentDataWidget) {
    bool applyParentData = true;
    assert(());
    if (applyParentData) {
        parentDataWidget.applyParentData(renderObject);
    }
}

void RenderObjectElement::_updateSlot(Object newSlot) {
    Object oldSlot = slot;
    assert(oldSlot != newSlot);
    super._updateSlot(newSlot);
    assert(slot == newSlot);
    _ancestorRenderObjectElement!.moveRenderObjectChild(renderObject, oldSlot, slot);
}

void RootRenderObjectElement::assignOwner(BuildOwner owner) {
    _owner = owner;
}

void RootRenderObjectElement::mount(Object newSlot, Element parent) {
    assert(parent == nullptr);
    assert(newSlot == nullptr);
    super.mount(parent, newSlot);
}

void LeafRenderObjectElement::forgetChild(Element child) {
    assert(false);
    super.forgetChild(child);
}

void LeafRenderObjectElement::insertRenderObjectChild(RenderObject child, Object slot) {
    assert(false);
}

void LeafRenderObjectElement::moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot) {
    assert(false);
}

void LeafRenderObjectElement::removeRenderObjectChild(RenderObject child, Object slot) {
    assert(false);
}

List<DiagnosticsNode> LeafRenderObjectElement::debugDescribeChildren() {
    return widget.debugDescribeChildren();
}

void SingleChildRenderObjectElement::visitChildren(ElementVisitor visitor) {
    if (_child != nullptr) {
        visitor(_child!);
    }
}

void SingleChildRenderObjectElement::forgetChild(Element child) {
    assert(child == _child);
    _child = nullptr;
    super.forgetChild(child);
}

void SingleChildRenderObjectElement::mount(Object newSlot, Element parent) {
    super.mount(parent, newSlot);
    _child = updateChild(_child, (().child, nullptr);
}

void SingleChildRenderObjectElement::update(SingleChildRenderObjectWidget newWidget) {
    super.update(newWidget);
    assert(widget == newWidget);
    _child = updateChild(_child, (().child, nullptr);
}

void SingleChildRenderObjectElement::insertRenderObjectChild(RenderObject child, Object slot) {
    RenderObjectWithChildMixin<RenderObject> renderObject = (;
    assert(slot == nullptr);
    assert(renderObject.debugValidateChild(child));
    renderObject.child = child;
    assert(renderObject == this.renderObject);
}

void SingleChildRenderObjectElement::moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot) {
    assert(false);
}

void SingleChildRenderObjectElement::removeRenderObjectChild(RenderObject child, Object slot) {
    RenderObjectWithChildMixin<RenderObject> renderObject = (;
    assert(slot == nullptr);
    assert(renderObject.child == child);
    renderObject.child = nullptr;
    assert(renderObject == this.renderObject);
}

MultiChildRenderObjectElement::MultiChildRenderObjectElement(MultiChildRenderObjectWidget widget) {
    {
        assert(!debugChildrenHaveDuplicateKeys(widget, widget.children));
    }
}

ContainerRenderObjectMixin<RenderObject, ContainerParentDataMixin<RenderObject>> MultiChildRenderObjectElement::renderObject() {
    return (;
}

Iterable<Element> MultiChildRenderObjectElement::children() {
    return _children.where();
}

void MultiChildRenderObjectElement::insertRenderObjectChild(RenderObject child, IndexedSlot<Element> slot) {
    ContainerRenderObjectMixin<RenderObject, ContainerParentDataMixin<RenderObject>> renderObject = this.renderObject;
    assert(renderObject.debugValidateChild(child));
    renderObject.insert(childslot.value?.renderObject);
    assert(renderObject == this.renderObject);
}

void MultiChildRenderObjectElement::moveRenderObjectChild(RenderObject child, IndexedSlot<Element> newSlot, IndexedSlot<Element> oldSlot) {
    ContainerRenderObjectMixin<RenderObject, ContainerParentDataMixin<RenderObject>> renderObject = this.renderObject;
    assert(child.parent == renderObject);
    renderObject.move(childnewSlot.value?.renderObject);
    assert(renderObject == this.renderObject);
}

void MultiChildRenderObjectElement::removeRenderObjectChild(RenderObject child, Object slot) {
    ContainerRenderObjectMixin<RenderObject, ContainerParentDataMixin<RenderObject>> renderObject = this.renderObject;
    assert(child.parent == renderObject);
    renderObject.remove(child);
    assert(renderObject == this.renderObject);
}

void MultiChildRenderObjectElement::visitChildren(ElementVisitor visitor) {
    for (Element child : _children) {
        if (!_forgottenChildren.contains(child)) {
            visitor(child);
        }
    }
}

void MultiChildRenderObjectElement::forgetChild(Element child) {
    assert(_children.contains(child));
    assert(!_forgottenChildren.contains(child));
    _forgottenChildren.add(child);
    super.forgetChild(child);
}

Element MultiChildRenderObjectElement::inflateWidget(Object newSlot, Widget newWidget) {
    Element newChild = super.inflateWidget(newWidget, newSlot);
    assert(_debugCheckHasAssociatedRenderObject(newChild));
    return newChild;
}

void MultiChildRenderObjectElement::mount(Object newSlot, Element parent) {
    super.mount(parent, newSlot);
    MultiChildRenderObjectWidget multiChildRenderObjectWidget = (;
    List<Element> children = <Element>filled(multiChildRenderObjectWidget.children.length, _NullElement.instance);
    Element previousChild;
    for (;  < children.length; i = 1) {
        Element newChild = inflateWidget(multiChildRenderObjectWidget.children[i], <Element>IndexedSlot(i, previousChild));
        children[i] = newChild;
        previousChild = newChild;
    }
    _children = children;
}

void MultiChildRenderObjectElement::update(MultiChildRenderObjectWidget newWidget) {
    super.update(newWidget);
    MultiChildRenderObjectWidget multiChildRenderObjectWidget = (;
    assert(widget == newWidget);
    assert(!debugChildrenHaveDuplicateKeys(widget, multiChildRenderObjectWidget.children));
    _children = updateChildren(_children, multiChildRenderObjectWidget.children_forgottenChildren);
    _forgottenChildren.clear();
}

bool MultiChildRenderObjectElement::_debugCheckHasAssociatedRenderObject(Element newChild) {
    assert(());
    return true;
}

String DebugCreator::toString() {
    return element.debugGetCreatorChain(12);
}

FlutterErrorDetails _debugReportException(DiagnosticsNode context, Object exception, InformationCollector informationCollector, StackTrace stack) {
    FlutterErrorDetails details = FlutterErrorDetails(exception, stack, "widgets library", context, informationCollector);
    FlutterError.reportError(details);
    return details;
}

bool IndexedSlot::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is IndexedSlot && index == other.index && value == other.value;
}

int IndexedSlot::hashCode() {
    return Object.hash(index, value);
}

bool _NullElement::debugDoingBuild() {
    return ;
}

void _NullElement::performRebuild() {
    return ;
}

_NullElement::_NullElement() {
    {
        super(const _NullWidget());
    }
}

Element _NullWidget::createElement() {
    return ;
}

bool _debugShouldReassemble(DebugReassembleConfig config, Widget widget) {
    return config == nullptr || config.widgetName == nullptr || widget?.runtimeType.toString() == config.widgetName;
}
