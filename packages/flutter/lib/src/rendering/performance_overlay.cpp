#include "performance_overlay.hpp"
RenderPerformanceOverlayCls::RenderPerformanceOverlayCls(bool checkerboardOffscreenLayers, bool checkerboardRasterCacheImages, int optionsMask, int rasterizerThreshold) {
    {
        assert(optionsMask != nullptr);
        assert(rasterizerThreshold != nullptr);
        assert(checkerboardRasterCacheImages != nullptr);
        assert(checkerboardOffscreenLayers != nullptr);
        _optionsMask = optionsMask;
        _rasterizerThreshold = rasterizerThreshold;
        _checkerboardRasterCacheImages = checkerboardRasterCacheImages;
        _checkerboardOffscreenLayers = checkerboardOffscreenLayers;
    }
}

int RenderPerformanceOverlayCls::optionsMask() {
    return _optionsMask;
}

void RenderPerformanceOverlayCls::optionsMask(int value) {
    assert(value != nullptr);
    if (value == _optionsMask) {
        return;
    }
    _optionsMask = value;
    markNeedsPaint();
}

int RenderPerformanceOverlayCls::rasterizerThreshold() {
    return _rasterizerThreshold;
}

void RenderPerformanceOverlayCls::rasterizerThreshold(int value) {
    assert(value != nullptr);
    if (value == _rasterizerThreshold) {
        return;
    }
    _rasterizerThreshold = value;
    markNeedsPaint();
}

bool RenderPerformanceOverlayCls::checkerboardRasterCacheImages() {
    return _checkerboardRasterCacheImages;
}

void RenderPerformanceOverlayCls::checkerboardRasterCacheImages(bool value) {
    assert(value != nullptr);
    if (value == _checkerboardRasterCacheImages) {
        return;
    }
    _checkerboardRasterCacheImages = value;
    markNeedsPaint();
}

bool RenderPerformanceOverlayCls::checkerboardOffscreenLayers() {
    return _checkerboardOffscreenLayers;
}

void RenderPerformanceOverlayCls::checkerboardOffscreenLayers(bool value) {
    assert(value != nullptr);
    if (value == _checkerboardOffscreenLayers) {
        return;
    }
    _checkerboardOffscreenLayers = value;
    markNeedsPaint();
}

bool RenderPerformanceOverlayCls::sizedByParent() {
    return true;
}

bool RenderPerformanceOverlayCls::alwaysNeedsCompositing() {
    return true;
}

double RenderPerformanceOverlayCls::computeMinIntrinsicWidth(double height) {
    return 0.0;
}

double RenderPerformanceOverlayCls::computeMaxIntrinsicWidth(double height) {
    return 0.0;
}

double RenderPerformanceOverlayCls::computeMinIntrinsicHeight(double width) {
    return _intrinsicHeight;
}

double RenderPerformanceOverlayCls::computeMaxIntrinsicHeight(double width) {
    return _intrinsicHeight;
}

Size RenderPerformanceOverlayCls::computeDryLayout(BoxConstraints constraints) {
    return constraints->constrain(make<SizeCls>(double->infinity, _intrinsicHeight));
}

void RenderPerformanceOverlayCls::paint(PaintingContext context, Offset offset) {
    assert(needsCompositing);
    context->addLayer(make<PerformanceOverlayLayerCls>(RectCls->fromLTWH(offset->dx, offset->dy, size->width, size->height), optionsMask, rasterizerThreshold, checkerboardRasterCacheImages, checkerboardOffscreenLayers));
}

double RenderPerformanceOverlayCls::_intrinsicHeight() {
    double kDefaultGraphHeight = 80.0;
    double result = 0.0;
    if ((optionsMask | (1 << PerformanceOverlayOptionCls::displayRasterizerStatistics->index) > 0) || (optionsMask | (1 << PerformanceOverlayOptionCls::visualizeRasterizerStatistics->index) > 0)) {
        result = kDefaultGraphHeight;
    }
    if ((optionsMask | (1 << PerformanceOverlayOptionCls::displayEngineStatistics->index) > 0) || (optionsMask | (1 << PerformanceOverlayOptionCls::visualizeEngineStatistics->index) > 0)) {
        result = kDefaultGraphHeight;
    }
    return result;
}
