#include "actions.hpp"
BuildContext _getParent(BuildContext context) {
    BuildContext parent;
    context.visitAncestorElements();
    return parent;
}

void Action::overridable(BuildContext context, Action<T> defaultAction) {
    return defaultAction._makeOverridableAction(context);
}

Action<T> Action::callingAction() {
    return _currentCallingAction;
}

Type Action::intentType() {
    return T;
}

bool Action::isEnabled(T intent) {
    return isActionEnabled;
}

bool Action::isActionEnabled() {
    return true;
}

bool Action::consumesKey(T intent) {
    return true;
}

void Action::addActionListener(ActionListenerCallback listener) {
    return _listeners.add(listener);
}

void Action::removeActionListener(ActionListenerCallback listener) {
    return _listeners.remove(listener);
}

void Action::notifyActionListeners() {
    if (_listeners.isEmpty) {
        return;
    }
    List<ActionListenerCallback> localListeners = <ActionListenerCallback>of(_listeners);
    for (ActionListenerCallback listener : localListeners) {
        InformationCollector collector;
        assert(());
        ;
    }
}

void Action::_updateCallingAction(Action<T> value) {
    _currentCallingAction = value;
}

Action<T> Action::_makeOverridableAction(BuildContext context) {
    return <T>_OverridableAction(this, context);
}

ActionListener::ActionListener(Action<Intent> action, Widget child, Unknown, ActionListenerCallback listener) {
    {
        assert(listener != nullptr);
        assert(action != nullptr);
        assert(child != nullptr);
    }
}

State<ActionListener> ActionListener::createState() {
    return _ActionListenerState();
}

void _ActionListenerState::initState() {
    super.initState();
    widget.action.addActionListener(widget.listener);
}

void _ActionListenerState::didUpdateWidget(ActionListener oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (oldWidget.action == widget.action && oldWidget.listener == widget.listener) {
        return;
    }
    oldWidget.action.removeActionListener(oldWidget.listener);
    widget.action.addActionListener(widget.listener);
}

void _ActionListenerState::dispose() {
    widget.action.removeActionListener(widget.listener);
    super.dispose();
}

Widget _ActionListenerState::build(BuildContext context) {
    return widget.child;
}

ContextAction<T> ContextAction::_makeOverridableAction(BuildContext context) {
    return <T>_OverridableContextAction(this, context);
}

CallbackAction::CallbackAction(OnInvokeCallback<T> onInvoke) {
    {
        assert(onInvoke != nullptr);
    }
}

Object CallbackAction::invoke(T intent) {
    return onInvoke(intent);
}

Object ActionDispatcher::invokeAction(Action<Intent> action, BuildContext context, Intent intent) {
    assert(action != nullptr);
    assert(intent != nullptr);
    assert(action.isEnabled(intent), "Action must be enabled when calling invokeAction");
    if (action is ContextAction) {
        context = primaryFocus?.context;
        return action.invoke(intent, context);
    } else {
        return action.invoke(intent);
    }
}

Actions::Actions(Map<Type, Action<Intent>> actions, Widget child, ActionDispatcher dispatcher, Unknown) {
    {
        assert(actions != nullptr);
        assert(child != nullptr);
    }
}

VoidCallback Actions::handler<T extends Intent>(BuildContext context, T intent) {
    Action<T> action = Actions.<T>maybeFind(context);
    if (action != nullptr && action.isEnabled(intent)) {
        return ;
    }
    return nullptr;
}

Action<T> Actions::find<T extends Intent>(BuildContext context, T intent) {
    Action<T> action = maybeFind(contextintent);
    assert(());
    return action!;
}

Action<T> Actions::maybeFind<T extends Intent>(BuildContext context, T intent) {
    Action<T> action;
    Type type = intent?.runtimeType ?? T;
    assert(type != Intent, "The type passed to "find" resolved to "Intent": either a non-Intent generic type argument or an example intent derived from Intent must be specified. Intent may be used as the generic type as long as the optional "intent" argument is passed.");
    _visitActionsAncestors(context, );
    return action;
}

