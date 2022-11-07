#include "focus_manager.hpp"
bool _focusDebug(Iterable<String> details, String message) {
    if (debugFocusChanges) {
        debugPrint("FOCUS: $message");
        if (details != nullptr && details.isNotEmpty) {
            for (String detail : details) {
                debugPrint("    $detail");
            }
        }
    }
    return true;
}

KeyEventResult combineKeyEventResults(Iterable<KeyEventResult> results) {
    bool hasSkipRemainingHandlers = false;
    for (KeyEventResult result : results) {
        ;
    }
    return hasSkipRemainingHandlers? KeyEventResult.skipRemainingHandlers : KeyEventResult.ignored;
}

void _Autofocus::applyIfValid(FocusManager manager) {
    bool shouldApply = (scope.parent != nullptr || identical(scope, manager.rootScope)) && identical(scope._manager, manager) && scope.focusedChild == nullptr && autofocusNode.ancestors.contains(scope);
    if (shouldApply) {
        assert(_focusDebug("Applying autofocus: $autofocusNode"));
        autofocusNode._doRequestFocus(true);
    } else {
        assert(_focusDebug("Autofocus request discarded for node: $autofocusNode."));
    }
}

bool FocusAttachment::isAttached() {
    return _node._attachment == this;
}

void FocusAttachment::detach() {
    assert(_node != nullptr);
    assert(_focusDebug("Detaching node:", ));
    if (isAttached) {
        if (_node.hasPrimaryFocus || (_node._manager != nullptr && _node._manager!._markedForFocus == _node)) {
            _node.unfocus(UnfocusDisposition.previouslyFocusedChild);
        }
        _node._manager?._markDetached(_node);
        _node._parent?._removeChild(_node);
        _node._attachment = nullptr;
        assert(!_node.hasPrimaryFocus);
        assert(_node._manager?._markedForFocus != _node);
    }
    assert(!isAttached);
}

void FocusAttachment::reparent(FocusNode parent) {
    assert(_node != nullptr);
    if (isAttached) {
        assert(_node.context != nullptr);
        parent = Focus.maybeOf(_node.context!true);
        parent = _node.context!.owner!.focusManager.rootScope;
        assert(parent != nullptr);
        parent._reparent(_node);
    }
}

void FocusAttachment::_(FocusNode _node)

FocusNode::FocusNode(bool canRequestFocus, String debugLabel, bool descendantsAreFocusable, bool descendantsAreTraversable, FocusOnKeyCallback onKey, FocusOnKeyEventCallback onKeyEvent, bool skipTraversal) {
    {
        assert(skipTraversal != nullptr);
        assert(canRequestFocus != nullptr);
        assert(descendantsAreFocusable != nullptr);
        _skipTraversal = skipTraversal;
        _canRequestFocus = canRequestFocus;
        _descendantsAreFocusable = descendantsAreFocusable;
        _descendantsAreTraversable = descendantsAreTraversable;
    }
    {
        this.debugLabel = debugLabel;
    }
}

bool FocusNode::skipTraversal() {
    if (_skipTraversal) {
        return true;
    }
    for (FocusNode ancestor : ancestors) {
        if (!ancestor.descendantsAreTraversable) {
            return true;
        }
    }
    return false;
}

void FocusNode::skipTraversal(bool value) {
    if (value != _skipTraversal) {
        _skipTraversal = value;
        _manager?._markPropertiesChanged(this);
    }
}

bool FocusNode::canRequestFocus() {
    if (!_canRequestFocus) {
        return false;
    }
    FocusScopeNode scope = enclosingScope;
    if (scope != nullptr && !scope.canRequestFocus) {
        return false;
    }
    for (FocusNode ancestor : ancestors) {
        if (!ancestor.descendantsAreFocusable) {
            return false;
        }
    }
    return true;
}

void FocusNode::canRequestFocus(bool value) {
    if (value != _canRequestFocus) {
        _canRequestFocus = value;
        if (hasFocus && !value) {
            unfocus(UnfocusDisposition.previouslyFocusedChild);
        }
        _manager?._markPropertiesChanged(this);
    }
}

bool FocusNode::descendantsAreFocusable() {
    return _descendantsAreFocusable;
}

