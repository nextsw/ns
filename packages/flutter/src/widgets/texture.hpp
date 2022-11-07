#ifndef TEXTURE_H
#define TEXTURE_H
#include <memory>

#include <flutter/rendering.hpp>
#include "framework.hpp"



class Texture : LeafRenderObjectWidget {
public:
    int textureId;

    bool freeze;

    FilterQuality filterQuality;


     Texture(FilterQuality filterQuality, bool freeze, Unknown, int textureId);

    TextureBox createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, TextureBox renderObject);

private:

};

#endif