ActionDispatcher Actions::of(BuildContext context) {
    assert(context != nullptr);
    _ActionsMarker marker = context.<_ActionsMarker>dependOnInheritedWidgetOfExactType();
    return marker?.dispatcher ?? _findDispatcher(context);
}

Object Actions::invoke<T extends Intent>(BuildContext context, T intent) {
    assert(intent != nullptr);
    assert(context != nullptr);
    Object returnValue;
    bool actionFound = _visitActionsAncestors(context, );
    assert(());
    return returnValue;
}

Object Actions::maybeInvoke<T extends Intent>(BuildContext context, T intent) {
    assert(intent != nullptr);
    assert(context != nullptr);
    Object returnValue;
    _visitActionsAncestors(context, );
    return returnValue;
}

State<Actions> Actions::createState() {
    return _ActionsState();
}

void Actions::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<ActionDispatcher>DiagnosticsProperty("dispatcher", dispatcher));
    properties.add(<Map<Type, Action<Intent>>>DiagnosticsProperty("actions", actions));
}

bool Actions::_visitActionsAncestors(BuildContext context, FunctionType visitor) {
    InheritedElement actionsElement = context.<_ActionsMarker>getElementForInheritedWidgetOfExactType();
    while (actionsElement != nullptr) {
        if (visitor(actionsElement) == true) {
                        break;
        }
        BuildContext parent = _getParent(actionsElement);
        actionsElement = parent.<_ActionsMarker>getElementForInheritedWidgetOfExactType();
    }
    return actionsElement != nullptr;
}

ActionDispatcher Actions::_findDispatcher(BuildContext context) {
    ActionDispatcher dispatcher;
    _visitActionsAncestors(context, );
    return dispatcher ?? const ActionDispatcher();
}

Action<T> Actions::_maybeFindWithoutDependingOn<T extends Intent>(BuildContext context, T intent) {
    Action<T> action;
    Type type = intent?.runtimeType ?? T;
    assert(type != Intent, "The type passed to "find" resolved to "Intent": either a non-Intent generic type argument or an example intent derived from Intent must be specified. Intent may be used as the generic type as long as the optional "intent" argument is passed.");
    _visitActionsAncestors(context, );
    return action;
}

Action<T> Actions::_castAction<T extends Intent>(_ActionsMarker actionsMarker, T intent) {
    Action<Intent> mappedAction = actionsMarker.actions[intent?.runtimeType ?? T];
    if (mappedAction is Action<T>) {
        return mappedAction;
    } else {
        assert(false, "$T cannot be handled by an Action of runtime type ${mappedAction.runtimeType}.");
        return nullptr;
    }
}

void _ActionsState::initState() {
    super.initState();
    _updateActionListeners();
}

void _ActionsState::didUpdateWidget(Actions oldWidget) {
    super.didUpdateWidget(oldWidget);
    _updateActionListeners();
}

void _ActionsState::dispose() {
    super.dispose();
    for (Action<Intent> action : listenedActions!) {
        action.removeActionListener(_handleActionChanged);
    }
    listenedActions = nullptr;
}

Widget _ActionsState::build(BuildContext context) {
    return _ActionsMarker(widget.actions, widget.dispatcher, rebuildKey, widget.child);
}

void _ActionsState::_handleActionChanged(Action<Intent> action) {
    setState();
}

void _ActionsState::_updateActionListeners() {
    Set<Action<Intent>> widgetActions = widget.actions.values.toSet();
    Set<Action<Intent>> removedActions = listenedActions!.difference(widgetActions);
    Set<Action<Intent>> addedActions = widgetActions.difference(listenedActions!);
    for (Action<Intent> action : removedActions) {
        action.removeActionListener(_handleActionChanged);
    }
    for (Action<Intent> action : addedActions) {
        action.addActionListener(_handleActionChanged);
    }
    listenedActions = widgetActions;
}

