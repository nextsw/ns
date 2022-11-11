#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_FRAMEWORK
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_FRAMEWORK
#include <base.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/collection/collection.hpp>
#include <dart/developer/developer.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "binding.hpp"
#include "debug.hpp"
#include "focus_manager.hpp"
#include "inherited_model.hpp"
#include "notification_listener.hpp"
#include "widget_inspector.hpp"


class _DebugOnlyCls : public ObjectCls {
public:

private:

     _DebugOnlyCls();
};
using _DebugOnly = std::shared_ptr<_DebugOnlyCls>;
_DebugOnly _debugOnly;


class ObjectKeyCls : public LocalKeyCls {
public:
    Object value;


     ObjectKeyCls(Object value);
    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using ObjectKey = std::shared_ptr<ObjectKeyCls>;

template<typename T>
class GlobalKeyCls : public KeyCls {
public:

     GlobalKeyCls(String debugLabel);

    virtual void  constructor();

    virtual BuildContext currentContext();

    virtual Widget currentWidget();

    virtual T currentState();

private:

    virtual Element _currentElement();

};
template<typename T>
using GlobalKey = std::shared_ptr<GlobalKeyCls<T>>;

template<typename T>
class LabeledGlobalKeyCls : public GlobalKeyCls<T> {
public:

     LabeledGlobalKeyCls(String _debugLabel);

    virtual String toString();

private:
    String _debugLabel;


};
template<typename T>
using LabeledGlobalKey = std::shared_ptr<LabeledGlobalKeyCls<T>>;

template<typename T>
class GlobalObjectKeyCls : public GlobalKeyCls<T> {
public:
    Object value;


     GlobalObjectKeyCls(Object value);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
template<typename T>
using GlobalObjectKey = std::shared_ptr<GlobalObjectKeyCls<T>>;

class WidgetCls : public DiagnosticableTreeCls {
public:
    Key key;


     WidgetCls(Key key);
    virtual Element createElement();
    virtual String toStringShort();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual bool operator==(Object other);

    virtual int hashCode();

    static bool canUpdate(Widget newWidget, Widget oldWidget);

private:

    static int _debugConcreteSubtype(Widget widget);

};
using Widget = std::shared_ptr<WidgetCls>;

class StatelessWidgetCls : public WidgetCls {
public:

     StatelessWidgetCls(Unknown key);
    virtual StatelessElement createElement();

    virtual Widget build(BuildContext context);
private:

};
using StatelessWidget = std::shared_ptr<StatelessWidgetCls>;

class StatefulWidgetCls : public WidgetCls {
public:

     StatefulWidgetCls(Unknown key);
    virtual StatefulElement createElement();

    virtual State createState();
private:

};
using StatefulWidget = std::shared_ptr<StatefulWidgetCls>;

enum _StateLifecycle{
    created,
    initialized,
    ready,
    defunct,
} // end _StateLifecycle

template<typename T>
class StateCls : public ObjectCls {
public:

    virtual T widget();

    virtual BuildContext context();

    virtual bool mounted();

    virtual void initState();

    virtual void didUpdateWidget(T oldWidget);

    virtual void reassemble();

    virtual void setState(VoidCallback fn);

    virtual void deactivate();

    virtual void activate();

    virtual void dispose();

    virtual Widget build(BuildContext context);
    virtual void didChangeDependencies();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    T _widget;

    _StateLifecycle _debugLifecycleState;

    StatefulElement _element;


    virtual bool _debugTypesAreRight(Widget widget);

};
template<typename T>
using State = std::shared_ptr<StateCls<T>>;

class ProxyWidgetCls : public WidgetCls {
public:
    Widget child;


     ProxyWidgetCls(Widget child, Unknown key);
private:

};
using ProxyWidget = std::shared_ptr<ProxyWidgetCls>;

template<typename T>
class ParentDataWidgetCls : public ProxyWidgetCls {
public:

     ParentDataWidgetCls(Unknown child, Unknown key);
    virtual ParentDataElement<T> createElement();

    virtual bool debugIsValidRenderObject(RenderObject renderObject);

