#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ACTIONS
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ACTIONS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic.hpp"
#include "focus_manager.hpp"
#include "focus_scope.hpp"
#include "framework.hpp"
#include "media_query.hpp"
#include "shortcuts.hpp"

BuildContext _getParent(BuildContext context);


class IntentCls : public ObjectCls {
public:
    static DoNothingIntent doNothing;


     IntentCls();
private:

};
using Intent = std::shared_ptr<IntentCls>;

template<typename T> class ActionCls : public ObjectCls {
public:

     ActionCls();
    virtual void  overridable(BuildContext context, Action<T> defaultAction);

    virtual Action<T> callingAction();

    virtual Type intentType();

    virtual bool isEnabled(T intent);

    virtual bool isActionEnabled();

    virtual bool consumesKey(T intent);

    virtual Object invoke(T intent);
    virtual void addActionListener(ActionListenerCallback listener);

    virtual void removeActionListener(ActionListenerCallback listener);

    virtual void notifyActionListeners();

private:
    ObserverList<ActionListenerCallback> _listeners;

    Action<T> _currentCallingAction;


    virtual void _updateCallingAction(Action<T> value);

    virtual Action<T> _makeOverridableAction(BuildContext context);

};
template<typename T> using Action = std::shared_ptr<ActionCls<T>>;

class ActionListenerCls : public StatefulWidgetCls {
public:
    ActionListenerCallback listener;

    Action<Intent> action;

    Widget child;


     ActionListenerCls(Action<Intent> action, Widget child, Unknown key, ActionListenerCallback listener);

    virtual State<ActionListener> createState();

private:

};
using ActionListener = std::shared_ptr<ActionListenerCls>;

class _ActionListenerStateCls : public StateCls<ActionListener> {
public:

    virtual void initState();

    virtual void didUpdateWidget(ActionListener oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:

};
using _ActionListenerState = std::shared_ptr<_ActionListenerStateCls>;

template<typename T> class ContextActionCls : public ActionCls<T> {
public:

    virtual Object invoke(BuildContext context, T intent) override;
private:

    virtual ContextAction<T> _makeOverridableAction(BuildContext context);

};
template<typename T> using ContextAction = std::shared_ptr<ContextActionCls<T>>;

template<typename T> class CallbackActionCls : public ActionCls<T> {
public:
    OnInvokeCallback<T> onInvoke;


     CallbackActionCls(OnInvokeCallback<T> onInvoke);

    virtual Object invoke(T intent);

private:

};
template<typename T> using CallbackAction = std::shared_ptr<CallbackActionCls<T>>;

class ActionDispatcherCls : public ObjectCls {
public:

     ActionDispatcherCls();
    virtual Object invokeAction(Action<Intent> action, BuildContext context, Intent intent);

private:

};
using ActionDispatcher = std::shared_ptr<ActionDispatcherCls>;

class ActionsCls : public StatefulWidgetCls {
public:
    ActionDispatcher dispatcher;

    Map<Type, Action<Intent>> actions;

    Widget child;


     ActionsCls(Map<Type, Action<Intent>> actions, Widget child, ActionDispatcher dispatcher, Unknown key);

    template<typename T>  static VoidCallback handler(BuildContext context, T intent);

    template<typename T>  static Action<T> find(BuildContext context, T intent);

    template<typename T>  static Action<T> maybeFind(BuildContext context, T intent);

    static ActionDispatcher of(BuildContext context);

    template<typename T>  static Object invoke(BuildContext context, T intent);

    template<typename T>  static Object maybeInvoke(BuildContext context, T intent);

    virtual State<Actions> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    static bool _visitActionsAncestors(BuildContext context, bool visitor(InheritedElement element) );

    static ActionDispatcher _findDispatcher(BuildContext context);

    template<typename T>  static Action<T> _maybeFindWithoutDependingOn(BuildContext context, T intent);

    template<typename T>  static Action<T> _castAction(_ActionsMarker actionsMarker, T intent);

};
using Actions = std::shared_ptr<ActionsCls>;

class _ActionsStateCls : public StateCls<Actions> {
public:
    Set<Action<Intent>> listenedActions;

    Object rebuildKey;


    virtual void initState();

    virtual void didUpdateWidget(Actions oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:

    virtual void _handleActionChanged(Action<Intent> action);

    virtual void _updateActionListeners();

};
using _ActionsState = std::shared_ptr<_ActionsStateCls>;

class _ActionsMarkerCls : public InheritedWidgetCls {
public:
    ActionDispatcher dispatcher;

