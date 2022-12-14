#include "sliver_multi_box_adaptor.hpp"
void RenderSliverBoxChildManagerCls::didStartLayout() {
}

void RenderSliverBoxChildManagerCls::didFinishLayout() {
}

bool RenderSliverBoxChildManagerCls::debugAssertChildListLocked() {
    return true;
}

void RenderSliverWithKeepAliveMixinCls::setupParentData(RenderObject child) {
    assert(is<KeepAliveParentDataMixin>(child->parentData));
}

bool SliverMultiBoxAdaptorParentDataCls::keptAlive() {
    return _keptAlive;
}

String SliverMultiBoxAdaptorParentDataCls::toString() {
    return __sf("index=%s; %s", index, keepAlive == true? __s("keepAlive; ") : __sf("%s", super->toString()));
}

RenderSliverMultiBoxAdaptorCls::RenderSliverMultiBoxAdaptorCls(RenderSliverBoxChildManager childManager) {
    {
        assert(childManager != nullptr);
        _childManager = childManager;
    }
    {
        assert([=] () {
            _debugDanglingKeepAlives = makeList();
            return true;
        }());
    }
}

void RenderSliverMultiBoxAdaptorCls::setupParentData(RenderObject child) {
    if (!is<SliverMultiBoxAdaptorParentData>(child->parentData)) {
        child->parentData = make<SliverMultiBoxAdaptorParentDataCls>();
    }
}

RenderSliverBoxChildManager RenderSliverMultiBoxAdaptorCls::childManager() {
    return _childManager;
}

bool RenderSliverMultiBoxAdaptorCls::debugChildIntegrityEnabled() {
    return _debugChildIntegrityEnabled;
}

void RenderSliverMultiBoxAdaptorCls::debugChildIntegrityEnabled(bool enabled) {
    assert(enabled != nullptr);
    assert([=] () {
        _debugChildIntegrityEnabled = enabled;
        return _debugVerifyChildOrder() && (!_debugChildIntegrityEnabled || _debugDanglingKeepAlives->isEmpty());
    }());
}

void RenderSliverMultiBoxAdaptorCls::adoptChild(RenderObject child) {
    super->adoptChild(child);
    SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(child->parentData!);
    if (!childParentData->_keptAlive) {
        childManager()->didAdoptChild(as<RenderBox>(child));
    }
}

void RenderSliverMultiBoxAdaptorCls::insert(RenderBox child, RenderBox after) {
    assert(!_keepAliveBucket->containsValue(child));
    super->insert(child, after);
    assert(firstChild != nullptr);
    assert(_debugVerifyChildOrder());
}

void RenderSliverMultiBoxAdaptorCls::move(RenderBox child, RenderBox after) {
    SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(child->parentData!);
    if (!childParentData->keptAlive()) {
        super->move(child, after);
        childManager()->didAdoptChild(child);
        markNeedsLayout();
    } else {
        if (_keepAliveBucket[childParentData->index] == child) {
            _keepAliveBucket->remove(childParentData->index);
        }
        assert([=] () {
            _debugDanglingKeepAlives->remove(child);
            return true;
        }());
        childManager()->didAdoptChild(child);
        assert([=] () {
            if (_keepAliveBucket->containsKey(childParentData->index)) {
                _debugDanglingKeepAlives->add(_keepAliveBucket[childParentData->index]!);
            }
            return true;
        }());
        _keepAliveBucket[childParentData->index!] = child;
    }
}

void RenderSliverMultiBoxAdaptorCls::remove(RenderBox child) {
    SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(child->parentData!);
    if (!childParentData->_keptAlive) {
        super->remove(child);
        return;
    }
    assert(_keepAliveBucket[childParentData->index] == child);
    assert([=] () {
        _debugDanglingKeepAlives->remove(child);
        return true;
    }());
    _keepAliveBucket->remove(childParentData->index);
    dropChild(child);
}

void RenderSliverMultiBoxAdaptorCls::removeAll() {
    super->removeAll();
    _keepAliveBucket->values()->forEach(dropChild);
    _keepAliveBucket->clear();
}

void RenderSliverMultiBoxAdaptorCls::attach(PipelineOwner owner) {
    super->attach(owner);
    for (RenderBox child : _keepAliveBucket->values()) {
        child->attach(owner);
    }
}

void RenderSliverMultiBoxAdaptorCls::detach() {
    super->detach();
    for (RenderBox child : _keepAliveBucket->values()) {
        child->detach();
    }
}

