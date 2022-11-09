#include "framework.hpp"
bool ObjectKeyCls::==(Object other) {
    if (other->runtimeType != runtimeType) {
        return false;
    }
    return other is ObjectKey && identical(other->value, value);
}

int ObjectKeyCls::hashCode() {
    return ObjectCls->hash(runtimeType, identityHashCode(value));
}

String ObjectKeyCls::toString() {
    if (runtimeType == ObjectKeyCls) {
        return "[${describeIdentity(value)}]";
    }
    return "[${objectRuntimeType(this, 'ObjectKey')} ${describeIdentity(value)}]";
}

template<typename T : State<StatefulWidget>> GlobalKeyCls<T>::GlobalKeyCls(String debugLabel) {
}

template<typename T : State<StatefulWidget>> void GlobalKeyCls<T>::constructor()

template<typename T : State<StatefulWidget>> BuildContext GlobalKeyCls<T>::currentContext() {
    return _currentElement;
}

template<typename T : State<StatefulWidget>> Widget GlobalKeyCls<T>::currentWidget() {
    return _currentElement?->widget;
}

template<typename T : State<StatefulWidget>> T GlobalKeyCls<T>::currentState() {
    Element element = _currentElement;
    if (element is StatefulElement) {
        StatefulElement statefulElement = element;
        State state = statefulElement->state;
        if (state is T) {
            return state;
        }
    }
    return nullptr;
}

template<typename T : State<StatefulWidget>> Element GlobalKeyCls<T>::_currentElement() {
    return WidgetsBindingCls::instance->buildOwner!->_globalKeyRegistry[this];
}

template<typename T : State<StatefulWidget>> LabeledGlobalKeyCls<T>::LabeledGlobalKeyCls(String _debugLabel) {
    {
        super->constructor();
    }
}

template<typename T : State<StatefulWidget>> String LabeledGlobalKeyCls<T>::toString() {
    String label = _debugLabel != nullptr? " $_debugLabel" : "";
    if (runtimeType == LabeledGlobalKeyCls) {
        return "[GlobalKey#${shortHash(this)}$label]";
    }
    return "[${describeIdentity(this)}$label]";
}

template<typename T : State<StatefulWidget>> GlobalObjectKeyCls<T>::GlobalObjectKeyCls(Object value) {
    {
        super->constructor();
    }
}

template<typename T : State<StatefulWidget>> bool GlobalObjectKeyCls<T>::==(Object other) {
    if (other->runtimeType != runtimeType) {
        return false;
    }
    return other is GlobalObjectKey<T> && identical(other->value, value);
}

template<typename T : State<StatefulWidget>> int GlobalObjectKeyCls<T>::hashCode() {
    return identityHashCode(value);
}

template<typename T : State<StatefulWidget>> String GlobalObjectKeyCls<T>::toString() {
    String selfType = objectRuntimeType(this, "GlobalObjectKey");
    String suffix = "<State<StatefulWidget>>";
    if (selfType->endsWith(suffix)) {
        selfType = selfType->substring(0, selfType->length - suffix->length);
    }
    return "[$selfType ${describeIdentity(value)}]";
}

String WidgetCls::toStringShort() {
    String type = objectRuntimeType(this, "Widget");
    return key == nullptr? type : "$type-$key";
}

void WidgetCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->defaultDiagnosticsTreeStyle = DiagnosticsTreeStyleCls::dense;
}

bool WidgetCls::==(Object other) {
    return super == other;
}

int WidgetCls::hashCode() {
    return super->hashCode;
}

bool WidgetCls::canUpdate(Widget newWidget, Widget oldWidget) {
    return oldWidget->runtimeType == newWidget->runtimeType && oldWidget->key == newWidget->key;
}

int WidgetCls::_debugConcreteSubtype(Widget widget) {
    return widget is StatefulWidget? 1 : widget is StatelessWidget? 2 : 0;
}

StatelessElement StatelessWidgetCls::createElement() {
    return make<StatelessElementCls>(this);
}

StatefulElement StatefulWidgetCls::createElement() {
    return make<StatefulElementCls>(this);
}

template<typename T : StatefulWidget> T StateCls<T>::widget() {
    return _widget!;
}

template<typename T : StatefulWidget> BuildContext StateCls<T>::context() {
    assert([=] () {
        if (_element == nullptr) {
            ;
        }
        return true;
    }());
    return _element!;
}

template<typename T : StatefulWidget> bool StateCls<T>::mounted() {
    return _element != nullptr;
}

template<typename T : StatefulWidget> void StateCls<T>::initState() {
    assert(_debugLifecycleState == _StateLifecycleCls::created);
}

template<typename T : StatefulWidget> void StateCls<T>::didUpdateWidget(T oldWidget) {
}

template<typename T : StatefulWidget> void StateCls<T>::reassemble() {
}

template<typename T : StatefulWidget> void StateCls<T>::setState(VoidCallback fn) {
    assert(fn != nullptr);
    assert([=] () {
        if (_debugLifecycleState == _StateLifecycleCls::defunct) {
            ;
        }
        if (_debugLifecycleState == _StateLifecycleCls::created && !mounted) {
            ;
        }
        return true;
    }());
    Object result = ((dynamic)fn());
    assert([=] () {
        if (result is Future) {
            ;
        }
        return true;
    }());
    _element!->markNeedsBuild();
}

template<typename T : StatefulWidget> void StateCls<T>::deactivate() {
}

template<typename T : StatefulWidget> void StateCls<T>::activate() {
}

template<typename T : StatefulWidget> void StateCls<T>::dispose() {
    assert(_debugLifecycleState == _StateLifecycleCls::ready);
    assert([=] () {
        _debugLifecycleState = _StateLifecycleCls::defunct;
        return true;
    }());
}

template<typename T : StatefulWidget> void StateCls<T>::didChangeDependencies() {
}

template<typename T : StatefulWidget> void StateCls<T>::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    assert([=] () {
        properties->add(<_StateLifecycle>make<EnumPropertyCls>("lifecycle state", _debugLifecycleState_StateLifecycleCls::ready));
        return true;
    }());
    properties->add(<T>make<ObjectFlagPropertyCls>("_widget", _widget"no widget"));
    properties->add(<StatefulElement>make<ObjectFlagPropertyCls>("_element", _element"not mounted"));
}

template<typename T : StatefulWidget> bool StateCls<T>::_debugTypesAreRight(Widget widget) {
    return widget is T;
}

template<typename T : ParentData> ParentDataElement<T> ParentDataWidgetCls<T>::createElement() {
    return <T>make<ParentDataElementCls>(this);
}

template<typename T : ParentData> bool ParentDataWidgetCls<T>::debugIsValidRenderObject(RenderObject renderObject) {
    assert(TCls != dynamic);
    assert(TCls != ParentDataCls);
    return renderObject->parentData is T;
}

template<typename T : ParentData> bool ParentDataWidgetCls<T>::debugCanApplyOutOfTurn() {
    return false;
}

