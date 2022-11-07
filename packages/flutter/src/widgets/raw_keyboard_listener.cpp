#include "raw_keyboard_listener.hpp"
RawKeyboardListener::RawKeyboardListener(bool autofocus, Widget child, FocusNode focusNode, bool includeSemantics, Unknown, ValueChanged<RawKeyEvent> onKey) {
    {
        assert(focusNode != nullptr);
        assert(autofocus != nullptr);
        assert(includeSemantics != nullptr);
        assert(child != nullptr);
    }
}

State<RawKeyboardListener> RawKeyboardListener::createState() {
    return _RawKeyboardListenerState();
}

void RawKeyboardListener::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<FocusNode>DiagnosticsProperty("focusNode", focusNode));
}

void _RawKeyboardListenerState::initState() {
    super.initState();
    widget.focusNode.addListener(_handleFocusChanged);
}

void _RawKeyboardListenerState::didUpdateWidget(RawKeyboardListener oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (widget.focusNode != oldWidget.focusNode) {
        oldWidget.focusNode.removeListener(_handleFocusChanged);
        widget.focusNode.addListener(_handleFocusChanged);
    }
}

void _RawKeyboardListenerState::dispose() {
    widget.focusNode.removeListener(_handleFocusChanged);
    _detachKeyboardIfAttached();
    super.dispose();
}

Widget _RawKeyboardListenerState::build(BuildContext context) {
    return Focus(widget.focusNode, widget.autofocus, widget.includeSemantics, widget.child);
}

void _RawKeyboardListenerState::_handleFocusChanged() {
    if (widget.focusNode.hasFocus) {
        _attachKeyboardIfDetached();
    } else {
        _detachKeyboardIfAttached();
    }
}

void _RawKeyboardListenerState::_attachKeyboardIfDetached() {
    if (_listening) {
        return;
    }
    RawKeyboard.instance.addListener(_handleRawKeyEvent);
    _listening = true;
}

void _RawKeyboardListenerState::_detachKeyboardIfAttached() {
    if (!_listening) {
        return;
    }
    RawKeyboard.instance.removeListener(_handleRawKeyEvent);
    _listening = false;
}

void _RawKeyboardListenerState::_handleRawKeyEvent(RawKeyEvent event) {
    widget.onKey?.call(event);
}
