#include "custom_layout.hpp"
String MultiChildLayoutParentDataCls::toString() {
    return __s("%s$%s;");
}

MultiChildLayoutDelegateCls::MultiChildLayoutDelegateCls(Listenable relayout) {
    {
        _relayout = relayout;
    }
}

bool MultiChildLayoutDelegateCls::hasChild(Object childId) {
    return _idToChild![childId] != nullptr;
}

Size MultiChildLayoutDelegateCls::layoutChild(Object childId, BoxConstraints constraints) {
    RenderBox child = _idToChild![childId];
    assert([=] () {
        if (child == nullptr) {
            throw make<FlutterErrorCls>(__s("The %sThere is no child with the id "$%s,"));
        }
        if (!_debugChildrenNeedingLayout!->remove(child)) {
            throw make<FlutterErrorCls>(__s("The %s$%sEach child must be laid out exactly once.,"));
        }
        try {
            assert(constraints->debugAssertIsValid(true));
        } catch (AssertionError exception) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
        };
        return true;
    }());
    child!->layout(constraints, true);
    return child->size();
}

void MultiChildLayoutDelegateCls::positionChild(Object childId, Offset offset) {
    RenderBox child = _idToChild![childId];
    assert([=] () {
        if (child == nullptr) {
            throw make<FlutterErrorCls>(__s("The %sThere is no child with the id "$%s,"));
        }
        if (offset == nullptr) {
            throw make<FlutterErrorCls>(__s("The %s$%s,"));
        }
        return true;
    }());
    MultiChildLayoutParentData childParentData = as<MultiChildLayoutParentData>(child!->parentData!);
    childParentData->offset = offset;
}

Size MultiChildLayoutDelegateCls::getSize(BoxConstraints constraints) {
    return constraints->biggest();
}

String MultiChildLayoutDelegateCls::toString() {
    return objectRuntimeType(this, __s("MultiChildLayoutDelegate"));
}

DiagnosticsNode MultiChildLayoutDelegateCls::_debugDescribeChild(RenderBox child) {
    MultiChildLayoutParentData childParentData = as<MultiChildLayoutParentData>(child->parentData!);
    return <RenderBox>make<DiagnosticsPropertyCls>(__s("%s,"), child);
}

void MultiChildLayoutDelegateCls::_callPerformLayout(Size size, RenderBox firstChild) {
    Map<Object, RenderBox> previousIdToChild = _idToChild;
    Set<RenderBox> debugPreviousChildrenNeedingLayout;
    assert([=] () {
        debugPreviousChildrenNeedingLayout = _debugChildrenNeedingLayout;
        _debugChildrenNeedingLayout = makeSet();
        return true;
    }());
    try {
        _idToChild = makeMap(makeList(), makeList();
        RenderBox child = firstChild;
        while (child != nullptr) {
            MultiChildLayoutParentData childParentData = as<MultiChildLayoutParentData>(child->parentData!);
            assert([=] () {
                if (childParentData->id == nullptr) {
                    throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem));
                }
                return true;
            }());
            _idToChild![childParentData->id!] = child;
            assert([=] () {
                _debugChildrenNeedingLayout!->add(child!);
                return true;
            }());
            child = childParentData->nextSibling;
        }
        performLayout(size);
        assert([=] () {
            if (_debugChildrenNeedingLayout!->isNotEmpty()) {
                throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem));
            }
            return true;
        }());
    } finally {
        _idToChild = previousIdToChild;
        assert([=] () {
            _debugChildrenNeedingLayout = debugPreviousChildrenNeedingLayout;
            return true;
        }());
    };
}

RenderCustomMultiChildLayoutBoxCls::RenderCustomMultiChildLayoutBoxCls(List<RenderBox> children, MultiChildLayoutDelegate delegate) {
    {
        assert(delegate != nullptr);
        _delegate = delegate;
    }
    {
        addAll(children);
    }
}

void RenderCustomMultiChildLayoutBoxCls::setupParentData(RenderBox child) {
    if (!is<MultiChildLayoutParentData>(child->parentData)) {
        child->parentData = make<MultiChildLayoutParentDataCls>();
    }
}

MultiChildLayoutDelegate RenderCustomMultiChildLayoutBoxCls::delegate() {
    return _delegate;
}

void RenderCustomMultiChildLayoutBoxCls::delegate(MultiChildLayoutDelegate newDelegate) {
    assert(newDelegate != nullptr);
    if (_delegate == newDelegate) {
        return;
    }
    MultiChildLayoutDelegate oldDelegate = _delegate;
    if (newDelegate->runtimeType != oldDelegate->runtimeType || newDelegate->shouldRelayout(oldDelegate)) {
        markNeedsLayout();
    }
    _delegate = newDelegate;
    if (attached()) {
        oldDelegate->_relayout?->removeListener(markNeedsLayout);
        newDelegate->_relayout?->addListener(markNeedsLayout);
    }
}

void RenderCustomMultiChildLayoutBoxCls::attach(PipelineOwner owner) {
    super->attach(owner);
    _delegate->_relayout?->addListener(markNeedsLayout);
}

void RenderCustomMultiChildLayoutBoxCls::detach() {
    _delegate->_relayout?->removeListener(markNeedsLayout);
    super->detach();
}

double RenderCustomMultiChildLayoutBoxCls::computeMinIntrinsicWidth(double height) {
    double width = _getSize(BoxConstraintsCls->tightForFinite(height))->width();
    if (width->isFinite()) {
        return width;
    }
    return 0.0;
}

double RenderCustomMultiChildLayoutBoxCls::computeMaxIntrinsicWidth(double height) {
    double width = _getSize(BoxConstraintsCls->tightForFinite(height))->width();
    if (width->isFinite()) {
        return width;
    }
    return 0.0;
}

double RenderCustomMultiChildLayoutBoxCls::computeMinIntrinsicHeight(double width) {
    double height = _getSize(BoxConstraintsCls->tightForFinite(width))->height();
    if (height->isFinite()) {
        return height;
    }
    return 0.0;
}

double RenderCustomMultiChildLayoutBoxCls::computeMaxIntrinsicHeight(double width) {
    double height = _getSize(BoxConstraintsCls->tightForFinite(width))->height();
    if (height->isFinite()) {
        return height;
    }
    return 0.0;
}

Size RenderCustomMultiChildLayoutBoxCls::computeDryLayout(BoxConstraints constraints) {
    return _getSize(constraints);
}

void RenderCustomMultiChildLayoutBoxCls::performLayout() {
    size() = _getSize(constraints());
    delegate()->_callPerformLayout(size(), firstChild);
}

void RenderCustomMultiChildLayoutBoxCls::paint(PaintingContext context, Offset offset) {
    defaultPaint(context, offset);
}

bool RenderCustomMultiChildLayoutBoxCls::hitTestChildren(BoxHitTestResult result, Offset position) {
    return defaultHitTestChildren(result, position);
}

Size RenderCustomMultiChildLayoutBoxCls::_getSize(BoxConstraints constraints) {
    assert(constraints->debugAssertIsValid());
    return constraints->constrain(_delegate->getSize(constraints));
}
