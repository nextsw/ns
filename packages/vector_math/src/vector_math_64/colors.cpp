#include "colors.hpp"
void Colors::fromRgba(int a, int b, int g, int r, Vector4 result) {
    result.setValues(r / 255.0, g / 255.0, b / 255.0, a / 255.0);
}

void Colors::fromHexString(Vector4 result, String value) {
    Unknown fullMatch = _hexStringFullRegex.matchAsPrefix(value);
    if (fullMatch != nullptr) {
        if (fullMatch[4] == nullptr) {
            Unknown r = int.parse(fullMatch[1]!16);
            Unknown g = int.parse(fullMatch[2]!16);
            Unknown b = int.parse(fullMatch[3]!16);
            fromRgba(r, g, b, 255, result);
            return;
        } else {
            Unknown a = int.parse(fullMatch[1]!16);
            Unknown r = int.parse(fullMatch[2]!16);
            Unknown g = int.parse(fullMatch[3]!16);
            Unknown b = int.parse(fullMatch[4]!16);
            fromRgba(r, g, b, a, result);
            return;
        }
    }
    Unknown smallMatch = _hexStringSmallRegex.matchAsPrefix(value);
    if (smallMatch != nullptr) {
        if (smallMatch[4] == nullptr) {
            Unknown r = int.parse(smallMatch[1]! + smallMatch[1]!16);
            Unknown g = int.parse(smallMatch[2]! + smallMatch[2]!16);
            Unknown b = int.parse(smallMatch[3]! + smallMatch[3]!16);
            fromRgba(r, g, b, 255, result);
            return;
        } else {
            Unknown a = int.parse(smallMatch[1]! + smallMatch[1]!16);
            Unknown r = int.parse(smallMatch[2]! + smallMatch[2]!16);
            Unknown g = int.parse(smallMatch[3]! + smallMatch[3]!16);
            Unknown b = int.parse(smallMatch[4]! + smallMatch[4]!16);
            fromRgba(r, g, b, a, result);
            return;
        }
    }
    ;
}

String Colors::toHexString(bool alpha, Vector4 input, bool short) {
    Unknown r = (input.r * 0xFF).floor() & 0xFF;
    Unknown g = (input.g * 0xFF).floor() & 0xFF;
    Unknown b = (input.b * 0xFF).floor() & 0xFF;
    Unknown a = (input.a * 0xFF).floor() & 0xFF;
    Unknown isShort = short && ((r >> 4) == (r & 0xF)) && ((g >> 4) == (g & 0xF)) && ((b >> 4) == (b & 0xF)) && (!alpha || (a >> 4) == (a & 0xF));
    if (isShort) {
        Unknown rgb = (r & 0xF).toRadixString(16) + (g & 0xF).toRadixString(16) + (b & 0xF).toRadixString(16);
        return alpha? (a & 0xF).toRadixString(16) + rgb : rgb;
    } else {
        Unknown rgb = r.toRadixString(16).padLeft(2, "0") + g.toRadixString(16).padLeft(2, "0") + b.toRadixString(16).padLeft(2, "0");
        return alpha? a.toRadixString(16).padLeft(2, "0") + rgb : rgb;
    }
}

void Colors::alphaBlend(Vector4 background, Vector4 foreground, Vector4 result) {
    Unknown a = foreground.a + (1.0 - foreground.a) * background.a;
    Unknown factor = 1.0 / a;
    Unknown r = factor * (foreground.a * foreground.r + (1.0 - foreground.a) * background.a * background.r);
    Unknown g = factor * (foreground.a * foreground.g + (1.0 - foreground.a) * background.a * background.g);
    Unknown b = factor * (foreground.a * foreground.b + (1.0 - foreground.a) * background.a * background.b);
    result.setValues(r, g, b, a);
}

void Colors::toGrayscale(Vector4 input, Vector4 result) {
    Unknown value = 0.21 * input.r + 0.71 * input.g + 0.07 * input.b;
    ;
}

void Colors::linearToGamma(double gamma, Vector4 gammaColor, Vector4 linearColor) {
    Unknown exponent = 1.0 / gamma;
    ;
}

void Colors::gammaToLinear(double gamma, Vector4 gammaColor, Vector4 linearColor) {
    ;
}

