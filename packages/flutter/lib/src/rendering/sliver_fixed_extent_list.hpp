#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_SLIVER_FIXED_EXTENT_LIST
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_SLIVER_FIXED_EXTENT_LIST
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "box.hpp"
#include "sliver.hpp"
#include "sliver_multi_box_adaptor.hpp"


class RenderSliverFixedExtentBoxAdaptorCls : public RenderSliverMultiBoxAdaptorCls {
public:

     RenderSliverFixedExtentBoxAdaptorCls(Unknown childManager);
    virtual double itemExtent();
    virtual double indexToLayoutOffset(double itemExtent, int index);

    virtual int getMinChildIndexForScrollOffset(double scrollOffset, double itemExtent);

    virtual int getMaxChildIndexForScrollOffset(double scrollOffset, double itemExtent);

    virtual double estimateMaxScrollOffset(SliverConstraints constraints, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset);

    virtual double computeMaxScrollOffset(SliverConstraints constraints, double itemExtent);

    virtual void performLayout();

private:

    virtual int _calculateLeadingGarbage(int firstIndex);

    virtual int _calculateTrailingGarbage(int targetLastIndex);

};
using RenderSliverFixedExtentBoxAdaptor = std::shared_ptr<RenderSliverFixedExtentBoxAdaptorCls>;

class RenderSliverFixedExtentListCls : public RenderSliverFixedExtentBoxAdaptorCls {
public:

     RenderSliverFixedExtentListCls(Unknown childManager, double itemExtent);

    virtual double itemExtent();

    virtual void  itemExtent(double value);

private:
    double _itemExtent;


};
using RenderSliverFixedExtentList = std::shared_ptr<RenderSliverFixedExtentListCls>;


#endif