#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SLIVER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SLIVER
#include <base.hpp>
#include <packages/flutter/lib/rendering.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "automatic_keep_alive.hpp"
#include "basic.hpp"
#include "framework.hpp"
#include "selection_container.hpp"

int _kDefaultSemanticIndexCallback(Widget _, int localIndex);


class SliverChildDelegateCls : public ObjectCls {
public:

     SliverChildDelegateCls();
    virtual Widget build(BuildContext context, int index);
    virtual int estimatedChildCount();

    virtual double estimateMaxScrollOffset(int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset);

    virtual void didFinishLayout(int firstIndex, int lastIndex);

    virtual bool shouldRebuild(SliverChildDelegate oldDelegate);
    virtual int findIndexByKey(Key key);

    virtual String toString();

    virtual void debugFillDescription(List<String> description);

private:

};
using SliverChildDelegate = std::shared_ptr<SliverChildDelegateCls>;

class _SaltedValueKeyCls : public ValueKeyCls<Key> {
public:

private:

     _SaltedValueKeyCls(Unknown key);

};
using _SaltedValueKey = std::shared_ptr<_SaltedValueKeyCls>;

class SliverChildBuilderDelegateCls : public SliverChildDelegateCls {
public:
    NullableIndexedWidgetBuilder builder;

    int childCount;

    bool addAutomaticKeepAlives;

    bool addRepaintBoundaries;

    bool addSemanticIndexes;

    int semanticIndexOffset;

    SemanticIndexCallback semanticIndexCallback;

    ChildIndexGetter findChildIndexCallback;


     SliverChildBuilderDelegateCls(NullableIndexedWidgetBuilder builder, bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, int childCount, ChildIndexGetter findChildIndexCallback, SemanticIndexCallback semanticIndexCallback, int semanticIndexOffset);

    virtual int findIndexByKey(Key key);

    virtual Widget build(BuildContext context, int index);

    virtual int estimatedChildCount();

    virtual bool shouldRebuild(SliverChildBuilderDelegate oldDelegate);

private:

};
using SliverChildBuilderDelegate = std::shared_ptr<SliverChildBuilderDelegateCls>;

class SliverChildListDelegateCls : public SliverChildDelegateCls {
public:
    bool addAutomaticKeepAlives;

    bool addRepaintBoundaries;

    bool addSemanticIndexes;

    int semanticIndexOffset;

    SemanticIndexCallback semanticIndexCallback;

    List<Widget> children;


     SliverChildListDelegateCls(List<Widget> children, bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, SemanticIndexCallback semanticIndexCallback, int semanticIndexOffset);

    virtual void  fixed(List<Widget> children, bool addAutomaticKeepAlives, bool addRepaintBoundaries, bool addSemanticIndexes, SemanticIndexCallback semanticIndexCallback, int semanticIndexOffset);

    virtual int findIndexByKey(Key key);

    virtual Widget build(BuildContext context, int index);

    virtual int estimatedChildCount();

    virtual bool shouldRebuild(SliverChildListDelegate oldDelegate);

private:
    Map<Key, int> _keyToIndex;


    virtual bool _isConstantInstance();

    virtual int _findChildIndex(Key key);

};
using SliverChildListDelegate = std::shared_ptr<SliverChildListDelegateCls>;

class _SelectionKeepAliveCls : public StatefulWidgetCls {
public:
    Widget child;


    virtual State<_SelectionKeepAlive> createState();

private:

     _SelectionKeepAliveCls(Widget child);
};
using _SelectionKeepAlive = std::shared_ptr<_SelectionKeepAliveCls>;

class _SelectionKeepAliveStateCls : public StateCls<_SelectionKeepAlive> {
public:

    virtual bool wantKeepAlive();

    virtual void  wantKeepAlive(bool value);

    virtual VoidCallback listensTo(Selectable selectable);

    virtual void didChangeDependencies();

    virtual void add(Selectable selectable);

    virtual void remove(Selectable selectable);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    Set<Selectable> _selectablesWithSelections;

    Map<Selectable, VoidCallback> _selectableAttachments;

    SelectionRegistrar _registrar;

    bool _wantKeepAlive;


    virtual void _updateSelectablesWithSelections(Selectable selectable, bool add);

};
using _SelectionKeepAliveState = std::shared_ptr<_SelectionKeepAliveStateCls>;

class SliverWithKeepAliveWidgetCls : public RenderObjectWidgetCls {
public:

     SliverWithKeepAliveWidgetCls(Key key);
    virtual RenderSliverWithKeepAliveMixin createRenderObject(BuildContext context) override;
private:

};
using SliverWithKeepAliveWidget = std::shared_ptr<SliverWithKeepAliveWidgetCls>;

class SliverMultiBoxAdaptorWidgetCls : public SliverWithKeepAliveWidgetCls {
public:
    SliverChildDelegate delegate;


     SliverMultiBoxAdaptorWidgetCls(SliverChildDelegate delegate, Key key);

    virtual SliverMultiBoxAdaptorElement createElement();

