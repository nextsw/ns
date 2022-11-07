#ifndef ACTIONS_H
#define ACTIONS_H
#include <memory>

#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include <flutter/scheduler.hpp>
#include <flutter/services.hpp>
#include "basic.hpp"
#include "focus_manager.hpp"
#include "focus_scope.hpp"
#include "framework.hpp"
#include "media_query.hpp"
#include "shortcuts.hpp"


BuildContext _getParent(BuildContext context);


class Intent {
public:
    static const DoNothingIntent doNothing;


     Intent();

private:

};

class Action<T extends Intent> {
public:

     Action();

    void  overridable(BuildContext context, Action<T> defaultAction);

    Action<T> callingAction();

    Type intentType();

    bool isEnabled(T intent);

    bool isActionEnabled();

    bool consumesKey(T intent);

    Object invoke(T intent);

    void addActionListener(ActionListenerCallback listener);

    void removeActionListener(ActionListenerCallback listener);

    void notifyActionListeners();

private:
    ObserverList<ActionListenerCallback> _listeners;

    Action<T> _currentCallingAction;


    void _updateCallingAction(Action<T> value);

    Action<T> _makeOverridableAction(BuildContext context);

};

class ActionListener : StatefulWidget {
public:
    ActionListenerCallback listener;

    Action<Intent> action;

    Widget child;


     ActionListener(Action<Intent> action, Widget child, Unknown, ActionListenerCallback listener);

    State<ActionListener> createState();

private:

};

class _ActionListenerState : State<ActionListener> {
public:

    void initState();

    void didUpdateWidget(ActionListener oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:

};

class ContextAction<T extends Intent> : Action<T> {
public:

    Object invoke(BuildContext context, T intent);

private:

    ContextAction<T> _makeOverridableAction(BuildContext context);

};

class CallbackAction<T extends Intent> : Action<T> {
public:
    OnInvokeCallback<T> onInvoke;


     CallbackAction(OnInvokeCallback<T> onInvoke);

    Object invoke(T intent);

private:

};

class ActionDispatcher {
public:

     ActionDispatcher();

    Object invokeAction(Action<Intent> action, BuildContext context, Intent intent);

private:

};

class Actions : StatefulWidget {
public:
    ActionDispatcher dispatcher;

    Map<Type, Action<Intent>> actions;

    Widget child;


     Actions(Map<Type, Action<Intent>> actions, Widget child, ActionDispatcher dispatcher, Unknown);

    static VoidCallback handler<T extends Intent>(BuildContext context, T intent);

    static Action<T> find<T extends Intent>(BuildContext context, T intent);

    static Action<T> maybeFind<T extends Intent>(BuildContext context, T intent);

    static ActionDispatcher of(BuildContext context);

    static Object invoke<T extends Intent>(BuildContext context, T intent);

    static Object maybeInvoke<T extends Intent>(BuildContext context, T intent);

    State<Actions> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    static bool _visitActionsAncestors(BuildContext context, FunctionType visitor);

    static ActionDispatcher _findDispatcher(BuildContext context);

    static Action<T> _maybeFindWithoutDependingOn<T extends Intent>(BuildContext context, T intent);

    static Action<T> _castAction<T extends Intent>(_ActionsMarker actionsMarker, T intent);

};

class _ActionsState : State<Actions> {
public:
    Set<Action<Intent>> listenedActions;

    Object rebuildKey;


    void initState();

    void didUpdateWidget(Actions oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:

    void _handleActionChanged(Action<Intent> action);

    void _updateActionListeners();

};

class _ActionsMarker : InheritedWidget {
public:
    ActionDispatcher dispatcher;

    Map<Type, Action<Intent>> actions;

    Object rebuildKey;


    bool updateShouldNotify(_ActionsMarker oldWidget);

private:

     _ActionsMarker(Map<Type, Action<Intent>> actions, Unknown, ActionDispatcher dispatcher, Object rebuildKey);

};

class FocusableActionDetector : StatefulWidget {
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


     FocusableActionDetector(Map<Type, Action<Intent>> actions, bool autofocus, Widget child, bool descendantsAreFocusable, bool descendantsAreTraversable, bool enabled, FocusNode focusNode, Unknown, MouseCursor mouseCursor, ValueChanged<bool> onFocusChange, ValueChanged<bool> onShowFocusHighlight, ValueChanged<bool> onShowHoverHighlight, Map<ShortcutActivator, Intent> shortcuts);

    State<FocusableActionDetector> createState();

private:

};

class _FocusableActionDetectorState : State<FocusableActionDetector> {
public:

    void initState();

    void dispose();

    void didUpdateWidget(FocusableActionDetector oldWidget);