    virtual Type debugTypicalAncestorWidgetClass();
    virtual void applyParentData(RenderObject renderObject);
    virtual bool debugCanApplyOutOfTurn();

private:

    virtual Iterable<DiagnosticsNode> _debugDescribeIncorrectParentDataType(DiagnosticsNode ownershipChain, ParentData parentData, RenderObjectWidget parentDataCreator);

};
template<typename T>
using ParentDataWidget = std::shared_ptr<ParentDataWidgetCls<T>>;

class InheritedWidgetCls : public ProxyWidgetCls {
public:

     InheritedWidgetCls(Unknown child, Unknown key);
    virtual InheritedElement createElement();

    virtual bool updateShouldNotify(InheritedWidget oldWidget);
private:

};
using InheritedWidget = std::shared_ptr<InheritedWidgetCls>;

class RenderObjectWidgetCls : public WidgetCls {
public:

     RenderObjectWidgetCls(Unknown key);
    virtual RenderObjectElement createElement() override;
    virtual RenderObject createRenderObject(BuildContext context);
    virtual void updateRenderObject(BuildContext context, RenderObject renderObject);

    virtual void didUnmountRenderObject(RenderObject renderObject);

private:

};
using RenderObjectWidget = std::shared_ptr<RenderObjectWidgetCls>;

class LeafRenderObjectWidgetCls : public RenderObjectWidgetCls {
public:

     LeafRenderObjectWidgetCls(Unknown key);
    virtual LeafRenderObjectElement createElement();

private:

};
using LeafRenderObjectWidget = std::shared_ptr<LeafRenderObjectWidgetCls>;

class SingleChildRenderObjectWidgetCls : public RenderObjectWidgetCls {
public:
    Widget child;


     SingleChildRenderObjectWidgetCls(Widget child, Unknown key);
    virtual SingleChildRenderObjectElement createElement();

private:

};
using SingleChildRenderObjectWidget = std::shared_ptr<SingleChildRenderObjectWidgetCls>;

class MultiChildRenderObjectWidgetCls : public RenderObjectWidgetCls {
public:
    List<Widget> children;


     MultiChildRenderObjectWidgetCls(List<Widget> children, Unknown key);

    virtual MultiChildRenderObjectElement createElement();

private:

};
using MultiChildRenderObjectWidget = std::shared_ptr<MultiChildRenderObjectWidgetCls>;

enum _ElementLifecycle{
    initial,
    active,
    inactive,
    defunct,
} // end _ElementLifecycle

class _InactiveElementsCls : public ObjectCls {
public:

    virtual void add(Element element);

    virtual void remove(Element element);

    virtual bool debugContains(Element element);

private:
    bool _locked;

    Set<Element> _elements;


    virtual void _unmount(Element element);

    virtual void _unmountAll();

    static void _deactivateRecursively(Element element);

};
using _InactiveElements = std::shared_ptr<_InactiveElementsCls>;

class BuildContextCls : public ObjectCls {
public:

    virtual Widget widget();
    virtual BuildOwner owner();
    virtual bool debugDoingBuild();
    virtual RenderObject findRenderObject();
    virtual Size size();
    virtual InheritedWidget dependOnInheritedElement(InheritedElement ancestor, Object aspect);
    template<typename T>
 virtual T dependOnInheritedWidgetOfExactType(Object aspect);
    template<typename T>
 virtual InheritedElement getElementForInheritedWidgetOfExactType();
    template<typename T>
 virtual T findAncestorWidgetOfExactType();
    template<typename T>
 virtual T findAncestorStateOfType();
    template<typename T>
 virtual T findRootAncestorStateOfType();
    template<typename T>
 virtual T findAncestorRenderObjectOfType();
    virtual void visitAncestorElements(std::function<bool(Element element)> visitor);
    virtual void visitChildElements(ElementVisitor visitor);
    virtual void dispatchNotification(Notification notification);
    virtual DiagnosticsNode describeElement(String name, DiagnosticsTreeStyle style);
    virtual DiagnosticsNode describeWidget(String name, DiagnosticsTreeStyle style);
    virtual List<DiagnosticsNode> describeMissingAncestor(Type expectedAncestorType);
    virtual DiagnosticsNode describeOwnershipChain(String name);
private:

};
using BuildContext = std::shared_ptr<BuildContextCls>;

class BuildOwnerCls : public ObjectCls {
public:
    VoidCallback onBuildScheduled;

