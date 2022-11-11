#include "focus_traversal.hpp"
BuildContext _getAncestor(BuildContext context, int count) {
    BuildContext target;
    context->visitAncestorElements([=] (Element ancestor) {
        count--;
        if (count == 0) {
            target = ancestor;
            return false;
        }
        return true;
    });
    return target;
}

void _focusAndEnsureVisible(FocusNode node, ScrollPositionAlignmentPolicy alignmentPolicy) {
    node->requestFocus();
    ScrollableCls->ensureVisible(node->context()!1.0, alignmentPolicy);
}

_FocusTraversalGroupInfoCls::_FocusTraversalGroupInfoCls(_FocusTraversalGroupMarker marker, FocusTraversalPolicy defaultPolicy, List<FocusNode> members) {
    {
        groupNode = marker?->focusNode;
        policy = marker?->policy | defaultPolicy | make<ReadingOrderTraversalPolicyCls>();
        members = members | makeList();
    }
}

FocusNode FocusTraversalPolicyCls::findFirstFocus(FocusNode currentNode) {
    return _findInitialFocus(currentNode);
}

FocusNode FocusTraversalPolicyCls::findLastFocus(FocusNode currentNode) {
    return _findInitialFocus(currentNodetrue);
}

void FocusTraversalPolicyCls::invalidateScopeData(FocusScopeNode node) {
}

void FocusTraversalPolicyCls::changedScope(FocusNode node, FocusScopeNode oldScope) {
}

bool FocusTraversalPolicyCls::next(FocusNode currentNode) {
    return _moveFocus(currentNodetrue);
}

bool FocusTraversalPolicyCls::previous(FocusNode currentNode) {
    return _moveFocus(currentNodefalse);
}

FocusNode FocusTraversalPolicyCls::_findInitialFocus(FocusNode currentNode, bool fromEnd) {
    assert(currentNode != nullptr);
    FocusScopeNode scope = currentNode->nearestScope()!;
    FocusNode candidate = scope->focusedChild();
    if (candidate == nullptr && scope->descendants->isNotEmpty) {
        Iterable<FocusNode> sorted = _sortAllDescendants(scope, currentNode);
        if (sorted->isEmpty()) {
            candidate = nullptr;
        } else {
            candidate = fromEnd? sorted->last() : sorted->first();
        }
    }
    candidate |= currentNode;
    return candidate;
}

_FocusTraversalGroupMarker FocusTraversalPolicyCls::_getMarker(BuildContext context) {
    return as<_FocusTraversalGroupMarker>(context?-><_FocusTraversalGroupMarker>getElementForInheritedWidgetOfExactType()?->widget);
}

