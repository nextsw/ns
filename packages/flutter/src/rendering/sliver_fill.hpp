#ifndef SLIVER_FILL_H
#define SLIVER_FILL_H
#include <memory>

#include <math/math.hpp>
#include "box.hpp"
#include "object.hpp"
#include "sliver.hpp"
#include "sliver_fixed_extent_list.hpp"



class RenderSliverFillViewport : RenderSliverFixedExtentBoxAdaptor {
public:

     RenderSliverFillViewport(Unknown, double viewportFraction);

    double itemExtent();

    double viewportFraction();

    void  viewportFraction(double value);

private:
    double _viewportFraction;


};

class RenderSliverFillRemainingWithScrollable : RenderSliverSingleBoxAdapter {
public:

     RenderSliverFillRemainingWithScrollable(Unknown);

    void performLayout();

private:

};

class RenderSliverFillRemaining : RenderSliverSingleBoxAdapter {
public:

     RenderSliverFillRemaining(Unknown);

    void performLayout();

private:

};

class RenderSliverFillRemainingAndOverscroll : RenderSliverSingleBoxAdapter {
public:

     RenderSliverFillRemainingAndOverscroll(Unknown);

    void performLayout();

private:

};

#endif