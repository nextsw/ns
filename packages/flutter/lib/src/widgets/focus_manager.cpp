#include "focus_manager.hpp"
bool _focusDebug(String message, Iterable<String> details) {
    if (debugFocusChanges) {
        debugPrint(__sf("FOCUS: %s", message));
        if (details != nullptr && details->isNotEmpty()) {
            for (String detail : details) {
                debugPrint(__sf("    %s", detail));
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
    return hasSkipRemainingHandlers? KeyEventResultCls::skipRemainingHandlers : KeyEventResultCls::ignored;
}

void _AutofocusCls::applyIfValid(FocusManager manager) {
    bool shouldApply = (scope->parent() != nullptr || identical(scope, manager->rootScope)) && identical(scope->_manager, manager) && scope->focusedChild() == nullptr && autofocusNode->ancestors()->contains(scope);
    if (shouldApply) {
        assert(_focusDebug(__sf("Applying autofocus: %s", autofocusNode)));
        autofocusNode->_doRequestFocus(true);
    } else {
        assert(_focusDebug(__sf("Autofocus request discarded for node: %s.", autofocusNode)));
    }
}

bool FocusAttachmentCls::isAttached() {
    return _node->_attachment == this;
}

void FocusAttachmentCls::detach() {
    assert(_node != nullptr);
    assert(_focusDebug(__s("Detaching node:"), makeList(ArrayItem, ArrayItem)));
    if (isAttached()) {
        if (_node->hasPrimaryFocus() || (_node->_manager != nullptr && _node->_manager!->_markedForFocus == _node)) {
            _node->unfocus(UnfocusDispositionCls::previouslyFocusedChild);
        }
        _node->_manager?->_markDetached(_node);
        _node->_parent?->_removeChild(_node);
        _node->_attachment = nullptr;
        assert(!_node->hasPrimaryFocus());
        assert(_node->_manager?->_markedForFocus != _node);
    }
    assert(!isAttached());
}

void FocusAttachmentCls::reparent(FocusNode parent) {
    assert(_node != nullptr);
    if (isAttached()) {
        assert(_node->context() != nullptr);
        parent |= FocusCls->maybeOf(_node->context()!, true);
        parent |= _node->context()!->owner()!->focusManager->rootScope;
        assert(parent != nullptr);
        parent->_reparent(_node);
    }
}

void FocusAttachmentCls::_(Unknown _node)

FocusNodeCls::FocusNodeCls(bool canRequestFocus, String debugLabel, bool descendantsAreFocusable, bool descendantsAreTraversable, FocusOnKeyCallback onKey, FocusOnKeyEventCallback onKeyEvent, bool skipTraversal) {
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
        this->debugLabel = debugLabel;
    }
}

bool FocusNodeCls::skipTraversal() {
    if (_skipTraversal) {
        return true;
    }
    for (FocusNode ancestor : ancestors()) {
        if (!ancestor->descendantsAreTraversable) {
            return true;
        }
    }
    return false;
}

void FocusNodeCls::skipTraversal(bool value) {
    if (value != _skipTraversal) {
        _skipTraversal = value;
        _manager?->_markPropertiesChanged(this);
    }
}

bool FocusNodeCls::canRequestFocus() {
    if (!_canRequestFocus) {
        return false;
    }
    FocusScopeNode scope = enclosingScope();
    if (scope != nullptr && !scope->canRequestFocus()) {
        return false;
    }
    for (FocusNode ancestor : ancestors()) {
        if (!ancestor->descendantsAreFocusable) {
            return false;
        }
    }
    return true;
}

void FocusNodeCls::canRequestFocus(bool value) {
    if (value != _canRequestFocus) {
        _canRequestFocus = value;
        if (hasFocus() && !value) {
            unfocus(UnfocusDispositionCls::previouslyFocusedChild);
        }
        _manager?->_markPropertiesChanged(this);
    }
}

bool FocusNodeCls::descendantsAreFocusable() {
    return _descendantsAreFocusable;
}

void FocusNodeCls::descendantsAreFocusable(bool value) {
    if (value == _descendantsAreFocusable) {
        return;
    }
    _descendantsAreFocusable = value;
    if (!value && hasFocus()) {
        unfocus(UnfocusDispositionCls::previouslyFocusedChild);
    }
    _manager?->_markPropertiesChanged(this);
}

bool FocusNodeCls::descendantsAreTraversable() {
    return _descendantsAreTraversable;
}

void FocusNodeCls::descendantsAreTraversable(bool value) {
    if (value != _descendantsAreTraversable) {
        _descendantsAreTraversable = value;
        _manager?->_markPropertiesChanged(this);
    }
}

BuildContext FocusNodeCls::context() {
    return _context;
}

FocusNode FocusNodeCls::parent() {
    return _parent;
}

Iterable<FocusNode> FocusNodeCls::children() {
    return _children;
}

Iterable<FocusNode> FocusNodeCls::traversalChildren() {
    if (!descendantsAreFocusable()) {
        return <FocusNode>empty();
    }
    return children()->where([=] (FocusNode node) {
        !node->skipTraversal && node->canRequestFocus;
    });
}

String FocusNodeCls::debugLabel() {
    return _debugLabel;
}

void FocusNodeCls::debugLabel(String value) {
    assert([=] () {
        _debugLabel = value;
        return true;
    }());
}

Iterable<FocusNode> FocusNodeCls::descendants() {
    if (_descendants == nullptr) {
        List<FocusNode> result = makeList();
        for (FocusNode child : _children) {
            result->addAll(child->descendants);
            result->add(child);
        }
        _descendants = result;
    }
    return _descendants!;
}

Iterable<FocusNode> FocusNodeCls::traversalDescendants() {
    if (!descendantsAreFocusable()) {
        return <FocusNode>empty();
    }
    return descendants()->where([=] (FocusNode node) {
        !node->skipTraversal && node->canRequestFocus;
    });
}

Iterable<FocusNode> FocusNodeCls::ancestors() {
    if (_ancestors == nullptr) {
        List<FocusNode> result = makeList();
        FocusNode parent = _parent;
        while (parent != nullptr) {
            result->add(parent);
            parent = parent->_parent;
        }
        _ancestors = result;
    }
    return _ancestors!;
}

bool FocusNodeCls::hasFocus() {
    return hasPrimaryFocus() || (_manager?->primaryFocus()?->ancestors()->contains(this) | false);
}

bool FocusNodeCls::hasPrimaryFocus() {
    return _manager?->primaryFocus() == this;
}

FocusHighlightMode FocusNodeCls::highlightMode() {
    return FocusManagerCls::instance->highlightMode;
}

FocusScopeNode FocusNodeCls::nearestScope() {
    return enclosingScope();
}

FocusScopeNode FocusNodeCls::enclosingScope() {
    for (FocusNode node : ancestors()) {
        if (is<FocusScopeNode>(node)) {
            return as<FocusScopeNodeCls>(node);
        }
    }
    return nullptr;
}

Size FocusNodeCls::size() {
    return rect()->size();
}

Offset FocusNodeCls::offset() {
    assert(context() != nullptr, __s("Tried to get the offset of a focus node that didn't have its context set yet.\nThe context needs to be set before trying to evaluate traversal policies. Setting the context is typically done with the attach method."));
    RenderObject object = context()!->findRenderObject()!;
    return MatrixUtilsCls->transformPoint(object->getTransformTo(nullptr), object->semanticBounds()->topLeft());
}

Rect FocusNodeCls::rect() {
    assert(context() != nullptr, __s("Tried to get the bounds of a focus node that didn't have its context set yet.\nThe context needs to be set before trying to evaluate traversal policies. Setting the context is typically done with the attach method."));
    RenderObject object = context()!->findRenderObject()!;
    Offset topLeft = MatrixUtilsCls->transformPoint(object->getTransformTo(nullptr), object->semanticBounds()->topLeft());
    Offset bottomRight = MatrixUtilsCls->transformPoint(object->getTransformTo(nullptr), object->semanticBounds()->bottomRight());
    return RectCls->fromLTRB(topLeft->dx(), topLeft->dy(), bottomRight->dx(), bottomRight->dy());
}

void FocusNodeCls::unfocus(UnfocusDisposition disposition) {
    assert(disposition != nullptr);
    if (!hasFocus() && (_manager == nullptr || _manager!->_markedForFocus != this)) {
        return;
    }
    FocusScopeNode scope = enclosingScope();
    if (scope == nullptr) {
        return;
    }
    ;
    assert(_focusDebug(__s("Unfocused node:"), makeList(ArrayItem, ArrayItem)));
}

bool FocusNodeCls::consumeKeyboardToken() {
    if (!_hasKeyboardToken) {
        return false;
    }
    _hasKeyboardToken = false;
    return true;
}

FocusAttachment FocusNodeCls::attach(BuildContext context, FocusOnKeyCallback onKey, FocusOnKeyEventCallback onKeyEvent) {
    _context = context;
    this->onKey = onKey | this->onKey;
    this->onKeyEvent = onKeyEvent | this->onKeyEvent;
    _attachment = FocusAttachmentCls->_(this);
    return _attachment!;
}

void FocusNodeCls::dispose() {
    _attachment?->detach();
    super->dispose();
}

void FocusNodeCls::requestFocus(FocusNode node) {
    if (node != nullptr) {
        if (node->_parent == nullptr) {
            _reparent(node);
        }
        assert(node->ancestors()->contains(this), __s("Focus was requested for a node that is not a descendant of the scope from which it was requested."));
        node->_doRequestFocus(true);
        return;
    }
    _doRequestFocus(true);
}

bool FocusNodeCls::nextFocus() {
    return FocusTraversalGroupCls->of(context()!)->next(this);
}

bool FocusNodeCls::previousFocus() {
    return FocusTraversalGroupCls->of(context()!)->previous(this);
}

bool FocusNodeCls::focusInDirection(TraversalDirection direction) {
    return FocusTraversalGroupCls->of(context()!)->inDirection(this, direction);
}

void FocusNodeCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<BuildContext>make<DiagnosticsPropertyCls>(__s("context"), context(), nullptr));
    properties->add(make<FlagPropertyCls>(__s("descendantsAreFocusable"), descendantsAreFocusable(), __s("DESCENDANTS UNFOCUSABLE"), true));
    properties->add(make<FlagPropertyCls>(__s("descendantsAreTraversable"), descendantsAreTraversable(), __s("DESCENDANTS UNTRAVERSABLE"), true));
    properties->add(make<FlagPropertyCls>(__s("canRequestFocus"), canRequestFocus(), __s("NOT FOCUSABLE"), true));
    properties->add(make<FlagPropertyCls>(__s("hasFocus"), hasFocus() && !hasPrimaryFocus(), __s("IN FOCUS PATH"), false));
    properties->add(make<FlagPropertyCls>(__s("hasPrimaryFocus"), hasPrimaryFocus(), __s("PRIMARY FOCUS"), false));
}

