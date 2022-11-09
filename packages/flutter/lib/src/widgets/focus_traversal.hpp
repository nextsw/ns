#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_FOCUS_TRAVERSAL
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_FOCUS_TRAVERSAL
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "actions.hpp"
#include "basic.hpp"
#include "focus_manager.hpp"
#include "focus_scope.hpp"
#include "framework.hpp"
#include "scroll_position.hpp"
#include "scrollable.hpp"

BuildContext _getAncestor(BuildContext context, int count);

void _focusAndEnsureVisible(ScrollPositionAlignmentPolicy alignmentPolicy, FocusNode node);


class _FocusTraversalGroupInfoCls : public ObjectCls {
public:
    FocusNode groupNode;

    FocusTraversalPolicy policy;

    List<FocusNode> members;


private:

     _FocusTraversalGroupInfoCls(FocusTraversalPolicy defaultPolicy, _FocusTraversalGroupMarker marker, List<FocusNode> members);

};
using _FocusTraversalGroupInfo = std::shared_ptr<_FocusTraversalGroupInfoCls>;

enum TraversalDirection{
    up,
    right,
    down,
    left,
} // end TraversalDirection

class FocusTraversalPolicyCls : public ObjectCls {
public:

     FocusTraversalPolicyCls();
    virtual FocusNode findFirstFocus(FocusNode currentNode);

    virtual FocusNode findLastFocus(FocusNode currentNode);

    virtual FocusNode findFirstFocusInDirection(FocusNode currentNode, TraversalDirection direction);
    virtual void invalidateScopeData(FocusScopeNode node);

    virtual void changedScope(FocusNode node, FocusScopeNode oldScope);

    virtual bool next(FocusNode currentNode);

    virtual bool previous(FocusNode currentNode);

    virtual bool inDirection(FocusNode currentNode, TraversalDirection direction);
    virtual Iterable<FocusNode> sortDescendants(FocusNode currentNode, Iterable<FocusNode> descendants);
private:

    virtual FocusNode _findInitialFocus(FocusNode currentNode, bool fromEnd);

    virtual _FocusTraversalGroupMarker _getMarker(BuildContext context);

    virtual List<FocusNode> _sortAllDescendants(FocusNode currentNode, FocusScopeNode scope);

    virtual bool _moveFocus(FocusNode currentNode, bool forward);

};
using FocusTraversalPolicy = std::shared_ptr<FocusTraversalPolicyCls>;

class _DirectionalPolicyDataEntryCls : public ObjectCls {
public:
    TraversalDirection direction;

    FocusNode node;


private:

     _DirectionalPolicyDataEntryCls(TraversalDirection direction, FocusNode node);

};
using _DirectionalPolicyDataEntry = std::shared_ptr<_DirectionalPolicyDataEntryCls>;

class _DirectionalPolicyDataCls : public ObjectCls {
public:
    List<_DirectionalPolicyDataEntry> history;


private:

     _DirectionalPolicyDataCls(List<_DirectionalPolicyDataEntry> history);

};
using _DirectionalPolicyData = std::shared_ptr<_DirectionalPolicyDataCls>;

class DirectionalFocusTraversalPolicyMixinCls : public ObjectCls {
public:

    virtual void invalidateScopeData(FocusScopeNode node);

    virtual void changedScope(FocusNode node, FocusScopeNode oldScope);

    virtual FocusNode findFirstFocusInDirection(FocusNode currentNode, TraversalDirection direction);

    virtual bool inDirection(FocusNode currentNode, TraversalDirection direction);

private:
    Map<FocusScopeNode, _DirectionalPolicyData> _policyData;


    virtual FocusNode _sortAndFindInitial(FocusNode currentNode, bool first, bool vertical);

    virtual Iterable<FocusNode> _sortAndFilterHorizontally(TraversalDirection direction, FocusNode nearestScope, Rect target);

    virtual Iterable<FocusNode> _sortAndFilterVertically(TraversalDirection direction, Iterable<FocusNode> nodes, Rect target);

    virtual bool _popPolicyDataIfNeeded(TraversalDirection direction, FocusNode focusedChild, FocusScopeNode nearestScope);

