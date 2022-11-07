#include "icon.hpp"
Widget Icon::build(BuildContext context) {
    assert(this.textDirection != nullptr || debugCheckHasDirectionality(context));
    TextDirection textDirection = this.textDirection ?? Directionality.of(context);
    IconThemeData iconTheme = IconTheme.of(context);
    double iconSize = size ?? iconTheme.size;
    List<Shadow> iconShadows = shadows ?? iconTheme.shadows;
    if (icon == nullptr) {
        return Semantics(semanticLabel, SizedBox(iconSize, iconSize));
    }
    double iconOpacity = iconTheme.opacity ?? 1.0;
    Color iconColor = color ?? iconTheme.color!;
    if (iconOpacity != 1.0) {
        iconColor = iconColor.withOpacity(iconColor.opacity * iconOpacity);
    }
    Widget iconWidget = RichText(TextOverflow.visible, textDirection, TextSpan(String.fromCharCode(icon!.codePoint), TextStyle(false, iconColor, iconSize, icon!.fontFamily, icon!.fontPackage, iconShadows)));
    if (icon!.matchTextDirection) {
        ;
    }
    return Semantics(semanticLabel, ExcludeSemantics(SizedBox(iconSize, iconSize, Center(iconWidget))));
}

void Icon::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(IconDataProperty("icon", icon"<empty>", false));
    properties.add(DoubleProperty("size", sizenullptr));
    properties.add(ColorProperty("color", colornullptr));
    properties.add(<Shadow>IterableProperty("shadows", shadowsnullptr));
}