void Colors::rgbToHsv(Vector4 hsvColor, Vector4 rgbColor) {
    Unknown max = math.max(math.max(rgbColor.r, rgbColor.g), rgbColor.b);
    Unknown min = math.min(math.min(rgbColor.r, rgbColor.g), rgbColor.b);
    Unknown d = max - min;
    Unknown v = max;
    Unknown s = max == 0.0? 0.0 : d / max;
    auto h = 0.0;
    if (max != min) {
        if (max == rgbColor.r) {
            h = (rgbColor.g - rgbColor.b) / d + (rgbColor.g < rgbColor.b? 6.0 : 0.0);
        } else         {
            if (max == rgbColor.g) {
            h = (rgbColor.b - rgbColor.r) / d + 2.0;
        } else {
            h = (rgbColor.r - rgbColor.g) / d + 4.0;
        }
;
        }        h = 6.0;
    }
    hsvColor.setValues(h, s, v, rgbColor.a);
}

void Colors::hsvToRgb(Vector4 hsvColor, Vector4 rgbColor) {
    Unknown i = (hsvColor.x * 6.0).floor();
    Unknown f = hsvColor.x * 6.0 - i.toDouble();
    Unknown p = hsvColor.z * (1.0 - hsvColor.y);
    Unknown q = hsvColor.z * (1.0 - f * hsvColor.y);
    Unknown t = hsvColor.z * (1.0 - (1.0 - f) * hsvColor.y);
    ;
}

void Colors::rgbToHsl(Vector4 hslColor, Vector4 rgbColor) {
    Unknown max = math.max(math.max(rgbColor.r, rgbColor.g), rgbColor.b);
    Unknown min = math.min(math.min(rgbColor.r, rgbColor.g), rgbColor.b);
    Unknown l = (max + min) / 2.0;
    auto h = 0.0;
    auto s = 0.0;
    if (max != min) {
        Unknown d = max - min;
        s = l > 0.5? d / (2.0 - max - min) : d / (max + min);
        if (max == rgbColor.r) {
            h = (rgbColor.g - rgbColor.b) / d + (rgbColor.g < rgbColor.b? 6.0 : 0.0);
        } else         {
            if (max == rgbColor.g) {
            h = (rgbColor.b - rgbColor.r) / d + 2.0;
        } else {
            h = (rgbColor.r - rgbColor.g) / d + 4.0;
        }
;
        }        h = 6.0;
    }
    hslColor.setValues(h, s, l, rgbColor.a);
}

void Colors::hslToRgb(Vector4 hslColor, Vector4 rgbColor) {
    if (hslColor.y == 0.0) {
        rgbColor.setValues(hslColor.z, hslColor.z, hslColor.z, hslColor.a);
    } else {
        Unknown q = hslColor.z < 0.5? hslColor.z * (1.0 + hslColor.y) : hslColor.z + hslColor.y - hslColor.z * hslColor.y;
        Unknown p = 2.0 * hslColor.z - q;
        Unknown r = _hueToRgb(p, q, hslColor.x + 1.0 / 3.0);
        Unknown g = _hueToRgb(p, q, hslColor.x);
        Unknown b = _hueToRgb(p, q, hslColor.x - 1.0 / 3.0);
        rgbColor.setValues(r, g, b, hslColor.a);
    }
}

Vector4 Colors::transparent() {
    return Vector4(255.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0, 0.0 / 255.0);
}