List<DiagnosticsNode> FocusNodeCls::debugDescribeChildren() {
    int count = 1;
    return _children-><DiagnosticsNode>map([=] (FocusNode child) {
        return child->toDiagnosticsNode(__sf("Child %s", count++));
    })->toList();
}

String FocusNodeCls::toStringShort() {
    bool hasDebugLabel = debugLabel() != nullptr && debugLabel()!->isNotEmpty();
    String extraData = __sf("%s", hasDebugLabel? debugLabel() : __sf("%s", hasFocus() && hasDebugLabel? __s(" ") : __sf("%s", hasFocus() && !hasPrimaryFocus()? __s("[IN FOCUS PATH]") : __sf("%s", hasPrimaryFocus()? __s("[PRIMARY FOCUS]") : __s("")))));
    return __sf("%s%s", describeIdentity(this), extraData->isNotEmpty()? __sf("(%s)", extraData) : __s(""));
}

void FocusNodeCls::_markNextFocus(FocusNode newFocus) {
    if (_manager != nullptr) {
        _manager!->_markNextFocus(this);
        return;
    }
    newFocus->_setAsFocusedChildForScope();
    newFocus->_notify();
    if (newFocus != this) {
        _notify();
    }
}

void FocusNodeCls::_removeChild(FocusNode node, bool removeScopeFocus) {
    assert(node != nullptr);
    assert(_children->contains(node), __s("Tried to remove a node that wasn't a child."));
    assert(node->_parent == this);
    assert(node->_manager == _manager);
    if (removeScopeFocus) {
        node->enclosingScope()?->_focusedChildren->remove(node);
    }
    node->_parent = nullptr;
    _children->remove(node);
    for (FocusNode ancestor : ancestors()) {
        ancestor->_descendants = nullptr;
    }
    _descendants = nullptr;
    assert(_manager == nullptr || !_manager!->rootScope->descendants()->contains(node));
}