List<FocusNode> FocusTraversalPolicyCls::_sortAllDescendants(FocusScopeNode scope, FocusNode currentNode) {
    assert(scope != nullptr);
    _FocusTraversalGroupMarker scopeGroupMarker = _getMarker(scope->context);
    FocusTraversalPolicy defaultPolicy = scopeGroupMarker?->policy | make<ReadingOrderTraversalPolicyCls>();
    Map<FocusNode, _FocusTraversalGroupInfo> groups = makeMap(makeList(), makeList();
    for (FocusNode node : scope->descendants) {
        _FocusTraversalGroupMarker groupMarker = _getMarker(node->context);
        FocusNode groupNode = groupMarker?->focusNode;
        if (node == groupNode) {
            BuildContext parentContext = _getAncestor(groupNode!->context()!2);
            _FocusTraversalGroupMarker parentMarker = _getMarker(parentContext);
            FocusNode parentNode = parentMarker?->focusNode;
            groups[parentNode] |= make<_FocusTraversalGroupInfoCls>(parentMarkermakeList(), defaultPolicy);
            assert(!groups[parentNode]!->members->contains(node));
            groups[parentNode]!->members->add(groupNode);
            continue;
        }
        if (node->canRequestFocus && !node->skipTraversal) {
            groups[groupNode] |= make<_FocusTraversalGroupInfoCls>(groupMarkermakeList(), defaultPolicy);
            assert(!groups[groupNode]!->members->contains(node));
            groups[groupNode]!->members->add(node);
        }
    }
    for (FocusNode key : groups->keys()) {
        List<FocusNode> sortedMembers = groups[key]!->policy->sortDescendants(groups[key]!->members, currentNode)->toList();
        groups[key]!->members->clear();
        groups[key]!->members->addAll(sortedMembers);
    }
    List<FocusNode> sortedDescendants = makeList();
    InlineMethod;
    if (groups->isNotEmpty() && groups->containsKey(scopeGroupMarker?->focusNode)) {
        visitGroups(groups[scopeGroupMarker?->focusNode]!);
    }
    sortedDescendants->removeWhere([=] (FocusNode node) {
        return !node->canRequestFocus || node->skipTraversal;
    });
    assert(sortedDescendants->length() <= scope->traversalDescendants()->length() && sortedDescendants->toSet()->difference(scope->traversalDescendants()->toSet())->isEmpty, __s("Sorted descendants contains different nodes than FocusScopeNode.traversalDescendants would. These are the different nodes: ${sortedDescendants.toSet().difference(scope.traversalDescendants.toSet())}"));
    return sortedDescendants;
}

bool FocusTraversalPolicyCls::_moveFocus(FocusNode currentNode, bool forward) {
    assert(forward != nullptr);
    FocusScopeNode nearestScope = currentNode->nearestScope()!;
    invalidateScopeData(nearestScope);
    FocusNode focusedChild = nearestScope->focusedChild();
    if (focusedChild == nullptr) {
        FocusNode firstFocus = forward? findFirstFocus(currentNode) : findLastFocus(currentNode);
        if (firstFocus != nullptr) {
            _focusAndEnsureVisible(firstFocusforward? ScrollPositionAlignmentPolicyCls::keepVisibleAtEnd : ScrollPositionAlignmentPolicyCls::keepVisibleAtStart);
            return true;
        }
    }
    List<FocusNode> sortedNodes = _sortAllDescendants(nearestScope, currentNode);
    if (sortedNodes->isEmpty) {
        return false;
    }
    if (forward && focusedChild == sortedNodes->last) {
        _focusAndEnsureVisible(sortedNodes->firstScrollPositionAlignmentPolicyCls::keepVisibleAtEnd);
        return true;
    }
    if (!forward && focusedChild == sortedNodes->first) {
        _focusAndEnsureVisible(sortedNodes->lastScrollPositionAlignmentPolicyCls::keepVisibleAtStart);
        return true;
    }
    Iterable<FocusNode> maybeFlipped = forward? sortedNodes : sortedNodes->reversed();
    FocusNode previousNode;
    for (FocusNode node : maybeFlipped) {
        if (previousNode == focusedChild) {
            _focusAndEnsureVisible(nodeforward? ScrollPositionAlignmentPolicyCls::keepVisibleAtEnd : ScrollPositionAlignmentPolicyCls::keepVisibleAtStart);
            return true;
        }
        previousNode = node;
    }
    return false;
}

_DirectionalPolicyDataEntryCls::_DirectionalPolicyDataEntryCls(TraversalDirection direction, FocusNode node) {
    {
        assert(direction != nullptr);
        assert(node != nullptr);
    }
}

_DirectionalPolicyDataCls::_DirectionalPolicyDataCls(List<_DirectionalPolicyDataEntry> history) {
    {
        assert(history != nullptr);
    }
}

void DirectionalFocusTraversalPolicyMixinCls::invalidateScopeData(FocusScopeNode node) {
    super->invalidateScopeData(node);
    _policyData->remove(node);
}

void DirectionalFocusTraversalPolicyMixinCls::changedScope(FocusNode node, FocusScopeNode oldScope) {
    super->changedScope(node, oldScope);
    if (oldScope != nullptr) {
        _policyData[oldScope]?->history->removeWhere([=] (_DirectionalPolicyDataEntry entry) {
            return entry->node == node;
        });
    }
}

FocusNode DirectionalFocusTraversalPolicyMixinCls::findFirstFocusInDirection(FocusNode currentNode, TraversalDirection direction) {
    assert(direction != nullptr);
    assert(currentNode != nullptr);
    ;
}

bool DirectionalFocusTraversalPolicyMixinCls::inDirection(FocusNode currentNode, TraversalDirection direction) {
    FocusScopeNode nearestScope = currentNode->nearestScope()!;
    FocusNode focusedChild = nearestScope->focusedChild();
    if (focusedChild == nullptr) {
        FocusNode firstFocus = findFirstFocusInDirection(currentNode, direction) | currentNode;
        ;
        return true;
    }
    if (_popPolicyDataIfNeeded(direction, nearestScope, focusedChild)) {
        return true;
    }
    FocusNode found;
    ScrollableState focusedScrollable = ScrollableCls->of(focusedChild->context()!);
    ;
    if (found != nullptr) {
        _pushPolicyData(direction, nearestScope, focusedChild);
        ;
        return true;
    }
    return false;
}

FocusNode DirectionalFocusTraversalPolicyMixinCls::_sortAndFindInitial(FocusNode currentNode, bool first, bool vertical) {
    Iterable<FocusNode> nodes = currentNode->nearestScope()!->traversalDescendants();
    List<FocusNode> sorted = nodes->toList();
    <FocusNode>mergeSort(sorted[=] (FocusNode a,FocusNode b) {
        if (vertical) {
            if (first) {
                return a->rect->top->compareTo(b->rect->top);
            } else {
                return b->rect->bottom->compareTo(a->rect->bottom);
            }
        } else {
            if (first) {
                return a->rect->left->compareTo(b->rect->left);
            } else {
                return b->rect->right->compareTo(a->rect->right);
            }
        }
    });
    if (sorted->isNotEmpty) {
        return sorted->first;
    }
    return nullptr;
}

Iterable<FocusNode> DirectionalFocusTraversalPolicyMixinCls::_sortAndFilterHorizontally(TraversalDirection direction, Rect target, FocusNode nearestScope) {
    assert(direction == TraversalDirectionCls::left || direction == TraversalDirectionCls::right);
    Iterable<FocusNode> nodes = nearestScope->traversalDescendants();
    assert(!nodes->contains(nearestScope));
    List<FocusNode> sorted = nodes->toList();
    <FocusNode>mergeSort(sorted[=] (FocusNode a,FocusNode b)     {
        a->rect->center->dx->compareTo(b->rect->center->dx);
    });
    Iterable<FocusNode> result;
    ;
    return result;
}

Iterable<FocusNode> DirectionalFocusTraversalPolicyMixinCls::_sortAndFilterVertically(TraversalDirection direction, Rect target, Iterable<FocusNode> nodes) {
    List<FocusNode> sorted = nodes->toList();
    <FocusNode>mergeSort(sorted[=] (FocusNode a,FocusNode b)     {
        a->rect->center->dy->compareTo(b->rect->center->dy);
    });
    ;
    assert(direction == TraversalDirectionCls::up || direction == TraversalDirectionCls::down);
    return nullptr;
}

bool DirectionalFocusTraversalPolicyMixinCls::_popPolicyDataIfNeeded(TraversalDirection direction, FocusScopeNode nearestScope, FocusNode focusedChild) {
    _DirectionalPolicyData policyData = _policyData[nearestScope];
    if (policyData != nullptr && policyData->history->isNotEmpty && policyData->history->first->direction != direction) {
        if (policyData->history->last->node->parent == nullptr) {
            invalidateScopeData(nearestScope);
            return false;
        }
        InlineMethod;
        ;
    }
    if (policyData != nullptr && policyData->history->isEmpty) {
        invalidateScopeData(nearestScope);
    }
    return false;
}

void DirectionalFocusTraversalPolicyMixinCls::_pushPolicyData(TraversalDirection direction, FocusScopeNode nearestScope, FocusNode focusedChild) {
    _DirectionalPolicyData policyData = _policyData[nearestScope];
    _DirectionalPolicyDataEntry newEntry = make<_DirectionalPolicyDataEntryCls>(focusedChild, direction);
    if (policyData != nullptr) {
        policyData->history->add(newEntry);
    } else {
        _policyData[nearestScope] = make<_DirectionalPolicyDataCls>(makeList(ArrayItem));
    }
}

Iterable<FocusNode> WidgetOrderTraversalPolicyCls::sortDescendants(Iterable<FocusNode> descendants, FocusNode currentNode) {
    return descendants;
}

TextDirection _ReadingOrderSortDataCls::commonDirectionalityOf(List<_ReadingOrderSortData> list) {
    Iterable<Set<Directionality>> allAncestors = list-><Set<Directionality>>map([=] (_ReadingOrderSortData member) {
    member->directionalAncestors->toSet();
});
    Set<Directionality> common;
    for (Set<Directionality> ancestorSet : allAncestors) {
        common |= ancestorSet;
        common = common->intersection(ancestorSet);
    }
    if (common!->isEmpty) {
        return list->first->directionality;
    }
    return list->first->directionalAncestors->firstWhere(common->contains)->textDirection;
}

void _ReadingOrderSortDataCls::sortWithDirectionality(List<_ReadingOrderSortData> list, TextDirection directionality) {
    <_ReadingOrderSortData>mergeSort(list[=] (_ReadingOrderSortData a,_ReadingOrderSortData b) {
        ;
    });
}

Iterable<Directionality> _ReadingOrderSortDataCls::directionalAncestors() {
    InlineMethod;
    _directionalAncestors |= getDirectionalityAncestors(node->context()!);
    return _directionalAncestors!;
}

void _ReadingOrderSortDataCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<TextDirection>make<DiagnosticsPropertyCls>(__s("directionality"), directionality));
    properties->add(make<StringPropertyCls>(__s("name"), node->debugLabel()nullptr));
    properties->add(<Rect>make<DiagnosticsPropertyCls>(__s("rect"), rect));
}

