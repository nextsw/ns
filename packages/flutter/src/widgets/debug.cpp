#include "debug.hpp"
Key _firstNonUniqueKey(Iterable<Widget> widgets) {
    Set<Key> keySet = <Key>HashSet();
    for (Widget widget : widgets) {
        assert(widget != nullptr);
        if (widget.key == nullptr) {
            continue;
        }
        if (!keySet.add(widget.key!)) {
            return widget.key;
        }
    }
    return nullptr;
}

bool debugChildrenHaveDuplicateKeys(Iterable<Widget> children, Widget parent) {
    assert(());
    return false;
}

bool debugItemsHaveDuplicateKeys(Iterable<Widget> items) {
    assert(());
    return false;
}

bool debugCheckHasTable(BuildContext context) {
    assert(());
    return true;
}

bool debugCheckHasMediaQuery(BuildContext context) {
    assert(());
    return true;
}

bool debugCheckHasDirectionality(String alternative, BuildContext context, String hint, String why) {
    assert(());
    return true;
}

void debugWidgetBuilderValue(Widget built, Widget widget) {
    assert(());
}

bool debugCheckHasWidgetsLocalizations(BuildContext context) {
    assert(());
    return true;
}

bool debugCheckHasOverlay(BuildContext context) {
    assert(());
    return true;
}

bool debugAssertAllWidgetVarsUnset(String reason) {
    assert(());
    return true;
}