void FocusNodeCls::_updateManager(FocusManager manager) {
    _manager = manager;
    for (FocusNode descendant : descendants()) {
        descendant->_manager = manager;
        descendant->_ancestors = nullptr;
    }
}

void FocusNodeCls::_reparent(FocusNode child) {
    assert(child != nullptr);
    assert(child != this, __s("Tried to make a child into a parent of itself."));
    if (child->_parent == this) {
        assert(_children->contains(child), __s("Found a node that says it's a child, but doesn't appear in the child list."));
        return;
    }
    assert(_manager == nullptr || child != _manager!->rootScope, __s("Reparenting the root node isn't allowed."));
    assert(!ancestors()->contains(child), __s("The supplied child is already an ancestor of this node. Loops are not allowed."));
    FocusScopeNode oldScope = child->enclosingScope();
    bool hadFocus = child->hasFocus();
    child->_parent?->_removeChild(child, oldScope != nearestScope());
    _children->add(child);
    child->_parent = this;
    child->_ancestors = nullptr;
    child->_updateManager(_manager);
    for (FocusNode ancestor : child->ancestors()) {
        ancestor->_descendants = nullptr;
    }
    if (hadFocus) {
        _manager?->primaryFocus()?->_setAsFocusedChildForScope();
    }
    if (oldScope != nullptr && child->context() != nullptr && child->enclosingScope() != oldScope) {
        FocusTraversalGroupCls->maybeOf(child->context()!)?->changedScope(child, oldScope);
    }
    if (child->_requestFocusWhenReparented) {
        child->_doRequestFocus(true);
        child->_requestFocusWhenReparented = false;
    }
}