    FocusManager focusManager;


     BuildOwnerCls(FocusManager focusManager, VoidCallback onBuildScheduled);

    virtual void scheduleBuildFor(Element element);

    virtual bool debugBuilding();

    virtual void lockState(VoidCallback callback);

    virtual void buildScope(VoidCallback callback, Element context);

    virtual int globalKeyCount();

    virtual void finalizeTree();

    virtual void reassemble(DebugReassembleConfig reassembleConfig, Element root);

private:
    _InactiveElements _inactiveElements;

    List<Element> _dirtyElements;

    bool _scheduledFlushDirtyElements;

    bool _dirtyElementsNeedsResorting;

    int _debugStateLockLevel;

    bool _debugBuilding;

    Element _debugCurrentBuildTarget;

    Map<Element, Set<GlobalKey>> _debugElementsThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans;

    Map<GlobalKey, Element> _globalKeyRegistry;

    Set<Element> _debugIllFatedElements;

    Map<Element, Map<Element, GlobalKey>> _debugGlobalKeyReservations;


    virtual bool _debugIsInBuildScope();

    virtual bool _debugStateLocked();

    virtual void _debugTrackElementThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans(GlobalKey key, Element node);

    virtual void _debugElementWasRebuilt(Element node);

    virtual void _debugRemoveGlobalKeyReservationFor(Element child, Element parent);

    virtual void _registerGlobalKey(Element element, GlobalKey key);

    virtual void _unregisterGlobalKey(Element element, GlobalKey key);

    virtual void _debugReserveGlobalKeyFor(Element child, GlobalKey key, Element parent);

    virtual void _debugVerifyGlobalKeyReservation();

    virtual void _debugVerifyIllFatedPopulation();

};
using BuildOwner = std::shared_ptr<BuildOwnerCls>;

class NotifiableElementMixinCls : public ObjectCls {
public:

    virtual bool onNotification(Notification notification);
    virtual void attachNotificationTree();

private:

};
using NotifiableElementMixin = std::shared_ptr<NotifiableElementMixinCls>;

class _NotificationNodeCls : public ObjectCls {
public:
    NotifiableElementMixin current;

    _NotificationNode parent;


    virtual void dispatchNotification(Notification notification);

private:

     _NotificationNodeCls(NotifiableElementMixin current, _NotificationNode parent);
};
using _NotificationNode = std::shared_ptr<_NotificationNodeCls>;
bool _isProfileBuildsEnabledFor(Widget widget);


class ElementCls : public DiagnosticableTreeCls {
public:

     ElementCls(Widget widget);

    virtual bool operator==(Object other);

    virtual Object slot();

    virtual int depth();

    virtual Widget widget();

    virtual bool debugIsDefunct();

    virtual bool debugIsActive();

    virtual BuildOwner owner();

    virtual void reassemble();

    virtual RenderObject renderObject();

    virtual List<DiagnosticsNode> describeMissingAncestor(Type expectedAncestorType);

    static DiagnosticsNode describeElements(Iterable<Element> elements, String name);

    virtual DiagnosticsNode describeElement(String name, DiagnosticsTreeStyle style);

    virtual DiagnosticsNode describeWidget(String name, DiagnosticsTreeStyle style);

    virtual DiagnosticsNode describeOwnershipChain(String name);

    virtual void visitChildren(ElementVisitor visitor);

    virtual void debugVisitOnstageChildren(ElementVisitor visitor);

    virtual void visitChildElements(ElementVisitor visitor);

    virtual Element updateChild(Element child, Object newSlot, Widget newWidget);

    virtual void mount(Object newSlot, Element parent);

    virtual void update(Widget newWidget);

    virtual void updateSlotForChild(Element child, Object newSlot);

    virtual void detachRenderObject();

    virtual void attachRenderObject(Object newSlot);

    virtual Element inflateWidget(Object newSlot, Widget newWidget);

    virtual void deactivateChild(Element child);

    virtual void forgetChild(Element child);

