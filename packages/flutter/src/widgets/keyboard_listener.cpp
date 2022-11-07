#include "keyboard_listener.hpp"
KeyboardListener::KeyboardListener(bool autofocus, Widget child, FocusNode focusNode, bool includeSemantics, Unknown, ValueChanged<KeyEvent> onKeyEvent) {
    {
        assert(focusNode != nullptr);
        assert(autofocus != nullptr);
        assert(includeSemantics != nullptr);
        assert(child != nullptr);
    }
}

Widget KeyboardListener::build(BuildContext context) {
    return Focus(focusNode, autofocus, includeSemantics, , child);
}

void KeyboardListener::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<FocusNode>DiagnosticsProperty("focusNode", focusNode));
}
