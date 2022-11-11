#include "sliver_fixed_extent_list.hpp"
double RenderSliverFixedExtentBoxAdaptorCls::indexToLayoutOffset(int index, double itemExtent) {
    return itemExtent * index;
}

int RenderSliverFixedExtentBoxAdaptorCls::getMinChildIndexForScrollOffset(double itemExtent, double scrollOffset) {
    if (itemExtent > 0.0) {
        double actual = scrollOffset / itemExtent;
        int round = actual->round();
        if ((actual * itemExtent - round * itemExtent)->abs() < precisionErrorTolerance) {
            return round;
        }
        return actual->floor();
    }
    return 0;
}

int RenderSliverFixedExtentBoxAdaptorCls::getMaxChildIndexForScrollOffset(double itemExtent, double scrollOffset) {
    if (itemExtent > 0.0) {
        double actual = scrollOffset / itemExtent - 1;
        int round = actual->round();
        if ((actual * itemExtent - round * itemExtent)->abs() < precisionErrorTolerance) {
            return math->max(0, round);
        }
        return math->max(0, actual->ceil());
    }
    return 0;
}

double RenderSliverFixedExtentBoxAdaptorCls::estimateMaxScrollOffset(SliverConstraints constraints, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset) {
    return childManager->estimateMaxScrollOffset(constraintsfirstIndex, lastIndex, leadingScrollOffset, trailingScrollOffset);
}

double RenderSliverFixedExtentBoxAdaptorCls::computeMaxScrollOffset(SliverConstraints constraints, double itemExtent) {
    return childManager->childCount * itemExtent;
}