    virtual void activate();

    virtual void deactivate();

    virtual void debugDeactivated();

    virtual void unmount();

    virtual RenderObject findRenderObject();

    virtual Size size();

    virtual bool doesDependOnInheritedElement(InheritedElement ancestor);

    virtual InheritedWidget dependOnInheritedElement(InheritedElement ancestor, Object aspect);

    template<typename T>
 virtual T dependOnInheritedWidgetOfExactType(Object aspect);

    template<typename T>
 virtual InheritedElement getElementForInheritedWidgetOfExactType();

    virtual void attachNotificationTree();

    template<typename T>
 virtual T findAncestorWidgetOfExactType();

    template<typename T>
 virtual T findAncestorStateOfType();

    template<typename T>
 virtual T findRootAncestorStateOfType();

    template<typename T>
 virtual T findAncestorRenderObjectOfType();

    virtual void visitAncestorElements(std::function<bool(Element element)> visitor);

    virtual void didChangeDependencies();

    virtual String debugGetCreatorChain(int limit);

    virtual List<Element> debugGetDiagnosticChain();

    virtual void dispatchNotification(Notification notification);

    virtual String toStringShort();

    virtual DiagnosticsNode toDiagnosticsNode(String name, DiagnosticsTreeStyle style);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual List<DiagnosticsNode> debugDescribeChildren();

    virtual bool dirty();

    virtual void markNeedsBuild();

    virtual void rebuild();

    virtual void performRebuild();
private:
    Element _parent;

    DebugReassembleConfig _debugReassembleConfig;

    _NotificationNode _notificationTree;

    Object _slot;

    int _depth;

    Widget _widget;

    BuildOwner _owner;

    _ElementLifecycle _lifecycleState;

    Set<Element> _debugForgottenChildrenWithGlobalKey;

    Map<Type, InheritedElement> _inheritedWidgets;

    Set<InheritedElement> _dependencies;

    bool _hadUnsatisfiedDependencies;

    bool _dirty;

    bool _inDirtyList;

    bool _debugBuiltOnce;

    bool _debugAllowIgnoredCallsToMarkNeedsBuild;


    static int _sort(Element a, Element b);

    static int _debugConcreteSubtype(Element element);

    virtual bool _debugIsInScope(Element target);

    virtual void _debugRemoveGlobalKeyReservation(Element child);

    virtual void _updateSlot(Object newSlot);

    virtual void _updateDepth(int parentDepth);

    virtual Element _retakeInactiveElement(GlobalKey key, Widget newWidget);

    virtual void _debugCheckForCycles(Element newChild);

    virtual void _activateWithParent(Object newSlot, Element parent);

    static void _activateRecursively(Element element);

    virtual bool _debugCheckStateIsActiveForAncestorLookup();

    virtual void _updateInheritance();

    virtual bool _debugCheckOwnerBuildTargetExists(String methodName);

    virtual bool _debugSetAllowIgnoredCallsToMarkNeedsBuild(bool value);

};
using Element = std::shared_ptr<ElementCls>;

class _ElementDiagnosticableTreeNodeCls : public DiagnosticableTreeNodeCls {
public:
    bool stateful;


    virtual Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

private:

     _ElementDiagnosticableTreeNodeCls(Unknown name, bool stateful, Unknown style, Element value);
};
using _ElementDiagnosticableTreeNode = std::shared_ptr<_ElementDiagnosticableTreeNodeCls>;

class ErrorWidgetCls : public LeafRenderObjectWidgetCls {
public:
    static ErrorWidgetBuilder builder;

    String message;


     ErrorWidgetCls(Object exception);

    virtual void  withDetails(FlutterError error, String message);

    virtual RenderBox createRenderObject(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    FlutterError _flutterError;


    static Widget _defaultErrorWidgetBuilder(FlutterErrorDetails details);

    static String _stringify(Object exception);

};
using ErrorWidget = std::shared_ptr<ErrorWidgetCls>;

class ComponentElementCls : public ElementCls {
public:

     ComponentElementCls(Unknown widget);
    virtual bool debugDoingBuild();

    virtual void mount(Object newSlot, Element parent);

    virtual void performRebuild();

