#include "actions.hpp"
BuildContext _getParent(BuildContext context) {
    BuildContext parent;
    context->visitAncestorElements([=] (Element ancestor) {
        parent = ancestor;
        return false;
    });
    return parent;
}

template<typename T>
void ActionCls<T>::overridable(BuildContext context, Action<T> defaultAction) {
    return defaultAction->_makeOverridableAction(context);
}

template<typename T>
Action<T> ActionCls<T>::callingAction() {
    return _currentCallingAction;
}

template<typename T>
Type ActionCls<T>::intentType() {
    return T;
}

template<typename T>
bool ActionCls<T>::isEnabled(T intent) {
    return isActionEnabled();
}

template<typename T>
bool ActionCls<T>::isActionEnabled() {
    return true;
}

template<typename T>
bool ActionCls<T>::consumesKey(T intent) {
    return true;
}

template<typename T>
void ActionCls<T>::addActionListener(ActionListenerCallback listener) {
    return _listeners->add(listener);
}

template<typename T>
void ActionCls<T>::removeActionListener(ActionListenerCallback listener) {
    return _listeners->remove(listener);
}

template<typename T>
void ActionCls<T>::notifyActionListeners() {
    if (_listeners->isEmpty()) {
        return;
    }
    List<ActionListenerCallback> localListeners = <ActionListenerCallback>of(_listeners);
    for (ActionListenerCallback listener : localListeners) {
        InformationCollector collector;
        assert([=] () {
            collector = [=] () {
                makeList(ArrayItem);
            };
            return true;
        }());
        try {
            if (_listeners->contains(listener)) {
                listener(this);
            }
        } catch (Unknown exception) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("widgets library"), make<ErrorDescriptionCls>(__s("while dispatching notifications for $runtimeType")), collector));
        };
    }
}

template<typename T>
void ActionCls<T>::_updateCallingAction(Action<T> value) {
    _currentCallingAction = value;
}

template<typename T>
Action<T> ActionCls<T>::_makeOverridableAction(BuildContext context) {
    return <T>make<_OverridableActionCls>(this, context);
}

ActionListenerCls::ActionListenerCls(Action<Intent> action, Widget child, Key key, ActionListenerCallback listener) {
    {
        assert(listener != nullptr);
        assert(action != nullptr);
        assert(child != nullptr);
    }
}

State<ActionListener> ActionListenerCls::createState() {
    return make<_ActionListenerStateCls>();
}

void _ActionListenerStateCls::initState() {
    super->initState();
    widget()->action->addActionListener(widget()->listener);
}

void _ActionListenerStateCls::didUpdateWidget(ActionListener oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (oldWidget->action == widget()->action && oldWidget->listener == widget()->listener) {
        return;
    }
    oldWidget->action->removeActionListener(oldWidget->listener);
    widget()->action->addActionListener(widget()->listener);
}

void _ActionListenerStateCls::dispose() {
    widget()->action->removeActionListener(widget()->listener);
    super->dispose();
}

Widget _ActionListenerStateCls::build(BuildContext context) {
    return widget()->child;
}

template<typename T>
ContextAction<T> ContextActionCls<T>::_makeOverridableAction(BuildContext context) {
    return <T>make<_OverridableContextActionCls>(this, context);
}

template<typename T>
CallbackActionCls<T>::CallbackActionCls(OnInvokeCallback<T> onInvoke) {
    {
        assert(onInvoke != nullptr);
    }
}

template<typename T>
Object CallbackActionCls<T>::invoke(T intent) {
    return onInvoke(intent);
}

Object ActionDispatcherCls::invokeAction(Action<Intent> action, Intent intent, BuildContext context) {
    assert(action != nullptr);
    assert(intent != nullptr);
    assert(action->isEnabled(intent), __s("Action must be enabled when calling invokeAction"));
    if (is<ContextAction>(action)) {
        context |= primaryFocus?->context;
        return as<ContextActionCls>(action)->invoke(intent, context);
    } else {
        return action->invoke(intent);
    }
}

ActionsCls::ActionsCls(Map<Type, Action<Intent>> actions, Widget child, ActionDispatcher dispatcher, Key key) {
    {
        assert(actions != nullptr);
        assert(child != nullptr);
    }
}