bool _ActionsMarker::updateShouldNotify(_ActionsMarker oldWidget) {
    return rebuildKey != oldWidget.rebuildKey || oldWidget.dispatcher != dispatcher || !<Type, Action<Intent>>mapEquals(oldWidget.actions, actions);
}

_ActionsMarker::_ActionsMarker(Map<Type, Action<Intent>> actions, Unknown, ActionDispatcher dispatcher, Object rebuildKey) {
    {
        assert(child != nullptr);
        assert(actions != nullptr);
    }
}

FocusableActionDetector::FocusableActionDetector(Map<Type, Action<Intent>> actions, bool autofocus, Widget child, bool descendantsAreFocusable, bool descendantsAreTraversable, bool enabled, FocusNode focusNode, Unknown, MouseCursor mouseCursor, ValueChanged<bool> onFocusChange, ValueChanged<bool> onShowFocusHighlight, ValueChanged<bool> onShowHoverHighlight, Map<ShortcutActivator, Intent> shortcuts) {
    {
        assert(enabled != nullptr);
        assert(autofocus != nullptr);
        assert(mouseCursor != nullptr);
        assert(child != nullptr);
    }
}

State<FocusableActionDetector> FocusableActionDetector::createState() {
    return _FocusableActionDetectorState();
}

void _FocusableActionDetectorState::initState() {
    super.initState();
    SchedulerBinding.instance.addPostFrameCallback();
    FocusManager.instance.addHighlightModeListener(_handleFocusHighlightModeChange);
}

void _FocusableActionDetectorState::dispose() {
    FocusManager.instance.removeHighlightModeListener(_handleFocusHighlightModeChange);
    super.dispose();
}

void _FocusableActionDetectorState::didUpdateWidget(FocusableActionDetector oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (widget.enabled != oldWidget.enabled) {
        SchedulerBinding.instance.addPostFrameCallback();
    }
}

Widget _FocusableActionDetectorState::build(BuildContext context) {
    Widget child = MouseRegion(_mouseRegionKey, _handleMouseEnter, _handleMouseExit, widget.mouseCursor, Focus(widget.focusNode, widget.autofocus, widget.descendantsAreFocusable, widget.descendantsAreTraversable, _canRequestFocus, _handleFocusChange, widget.child));
    if (widget.enabled && widget.actions != nullptr && widget.actions!.isNotEmpty) {
        child = Actions(widget.actions!, child);
    }
    if (widget.enabled && widget.shortcuts != nullptr && widget.shortcuts!.isNotEmpty) {
        child = Shortcuts(widget.shortcuts!, child);
    }
    return child;
}

void _FocusableActionDetectorState::_updateHighlightMode(FocusHighlightMode mode) {
    _mayTriggerCallback();
}

void _FocusableActionDetectorState::_handleFocusHighlightModeChange(FocusHighlightMode mode) {
    if (!mounted) {
        return;
    }
    _updateHighlightMode(mode);
}

void _FocusableActionDetectorState::_handleMouseEnter(PointerEnterEvent event) {
    if (!_hovering) {
        _mayTriggerCallback();
    }
}

void _FocusableActionDetectorState::_handleMouseExit(PointerExitEvent event) {
    if (_hovering) {
        _mayTriggerCallback();
    }
}

void _FocusableActionDetectorState::_handleFocusChange(bool focused) {
    if (_focused != focused) {
        _mayTriggerCallback();
        widget.onFocusChange?.call(_focused);
    }
}

