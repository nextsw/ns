#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_IMAGE
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_IMAGE
#include <base.hpp>
#include <packages/flutter/flutter.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/flutter.hpp>
#include "box.hpp"
#include "object.hpp"


class RenderImageCls : public RenderBoxCls {
public:
    String debugImageLabel;


     RenderImageCls(AlignmentGeometry alignment, Rect centerSlice, Color color, BlendMode colorBlendMode, String debugImageLabel, FilterQuality filterQuality, BoxFit fit, double height, Image image, bool invertColors, bool isAntiAlias, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, TextDirection textDirection, double width);

    virtual Image image();

    virtual void  image(Image value);

    virtual double width();

    virtual void  width(double value);

    virtual double height();

    virtual void  height(double value);

    virtual double scale();

    virtual void  scale(double value);

    virtual Color color();

    virtual void  color(Color value);

    virtual Animation<double> opacity();

    virtual void  opacity(Animation<double> value);

    virtual FilterQuality filterQuality();

    virtual void  filterQuality(FilterQuality value);

    virtual BlendMode colorBlendMode();

    virtual void  colorBlendMode(BlendMode value);

    virtual BoxFit fit();

    virtual void  fit(BoxFit value);

    virtual AlignmentGeometry alignment();

    virtual void  alignment(AlignmentGeometry value);

    virtual ImageRepeat repeat();

    virtual void  repeat(ImageRepeat value);

    virtual Rect centerSlice();

    virtual void  centerSlice(Rect value);

    virtual bool invertColors();

    virtual void  invertColors(bool value);

    virtual bool matchTextDirection();

    virtual void  matchTextDirection(bool value);

    virtual TextDirection textDirection();

    virtual void  textDirection(TextDirection value);

    virtual bool isAntiAlias();

    virtual void  isAntiAlias(bool value);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual bool hitTestSelf(Offset position);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual void paint(PaintingContext context, Offset offset);

    virtual void dispose();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Alignment _resolvedAlignment;

    bool _flipHorizontally;

    Image _image;

    double _width;

    double _height;

    double _scale;

    ColorFilter _colorFilter;

    Color _color;

    Animation<double> _opacity;

    FilterQuality _filterQuality;

    BlendMode _colorBlendMode;

    BoxFit _fit;

    AlignmentGeometry _alignment;

    ImageRepeat _repeat;

    Rect _centerSlice;

    bool _invertColors;

    bool _matchTextDirection;

    TextDirection _textDirection;

    bool _isAntiAlias;


    virtual void _resolve();

    virtual void _markNeedResolution();

    virtual void _updateColorFilter();

    virtual Size _sizeForConstraints(BoxConstraints constraints);

};
using RenderImage = std::shared_ptr<RenderImageCls>;


#endif