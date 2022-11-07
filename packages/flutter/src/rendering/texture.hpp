#ifndef TEXTURE_H
#define TEXTURE_H
#include <memory>

#include "box.hpp"
#include "layer.hpp"
#include "object.hpp"



class TextureBox : RenderBox {
public:

     TextureBox(FilterQuality filterQuality, bool freeze, int textureId);

    int textureId();

    void  textureId(int value);

    bool freeze();

    void  freeze(bool value);

    FilterQuality filterQuality();

    void  filterQuality(FilterQuality value);

    bool sizedByParent();

    bool alwaysNeedsCompositing();

    bool isRepaintBoundary();

    Size computeDryLayout(BoxConstraints constraints);

    bool hitTestSelf(Offset position);

    void paint(PaintingContext context, Offset offset);

private:
    int _textureId;

    bool _freeze;

    FilterQuality _filterQuality;


};

#endif