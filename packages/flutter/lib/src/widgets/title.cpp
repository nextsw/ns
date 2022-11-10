#include "title.hpp"
TitleCls::TitleCls(Widget child, Color color, Unknown key, String title) {
    {
        assert(title != nullptr);
        assert(color != nullptr && color->alpha() == 0xFF);
    }
}

Widget TitleCls::build(BuildContext context) {
    SystemChromeCls->setApplicationSwitcherDescription(make<ApplicationSwitcherDescriptionCls>(title, color->value));
    return child;
}

void TitleCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<StringPropertyCls>(__s("title"), title__s("")));
    properties->add(make<ColorPropertyCls>(__s("color"), colornullptr));
}
