#include "inherited_theme.hpp"
Widget InheritedTheme::captureAll(Widget child, BuildContext context, BuildContext to) {
    assert(child != nullptr);
    assert(context != nullptr);
    return capture(context, to).wrap(child);
}

CapturedThemes InheritedTheme::capture(BuildContext from, BuildContext to) {
    assert(from != nullptr);
    if (from == to) {
        return CapturedThemes._(const );
    }
    List<InheritedTheme> themes = ;
    Set<Type> themeTypes = ;
    bool debugDidFindAncestor;
    assert(());
    from.visitAncestorElements();
    assert(debugDidFindAncestor, "The provided `to` context must be an ancestor of the `from` context.");
    return CapturedThemes._(themes);
}

Widget CapturedThemes::wrap(Widget child) {
    return _CaptureAll(_themes, child);
}

Widget _CaptureAll::build(BuildContext context) {
    Widget wrappedChild = child;
    for (InheritedTheme theme : themes) {
        wrappedChild = theme.wrap(context, wrappedChild);
    }
    return wrappedChild;
}

_CaptureAll::_CaptureAll(Widget child, List<InheritedTheme> themes) {
    {
        assert(themes != nullptr);
        assert(child != nullptr);
    }
}
