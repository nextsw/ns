#include "framework.hpp"
bool ObjectKeyCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<ObjectKey>(other) && identical(other->value, value);
}

int ObjectKeyCls::hashCode() {
    return ObjectCls->hash(runtimeType, identityHashCode(value));
}

String ObjectKeyCls::toString() {
    if (runtimeType == ObjectKeyCls) {
        return __s("[${describeIdentity(value)}]");
    }
    return __s("[${objectRuntimeType(this, 'ObjectKey')} ${describeIdentity(value)}]");
}

template<typename T>
GlobalKeyCls<T>::GlobalKeyCls(String debugLabel) {
}

template<typename T>
void GlobalKeyCls<T>::constructor()

template<typename T>
BuildContext GlobalKeyCls<T>::currentContext() {
    return _currentElement();
}

template<typename T>
Widget GlobalKeyCls<T>::currentWidget() {
    return _currentElement()?->widget();
}

template<typename T>
T GlobalKeyCls<T>::currentState() {
    Element element = _currentElement();
    if (is<StatefulElement>(element)) {
        StatefulElement statefulElement = as<StatefulElementCls>(element);
        State state = statefulElement->state();
        if (is<T>(state)) {
            return state;
        }
    }
    return nullptr;
}

template<typename T>
Element GlobalKeyCls<T>::_currentElement() {
    return WidgetsBindingCls::instance->buildOwner!->_globalKeyRegistry[this];
}

template<typename T>
LabeledGlobalKeyCls<T>::LabeledGlobalKeyCls(String _debugLabel) {
    {
        super->constructor();
    }
}

template<typename T>
String LabeledGlobalKeyCls<T>::toString() {
    String label = _debugLabel != nullptr? __s(" $_debugLabel") : __s("");
    if (runtimeType == LabeledGlobalKeyCls) {
        return __s("[GlobalKey#${shortHash(this)}$label]");
    }
    return __s("[${describeIdentity(this)}$label]");
}

template<typename T>
GlobalObjectKeyCls<T>::GlobalObjectKeyCls(Object value) {
    {
        super->constructor();
    }
}

template<typename T>
bool GlobalObjectKeyCls<T>::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<GlobalObjectKey<T>>(other) && identical(other->value, value);
}

template<typename T>
int GlobalObjectKeyCls<T>::hashCode() {
    return identityHashCode(value);
}

template<typename T>
String GlobalObjectKeyCls<T>::toString() {
    String selfType = objectRuntimeType(this, __s("GlobalObjectKey"));
    String suffix = __s("<State<StatefulWidget>>");
    if (selfType->endsWith(suffix)) {
        selfType = selfType->substring(0, selfType->length() - suffix->length());
    }
    return __s("[$selfType ${describeIdentity(value)}]");
}

String WidgetCls::toStringShort() {
    String type = objectRuntimeType(this, __s("Widget"));
    return key == nullptr? type : __s("$type-$key");
}

void WidgetCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->defaultDiagnosticsTreeStyle = DiagnosticsTreeStyleCls::dense;
}

bool WidgetCls::==(Object other) {
    return super == other;
}

int WidgetCls::hashCode() {
    return super->hashCode();
}

bool WidgetCls::canUpdate(Widget oldWidget, Widget newWidget) {
    return oldWidget->runtimeType == newWidget->runtimeType && oldWidget->key == newWidget->key;
}

int WidgetCls::_debugConcreteSubtype(Widget widget) {
    return is<StatefulWidget>(widget)? 1 : is<StatelessWidget>(widget)? 2 : 0;
}

StatelessElement StatelessWidgetCls::createElement() {
    return make<StatelessElementCls>(this);
}

StatefulElement StatefulWidgetCls::createElement() {
    return make<StatefulElementCls>(this);
}

template<typename T>
T StateCls<T>::widget() {
    return _widget!;
}

template<typename T>
BuildContext StateCls<T>::context() {
    assert([=] () {
        if (_element == nullptr) {
            throw make<FlutterErrorCls>(__s("This widget has been unmounted, so the State no longer has a context (and should be considered defunct). \nConsider canceling any active work during "dispose" or using the "mounted" getter to determine if the State is still active."));
        }
        return true;
    }());
    return _element!;
}

template<typename T>
bool StateCls<T>::mounted() {
    return _element != nullptr;
}

template<typename T>
void StateCls<T>::initState() {
    assert(_debugLifecycleState == _StateLifecycleCls::created);
}

template<typename T>
void StateCls<T>::didUpdateWidget(T oldWidget) {
}

template<typename T>
void StateCls<T>::reassemble() {
}

template<typename T>
void StateCls<T>::setState(VoidCallback fn) {
    assert(fn != nullptr);
    assert([=] () {
        if (_debugLifecycleState == _StateLifecycleCls::defunct) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));
        }
        if (_debugLifecycleState == _StateLifecycleCls::created && !mounted()) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem));
        }
        return true;
    }());
    Object result = as<dynamic>(fn());
    assert([=] () {
        if (is<Future>(result)) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
        }
        return true;
    }());
    _element!->markNeedsBuild();
}

template<typename T>
void StateCls<T>::deactivate() {
}

template<typename T>
void StateCls<T>::activate() {
}

template<typename T>
void StateCls<T>::dispose() {
    assert(_debugLifecycleState == _StateLifecycleCls::ready);
    assert([=] () {
        _debugLifecycleState = _StateLifecycleCls::defunct;
        return true;
    }());
}

template<typename T>
void StateCls<T>::didChangeDependencies() {
}

template<typename T>
void StateCls<T>::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    assert([=] () {
        properties->add(<_StateLifecycle>make<EnumPropertyCls>(__s("lifecycle state"), _debugLifecycleState, _StateLifecycleCls::ready));
        return true;
    }());
    properties->add(<T>make<ObjectFlagPropertyCls>(__s("_widget"), _widget, __s("no widget")));
    properties->add(<StatefulElement>make<ObjectFlagPropertyCls>(__s("_element"), _element, __s("not mounted")));
}

template<typename T>
bool StateCls<T>::_debugTypesAreRight(Widget widget) {
    return is<T>(widget);
}

template<typename T>
ParentDataElement<T> ParentDataWidgetCls<T>::createElement() {
    return <T>make<ParentDataElementCls>(this);
}

template<typename T>
bool ParentDataWidgetCls<T>::debugIsValidRenderObject(RenderObject renderObject) {
    assert(T != dynamic);
    assert(T != ParentDataCls);
    return is<T>(renderObject->parentData);
}

template<typename T>
bool ParentDataWidgetCls<T>::debugCanApplyOutOfTurn() {
    return false;
}

template<typename T>
Iterable<DiagnosticsNode> ParentDataWidgetCls<T>::_debugDescribeIncorrectParentDataType(DiagnosticsNode ownershipChain, ParentData parentData, RenderObjectWidget parentDataCreator) {
    assert(T != dynamic);
    assert(T != ParentDataCls);
    assert(debugTypicalAncestorWidgetClass() != nullptr);
    String description = __s("The ParentDataWidget $this wants to apply ParentData of type $T to a RenderObject");
    List<DiagnosticsNode> list1 = make<ListCls<>>();if (parentData == nullptr) {    list1.add(ArrayItem);} else {    list1.add(ArrayItem);}list1.add(ArrayItem);if (parentDataCreator != nullptr) {    list1.add(ArrayItem);}if (ownershipChain != nullptr) {    list1.add(ArrayItem);}return list1;
}

InheritedElement InheritedWidgetCls::createElement() {
    return make<InheritedElementCls>(this);
}

void RenderObjectWidgetCls::updateRenderObject(BuildContext context, RenderObject renderObject) {
}

void RenderObjectWidgetCls::didUnmountRenderObject(RenderObject renderObject) {
}

LeafRenderObjectElement LeafRenderObjectWidgetCls::createElement() {
    return make<LeafRenderObjectElementCls>(this);
}

SingleChildRenderObjectElement SingleChildRenderObjectWidgetCls::createElement() {
    return make<SingleChildRenderObjectElementCls>(this);
}

MultiChildRenderObjectWidgetCls::MultiChildRenderObjectWidgetCls(List<Widget> children, Key key) {
    {
        assert(children != nullptr);
    }
    {
        assert([=] () {
            for (;  < children->length(); index++) {
                if (children[index] == nullptr) {
                    throw make<FlutterErrorCls>(__s("$runtimeType's children must not contain any null values, but a null value was found at index $index"));
                }
            }
            return true;
        }());
    }
}

MultiChildRenderObjectElement MultiChildRenderObjectWidgetCls::createElement() {
    return make<MultiChildRenderObjectElementCls>(this);
}

void _InactiveElementsCls::add(Element element) {
    assert(!_locked);
    assert(!_elements->contains(element));
    assert(element->_parent == nullptr);
    if (element->_lifecycleState == _ElementLifecycleCls::active) {
        _deactivateRecursively(element);
    }
    _elements->add(element);
}

void _InactiveElementsCls::remove(Element element) {
    assert(!_locked);
    assert(_elements->contains(element));
    assert(element->_parent == nullptr);
    _elements->remove(element);
    assert(element->_lifecycleState != _ElementLifecycleCls::active);
}

bool _InactiveElementsCls::debugContains(Element element) {
    bool result;
    assert([=] () {
        result = _elements->contains(element);
        return true;
    }());
    return result;
}

void _InactiveElementsCls::_unmount(Element element) {
    assert(element->_lifecycleState == _ElementLifecycleCls::inactive);
    assert([=] () {
        if (debugPrintGlobalKeyedWidgetLifecycle) {
            if (is<GlobalKey>(element->widget()->key)) {
                debugPrint(__s("Discarding $element from inactive elements list."));
            }
        }
        return true;
    }());
    element->visitChildren([=] (Element child) {
        assert(child->_parent == element);
        _unmount(child);
    });
    element->unmount();
    assert(element->_lifecycleState == _ElementLifecycleCls::defunct);
}

void _InactiveElementsCls::_unmountAll() {
    _locked = true;
    auto _c1 = _elements->toList();_c1.sort(ElementCls::_sort);List<Element> elements = _c1;
    _elements->clear();
    try {
        elements->reversed()->forEach(_unmount);
    } finally {
        assert(_elements->isEmpty());
        _locked = false;
    };
}

void _InactiveElementsCls::_deactivateRecursively(Element element) {
    assert(element->_lifecycleState == _ElementLifecycleCls::active);
    element->deactivate();
    assert(element->_lifecycleState == _ElementLifecycleCls::inactive);
    element->visitChildren(_deactivateRecursively);
    assert([=] () {
        element->debugDeactivated();
        return true;
    }());
}