    virtual Widget build();
    virtual void visitChildren(ElementVisitor visitor);

    virtual void forgetChild(Element child);

private:
    Element _child;

    bool _debugDoingBuild;


    virtual void _firstBuild();

};
using ComponentElement = std::shared_ptr<ComponentElementCls>;

class StatelessElementCls : public ComponentElementCls {
public:

     StatelessElementCls(StatelessWidget widget);
    virtual Widget build();

    virtual void update(StatelessWidget newWidget);

private:

};
using StatelessElement = std::shared_ptr<StatelessElementCls>;

class StatefulElementCls : public ComponentElementCls {
public:

     StatefulElementCls(StatefulWidget widget);

    virtual Widget build();

    virtual State<StatefulWidget> state();

    virtual void reassemble();

    virtual void performRebuild();

    virtual void update(StatefulWidget newWidget);

    virtual void activate();

    virtual void deactivate();

    virtual void unmount();

    virtual InheritedWidget dependOnInheritedElement(Element ancestor, Object aspect);

    virtual void didChangeDependencies();

    virtual DiagnosticsNode toDiagnosticsNode(String name, DiagnosticsTreeStyle style);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    State<StatefulWidget> _state;

    bool _didChangeDependencies;


    virtual void _firstBuild();

};
using StatefulElement = std::shared_ptr<StatefulElementCls>;

class ProxyElementCls : public ComponentElementCls {
public:

     ProxyElementCls(ProxyWidget widget);
    virtual Widget build();

    virtual void update(ProxyWidget newWidget);

    virtual void updated(ProxyWidget oldWidget);

    virtual void notifyClients(ProxyWidget oldWidget);
private:

};
using ProxyElement = std::shared_ptr<ProxyElementCls>;

template<typename T>
class ParentDataElementCls : public ProxyElementCls {
public:

     ParentDataElementCls(ParentDataWidget<T> widget);
    virtual void applyWidgetOutOfTurn(ParentDataWidget<T> newWidget);

    virtual void notifyClients(ParentDataWidget<T> oldWidget);

private:

    virtual void _applyParentData(ParentDataWidget<T> widget);

};
template<typename T>
using ParentDataElement = std::shared_ptr<ParentDataElementCls<T>>;

class InheritedElementCls : public ProxyElementCls {
public:

     InheritedElementCls(InheritedWidget widget);
    virtual void debugDeactivated();

    virtual Object getDependencies(Element dependent);

    virtual void setDependencies(Element dependent, Object value);

    virtual void updateDependencies(Object aspect, Element dependent);

    virtual void notifyDependent(Element dependent, InheritedWidget oldWidget);

    virtual void updated(InheritedWidget oldWidget);

    virtual void notifyClients(InheritedWidget oldWidget);

private:
    Map<Element, Object> _dependents;


    virtual void _updateInheritance();

};
using InheritedElement = std::shared_ptr<InheritedElementCls>;

class RenderObjectElementCls : public ElementCls {
public:

     RenderObjectElementCls(RenderObjectWidget widget);
    virtual RenderObject renderObject();

    virtual bool debugDoingBuild();

    virtual void mount(Object newSlot, Element parent);

    virtual void update(RenderObjectWidget newWidget);

    virtual void performRebuild();

    virtual List<Element> updateChildren(Set<Element> forgottenChildren, List<Widget> newWidgets, List<Element> oldChildren, List<Object> slots);

    virtual void deactivate();

    virtual void unmount();

    virtual void attachRenderObject(Object newSlot);

    virtual void detachRenderObject();

    virtual void insertRenderObjectChild(RenderObject child, Object slot);

    virtual void moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot);

    virtual void removeRenderObjectChild(RenderObject child, Object slot);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    RenderObject _renderObject;

    bool _debugDoingBuild;

    RenderObjectElement _ancestorRenderObjectElement;


    virtual RenderObjectElement _findAncestorRenderObjectElement();

    virtual ParentDataElement<ParentData> _findAncestorParentDataElement();

    virtual void _debugUpdateRenderObjectOwner();

    virtual void _performRebuild();

    virtual void _updateParentData(ParentDataWidget<ParentData> parentDataWidget);

