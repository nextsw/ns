#include "box.hpp"
_DebugSizeCls::_DebugSizeCls(bool _canBeUsedByParent, RenderBox _owner, Unknown source) {
    {
        super->copy();
    }
}

BoxConstraintsCls::BoxConstraintsCls(double maxHeight, double maxWidth, double minHeight, double minWidth) {
    {
        assert(minWidth != nullptr);
        assert(maxWidth != nullptr);
        assert(minHeight != nullptr);
        assert(maxHeight != nullptr);
    }
}

void BoxConstraintsCls::tight(Size size)

void BoxConstraintsCls::tightFor(double height, double width)

void BoxConstraintsCls::tightForFinite(double height, double width)

void BoxConstraintsCls::loose(Size size)

void BoxConstraintsCls::expand(double height, double width)

BoxConstraints BoxConstraintsCls::copyWith(double maxHeight, double maxWidth, double minHeight, double minWidth) {
    return make<BoxConstraintsCls>(minWidth or this->minWidth, maxWidth or this->maxWidth, minHeight or this->minHeight, maxHeight or this->maxHeight);
}

BoxConstraints BoxConstraintsCls::deflate(EdgeInsets edges) {
    assert(edges != nullptr);
    assert(debugAssertIsValid());
    double horizontal = edges->horizontal;
    double vertical = edges->vertical;
    double deflatedMinWidth = math->max(0.0, minWidth - horizontal);
    double deflatedMinHeight = math->max(0.0, minHeight - vertical);
    return make<BoxConstraintsCls>(deflatedMinWidth, math->max(deflatedMinWidth, maxWidth - horizontal), deflatedMinHeight, math->max(deflatedMinHeight, maxHeight - vertical));
}

BoxConstraints BoxConstraintsCls::loosen() {
    assert(debugAssertIsValid());
    return make<BoxConstraintsCls>(maxWidth, maxHeight);
}

BoxConstraints BoxConstraintsCls::enforce(BoxConstraints constraints) {
    return make<BoxConstraintsCls>(clampDouble(minWidth, constraints->minWidth, constraints->maxWidth), clampDouble(maxWidth, constraints->minWidth, constraints->maxWidth), clampDouble(minHeight, constraints->minHeight, constraints->maxHeight), clampDouble(maxHeight, constraints->minHeight, constraints->maxHeight));
}

BoxConstraints BoxConstraintsCls::tighten(double height, double width) {
    return make<BoxConstraintsCls>(width == nullptr? minWidth : clampDouble(width, minWidth, maxWidth), width == nullptr? maxWidth : clampDouble(width, minWidth, maxWidth), height == nullptr? minHeight : clampDouble(height, minHeight, maxHeight), height == nullptr? maxHeight : clampDouble(height, minHeight, maxHeight));
}

BoxConstraints BoxConstraintsCls::flipped() {
    return make<BoxConstraintsCls>(minHeight, maxHeight, minWidth, maxWidth);
}

BoxConstraints BoxConstraintsCls::widthConstraints() {
    return make<BoxConstraintsCls>(minWidth, maxWidth);
}

BoxConstraints BoxConstraintsCls::heightConstraints() {
    return make<BoxConstraintsCls>(minHeight, maxHeight);
}

double BoxConstraintsCls::constrainWidth(double width) {
    assert(debugAssertIsValid());
    return clampDouble(width, minWidth, maxWidth);
}

double BoxConstraintsCls::constrainHeight(double height) {
    assert(debugAssertIsValid());
    return clampDouble(height, minHeight, maxHeight);
}

Size BoxConstraintsCls::constrain(Size size) {
    Size result = make<SizeCls>(constrainWidth(size->width()), constrainHeight(size->height()));
    assert([=] () {
        result = _debugPropagateDebugSize(size, result);
        return true;
    }());
    return result;
}

Size BoxConstraintsCls::constrainDimensions(double height, double width) {
    return make<SizeCls>(constrainWidth(width), constrainHeight(height));
}

Size BoxConstraintsCls::constrainSizeAndAttemptToPreserveAspectRatio(Size size) {
    if (isTight()) {
        Size result = smallest();
        assert([=] () {
            result = _debugPropagateDebugSize(size, result);
            return true;
        }());
        return result;
    }
    double width = size->width();
    double height = size->height();
    assert(width > 0.0);
    assert(height > 0.0);
    double aspectRatio = width / height;
    if (width > maxWidth) {
        width = maxWidth;
        height = width / aspectRatio;
    }
    if (height > maxHeight) {
        height = maxHeight;
        width = height * aspectRatio;
    }
    if ( < minWidth) {
        width = minWidth;
        height = width / aspectRatio;
    }
    if ( < minHeight) {
        height = minHeight;
        width = height * aspectRatio;
    }
    Size result = make<SizeCls>(constrainWidth(width), constrainHeight(height));
    assert([=] () {
        result = _debugPropagateDebugSize(size, result);
        return true;
    }());
    return result;
}

Size BoxConstraintsCls::biggest() {
    return make<SizeCls>(constrainWidth(), constrainHeight());
}

Size BoxConstraintsCls::smallest() {
    return make<SizeCls>(constrainWidth(0.0), constrainHeight(0.0));
}

