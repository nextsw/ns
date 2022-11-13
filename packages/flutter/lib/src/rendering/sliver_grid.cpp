#include "sliver_grid.hpp"
double SliverGridGeometryCls::trailingScrollOffset() {
    return scrollOffset + mainAxisExtent;
}

BoxConstraints SliverGridGeometryCls::getBoxConstraints(SliverConstraints constraints) {
    return constraints->asBoxConstraints(mainAxisExtent, mainAxisExtent, crossAxisExtent);
}

String SliverGridGeometryCls::toString() {
    List<String> properties = makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem);
    return __sf("SliverGridGeometry(%s)", properties->join(__s(", ")));
}

SliverGridRegularTileLayoutCls::SliverGridRegularTileLayoutCls(double childCrossAxisExtent, double childMainAxisExtent, int crossAxisCount, double crossAxisStride, double mainAxisStride, bool reverseCrossAxis) {
    {
        assert(crossAxisCount != nullptr && crossAxisCount > 0);
        assert(mainAxisStride != nullptr && mainAxisStride >= 0);
        assert(crossAxisStride != nullptr && crossAxisStride >= 0);
        assert(childMainAxisExtent != nullptr && childMainAxisExtent >= 0);
        assert(childCrossAxisExtent != nullptr && childCrossAxisExtent >= 0);
        assert(reverseCrossAxis != nullptr);
    }
}

int SliverGridRegularTileLayoutCls::getMinChildIndexForScrollOffset(double scrollOffset) {
    return mainAxisStride > precisionErrorTolerance? crossAxisCount * (scrollOffset ~/ mainAxisStride) : 0;
}

int SliverGridRegularTileLayoutCls::getMaxChildIndexForScrollOffset(double scrollOffset) {
    if (mainAxisStride > 0.0) {
        int mainAxisCount = (scrollOffset / mainAxisStride)->ceil();
        return math->max(0, crossAxisCount * mainAxisCount - 1);
    }
    return 0;
}

SliverGridGeometry SliverGridRegularTileLayoutCls::getGeometryForChildIndex(int index) {
    double crossAxisStart = (index % crossAxisCount) * crossAxisStride;
    return make<SliverGridGeometryCls>((index ~/ crossAxisCount) * mainAxisStride, _getOffsetFromStartInCrossAxis(crossAxisStart), childMainAxisExtent, childCrossAxisExtent);
}

double SliverGridRegularTileLayoutCls::computeMaxScrollOffset(int childCount) {
    assert(childCount != nullptr);
    int mainAxisCount = ((childCount - 1) ~/ crossAxisCount) + 1;
    double mainAxisSpacing = mainAxisStride - childMainAxisExtent;
    return mainAxisStride * mainAxisCount - mainAxisSpacing;
}

double SliverGridRegularTileLayoutCls::_getOffsetFromStartInCrossAxis(double crossAxisStart) {
    if (reverseCrossAxis) {
        return crossAxisCount * crossAxisStride - crossAxisStart - childCrossAxisExtent - (crossAxisStride - childCrossAxisExtent);
    }
    return crossAxisStart;
}

SliverGridDelegateWithFixedCrossAxisCountCls::SliverGridDelegateWithFixedCrossAxisCountCls(double childAspectRatio, int crossAxisCount, double crossAxisSpacing, double mainAxisExtent, double mainAxisSpacing) {
    {
        assert(crossAxisCount != nullptr && crossAxisCount > 0);
        assert(mainAxisSpacing != nullptr && mainAxisSpacing >= 0);
        assert(crossAxisSpacing != nullptr && crossAxisSpacing >= 0);
        assert(childAspectRatio != nullptr && childAspectRatio > 0);
    }
}

SliverGridLayout SliverGridDelegateWithFixedCrossAxisCountCls::getLayout(SliverConstraints constraints) {
    assert(_debugAssertIsValid());
    double usableCrossAxisExtent = math->max(0.0, constraints->crossAxisExtent - crossAxisSpacing * (crossAxisCount - 1));
    double childCrossAxisExtent = usableCrossAxisExtent / crossAxisCount;
    double childMainAxisExtent = mainAxisExtent | childCrossAxisExtent / childAspectRatio;
    return make<SliverGridRegularTileLayoutCls>(crossAxisCount, childMainAxisExtent + mainAxisSpacing, childCrossAxisExtent + crossAxisSpacing, childMainAxisExtent, childCrossAxisExtent, axisDirectionIsReversed(constraints->crossAxisDirection));
}

bool SliverGridDelegateWithFixedCrossAxisCountCls::shouldRelayout(SliverGridDelegateWithFixedCrossAxisCount oldDelegate) {
    return oldDelegate->crossAxisCount != crossAxisCount || oldDelegate->mainAxisSpacing != mainAxisSpacing || oldDelegate->crossAxisSpacing != crossAxisSpacing || oldDelegate->childAspectRatio != childAspectRatio || oldDelegate->mainAxisExtent != mainAxisExtent;
}