void _FocusableActionDetectorState::_mayTriggerCallback(FocusableActionDetector oldWidget, VoidCallback task) {
    ;
    ;
    ;
    assert(SchedulerBinding.instance.schedulerPhase != SchedulerPhase.persistentCallbacks);
    FocusableActionDetector oldTarget = oldWidget ?? widget;
    bool didShowHoverHighlight = shouldShowHoverHighlight(oldTarget);
    bool didShowFocusHighlight = shouldShowFocusHighlight(oldTarget);
    if (task != nullptr) {
        task();
    }
    bool doShowHoverHighlight = shouldShowHoverHighlight(widget);
    bool doShowFocusHighlight = shouldShowFocusHighlight(widget);
    if (didShowFocusHighlight != doShowFocusHighlight) {
        widget.onShowFocusHighlight?.call(doShowFocusHighlight);
    }
    if (didShowHoverHighlight != doShowHoverHighlight) {
        widget.onShowHoverHighlight?.call(doShowHoverHighlight);
    }
}

bool _FocusableActionDetectorState::_canRequestFocus() {
    NavigationMode mode = MediaQuery.maybeOf(context)?.navigationMode ?? NavigationMode.traditional;
    ;
}

Object VoidCallbackAction::invoke(VoidCallbackIntent intent) {
    intent.callback();
    return nullptr;
}

DoNothingAction::DoNothingAction(bool consumesKey) {
    {
        _consumesKey = consumesKey;
    }
}

bool DoNothingAction::consumesKey(Intent intent) {
    return _consumesKey;
}

void DoNothingAction::invoke(Intent intent) {
}

PrioritizedIntents::PrioritizedIntents(List<Intent> orderedIntents) {
    {
        assert(orderedIntents != nullptr);
    }
}

bool PrioritizedAction::isEnabled(PrioritizedIntents intent) {
    FocusNode focus = primaryFocus;
    if (focus == nullptr || focus.context == nullptr) {
        return false;
    }
    for (Intent candidateIntent : intent.orderedIntents) {
        Action<Intent> candidateAction = Actions.<Intent>maybeFind(focus.context!candidateIntent);
        if (candidateAction != nullptr && candidateAction.isEnabled(candidateIntent)) {
            _selectedAction = candidateAction;
            _selectedIntent = candidateIntent;
            return true;
        }
    }
    return false;
}

void PrioritizedAction::invoke(PrioritizedIntents intent) {
    assert(_selectedAction != nullptr);
    assert(_selectedIntent != nullptr);
    _selectedAction.invoke(_selectedIntent);
}

Action<T> _OverridableActionMixin::getOverrideAction(bool declareDependency) {
    Action<T> override = declareDependency? Actions.maybeFind(lookupContext) : Actions._maybeFindWithoutDependingOn(lookupContext);
    assert(!identical(override, this));
    return override;
}

Object _OverridableActionMixin::invoke(BuildContext context, T intent) {
    Action<T> overrideAction = getOverrideAction();
    Object returnValue = overrideAction == nullptr? invokeDefaultAction(intent, callingAction, context) : _invokeOverride(overrideAction, intent, context);
    return returnValue;
}

bool _OverridableActionMixin::isOverrideActionEnabled(Action<T> overrideAction) {
    assert(!debugAssertIsActionEnabledMutuallyRecursive);
    assert(());
    overrideAction._updateCallingAction(defaultAction);
    bool isOverrideEnabled = overrideAction.isActionEnabled;
    overrideAction._updateCallingAction(nullptr);
    assert(());
    return isOverrideEnabled;
}

bool _OverridableActionMixin::isActionEnabled() {
    Action<T> overrideAction = getOverrideAction(true);
    bool returnValue = overrideAction != nullptr? isOverrideActionEnabled(overrideAction) : defaultAction.isActionEnabled;
    return returnValue;
}

bool _OverridableActionMixin::isEnabled(T intent) {
    assert(!debugAssertIsEnabledMutuallyRecursive);
    assert(());
    Action<T> overrideAction = getOverrideAction();
    overrideAction?._updateCallingAction(defaultAction);
    bool returnValue = (overrideAction ?? defaultAction).isEnabled(intent);
    overrideAction?._updateCallingAction(nullptr);
    assert(());
    return returnValue;
}

