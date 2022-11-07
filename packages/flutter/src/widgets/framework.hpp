#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include <memory>
#include <flutter/foundation.hpp>
#include <flutter/foundation.hpp>
#include <flutter/foundation.hpp>
#include <flutter/foundation.hpp>
#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>

#include <async/async.hpp>
#include <collection/collection.hpp>
#include <developer/developer.hpp>
#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include "binding.hpp"
#include "debug.hpp"
#include "focus_manager.hpp"
#include "inherited_model.hpp"
#include "notification_listener.hpp"
#include "widget_inspector.hpp"



class _DebugOnly {
public:

private:

     _DebugOnly();

};
const _DebugOnly _debugOnly;


class ObjectKey : LocalKey {
public:
    Object value;


     ObjectKey(Object value);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class GlobalKey<T extends State<StatefulWidget>> : Key {
public:

     GlobalKey(String debugLabel);

    void  constructor();

    BuildContext currentContext();

    Widget currentWidget();

    T currentState();

private:

    Element _currentElement();

};

class LabeledGlobalKey<T extends State<StatefulWidget>> : GlobalKey<T> {
public:

     LabeledGlobalKey(String _debugLabel);

    String toString();

private:
    String _debugLabel;


};

class GlobalObjectKey<T extends State<StatefulWidget>> : GlobalKey<T> {
public:
    Object value;


     GlobalObjectKey(Object value);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class Widget : DiagnosticableTree {
public:
    Key key;


     Widget(Key key);

    Element createElement();

    String toStringShort();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    bool ==(Object other);

    int hashCode();

    static bool canUpdate(Widget newWidget, Widget oldWidget);

private:

    static int _debugConcreteSubtype(Widget widget);

};

class StatelessWidget : Widget {
public:

     StatelessWidget(Unknown);

    StatelessElement createElement();

    Widget build(BuildContext context);

private:

};

class StatefulWidget : Widget {
public:

     StatefulWidget(Unknown);

    StatefulElement createElement();

    State createState();

private:

};

enum _StateLifecycle{
    created,
    initialized,
    ready,
    defunct,
} // end _StateLifecycle

class State<T extends StatefulWidget> {
public:

    T widget();

    BuildContext context();

    bool mounted();

    void initState();

    void didUpdateWidget(T oldWidget);

    void reassemble();

    void setState(VoidCallback fn);

    void deactivate();

    void activate();

    void dispose();

    Widget build(BuildContext context);

    void didChangeDependencies();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    T _widget;

    _StateLifecycle _debugLifecycleState;

    StatefulElement _element;


    bool _debugTypesAreRight(Widget widget);

};

class ProxyWidget : Widget {
public:
    Widget child;


     ProxyWidget(Widget child, Unknown);

private:

};

class ParentDataWidget<T extends ParentData> : ProxyWidget {
public:

     ParentDataWidget(Unknown, Unknown);

    ParentDataElement<T> createElement();

    bool debugIsValidRenderObject(RenderObject renderObject);

    Type debugTypicalAncestorWidgetClass();

    void applyParentData(RenderObject renderObject);

    bool debugCanApplyOutOfTurn();

private:

    Iterable<DiagnosticsNode> _debugDescribeIncorrectParentDataType(DiagnosticsNode ownershipChain, ParentData parentData, RenderObjectWidget parentDataCreator);

};

class InheritedWidget : ProxyWidget {
public:

     InheritedWidget(Unknown, Unknown);

    InheritedElement createElement();

    bool updateShouldNotify(InheritedWidget oldWidget);

private:

};

class RenderObjectWidget : Widget {
public:

     RenderObjectWidget(Unknown);

    RenderObjectElement createElement();

    RenderObject createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderObject renderObject);

    void didUnmountRenderObject(RenderObject renderObject);

private:

};

class LeafRenderObjectWidget : RenderObjectWidget {
public:

     LeafRenderObjectWidget(Unknown);

    LeafRenderObjectElement createElement();

private:

};

class SingleChildRenderObjectWidget : RenderObjectWidget {
public:
    Widget child;


     SingleChildRenderObjectWidget(Widget child, Unknown);

    SingleChildRenderObjectElement createElement();

private:

};

class MultiChildRenderObjectWidget : RenderObjectWidget {
public:
    List<Widget> children;


     MultiChildRenderObjectWidget(List<Widget> children, Unknown);