template<typename T>
VoidCallback ActionsCls::handler(BuildContext context, T intent) {
    Action<T> action = ActionsCls-><T>maybeFind(context);
    if (action != nullptr && action->isEnabled(intent)) {
        return [=] () {
            if (action->isEnabled(intent)) {
                ActionsCls->of(context)->invokeAction(action, intent, context);
            }
        };
    }
    return nullptr;
}

template<typename T>
Action<T> ActionsCls::find(BuildContext context, T intent) {
    Action<T> action = maybeFind(context, intent);
    assert([=] () {
        if (action == nullptr) {
            Type type = intent?->runtimeType | T;
            throw make<FlutterErrorCls>(__s("Unable to find an action for a $type in an $Actions widget in the given context.\n$Actions.find() was called on a context that doesn't contain an $Actions widget with a mapping for the given intent type.\nThe context used was:\n  $context\nThe intent type requested was:\n  $type"));
        }
        return true;
    }());
    return action!;
}

template<typename T>
Action<T> ActionsCls::maybeFind(BuildContext context, T intent) {
    Action<T> action;
    Type type = intent?->runtimeType | T;
    assert(type != IntentCls, __s("The type passed to "find" resolved to "Intent": either a non-Intent generic type argument or an example intent derived from Intent must be specified. Intent may be used as the generic type as long as the optional "intent" argument is passed."));
    _visitActionsAncestors(context, [=] (InheritedElement element) {
        _ActionsMarker actions = as<_ActionsMarker>(element->widget);
        Action<T> result = _castAction(actions, intent);
        if (result != nullptr) {
            context->dependOnInheritedElement(element);
            action = result;
            return true;
        }
        return false;
    });
    return action;
}

ActionDispatcher ActionsCls::of(BuildContext context) {
    assert(context != nullptr);
    _ActionsMarker marker = context-><_ActionsMarker>dependOnInheritedWidgetOfExactType();
    return marker?->dispatcher | _findDispatcher(context);
}

template<typename T>
Object ActionsCls::invoke(BuildContext context, T intent) {
    assert(intent != nullptr);
    assert(context != nullptr);
    Object returnValue;
    bool actionFound = _visitActionsAncestors(context, [=] (InheritedElement element) {
    _ActionsMarker actions = as<_ActionsMarker>(element->widget);
    Action<T> result = _castAction(actions, intent);
    if (result != nullptr && result->isEnabled(intent)) {
        returnValue = _findDispatcher(element)->invokeAction(result, intent, context);
    }
    return result != nullptr;
});
    assert([=] () {
        if (!actionFound) {
            throw make<FlutterErrorCls>(__s("Unable to find an action for an Intent with type ${intent.runtimeType} in an $Actions widget in the given context.\n$Actions.invoke() was unable to find an $Actions widget that contained a mapping for the given intent, or the intent type isn't the same as the type argument to invoke (which is $T - try supplying a type argument to invoke if one was not given)\nThe context used was:\n  $context\nThe intent type requested was:\n  ${intent.runtimeType}"));
        }
        return true;
    }());
    return returnValue;
}

template<typename T>
Object ActionsCls::maybeInvoke(BuildContext context, T intent) {
    assert(intent != nullptr);
    assert(context != nullptr);
    Object returnValue;
    _visitActionsAncestors(context, [=] (InheritedElement element) {
        _ActionsMarker actions = as<_ActionsMarker>(element->widget);
        Action<T> result = _castAction(actions, intent);
        if (result != nullptr && result->isEnabled(intent)) {
            returnValue = _findDispatcher(element)->invokeAction(result, intent, context);
        }
        return result != nullptr;
    });
    return returnValue;
}

State<Actions> ActionsCls::createState() {
    return make<_ActionsStateCls>();
}

void ActionsCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<ActionDispatcher>make<DiagnosticsPropertyCls>(__s("dispatcher"), dispatcher));
    properties->add(<Map<Type, Action<Intent>>>make<DiagnosticsPropertyCls>(__s("actions"), actions));
}

bool ActionsCls::_visitActionsAncestors(BuildContext context, std::function<bool(InheritedElement element)> visitor) {
    InheritedElement actionsElement = context-><_ActionsMarker>getElementForInheritedWidgetOfExactType();
    while (actionsElement != nullptr) {
        if (visitor(actionsElement) == true) {
            break;
        }
        BuildContext parent = _getParent(actionsElement);
        actionsElement = parent-><_ActionsMarker>getElementForInheritedWidgetOfExactType();
    }
    return actionsElement != nullptr;
}