void FocusNode::descendantsAreFocusable(bool value) {
    if (value == _descendantsAreFocusable) {
        return;
    }
    _descendantsAreFocusable = value;
    if (!value && hasFocus) {
        unfocus(UnfocusDisposition.previouslyFocusedChild);
    }
    _manager?._markPropertiesChanged(this);
}

bool FocusNode::descendantsAreTraversable() {
    return _descendantsAreTraversable;
}

void FocusNode::descendantsAreTraversable(bool value) {
    if (value != _descendantsAreTraversable) {
        _descendantsAreTraversable = value;
        _manager?._markPropertiesChanged(this);
    }
}

BuildContext FocusNode::context() {
    return _context;
}

FocusNode FocusNode::parent() {
    return _parent;
}

Iterable<FocusNode> FocusNode::children() {
    return _children;
}

Iterable<FocusNode> FocusNode::traversalChildren() {
    if (!descendantsAreFocusable) {
        return const <FocusNode>empty();
    }
    return children.where();
}

String FocusNode::debugLabel() {
    return _debugLabel;
}

void FocusNode::debugLabel(String value) {
    assert(());
}

Iterable<FocusNode> FocusNode::descendants() {
    if (_descendants == nullptr) {
        List<FocusNode> result = ;
        for (FocusNode child : _children) {
            result.addAll(child.descendants);
            result.add(child);
        }
        _descendants = result;
    }
    return _descendants!;
}

Iterable<FocusNode> FocusNode::traversalDescendants() {
    if (!descendantsAreFocusable) {
        return const <FocusNode>empty();
    }
    return descendants.where();
}

Iterable<FocusNode> FocusNode::ancestors() {
    if (_ancestors == nullptr) {
        List<FocusNode> result = ;
        FocusNode parent = _parent;
        while (parent != nullptr) {
            result.add(parent);
            parent = parent._parent;
        }
        _ancestors = result;
    }
    return _ancestors!;
}

bool FocusNode::hasFocus() {
    return hasPrimaryFocus || (_manager?.primaryFocus?.ancestors.contains(this) ?? false);
}

bool FocusNode::hasPrimaryFocus() {
    return _manager?.primaryFocus == this;
}

FocusHighlightMode FocusNode::highlightMode() {
    return FocusManager.instance.highlightMode;
}

FocusScopeNode FocusNode::nearestScope() {
    return enclosingScope;
}

FocusScopeNode FocusNode::enclosingScope() {
    for (FocusNode node : ancestors) {
        if (node is FocusScopeNode) {
            return node;
        }
    }
    return nullptr;
}

Size FocusNode::size() {
    return rect.size;
}

Offset FocusNode::offset() {
    assert(context != nullptr, "Tried to get the offset of a focus node that didn't have its context set yet.\nThe context needs to be set before trying to evaluate traversal policies. Setting the context is typically done with the attach method.");
    RenderObject object = context!.findRenderObject()!;
    return MatrixUtils.transformPoint(object.getTransformTo(nullptr), object.semanticBounds.topLeft);
}

Rect FocusNode::rect() {
    assert(context != nullptr, "Tried to get the bounds of a focus node that didn't have its context set yet.\nThe context needs to be set before trying to evaluate traversal policies. Setting the context is typically done with the attach method.");
    RenderObject object = context!.findRenderObject()!;
    Offset topLeft = MatrixUtils.transformPoint(object.getTransformTo(nullptr), object.semanticBounds.topLeft);
    Offset bottomRight = MatrixUtils.transformPoint(object.getTransformTo(nullptr), object.semanticBounds.bottomRight);
    return Rect.fromLTRB(topLeft.dx, topLeft.dy, bottomRight.dx, bottomRight.dy);
}

void FocusNode::unfocus(UnfocusDisposition disposition) {
    assert(disposition != nullptr);
    if (!hasFocus && (_manager == nullptr || _manager!._markedForFocus != this)) {
        return;
    }
    FocusScopeNode scope = enclosingScope;
    if (scope == nullptr) {
        return;
    }
    ;
    assert(_focusDebug("Unfocused node:", ));
}

