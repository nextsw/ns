#include "default_text_editing_shortcuts.hpp"
Widget DefaultTextEditingShortcutsCls::build(BuildContext context) {
    Widget result = child;
    if (kIsWeb) {
        result = make<ShortcutsCls>(__s("<Web Disabling Text Editing Shortcuts>"), _webDisablingTextShortcuts, result);
    }
    return make<ShortcutsCls>(__s("<Default Text Editing Shortcuts>"), _shortcuts(), result);
}

Map<ShortcutActivator, Intent> DefaultTextEditingShortcutsCls::_shortcuts() {
    ;
}
