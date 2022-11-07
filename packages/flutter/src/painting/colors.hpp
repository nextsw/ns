#ifndef COLORS_H
#define COLORS_H
#include <memory>

#include <math/math.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>


double _getHue(double blue, double delta, double green, double max, double red);

Color _colorFromHue(double alpha, double chroma, double hue, double match, double secondary);


class HSVColor {
public:
    double alpha;

    double hue;

    double saturation;

    double value;


    void  fromAHSV(double alpha, double hue, double saturation, double value);

    void  fromColor(Color color);

    HSVColor withAlpha(double alpha);

    HSVColor withHue(double hue);

    HSVColor withSaturation(double saturation);

    HSVColor withValue(double value);

    Color toColor();

    static HSVColor lerp(HSVColor a, HSVColor b, double t);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

    HSVColor _scaleAlpha(double factor);

};

class HSLColor {
public:
    double alpha;

    double hue;

    double saturation;

    double lightness;


    void  fromAHSL(double alpha, double hue, double lightness, double saturation);

    void  fromColor(Color color);

    HSLColor withAlpha(double alpha);

    HSLColor withHue(double hue);

    HSLColor withSaturation(double saturation);

    HSLColor withLightness(double lightness);

    Color toColor();

    static HSLColor lerp(HSLColor a, HSLColor b, double t);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

    HSLColor _scaleAlpha(double factor);

};

class ColorSwatch<T> : Color {
public:

     ColorSwatch(Map<T, Color> _swatch, Unknown);

    Color [](T index);

    bool ==(Object other);

    int hashCode();

    String toString();

    static ColorSwatch<T> lerp<T>(ColorSwatch<T> a, ColorSwatch<T> b, double t);

private:
    Map<T, Color> _swatch;


};

class ColorProperty : DiagnosticsProperty<Color> {
public:

     ColorProperty(Unknown, Unknown, String name, Unknown, Unknown, Unknown);

    Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

private:

};

#endif