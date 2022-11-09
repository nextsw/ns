#include "default_text_editing_shortcuts.hpp"
Widget DefaultTextEditingShortcutsCls::build(BuildContext context) {
    Widget result = child;
    if (kIsWeb) {
        result = make<ShortcutsCls>("<Web Disabling Text Editing Shortcuts>", _webDisablingTextShortcuts, result);
    }
    return make<ShortcutsCls>("<Default Text Editing Shortcuts>", _shortcuts, result);
}

Map<ShortcutActivator, Intent> DefaultTextEditingShortcutsCls::_shortcuts() {
    ;
}
