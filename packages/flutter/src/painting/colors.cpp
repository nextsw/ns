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
    }    hue = hue.isNaN? 0.0 : hue;
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
    }    return Color.fromARGB((alpha * 0xFF).round(), ((red + match) * 0xFF).round(), ((green + match) * 0xFF).round(), ((blue + match) * 0xFF).round());
}

void HSVColor::fromAHSV(double alpha, double hue, double saturation, double value)

void HSVColor::fromColor(Color color) {
    double red = color.red / 0xFF;
    double green = color.green / 0xFF;
    double blue = color.blue / 0xFF;
    double max = math.max(red, math.max(green, blue));
    double min = math.min(red, math.min(green, blue));
    double delta = max - min;
    double alpha = color.alpha / 0xFF;
    double hue = _getHue(red, green, blue, max, delta);
    double saturation = max == 0.0? 0.0 : delta / max;
    return HSVColor.fromAHSV(alpha, hue, saturation, max);
}

HSVColor HSVColor::withAlpha(double alpha) {
    return HSVColor.fromAHSV(alpha, hue, saturation, value);
}

HSVColor HSVColor::withHue(double hue) {
    return HSVColor.fromAHSV(alpha, hue, saturation, value);
}

HSVColor HSVColor::withSaturation(double saturation) {
    return HSVColor.fromAHSV(alpha, hue, saturation, value);
}

HSVColor HSVColor::withValue(double value) {
    return HSVColor.fromAHSV(alpha, hue, saturation, value);
}

Color HSVColor::toColor() {
    double chroma = saturation * value;
    double secondary = chroma * (1.0 - (((hue / 60.0) % 2.0) - 1.0).abs());
    double match = value - chroma;
    return _colorFromHue(alpha, hue, chroma, secondary, match);
}

HSVColor HSVColor::lerp(HSVColor a, HSVColor b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b!._scaleAlpha(t);
    }
    if (b == nullptr) {
        return a._scaleAlpha(1.0 - t);
    }
    return HSVColor.fromAHSV(clampDouble(lerpDouble(a.alpha, b.alpha, t)!, 0.0, 1.0), lerpDouble(a.hue, b.hue, t)! % 360.0, clampDouble(lerpDouble(a.saturation, b.saturation, t)!, 0.0, 1.0), clampDouble(lerpDouble(a.value, b.value, t)!, 0.0, 1.0));
}

bool HSVColor::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    return other is HSVColor && other.alpha == alpha && other.hue == hue && other.saturation == saturation && other.value == value;
}

int HSVColor::hashCode() {
    return Object.hash(alpha, hue, saturation, value);
}

String HSVColor::toString() {
    return "${objectRuntimeType(this, 'HSVColor')}($alpha, $hue, $saturation, $value)";
}

HSVColor HSVColor::_scaleAlpha(double factor) {
    return withAlpha(alpha * factor);
}

void HSLColor::fromAHSL(double alpha, double hue, double lightness, double saturation)

void HSLColor::fromColor(Color color) {
    double red = color.red / 0xFF;
    double green = color.green / 0xFF;
    double blue = color.blue / 0xFF;
    double max = math.max(red, math.max(green, blue));
    double min = math.min(red, math.min(green, blue));
    double delta = max - min;
    double alpha = color.alpha / 0xFF;
    double hue = _getHue(red, green, blue, max, delta);
    double lightness = (max + min) / 2.0;
    double saturation = lightness == 1.0? 0.0 : clampDouble(delta / (1.0 - (2.0 * lightness - 1.0).abs()), 0.0, 1.0);
    return HSLColor.fromAHSL(alpha, hue, saturation, lightness);
}

HSLColor HSLColor::withAlpha(double alpha) {
    return HSLColor.fromAHSL(alpha, hue, saturation, lightness);
}

HSLColor HSLColor::withHue(double hue) {
    return HSLColor.fromAHSL(alpha, hue, saturation, lightness);
}

HSLColor HSLColor::withSaturation(double saturation) {
    return HSLColor.fromAHSL(alpha, hue, saturation, lightness);
}

HSLColor HSLColor::withLightness(double lightness) {
    return HSLColor.fromAHSL(alpha, hue, saturation, lightness);
}

Color HSLColor::toColor() {
    double chroma = (1.0 - (2.0 * lightness - 1.0).abs()) * saturation;
    double secondary = chroma * (1.0 - (((hue / 60.0) % 2.0) - 1.0).abs());
    double match = lightness - chroma / 2.0;
    return _colorFromHue(alpha, hue, chroma, secondary, match);
}

HSLColor HSLColor::lerp(HSLColor a, HSLColor b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b!._scaleAlpha(t);
    }
    if (b == nullptr) {
        return a._scaleAlpha(1.0 - t);
    }
    return HSLColor.fromAHSL(clampDouble(lerpDouble(a.alpha, b.alpha, t)!, 0.0, 1.0), lerpDouble(a.hue, b.hue, t)! % 360.0, clampDouble(lerpDouble(a.saturation, b.saturation, t)!, 0.0, 1.0), clampDouble(lerpDouble(a.lightness, b.lightness, t)!, 0.0, 1.0));
}

bool HSLColor::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    return other is HSLColor && other.alpha == alpha && other.hue == hue && other.saturation == saturation && other.lightness == lightness;
}

int HSLColor::hashCode() {
    return Object.hash(alpha, hue, saturation, lightness);
}

String HSLColor::toString() {
    return "${objectRuntimeType(this, 'HSLColor')}($alpha, $hue, $saturation, $lightness)";
}

HSLColor HSLColor::_scaleAlpha(double factor) {
    return withAlpha(alpha * factor);
}

Color ColorSwatch::[](T index) {
    return _swatch[index];
}

bool ColorSwatch::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return super == other && other is ColorSwatch<T> && <T, Color>mapEquals(other._swatch, _swatch);
}

int ColorSwatch::hashCode() {
    return Object.hash(runtimeType, value, _swatch);
}

String ColorSwatch::toString() {
    return "${objectRuntimeType(this, 'ColorSwatch')}(primary value: ${super.toString()})";
}

ColorSwatch<T> ColorSwatch::lerp<T>(ColorSwatch<T> a, ColorSwatch<T> b, double t) {
    Map<T, Color> swatch;
    if (b == nullptr) {
        if (a == nullptr) {
            return nullptr;
        } else {
            swatch = a._swatch.map();
        }
    } else {
        if (a == nullptr) {
            swatch = b._swatch.map();
        } else {
            swatch = a._swatch.map();
        }
    }
    return <T>ColorSwatch(Color.lerp(a, b, t)!.value, swatch);
}

ColorProperty::ColorProperty(Unknown, Unknown, String name, Unknown, Unknown, Unknown) {
    {
        assert(showName != nullptr);
        assert(style != nullptr);
        assert(level != nullptr);
    }
}

Map<String, Object> ColorProperty::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> json = super.toJsonMap(delegate);
    if (value != nullptr) {
        json["valueProperties"] = ;
    }
    return json;
}