void FocusNodeCls::_notify() {
    if (_parent == nullptr) {
        return;
    }
    if (hasPrimaryFocus()) {
        _setAsFocusedChildForScope();
    }
    notifyListeners();
}

void FocusNodeCls::_doRequestFocus(bool findFirstFocus) {
    assert(findFirstFocus != nullptr);
    if (!canRequestFocus()) {
        assert(_focusDebug(__sf("Node NOT requesting focus because canRequestFocus is false: %s", this)));
        return;
    }
    if (_parent == nullptr) {
        _requestFocusWhenReparented = true;
        return;
    }
    _setAsFocusedChildForScope();
    if (hasPrimaryFocus() && (_manager!->_markedForFocus == nullptr || _manager!->_markedForFocus == this)) {
        return;
    }
    _hasKeyboardToken = true;
    assert(_focusDebug(__sf("Node requesting focus: %s", this)));
    _markNextFocus(this);
}

void FocusNodeCls::_setAsFocusedChildForScope() {
    FocusNode scopeFocus = this;
    for (FocusScopeNode ancestor : ancestors()-><FocusScopeNode>whereType()) {
        assert(scopeFocus != ancestor, __s("Somehow made a loop by setting focusedChild to its scope."));
        assert(_focusDebug(__sf("Setting %s as focused child for scope:", scopeFocus), makeList(ArrayItem)));
        ancestor->_focusedChildren->remove(scopeFocus);
        ancestor->_focusedChildren->add(scopeFocus);
        scopeFocus = ancestor;
    }
}

