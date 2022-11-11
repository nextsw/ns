#include "sliver_list.hpp"
void RenderSliverListCls::performLayout() {
    SliverConstraints constraints = this->constraints;
    childManager->didStartLayout();
    childManager->setDidUnderflow(false);
    double scrollOffset = constraints->scrollOffset + constraints->cacheOrigin;
    assert(scrollOffset >= 0.0);
    double remainingExtent = constraints->remainingCacheExtent;
    assert(remainingExtent >= 0.0);
    double targetEndScrollOffset = scrollOffset + remainingExtent;
    BoxConstraints childConstraints = constraints->asBoxConstraints();
    int leadingGarbage = 0;
    int trailingGarbage = 0;
    bool reachedEnd = false;
    if (firstChild == nullptr) {
        if (!addInitialChild()) {
            geometry = SliverGeometryCls::zero;
            childManager->didFinishLayout();
            return;
        }
    }
    RenderBox leadingChildWithLayout, trailingChildWithLayout;
    RenderBox earliestUsefulChild = firstChild;
    if (childScrollOffset(firstChild!) == nullptr) {
        int leadingChildrenWithoutLayoutOffset = 0;
        while (earliestUsefulChild != nullptr && childScrollOffset(earliestUsefulChild) == nullptr) {
            earliestUsefulChild = childAfter(earliestUsefulChild);
            leadingChildrenWithoutLayoutOffset += 1;
        }
        collectGarbage(leadingChildrenWithoutLayoutOffset, 0);
        if (firstChild == nullptr) {
            if (!addInitialChild()) {
                geometry = SliverGeometryCls::zero;
                childManager->didFinishLayout();
                return;
            }
        }
    }
    earliestUsefulChild = firstChild;
    for (; earliestScrollOffset > scrollOffset; earliestScrollOffset = childScrollOffset(earliestUsefulChild)!) {
        earliestUsefulChild = insertAndLayoutLeadingChild(childConstraints, true);
        if (earliestUsefulChild == nullptr) {
            SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(firstChild!->parentData!);
            childParentData->layoutOffset = 0.0;
            if (scrollOffset == 0.0) {
                firstChild!->layout(childConstraints, true);
                earliestUsefulChild = firstChild;
                leadingChildWithLayout = earliestUsefulChild;
                trailingChildWithLayout |= earliestUsefulChild;
                break;
            } else {
                geometry = make<SliverGeometryCls>(-scrollOffset);
                return;
            }
        }
        double firstChildScrollOffset = earliestScrollOffset - paintExtentOf(firstChild!);
        if ( < -precisionErrorTolerance) {
            geometry = make<SliverGeometryCls>(-firstChildScrollOffset);
            SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(firstChild!->parentData!);
            childParentData->layoutOffset = 0.0;
            return;
        }
        SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(earliestUsefulChild->parentData!);
        childParentData->layoutOffset = firstChildScrollOffset;
        assert(earliestUsefulChild == firstChild);
        leadingChildWithLayout = earliestUsefulChild;
        trailingChildWithLayout |= earliestUsefulChild;
    }
    assert(childScrollOffset(firstChild!)! > -precisionErrorTolerance);
    if ( < precisionErrorTolerance) {
        while (indexOf(firstChild!) > 0) {
            double earliestScrollOffset = childScrollOffset(firstChild!)!;
            earliestUsefulChild = insertAndLayoutLeadingChild(childConstraints, true);
            assert(earliestUsefulChild != nullptr);
            double firstChildScrollOffset = earliestScrollOffset - paintExtentOf(firstChild!);
            SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(firstChild!->parentData!);
            childParentData->layoutOffset = 0.0;
            if ( < -precisionErrorTolerance) {
                geometry = make<SliverGeometryCls>(-firstChildScrollOffset);
                return;
            }
        }
    }
    assert(earliestUsefulChild == firstChild);
    assert(childScrollOffset(earliestUsefulChild!)! <= scrollOffset);
    if (leadingChildWithLayout == nullptr) {
        earliestUsefulChild!->layout(childConstraints, true);
        leadingChildWithLayout = earliestUsefulChild;
        trailingChildWithLayout = earliestUsefulChild;
    }
    bool inLayoutRange = true;
    RenderBox child = earliestUsefulChild;
    int index = indexOf(child!);
    double endScrollOffset = childScrollOffset(child)! + paintExtentOf(child);
    InlineMethod;
    while ( < scrollOffset) {
        leadingGarbage += 1;
        if (!advance()) {
            assert(leadingGarbage == childCount);
            assert(child == nullptr);
            collectGarbage(leadingGarbage - 1, 0);
            assert(firstChild == lastChild);
            double extent = childScrollOffset(lastChild!)! + paintExtentOf(lastChild!);
            geometry = make<SliverGeometryCls>(extent, extent);
            return;
        }
    }
    while ( < targetEndScrollOffset) {
        if (!advance()) {
            reachedEnd = true;
            break;
        }
    }
    if (child != nullptr) {
        child = childAfter(child!);
        while (child != nullptr) {
            trailingGarbage += 1;
            child = childAfter(child!);
        }
    }
    collectGarbage(leadingGarbage, trailingGarbage);
    assert(debugAssertChildListIsNonEmptyAndContiguous());
    double estimatedMaxScrollOffset;
    if (reachedEnd) {
        estimatedMaxScrollOffset = endScrollOffset;
    } else {
        estimatedMaxScrollOffset = childManager->estimateMaxScrollOffset(constraints, indexOf(firstChild!), indexOf(lastChild!), childScrollOffset(firstChild!), endScrollOffset);
        assert(estimatedMaxScrollOffset >= endScrollOffset - childScrollOffset(firstChild!)!);
    }
    double paintExtent = calculatePaintOffset(constraints, childScrollOffset(firstChild!)!, endScrollOffset);
    double cacheExtent = calculateCacheOffset(constraints, childScrollOffset(firstChild!)!, endScrollOffset);
    double targetEndScrollOffsetForPaint = constraints->scrollOffset + constraints->remainingPaintExtent;
    geometry = make<SliverGeometryCls>(estimatedMaxScrollOffset, paintExtent, cacheExtent, estimatedMaxScrollOffset, endScrollOffset > targetEndScrollOffsetForPaint || constraints->scrollOffset > 0.0);
    if (estimatedMaxScrollOffset == endScrollOffset) {
        childManager->setDidUnderflow(true);
    }
    childManager->didFinishLayout();
}