_ReadingOrderSortDataCls::_ReadingOrderSortDataCls(FocusNode node) {
    {
        assert(node != nullptr);
        rect = node->rect;
        directionality = _findDirectionality(node->context()!);
    }
}

TextDirection _ReadingOrderSortDataCls::_findDirectionality(BuildContext context) {
    return (as<Directionality>(context-><Directionality>getElementForInheritedWidgetOfExactType()?->widget))?->textDirection;
}

TextDirection _ReadingOrderDirectionalGroupDataCls::directionality() {
    return members->first->directionality;
}

Rect _ReadingOrderDirectionalGroupDataCls::rect() {
    if (_rect == nullptr) {
        for (Rect rect : members-><Rect>map([=] (_ReadingOrderSortData data)         {
            data->rect;
        })) {
            _rect |= rect();
            _rect = _rect!->expandToInclude(rect());
        }
    }
    return _rect!;
}

List<Directionality> _ReadingOrderDirectionalGroupDataCls::memberAncestors() {
    if (_memberAncestors == nullptr) {
        _memberAncestors = makeList();
        for (_ReadingOrderSortData member : members) {
            _memberAncestors!->addAll(member->directionalAncestors);
        }
    }
    return _memberAncestors!;
}

void _ReadingOrderDirectionalGroupDataCls::sortWithDirectionality(List<_ReadingOrderDirectionalGroupData> list, TextDirection directionality) {
    <_ReadingOrderDirectionalGroupData>mergeSort(list[=] (_ReadingOrderDirectionalGroupData a,_ReadingOrderDirectionalGroupData b) {
        ;
    });
}

void _ReadingOrderDirectionalGroupDataCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<TextDirection>make<DiagnosticsPropertyCls>(__s("directionality"), directionality()));
    properties->add(<Rect>make<DiagnosticsPropertyCls>(__s("rect"), rect()));
    properties->add(<String>make<IterablePropertyCls>(__s("members"), members-><String>map([=] (_ReadingOrderSortData member) {
        return __s(""${member.node.debugLabel}"(${member.rect})");
    })));
}

Iterable<FocusNode> ReadingOrderTraversalPolicyCls::sortDescendants(Iterable<FocusNode> descendants, FocusNode currentNode) {
    assert(descendants != nullptr);
    if (descendants->length() <= 1) {
        return descendants;
    }
    List<_ReadingOrderSortData> list1 = make<ListCls<>>();for (FocusNode node : descendants) {    ;}{    list1.add(ArrayItem);}List<_ReadingOrderSortData> data = list1;
    List<FocusNode> sortedList = makeList();
    List<_ReadingOrderSortData> unplaced = data;
    _ReadingOrderSortData current = _pickNext(unplaced);
    sortedList->add(current->node);
    unplaced->remove(current);
    while (unplaced->isNotEmpty) {
        _ReadingOrderSortData next = _pickNext(unplaced);
        current = next;
        sortedList->add(current->node);
        unplaced->remove(current);
    }
    return sortedList;
}