bool BoxConstraintsCls::hasTightWidth() {
    return minWidth >= maxWidth;
}

bool BoxConstraintsCls::hasTightHeight() {
    return minHeight >= maxHeight;
}

bool BoxConstraintsCls::isTight() {
    return hasTightWidth() && hasTightHeight();
}

bool BoxConstraintsCls::hasBoundedWidth() {
    return  < double->infinity;
}

bool BoxConstraintsCls::hasBoundedHeight() {
    return  < double->infinity;
}

bool BoxConstraintsCls::hasInfiniteWidth() {
    return minWidth >= double->infinity;
}

bool BoxConstraintsCls::hasInfiniteHeight() {
    return minHeight >= double->infinity;
}

bool BoxConstraintsCls::isSatisfiedBy(Size size) {
    assert(debugAssertIsValid());
    return (minWidth <= size->width()) && (size->width() <= maxWidth) && (minHeight <= size->height()) && (size->height() <= maxHeight);
}

BoxConstraints BoxConstraintsCls::*(double factor) {
    return make<BoxConstraintsCls>(minWidth * factor, maxWidth * factor, minHeight * factor, maxHeight * factor);
}

BoxConstraints BoxConstraintsCls::/(double factor) {
    return make<BoxConstraintsCls>(minWidth / factor, maxWidth / factor, minHeight / factor, maxHeight / factor);
}

BoxConstraints BoxConstraintsCls::~/(double factor) {
    return make<BoxConstraintsCls>((minWidth ~/ factor)->toDouble(), (maxWidth ~/ factor)->toDouble(), (minHeight ~/ factor)->toDouble(), (maxHeight ~/ factor)->toDouble());
}

BoxConstraints BoxConstraintsCls::%(double value) {
    return make<BoxConstraintsCls>(minWidth % value, maxWidth % value, minHeight % value, maxHeight % value);
}

BoxConstraints BoxConstraintsCls::lerp(BoxConstraints a, BoxConstraints b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b! * t;
    }
    if (b == nullptr) {
        return a * (1.0 - t);
    }
    assert(a->debugAssertIsValid());
    assert(b->debugAssertIsValid());
    assert((a->minWidth->isFinite && b->minWidth->isFinite) || (a->minWidth == double->infinity && b->minWidth == double->infinity), __s("Cannot interpolate between finite constraints and unbounded constraints."));
    assert((a->maxWidth->isFinite && b->maxWidth->isFinite) || (a->maxWidth == double->infinity && b->maxWidth == double->infinity), __s("Cannot interpolate between finite constraints and unbounded constraints."));
    assert((a->minHeight->isFinite && b->minHeight->isFinite) || (a->minHeight == double->infinity && b->minHeight == double->infinity), __s("Cannot interpolate between finite constraints and unbounded constraints."));
    assert((a->maxHeight->isFinite && b->maxHeight->isFinite) || (a->maxHeight == double->infinity && b->maxHeight == double->infinity), __s("Cannot interpolate between finite constraints and unbounded constraints."));
    return make<BoxConstraintsCls>(a->minWidth->isFinite? ui->lerpDouble(a->minWidth, b->minWidth, t)! : double->infinity, a->maxWidth->isFinite? ui->lerpDouble(a->maxWidth, b->maxWidth, t)! : double->infinity, a->minHeight->isFinite? ui->lerpDouble(a->minHeight, b->minHeight, t)! : double->infinity, a->maxHeight->isFinite? ui->lerpDouble(a->maxHeight, b->maxHeight, t)! : double->infinity);
}

bool BoxConstraintsCls::isNormalized() {
    return minWidth >= 0.0 && minWidth <= maxWidth && minHeight >= 0.0 && minHeight <= maxHeight;
}

