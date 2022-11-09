#include "icon_theme_data.hpp"
IconThemeDataCls::IconThemeDataCls(Color color, double opacity, List<Shadow> shadows, double size) {
    {
        _opacity = opacity;
    }
}

void IconThemeDataCls::fallback()

IconThemeData IconThemeDataCls::copyWith(Color color, double opacity, List<Shadow> shadows, double size) {
    return make<IconThemeDataCls>(color ?? this->color, opacity ?? this->opacity, size ?? this->size, shadows ?? this->shadows);
}

IconThemeData IconThemeDataCls::merge(IconThemeData other) {
    if (other == nullptr) {
        return this;
    }
    return copyWith(other->color, other->opacity, other->size, other->shadows);
}

IconThemeData IconThemeDataCls::resolve(BuildContext context) {
    return this;
}

bool IconThemeDataCls::isConcrete() {
    return color != nullptr && opacity != nullptr && size != nullptr;
}

double IconThemeDataCls::opacity() {
    return _opacity == nullptr? nullptr : clampDouble(_opacity!, 0.0, 1.0);
}

IconThemeData IconThemeDataCls::lerp(IconThemeData a, IconThemeData b, double t) {
    assert(t != nullptr);
    return make<IconThemeDataCls>(ColorCls->lerp(a?->color, b?->color, t), ui->lerpDouble(a?->opacity, b?->opacity, t), ui->lerpDouble(a?->size, b?->size, t), ShadowCls->lerpList(a?->shadows, b?->shadows, t));
}

bool IconThemeDataCls::==(Object other) {
    if (other->runtimeType != runtimeType) {
        return false;
    }
    return other is IconThemeData && other->color == color && other->opacity == opacity && other->size == size && listEquals(other->shadows, shadows);
}

int IconThemeDataCls::hashCode() {
    return ObjectCls->hash(color, opacity, size, shadows == nullptr? nullptr : ObjectCls->hashAll(shadows!));
}

void IconThemeDataCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<ColorPropertyCls>("color", colornullptr));
    properties->add(make<DoublePropertyCls>("opacity", opacitynullptr));
    properties->add(make<DoublePropertyCls>("size", sizenullptr));
    properties->add(<Shadow>make<IterablePropertyCls>("shadows", shadowsnullptr));
}
