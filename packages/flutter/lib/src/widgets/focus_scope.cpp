#include "focus_scope.hpp"
FocusCls::FocusCls(bool autofocus, bool canRequestFocus, Widget child, String debugLabel, bool descendantsAreFocusable, bool descendantsAreTraversable, FocusNode focusNode, bool includeSemantics, Key key, ValueChanged<bool> onFocusChange, FocusOnKeyCallback onKey, FocusOnKeyEventCallback onKeyEvent, bool skipTraversal) {
    {
        _onKeyEvent = onKeyEvent;
        _onKey = onKey;
        _canRequestFocus = canRequestFocus;
        _skipTraversal = skipTraversal;
        _descendantsAreFocusable = descendantsAreFocusable;
        _descendantsAreTraversable = descendantsAreTraversable;
        _debugLabel = debugLabel;
        assert(child != nullptr);
        assert(autofocus != nullptr);
        assert(includeSemantics != nullptr);
    }
}

FocusOnKeyEventCallback FocusCls::onKeyEvent() {
    return _onKeyEvent | focusNode?->onKeyEvent();
}

FocusOnKeyCallback FocusCls::onKey() {
    return _onKey | focusNode?->onKey();
}

bool FocusCls::canRequestFocus() {
    return _canRequestFocus | focusNode?->canRequestFocus | true;
}

bool FocusCls::skipTraversal() {
    return _skipTraversal | focusNode?->skipTraversal | false;
}

bool FocusCls::descendantsAreFocusable() {
    return _descendantsAreFocusable | focusNode?->descendantsAreFocusable | true;
}

bool FocusCls::descendantsAreTraversable() {
    return _descendantsAreTraversable | focusNode?->descendantsAreTraversable | true;
}

String FocusCls::debugLabel() {
    return _debugLabel | focusNode?->debugLabel;
}

FocusNode FocusCls::of(BuildContext context, bool scopeOk) {
    assert(context != nullptr);
    assert(scopeOk != nullptr);
    _FocusMarker marker = context-><_FocusMarker>dependOnInheritedWidgetOfExactType();
    FocusNode node = marker?->notifier;
    assert([=] () {
        if (node == nullptr) {
            throw make<FlutterErrorCls>(__s("Focus.of() was called with a context that does not contain a Focus widget.\nNo Focus widget ancestor could be found starting from the context that was passed to Focus.of(). This can happen because you are using a widget that looks for a Focus ancestor, and do not have a Focus widget descendant in the nearest FocusScope.\nThe context used was:\n  $context"));
        }
        return true;
    }());
    assert([=] () {
        if (!scopeOk && is<FocusScopeNode>(node)) {
            throw make<FlutterErrorCls>(__s("Focus.of() was called with a context that does not contain a Focus between the given context and the nearest FocusScope widget.\nNo Focus ancestor could be found starting from the context that was passed to Focus.of() to the point where it found the nearest FocusScope widget. This can happen because you are using a widget that looks for a Focus ancestor, and do not have a Focus widget ancestor in the current FocusScope.\nThe context used was:\n  $context"));
        }
        return true;
    }());
    return node!;
}

FocusNode FocusCls::maybeOf(BuildContext context, bool scopeOk) {
    assert(context != nullptr);
    assert(scopeOk != nullptr);
    _FocusMarker marker = context-><_FocusMarker>dependOnInheritedWidgetOfExactType();
    FocusNode node = marker?->notifier;
    if (node == nullptr) {
        return nullptr;
    }
    if (!scopeOk && is<FocusScopeNode>(node)) {
        return nullptr;
    }
    return node;
}

bool FocusCls::isAt(BuildContext context) {
    return FocusCls->maybeOf(context)?->hasFocus | false;
}

void FocusCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<StringPropertyCls>(__s("debugLabel"), debugLabel(), nullptr));
    properties->add(make<FlagPropertyCls>(__s("autofocus"), autofocus, __s("AUTOFOCUS"), false));
    properties->add(make<FlagPropertyCls>(__s("canRequestFocus"), canRequestFocus(), __s("NOT FOCUSABLE"), false));
    properties->add(make<FlagPropertyCls>(__s("descendantsAreFocusable"), descendantsAreFocusable(), __s("DESCENDANTS UNFOCUSABLE"), true));
    properties->add(make<FlagPropertyCls>(__s("descendantsAreTraversable"), descendantsAreTraversable(), __s("DESCENDANTS UNTRAVERSABLE"), true));
    properties->add(<FocusNode>make<DiagnosticsPropertyCls>(__s("focusNode"), focusNode, nullptr));
}

State<Focus> FocusCls::createState() {
    return make<_FocusStateCls>();
}

