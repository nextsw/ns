#include "colors.hpp"
void ColorsCls::fromRgba(int r, int g, int b, int a, Vector4 result) {
    result->setValues(r / 255.0, g / 255.0, b / 255.0, a / 255.0);
}

void ColorsCls::fromHexString(String value, Vector4 result) {
    Unknown fullMatch = _hexStringFullRegex->matchAsPrefix(value);
    if (fullMatch != nullptr) {
        if (fullMatch[4] == nullptr) {
            Unknown r = intValue->parse(fullMatch[1]!, 16);
            Unknown g = intValue->parse(fullMatch[2]!, 16);
            Unknown b = intValue->parse(fullMatch[3]!, 16);
            fromRgba(r, g, b, 255, result);
            return;
        } else {
            Unknown a = intValue->parse(fullMatch[1]!, 16);
            Unknown r = intValue->parse(fullMatch[2]!, 16);
            Unknown g = intValue->parse(fullMatch[3]!, 16);
            Unknown b = intValue->parse(fullMatch[4]!, 16);
            fromRgba(r, g, b, a, result);
            return;
        }
    }
    Unknown smallMatch = _hexStringSmallRegex->matchAsPrefix(value);
    if (smallMatch != nullptr) {
        if (smallMatch[4] == nullptr) {
            Unknown r = intValue->parse(smallMatch[1]! + smallMatch[1]!, 16);
            Unknown g = intValue->parse(smallMatch[2]! + smallMatch[2]!, 16);
            Unknown b = intValue->parse(smallMatch[3]! + smallMatch[3]!, 16);
            fromRgba(r, g, b, 255, result);
            return;
        } else {
            Unknown a = intValue->parse(smallMatch[1]! + smallMatch[1]!, 16);
            Unknown r = intValue->parse(smallMatch[2]! + smallMatch[2]!, 16);
            Unknown g = intValue->parse(smallMatch[3]! + smallMatch[3]!, 16);
            Unknown b = intValue->parse(smallMatch[4]! + smallMatch[4]!, 16);
            fromRgba(r, g, b, a, result);
            return;
        }
    }
    throw make<FormatExceptionCls>(__s("Could not parse hex color %s)"));
}

String ColorsCls::toHexString(Vector4 input, bool alpha, bool short) {
    Unknown r = (input->r * 0xFF)->floor() & 0xFF;
    Unknown g = (input->g * 0xFF)->floor() & 0xFF;
    Unknown b = (input->b * 0xFF)->floor() & 0xFF;
    Unknown a = (input->a * 0xFF)->floor() & 0xFF;
    Unknown isShort = short && ((r >> 4) == (r & 0xF)) && ((g >> 4) == (g & 0xF)) && ((b >> 4) == (b & 0xF)) && (!alpha || (a >> 4) == (a & 0xF));
    if (isShort) {
        Unknown rgb = (r & 0xF)->toRadixString(16) + (g & 0xF)->toRadixString(16) + (b & 0xF)->toRadixString(16);
        return alpha? (a & 0xF)->toRadixString(16) + rgb : rgb;
    } else {
        Unknown rgb = r->toRadixString(16)->padLeft(2, __s("0")) + g->toRadixString(16)->padLeft(2, __s("0")) + b->toRadixString(16)->padLeft(2, __s("0"));
        return alpha? a->toRadixString(16)->padLeft(2, __s("0")) + rgb : rgb;
    }
}

void ColorsCls::alphaBlend(Vector4 foreground, Vector4 background, Vector4 result) {
    Unknown a = foreground->a + (1.0 - foreground->a) * background->a;
    Unknown factor = 1.0 / a;
    Unknown r = factor * (foreground->a * foreground->r + (1.0 - foreground->a) * background->a * background->r);
    Unknown g = factor * (foreground->a * foreground->g + (1.0 - foreground->a) * background->a * background->g);
    Unknown b = factor * (foreground->a * foreground->b + (1.0 - foreground->a) * background->a * background->b);
    result->setValues(r, g, b, a);
}

