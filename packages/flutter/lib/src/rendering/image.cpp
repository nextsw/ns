#include "image.hpp"
RenderImageCls::RenderImageCls(AlignmentGeometry alignment, Rect centerSlice, Color color, BlendMode colorBlendMode, String debugImageLabel, FilterQuality filterQuality, BoxFit fit, double height, Image image, bool invertColors, bool isAntiAlias, bool matchTextDirection, Animation<double> opacity, ImageRepeat repeat, double scale, TextDirection textDirection, double width) {
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

Image RenderImageCls::image() {
    return _image;
}

void RenderImageCls::image(Image value) {
    if (value == _image) {
        return;
    }
    if (value != nullptr && _image != nullptr && value->isCloneOf(_image!)) {
        value->dispose();
        return;
    }
    _image?->dispose();
    _image = value;
    markNeedsPaint();
    if (_width == nullptr || _height == nullptr) {
        markNeedsLayout();
    }
}

double RenderImageCls::width() {
    return _width;
}

void RenderImageCls::width(double value) {
    if (value == _width) {
        return;
    }
    _width = value;
    markNeedsLayout();
}

double RenderImageCls::height() {
    return _height;
}

void RenderImageCls::height(double value) {
    if (value == _height) {
        return;
    }
    _height = value;
    markNeedsLayout();
}

double RenderImageCls::scale() {
    return _scale;
}

void RenderImageCls::scale(double value) {
    assert(value != nullptr);
    if (value == _scale) {
        return;
    }
    _scale = value;
    markNeedsLayout();
}

Color RenderImageCls::color() {
    return _color;
}

void RenderImageCls::color(Color value) {
    if (value == _color) {
        return;
    }
    _color = value;
    _updateColorFilter();
    markNeedsPaint();
}

Animation<double> RenderImageCls::opacity() {
    return _opacity;
}

void RenderImageCls::opacity(Animation<double> value) {
    if (value == _opacity) {
        return;
    }
    if (attached) {
        _opacity?->removeListener(markNeedsPaint);
    }
    _opacity = value;
    if (attached) {
        value?->addListener(markNeedsPaint);
    }
}

FilterQuality RenderImageCls::filterQuality() {
    return _filterQuality;
}

void RenderImageCls::filterQuality(FilterQuality value) {
    assert(value != nullptr);
    if (value == _filterQuality) {
        return;
    }
    _filterQuality = value;
    markNeedsPaint();
}

BlendMode RenderImageCls::colorBlendMode() {
    return _colorBlendMode;
}

void RenderImageCls::colorBlendMode(BlendMode value) {
    if (value == _colorBlendMode) {
        return;
    }
    _colorBlendMode = value;
    _updateColorFilter();
    markNeedsPaint();
}

BoxFit RenderImageCls::fit() {
    return _fit;
}

void RenderImageCls::fit(BoxFit value) {
    if (value == _fit) {
        return;
    }
    _fit = value;
    markNeedsPaint();
}

AlignmentGeometry RenderImageCls::alignment() {
    return _alignment;
}

void RenderImageCls::alignment(AlignmentGeometry value) {
    assert(value != nullptr);
    if (value == _alignment) {
        return;
    }
    _alignment = value;
    _markNeedResolution();
}

ImageRepeat RenderImageCls::repeat() {
    return _repeat;
}

void RenderImageCls::repeat(ImageRepeat value) {
    assert(value != nullptr);
    if (value == _repeat) {
        return;
    }
    _repeat = value;
    markNeedsPaint();
}

Rect RenderImageCls::centerSlice() {
    return _centerSlice;
}

void RenderImageCls::centerSlice(Rect value) {
    if (value == _centerSlice) {
        return;
    }
    _centerSlice = value;
    markNeedsPaint();
}

bool RenderImageCls::invertColors() {
    return _invertColors;
}

void RenderImageCls::invertColors(bool value) {
    if (value == _invertColors) {
        return;
    }
    _invertColors = value;
    markNeedsPaint();
}

bool RenderImageCls::matchTextDirection() {
    return _matchTextDirection;
}

void RenderImageCls::matchTextDirection(bool value) {
    assert(value != nullptr);
    if (value == _matchTextDirection) {
        return;
    }
    _matchTextDirection = value;
    _markNeedResolution();
}

TextDirection RenderImageCls::textDirection() {
    return _textDirection;
}

void RenderImageCls::textDirection(TextDirection value) {
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    _markNeedResolution();
}

bool RenderImageCls::isAntiAlias() {
    return _isAntiAlias;
}

void RenderImageCls::isAntiAlias(bool value) {
    if (_isAntiAlias == value) {
        return;
    }
    assert(value != nullptr);
    _isAntiAlias = value;
    markNeedsPaint();
}

double RenderImageCls::computeMinIntrinsicWidth(double height) {
    assert(height >= 0.0);
    if (_width == nullptr && _height == nullptr) {
        return 0.0;
    }
    return _sizeForConstraints(BoxConstraintsCls->tightForFinite(height))->width();
}

double RenderImageCls::computeMaxIntrinsicWidth(double height) {
    assert(height >= 0.0);
    return _sizeForConstraints(BoxConstraintsCls->tightForFinite(height))->width();
}

double RenderImageCls::computeMinIntrinsicHeight(double width) {
    assert(width >= 0.0);
    if (_width == nullptr && _height == nullptr) {
        return 0.0;
    }
    return _sizeForConstraints(BoxConstraintsCls->tightForFinite(width))->height();
}

double RenderImageCls::computeMaxIntrinsicHeight(double width) {
    assert(width >= 0.0);
    return _sizeForConstraints(BoxConstraintsCls->tightForFinite(width))->height();
}

bool RenderImageCls::hitTestSelf(Offset position) {
    return true;
}

Size RenderImageCls::computeDryLayout(BoxConstraints constraints) {
    return _sizeForConstraints(constraints);
}

void RenderImageCls::performLayout() {
    size = _sizeForConstraints(constraints);
}

void RenderImageCls::attach(PipelineOwner owner) {
    super->attach(owner);
    _opacity?->addListener(markNeedsPaint);
}

void RenderImageCls::detach() {
    _opacity?->removeListener(markNeedsPaint);
    super->detach();
}

void RenderImageCls::paint(PaintingContext context, Offset offset) {
    if (_image == nullptr) {
        return;
    }
    _resolve();
    assert(_resolvedAlignment != nullptr);
    assert(_flipHorizontally != nullptr);
    paintImage(context->canvas(), offset & size, _image!, debugImageLabel, _scale, _opacity?->value() or 1.0, _colorFilter, _fit, _resolvedAlignment!, _centerSlice, _repeat, _flipHorizontally!, invertColors(), _filterQuality, _isAntiAlias);
}

void RenderImageCls::dispose() {
    _image?->dispose();
    _image = nullptr;
    super->dispose();
}

void RenderImageCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Image>make<DiagnosticsPropertyCls>(__s("image"), image()));
    properties->add(make<DoublePropertyCls>(__s("width"), width()nullptr));
    properties->add(make<DoublePropertyCls>(__s("height"), height()nullptr));
    properties->add(make<DoublePropertyCls>(__s("scale"), scale()1.0));
    properties->add(make<ColorPropertyCls>(__s("color"), color()nullptr));
    properties->add(<Animation<double>>make<DiagnosticsPropertyCls>(__s("opacity"), opacity()nullptr));
    properties->add(<BlendMode>make<EnumPropertyCls>(__s("colorBlendMode"), colorBlendMode()nullptr));
    properties->add(<BoxFit>make<EnumPropertyCls>(__s("fit"), fit()nullptr));
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment()nullptr));
    properties->add(<ImageRepeat>make<EnumPropertyCls>(__s("repeat"), repeat()ImageRepeatCls::noRepeat));
    properties->add(<Rect>make<DiagnosticsPropertyCls>(__s("centerSlice"), centerSlice()nullptr));
    properties->add(make<FlagPropertyCls>(__s("matchTextDirection")matchTextDirection(), __s("match text direction")));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection()nullptr));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("invertColors"), invertColors()));
    properties->add(<FilterQuality>make<EnumPropertyCls>(__s("filterQuality"), filterQuality()));
}

void RenderImageCls::_resolve() {
    if (_resolvedAlignment != nullptr) {
        return;
    }
    _resolvedAlignment = alignment()->resolve(textDirection());
    _flipHorizontally = matchTextDirection() && textDirection() == TextDirectionCls::rtl;
}

void RenderImageCls::_markNeedResolution() {
    _resolvedAlignment = nullptr;
    _flipHorizontally = nullptr;
    markNeedsPaint();
}

void RenderImageCls::_updateColorFilter() {
    if (_color == nullptr) {
        _colorFilter = nullptr;
    } else {
        _colorFilter = ColorFilterCls->mode(_color!, _colorBlendMode or BlendModeCls::srcIn);
    }
}

Size RenderImageCls::_sizeForConstraints(BoxConstraints constraints) {
    constraints = BoxConstraintsCls->tightFor(_width, _height)->enforce(constraints);
    if (_image == nullptr) {
        return constraints->smallest();
    }
    return constraints->constrainSizeAndAttemptToPreserveAspectRatio(make<SizeCls>(_image!->width->toDouble() / _scale, _image!->height->toDouble() / _scale));
}
