#include "focus_traversal.hpp"
BuildContext _getAncestor(BuildContext context, int count) {
    BuildContext target;
    context.visitAncestorElements();
    return target;
}

void _focusAndEnsureVisible(ScrollPositionAlignmentPolicy alignmentPolicy, FocusNode node) {
    node.requestFocus();
    Scrollable.ensureVisible(node.context!1.0, alignmentPolicy);
}

_FocusTraversalGroupInfo::_FocusTraversalGroupInfo(FocusTraversalPolicy defaultPolicy, _FocusTraversalGroupMarker marker, List<FocusNode> members) {
    {
        groupNode = marker?.focusNode;
        policy = marker?.policy ?? defaultPolicy ?? ReadingOrderTraversalPolicy();
        members = members ?? ;
    }
}

FocusNode FocusTraversalPolicy::findFirstFocus(FocusNode currentNode) {
    return _findInitialFocus(currentNode);
}

FocusNode FocusTraversalPolicy::findLastFocus(FocusNode currentNode) {
    return _findInitialFocus(currentNodetrue);
}

void FocusTraversalPolicy::invalidateScopeData(FocusScopeNode node) {
}

void FocusTraversalPolicy::changedScope(FocusNode node, FocusScopeNode oldScope) {
}

bool FocusTraversalPolicy::next(FocusNode currentNode) {
    return _moveFocus(currentNodetrue);
}

bool FocusTraversalPolicy::previous(FocusNode currentNode) {
    return _moveFocus(currentNodefalse);
}

FocusNode FocusTraversalPolicy::_findInitialFocus(FocusNode currentNode, bool fromEnd) {
    assert(currentNode != nullptr);
    FocusScopeNode scope = currentNode.nearestScope!;
    FocusNode candidate = scope.focusedChild;
    if (candidate == nullptr && scope.descendants.isNotEmpty) {
        Iterable<FocusNode> sorted = _sortAllDescendants(scope, currentNode);
        if (sorted.isEmpty) {
            candidate = nullptr;
        } else {
            candidate = fromEnd? sorted.last : sorted.first;
        }
    }
    candidate = currentNode;
    return candidate;
}