void ColorsCls::toGrayscale(Vector4 input, Vector4 result) {
    Unknown value = 0.21 * input->r + 0.71 * input->g + 0.07 * input->b;
    auto _c1 = result;_c1.r = auto _c2 = value;_c2.g = auto _c3 = value;_c3.b = auto _c4 = value;_c4.a = input->a;_c4;_c3;_c2;_c1;
}

void ColorsCls::linearToGamma(Vector4 linearColor, Vector4 gammaColor, double gamma) {
    Unknown exponent = 1.0 / gamma;
    auto _c1 = gammaColor;_c1.r = auto _c2 = math->pow(linearColor->r, exponent)->toDouble();_c2.g = auto _c3 = math->pow(linearColor->g, exponent)->toDouble();_c3.b = auto _c4 = math->pow(linearColor->b, exponent)->toDouble();_c4.a = linearColor->a;_c4;_c3;_c2;_c1;
}

void ColorsCls::gammaToLinear(Vector4 gammaColor, Vector4 linearColor, double gamma) {
    auto _c1 = linearColor;_c1.r = auto _c2 = math->pow(gammaColor->r, gamma)->toDouble();_c2.g = auto _c3 = math->pow(gammaColor->g, gamma)->toDouble();_c3.b = auto _c4 = math->pow(gammaColor->b, gamma)->toDouble();_c4.a = gammaColor->a;_c4;_c3;_c2;_c1;
}

void ColorsCls::rgbToHsv(Vector4 rgbColor, Vector4 hsvColor) {
    Unknown max = math->max(math->max(rgbColor->r, rgbColor->g), rgbColor->b);
    Unknown min = math->min(math->min(rgbColor->r, rgbColor->g), rgbColor->b);
    Unknown d = max - min;
    Unknown v = max;
    Unknown s = max == 0.0? 0.0 : d / max;
    auto h = 0.0;
    if (max != min) {
        if (max == rgbColor->r) {
            h = (rgbColor->g - rgbColor->b) / d + (rgbColor->g < rgbColor->b? 6.0 : 0.0);
        } else {
            if (max == rgbColor->g) {
            h = (rgbColor->b - rgbColor->r) / d + 2.0;
        } else {
            h = (rgbColor->r - rgbColor->g) / d + 4.0;
        }
;
        }        h /= 6.0;
    }
    hsvColor->setValues(h, s, v, rgbColor->a);
}

void ColorsCls::hsvToRgb(Vector4 hsvColor, Vector4 rgbColor) {
    Unknown i = (hsvColor->x * 6.0)->floor();
    Unknown f = hsvColor->x * 6.0 - i->toDouble();
    Unknown p = hsvColor->z * (1.0 - hsvColor->y);
    Unknown q = hsvColor->z * (1.0 - f * hsvColor->y);
    Unknown t = hsvColor->z * (1.0 - (1.0 - f) * hsvColor->y);
    ;
}

void ColorsCls::rgbToHsl(Vector4 rgbColor, Vector4 hslColor) {
    Unknown max = math->max(math->max(rgbColor->r, rgbColor->g), rgbColor->b);
    Unknown min = math->min(math->min(rgbColor->r, rgbColor->g), rgbColor->b);
    Unknown l = (max + min) / 2.0;
    auto h = 0.0;
    auto s = 0.0;
    if (max != min) {
        Unknown d = max - min;
        s = l > 0.5? d / (2.0 - max - min) : d / (max + min);
        if (max == rgbColor->r) {
            h = (rgbColor->g - rgbColor->b) / d + (rgbColor->g < rgbColor->b? 6.0 : 0.0);
        } else {
            if (max == rgbColor->g) {
            h = (rgbColor->b - rgbColor->r) / d + 2.0;
        } else {
            h = (rgbColor->r - rgbColor->g) / d + 4.0;
        }
;
        }        h /= 6.0;
    }
    hslColor->setValues(h, s, l, rgbColor->a);
}

