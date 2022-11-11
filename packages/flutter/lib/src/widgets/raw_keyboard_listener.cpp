#include "raw_keyboard_listener.hpp"
RawKeyboardListenerCls::RawKeyboardListenerCls(bool autofocus, Widget child, FocusNode focusNode, bool includeSemantics, Key key, ValueChanged<RawKeyEvent> onKey) {
    {
        assert(focusNode != nullptr);
        assert(autofocus != nullptr);
        assert(includeSemantics != nullptr);
        assert(child != nullptr);
    }
}

State<RawKeyboardListener> RawKeyboardListenerCls::createState() {
    return make<_RawKeyboardListenerStateCls>();
}

void RawKeyboardListenerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<FocusNode>make<DiagnosticsPropertyCls>(__s("focusNode"), focusNode));
}

void _RawKeyboardListenerStateCls::initState() {
    super->initState();
    widget()->focusNode->addListener(_handleFocusChanged);
}

void _RawKeyboardListenerStateCls::didUpdateWidget(RawKeyboardListener oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (widget()->focusNode != oldWidget->focusNode) {
        oldWidget->focusNode->removeListener(_handleFocusChanged);
        widget()->focusNode->addListener(_handleFocusChanged);
    }
}

void _RawKeyboardListenerStateCls::dispose() {
    widget()->focusNode->removeListener(_handleFocusChanged);
    _detachKeyboardIfAttached();
    super->dispose();
}

Widget _RawKeyboardListenerStateCls::build(BuildContext context) {
    return make<FocusCls>(widget()->focusNode, widget()->autofocus, widget()->includeSemantics, widget()->child);
}

void _RawKeyboardListenerStateCls::_handleFocusChanged() {
    if (widget()->focusNode->hasFocus) {
        _attachKeyboardIfDetached();
    } else {
        _detachKeyboardIfAttached();
    }
}

void _RawKeyboardListenerStateCls::_attachKeyboardIfDetached() {
    if (_listening) {
        return;
    }
    RawKeyboardCls::instance->addListener(_handleRawKeyEvent);
    _listening = true;
}

void _RawKeyboardListenerStateCls::_detachKeyboardIfAttached() {
    if (!_listening) {
        return;
    }
    RawKeyboardCls::instance->removeListener(_handleRawKeyEvent);
    _listening = false;
}

void _RawKeyboardListenerStateCls::_handleRawKeyEvent(RawKeyEvent event) {
    widget()->onKey?->call(event);
}