_FocusTraversalGroupMarker FocusTraversalPolicy::_getMarker(BuildContext context) {
    return (;
}

List<FocusNode> FocusTraversalPolicy::_sortAllDescendants(FocusNode currentNode, FocusScopeNode scope) {
    assert(scope != nullptr);
    _FocusTraversalGroupMarker scopeGroupMarker = _getMarker(scope.context);
    FocusTraversalPolicy defaultPolicy = scopeGroupMarker?.policy ?? ReadingOrderTraversalPolicy();
    Map<FocusNode, _FocusTraversalGroupInfo> groups = ;
    for (FocusNode node : scope.descendants) {
        _FocusTraversalGroupMarker groupMarker = _getMarker(node.context);
        FocusNode groupNode = groupMarker?.focusNode;
        if (node == groupNode) {
            BuildContext parentContext = _getAncestor(groupNode!.context!2);
            _FocusTraversalGroupMarker parentMarker = _getMarker(parentContext);
            FocusNode parentNode = parentMarker?.focusNode;
            groups[parentNode] = _FocusTraversalGroupInfo(parentMarker, defaultPolicy);
            assert(!groups[parentNode]!.members.contains(node));
            groups[parentNode]!.members.add(groupNode);
            continue;
        }
        if (node.canRequestFocus && !node.skipTraversal) {
            groups[groupNode] = _FocusTraversalGroupInfo(groupMarker, defaultPolicy);
            assert(!groups[groupNode]!.members.contains(node));
            groups[groupNode]!.members.add(node);
        }
    }
    for (FocusNode key : groups.keys) {
        List<FocusNode> sortedMembers = groups[key]!.policy.sortDescendants(groups[key]!.members, currentNode).toList();
        groups[key]!.members.clear();
        groups[key]!.members.addAll(sortedMembers);
    }
    List<FocusNode> sortedDescendants = ;
    ;
    if (groups.isNotEmpty && groups.containsKey(scopeGroupMarker?.focusNode)) {
        visitGroups(groups[scopeGroupMarker?.focusNode]!);
    }
    sortedDescendants.removeWhere();
    assert(sortedDescendants.length <= scope.traversalDescendants.length && sortedDescendants.toSet().difference(scope.traversalDescendants.toSet()).isEmpty, "Sorted descendants contains different nodes than FocusScopeNode.traversalDescendants would. These are the different nodes: ${sortedDescendants.toSet().difference(scope.traversalDescendants.toSet())}");
    return sortedDescendants;
}

bool FocusTraversalPolicy::_moveFocus(FocusNode currentNode, bool forward) {
    assert(forward != nullptr);
    FocusScopeNode nearestScope = currentNode.nearestScope!;
    invalidateScopeData(nearestScope);
    FocusNode focusedChild = nearestScope.focusedChild;
    if (focusedChild == nullptr) {
        FocusNode firstFocus = forward? findFirstFocus(currentNode) : findLastFocus(currentNode);
        if (firstFocus != nullptr) {
            _focusAndEnsureVisible(firstFocusforward? ScrollPositionAlignmentPolicy.keepVisibleAtEnd : ScrollPositionAlignmentPolicy.keepVisibleAtStart);
            return true;
        }
    }
    List<FocusNode> sortedNodes = _sortAllDescendants(nearestScope, currentNode);
    if (sortedNodes.isEmpty) {
        return false;
    }
    if (forward && focusedChild == sortedNodes.last) {
        _focusAndEnsureVisible(sortedNodes.firstScrollPositionAlignmentPolicy.keepVisibleAtEnd);
        return true;
    }
    if (!forward && focusedChild == sortedNodes.first) {
        _focusAndEnsureVisible(sortedNodes.lastScrollPositionAlignmentPolicy.keepVisibleAtStart);
        return true;
    }
    Iterable<FocusNode> maybeFlipped = forward? sortedNodes : sortedNodes.reversed;
    FocusNode previousNode;
    for (FocusNode node : maybeFlipped) {
        if (previousNode == focusedChild) {
            _focusAndEnsureVisible(nodeforward? ScrollPositionAlignmentPolicy.keepVisibleAtEnd : ScrollPositionAlignmentPolicy.keepVisibleAtStart);
            return true;
        }
        previousNode = node;
    }
    return false;
}

_DirectionalPolicyDataEntry::_DirectionalPolicyDataEntry(TraversalDirection direction, FocusNode node) {
    {
        assert(direction != nullptr);
        assert(node != nullptr);
    }
}

_DirectionalPolicyData::_DirectionalPolicyData(List<_DirectionalPolicyDataEntry> history) {
    {
        assert(history != nullptr);
    }
}

void DirectionalFocusTraversalPolicyMixin::invalidateScopeData(FocusScopeNode node) {
    super.invalidateScopeData(node);
    _policyData.remove(node);
}

void DirectionalFocusTraversalPolicyMixin::changedScope(FocusNode node, FocusScopeNode oldScope) {
    super.changedScope(node, oldScope);
    if (oldScope != nullptr) {
        _policyData[oldScope]?.history.removeWhere();
    }
}

FocusNode DirectionalFocusTraversalPolicyMixin::findFirstFocusInDirection(FocusNode currentNode, TraversalDirection direction) {
    assert(direction != nullptr);
    assert(currentNode != nullptr);
    ;
}

bool DirectionalFocusTraversalPolicyMixin::inDirection(FocusNode currentNode, TraversalDirection direction) {
    FocusScopeNode nearestScope = currentNode.nearestScope!;
    FocusNode focusedChild = nearestScope.focusedChild;
    if (focusedChild == nullptr) {
        FocusNode firstFocus = findFirstFocusInDirection(currentNode, direction) ?? currentNode;
        ;
        return true;
    }
    if (_popPolicyDataIfNeeded(direction, nearestScope, focusedChild)) {
        return true;
    }
    FocusNode found;
    ScrollableState focusedScrollable = Scrollable.of(focusedChild.context!);
    ;
    if (found != nullptr) {
        _pushPolicyData(direction, nearestScope, focusedChild);
        ;
        return true;
    }
    return false;
}

FocusNode DirectionalFocusTraversalPolicyMixin::_sortAndFindInitial(FocusNode currentNode, bool first, bool vertical) {
    Iterable<FocusNode> nodes = currentNode.nearestScope!.traversalDescendants;
    List<FocusNode> sorted = nodes.toList();
    <FocusNode>mergeSort(sorted);
    if (sorted.isNotEmpty) {
        return sorted.first;
    }
    return nullptr;
}

Iterable<FocusNode> DirectionalFocusTraversalPolicyMixin::_sortAndFilterHorizontally(TraversalDirection direction, FocusNode nearestScope, Rect target) {
    assert(direction == TraversalDirection.left || direction == TraversalDirection.right);
    Iterable<FocusNode> nodes = nearestScope.traversalDescendants;
    assert(!nodes.contains(nearestScope));
    List<FocusNode> sorted = nodes.toList();
    <FocusNode>mergeSort(sorted);
    Iterable<FocusNode> result;
    ;
    return result;
}

Iterable<FocusNode> DirectionalFocusTraversalPolicyMixin::_sortAndFilterVertically(TraversalDirection direction, Iterable<FocusNode> nodes, Rect target) {
    List<FocusNode> sorted = nodes.toList();
    <FocusNode>mergeSort(sorted);
    ;
    assert(direction == TraversalDirection.up || direction == TraversalDirection.down);
    return nullptr;
}

bool DirectionalFocusTraversalPolicyMixin::_popPolicyDataIfNeeded(TraversalDirection direction, FocusNode focusedChild, FocusScopeNode nearestScope) {
    _DirectionalPolicyData policyData = _policyData[nearestScope];
    if (policyData != nullptr && policyData.history.isNotEmpty && policyData.history.first.direction != direction) {
        if (policyData.history.last.node.parent == nullptr) {
            invalidateScopeData(nearestScope);
            return false;
        }
        ;
        ;
    }
    if (policyData != nullptr && policyData.history.isEmpty) {
        invalidateScopeData(nearestScope);
    }
    return false;
}

void DirectionalFocusTraversalPolicyMixin::_pushPolicyData(TraversalDirection direction, FocusNode focusedChild, FocusScopeNode nearestScope) {
    _DirectionalPolicyData policyData = _policyData[nearestScope];
    _DirectionalPolicyDataEntry newEntry = _DirectionalPolicyDataEntry(focusedChild, direction);
    if (policyData != nullptr) {
        policyData.history.add(newEntry);
    } else {
        _policyData[nearestScope] = _DirectionalPolicyData();
    }
}

Iterable<FocusNode> WidgetOrderTraversalPolicy::sortDescendants(FocusNode currentNode, Iterable<FocusNode> descendants) {
    return descendants;
}

TextDirection _ReadingOrderSortData::commonDirectionalityOf(List<_ReadingOrderSortData> list) {
    Iterable<Set<Directionality>> allAncestors = list.<Set<Directionality>>map();
    Set<Directionality> common;
    for (Set<Directionality> ancestorSet : allAncestors) {
        common = ancestorSet;
        common = common.intersection(ancestorSet);
    }
    if (common!.isEmpty) {
        return list.first.directionality;
    }
    return list.first.directionalAncestors.firstWhere(common.contains).textDirection;
}

void _ReadingOrderSortData::sortWithDirectionality(TextDirection directionality, List<_ReadingOrderSortData> list) {
    <_ReadingOrderSortData>mergeSort(list);
}

Iterable<Directionality> _ReadingOrderSortData::directionalAncestors() {
    ;
    _directionalAncestors = getDirectionalityAncestors(node.context!);
    return _directionalAncestors!;
}

void _ReadingOrderSortData::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<TextDirection>DiagnosticsProperty("directionality", directionality));
    properties.add(StringProperty("name", node.debugLabelnullptr));
    properties.add(<Rect>DiagnosticsProperty("rect", rect));
}