FocusScopeNodeCls::FocusScopeNodeCls(bool canRequestFocus, String debugLabel, FocusOnKeyCallback onKey, FocusOnKeyEventCallback onKeyEvent, bool skipTraversal) : FocusNode(true) {
    {
        assert(skipTraversal != nullptr);
        assert(canRequestFocus != nullptr);
    }
}

FocusScopeNode FocusScopeNodeCls::nearestScope() {
    return this;
}

bool FocusScopeNodeCls::isFirstFocus() {
    return enclosingScope()!->focusedChild() == this;
}

FocusNode FocusScopeNodeCls::focusedChild() {
    assert(_focusedChildren->isEmpty() || _focusedChildren->last->enclosingScope == this, __s("Focused child does not have the same idea of its enclosing scope as the scope does."));
    return _focusedChildren->isNotEmpty()? _focusedChildren->last : nullptr;
}

Iterable<FocusNode> FocusScopeNodeCls::traversalChildren() {
    if (!canRequestFocus()) {
        return <FocusNode>empty();
    }
    return super->traversalChildren;
}

Iterable<FocusNode> FocusScopeNodeCls::traversalDescendants() {
    if (!canRequestFocus()) {
        return <FocusNode>empty();
    }
    return super->traversalDescendants;
}

void FocusScopeNodeCls::setFirstFocus(FocusScopeNode scope) {
    assert(scope != nullptr);
    assert(scope != this, __s("Unexpected self-reference in setFirstFocus."));
    assert(_focusDebug(__sf("Setting scope as first focus in %s to node:", this), makeList(ArrayItem)));
    if (scope->_parent == nullptr) {
        _reparent(scope);
    }
    assert(scope->ancestors()->contains(this), __sf("%s %s must be a child of %s to set it as first focus.", FocusScopeNodeCls, scope, this));
    if (hasFocus()) {
        scope->_doRequestFocus(true);
    } else {
        scope->_setAsFocusedChildForScope();
    }
}

void FocusScopeNodeCls::autofocus(FocusNode node) {
    if (node->_parent == nullptr) {
        _reparent(node);
    }
    assert(_manager != nullptr);
    assert(_focusDebug(__sf("Autofocus scheduled for %s: scope %s", node, this)));
    _manager?->_pendingAutofocuses->add(make<_AutofocusCls>(this, node));
    _manager?->_markNeedsUpdate();
}

void FocusScopeNodeCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    if (_focusedChildren->isEmpty()) {
        return;
    }
    List<String> childList = _focusedChildren->reversed()-><String>map([=] (FocusNode child) {
    return child->toStringShort();
})->toList();
    properties->add(<String>make<IterablePropertyCls>(__s("focusedChildren"), childList, <String>empty()));
}

void FocusScopeNodeCls::_doRequestFocus(bool findFirstFocus) {
    assert(findFirstFocus != nullptr);
    while (this->focusedChild() != nullptr && !this->focusedChild()!->canRequestFocus()) {
        _focusedChildren->removeLast();
    }
    FocusNode focusedChild = this->focusedChild();
    if (!findFirstFocus || focusedChild == nullptr) {
        if (canRequestFocus()) {
            _setAsFocusedChildForScope();
            _markNextFocus(this);
        }
        return;
    }
    focusedChild->_doRequestFocus(true);
}

FocusManagerCls::FocusManagerCls() {
    {
        rootScope->_manager = this;
    }
}

void FocusManagerCls::registerGlobalHandlers() {
    assert(ServicesBindingCls::instance->keyEventManager->keyMessageHandler == nullptr);
    ServicesBindingCls::instance->keyEventManager->keyMessageHandler = _handleKeyMessage;
    GestureBindingCls::instance->pointerRouter->addGlobalRoute(_handlePointerEvent);
}

