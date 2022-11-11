#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ANNOTATED_REGION
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ANNOTATED_REGION
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "framework.hpp"


template<typename T>
class AnnotatedRegionCls : public SingleChildRenderObjectWidgetCls {
public:
    T value;

    bool sized;


     AnnotatedRegionCls(Widget child, Unknown key, bool sized, T value);

    virtual RenderObject createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderAnnotatedRegion<T> renderObject);

private:

};
template<typename T>
using AnnotatedRegion = std::shared_ptr<AnnotatedRegionCls<T>>;


#endif