bool BoxConstraintsCls::debugAssertIsValid(InformationCollector informationCollector, bool isAppliedConstraint) {
    assert([=] () {
        InlineMethod;
        if (minWidth->isNaN || maxWidth->isNaN || minHeight->isNaN || maxHeight->isNaN) {
                    List<String> list1 = make<ListCls<>>();        if (minWidth->isNaN) {            list1.add(ArrayItem);        }if (maxWidth->isNaN) {            list1.add(ArrayItem);        }if (minHeight->isNaN) {            list1.add(ArrayItem);        }if (maxHeight->isNaN) {            list1.add(ArrayItem);        }List<String> affectedFieldsList = list1;
            assert(affectedFieldsList->isNotEmpty);
            if (affectedFieldsList->length() > 1) {
                affectedFieldsList->add(__s("and ${affectedFieldsList.removeLast()}"));
            }
            String whichFields = __s("");
            if (affectedFieldsList->length() > 2) {
                whichFields = affectedFieldsList->join(__s(", "));
            } else             {
                if (affectedFieldsList->length() == 2) {
                whichFields = affectedFieldsList->join(__s(" "));
            } else {
                whichFields = affectedFieldsList->single;
            }
;
            }            throwError(make<ErrorSummaryCls>(__s("BoxConstraints has ${affectedFieldsList.length == 1 ? 'a NaN value' : 'NaN values' } in $whichFields.")));
        }
        if ( < 0.0 &&  < 0.0) {
            throwError(make<ErrorSummaryCls>(__s("BoxConstraints has both a negative minimum width and a negative minimum height.")));
        }
        if ( < 0.0) {
            throwError(make<ErrorSummaryCls>(__s("BoxConstraints has a negative minimum width.")));
        }
        if ( < 0.0) {
            throwError(make<ErrorSummaryCls>(__s("BoxConstraints has a negative minimum height.")));
        }
        if ( < minWidth &&  < minHeight) {
            throwError(make<ErrorSummaryCls>(__s("BoxConstraints has both width and height constraints non-normalized.")));
        }
        if ( < minWidth) {
            throwError(make<ErrorSummaryCls>(__s("BoxConstraints has non-normalized width constraints.")));
        }
        if ( < minHeight) {
            throwError(make<ErrorSummaryCls>(__s("BoxConstraints has non-normalized height constraints.")));
        }
        if (isAppliedConstraint) {
            if (minWidth->isInfinite && minHeight->isInfinite) {
                throwError(make<ErrorSummaryCls>(__s("BoxConstraints forces an infinite width and infinite height.")));
            }
            if (minWidth->isInfinite) {
                throwError(make<ErrorSummaryCls>(__s("BoxConstraints forces an infinite width.")));
            }
            if (minHeight->isInfinite) {
                throwError(make<ErrorSummaryCls>(__s("BoxConstraints forces an infinite height.")));
            }
        }
        assert(isNormalized());
        return true;
    }());
    return isNormalized();
}

BoxConstraints BoxConstraintsCls::normalize() {
    if (isNormalized()) {
        return this;
    }
    double minWidth = this->minWidth >= 0.0? this->minWidth : 0.0;
    double minHeight = this->minHeight >= 0.0? this->minHeight : 0.0;
    return make<BoxConstraintsCls>(minWidth, minWidth > maxWidth? minWidth : maxWidth, minHeight, minHeight > maxHeight? minHeight : maxHeight);
}

bool BoxConstraintsCls::==(Object other) {
    assert(debugAssertIsValid());
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    assert(is<BoxConstraints>(other) && other->debugAssertIsValid());
    return is<BoxConstraints>(other) && other->minWidth == minWidth && other->maxWidth == maxWidth && other->minHeight == minHeight && other->maxHeight == maxHeight;
}

int BoxConstraintsCls::hashCode() {
    assert(debugAssertIsValid());
    return ObjectCls->hash(minWidth, maxWidth, minHeight, maxHeight);
}

String BoxConstraintsCls::toString() {
    String annotation = isNormalized()? __s("") : __s("; NOT NORMALIZED");
    if (minWidth == double->infinity && minHeight == double->infinity) {
        return __s("BoxConstraints(biggest$annotation)");
    }
    if (minWidth == 0 && maxWidth == double->infinity && minHeight == 0 && maxHeight == double->infinity) {
        return __s("BoxConstraints(unconstrained$annotation)");
    }
    InlineMethod;
    String width = describe(minWidth, maxWidth, __s("w"));
    String height = describe(minHeight, maxHeight, __s("h"));
    return __s("BoxConstraints($width, $height$annotation)");
}

Size BoxConstraintsCls::_debugPropagateDebugSize(Size result, Size size) {
    assert([=] () {
        if (is<_DebugSize>(size)) {
            result = make<_DebugSizeCls>(result, as<_DebugSizeCls>(size)->_owner, as<_DebugSizeCls>(size)->_canBeUsedByParent);
        }
        return true;
    }());
    return result;
}

BoxHitTestResultCls::BoxHitTestResultCls() : HitTestResult() {
}

void BoxHitTestResultCls::wrap(Unknown result)

bool BoxHitTestResultCls::addWithPaintTransform(BoxHitTest hitTest, Offset position, Matrix4 transform) {
    assert(position != nullptr);
    assert(hitTest != nullptr);
    if (transform != nullptr) {
        transform = Matrix4Cls->tryInvert(PointerEventCls->removePerspectiveTransform(transform));
        if (transform == nullptr) {
            return false;
        }
    }
    return addWithRawTransform(transform, position, hitTest);
}

bool BoxHitTestResultCls::addWithPaintOffset(BoxHitTest hitTest, Offset offset, Offset position) {
    assert(position != nullptr);
    assert(hitTest != nullptr);
    Offset transformedPosition = offset == nullptr? position : position - offset;
    if (offset != nullptr) {
        pushOffset(-offset);
    }
    bool isHit = hitTest(this, transformedPosition);
    if (offset != nullptr) {
        popTransform();
    }
    return isHit;
}

bool BoxHitTestResultCls::addWithRawTransform(BoxHitTest hitTest, Offset position, Matrix4 transform) {
    assert(position != nullptr);
    assert(hitTest != nullptr);
    assert(position != nullptr);
    Offset transformedPosition = transform == nullptr? position : MatrixUtilsCls->transformPoint(transform, position);
    if (transform != nullptr) {
        pushTransform(transform);
    }
    bool isHit = hitTest(this, transformedPosition);
    if (transform != nullptr) {
        popTransform();
    }
    return isHit;
}

