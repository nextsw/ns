#include "icon.hpp"
Widget IconCls::build(BuildContext context) {
    assert(this->textDirection != nullptr || debugCheckHasDirectionality(context));
    TextDirection textDirection = this->textDirection | DirectionalityCls->of(context);
    IconThemeData iconTheme = IconThemeCls->of(context);
    double iconSize = size | iconTheme->size;
    List<Shadow> iconShadows = shadows | iconTheme->shadows;
    if (icon == nullptr) {
        return make<SemanticsCls>(semanticLabel, make<SizedBoxCls>(iconSize, iconSize));
    }
    double iconOpacity = iconTheme->opacity() | 1.0;
    Color iconColor = color | iconTheme->color!;
    if (iconOpacity != 1.0) {
        iconColor = iconColor->withOpacity(iconColor->opacity() * iconOpacity);
    }
    Widget iconWidget = make<RichTextCls>(TextOverflowCls::visible, textDirection, make<TextSpanCls>(StringCls->fromCharCode(icon!->codePoint), make<TextStyleCls>(false, iconColor, iconSize, icon!->fontFamily, icon!->fontPackage, iconShadows)));
    if (icon!->matchTextDirection) {
        ;
    }
    return make<SemanticsCls>(semanticLabel, make<ExcludeSemanticsCls>(make<SizedBoxCls>(iconSize, iconSize, make<CenterCls>(iconWidget))));
}

void IconCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<IconDataPropertyCls>(__s("icon"), icon, __s("<empty>"), false));
    properties->add(make<DoublePropertyCls>(__s("size"), size, nullptr));
    properties->add(make<ColorPropertyCls>(__s("color"), color, nullptr));
    properties->add(<Shadow>make<IterablePropertyCls>(__s("shadows"), shadows, nullptr));
}
