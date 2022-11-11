#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DEFAULT_TEXT_EDITING_SHORTCUTS
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DEFAULT_TEXT_EDITING_SHORTCUTS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "actions.hpp"
#include "framework.hpp"
#include "shortcuts.hpp"
#include "text_editing_intents.hpp"


class DefaultTextEditingShortcutsCls : public StatelessWidgetCls {
public:
    Widget child;


     DefaultTextEditingShortcutsCls(Widget child, Key key);
    virtual Widget build(BuildContext context);

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
using DefaultTextEditingShortcuts = std::shared_ptr<DefaultTextEditingShortcutsCls>;


#endif