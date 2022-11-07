#ifndef SLIVER_H
#define SLIVER_H
#include <memory>
#include <flutter/rendering.hpp>

#include <collection/collection.hpp>
#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include "automatic_keep_alive.hpp"
#include "basic.hpp"
#include "framework.hpp"
#include "selection_container.hpp"


int _kDefaultSemanticIndexCallback(Widget _, int localIndex);


class SliverChildDelegate {
public:

     SliverChildDelegate();

    Widget build(BuildContext context, int index);

    int estimatedChildCount();

    double estimateMaxScrollOffset(int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset);

    void didFinishLayout(int firstIndex, int lastIndex);

    bool shouldRebuild(SliverChildDelegate oldDelegate);

    int findIndexByKey(Key key);

    String toString();

    void debugFillDescription(List<String> description);

private:

};

class _SaltedValueKey : ValueKey<Key> {
public:

private:

     _SaltedValueKey(Unknown);

};

class SliverChildBuilderDelegate : SliverChildDelegate {
public:
    NullableIndexedWidgetBuilder builder;

    int childCount;

    bool addAutomaticKeepAlives;

    bool addRepaintBoundaries;

    bool addSemanticIndexes;

    int semanticIndexOffset;

    SemanticIndexCallback semanticIndexCallback;

    ChildIndexGetter findChildIndexCallback;


     SliverChildBuilderDelegate(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, NullableIndexedWidgetBuilder builder, int childCount, ChildIndexGetter findChildIndexCallback, SemanticIndexCallback semanticIndexCallback, int semanticIndexOffset);

    int findIndexByKey(Key key);

    Widget build(BuildContext context, int index);

    int estimatedChildCount();

    bool shouldRebuild(SliverChildBuilderDelegate oldDelegate);

private:

};

class SliverChildListDelegate : SliverChildDelegate {
public:
    bool addAutomaticKeepAlives;

    bool addRepaintBoundaries;

    bool addSemanticIndexes;

    int semanticIndexOffset;

    SemanticIndexCallback semanticIndexCallback;

    List<Widget> children;


     SliverChildListDelegate(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, List<Widget> children, SemanticIndexCallback semanticIndexCallback, int semanticIndexOffset);

    void  fixed(bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, List<Widget> children, SemanticIndexCallback semanticIndexCallback, int semanticIndexOffset);

    int findIndexByKey(Key key);

    Widget build(BuildContext context, int index);

    int estimatedChildCount();

    bool shouldRebuild(SliverChildListDelegate oldDelegate);

private:
    Map<Key, int> _keyToIndex;


    bool _isConstantInstance();

    int _findChildIndex(Key key);

};

class _SelectionKeepAlive : StatefulWidget {
public:
    Widget child;


    State<_SelectionKeepAlive> createState();

private:

     _SelectionKeepAlive(Widget child);

};

class _SelectionKeepAliveState : State<_SelectionKeepAlive> {
public:

    bool wantKeepAlive();

    void  wantKeepAlive(bool value);

    VoidCallback listensTo(Selectable selectable);

    void didChangeDependencies();

    void add(Selectable selectable);

    void remove(Selectable selectable);

    void dispose();

    Widget build(BuildContext context);

private:
    Set<Selectable> _selectablesWithSelections;

    Map<Selectable, VoidCallback> _selectableAttachments;

    SelectionRegistrar _registrar;

    bool _wantKeepAlive;


    void _updateSelectablesWithSelections(bool add, Selectable selectable);

};

class SliverWithKeepAliveWidget : RenderObjectWidget {
public:

     SliverWithKeepAliveWidget(Unknown);

    RenderSliverWithKeepAliveMixin createRenderObject(BuildContext context);

private:

};

class SliverMultiBoxAdaptorWidget : SliverWithKeepAliveWidget {
public:
    SliverChildDelegate delegate;


     SliverMultiBoxAdaptorWidget(SliverChildDelegate delegate, Unknown);

    SliverMultiBoxAdaptorElement createElement();

    RenderSliverMultiBoxAdaptor createRenderObject(BuildContext context);

