#include "texture.hpp"
Texture::Texture(FilterQuality filterQuality, bool freeze, Unknown, int textureId) {
    {
        assert(textureId != nullptr);
    }
}

TextureBox Texture::createRenderObject(BuildContext context) {
    return TextureBox(textureId, freeze, filterQuality);
}

void Texture::updateRenderObject(BuildContext context, TextureBox renderObject) {
    renderObject.textureId = textureId;
    renderObject.freeze = freeze;
    renderObject.filterQuality = filterQuality;
}
