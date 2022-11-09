#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_FOCUS_MANAGER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_FOCUS_MANAGER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
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


class _AutofocusCls : public ObjectCls {
public:
    FocusScopeNode scope;

    FocusNode autofocusNode;


    virtual void applyIfValid(FocusManager manager);

private:

     _AutofocusCls(FocusNode autofocusNode, FocusScopeNode scope);
};
using _Autofocus = std::shared_ptr<_AutofocusCls>;

class FocusAttachmentCls : public ObjectCls {
public:

    virtual bool isAttached();

    virtual void detach();

    virtual void reparent(FocusNode parent);

private:
    FocusNode _node;


    virtual void  _(FocusNode _node);

};
using FocusAttachment = std::shared_ptr<FocusAttachmentCls>;

enum UnfocusDisposition{
    scope,
    previouslyFocusedChild,
} // end UnfocusDisposition

class FocusNodeCls : public ObjectCls {
public:
    FocusOnKeyCallback onKey;

    FocusOnKeyEventCallback onKeyEvent;


     FocusNodeCls(bool canRequestFocus, String debugLabel, bool descendantsAreFocusable, bool descendantsAreTraversable, FocusOnKeyCallback onKey, FocusOnKeyEventCallback onKeyEvent, bool skipTraversal);

    virtual bool skipTraversal();

    virtual void  skipTraversal(bool value);

    virtual bool canRequestFocus();

    virtual void  canRequestFocus(bool value);

    virtual bool descendantsAreFocusable();

    virtual void  descendantsAreFocusable(bool value);

    virtual bool descendantsAreTraversable();

    virtual void  descendantsAreTraversable(bool value);

    virtual BuildContext context();

    virtual FocusNode parent();

    virtual Iterable<FocusNode> children();

    virtual Iterable<FocusNode> traversalChildren();

    virtual String debugLabel();

    virtual void  debugLabel(String value);

    virtual Iterable<FocusNode> descendants();

    virtual Iterable<FocusNode> traversalDescendants();

    virtual Iterable<FocusNode> ancestors();

    virtual bool hasFocus();

    virtual bool hasPrimaryFocus();

    virtual FocusHighlightMode highlightMode();

    virtual FocusScopeNode nearestScope();

    virtual FocusScopeNode enclosingScope();

    virtual Size size();

    virtual Offset offset();

    virtual Rect rect();

    virtual void unfocus(UnfocusDisposition disposition);

    virtual bool consumeKeyboardToken();

    virtual FocusAttachment attach(BuildContext context, FocusOnKeyCallback onKey, FocusOnKeyEventCallback onKeyEvent);

    virtual void dispose();

    virtual void requestFocus(FocusNode node);

    virtual bool nextFocus();

    virtual bool previousFocus();

    virtual bool focusInDirection(TraversalDirection direction);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual List<DiagnosticsNode> debugDescribeChildren();

    virtual String toStringShort();

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


    virtual void _markNextFocus(FocusNode newFocus);

    virtual void _removeChild(FocusNode node, bool removeScopeFocus);

    virtual void _updateManager(FocusManager manager);

    virtual void _reparent(FocusNode child);

    virtual void _notify();

    virtual void _doRequestFocus(bool findFirstFocus);

    virtual void _setAsFocusedChildForScope();

};
using FocusNode = std::shared_ptr<FocusNodeCls>;

class FocusScopeNodeCls : public FocusNodeCls {
public:

     FocusScopeNodeCls(Unknown canRequestFocus, Unknown debugLabel, Unknown onKey, Unknown onKeyEvent, Unknown skipTraversal);

    virtual FocusScopeNode nearestScope();

    virtual bool isFirstFocus();

    virtual FocusNode focusedChild();

    virtual Iterable<FocusNode> traversalChildren();

    virtual Iterable<FocusNode> traversalDescendants();

    virtual void setFirstFocus(FocusScopeNode scope);

    virtual void autofocus(FocusNode node);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    List<FocusNode> _focusedChildren;


    virtual void _doRequestFocus(bool findFirstFocus);

};
using FocusScopeNode = std::shared_ptr<FocusScopeNodeCls>;

enum FocusHighlightMode{
    touch,
    traditional,
} // end FocusHighlightMode

enum FocusHighlightStrategy{
    automatic,
    alwaysTouch,
    alwaysTraditional,
} // end FocusHighlightStrategy

class FocusManagerCls : public ObjectCls {
public:
    FocusScopeNode rootScope;


     FocusManagerCls();

    virtual void registerGlobalHandlers();

    virtual void dispose();

    static FocusManager instance();

    virtual FocusHighlightStrategy highlightStrategy();

    virtual void  highlightStrategy(FocusHighlightStrategy highlightStrategy);

    virtual FocusHighlightMode highlightMode();

    virtual void addHighlightModeListener(ValueChanged<FocusHighlightMode> listener);

    virtual void removeHighlightModeListener(ValueChanged<FocusHighlightMode> listener);

    virtual FocusNode primaryFocus();

    virtual List<DiagnosticsNode> debugDescribeChildren();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

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

    virtual void _updateHighlightMode();

    virtual void _notifyHighlightModeListeners();

    virtual void _handlePointerEvent(PointerEvent event);

    virtual bool _handleKeyMessage(KeyMessage message);

    virtual void _markDetached(FocusNode node);

    virtual void _markPropertiesChanged(FocusNode node);

    virtual void _markNextFocus(FocusNode node);

    virtual void _markNeedsUpdate();

    virtual void _applyFocusChange();

};
using FocusManager = std::shared_ptr<FocusManagerCls>;
FocusNode primaryFocus();

String debugDescribeFocusTree();

void debugDumpFocusTree();



#endif