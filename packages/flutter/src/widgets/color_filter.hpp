#ifndef COLOR_FILTER_H
#define COLOR_FILTER_H
#include <memory>

#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include "framework.hpp"



class ColorFiltered : SingleChildRenderObjectWidget {
public:
    ColorFilter colorFilter;


     ColorFiltered(Unknown, ColorFilter colorFilter, Unknown);

    RenderObject createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderObject renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _ColorFilterRenderObject : RenderProxyBox {
public:

    ColorFilter colorFilter();

    void  colorFilter(ColorFilter value);

    bool alwaysNeedsCompositing();

    void paint(PaintingContext context, Offset offset);

private:
    ColorFilter _colorFilter;


     _ColorFilterRenderObject(ColorFilter _colorFilter);

};

#endif