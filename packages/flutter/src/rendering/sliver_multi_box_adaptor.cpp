#include "sliver_multi_box_adaptor.hpp"
void RenderSliverBoxChildManager::didStartLayout() {
}

void RenderSliverBoxChildManager::didFinishLayout() {
}

bool RenderSliverBoxChildManager::debugAssertChildListLocked() {
    return true;
}

void RenderSliverWithKeepAliveMixin::setupParentData(RenderObject child) {
    assert(child.parentData is KeepAliveParentDataMixin);
}

bool SliverMultiBoxAdaptorParentData::keptAlive() {
    return _keptAlive;
}

String SliverMultiBoxAdaptorParentData::toString() {
    return "index=$index; ${keepAlive == true ? "keepAlive; " : ""}${super.toString()}";
}

RenderSliverMultiBoxAdaptor::RenderSliverMultiBoxAdaptor(RenderSliverBoxChildManager childManager) {
    {
        assert(childManager != nullptr);
        _childManager = childManager;
    }
    {
        assert(());
    }
}

void RenderSliverMultiBoxAdaptor::setupParentData(RenderObject child) {
    if (child.parentData is! SliverMultiBoxAdaptorParentData) {
        child.parentData = SliverMultiBoxAdaptorParentData();
    }
}

RenderSliverBoxChildManager RenderSliverMultiBoxAdaptor::childManager() {
    return _childManager;
}

bool RenderSliverMultiBoxAdaptor::debugChildIntegrityEnabled() {
    return _debugChildIntegrityEnabled;
}

void RenderSliverMultiBoxAdaptor::debugChildIntegrityEnabled(bool enabled) {
    assert(enabled != nullptr);
    assert(());
}

