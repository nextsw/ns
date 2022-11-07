#ifndef SLIVER_FIXED_EXTENT_LIST_H
#define SLIVER_FIXED_EXTENT_LIST_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include "box.hpp"
#include "sliver.hpp"
#include "sliver_multi_box_adaptor.hpp"



class RenderSliverFixedExtentBoxAdaptor : RenderSliverMultiBoxAdaptor {
public:

     RenderSliverFixedExtentBoxAdaptor(Unknown);

    double itemExtent();

    double indexToLayoutOffset(int index, double itemExtent);

    int getMinChildIndexForScrollOffset(double itemExtent, double scrollOffset);

    int getMaxChildIndexForScrollOffset(double itemExtent, double scrollOffset);

    double estimateMaxScrollOffset(SliverConstraints constraints, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset);

    double computeMaxScrollOffset(SliverConstraints constraints, double itemExtent);

    void performLayout();

private:

    int _calculateLeadingGarbage(int firstIndex);

    int _calculateTrailingGarbage(int targetLastIndex);

};

class RenderSliverFixedExtentList : RenderSliverFixedExtentBoxAdaptor {
public:

     RenderSliverFixedExtentList(Unknown, double itemExtent);

    double itemExtent();

    void  itemExtent(double value);

private:
    double _itemExtent;


};

#endif