    Map<Type, Action<Intent>> actions;

    Object rebuildKey;


    virtual bool updateShouldNotify(_ActionsMarker oldWidget);

private:

     _ActionsMarkerCls(Map<Type, Action<Intent>> actions, Unknown child, ActionDispatcher dispatcher, Object rebuildKey);

};
using _ActionsMarker = std::shared_ptr<_ActionsMarkerCls>;

class FocusableActionDetectorCls : public StatefulWidgetCls {
public:
    bool enabled;

    FocusNode focusNode;

    bool autofocus;

    bool descendantsAreFocusable;

    bool descendantsAreTraversable;

    Map<Type, Action<Intent>> actions;

    Map<ShortcutActivator, Intent> shortcuts;

    ValueChanged<bool> onShowFocusHighlight;

    ValueChanged<bool> onShowHoverHighlight;

    ValueChanged<bool> onFocusChange;

    MouseCursor mouseCursor;

    Widget child;


     FocusableActionDetectorCls(Map<Type, Action<Intent>> actions, bool autofocus, Widget child, bool descendantsAreFocusable, bool descendantsAreTraversable, bool enabled, FocusNode focusNode, Unknown key, MouseCursor mouseCursor, ValueChanged<bool> onFocusChange, ValueChanged<bool> onShowFocusHighlight, ValueChanged<bool> onShowHoverHighlight, Map<ShortcutActivator, Intent> shortcuts);

    virtual State<FocusableActionDetector> createState();

private:

};
using FocusableActionDetector = std::shared_ptr<FocusableActionDetectorCls>;

class _FocusableActionDetectorStateCls : public StateCls<FocusableActionDetector> {
public:

    virtual void initState();

    virtual void dispose();

    virtual void didUpdateWidget(FocusableActionDetector oldWidget);

    virtual Widget build(BuildContext context);

private:
    bool _canShowHighlight;

    bool _hovering;

    bool _focused;

    GlobalKey _mouseRegionKey;


    virtual void _updateHighlightMode(FocusHighlightMode mode);

    virtual void _handleFocusHighlightModeChange(FocusHighlightMode mode);

    virtual void _handleMouseEnter(PointerEnterEvent event);

    virtual void _handleMouseExit(PointerExitEvent event);

    virtual void _handleFocusChange(bool focused);

    virtual void _mayTriggerCallback(FocusableActionDetector oldWidget, VoidCallback task);

    virtual bool _canRequestFocus();

};
using _FocusableActionDetectorState = std::shared_ptr<_FocusableActionDetectorStateCls>;

class VoidCallbackIntentCls : public IntentCls {
public:
    VoidCallback callback;


     VoidCallbackIntentCls(VoidCallback callback);
private:

};
using VoidCallbackIntent = std::shared_ptr<VoidCallbackIntentCls>;

class VoidCallbackActionCls : public ActionCls<VoidCallbackIntent> {
public:

    virtual Object invoke(VoidCallbackIntent intent);

private:

};
using VoidCallbackAction = std::shared_ptr<VoidCallbackActionCls>;

class DoNothingIntentCls : public IntentCls {
public:

     DoNothingIntentCls();
private:

    virtual void  _();
};
using DoNothingIntent = std::shared_ptr<DoNothingIntentCls>;

class DoNothingAndStopPropagationIntentCls : public IntentCls {
public:

     DoNothingAndStopPropagationIntentCls();
private:

    virtual void  _();
};
using DoNothingAndStopPropagationIntent = std::shared_ptr<DoNothingAndStopPropagationIntentCls>;

class DoNothingActionCls : public ActionCls<Intent> {
public:

     DoNothingActionCls(bool consumesKey);

    virtual bool consumesKey(Intent intent);

    virtual void invoke(Intent intent);

private:
    bool _consumesKey;


};
using DoNothingAction = std::shared_ptr<DoNothingActionCls>;

class ActivateIntentCls : public IntentCls {
public:

     ActivateIntentCls();
private:

};
using ActivateIntent = std::shared_ptr<ActivateIntentCls>;

class ButtonActivateIntentCls : public IntentCls {
public:

     ButtonActivateIntentCls();
private:

};
using ButtonActivateIntent = std::shared_ptr<ButtonActivateIntentCls>;

class ActivateActionCls : public ActionCls<ActivateIntent> {
public:

private:

};
using ActivateAction = std::shared_ptr<ActivateActionCls>;

class SelectIntentCls : public IntentCls {
public:

