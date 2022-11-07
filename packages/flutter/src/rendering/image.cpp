#include "image.hpp"
RenderImage::RenderImage(AlignmentGeometry alignment, Rect centerSlice, Color color, BlendMode colorBlendMode, String debugImageLabel, FilterQuality filterQuality, BoxFit fit, double height, Image image, bool invertColors, bool isAntiAlias, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, TextDirection textDirection, double width) {
    {
        assert(scale != nullptr);
        assert(repeat != nullptr);
        assert(alignment != nullptr);
        assert(filterQuality != nullptr);
        assert(matchTextDirection != nullptr);
        assert(isAntiAlias != nullptr);
        _image = image;
        _width = width;
        _height = height;
        _scale = scale;
        _color = color;
        _opacity = opacity;
        _colorBlendMode = colorBlendMode;
        _fit = fit;
        _alignment = alignment;
        _repeat = repeat;
        _centerSlice = centerSlice;
        _matchTextDirection = matchTextDirection;
        _invertColors = invertColors;
        _textDirection = textDirection;
        _isAntiAlias = isAntiAlias;
        _filterQuality = filterQuality;
    }
    {
        _updateColorFilter();
    }
}

Image RenderImage::image() {
    return _image;
}

void RenderImage::image(Image value) {
    if (value == _image) {
        return;
    }
    if (value != nullptr && _image != nullptr && value.isCloneOf(_image!)) {
        value.dispose();
        return;
    }
    _image?.dispose();
    _image = value;
    markNeedsPaint();
    if (_width == nullptr || _height == nullptr) {
        markNeedsLayout();
    }
}

double RenderImage::width() {
    return _width;
}

void RenderImage::width(double value) {
    if (value == _width) {
        return;
    }
    _width = value;
    markNeedsLayout();
}

double RenderImage::height() {
    return _height;
}

void RenderImage::height(double value) {
    if (value == _height) {
        return;
    }
    _height = value;
    markNeedsLayout();
}

double RenderImage::scale() {
    return _scale;
}

void RenderImage::scale(double value) {
    assert(value != nullptr);
    if (value == _scale) {
        return;
    }
    _scale = value;
    markNeedsLayout();
}

Color RenderImage::color() {
    return _color;
}

void RenderImage::color(Color value) {
    if (value == _color) {
        return;
    }
    _color = value;
    _updateColorFilter();
    markNeedsPaint();
}

Animation<double> RenderImage::opacity() {
    return _opacity;
}

void RenderImage::opacity(Animation<double> value) {
    if (value == _opacity) {
        return;
    }
    if (attached) {
        _opacity?.removeListener(markNeedsPaint);
    }
    _opacity = value;
    if (attached) {
        value?.addListener(markNeedsPaint);
    }
}

FilterQuality RenderImage::filterQuality() {
    return _filterQuality;
}

void RenderImage::filterQuality(FilterQuality value) {
    assert(value != nullptr);
    if (value == _filterQuality) {
        return;
    }
    _filterQuality = value;
    markNeedsPaint();
}

BlendMode RenderImage::colorBlendMode() {
    return _colorBlendMode;
}

void RenderImage::colorBlendMode(BlendMode value) {
    if (value == _colorBlendMode) {
        return;
    }
    _colorBlendMode = value;
    _updateColorFilter();
    markNeedsPaint();
}

BoxFit RenderImage::fit() {
    return _fit;
}

void RenderImage::fit(BoxFit value) {
    if (value == _fit) {
        return;
    }
    _fit = value;
    markNeedsPaint();
}

AlignmentGeometry RenderImage::alignment() {
    return _alignment;
}

void RenderImage::alignment(AlignmentGeometry value) {
    assert(value != nullptr);
    if (value == _alignment) {
        return;
    }
    _alignment = value;
    _markNeedResolution();
}

ImageRepeat RenderImage::repeat() {
    return _repeat;
}

void RenderImage::repeat(ImageRepeat value) {
    assert(value != nullptr);
    if (value == _repeat) {
        return;
    }
    _repeat = value;
    markNeedsPaint();
}

Rect RenderImage::centerSlice() {
    return _centerSlice;
}

void RenderImage::centerSlice(Rect value) {
    if (value == _centerSlice) {
        return;
    }
    _centerSlice = value;
    markNeedsPaint();
}

bool RenderImage::invertColors() {
    return _invertColors;
}

void RenderImage::invertColors(bool value) {
    if (value == _invertColors) {
        return;
    }
    _invertColors = value;
    markNeedsPaint();
}

bool RenderImage::matchTextDirection() {
    return _matchTextDirection;
}

void RenderImage::matchTextDirection(bool value) {
    assert(value != nullptr);
    if (value == _matchTextDirection) {
        return;
    }
    _matchTextDirection = value;
    _markNeedResolution();
}

