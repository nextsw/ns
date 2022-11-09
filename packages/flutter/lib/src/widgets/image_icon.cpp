#include "image_icon.hpp"
Widget ImageIconCls::build(BuildContext context) {
    IconThemeData iconTheme = IconThemeCls->of(context);
    double iconSize = size ?? iconTheme->size;
    if (image == nullptr) {
        return make<SemanticsCls>(semanticLabel, make<SizedBoxCls>(iconSize, iconSize));
    }
    double iconOpacity = iconTheme->opacity;
    Color iconColor = color ?? iconTheme->color!;
    if (iconOpacity != nullptr && iconOpacity != 1.0) {
        iconColor = iconColor->withOpacity(iconColor->opacity * iconOpacity);
    }
    return make<SemanticsCls>(semanticLabel, make<ImageCls>(image!, iconSize, iconSize, iconColor, BoxFitCls::scaleDown, true));
}

void ImageIconCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<ImageProvider>make<DiagnosticsPropertyCls>("image", image"<empty>", false));
    properties->add(make<DoublePropertyCls>("size", sizenullptr));
    properties->add(make<ColorPropertyCls>("color", colornullptr));
}