void RenderSliverMultiBoxAdaptorCls::redepthChildren() {
    super->redepthChildren();
    _keepAliveBucket->values()->forEach(redepthChild);
}

void RenderSliverMultiBoxAdaptorCls::visitChildren(RenderObjectVisitor visitor) {
    super->visitChildren(visitor);
    _keepAliveBucket->values()->forEach(visitor);
}

void RenderSliverMultiBoxAdaptorCls::visitChildrenForSemantics(RenderObjectVisitor visitor) {
    super->visitChildren(visitor);
}

bool RenderSliverMultiBoxAdaptorCls::addInitialChild(int index, double layoutOffset) {
    assert(_debugAssertChildListLocked());
    assert(firstChild == nullptr);
    _createOrObtainChild(index, nullptr);
    if (firstChild != nullptr) {
        assert(firstChild == lastChild);
        assert(indexOf(firstChild!) == index);
        SliverMultiBoxAdaptorParentData firstChildParentData = as<SliverMultiBoxAdaptorParentData>(firstChild!->parentData!);
        firstChildParentData->layoutOffset = layoutOffset;
        return true;
    }
    childManager()->setDidUnderflow(true);
    return false;
}

RenderBox RenderSliverMultiBoxAdaptorCls::insertAndLayoutLeadingChild(BoxConstraints childConstraints, bool parentUsesSize) {
    assert(_debugAssertChildListLocked());
    int index = indexOf(firstChild!) - 1;
    _createOrObtainChild(index, nullptr);
    if (indexOf(firstChild!) == index) {
        firstChild!->layout(childConstraints, parentUsesSize);
        return firstChild;
    }
    childManager()->setDidUnderflow(true);
    return nullptr;
}

RenderBox RenderSliverMultiBoxAdaptorCls::insertAndLayoutChild(BoxConstraints childConstraints, RenderBox after, bool parentUsesSize) {
    assert(_debugAssertChildListLocked());
    assert(after != nullptr);
    int index = indexOf(after!) + 1;
    _createOrObtainChild(index, after);
    RenderBox child = childAfter(after);
    if (child != nullptr && indexOf(child) == index) {
        child->layout(childConstraints, parentUsesSize);
        return child;
    }
    childManager()->setDidUnderflow(true);
    return nullptr;
}

void RenderSliverMultiBoxAdaptorCls::collectGarbage(int leadingGarbage, int trailingGarbage) {
    assert(_debugAssertChildListLocked());
    assert(childCount >= leadingGarbage + trailingGarbage);
    <SliverConstraints>invokeLayoutCallback([=] (SliverConstraints constraints) {
        while (leadingGarbage > 0) {
            _destroyOrCacheChild(firstChild!);
            leadingGarbage -= 1;
        }
        while (trailingGarbage > 0) {
            _destroyOrCacheChild(lastChild!);
            trailingGarbage -= 1;
        }
        _keepAliveBucket->values()->where([=] (RenderBox child) {
            SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(child->parentData!);
            return !childParentData->keepAlive;
        })->toList()->forEach(_childManager->removeChild);
        assert(_keepAliveBucket->values()->where([=] (RenderBox child) {
            SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(child->parentData!);
            return !childParentData->keepAlive;
        })->isEmpty());
    });
}

int RenderSliverMultiBoxAdaptorCls::indexOf(RenderBox child) {
    assert(child != nullptr);
    SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(child->parentData!);
    assert(childParentData->index != nullptr);
    return childParentData->index!;
}

double RenderSliverMultiBoxAdaptorCls::paintExtentOf(RenderBox child) {
    assert(child != nullptr);
    assert(child->hasSize());
    ;
}

bool RenderSliverMultiBoxAdaptorCls::hitTestChildren(SliverHitTestResult result, double crossAxisPosition, double mainAxisPosition) {
    RenderBox child = lastChild;
    BoxHitTestResult boxResult = BoxHitTestResultCls->wrap(result);
    while (child != nullptr) {
        if (hitTestBoxChild(boxResult, child, mainAxisPosition, crossAxisPosition)) {
            return true;
        }
        child = childBefore(child);
    }
    return false;
}

double RenderSliverMultiBoxAdaptorCls::childMainAxisPosition(RenderBox child) {
    return childScrollOffset(child)! - constraints()->scrollOffset;
}

