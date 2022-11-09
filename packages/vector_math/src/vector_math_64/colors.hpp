#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_COLORS
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_COLORS
#include <base.hpp>

#include <dart/core/core.hpp>


class ColorsCls : public ObjectCls {
public:

    static void fromRgba(int a, int b, int g, int r, Vector4 result);

    static void fromHexString(Vector4 result, String value);

    static String toHexString(bool alpha, Vector4 input, bool short);

    static void alphaBlend(Vector4 background, Vector4 foreground, Vector4 result);

    static void toGrayscale(Vector4 input, Vector4 result);

    static void linearToGamma(double gamma, Vector4 gammaColor, Vector4 linearColor);

    static void gammaToLinear(double gamma, Vector4 gammaColor, Vector4 linearColor);

    static void rgbToHsv(Vector4 hsvColor, Vector4 rgbColor);

    static void hsvToRgb(Vector4 hsvColor, Vector4 rgbColor);

    static void rgbToHsl(Vector4 hslColor, Vector4 rgbColor);

    static void hslToRgb(Vector4 hslColor, Vector4 rgbColor);

    static Vector4 transparent();

    static Vector4 aliceBlue();

    static Vector4 antiqueWhite();

    static Vector4 aqua();

    static Vector4 aquamarine();

    static Vector4 azure();

    static Vector4 beige();

    static Vector4 bisque();

    static Vector4 black();

    static Vector4 blanchedAlmond();

    static Vector4 blue();

    static Vector4 blueViolet();

    static Vector4 brown();

    static Vector4 burlyWood();

    static Vector4 cadetBlue();

    static Vector4 chartreuse();

    static Vector4 chocolate();

    static Vector4 coral();

    static Vector4 cornflowerBlue();

    static Vector4 cornsilk();

    static Vector4 crimson();

    static Vector4 cyan();

    static Vector4 darkBlue();

    static Vector4 darkCyan();

    static Vector4 darkGoldenrod();

    static Vector4 darkGray();

    static Vector4 darkGreen();

    static Vector4 darkKhaki();

    static Vector4 darkMagenta();

    static Vector4 darkOliveGreen();

    static Vector4 darkOrange();

    static Vector4 darkOrchid();

    static Vector4 darkRed();

    static Vector4 darkSalmon();

    static Vector4 darkSeaGreen();

    static Vector4 darkSlateBlue();

    static Vector4 darkSlateGray();

    static Vector4 darkTurquoise();

    static Vector4 darkViolet();

    static Vector4 deepPink();

    static Vector4 deepSkyBlue();

    static Vector4 dimGray();

    static Vector4 dodgerBlue();

    static Vector4 firebrick();

    static Vector4 floralWhite();

    static Vector4 forestGreen();

    static Vector4 fuchsia();

    static Vector4 gainsboro();

    static Vector4 ghostWhite();

    static Vector4 gold();

    static Vector4 goldenrod();

    static Vector4 gray();

    static Vector4 green();

    static Vector4 greenYellow();

    static Vector4 honeydew();

    static Vector4 hotPink();

    static Vector4 indianRed();

    static Vector4 indigo();

    static Vector4 ivory();

    static Vector4 khaki();

    static Vector4 lavender();

    static Vector4 lavenderBlush();

    static Vector4 lawnGreen();

    static Vector4 lemonChiffon();

    static Vector4 lightBlue();

    static Vector4 lightCoral();

    static Vector4 lightCyan();

    static Vector4 lightGoldenrodYellow();

    static Vector4 lightGreen();

    static Vector4 lightGray();

    static Vector4 lightPink();

    static Vector4 lightSalmon();

    static Vector4 lightSeaGreen();

    static Vector4 lightSkyBlue();

    static Vector4 lightSlateGray();

    static Vector4 lightSteelBlue();

    static Vector4 lightYellow();

    static Vector4 lime();

    static Vector4 limeGreen();

    static Vector4 linen();

    static Vector4 magenta();

    static Vector4 maroon();

    static Vector4 mediumAquamarine();

    static Vector4 mediumBlue();

    static Vector4 mediumOrchid();

    static Vector4 mediumPurple();

    static Vector4 mediumSeaGreen();

    static Vector4 mediumSlateBlue();

    static Vector4 mediumSpringGreen();

    static Vector4 mediumTurquoise();

    static Vector4 mediumVioletRed();

    static Vector4 midnightBlue();

    static Vector4 mintCream();

    static Vector4 mistyRose();

    static Vector4 moccasin();

    static Vector4 navajoWhite();

    static Vector4 navy();

    static Vector4 oldLace();

    static Vector4 olive();

    static Vector4 oliveDrab();

    static Vector4 orange();

    static Vector4 orangeRed();

    static Vector4 orchid();

    static Vector4 paleGoldenrod();

    static Vector4 paleGreen();

    static Vector4 paleTurquoise();

    static Vector4 paleVioletRed();

    static Vector4 papayaWhip();

    static Vector4 peachPuff();

    static Vector4 peru();

    static Vector4 pink();

    static Vector4 plum();

    static Vector4 powderBlue();

    static Vector4 purple();

    static Vector4 red();

    static Vector4 rosyBrown();

    static Vector4 royalBlue();

    static Vector4 saddleBrown();

    static Vector4 salmon();

    static Vector4 sandyBrown();

    static Vector4 seaGreen();

    static Vector4 seaShell();

    static Vector4 sienna();

    static Vector4 silver();

    static Vector4 skyBlue();

    static Vector4 slateBlue();

    static Vector4 slateGray();

    static Vector4 snow();

    static Vector4 springGreen();

    static Vector4 steelBlue();

    static Vector4 tan();

    static Vector4 teal();

    static Vector4 thistle();

    static Vector4 tomato();

    static Vector4 turquoise();

    static Vector4 violet();

    static Vector4 wheat();

    static Vector4 white();

    static Vector4 whiteSmoke();

    static Vector4 yellow();

    static Vector4 yellowGreen();

private:
    static auto  _hexStringFullRegex;

    static auto  _hexStringSmallRegex;


    static double _hueToRgb(double p, double q, double t);

    virtual void  _();
};
using Colors = std::shared_ptr<ColorsCls>;


#endif