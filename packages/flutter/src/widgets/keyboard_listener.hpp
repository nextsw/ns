#ifndef KEYBOARD_LISTENER_H
#define KEYBOARD_LISTENER_H
#include <memory>
#include <flutter/services.hpp>

#include <flutter/foundation.hpp>
#include <flutter/services.hpp>
#include "focus_manager.hpp"
#include "focus_scope.hpp"
#include "framework.hpp"



class KeyboardListener : StatelessWidget {
public:
    FocusNode focusNode;

    bool autofocus;

    bool includeSemantics;

    ValueChanged<KeyEvent> onKeyEvent;

    Widget child;


     KeyboardListener(bool autofocus, Widget child, FocusNode focusNode, bool includeSemantics, Unknown, ValueChanged<KeyEvent> onKeyEvent);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

#endif