_ReadingOrderSortData::_ReadingOrderSortData(FocusNode node) {
    {
        assert(node != nullptr);
        rect = node.rect;
        directionality = _findDirectionality(node.context!);
    }
}

TextDirection _ReadingOrderSortData::_findDirectionality(BuildContext context) {
    return (()?.textDirection;
}

TextDirection _ReadingOrderDirectionalGroupData::directionality() {
    return members.first.directionality;
}

Rect _ReadingOrderDirectionalGroupData::rect() {
    if (_rect == nullptr) {
        for (Rect rect : members.<Rect>map()) {
            _rect = rect;
            _rect = _rect!.expandToInclude(rect);
        }
    }
    return _rect!;
}

List<Directionality> _ReadingOrderDirectionalGroupData::memberAncestors() {
    if (_memberAncestors == nullptr) {
        _memberAncestors = ;
        for (_ReadingOrderSortData member : members) {
            _memberAncestors!.addAll(member.directionalAncestors);
        }
    }
    return _memberAncestors!;
}

void _ReadingOrderDirectionalGroupData::sortWithDirectionality(TextDirection directionality, List<_ReadingOrderDirectionalGroupData> list) {
    <_ReadingOrderDirectionalGroupData>mergeSort(list);
}

void _ReadingOrderDirectionalGroupData::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<TextDirection>DiagnosticsProperty("directionality", directionality));
    properties.add(<Rect>DiagnosticsProperty("rect", rect));
    properties.add(<String>IterableProperty("members", members.<String>map()));
}