ActionDispatcher ActionsCls::_findDispatcher(BuildContext context) {
    ActionDispatcher dispatcher;
    _visitActionsAncestors(context, [=] (InheritedElement element) {
        ActionDispatcher found = (as<_ActionsMarker>(element->widget))->dispatcher;
        if (found != nullptr) {
            dispatcher = found;
            return true;
        }
        return false;
    });
    return dispatcher | make<ActionDispatcherCls>();
}

template<typename T>
Action<T> ActionsCls::_maybeFindWithoutDependingOn(BuildContext context, T intent) {
    Action<T> action;
    Type type = intent?->runtimeType | T;
    assert(type != IntentCls, __s("The type passed to "find" resolved to "Intent": either a non-Intent generic type argument or an example intent derived from Intent must be specified. Intent may be used as the generic type as long as the optional "intent" argument is passed."));
    _visitActionsAncestors(context, [=] (InheritedElement element) {
        _ActionsMarker actions = as<_ActionsMarker>(element->widget);
        Action<T> result = _castAction(actions, intent);
        if (result != nullptr) {
            action = result;
            return true;
        }
        return false;
    });
    return action;
}

template<typename T>
Action<T> ActionsCls::_castAction(_ActionsMarker actionsMarker, T intent) {
    Action<Intent> mappedAction = actionsMarker->actions[intent?->runtimeType | T];
    if (is<Action<T>>(mappedAction)) {
        return as<ActionCls>(mappedAction);
    } else {
        assert(false, __s("$T cannot be handled by an Action of runtime type ${mappedAction.runtimeType}."));
        return nullptr;
    }
}

void _ActionsStateCls::initState() {
    super->initState();
    _updateActionListeners();
}

void _ActionsStateCls::didUpdateWidget(Actions oldWidget) {
    super->didUpdateWidget(oldWidget);
    _updateActionListeners();
}

void _ActionsStateCls::dispose() {
    super->dispose();
    for (Action<Intent> action : listenedActions!) {
        action->removeActionListener(_handleActionChanged);
    }
    listenedActions = nullptr;
}

Widget _ActionsStateCls::build(BuildContext context) {
    return make<_ActionsMarkerCls>(widget()->actions, widget()->dispatcher, rebuildKey, widget()->child);
}

void _ActionsStateCls::_handleActionChanged(Action<Intent> action) {
    setState([=] () {
        rebuildKey = make<ObjectCls>();
    });
}

void _ActionsStateCls::_updateActionListeners() {
    Set<Action<Intent>> widgetActions = widget()->actions->values->toSet();
    Set<Action<Intent>> removedActions = listenedActions!->difference(widgetActions);
    Set<Action<Intent>> addedActions = widgetActions->difference(listenedActions!);
    for (Action<Intent> action : removedActions) {
        action->removeActionListener(_handleActionChanged);
    }
    for (Action<Intent> action : addedActions) {
        action->addActionListener(_handleActionChanged);
    }
    listenedActions = widgetActions;
}

bool _ActionsMarkerCls::updateShouldNotify(_ActionsMarker oldWidget) {
    return rebuildKey != oldWidget->rebuildKey || oldWidget->dispatcher != dispatcher || !<Type, Action<Intent>>mapEquals(oldWidget->actions, actions);
}

_ActionsMarkerCls::_ActionsMarkerCls(Map<Type, Action<Intent>> actions, Widget child, ActionDispatcher dispatcher, Object rebuildKey) {
    {
        assert(child != nullptr);
        assert(actions != nullptr);
    }
}

FocusableActionDetectorCls::FocusableActionDetectorCls(Map<Type, Action<Intent>> actions, bool autofocus, Widget child, bool descendantsAreFocusable, bool descendantsAreTraversable, bool enabled, FocusNode focusNode, Key key, MouseCursor mouseCursor, ValueChanged<bool> onFocusChange, ValueChanged<bool> onShowFocusHighlight, ValueChanged<bool> onShowHoverHighlight, Map<ShortcutActivator, Intent> shortcuts) {
    {
        assert(enabled != nullptr);
        assert(autofocus != nullptr);
        assert(mouseCursor != nullptr);
        assert(child != nullptr);
    }
}

