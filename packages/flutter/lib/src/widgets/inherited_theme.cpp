#include "inherited_theme.hpp"
Widget InheritedThemeCls::captureAll(Widget child, BuildContext context, BuildContext to) {
    assert(child != nullptr);
    assert(context != nullptr);
    return capture(context, to)->wrap(child);
}

CapturedThemes InheritedThemeCls::capture(BuildContext from, BuildContext to) {
    assert(from != nullptr);
    if (from == to) {
        return CapturedThemesCls->_(makeList());
    }
    List<InheritedTheme> themes = makeList();
    Set<Type> themeTypes = makeSet();
    bool debugDidFindAncestor;
    assert([=] () {
        debugDidFindAncestor = to == nullptr;
        return true;
    }());
    from->visitAncestorElements([=] (Element ancestor) {
        if (ancestor == to) {
            assert([=] () {
                debugDidFindAncestor = true;
                return true;
            }());
            return false;
        }
        if (is<InheritedElement>(ancestor) && is<InheritedTheme>(ancestor->widget)) {
            InheritedTheme theme = as<InheritedTheme>(ancestor->widget);
            Type themeType = theme->runtimeType;
            if (!themeTypes->contains(themeType)) {
                themeTypes->add(themeType);
                themes->add(theme);
            }
        }
        return true;
    });
    assert(debugDidFindAncestor, __s("The provided `to` context must be an ancestor of the `from` context."));
    return CapturedThemesCls->_(themes);
}

Widget CapturedThemesCls::wrap(Widget child) {
    return make<_CaptureAllCls>(_themes, child);
}

Widget _CaptureAllCls::build(BuildContext context) {
    Widget wrappedChild = child;
    for (InheritedTheme theme : themes) {
        wrappedChild = theme->wrap(context, wrappedChild);
    }
    return wrappedChild;
}

_CaptureAllCls::_CaptureAllCls(Widget child, List<InheritedTheme> themes) {
    {
        assert(themes != nullptr);
        assert(child != nullptr);
    }
}