bool _OverridableActionMixin::consumesKey(T intent) {
    assert(!debugAssertConsumeKeyMutuallyRecursive);
    assert(());
    Action<T> overrideAction = getOverrideAction();
    overrideAction?._updateCallingAction(defaultAction);
    bool isEnabled = (overrideAction ?? defaultAction).consumesKey(intent);
    overrideAction?._updateCallingAction(nullptr);
    assert(());
    return isEnabled;
}

void _OverridableActionMixin::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Action<T>>DiagnosticsProperty("defaultAction", defaultAction));
}

void _OverridableActionMixin::_updateCallingAction(Action<T> value) {
    super._updateCallingAction(value);
    defaultAction._updateCallingAction(value);
}

Object _OverridableActionMixin::_invokeOverride(BuildContext context, T intent, Action<T> overrideAction) {
    assert(!debugAssertMutuallyRecursive);
    assert(());
    overrideAction._updateCallingAction(defaultAction);
    Object returnValue = overrideAction is ContextAction<T>? overrideAction.invoke(intent, context) : overrideAction.invoke(intent);
    overrideAction._updateCallingAction(nullptr);
    assert(());
    return returnValue;
}

Object _OverridableAction::invokeDefaultAction(BuildContext context, Action<T> fromAction, T intent) {
    if (fromAction == nullptr) {
        return defaultAction.invoke(intent);
    } else {
        Object returnValue = defaultAction.invoke(intent);
        return returnValue;
    }
}

ContextAction<T> _OverridableAction::_makeOverridableAction(BuildContext context) {
    return <T>_OverridableAction(defaultAction, context);
}

Object _OverridableContextAction::invokeDefaultAction(BuildContext context, Action<T> fromAction, T intent) {
    if (fromAction == nullptr) {
        return defaultAction.invoke(intent, context);
    } else {
        Object returnValue = defaultAction.invoke(intent, context);
        return returnValue;
    }
}

Object _OverridableContextAction::_invokeOverride(BuildContext context, T intent, Action<T> overrideAction) {
    assert(context != nullptr);
    assert(!debugAssertMutuallyRecursive);
    assert(());
    Action<T> wrappedDefault = <T>_ContextActionToActionAdapter(context!, defaultAction);
    overrideAction._updateCallingAction(wrappedDefault);
    Object returnValue = overrideAction is ContextAction<T>? overrideAction.invoke(intent, context) : overrideAction.invoke(intent);
    overrideAction._updateCallingAction(nullptr);
    assert(());
    return returnValue;
}

ContextAction<T> _OverridableContextAction::_makeOverridableAction(BuildContext context) {
    return <T>_OverridableContextAction(defaultAction, context);
}

Action<T> _ContextActionToActionAdapter::callingAction() {
    return action.callingAction;
}

bool _ContextActionToActionAdapter::isEnabled(T intent) {
    return action.isEnabled(intent);
}

bool _ContextActionToActionAdapter::isActionEnabled() {
    return action.isActionEnabled;
}

bool _ContextActionToActionAdapter::consumesKey(T intent) {
    return action.consumesKey(intent);
}

void _ContextActionToActionAdapter::addActionListener(ActionListenerCallback listener) {
    super.addActionListener(listener);
    action.addActionListener(listener);
}

void _ContextActionToActionAdapter::removeActionListener(ActionListenerCallback listener) {
    super.removeActionListener(listener);
    action.removeActionListener(listener);
}

void _ContextActionToActionAdapter::notifyActionListeners() {
    return action.notifyActionListeners();
}

Object _ContextActionToActionAdapter::invoke(T intent) {
    return action.invoke(intent, invokeContext);
}

void _ContextActionToActionAdapter::_updateCallingAction(Action<T> value) {
    action._updateCallingAction(value);
}