Iterable<FocusNode> ReadingOrderTraversalPolicy::sortDescendants(FocusNode currentNode, Iterable<FocusNode> descendants) {
    assert(descendants != nullptr);
    if (descendants.length <= 1) {
        return descendants;
    }
    List<_ReadingOrderSortData> data = ;
    List<FocusNode> sortedList = ;
    List<_ReadingOrderSortData> unplaced = data;
    _ReadingOrderSortData current = _pickNext(unplaced);
    sortedList.add(current.node);
    unplaced.remove(current);
    while (unplaced.isNotEmpty) {
        _ReadingOrderSortData next = _pickNext(unplaced);
        current = next;
        sortedList.add(current.node);
        unplaced.remove(current);
    }
    return sortedList;
}

List<_ReadingOrderDirectionalGroupData> ReadingOrderTraversalPolicy::_collectDirectionalityGroups(Iterable<_ReadingOrderSortData> candidates) {
    TextDirection currentDirection = candidates.first.directionality;
    List<_ReadingOrderSortData> currentGroup = ;
    List<_ReadingOrderDirectionalGroupData> result = ;
    for (_ReadingOrderSortData candidate : candidates) {
        if (candidate.directionality == currentDirection) {
            currentGroup.add(candidate);
            continue;
        }
        currentDirection = candidate.directionality;
        result.add(_ReadingOrderDirectionalGroupData(currentGroup));
        currentGroup = ;
    }
    if (currentGroup.isNotEmpty) {
        result.add(_ReadingOrderDirectionalGroupData(currentGroup));
    }
    for (_ReadingOrderDirectionalGroupData bandGroup : result) {
        if (bandGroup.members.length == 1) {
            continue;
        }
        _ReadingOrderSortData.sortWithDirectionality(bandGroup.members, bandGroup.directionality!);
    }
    return result;
}

_ReadingOrderSortData ReadingOrderTraversalPolicy::_pickNext(List<_ReadingOrderSortData> candidates) {
    <_ReadingOrderSortData>mergeSort(candidates);
    _ReadingOrderSortData topmost = candidates.first;
    ;
    List<_ReadingOrderSortData> inBandOfTop = inBand(topmost, candidates);
    assert(topmost.rect.isEmpty || inBandOfTop.isNotEmpty);
    if (inBandOfTop.length <= 1) {
        return topmost;
    }
    TextDirection nearestCommonDirectionality = _ReadingOrderSortData.commonDirectionalityOf(inBandOfTop);
    _ReadingOrderSortData.sortWithDirectionality(inBandOfTop, nearestCommonDirectionality!);
    List<_ReadingOrderDirectionalGroupData> bandGroups = _collectDirectionalityGroups(inBandOfTop);
    if (bandGroups.length == 1) {
        return bandGroups.first.members.first;
    }
    _ReadingOrderDirectionalGroupData.sortWithDirectionality(bandGroups, nearestCommonDirectionality);
    return bandGroups.first.members.first;
}

int FocusOrder::compareTo(FocusOrder other) {
    assert(runtimeType == other.runtimeType, "The sorting algorithm must not compare incomparable keys, since they don't know how to order themselves relative to each other. Comparing $this with $other");
    return doCompare(other);
}

NumericFocusOrder::NumericFocusOrder(double order) {
    {
        assert(order != nullptr);
    }
}

int NumericFocusOrder::doCompare(NumericFocusOrder other) {
    return order.compareTo(other.order);
}

void NumericFocusOrder::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("order", order));
}

LexicalFocusOrder::LexicalFocusOrder(String order) {
    {
        assert(order != nullptr);
    }
}

int LexicalFocusOrder::doCompare(LexicalFocusOrder other) {
    return order.compareTo(other.order);
}

void LexicalFocusOrder::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(StringProperty("order", order));
}

_OrderedFocusInfo::_OrderedFocusInfo(FocusNode node, FocusOrder order) {
    {
        assert(node != nullptr);
        assert(order != nullptr);
    }
}