void RenderSliverFixedExtentBoxAdaptorCls::performLayout() {
    SliverConstraints constraints = this->constraints;
    childManager->didStartLayout();
    childManager->setDidUnderflow(false);
    double itemExtent = this->itemExtent();
    double scrollOffset = constraints->scrollOffset + constraints->cacheOrigin;
    assert(scrollOffset >= 0.0);
    double remainingExtent = constraints->remainingCacheExtent;
    assert(remainingExtent >= 0.0);
    double targetEndScrollOffset = scrollOffset + remainingExtent;
    BoxConstraints childConstraints = constraints->asBoxConstraints(itemExtent, itemExtent);
    int firstIndex = getMinChildIndexForScrollOffset(scrollOffset, itemExtent);
    int targetLastIndex = targetEndScrollOffset->isFinite? getMaxChildIndexForScrollOffset(targetEndScrollOffset, itemExtent) : nullptr;
    if (firstChild != nullptr) {
        int leadingGarbage = _calculateLeadingGarbage(firstIndex);
        int trailingGarbage = targetLastIndex != nullptr? _calculateTrailingGarbage(targetLastIndex) : 0;
        collectGarbage(leadingGarbage, trailingGarbage);
    } else {
        collectGarbage(0, 0);
    }
    if (firstChild == nullptr) {
        if (!addInitialChild(firstIndex, indexToLayoutOffset(itemExtent, firstIndex))) {
            double max;
            if (firstIndex <= 0) {
                max = 0.0;
            } else {
                max = computeMaxScrollOffset(constraints, itemExtent);
            }
            geometry = make<SliverGeometryCls>(max, max);
            childManager->didFinishLayout();
            return;
        }
    }
    RenderBox trailingChildWithLayout;
    for (; index >= firstIndex; --index) {
        RenderBox child = insertAndLayoutLeadingChild(childConstraints);
        if (child == nullptr) {
            geometry = make<SliverGeometryCls>(index * itemExtent);
            return;
        }
        SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(child->parentData!);
        childParentData->layoutOffset = indexToLayoutOffset(itemExtent, index);
        assert(childParentData->index == index);
        trailingChildWithLayout = child;
    }
    if (trailingChildWithLayout == nullptr) {
        firstChild!->layout(childConstraints);
        SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(firstChild!->parentData!);
        childParentData->layoutOffset = indexToLayoutOffset(itemExtent, firstIndex);
        trailingChildWithLayout = firstChild;
    }
    double estimatedMaxScrollOffset = double->infinity;
    for (; targetLastIndex == nullptr || index <= targetLastIndex; ++index) {
        RenderBox child = childAfter(trailingChildWithLayout!);
        if (child == nullptr || indexOf(child) != index) {
            child = insertAndLayoutChild(childConstraintstrailingChildWithLayout);
            if (child == nullptr) {
                estimatedMaxScrollOffset = index * itemExtent;
                break;
            }
        } else {
            child->layout(childConstraints);
        }
        trailingChildWithLayout = child;
        assert(child != nullptr);
        SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(child->parentData!);
        assert(childParentData->index == index);
        childParentData->layoutOffset = indexToLayoutOffset(itemExtent, childParentData->index!);
    }
    int lastIndex = indexOf(lastChild!);
    double leadingScrollOffset = indexToLayoutOffset(itemExtent, firstIndex);
    double trailingScrollOffset = indexToLayoutOffset(itemExtent, lastIndex + 1);
    assert(firstIndex == 0 || childScrollOffset(firstChild!)! - scrollOffset <= precisionErrorTolerance);
    assert(debugAssertChildListIsNonEmptyAndContiguous());
    assert(indexOf(firstChild!) == firstIndex);
    assert(targetLastIndex == nullptr || lastIndex <= targetLastIndex);
    estimatedMaxScrollOffset = math->min(estimatedMaxScrollOffset, estimateMaxScrollOffset(constraintsfirstIndex, lastIndex, leadingScrollOffset, trailingScrollOffset));
    double paintExtent = calculatePaintOffset(constraintsleadingScrollOffset, trailingScrollOffset);
    double cacheExtent = calculateCacheOffset(constraintsleadingScrollOffset, trailingScrollOffset);
    double targetEndScrollOffsetForPaint = constraints->scrollOffset + constraints->remainingPaintExtent;
    int targetLastIndexForPaint = targetEndScrollOffsetForPaint->isFinite? getMaxChildIndexForScrollOffset(targetEndScrollOffsetForPaint, itemExtent) : nullptr;
    geometry = make<SliverGeometryCls>(estimatedMaxScrollOffset, paintExtent, cacheExtent, estimatedMaxScrollOffset, (targetLastIndexForPaint != nullptr && lastIndex >= targetLastIndexForPaint) || constraints->scrollOffset > 0.0);
    if (estimatedMaxScrollOffset == trailingScrollOffset) {
        childManager->setDidUnderflow(true);
    }
    childManager->didFinishLayout();
}

int RenderSliverFixedExtentBoxAdaptorCls::_calculateLeadingGarbage(int firstIndex) {
    RenderBox walker = firstChild;
    int leadingGarbage = 0;
    while (walker != nullptr && indexOf(walker) < firstIndex) {
        leadingGarbage = 1;
        walker = childAfter(walker);
    }
    return leadingGarbage;
}

int RenderSliverFixedExtentBoxAdaptorCls::_calculateTrailingGarbage(int targetLastIndex) {
    RenderBox walker = lastChild;
    int trailingGarbage = 0;
    while (walker != nullptr && indexOf(walker) > targetLastIndex) {
        trailingGarbage = 1;
        walker = childBefore(walker);
    }
    return trailingGarbage;
}

RenderSliverFixedExtentListCls::RenderSliverFixedExtentListCls(Unknown childManager, double itemExtent) {
    {
        _itemExtent = itemExtent;
    }
}

double RenderSliverFixedExtentListCls::itemExtent() {
    return _itemExtent;
}

void RenderSliverFixedExtentListCls::itemExtent(double value) {
    assert(value != nullptr);
    if (_itemExtent == value) {
        return;
    }
    _itemExtent = value;
    markNeedsLayout();
}
