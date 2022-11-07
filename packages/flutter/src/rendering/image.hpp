#ifndef IMAGE_H
#define IMAGE_H
#include <memory>
#include <flutter/painting.hpp>

#include <ui/ui.hpp>
#include <flutter/animation.hpp>
#include "box.hpp"
#include "object.hpp"



class RenderImage : RenderBox {
public:
    String debugImageLabel;


     RenderImage(AlignmentGeometry alignment, Rect centerSlice, Color color, BlendMode colorBlendMode, String debugImageLabel, FilterQuality filterQuality, BoxFit fit, double height, Image image, bool invertColors, bool isAntiAlias, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, TextDirection textDirection, double width);

    Image image();

    void  image(Image value);

    double width();

    void  width(double value);

    double height();

    void  height(double value);

    double scale();

    void  scale(double value);

    Color color();

    void  color(Color value);

    Animation<double> opacity();

    void  opacity(Animation<double> value);

    FilterQuality filterQuality();

    void  filterQuality(FilterQuality value);

    BlendMode colorBlendMode();

    void  colorBlendMode(BlendMode value);

    BoxFit fit();

    void  fit(BoxFit value);

    AlignmentGeometry alignment();

    void  alignment(AlignmentGeometry value);

    ImageRepeat repeat();

    void  repeat(ImageRepeat value);

    Rect centerSlice();

    void  centerSlice(Rect value);

    bool invertColors();

    void  invertColors(bool value);

    bool matchTextDirection();

    void  matchTextDirection(bool value);

    TextDirection textDirection();

    void  textDirection(TextDirection value);

    bool isAntiAlias();

    void  isAntiAlias(bool value);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    bool hitTestSelf(Offset position);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    void attach(PipelineOwner owner);

    void detach();

    void paint(PaintingContext context, Offset offset);

    void dispose();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

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


    void _resolve();

    void _markNeedResolution();

    void _updateColorFilter();

    Size _sizeForConstraints(BoxConstraints constraints);

};

#endif