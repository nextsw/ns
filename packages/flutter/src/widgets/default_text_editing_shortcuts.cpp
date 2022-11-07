#include "default_text_editing_shortcuts.hpp"
Widget DefaultTextEditingShortcuts::build(BuildContext context) {
    Widget result = child;
    if (kIsWeb) {
        result = Shortcuts("<Web Disabling Text Editing Shortcuts>", _webDisablingTextShortcuts, result);
    }
    return Shortcuts("<Default Text Editing Shortcuts>", _shortcuts, result);
}

Map<ShortcutActivator, Intent> DefaultTextEditingShortcuts::_shortcuts() {
    ;
}