    virtual void _updateSlot(Object newSlot);

};
using RenderObjectElement = std::shared_ptr<RenderObjectElementCls>;

class RootRenderObjectElementCls : public RenderObjectElementCls {
public:

     RootRenderObjectElementCls(Unknown widget);
    virtual void assignOwner(BuildOwner owner);

    virtual void mount(Object newSlot, Element parent);

private:

};
using RootRenderObjectElement = std::shared_ptr<RootRenderObjectElementCls>;

class LeafRenderObjectElementCls : public RenderObjectElementCls {
public:

     LeafRenderObjectElementCls(LeafRenderObjectWidget widget);
    virtual void forgetChild(Element child);

    virtual void insertRenderObjectChild(RenderObject child, Object slot);

    virtual void moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot);

    virtual void removeRenderObjectChild(RenderObject child, Object slot);

    virtual List<DiagnosticsNode> debugDescribeChildren();

private:

};
using LeafRenderObjectElement = std::shared_ptr<LeafRenderObjectElementCls>;

class SingleChildRenderObjectElementCls : public RenderObjectElementCls {
public:

     SingleChildRenderObjectElementCls(SingleChildRenderObjectWidget widget);
    virtual void visitChildren(ElementVisitor visitor);

    virtual void forgetChild(Element child);

    virtual void mount(Object newSlot, Element parent);

    virtual void update(SingleChildRenderObjectWidget newWidget);

    virtual void insertRenderObjectChild(RenderObject child, Object slot);

    virtual void moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot);

    virtual void removeRenderObjectChild(RenderObject child, Object slot);

private:
    Element _child;


};
using SingleChildRenderObjectElement = std::shared_ptr<SingleChildRenderObjectElementCls>;

class MultiChildRenderObjectElementCls : public RenderObjectElementCls {
public:

     MultiChildRenderObjectElementCls(MultiChildRenderObjectWidget widget);

    virtual ContainerRenderObjectMixin<RenderObject, ContainerParentDataMixin<RenderObject>> renderObject();

    virtual Iterable<Element> children();

    virtual void insertRenderObjectChild(RenderObject child, IndexedSlot<Element> slot);

    virtual void moveRenderObjectChild(RenderObject child, IndexedSlot<Element> newSlot, IndexedSlot<Element> oldSlot);

    virtual void removeRenderObjectChild(RenderObject child, Object slot);

    virtual void visitChildren(ElementVisitor visitor);

    virtual void forgetChild(Element child);

    virtual Element inflateWidget(Object newSlot, Widget newWidget);

    virtual void mount(Object newSlot, Element parent);

    virtual void update(MultiChildRenderObjectWidget newWidget);

private:
    List<Element> _children;

    Set<Element> _forgottenChildren;


    virtual bool _debugCheckHasAssociatedRenderObject(Element newChild);

};
using MultiChildRenderObjectElement = std::shared_ptr<MultiChildRenderObjectElementCls>;

class DebugCreatorCls : public ObjectCls {
public:
    Element element;


     DebugCreatorCls(Element element);
    virtual String toString();

private:

};
using DebugCreator = std::shared_ptr<DebugCreatorCls>;
FlutterErrorDetails _debugReportException(DiagnosticsNode context, Object exception, InformationCollector informationCollector, StackTrace stack);


template<typename T>
class IndexedSlotCls : public ObjectCls {
public:
    T value;

    int index;


     IndexedSlotCls(int index, T value);
    virtual bool operator==(Object other);

    virtual int hashCode();

private:

};
template<typename T>
using IndexedSlot = std::shared_ptr<IndexedSlotCls<T>>;

class _NullElementCls : public ElementCls {
public:
    static _NullElement instance;


    virtual bool debugDoingBuild();

    virtual void performRebuild();

private:

     _NullElementCls();

};
using _NullElement = std::shared_ptr<_NullElementCls>;

class _NullWidgetCls : public WidgetCls {
public:

    virtual Element createElement();

private:

     _NullWidgetCls();
};
using _NullWidget = std::shared_ptr<_NullWidgetCls>;
bool _debugShouldReassemble(DebugReassembleConfig config, Widget widget);



#endif