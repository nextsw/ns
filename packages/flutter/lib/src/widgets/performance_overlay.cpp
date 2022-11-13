#include "performance_overlay.hpp"
void PerformanceOverlayCls::allEnabled(Unknown checkerboardOffscreenLayers, Unknown checkerboardRasterCacheImages, Unknown key, Unknown rasterizerThreshold)

RenderPerformanceOverlay PerformanceOverlayCls::createRenderObject(BuildContext context) {
    return make<RenderPerformanceOverlayCls>(optionsMask, rasterizerThreshold, checkerboardRasterCacheImages, checkerboardOffscreenLayers);
}

void PerformanceOverlayCls::updateRenderObject(BuildContext context, RenderPerformanceOverlay renderObject) {
    auto _c1 = renderObject;_c1.optionsMask = auto _c2 = optionsMask;_c2.rasterizerThreshold = rasterizerThreshold;_c2;_c1;
}
