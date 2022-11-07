#ifndef DEFAULT_TEXT_EDITING_SHORTCUTS_H
#define DEFAULT_TEXT_EDITING_SHORTCUTS_H
#include <memory>

#include <flutter/foundation.hpp>
#include <flutter/services.hpp>
#include "actions.hpp"
#include "framework.hpp"
#include "shortcuts.hpp"
#include "text_editing_intents.hpp"



class DefaultTextEditingShortcuts : StatelessWidget {
public:
    Widget child;


     DefaultTextEditingShortcuts(Widget child, Unknown);

    Widget build(BuildContext context);

private:
    static Map<ShortcutActivator, Intent> _commonShortcuts;

    static Map<ShortcutActivator, Intent> _androidShortcuts;

    static Map<ShortcutActivator, Intent> _fuchsiaShortcuts;

    static Map<ShortcutActivator, Intent> _linuxShortcuts;

    static Map<ShortcutActivator, Intent> _macShortcuts;

    static Map<ShortcutActivator, Intent> _iOSShortcuts;

    static Map<ShortcutActivator, Intent> _windowsShortcuts;

    static Map<ShortcutActivator, Intent> _webDisablingTextShortcuts;


    static Map<ShortcutActivator, Intent> _shortcuts();

};

#endif