BuildOwnerCls::BuildOwnerCls(FocusManager focusManager, VoidCallback onBuildScheduled) {
    {
            auto _c1 = make<FocusManagerCls>();    _c1.registerGlobalHandlers();focusManager = focusManager | (_c1);
    }
}

void BuildOwnerCls::scheduleBuildFor(Element element) {
    assert(element != nullptr);
    assert(element->owner() == this);
    assert([=] () {
        if (debugPrintScheduleBuildForStacks) {
            debugPrintStack(__s("scheduleBuildFor() called for $element${_dirtyElements.contains(element) ? " (ALREADY IN LIST)" : ""}"));
        }
        if (!element->dirty()) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));
        }
        return true;
    }());
    if (element->_inDirtyList) {
        assert([=] () {
            if (debugPrintScheduleBuildForStacks) {
                debugPrintStack(__s("BuildOwner.scheduleBuildFor() called; _dirtyElementsNeedsResorting was $_dirtyElementsNeedsResorting (now true); dirty list is: $_dirtyElements"));
            }
            if (!_debugIsInBuildScope()) {
                throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem));
            }
            return true;
        }());
        _dirtyElementsNeedsResorting = true;
        return;
    }
    if (!_scheduledFlushDirtyElements && onBuildScheduled != nullptr) {
        _scheduledFlushDirtyElements = true;
        onBuildScheduled!();
    }
    _dirtyElements->add(element);
    element->_inDirtyList = true;
    assert([=] () {
        if (debugPrintScheduleBuildForStacks) {
            debugPrint(__s("...dirty list is now: $_dirtyElements"));
        }
        return true;
    }());
}

bool BuildOwnerCls::debugBuilding() {
    return _debugBuilding;
}

void BuildOwnerCls::lockState(VoidCallback callback) {
    assert(callback != nullptr);
    assert(_debugStateLockLevel >= 0);
    assert([=] () {
        _debugStateLockLevel += 1;
        return true;
    }());
    try {
        callback();
    } finally {
        assert([=] () {
            _debugStateLockLevel -= 1;
            return true;
        }());
    };
    assert(_debugStateLockLevel >= 0);
}

void BuildOwnerCls::buildScope(Element context, VoidCallback callback) {
    if (callback == nullptr && _dirtyElements->isEmpty()) {
        return;
    }
    assert(context != nullptr);
    assert(_debugStateLockLevel >= 0);
    assert(!_debugBuilding);
    assert([=] () {
        if (debugPrintBuildScope) {
            debugPrint(__s("buildScope called with context $context; dirty list is: $_dirtyElements"));
        }
        _debugStateLockLevel += 1;
        _debugBuilding = true;
        return true;
    }());
    if (!kReleaseMode) {
        Map<String, String> debugTimelineArguments;
        assert([=] () {
            if (debugEnhanceBuildTimelineArguments) {
                            Map<String, String> map1 = make<MapCls<>>();            map1.set(__s("dirty count"), __s("${_dirtyElements.length}"));            map1.set(__s("dirty list"), __s("$_dirtyElements"));            map1.set(__s("lock level"), __s("$_debugStateLockLevel"));            map1.set(__s("scope context"), __s("$context"));debugTimelineArguments = list1;
            }
            return true;
        }());
        TimelineCls->startSync(__s("BUILD"), debugTimelineArguments);
    }
    try {
        _scheduledFlushDirtyElements = true;
        if (callback != nullptr) {
            assert(_debugStateLocked());
            Element debugPreviousBuildTarget;
            assert([=] () {
                context->_debugSetAllowIgnoredCallsToMarkNeedsBuild(true);
                debugPreviousBuildTarget = _debugCurrentBuildTarget;
                _debugCurrentBuildTarget = context;
                return true;
            }());
            _dirtyElementsNeedsResorting = false;
            try {
                callback();
            } finally {
                assert([=] () {
                    context->_debugSetAllowIgnoredCallsToMarkNeedsBuild(false);
                    assert(_debugCurrentBuildTarget == context);
                    _debugCurrentBuildTarget = debugPreviousBuildTarget;
                    _debugElementWasRebuilt(context);
                    return true;
                }());
            };
        }
        _dirtyElements->sort(ElementCls::_sort);
        _dirtyElementsNeedsResorting = false;
        int dirtyCount = _dirtyElements->length();
        int index = 0;
        while ( < dirtyCount) {
            Element element = _dirtyElements[index];
            assert(element != nullptr);
            assert(element->_inDirtyList);
            assert([=] () {
                if (element->_lifecycleState == _ElementLifecycleCls::active && !element->_debugIsInScope(context)) {
                    throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem));
                }
                return true;
            }());
            bool isTimelineTracked = !kReleaseMode && _isProfileBuildsEnabledFor(element->widget());
            if (isTimelineTracked) {
                Map<String, String> debugTimelineArguments;
                assert([=] () {
                    if (kDebugMode && debugEnhanceBuildTimelineArguments) {
                        debugTimelineArguments = element->widget()->toDiagnosticsNode()->toTimelineArguments();
                    }
                    return true;
                }());
                TimelineCls->startSync(__s("${element.widget.runtimeType}"), debugTimelineArguments);
            }
            try {
                element->rebuild();
            } catch (Unknown e) {
                            List<DiagnosticsNode> list2 = make<ListCls<>>();            if (kDebugMode &&  < _dirtyElements->length()) {                list2.add(ArrayItem);            }if ( < _dirtyElements->length()) {                list2.add(ArrayItem);            } else {                list2.add(ArrayItem);            }_debugReportException(make<ErrorDescriptionCls>(__s("while rebuilding dirty elements")), e, stack, [=] () {
                    list2;
                });
            };
            if (isTimelineTracked) {
                TimelineCls->finishSync();
            }
            index += 1;
            if ( < _dirtyElements->length() || _dirtyElementsNeedsResorting!) {
                _dirtyElements->sort(ElementCls::_sort);
                _dirtyElementsNeedsResorting = false;
                dirtyCount = _dirtyElements->length();
                while (index > 0 && _dirtyElements[index - 1]->dirty()) {
                    index -= 1;
                }
            }
        }
        assert([=] () {
            if (_dirtyElements->any([=] (Element element) {
                element->_lifecycleState == _ElementLifecycleCls::active && element->dirty;
            })) {
                throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
            }
            return true;
        }());
    } finally {
        for (Element element : _dirtyElements) {
            assert(element->_inDirtyList);
            element->_inDirtyList = false;
        }
        _dirtyElements->clear();
        _scheduledFlushDirtyElements = false;
        _dirtyElementsNeedsResorting = nullptr;
        if (!kReleaseMode) {
            TimelineCls->finishSync();
        }
        assert(_debugBuilding);
        assert([=] () {
            _debugBuilding = false;
            _debugStateLockLevel -= 1;
            if (debugPrintBuildScope) {
                debugPrint(__s("buildScope finished"));
            }
            return true;
        }());
    };
    assert(_debugStateLockLevel >= 0);
}

int BuildOwnerCls::globalKeyCount() {
    return _globalKeyRegistry->length();
}

void BuildOwnerCls::finalizeTree() {
    if (!kReleaseMode) {
        TimelineCls->startSync(__s("FINALIZE TREE"));
    }
    try {
        lockState(_inactiveElements->_unmountAll);
        assert([=] () {
            try {
                _debugVerifyGlobalKeyReservation();
                _debugVerifyIllFatedPopulation();
                if (_debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans != nullptr && _debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans!->isNotEmpty()) {
                    Set<GlobalKey> keys = <GlobalKey>make<HashSetCls>();
                    for (Element element : _debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans!->keys) {
                        if (element->_lifecycleState != _ElementLifecycleCls::defunct) {
                            keys->addAll(_debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans![element]!);
                        }
                    }
                    if (keys->isNotEmpty()) {
                        Map<String, int> keyStringCount = <String, int>make<HashMapCls>();
                        for (String key : keys-><String>map([=] (GlobalKey key) {
                            key->toString();
                        })) {
                            if (keyStringCount->containsKey(key)) {
                                keyStringCount->update(key, [=] (int value) {
                                    value + 1;
                                });
                            } else {
                                keyStringCount[key] = 1;
                            }
                        }
                        List<String> keyLabels = makeList();
                        keyStringCount->forEach([=] (String key,int count) {
                            if (count == 1) {
                                keyLabels->add(key);
                            } else {
                                keyLabels->add(__s("$key ($count different affected keys had this toString representation)"));
                            }
                        });
                        Iterable<Element> elements = _debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans!->keys;
                        Map<String, int> elementStringCount = <String, int>make<HashMapCls>();
                        for (String element : elements-><String>map([=] (Element element) {
                            element->toString();
                        })) {
                            if (elementStringCount->containsKey(element)) {
                                elementStringCount->update(element, [=] (int value) {
                                    value + 1;
                                });
                            } else {
                                elementStringCount[element] = 1;
                            }
                        }
                        List<String> elementLabels = makeList();
                        elementStringCount->forEach([=] (String element,int count) {
                            if (count == 1) {
                                elementLabels->add(element);
                            } else {
                                elementLabels->add(__s("$element ($count different affected elements had this toString representation)"));
                            }
                        });
                        assert(keyLabels->isNotEmpty());
                        String the = keys->length() == 1? __s(" the") : __s("");
                        String s = keys->length() == 1? __s("") : __s("s");
                        String were = keys->length() == 1? __s("was") : __s("were");
                        String their = keys->length() == 1? __s("its") : __s("their");
                        String respective = elementLabels->length() == 1? __s("") : __s(" respective");
                        String those = keys->length() == 1? __s("that") : __s("those");
                        String s2 = elementLabels->length() == 1? __s("") : __s("s");
                        String those2 = elementLabels->length() == 1? __s("that") : __s("those");
                        String they = elementLabels->length() == 1? __s("it") : __s("they");
                        String think = elementLabels->length() == 1? __s("thinks") : __s("think");
                        String are = elementLabels->length() == 1? __s("is") : __s("are");
                        throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem));
                    }
                }
            } finally {
                _debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans?->clear();
            };
            return true;
        }());
    } catch (Unknown e) {
        _debugReportException(make<ErrorSummaryCls>(__s("while finalizing the widget tree")), e, stack);
    } finally {
        if (!kReleaseMode) {
            TimelineCls->finishSync();
        }
    };
}

void BuildOwnerCls::reassemble(Element root, DebugReassembleConfig reassembleConfig) {
    if (!kReleaseMode) {
        TimelineCls->startSync(__s("Preparing Hot Reload (widgets)"));
    }
    try {
        assert(root->_parent == nullptr);
        assert(root->owner() == this);
        root->_debugReassembleConfig = reassembleConfig;
        root->reassemble();
    } finally {
        if (!kReleaseMode) {
            TimelineCls->finishSync();
        }
    };
}