bool BoxHitTestResultCls::addWithOutOfBandPosition(BoxHitTestWithOutOfBandPosition hitTest, Offset paintOffset, Matrix4 paintTransform, Matrix4 rawTransform) {
    assert(hitTest != nullptr);
    assert((paintOffset == nullptr && paintTransform == nullptr && rawTransform != nullptr) || (paintOffset == nullptr && paintTransform != nullptr && rawTransform == nullptr) || (paintOffset != nullptr && paintTransform == nullptr && rawTransform == nullptr), __s("Exactly one transform or offset argument must be provided."));
    if (paintOffset != nullptr) {
        pushOffset(-paintOffset);
    } else     {
        if (rawTransform != nullptr) {
        pushTransform(rawTransform);
    } else {
        assert(paintTransform != nullptr);
        paintTransform = Matrix4Cls->tryInvert(PointerEventCls->removePerspectiveTransform(paintTransform!));
        assert(paintTransform != nullptr, __s("paintTransform must be invertible."));
        pushTransform(paintTransform!);
    }
;
    }    bool isHit = hitTest(this);
    popTransform();
    return isHit;
}

BoxHitTestEntryCls::BoxHitTestEntryCls(Offset localPosition, Unknown target) {
    {
        assert(localPosition != nullptr);
    }
}

String BoxHitTestEntryCls::toString() {
    return __s("${describeIdentity(target)}@$localPosition");
}

String BoxParentDataCls::toString() {
    return __s("offset=$offset");
}

bool _IntrinsicDimensionsCacheEntryCls::==(Object other) {
    return is<_IntrinsicDimensionsCacheEntry>(other) && other->dimension == dimension && other->argument == argument;
}

int _IntrinsicDimensionsCacheEntryCls::hashCode() {
    return ObjectCls->hash(dimension, argument);
}

void RenderBoxCls::setupParentData(RenderObject child) {
    if (!is<BoxParentData>(child->parentData)) {
        child->parentData = make<BoxParentDataCls>();
    }
}

double RenderBoxCls::getMinIntrinsicWidth(double height) {
    assert([=] () {
        if (height == nullptr) {
            ;
        }
        if ( < 0.0) {
            ;
        }
        return true;
    }());
    return _computeIntrinsicDimension(_IntrinsicDimensionCls::minWidth, height, computeMinIntrinsicWidth);
}

double RenderBoxCls::computeMinIntrinsicWidth(double height) {
    return 0.0;
}

double RenderBoxCls::getMaxIntrinsicWidth(double height) {
    assert([=] () {
        if (height == nullptr) {
            ;
        }
        if ( < 0.0) {
            ;
        }
        return true;
    }());
    return _computeIntrinsicDimension(_IntrinsicDimensionCls::maxWidth, height, computeMaxIntrinsicWidth);
}

double RenderBoxCls::computeMaxIntrinsicWidth(double height) {
    return 0.0;
}

double RenderBoxCls::getMinIntrinsicHeight(double width) {
    assert([=] () {
        if (width == nullptr) {
            ;
        }
        if ( < 0.0) {
            ;
        }
        return true;
    }());
    return _computeIntrinsicDimension(_IntrinsicDimensionCls::minHeight, width, computeMinIntrinsicHeight);
}

double RenderBoxCls::computeMinIntrinsicHeight(double width) {
    return 0.0;
}

double RenderBoxCls::getMaxIntrinsicHeight(double width) {
    assert([=] () {
        if (width == nullptr) {
            ;
        }
        if ( < 0.0) {
            ;
        }
        return true;
    }());
    return _computeIntrinsicDimension(_IntrinsicDimensionCls::maxHeight, width, computeMaxIntrinsicHeight);
}

double RenderBoxCls::computeMaxIntrinsicHeight(double width) {
    return 0.0;
}

Size RenderBoxCls::getDryLayout(BoxConstraints constraints) {
    bool shouldCache = true;
    assert([=] () {
        if (RenderObjectCls::debugCheckingIntrinsics) {
            shouldCache = false;
        }
        return true;
    }());
    if (shouldCache) {
        Map<String, String> debugTimelineArguments;
        assert([=] () {
            if (debugEnhanceLayoutTimelineArguments) {
                debugTimelineArguments = toDiagnosticsNode()->toTimelineArguments();
            } else {
                debugTimelineArguments = makeMap(makeList(), makeList();
            }
            debugTimelineArguments![__s("getDryLayout constraints")] = __s("$constraints");
            return true;
        }());
        if (!kReleaseMode) {
            if (debugProfileLayoutsEnabled || _debugIntrinsicsDepth == 0) {
                TimelineCls->startSync(__s("$runtimeType.getDryLayout")debugTimelineArguments);
            }
            _debugIntrinsicsDepth = 1;
        }
        _cachedDryLayoutSizes = makeMap(makeList(), makeList();
        Size result = _cachedDryLayoutSizes!->putIfAbsent(constraints, [=] () {
    _computeDryLayout(constraints);
});
        if (!kReleaseMode) {
            _debugIntrinsicsDepth = 1;
            if (debugProfileLayoutsEnabled || _debugIntrinsicsDepth == 0) {
                TimelineCls->finishSync();
            }
        }
        return result;
    }
    return _computeDryLayout(constraints);
}

Size RenderBoxCls::computeDryLayout(BoxConstraints constraints) {
    assert(debugCannotComputeDryLayout(FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem))));
    return SizeCls::zero;
}