Iterable<FocusNode> OrderedTraversalPolicy::sortDescendants(FocusNode currentNode, Iterable<FocusNode> descendants) {
    FocusTraversalPolicy secondaryPolicy = secondary ?? ReadingOrderTraversalPolicy();
    Iterable<FocusNode> sortedDescendants = secondaryPolicy.sortDescendants(descendants, currentNode);
    List<FocusNode> unordered = ;
    List<_OrderedFocusInfo> ordered = ;
    for (FocusNode node : sortedDescendants) {
        FocusOrder order = FocusTraversalOrder.maybeOf(node.context!);
        if (order != nullptr) {
            ordered.add(_OrderedFocusInfo(node, order));
        } else {
            unordered.add(node);
        }
    }
    <_OrderedFocusInfo>mergeSort(ordered);
    return ordered.<FocusNode>map().followedBy(unordered);
}

FocusOrder FocusTraversalOrder::of(BuildContext context) {
    assert(context != nullptr);
    FocusTraversalOrder marker = (;
    assert(());
    return marker!.order;
}

FocusOrder FocusTraversalOrder::maybeOf(BuildContext context) {
    assert(context != nullptr);
    FocusTraversalOrder marker = (;
    return marker?.order;
}

bool FocusTraversalOrder::updateShouldNotify(InheritedWidget oldWidget) {
    return false;
}

void FocusTraversalOrder::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<FocusOrder>DiagnosticsProperty("order", order));
}

FocusTraversalGroup::FocusTraversalGroup(Widget child, bool descendantsAreFocusable, bool descendantsAreTraversable, Unknown, FocusTraversalPolicy policy) {
    {
        assert(descendantsAreFocusable != nullptr);
        assert(descendantsAreTraversable != nullptr);
        policy = policy ?? ReadingOrderTraversalPolicy();
    }
}

FocusTraversalPolicy FocusTraversalGroup::of(BuildContext context) {
    assert(context != nullptr);
    _FocusTraversalGroupMarker inherited = context.<_FocusTraversalGroupMarker>dependOnInheritedWidgetOfExactType();
    assert(());
    return inherited!.policy;
}

FocusTraversalPolicy FocusTraversalGroup::maybeOf(BuildContext context) {
    assert(context != nullptr);
    _FocusTraversalGroupMarker inherited = context.<_FocusTraversalGroupMarker>dependOnInheritedWidgetOfExactType();
    return inherited?.policy;
}

State<FocusTraversalGroup> FocusTraversalGroup::createState() {
    return _FocusTraversalGroupState();
}

void FocusTraversalGroup::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<FocusTraversalPolicy>DiagnosticsProperty("policy", policy));
}

void _FocusTraversalGroupState::initState() {
    super.initState();
    focusNode = FocusNode(false, true, "FocusTraversalGroup");
}

void _FocusTraversalGroupState::dispose() {
    focusNode?.dispose();
    super.dispose();
}

Widget _FocusTraversalGroupState::build(BuildContext context) {
    return _FocusTraversalGroupMarker(widget.policy, focusNode!, Focus(focusNode, false, true, false, widget.descendantsAreFocusable, widget.descendantsAreTraversable, widget.child));
}

bool _FocusTraversalGroupMarker::updateShouldNotify(InheritedWidget oldWidget) {
    return false;
}

_FocusTraversalGroupMarker::_FocusTraversalGroupMarker(Unknown, FocusNode focusNode, FocusTraversalPolicy policy) {
    {
        assert(policy != nullptr);
        assert(focusNode != nullptr);
    }
}

RequestFocusIntent::RequestFocusIntent(FocusNode focusNode) {
    {
        assert(focusNode != nullptr);
    }
}

void RequestFocusAction::invoke(RequestFocusIntent intent) {
    _focusAndEnsureVisible(intent.focusNode);
}

void NextFocusAction::invoke(NextFocusIntent intent) {
    primaryFocus!.nextFocus();
}

void PreviousFocusAction::invoke(PreviousFocusIntent intent) {
    primaryFocus!.previousFocus();
}

DirectionalFocusIntent::DirectionalFocusIntent(TraversalDirection direction, bool ignoreTextFields) {
    {
        assert(ignoreTextFields != nullptr);
    }
}

DirectionalFocusAction::DirectionalFocusAction() {
    {
        _isForTextField = false;
    }
}

void DirectionalFocusAction::forTextField()

void DirectionalFocusAction::invoke(DirectionalFocusIntent intent) {
    if (!intent.ignoreTextFields || !_isForTextField) {
        primaryFocus!.focusInDirection(intent.direction);
    }
}

ExcludeFocusTraversal::ExcludeFocusTraversal(Widget child, bool excluding, Unknown) {
    {
        assert(excluding != nullptr);
        assert(child != nullptr);
    }
}

Widget ExcludeFocusTraversal::build(BuildContext context) {
    return Focus(false, true, false, !excluding, child);
}