bool BuildOwnerCls::_debugIsInBuildScope() {
    return _dirtyElementsNeedsResorting != nullptr;
}

bool BuildOwnerCls::_debugStateLocked() {
    return _debugStateLockLevel > 0;
}

void BuildOwnerCls::_debugTrackElementThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans(Element node, GlobalKey key) {
    _debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans |= <Element, Set<GlobalKey>>make<HashMapCls>();
    Set<GlobalKey> keys = _debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans!->putIfAbsent(node, [=] () {
    <GlobalKey>make<HashSetCls>();
});
    keys->add(key);
}

void BuildOwnerCls::_debugElementWasRebuilt(Element node) {
    _debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans?->remove(node);
}

void BuildOwnerCls::_debugRemoveGlobalKeyReservationFor(Element parent, Element child) {
    assert([=] () {
        assert(parent != nullptr);
        assert(child != nullptr);
        _debugGlobalKeyReservations?[parent]?->remove(child);
        return true;
    }());
}

void BuildOwnerCls::_registerGlobalKey(GlobalKey key, Element element) {
    assert([=] () {
        if (_globalKeyRegistry->containsKey(key)) {
            assert(element->widget() != nullptr);
            Element oldElement = _globalKeyRegistry[key]!;
            assert(oldElement->widget() != nullptr);
            assert(element->widget()->runtimeType != oldElement->widget()->runtimeType);
            _debugIllFatedElements?->add(oldElement);
        }
        return true;
    }());
    _globalKeyRegistry[key] = element;
}

void BuildOwnerCls::_unregisterGlobalKey(GlobalKey key, Element element) {
    assert([=] () {
        if (_globalKeyRegistry->containsKey(key) && _globalKeyRegistry[key] != element) {
            assert(element->widget() != nullptr);
            Element oldElement = _globalKeyRegistry[key]!;
            assert(oldElement->widget() != nullptr);
            assert(element->widget()->runtimeType != oldElement->widget()->runtimeType);
        }
        return true;
    }());
    if (_globalKeyRegistry[key] == element) {
        _globalKeyRegistry->remove(key);
    }
}

void BuildOwnerCls::_debugReserveGlobalKeyFor(Element parent, Element child, GlobalKey key) {
    assert([=] () {
        assert(parent != nullptr);
        assert(child != nullptr);
        _debugGlobalKeyReservations?[parent] |= makeMap(makeList(), makeList();
        _debugGlobalKeyReservations?[parent]![child] = key;
        return true;
    }());
}

void BuildOwnerCls::_debugVerifyGlobalKeyReservation() {
    assert([=] () {
        Map<GlobalKey, Element> keyToParent = makeMap(makeList(), makeList();
        _debugGlobalKeyReservations?->forEach([=] (Element parent,Map<Element, GlobalKey> childToKey) {
            if (parent->_lifecycleState == _ElementLifecycleCls::defunct || parent->renderObject?->attached == false) {
                return;
            }
            childToKey->forEach([=] (Element child,GlobalKey key) {
                if (child->_parent == nullptr) {
                    return;
                }
                if (keyToParent->containsKey(key) && keyToParent[key] != parent) {
                    Element older = keyToParent[key]!;
                    Element newer = parent;
                    FlutterError error;
                    if (older->toString() != newer->toString()) {
                        error = FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem));
                    } else {
                        error = FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem));
                    }
                    if (child->_parent != older) {
                        older->visitChildren([=] (Element currentChild) {
                            if (currentChild == child) {
                                older->forgetChild(child);
                            }
                        });
                    }
                    if (child->_parent != newer) {
                        newer->visitChildren([=] (Element currentChild) {
                            if (currentChild == child) {
                                newer->forgetChild(child);
                            }
                        });
                    }
                    throw error;
                } else {
                    keyToParent[key] = parent;
                }
            });
        });
        _debugGlobalKeyReservations?->clear();
        return true;
    }());
}

void BuildOwnerCls::_debugVerifyIllFatedPopulation() {
    assert([=] () {
        Map<GlobalKey, Set<Element>> duplicates;
        for (Element element : _debugIllFatedElements | makeSet()) {
            if (element->_lifecycleState != _ElementLifecycleCls::defunct) {
                assert(element != nullptr);
                assert(element->widget != nullptr);
                assert(element->widget->key != nullptr);
                GlobalKey key = as<GlobalKey>(element->widget->key!);
                assert(_globalKeyRegistry->containsKey(key));
                duplicates |= makeMap(makeList(), makeList();
                Set<Element> elements = duplicates->putIfAbsent(key, [=] () {
    <Element>make<LinkedHashSetCls>();
});
                elements->add(element);
                elements->add(_globalKeyRegistry[key]!);
            }
        }
        _debugIllFatedElements?->clear();
        if (duplicates != nullptr) {
            List<DiagnosticsNode> information = makeList();
            information->add(make<ErrorSummaryCls>(__s("Multiple widgets used the same GlobalKey.")));
            for (GlobalKey key : duplicates->keys()) {
                Set<Element> elements = duplicates[key]!;
                information->add(ElementCls->describeElements(__s("The key $key was used by ${elements.length} widgets"), elements));
            }
            information->add(make<ErrorDescriptionCls>(__s("A GlobalKey can only be specified on one widget at a time in the widget tree.")));
            throw FlutterErrorCls->fromParts(information);
        }
        return true;
    }());
}

void NotifiableElementMixinCls::attachNotificationTree() {
    _notificationTree = make<_NotificationNodeCls>(_parent?->_notificationTree, this);
}

void _NotificationNodeCls::dispatchNotification(Notification notification) {
    if (current?->onNotification(notification) | true) {
        return;
    }
    parent?->dispatchNotification(notification);
}

bool _isProfileBuildsEnabledFor(Widget widget) {
    return debugProfileBuildsEnabled || (debugProfileBuildsEnabledUserWidgets && debugIsWidgetLocalCreation(widget));
}

ElementCls::ElementCls(Widget widget) {
    {
        assert(widget != nullptr);
        _widget = widget;
    }
}

bool ElementCls::==(Object other) {
    return identical(this, other);
}

Object ElementCls::slot() {
    return _slot;
}

int ElementCls::depth() {
    assert([=] () {
        if (_lifecycleState == _ElementLifecycleCls::initial) {
            throw make<FlutterErrorCls>(__s("Depth is only available when element has been mounted."));
        }
        return true;
    }());
    return _depth;
}

Widget ElementCls::widget() {
    return _widget!;
}

bool ElementCls::debugIsDefunct() {
    bool isDefunct = false;
    assert([=] () {
        isDefunct = _lifecycleState == _ElementLifecycleCls::defunct;
        return true;
    }());
    return isDefunct;
}

bool ElementCls::debugIsActive() {
    bool isActive = false;
    assert([=] () {
        isActive = _lifecycleState == _ElementLifecycleCls::active;
        return true;
    }());
    return isActive;
}

BuildOwner ElementCls::owner() {
    return _owner;
}

void ElementCls::reassemble() {
    if (_debugShouldReassemble(_debugReassembleConfig, _widget)) {
        markNeedsBuild();
        _debugReassembleConfig = nullptr;
    }
    visitChildren([=] (Element child) {
        child->_debugReassembleConfig = _debugReassembleConfig;
        child->reassemble();
    });
    _debugReassembleConfig = nullptr;
}

RenderObject ElementCls::renderObject() {
    RenderObject result;
    InlineMethod;
    visit(this);
    return result;
}

List<DiagnosticsNode> ElementCls::describeMissingAncestor(Type expectedAncestorType) {
    List<DiagnosticsNode> information = makeList();
    List<Element> ancestors = makeList();
    visitAncestorElements([=] (Element element) {
        ancestors->add(element);
        return true;
    });
    information->add(<Element>make<DiagnosticsPropertyCls>(__s("The specific widget that could not find a $expectedAncestorType ancestor was"), this, DiagnosticsTreeStyleCls::errorProperty));
    if (ancestors->isNotEmpty()) {
        information->add(describeElements(__s("The ancestors of this widget were"), ancestors));
    } else {
        information->add(make<ErrorDescriptionCls>(__s("This widget is the root of the tree, so it has no ancestors, let alone a "$expectedAncestorType" ancestor.")));
    }
    return information;
}

DiagnosticsNode ElementCls::describeElements(String name, Iterable<Element> elements) {
    return make<DiagnosticsBlockCls>(name, elements-><DiagnosticsNode>map([=] (Element element) {
        <Element>make<DiagnosticsPropertyCls>(__s(""), element);
    })->toList(), true);
}

DiagnosticsNode ElementCls::describeElement(String name, DiagnosticsTreeStyle style) {
    return <Element>make<DiagnosticsPropertyCls>(name, this, style);
}

DiagnosticsNode ElementCls::describeWidget(String name, DiagnosticsTreeStyle style) {
    return <Element>make<DiagnosticsPropertyCls>(name, this, style);
}

DiagnosticsNode ElementCls::describeOwnershipChain(String name) {
    return make<StringPropertyCls>(name, debugGetCreatorChain(10));
}

void ElementCls::visitChildren(ElementVisitor visitor) {
}

void ElementCls::debugVisitOnstageChildren(ElementVisitor visitor) {
    return visitChildren(visitor);
}

void ElementCls::visitChildElements(ElementVisitor visitor) {
    assert([=] () {
        if (owner() == nullptr || !owner()!->_debugStateLocked()) {
            return true;
        }
        throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem));
    }());
    visitChildren(visitor);
}

