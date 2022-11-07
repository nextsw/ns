#ifndef SLIVER_GRID_H
#define SLIVER_GRID_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include "box.hpp"
#include "object.hpp"
#include "sliver.hpp"
#include "sliver_multi_box_adaptor.hpp"



class SliverGridGeometry {
public:
    double scrollOffset;

    double crossAxisOffset;

    double mainAxisExtent;

    double crossAxisExtent;


     SliverGridGeometry(double crossAxisExtent, double crossAxisOffset, double mainAxisExtent, double scrollOffset);

    double trailingScrollOffset();

    BoxConstraints getBoxConstraints(SliverConstraints constraints);

    String toString();

private:

};

class SliverGridLayout {
public:

     SliverGridLayout();

    int getMinChildIndexForScrollOffset(double scrollOffset);

    int getMaxChildIndexForScrollOffset(double scrollOffset);

    SliverGridGeometry getGeometryForChildIndex(int index);

    double computeMaxScrollOffset(int childCount);

private:

};

class SliverGridRegularTileLayout : SliverGridLayout {
public:
    int crossAxisCount;

    double mainAxisStride;

    double crossAxisStride;

    double childMainAxisExtent;

    double childCrossAxisExtent;

    bool reverseCrossAxis;


     SliverGridRegularTileLayout(double childCrossAxisExtent, double childMainAxisExtent, int crossAxisCount, double crossAxisStride, double mainAxisStride, bool reverseCrossAxis);

    int getMinChildIndexForScrollOffset(double scrollOffset);

    int getMaxChildIndexForScrollOffset(double scrollOffset);

    SliverGridGeometry getGeometryForChildIndex(int index);

    double computeMaxScrollOffset(int childCount);

private:

    double _getOffsetFromStartInCrossAxis(double crossAxisStart);

};

class SliverGridDelegate {
public:

     SliverGridDelegate();

    SliverGridLayout getLayout(SliverConstraints constraints);

    bool shouldRelayout(SliverGridDelegate oldDelegate);

private:

};

class SliverGridDelegateWithFixedCrossAxisCount : SliverGridDelegate {
public:
    int crossAxisCount;

    double mainAxisSpacing;

    double crossAxisSpacing;

    double childAspectRatio;

    double mainAxisExtent;


     SliverGridDelegateWithFixedCrossAxisCount(double childAspectRatio, int crossAxisCount, double crossAxisSpacing, double mainAxisExtent, double mainAxisSpacing);

    SliverGridLayout getLayout(SliverConstraints constraints);

    bool shouldRelayout(SliverGridDelegateWithFixedCrossAxisCount oldDelegate);

private:

    bool _debugAssertIsValid();

};

class SliverGridDelegateWithMaxCrossAxisExtent : SliverGridDelegate {
public:
    double maxCrossAxisExtent;

    double mainAxisSpacing;

    double crossAxisSpacing;

    double childAspectRatio;

    double mainAxisExtent;


     SliverGridDelegateWithMaxCrossAxisExtent(double childAspectRatio, double crossAxisSpacing, double mainAxisExtent, double mainAxisSpacing, double maxCrossAxisExtent);

    SliverGridLayout getLayout(SliverConstraints constraints);

    bool shouldRelayout(SliverGridDelegateWithMaxCrossAxisExtent oldDelegate);

private:

    bool _debugAssertIsValid(double crossAxisExtent);

};

class SliverGridParentData : SliverMultiBoxAdaptorParentData {
public:
    double crossAxisOffset;


    String toString();

private:

};

class RenderSliverGrid : RenderSliverMultiBoxAdaptor {
public:

     RenderSliverGrid(Unknown, SliverGridDelegate gridDelegate);

    void setupParentData(RenderObject child);

    SliverGridDelegate gridDelegate();

    void  gridDelegate(SliverGridDelegate value);

    double childCrossAxisPosition(RenderBox child);

    void performLayout();

private:
    SliverGridDelegate _gridDelegate;


};

#endif