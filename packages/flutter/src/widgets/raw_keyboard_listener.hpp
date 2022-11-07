#ifndef RAW_KEYBOARD_LISTENER_H
#define RAW_KEYBOARD_LISTENER_H
#include <memory>
#include <flutter/services.hpp>

#include <flutter/foundation.hpp>
#include <flutter/services.hpp>
#include "focus_manager.hpp"
#include "focus_scope.hpp"
#include "framework.hpp"



class RawKeyboardListener : StatefulWidget {
public:
    FocusNode focusNode;

    bool autofocus;

    bool includeSemantics;

    ValueChanged<RawKeyEvent> onKey;

    Widget child;


     RawKeyboardListener(bool autofocus, Widget child, FocusNode focusNode, bool includeSemantics, Unknown, ValueChanged<RawKeyEvent> onKey);

    State<RawKeyboardListener> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _RawKeyboardListenerState : State<RawKeyboardListener> {
public:

    void initState();

    void didUpdateWidget(RawKeyboardListener oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:
    bool _listening;


    void _handleFocusChanged();

    void _attachKeyboardIfDetached();

    void _detachKeyboardIfAttached();

    void _handleRawKeyEvent(RawKeyEvent event);

};

#endif