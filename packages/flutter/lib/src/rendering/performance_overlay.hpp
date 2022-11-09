#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_PERFORMANCE_OVERLAY
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_PERFORMANCE_OVERLAY
#include <base.hpp>

#include <dart/core/core.hpp>
#include "box.hpp"
#include "layer.hpp"
#include "object.hpp"


enum PerformanceOverlayOption{
    displayRasterizerStatistics,
    visualizeRasterizerStatistics,
    displayEngineStatistics,
    visualizeEngineStatistics,
} // end PerformanceOverlayOption

class RenderPerformanceOverlayCls : public RenderBoxCls {
public:

     RenderPerformanceOverlayCls(bool checkerboardOffscreenLayers, bool checkerboardRasterCacheImages, int optionsMask, int rasterizerThreshold);

    virtual int optionsMask();

    virtual void  optionsMask(int value);

    virtual int rasterizerThreshold();

    virtual void  rasterizerThreshold(int value);

    virtual bool checkerboardRasterCacheImages();

    virtual void  checkerboardRasterCacheImages(bool value);

    virtual bool checkerboardOffscreenLayers();

    virtual void  checkerboardOffscreenLayers(bool value);

    virtual bool sizedByParent();

    virtual bool alwaysNeedsCompositing();

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void paint(PaintingContext context, Offset offset);

private:
    int _optionsMask;

    int _rasterizerThreshold;

    bool _checkerboardRasterCacheImages;

    bool _checkerboardOffscreenLayers;


    virtual double _intrinsicHeight();

};
using RenderPerformanceOverlay = std::shared_ptr<RenderPerformanceOverlayCls>;


#endif