template<typename T : ParentData> Iterable<DiagnosticsNode> ParentDataWidgetCls<T>::_debugDescribeIncorrectParentDataType(DiagnosticsNode ownershipChain, ParentData parentData, RenderObjectWidget parentDataCreator) {
    assert(TCls != dynamic);
    assert(TCls != ParentDataCls);
    assert(debugTypicalAncestorWidgetClass != nullptr);
    String description = "The ParentDataWidget $this wants to apply ParentData of type $T to a RenderObject";
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

MultiChildRenderObjectWidgetCls::MultiChildRenderObjectWidgetCls(List<Widget> children, Unknown key) {
    {
        assert(children != nullptr);
    }
    {
        assert([=] () {
            for (;  < children->length; index++) {
                if (children[index] == nullptr) {
                    ;
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
            if (element->widget->key is GlobalKey) {
                debugPrint("Discarding $element from inactive elements list.");
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
        elements->reversed->forEach(_unmount);
    } finally {
        assert(_elements->isEmpty);
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
            auto _c1 = make<FocusManagerCls>();    _c1.registerGlobalHandlers();focusManager = focusManager ?? (_c1);
    }
}

void BuildOwnerCls::scheduleBuildFor(Element element) {
    assert(element != nullptr);
    assert(element->owner == this);
    assert([=] () {
        if (debugPrintScheduleBuildForStacks) {
            debugPrintStack("scheduleBuildFor() called for $element${_dirtyElements.contains(element) ? " (ALREADY IN LIST)" : ""}");
        }
        if (!element->dirty) {
            ;
        }
        return true;
    }());
    if (element->_inDirtyList) {
        assert([=] () {
            if (debugPrintScheduleBuildForStacks) {
                debugPrintStack("BuildOwner.scheduleBuildFor() called; _dirtyElementsNeedsResorting was $_dirtyElementsNeedsResorting (now true); dirty list is: $_dirtyElements");
            }
            if (!_debugIsInBuildScope) {
                ;
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
            debugPrint("...dirty list is now: $_dirtyElements");
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
        _debugStateLockLevel = 1;
        return true;
    }());
    try {
        callback();
    } finally {
        assert([=] () {
            _debugStateLockLevel = 1;
            return true;
        }());
    };
    assert(_debugStateLockLevel >= 0);
}

void BuildOwnerCls::buildScope(VoidCallback callback, Element context) {
    if (callback == nullptr && _dirtyElements->isEmpty) {
        return;
    }
    assert(context != nullptr);
    assert(_debugStateLockLevel >= 0);
    assert(!_debugBuilding);
    assert([=] () {
        if (debugPrintBuildScope) {
            debugPrint("buildScope called with context $context; dirty list is: $_dirtyElements");
        }
        _debugStateLockLevel = 1;
        _debugBuilding = true;
        return true;
    }());
    if (!kReleaseMode) {
        Map<String, String> debugTimelineArguments;
        assert([=] () {
            if (debugEnhanceBuildTimelineArguments) {
                            Map<String, String> map1 = make<MapCls<>>();            map1.set("dirty count", "${_dirtyElements.length}");            map1.set("dirty list", "$_dirtyElements");            map1.set("lock level", "$_debugStateLockLevel");            map1.set("scope context", "$context");debugTimelineArguments = list1;
            }
            return true;
        }());
        TimelineCls->startSync("BUILD"debugTimelineArguments);
    }
    try {
        _scheduledFlushDirtyElements = true;
        if (callback != nullptr) {
            assert(_debugStateLocked);
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
        int dirtyCount = _dirtyElements->length;
        int index = 0;
        while ( < dirtyCount) {
            Element element = _dirtyElements[index];
            assert(element != nullptr);
            assert(element->_inDirtyList);
            assert([=] () {
                if (element->_lifecycleState == _ElementLifecycleCls::active && !element->_debugIsInScope(context)) {
                    ;
                }
                return true;
            }());
            bool isTimelineTracked = !kReleaseMode && _isProfileBuildsEnabledFor(element->widget);
            if (isTimelineTracked) {
                Map<String, String> debugTimelineArguments;
                assert([=] () {
                    if (kDebugMode && debugEnhanceBuildTimelineArguments) {
                        debugTimelineArguments = element->widget->toDiagnosticsNode()->toTimelineArguments();
                    }
                    return true;
                }());
                TimelineCls->startSync("${element.widget.runtimeType}"debugTimelineArguments);
            }
            try {
                element->rebuild();
            } catch (Unknown e) {
                            List<DiagnosticsNode> list2 = make<ListCls<>>();            if (kDebugMode &&  < _dirtyElements->length) {                list2.add(ArrayItem);            }if ( < _dirtyElements->length) {                list2.add(ArrayItem);            } else {                list2.add(ArrayItem);            }_debugReportException(make<ErrorDescriptionCls>("while rebuilding dirty elements"), e, stack[=] ()                 {
                    list2;
                });
            };
            if (isTimelineTracked) {
                TimelineCls->finishSync();
            }
            index = 1;
            if ( < _dirtyElements->length || _dirtyElementsNeedsResorting!) {
                _dirtyElements->sort(ElementCls::_sort);
                _dirtyElementsNeedsResorting = false;
                dirtyCount = _dirtyElements->length;
                while (index > 0 && _dirtyElements[index - 1]->dirty) {
                    index = 1;
                }
            }
        }
        assert([=] () {
            if (_dirtyElements->any([=] (Element element)             {
                element->_lifecycleState == _ElementLifecycleCls::active && element->dirty;
            })) {
                ;
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
            _debugStateLockLevel = 1;
            if (debugPrintBuildScope) {
                debugPrint("buildScope finished");
            }
            return true;
        }());
    };
    assert(_debugStateLockLevel >= 0);
}

int BuildOwnerCls::globalKeyCount() {
    return _globalKeyRegistry->length;
}

void BuildOwnerCls::finalizeTree() {
    if (!kReleaseMode) {
        TimelineCls->startSync("FINALIZE TREE");
    }
    try {
        lockState(_inactiveElements->_unmountAll);
        assert([=] () {
            try {
                _debugVerifyGlobalKeyReservation();
                _debugVerifyIllFatedPopulation();
                if (_debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans != nullptr && _debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans!->isNotEmpty) {
                    Set<GlobalKey> keys = <GlobalKey>make<HashSetCls>();
                    for (Element element : _debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans!->keys) {
                        if (element->_lifecycleState != _ElementLifecycleCls::defunct) {
                            keys->addAll(_debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans![element]!);
                        }
                    }
                    if (keys->isNotEmpty) {
                        Map<String, int> keyStringCount = <String, int>make<HashMapCls>();
                        for (String key : keys-><String>map([=] (GlobalKey key)                         {
                            key->toString();
                        })) {
                            if (keyStringCount->containsKey(key)) {
                                keyStringCount->update(key, [=] (int value)                                 {
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
                                keyLabels->add("$key ($count different affected keys had this toString representation)");
                            }
                        });
                        Iterable<Element> elements = _debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans!->keys;
                        Map<String, int> elementStringCount = <String, int>make<HashMapCls>();
                        for (String element : elements-><String>map([=] (Element element)                         {
                            element->toString();
                        })) {
                            if (elementStringCount->containsKey(element)) {
                                elementStringCount->update(element, [=] (int value)                                 {
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
                                elementLabels->add("$element ($count different affected elements had this toString representation)");
                            }
                        });
                        assert(keyLabels->isNotEmpty);
                        String the = keys->length == 1? " the" : "";
                        String s = keys->length == 1? "" : "s";
                        String were = keys->length == 1? "was" : "were";
                        String their = keys->length == 1? "its" : "their";
                        String respective = elementLabels->length == 1? "" : " respective";
                        String those = keys->length == 1? "that" : "those";
                        String s2 = elementLabels->length == 1? "" : "s";
                        String those2 = elementLabels->length == 1? "that" : "those";
                        String they = elementLabels->length == 1? "it" : "they";
                        String think = elementLabels->length == 1? "thinks" : "think";
                        String are = elementLabels->length == 1? "is" : "are";
                        ;
                    }
                }
            } finally {
                _debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans?->clear();
            };
            return true;
        }());
    } catch (Unknown e) {
        _debugReportException(make<ErrorSummaryCls>("while finalizing the widget tree"), e, stack);
    } finally {
        if (!kReleaseMode) {
            TimelineCls->finishSync();
        }
    };
}

void BuildOwnerCls::reassemble(DebugReassembleConfig reassembleConfig, Element root) {
    if (!kReleaseMode) {
        TimelineCls->startSync("Preparing Hot Reload (widgets)");
    }
    try {
        assert(root->_parent == nullptr);
        assert(root->owner == this);
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

void BuildOwnerCls::_debugTrackElementThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans(GlobalKey key, Element node) {
    _debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans = <Element, Set<GlobalKey>>make<HashMapCls>();
    Set<GlobalKey> keys = _debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans!->putIfAbsent(node, [=] () {
    <GlobalKey>make<HashSetCls>();
});
    keys->add(key);
}

void BuildOwnerCls::_debugElementWasRebuilt(Element node) {
    _debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans?->remove(node);
}

void BuildOwnerCls::_debugRemoveGlobalKeyReservationFor(Element child, Element parent) {
    assert([=] () {
        assert(parent != nullptr);
        assert(child != nullptr);
        _debugGlobalKeyReservations?[parent]?->remove(child);
        return true;
    }());
}

void BuildOwnerCls::_registerGlobalKey(Element element, GlobalKey key) {
    assert([=] () {
        if (_globalKeyRegistry->containsKey(key)) {
            assert(element->widget != nullptr);
            Element oldElement = _globalKeyRegistry[key]!;
            assert(oldElement->widget != nullptr);
            assert(element->widget->runtimeType != oldElement->widget->runtimeType);
            _debugIllFatedElements?->add(oldElement);
        }
        return true;
    }());
    _globalKeyRegistry[key] = element;
}

void BuildOwnerCls::_unregisterGlobalKey(Element element, GlobalKey key) {
    assert([=] () {
        if (_globalKeyRegistry->containsKey(key) && _globalKeyRegistry[key] != element) {
            assert(element->widget != nullptr);
            Element oldElement = _globalKeyRegistry[key]!;
            assert(oldElement->widget != nullptr);
            assert(element->widget->runtimeType != oldElement->widget->runtimeType);
        }
        return true;
    }());
    if (_globalKeyRegistry[key] == element) {
        _globalKeyRegistry->remove(key);
    }
}

void BuildOwnerCls::_debugReserveGlobalKeyFor(Element child, GlobalKey key, Element parent) {
    assert([=] () {
        assert(parent != nullptr);
        assert(child != nullptr);
        _debugGlobalKeyReservations?[parent] = makeMap(makeList(), makeList();
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
                    ;
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
        for (Element element : _debugIllFatedElements ?? makeSet()) {
            if (element->_lifecycleState != _ElementLifecycleCls::defunct) {
                assert(element != nullptr);
                assert(element->widget != nullptr);
                assert(element->widget->key != nullptr);
                GlobalKey key = ((GlobalKey)element->widget->key!);
                assert(_globalKeyRegistry->containsKey(key));
                duplicates = makeMap(makeList(), makeList();
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
            information->add(make<ErrorSummaryCls>("Multiple widgets used the same GlobalKey."));
            for (GlobalKey key : duplicates->keys) {
                Set<Element> elements = duplicates[key]!;
                information->add(ElementCls->describeElements("The key $key was used by ${elements.length} widgets", elements));
            }
            information->add(make<ErrorDescriptionCls>("A GlobalKey can only be specified on one widget at a time in the widget tree."));
            ;
        }
        return true;
    }());
}

void NotifiableElementMixinCls::attachNotificationTree() {
    _notificationTree = make<_NotificationNodeCls>(_parent?->_notificationTree, this);
}

void _NotificationNodeCls::dispatchNotification(Notification notification) {
    if (current?->onNotification(notification) ?? true) {
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
            ;
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
    information->add(<Element>make<DiagnosticsPropertyCls>("The specific widget that could not find a $expectedAncestorType ancestor was", thisDiagnosticsTreeStyleCls::errorProperty));
    if (ancestors->isNotEmpty) {
        information->add(describeElements("The ancestors of this widget were", ancestors));
    } else {
        information->add(make<ErrorDescriptionCls>("This widget is the root of the tree, so it has no ancestors, let alone a "$expectedAncestorType" ancestor."));
    }
    return information;
}

DiagnosticsNode ElementCls::describeElements(Iterable<Element> elements, String name) {
    return make<DiagnosticsBlockCls>(name, elements-><DiagnosticsNode>map([=] (Element element)     {
        <Element>make<DiagnosticsPropertyCls>("", element);
    })->toList(), true);
}

DiagnosticsNode ElementCls::describeElement(String name, DiagnosticsTreeStyle style) {
    return <Element>make<DiagnosticsPropertyCls>(name, thisstyle);
}

DiagnosticsNode ElementCls::describeWidget(String name, DiagnosticsTreeStyle style) {
    return <Element>make<DiagnosticsPropertyCls>(name, thisstyle);
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
        if (owner == nullptr || !owner!->_debugStateLocked) {
            return true;
        }
        ;
    }());
    visitChildren(visitor);
}

Element ElementCls::updateChild(Element child, Object newSlot, Widget newWidget) {
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
        if (hasSameSuperclass && child->widget == newWidget) {
            if (child->slot != newSlot) {
                updateSlotForChild(child, newSlot);
            }
            newChild = child;
        } else         {
            if (hasSameSuperclass && WidgetCls->canUpdate(child->widget, newWidget)) {
            if (child->slot != newSlot) {
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
                TimelineCls->startSync("${newWidget.runtimeType}"debugTimelineArguments);
            }
            child->update(newWidget);
            if (isTimelineTracked) {
                TimelineCls->finishSync();
            }
            assert(child->widget == newWidget);
            assert([=] () {
                child->owner!->_debugElementWasRebuilt(child);
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
        if (key is GlobalKey) {
            assert(owner != nullptr);
            owner!->_debugReserveGlobalKeyFor(this, newChild, key);
        }
        return true;
    }());
    return newChild;
}

void ElementCls::mount(Object newSlot, Element parent) {
    assert(_lifecycleState == _ElementLifecycleCls::initial);
    assert(widget != nullptr);
    assert(_parent == nullptr);
    assert(parent == nullptr || parent->_lifecycleState == _ElementLifecycleCls::active);
    assert(slot == nullptr);
    _parent = parent;
    _slot = newSlot;
    _lifecycleState = _ElementLifecycleCls::active;
    _depth = _parent != nullptr? _parent!->depth + 1 : 1;
    if (parent != nullptr) {
        _owner = parent->owner;
    }
    assert(owner != nullptr);
    Key key = widget->key;
    if (key is GlobalKey) {
        owner!->_registerGlobalKey(key, this);
    }
    _updateInheritance();
    attachNotificationTree();
}

void ElementCls::update(Widget newWidget) {
    assert(_lifecycleState == _ElementLifecycleCls::active && widget != nullptr && newWidget != nullptr && newWidget != widget && depth != nullptr && WidgetCls->canUpdate(widget, newWidget));
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

Element ElementCls::inflateWidget(Object newSlot, Widget newWidget) {
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
        TimelineCls->startSync("${newWidget.runtimeType}"debugTimelineArguments);
    }
    try {
        Key key = newWidget->key;
        if (key is GlobalKey) {
            Element newChild = _retakeInactiveElement(key, newWidget);
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
    owner!->_inactiveElements->add(child);
    assert([=] () {
        if (debugPrintGlobalKeyedWidgetLifecycle) {
            if (child->widget->key is GlobalKey) {
                debugPrint("Deactivated $child (keyed child of $this)");
            }
        }
        return true;
    }());
}

void ElementCls::forgetChild(Element child) {
    assert([=] () {
        if (child->widget->key is GlobalKey) {
            _debugForgottenChildrenWithGlobalKey?->add(child);
        }
        return true;
    }());
}

void ElementCls::activate() {
    assert(_lifecycleState == _ElementLifecycleCls::inactive);
    assert(widget != nullptr);
    assert(owner != nullptr);
    assert(depth != nullptr);
    bool hadDependencies = (_dependencies != nullptr && _dependencies!->isNotEmpty) || _hadUnsatisfiedDependencies;
    _lifecycleState = _ElementLifecycleCls::active;
    _dependencies?->clear();
    _hadUnsatisfiedDependencies = false;
    _updateInheritance();
    attachNotificationTree();
    if (_dirty) {
        owner!->scheduleBuildFor(this);
    }
    if (hadDependencies) {
        didChangeDependencies();
    }
}

void ElementCls::deactivate() {
    assert(_lifecycleState == _ElementLifecycleCls::active);
    assert(_widget != nullptr);
    assert(depth != nullptr);
    if (_dependencies != nullptr && _dependencies!->isNotEmpty) {
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
    assert(depth != nullptr);
    assert(owner != nullptr);
    Key key = _widget?->key;
    if (key is GlobalKey) {
        owner!->_unregisterGlobalKey(key, this);
    }
    _widget = nullptr;
    _dependencies = nullptr;
    _lifecycleState = _ElementLifecycleCls::defunct;
}

RenderObject ElementCls::findRenderObject() {
    assert([=] () {
        if (_lifecycleState != _ElementLifecycleCls::active) {
            ;
        }
        return true;
    }());
    return renderObject;
}

Size ElementCls::size() {
    assert([=] () {
        if (_lifecycleState != _ElementLifecycleCls::active) {
            ;
        }
        if (owner!->_debugBuilding) {
            ;
        }
        return true;
    }());
    RenderObject renderObject = findRenderObject();
    assert([=] () {
        if (renderObject == nullptr) {
            ;
        }
        if (renderObject is RenderSliver) {
            ;
        }
        if (renderObject is! RenderBox) {
            ;
        }
        RenderBox box = renderObject;
        if (!box->hasSize) {
            ;
        }
        if (box->debugNeedsLayout) {
            ;
        }
        return true;
    }());
    if (renderObject is RenderBox) {
        return renderObject->size;
    }
    return nullptr;
}

bool ElementCls::doesDependOnInheritedElement(InheritedElement ancestor) {
    return _dependencies != nullptr && _dependencies!->contains(ancestor);
}

InheritedWidget ElementCls::dependOnInheritedElement(InheritedElement ancestor, Object aspect) {
    assert(ancestor != nullptr);
    _dependencies = <InheritedElement>make<HashSetCls>();
    _dependencies!->add(ancestor);
    ancestor->updateDependencies(this, aspect);
    return ((InheritedWidget)ancestor->widget);
}

T ElementCls::dependOnInheritedWidgetOfExactTypetemplate<typename T : InheritedWidget> (Object aspect) {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    InheritedElement ancestor = _inheritedWidgets == nullptr? nullptr : _inheritedWidgets![TCls];
    if (ancestor != nullptr) {
        return ((T)dependOnInheritedElement(ancestoraspect));
    }
    _hadUnsatisfiedDependencies = true;
    return nullptr;
}

InheritedElement ElementCls::getElementForInheritedWidgetOfExactTypetemplate<typename T : InheritedWidget> () {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    InheritedElement ancestor = _inheritedWidgets == nullptr? nullptr : _inheritedWidgets![TCls];
    return ancestor;
}

void ElementCls::attachNotificationTree() {
    _notificationTree = _parent?->_notificationTree;
}

T ElementCls::findAncestorWidgetOfExactTypetemplate<typename T : Widget> () {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    Element ancestor = _parent;
    while (ancestor != nullptr && ancestor->widget->runtimeType != TCls) {
        ancestor = ancestor->_parent;
    }
    return ((T)ancestor?->widget);
}

T ElementCls::findAncestorStateOfTypetemplate<typename T : State<StatefulWidget>> () {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    Element ancestor = _parent;
    while (ancestor != nullptr) {
        if (ancestor is StatefulElement && ancestor->state is T) {
                        break;
        }
        ancestor = ancestor->_parent;
    }
    StatefulElement statefulAncestor = ((StatefulElement)ancestor);
    return ((T)statefulAncestor?->state);
}

T ElementCls::findRootAncestorStateOfTypetemplate<typename T : State<StatefulWidget>> () {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    Element ancestor = _parent;
    StatefulElement statefulAncestor;
    while (ancestor != nullptr) {
        if (ancestor is StatefulElement && ancestor->state is T) {
            statefulAncestor = ancestor;
        }
        ancestor = ancestor->_parent;
    }
    return ((T)statefulAncestor?->state);
}

T ElementCls::findAncestorRenderObjectOfTypetemplate<typename T : RenderObject> () {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    Element ancestor = _parent;
    while (ancestor != nullptr) {
        if (ancestor is RenderObjectElement && ancestor->renderObject is T) {
            return ((T)ancestor->renderObject);
        }
        ancestor = ancestor->_parent;
    }
    return nullptr;
}

void ElementCls::visitAncestorElements(bool visitor(Element element) ) {
    assert(_debugCheckStateIsActiveForAncestorLookup());
    Element ancestor = _parent;
    while (ancestor != nullptr && visitor(ancestor)) {
        ancestor = ancestor->_parent;
    }
}

void ElementCls::didChangeDependencies() {
    assert(_lifecycleState == _ElementLifecycleCls::active);
    assert(_debugCheckOwnerBuildTargetExists("didChangeDependencies"));
    markNeedsBuild();
}

String ElementCls::debugGetCreatorChain(int limit) {
    List<String> chain = makeList();
    Element node = this;
    while (chain->length < limit && node != nullptr) {
        chain->add(node->toStringShort());
        node = node->_parent;
    }
    if (node != nullptr) {
        chain->add("\u22EF");
    }
    return chain->join(" \u2190 ");
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
    return _widget?->toStringShort() ?? "${describeIdentity(this)}(DEFUNCT)";
}

DiagnosticsNode ElementCls::toDiagnosticsNode(String name, DiagnosticsTreeStyle style) {
    return make<_ElementDiagnosticableTreeNodeCls>(name, this, style);
}

void ElementCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->defaultDiagnosticsTreeStyle = DiagnosticsTreeStyleCls::dense;
    if (_lifecycleState != _ElementLifecycleCls::initial) {
        properties->add(<int>make<ObjectFlagPropertyCls>("depth", depth"no depth"));
    }
    properties->add(<Widget>make<ObjectFlagPropertyCls>("widget", _widget"no widget"));
    properties->add(<Key>make<DiagnosticsPropertyCls>("key", _widget?->keyfalse, nullptr, DiagnosticLevelCls::hidden));
    _widget?->debugFillProperties(properties);
    properties->add(make<FlagPropertyCls>("dirty"dirty, "dirty"));
    Set<InheritedElement> deps = _dependencies;
    if (deps != nullptr && deps->isNotEmpty) {
            auto _c1 = deps->toList();    _c1.sort([=] (InheritedElement a,InheritedElement b) {        a->toStringShort()->compareTo(b->toStringShort());    });List<InheritedElement> sortedDependencies = _c1;
        List<DiagnosticsNode> diagnosticsDependencies = sortedDependencies->map([=] (InheritedElement element) {
    element->widget->toDiagnosticsNode(DiagnosticsTreeStyleCls::sparse);
})->toList();
        properties->add(<List<DiagnosticsNode>>make<DiagnosticsPropertyCls>("dependencies", diagnosticsDependencies));
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
    assert(owner != nullptr);
    assert(_lifecycleState == _ElementLifecycleCls::active);
    assert([=] () {
        if (owner!->_debugBuilding) {
            assert(owner!->_debugCurrentBuildTarget != nullptr);
            assert(owner!->_debugStateLocked);
            if (_debugIsInScope(owner!->_debugCurrentBuildTarget!)) {
                return true;
            }
            if (!_debugAllowIgnoredCallsToMarkNeedsBuild) {
                List<DiagnosticsNode> information = makeList(ArrayItem, ArrayItem, ArrayItem);
                if (owner!->_debugCurrentBuildTarget != nullptr) {
                    information->add(owner!->_debugCurrentBuildTarget!->describeWidget("The widget which was currently being built when the offending call was made was"));
                }
                ;
            }
            assert(dirty);
        } else         {
            if (owner!->_debugStateLocked) {
            assert(!_debugAllowIgnoredCallsToMarkNeedsBuild);
            ;
        }
;
        }        return true;
    }());
    if (dirty) {
        return;
    }
    _dirty = true;
    owner!->scheduleBuildFor(this);
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
                debugPrint("Building $this");
                _debugBuiltOnce = true;
            } else {
                debugPrint("Rebuilding $this");
            }
        }
        return true;
    }());
    assert(_lifecycleState == _ElementLifecycleCls::active);
    assert(owner!->_debugStateLocked);
    Element debugPreviousBuildTarget;
    assert([=] () {
        debugPreviousBuildTarget = owner!->_debugCurrentBuildTarget;
        owner!->_debugCurrentBuildTarget = this;
        return true;
    }());
    performRebuild();
    assert([=] () {
        assert(owner!->_debugCurrentBuildTarget == this);
        owner!->_debugCurrentBuildTarget = debugPreviousBuildTarget;
        return true;
    }());
    assert(!_dirty);
}

int ElementCls::_sort(Element a, Element b) {
    int diff = a->depth - b->depth;
    if (diff != 0) {
        return diff;
    }
    bool isBDirty = b->dirty;
    if (a->dirty != isBDirty) {
        return isBDirty? -1 : 1;
    }
    return 0;
}

int ElementCls::_debugConcreteSubtype(Element element) {
    return element is StatefulElement? 1 : element is StatelessElement? 2 : 0;
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
    assert(owner != nullptr);
    owner!->_debugRemoveGlobalKeyReservationFor(this, child);
}

void ElementCls::_updateSlot(Object newSlot) {
    assert(_lifecycleState == _ElementLifecycleCls::active);
    assert(widget != nullptr);
    assert(_parent != nullptr);
    assert(_parent!->_lifecycleState == _ElementLifecycleCls::active);
    assert(depth != nullptr);
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
    Element element = key->_currentElement;
    if (element == nullptr) {
        return nullptr;
    }
    if (!WidgetCls->canUpdate(element->widget, newWidget)) {
        return nullptr;
    }
    assert([=] () {
        if (debugPrintGlobalKeyedWidgetLifecycle) {
            debugPrint("Attempting to take $element from ${element._parent ?? "inactive elements list"} to put in $this.");
        }
        return true;
    }());
    Element parent = element->_parent;
    if (parent != nullptr) {
        assert([=] () {
            if (parent == this) {
                ;
            }
            parent->owner!->_debugTrackElementThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans(parent, key);
            return true;
        }());
        parent->forgetChild(element);
        parent->deactivateChild(element);
    }
    assert(element->_parent == nullptr);
    owner!->_inactiveElements->remove(element);
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

void ElementCls::_activateWithParent(Object newSlot, Element parent) {
    assert(_lifecycleState == _ElementLifecycleCls::inactive);
    _parent = parent;
    assert([=] () {
        if (debugPrintGlobalKeyedWidgetLifecycle) {
            debugPrint("Reactivating $this (now child of $_parent).");
        }
        return true;
    }());
    _updateDepth(_parent!->depth);
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
            ;
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
        if (owner!->_debugCurrentBuildTarget == nullptr) {
            ;
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
    Element element = ((Element)value);
    if (!element->debugIsDefunct) {
        json["widgetRuntimeType"] = element->widget->runtimeType->toString();
    }
    json["stateful"] = stateful;
    return json;
}

ErrorWidgetCls::ErrorWidgetCls(Object exception) {
    {
        message = _stringify(exception);
        _flutterError = exception is FlutterError? exception : nullptr;
    }
}

void ErrorWidgetCls::withDetails(FlutterError error, String message)

RenderBox ErrorWidgetCls::createRenderObject(BuildContext context) {
    return make<RenderErrorBoxCls>(message);
}

void ErrorWidgetCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    if (_flutterError == nullptr) {
        properties->add(make<StringPropertyCls>("message", messagefalse));
    } else {
        properties->add(_flutterError!->toDiagnosticsNode(DiagnosticsTreeStyleCls::whitespace));
    }
}

Widget ErrorWidgetCls::_defaultErrorWidgetBuilder(FlutterErrorDetails details) {
    String message = "";
    assert([=] () {
        message = "${_stringify(details.exception)}\nSee also: https://flutter.dev/docs/testing/errors";
        return true;
    }());
    Object exception = details->exception;
    return ErrorWidgetCls->withDetails(message, exception is FlutterError? exception : nullptr);
}

String ErrorWidgetCls::_stringify(Object exception) {
    try {
        return exception->toString();
    } catch (Unknown error) {
    };
    return "Error";
}

bool ComponentElementCls::debugDoingBuild() {
    return _debugDoingBuild;
}

void ComponentElementCls::mount(Object newSlot, Element parent) {
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
        debugWidgetBuilderValue(widget, built);
    } catch (Unknown e) {
        _debugDoingBuild = false;
            List<DiagnosticsNode> list1 = make<ListCls<>>();    if (kDebugMode) {        list1.add(ArrayItem);    }built = ErrorWidgetCls->builder(_debugReportException(make<ErrorDescriptionCls>("building $this"), e, stack[=] ()         {
            list1;
        }));
    } finally {
        _dirty = false;
        assert(_debugSetAllowIgnoredCallsToMarkNeedsBuild(false));
    };
    try {
        _child = updateChild(_child, built, slot);
        assert(_child != nullptr);
    } catch (Unknown e) {
            List<DiagnosticsNode> list2 = make<ListCls<>>();    if (kDebugMode) {        list2.add(ArrayItem);    }built = ErrorWidgetCls->builder(_debugReportException(make<ErrorDescriptionCls>("building $this"), e, stack[=] ()         {
            list2;
        }));
        _child = updateChild(nullptr, built, slot);
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
    return (((StatelessWidget)widget))->build(this);
}

void StatelessElementCls::update(StatelessWidget newWidget) {
    super->update(newWidget);
    assert(widget == newWidget);
    _dirty = true;
    rebuild();
}

StatefulElementCls::StatefulElementCls(StatefulWidget widget) {
    {
        _state = widget->createState();
    }
    {
        assert([=] () {
            if (!state->_debugTypesAreRight(widget)) {
                ;
            }
            return true;
        }());
        assert(state->_element == nullptr);
        state->_element = this;
        assert(state->_widget == nullptr, "The createState function for $widget returned an old or invalid state instance: ${state._widget}, which is not null, violating the contract for createState.");
        state->_widget = widget;
        assert(state->_debugLifecycleState == _StateLifecycleCls::created);
    }
}

Widget StatefulElementCls::build() {
    return state->build(this);
}

State<StatefulWidget> StatefulElementCls::state() {
    return _state!;
}

void StatefulElementCls::reassemble() {
    if (_debugShouldReassemble(_debugReassembleConfig, _widget)) {
        state->reassemble();
    }
    super->reassemble();
}

void StatefulElementCls::performRebuild() {
    if (_didChangeDependencies) {
        state->didChangeDependencies();
        _didChangeDependencies = false;
    }
    super->performRebuild();
}

void StatefulElementCls::update(StatefulWidget newWidget) {
    super->update(newWidget);
    assert(widget == newWidget);
    StatefulWidget oldWidget = state->_widget!;
    _dirty = true;
    state->_widget = ((StatefulWidget)widget);
    try {
        _debugSetAllowIgnoredCallsToMarkNeedsBuild(true);
        Object debugCheckForReturnedFuture = ((dynamic)state->didUpdateWidget(oldWidget));
        assert([=] () {
            if (debugCheckForReturnedFuture is Future) {
                ;
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
    state->activate();
    assert(_lifecycleState == _ElementLifecycleCls::active);
    markNeedsBuild();
}

void StatefulElementCls::deactivate() {
    state->deactivate();
    super->deactivate();
}

void StatefulElementCls::unmount() {
    super->unmount();
    state->dispose();
    assert([=] () {
        if (state->_debugLifecycleState == _StateLifecycleCls::defunct) {
            return true;
        }
        ;
    }());
    state->_element = nullptr;
    _state = nullptr;
}

InheritedWidget StatefulElementCls::dependOnInheritedElement(Element ancestor, Object aspect) {
    assert(ancestor != nullptr);
    assert([=] () {
        Type targetType = ancestor->widget->runtimeType;
        if (state->_debugLifecycleState == _StateLifecycleCls::created) {
            ;
        }
        if (state->_debugLifecycleState == _StateLifecycleCls::defunct) {
            ;
        }
        return true;
    }());
    return super->dependOnInheritedElement(((InheritedElement)ancestor)aspect);
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
    properties->add(<State<StatefulWidget>>make<DiagnosticsPropertyCls>("state", _statenullptr));
}

void StatefulElementCls::_firstBuild() {
    assert(state->_debugLifecycleState == _StateLifecycleCls::created);
    try {
        _debugSetAllowIgnoredCallsToMarkNeedsBuild(true);
        Object debugCheckForReturnedFuture = ((dynamic)state->initState());
        assert([=] () {
            if (debugCheckForReturnedFuture is Future) {
                ;
            }
            return true;
        }());
    } finally {
        _debugSetAllowIgnoredCallsToMarkNeedsBuild(false);
    };
    assert([=] () {
        state->_debugLifecycleState = _StateLifecycleCls::initialized;
        return true;
    }());
    state->didChangeDependencies();
    assert([=] () {
        state->_debugLifecycleState = _StateLifecycleCls::ready;
        return true;
    }());
    super->_firstBuild();
}

Widget ProxyElementCls::build() {
    return (((ProxyWidget)widget))->child;
}

void ProxyElementCls::update(ProxyWidget newWidget) {
    ProxyWidget oldWidget = ((ProxyWidget)widget);
    assert(widget != nullptr);
    assert(widget != newWidget);
    super->update(newWidget);
    assert(widget == newWidget);
    updated(oldWidget);
    _dirty = true;
    rebuild();
}

void ProxyElementCls::updated(ProxyWidget oldWidget) {
    notifyClients(oldWidget);
}

template<typename T : ParentData> void ParentDataElementCls<T>::applyWidgetOutOfTurn(ParentDataWidget<T> newWidget) {
    assert(newWidget != nullptr);
    assert(newWidget->debugCanApplyOutOfTurn());
    assert(newWidget->child == (((ParentDataWidget<T>)widget))->child);
    _applyParentData(newWidget);
}

template<typename T : ParentData> void ParentDataElementCls<T>::notifyClients(ParentDataWidget<T> oldWidget) {
    _applyParentData(((ParentDataWidget<T>)widget));
}

template<typename T : ParentData> void ParentDataElementCls<T>::_applyParentData(ParentDataWidget<T> widget) {
    InlineMethod;
    visitChildren(applyParentDataToChild);
}

void InheritedElementCls::debugDeactivated() {
    assert([=] () {
        assert(_dependents->isEmpty);
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

void InheritedElementCls::updateDependencies(Object aspect, Element dependent) {
    setDependencies(dependent, nullptr);
}

void InheritedElementCls::notifyDependent(Element dependent, InheritedWidget oldWidget) {
    dependent->didChangeDependencies();
}

void InheritedElementCls::updated(InheritedWidget oldWidget) {
    if ((((InheritedWidget)widget))->updateShouldNotify(oldWidget)) {
        super->updated(oldWidget);
    }
}

void InheritedElementCls::notifyClients(InheritedWidget oldWidget) {
    assert(_debugCheckOwnerBuildTargetExists("notifyClients"));
    for (Element dependent : _dependents->keys) {
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
    _inheritedWidgets![widget->runtimeType] = this;
}

RenderObject RenderObjectElementCls::renderObject() {
    assert(_renderObject != nullptr, "$runtimeType unmounted");
    return _renderObject!;
}

bool RenderObjectElementCls::debugDoingBuild() {
    return _debugDoingBuild;
}

void RenderObjectElementCls::mount(Object newSlot, Element parent) {
    super->mount(parent, newSlot);
    assert([=] () {
        _debugDoingBuild = true;
        return true;
    }());
    _renderObject = (((RenderObjectWidget)widget))->createRenderObject(this);
    assert(!_renderObject!->debugDisposed!);
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
    assert(widget == newWidget);
    assert([=] () {
        _debugUpdateRenderObjectOwner();
        return true;
    }());
    _performRebuild();
}

void RenderObjectElementCls::performRebuild() {
    _performRebuild();
}

List<Element> RenderObjectElementCls::updateChildren(Set<Element> forgottenChildren, List<Widget> newWidgets, List<Element> oldChildren, List<Object> slots) {
    assert(oldChildren != nullptr);
    assert(newWidgets != nullptr);
    assert(slots == nullptr || newWidgets->length == slots->length);
    InlineMethod;
    InlineMethod;
    int newChildrenTop = 0;
    int oldChildrenTop = 0;
    int newChildrenBottom = newWidgets->length - 1;
    int oldChildrenBottom = oldChildren->length - 1;
    List<Element> newChildren = oldChildren->length == newWidgets->length? oldChildren : <Element>filled(newWidgets->length, _NullElementCls::instance);
    Element previousChild;
    while ((oldChildrenTop <= oldChildrenBottom) && (newChildrenTop <= newChildrenBottom)) {
        Element oldChild = replaceWithNullIfForgotten(oldChildren[oldChildrenTop]);
        Widget newWidget = newWidgets[newChildrenTop];
        assert(oldChild == nullptr || oldChild->_lifecycleState == _ElementLifecycleCls::active);
        if (oldChild == nullptr || !WidgetCls->canUpdate(oldChild->widget, newWidget)) {
                        break;
        }
        Element newChild = updateChild(oldChild, newWidget, slotFor(newChildrenTop, previousChild))!;
        assert(newChild->_lifecycleState == _ElementLifecycleCls::active);
        newChildren[newChildrenTop] = newChild;
        previousChild = newChild;
        newChildrenTop = 1;
        oldChildrenTop = 1;
    }
    while ((oldChildrenTop <= oldChildrenBottom) && (newChildrenTop <= newChildrenBottom)) {
        Element oldChild = replaceWithNullIfForgotten(oldChildren[oldChildrenBottom]);
        Widget newWidget = newWidgets[newChildrenBottom];
        assert(oldChild == nullptr || oldChild->_lifecycleState == _ElementLifecycleCls::active);
        if (oldChild == nullptr || !WidgetCls->canUpdate(oldChild->widget, newWidget)) {
                        break;
        }
        oldChildrenBottom = 1;
        newChildrenBottom = 1;
    }
    bool haveOldChildren = oldChildrenTop <= oldChildrenBottom;
    Map<Key, Element> oldKeyedChildren;
    if (haveOldChildren) {
        oldKeyedChildren = makeMap(makeList(), makeList();
        while (oldChildrenTop <= oldChildrenBottom) {
            Element oldChild = replaceWithNullIfForgotten(oldChildren[oldChildrenTop]);
            assert(oldChild == nullptr || oldChild->_lifecycleState == _ElementLifecycleCls::active);
            if (oldChild != nullptr) {
                if (oldChild->widget->key != nullptr) {
                    oldKeyedChildren[oldChild->widget->key!] = oldChild;
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
            Key key = newWidget->key;
            if (key != nullptr) {
                oldChild = oldKeyedChildren![key];
                if (oldChild != nullptr) {
                    if (WidgetCls->canUpdate(oldChild->widget, newWidget)) {
                        oldKeyedChildren->remove(key);
                    } else {
                        oldChild = nullptr;
                    }
                }
            }
        }
        assert(oldChild == nullptr || WidgetCls->canUpdate(oldChild->widget, newWidget));
        Element newChild = updateChild(oldChild, newWidget, slotFor(newChildrenTop, previousChild))!;
        assert(newChild->_lifecycleState == _ElementLifecycleCls::active);
        assert(oldChild == newChild || oldChild == nullptr || oldChild->_lifecycleState != _ElementLifecycleCls::active);
        newChildren[newChildrenTop] = newChild;
        previousChild = newChild;
        newChildrenTop = 1;
    }
    assert(oldChildrenTop == oldChildrenBottom + 1);
    assert(newChildrenTop == newChildrenBottom + 1);
    assert(newWidgets->length - newChildrenTop == oldChildren->length - oldChildrenTop);
    newChildrenBottom = newWidgets->length - 1;
    oldChildrenBottom = oldChildren->length - 1;
    while ((oldChildrenTop <= oldChildrenBottom) && (newChildrenTop <= newChildrenBottom)) {
        Element oldChild = oldChildren[oldChildrenTop];
        assert(replaceWithNullIfForgotten(oldChild) != nullptr);
        assert(oldChild->_lifecycleState == _ElementLifecycleCls::active);
        Widget newWidget = newWidgets[newChildrenTop];
        assert(WidgetCls->canUpdate(oldChild->widget, newWidget));
        Element newChild = updateChild(oldChild, newWidget, slotFor(newChildrenTop, previousChild))!;
        assert(newChild->_lifecycleState == _ElementLifecycleCls::active);
        assert(oldChild == newChild || oldChild == nullptr || oldChild->_lifecycleState != _ElementLifecycleCls::active);
        newChildren[newChildrenTop] = newChild;
        previousChild = newChild;
        newChildrenTop = 1;
        oldChildrenTop = 1;
    }
    if (haveOldChildren && oldKeyedChildren!->isNotEmpty) {
        for (Element oldChild : oldKeyedChildren->values) {
            if (forgottenChildren == nullptr || !forgottenChildren->contains(oldChild)) {
                deactivateChild(oldChild);
            }
        }
    }
    assert(newChildren->every([=] (Element element)     {
        element is! _NullElement;
    }));
    return newChildren;
}

void RenderObjectElementCls::deactivate() {
    super->deactivate();
    assert(!renderObject->attached, "A RenderObject was still attached when attempting to deactivate its RenderObjectElement: $renderObject");
}

void RenderObjectElementCls::unmount() {
    assert(!renderObject->debugDisposed!, "A RenderObject was disposed prior to its owning element being unmounted: $renderObject");
    RenderObjectWidget oldWidget = ((RenderObjectWidget)widget);
    super->unmount();
    assert(!renderObject->attached, "A RenderObject was still attached when attempting to unmount its RenderObjectElement: $renderObject");
    oldWidget->didUnmountRenderObject(renderObject);
    _renderObject!->dispose();
    _renderObject = nullptr;
}

void RenderObjectElementCls::attachRenderObject(Object newSlot) {
    assert(_ancestorRenderObjectElement == nullptr);
    _slot = newSlot;
    _ancestorRenderObjectElement = _findAncestorRenderObjectElement();
    _ancestorRenderObjectElement?->insertRenderObjectChild(renderObject, newSlot);
    ParentDataElement<ParentData> parentDataElement = _findAncestorParentDataElement();
    if (parentDataElement != nullptr) {
        _updateParentData(((ParentDataWidget<ParentData>)parentDataElement->widget));
    }
}

void RenderObjectElementCls::detachRenderObject() {
    if (_ancestorRenderObjectElement != nullptr) {
        _ancestorRenderObjectElement!->removeRenderObjectChild(renderObject, slot);
        _ancestorRenderObjectElement = nullptr;
    }
    _slot = nullptr;
}

void RenderObjectElementCls::insertRenderObjectChild(RenderObject child, Object slot) {
    assert([=] () {
        ;
    }());
}

void RenderObjectElementCls::moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot) {
    assert([=] () {
        ;
    }());
}

void RenderObjectElementCls::removeRenderObjectChild(RenderObject child, Object slot) {
    assert([=] () {
        ;
    }());
}

void RenderObjectElementCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<RenderObject>make<DiagnosticsPropertyCls>("renderObject", _renderObjectnullptr));
}

RenderObjectElement RenderObjectElementCls::_findAncestorRenderObjectElement() {
    Element ancestor = _parent;
    while (ancestor != nullptr && ancestor is! RenderObjectElement) {
        ancestor = ancestor->_parent;
    }
    return ((RenderObjectElement)ancestor);
}

ParentDataElement<ParentData> RenderObjectElementCls::_findAncestorParentDataElement() {
    Element ancestor = _parent;
    ParentDataElement<ParentData> result;
    while (ancestor != nullptr && ancestor is! RenderObjectElement) {
        if (ancestor is ParentDataElement<ParentData>) {
            result = ancestor;
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
        while (ancestor != nullptr && ancestor is! RenderObjectElement) {
            if (ancestor is ParentDataElement<ParentData>) {
                badAncestors->add(((ParentDataElement<ParentData>)ancestor!));
            }
            ancestor = ancestor!->_parent;
        }
        if (badAncestors->isNotEmpty) {
            badAncestors->insert(0, result);
            try {
                ;
            } catch (FlutterError e) {
                _debugReportException(make<ErrorSummaryCls>("while looking for parent data."), e, e->stackTrace);
            };
        }
        return true;
    }());
    return result;
}

void RenderObjectElementCls::_debugUpdateRenderObjectOwner() {
    assert([=] () {
        renderObject->debugCreator = make<DebugCreatorCls>(this);
        return true;
    }());
}

void RenderObjectElementCls::_performRebuild() {
    assert([=] () {
        _debugDoingBuild = true;
        return true;
    }());
    (((RenderObjectWidget)widget))->updateRenderObject(this, renderObject);
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
            if (!parentDataWidget->debugIsValidRenderObject(renderObject)) {
                applyParentData = false;
                ;
            }
        } catch (FlutterError e) {
            _debugReportException(make<ErrorSummaryCls>("while applying parent data."), e, e->stackTrace);
        };
        return true;
    }());
    if (applyParentData) {
        parentDataWidget->applyParentData(renderObject);
    }
}

void RenderObjectElementCls::_updateSlot(Object newSlot) {
    Object oldSlot = slot;
    assert(oldSlot != newSlot);
    super->_updateSlot(newSlot);
    assert(slot == newSlot);
    _ancestorRenderObjectElement!->moveRenderObjectChild(renderObject, oldSlot, slot);
}

void RootRenderObjectElementCls::assignOwner(BuildOwner owner) {
    _owner = owner;
}

void RootRenderObjectElementCls::mount(Object newSlot, Element parent) {
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

void LeafRenderObjectElementCls::moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot) {
    assert(false);
}

void LeafRenderObjectElementCls::removeRenderObjectChild(RenderObject child, Object slot) {
    assert(false);
}

List<DiagnosticsNode> LeafRenderObjectElementCls::debugDescribeChildren() {
    return widget->debugDescribeChildren();
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

void SingleChildRenderObjectElementCls::mount(Object newSlot, Element parent) {
    super->mount(parent, newSlot);
    _child = updateChild(_child, (((SingleChildRenderObjectWidget)widget))->child, nullptr);
}

void SingleChildRenderObjectElementCls::update(SingleChildRenderObjectWidget newWidget) {
    super->update(newWidget);
    assert(widget == newWidget);
    _child = updateChild(_child, (((SingleChildRenderObjectWidget)widget))->child, nullptr);
}

void SingleChildRenderObjectElementCls::insertRenderObjectChild(RenderObject child, Object slot) {
    RenderObjectWithChildMixin<RenderObject> renderObject = ((RenderObjectWithChildMixin<RenderObject>)this->renderObject);
    assert(slot == nullptr);
    assert(renderObject->debugValidateChild(child));
    renderObject->child = child;
    assert(renderObject == this->renderObject);
}

void SingleChildRenderObjectElementCls::moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot) {
    assert(false);
}

void SingleChildRenderObjectElementCls::removeRenderObjectChild(RenderObject child, Object slot) {
    RenderObjectWithChildMixin<RenderObject> renderObject = ((RenderObjectWithChildMixin<RenderObject>)this->renderObject);
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
    return ((ContainerRenderObjectMixin<RenderObject, ContainerParentDataMixin<RenderObject>>)super->renderObject);
}

Iterable<Element> MultiChildRenderObjectElementCls::children() {
    return _children->where([=] (Element child)     {
        !_forgottenChildren->contains(child);
    });
}

void MultiChildRenderObjectElementCls::insertRenderObjectChild(RenderObject child, IndexedSlot<Element> slot) {
    ContainerRenderObjectMixin<RenderObject, ContainerParentDataMixin<RenderObject>> renderObject = this->renderObject;
    assert(renderObject->debugValidateChild(child));
    renderObject->insert(childslot->value?->renderObject);
    assert(renderObject == this->renderObject);
}

void MultiChildRenderObjectElementCls::moveRenderObjectChild(RenderObject child, IndexedSlot<Element> newSlot, IndexedSlot<Element> oldSlot) {
    ContainerRenderObjectMixin<RenderObject, ContainerParentDataMixin<RenderObject>> renderObject = this->renderObject;
    assert(child->parent == renderObject);
    renderObject->move(childnewSlot->value?->renderObject);
    assert(renderObject == this->renderObject);
}

void MultiChildRenderObjectElementCls::removeRenderObjectChild(RenderObject child, Object slot) {
    ContainerRenderObjectMixin<RenderObject, ContainerParentDataMixin<RenderObject>> renderObject = this->renderObject;
    assert(child->parent == renderObject);
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

Element MultiChildRenderObjectElementCls::inflateWidget(Object newSlot, Widget newWidget) {
    Element newChild = super->inflateWidget(newWidget, newSlot);
    assert(_debugCheckHasAssociatedRenderObject(newChild));
    return newChild;
}

void MultiChildRenderObjectElementCls::mount(Object newSlot, Element parent) {
    super->mount(parent, newSlot);
    MultiChildRenderObjectWidget multiChildRenderObjectWidget = ((MultiChildRenderObjectWidget)widget);
    List<Element> children = <Element>filled(multiChildRenderObjectWidget->children->length, _NullElementCls::instance);
    Element previousChild;
    for (;  < children->length; i = 1) {
        Element newChild = inflateWidget(multiChildRenderObjectWidget->children[i], <Element>make<IndexedSlotCls>(i, previousChild));
        children[i] = newChild;
        previousChild = newChild;
    }
    _children = children;
}

void MultiChildRenderObjectElementCls::update(MultiChildRenderObjectWidget newWidget) {
    super->update(newWidget);
    MultiChildRenderObjectWidget multiChildRenderObjectWidget = ((MultiChildRenderObjectWidget)widget);
    assert(widget == newWidget);
    assert(!debugChildrenHaveDuplicateKeys(widget, multiChildRenderObjectWidget->children));
    _children = updateChildren(_children, multiChildRenderObjectWidget->children_forgottenChildren);
    _forgottenChildren->clear();
}

bool MultiChildRenderObjectElementCls::_debugCheckHasAssociatedRenderObject(Element newChild) {
    assert([=] () {
        if (newChild->renderObject == nullptr) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem))));
        }
        return true;
    }());
    return true;
}

String DebugCreatorCls::toString() {
    return element->debugGetCreatorChain(12);
}

FlutterErrorDetails _debugReportException(DiagnosticsNode context, Object exception, InformationCollector informationCollector, StackTrace stack) {
    FlutterErrorDetails details = make<FlutterErrorDetailsCls>(exception, stack, "widgets library", context, informationCollector);
    FlutterErrorCls->reportError(details);
    return details;
}

template<typename T : Element> bool IndexedSlotCls<T>::==(Object other) {
    if (other->runtimeType != runtimeType) {
        return false;
    }
    return other is IndexedSlot && index == other->index && value == other->value;
}

template<typename T : Element> int IndexedSlotCls<T>::hashCode() {
    return ObjectCls->hash(index, value);
}

bool _NullElementCls::debugDoingBuild() {
    return ;
}

void _NullElementCls::performRebuild() {
    return ;
}

_NullElementCls::_NullElementCls() {
}

Element _NullWidgetCls::createElement() {
    return ;
}

bool _debugShouldReassemble(DebugReassembleConfig config, Widget widget) {
    return config == nullptr || config->widgetName == nullptr || widget?->runtimeType->toString() == config->widgetName;
}
