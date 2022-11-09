#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_IMAGE_FILTER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_IMAGE_FILTER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "framework.hpp"


class ImageFilteredCls : public SingleChildRenderObjectWidgetCls {
public:
    ImageFilter imageFilter;

    bool enabled;


     ImageFilteredCls(Unknown child, bool enabled, ImageFilter imageFilter, Unknown key);

    virtual RenderObject createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderObject renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using ImageFiltered = std::shared_ptr<ImageFilteredCls>;

class _ImageFilterRenderObjectCls : public RenderProxyBoxCls {
public:

    virtual bool enabled();

    virtual void  enabled(bool value);

    virtual ImageFilter imageFilter();

    virtual void  imageFilter(ImageFilter value);

    virtual bool alwaysNeedsCompositing();

    virtual void paint(PaintingContext context, Offset offset);

private:
    bool _enabled;

    ImageFilter _imageFilter;


     _ImageFilterRenderObjectCls(bool _enabled, ImageFilter _imageFilter);
};
using _ImageFilterRenderObject = std::shared_ptr<_ImageFilterRenderObjectCls>;


#endif