bool RenderBoxCls::debugCannotComputeDryLayout(FlutterError error, String reason) {
    assert((reason == nullptr) != (error == nullptr));
    assert([=] () {
        if (!RenderObjectCls->debugCheckingIntrinsics) {
            if (reason != nullptr) {
                assert(error == nullptr);
                ;
            }
            assert(error != nullptr);
            ;
        }
        _dryLayoutCalculationValid = false;
        return true;
    }());
    return true;
}

bool RenderBoxCls::hasSize() {
    return _size != nullptr;
}

Size RenderBoxCls::size() {
    assert(hasSize(), __s("RenderBox was not laid out: $this"));
    assert([=] () {
        Size size = _size;
        if (is<_DebugSize>(size)) {
            assert(as<_DebugSizeCls>(size)->_owner == this);
            if (RenderObjectCls::debugActiveLayout != nullptr && !RenderObjectCls->debugActiveLayout!->debugDoingThisLayoutWithCallback) {
                assert(debugDoingThisResize || debugDoingThisLayout || _computingThisDryLayout || (RenderObjectCls::debugActiveLayout == parent && size->_canBeUsedByParent), __s("RenderBox.size accessed beyond the scope of resize, layout, or permitted parent access. RenderBox can always access its own size, otherwise, the only object that is allowed to read RenderBox.size is its parent, if they have said they will. It you hit this assert trying to access a child\'s size, pass "parentUsesSize: true" to that child's layout()."));
            }
            assert(as<_DebugSizeCls>(size) == _size);
        }
        return true;
    }());
    return _size!;
}

void RenderBoxCls::size(Size value) {
    assert(!(debugDoingThisResize && debugDoingThisLayout));
    assert(sizedByParent || !debugDoingThisResize);
    assert([=] () {
        if ((sizedByParent && debugDoingThisResize) || (!sizedByParent && debugDoingThisLayout)) {
            return true;
        }
        assert(!debugDoingThisResize);
        List<DiagnosticsNode> information = makeList(ArrayItem);
        if (debugDoingThisLayout) {
            assert(sizedByParent);
            information->add(make<ErrorDescriptionCls>(__s("It appears that the size setter was called from performLayout().")));
        } else {
            information->add(make<ErrorDescriptionCls>(__s("The size setter was called from outside layout (neither performResize() nor performLayout() were being run for this object).")));
            if (owner != nullptr && owner!->debugDoingLayout) {
                information->add(make<ErrorDescriptionCls>(__s("Only the object itself can set its size. It is a contract violation for other objects to set it.")));
            }
        }
        if (sizedByParent) {
            information->add(make<ErrorDescriptionCls>(__s("Because this RenderBox has sizedByParent set to true, it must set its size in performResize().")));
        } else {
            information->add(make<ErrorDescriptionCls>(__s("Because this RenderBox has sizedByParent set to false, it must set its size in performLayout().")));
        }
        ;
    }());
    assert([=] () {
        value = debugAdoptSize(value);
        return true;
    }());
    _size = value;
    assert([=] () {
        debugAssertDoesMeetConstraints();
        return true;
    }());
}

Size RenderBoxCls::debugAdoptSize(Size value) {
    Size result = value;
    assert([=] () {
        if (is<_DebugSize>(value)) {
            if (as<_DebugSizeCls>(value)->_owner != this) {
                if (value->_owner->parent != this) {
                    ;
                }
                if (!value->_canBeUsedByParent) {
                    ;
                }
            }
        }
        result = make<_DebugSizeCls>(value, this, debugCanParentUseSize);
        return true;
    }());
    return result;
}

Rect RenderBoxCls::semanticBounds() {
    return OffsetCls::zero & size();
}

void RenderBoxCls::debugResetSize() {
    size() = size();
}

double RenderBoxCls::getDistanceToBaseline(TextBaseline baseline, bool onlyReal) {
    assert(!_debugDoingBaseline, __s("Please see the documentation for computeDistanceToActualBaseline for the required calling conventions of this method."));
    assert(!debugNeedsLayout);
    assert([=] () {
        RenderObject parent = as<RenderObject>(this->parent);
        if (owner!->debugDoingLayout) {
            return (RenderObjectCls::debugActiveLayout == parent) && parent!->debugDoingThisLayout();
        }
        if (owner!->debugDoingPaint) {
            return ((RenderObjectCls::debugActivePaint == parent) && parent!->debugDoingThisPaint()) || ((RenderObjectCls::debugActivePaint == this) && debugDoingThisPaint);
        }
        assert(parent == this->parent);
        return false;
    }());
    assert(_debugSetDoingBaseline(true));
    double result = getDistanceToActualBaseline(baseline);
    assert(_debugSetDoingBaseline(false));
    if (result == nullptr && !onlyReal) {
        return size()->height();
    }
    return result;
}