List<_ReadingOrderDirectionalGroupData> ReadingOrderTraversalPolicyCls::_collectDirectionalityGroups(Iterable<_ReadingOrderSortData> candidates) {
    TextDirection currentDirection = candidates->first()->directionality;
    List<_ReadingOrderSortData> currentGroup = makeList();
    List<_ReadingOrderDirectionalGroupData> result = makeList();
    for (_ReadingOrderSortData candidate : candidates) {
        if (candidate->directionality == currentDirection) {
            currentGroup->add(candidate);
            continue;
        }
        currentDirection = candidate->directionality;
        result->add(make<_ReadingOrderDirectionalGroupDataCls>(currentGroup));
        currentGroup = makeList(ArrayItem);
    }
    if (currentGroup->isNotEmpty) {
        result->add(make<_ReadingOrderDirectionalGroupDataCls>(currentGroup));
    }
    for (_ReadingOrderDirectionalGroupData bandGroup : result) {
        if (bandGroup->members->length == 1) {
            continue;
        }
        _ReadingOrderSortDataCls->sortWithDirectionality(bandGroup->members, bandGroup->directionality!);
    }
    return result;
}

_ReadingOrderSortData ReadingOrderTraversalPolicyCls::_pickNext(List<_ReadingOrderSortData> candidates) {
    <_ReadingOrderSortData>mergeSort(candidates[=] (_ReadingOrderSortData a,_ReadingOrderSortData b)     {
        a->rect->top->compareTo(b->rect->top);
    });
    _ReadingOrderSortData topmost = candidates->first;
    InlineMethod;
    List<_ReadingOrderSortData> inBandOfTop = inBand(topmost, candidates);
    assert(topmost->rect->isEmpty() || inBandOfTop->isNotEmpty);
    if (inBandOfTop->length() <= 1) {
        return topmost;
    }
    TextDirection nearestCommonDirectionality = _ReadingOrderSortDataCls->commonDirectionalityOf(inBandOfTop);
    _ReadingOrderSortDataCls->sortWithDirectionality(inBandOfTop, nearestCommonDirectionality!);
    List<_ReadingOrderDirectionalGroupData> bandGroups = _collectDirectionalityGroups(inBandOfTop);
    if (bandGroups->length() == 1) {
        return bandGroups->first->members->first;
    }
    _ReadingOrderDirectionalGroupDataCls->sortWithDirectionality(bandGroups, nearestCommonDirectionality);
    return bandGroups->first->members->first;
}

int FocusOrderCls::compareTo(FocusOrder other) {
    assert(runtimeType == other->runtimeType, __s("The sorting algorithm must not compare incomparable keys, since they don't know how to order themselves relative to each other. Comparing $this with $other"));
    return doCompare(other);
}

