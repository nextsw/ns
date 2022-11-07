#include "focus_scope.hpp"
Focus::Focus(bool autofocus, bool canRequestFocus, Widget child, String debugLabel, bool descendantsAreFocusable, bool descendantsAreTraversable, FocusNode focusNode, bool includeSemantics, Unknown, ValueChanged<bool> onFocusChange, FocusOnKeyCallback onKey, FocusOnKeyEventCallback onKeyEvent, bool skipTraversal) {
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

FocusOnKeyEventCallback Focus::onKeyEvent() {
    return _onKeyEvent ?? focusNode?.onKeyEvent;
}

FocusOnKeyCallback Focus::onKey() {
    return _onKey ?? focusNode?.onKey;
}

bool Focus::canRequestFocus() {
    return _canRequestFocus ?? focusNode?.canRequestFocus ?? true;
}

bool Focus::skipTraversal() {
    return _skipTraversal ?? focusNode?.skipTraversal ?? false;
}

bool Focus::descendantsAreFocusable() {
    return _descendantsAreFocusable ?? focusNode?.descendantsAreFocusable ?? true;
}

bool Focus::descendantsAreTraversable() {
    return _descendantsAreTraversable ?? focusNode?.descendantsAreTraversable ?? true;
}

String Focus::debugLabel() {
    return _debugLabel ?? focusNode?.debugLabel;
}

FocusNode Focus::of(BuildContext context, bool scopeOk) {
    assert(context != nullptr);
    assert(scopeOk != nullptr);
    _FocusMarker marker = context.<_FocusMarker>dependOnInheritedWidgetOfExactType();
    FocusNode node = marker?.notifier;
    assert(());
    assert(());
    return node!;
}

FocusNode Focus::maybeOf(BuildContext context, bool scopeOk) {
    assert(context != nullptr);
    assert(scopeOk != nullptr);
    _FocusMarker marker = context.<_FocusMarker>dependOnInheritedWidgetOfExactType();
    FocusNode node = marker?.notifier;
    if (node == nullptr) {
        return nullptr;
    }
    if (!scopeOk && node is FocusScopeNode) {
        return nullptr;
    }
    return node;
}

bool Focus::isAt(BuildContext context) {
    return Focus.maybeOf(context)?.hasFocus ?? false;
}

void Focus::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(StringProperty("debugLabel", debugLabelnullptr));
    properties.add(FlagProperty("autofocus"autofocus, "AUTOFOCUS", false));
    properties.add(FlagProperty("canRequestFocus"canRequestFocus, "NOT FOCUSABLE", false));
    properties.add(FlagProperty("descendantsAreFocusable"descendantsAreFocusable, "DESCENDANTS UNFOCUSABLE", true));
    properties.add(FlagProperty("descendantsAreTraversable"descendantsAreTraversable, "DESCENDANTS UNTRAVERSABLE", true));
    properties.add(<FocusNode>DiagnosticsProperty("focusNode", focusNodenullptr));
}

State<Focus> Focus::createState() {
    return _FocusState();
}

bool Focus::_usingExternalFocus() {
    return false;
}

FocusOnKeyEventCallback _FocusWithExternalFocusNode::onKeyEvent() {
    return focusNode!.onKeyEvent;
}

FocusOnKeyCallback _FocusWithExternalFocusNode::onKey() {
    return focusNode!.onKey;
}

bool _FocusWithExternalFocusNode::canRequestFocus() {
    return focusNode!.canRequestFocus;
}

bool _FocusWithExternalFocusNode::skipTraversal() {
    return focusNode!.skipTraversal;
}

bool _FocusWithExternalFocusNode::descendantsAreFocusable() {
    return focusNode!.descendantsAreFocusable;
}

String _FocusWithExternalFocusNode::debugLabel() {
    return focusNode!.debugLabel;
}

bool _FocusWithExternalFocusNode::_usingExternalFocus() {
    return true;
}

bool _FocusWithExternalFocusNode::_descendantsAreTraversable() {
    return focusNode!.descendantsAreTraversable;
}

FocusNode _FocusState::focusNode() {
    return widget.focusNode ?? _internalNode!;
}

void _FocusState::initState() {
    super.initState();
    _initNode();
}

void _FocusState::dispose() {
    focusNode.removeListener(_handleFocusChanged);
    _focusAttachment!.detach();
    _internalNode?.dispose();
    super.dispose();
}

void _FocusState::didChangeDependencies() {
    super.didChangeDependencies();
    _focusAttachment?.reparent();
    _handleAutofocus();
}

void _FocusState::deactivate() {
    super.deactivate();
    _focusAttachment?.reparent();
    _didAutofocus = false;
}

void _FocusState::didUpdateWidget(Focus oldWidget) {
    super.didUpdateWidget(oldWidget);
    assert(());
    if (oldWidget.focusNode == widget.focusNode) {
        if (!widget._usingExternalFocus) {
            if (widget.onKey != focusNode.onKey) {
                focusNode.onKey = widget.onKey;
            }
            if (widget.onKeyEvent != focusNode.onKeyEvent) {
                focusNode.onKeyEvent = widget.onKeyEvent;
            }
            if (widget.skipTraversal != nullptr) {
                focusNode.skipTraversal = widget.skipTraversal;
            }
            if (widget._canRequestFocus != nullptr) {
                focusNode.canRequestFocus = widget._canRequestFocus!;
            }
            focusNode.descendantsAreFocusable = widget.descendantsAreFocusable;
            focusNode.descendantsAreTraversable = widget.descendantsAreTraversable;
        }
    } else {
        _focusAttachment!.detach();
        oldWidget.focusNode?.removeListener(_handleFocusChanged);
        _initNode();
    }
    if (oldWidget.autofocus != widget.autofocus) {
        _handleAutofocus();
    }
}