bool FocusNode::consumeKeyboardToken() {
    if (!_hasKeyboardToken) {
        return false;
    }
    _hasKeyboardToken = false;
    return true;
}

FocusAttachment FocusNode::attach(BuildContext context, FocusOnKeyCallback onKey, FocusOnKeyEventCallback onKeyEvent) {
    _context = context;
    this.onKey = onKey ?? this.onKey;
    this.onKeyEvent = onKeyEvent ?? this.onKeyEvent;
    _attachment = FocusAttachment._(this);
    return _attachment!;
}

void FocusNode::dispose() {
    _attachment?.detach();
    super.dispose();
}

void FocusNode::requestFocus(FocusNode node) {
    if (node != nullptr) {
        if (node._parent == nullptr) {
            _reparent(node);
        }
        assert(node.ancestors.contains(this), "Focus was requested for a node that is not a descendant of the scope from which it was requested.");
        node._doRequestFocus(true);
        return;
    }
    _doRequestFocus(true);
}

bool FocusNode::nextFocus() {
    return FocusTraversalGroup.of(context!).next(this);
}

bool FocusNode::previousFocus() {
    return FocusTraversalGroup.of(context!).previous(this);
}

bool FocusNode::focusInDirection(TraversalDirection direction) {
    return FocusTraversalGroup.of(context!).inDirection(this, direction);
}

void FocusNode::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<BuildContext>DiagnosticsProperty("context", contextnullptr));
    properties.add(FlagProperty("descendantsAreFocusable"descendantsAreFocusable, "DESCENDANTS UNFOCUSABLE", true));
    properties.add(FlagProperty("descendantsAreTraversable"descendantsAreTraversable, "DESCENDANTS UNTRAVERSABLE", true));
    properties.add(FlagProperty("canRequestFocus"canRequestFocus, "NOT FOCUSABLE", true));
    properties.add(FlagProperty("hasFocus"hasFocus && !hasPrimaryFocus, "IN FOCUS PATH", false));
    properties.add(FlagProperty("hasPrimaryFocus"hasPrimaryFocus, "PRIMARY FOCUS", false));
}

List<DiagnosticsNode> FocusNode::debugDescribeChildren() {
    int count = 1;
    return _children.<DiagnosticsNode>map().toList();
}

String FocusNode::toStringShort() {
    bool hasDebugLabel = debugLabel != nullptr && debugLabel!.isNotEmpty;
    String extraData = "${hasDebugLabel ? debugLabel : ''}${hasFocus && hasDebugLabel ? ' ' : ''}${hasFocus && !hasPrimaryFocus ? '[IN FOCUS PATH]' : ''}${hasPrimaryFocus ? '[PRIMARY FOCUS]' : ''}";
    return "${describeIdentity(this)}${extraData.isNotEmpty ? '($extraData)' : ''}";
}

void FocusNode::_markNextFocus(FocusNode newFocus) {
    if (_manager != nullptr) {
        _manager!._markNextFocus(this);
        return;
    }
    newFocus._setAsFocusedChildForScope();
    newFocus._notify();
    if (newFocus != this) {
        _notify();
    }
}

void FocusNode::_removeChild(FocusNode node, bool removeScopeFocus) {
    assert(node != nullptr);
    assert(_children.contains(node), "Tried to remove a node that wasn't a child.");
    assert(node._parent == this);
    assert(node._manager == _manager);
    if (removeScopeFocus) {
        node.enclosingScope?._focusedChildren.remove(node);
    }
    node._parent = nullptr;
    _children.remove(node);
    for (FocusNode ancestor : ancestors) {
        ancestor._descendants = nullptr;
    }
    _descendants = nullptr;
    assert(_manager == nullptr || !_manager!.rootScope.descendants.contains(node));
}

void FocusNode::_updateManager(FocusManager manager) {
    _manager = manager;
    for (FocusNode descendant : descendants) {
        descendant._manager = manager;
        descendant._ancestors = nullptr;
    }
}