    MultiChildRenderObjectElement createElement();

private:

};

enum _ElementLifecycle{
    initial,
    active,
    inactive,
    defunct,
} // end _ElementLifecycle

class _InactiveElements {
public:

    void add(Element element);

    void remove(Element element);

    bool debugContains(Element element);

private:
    bool _locked;

    Set<Element> _elements;


    void _unmount(Element element);

    void _unmountAll();

    static void _deactivateRecursively(Element element);

};

class BuildContext {
public:

    Widget widget();

    BuildOwner owner();

    bool debugDoingBuild();

    RenderObject findRenderObject();

    Size size();

    InheritedWidget dependOnInheritedElement(InheritedElement ancestor, Object aspect);

    T dependOnInheritedWidgetOfExactType<T extends InheritedWidget>(Object aspect);

    InheritedElement getElementForInheritedWidgetOfExactType<T extends InheritedWidget>();

    T findAncestorWidgetOfExactType<T extends Widget>();

    T findAncestorStateOfType<T extends State>();

    T findRootAncestorStateOfType<T extends State>();

    T findAncestorRenderObjectOfType<T extends RenderObject>();

    void visitAncestorElements(FunctionType visitor);

    void visitChildElements(ElementVisitor visitor);

    void dispatchNotification(Notification notification);

    DiagnosticsNode describeElement(String name, DiagnosticsTreeStyle style);

    DiagnosticsNode describeWidget(String name, DiagnosticsTreeStyle style);

    List<DiagnosticsNode> describeMissingAncestor(Type expectedAncestorType);

    DiagnosticsNode describeOwnershipChain(String name);

private:

};

class BuildOwner {
public:
    VoidCallback onBuildScheduled;

    FocusManager focusManager;


     BuildOwner(FocusManager focusManager, VoidCallback onBuildScheduled);

    void scheduleBuildFor(Element element);

    bool debugBuilding();

    void lockState(VoidCallback callback);

    void buildScope(VoidCallback callback, Element context);

    int globalKeyCount();

    void finalizeTree();

    void reassemble(DebugReassembleConfig reassembleConfig, Element root);

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


    bool _debugIsInBuildScope();

    bool _debugStateLocked();

    void _debugTrackElementThatWillNeedToBeRebuiltDueToGlobalKeyShenanigans(GlobalKey key, Element node);

    void _debugElementWasRebuilt(Element node);

    void _debugRemoveGlobalKeyReservationFor(Element child, Element parent);

    void _registerGlobalKey(Element element, GlobalKey key);

    void _unregisterGlobalKey(Element element, GlobalKey key);

    void _debugReserveGlobalKeyFor(Element child, GlobalKey key, Element parent);

    void _debugVerifyGlobalKeyReservation();

    void _debugVerifyIllFatedPopulation();

};

class NotifiableElementMixin {
public:

    bool onNotification(Notification notification);

    void attachNotificationTree();

private:

};

class _NotificationNode {
public:
    NotifiableElementMixin current;

    _NotificationNode parent;


    void dispatchNotification(Notification notification);

private:

     _NotificationNode(NotifiableElementMixin current, _NotificationNode parent);

};
bool _isProfileBuildsEnabledFor(Widget widget);


class Element : DiagnosticableTree {
public:

     Element(Widget widget);

    bool ==(Object other);

    Object slot();

    int depth();

    Widget widget();

    bool debugIsDefunct();

    bool debugIsActive();

    BuildOwner owner();

    void reassemble();

    RenderObject renderObject();

    List<DiagnosticsNode> describeMissingAncestor(Type expectedAncestorType);

    static DiagnosticsNode describeElements(Iterable<Element> elements, String name);

    DiagnosticsNode describeElement(String name, DiagnosticsTreeStyle style);

    DiagnosticsNode describeWidget(String name, DiagnosticsTreeStyle style);

    DiagnosticsNode describeOwnershipChain(String name);

    void visitChildren(ElementVisitor visitor);

    void debugVisitOnstageChildren(ElementVisitor visitor);

    void visitChildElements(ElementVisitor visitor);

    Element updateChild(Element child, Object newSlot, Widget newWidget);

    void mount(Object newSlot, Element parent);

    void update(Widget newWidget);

    void updateSlotForChild(Element child, Object newSlot);

    void detachRenderObject();

    void attachRenderObject(Object newSlot);

    Element inflateWidget(Object newSlot, Widget newWidget);

    void deactivateChild(Element child);

    void forgetChild(Element child);

    void activate();

    void deactivate();

    void debugDeactivated();