void FocusManagerCls::dispose() {
    if (ServicesBindingCls::instance->keyEventManager->keyMessageHandler == _handleKeyMessage) {
        ServicesBindingCls::instance->keyEventManager->keyMessageHandler = nullptr;
        GestureBindingCls::instance->pointerRouter->removeGlobalRoute(_handlePointerEvent);
    }
    super->dispose();
}

FocusManager FocusManagerCls::instance() {
    return WidgetsBindingCls::instance->focusManager;
}

FocusHighlightStrategy FocusManagerCls::highlightStrategy() {
    return _highlightStrategy;
}

void FocusManagerCls::highlightStrategy(FocusHighlightStrategy highlightStrategy) {
    _highlightStrategy = highlightStrategy;
    _updateHighlightMode();
}

FocusHighlightMode FocusManagerCls::highlightMode() {
    return _highlightMode | _defaultModeForPlatform();
}

void FocusManagerCls::addHighlightModeListener(ValueChanged<FocusHighlightMode> listener) {
    return _listeners->add(listener);
}

void FocusManagerCls::removeHighlightModeListener(ValueChanged<FocusHighlightMode> listener) {
    return _listeners->remove(listener);
}

FocusNode FocusManagerCls::primaryFocus() {
    return _primaryFocus;
}

List<DiagnosticsNode> FocusManagerCls::debugDescribeChildren() {
    return makeList(ArrayItem);
}

void FocusManagerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    properties->add(make<FlagPropertyCls>(__s("haveScheduledUpdate"), _haveScheduledUpdate, __s("UPDATE SCHEDULED")));
    properties->add(<FocusNode>make<DiagnosticsPropertyCls>(__s("primaryFocus"), primaryFocus(), nullptr));
    properties->add(<FocusNode>make<DiagnosticsPropertyCls>(__s("nextFocus"), _markedForFocus, nullptr));
    Element element = as<Element>(primaryFocus()?->context());
    if (element != nullptr) {
        properties->add(<String>make<DiagnosticsPropertyCls>(__s("primaryFocusCreator"), element->debugGetCreatorChain(20)));
    }
}

FocusHighlightMode FocusManagerCls::_defaultModeForPlatform() {
    ;
}

void FocusManagerCls::_updateHighlightMode() {
    FocusHighlightMode newMode;
    ;
    FocusHighlightMode oldMode = highlightMode();
    _highlightMode = newMode;
    if (highlightMode() != oldMode) {
        _notifyHighlightModeListeners();
    }
}

void FocusManagerCls::_notifyHighlightModeListeners() {
    if (_listeners->isEmpty()) {
        return;
    }
    List<ValueChanged<FocusHighlightMode>> localListeners = <ValueChanged<FocusHighlightMode>>of(_listeners);
    for (ValueChanged<FocusHighlightMode> listener : localListeners) {
        try {
            if (_listeners->contains(listener)) {
                listener(highlightMode());
            }
        } catch (Unknown exception) {
            InformationCollector collector;
            assert([=] () {
                collector = [=] () {
                    makeList(ArrayItem);
                };
                return true;
            }());
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("widgets library"), make<ErrorDescriptionCls>(__sf("while dispatching notifications for %s", runtimeType)), collector));
        };
    }
}

void FocusManagerCls::_handlePointerEvent(PointerEvent event) {
    FocusHighlightMode expectedMode;
    ;
    if (expectedMode != highlightMode()) {
        _updateHighlightMode();
    }
}