State<FocusableActionDetector> FocusableActionDetectorCls::createState() {
    return make<_FocusableActionDetectorStateCls>();
}

void _FocusableActionDetectorStateCls::initState() {
    super->initState();
    SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration duration) {
        _updateHighlightMode(FocusManagerCls::instance->highlightMode);
    });
    FocusManagerCls::instance->addHighlightModeListener(_handleFocusHighlightModeChange);
}

void _FocusableActionDetectorStateCls::dispose() {
    FocusManagerCls::instance->removeHighlightModeListener(_handleFocusHighlightModeChange);
    super->dispose();
}

void _FocusableActionDetectorStateCls::didUpdateWidget(FocusableActionDetector oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (widget()->enabled != oldWidget->enabled) {
        SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration duration) {
            _mayTriggerCallback(oldWidget);
        });
    }
}

Widget _FocusableActionDetectorStateCls::build(BuildContext context) {
    Widget child = make<MouseRegionCls>(_mouseRegionKey, _handleMouseEnter, _handleMouseExit, widget()->mouseCursor, make<FocusCls>(widget()->focusNode, widget()->autofocus, widget()->descendantsAreFocusable, widget()->descendantsAreTraversable, _canRequestFocus(), _handleFocusChange, widget()->child));
    if (widget()->enabled && widget()->actions != nullptr && widget()->actions!->isNotEmpty) {
        child = make<ActionsCls>(widget()->actions!, child);
    }
    if (widget()->enabled && widget()->shortcuts != nullptr && widget()->shortcuts!->isNotEmpty) {
        child = make<ShortcutsCls>(widget()->shortcuts!, child);
    }
    return child;
}

void _FocusableActionDetectorStateCls::_updateHighlightMode(FocusHighlightMode mode) {
    _mayTriggerCallback([=] () {
        ;
    });
}

void _FocusableActionDetectorStateCls::_handleFocusHighlightModeChange(FocusHighlightMode mode) {
    if (!mounted()) {
        return;
    }
    _updateHighlightMode(mode);
}

void _FocusableActionDetectorStateCls::_handleMouseEnter(PointerEnterEvent event) {
    if (!_hovering) {
        _mayTriggerCallback([=] () {
            _hovering = true;
        });
    }
}

void _FocusableActionDetectorStateCls::_handleMouseExit(PointerExitEvent event) {
    if (_hovering) {
        _mayTriggerCallback([=] () {
            _hovering = false;
        });
    }
}

void _FocusableActionDetectorStateCls::_handleFocusChange(bool focused) {
    if (_focused != focused) {
        _mayTriggerCallback([=] () {
            _focused = focused;
        });
        widget()->onFocusChange?->call(_focused);
    }
}

void _FocusableActionDetectorStateCls::_mayTriggerCallback(FocusableActionDetector oldWidget, VoidCallback task) {
    InlineMethod;
    InlineMethod;
    InlineMethod;
    assert(SchedulerBindingCls::instance->schedulerPhase != SchedulerPhaseCls::persistentCallbacks);
    FocusableActionDetector oldTarget = oldWidget | widget();
    bool didShowHoverHighlight = shouldShowHoverHighlight(oldTarget);
    bool didShowFocusHighlight = shouldShowFocusHighlight(oldTarget);
    if (task != nullptr) {
        task();
    }
    bool doShowHoverHighlight = shouldShowHoverHighlight(widget());
    bool doShowFocusHighlight = shouldShowFocusHighlight(widget());
    if (didShowFocusHighlight != doShowFocusHighlight) {
        widget()->onShowFocusHighlight?->call(doShowFocusHighlight);
    }
    if (didShowHoverHighlight != doShowHoverHighlight) {
        widget()->onShowHoverHighlight?->call(doShowHoverHighlight);
    }
}

bool _FocusableActionDetectorStateCls::_canRequestFocus() {
    NavigationMode mode = MediaQueryCls->maybeOf(context())?->navigationMode | NavigationModeCls::traditional;
    ;
}

Object VoidCallbackActionCls::invoke(VoidCallbackIntent intent) {
    intent->callback();
    return nullptr;
}

