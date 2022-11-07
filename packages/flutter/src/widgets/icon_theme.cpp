#include "icon_theme.hpp"
IconTheme::IconTheme(Unknown, IconThemeData data, Unknown) {
    {
        assert(data != nullptr);
        assert(child != nullptr);
    }
}

Widget IconTheme::merge(Widget child, IconThemeData data, Key key) {
    return Builder();
}

IconThemeData IconTheme::of(BuildContext context) {
    IconThemeData iconThemeData = _getInheritedIconThemeData(context).resolve(context);
    return iconThemeData.isConcrete? iconThemeData : iconThemeData.copyWith(iconThemeData.size ?? const IconThemeData.fallback().size, iconThemeData.color ?? const IconThemeData.fallback().color, iconThemeData.opacity ?? const IconThemeData.fallback().opacity, iconThemeData.shadows ?? const IconThemeData.fallback().shadows);
}

bool IconTheme::updateShouldNotify(IconTheme oldWidget) {
    return data != oldWidget.data;
}

Widget IconTheme::wrap(Widget child, BuildContext context) {
    return IconTheme(data, child);
}

void IconTheme::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    data.debugFillProperties(properties);
}

IconThemeData IconTheme::_getInheritedIconThemeData(BuildContext context) {
    IconTheme iconTheme = context.<IconTheme>dependOnInheritedWidgetOfExactType();
    return iconTheme?.data ?? const IconThemeData.fallback();
}