void RenderSliverMultiBoxAdaptor::adoptChild(RenderObject child) {
    super.adoptChild(child);
    SliverMultiBoxAdaptorParentData childParentData = (;
    if (!childParentData._keptAlive) {
        childManager.didAdoptChild(();
    }
}

void RenderSliverMultiBoxAdaptor::insert(RenderBox after, RenderBox child) {
    assert(!_keepAliveBucket.containsValue(child));
    super.insert(childafter);
    assert(firstChild != nullptr);
    assert(_debugVerifyChildOrder());
}

void RenderSliverMultiBoxAdaptor::move(RenderBox after, RenderBox child) {
    SliverMultiBoxAdaptorParentData childParentData = (;
    if (!childParentData.keptAlive) {
        super.move(childafter);
        childManager.didAdoptChild(child);
        markNeedsLayout();
    } else {
        if (_keepAliveBucket[childParentData.index] == child) {
            _keepAliveBucket.remove(childParentData.index);
        }
        assert(());
        childManager.didAdoptChild(child);
        assert(());
        _keepAliveBucket[childParentData.index!] = child;
    }
}

void RenderSliverMultiBoxAdaptor::remove(RenderBox child) {
    SliverMultiBoxAdaptorParentData childParentData = (;
    if (!childParentData._keptAlive) {
        super.remove(child);
        return;
    }
    assert(_keepAliveBucket[childParentData.index] == child);
    assert(());
    _keepAliveBucket.remove(childParentData.index);
    dropChild(child);
}

void RenderSliverMultiBoxAdaptor::removeAll() {
    super.removeAll();
    _keepAliveBucket.values.forEach(dropChild);
    _keepAliveBucket.clear();
}

void RenderSliverMultiBoxAdaptor::attach(PipelineOwner owner) {
    super.attach(owner);
    for (RenderBox child : _keepAliveBucket.values) {
        child.attach(owner);
    }
}

void RenderSliverMultiBoxAdaptor::detach() {
    super.detach();
    for (RenderBox child : _keepAliveBucket.values) {
        child.detach();
    }
}

void RenderSliverMultiBoxAdaptor::redepthChildren() {
    super.redepthChildren();
    _keepAliveBucket.values.forEach(redepthChild);
}

void RenderSliverMultiBoxAdaptor::visitChildren(RenderObjectVisitor visitor) {
    super.visitChildren(visitor);
    _keepAliveBucket.values.forEach(visitor);
}

void RenderSliverMultiBoxAdaptor::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    super.visitChildren(visitor);
}

bool RenderSliverMultiBoxAdaptor::addInitialChild(int index, double layoutOffset) {
    assert(_debugAssertChildListLocked());
    assert(firstChild == nullptr);
    _createOrObtainChild(indexnullptr);
    if (firstChild != nullptr) {
        assert(firstChild == lastChild);
        assert(indexOf(firstChild!) == index);
        SliverMultiBoxAdaptorParentData firstChildParentData = (;
        firstChildParentData.layoutOffset = layoutOffset;
        return true;
    }
    childManager.setDidUnderflow(true);
    return false;
}

RenderBox RenderSliverMultiBoxAdaptor::insertAndLayoutLeadingChild(BoxConstraints childConstraints, bool parentUsesSize) {
    assert(_debugAssertChildListLocked());
    int index = indexOf(firstChild!) - 1;
    _createOrObtainChild(indexnullptr);
    if (indexOf(firstChild!) == index) {
        firstChild!.layout(childConstraintsparentUsesSize);
        return firstChild;
    }
    childManager.setDidUnderflow(true);
    return nullptr;
}

RenderBox RenderSliverMultiBoxAdaptor::insertAndLayoutChild(RenderBox after, BoxConstraints childConstraints, bool parentUsesSize) {
    assert(_debugAssertChildListLocked());
    assert(after != nullptr);
    int index = indexOf(after!) + 1;
    _createOrObtainChild(indexafter);
    RenderBox child = childAfter(after);
    if (child != nullptr && indexOf(child) == index) {
        child.layout(childConstraintsparentUsesSize);
        return child;
    }
    childManager.setDidUnderflow(true);
    return nullptr;
}

void RenderSliverMultiBoxAdaptor::collectGarbage(int leadingGarbage, int trailingGarbage) {
    assert(_debugAssertChildListLocked());
    assert(childCount >= leadingGarbage + trailingGarbage);
    <SliverConstraints>invokeLayoutCallback();
}

int RenderSliverMultiBoxAdaptor::indexOf(RenderBox child) {
    assert(child != nullptr);
    SliverMultiBoxAdaptorParentData childParentData = (;
    assert(childParentData.index != nullptr);
    return childParentData.index!;
}

double RenderSliverMultiBoxAdaptor::paintExtentOf(RenderBox child) {
    assert(child != nullptr);
    assert(child.hasSize);
    ;
}

bool RenderSliverMultiBoxAdaptor::hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result) {
    RenderBox child = lastChild;
    BoxHitTestResult boxResult = BoxHitTestResult.wrap(result);
    while (child != nullptr) {
        if (hitTestBoxChild(boxResult, childmainAxisPosition, crossAxisPosition)) {
            return true;
        }
        child = childBefore(child);
    }
    return false;
}

double RenderSliverMultiBoxAdaptor::childMainAxisPosition(RenderBox child) {
    return childScrollOffset(child)! - constraints.scrollOffset;
}

double RenderSliverMultiBoxAdaptor::childScrollOffset(RenderObject child) {
    assert(child != nullptr);
    assert(child.parent == this);
    SliverMultiBoxAdaptorParentData childParentData = (;
    return childParentData.layoutOffset;
}

bool RenderSliverMultiBoxAdaptor::paintsChild(RenderBox child) {
    SliverMultiBoxAdaptorParentData childParentData = (;
    return childParentData?.index != nullptr && !_keepAliveBucket.containsKey(childParentData!.index);
}

void RenderSliverMultiBoxAdaptor::applyPaintTransform(RenderBox child, Matrix4 transform) {
    if (!paintsChild(child)) {
        transform.setZero();
    } else {
        applyPaintTransformForBoxChild(child, transform);
    }
}

void RenderSliverMultiBoxAdaptor::paint(PaintingContext context, Offset offset) {
    if (firstChild == nullptr) {
        return;
    }
    Offset mainAxisUnit, crossAxisUnit, originOffset;
    bool addExtent;
    ;
    assert(mainAxisUnit != nullptr);
    assert(addExtent != nullptr);
    RenderBox child = firstChild;
    while (child != nullptr) {
        double mainAxisDelta = childMainAxisPosition(child);
        double crossAxisDelta = childCrossAxisPosition(child);
        Offset childOffset = Offset(originOffset.dx + mainAxisUnit.dx * mainAxisDelta + crossAxisUnit.dx * crossAxisDelta, originOffset.dy + mainAxisUnit.dy * mainAxisDelta + crossAxisUnit.dy * crossAxisDelta);
        if (addExtent) {
            childOffset = mainAxisUnit * paintExtentOf(child);
        }
        if ( < constraints.remainingPaintExtent && mainAxisDelta + paintExtentOf(child) > 0) {
            context.paintChild(child, childOffset);
        }
        child = childAfter(child);
    }
}

void RenderSliverMultiBoxAdaptor::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DiagnosticsNode.message(firstChild != nullptr? "currently live children: ${indexOf(firstChild!)} to ${indexOf(lastChild!)}" : "no children current live"));
}

bool RenderSliverMultiBoxAdaptor::debugAssertChildListIsNonEmptyAndContiguous() {
    assert(());
    return true;
}

List<DiagnosticsNode> RenderSliverMultiBoxAdaptor::debugDescribeChildren() {
    List<DiagnosticsNode> children = ;
    if (firstChild != nullptr) {
        RenderBox child = firstChild;
        while (true) {
            SliverMultiBoxAdaptorParentData childParentData = (;
            children.add(child.toDiagnosticsNode("child with index ${childParentData.index}"));
            if (child == lastChild) {
                                break;
            }
            child = childParentData.nextSibling;
        }
    }
    if (_keepAliveBucket.isNotEmpty) {
        List<int> indices = ;
        for (int index : indices) {
            children.add(_keepAliveBucket[index]!.toDiagnosticsNode("child with index $index (kept alive but not laid out)", DiagnosticsTreeStyle.offstage));
        }
    }
    return children;
}

bool RenderSliverMultiBoxAdaptor::_debugAssertChildListLocked() {
    return childManager.debugAssertChildListLocked();
}

bool RenderSliverMultiBoxAdaptor::_debugVerifyChildOrder() {
    if (_debugChildIntegrityEnabled) {
        RenderBox child = firstChild;
        int index;
        while (child != nullptr) {
            index = indexOf(child);
            child = childAfter(child);
            assert(child == nullptr || indexOf(child) > index);
        }
    }
    return true;
}

void RenderSliverMultiBoxAdaptor::_createOrObtainChild(RenderBox after, int index) {
    <SliverConstraints>invokeLayoutCallback();
}

void RenderSliverMultiBoxAdaptor::_destroyOrCacheChild(RenderBox child) {
    SliverMultiBoxAdaptorParentData childParentData = (;
    if (childParentData.keepAlive) {
        assert(!childParentData._keptAlive);
        remove(child);
        _keepAliveBucket[childParentData.index!] = child;
        child.parentData = childParentData;
        super.adoptChild(child);
        childParentData._keptAlive = true;
    } else {
        assert(child.parent == this);
        _childManager.removeChild(child);
        assert(child.parent == nullptr);
    }
}