Element ElementCls::updateChild(Element child, Widget newWidget, Object newSlot) {
    if (newWidget == nullptr) {
        if (child != nullptr) {
            deactivateChild(child);
        }
        return nullptr;
    }
    Element newChild;
    if (child != nullptr) {
        bool hasSameSuperclass = true;
        assert([=] () {
            int oldElementClass = ElementCls->_debugConcreteSubtype(child);
            int newWidgetClass = WidgetCls->_debugConcreteSubtype(newWidget);
            hasSameSuperclass = oldElementClass == newWidgetClass;
            return true;
        }());
        if (hasSameSuperclass && child->widget() == newWidget) {
            if (child->slot() != newSlot) {
                updateSlotForChild(child, newSlot);
            }
            newChild = child;
        } else {
            if (hasSameSuperclass && WidgetCls->canUpdate(child->widget(), newWidget)) {
            if (child->slot() != newSlot) {
                updateSlotForChild(child, newSlot);
            }
            bool isTimelineTracked = !kReleaseMode && _isProfileBuildsEnabledFor(newWidget);
            if (isTimelineTracked) {
                Map<String, String> debugTimelineArguments;
                assert([=] () {
                    if (kDebugMode && debugEnhanceBuildTimelineArguments) {
                        debugTimelineArguments = newWidget->toDiagnosticsNode()->toTimelineArguments();
                    }
                    return true;
                }());
                TimelineCls->startSync(__s("${newWidget.runtimeType}"), debugTimelineArguments);
            }
            child->update(newWidget);
            if (isTimelineTracked) {
                TimelineCls->finishSync();
            }
            assert(child->widget() == newWidget);
            assert([=] () {
                child->owner()!->_debugElementWasRebuilt(child);
                return true;
            }());
            newChild = child;
        } else {
            deactivateChild(child);
            assert(child->_parent == nullptr);
            newChild = inflateWidget(newWidget, newSlot);
        }
;
        }    } else {
        newChild = inflateWidget(newWidget, newSlot);
    }
    assert([=] () {
        if (child != nullptr) {
            _debugRemoveGlobalKeyReservation(child);
        }
        Key key = newWidget->key;
        if (is<GlobalKey>(key)) {
            assert(owner() != nullptr);
            owner()!->_debugReserveGlobalKeyFor(this, newChild, as<GlobalKeyCls>(key));
        }
        return true;
    }());
    return newChild;
}

void ElementCls::mount(Element parent, Object newSlot) {
    assert(_lifecycleState == _ElementLifecycleCls::initial);
    assert(widget() != nullptr);
    assert(_parent == nullptr);
    assert(parent == nullptr || parent->_lifecycleState == _ElementLifecycleCls::active);
    assert(slot() == nullptr);
    _parent = parent;
    _slot = newSlot;
    _lifecycleState = _ElementLifecycleCls::active;
    _depth = _parent != nullptr? _parent!->depth() + 1 : 1;
    if (parent != nullptr) {
        _owner = parent->owner();
    }
    assert(owner() != nullptr);
    Key key = widget()->key;
    if (is<GlobalKey>(key)) {
        owner()!->_registerGlobalKey(as<GlobalKeyCls>(key), this);
    }
    _updateInheritance();
    attachNotificationTree();
}

void ElementCls::update(Widget newWidget) {
    assert(_lifecycleState == _ElementLifecycleCls::active && widget() != nullptr && newWidget != nullptr && newWidget != widget() && depth() != nullptr && WidgetCls->canUpdate(widget(), newWidget));
    assert([=] () {
        _debugForgottenChildrenWithGlobalKey?->forEach(_debugRemoveGlobalKeyReservation);
        _debugForgottenChildrenWithGlobalKey?->clear();
        return true;
    }());
    _widget = newWidget;
}

void ElementCls::updateSlotForChild(Element child, Object newSlot) {
    assert(_lifecycleState == _ElementLifecycleCls::active);
    assert(child != nullptr);
    assert(child->_parent == this);
    InlineMethod;
    visit(child);
}

void ElementCls::detachRenderObject() {
    visitChildren([=] (Element child) {
        child->detachRenderObject();
    });
    _slot = nullptr;
}

void ElementCls::attachRenderObject(Object newSlot) {
    assert(_slot == nullptr);
    visitChildren([=] (Element child) {
        child->attachRenderObject(newSlot);
    });
    _slot = newSlot;
}

Element ElementCls::inflateWidget(Widget newWidget, Object newSlot) {
    assert(newWidget != nullptr);
    bool isTimelineTracked = !kReleaseMode && _isProfileBuildsEnabledFor(newWidget);
    if (isTimelineTracked) {
        Map<String, String> debugTimelineArguments;
        assert([=] () {
            if (kDebugMode && debugEnhanceBuildTimelineArguments) {
                debugTimelineArguments = newWidget->toDiagnosticsNode()->toTimelineArguments();
            }
            return true;
        }());
        TimelineCls->startSync(__s("${newWidget.runtimeType}"), debugTimelineArguments);
    }
    try {
        Key key = newWidget->key;
        if (is<GlobalKey>(key)) {
            Element newChild = _retakeInactiveElement(as<GlobalKeyCls>(key), newWidget);
            if (newChild != nullptr) {
                assert(newChild->_parent == nullptr);
                assert([=] () {
                    _debugCheckForCycles(newChild);
                    return true;
                }());
                newChild->_activateWithParent(this, newSlot);
                Element updatedChild = updateChild(newChild, newWidget, newSlot);
                assert(newChild == updatedChild);
                return updatedChild!;
            }
        }
        Element newChild = newWidget->createElement();
        assert([=] () {
            _debugCheckForCycles(newChild);
            return true;
        }());
        newChild->mount(this, newSlot);
        assert(newChild->_lifecycleState == _ElementLifecycleCls::active);
        return newChild;
    } finally {
        if (isTimelineTracked) {
            TimelineCls->finishSync();
        }
    };
}

void ElementCls::deactivateChild(Element child) {
    assert(child != nullptr);
    assert(child->_parent == this);
    child->_parent = nullptr;
    child->detachRenderObject();
    owner()!->_inactiveElements->add(child);
    assert([=] () {
        if (debugPrintGlobalKeyedWidgetLifecycle) {
            if (is<GlobalKey>(child->widget()->key)) {
                debugPrint(__s("Deactivated $child (keyed child of $this)"));
            }
        }
        return true;
    }());
}

void ElementCls::forgetChild(Element child) {
    assert([=] () {
        if (is<GlobalKey>(child->widget()->key)) {
            _debugForgottenChildrenWithGlobalKey?->add(child);
        }
        return true;
    }());
}

void ElementCls::activate() {
    assert(_lifecycleState == _ElementLifecycleCls::inactive);
    assert(widget() != nullptr);
    assert(owner() != nullptr);
    assert(depth() != nullptr);
    bool hadDependencies = (_dependencies != nullptr && _dependencies!->isNotEmpty()) || _hadUnsatisfiedDependencies;
    _lifecycleState = _ElementLifecycleCls::active;
    _dependencies?->clear();
    _hadUnsatisfiedDependencies = false;
    _updateInheritance();
    attachNotificationTree();
    if (_dirty) {
        owner()!->scheduleBuildFor(this);
    }
    if (hadDependencies) {
        didChangeDependencies();
    }
}

void ElementCls::deactivate() {
    assert(_lifecycleState == _ElementLifecycleCls::active);
    assert(_widget != nullptr);
    assert(depth() != nullptr);
    if (_dependencies != nullptr && _dependencies!->isNotEmpty()) {
        for (InheritedElement dependency : _dependencies!) {
            dependency->_dependents->remove(this);
        }
    }
    _inheritedWidgets = nullptr;
    _lifecycleState = _ElementLifecycleCls::inactive;
}

void ElementCls::debugDeactivated() {
    assert(_lifecycleState == _ElementLifecycleCls::inactive);
}

void ElementCls::unmount() {
    assert(_lifecycleState == _ElementLifecycleCls::inactive);
    assert(_widget != nullptr);
    assert(depth() != nullptr);
    assert(owner() != nullptr);
    Key key = _widget?->key;
    if (is<GlobalKey>(key)) {
        owner()!->_unregisterGlobalKey(as<GlobalKeyCls>(key), this);
    }
    _widget = nullptr;
    _dependencies = nullptr;
    _lifecycleState = _ElementLifecycleCls::defunct;
}

RenderObject ElementCls::findRenderObject() {
    assert([=] () {
        if (_lifecycleState != _ElementLifecycleCls::active) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
        }
        return true;
    }());
    return renderObject();
}

Size ElementCls::size() {
    assert([=] () {
        if (_lifecycleState != _ElementLifecycleCls::active) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
        }
        if (owner()!->_debugBuilding) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem));
        }
        return true;
    }());
    RenderObject renderObject = findRenderObject();
    assert([=] () {
        if (renderObject == nullptr) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
        }
        if (is<RenderSliver>(renderObject)) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));
        }
        if (!is<RenderBox>(renderObject)) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));
        }
        RenderBox box = renderObject;
        if (!box->hasSize()) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));
        }
        if (box->debugNeedsLayout()) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem));
        }
        return true;
    }());
    if (is<RenderBox>(renderObject)) {
        return as<RenderBoxCls>(renderObject)->size();
    }
    return nullptr;
}

bool ElementCls::doesDependOnInheritedElement(InheritedElement ancestor) {
    return _dependencies != nullptr && _dependencies!->contains(ancestor);
}

InheritedWidget ElementCls::dependOnInheritedElement(InheritedElement ancestor, Object aspect) {
    assert(ancestor != nullptr);
    _dependencies |= <InheritedElement>make<HashSetCls>();
    _dependencies!->add(ancestor);
    ancestor->updateDependencies(this, aspect);
    return as<InheritedWidget>(ancestor->widget());
}

template<typename T>
T ElementCls::dependOnInheritedWidgetOfExactType(Object aspect) {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    InheritedElement ancestor = _inheritedWidgets == nullptr? nullptr : _inheritedWidgets![T];
    if (ancestor != nullptr) {
        return as<T>(dependOnInheritedElement(ancestor, aspect));
    }
    _hadUnsatisfiedDependencies = true;
    return nullptr;
}

template<typename T>
InheritedElement ElementCls::getElementForInheritedWidgetOfExactType() {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    InheritedElement ancestor = _inheritedWidgets == nullptr? nullptr : _inheritedWidgets![T];
    return ancestor;
}

void ElementCls::attachNotificationTree() {
    _notificationTree = _parent?->_notificationTree;
}

template<typename T>
T ElementCls::findAncestorWidgetOfExactType() {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    Element ancestor = _parent;
    while (ancestor != nullptr && ancestor->widget()->runtimeType != T) {
        ancestor = ancestor->_parent;
    }
    return as<T>(ancestor?->widget());
}

template<typename T>
T ElementCls::findAncestorStateOfType() {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    Element ancestor = _parent;
    while (ancestor != nullptr) {
        if (is<StatefulElement>(ancestor) && is<T>(ancestor->state)) {
            break;
        }
        ancestor = ancestor->_parent;
    }
    StatefulElement statefulAncestor = as<StatefulElement>(ancestor);
    return as<T>(statefulAncestor?->state());
}

template<typename T>
T ElementCls::findRootAncestorStateOfType() {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    Element ancestor = _parent;
    StatefulElement statefulAncestor;
    while (ancestor != nullptr) {
        if (is<StatefulElement>(ancestor) && is<T>(ancestor->state)) {
            statefulAncestor = ancestor;
        }
        ancestor = ancestor->_parent;
    }
    return as<T>(statefulAncestor?->state());
}