double RenderBoxCls::getDistanceToActualBaseline(TextBaseline baseline) {
    assert(_debugDoingBaseline, __s("Please see the documentation for computeDistanceToActualBaseline for the required calling conventions of this method."));
    _cachedBaselines = makeMap(makeList(), makeList();
    _cachedBaselines!->putIfAbsent(baseline, [=] ()     {
        computeDistanceToActualBaseline(baseline);
    });
    return _cachedBaselines![baseline];
}

double RenderBoxCls::computeDistanceToActualBaseline(TextBaseline baseline) {
    assert(_debugDoingBaseline, __s("Please see the documentation for computeDistanceToActualBaseline for the required calling conventions of this method."));
    return nullptr;
}

BoxConstraints RenderBoxCls::constraints() {
    return as<BoxConstraints>(super->constraints);
}

void RenderBoxCls::debugAssertDoesMeetConstraints() {
    assert(constraints() != nullptr);
    assert([=] () {
        if (!hasSize()) {
            DiagnosticsNode contract;
            if (sizedByParent) {
                contract = make<ErrorDescriptionCls>(__s("Because this RenderBox has sizedByParent set to true, it must set its size in performResize()."));
            } else {
                contract = make<ErrorDescriptionCls>(__s("Because this RenderBox has sizedByParent set to false, it must set its size in performLayout()."));
            }
            ;
        }
        if (!_size!->isFinite) {
            List<DiagnosticsNode> information = makeList(ArrayItem, ArrayItem);
            if (!constraints()->hasBoundedWidth()) {
                RenderBox node = this;
                while (!node->constraints()->hasBoundedWidth() && is<RenderBox>(node->parent)) {
                    node = as<RenderBox>(node->parent!);
                }
                information->add(node->describeForError(__s("The nearest ancestor providing an unbounded width constraint is")));
            }
            if (!constraints()->hasBoundedHeight()) {
                RenderBox node = this;
                while (!node->constraints()->hasBoundedHeight() && is<RenderBox>(node->parent)) {
                    node = as<RenderBox>(node->parent!);
                }
                information->add(node->describeForError(__s("The nearest ancestor providing an unbounded height constraint is")));
            }
            ;
        }
        if (!constraints()->isSatisfiedBy(_size!)) {
            ;
        }
        if (debugCheckIntrinsicSizes) {
            assert(!RenderObjectCls->debugCheckingIntrinsics);
            RenderObjectCls::debugCheckingIntrinsics = true;
            List<DiagnosticsNode> failures = makeList();
            InlineMethod;
            InlineMethod;
            testIntrinsicsForValues(getMinIntrinsicWidth, getMaxIntrinsicWidth, __s("Width"), double->infinity);
            testIntrinsicsForValues(getMinIntrinsicHeight, getMaxIntrinsicHeight, __s("Height"), double->infinity);
            if (constraints()->hasBoundedWidth()) {
                testIntrinsicsForValues(getMinIntrinsicWidth, getMaxIntrinsicWidth, __s("Width"), constraints()->maxHeight);
            }
            if (constraints()->hasBoundedHeight()) {
                testIntrinsicsForValues(getMinIntrinsicHeight, getMaxIntrinsicHeight, __s("Height"), constraints()->maxWidth);
            }
            RenderObjectCls::debugCheckingIntrinsics = false;
            if (failures->isNotEmpty) {
                ;
            }
            _dryLayoutCalculationValid = true;
            RenderObjectCls::debugCheckingIntrinsics = true;
            Size dryLayoutSize;
            try {
                dryLayoutSize = getDryLayout(constraints());
            } finally {
                RenderObjectCls::debugCheckingIntrinsics = false;
            };
            if (_dryLayoutCalculationValid && dryLayoutSize != size()) {
                ;
            }
        }
        return true;
    }());
}

void RenderBoxCls::markNeedsLayout() {
    if (_clearCachedData() && is<RenderObject>(parent)) {
        markParentNeedsLayout();
        return;
    }
    super->markNeedsLayout();
}

void RenderBoxCls::layout(Constraints constraints, bool parentUsesSize) {
    if (hasSize() && constraints != this->constraints && _cachedBaselines != nullptr && _cachedBaselines!->isNotEmpty()) {
        _cachedBaselines?->clear();
    }
    super->layout(constraintsparentUsesSize);
}

void RenderBoxCls::performResize() {
    size() = computeDryLayout(constraints());
    assert(size()->isFinite);
}

void RenderBoxCls::performLayout() {
    assert([=] () {
        if (!sizedByParent) {
            ;
        }
        return true;
    }());
}

bool RenderBoxCls::hitTest(Offset position, BoxHitTestResult result) {
    assert([=] () {
        if (!hasSize()) {
            if (debugNeedsLayout) {
                ;
            }
            ;
        }
        return true;
    }());
    if (_size!->contains(position)) {
        if (hitTestChildren(resultposition) || hitTestSelf(position)) {
            result->add(make<BoxHitTestEntryCls>(this, position));
            return true;
        }
    }
    return false;
}

bool RenderBoxCls::hitTestSelf(Offset position) {
    return false;
}

bool RenderBoxCls::hitTestChildren(Offset position, BoxHitTestResult result) {
    return false;
}

void RenderBoxCls::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(child != nullptr);
    assert(child->parent == this);
    assert([=] () {
        if (!is<BoxParentData>(child->parentData)) {
            ;
        }
        return true;
    }());
    BoxParentData childParentData = as<BoxParentData>(child->parentData!);
    Offset offset = childParentData->offset;
    transform->translate(offset->dx(), offset->dy());
}

