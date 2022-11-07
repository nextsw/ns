#include "icon_theme_data.hpp"
IconThemeData::IconThemeData(Color color, double opacity, List<Shadow> shadows, double size) {
    {
        _opacity = opacity;
    }
}

void IconThemeData::fallback()

IconThemeData IconThemeData::copyWith(Color color, double opacity, List<Shadow> shadows, double size) {
    return IconThemeData(color ?? this.color, opacity ?? this.opacity, size ?? this.size, shadows ?? this.shadows);
}

IconThemeData IconThemeData::merge(IconThemeData other) {
    if (other == nullptr) {
        return this;
    }
    return copyWith(other.color, other.opacity, other.size, other.shadows);
}

IconThemeData IconThemeData::resolve(BuildContext context) {
    return this;
}

bool IconThemeData::isConcrete() {
    return color != nullptr && opacity != nullptr && size != nullptr;
}

double IconThemeData::opacity() {
    return _opacity == nullptr? nullptr : clampDouble(_opacity!, 0.0, 1.0);
}

IconThemeData IconThemeData::lerp(IconThemeData a, IconThemeData b, double t) {
    assert(t != nullptr);
    return IconThemeData(Color.lerp(a?.color, b?.color, t), ui.lerpDouble(a?.opacity, b?.opacity, t), ui.lerpDouble(a?.size, b?.size, t), Shadow.lerpList(a?.shadows, b?.shadows, t));
}

bool IconThemeData::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is IconThemeData && other.color == color && other.opacity == opacity && other.size == size && listEquals(other.shadows, shadows);
}

int IconThemeData::hashCode() {
    return Object.hash(color, opacity, size, shadows == nullptr? nullptr : Object.hashAll(shadows!));
}

void IconThemeData::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(ColorProperty("color", colornullptr));
    properties.add(DoubleProperty("opacity", opacitynullptr));
    properties.add(DoubleProperty("size", sizenullptr));
    properties.add(<Shadow>IterableProperty("shadows", shadowsnullptr));
}