    void unmount();

    RenderObject findRenderObject();

    Size size();

    bool doesDependOnInheritedElement(InheritedElement ancestor);

    InheritedWidget dependOnInheritedElement(InheritedElement ancestor, Object aspect);

    T dependOnInheritedWidgetOfExactType<T extends InheritedWidget>(Object aspect);

    InheritedElement getElementForInheritedWidgetOfExactType<T extends InheritedWidget>();

    void attachNotificationTree();

    T findAncestorWidgetOfExactType<T extends Widget>();

    T findAncestorStateOfType<T extends State<StatefulWidget>>();

    T findRootAncestorStateOfType<T extends State<StatefulWidget>>();

    T findAncestorRenderObjectOfType<T extends RenderObject>();

    void visitAncestorElements(FunctionType visitor);

    void didChangeDependencies();

    String debugGetCreatorChain(int limit);

    List<Element> debugGetDiagnosticChain();

    void dispatchNotification(Notification notification);

    String toStringShort();

    DiagnosticsNode toDiagnosticsNode(String name, DiagnosticsTreeStyle style);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    List<DiagnosticsNode> debugDescribeChildren();

    bool dirty();

    void markNeedsBuild();

    void rebuild();

    void performRebuild();

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

    bool _debugIsInScope(Element target);

    void _debugRemoveGlobalKeyReservation(Element child);

    void _updateSlot(Object newSlot);

    void _updateDepth(int parentDepth);

    Element _retakeInactiveElement(GlobalKey key, Widget newWidget);

    void _debugCheckForCycles(Element newChild);

    void _activateWithParent(Object newSlot, Element parent);

    static void _activateRecursively(Element element);

    bool _debugCheckStateIsActiveForAncestorLookup();

    void _updateInheritance();

    bool _debugCheckOwnerBuildTargetExists(String methodName);

    bool _debugSetAllowIgnoredCallsToMarkNeedsBuild(bool value);

};

class _ElementDiagnosticableTreeNode : DiagnosticableTreeNode {
public:
    bool stateful;


    Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

private:

     _ElementDiagnosticableTreeNode(Unknown, bool stateful, Unknown, Element value);

};

class ErrorWidget : LeafRenderObjectWidget {
public:
    static ErrorWidgetBuilder builder;

    String message;


     ErrorWidget(Object exception);

    void  withDetails(FlutterError error, String message);

    RenderBox createRenderObject(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    FlutterError _flutterError;


    static Widget _defaultErrorWidgetBuilder(FlutterErrorDetails details);

    static String _stringify(Object exception);

};

class ComponentElement : Element {
public:

     ComponentElement(Unknown);

    bool debugDoingBuild();

    void mount(Object newSlot, Element parent);

    void performRebuild();

    Widget build();

    void visitChildren(ElementVisitor visitor);

    void forgetChild(Element child);

private:
    Element _child;

    bool _debugDoingBuild;


    void _firstBuild();

};

class StatelessElement : ComponentElement {
public:

     StatelessElement(StatelessWidget widget);

    Widget build();

    void update(StatelessWidget newWidget);

private:

};

class StatefulElement : ComponentElement {
public:

     StatefulElement(StatefulWidget widget);

    Widget build();

    State<StatefulWidget> state();

    void reassemble();

    void performRebuild();

    void update(StatefulWidget newWidget);

    void activate();

    void deactivate();

    void unmount();

    InheritedWidget dependOnInheritedElement(Element ancestor, Object aspect);

    void didChangeDependencies();

    DiagnosticsNode toDiagnosticsNode(String name, DiagnosticsTreeStyle style);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    State<StatefulWidget> _state;

    bool _didChangeDependencies;


    void _firstBuild();

};

class ProxyElement : ComponentElement {
public:

     ProxyElement(ProxyWidget widget);

    Widget build();

    void update(ProxyWidget newWidget);

    void updated(ProxyWidget oldWidget);

    void notifyClients(ProxyWidget oldWidget);

private:

};

class ParentDataElement<T extends ParentData> : ProxyElement {
public:

     ParentDataElement(ParentDataWidget<T> widget);

    void applyWidgetOutOfTurn(ParentDataWidget<T> newWidget);

    void notifyClients(ParentDataWidget<T> oldWidget);

private:

    void _applyParentData(ParentDataWidget<T> widget);

};

class InheritedElement : ProxyElement {
public:

     InheritedElement(InheritedWidget widget);

    void debugDeactivated();