void FocusNode::_reparent(FocusNode child) {
    assert(child != nullptr);
    assert(child != this, "Tried to make a child into a parent of itself.");
    if (child._parent == this) {
        assert(_children.contains(child), "Found a node that says it's a child, but doesn't appear in the child list.");
        return;
    }
    assert(_manager == nullptr || child != _manager!.rootScope, "Reparenting the root node isn't allowed.");
    assert(!ancestors.contains(child), "The supplied child is already an ancestor of this node. Loops are not allowed.");
    FocusScopeNode oldScope = child.enclosingScope;
    bool hadFocus = child.hasFocus;
    child._parent?._removeChild(childoldScope != nearestScope);
    _children.add(child);
    child._parent = this;
    child._ancestors = nullptr;
    child._updateManager(_manager);
    for (FocusNode ancestor : child.ancestors) {
        ancestor._descendants = nullptr;
    }
    if (hadFocus) {
        _manager?.primaryFocus?._setAsFocusedChildForScope();
    }
    if (oldScope != nullptr && child.context != nullptr && child.enclosingScope != oldScope) {
        FocusTraversalGroup.maybeOf(child.context!)?.changedScope(child, oldScope);
    }
    if (child._requestFocusWhenReparented) {
        child._doRequestFocus(true);
        child._requestFocusWhenReparented = false;
    }
}

void FocusNode::_notify() {
    if (_parent == nullptr) {
        return;
    }
    if (hasPrimaryFocus) {
        _setAsFocusedChildForScope();
    }
    notifyListeners();
}

void FocusNode::_doRequestFocus(bool findFirstFocus) {
    assert(findFirstFocus != nullptr);
    if (!canRequestFocus) {
        assert(_focusDebug("Node NOT requesting focus because canRequestFocus is false: $this"));
        return;
    }
    if (_parent == nullptr) {
        _requestFocusWhenReparented = true;
        return;
    }
    _setAsFocusedChildForScope();
    if (hasPrimaryFocus && (_manager!._markedForFocus == nullptr || _manager!._markedForFocus == this)) {
        return;
    }
    _hasKeyboardToken = true;
    assert(_focusDebug("Node requesting focus: $this"));
    _markNextFocus(this);
}

void FocusNode::_setAsFocusedChildForScope() {
    FocusNode scopeFocus = this;
    for (FocusScopeNode ancestor : ancestors.<FocusScopeNode>whereType()) {
        assert(scopeFocus != ancestor, "Somehow made a loop by setting focusedChild to its scope.");
        assert(_focusDebug("Setting $scopeFocus as focused child for scope:", ));
        ancestor._focusedChildren.remove(scopeFocus);
        ancestor._focusedChildren.add(scopeFocus);
        scopeFocus = ancestor;
    }
}

FocusScopeNode::FocusScopeNode(Unknown, Unknown, Unknown, Unknown, Unknown) {
    {
        assert(skipTraversal != nullptr);
        assert(canRequestFocus != nullptr);
        super(true);
    }
}

FocusScopeNode FocusScopeNode::nearestScope() {
    return this;
}

bool FocusScopeNode::isFirstFocus() {
    return enclosingScope!.focusedChild == this;
}

FocusNode FocusScopeNode::focusedChild() {
    assert(_focusedChildren.isEmpty || _focusedChildren.last.enclosingScope == this, "Focused child does not have the same idea of its enclosing scope as the scope does.");
    return _focusedChildren.isNotEmpty? _focusedChildren.last : nullptr;
}

Iterable<FocusNode> FocusScopeNode::traversalChildren() {
    if (!canRequestFocus) {
        return const <FocusNode>empty();
    }
    return super.traversalChildren;
}

Iterable<FocusNode> FocusScopeNode::traversalDescendants() {
    if (!canRequestFocus) {
        return const <FocusNode>empty();
    }
    return super.traversalDescendants;
}

void FocusScopeNode::setFirstFocus(FocusScopeNode scope) {
    assert(scope != nullptr);
    assert(scope != this, "Unexpected self-reference in setFirstFocus.");
    assert(_focusDebug("Setting scope as first focus in $this to node:", ));
    if (scope._parent == nullptr) {
        _reparent(scope);
    }
    assert(scope.ancestors.contains(this), "$FocusScopeNode $scope must be a child of $this to set it as first focus.");
    if (hasFocus) {
        scope._doRequestFocus(true);
    } else {
        scope._setAsFocusedChildForScope();
    }
}

