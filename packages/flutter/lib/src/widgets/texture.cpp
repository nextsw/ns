#include "texture.hpp"
TextureCls::TextureCls(FilterQuality filterQuality, bool freeze, Key key, int textureId) {
    {
        assert(textureId != nullptr);
    }
}

TextureBox TextureCls::createRenderObject(BuildContext context) {
    return make<TextureBoxCls>(textureId, freeze, filterQuality);
}

void TextureCls::updateRenderObject(BuildContext context, TextureBox renderObject) {
    renderObject->textureId = textureId;
    renderObject->freeze = freeze;
    renderObject->filterQuality = filterQuality;
}
