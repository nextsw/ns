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
    ;
}