template<typename T>
T ElementCls::findAncestorRenderObjectOfType() {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    Element ancestor = _parent;
    while (ancestor != nullptr) {
        if (is<RenderObjectElement>(ancestor) && is<T>(ancestor->renderObject())) {
            return as<T>(ancestor->renderObject());
        }
        ancestor = ancestor->_parent;
    }
    return nullptr;
}

void ElementCls::visitAncestorElements(std::function<bool(Element element)> visitor) {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    Element ancestor = _parent;
    while (ancestor != nullptr && visitor(ancestor)) {
        ancestor = ancestor->_parent;
    }
}

void ElementCls::didChangeDependencies() {
    assert(_lifecycleState == _ElementLifecycleCls::active);
    assert(_debugCheckOwnerBuildTargetExists(__s("didChangeDependencies")));
    markNeedsBuild();
}

String ElementCls::debugGetCreatorChain(int limit) {
    List<String> chain = makeList();
    Element node = this;
    while (chain->length() < limit && node != nullptr) {
        chain->add(node->toStringShort());
        node = node->_parent;
    }
    if (node != nullptr) {
        chain->add(__s("\u22EF"));
    }
    return chain->join(__s(" \u2190 "));
}

List<Element> ElementCls::debugGetDiagnosticChain() {
    List<Element> chain = makeList(ArrayItem);
    Element node = _parent;
    while (node != nullptr) {
        chain->add(node);
        node = node->_parent;
    }
    return chain;
}

void ElementCls::dispatchNotification(Notification notification) {
    _notificationTree?->dispatchNotification(notification);
}

String ElementCls::toStringShort() {
    return _widget?->toStringShort() | __s("${describeIdentity(this)}(DEFUNCT)");
}

DiagnosticsNode ElementCls::toDiagnosticsNode(String name, DiagnosticsTreeStyle style) {
    return make<_ElementDiagnosticableTreeNodeCls>(name, this, style);
}

void ElementCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->defaultDiagnosticsTreeStyle = DiagnosticsTreeStyleCls::dense;
    if (_lifecycleState != _ElementLifecycleCls::initial) {
        properties->add(<int>make<ObjectFlagPropertyCls>(__s("depth"), depth(), __s("no depth")));
    }
    properties->add(<Widget>make<ObjectFlagPropertyCls>(__s("widget"), _widget, __s("no widget")));
    properties->add(<Key>make<DiagnosticsPropertyCls>(__s("key"), _widget?->key, false, nullptr, DiagnosticLevelCls::hidden));
    _widget?->debugFillProperties(properties);
    properties->add(make<FlagPropertyCls>(__s("dirty"), dirty(), __s("dirty")));
    Set<InheritedElement> deps = _dependencies;
    if (deps != nullptr && deps->isNotEmpty()) {
            auto _c1 = deps->toList();    _c1.sort([=] (InheritedElement a,InheritedElement b) {        a->toStringShort()->compareTo(b->toStringShort());    });List<InheritedElement> sortedDependencies = _c1;
        List<DiagnosticsNode> diagnosticsDependencies = sortedDependencies->map([=] (InheritedElement element) {
    element->widget->toDiagnosticsNode(DiagnosticsTreeStyleCls::sparse);
})->toList();
        properties->add(<List<DiagnosticsNode>>make<DiagnosticsPropertyCls>(__s("dependencies"), diagnosticsDependencies));
    }
}

List<DiagnosticsNode> ElementCls::debugDescribeChildren() {
    List<DiagnosticsNode> children = makeList();
    visitChildren([=] (Element child) {
        children->add(child->toDiagnosticsNode());
    });
    return children;
}

bool ElementCls::dirty() {
    return _dirty;
}

void ElementCls::markNeedsBuild() {
    assert(_lifecycleState != _ElementLifecycleCls::defunct);
    if (_lifecycleState != _ElementLifecycleCls::active) {
        return;
    }
    assert(owner() != nullptr);
    assert(_lifecycleState == _ElementLifecycleCls::active);
    assert([=] () {
        if (owner()!->_debugBuilding) {
            assert(owner()!->_debugCurrentBuildTarget != nullptr);
            assert(owner()!->_debugStateLocked());
            if (_debugIsInScope(owner()!->_debugCurrentBuildTarget!)) {
                return true;
            }
            if (!_debugAllowIgnoredCallsToMarkNeedsBuild) {
                List<DiagnosticsNode> information = makeList(ArrayItem, ArrayItem, ArrayItem);
                if (owner()!->_debugCurrentBuildTarget != nullptr) {
                    information->add(owner()!->_debugCurrentBuildTarget!->describeWidget(__s("The widget which was currently being built when the offending call was made was")));
                }
                throw FlutterErrorCls->fromParts(information);
            }
            assert(dirty());
        } else {
            if (owner()!->_debugStateLocked()) {
            assert(!_debugAllowIgnoredCallsToMarkNeedsBuild);
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
        }
;
        }        return true;
    }());
    if (dirty()) {
        return;
    }
    _dirty = true;
    owner()!->scheduleBuildFor(this);
}

void ElementCls::rebuild() {
    assert(_lifecycleState != _ElementLifecycleCls::initial);
    if (_lifecycleState != _ElementLifecycleCls::active || !_dirty) {
        return;
    }
    assert([=] () {
        debugOnRebuildDirtyWidget?->call(this, _debugBuiltOnce);
        if (debugPrintRebuildDirtyWidgets) {
            if (!_debugBuiltOnce) {
                debugPrint(__s("Building $this"));
                _debugBuiltOnce = true;
            } else {
                debugPrint(__s("Rebuilding $this"));
            }
        }
        return true;
    }());
    assert(_lifecycleState == _ElementLifecycleCls::active);
    assert(owner()!->_debugStateLocked());
    Element debugPreviousBuildTarget;
    assert([=] () {
        debugPreviousBuildTarget = owner()!->_debugCurrentBuildTarget;
        owner()!->_debugCurrentBuildTarget = this;
        return true;
    }());
    performRebuild();
    assert([=] () {
        assert(owner()!->_debugCurrentBuildTarget == this);
        owner()!->_debugCurrentBuildTarget = debugPreviousBuildTarget;
        return true;
    }());
    assert(!_dirty);
}

int ElementCls::_sort(Element a, Element b) {
    int diff = a->depth() - b->depth();
    if (diff != 0) {
        return diff;
    }
    bool isBDirty = b->dirty();
    if (a->dirty() != isBDirty) {
        return isBDirty? -1 : 1;
    }
    return 0;
}

int ElementCls::_debugConcreteSubtype(Element element) {
    return is<StatefulElement>(element)? 1 : is<StatelessElement>(element)? 2 : 0;
}

bool ElementCls::_debugIsInScope(Element target) {
    Element current = this;
    while (current != nullptr) {
        if (target == current) {
            return true;
        }
        current = current->_parent;
    }
    return false;
}

void ElementCls::_debugRemoveGlobalKeyReservation(Element child) {
    assert(owner() != nullptr);
    owner()!->_debugRemoveGlobalKeyReservationFor(this, child);
}

void ElementCls::_updateSlot(Object newSlot) {
    assert(_lifecycleState == _ElementLifecycleCls::active);
    assert(widget() != nullptr);
    assert(_parent != nullptr);
    assert(_parent!->_lifecycleState == _ElementLifecycleCls::active);
    assert(depth() != nullptr);
    _slot = newSlot;
}

void ElementCls::_updateDepth(int parentDepth) {
    int expectedDepth = parentDepth + 1;
    if ( < expectedDepth) {
        _depth = expectedDepth;
        visitChildren([=] (Element child) {
            child->_updateDepth(expectedDepth);
        });
    }
}

Element ElementCls::_retakeInactiveElement(GlobalKey key, Widget newWidget) {
    Element element = key->_currentElement();
    if (element == nullptr) {
        return nullptr;
    }
    if (!WidgetCls->canUpdate(element->widget(), newWidget)) {
        return nullptr;
    }
    assert([=] () {
        if (debugPrintGlobalKeyedWidgetLifecycle) {
            debugPrint(__s("Attempting to take $element from ${element._parent ?? "inactive elements list"} to put in $this."));
        }
        return true;
    }());
    Element parent = element->_parent;
    if (parent != nullptr) {
        assert([=] () {
            if (parent == this) {
                throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem));
            }
            parent->owner()!->_debugTrackElementThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans(parent, key);
            return true;
        }());
        parent->forgetChild(element);
        parent->deactivateChild(element);
    }
    assert(element->_parent == nullptr);
    owner()!->_inactiveElements->remove(element);
    return element;
}

void ElementCls::_debugCheckForCycles(Element newChild) {
    assert(newChild->_parent == nullptr);
    assert([=] () {
        Element node = this;
        while (node->_parent != nullptr) {
            node = node->_parent!;
        }
        assert(node != newChild);
        return true;
    }());
}

void ElementCls::_activateWithParent(Element parent, Object newSlot) {
    assert(_lifecycleState == _ElementLifecycleCls::inactive);
    _parent = parent;
    assert([=] () {
        if (debugPrintGlobalKeyedWidgetLifecycle) {
            debugPrint(__s("Reactivating $this (now child of $_parent)."));
        }
        return true;
    }());
    _updateDepth(_parent!->depth());
    _activateRecursively(this);
    attachRenderObject(newSlot);
    assert(_lifecycleState == _ElementLifecycleCls::active);
}

void ElementCls::_activateRecursively(Element element) {
    assert(element->_lifecycleState == _ElementLifecycleCls::inactive);
    element->activate();
    assert(element->_lifecycleState == _ElementLifecycleCls::active);
    element->visitChildren(_activateRecursively);
}

bool ElementCls::_debugCheckStateIsActiveForAncestorLookup() {
    assert([=] () {
        if (_lifecycleState != _ElementLifecycleCls::active) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
        }
        return true;
    }());
    return true;
}

void ElementCls::_updateInheritance() {
    assert(_lifecycleState == _ElementLifecycleCls::active);
    _inheritedWidgets = _parent?->_inheritedWidgets;
}

bool ElementCls::_debugCheckOwnerBuildTargetExists(String methodName) {
    assert([=] () {
        if (owner()!->_debugCurrentBuildTarget == nullptr) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
        }
        return true;
    }());
    return true;
}

bool ElementCls::_debugSetAllowIgnoredCallsToMarkNeedsBuild(bool value) {
    assert(_debugAllowIgnoredCallsToMarkNeedsBuild == !value);
    _debugAllowIgnoredCallsToMarkNeedsBuild = value;
    return true;
}

Map<String, Object> _ElementDiagnosticableTreeNodeCls::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> json = super->toJsonMap(delegate);
    Element element = as<Element>(value);
    if (!element->debugIsDefunct()) {
        json[__s("widgetRuntimeType")] = element->widget()->runtimeType->toString();
    }
    json[__s("stateful")] = stateful;
    return json;
}

