#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_PERFORMANCE_OVERLAY
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_PERFORMANCE_OVERLAY
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "framework.hpp"


class PerformanceOverlayCls : public LeafRenderObjectWidgetCls {
public:
    int optionsMask;

    int rasterizerThreshold;

    bool checkerboardRasterCacheImages;

    bool checkerboardOffscreenLayers;


     PerformanceOverlayCls(bool checkerboardOffscreenLayers, bool checkerboardRasterCacheImages, Key key, int optionsMask, int rasterizerThreshold);
    virtual void  allEnabled(Unknown checkerboardOffscreenLayers, Unknown checkerboardRasterCacheImages, Unknown key, Unknown rasterizerThreshold);

    virtual RenderPerformanceOverlay createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderPerformanceOverlay renderObject);

private:

};
using PerformanceOverlay = std::shared_ptr<PerformanceOverlayCls>;


#endif