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

bool debugChildrenHaveDuplicateKeys(Widget parent, Iterable<Widget> children) {
    assert([=] () {
        Key nonUniqueKey = _firstNonUniqueKey(children);
        if (nonUniqueKey != nullptr) {
            throw make<FlutterErrorCls>(__sf("Duplicate keys found.\nIf multiple keyed nodes exist as children of another node, they must have unique keys.\n%s has multiple children with key %s.", parent, nonUniqueKey));
        }
        return true;
    }());
    return false;
}

bool debugItemsHaveDuplicateKeys(Iterable<Widget> items) {
    assert([=] () {
        Key nonUniqueKey = _firstNonUniqueKey(items);
        if (nonUniqueKey != nullptr) {
            throw make<FlutterErrorCls>(__sf("Duplicate key found: %s.", nonUniqueKey));
        }
        return true;
    }());
    return false;
}

bool debugCheckHasTable(BuildContext context) {
    assert([=] () {
        if (!is<Table>(context->widget()) && context-><Table>findAncestorWidgetOfExactType() == nullptr) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));
        }
        return true;
    }());
    return true;
}

bool debugCheckHasMediaQuery(BuildContext context) {
    assert([=] () {
        if (!is<MediaQuery>(context->widget()) && context-><MediaQuery>getElementForInheritedWidgetOfExactType() == nullptr) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem));
        }
        return true;
    }());
    return true;
}

bool debugCheckHasDirectionality(BuildContext context, String alternative, String hint, String why) {
    assert([=] () {
        if (!is<Directionality>(context->widget()) && context-><Directionality>getElementForInheritedWidgetOfExactType() == nullptr) {
            why = why == nullptr? __s("") : __sf(" %s", why);
                    List<DiagnosticsNode> list1 = make<ListCls<>>();        list1.add(ArrayItem);        list1.add(ArrayItem);        if (hint != nullptr) {            list1.add(ArrayItem);        }list1.add(ArrayItem);        list1.add(ArrayItem);        list1.add(ArrayItem);        if (alternative != nullptr) {            list1.add(ArrayItem);        }throw FlutterErrorCls->fromParts(list1);
        }
        return true;
    }());
    return true;
}

void debugWidgetBuilderValue(Widget widget, Widget built) {
    assert([=] () {
        if (built == nullptr) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));
        }
        if (widget == built) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
        }
        return true;
    }());
}

bool debugCheckHasWidgetsLocalizations(BuildContext context) {
    assert([=] () {
        if (LocalizationsCls-><WidgetsLocalizations>of(context, WidgetsLocalizationsCls) == nullptr) {
                    List<DiagnosticsNode> list1 = make<ListCls<>>();        list1.add(ArrayItem);        list1.add(ArrayItem);        list1.add(ArrayItem);        list1.add(ArrayItem);        for (auto _x1 : context->describeMissingAncestor(WidgetsLocalizationsCls)) {        {            list1.add(_x1);        }throw FlutterErrorCls->fromParts(list1);
        }
        return true;
    }());
    return true;
}

bool debugCheckHasOverlay(BuildContext context) {
    assert([=] () {
        if (!is<Overlay>(context->widget()) && context-><Overlay>findAncestorWidgetOfExactType() == nullptr) {
                    List<DiagnosticsNode> list1 = make<ListCls<>>();        list1.add(ArrayItem);        list1.add(ArrayItem);        list1.add(ArrayItem);        for (auto _x1 : context->describeMissingAncestor(OverlayCls)) {        {            list1.add(_x1);        }throw FlutterErrorCls->fromParts(list1);
        }
        return true;
    }());
    return true;
}

bool debugAssertAllWidgetVarsUnset(String reason) {
    assert([=] () {
        if (debugPrintRebuildDirtyWidgets || debugPrintBuildScope || debugPrintScheduleBuildForStacks || debugPrintGlobalKeyedWidgetLifecycle || debugProfileBuildsEnabled || debugHighlightDeprecatedWidgets || debugProfileBuildsEnabledUserWidgets) {
            throw make<FlutterErrorCls>(reason);
        }
        return true;
    }());
    return true;
}