    Object getDependencies(Element dependent);

    void setDependencies(Element dependent, Object value);

    void updateDependencies(Object aspect, Element dependent);

    void notifyDependent(Element dependent, InheritedWidget oldWidget);

    void updated(InheritedWidget oldWidget);

    void notifyClients(InheritedWidget oldWidget);

private:
    Map<Element, Object> _dependents;


    void _updateInheritance();

};

class RenderObjectElement : Element {
public:

     RenderObjectElement(RenderObjectWidget widget);

    RenderObject renderObject();

    bool debugDoingBuild();

    void mount(Object newSlot, Element parent);

    void update(RenderObjectWidget newWidget);

    void performRebuild();

    List<Element> updateChildren(Set<Element> forgottenChildren, List<Widget> newWidgets, List<Element> oldChildren, List<Object> slots);

    void deactivate();

    void unmount();

    void attachRenderObject(Object newSlot);

    void detachRenderObject();

    void insertRenderObjectChild(RenderObject child, Object slot);

    void moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot);

    void removeRenderObjectChild(RenderObject child, Object slot);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    RenderObject _renderObject;

    bool _debugDoingBuild;

    RenderObjectElement _ancestorRenderObjectElement;


    RenderObjectElement _findAncestorRenderObjectElement();

    ParentDataElement<ParentData> _findAncestorParentDataElement();

    void _debugUpdateRenderObjectOwner();

    void _performRebuild();

    void _updateParentData(ParentDataWidget<ParentData> parentDataWidget);

    void _updateSlot(Object newSlot);

};

class RootRenderObjectElement : RenderObjectElement {
public:

     RootRenderObjectElement(Unknown);

    void assignOwner(BuildOwner owner);

    void mount(Object newSlot, Element parent);

private:

};

class LeafRenderObjectElement : RenderObjectElement {
public:

     LeafRenderObjectElement(LeafRenderObjectWidget widget);

    void forgetChild(Element child);

    void insertRenderObjectChild(RenderObject child, Object slot);

    void moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot);

    void removeRenderObjectChild(RenderObject child, Object slot);

    List<DiagnosticsNode> debugDescribeChildren();

private:

};

class SingleChildRenderObjectElement : RenderObjectElement {
public:

     SingleChildRenderObjectElement(SingleChildRenderObjectWidget widget);

    void visitChildren(ElementVisitor visitor);

    void forgetChild(Element child);

    void mount(Object newSlot, Element parent);

    void update(SingleChildRenderObjectWidget newWidget);

    void insertRenderObjectChild(RenderObject child, Object slot);

    void moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot);

    void removeRenderObjectChild(RenderObject child, Object slot);

private:
    Element _child;


};

class MultiChildRenderObjectElement : RenderObjectElement {
public:

     MultiChildRenderObjectElement(MultiChildRenderObjectWidget widget);

    ContainerRenderObjectMixin<RenderObject, ContainerParentDataMixin<RenderObject>> renderObject();

    Iterable<Element> children();

    void insertRenderObjectChild(RenderObject child, IndexedSlot<Element> slot);

    void moveRenderObjectChild(RenderObject child, IndexedSlot<Element> newSlot, IndexedSlot<Element> oldSlot);

    void removeRenderObjectChild(RenderObject child, Object slot);

    void visitChildren(ElementVisitor visitor);

    void forgetChild(Element child);

    Element inflateWidget(Object newSlot, Widget newWidget);

    void mount(Object newSlot, Element parent);

    void update(MultiChildRenderObjectWidget newWidget);

private:
    List<Element> _children;

    Set<Element> _forgottenChildren;


    bool _debugCheckHasAssociatedRenderObject(Element newChild);

};

class DebugCreator {
public:
    Element element;


     DebugCreator(Element element);

    String toString();

private:

};
FlutterErrorDetails _debugReportException(DiagnosticsNode context, Object exception, InformationCollector informationCollector, StackTrace stack);


class IndexedSlot<T extends Element> {
public:
    T value;

    int index;


     IndexedSlot(int index, T value);

    bool ==(Object other);

    int hashCode();

private:

};

class _NullElement : Element {
public:
    static _NullElement instance;


    bool debugDoingBuild();

    void performRebuild();

private:

     _NullElement();

};

class _NullWidget : Widget {
public:

    Element createElement();

private:

     _NullWidget();

};
bool _debugShouldReassemble(DebugReassembleConfig config, Widget widget);


#endif