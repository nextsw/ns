#include "keyboard_listener.hpp"
KeyboardListenerCls::KeyboardListenerCls(bool autofocus, Widget child, FocusNode focusNode, bool includeSemantics, Unknown key, ValueChanged<KeyEvent> onKeyEvent) {
    {
        assert(focusNode != nullptr);
        assert(autofocus != nullptr);
        assert(includeSemantics != nullptr);
        assert(child != nullptr);
    }
}

Widget KeyboardListenerCls::build(BuildContext context) {
    return make<FocusCls>(focusNode, autofocus, includeSemantics, [=] (FocusNode node,KeyEvent event) {
        onKeyEvent?->call(event);
        return KeyEventResultCls::ignored;
    }, child);
}

void KeyboardListenerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<FocusNode>make<DiagnosticsPropertyCls>("focusNode", focusNode));
}
