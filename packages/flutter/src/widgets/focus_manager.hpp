#ifndef FOCUS_MANAGER_H
#define FOCUS_MANAGER_H
#include <memory>

#include <async/async.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/painting.hpp>
#include <flutter/services.hpp>
#include "binding.hpp"
#include "focus_scope.hpp"
#include "focus_traversal.hpp"
#include "framework.hpp"


bool debugFocusChanges;

bool _focusDebug(Iterable<String> details, String message);


enum KeyEventResult{
    handled,
    ignored,
    skipRemainingHandlers,
} // end KeyEventResult
KeyEventResult combineKeyEventResults(Iterable<KeyEventResult> results);


class _Autofocus {
public:
    FocusScopeNode scope;

    FocusNode autofocusNode;


    void applyIfValid(FocusManager manager);

private:

     _Autofocus(FocusNode autofocusNode, FocusScopeNode scope);

};

class FocusAttachment {
public:

    bool isAttached();

    void detach();

    void reparent(FocusNode parent);

private:
    FocusNode _node;


    void  _(FocusNode _node);

};

enum UnfocusDisposition{
    scope,
    previouslyFocusedChild,
} // end UnfocusDisposition

class FocusNode {
public:
    FocusOnKeyCallback onKey;

    FocusOnKeyEventCallback onKeyEvent;


     FocusNode(bool canRequestFocus, String debugLabel, bool descendantsAreFocusable, bool descendantsAreTraversable, FocusOnKeyCallback onKey, FocusOnKeyEventCallback onKeyEvent, bool skipTraversal);

    bool skipTraversal();

    void  skipTraversal(bool value);

    bool canRequestFocus();

    void  canRequestFocus(bool value);

    bool descendantsAreFocusable();

    void  descendantsAreFocusable(bool value);

    bool descendantsAreTraversable();

    void  descendantsAreTraversable(bool value);

    BuildContext context();

    FocusNode parent();

    Iterable<FocusNode> children();

    Iterable<FocusNode> traversalChildren();

    String debugLabel();

    void  debugLabel(String value);

    Iterable<FocusNode> descendants();

    Iterable<FocusNode> traversalDescendants();

    Iterable<FocusNode> ancestors();

    bool hasFocus();

    bool hasPrimaryFocus();

    FocusHighlightMode highlightMode();

    FocusScopeNode nearestScope();

    FocusScopeNode enclosingScope();

    Size size();

    Offset offset();

    Rect rect();

    void unfocus(UnfocusDisposition disposition);

    bool consumeKeyboardToken();

    FocusAttachment attach(BuildContext context, FocusOnKeyCallback onKey, FocusOnKeyEventCallback onKeyEvent);

    void dispose();

    void requestFocus(FocusNode node);

    bool nextFocus();

    bool previousFocus();

    bool focusInDirection(TraversalDirection direction);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    List<DiagnosticsNode> debugDescribeChildren();

    String toStringShort();

private:
    bool _skipTraversal;

    bool _canRequestFocus;

    bool _descendantsAreFocusable;

    bool _descendantsAreTraversable;

    BuildContext _context;

    FocusManager _manager;

    List<FocusNode> _ancestors;

    List<FocusNode> _descendants;

    bool _hasKeyboardToken;

    FocusNode _parent;

    List<FocusNode> _children;

    String _debugLabel;

    FocusAttachment _attachment;

    bool _requestFocusWhenReparented;


    void _markNextFocus(FocusNode newFocus);

    void _removeChild(FocusNode node, bool removeScopeFocus);

    void _updateManager(FocusManager manager);

    void _reparent(FocusNode child);

    void _notify();

    void _doRequestFocus(bool findFirstFocus);

    void _setAsFocusedChildForScope();

};

class FocusScopeNode : FocusNode {
public:

     FocusScopeNode(Unknown, Unknown, Unknown, Unknown, Unknown);

    FocusScopeNode nearestScope();

    bool isFirstFocus();

    FocusNode focusedChild();

    Iterable<FocusNode> traversalChildren();

    Iterable<FocusNode> traversalDescendants();

    void setFirstFocus(FocusScopeNode scope);

    void autofocus(FocusNode node);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    List<FocusNode> _focusedChildren;


    void _doRequestFocus(bool findFirstFocus);

};

enum FocusHighlightMode{
    touch,
    traditional,
} // end FocusHighlightMode

enum FocusHighlightStrategy{
    automatic,
    alwaysTouch,
    alwaysTraditional,
} // end FocusHighlightStrategy

class FocusManager {
public:
    FocusScopeNode rootScope;


     FocusManager();

    void registerGlobalHandlers();

    void dispose();

    static FocusManager instance();

    FocusHighlightStrategy highlightStrategy();

    void  highlightStrategy(FocusHighlightStrategy highlightStrategy);

    FocusHighlightMode highlightMode();

    void addHighlightModeListener(ValueChanged<FocusHighlightMode> listener);

    void removeHighlightModeListener(ValueChanged<FocusHighlightMode> listener);

    FocusNode primaryFocus();

    List<DiagnosticsNode> debugDescribeChildren();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    FocusHighlightStrategy _highlightStrategy;

    FocusHighlightMode _highlightMode;

    bool _lastInteractionWasTouch;

    HashedObserverList<ValueChanged<FocusHighlightMode>> _listeners;

    FocusNode _primaryFocus;

    Set<FocusNode> _dirtyNodes;

    FocusNode _markedForFocus;

    List<_Autofocus> _pendingAutofocuses;

    bool _haveScheduledUpdate;


    static FocusHighlightMode _defaultModeForPlatform();

    void _updateHighlightMode();

    void _notifyHighlightModeListeners();

    void _handlePointerEvent(PointerEvent event);

    bool _handleKeyMessage(KeyMessage message);

    void _markDetached(FocusNode node);

    void _markPropertiesChanged(FocusNode node);

    void _markNextFocus(FocusNode node);

    void _markNeedsUpdate();

    void _applyFocusChange();

};
FocusNode primaryFocus();

String debugDescribeFocusTree();

void debugDumpFocusTree();


#endif