bool FocusCls::_usingExternalFocus() {
    return false;
}

FocusOnKeyEventCallback _FocusWithExternalFocusNodeCls::onKeyEvent() {
    return focusNode!->onKeyEvent;
}

FocusOnKeyCallback _FocusWithExternalFocusNodeCls::onKey() {
    return focusNode!->onKey;
}

bool _FocusWithExternalFocusNodeCls::canRequestFocus() {
    return focusNode!->canRequestFocus();
}

bool _FocusWithExternalFocusNodeCls::skipTraversal() {
    return focusNode!->skipTraversal();
}

bool _FocusWithExternalFocusNodeCls::descendantsAreFocusable() {
    return focusNode!->descendantsAreFocusable();
}

String _FocusWithExternalFocusNodeCls::debugLabel() {
    return focusNode!->debugLabel();
}

bool _FocusWithExternalFocusNodeCls::_usingExternalFocus() {
    return true;
}

bool _FocusWithExternalFocusNodeCls::_descendantsAreTraversable() {
    return focusNode!->descendantsAreTraversable();
}

FocusNode _FocusStateCls::focusNode() {
    return widget()->focusNode() | _internalNode!;
}

void _FocusStateCls::initState() {
    super->initState();
    _initNode();
}

void _FocusStateCls::dispose() {
    focusNode()->removeListener(_handleFocusChanged);
    _focusAttachment!->detach();
    _internalNode?->dispose();
    super->dispose();
}

void _FocusStateCls::didChangeDependencies() {
    super->didChangeDependencies();
    _focusAttachment?->reparent();
    _handleAutofocus();
}

void _FocusStateCls::deactivate() {
    super->deactivate();
    _focusAttachment?->reparent();
    _didAutofocus = false;
}

void _FocusStateCls::didUpdateWidget(Focus oldWidget) {
    super->didUpdateWidget(oldWidget);
    assert([=] () {
        if (oldWidget->focusNode == widget()->focusNode() && !widget()->_usingExternalFocus && oldWidget->debugLabel() != widget()->debugLabel) {
            focusNode()->debugLabel() = widget()->debugLabel;
        }
        return true;
    }());
    if (oldWidget->focusNode == widget()->focusNode()) {
        if (!widget()->_usingExternalFocus) {
            if (widget()->onKey != focusNode()->onKey) {
                focusNode()->onKey = widget()->onKey;
            }
            if (widget()->onKeyEvent != focusNode()->onKeyEvent) {
                focusNode()->onKeyEvent = widget()->onKeyEvent;
            }
            if (widget()->skipTraversal != nullptr) {
                focusNode()->skipTraversal() = widget()->skipTraversal;
            }
            if (widget()->_canRequestFocus != nullptr) {
                focusNode()->canRequestFocus() = widget()->_canRequestFocus!;
            }
            focusNode()->descendantsAreFocusable() = widget()->descendantsAreFocusable;
            focusNode()->descendantsAreTraversable() = widget()->descendantsAreTraversable;
        }
    } else {
        _focusAttachment!->detach();
        oldWidget->focusNode?->removeListener(_handleFocusChanged);
        _initNode();
    }
    if (oldWidget->autofocus != widget()->autofocus) {
        _handleAutofocus();
    }
}

Widget _FocusStateCls::build(BuildContext context) {
    _focusAttachment!->reparent();
    Widget child = widget()->child;
    if (widget()->includeSemantics) {
        child = make<SemanticsCls>(_couldRequestFocus, _hadPrimaryFocus, widget()->child);
    }
    return make<_FocusMarkerCls>(focusNode(), child);
}

void _FocusStateCls::_initNode() {
    if (widget()->focusNode() == nullptr) {
        _internalNode |= _createNode();
    }
    focusNode()->descendantsAreFocusable() = widget()->descendantsAreFocusable;
    focusNode()->descendantsAreTraversable() = widget()->descendantsAreTraversable;
    if (widget()->skipTraversal != nullptr) {
        focusNode()->skipTraversal() = widget()->skipTraversal;
    }
    if (widget()->_canRequestFocus != nullptr) {
        focusNode()->canRequestFocus() = widget()->_canRequestFocus!;
    }
    _couldRequestFocus = focusNode()->canRequestFocus();
    _descendantsWereFocusable = focusNode()->descendantsAreFocusable();
    _descendantsWereTraversable = focusNode()->descendantsAreTraversable();
    _hadPrimaryFocus = focusNode()->hasPrimaryFocus();
    _focusAttachment = focusNode()->attach(context(), widget()->onKeyEvent, widget()->onKey);
    focusNode()->addListener(_handleFocusChanged);
}