    double estimateMaxScrollOffset(SliverConstraints constraints, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class SliverList : SliverMultiBoxAdaptorWidget {
public:

     SliverList(Unknown, Unknown);

    SliverMultiBoxAdaptorElement createElement();

    RenderSliverList createRenderObject(BuildContext context);

private:

};

class SliverFixedExtentList : SliverMultiBoxAdaptorWidget {
public:
    double itemExtent;


     SliverFixedExtentList(Unknown, double itemExtent, Unknown);

    RenderSliverFixedExtentList createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderSliverFixedExtentList renderObject);

private:

};

class SliverGrid : SliverMultiBoxAdaptorWidget {
public:
    SliverGridDelegate gridDelegate;


     SliverGrid(Unknown, SliverGridDelegate gridDelegate, Unknown);

    void  count(double childAspectRatio, List<Widget> children, int crossAxisCount, double crossAxisSpacing, Unknown, double mainAxisSpacing);

    void  extent(double childAspectRatio, List<Widget> children, double crossAxisSpacing, Unknown, double mainAxisSpacing, double maxCrossAxisExtent);

    RenderSliverGrid createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderSliverGrid renderObject);

    double estimateMaxScrollOffset(SliverConstraints constraints, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset);

private:

};

class SliverMultiBoxAdaptorElement : RenderObjectElement {
public:

     SliverMultiBoxAdaptorElement(bool replaceMovedChildren, SliverMultiBoxAdaptorWidget widget);

    RenderSliverMultiBoxAdaptor renderObject();

    void update(SliverMultiBoxAdaptorWidget newWidget);

    void performRebuild();

    void createChild(RenderBox after, int index);

    Element updateChild(Element child, Object newSlot, Widget newWidget);

    void forgetChild(Element child);

    void removeChild(RenderBox child);

    double estimateMaxScrollOffset(SliverConstraints constraints, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset);

    int estimatedChildCount();

    int childCount();

    void didStartLayout();

    void didFinishLayout();

    bool debugAssertChildListLocked();

    void didAdoptChild(RenderBox child);

    void setDidUnderflow(bool value);

    void insertRenderObjectChild(RenderObject child, int slot);

    void moveRenderObjectChild(RenderObject child, int newSlot, int oldSlot);

    void removeRenderObjectChild(RenderObject child, int slot);

    void visitChildren(ElementVisitor visitor);

    void debugVisitOnstageChildren(ElementVisitor visitor);

private:
    bool _replaceMovedChildren;

    SplayTreeMap<int, Element> _childElements;

    RenderBox _currentBeforeChild;

    int _currentlyUpdatingChildIndex;

    bool _didUnderflow;


    Widget _build(int index, SliverMultiBoxAdaptorWidget widget);

    static double _extrapolateMaxScrollOffset(int childCount, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset);

};

class SliverOpacity : SingleChildRenderObjectWidget {
public:
    double opacity;

    bool alwaysIncludeSemantics;


     SliverOpacity(bool alwaysIncludeSemantics, Unknown, double opacity, Widget sliver);

    RenderSliverOpacity createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderSliverOpacity renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class SliverIgnorePointer : SingleChildRenderObjectWidget {
public:
    bool ignoring;

    bool ignoringSemantics;


     SliverIgnorePointer(bool ignoring, bool ignoringSemantics, Unknown, Widget sliver);

    RenderSliverIgnorePointer createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderSliverIgnorePointer renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class SliverOffstage : SingleChildRenderObjectWidget {
public:
    bool offstage;


     SliverOffstage(Unknown, bool offstage, Widget sliver);

    RenderSliverOffstage createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderSliverOffstage renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    SingleChildRenderObjectElement createElement();

private:

};

class _SliverOffstageElement : SingleChildRenderObjectElement {
public:

    void debugVisitOnstageChildren(ElementVisitor visitor);

private:

     _SliverOffstageElement(SliverOffstage widget);

};

class KeepAlive : ParentDataWidget<KeepAliveParentDataMixin> {
public:
    bool keepAlive;


     KeepAlive(Unknown, bool keepAlive, Unknown);

    void applyParentData(RenderObject renderObject);

    bool debugCanApplyOutOfTurn();

    Type debugTypicalAncestorWidgetClass();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
Widget _createErrorWidget(Object exception, StackTrace stackTrace);


#endif