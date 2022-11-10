#include "debug.hpp"
Key _firstNonUniqueKey(Iterable<Widget> widgets) {
    Set<Key> keySet = <Key>make<HashSetCls>();
    for (Widget widget : widgets) {
        assert(widget != nullptr);
        if (widget->key == nullptr) {
            continue;
        }
        if (!keySet->add(widget->key!)) {
            return widget->key;
        }
    }
    return nullptr;
}

bool debugChildrenHaveDuplicateKeys(Iterable<Widget> children, Widget parent) {
    assert([=] () {
        Key nonUniqueKey = _firstNonUniqueKey(children);
        if (nonUniqueKey != nullptr) {
            ;
        }
        return true;
    }());
    return false;
}

bool debugItemsHaveDuplicateKeys(Iterable<Widget> items) {
    assert([=] () {
        Key nonUniqueKey = _firstNonUniqueKey(items);
        if (nonUniqueKey != nullptr) {
            ;
        }
        return true;
    }());
    return false;
}

bool debugCheckHasTable(BuildContext context) {
    assert([=] () {
        if (!is<Table>(context->widget) && context-><Table>findAncestorWidgetOfExactType() == nullptr) {
            ;
        }
        return true;
    }());
    return true;
}

bool debugCheckHasMediaQuery(BuildContext context) {
    assert([=] () {
        if (!is<MediaQuery>(context->widget) && context-><MediaQuery>getElementForInheritedWidgetOfExactType() == nullptr) {
            ;
        }
        return true;
    }());
    return true;
}

bool debugCheckHasDirectionality(String alternative, BuildContext context, String hint, String why) {
    assert([=] () {
        if (!is<Directionality>(context->widget) && context-><Directionality>getElementForInheritedWidgetOfExactType() == nullptr) {
            why = why == nullptr? __s("") : __s(" $why");
            ;
        }
        return true;
    }());
    return true;
}

void debugWidgetBuilderValue(Widget built, Widget widget) {
    assert([=] () {
        if (built == nullptr) {
            ;
        }
        if (widget == built) {
            ;
        }
        return true;
    }());
}

bool debugCheckHasWidgetsLocalizations(BuildContext context) {
    assert([=] () {
        if (LocalizationsCls-><WidgetsLocalizations>of(context, WidgetsLocalizationsCls) == nullptr) {
            ;
        }
        return true;
    }());
    return true;
}

bool debugCheckHasOverlay(BuildContext context) {
    assert([=] () {
        if (!is<Overlay>(context->widget) && context-><Overlay>findAncestorWidgetOfExactType() == nullptr) {
            ;
        }
        return true;
    }());
    return true;
}

bool debugAssertAllWidgetVarsUnset(String reason) {
    assert([=] () {
        if (debugPrintRebuildDirtyWidgets || debugPrintBuildScope || debugPrintScheduleBuildForStacks || debugPrintGlobalKeyedWidgetLifecycle || debugProfileBuildsEnabled || debugHighlightDeprecatedWidgets || debugProfileBuildsEnabledUserWidgets) {
            ;
        }
        return true;
    }());
    return true;
}