    virtual void _pushPolicyData(TraversalDirection direction, FocusNode focusedChild, FocusScopeNode nearestScope);

};
using DirectionalFocusTraversalPolicyMixin = std::shared_ptr<DirectionalFocusTraversalPolicyMixinCls>;

class WidgetOrderTraversalPolicyCls : public FocusTraversalPolicyCls {
public:

    virtual Iterable<FocusNode> sortDescendants(FocusNode currentNode, Iterable<FocusNode> descendants);

private:

};
using WidgetOrderTraversalPolicy = std::shared_ptr<WidgetOrderTraversalPolicyCls>;

class _ReadingOrderSortDataCls : public ObjectCls {
public:
    TextDirection directionality;

    Rect rect;

    FocusNode node;


    static TextDirection commonDirectionalityOf(List<_ReadingOrderSortData> list);

    static void sortWithDirectionality(TextDirection directionality, List<_ReadingOrderSortData> list);

    virtual Iterable<Directionality> directionalAncestors();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    List<Directionality> _directionalAncestors;


     _ReadingOrderSortDataCls(FocusNode node);

    static TextDirection _findDirectionality(BuildContext context);

};
using _ReadingOrderSortData = std::shared_ptr<_ReadingOrderSortDataCls>;

class _ReadingOrderDirectionalGroupDataCls : public ObjectCls {
public:
    List<_ReadingOrderSortData> members;


    virtual TextDirection directionality();

    virtual Rect rect();

    virtual List<Directionality> memberAncestors();

    static void sortWithDirectionality(TextDirection directionality, List<_ReadingOrderDirectionalGroupData> list);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Rect _rect;

    List<Directionality> _memberAncestors;


     _ReadingOrderDirectionalGroupDataCls(List<_ReadingOrderSortData> members);
};
using _ReadingOrderDirectionalGroupData = std::shared_ptr<_ReadingOrderDirectionalGroupDataCls>;

class ReadingOrderTraversalPolicyCls : public FocusTraversalPolicyCls {
public:

    virtual Iterable<FocusNode> sortDescendants(FocusNode currentNode, Iterable<FocusNode> descendants);

private:

    virtual List<_ReadingOrderDirectionalGroupData> _collectDirectionalityGroups(Iterable<_ReadingOrderSortData> candidates);

    virtual _ReadingOrderSortData _pickNext(List<_ReadingOrderSortData> candidates);

};
using ReadingOrderTraversalPolicy = std::shared_ptr<ReadingOrderTraversalPolicyCls>;

class FocusOrderCls : public ObjectCls {
public:

     FocusOrderCls();
    virtual int compareTo(FocusOrder other);

    virtual int doCompare(FocusOrder other);
private:

};
using FocusOrder = std::shared_ptr<FocusOrderCls>;

class NumericFocusOrderCls : public FocusOrderCls {
public:
    double order;


     NumericFocusOrderCls(double order);

    virtual int doCompare(NumericFocusOrder other);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using NumericFocusOrder = std::shared_ptr<NumericFocusOrderCls>;

class LexicalFocusOrderCls : public FocusOrderCls {
public:
    String order;


     LexicalFocusOrderCls(String order);

    virtual int doCompare(LexicalFocusOrder other);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using LexicalFocusOrder = std::shared_ptr<LexicalFocusOrderCls>;

class _OrderedFocusInfoCls : public ObjectCls {
public:
    FocusNode node;

    FocusOrder order;


private:

     _OrderedFocusInfoCls(FocusNode node, FocusOrder order);

};
using _OrderedFocusInfo = std::shared_ptr<_OrderedFocusInfoCls>;

class OrderedTraversalPolicyCls : public FocusTraversalPolicyCls {
public:
    FocusTraversalPolicy secondary;


     OrderedTraversalPolicyCls(FocusTraversalPolicy secondary);
    virtual Iterable<FocusNode> sortDescendants(FocusNode currentNode, Iterable<FocusNode> descendants);

private:

};
using OrderedTraversalPolicy = std::shared_ptr<OrderedTraversalPolicyCls>;

class FocusTraversalOrderCls : public InheritedWidgetCls {
public:
    FocusOrder order;


