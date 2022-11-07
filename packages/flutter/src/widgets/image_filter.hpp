#ifndef IMAGE_FILTER_H
#define IMAGE_FILTER_H
#include <memory>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include "framework.hpp"



class ImageFiltered : SingleChildRenderObjectWidget {
public:
    ImageFilter imageFilter;

    bool enabled;


     ImageFiltered(Unknown, bool enabled, ImageFilter imageFilter, Unknown);

    RenderObject createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderObject renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _ImageFilterRenderObject : RenderProxyBox {
public:

    bool enabled();

    void  enabled(bool value);

    ImageFilter imageFilter();

    void  imageFilter(ImageFilter value);

    bool alwaysNeedsCompositing();

    void paint(PaintingContext context, Offset offset);

private:
    bool _enabled;

    ImageFilter _imageFilter;


     _ImageFilterRenderObject(bool _enabled, ImageFilter _imageFilter);

};

#endif