Offset RenderBoxCls::globalToLocal(RenderObject ancestor, Offset point) {
    Matrix4 transform = getTransformTo(ancestor);
    double det = transform->invert();
    if (det == 0.0) {
        return OffsetCls::zero;
    }
    Vector3 n = make<Vector3Cls>(0.0, 0.0, 1.0);
    Vector3 i = transform->perspectiveTransform(make<Vector3Cls>(0.0, 0.0, 0.0));
    Vector3 d = transform->perspectiveTransform(make<Vector3Cls>(0.0, 0.0, 1.0)) - i;
    Vector3 s = transform->perspectiveTransform(make<Vector3Cls>(point->dx(), point->dy(), 0.0));
    Vector3 p = s - d * (n->dot(s) / n->dot(d));
    return make<OffsetCls>(p->x, p->y);
}

Offset RenderBoxCls::localToGlobal(RenderObject ancestor, Offset point) {
    return MatrixUtilsCls->transformPoint(getTransformTo(ancestor), point);
}

Rect RenderBoxCls::paintBounds() {
    return OffsetCls::zero & size();
}

void RenderBoxCls::handleEvent(BoxHitTestEntry entry, PointerEvent event) {
    super->handleEvent(event, entry);
}

bool RenderBoxCls::debugHandleEvent(HitTestEntry entry, PointerEvent event) {
    assert([=] () {
        if (debugPaintPointersEnabled) {
            if (is<PointerDownEvent>(event)) {
                _debugActivePointers = 1;
            } else             {
                if (is<PointerUpEvent>(event) || is<PointerCancelEvent>(event)) {
                _debugActivePointers = 1;
            }
;
            }            markNeedsPaint();
        }
        return true;
    }());
    return true;
}

void RenderBoxCls::debugPaint(PaintingContext context, Offset offset) {
    assert([=] () {
        if (debugPaintSizeEnabled) {
            debugPaintSize(context, offset);
        }
        if (debugPaintBaselinesEnabled) {
            debugPaintBaselines(context, offset);
        }
        if (debugPaintPointersEnabled) {
            debugPaintPointers(context, offset);
        }
        return true;
    }());
}

void RenderBoxCls::debugPaintSize(PaintingContext context, Offset offset) {
    assert([=] () {
            auto _c1 = make<PaintCls>();    _c1.style = auto _c2 = PaintingStyleCls::stroke;    _c2.strokeWidth = auto _c3 = 1.0;    _c3.color = make<ColorCls>(0xFF00FFFF);    _c3;    _c2;Paint paint = _c1;
        context->canvas()->drawRect((offset & size())->deflate(0.5), paint);
        return true;
    }());
}

void RenderBoxCls::debugPaintBaselines(PaintingContext context, Offset offset) {
    assert([=] () {
            auto _c1 = make<PaintCls>();    _c1.style = auto _c2 = PaintingStyleCls::stroke;    _c2.strokeWidth = 0.25;    _c2;Paint paint = _c1;
        Path path;
        double baselineI = getDistanceToBaseline(TextBaselineCls::ideographictrue);
        if (baselineI != nullptr) {
            paint->color() = make<ColorCls>(0xFFFFD000);
            path = make<PathCls>();
            path->moveTo(offset->dx(), offset->dy() + baselineI);
            path->lineTo(offset->dx() + size()->width(), offset->dy() + baselineI);
            context->canvas()->drawPath(path, paint);
        }
        double baselineA = getDistanceToBaseline(TextBaselineCls::alphabetictrue);
        if (baselineA != nullptr) {
            paint->color() = make<ColorCls>(0xFF00FF00);
            path = make<PathCls>();
            path->moveTo(offset->dx(), offset->dy() + baselineA);
            path->lineTo(offset->dx() + size()->width(), offset->dy() + baselineA);
            context->canvas()->drawPath(path, paint);
        }
        return true;
    }());
}

void RenderBoxCls::debugPaintPointers(PaintingContext context, Offset offset) {
    assert([=] () {
        if (_debugActivePointers > 0) {
                    auto _c1 = make<PaintCls>();        _c1.color = make<ColorCls>(0x00BBBB | ((0x04000000 * depth) & 0xFF000000));Paint paint = _c1;
            context->canvas()->drawRect(offset & size(), paint);
        }
        return true;
    }());
}

void RenderBoxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Size>make<DiagnosticsPropertyCls>(__s("size"), _sizetrue));
}

