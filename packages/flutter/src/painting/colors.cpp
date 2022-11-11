#include "colors.hpp"
double _getHue(double blue, double delta, double green, double max, double red) {
    double hue;
    if (max == 0.0) {
        hue = 0.0;
    } else     {
        if (max == red) {
        hue = 60.0 * (((green - blue) / delta) % 6);
    } else     {
        if (max == green) {
        hue = 60.0 * (((blue - red) / delta) + 2);
    } else     {
        if (max == blue) {
        hue = 60.0 * (((red - green) / delta) + 4);
    }
;
    };
    };
    }    hue = hue->isNaN? 0.0 : hue;
    return hue;
}

Color _colorFromHue(double alpha, double chroma, double hue, double match, double secondary) {
    double red;
    double green;
    double blue;
    if ( < 60.0) {
        red = chroma;
        green = secondary;
        blue = 0.0;
    } else     {
        if ( < 120.0) {
        red = secondary;
        green = chroma;
        blue = 0.0;
    } else     {
        if ( < 180.0) {
        red = 0.0;
        green = chroma;
        blue = secondary;
    } else     {
        if ( < 240.0) {
        red = 0.0;
        green = secondary;
        blue = chroma;
    } else     {
        if ( < 300.0) {
        red = secondary;
        green = 0.0;
        blue = chroma;
    } else {
        red = chroma;
        green = 0.0;
        blue = secondary;
    }
;
    };
    };
    };
    }    return ColorCls->fromARGB((alpha * 0xFF)->round(), ((red + match) * 0xFF)->round(), ((green + match) * 0xFF)->round(), ((blue + match) * 0xFF)->round());
}

void HSVColorCls::fromAHSV(double alpha, double hue, double saturation, double value)

void HSVColorCls::fromColor(Color color) {
    double red = color->red() / 0xFF;
    double green = color->green() / 0xFF;
    double blue = color->blue() / 0xFF;
    double max = math->max(red, math->max(green, blue));
    double min = math->min(red, math->min(green, blue));
    double delta = max - min;
    double alpha = color->alpha / 0xFF;
    double hue = _getHue(red, green, blue, max, delta);
    double saturation = max == 0.0? 0.0 : delta / max;
    return HSVColorCls->fromAHSV(alpha, hue, saturation, max);
}

HSVColor HSVColorCls::withAlpha(double alpha) {
    return HSVColorCls->fromAHSV(alpha, hue, saturation, value);
}

HSVColor HSVColorCls::withHue(double hue) {
    return HSVColorCls->fromAHSV(alpha, hue, saturation, value);
}

HSVColor HSVColorCls::withSaturation(double saturation) {
    return HSVColorCls->fromAHSV(alpha, hue, saturation, value);
}

HSVColor HSVColorCls::withValue(double value) {
    return HSVColorCls->fromAHSV(alpha, hue, saturation, value);
}

Color HSVColorCls::toColor() {
    double chroma = saturation * value;
    double secondary = chroma * (1.0 - (((hue / 60.0) % 2.0) - 1.0)->abs());
    double match = value - chroma;
    return _colorFromHue(alpha, hue, chroma, secondary, match);
}

HSVColor HSVColorCls::lerp(HSVColor a, HSVColor b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b!->_scaleAlpha(t);
    }
    if (b == nullptr) {
        return a->_scaleAlpha(1.0 - t);
    }
    return HSVColorCls->fromAHSV(clampDouble(lerpDouble(a->alpha, b->alpha, t)!, 0.0, 1.0), lerpDouble(a->hue, b->hue, t)! % 360.0, clampDouble(lerpDouble(a->saturation, b->saturation, t)!, 0.0, 1.0), clampDouble(lerpDouble(a->value, b->value, t)!, 0.0, 1.0));
}

bool HSVColorCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    return is<HSVColor>(other) && other->alpha == alpha && other->hue == hue && other->saturation == saturation && other->value == value;
}

int HSVColorCls::hashCode() {
    return ObjectCls->hash(alpha, hue, saturation, value);
}

String HSVColorCls::toString() {
    return __s("${objectRuntimeType(this, 'HSVColor')}($alpha, $hue, $saturation, $value)");
}

HSVColor HSVColorCls::_scaleAlpha(double factor) {
    return withAlpha(alpha * factor);
}

void HSLColorCls::fromAHSL(double alpha, double hue, double lightness, double saturation)

void HSLColorCls::fromColor(Color color) {
    double red = color->red() / 0xFF;
    double green = color->green() / 0xFF;
    double blue = color->blue() / 0xFF;
    double max = math->max(red, math->max(green, blue));
    double min = math->min(red, math->min(green, blue));
    double delta = max - min;
    double alpha = color->alpha / 0xFF;
    double hue = _getHue(red, green, blue, max, delta);
    double lightness = (max + min) / 2.0;
    double saturation = lightness == 1.0? 0.0 : clampDouble(delta / (1.0 - (2.0 * lightness - 1.0)->abs()), 0.0, 1.0);
    return HSLColorCls->fromAHSL(alpha, hue, saturation, lightness);
}