ErrorWidgetCls::ErrorWidgetCls(Object exception) : LeafRenderObjectWidget(make<UniqueKeyCls>()) {
    {
        message = _stringify(exception);
        _flutterError = is<FlutterError>(exception)? exception : nullptr;
    }
}

void ErrorWidgetCls::withDetails(FlutterError error, String message)

RenderBox ErrorWidgetCls::createRenderObject(BuildContext context) {
    return make<RenderErrorBoxCls>(message);
}

void ErrorWidgetCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    if (_flutterError == nullptr) {
        properties->add(make<StringPropertyCls>(__s("message"), message, false));
    } else {
        properties->add(_flutterError!->toDiagnosticsNode(DiagnosticsTreeStyleCls::whitespace));
    }
}

Widget ErrorWidgetCls::_defaultErrorWidgetBuilder(FlutterErrorDetails details) {
    String message = __s("");
    assert([=] () {
        message = __s("${_stringify(details.exception)}\nSee also: https://flutter.dev/docs/testing/errors");
        return true;
    }());
    Object exception = details->exception;
    return ErrorWidgetCls->withDetails(message, is<FlutterError>(exception)? exception : nullptr);
}

String ErrorWidgetCls::_stringify(Object exception) {
    try {
        return exception->toString();
    } catch (Unknown error) {
    };
    return __s("Error");
}

bool ComponentElementCls::debugDoingBuild() {
    return _debugDoingBuild;
}

void ComponentElementCls::mount(Element parent, Object newSlot) {
    super->mount(parent, newSlot);
    assert(_child == nullptr);
    assert(_lifecycleState == _ElementLifecycleCls::active);
    _firstBuild();
    assert(_child != nullptr);
}

void ComponentElementCls::performRebuild() {
    assert(_debugSetAllowIgnoredCallsToMarkNeedsBuild(true));
    Widget built;
    try {
        assert([=] () {
            _debugDoingBuild = true;
            return true;
        }());
        built = build();
        assert([=] () {
            _debugDoingBuild = false;
            return true;
        }());
        debugWidgetBuilderValue(widget(), built);
    } catch (Unknown e) {
        _debugDoingBuild = false;
            List<DiagnosticsNode> list1 = make<ListCls<>>();    if (kDebugMode) {        list1.add(ArrayItem);    }built = ErrorWidgetCls->builder(_debugReportException(make<ErrorDescriptionCls>(__s("building $this")), e, stack, [=] () {
            list1;
        }));
    } finally {
        _dirty = false;
        assert(_debugSetAllowIgnoredCallsToMarkNeedsBuild(false));
    };
    try {
        _child = updateChild(_child, built, slot());
        assert(_child != nullptr);
    } catch (Unknown e) {
            List<DiagnosticsNode> list2 = make<ListCls<>>();    if (kDebugMode) {        list2.add(ArrayItem);    }built = ErrorWidgetCls->builder(_debugReportException(make<ErrorDescriptionCls>(__s("building $this")), e, stack, [=] () {
            list2;
        }));
        _child = updateChild(nullptr, built, slot());
    };
}

void ComponentElementCls::visitChildren(ElementVisitor visitor) {
    if (_child != nullptr) {
        visitor(_child!);
    }
}

void ComponentElementCls::forgetChild(Element child) {
    assert(child == _child);
    _child = nullptr;
    super->forgetChild(child);
}

void ComponentElementCls::_firstBuild() {
    rebuild();
}

Widget StatelessElementCls::build() {
    return (as<StatelessWidget>(widget()))->build(this);
}

void StatelessElementCls::update(StatelessWidget newWidget) {
    super->update(newWidget);
    assert(widget() == newWidget);
    _dirty = true;
    rebuild();
}

StatefulElementCls::StatefulElementCls(StatefulWidget widget) : ComponentElement(widget) {
    {
        _state = widget->createState();
    }
    {
        assert([=] () {
            if (!state()->_debugTypesAreRight(widget)) {
                throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem));
            }
            return true;
        }());
        assert(state()->_element == nullptr);
        state()->_element = this;
        assert(state()->_widget == nullptr, __s("The createState function for $widget returned an old or invalid state instance: ${state._widget}, which is not null, violating the contract for createState."));
        state()->_widget = widget;
        assert(state()->_debugLifecycleState == _StateLifecycleCls::created);
    }
}

Widget StatefulElementCls::build() {
    return state()->build(this);
}

State<StatefulWidget> StatefulElementCls::state() {
    return _state!;
}

void StatefulElementCls::reassemble() {
    if (_debugShouldReassemble(_debugReassembleConfig, _widget)) {
        state()->reassemble();
    }
    super->reassemble();
}

void StatefulElementCls::performRebuild() {
    if (_didChangeDependencies) {
        state()->didChangeDependencies();
        _didChangeDependencies = false;
    }
    super->performRebuild();
}

void StatefulElementCls::update(StatefulWidget newWidget) {
    super->update(newWidget);
    assert(widget() == newWidget);
    StatefulWidget oldWidget = state()->_widget!;
    _dirty = true;
    state()->_widget = as<StatefulWidget>(widget());
    try {
        _debugSetAllowIgnoredCallsToMarkNeedsBuild(true);
        Object debugCheckForReturnedFuture = as<dynamic>(state()->didUpdateWidget(oldWidget));
        assert([=] () {
            if (is<Future>(debugCheckForReturnedFuture)) {
                throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
            }
            return true;
        }());
    } finally {
        _debugSetAllowIgnoredCallsToMarkNeedsBuild(false);
    };
    rebuild();
}

void StatefulElementCls::activate() {
    super->activate();
    state()->activate();
    assert(_lifecycleState == _ElementLifecycleCls::active);
    markNeedsBuild();
}

void StatefulElementCls::deactivate() {
    state()->deactivate();
    super->deactivate();
}

void StatefulElementCls::unmount() {
    super->unmount();
    state()->dispose();
    assert([=] () {
        if (state()->_debugLifecycleState == _StateLifecycleCls::defunct) {
            return true;
        }
        throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem));
    }());
    state()->_element = nullptr;
    _state = nullptr;
}

InheritedWidget StatefulElementCls::dependOnInheritedElement(Element ancestor, Object aspect) {
    assert(ancestor != nullptr);
    assert([=] () {
        Type targetType = ancestor->widget()->runtimeType;
        if (state()->_debugLifecycleState == _StateLifecycleCls::created) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
        }
        if (state()->_debugLifecycleState == _StateLifecycleCls::defunct) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));
        }
        return true;
    }());
    return super->dependOnInheritedElement(as<InheritedElement>(ancestor), aspect);
}

void StatefulElementCls::didChangeDependencies() {
    super->didChangeDependencies();
    _didChangeDependencies = true;
}

DiagnosticsNode StatefulElementCls::toDiagnosticsNode(String name, DiagnosticsTreeStyle style) {
    return make<_ElementDiagnosticableTreeNodeCls>(name, this, style, true);
}

void StatefulElementCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<State<StatefulWidget>>make<DiagnosticsPropertyCls>(__s("state"), _state, nullptr));
}

void StatefulElementCls::_firstBuild() {
    assert(state()->_debugLifecycleState == _StateLifecycleCls::created);
    try {
        _debugSetAllowIgnoredCallsToMarkNeedsBuild(true);
        Object debugCheckForReturnedFuture = as<dynamic>(state()->initState());
        assert([=] () {
            if (is<Future>(debugCheckForReturnedFuture)) {
                throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
            }
            return true;
        }());
    } finally {
        _debugSetAllowIgnoredCallsToMarkNeedsBuild(false);
    };
    assert([=] () {
        state()->_debugLifecycleState = _StateLifecycleCls::initialized;
        return true;
    }());
    state()->didChangeDependencies();
    assert([=] () {
        state()->_debugLifecycleState = _StateLifecycleCls::ready;
        return true;
    }());
    super->_firstBuild();
}

Widget ProxyElementCls::build() {
    return (as<ProxyWidget>(widget()))->child;
}

void ProxyElementCls::update(ProxyWidget newWidget) {
    ProxyWidget oldWidget = as<ProxyWidget>(widget());
    assert(widget() != nullptr);
    assert(widget() != newWidget);
    super->update(newWidget);
    assert(widget() == newWidget);
    updated(oldWidget);
    _dirty = true;
    rebuild();
}

void ProxyElementCls::updated(ProxyWidget oldWidget) {
    notifyClients(oldWidget);
}

template<typename T>
void ParentDataElementCls<T>::applyWidgetOutOfTurn(ParentDataWidget<T> newWidget) {
    assert(newWidget != nullptr);
    assert(newWidget->debugCanApplyOutOfTurn());
    assert(newWidget->child == (as<ParentDataWidget<T>>(widget()))->child);
    _applyParentData(newWidget);
}

template<typename T>
void ParentDataElementCls<T>::notifyClients(ParentDataWidget<T> oldWidget) {
    _applyParentData(as<ParentDataWidget<T>>(widget()));
}

template<typename T>
void ParentDataElementCls<T>::_applyParentData(ParentDataWidget<T> widget) {
    InlineMethod;
    visitChildren(applyParentDataToChild);
}

void InheritedElementCls::debugDeactivated() {
    assert([=] () {
        assert(_dependents->isEmpty());
        return true;
    }());
    super->debugDeactivated();
}

Object InheritedElementCls::getDependencies(Element dependent) {
    return _dependents[dependent];
}

void InheritedElementCls::setDependencies(Element dependent, Object value) {
    _dependents[dependent] = value;
}

void InheritedElementCls::updateDependencies(Element dependent, Object aspect) {
    setDependencies(dependent, nullptr);
}

void InheritedElementCls::notifyDependent(InheritedWidget oldWidget, Element dependent) {
    dependent->didChangeDependencies();
}

void InheritedElementCls::updated(InheritedWidget oldWidget) {
    if ((as<InheritedWidget>(widget()))->updateShouldNotify(oldWidget)) {
        super->updated(oldWidget);
    }
}

void InheritedElementCls::notifyClients(InheritedWidget oldWidget) {
    assert(_debugCheckOwnerBuildTargetExists(__s("notifyClients")));
    for (Element dependent : _dependents->keys()) {
        assert([=] () {
            Element ancestor = dependent->_parent;
            while (ancestor != this && ancestor != nullptr) {
                ancestor = ancestor->_parent;
            }
            return ancestor == this;
        }());
        assert(dependent->_dependencies!->contains(this));
        notifyDependent(oldWidget, dependent);
    }
}