TextDirection RenderImage::textDirection() {
    return _textDirection;
}

void RenderImage::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    _markNeedResolution();
}

bool RenderImage::isAntiAlias() {
    return _isAntiAlias;
}

void RenderImage::isAntiAlias(bool value) {
    if (_isAntiAlias == value) {
        return;
    }
    assert(value != nullptr);
    _isAntiAlias = value;
    markNeedsPaint();
}

double RenderImage::computeMinIntrinsicWidth(double height) {
    assert(height >= 0.0);
    if (_width == nullptr && _height == nullptr) {
        return 0.0;
    }
    return _sizeForConstraints(BoxConstraints.tightForFinite(height)).width;
}

double RenderImage::computeMaxIntrinsicWidth(double height) {
    assert(height >= 0.0);
    return _sizeForConstraints(BoxConstraints.tightForFinite(height)).width;
}

double RenderImage::computeMinIntrinsicHeight(double width) {
    assert(width >= 0.0);
    if (_width == nullptr && _height == nullptr) {
        return 0.0;
    }
    return _sizeForConstraints(BoxConstraints.tightForFinite(width)).height;
}

double RenderImage::computeMaxIntrinsicHeight(double width) {
    assert(width >= 0.0);
    return _sizeForConstraints(BoxConstraints.tightForFinite(width)).height;
}

bool RenderImage::hitTestSelf(Offset position) {
    return true;
}

Size RenderImage::computeDryLayout(BoxConstraints constraints) {
    return _sizeForConstraints(constraints);
}

void RenderImage::performLayout() {
    size = _sizeForConstraints(constraints);
}

void RenderImage::attach(PipelineOwner owner) {
    super.attach(owner);
    _opacity?.addListener(markNeedsPaint);
}

void RenderImage::detach() {
    _opacity?.removeListener(markNeedsPaint);
    super.detach();
}

void RenderImage::paint(PaintingContext context, Offset offset) {
    if (_image == nullptr) {
        return;
    }
    _resolve();
    assert(_resolvedAlignment != nullptr);
    assert(_flipHorizontally != nullptr);
    paintImage(context.canvas, offset & size, _image!, debugImageLabel, _scale, _opacity?.value ?? 1.0, _colorFilter, _fit, _resolvedAlignment!, _centerSlice, _repeat, _flipHorizontally!, invertColors, _filterQuality, _isAntiAlias);
}

void RenderImage::dispose() {
    _image?.dispose();
    _image = nullptr;
    super.dispose();
}

void RenderImage::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Image>DiagnosticsProperty("image", image));
    properties.add(DoubleProperty("width", widthnullptr));
    properties.add(DoubleProperty("height", heightnullptr));
    properties.add(DoubleProperty("scale", scale1.0));
    properties.add(ColorProperty("color", colornullptr));
    properties.add(<Animation<double>>DiagnosticsProperty("opacity", opacitynullptr));
    properties.add(<BlendMode>EnumProperty("colorBlendMode", colorBlendModenullptr));
    properties.add(<BoxFit>EnumProperty("fit", fitnullptr));
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignmentnullptr));
    properties.add(<ImageRepeat>EnumProperty("repeat", repeatImageRepeat.noRepeat));
    properties.add(<Rect>DiagnosticsProperty("centerSlice", centerSlicenullptr));
    properties.add(FlagProperty("matchTextDirection"matchTextDirection, "match text direction"));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
    properties.add(<bool>DiagnosticsProperty("invertColors", invertColors));
    properties.add(<FilterQuality>EnumProperty("filterQuality", filterQuality));
}

void RenderImage::_resolve() {
    if (_resolvedAlignment != nullptr) {
        return;
    }
    _resolvedAlignment = alignment.resolve(textDirection);
    _flipHorizontally = matchTextDirection && textDirection == TextDirection.rtl;
}

void RenderImage::_markNeedResolution() {
    _resolvedAlignment = nullptr;
    _flipHorizontally = nullptr;
    markNeedsPaint();
}

void RenderImage::_updateColorFilter() {
    if (_color == nullptr) {
        _colorFilter = nullptr;
    } else {
        _colorFilter = ColorFilter.mode(_color!, _colorBlendMode ?? BlendMode.srcIn);
    }
}

Size RenderImage::_sizeForConstraints(BoxConstraints constraints) {
    constraints = BoxConstraints.tightFor(_width, _height).enforce(constraints);
    if (_image == nullptr) {
        return constraints.smallest;
    }
    return constraints.constrainSizeAndAttemptToPreserveAspectRatio(Size(_image!.width.toDouble() / _scale, _image!.height.toDouble() / _scale));
}