double RenderSliverMultiBoxAdaptorCls::childScrollOffset(RenderObject child) {
    assert(child != nullptr);
    assert(child->parent() == this);
    SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(child->parentData!);
    return childParentData->layoutOffset;
}

bool RenderSliverMultiBoxAdaptorCls::paintsChild(RenderBox child) {
    SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(child->parentData);
    return childParentData?->index != nullptr && !_keepAliveBucket->containsKey(childParentData!->index);
}

void RenderSliverMultiBoxAdaptorCls::applyPaintTransform(RenderBox child, Matrix4 transform) {
    if (!paintsChild(child)) {
        transform->setZero();
    } else {
        applyPaintTransformForBoxChild(child, transform);
    }
}

void RenderSliverMultiBoxAdaptorCls::paint(PaintingContext context, Offset offset) {
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
        Offset childOffset = make<OffsetCls>(originOffset->dx() + mainAxisUnit->dx() * mainAxisDelta + crossAxisUnit->dx() * crossAxisDelta, originOffset->dy() + mainAxisUnit->dy() * mainAxisDelta + crossAxisUnit->dy() * crossAxisDelta);
        if (addExtent) {
            childOffset += mainAxisUnit * paintExtentOf(child);
        }
        if ( < constraints()->remainingPaintExtent && mainAxisDelta + paintExtentOf(child) > 0) {
            context->paintChild(child, childOffset);
        }
        child = childAfter(child);
    }
}

void RenderSliverMultiBoxAdaptorCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(DiagnosticsNodeCls->message(firstChild != nullptr? __sf("currently live children: %s to %s", indexOf(firstChild!), indexOf(lastChild!)) : __s("no children current live")));
}

bool RenderSliverMultiBoxAdaptorCls::debugAssertChildListIsNonEmptyAndContiguous() {
    assert([=] () {
        assert(firstChild != nullptr);
        int index = indexOf(firstChild!);
        RenderBox child = childAfter(firstChild!);
        while (child != nullptr) {
            index += 1;
            assert(indexOf(child) == index);
            child = childAfter(child);
        }
        return true;
    }());
    return true;
}

List<DiagnosticsNode> RenderSliverMultiBoxAdaptorCls::debugDescribeChildren() {
    List<DiagnosticsNode> children = makeList();
    if (firstChild != nullptr) {
        RenderBox child = firstChild;
        while (true) {
            SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(child!->parentData!);
            children->add(child->toDiagnosticsNode(__sf("child with index %s", childParentData->index)));
            if (child == lastChild) {
                break;
            }
            child = childParentData->nextSibling;
        }
    }
    if (_keepAliveBucket->isNotEmpty()) {
            auto _c1 = _keepAliveBucket->keys()->toList();    _c1.sort();List<int> indices = _c1;
        for (int index : indices) {
            children->add(_keepAliveBucket[index]!->toDiagnosticsNode(__sf("child with index %s (kept alive but not laid out)", index), DiagnosticsTreeStyleCls::offstage));
        }
    }
    return children;
}

bool RenderSliverMultiBoxAdaptorCls::_debugAssertChildListLocked() {
    return childManager()->debugAssertChildListLocked();
}

bool RenderSliverMultiBoxAdaptorCls::_debugVerifyChildOrder() {
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

void RenderSliverMultiBoxAdaptorCls::_createOrObtainChild(int index, RenderBox after) {
    <SliverConstraints>invokeLayoutCallback([=] (SliverConstraints constraints) {
        assert(constraints() == this->constraints());
        if (_keepAliveBucket->containsKey(index)) {
            RenderBox child = _keepAliveBucket->remove(index)!;
            SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(child->parentData!);
            assert(childParentData->_keptAlive);
            dropChild(child);
            child->parentData = childParentData;
            insert(child, after);
            childParentData->_keptAlive = false;
        } else {
            _childManager->createChild(index, after);
        }
    });
}

void RenderSliverMultiBoxAdaptorCls::_destroyOrCacheChild(RenderBox child) {
    SliverMultiBoxAdaptorParentData childParentData = as<SliverMultiBoxAdaptorParentData>(child->parentData!);
    if (childParentData->keepAlive) {
        assert(!childParentData->_keptAlive);
        remove(child);
        _keepAliveBucket[childParentData->index!] = child;
        child->parentData = childParentData;
        super->adoptChild(child);
        childParentData->_keptAlive = true;
    } else {
        assert(child->parent() == this);
        _childManager->removeChild(child);
        assert(child->parent() == nullptr);
    }
}