bool SliverGridDelegateWithFixedCrossAxisCountCls::_debugAssertIsValid() {
    assert(crossAxisCount > 0);
    assert(mainAxisSpacing >= 0.0);
    assert(crossAxisSpacing >= 0.0);
    assert(childAspectRatio > 0.0);
    return true;
}

SliverGridDelegateWithMaxCrossAxisExtentCls::SliverGridDelegateWithMaxCrossAxisExtentCls(double childAspectRatio, double crossAxisSpacing, double mainAxisExtent, double mainAxisSpacing, double maxCrossAxisExtent) {
    {
        assert(maxCrossAxisExtent != nullptr && maxCrossAxisExtent > 0);
        assert(mainAxisSpacing != nullptr && mainAxisSpacing >= 0);
        assert(crossAxisSpacing != nullptr && crossAxisSpacing >= 0);
        assert(childAspectRatio != nullptr && childAspectRatio > 0);
    }
}

SliverGridLayout SliverGridDelegateWithMaxCrossAxisExtentCls::getLayout(SliverConstraints constraints) {
    assert(_debugAssertIsValid(constraints->crossAxisExtent));
    int crossAxisCount = (constraints->crossAxisExtent / (maxCrossAxisExtent + crossAxisSpacing))->ceil();
    double usableCrossAxisExtent = math->max(0.0, constraints->crossAxisExtent - crossAxisSpacing * (crossAxisCount - 1));
    double childCrossAxisExtent = usableCrossAxisExtent / crossAxisCount;
    double childMainAxisExtent = mainAxisExtent | childCrossAxisExtent / childAspectRatio;
    return make<SliverGridRegularTileLayoutCls>(crossAxisCount, childMainAxisExtent + mainAxisSpacing, childCrossAxisExtent + crossAxisSpacing, childMainAxisExtent, childCrossAxisExtent, axisDirectionIsReversed(constraints->crossAxisDirection));
}

bool SliverGridDelegateWithMaxCrossAxisExtentCls::shouldRelayout(SliverGridDelegateWithMaxCrossAxisExtent oldDelegate) {
    return oldDelegate->maxCrossAxisExtent != maxCrossAxisExtent || oldDelegate->mainAxisSpacing != mainAxisSpacing || oldDelegate->crossAxisSpacing != crossAxisSpacing || oldDelegate->childAspectRatio != childAspectRatio || oldDelegate->mainAxisExtent != mainAxisExtent;
}

bool SliverGridDelegateWithMaxCrossAxisExtentCls::_debugAssertIsValid(double crossAxisExtent) {
    assert(crossAxisExtent > 0.0);
    assert(maxCrossAxisExtent > 0.0);
    assert(mainAxisSpacing >= 0.0);
    assert(crossAxisSpacing >= 0.0);
    assert(childAspectRatio > 0.0);
    return true;
}

String SliverGridParentDataCls::toString() {
    return __sf("crossAxisOffset=%s; %s", crossAxisOffset, super->toString());
}

RenderSliverGridCls::RenderSliverGridCls(RenderSliverBoxChildManager childManager, SliverGridDelegate gridDelegate) {
    {
        assert(gridDelegate != nullptr);
        _gridDelegate = gridDelegate;
    }
}

void RenderSliverGridCls::setupParentData(RenderObject child) {
    if (!is<SliverGridParentData>(child->parentData)) {
        child->parentData = make<SliverGridParentDataCls>();
    }
}

SliverGridDelegate RenderSliverGridCls::gridDelegate() {
    return _gridDelegate;
}

void RenderSliverGridCls::gridDelegate(SliverGridDelegate value) {
    assert(value != nullptr);
    if (_gridDelegate == value) {
        return;
    }
    if (value->runtimeType != _gridDelegate->runtimeType || value->shouldRelayout(_gridDelegate)) {
        markNeedsLayout();
    }
    _gridDelegate = value;
}

double RenderSliverGridCls::childCrossAxisPosition(RenderBox child) {
    SliverGridParentData childParentData = as<SliverGridParentData>(child->parentData!);
    return childParentData->crossAxisOffset!;
}

