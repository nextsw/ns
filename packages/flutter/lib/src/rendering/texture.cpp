#include "texture.hpp"
TextureBoxCls::TextureBoxCls(FilterQuality filterQuality, bool freeze, int textureId) {
    {
        assert(textureId != nullptr);
        _textureId = textureId;
        _freeze = freeze;
        _filterQuality = filterQuality;
    }
}

int TextureBoxCls::textureId() {
    return _textureId;
}

void TextureBoxCls::textureId(int value) {
    assert(value != nullptr);
    if (value != _textureId) {
        _textureId = value;
        markNeedsPaint();
    }
}

bool TextureBoxCls::freeze() {
    return _freeze;
}

void TextureBoxCls::freeze(bool value) {
    assert(value != nullptr);
    if (value != _freeze) {
        _freeze = value;
        markNeedsPaint();
    }
}

FilterQuality TextureBoxCls::filterQuality() {
    return _filterQuality;
}

void TextureBoxCls::filterQuality(FilterQuality value) {
    assert(value != nullptr);
    if (value != _filterQuality) {
        _filterQuality = value;
        markNeedsPaint();
    }
}

bool TextureBoxCls::sizedByParent() {
    return true;
}

bool TextureBoxCls::alwaysNeedsCompositing() {
    return true;
}

bool TextureBoxCls::isRepaintBoundary() {
    return true;
}

Size TextureBoxCls::computeDryLayout(BoxConstraints constraints) {
    return constraints->biggest;
}

bool TextureBoxCls::hitTestSelf(Offset position) {
    return true;
}

void TextureBoxCls::paint(PaintingContext context, Offset offset) {
    context->addLayer(make<TextureLayerCls>(RectCls->fromLTWH(offset->dx, offset->dy, size->width, size->height), _textureId, freeze, _filterQuality));
}