DoNothingActionCls::DoNothingActionCls(bool consumesKey) {
    {
        _consumesKey = consumesKey;
    }
}

bool DoNothingActionCls::consumesKey(Intent intent) {
    return _consumesKey;
}

void DoNothingActionCls::invoke(Intent intent) {
}

PrioritizedIntentsCls::PrioritizedIntentsCls(List<Intent> orderedIntents) {
    {
        assert(orderedIntents != nullptr);
    }
}

bool PrioritizedActionCls::isEnabled(PrioritizedIntents intent) {
    FocusNode focus = primaryFocus;
    if (focus == nullptr || focus->context() == nullptr) {
        return false;
    }
    for (Intent candidateIntent : intent->orderedIntents) {
        Action<Intent> candidateAction = ActionsCls-><Intent>maybeFind(focus->context()!, candidateIntent);
        if (candidateAction != nullptr && candidateAction->isEnabled(candidateIntent)) {
            _selectedAction = candidateAction;
            _selectedIntent = candidateIntent;
            return true;
        }
    }
    return false;
}

void PrioritizedActionCls::invoke(PrioritizedIntents intent) {
    assert(_selectedAction != nullptr);
    assert(_selectedIntent != nullptr);
    _selectedAction->invoke(_selectedIntent);
}

template<typename T>
Action<T> _OverridableActionMixinCls<T>::getOverrideAction(bool declareDependency) {
    Action<T> override = declareDependency? ActionsCls->maybeFind(lookupContext()) : ActionsCls->_maybeFindWithoutDependingOn(lookupContext());
    assert(!identical(override, this));
    return override;
}

template<typename T>
Object _OverridableActionMixinCls<T>::invoke(T intent, BuildContext context) {
    Action<T> overrideAction = getOverrideAction();
    Object returnValue = overrideAction == nullptr? invokeDefaultAction(intent, callingAction, context) : _invokeOverride(overrideAction, intent, context);
    return returnValue;
}

template<typename T>
bool _OverridableActionMixinCls<T>::isOverrideActionEnabled(Action<T> overrideAction) {
    assert(!debugAssertIsActionEnabledMutuallyRecursive);
    assert([=] () {
        debugAssertIsActionEnabledMutuallyRecursive = true;
        return true;
    }());
    overrideAction->_updateCallingAction(defaultAction());
    bool isOverrideEnabled = overrideAction->isActionEnabled();
    overrideAction->_updateCallingAction(nullptr);
    assert([=] () {
        debugAssertIsActionEnabledMutuallyRecursive = false;
        return true;
    }());
    return isOverrideEnabled;
}

template<typename T>
bool _OverridableActionMixinCls<T>::isActionEnabled() {
    Action<T> overrideAction = getOverrideAction(true);
    bool returnValue = overrideAction != nullptr? isOverrideActionEnabled(overrideAction) : defaultAction()->isActionEnabled();
    return returnValue;
}

template<typename T>
bool _OverridableActionMixinCls<T>::isEnabled(T intent) {
    assert(!debugAssertIsEnabledMutuallyRecursive);
    assert([=] () {
        debugAssertIsEnabledMutuallyRecursive = true;
        return true;
    }());
    Action<T> overrideAction = getOverrideAction();
    overrideAction?->_updateCallingAction(defaultAction());
    bool returnValue = (overrideAction | defaultAction())->isEnabled(intent);
    overrideAction?->_updateCallingAction(nullptr);
    assert([=] () {
        debugAssertIsEnabledMutuallyRecursive = false;
        return true;
    }());
    return returnValue;
}

template<typename T>
bool _OverridableActionMixinCls<T>::consumesKey(T intent) {
    assert(!debugAssertConsumeKeyMutuallyRecursive);
    assert([=] () {
        debugAssertConsumeKeyMutuallyRecursive = true;
        return true;
    }());
    Action<T> overrideAction = getOverrideAction();
    overrideAction?->_updateCallingAction(defaultAction());
    bool isEnabled = (overrideAction | defaultAction())->consumesKey(intent);
    overrideAction?->_updateCallingAction(nullptr);
    assert([=] () {
        debugAssertConsumeKeyMutuallyRecursive = false;
        return true;
    }());
    return isEnabled;
}

