#include "performance_overlay.hpp"
RenderPerformanceOverlay::RenderPerformanceOverlay(bool checkerboardOffscreenLayers, bool checkerboardRasterCacheImages, int optionsMask, int rasterizerThreshold) {
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

int RenderPerformanceOverlay::optionsMask() {
    return _optionsMask;
}

void RenderPerformanceOverlay::optionsMask(int value) {
    assert(value != nullptr);
    if (value == _optionsMask) {
        return;
    }
    _optionsMask = value;
    markNeedsPaint();
}

int RenderPerformanceOverlay::rasterizerThreshold() {
    return _rasterizerThreshold;
}

void RenderPerformanceOverlay::rasterizerThreshold(int value) {
    assert(value != nullptr);
    if (value == _rasterizerThreshold) {
        return;
    }
    _rasterizerThreshold = value;
    markNeedsPaint();
}

bool RenderPerformanceOverlay::checkerboardRasterCacheImages() {
    return _checkerboardRasterCacheImages;
}

void RenderPerformanceOverlay::checkerboardRasterCacheImages(bool value) {
    assert(value != nullptr);
    if (value == _checkerboardRasterCacheImages) {
        return;
    }
    _checkerboardRasterCacheImages = value;
    markNeedsPaint();
}

bool RenderPerformanceOverlay::checkerboardOffscreenLayers() {
    return _checkerboardOffscreenLayers;
}

void RenderPerformanceOverlay::checkerboardOffscreenLayers(bool value) {
    assert(value != nullptr);
    if (value == _checkerboardOffscreenLayers) {
        return;
    }
    _checkerboardOffscreenLayers = value;
    markNeedsPaint();
}

bool RenderPerformanceOverlay::sizedByParent() {
    return true;
}

bool RenderPerformanceOverlay::alwaysNeedsCompositing() {
    return true;
}

double RenderPerformanceOverlay::computeMinIntrinsicWidth(double height) {
    return 0.0;
}

double RenderPerformanceOverlay::computeMaxIntrinsicWidth(double height) {
    return 0.0;
}

double RenderPerformanceOverlay::computeMinIntrinsicHeight(double width) {
    return _intrinsicHeight;
}

double RenderPerformanceOverlay::computeMaxIntrinsicHeight(double width) {
    return _intrinsicHeight;
}

Size RenderPerformanceOverlay::computeDryLayout(BoxConstraints constraints) {
    return constraints.constrain(Size(double.infinity, _intrinsicHeight));
}

void RenderPerformanceOverlay::paint(PaintingContext context, Offset offset) {
    assert(needsCompositing);
    context.addLayer(PerformanceOverlayLayer(Rect.fromLTWH(offset.dx, offset.dy, size.width, size.height), optionsMask, rasterizerThreshold, checkerboardRasterCacheImages, checkerboardOffscreenLayers));
}

double RenderPerformanceOverlay::_intrinsicHeight() {
    double kDefaultGraphHeight = 80.0;
    double result = 0.0;
    if ((optionsMask | (1 << PerformanceOverlayOption.displayRasterizerStatistics.index) > 0) || (optionsMask | (1 << PerformanceOverlayOption.visualizeRasterizerStatistics.index) > 0)) {
        result = kDefaultGraphHeight;
    }
    if ((optionsMask | (1 << PerformanceOverlayOption.displayEngineStatistics.index) > 0) || (optionsMask | (1 << PerformanceOverlayOption.visualizeEngineStatistics.index) > 0)) {
        result = kDefaultGraphHeight;
    }
    return result;
}