NumericFocusOrderCls::NumericFocusOrderCls(double order) {
    {
        assert(order != nullptr);
    }
}

int NumericFocusOrderCls::doCompare(NumericFocusOrder other) {
    return order->compareTo(other->order);
}

void NumericFocusOrderCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("order"), order));
}

LexicalFocusOrderCls::LexicalFocusOrderCls(String order) {
    {
        assert(order != nullptr);
    }
}

int LexicalFocusOrderCls::doCompare(LexicalFocusOrder other) {
    return order->compareTo(other->order);
}

void LexicalFocusOrderCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<StringPropertyCls>(__s("order"), order));
}

_OrderedFocusInfoCls::_OrderedFocusInfoCls(FocusNode node, FocusOrder order) {
    {
        assert(node != nullptr);
        assert(order != nullptr);
    }
}

Iterable<FocusNode> OrderedTraversalPolicyCls::sortDescendants(Iterable<FocusNode> descendants, FocusNode currentNode) {
    FocusTraversalPolicy secondaryPolicy = secondary | make<ReadingOrderTraversalPolicyCls>();
    Iterable<FocusNode> sortedDescendants = secondaryPolicy->sortDescendants(descendants, currentNode);
    List<FocusNode> unordered = makeList();
    List<_OrderedFocusInfo> ordered = makeList();
    for (FocusNode node : sortedDescendants) {
        FocusOrder order = FocusTraversalOrderCls->maybeOf(node->context!);
        if (order != nullptr) {
            ordered->add(make<_OrderedFocusInfoCls>(node, order));
        } else {
            unordered->add(node);
        }
    }
    <_OrderedFocusInfo>mergeSort(ordered[=] (_OrderedFocusInfo a,_OrderedFocusInfo b) {
        assert(a->order->runtimeType() == b->order->runtimeType(), __s("When sorting nodes for determining focus order, the order (${a.order}) of node ${a.node}, isn't the same type as the order (${b.order}) of ${b.node}. Incompatible order types can't be compared.  Use a FocusTraversalGroup to group similar orders together."));
        return a->order->compareTo(b->order);
    });
    return ordered-><FocusNode>map([=] (_OrderedFocusInfo info)     {
        info->node;
    })->followedBy(unordered);
}

FocusOrder FocusTraversalOrderCls::of(BuildContext context) {
    assert(context != nullptr);
    FocusTraversalOrder marker = as<FocusTraversalOrder>(context-><FocusTraversalOrder>getElementForInheritedWidgetOfExactType()?->widget);
    assert([=] () {
        if (marker == nullptr) {
            throw make<FlutterErrorCls>(__s("FocusTraversalOrder.of() was called with a context that does not contain a FocusTraversalOrder widget. No TraversalOrder widget ancestor could be found starting from the context that was passed to FocusTraversalOrder.of().\nThe context used was:\n  $context"));
        }
        return true;
    }());
    return marker!->order;
}

FocusOrder FocusTraversalOrderCls::maybeOf(BuildContext context) {
    assert(context != nullptr);
    FocusTraversalOrder marker = as<FocusTraversalOrder>(context-><FocusTraversalOrder>getElementForInheritedWidgetOfExactType()?->widget);
    return marker?->order;
}

bool FocusTraversalOrderCls::updateShouldNotify(InheritedWidget oldWidget) {
    return false;
}

void FocusTraversalOrderCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<FocusOrder>make<DiagnosticsPropertyCls>(__s("order"), order));
}

FocusTraversalGroupCls::FocusTraversalGroupCls(Widget child, bool descendantsAreFocusable, bool descendantsAreTraversable, Unknown key, FocusTraversalPolicy policy) {
    {
        assert(descendantsAreFocusable != nullptr);
        assert(descendantsAreTraversable != nullptr);
        policy = policy | make<ReadingOrderTraversalPolicyCls>();
    }
}