template<typename T>
void _OverridableActionMixinCls<T>::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Action<T>>make<DiagnosticsPropertyCls>(__s("defaultAction"), defaultAction()));
}

template<typename T>
void _OverridableActionMixinCls<T>::_updateCallingAction(Action<T> value) {
    super->_updateCallingAction(value);
    defaultAction()->_updateCallingAction(value);
}

template<typename T>
Object _OverridableActionMixinCls<T>::_invokeOverride(Action<T> overrideAction, T intent, BuildContext context) {
    assert(!debugAssertMutuallyRecursive);
    assert([=] () {
        debugAssertMutuallyRecursive = true;
        return true;
    }());
    overrideAction->_updateCallingAction(defaultAction());
    Object returnValue = is<ContextAction<T>>(overrideAction)? overrideAction->invoke(intent, context) : overrideAction->invoke(intent);
    overrideAction->_updateCallingAction(nullptr);
    assert([=] () {
        debugAssertMutuallyRecursive = false;
        return true;
    }());
    return returnValue;
}

template<typename T>
Object _OverridableActionCls<T>::invokeDefaultAction(T intent, Action<T> fromAction, BuildContext context) {
    if (fromAction == nullptr) {
        return defaultAction->invoke(intent);
    } else {
        Object returnValue = defaultAction->invoke(intent);
        return returnValue;
    }
}

template<typename T>
ContextAction<T> _OverridableActionCls<T>::_makeOverridableAction(BuildContext context) {
    return <T>make<_OverridableActionCls>(defaultAction, context);
}

template<typename T>
Object _OverridableContextActionCls<T>::invokeDefaultAction(T intent, Action<T> fromAction, BuildContext context) {
    if (fromAction == nullptr) {
        return defaultAction->invoke(intent, context);
    } else {
        Object returnValue = defaultAction->invoke(intent, context);
        return returnValue;
    }
}

template<typename T>
Object _OverridableContextActionCls<T>::_invokeOverride(Action<T> overrideAction, T intent, BuildContext context) {
    assert(context != nullptr);
    assert(!debugAssertMutuallyRecursive);
    assert([=] () {
        debugAssertMutuallyRecursive = true;
        return true;
    }());
    Action<T> wrappedDefault = <T>make<_ContextActionToActionAdapterCls>(context!, defaultAction);
    overrideAction->_updateCallingAction(wrappedDefault);
    Object returnValue = is<ContextAction<T>>(overrideAction)? overrideAction->invoke(intent, context) : overrideAction->invoke(intent);
    overrideAction->_updateCallingAction(nullptr);
    assert([=] () {
        debugAssertMutuallyRecursive = false;
        return true;
    }());
    return returnValue;
}

template<typename T>
ContextAction<T> _OverridableContextActionCls<T>::_makeOverridableAction(BuildContext context) {
    return <T>make<_OverridableContextActionCls>(defaultAction, context);
}

template<typename T>
Action<T> _ContextActionToActionAdapterCls<T>::callingAction() {
    return action->callingAction();
}

template<typename T>
bool _ContextActionToActionAdapterCls<T>::isEnabled(T intent) {
    return action->isEnabled(intent);
}

template<typename T>
bool _ContextActionToActionAdapterCls<T>::isActionEnabled() {
    return action->isActionEnabled();
}

template<typename T>
bool _ContextActionToActionAdapterCls<T>::consumesKey(T intent) {
    return action->consumesKey(intent);
}

template<typename T>
void _ContextActionToActionAdapterCls<T>::addActionListener(ActionListenerCallback listener) {
    super->addActionListener(listener);
    action->addActionListener(listener);
}

template<typename T>
void _ContextActionToActionAdapterCls<T>::removeActionListener(ActionListenerCallback listener) {
    super->removeActionListener(listener);
    action->removeActionListener(listener);
}

template<typename T>
void _ContextActionToActionAdapterCls<T>::notifyActionListeners() {
    return action->notifyActionListeners();
}

template<typename T>
Object _ContextActionToActionAdapterCls<T>::invoke(T intent) {
    return action->invoke(intent, invokeContext);
}

template<typename T>
void _ContextActionToActionAdapterCls<T>::_updateCallingAction(Action<T> value) {
    action->_updateCallingAction(value);
}
