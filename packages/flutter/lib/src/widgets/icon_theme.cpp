#include "icon_theme.hpp"
IconThemeCls::IconThemeCls(Unknown child, IconThemeData data, Unknown key) {
    {
        assert(data != nullptr);
        assert(child != nullptr);
    }
}

Widget IconThemeCls::merge(Widget child, IconThemeData data, Key key) {
    return make<BuilderCls>([=] (BuildContext context) {
        return make<IconThemeCls>(key, _getInheritedIconThemeData(context)->merge(data), child);
    });
}

IconThemeData IconThemeCls::of(BuildContext context) {
    IconThemeData iconThemeData = _getInheritedIconThemeData(context)->resolve(context);
    return iconThemeData->isConcrete()? iconThemeData : iconThemeData->copyWith(iconThemeData->size | IconThemeDataCls->fallback()->size, iconThemeData->color | IconThemeDataCls->fallback()->color, iconThemeData->opacity() | IconThemeDataCls->fallback()->opacity, iconThemeData->shadows | IconThemeDataCls->fallback()->shadows);
}

bool IconThemeCls::updateShouldNotify(IconTheme oldWidget) {
    return data != oldWidget->data;
}

Widget IconThemeCls::wrap(BuildContext context, Widget child) {
    return make<IconThemeCls>(data, child);
}

void IconThemeCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    data->debugFillProperties(properties);
}

IconThemeData IconThemeCls::_getInheritedIconThemeData(BuildContext context) {
    IconTheme iconTheme = context-><IconTheme>dependOnInheritedWidgetOfExactType();
    return iconTheme?->data | IconThemeDataCls->fallback();
}