bool FocusManagerCls::_handleKeyMessage(KeyMessage message) {
    _lastInteractionWasTouch = false;
    _updateHighlightMode();
    assert(_focusDebug(__sf("Received key event %s", message)));
    if (_primaryFocus == nullptr) {
        assert(_focusDebug(__sf("No primary focus for key event, ignored: %s", message)));
        return false;
    }
    bool handled = false;
    for (FocusNode node : list1) {
            List<FocusNode> list1 = make<ListCls<>>();    list1.add(ArrayItem);    for (auto _x1 : _primaryFocus!->ancestors()) {    {        list1.add(_x1);    }List<KeyEventResult> results = makeList();
        if (node->onKeyEvent != nullptr) {
            for (KeyEvent event : message->events) {
                results->add(node->onKeyEvent!(node, event));
            }
        }
        if (node->onKey != nullptr && message->rawEvent != nullptr) {
            results->add(node->onKey!(node, message->rawEvent!));
        }
        KeyEventResult result = combineKeyEventResults(results);
        ;
        assert(result != KeyEventResultCls::ignored);
        break;
    }
    if (!handled) {
        assert(_focusDebug(__sf("Key event not handled by anyone: %s.", message)));
    }
    return handled;
}

void FocusManagerCls::_markDetached(FocusNode node) {
    assert(_focusDebug(__sf("Node was detached: %s", node)));
    if (_primaryFocus == node) {
        _primaryFocus = nullptr;
    }
    _dirtyNodes->remove(node);
}

void FocusManagerCls::_markPropertiesChanged(FocusNode node) {
    _markNeedsUpdate();
    assert(_focusDebug(__sf("Properties changed for node %s.", node)));
    _dirtyNodes->add(node);
}

void FocusManagerCls::_markNextFocus(FocusNode node) {
    if (_primaryFocus == node) {
        _markedForFocus = nullptr;
    } else {
        _markedForFocus = node;
        _markNeedsUpdate();
    }
}

void FocusManagerCls::_markNeedsUpdate() {
    assert(_focusDebug(__sf("Scheduling update, current focus is %s, next focus will be %s", _primaryFocus, _markedForFocus)));
    if (_haveScheduledUpdate) {
        return;
    }
    _haveScheduledUpdate = true;
    scheduleMicrotask(_applyFocusChange);
}

void FocusManagerCls::_applyFocusChange() {
    _haveScheduledUpdate = false;
    FocusNode previousFocus = _primaryFocus;
    for (_Autofocus autofocus : _pendingAutofocuses) {
        autofocus->applyIfValid(this);
    }
    _pendingAutofocuses->clear();
    if (_primaryFocus == nullptr && _markedForFocus == nullptr) {
        _markedForFocus = rootScope;
    }
    assert(_focusDebug(__sf("Refreshing focus state. Next focus will be %s", _markedForFocus)));
    if (_markedForFocus != nullptr && _markedForFocus != _primaryFocus) {
        Set<FocusNode> previousPath = previousFocus?->ancestors()->toSet() | makeSet();
        Set<FocusNode> nextPath = _markedForFocus!->ancestors()->toSet();
        _dirtyNodes->addAll(nextPath->difference(previousPath));
        _dirtyNodes->addAll(previousPath->difference(nextPath));
        _primaryFocus = _markedForFocus;
        _markedForFocus = nullptr;
    }
    assert(_markedForFocus == nullptr);
    if (previousFocus != _primaryFocus) {
        assert(_focusDebug(__sf("Updating focus from %s to %s", previousFocus, _primaryFocus)));
        if (previousFocus != nullptr) {
            _dirtyNodes->add(previousFocus);
        }
        if (_primaryFocus != nullptr) {
            _dirtyNodes->add(_primaryFocus!);
        }
    }
    for (FocusNode node : _dirtyNodes) {
        node->_notify();
    }
    assert(_focusDebug(__sf("Notified %s dirty nodes:", _dirtyNodes->length()), _dirtyNodes->toList()-><String>map([=] (FocusNode node) {
        node->toString();
    })));
    _dirtyNodes->clear();
    if (previousFocus != _primaryFocus) {
        notifyListeners();
    }
    assert([=] () {
        if (debugFocusChanges) {
            debugDumpFocusTree();
        }
        return true;
    }());
}

FocusNode primaryFocus() {
    return WidgetsBindingCls::instance->focusManager->primaryFocus;
}

String debugDescribeFocusTree() {
    assert(WidgetsBindingCls::instance != nullptr);
    String result;
    assert([=] () {
        result = FocusManagerCls::instance->toStringDeep();
        return true;
    }());
    return result | __s("");
}

void debugDumpFocusTree() {
    assert([=] () {
        debugPrint(debugDescribeFocusTree());
        return true;
    }());
}