FocusTraversalPolicy FocusTraversalGroupCls::of(BuildContext context) {
    assert(context != nullptr);
    _FocusTraversalGroupMarker inherited = context-><_FocusTraversalGroupMarker>dependOnInheritedWidgetOfExactType();
    assert([=] () {
        if (inherited == nullptr) {
            throw make<FlutterErrorCls>(__s("Unable to find a FocusTraversalGroup widget in the context.\nFocusTraversalGroup.of() was called with a context that does not contain a FocusTraversalGroup.\nNo FocusTraversalGroup ancestor could be found starting from the context that was passed to FocusTraversalGroup.of(). This can happen because there is not a WidgetsApp or MaterialApp widget (those widgets introduce a FocusTraversalGroup), or it can happen if the context comes from a widget above those widgets.\nThe context used was:\n  $context"));
        }
        return true;
    }());
    return inherited!->policy;
}

FocusTraversalPolicy FocusTraversalGroupCls::maybeOf(BuildContext context) {
    assert(context != nullptr);
    _FocusTraversalGroupMarker inherited = context-><_FocusTraversalGroupMarker>dependOnInheritedWidgetOfExactType();
    return inherited?->policy;
}

State<FocusTraversalGroup> FocusTraversalGroupCls::createState() {
    return make<_FocusTraversalGroupStateCls>();
}

void FocusTraversalGroupCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<FocusTraversalPolicy>make<DiagnosticsPropertyCls>(__s("policy"), policy));
}

void _FocusTraversalGroupStateCls::initState() {
    super->initState();
    focusNode = make<FocusNodeCls>(false, true, __s("FocusTraversalGroup"));
}

void _FocusTraversalGroupStateCls::dispose() {
    focusNode?->dispose();
    super->dispose();
}

Widget _FocusTraversalGroupStateCls::build(BuildContext context) {
    return make<_FocusTraversalGroupMarkerCls>(widget->policy, focusNode!, make<FocusCls>(focusNode, false, true, false, widget->descendantsAreFocusable, widget->descendantsAreTraversable, widget->child));
}

bool _FocusTraversalGroupMarkerCls::updateShouldNotify(InheritedWidget oldWidget) {
    return false;
}

_FocusTraversalGroupMarkerCls::_FocusTraversalGroupMarkerCls(Unknown child, FocusNode focusNode, FocusTraversalPolicy policy) {
    {
        assert(policy != nullptr);
        assert(focusNode != nullptr);
    }
}

RequestFocusIntentCls::RequestFocusIntentCls(FocusNode focusNode) {
    {
        assert(focusNode != nullptr);
    }
}

void RequestFocusActionCls::invoke(RequestFocusIntent intent) {
    _focusAndEnsureVisible(intent->focusNode);
}

void NextFocusActionCls::invoke(NextFocusIntent intent) {
    primaryFocus!->nextFocus();
}

void PreviousFocusActionCls::invoke(PreviousFocusIntent intent) {
    primaryFocus!->previousFocus();
}

DirectionalFocusIntentCls::DirectionalFocusIntentCls(TraversalDirection direction, bool ignoreTextFields) {
    {
        assert(ignoreTextFields != nullptr);
    }
}

DirectionalFocusActionCls::DirectionalFocusActionCls() {
    {
        _isForTextField = false;
    }
}

void DirectionalFocusActionCls::forTextField()

void DirectionalFocusActionCls::invoke(DirectionalFocusIntent intent) {
    if (!intent->ignoreTextFields || !_isForTextField) {
        primaryFocus!->focusInDirection(intent->direction);
    }
}

ExcludeFocusTraversalCls::ExcludeFocusTraversalCls(Widget child, bool excluding, Unknown key) {
    {
        assert(excluding != nullptr);
        assert(child != nullptr);
    }
}

Widget ExcludeFocusTraversalCls::build(BuildContext context) {
    return make<FocusCls>(false, true, false, !excluding, child);
}
