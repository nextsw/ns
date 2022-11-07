#ifndef FOCUS_TRAVERSAL_H
#define FOCUS_TRAVERSAL_H
#include <memory>

#include <flutter/foundation.hpp>
#include "actions.hpp"
#include "basic.hpp"
#include "focus_manager.hpp"
#include "focus_scope.hpp"
#include "framework.hpp"
#include "scroll_position.hpp"
#include "scrollable.hpp"


BuildContext _getAncestor(BuildContext context, int count);

void _focusAndEnsureVisible(ScrollPositionAlignmentPolicy alignmentPolicy, FocusNode node);


class _FocusTraversalGroupInfo {
public:
    FocusNode groupNode;

    FocusTraversalPolicy policy;

    List<FocusNode> members;


private:

     _FocusTraversalGroupInfo(FocusTraversalPolicy defaultPolicy, _FocusTraversalGroupMarker marker, List<FocusNode> members);

};

enum TraversalDirection{
    up,
    right,
    down,
    left,
} // end TraversalDirection

class FocusTraversalPolicy {
public:

     FocusTraversalPolicy();

    FocusNode findFirstFocus(FocusNode currentNode);

    FocusNode findLastFocus(FocusNode currentNode);

    FocusNode findFirstFocusInDirection(FocusNode currentNode, TraversalDirection direction);

    void invalidateScopeData(FocusScopeNode node);

    void changedScope(FocusNode node, FocusScopeNode oldScope);

    bool next(FocusNode currentNode);

    bool previous(FocusNode currentNode);

    bool inDirection(FocusNode currentNode, TraversalDirection direction);

    Iterable<FocusNode> sortDescendants(FocusNode currentNode, Iterable<FocusNode> descendants);

private:

    FocusNode _findInitialFocus(FocusNode currentNode, bool fromEnd);

    _FocusTraversalGroupMarker _getMarker(BuildContext context);

    List<FocusNode> _sortAllDescendants(FocusNode currentNode, FocusScopeNode scope);

    bool _moveFocus(FocusNode currentNode, bool forward);

};

class _DirectionalPolicyDataEntry {
public:
    TraversalDirection direction;

    FocusNode node;


private:

     _DirectionalPolicyDataEntry(TraversalDirection direction, FocusNode node);

};

class _DirectionalPolicyData {
public:
    List<_DirectionalPolicyDataEntry> history;


private:

     _DirectionalPolicyData(List<_DirectionalPolicyDataEntry> history);

};

class DirectionalFocusTraversalPolicyMixin {
public:

    void invalidateScopeData(FocusScopeNode node);

    void changedScope(FocusNode node, FocusScopeNode oldScope);

    FocusNode findFirstFocusInDirection(FocusNode currentNode, TraversalDirection direction);

    bool inDirection(FocusNode currentNode, TraversalDirection direction);

private:
    Map<FocusScopeNode, _DirectionalPolicyData> _policyData;


    FocusNode _sortAndFindInitial(FocusNode currentNode, bool first, bool vertical);

    Iterable<FocusNode> _sortAndFilterHorizontally(TraversalDirection direction, FocusNode nearestScope, Rect target);

    Iterable<FocusNode> _sortAndFilterVertically(TraversalDirection direction, Iterable<FocusNode> nodes, Rect target);

    bool _popPolicyDataIfNeeded(TraversalDirection direction, FocusNode focusedChild, FocusScopeNode nearestScope);

    void _pushPolicyData(TraversalDirection direction, FocusNode focusedChild, FocusScopeNode nearestScope);

};

class WidgetOrderTraversalPolicy : FocusTraversalPolicy {
public:

    Iterable<FocusNode> sortDescendants(FocusNode currentNode, Iterable<FocusNode> descendants);

private:

};

class _ReadingOrderSortData {
public:
    TextDirection directionality;

    Rect rect;

    FocusNode node;


    static TextDirection commonDirectionalityOf(List<_ReadingOrderSortData> list);

    static void sortWithDirectionality(TextDirection directionality, List<_ReadingOrderSortData> list);

    Iterable<Directionality> directionalAncestors();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    List<Directionality> _directionalAncestors;


     _ReadingOrderSortData(FocusNode node);

    static TextDirection _findDirectionality(BuildContext context);

};

class _ReadingOrderDirectionalGroupData {
public:
    List<_ReadingOrderSortData> members;


    TextDirection directionality();

    Rect rect();

    List<Directionality> memberAncestors();