void FocusScopeNode::autofocus(FocusNode node) {
    if (node._parent == nullptr) {
        _reparent(node);
    }
    assert(_manager != nullptr);
    assert(_focusDebug("Autofocus scheduled for $node: scope $this"));
    _manager?._pendingAutofocuses.add(_Autofocus(this, node));
    _manager?._markNeedsUpdate();
}

void FocusScopeNode::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    if (_focusedChildren.isEmpty) {
        return;
    }
    List<String> childList = _focusedChildren.reversed.<String>map().toList();
    properties.add(<String>IterableProperty("focusedChildren", childListconst <String>empty()));
}

void FocusScopeNode::_doRequestFocus(bool findFirstFocus) {
    assert(findFirstFocus != nullptr);
    while (this.focusedChild != nullptr && !this.focusedChild!.canRequestFocus) {
        _focusedChildren.removeLast();
    }
    FocusNode focusedChild = this.focusedChild;
    if (!findFirstFocus || focusedChild == nullptr) {
        if (canRequestFocus) {
            _setAsFocusedChildForScope();
            _markNextFocus(this);
        }
        return;
    }
    focusedChild._doRequestFocus(true);
}

FocusManager::FocusManager() {
    {
        rootScope._manager = this;
    }
}

void FocusManager::registerGlobalHandlers() {
    assert(ServicesBinding.instance.keyEventManager.keyMessageHandler == nullptr);
    ServicesBinding.instance.keyEventManager.keyMessageHandler = _handleKeyMessage;
    GestureBinding.instance.pointerRouter.addGlobalRoute(_handlePointerEvent);
}

void FocusManager::dispose() {
    if (ServicesBinding.instance.keyEventManager.keyMessageHandler == _handleKeyMessage) {
        ServicesBinding.instance.keyEventManager.keyMessageHandler = nullptr;
        GestureBinding.instance.pointerRouter.removeGlobalRoute(_handlePointerEvent);
    }
    super.dispose();
}

FocusManager FocusManager::instance() {
    return WidgetsBinding.instance.focusManager;
}

FocusHighlightStrategy FocusManager::highlightStrategy() {
    return _highlightStrategy;
}

void FocusManager::highlightStrategy(FocusHighlightStrategy highlightStrategy) {
    _highlightStrategy = highlightStrategy;
    _updateHighlightMode();
}

FocusHighlightMode FocusManager::highlightMode() {
    return _highlightMode ?? _defaultModeForPlatform;
}

void FocusManager::addHighlightModeListener(ValueChanged<FocusHighlightMode> listener) {
    return _listeners.add(listener);
}

void FocusManager::removeHighlightModeListener(ValueChanged<FocusHighlightMode> listener) {
    return _listeners.remove(listener);
}

FocusNode FocusManager::primaryFocus() {
    return _primaryFocus;
}

List<DiagnosticsNode> FocusManager::debugDescribeChildren() {
    return ;
}

void FocusManager::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    properties.add(FlagProperty("haveScheduledUpdate"_haveScheduledUpdate, "UPDATE SCHEDULED"));
    properties.add(<FocusNode>DiagnosticsProperty("primaryFocus", primaryFocusnullptr));
    properties.add(<FocusNode>DiagnosticsProperty("nextFocus", _markedForFocusnullptr));
    Element element = (;
    if (element != nullptr) {
        properties.add(<String>DiagnosticsProperty("primaryFocusCreator", element.debugGetCreatorChain(20)));
    }
}

FocusHighlightMode FocusManager::_defaultModeForPlatform() {
    ;
}

void FocusManager::_updateHighlightMode() {
    FocusHighlightMode newMode;
    ;
    FocusHighlightMode oldMode = highlightMode;
    _highlightMode = newMode;
    if (highlightMode != oldMode) {
        _notifyHighlightModeListeners();
    }
}

void FocusManager::_notifyHighlightModeListeners() {
    if (_listeners.isEmpty) {
        return;
    }
    List<ValueChanged<FocusHighlightMode>> localListeners = <ValueChanged<FocusHighlightMode>>of(_listeners);
    for (ValueChanged<FocusHighlightMode> listener : localListeners) {
        ;
    }
}