    virtual RenderSliverMultiBoxAdaptor createRenderObject(BuildContext context) override;
    virtual double estimateMaxScrollOffset(SliverConstraints constraints, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using SliverMultiBoxAdaptorWidget = std::shared_ptr<SliverMultiBoxAdaptorWidgetCls>;

class SliverListCls : public SliverMultiBoxAdaptorWidgetCls {
public:

     SliverListCls(SliverChildDelegate delegate, Key key);
    virtual SliverMultiBoxAdaptorElement createElement();

    virtual RenderSliverList createRenderObject(BuildContext context);

private:

};
using SliverList = std::shared_ptr<SliverListCls>;

class SliverFixedExtentListCls : public SliverMultiBoxAdaptorWidgetCls {
public:
    double itemExtent;


     SliverFixedExtentListCls(SliverChildDelegate delegate, double itemExtent, Key key);
    virtual RenderSliverFixedExtentList createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderSliverFixedExtentList renderObject);

private:

};
using SliverFixedExtentList = std::shared_ptr<SliverFixedExtentListCls>;

class SliverGridCls : public SliverMultiBoxAdaptorWidgetCls {
public:
    SliverGridDelegate gridDelegate;


     SliverGridCls(SliverChildDelegate delegate, SliverGridDelegate gridDelegate, Key key);
    virtual void  count(double childAspectRatio, List<Widget> children, int crossAxisCount, double crossAxisSpacing, Key key, double mainAxisSpacing);

    virtual void  extent(double childAspectRatio, List<Widget> children, double crossAxisSpacing, Key key, double mainAxisSpacing, double maxCrossAxisExtent);

    virtual RenderSliverGrid createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderSliverGrid renderObject);

    virtual double estimateMaxScrollOffset(SliverConstraints constraints, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset);

private:

};
using SliverGrid = std::shared_ptr<SliverGridCls>;

class SliverMultiBoxAdaptorElementCls : public RenderObjectElementCls {
public:

     SliverMultiBoxAdaptorElementCls(SliverMultiBoxAdaptorWidget widget, bool replaceMovedChildren);

    virtual RenderSliverMultiBoxAdaptor renderObject();

    virtual void update(SliverMultiBoxAdaptorWidget newWidget);

    virtual void performRebuild();

    virtual void createChild(int index, RenderBox after);

    virtual Element updateChild(Element child, Widget newWidget, Object newSlot);

    virtual void forgetChild(Element child);

    virtual void removeChild(RenderBox child);

    virtual double estimateMaxScrollOffset(SliverConstraints constraints, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset);

    virtual int estimatedChildCount();

    virtual int childCount();

    virtual void didStartLayout();

    virtual void didFinishLayout();

    virtual bool debugAssertChildListLocked();

    virtual void didAdoptChild(RenderBox child);

    virtual void setDidUnderflow(bool value);

    virtual void insertRenderObjectChild(RenderObject child, int slot);

    virtual void moveRenderObjectChild(RenderObject child, int oldSlot, int newSlot);

    virtual void removeRenderObjectChild(RenderObject child, int slot);

    virtual void visitChildren(ElementVisitor visitor);

    virtual void debugVisitOnstageChildren(ElementVisitor visitor);

private:
    bool _replaceMovedChildren;

    SplayTreeMap<int, Element> _childElements;

    RenderBox _currentBeforeChild;

    int _currentlyUpdatingChildIndex;

    bool _didUnderflow;


    virtual Widget _build(int index, SliverMultiBoxAdaptorWidget widget);

    static double _extrapolateMaxScrollOffset(int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset, int childCount);

};
using SliverMultiBoxAdaptorElement = std::shared_ptr<SliverMultiBoxAdaptorElementCls>;

class SliverOpacityCls : public SingleChildRenderObjectWidgetCls {
public:
    double opacity;

    bool alwaysIncludeSemantics;


     SliverOpacityCls(bool alwaysIncludeSemantics, Key key, double opacity, Widget sliver);

    virtual RenderSliverOpacity createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderSliverOpacity renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using SliverOpacity = std::shared_ptr<SliverOpacityCls>;

class SliverIgnorePointerCls : public SingleChildRenderObjectWidgetCls {
public:
    bool ignoring;

    bool ignoringSemantics;


     SliverIgnorePointerCls(bool ignoring, bool ignoringSemantics, Key key, Widget sliver);

    virtual RenderSliverIgnorePointer createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderSliverIgnorePointer renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using SliverIgnorePointer = std::shared_ptr<SliverIgnorePointerCls>;

class SliverOffstageCls : public SingleChildRenderObjectWidgetCls {
public:
    bool offstage;


     SliverOffstageCls(Key key, bool offstage, Widget sliver);

    virtual RenderSliverOffstage createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderSliverOffstage renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual SingleChildRenderObjectElement createElement();

private:

};
using SliverOffstage = std::shared_ptr<SliverOffstageCls>;

class _SliverOffstageElementCls : public SingleChildRenderObjectElementCls {
public:

    virtual void debugVisitOnstageChildren(ElementVisitor visitor);

private:

     _SliverOffstageElementCls(SliverOffstage widget);
};
using _SliverOffstageElement = std::shared_ptr<_SliverOffstageElementCls>;

class KeepAliveCls : public ParentDataWidgetCls<KeepAliveParentDataMixin> {
public:
    bool keepAlive;


     KeepAliveCls(Widget child, bool keepAlive, Key key);

    virtual void applyParentData(RenderObject renderObject);

    virtual bool debugCanApplyOutOfTurn();

    virtual Type debugTypicalAncestorWidgetClass();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using KeepAlive = std::shared_ptr<KeepAliveCls>;
Widget _createErrorWidget(Object exception, StackTrace stackTrace);



#endif