    static void sortWithDirectionality(TextDirection directionality, List<_ReadingOrderDirectionalGroupData> list);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Rect _rect;

    List<Directionality> _memberAncestors;


     _ReadingOrderDirectionalGroupData(List<_ReadingOrderSortData> members);

};

class ReadingOrderTraversalPolicy : FocusTraversalPolicy {
public:

    Iterable<FocusNode> sortDescendants(FocusNode currentNode, Iterable<FocusNode> descendants);

private:

    List<_ReadingOrderDirectionalGroupData> _collectDirectionalityGroups(Iterable<_ReadingOrderSortData> candidates);

    _ReadingOrderSortData _pickNext(List<_ReadingOrderSortData> candidates);

};

class FocusOrder {
public:

     FocusOrder();

    int compareTo(FocusOrder other);

    int doCompare(FocusOrder other);

private:

};

class NumericFocusOrder : FocusOrder {
public:
    double order;


     NumericFocusOrder(double order);

    int doCompare(NumericFocusOrder other);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class LexicalFocusOrder : FocusOrder {
public:
    String order;


     LexicalFocusOrder(String order);

    int doCompare(LexicalFocusOrder other);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _OrderedFocusInfo {
public:
    FocusNode node;

    FocusOrder order;


private:

     _OrderedFocusInfo(FocusNode node, FocusOrder order);

};

class OrderedTraversalPolicy : FocusTraversalPolicy {
public:
    FocusTraversalPolicy secondary;


     OrderedTraversalPolicy(FocusTraversalPolicy secondary);

    Iterable<FocusNode> sortDescendants(FocusNode currentNode, Iterable<FocusNode> descendants);

private:

};

class FocusTraversalOrder : InheritedWidget {
public:
    FocusOrder order;


     FocusTraversalOrder(Unknown, Unknown, FocusOrder order);

    static FocusOrder of(BuildContext context);

    static FocusOrder maybeOf(BuildContext context);

    bool updateShouldNotify(InheritedWidget oldWidget);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class FocusTraversalGroup : StatefulWidget {
public:
    FocusTraversalPolicy policy;

    bool descendantsAreFocusable;

    bool descendantsAreTraversable;

    Widget child;


     FocusTraversalGroup(Widget child, bool descendantsAreFocusable, bool descendantsAreTraversable, Unknown, FocusTraversalPolicy policy);

    static FocusTraversalPolicy of(BuildContext context);

    static FocusTraversalPolicy maybeOf(BuildContext context);

    State<FocusTraversalGroup> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _FocusTraversalGroupState : State<FocusTraversalGroup> {
public:
    FocusNode focusNode;


    void initState();

    void dispose();

    Widget build(BuildContext context);

private:

};

class _FocusTraversalGroupMarker : InheritedWidget {
public:
    FocusTraversalPolicy policy;

    FocusNode focusNode;


    bool updateShouldNotify(InheritedWidget oldWidget);

private:

     _FocusTraversalGroupMarker(Unknown, FocusNode focusNode, FocusTraversalPolicy policy);

};

class RequestFocusIntent : Intent {
public:
    FocusNode focusNode;


     RequestFocusIntent(FocusNode focusNode);

private:

};

class RequestFocusAction : Action<RequestFocusIntent> {
public:

    void invoke(RequestFocusIntent intent);

private:

};

class NextFocusIntent : Intent {
public:

     NextFocusIntent();

private:

};

class NextFocusAction : Action<NextFocusIntent> {
public:

    void invoke(NextFocusIntent intent);

private:

};

class PreviousFocusIntent : Intent {
public:

     PreviousFocusIntent();

private:

};

class PreviousFocusAction : Action<PreviousFocusIntent> {
public:

    void invoke(PreviousFocusIntent intent);

private:

};

class DirectionalFocusIntent : Intent {
public:
    TraversalDirection direction;

    bool ignoreTextFields;


     DirectionalFocusIntent(TraversalDirection direction, bool ignoreTextFields);

private:

};

class DirectionalFocusAction : Action<DirectionalFocusIntent> {
public:

     DirectionalFocusAction();

    void  forTextField();

    void invoke(DirectionalFocusIntent intent);

private:
    bool _isForTextField;


};

class ExcludeFocusTraversal : StatelessWidget {
public:
    bool excluding;

    Widget child;


     ExcludeFocusTraversal(Widget child, bool excluding, Unknown);

    Widget build(BuildContext context);

private:

};

#endif