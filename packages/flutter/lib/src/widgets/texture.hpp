#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_TEXTURE
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_TEXTURE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "framework.hpp"


class TextureCls : public LeafRenderObjectWidgetCls {
public:
    int textureId;

    bool freeze;

    FilterQuality filterQuality;


     TextureCls(FilterQuality filterQuality, bool freeze, Unknown key, int textureId);

    virtual TextureBox createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, TextureBox renderObject);

private:

};
using Texture = std::shared_ptr<TextureCls>;


#endif