void ColorsCls::hslToRgb(Vector4 hslColor, Vector4 rgbColor) {
    if (hslColor->y == 0.0) {
        rgbColor->setValues(hslColor->z, hslColor->z, hslColor->z, hslColor->a);
    } else {
        Unknown q = hslColor->z < 0.5? hslColor->z * (1.0 + hslColor->y) : hslColor->z + hslColor->y - hslColor->z * hslColor->y;
        Unknown p = 2.0 * hslColor->z - q;
        Unknown r = _hueToRgb(p, q, hslColor->x + 1.0 / 3.0);
        Unknown g = _hueToRgb(p, q, hslColor->x);
        Unknown b = _hueToRgb(p, q, hslColor->x - 1.0 / 3.0);
        rgbColor->setValues(r, g, b, hslColor->a);
    }
}

Vector4 ColorsCls::transparent() {
    return make<Vector4Cls>(255.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0, 0.0 / 255.0);
}

Vector4 ColorsCls::aliceBlue() {
    return make<Vector4Cls>(240.0 / 255.0, 248.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::antiqueWhite() {
    return make<Vector4Cls>(250.0 / 255.0, 235.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::aqua() {
    return make<Vector4Cls>(0.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::aquamarine() {
    return make<Vector4Cls>(127.0 / 255.0, 255.0 / 255.0, 212.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::azure() {
    return make<Vector4Cls>(240.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::beige() {
    return make<Vector4Cls>(245.0 / 255.0, 245.0 / 255.0, 220.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::bisque() {
    return make<Vector4Cls>(255.0 / 255.0, 228.0 / 255.0, 196.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::black() {
    return make<Vector4Cls>(0.0 / 255.0, 0.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::blanchedAlmond() {
    return make<Vector4Cls>(255.0 / 255.0, 235.0 / 255.0, 205.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::blue() {
    return make<Vector4Cls>(0.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::blueViolet() {
    return make<Vector4Cls>(138.0 / 255.0, 43.0 / 255.0, 226.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::brown() {
    return make<Vector4Cls>(165.0 / 255.0, 42.0 / 255.0, 42.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::burlyWood() {
    return make<Vector4Cls>(222.0 / 255.0, 184.0 / 255.0, 135.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::cadetBlue() {
    return make<Vector4Cls>(95.0 / 255.0, 158.0 / 255.0, 160.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::chartreuse() {
    return make<Vector4Cls>(127.0 / 255.0, 255.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::chocolate() {
    return make<Vector4Cls>(210.0 / 255.0, 105.0 / 255.0, 30.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::coral() {
    return make<Vector4Cls>(255.0 / 255.0, 127.0 / 255.0, 80.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::cornflowerBlue() {
    return make<Vector4Cls>(100.0 / 255.0, 149.0 / 255.0, 237.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::cornsilk() {
    return make<Vector4Cls>(255.0 / 255.0, 248.0 / 255.0, 220.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::crimson() {
    return make<Vector4Cls>(220.0 / 255.0, 20.0 / 255.0, 60.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::cyan() {
    return make<Vector4Cls>(0.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::darkBlue() {
    return make<Vector4Cls>(0.0 / 255.0, 0.0 / 255.0, 139.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::darkCyan() {
    return make<Vector4Cls>(0.0 / 255.0, 139.0 / 255.0, 139.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::darkGoldenrod() {
    return make<Vector4Cls>(184.0 / 255.0, 134.0 / 255.0, 11.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::darkGray() {
    return make<Vector4Cls>(169.0 / 255.0, 169.0 / 255.0, 169.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::darkGreen() {
    return make<Vector4Cls>(0.0 / 255.0, 100.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::darkKhaki() {
    return make<Vector4Cls>(189.0 / 255.0, 183.0 / 255.0, 107.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::darkMagenta() {
    return make<Vector4Cls>(139.0 / 255.0, 0.0 / 255.0, 139.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::darkOliveGreen() {
    return make<Vector4Cls>(85.0 / 255.0, 107.0 / 255.0, 47.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::darkOrange() {
    return make<Vector4Cls>(255.0 / 255.0, 140.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::darkOrchid() {
    return make<Vector4Cls>(153.0 / 255.0, 50.0 / 255.0, 204.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::darkRed() {
    return make<Vector4Cls>(139.0 / 255.0, 0.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::darkSalmon() {
    return make<Vector4Cls>(233.0 / 255.0, 150.0 / 255.0, 122.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::darkSeaGreen() {
    return make<Vector4Cls>(143.0 / 255.0, 188.0 / 255.0, 139.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::darkSlateBlue() {
    return make<Vector4Cls>(72.0 / 255.0, 61.0 / 255.0, 139.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::darkSlateGray() {
    return make<Vector4Cls>(47.0 / 255.0, 79.0 / 255.0, 79.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::darkTurquoise() {
    return make<Vector4Cls>(0.0 / 255.0, 206.0 / 255.0, 209.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::darkViolet() {
    return make<Vector4Cls>(148.0 / 255.0, 0.0 / 255.0, 211.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::deepPink() {
    return make<Vector4Cls>(255.0 / 255.0, 20.0 / 255.0, 147.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::deepSkyBlue() {
    return make<Vector4Cls>(0.0 / 255.0, 191.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::dimGray() {
    return make<Vector4Cls>(105.0 / 255.0, 105.0 / 255.0, 105.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::dodgerBlue() {
    return make<Vector4Cls>(30.0 / 255.0, 144.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::firebrick() {
    return make<Vector4Cls>(178.0 / 255.0, 34.0 / 255.0, 34.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::floralWhite() {
    return make<Vector4Cls>(255.0 / 255.0, 250.0 / 255.0, 240.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::forestGreen() {
    return make<Vector4Cls>(34.0 / 255.0, 139.0 / 255.0, 34.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::fuchsia() {
    return make<Vector4Cls>(255.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::gainsboro() {
    return make<Vector4Cls>(220.0 / 255.0, 220.0 / 255.0, 220.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::ghostWhite() {
    return make<Vector4Cls>(248.0 / 255.0, 248.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::gold() {
    return make<Vector4Cls>(255.0 / 255.0, 215.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::goldenrod() {
    return make<Vector4Cls>(218.0 / 255.0, 165.0 / 255.0, 32.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::gray() {
    return make<Vector4Cls>(128.0 / 255.0, 128.0 / 255.0, 128.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::green() {
    return make<Vector4Cls>(0.0 / 255.0, 128.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::greenYellow() {
    return make<Vector4Cls>(173.0 / 255.0, 255.0 / 255.0, 47.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::honeydew() {
    return make<Vector4Cls>(240.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::hotPink() {
    return make<Vector4Cls>(255.0 / 255.0, 105.0 / 255.0, 180.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::indianRed() {
    return make<Vector4Cls>(205.0 / 255.0, 92.0 / 255.0, 92.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::indigo() {
    return make<Vector4Cls>(75.0 / 255.0, 0.0 / 255.0, 130.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::ivory() {
    return make<Vector4Cls>(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::khaki() {
    return make<Vector4Cls>(240.0 / 255.0, 230.0 / 255.0, 140.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::lavender() {
    return make<Vector4Cls>(230.0 / 255.0, 230.0 / 255.0, 250.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::lavenderBlush() {
    return make<Vector4Cls>(255.0 / 255.0, 240.0 / 255.0, 245.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::lawnGreen() {
    return make<Vector4Cls>(124.0 / 255.0, 252.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::lemonChiffon() {
    return make<Vector4Cls>(255.0 / 255.0, 250.0 / 255.0, 205.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::lightBlue() {
    return make<Vector4Cls>(173.0 / 255.0, 216.0 / 255.0, 230.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::lightCoral() {
    return make<Vector4Cls>(240.0 / 255.0, 128.0 / 255.0, 128.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::lightCyan() {
    return make<Vector4Cls>(224.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::lightGoldenrodYellow() {
    return make<Vector4Cls>(250.0 / 255.0, 250.0 / 255.0, 210.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::lightGreen() {
    return make<Vector4Cls>(144.0 / 255.0, 238.0 / 255.0, 144.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::lightGray() {
    return make<Vector4Cls>(211.0 / 255.0, 211.0 / 255.0, 211.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::lightPink() {
    return make<Vector4Cls>(255.0 / 255.0, 182.0 / 255.0, 193.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::lightSalmon() {
    return make<Vector4Cls>(255.0 / 255.0, 160.0 / 255.0, 122.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::lightSeaGreen() {
    return make<Vector4Cls>(32.0 / 255.0, 178.0 / 255.0, 170.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::lightSkyBlue() {
    return make<Vector4Cls>(135.0 / 255.0, 206.0 / 255.0, 250.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::lightSlateGray() {
    return make<Vector4Cls>(119.0 / 255.0, 136.0 / 255.0, 153.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::lightSteelBlue() {
    return make<Vector4Cls>(176.0 / 255.0, 196.0 / 255.0, 222.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::lightYellow() {
    return make<Vector4Cls>(255.0 / 255.0, 255.0 / 255.0, 224.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::lime() {
    return make<Vector4Cls>(0.0 / 255.0, 255.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::limeGreen() {
    return make<Vector4Cls>(50.0 / 255.0, 205.0 / 255.0, 50.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::linen() {
    return make<Vector4Cls>(250.0 / 255.0, 240.0 / 255.0, 230.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::magenta() {
    return make<Vector4Cls>(255.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::maroon() {
    return make<Vector4Cls>(128.0 / 255.0, 0.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::mediumAquamarine() {
    return make<Vector4Cls>(102.0 / 255.0, 205.0 / 255.0, 170.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::mediumBlue() {
    return make<Vector4Cls>(0.0 / 255.0, 0.0 / 255.0, 205.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::mediumOrchid() {
    return make<Vector4Cls>(186.0 / 255.0, 85.0 / 255.0, 211.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::mediumPurple() {
    return make<Vector4Cls>(147.0 / 255.0, 112.0 / 255.0, 219.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::mediumSeaGreen() {
    return make<Vector4Cls>(60.0 / 255.0, 179.0 / 255.0, 113.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::mediumSlateBlue() {
    return make<Vector4Cls>(123.0 / 255.0, 104.0 / 255.0, 238.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::mediumSpringGreen() {
    return make<Vector4Cls>(0.0 / 255.0, 250.0 / 255.0, 154.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::mediumTurquoise() {
    return make<Vector4Cls>(72.0 / 255.0, 209.0 / 255.0, 204.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::mediumVioletRed() {
    return make<Vector4Cls>(199.0 / 255.0, 21.0 / 255.0, 133.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::midnightBlue() {
    return make<Vector4Cls>(25.0 / 255.0, 25.0 / 255.0, 112.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::mintCream() {
    return make<Vector4Cls>(245.0 / 255.0, 255.0 / 255.0, 250.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::mistyRose() {
    return make<Vector4Cls>(255.0 / 255.0, 228.0 / 255.0, 225.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::moccasin() {
    return make<Vector4Cls>(255.0 / 255.0, 228.0 / 255.0, 181.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::navajoWhite() {
    return make<Vector4Cls>(255.0 / 255.0, 222.0 / 255.0, 173.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::navy() {
    return make<Vector4Cls>(0.0 / 255.0, 0.0 / 255.0, 128.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::oldLace() {
    return make<Vector4Cls>(253.0 / 255.0, 245.0 / 255.0, 230.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::olive() {
    return make<Vector4Cls>(128.0 / 255.0, 128.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::oliveDrab() {
    return make<Vector4Cls>(107.0 / 255.0, 142.0 / 255.0, 35.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::orange() {
    return make<Vector4Cls>(255.0 / 255.0, 165.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::orangeRed() {
    return make<Vector4Cls>(255.0 / 255.0, 69.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::orchid() {
    return make<Vector4Cls>(218.0 / 255.0, 112.0 / 255.0, 214.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::paleGoldenrod() {
    return make<Vector4Cls>(238.0 / 255.0, 232.0 / 255.0, 170.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::paleGreen() {
    return make<Vector4Cls>(152.0 / 255.0, 251.0 / 255.0, 152.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::paleTurquoise() {
    return make<Vector4Cls>(175.0 / 255.0, 238.0 / 255.0, 238.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::paleVioletRed() {
    return make<Vector4Cls>(219.0 / 255.0, 112.0 / 255.0, 147.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::papayaWhip() {
    return make<Vector4Cls>(255.0 / 255.0, 239.0 / 255.0, 213.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::peachPuff() {
    return make<Vector4Cls>(255.0 / 255.0, 218.0 / 255.0, 185.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::peru() {
    return make<Vector4Cls>(205.0 / 255.0, 133.0 / 255.0, 63.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::pink() {
    return make<Vector4Cls>(255.0 / 255.0, 192.0 / 255.0, 203.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::plum() {
    return make<Vector4Cls>(221.0 / 255.0, 160.0 / 255.0, 221.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::powderBlue() {
    return make<Vector4Cls>(176.0 / 255.0, 224.0 / 255.0, 230.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::purple() {
    return make<Vector4Cls>(128.0 / 255.0, 0.0 / 255.0, 128.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::red() {
    return make<Vector4Cls>(255.0 / 255.0, 0.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::rosyBrown() {
    return make<Vector4Cls>(188.0 / 255.0, 143.0 / 255.0, 143.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::royalBlue() {
    return make<Vector4Cls>(65.0 / 255.0, 105.0 / 255.0, 225.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::saddleBrown() {
    return make<Vector4Cls>(139.0 / 255.0, 69.0 / 255.0, 19.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::salmon() {
    return make<Vector4Cls>(250.0 / 255.0, 128.0 / 255.0, 114.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::sandyBrown() {
    return make<Vector4Cls>(244.0 / 255.0, 164.0 / 255.0, 96.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::seaGreen() {
    return make<Vector4Cls>(46.0 / 255.0, 139.0 / 255.0, 87.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::seaShell() {
    return make<Vector4Cls>(255.0 / 255.0, 245.0 / 255.0, 238.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::sienna() {
    return make<Vector4Cls>(160.0 / 255.0, 82.0 / 255.0, 45.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::silver() {
    return make<Vector4Cls>(192.0 / 255.0, 192.0 / 255.0, 192.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::skyBlue() {
    return make<Vector4Cls>(135.0 / 255.0, 206.0 / 255.0, 235.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::slateBlue() {
    return make<Vector4Cls>(106.0 / 255.0, 90.0 / 255.0, 205.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::slateGray() {
    return make<Vector4Cls>(112.0 / 255.0, 128.0 / 255.0, 144.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::snow() {
    return make<Vector4Cls>(255.0 / 255.0, 250.0 / 255.0, 250.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::springGreen() {
    return make<Vector4Cls>(0.0 / 255.0, 255.0 / 255.0, 127.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::steelBlue() {
    return make<Vector4Cls>(70.0 / 255.0, 130.0 / 255.0, 180.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::tan() {
    return make<Vector4Cls>(210.0 / 255.0, 180.0 / 255.0, 140.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::teal() {
    return make<Vector4Cls>(0.0 / 255.0, 128.0 / 255.0, 128.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::thistle() {
    return make<Vector4Cls>(216.0 / 255.0, 191.0 / 255.0, 216.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::tomato() {
    return make<Vector4Cls>(255.0 / 255.0, 99.0 / 255.0, 71.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::turquoise() {
    return make<Vector4Cls>(64.0 / 255.0, 224.0 / 255.0, 208.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::violet() {
    return make<Vector4Cls>(238.0 / 255.0, 130.0 / 255.0, 238.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::wheat() {
    return make<Vector4Cls>(245.0 / 255.0, 222.0 / 255.0, 179.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::white() {
    return make<Vector4Cls>(255.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::whiteSmoke() {
    return make<Vector4Cls>(245.0 / 255.0, 245.0 / 255.0, 245.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::yellow() {
    return make<Vector4Cls>(255.0 / 255.0, 255.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 ColorsCls::yellowGreen() {
    return make<Vector4Cls>(154.0 / 255.0, 205.0 / 255.0, 50.0 / 255.0, 255.0 / 255.0);
}

double ColorsCls::_hueToRgb(double p, double q, double t) {
    if ( < 0.0) {
        t += 1.0;
    } else {
        if (t > 1.0) {
        t -= 1.0;
    }
;
    }    if ( < 1.0 / 6.0) {
        return p + (q - p) * 6.0 * t;
    } else {
        if ( < 1.0 / 2.0) {
        return q;
    } else {
        if ( < 2.0 / 3.0) {
        return p + (q - p) * (2.0 / 3.0 - t) * 6.0;
    } else {
        return p;
    }
;
    };
    }}
