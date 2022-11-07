#ifndef PERFORMANCE_OVERLAY_H
#define PERFORMANCE_OVERLAY_H
#include <memory>

#include <flutter/rendering.hpp>
#include "framework.hpp"



class PerformanceOverlay : LeafRenderObjectWidget {
public:
    int optionsMask;

    int rasterizerThreshold;

    bool checkerboardRasterCacheImages;

    bool checkerboardOffscreenLayers;


     PerformanceOverlay(bool checkerboardOffscreenLayers, bool checkerboardRasterCacheImages, Unknown, int optionsMask, int rasterizerThreshold);

    void  allEnabled(bool checkerboardOffscreenLayers, bool checkerboardRasterCacheImages, Unknown, int rasterizerThreshold);

    RenderPerformanceOverlay createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderPerformanceOverlay renderObject);

private:

};

#endif