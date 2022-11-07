#include "texture.hpp"
TextureBox::TextureBox(FilterQuality filterQuality, bool freeze, int textureId) {
    {
        assert(textureId != nullptr);
        _textureId = textureId;
        _freeze = freeze;
        _filterQuality = filterQuality;
    }
}

int TextureBox::textureId() {
    return _textureId;
}

void TextureBox::textureId(int value) {
    assert(value != nullptr);
    if (value != _textureId) {
        _textureId = value;
        markNeedsPaint();
    }
}

bool TextureBox::freeze() {
    return _freeze;
}

void TextureBox::freeze(bool value) {
    assert(value != nullptr);
    if (value != _freeze) {
        _freeze = value;
        markNeedsPaint();
    }
}

FilterQuality TextureBox::filterQuality() {
    return _filterQuality;
}

void TextureBox::filterQuality(FilterQuality value) {
    assert(value != nullptr);
    if (value != _filterQuality) {
        _filterQuality = value;
        markNeedsPaint();
    }
}

bool TextureBox::sizedByParent() {
    return true;
}

bool TextureBox::alwaysNeedsCompositing() {
    return true;
}

bool TextureBox::isRepaintBoundary() {
    return true;
}

Size TextureBox::computeDryLayout(BoxConstraints constraints) {
    return constraints.biggest;
}

bool TextureBox::hitTestSelf(Offset position) {
    return true;
}

void TextureBox::paint(PaintingContext context, Offset offset) {
    context.addLayer(TextureLayer(Rect.fromLTWH(offset.dx, offset.dy, size.width, size.height), _textureId, freeze, _filterQuality));
}