void FocusManager::_handlePointerEvent(PointerEvent event) {
    FocusHighlightMode expectedMode;
    ;
    if (expectedMode != highlightMode) {
        _updateHighlightMode();
    }
}

bool FocusManager::_handleKeyMessage(KeyMessage message) {
    _lastInteractionWasTouch = false;
    _updateHighlightMode();
    assert(_focusDebug("Received key event $message"));
    if (_primaryFocus == nullptr) {
        assert(_focusDebug("No primary focus for key event, ignored: $message"));
        return false;
    }
    bool handled = false;
    for (FocusNode node : ) {
        List<KeyEventResult> results = ;
        if (node.onKeyEvent != nullptr) {
            for (KeyEvent event : message.events) {
                results.add(node.onKeyEvent!(node, event));
            }
        }
        if (node.onKey != nullptr && message.rawEvent != nullptr) {
            results.add(node.onKey!(node, message.rawEvent!));
        }
        KeyEventResult result = combineKeyEventResults(results);
        ;
        assert(result != KeyEventResult.ignored);
                break;
    }
    if (!handled) {
        assert(_focusDebug("Key event not handled by anyone: $message."));
    }
    return handled;
}

void FocusManager::_markDetached(FocusNode node) {
    assert(_focusDebug("Node was detached: $node"));
    if (_primaryFocus == node) {
        _primaryFocus = nullptr;
    }
    _dirtyNodes.remove(node);
}

void FocusManager::_markPropertiesChanged(FocusNode node) {
    _markNeedsUpdate();
    assert(_focusDebug("Properties changed for node $node."));
    _dirtyNodes.add(node);
}

void FocusManager::_markNextFocus(FocusNode node) {
    if (_primaryFocus == node) {
        _markedForFocus = nullptr;
    } else {
        _markedForFocus = node;
        _markNeedsUpdate();
    }
}

void FocusManager::_markNeedsUpdate() {
    assert(_focusDebug("Scheduling update, current focus is $_primaryFocus, next focus will be $_markedForFocus"));
    if (_haveScheduledUpdate) {
        return;
    }
    _haveScheduledUpdate = true;
    scheduleMicrotask(_applyFocusChange);
}

void FocusManager::_applyFocusChange() {
    _haveScheduledUpdate = false;
    FocusNode previousFocus = _primaryFocus;
    for (_Autofocus autofocus : _pendingAutofocuses) {
        autofocus.applyIfValid(this);
    }
    _pendingAutofocuses.clear();
    if (_primaryFocus == nullptr && _markedForFocus == nullptr) {
        _markedForFocus = rootScope;
    }
    assert(_focusDebug("Refreshing focus state. Next focus will be $_markedForFocus"));
    if (_markedForFocus != nullptr && _markedForFocus != _primaryFocus) {
        Set<FocusNode> previousPath = previousFocus?.ancestors.toSet() ?? ;
        Set<FocusNode> nextPath = _markedForFocus!.ancestors.toSet();
        _dirtyNodes.addAll(nextPath.difference(previousPath));
        _dirtyNodes.addAll(previousPath.difference(nextPath));
        _primaryFocus = _markedForFocus;
        _markedForFocus = nullptr;
    }
    assert(_markedForFocus == nullptr);
    if (previousFocus != _primaryFocus) {
        assert(_focusDebug("Updating focus from $previousFocus to $_primaryFocus"));
        if (previousFocus != nullptr) {
            _dirtyNodes.add(previousFocus);
        }
        if (_primaryFocus != nullptr) {
            _dirtyNodes.add(_primaryFocus!);
        }
    }
    for (FocusNode node : _dirtyNodes) {
        node._notify();
    }
    assert(_focusDebug("Notified ${_dirtyNodes.length} dirty nodes:", _dirtyNodes.toList().<String>map()));
    _dirtyNodes.clear();
    if (previousFocus != _primaryFocus) {
        notifyListeners();
    }
    assert(());
}

FocusNode primaryFocus() {
    return WidgetsBinding.instance.focusManager.primaryFocus;
}

String debugDescribeFocusTree() {
    assert(WidgetsBinding.instance != nullptr);
    String result;
    assert(());
    return result ?? "";
}

void debugDumpFocusTree() {
    assert(());
}
