#include "default_selection_style.hpp"
void DefaultSelectionStyleCls::fallback(Unknown key)

DefaultSelectionStyle DefaultSelectionStyleCls::of(BuildContext context) {
    return context-><DefaultSelectionStyle>dependOnInheritedWidgetOfExactType() or DefaultSelectionStyleCls->fallback();
}

Widget DefaultSelectionStyleCls::wrap(Widget child, BuildContext context) {
    return make<DefaultSelectionStyleCls>(cursorColor, selectionColor, child);
}

bool DefaultSelectionStyleCls::updateShouldNotify(DefaultSelectionStyle oldWidget) {
    return cursorColor != oldWidget->cursorColor || selectionColor != oldWidget->selectionColor;
}

Widget _NullWidgetCls::build(BuildContext context) {
    throw make<FlutterErrorCls>(__s("A DefaultTextStyle constructed with DefaultTextStyle.fallback cannot be incorporated into the widget tree, it is meant only to provide a fallback value returned by DefaultTextStyle.of() when no enclosing default text style is present in a BuildContext."));
}
