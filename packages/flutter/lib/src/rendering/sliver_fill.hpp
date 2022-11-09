#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_SLIVER_FILL
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_SLIVER_FILL
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include "box.hpp"
#include "object.hpp"
#include "sliver.hpp"
#include "sliver_fixed_extent_list.hpp"


class RenderSliverFillViewportCls : public RenderSliverFixedExtentBoxAdaptorCls {
public:

     RenderSliverFillViewportCls(Unknown childManager, double viewportFraction);

    virtual double itemExtent();

    virtual double viewportFraction();

    virtual void  viewportFraction(double value);

private:
    double _viewportFraction;


};
using RenderSliverFillViewport = std::shared_ptr<RenderSliverFillViewportCls>;

class RenderSliverFillRemainingWithScrollableCls : public RenderSliverSingleBoxAdapterCls {
public:

     RenderSliverFillRemainingWithScrollableCls(Unknown child);
    virtual void performLayout();

private:

};
using RenderSliverFillRemainingWithScrollable = std::shared_ptr<RenderSliverFillRemainingWithScrollableCls>;

class RenderSliverFillRemainingCls : public RenderSliverSingleBoxAdapterCls {
public:

     RenderSliverFillRemainingCls(Unknown child);
    virtual void performLayout();

private:

};
using RenderSliverFillRemaining = std::shared_ptr<RenderSliverFillRemainingCls>;

class RenderSliverFillRemainingAndOverscrollCls : public RenderSliverSingleBoxAdapterCls {
public:

     RenderSliverFillRemainingAndOverscrollCls(Unknown child);
    virtual void performLayout();

private:

};
using RenderSliverFillRemainingAndOverscroll = std::shared_ptr<RenderSliverFillRemainingAndOverscrollCls>;


#endif