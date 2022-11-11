#ifndef PACKAGES_FLUTTER_SRC_PAINTING_COLORS
#define PACKAGES_FLUTTER_SRC_PAINTING_COLORS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>

double _getHue(double red, double green, double blue, double max, double delta);

Color _colorFromHue(double alpha, double hue, double chroma, double secondary, double match);


class HSVColorCls : public ObjectCls {
public:
    double alpha;

    double hue;

    double saturation;

    double value;


    virtual void  fromAHSV(double alpha, double hue, double saturation, double value);

    virtual void  fromColor(Color color);

    virtual HSVColor withAlpha(double alpha);

    virtual HSVColor withHue(double hue);

    virtual HSVColor withSaturation(double saturation);

    virtual HSVColor withValue(double value);

    virtual Color toColor();

    static HSVColor lerp(HSVColor a, HSVColor b, double t);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

    virtual HSVColor _scaleAlpha(double factor);

};
using HSVColor = std::shared_ptr<HSVColorCls>;

class HSLColorCls : public ObjectCls {
public:
    double alpha;

    double hue;

    double saturation;

    double lightness;


    virtual void  fromAHSL(double alpha, double hue, double saturation, double lightness);

    virtual void  fromColor(Color color);

    virtual HSLColor withAlpha(double alpha);

    virtual HSLColor withHue(double hue);

    virtual HSLColor withSaturation(double saturation);

    virtual HSLColor withLightness(double lightness);

    virtual Color toColor();

    static HSLColor lerp(HSLColor a, HSLColor b, double t);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

    virtual HSLColor _scaleAlpha(double factor);

};
using HSLColor = std::shared_ptr<HSLColorCls>;

template<typename T>
class ColorSwatchCls : public ColorCls {
public:

     ColorSwatchCls(Unknown primary, Map<T, Color> _swatch);
    virtual Color operator[](T index);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

    template<typename T>
 static ColorSwatch<T> lerp(ColorSwatch<T> a, ColorSwatch<T> b, double t);

private:
    Map<T, Color> _swatch;


};
template<typename T>
using ColorSwatch = std::shared_ptr<ColorSwatchCls<T>>;

class ColorPropertyCls : public DiagnosticsPropertyCls<Color> {
public:

     ColorPropertyCls(String name, Unknown value, Unknown defaultValue, Unknown level, Unknown showName, Unknown style);

    virtual Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

private:

};
using ColorProperty = std::shared_ptr<ColorPropertyCls>;


#endif