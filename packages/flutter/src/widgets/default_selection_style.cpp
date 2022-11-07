#include "default_selection_style.hpp"
void DefaultSelectionStyle::fallback(Unknown)

DefaultSelectionStyle DefaultSelectionStyle::of(BuildContext context) {
    return context.<DefaultSelectionStyle>dependOnInheritedWidgetOfExactType() ?? const DefaultSelectionStyle.fallback();
}

Widget DefaultSelectionStyle::wrap(Widget child, BuildContext context) {
    return DefaultSelectionStyle(cursorColor, selectionColor, child);
}

bool DefaultSelectionStyle::updateShouldNotify(DefaultSelectionStyle oldWidget) {
    return cursorColor != oldWidget.cursorColor || selectionColor != oldWidget.selectionColor;
}

Widget _NullWidget::build(BuildContext context) {
    ;
}