     FocusTraversalOrderCls(Unknown child, Unknown key, FocusOrder order);
    static FocusOrder of(BuildContext context);

    static FocusOrder maybeOf(BuildContext context);

    virtual bool updateShouldNotify(InheritedWidget oldWidget);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using FocusTraversalOrder = std::shared_ptr<FocusTraversalOrderCls>;

class FocusTraversalGroupCls : public StatefulWidgetCls {
public:
    FocusTraversalPolicy policy;

    bool descendantsAreFocusable;

    bool descendantsAreTraversable;

    Widget child;


     FocusTraversalGroupCls(Widget child, bool descendantsAreFocusable, bool descendantsAreTraversable, Unknown key, FocusTraversalPolicy policy);

    static FocusTraversalPolicy of(BuildContext context);

    static FocusTraversalPolicy maybeOf(BuildContext context);

    virtual State<FocusTraversalGroup> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using FocusTraversalGroup = std::shared_ptr<FocusTraversalGroupCls>;

class _FocusTraversalGroupStateCls : public StateCls<FocusTraversalGroup> {
public:
    FocusNode focusNode;


    virtual void initState();

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:

};
using _FocusTraversalGroupState = std::shared_ptr<_FocusTraversalGroupStateCls>;

class _FocusTraversalGroupMarkerCls : public InheritedWidgetCls {
public:
    FocusTraversalPolicy policy;

    FocusNode focusNode;


    virtual bool updateShouldNotify(InheritedWidget oldWidget);

private:

     _FocusTraversalGroupMarkerCls(Unknown child, FocusNode focusNode, FocusTraversalPolicy policy);

};
using _FocusTraversalGroupMarker = std::shared_ptr<_FocusTraversalGroupMarkerCls>;

class RequestFocusIntentCls : public IntentCls {
public:
    FocusNode focusNode;


     RequestFocusIntentCls(FocusNode focusNode);

private:

};
using RequestFocusIntent = std::shared_ptr<RequestFocusIntentCls>;

class RequestFocusActionCls : public ActionCls<RequestFocusIntent> {
public:

    virtual void invoke(RequestFocusIntent intent);

private:

};
using RequestFocusAction = std::shared_ptr<RequestFocusActionCls>;

class NextFocusIntentCls : public IntentCls {
public:

     NextFocusIntentCls();
private:

};
using NextFocusIntent = std::shared_ptr<NextFocusIntentCls>;

class NextFocusActionCls : public ActionCls<NextFocusIntent> {
public:

    virtual void invoke(NextFocusIntent intent);

private:

};
using NextFocusAction = std::shared_ptr<NextFocusActionCls>;

class PreviousFocusIntentCls : public IntentCls {
public:

     PreviousFocusIntentCls();
private:

};
using PreviousFocusIntent = std::shared_ptr<PreviousFocusIntentCls>;

class PreviousFocusActionCls : public ActionCls<PreviousFocusIntent> {
public:

    virtual void invoke(PreviousFocusIntent intent);

private:

};
using PreviousFocusAction = std::shared_ptr<PreviousFocusActionCls>;

class DirectionalFocusIntentCls : public IntentCls {
public:
    TraversalDirection direction;

    bool ignoreTextFields;


     DirectionalFocusIntentCls(TraversalDirection direction, bool ignoreTextFields);

private:

};
using DirectionalFocusIntent = std::shared_ptr<DirectionalFocusIntentCls>;

class DirectionalFocusActionCls : public ActionCls<DirectionalFocusIntent> {
public:

     DirectionalFocusActionCls();

    virtual void  forTextField();

    virtual void invoke(DirectionalFocusIntent intent);

private:
    bool _isForTextField;


};
using DirectionalFocusAction = std::shared_ptr<DirectionalFocusActionCls>;

class ExcludeFocusTraversalCls : public StatelessWidgetCls {
public:
    bool excluding;

    Widget child;


     ExcludeFocusTraversalCls(Widget child, bool excluding, Unknown key);

    virtual Widget build(BuildContext context);

private:

};
using ExcludeFocusTraversal = std::shared_ptr<ExcludeFocusTraversalCls>;


#endif