FocusNode _FocusStateCls::_createNode() {
    return make<FocusNodeCls>(widget()->debugLabel, widget()->canRequestFocus, widget()->descendantsAreFocusable, widget()->descendantsAreTraversable, widget()->skipTraversal);
}

void _FocusStateCls::_handleAutofocus() {
    if (!_didAutofocus && widget()->autofocus) {
        FocusScopeCls->of(context())->autofocus(focusNode());
        _didAutofocus = true;
    }
}

void _FocusStateCls::_handleFocusChanged() {
    bool hasPrimaryFocus = focusNode()->hasPrimaryFocus();
    bool canRequestFocus = focusNode()->canRequestFocus();
    bool descendantsAreFocusable = focusNode()->descendantsAreFocusable();
    bool descendantsAreTraversable = focusNode()->descendantsAreTraversable();
    widget()->onFocusChange?->call(focusNode()->hasFocus());
    if (_hadPrimaryFocus != hasPrimaryFocus) {
        setState([=] () {
            _hadPrimaryFocus = hasPrimaryFocus;
        });
    }
    if (_couldRequestFocus != canRequestFocus) {
        setState([=] () {
            _couldRequestFocus = canRequestFocus;
        });
    }
    if (_descendantsWereFocusable != descendantsAreFocusable) {
        setState([=] () {
            _descendantsWereFocusable = descendantsAreFocusable;
        });
    }
    if (_descendantsWereTraversable != descendantsAreTraversable) {
        setState([=] () {
            _descendantsWereTraversable = descendantsAreTraversable;
        });
    }
}

FocusScopeCls::FocusScopeCls(bool autofocus, Unknown canRequestFocus, Widget child, Unknown debugLabel, Key key, FocusScopeNode node, ValueChanged<bool> onFocusChange, Unknown onKey, Unknown onKeyEvent, Unknown skipTraversal) : Focus(node) {
    {
        assert(child != nullptr);
        assert(autofocus != nullptr);
    }
}

FocusScopeNode FocusScopeCls::of(BuildContext context) {
    assert(context != nullptr);
    _FocusMarker marker = context-><_FocusMarker>dependOnInheritedWidgetOfExactType();
    return marker?->notifier?->nearestScope | context->owner()!->focusManager->rootScope;
}

State<Focus> FocusScopeCls::createState() {
    return make<_FocusScopeStateCls>();
}

FocusOnKeyEventCallback _FocusScopeWithExternalFocusNodeCls::onKeyEvent() {
    return focusNode!->onKeyEvent;
}

FocusOnKeyCallback _FocusScopeWithExternalFocusNodeCls::onKey() {
    return focusNode!->onKey;
}

bool _FocusScopeWithExternalFocusNodeCls::canRequestFocus() {
    return focusNode!->canRequestFocus();
}

bool _FocusScopeWithExternalFocusNodeCls::skipTraversal() {
    return focusNode!->skipTraversal();
}

bool _FocusScopeWithExternalFocusNodeCls::descendantsAreFocusable() {
    return focusNode!->descendantsAreFocusable();
}

bool _FocusScopeWithExternalFocusNodeCls::descendantsAreTraversable() {
    return focusNode!->descendantsAreTraversable();
}

String _FocusScopeWithExternalFocusNodeCls::debugLabel() {
    return focusNode!->debugLabel();
}

_FocusScopeWithExternalFocusNodeCls::_FocusScopeWithExternalFocusNodeCls(bool autofocus, Widget child, FocusScopeNode focusScopeNode, Key key, ValueChanged<bool> onFocusChange) : FocusScope(focusScopeNode) {
}

bool _FocusScopeWithExternalFocusNodeCls::_usingExternalFocus() {
    return true;
}

Widget _FocusScopeStateCls::build(BuildContext context) {
    _focusAttachment!->reparent();
    return make<SemanticsCls>(true, make<_FocusMarkerCls>(focusNode(), widget()->child));
}

FocusScopeNode _FocusScopeStateCls::_createNode() {
    return make<FocusScopeNodeCls>(widget()->debugLabel, widget()->canRequestFocus, widget()->skipTraversal);
}

_FocusMarkerCls::_FocusMarkerCls(Widget child, FocusNode node) : InheritedNotifier<FocusNode>(node) {
    {
        assert(node != nullptr);
        assert(child != nullptr);
    }
}

ExcludeFocusCls::ExcludeFocusCls(Widget child, bool excluding, Key key) {
    {
        assert(excluding != nullptr);
        assert(child != nullptr);
    }
}

Widget ExcludeFocusCls::build(BuildContext context) {
    return make<FocusCls>(false, true, false, !excluding, child);
}
