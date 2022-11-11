#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_KEYBOARD_LISTENER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_KEYBOARD_LISTENER
#include <base.hpp>
#include <packages/flutter/flutter.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "focus_manager.hpp"
#include "focus_scope.hpp"
#include "framework.hpp"


class KeyboardListenerCls : public StatelessWidgetCls {
public:
    FocusNode focusNode;

    bool autofocus;

    bool includeSemantics;

    ValueChanged<KeyEvent> onKeyEvent;

    Widget child;


     KeyboardListenerCls(bool autofocus, Widget child, FocusNode focusNode, bool includeSemantics, Key key, ValueChanged<KeyEvent> onKeyEvent);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using KeyboardListener = std::shared_ptr<KeyboardListenerCls>;


#endif