#include "performance_overlay.hpp"
void PerformanceOverlay::allEnabled(bool checkerboardOffscreenLayers, bool checkerboardRasterCacheImages, Unknown, int rasterizerThreshold)

RenderPerformanceOverlay PerformanceOverlay::createRenderObject(BuildContext context) {
    return RenderPerformanceOverlay(optionsMask, rasterizerThreshold, checkerboardRasterCacheImages, checkerboardOffscreenLayers);
}

void PerformanceOverlay::updateRenderObject(BuildContext context, RenderPerformanceOverlay renderObject) {
    ;
}