Widget _FocusState::build(BuildContext context) {
    _focusAttachment!.reparent();
    Widget child = widget.child;
    if (widget.includeSemantics) {
        child = Semantics(_couldRequestFocus, _hadPrimaryFocus, widget.child);
    }
    return _FocusMarker(focusNode, child);
}

void _FocusState::_initNode() {
    if (widget.focusNode == nullptr) {
        _internalNode = _createNode();
    }
    focusNode.descendantsAreFocusable = widget.descendantsAreFocusable;
    focusNode.descendantsAreTraversable = widget.descendantsAreTraversable;
    if (widget.skipTraversal != nullptr) {
        focusNode.skipTraversal = widget.skipTraversal;
    }
    if (widget._canRequestFocus != nullptr) {
        focusNode.canRequestFocus = widget._canRequestFocus!;
    }
    _couldRequestFocus = focusNode.canRequestFocus;
    _descendantsWereFocusable = focusNode.descendantsAreFocusable;
    _descendantsWereTraversable = focusNode.descendantsAreTraversable;
    _hadPrimaryFocus = focusNode.hasPrimaryFocus;
    _focusAttachment = focusNode.attach(contextwidget.onKeyEvent, widget.onKey);
    focusNode.addListener(_handleFocusChanged);
}

FocusNode _FocusState::_createNode() {
    return FocusNode(widget.debugLabel, widget.canRequestFocus, widget.descendantsAreFocusable, widget.descendantsAreTraversable, widget.skipTraversal);
}

void _FocusState::_handleAutofocus() {
    if (!_didAutofocus && widget.autofocus) {
        FocusScope.of(context).autofocus(focusNode);
        _didAutofocus = true;
    }
}

void _FocusState::_handleFocusChanged() {
    bool hasPrimaryFocus = focusNode.hasPrimaryFocus;
    bool canRequestFocus = focusNode.canRequestFocus;
    bool descendantsAreFocusable = focusNode.descendantsAreFocusable;
    bool descendantsAreTraversable = focusNode.descendantsAreTraversable;
    widget.onFocusChange?.call(focusNode.hasFocus);
    if (_hadPrimaryFocus != hasPrimaryFocus) {
        setState();
    }
    if (_couldRequestFocus != canRequestFocus) {
        setState();
    }
    if (_descendantsWereFocusable != descendantsAreFocusable) {
        setState();
    }
    if (_descendantsWereTraversable != descendantsAreTraversable) {
        setState();
    }
}

FocusScope::FocusScope(Unknown, Unknown, Unknown, Unknown, Unknown, FocusScopeNode node, Unknown, Unknown, Unknown, Unknown) {
    {
        assert(child != nullptr);
        assert(autofocus != nullptr);
        super(node);
    }
}

FocusScopeNode FocusScope::of(BuildContext context) {
    assert(context != nullptr);
    _FocusMarker marker = context.<_FocusMarker>dependOnInheritedWidgetOfExactType();
    return marker?.notifier?.nearestScope ?? context.owner!.focusManager.rootScope;
}

State<Focus> FocusScope::createState() {
    return _FocusScopeState();
}

FocusOnKeyEventCallback _FocusScopeWithExternalFocusNode::onKeyEvent() {
    return focusNode!.onKeyEvent;
}

FocusOnKeyCallback _FocusScopeWithExternalFocusNode::onKey() {
    return focusNode!.onKey;
}

bool _FocusScopeWithExternalFocusNode::canRequestFocus() {
    return focusNode!.canRequestFocus;
}

bool _FocusScopeWithExternalFocusNode::skipTraversal() {
    return focusNode!.skipTraversal;
}

bool _FocusScopeWithExternalFocusNode::descendantsAreFocusable() {
    return focusNode!.descendantsAreFocusable;
}

bool _FocusScopeWithExternalFocusNode::descendantsAreTraversable() {
    return focusNode!.descendantsAreTraversable;
}

String _FocusScopeWithExternalFocusNode::debugLabel() {
    return focusNode!.debugLabel;
}

_FocusScopeWithExternalFocusNode::_FocusScopeWithExternalFocusNode(Unknown, Unknown, FocusScopeNode focusScopeNode, Unknown, Unknown) {
    {
        super(focusScopeNode);
    }
}

bool _FocusScopeWithExternalFocusNode::_usingExternalFocus() {
    return true;
}

Widget _FocusScopeState::build(BuildContext context) {
    _focusAttachment!.reparent();
    return Semantics(true, _FocusMarker(focusNode, widget.child));
}

FocusScopeNode _FocusScopeState::_createNode() {
    return FocusScopeNode(widget.debugLabel, widget.canRequestFocus, widget.skipTraversal);
}

_FocusMarker::_FocusMarker(Unknown, FocusNode node) {
    {
        assert(node != nullptr);
        assert(child != nullptr);
        super(node);
    }
}

ExcludeFocus::ExcludeFocus(Widget child, bool excluding, Unknown) {
    {
        assert(excluding != nullptr);
        assert(child != nullptr);
    }
}

Widget ExcludeFocus::build(BuildContext context) {
    return Focus(false, true, false, !excluding, child);
}
