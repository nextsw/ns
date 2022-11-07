#ifndef PERFORMANCE_OVERLAY_H
#define PERFORMANCE_OVERLAY_H
#include <memory>

#include "box.hpp"
#include "layer.hpp"
#include "object.hpp"



enum PerformanceOverlayOption{
    displayRasterizerStatistics,
    visualizeRasterizerStatistics,
    displayEngineStatistics,
    visualizeEngineStatistics,
} // end PerformanceOverlayOption

class RenderPerformanceOverlay : RenderBox {
public:

     RenderPerformanceOverlay(bool checkerboardOffscreenLayers, bool checkerboardRasterCacheImages, int optionsMask, int rasterizerThreshold);

    int optionsMask();

    void  optionsMask(int value);

    int rasterizerThreshold();

    void  rasterizerThreshold(int value);

    bool checkerboardRasterCacheImages();

    void  checkerboardRasterCacheImages(bool value);

    bool checkerboardOffscreenLayers();

    void  checkerboardOffscreenLayers(bool value);

    bool sizedByParent();

    bool alwaysNeedsCompositing();

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    Size computeDryLayout(BoxConstraints constraints);

    void paint(PaintingContext context, Offset offset);

private:
    int _optionsMask;

    int _rasterizerThreshold;

    bool _checkerboardRasterCacheImages;

    bool _checkerboardOffscreenLayers;


    double _intrinsicHeight();

};

#endif