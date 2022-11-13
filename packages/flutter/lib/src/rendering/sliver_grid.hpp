#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_SLIVER_GRID
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_SLIVER_GRID
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "box.hpp"
#include "object.hpp"
#include "sliver.hpp"
#include "sliver_multi_box_adaptor.hpp"


class SliverGridGeometryCls : public ObjectCls {
public:
    double scrollOffset;

    double crossAxisOffset;

    double mainAxisExtent;

    double crossAxisExtent;


     SliverGridGeometryCls(double crossAxisExtent, double crossAxisOffset, double mainAxisExtent, double scrollOffset);
    virtual double trailingScrollOffset();

    virtual BoxConstraints getBoxConstraints(SliverConstraints constraints);

    virtual String toString();

private:

};
using SliverGridGeometry = std::shared_ptr<SliverGridGeometryCls>;

class SliverGridLayoutCls : public ObjectCls {
public:

     SliverGridLayoutCls();
    virtual int getMinChildIndexForScrollOffset(double scrollOffset);
    virtual int getMaxChildIndexForScrollOffset(double scrollOffset);
    virtual SliverGridGeometry getGeometryForChildIndex(int index);
    virtual double computeMaxScrollOffset(int childCount);
private:

};
using SliverGridLayout = std::shared_ptr<SliverGridLayoutCls>;

class SliverGridRegularTileLayoutCls : public SliverGridLayoutCls {
public:
    int crossAxisCount;

    double mainAxisStride;

    double crossAxisStride;

    double childMainAxisExtent;

    double childCrossAxisExtent;

    bool reverseCrossAxis;


     SliverGridRegularTileLayoutCls(double childCrossAxisExtent, double childMainAxisExtent, int crossAxisCount, double crossAxisStride, double mainAxisStride, bool reverseCrossAxis);

    virtual int getMinChildIndexForScrollOffset(double scrollOffset);

    virtual int getMaxChildIndexForScrollOffset(double scrollOffset);

    virtual SliverGridGeometry getGeometryForChildIndex(int index);

    virtual double computeMaxScrollOffset(int childCount);

private:

    virtual double _getOffsetFromStartInCrossAxis(double crossAxisStart);

};
using SliverGridRegularTileLayout = std::shared_ptr<SliverGridRegularTileLayoutCls>;

class SliverGridDelegateCls : public ObjectCls {
public:

     SliverGridDelegateCls();
    virtual SliverGridLayout getLayout(SliverConstraints constraints);
    virtual bool shouldRelayout(SliverGridDelegate oldDelegate);
private:

};
using SliverGridDelegate = std::shared_ptr<SliverGridDelegateCls>;

class SliverGridDelegateWithFixedCrossAxisCountCls : public SliverGridDelegateCls {
public:
    int crossAxisCount;

    double mainAxisSpacing;

    double crossAxisSpacing;

    double childAspectRatio;

    double mainAxisExtent;


     SliverGridDelegateWithFixedCrossAxisCountCls(double childAspectRatio, int crossAxisCount, double crossAxisSpacing, double mainAxisExtent, double mainAxisSpacing);

    virtual SliverGridLayout getLayout(SliverConstraints constraints);

    virtual bool shouldRelayout(SliverGridDelegateWithFixedCrossAxisCount oldDelegate);

private:

    virtual bool _debugAssertIsValid();

};
using SliverGridDelegateWithFixedCrossAxisCount = std::shared_ptr<SliverGridDelegateWithFixedCrossAxisCountCls>;

class SliverGridDelegateWithMaxCrossAxisExtentCls : public SliverGridDelegateCls {
public:
    double maxCrossAxisExtent;

    double mainAxisSpacing;

    double crossAxisSpacing;

    double childAspectRatio;

    double mainAxisExtent;


     SliverGridDelegateWithMaxCrossAxisExtentCls(double childAspectRatio, double crossAxisSpacing, double mainAxisExtent, double mainAxisSpacing, double maxCrossAxisExtent);

    virtual SliverGridLayout getLayout(SliverConstraints constraints);

    virtual bool shouldRelayout(SliverGridDelegateWithMaxCrossAxisExtent oldDelegate);

private:

    virtual bool _debugAssertIsValid(double crossAxisExtent);

};
using SliverGridDelegateWithMaxCrossAxisExtent = std::shared_ptr<SliverGridDelegateWithMaxCrossAxisExtentCls>;

class SliverGridParentDataCls : public SliverMultiBoxAdaptorParentDataCls {
public:
    double crossAxisOffset;


    virtual String toString();

private:

};
using SliverGridParentData = std::shared_ptr<SliverGridParentDataCls>;

class RenderSliverGridCls : public RenderSliverMultiBoxAdaptorCls {
public:

     RenderSliverGridCls(RenderSliverBoxChildManager childManager, SliverGridDelegate gridDelegate);

    virtual void setupParentData(RenderObject child);

    virtual SliverGridDelegate gridDelegate();

    virtual void  gridDelegate(SliverGridDelegate value);

    virtual double childCrossAxisPosition(RenderBox child);

    virtual void performLayout();

private:
    SliverGridDelegate _gridDelegate;


};
using RenderSliverGrid = std::shared_ptr<RenderSliverGridCls>;


#endif