#ifndef FOCUS_SCOPE_H
#define FOCUS_SCOPE_H
#include <memory>

#include <flutter/foundation.hpp>
#include "basic.hpp"
#include "focus_manager.hpp"
#include "framework.hpp"
#include "inherited_notifier.hpp"



class Focus : StatefulWidget {
public:
    Widget child;

    FocusNode focusNode;

    bool autofocus;

    ValueChanged<bool> onFocusChange;

    bool includeSemantics;


     Focus(bool autofocus, bool canRequestFocus, Widget child, String debugLabel, bool descendantsAreFocusable, bool descendantsAreTraversable, FocusNode focusNode, bool includeSemantics, Unknown, ValueChanged<bool> onFocusChange, FocusOnKeyCallback onKey, FocusOnKeyEventCallback onKeyEvent, bool skipTraversal);

    void  withExternalFocusNode(bool autofocus, Widget child, FocusNode focusNode, bool includeSemantics, Key key, ValueChanged<bool> onFocusChange);

    FocusOnKeyEventCallback onKeyEvent();

    FocusOnKeyCallback onKey();

    bool canRequestFocus();

    bool skipTraversal();

    bool descendantsAreFocusable();

    bool descendantsAreTraversable();

    String debugLabel();

    static FocusNode of(BuildContext context, bool scopeOk);

    static FocusNode maybeOf(BuildContext context, bool scopeOk);

    static bool isAt(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    State<Focus> createState();

private:
    FocusOnKeyEventCallback _onKeyEvent;

    FocusOnKeyCallback _onKey;

    bool _canRequestFocus;

    bool _skipTraversal;

    bool _descendantsAreFocusable;

    bool _descendantsAreTraversable;

    String _debugLabel;


    bool _usingExternalFocus();

};

class _FocusWithExternalFocusNode : Focus {
public:

    FocusOnKeyEventCallback onKeyEvent();

    FocusOnKeyCallback onKey();

    bool canRequestFocus();

    bool skipTraversal();

    bool descendantsAreFocusable();

    String debugLabel();

private:

     _FocusWithExternalFocusNode(Unknown, Unknown, FocusNode focusNode, Unknown, Unknown, Unknown);

    bool _usingExternalFocus();

    bool _descendantsAreTraversable();

};

class _FocusState : State<Focus> {
public:

    FocusNode focusNode();

    void initState();

    void dispose();

    void didChangeDependencies();

    void deactivate();

    void didUpdateWidget(Focus oldWidget);

    Widget build(BuildContext context);

private:
    FocusNode _internalNode;

    bool _hadPrimaryFocus;

    bool _couldRequestFocus;

    bool _descendantsWereFocusable;

    bool _descendantsWereTraversable;

    bool _didAutofocus;

    FocusAttachment _focusAttachment;


    void _initNode();

    FocusNode _createNode();

    void _handleAutofocus();

    void _handleFocusChanged();

};

class FocusScope : Focus {
public:

     FocusScope(Unknown, Unknown, Unknown, Unknown, Unknown, FocusScopeNode node, Unknown, Unknown, Unknown, Unknown);

    void  withExternalFocusNode(bool autofocus, Widget child, FocusScopeNode focusScopeNode, Key key, ValueChanged<bool> onFocusChange);

    static FocusScopeNode of(BuildContext context);

    State<Focus> createState();

private:

};

class _FocusScopeWithExternalFocusNode : FocusScope {
public:

    FocusOnKeyEventCallback onKeyEvent();

    FocusOnKeyCallback onKey();

    bool canRequestFocus();

    bool skipTraversal();

    bool descendantsAreFocusable();

    bool descendantsAreTraversable();

    String debugLabel();

private:

     _FocusScopeWithExternalFocusNode(Unknown, Unknown, FocusScopeNode focusScopeNode, Unknown, Unknown);

    bool _usingExternalFocus();

};

class _FocusScopeState : _FocusState {
public:

    Widget build(BuildContext context);

private:

    FocusScopeNode _createNode();

};

class _FocusMarker : InheritedNotifier<FocusNode> {
public:

private:

     _FocusMarker(Unknown, FocusNode node);

};

class ExcludeFocus : StatelessWidget {
public:
    bool excluding;

    Widget child;


     ExcludeFocus(Widget child, bool excluding, Unknown);

    Widget build(BuildContext context);

private:

};

#endif