    Widget build(BuildContext context);

private:
    bool _canShowHighlight;

    bool _hovering;

    bool _focused;

    GlobalKey _mouseRegionKey;


    void _updateHighlightMode(FocusHighlightMode mode);

    void _handleFocusHighlightModeChange(FocusHighlightMode mode);

    void _handleMouseEnter(PointerEnterEvent event);

    void _handleMouseExit(PointerExitEvent event);

    void _handleFocusChange(bool focused);

    void _mayTriggerCallback(FocusableActionDetector oldWidget, VoidCallback task);

    bool _canRequestFocus();

};

class VoidCallbackIntent : Intent {
public:
    VoidCallback callback;


     VoidCallbackIntent(VoidCallback callback);

private:

};

class VoidCallbackAction : Action<VoidCallbackIntent> {
public:

    Object invoke(VoidCallbackIntent intent);

private:

};

class DoNothingIntent : Intent {
public:

     DoNothingIntent();

private:

    void  _();

};

class DoNothingAndStopPropagationIntent : Intent {
public:

     DoNothingAndStopPropagationIntent();

private:

    void  _();

};

class DoNothingAction : Action<Intent> {
public:

     DoNothingAction(bool consumesKey);

    bool consumesKey(Intent intent);

    void invoke(Intent intent);

private:
    bool _consumesKey;


};

class ActivateIntent : Intent {
public:

     ActivateIntent();

private:

};

class ButtonActivateIntent : Intent {
public:

     ButtonActivateIntent();

private:

};

class ActivateAction : Action<ActivateIntent> {
public:

private:

};

class SelectIntent : Intent {
public:

     SelectIntent();

private:

};

class SelectAction : Action<SelectIntent> {
public:

private:

};

class DismissIntent : Intent {
public:

     DismissIntent();

private:

};

class DismissAction : Action<DismissIntent> {
public:

private:

};

class PrioritizedIntents : Intent {
public:
    List<Intent> orderedIntents;


     PrioritizedIntents(List<Intent> orderedIntents);

private:

};

class PrioritizedAction : Action<PrioritizedIntents> {
public:

    bool isEnabled(PrioritizedIntents intent);

    void invoke(PrioritizedIntents intent);

private:
    Action<dynamic> _selectedAction;

    Intent _selectedIntent;


};

class _OverridableActionMixin<T extends Intent> {
public:
    bool debugAssertMutuallyRecursive;

    bool debugAssertIsActionEnabledMutuallyRecursive;

    bool debugAssertIsEnabledMutuallyRecursive;

    bool debugAssertConsumeKeyMutuallyRecursive;


    Action<T> defaultAction();

    BuildContext lookupContext();

    Object invokeDefaultAction(BuildContext context, Action<T> fromAction, T intent);

    Action<T> getOverrideAction(bool declareDependency);

    Object invoke(BuildContext context, T intent);

    bool isOverrideActionEnabled(Action<T> overrideAction);

    bool isActionEnabled();

    bool isEnabled(T intent);

    bool consumesKey(T intent);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    void _updateCallingAction(Action<T> value);

    Object _invokeOverride(BuildContext context, T intent, Action<T> overrideAction);

};

class _OverridableAction<T extends Intent> : ContextAction<T> {
public:
    Action<T> defaultAction;

    BuildContext lookupContext;


    Object invokeDefaultAction(BuildContext context, Action<T> fromAction, T intent);

private:

     _OverridableAction(Action<T> defaultAction, BuildContext lookupContext);

    ContextAction<T> _makeOverridableAction(BuildContext context);

};

class _OverridableContextAction<T extends Intent> : ContextAction<T> {
public:
    ContextAction<T> defaultAction;

    BuildContext lookupContext;


    Object invokeDefaultAction(BuildContext context, Action<T> fromAction, T intent);

private:

     _OverridableContextAction(ContextAction<T> defaultAction, BuildContext lookupContext);

    Object _invokeOverride(BuildContext context, T intent, Action<T> overrideAction);

    ContextAction<T> _makeOverridableAction(BuildContext context);

};

class _ContextActionToActionAdapter<T extends Intent> : Action<T> {
public:
    BuildContext invokeContext;

    ContextAction<T> action;


    Action<T> callingAction();

    bool isEnabled(T intent);

    bool isActionEnabled();

    bool consumesKey(T intent);

    void addActionListener(ActionListenerCallback listener);

    void removeActionListener(ActionListenerCallback listener);

    void notifyActionListeners();

    Object invoke(T intent);

private:

     _ContextActionToActionAdapter(ContextAction<T> action, BuildContext invokeContext);

    void _updateCallingAction(Action<T> value);

};

#endif