void InheritedElementCls::_updateInheritance() {
    assert(_lifecycleState == _ElementLifecycleCls::active);
    Map<Type, InheritedElement> incomingWidgets = _parent?->_inheritedWidgets;
    if (incomingWidgets != nullptr) {
        _inheritedWidgets = <Type, InheritedElement>of(incomingWidgets);
    } else {
        _inheritedWidgets = <Type, InheritedElement>make<HashMapCls>();
    }
    _inheritedWidgets![widget()->runtimeType] = this;
}

RenderObject RenderObjectElementCls::renderObject() {
    assert(_renderObject != nullptr, __s("$runtimeType unmounted"));
    return _renderObject!;
}

bool RenderObjectElementCls::debugDoingBuild() {
    return _debugDoingBuild;
}

void RenderObjectElementCls::mount(Element parent, Object newSlot) {
    super->mount(parent, newSlot);
    assert([=] () {
        _debugDoingBuild = true;
        return true;
    }());
    _renderObject = (as<RenderObjectWidget>(widget()))->createRenderObject(this);
    assert(!_renderObject!->debugDisposed()!);
    assert([=] () {
        _debugDoingBuild = false;
        return true;
    }());
    assert([=] () {
        _debugUpdateRenderObjectOwner();
        return true;
    }());
    assert(_slot == newSlot);
    attachRenderObject(newSlot);
    _dirty = false;
}

void RenderObjectElementCls::update(RenderObjectWidget newWidget) {
    super->update(newWidget);
    assert(widget() == newWidget);
    assert([=] () {
        _debugUpdateRenderObjectOwner();
        return true;
    }());
    _performRebuild();
}

void RenderObjectElementCls::performRebuild() {
    _performRebuild();
}

List<Element> RenderObjectElementCls::updateChildren(List<Element> oldChildren, List<Widget> newWidgets, Set<Element> forgottenChildren, List<Object> slots) {
    assert(oldChildren != nullptr);
    assert(newWidgets != nullptr);
    assert(slots == nullptr || newWidgets->length() == slots->length());
    InlineMethod;
    InlineMethod;
    int newChildrenTop = 0;
    int oldChildrenTop = 0;
    int newChildrenBottom = newWidgets->length() - 1;
    int oldChildrenBottom = oldChildren->length() - 1;
    List<Element> newChildren = oldChildren->length() == newWidgets->length()? oldChildren : <Element>filled(newWidgets->length(), _NullElementCls::instance);
    Element previousChild;
    while ((oldChildrenTop <= oldChildrenBottom) && (newChildrenTop <= newChildrenBottom)) {
        Element oldChild = replaceWithNullIfForgotten(oldChildren[oldChildrenTop]);
        Widget newWidget = newWidgets[newChildrenTop];
        assert(oldChild == nullptr || oldChild->_lifecycleState == _ElementLifecycleCls::active);
        if (oldChild == nullptr || !WidgetCls->canUpdate(oldChild->widget(), newWidget)) {
            break;
        }
        Element newChild = updateChild(oldChild, newWidget, slotFor(newChildrenTop, previousChild))!;
        assert(newChild->_lifecycleState == _ElementLifecycleCls::active);
        newChildren[newChildrenTop] = newChild;
        previousChild = newChild;
        newChildrenTop += 1;
        oldChildrenTop += 1;
    }
    while ((oldChildrenTop <= oldChildrenBottom) && (newChildrenTop <= newChildrenBottom)) {
        Element oldChild = replaceWithNullIfForgotten(oldChildren[oldChildrenBottom]);
        Widget newWidget = newWidgets[newChildrenBottom];
        assert(oldChild == nullptr || oldChild->_lifecycleState == _ElementLifecycleCls::active);
        if (oldChild == nullptr || !WidgetCls->canUpdate(oldChild->widget(), newWidget)) {
            break;
        }
        oldChildrenBottom -= 1;
        newChildrenBottom -= 1;
    }
    bool haveOldChildren = oldChildrenTop <= oldChildrenBottom;
    Map<Key, Element> oldKeyedChildren;
    if (haveOldChildren) {
        oldKeyedChildren = makeMap(makeList(), makeList();
        while (oldChildrenTop <= oldChildrenBottom) {
            Element oldChild = replaceWithNullIfForgotten(oldChildren[oldChildrenTop]);
            assert(oldChild == nullptr || oldChild->_lifecycleState == _ElementLifecycleCls::active);
            if (oldChild != nullptr) {
                if (oldChild->widget()->key != nullptr) {
                    oldKeyedChildren[oldChild->widget()->key!] = oldChild;
                } else {
                    deactivateChild(oldChild);
                }
            }
            oldChildrenTop += 1;
        }
    }
    while (newChildrenTop <= newChildrenBottom) {
        Element oldChild;
        Widget newWidget = newWidgets[newChildrenTop];
        if (haveOldChildren) {
            Key key = newWidget->key;
            if (key != nullptr) {
                oldChild = oldKeyedChildren![key];
                if (oldChild != nullptr) {
                    if (WidgetCls->canUpdate(oldChild->widget(), newWidget)) {
                        oldKeyedChildren->remove(key);
                    } else {
                        oldChild = nullptr;
                    }
                }
            }
        }
        assert(oldChild == nullptr || WidgetCls->canUpdate(oldChild->widget(), newWidget));
        Element newChild = updateChild(oldChild, newWidget, slotFor(newChildrenTop, previousChild))!;
        assert(newChild->_lifecycleState == _ElementLifecycleCls::active);
        assert(oldChild == newChild || oldChild == nullptr || oldChild->_lifecycleState != _ElementLifecycleCls::active);
        newChildren[newChildrenTop] = newChild;
        previousChild = newChild;
        newChildrenTop += 1;
    }
    assert(oldChildrenTop == oldChildrenBottom + 1);
    assert(newChildrenTop == newChildrenBottom + 1);
    assert(newWidgets->length() - newChildrenTop == oldChildren->length() - oldChildrenTop);
    newChildrenBottom = newWidgets->length() - 1;
    oldChildrenBottom = oldChildren->length() - 1;
    while ((oldChildrenTop <= oldChildrenBottom) && (newChildrenTop <= newChildrenBottom)) {
        Element oldChild = oldChildren[oldChildrenTop];
        assert(replaceWithNullIfForgotten(oldChild) != nullptr);
        assert(oldChild->_lifecycleState == _ElementLifecycleCls::active);
        Widget newWidget = newWidgets[newChildrenTop];
        assert(WidgetCls->canUpdate(oldChild->widget(), newWidget));
        Element newChild = updateChild(oldChild, newWidget, slotFor(newChildrenTop, previousChild))!;
        assert(newChild->_lifecycleState == _ElementLifecycleCls::active);
        assert(oldChild == newChild || oldChild == nullptr || oldChild->_lifecycleState != _ElementLifecycleCls::active);
        newChildren[newChildrenTop] = newChild;
        previousChild = newChild;
        newChildrenTop += 1;
        oldChildrenTop += 1;
    }
    if (haveOldChildren && oldKeyedChildren!->isNotEmpty()) {
        for (Element oldChild : oldKeyedChildren->values()) {
            if (forgottenChildren == nullptr || !forgottenChildren->contains(oldChild)) {
                deactivateChild(oldChild);
            }
        }
    }
    assert(newChildren->every([=] (Element element) {
        !is<_NullElement>(element);
    }));
    return newChildren;
}

void RenderObjectElementCls::deactivate() {
    super->deactivate();
    assert(!renderObject()->attached(), __s("A RenderObject was still attached when attempting to deactivate its RenderObjectElement: $renderObject"));
}

void RenderObjectElementCls::unmount() {
    assert(!renderObject()->debugDisposed()!, __s("A RenderObject was disposed prior to its owning element being unmounted: $renderObject"));
    RenderObjectWidget oldWidget = as<RenderObjectWidget>(widget());
    super->unmount();
    assert(!renderObject()->attached(), __s("A RenderObject was still attached when attempting to unmount its RenderObjectElement: $renderObject"));
    oldWidget->didUnmountRenderObject(renderObject());
    _renderObject!->dispose();
    _renderObject = nullptr;
}

void RenderObjectElementCls::attachRenderObject(Object newSlot) {
    assert(_ancestorRenderObjectElement == nullptr);
    _slot = newSlot;
    _ancestorRenderObjectElement = _findAncestorRenderObjectElement();
    _ancestorRenderObjectElement?->insertRenderObjectChild(renderObject(), newSlot);
    ParentDataElement<ParentData> parentDataElement = _findAncestorParentDataElement();
    if (parentDataElement != nullptr) {
        _updateParentData(as<ParentDataWidget<ParentData>>(parentDataElement->widget()));
    }
}

void RenderObjectElementCls::detachRenderObject() {
    if (_ancestorRenderObjectElement != nullptr) {
        _ancestorRenderObjectElement!->removeRenderObjectChild(renderObject(), slot());
        _ancestorRenderObjectElement = nullptr;
    }
    _slot = nullptr;
}

void RenderObjectElementCls::insertRenderObjectChild(RenderObject child, Object slot) {
    assert([=] () {
        throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));
    }());
}

void RenderObjectElementCls::moveRenderObjectChild(RenderObject child, Object oldSlot, Object newSlot) {
    assert([=] () {
        throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));
    }());
}

void RenderObjectElementCls::removeRenderObjectChild(RenderObject child, Object slot) {
    assert([=] () {
        throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));
    }());
}

void RenderObjectElementCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<RenderObject>make<DiagnosticsPropertyCls>(__s("renderObject"), _renderObject, nullptr));
}

RenderObjectElement RenderObjectElementCls::_findAncestorRenderObjectElement() {
    Element ancestor = _parent;
    while (ancestor != nullptr && !is<RenderObjectElement>(ancestor)) {
        ancestor = ancestor->_parent;
    }
    return as<RenderObjectElement>(ancestor);
}