     SelectIntentCls();
private:

};
using SelectIntent = std::shared_ptr<SelectIntentCls>;

class SelectActionCls : public ActionCls<SelectIntent> {
public:

private:

};
using SelectAction = std::shared_ptr<SelectActionCls>;

class DismissIntentCls : public IntentCls {
public:

     DismissIntentCls();
private:

};
using DismissIntent = std::shared_ptr<DismissIntentCls>;

class DismissActionCls : public ActionCls<DismissIntent> {
public:

private:

};
using DismissAction = std::shared_ptr<DismissActionCls>;

class PrioritizedIntentsCls : public IntentCls {
public:
    List<Intent> orderedIntents;


     PrioritizedIntentsCls(List<Intent> orderedIntents);

private:

};
using PrioritizedIntents = std::shared_ptr<PrioritizedIntentsCls>;

class PrioritizedActionCls : public ActionCls<PrioritizedIntents> {
public:

    virtual bool isEnabled(PrioritizedIntents intent);

    virtual void invoke(PrioritizedIntents intent);

private:
    Action<dynamic> _selectedAction;

    Intent _selectedIntent;


};
using PrioritizedAction = std::shared_ptr<PrioritizedActionCls>;

template<typename T> class _OverridableActionMixinCls : public ObjectCls {
public:
    bool debugAssertMutuallyRecursive;

    bool debugAssertIsActionEnabledMutuallyRecursive;

    bool debugAssertIsEnabledMutuallyRecursive;

    bool debugAssertConsumeKeyMutuallyRecursive;


    virtual Action<T> defaultAction();
    virtual BuildContext lookupContext();
    virtual Object invokeDefaultAction(BuildContext context, Action<T> fromAction, T intent);
    virtual Action<T> getOverrideAction(bool declareDependency);

    virtual Object invoke(BuildContext context, T intent);

    virtual bool isOverrideActionEnabled(Action<T> overrideAction);

    virtual bool isActionEnabled();

    virtual bool isEnabled(T intent);

    virtual bool consumesKey(T intent);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    virtual void _updateCallingAction(Action<T> value);

    virtual Object _invokeOverride(BuildContext context, T intent, Action<T> overrideAction);

};
template<typename T> using _OverridableActionMixin = std::shared_ptr<_OverridableActionMixinCls<T>>;

template<typename T> class _OverridableActionCls : public ContextActionCls<T> {
public:
    Action<T> defaultAction;

    BuildContext lookupContext;


    virtual Object invokeDefaultAction(BuildContext context, Action<T> fromAction, T intent);

private:

     _OverridableActionCls(Action<T> defaultAction, BuildContext lookupContext);
    virtual ContextAction<T> _makeOverridableAction(BuildContext context);

};
template<typename T> using _OverridableAction = std::shared_ptr<_OverridableActionCls<T>>;

template<typename T> class _OverridableContextActionCls : public ContextActionCls<T> {
public:
    ContextAction<T> defaultAction;

    BuildContext lookupContext;


    virtual Object invokeDefaultAction(BuildContext context, Action<T> fromAction, T intent);

private:

     _OverridableContextActionCls(ContextAction<T> defaultAction, BuildContext lookupContext);
    virtual Object _invokeOverride(BuildContext context, T intent, Action<T> overrideAction);

    virtual ContextAction<T> _makeOverridableAction(BuildContext context);

};
template<typename T> using _OverridableContextAction = std::shared_ptr<_OverridableContextActionCls<T>>;

template<typename T> class _ContextActionToActionAdapterCls : public ActionCls<T> {
public:
    BuildContext invokeContext;

    ContextAction<T> action;


    virtual Action<T> callingAction();

    virtual bool isEnabled(T intent);

    virtual bool isActionEnabled();

    virtual bool consumesKey(T intent);

    virtual void addActionListener(ActionListenerCallback listener);

    virtual void removeActionListener(ActionListenerCallback listener);

    virtual void notifyActionListeners();

    virtual Object invoke(T intent);

private:

     _ContextActionToActionAdapterCls(ContextAction<T> action, BuildContext invokeContext);
    virtual void _updateCallingAction(Action<T> value);

};
template<typename T> using _ContextActionToActionAdapter = std::shared_ptr<_ContextActionToActionAdapterCls<T>>;


#endif