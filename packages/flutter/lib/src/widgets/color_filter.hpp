#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_COLOR_FILTER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_COLOR_FILTER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "framework.hpp"


class ColorFilteredCls : public SingleChildRenderObjectWidgetCls {
public:
    ColorFilter colorFilter;


     ColorFilteredCls(Widget child, ColorFilter colorFilter, Key key);

    virtual RenderObject createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderObject renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using ColorFiltered = std::shared_ptr<ColorFilteredCls>;

class _ColorFilterRenderObjectCls : public RenderProxyBoxCls {
public:

    virtual ColorFilter colorFilter();

    virtual void  colorFilter(ColorFilter value);

    virtual bool alwaysNeedsCompositing();

    virtual void paint(PaintingContext context, Offset offset);

private:
    ColorFilter _colorFilter;


     _ColorFilterRenderObjectCls(ColorFilter _colorFilter);
};
using _ColorFilterRenderObject = std::shared_ptr<_ColorFilterRenderObjectCls>;


#endif