ParentDataElement<ParentData> RenderObjectElementCls::_findAncestorParentDataElement() {
    Element ancestor = _parent;
    ParentDataElement<ParentData> result;
    while (ancestor != nullptr && !is<RenderObjectElement>(ancestor)) {
        if (is<ParentDataElement<ParentData>>(ancestor)) {
            result = as<ParentDataElementCls>(ancestor);
            break;
        }
        ancestor = ancestor->_parent;
    }
    assert([=] () {
        if (result == nullptr || ancestor == nullptr) {
            return true;
        }
        List<ParentDataElement<ParentData>> badAncestors = makeList();
        ancestor = ancestor!->_parent;
        while (ancestor != nullptr && !is<RenderObjectElement>(ancestor)) {
            if (is<ParentDataElement<ParentData>>(ancestor)) {
                badAncestors->add(as<ParentDataElement<ParentData>>(as<ParentDataElementCls>(ancestor)!));
            }
            ancestor = ancestor!->_parent;
        }
        if (badAncestors->isNotEmpty()) {
            badAncestors->insert(0, result);
            try {
                            List<DiagnosticsNode> list1 = make<ListCls<>>();            list1.add(ArrayItem);            list1.add(ArrayItem);            for (ParentDataElement<ParentData> ancestor : badAncestors) {                                ;                            }            {                list1.add(ArrayItem);            }list1.add(ArrayItem);            list1.add(ArrayItem);            list1.add(ArrayItem);throw FlutterErrorCls->fromParts(list1);
            } catch (FlutterError e) {
                _debugReportException(make<ErrorSummaryCls>(__s("while looking for parent data.")), e, e->stackTrace);
            };
        }
        return true;
    }());
    return result;
}

void RenderObjectElementCls::_debugUpdateRenderObjectOwner() {
    assert([=] () {
        renderObject()->debugCreator = make<DebugCreatorCls>(this);
        return true;
    }());
}

void RenderObjectElementCls::_performRebuild() {
    assert([=] () {
        _debugDoingBuild = true;
        return true;
    }());
    (as<RenderObjectWidget>(widget()))->updateRenderObject(this, renderObject());
    assert([=] () {
        _debugDoingBuild = false;
        return true;
    }());
    _dirty = false;
}

void RenderObjectElementCls::_updateParentData(ParentDataWidget<ParentData> parentDataWidget) {
    bool applyParentData = true;
    assert([=] () {
        try {
            if (!parentDataWidget->debugIsValidRenderObject(renderObject())) {
                applyParentData = false;
                            List<DiagnosticsNode> list1 = make<ListCls<>>();            list1.add(ArrayItem);            for (auto _x1 : parentDataWidget->_debugDescribeIncorrectParentDataType(renderObject()->parentData, as<RenderObjectWidget>(_ancestorRenderObjectElement!->widget()), make<ErrorDescriptionCls>(debugGetCreatorChain(10)))) {            {                list1.add(_x1);            }throw FlutterErrorCls->fromParts(list1);
            }
        } catch (FlutterError e) {
            _debugReportException(make<ErrorSummaryCls>(__s("while applying parent data.")), e, e->stackTrace);
        };
        return true;
    }());
    if (applyParentData) {
        parentDataWidget->applyParentData(renderObject());
    }
}

void RenderObjectElementCls::_updateSlot(Object newSlot) {
    Object oldSlot = slot();
    assert(oldSlot != newSlot);
    super->_updateSlot(newSlot);
    assert(slot() == newSlot);
    _ancestorRenderObjectElement!->moveRenderObjectChild(renderObject(), oldSlot, slot());
}

void RootRenderObjectElementCls::assignOwner(BuildOwner owner) {
    _owner = owner;
}

void RootRenderObjectElementCls::mount(Element parent, Object newSlot) {
    assert(parent == nullptr);
    assert(newSlot == nullptr);
    super->mount(parent, newSlot);
}

void LeafRenderObjectElementCls::forgetChild(Element child) {
    assert(false);
    super->forgetChild(child);
}

void LeafRenderObjectElementCls::insertRenderObjectChild(RenderObject child, Object slot) {
    assert(false);
}

void LeafRenderObjectElementCls::moveRenderObjectChild(RenderObject child, Object oldSlot, Object newSlot) {
    assert(false);
}

void LeafRenderObjectElementCls::removeRenderObjectChild(RenderObject child, Object slot) {
    assert(false);
}

List<DiagnosticsNode> LeafRenderObjectElementCls::debugDescribeChildren() {
    return widget()->debugDescribeChildren();
}

void SingleChildRenderObjectElementCls::visitChildren(ElementVisitor visitor) {
    if (_child != nullptr) {
        visitor(_child!);
    }
}

void SingleChildRenderObjectElementCls::forgetChild(Element child) {
    assert(child == _child);
    _child = nullptr;
    super->forgetChild(child);
}

void SingleChildRenderObjectElementCls::mount(Element parent, Object newSlot) {
    super->mount(parent, newSlot);
    _child = updateChild(_child, (as<SingleChildRenderObjectWidget>(widget()))->child, nullptr);
}

void SingleChildRenderObjectElementCls::update(SingleChildRenderObjectWidget newWidget) {
    super->update(newWidget);
    assert(widget() == newWidget);
    _child = updateChild(_child, (as<SingleChildRenderObjectWidget>(widget()))->child, nullptr);
}

void SingleChildRenderObjectElementCls::insertRenderObjectChild(RenderObject child, Object slot) {
    RenderObjectWithChildMixin<RenderObject> renderObject = as<RenderObjectWithChildMixin<RenderObject>>(this->renderObject());
    assert(slot == nullptr);
    assert(renderObject->debugValidateChild(child));
    renderObject->child = child;
    assert(renderObject == this->renderObject);
}

void SingleChildRenderObjectElementCls::moveRenderObjectChild(RenderObject child, Object oldSlot, Object newSlot) {
    assert(false);
}

void SingleChildRenderObjectElementCls::removeRenderObjectChild(RenderObject child, Object slot) {
    RenderObjectWithChildMixin<RenderObject> renderObject = as<RenderObjectWithChildMixin<RenderObject>>(this->renderObject());
    assert(slot == nullptr);
    assert(renderObject->child == child);
    renderObject->child = nullptr;
    assert(renderObject == this->renderObject);
}

MultiChildRenderObjectElementCls::MultiChildRenderObjectElementCls(MultiChildRenderObjectWidget widget) {
    {
        assert(!debugChildrenHaveDuplicateKeys(widget, widget->children));
    }
}

ContainerRenderObjectMixin<RenderObject, ContainerParentDataMixin<RenderObject>> MultiChildRenderObjectElementCls::renderObject() {
    return as<ContainerRenderObjectMixin<RenderObject, ContainerParentDataMixin<RenderObject>>>(super->renderObject);
}

Iterable<Element> MultiChildRenderObjectElementCls::children() {
    return _children->where([=] (Element child) {
        !_forgottenChildren->contains(child);
    });
}

void MultiChildRenderObjectElementCls::insertRenderObjectChild(RenderObject child, IndexedSlot<Element> slot) {
    ContainerRenderObjectMixin<RenderObject, ContainerParentDataMixin<RenderObject>> renderObject = this->renderObject();
    assert(renderObject->debugValidateChild(child));
    renderObject->insert(child, slot->value?->renderObject);
    assert(renderObject == this->renderObject);
}

void MultiChildRenderObjectElementCls::moveRenderObjectChild(RenderObject child, IndexedSlot<Element> oldSlot, IndexedSlot<Element> newSlot) {
    ContainerRenderObjectMixin<RenderObject, ContainerParentDataMixin<RenderObject>> renderObject = this->renderObject();
    assert(child->parent() == renderObject);
    renderObject->move(child, newSlot->value?->renderObject);
    assert(renderObject == this->renderObject);
}

void MultiChildRenderObjectElementCls::removeRenderObjectChild(RenderObject child, Object slot) {
    ContainerRenderObjectMixin<RenderObject, ContainerParentDataMixin<RenderObject>> renderObject = this->renderObject();
    assert(child->parent() == renderObject);
    renderObject->remove(child);
    assert(renderObject == this->renderObject);
}

void MultiChildRenderObjectElementCls::visitChildren(ElementVisitor visitor) {
    for (Element child : _children) {
        if (!_forgottenChildren->contains(child)) {
            visitor(child);
        }
    }
}

void MultiChildRenderObjectElementCls::forgetChild(Element child) {
    assert(_children->contains(child));
    assert(!_forgottenChildren->contains(child));
    _forgottenChildren->add(child);
    super->forgetChild(child);
}

Element MultiChildRenderObjectElementCls::inflateWidget(Widget newWidget, Object newSlot) {
    Element newChild = super->inflateWidget(newWidget, newSlot);
    assert(_debugCheckHasAssociatedRenderObject(newChild));
    return newChild;
}

void MultiChildRenderObjectElementCls::mount(Element parent, Object newSlot) {
    super->mount(parent, newSlot);
    MultiChildRenderObjectWidget multiChildRenderObjectWidget = as<MultiChildRenderObjectWidget>(widget());
    List<Element> children = <Element>filled(multiChildRenderObjectWidget->children->length(), _NullElementCls::instance);
    Element previousChild;
    for (;  < children->length(); i += 1) {
        Element newChild = inflateWidget(multiChildRenderObjectWidget->children[i], <Element>make<IndexedSlotCls>(i, previousChild));
        children[i] = newChild;
        previousChild = newChild;
    }
    _children = children;
}

void MultiChildRenderObjectElementCls::update(MultiChildRenderObjectWidget newWidget) {
    super->update(newWidget);
    MultiChildRenderObjectWidget multiChildRenderObjectWidget = as<MultiChildRenderObjectWidget>(widget());
    assert(widget() == newWidget);
    assert(!debugChildrenHaveDuplicateKeys(widget(), multiChildRenderObjectWidget->children));
    _children = updateChildren(_children, multiChildRenderObjectWidget->children, _forgottenChildren);
    _forgottenChildren->clear();
}

bool MultiChildRenderObjectElementCls::_debugCheckHasAssociatedRenderObject(Element newChild) {
    assert([=] () {
        if (newChild->renderObject() == nullptr) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem))));
        }
        return true;
    }());
    return true;
}

String DebugCreatorCls::toString() {
    return element->debugGetCreatorChain(12);
}

FlutterErrorDetails _debugReportException(DiagnosticsNode context, Object exception, StackTrace stack, InformationCollector informationCollector) {
    FlutterErrorDetails details = make<FlutterErrorDetailsCls>(exception, stack, __s("widgets library"), context, informationCollector);
    FlutterErrorCls->reportError(details);
    return details;
}

template<typename T>
bool IndexedSlotCls<T>::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<IndexedSlot>(other) && index == other->index && value == other->value;
}

template<typename T>
int IndexedSlotCls<T>::hashCode() {
    return ObjectCls->hash(index, value);
}

bool _NullElementCls::debugDoingBuild() {
    return throw make<UnimplementedErrorCls>();
}

void _NullElementCls::performRebuild() {
    return throw make<UnimplementedErrorCls>();
}

_NullElementCls::_NullElementCls() : Element(make<_NullWidgetCls>()) {
}

Element _NullWidgetCls::createElement() {
    return throw make<UnimplementedErrorCls>();
}

bool _debugShouldReassemble(DebugReassembleConfig config, Widget widget) {
    return config == nullptr || config->widgetName == nullptr || widget?->runtimeType->toString() == config->widgetName;
}