void RenderSliverGridCls::performLayout() {
    SliverConstraints constraints = this->constraints();
    childManager()->didStartLayout();
    childManager()->setDidUnderflow(false);
    double scrollOffset = constraints->scrollOffset + constraints->cacheOrigin;
    assert(scrollOffset >= 0.0);
    double remainingExtent = constraints->remainingCacheExtent;
    assert(remainingExtent >= 0.0);
    double targetEndScrollOffset = scrollOffset + remainingExtent;
    SliverGridLayout layout = _gridDelegate->getLayout(constraints);
    int firstIndex = layout->getMinChildIndexForScrollOffset(scrollOffset);
    int targetLastIndex = targetEndScrollOffset->isFinite()? layout->getMaxChildIndexForScrollOffset(targetEndScrollOffset) : nullptr;
    if (firstChild != nullptr) {
        int oldFirstIndex = indexOf(firstChild!);
        int oldLastIndex = indexOf(lastChild!);
        int leadingGarbage = (firstIndex - oldFirstIndex)->clamp(0, childCount);
        int trailingGarbage = targetLastIndex == nullptr? 0 : (oldLastIndex - targetLastIndex)->clamp(0, childCount);
        collectGarbage(leadingGarbage, trailingGarbage);
    } else {
        collectGarbage(0, 0);
    }
    SliverGridGeometry firstChildGridGeometry = layout->getGeometryForChildIndex(firstIndex);
    double leadingScrollOffset = firstChildGridGeometry->scrollOffset;
    double trailingScrollOffset = firstChildGridGeometry->trailingScrollOffset();
    if (firstChild == nullptr) {
        if (!addInitialChild(firstIndex, firstChildGridGeometry->scrollOffset)) {
            double max = layout->computeMaxScrollOffset(childManager()->childCount());
            geometry() = make<SliverGeometryCls>(max, max);
            childManager()->didFinishLayout();
            return;
        }
    }
    RenderBox trailingChildWithLayout;
    for (; index >= firstIndex; --index) {
        SliverGridGeometry gridGeometry = layout->getGeometryForChildIndex(index);
        RenderBox child = insertAndLayoutLeadingChild(gridGeometry->getBoxConstraints(constraints))!;
        SliverGridParentData childParentData = as<SliverGridParentData>(child->parentData!);
        childParentData->layoutOffset = gridGeometry->scrollOffset;
        childParentData->crossAxisOffset = gridGeometry->crossAxisOffset;
        assert(childParentData->index == index);
        trailingChildWithLayout |= child;
        trailingScrollOffset = math->max(trailingScrollOffset, gridGeometry->trailingScrollOffset);
    }
    if (trailingChildWithLayout == nullptr) {
        firstChild!->layout(firstChildGridGeometry->getBoxConstraints(constraints));
        SliverGridParentData childParentData = as<SliverGridParentData>(firstChild!->parentData!);
        childParentData->layoutOffset = firstChildGridGeometry->scrollOffset;
        childParentData->crossAxisOffset = firstChildGridGeometry->crossAxisOffset;
        trailingChildWithLayout = firstChild;
    }
    for (; targetLastIndex == nullptr || index <= targetLastIndex; ++index) {
        SliverGridGeometry gridGeometry = layout->getGeometryForChildIndex(index);
        BoxConstraints childConstraints = gridGeometry->getBoxConstraints(constraints);
        RenderBox child = childAfter(trailingChildWithLayout!);
        if (child == nullptr || indexOf(child) != index) {
            child = insertAndLayoutChild(childConstraints, trailingChildWithLayout);
            if (child == nullptr) {
                break;
            }
        } else {
            child->layout(childConstraints);
        }
        trailingChildWithLayout = child;
        assert(child != nullptr);
        SliverGridParentData childParentData = as<SliverGridParentData>(child->parentData!);
        childParentData->layoutOffset = gridGeometry->scrollOffset;
        childParentData->crossAxisOffset = gridGeometry->crossAxisOffset;
        assert(childParentData->index == index);
        trailingScrollOffset = math->max(trailingScrollOffset, gridGeometry->trailingScrollOffset);
    }
    int lastIndex = indexOf(lastChild!);
    assert(debugAssertChildListIsNonEmptyAndContiguous());
    assert(indexOf(firstChild!) == firstIndex);
    assert(targetLastIndex == nullptr || lastIndex <= targetLastIndex);
    double estimatedTotalExtent = childManager()->estimateMaxScrollOffset(constraints, firstIndex, lastIndex, leadingScrollOffset, trailingScrollOffset);
    double paintExtent = calculatePaintOffset(constraints, math->min(constraints->scrollOffset, leadingScrollOffset), trailingScrollOffset);
    double cacheExtent = calculateCacheOffset(constraints, leadingScrollOffset, trailingScrollOffset);
    geometry() = make<SliverGeometryCls>(estimatedTotalExtent, paintExtent, estimatedTotalExtent, cacheExtent, estimatedTotalExtent > paintExtent || constraints->scrollOffset > 0.0 || constraints->overlap != 0.0);
    if (estimatedTotalExtent == trailingScrollOffset) {
        childManager()->setDidUnderflow(true);
    }
    childManager()->didFinishLayout();
}
