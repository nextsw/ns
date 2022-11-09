#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_TEXTURE
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_TEXTURE
#include <base.hpp>

#include <dart/core/core.hpp>
#include "box.hpp"
#include "layer.hpp"
#include "object.hpp"


class TextureBoxCls : public RenderBoxCls {
public:

     TextureBoxCls(FilterQuality filterQuality, bool freeze, int textureId);

    virtual int textureId();

    virtual void  textureId(int value);

    virtual bool freeze();

    virtual void  freeze(bool value);

    virtual FilterQuality filterQuality();

    virtual void  filterQuality(FilterQuality value);

    virtual bool sizedByParent();

    virtual bool alwaysNeedsCompositing();

    virtual bool isRepaintBoundary();

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual bool hitTestSelf(Offset position);

    virtual void paint(PaintingContext context, Offset offset);

private:
    int _textureId;

    bool _freeze;

    FilterQuality _filterQuality;


};
using TextureBox = std::shared_ptr<TextureBoxCls>;


#endif