#include "image_icon.hpp"
Widget ImageIcon::build(BuildContext context) {
    IconThemeData iconTheme = IconTheme.of(context);
    double iconSize = size ?? iconTheme.size;
    if (image == nullptr) {
        return Semantics(semanticLabel, SizedBox(iconSize, iconSize));
    }
    double iconOpacity = iconTheme.opacity;
    Color iconColor = color ?? iconTheme.color!;
    if (iconOpacity != nullptr && iconOpacity != 1.0) {
        iconColor = iconColor.withOpacity(iconColor.opacity * iconOpacity);
    }
    return Semantics(semanticLabel, Image(image!, iconSize, iconSize, iconColor, BoxFit.scaleDown, true));
}

void ImageIcon::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<ImageProvider>DiagnosticsProperty("image", image"<empty>", false));
    properties.add(DoubleProperty("size", sizenullptr));
    properties.add(ColorProperty("color", colornullptr));
}
