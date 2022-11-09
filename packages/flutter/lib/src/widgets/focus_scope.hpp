#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_FOCUS_SCOPE
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_FOCUS_SCOPE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic.hpp"
#include "focus_manager.hpp"
#include "framework.hpp"
#include "inherited_notifier.hpp"


class FocusCls : public StatefulWidgetCls {
public:
    Widget child;

    FocusNode focusNode;

    bool autofocus;

    ValueChanged<bool> onFocusChange;

    bool includeSemantics;


     FocusCls(bool autofocus, bool canRequestFocus, Widget child, String debugLabel, bool descendantsAreFocusable, bool descendantsAreTraversable, FocusNode focusNode, bool includeSemantics, Unknown key, ValueChanged<bool> onFocusChange, FocusOnKeyCallback onKey, FocusOnKeyEventCallback onKeyEvent, bool skipTraversal);

    virtual void  withExternalFocusNode(bool autofocus, Widget child, FocusNode focusNode, bool includeSemantics, Key key, ValueChanged<bool> onFocusChange);
    virtual FocusOnKeyEventCallback onKeyEvent();

    virtual FocusOnKeyCallback onKey();

    virtual bool canRequestFocus();

    virtual bool skipTraversal();

    virtual bool descendantsAreFocusable();

    virtual bool descendantsAreTraversable();

    virtual String debugLabel();

    static FocusNode of(BuildContext context, bool scopeOk);

    static FocusNode maybeOf(BuildContext context, bool scopeOk);

    static bool isAt(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual State<Focus> createState();

private:
    FocusOnKeyEventCallback _onKeyEvent;

    FocusOnKeyCallback _onKey;

    bool _canRequestFocus;

    bool _skipTraversal;

    bool _descendantsAreFocusable;

    bool _descendantsAreTraversable;

    String _debugLabel;


    virtual bool _usingExternalFocus();

};
using Focus = std::shared_ptr<FocusCls>;

class _FocusWithExternalFocusNodeCls : public FocusCls {
public:

    virtual FocusOnKeyEventCallback onKeyEvent();

    virtual FocusOnKeyCallback onKey();

    virtual bool canRequestFocus();

    virtual bool skipTraversal();

    virtual bool descendantsAreFocusable();

    virtual String debugLabel();

private:

     _FocusWithExternalFocusNodeCls(Unknown autofocus, Unknown child, FocusNode focusNode, Unknown includeSemantics, Unknown key, Unknown onFocusChange);
    virtual bool _usingExternalFocus();

    virtual bool _descendantsAreTraversable();

};
using _FocusWithExternalFocusNode = std::shared_ptr<_FocusWithExternalFocusNodeCls>;

class _FocusStateCls : public StateCls<Focus> {
public:

    virtual FocusNode focusNode();

    virtual void initState();

    virtual void dispose();

    virtual void didChangeDependencies();

    virtual void deactivate();

    virtual void didUpdateWidget(Focus oldWidget);

    virtual Widget build(BuildContext context);

private:
    FocusNode _internalNode;

    bool _hadPrimaryFocus;

    bool _couldRequestFocus;

    bool _descendantsWereFocusable;

    bool _descendantsWereTraversable;

    bool _didAutofocus;

    FocusAttachment _focusAttachment;


    virtual void _initNode();

    virtual FocusNode _createNode();

    virtual void _handleAutofocus();

    virtual void _handleFocusChanged();

};
using _FocusState = std::shared_ptr<_FocusStateCls>;

class FocusScopeCls : public FocusCls {
public:

     FocusScopeCls(Unknown autofocus, Unknown canRequestFocus, Unknown child, Unknown debugLabel, Unknown key, FocusScopeNode node, Unknown onFocusChange, Unknown onKey, Unknown onKeyEvent, Unknown skipTraversal);

    virtual void  withExternalFocusNode(bool autofocus, Widget child, FocusScopeNode focusScopeNode, Key key, ValueChanged<bool> onFocusChange) override;
    static FocusScopeNode of(BuildContext context);

    virtual State<Focus> createState();

private:

};
using FocusScope = std::shared_ptr<FocusScopeCls>;

class _FocusScopeWithExternalFocusNodeCls : public FocusScopeCls {
public:

    virtual FocusOnKeyEventCallback onKeyEvent();

    virtual FocusOnKeyCallback onKey();

    virtual bool canRequestFocus();

    virtual bool skipTraversal();

    virtual bool descendantsAreFocusable();

    virtual bool descendantsAreTraversable();

    virtual String debugLabel();

private:

     _FocusScopeWithExternalFocusNodeCls(Unknown autofocus, Unknown child, FocusScopeNode focusScopeNode, Unknown key, Unknown onFocusChange);

    virtual bool _usingExternalFocus();

};
using _FocusScopeWithExternalFocusNode = std::shared_ptr<_FocusScopeWithExternalFocusNodeCls>;

class _FocusScopeStateCls : public _FocusStateCls {
public:

    virtual Widget build(BuildContext context);

private:

    virtual FocusScopeNode _createNode();

};
using _FocusScopeState = std::shared_ptr<_FocusScopeStateCls>;

class _FocusMarkerCls : public InheritedNotifierCls<FocusNode> {
public:

private:

     _FocusMarkerCls(Unknown child, FocusNode node);

};
using _FocusMarker = std::shared_ptr<_FocusMarkerCls>;

class ExcludeFocusCls : public StatelessWidgetCls {
public:
    bool excluding;

    Widget child;


     ExcludeFocusCls(Widget child, bool excluding, Unknown key);

    virtual Widget build(BuildContext context);

private:

};
using ExcludeFocus = std::shared_ptr<ExcludeFocusCls>;


#endif