double RenderBoxCls::_computeIntrinsicDimension(double argument, double computer(double argument) , _IntrinsicDimension dimension) {
    assert(RenderObjectCls::debugCheckingIntrinsics || !debugDoingThisResize);
    bool shouldCache = true;
    assert([=] () {
        if (RenderObjectCls::debugCheckingIntrinsics) {
            shouldCache = false;
        }
        return true;
    }());
    if (shouldCache) {
        Map<String, String> debugTimelineArguments;
        assert([=] () {
            if (debugEnhanceLayoutTimelineArguments) {
                debugTimelineArguments = toDiagnosticsNode()->toTimelineArguments();
            } else {
                debugTimelineArguments = makeMap(makeList(), makeList();
            }
            debugTimelineArguments![__s("intrinsics dimension")] = describeEnum(dimension);
            debugTimelineArguments![__s("intrinsics argument")] = __s("$argument");
            return true;
        }());
        if (!kReleaseMode) {
            if (debugProfileLayoutsEnabled || _debugIntrinsicsDepth == 0) {
                TimelineCls->startSync(__s("$runtimeType intrinsics")debugTimelineArguments);
            }
            _debugIntrinsicsDepth = 1;
        }
        _cachedIntrinsicDimensions = makeMap(makeList(), makeList();
        double result = _cachedIntrinsicDimensions!->putIfAbsent(make<_IntrinsicDimensionsCacheEntryCls>(dimension, argument), [=] () {
    computer(argument);
});
        if (!kReleaseMode) {
            _debugIntrinsicsDepth = 1;
            if (debugProfileLayoutsEnabled || _debugIntrinsicsDepth == 0) {
                TimelineCls->finishSync();
            }
        }
        return result;
    }
    return computer(argument);
}

Size RenderBoxCls::_computeDryLayout(BoxConstraints constraints) {
    assert([=] () {
        assert(!_computingThisDryLayout);
        _computingThisDryLayout = true;
        return true;
    }());
    Size result = computeDryLayout(constraints);
    assert([=] () {
        assert(_computingThisDryLayout);
        _computingThisDryLayout = false;
        return true;
    }());
    return result;
}

bool RenderBoxCls::_debugSetDoingBaseline(bool value) {
    _debugDoingBaseline = value;
    return true;
}

bool RenderBoxCls::_clearCachedData() {
    if ((_cachedBaselines != nullptr && _cachedBaselines!->isNotEmpty()) || (_cachedIntrinsicDimensions != nullptr && _cachedIntrinsicDimensions!->isNotEmpty()) || (_cachedDryLayoutSizes != nullptr && _cachedDryLayoutSizes!->isNotEmpty())) {
        _cachedBaselines?->clear();
        _cachedIntrinsicDimensions?->clear();
        _cachedDryLayoutSizes?->clear();
        return true;
    }
    return false;
}

template<typename ChildType, typename ParentDataType> double RenderBoxContainerDefaultsMixinCls<ChildType, ParentDataType>::defaultComputeDistanceToFirstActualBaseline(TextBaseline baseline) {
    assert(!debugNeedsLayout);
    ChildType child = firstChild;
    while (child != nullptr) {
        ParentDataType childParentData = as<ParentDataType>(child->parentData);
        double result = child->getDistanceToActualBaseline(baseline);
        if (result != nullptr) {
            return result + childParentData!->offset->dy;
        }
        child = childParentData!->nextSibling;
    }
    return nullptr;
}

template<typename ChildType, typename ParentDataType> double RenderBoxContainerDefaultsMixinCls<ChildType, ParentDataType>::defaultComputeDistanceToHighestActualBaseline(TextBaseline baseline) {
    assert(!debugNeedsLayout);
    double result;
    ChildType child = firstChild;
    while (child != nullptr) {
        ParentDataType childParentData = as<ParentDataType>(child->parentData!);
        double candidate = child->getDistanceToActualBaseline(baseline);
        if (candidate != nullptr) {
            candidate = childParentData->offset->dy;
            if (result != nullptr) {
                result = math->min(result, candidate);
            } else {
                result = candidate;
            }
        }
        child = childParentData->nextSibling;
    }
    return result;
}

template<typename ChildType, typename ParentDataType> bool RenderBoxContainerDefaultsMixinCls<ChildType, ParentDataType>::defaultHitTestChildren(Offset position, BoxHitTestResult result) {
    ChildType child = lastChild;
    while (child != nullptr) {
        ParentDataType childParentData = as<ParentDataType>(child->parentData!);
        bool isHit = result->addWithPaintOffset(childParentData->offset, position, [=] (BoxHitTestResult result,Offset transformed) {
    assert(transformed == position - childParentData->offset);
    return child!->hitTest(resulttransformed);
});
        if (isHit) {
            return true;
        }
        child = childParentData->previousSibling;
    }
    return false;
}

template<typename ChildType, typename ParentDataType> void RenderBoxContainerDefaultsMixinCls<ChildType, ParentDataType>::defaultPaint(PaintingContext context, Offset offset) {
    ChildType child = firstChild;
    while (child != nullptr) {
        ParentDataType childParentData = as<ParentDataType>(child->parentData!);
        context->paintChild(child, childParentData->offset + offset);
        child = childParentData->nextSibling;
    }
}

template<typename ChildType, typename ParentDataType> List<ChildType> RenderBoxContainerDefaultsMixinCls<ChildType, ParentDataType>::getChildrenAsList() {
    List<ChildType> result = makeList();
    RenderBox child = firstChild;
    while (child != nullptr) {
        ParentDataType childParentData = as<ParentDataType>(child->parentData!);
        result->add(as<ChildType>(child));
        child = childParentData->nextSibling;
    }
    return result;
}