HSLColor HSLColorCls::withAlpha(double alpha) {
    return HSLColorCls->fromAHSL(alpha, hue, saturation, lightness);
}

HSLColor HSLColorCls::withHue(double hue) {
    return HSLColorCls->fromAHSL(alpha, hue, saturation, lightness);
}

HSLColor HSLColorCls::withSaturation(double saturation) {
    return HSLColorCls->fromAHSL(alpha, hue, saturation, lightness);
}

HSLColor HSLColorCls::withLightness(double lightness) {
    return HSLColorCls->fromAHSL(alpha, hue, saturation, lightness);
}

Color HSLColorCls::toColor() {
    double chroma = (1.0 - (2.0 * lightness - 1.0)->abs()) * saturation;
    double secondary = chroma * (1.0 - (((hue / 60.0) % 2.0) - 1.0)->abs());
    double match = lightness - chroma / 2.0;
    return _colorFromHue(alpha, hue, chroma, secondary, match);
}

HSLColor HSLColorCls::lerp(HSLColor a, HSLColor b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b!->_scaleAlpha(t);
    }
    if (b == nullptr) {
        return a->_scaleAlpha(1.0 - t);
    }
    return HSLColorCls->fromAHSL(clampDouble(lerpDouble(a->alpha, b->alpha, t)!, 0.0, 1.0), lerpDouble(a->hue, b->hue, t)! % 360.0, clampDouble(lerpDouble(a->saturation, b->saturation, t)!, 0.0, 1.0), clampDouble(lerpDouble(a->lightness, b->lightness, t)!, 0.0, 1.0));
}

bool HSLColorCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    return is<HSLColor>(other) && other->alpha == alpha && other->hue == hue && other->saturation == saturation && other->lightness == lightness;
}

int HSLColorCls::hashCode() {
    return ObjectCls->hash(alpha, hue, saturation, lightness);
}

String HSLColorCls::toString() {
    return __s("${objectRuntimeType(this, 'HSLColor')}($alpha, $hue, $saturation, $lightness)");
}

HSLColor HSLColorCls::_scaleAlpha(double factor) {
    return withAlpha(alpha * factor);
}

template<typename T> Color ColorSwatchCls<T>::[](T index) {
    return _swatch[index];
}

template<typename T> bool ColorSwatchCls<T>::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return super == other && is<ColorSwatch<T>>(other) && <T, Color>mapEquals(other->_swatch, _swatch);
}

template<typename T> int ColorSwatchCls<T>::hashCode() {
    return ObjectCls->hash(runtimeType, value, _swatch);
}

template<typename T> String ColorSwatchCls<T>::toString() {
    return __s("${objectRuntimeType(this, 'ColorSwatch')}(primary value: ${super.toString()})");
}

template<typename T> ColorSwatch<T> ColorSwatchCls<T>::lerptemplate<typename T> (ColorSwatch<T> a, ColorSwatch<T> b, double t) {
    Map<T, Color> swatch;
    if (b == nullptr) {
        if (a == nullptr) {
            return nullptr;
        } else {
            swatch = a->_swatch->map([=] (T key,Color color)             {
                <T, Color>make<MapEntryCls>(key, ColorCls->lerp(color, nullptr, t)!);
            });
        }
    } else {
        if (a == nullptr) {
            swatch = b->_swatch->map([=] (T key,Color color)             {
                <T, Color>make<MapEntryCls>(key, ColorCls->lerp(nullptr, color, t)!);
            });
        } else {
            swatch = a->_swatch->map([=] (T key,Color color)             {
                <T, Color>make<MapEntryCls>(key, ColorCls->lerp(color, b[key], t)!);
            });
        }
    }
    return <T>make<ColorSwatchCls>(ColorCls->lerp(a, b, t)!->value, swatch);
}

ColorPropertyCls::ColorPropertyCls(Unknown defaultValue, Unknown level, String name, Unknown showName, Unknown style, Unknown value) {
    {
        assert(showName != nullptr);
        assert(style != nullptr);
        assert(level != nullptr);
    }
}

Map<String, Object> ColorPropertyCls::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> json = super->toJsonMap(delegate);
    if (value != nullptr) {
            Map<String, Object> map1 = make<MapCls<>>();    map1.set(__s("red"), value!->red);    map1.set(__s("green"), value!->green);    map1.set(__s("blue"), value!->blue);    map1.set(__s("alpha"), value!->alpha);json[__s("valueProperties")] = list1;
    }
    return json;
}