Vector4 Colors::aliceBlue() {
    return Vector4(240.0 / 255.0, 248.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::antiqueWhite() {
    return Vector4(250.0 / 255.0, 235.0 / 255.0, 215.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::aqua() {
    return Vector4(0.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::aquamarine() {
    return Vector4(127.0 / 255.0, 255.0 / 255.0, 212.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::azure() {
    return Vector4(240.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::beige() {
    return Vector4(245.0 / 255.0, 245.0 / 255.0, 220.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::bisque() {
    return Vector4(255.0 / 255.0, 228.0 / 255.0, 196.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::black() {
    return Vector4(0.0 / 255.0, 0.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::blanchedAlmond() {
    return Vector4(255.0 / 255.0, 235.0 / 255.0, 205.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::blue() {
    return Vector4(0.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::blueViolet() {
    return Vector4(138.0 / 255.0, 43.0 / 255.0, 226.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::brown() {
    return Vector4(165.0 / 255.0, 42.0 / 255.0, 42.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::burlyWood() {
    return Vector4(222.0 / 255.0, 184.0 / 255.0, 135.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::cadetBlue() {
    return Vector4(95.0 / 255.0, 158.0 / 255.0, 160.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::chartreuse() {
    return Vector4(127.0 / 255.0, 255.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::chocolate() {
    return Vector4(210.0 / 255.0, 105.0 / 255.0, 30.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::coral() {
    return Vector4(255.0 / 255.0, 127.0 / 255.0, 80.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::cornflowerBlue() {
    return Vector4(100.0 / 255.0, 149.0 / 255.0, 237.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::cornsilk() {
    return Vector4(255.0 / 255.0, 248.0 / 255.0, 220.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::crimson() {
    return Vector4(220.0 / 255.0, 20.0 / 255.0, 60.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::cyan() {
    return Vector4(0.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::darkBlue() {
    return Vector4(0.0 / 255.0, 0.0 / 255.0, 139.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::darkCyan() {
    return Vector4(0.0 / 255.0, 139.0 / 255.0, 139.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::darkGoldenrod() {
    return Vector4(184.0 / 255.0, 134.0 / 255.0, 11.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::darkGray() {
    return Vector4(169.0 / 255.0, 169.0 / 255.0, 169.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::darkGreen() {
    return Vector4(0.0 / 255.0, 100.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::darkKhaki() {
    return Vector4(189.0 / 255.0, 183.0 / 255.0, 107.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::darkMagenta() {
    return Vector4(139.0 / 255.0, 0.0 / 255.0, 139.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::darkOliveGreen() {
    return Vector4(85.0 / 255.0, 107.0 / 255.0, 47.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::darkOrange() {
    return Vector4(255.0 / 255.0, 140.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::darkOrchid() {
    return Vector4(153.0 / 255.0, 50.0 / 255.0, 204.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::darkRed() {
    return Vector4(139.0 / 255.0, 0.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::darkSalmon() {
    return Vector4(233.0 / 255.0, 150.0 / 255.0, 122.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::darkSeaGreen() {
    return Vector4(143.0 / 255.0, 188.0 / 255.0, 139.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::darkSlateBlue() {
    return Vector4(72.0 / 255.0, 61.0 / 255.0, 139.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::darkSlateGray() {
    return Vector4(47.0 / 255.0, 79.0 / 255.0, 79.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::darkTurquoise() {
    return Vector4(0.0 / 255.0, 206.0 / 255.0, 209.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::darkViolet() {
    return Vector4(148.0 / 255.0, 0.0 / 255.0, 211.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::deepPink() {
    return Vector4(255.0 / 255.0, 20.0 / 255.0, 147.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::deepSkyBlue() {
    return Vector4(0.0 / 255.0, 191.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::dimGray() {
    return Vector4(105.0 / 255.0, 105.0 / 255.0, 105.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::dodgerBlue() {
    return Vector4(30.0 / 255.0, 144.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::firebrick() {
    return Vector4(178.0 / 255.0, 34.0 / 255.0, 34.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::floralWhite() {
    return Vector4(255.0 / 255.0, 250.0 / 255.0, 240.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::forestGreen() {
    return Vector4(34.0 / 255.0, 139.0 / 255.0, 34.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::fuchsia() {
    return Vector4(255.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::gainsboro() {
    return Vector4(220.0 / 255.0, 220.0 / 255.0, 220.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::ghostWhite() {
    return Vector4(248.0 / 255.0, 248.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::gold() {
    return Vector4(255.0 / 255.0, 215.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::goldenrod() {
    return Vector4(218.0 / 255.0, 165.0 / 255.0, 32.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::gray() {
    return Vector4(128.0 / 255.0, 128.0 / 255.0, 128.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::green() {
    return Vector4(0.0 / 255.0, 128.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::greenYellow() {
    return Vector4(173.0 / 255.0, 255.0 / 255.0, 47.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::honeydew() {
    return Vector4(240.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::hotPink() {
    return Vector4(255.0 / 255.0, 105.0 / 255.0, 180.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::indianRed() {
    return Vector4(205.0 / 255.0, 92.0 / 255.0, 92.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::indigo() {
    return Vector4(75.0 / 255.0, 0.0 / 255.0, 130.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::ivory() {
    return Vector4(255.0 / 255.0, 255.0 / 255.0, 240.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::khaki() {
    return Vector4(240.0 / 255.0, 230.0 / 255.0, 140.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::lavender() {
    return Vector4(230.0 / 255.0, 230.0 / 255.0, 250.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::lavenderBlush() {
    return Vector4(255.0 / 255.0, 240.0 / 255.0, 245.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::lawnGreen() {
    return Vector4(124.0 / 255.0, 252.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::lemonChiffon() {
    return Vector4(255.0 / 255.0, 250.0 / 255.0, 205.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::lightBlue() {
    return Vector4(173.0 / 255.0, 216.0 / 255.0, 230.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::lightCoral() {
    return Vector4(240.0 / 255.0, 128.0 / 255.0, 128.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::lightCyan() {
    return Vector4(224.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::lightGoldenrodYellow() {
    return Vector4(250.0 / 255.0, 250.0 / 255.0, 210.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::lightGreen() {
    return Vector4(144.0 / 255.0, 238.0 / 255.0, 144.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::lightGray() {
    return Vector4(211.0 / 255.0, 211.0 / 255.0, 211.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::lightPink() {
    return Vector4(255.0 / 255.0, 182.0 / 255.0, 193.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::lightSalmon() {
    return Vector4(255.0 / 255.0, 160.0 / 255.0, 122.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::lightSeaGreen() {
    return Vector4(32.0 / 255.0, 178.0 / 255.0, 170.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::lightSkyBlue() {
    return Vector4(135.0 / 255.0, 206.0 / 255.0, 250.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::lightSlateGray() {
    return Vector4(119.0 / 255.0, 136.0 / 255.0, 153.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::lightSteelBlue() {
    return Vector4(176.0 / 255.0, 196.0 / 255.0, 222.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::lightYellow() {
    return Vector4(255.0 / 255.0, 255.0 / 255.0, 224.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::lime() {
    return Vector4(0.0 / 255.0, 255.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::limeGreen() {
    return Vector4(50.0 / 255.0, 205.0 / 255.0, 50.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::linen() {
    return Vector4(250.0 / 255.0, 240.0 / 255.0, 230.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::magenta() {
    return Vector4(255.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::maroon() {
    return Vector4(128.0 / 255.0, 0.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::mediumAquamarine() {
    return Vector4(102.0 / 255.0, 205.0 / 255.0, 170.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::mediumBlue() {
    return Vector4(0.0 / 255.0, 0.0 / 255.0, 205.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::mediumOrchid() {
    return Vector4(186.0 / 255.0, 85.0 / 255.0, 211.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::mediumPurple() {
    return Vector4(147.0 / 255.0, 112.0 / 255.0, 219.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::mediumSeaGreen() {
    return Vector4(60.0 / 255.0, 179.0 / 255.0, 113.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::mediumSlateBlue() {
    return Vector4(123.0 / 255.0, 104.0 / 255.0, 238.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::mediumSpringGreen() {
    return Vector4(0.0 / 255.0, 250.0 / 255.0, 154.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::mediumTurquoise() {
    return Vector4(72.0 / 255.0, 209.0 / 255.0, 204.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::mediumVioletRed() {
    return Vector4(199.0 / 255.0, 21.0 / 255.0, 133.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::midnightBlue() {
    return Vector4(25.0 / 255.0, 25.0 / 255.0, 112.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::mintCream() {
    return Vector4(245.0 / 255.0, 255.0 / 255.0, 250.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::mistyRose() {
    return Vector4(255.0 / 255.0, 228.0 / 255.0, 225.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::moccasin() {
    return Vector4(255.0 / 255.0, 228.0 / 255.0, 181.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::navajoWhite() {
    return Vector4(255.0 / 255.0, 222.0 / 255.0, 173.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::navy() {
    return Vector4(0.0 / 255.0, 0.0 / 255.0, 128.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::oldLace() {
    return Vector4(253.0 / 255.0, 245.0 / 255.0, 230.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::olive() {
    return Vector4(128.0 / 255.0, 128.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::oliveDrab() {
    return Vector4(107.0 / 255.0, 142.0 / 255.0, 35.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::orange() {
    return Vector4(255.0 / 255.0, 165.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::orangeRed() {
    return Vector4(255.0 / 255.0, 69.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::orchid() {
    return Vector4(218.0 / 255.0, 112.0 / 255.0, 214.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::paleGoldenrod() {
    return Vector4(238.0 / 255.0, 232.0 / 255.0, 170.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::paleGreen() {
    return Vector4(152.0 / 255.0, 251.0 / 255.0, 152.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::paleTurquoise() {
    return Vector4(175.0 / 255.0, 238.0 / 255.0, 238.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::paleVioletRed() {
    return Vector4(219.0 / 255.0, 112.0 / 255.0, 147.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::papayaWhip() {
    return Vector4(255.0 / 255.0, 239.0 / 255.0, 213.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::peachPuff() {
    return Vector4(255.0 / 255.0, 218.0 / 255.0, 185.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::peru() {
    return Vector4(205.0 / 255.0, 133.0 / 255.0, 63.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::pink() {
    return Vector4(255.0 / 255.0, 192.0 / 255.0, 203.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::plum() {
    return Vector4(221.0 / 255.0, 160.0 / 255.0, 221.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::powderBlue() {
    return Vector4(176.0 / 255.0, 224.0 / 255.0, 230.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::purple() {
    return Vector4(128.0 / 255.0, 0.0 / 255.0, 128.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::red() {
    return Vector4(255.0 / 255.0, 0.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::rosyBrown() {
    return Vector4(188.0 / 255.0, 143.0 / 255.0, 143.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::royalBlue() {
    return Vector4(65.0 / 255.0, 105.0 / 255.0, 225.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::saddleBrown() {
    return Vector4(139.0 / 255.0, 69.0 / 255.0, 19.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::salmon() {
    return Vector4(250.0 / 255.0, 128.0 / 255.0, 114.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::sandyBrown() {
    return Vector4(244.0 / 255.0, 164.0 / 255.0, 96.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::seaGreen() {
    return Vector4(46.0 / 255.0, 139.0 / 255.0, 87.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::seaShell() {
    return Vector4(255.0 / 255.0, 245.0 / 255.0, 238.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::sienna() {
    return Vector4(160.0 / 255.0, 82.0 / 255.0, 45.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::silver() {
    return Vector4(192.0 / 255.0, 192.0 / 255.0, 192.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::skyBlue() {
    return Vector4(135.0 / 255.0, 206.0 / 255.0, 235.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::slateBlue() {
    return Vector4(106.0 / 255.0, 90.0 / 255.0, 205.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::slateGray() {
    return Vector4(112.0 / 255.0, 128.0 / 255.0, 144.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::snow() {
    return Vector4(255.0 / 255.0, 250.0 / 255.0, 250.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::springGreen() {
    return Vector4(0.0 / 255.0, 255.0 / 255.0, 127.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::steelBlue() {
    return Vector4(70.0 / 255.0, 130.0 / 255.0, 180.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::tan() {
    return Vector4(210.0 / 255.0, 180.0 / 255.0, 140.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::teal() {
    return Vector4(0.0 / 255.0, 128.0 / 255.0, 128.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::thistle() {
    return Vector4(216.0 / 255.0, 191.0 / 255.0, 216.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::tomato() {
    return Vector4(255.0 / 255.0, 99.0 / 255.0, 71.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::turquoise() {
    return Vector4(64.0 / 255.0, 224.0 / 255.0, 208.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::violet() {
    return Vector4(238.0 / 255.0, 130.0 / 255.0, 238.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::wheat() {
    return Vector4(245.0 / 255.0, 222.0 / 255.0, 179.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::white() {
    return Vector4(255.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::whiteSmoke() {
    return Vector4(245.0 / 255.0, 245.0 / 255.0, 245.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::yellow() {
    return Vector4(255.0 / 255.0, 255.0 / 255.0, 0.0 / 255.0, 255.0 / 255.0);
}

Vector4 Colors::yellowGreen() {
    return Vector4(154.0 / 255.0, 205.0 / 255.0, 50.0 / 255.0, 255.0 / 255.0);
}

double Colors::_hueToRgb(double p, double q, double t) {
    if ( < 0.0) {
        t = 1.0;
    } else     {
        if (t > 1.0) {
        t = 1.0;
    }
;
    }    if ( < 1.0 / 6.0) {
        return p + (q - p) * 6.0 * t;
    } else     {
        if ( < 1.0 / 2.0) {
        return q;
    } else     {
        if ( < 2.0 / 3.0) {
        return p + (q - p) * (2.0 / 3.0 - t) * 6.0;
    } else {
        return p;
    }
;
    };
    }}
