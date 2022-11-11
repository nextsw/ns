#include "sliver.hpp"
AxisDirection applyGrowthDirectionToAxisDirection(AxisDirection axisDirection, GrowthDirection growthDirection) {
    assert(axisDirection != nullptr);
    assert(growthDirection != nullptr);
    ;
}

ScrollDirection applyGrowthDirectionToScrollDirection(ScrollDirection scrollDirection, GrowthDirection growthDirection) {
    assert(scrollDirection != nullptr);
    assert(growthDirection != nullptr);
    ;
}

SliverConstraintsCls::SliverConstraintsCls(AxisDirection axisDirection, double cacheOrigin, AxisDirection crossAxisDirection, double crossAxisExtent, GrowthDirection growthDirection, double overlap, double precedingScrollExtent, double remainingCacheExtent, double remainingPaintExtent, double scrollOffset, ScrollDirection userScrollDirection, double viewportMainAxisExtent) {
    {
        assert(axisDirection != nullptr);
        assert(growthDirection != nullptr);
        assert(userScrollDirection != nullptr);
        assert(scrollOffset != nullptr);
        assert(precedingScrollExtent != nullptr);
        assert(overlap != nullptr);
        assert(remainingPaintExtent != nullptr);
        assert(crossAxisExtent != nullptr);
        assert(crossAxisDirection != nullptr);
        assert(viewportMainAxisExtent != nullptr);
        assert(remainingCacheExtent != nullptr);
        assert(cacheOrigin != nullptr);
    }
}

SliverConstraints SliverConstraintsCls::copyWith(AxisDirection axisDirection, double cacheOrigin, AxisDirection crossAxisDirection, double crossAxisExtent, GrowthDirection growthDirection, double overlap, double precedingScrollExtent, double remainingCacheExtent, double remainingPaintExtent, double scrollOffset, ScrollDirection userScrollDirection, double viewportMainAxisExtent) {
    return make<SliverConstraintsCls>(axisDirection | this->axisDirection, growthDirection | this->growthDirection, userScrollDirection | this->userScrollDirection, scrollOffset | this->scrollOffset, precedingScrollExtent | this->precedingScrollExtent, overlap | this->overlap, remainingPaintExtent | this->remainingPaintExtent, crossAxisExtent | this->crossAxisExtent, crossAxisDirection | this->crossAxisDirection, viewportMainAxisExtent | this->viewportMainAxisExtent, remainingCacheExtent | this->remainingCacheExtent, cacheOrigin | this->cacheOrigin);
}

Axis SliverConstraintsCls::axis() {
    return axisDirectionToAxis(axisDirection);
}

GrowthDirection SliverConstraintsCls::normalizedGrowthDirection() {
    assert(axisDirection != nullptr);
    ;
}

bool SliverConstraintsCls::isTight() {
    return false;
}

bool SliverConstraintsCls::isNormalized() {
    return scrollOffset >= 0.0 && crossAxisExtent >= 0.0 && axisDirectionToAxis(axisDirection) != axisDirectionToAxis(crossAxisDirection) && viewportMainAxisExtent >= 0.0 && remainingPaintExtent >= 0.0;
}

BoxConstraints SliverConstraintsCls::asBoxConstraints(double crossAxisExtent, double maxExtent, double minExtent) {
    crossAxisExtent |= this->crossAxisExtent;
    ;
}

bool SliverConstraintsCls::debugAssertIsValid(InformationCollector informationCollector, bool isAppliedConstraint) {
    assert([=] () {
        bool hasErrors = false;
        StringBuffer errorMessage = make<StringBufferCls>(__s("\n"));
        InlineMethod;
        InlineMethod;
        verify(axis() != nullptr, __s("The "axis" is null."));
        verify(growthDirection != nullptr, __s("The "growthDirection" is null."));
        verifyDouble(scrollOffset, __s("scrollOffset"));
        verifyDouble(overlap, __s("overlap"));
        verifyDouble(crossAxisExtent, __s("crossAxisExtent"));
        verifyDouble(scrollOffset, __s("scrollOffset"), true);
        verify(crossAxisDirection != nullptr, __s("The "crossAxisDirection" is null."));
        verify(axisDirectionToAxis(axisDirection) != axisDirectionToAxis(crossAxisDirection), __s("The "axisDirection" and the "crossAxisDirection" are along the same axis."));
        verifyDouble(viewportMainAxisExtent, __s("viewportMainAxisExtent"), true);
        verifyDouble(remainingPaintExtent, __s("remainingPaintExtent"), true);
        verifyDouble(remainingCacheExtent, __s("remainingCacheExtent"), true);
        verifyDouble(cacheOrigin, __s("cacheOrigin"), true);
        verifyDouble(precedingScrollExtent, __s("precedingScrollExtent"), true);
        verify(isNormalized(), __s("The constraints are not normalized."));
        if (hasErrors) {
                    List<DiagnosticsNode> list1 = make<ListCls<>>();        list1.add(ArrayItem);        if (informationCollector != nullptr) {            list1.add(ArrayItem);        }list1.add(ArrayItem);throw FlutterErrorCls->fromParts(list1);
        }
        return true;
    }());
    return true;
}

bool SliverConstraintsCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (!is<SliverConstraints>(other)) {
        return false;
    }
    assert(other->debugAssertIsValid());
    return other->axisDirection == axisDirection && other->growthDirection == growthDirection && other->scrollOffset == scrollOffset && other->overlap == overlap && other->remainingPaintExtent == remainingPaintExtent && other->crossAxisExtent == crossAxisExtent && other->crossAxisDirection == crossAxisDirection && other->viewportMainAxisExtent == viewportMainAxisExtent && other->remainingCacheExtent == remainingCacheExtent && other->cacheOrigin == cacheOrigin;
}

int SliverConstraintsCls::hashCode() {
    return ObjectCls->hash(axisDirection, growthDirection, scrollOffset, overlap, remainingPaintExtent, crossAxisExtent, crossAxisDirection, viewportMainAxisExtent, remainingCacheExtent, cacheOrigin);
}

String SliverConstraintsCls::toString() {
    List<String> list1 = make<ListCls<>>();list1.add(ArrayItem);list1.add(ArrayItem);list1.add(ArrayItem);list1.add(ArrayItem);list1.add(ArrayItem);if (overlap != 0.0) {    list1.add(ArrayItem);}list1.add(ArrayItem);list1.add(ArrayItem);list1.add(ArrayItem);list1.add(ArrayItem);list1.add(ArrayItem);List<String> properties = list1;
    return __s("SliverConstraints(${properties.join(', ')})");
}

SliverGeometryCls::SliverGeometryCls(double cacheExtent, bool hasVisualOverflow, double hitTestExtent, double layoutExtent, double maxPaintExtent, double maxScrollObstructionExtent, double paintExtent, double paintOrigin, double scrollExtent, double scrollOffsetCorrection, bool visible) {
    {
        assert(scrollExtent != nullptr);
        assert(paintExtent != nullptr);
        assert(paintOrigin != nullptr);
        assert(maxPaintExtent != nullptr);
        assert(hasVisualOverflow != nullptr);
        assert(scrollOffsetCorrection != 0.0);
        layoutExtent = layoutExtent | paintExtent;
        hitTestExtent = hitTestExtent | paintExtent;
        cacheExtent = cacheExtent | layoutExtent | paintExtent;
        visible = visible | paintExtent > 0.0;
    }
}

bool SliverGeometryCls::debugAssertIsValid(InformationCollector informationCollector) {
    assert([=] () {
        InlineMethod;
        verify(scrollExtent != nullptr, __s("The "scrollExtent" is null."));
        verify(scrollExtent >= 0.0, __s("The "scrollExtent" is negative."));
        verify(paintExtent != nullptr, __s("The "paintExtent" is null."));
        verify(paintExtent >= 0.0, __s("The "paintExtent" is negative."));
        verify(paintOrigin != nullptr, __s("The "paintOrigin" is null."));
        verify(layoutExtent != nullptr, __s("The "layoutExtent" is null."));
        verify(layoutExtent >= 0.0, __s("The "layoutExtent" is negative."));
        verify(cacheExtent >= 0.0, __s("The "cacheExtent" is negative."));
        if (layoutExtent > paintExtent) {
            verify(false, __s("The "layoutExtent" exceeds the "paintExtent"."), _debugCompareFloats(__s("paintExtent"), paintExtent, __s("layoutExtent"), layoutExtent));
        }
        verify(maxPaintExtent != nullptr, __s("The "maxPaintExtent" is null."));
        if (paintExtent - maxPaintExtent > precisionErrorTolerance) {
                    auto _c1 = _debugCompareFloats(__s("maxPaintExtent"), maxPaintExtent, __s("paintExtent"), paintExtent);        _c1.add(make<ErrorDescriptionCls>(__s("By definition, a sliver can't paint more than the maximum that it can paint!")));verify(false, __s("The "maxPaintExtent" is less than the "paintExtent"."), _c1);
        }
        verify(hitTestExtent != nullptr, __s("The "hitTestExtent" is null."));
        verify(hitTestExtent >= 0.0, __s("The "hitTestExtent" is negative."));
        verify(visible != nullptr, __s("The "visible" property is null."));
        verify(hasVisualOverflow != nullptr, __s("The "hasVisualOverflow" is null."));
        verify(scrollOffsetCorrection != 0.0, __s("The "scrollOffsetCorrection" is zero."));
        return true;
    }());
    return true;
}

String SliverGeometryCls::toStringShort() {
    return objectRuntimeType(this, __s("SliverGeometry"));
}

void SliverGeometryCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("scrollExtent"), scrollExtent));
    if (paintExtent > 0.0) {
        properties->add(make<DoublePropertyCls>(__s("paintExtent"), paintExtent, visible? nullptr : __s(" but not painting")));
    } else {
        if (paintExtent == 0.0) {
        if (visible) {
            properties->add(make<DoublePropertyCls>(__s("paintExtent"), paintExtent, visible? nullptr : __s(" but visible")));
        }
        properties->add(make<FlagPropertyCls>(__s("visible"), visible, __s("hidden")));
    } else {
        properties->add(make<DoublePropertyCls>(__s("paintExtent"), paintExtent, __s("!")));
    }
;
    }    properties->add(make<DoublePropertyCls>(__s("paintOrigin"), paintOrigin, 0.0));
    properties->add(make<DoublePropertyCls>(__s("layoutExtent"), layoutExtent, paintExtent));
    properties->add(make<DoublePropertyCls>(__s("maxPaintExtent"), maxPaintExtent));
    properties->add(make<DoublePropertyCls>(__s("hitTestExtent"), hitTestExtent, paintExtent));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("hasVisualOverflow"), hasVisualOverflow, false));
    properties->add(make<DoublePropertyCls>(__s("scrollOffsetCorrection"), scrollOffsetCorrection, nullptr));
    properties->add(make<DoublePropertyCls>(__s("cacheExtent"), cacheExtent, 0.0));
}

SliverHitTestResultCls::SliverHitTestResultCls() : HitTestResult() {
}

void SliverHitTestResultCls::wrap(Unknown result)

bool SliverHitTestResultCls::addWithAxisOffset(double crossAxisOffset, double crossAxisPosition, SliverHitTest hitTest, double mainAxisOffset, double mainAxisPosition, Offset paintOffset) {
    assert(mainAxisOffset != nullptr);
    assert(crossAxisOffset != nullptr);
    assert(mainAxisPosition != nullptr);
    assert(crossAxisPosition != nullptr);
    assert(hitTest != nullptr);
    if (paintOffset != nullptr) {
        pushOffset(-paintOffset);
    }
    bool isHit = hitTest(this, mainAxisPosition - mainAxisOffset, crossAxisPosition - crossAxisOffset);
    if (paintOffset != nullptr) {
        popTransform();
    }
    return isHit;
}

SliverHitTestEntryCls::SliverHitTestEntryCls(Unknown target, double crossAxisPosition, double mainAxisPosition) {
    {
        assert(mainAxisPosition != nullptr);
        assert(crossAxisPosition != nullptr);
    }
}

String SliverHitTestEntryCls::toString() {
    return __s("${target.runtimeType}@(mainAxis: $mainAxisPosition, crossAxis: $crossAxisPosition)");
}

String SliverLogicalParentDataCls::toString() {
    return __s("layoutOffset=${layoutOffset == null ? 'None': layoutOffset!.toStringAsFixed(1)}");
}

void SliverPhysicalParentDataCls::applyPaintTransform(Matrix4 transform) {
    transform->translate(paintOffset->dx(), paintOffset->dy());
}

String SliverPhysicalParentDataCls::toString() {
    return __s("paintOffset=$paintOffset");
}

List<DiagnosticsNode> _debugCompareFloats(String labelA, double valueA, String labelB, double valueB) {
    List<DiagnosticsNode> list1 = make<ListCls<>>();if (valueA->toStringAsFixed(1) != valueB->toStringAsFixed(1)) {    list1.add(ArrayItem);} else {    list1.add(ArrayItem);}return list1;
}

SliverConstraints RenderSliverCls::constraints() {
    return as<SliverConstraints>(super->constraints);
}

SliverGeometry RenderSliverCls::geometry() {
    return _geometry;
}

void RenderSliverCls::geometry(SliverGeometry value) {
    assert(!(debugDoingThisResize() && debugDoingThisLayout()));
    assert(sizedByParent() || !debugDoingThisResize());
    assert([=] () {
        if ((sizedByParent() && debugDoingThisResize()) || (!sizedByParent() && debugDoingThisLayout())) {
            return true;
        }
        assert(!debugDoingThisResize());
        DiagnosticsNode contract, violation, hint;
        if (debugDoingThisLayout()) {
            assert(sizedByParent());
            violation = make<ErrorDescriptionCls>(__s("It appears that the geometry setter was called from performLayout()."));
        } else {
            violation = make<ErrorDescriptionCls>(__s("The geometry setter was called from outside layout (neither performResize() nor performLayout() were being run for this object)."));
            if (owner() != nullptr && owner()!->debugDoingLayout()) {
                hint = make<ErrorDescriptionCls>(__s("Only the object itself can set its geometry. It is a contract violation for other objects to set it."));
            }
        }
        if (sizedByParent()) {
            contract = make<ErrorDescriptionCls>(__s("Because this RenderSliver has sizedByParent set to true, it must set its geometry in performResize()."));
        } else {
            contract = make<ErrorDescriptionCls>(__s("Because this RenderSliver has sizedByParent set to false, it must set its geometry in performLayout()."));
        }
            List<DiagnosticsNode> list1 = make<ListCls<>>();    list1.add(ArrayItem);    list1.add(ArrayItem);    if (hint != nullptr) {        list1.add(ArrayItem);    }list1.add(ArrayItem);    list1.add(ArrayItem);List<DiagnosticsNode> information = list1;
        throw FlutterErrorCls->fromParts(information);
    }());
    _geometry = value;
}

Rect RenderSliverCls::semanticBounds() {
    return paintBounds();
}

Rect RenderSliverCls::paintBounds() {
    assert(constraints()->axis() != nullptr);
    ;
}

void RenderSliverCls::debugResetSize() {
}

void RenderSliverCls::debugAssertDoesMeetConstraints() {
    assert(geometry()!->debugAssertIsValid([=] () {
        makeList(ArrayItem);
    }));
    assert([=] () {
        if (geometry()!->paintOrigin + geometry()!->paintExtent > constraints()->remainingPaintExtent) {
                    List<DiagnosticsNode> list1 = make<ListCls<>>();        list1.add(ArrayItem);        list1.add(ArrayItem);        for (auto _x1 : _debugCompareFloats(__s("remainingPaintExtent"), constraints()->remainingPaintExtent, __s("paintOrigin + paintExtent"), geometry()!->paintOrigin + geometry()!->paintExtent)) {        {            list1.add(_x1);        }list1.add(ArrayItem);throw FlutterErrorCls->fromParts(list1);
        }
        return true;
    }());
}

void RenderSliverCls::performResize() {
    assert(false);
}

double RenderSliverCls::centerOffsetAdjustment() {
    return 0.0;
}

bool RenderSliverCls::hitTest(SliverHitTestResult result, double crossAxisPosition, double mainAxisPosition) {
    if (mainAxisPosition >= 0.0 &&  < geometry()!->hitTestExtent && crossAxisPosition >= 0.0 &&  < constraints()->crossAxisExtent) {
        if (hitTestChildren(result, mainAxisPosition, crossAxisPosition) || hitTestSelf(mainAxisPosition, crossAxisPosition)) {
            result->add(make<SliverHitTestEntryCls>(this, mainAxisPosition, crossAxisPosition));
            return true;
        }
    }
    return false;
}

bool RenderSliverCls::hitTestSelf(double crossAxisPosition, double mainAxisPosition) {
    return false;
}

bool RenderSliverCls::hitTestChildren(SliverHitTestResult result, double crossAxisPosition, double mainAxisPosition) {
    return false;
}

double RenderSliverCls::calculatePaintOffset(SliverConstraints constraints, double from, double to) {
    assert(from <= to);
    double a = constraints->scrollOffset;
    double b = constraints->scrollOffset + constraints->remainingPaintExtent;
    return clampDouble(clampDouble(to, a, b) - clampDouble(from, a, b), 0.0, constraints->remainingPaintExtent);
}

double RenderSliverCls::calculateCacheOffset(SliverConstraints constraints, double from, double to) {
    assert(from <= to);
    double a = constraints->scrollOffset + constraints->cacheOrigin;
    double b = constraints->scrollOffset + constraints->remainingCacheExtent;
    return clampDouble(clampDouble(to, a, b) - clampDouble(from, a, b), 0.0, constraints->remainingCacheExtent);
}

double RenderSliverCls::childMainAxisPosition(RenderObject child) {
    assert([=] () {
        throw make<FlutterErrorCls>(__s("${objectRuntimeType(this, 'RenderSliver')} does not implement childPosition."));
    }());
    return 0.0;
}

double RenderSliverCls::childCrossAxisPosition(RenderObject child) {
    return 0.0;
}

double RenderSliverCls::childScrollOffset(RenderObject child) {
    assert(child->parent() == this);
    return 0.0;
}

void RenderSliverCls::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert([=] () {
        throw make<FlutterErrorCls>(__s("${objectRuntimeType(this, 'RenderSliver')} does not implement applyPaintTransform."));
    }());
}

Size RenderSliverCls::getAbsoluteSizeRelativeToOrigin() {
    assert(geometry() != nullptr);
    assert(!debugNeedsLayout());
    ;
}

Size RenderSliverCls::getAbsoluteSize() {
    assert(geometry() != nullptr);
    assert(!debugNeedsLayout());
    ;
}

void RenderSliverCls::debugPaint(PaintingContext context, Offset offset) {
    assert([=] () {
        if (debugPaintSizeEnabled) {
            double strokeWidth = math->min(4.0, geometry()!->paintExtent / 30.0);
                    auto _c1 = make<PaintCls>();        _c1.color = auto _c2 = make<ColorCls>(0xFF33CC33);        _c2.strokeWidth = auto _c3 = strokeWidth;        _c3.style = auto _c4 = PaintingStyleCls::stroke;        _c4.maskFilter = MaskFilterCls->blur(BlurStyleCls::solid, strokeWidth);        _c4;        _c3;        _c2;Paint paint = _c1;
            double arrowExtent = geometry()!->paintExtent;
            double padding = math->max(2.0, strokeWidth);
            Canvas canvas = context->canvas();
            canvas->drawCircle(offset->translate(padding, padding), padding * 0.5, paint);
            ;
        }
        return true;
    }());
}

void RenderSliverCls::handleEvent(PointerEvent event, SliverHitTestEntry entry) {
}

void RenderSliverCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<SliverGeometry>make<DiagnosticsPropertyCls>(__s("geometry"), geometry()));
}

void RenderSliverCls::_debugDrawArrow(Canvas canvas, Paint paint, Offset p0, Offset p1, GrowthDirection direction) {
    assert([=] () {
        if (p0 == p1) {
            return true;
        }
        assert(p0->dx() == p1->dx() || p0->dy() == p1->dy());
        double d = (p1 - p0)->distance() * 0.2;
        Offset temp;
        double dx1, dx2, dy1, dy2;
        ;
        if (p0->dx() == p1->dx()) {
            dx2 = -dx2;
        } else {
            dy2 = -dy2;
        }
            auto _c1 = make<PathCls>();    _c1.auto _c2 = moveTo(p0->dx(), p0->dy());    _c2.auto _c3 = lineTo(p1->dx(), p1->dy());    _c3.auto _c4 = moveTo(p1->dx() - dx1, p1->dy() - dy1);    _c4.auto _c5 = lineTo(p1->dx(), p1->dy());    _c5.lineTo(p1->dx() - dx2, p1->dy() - dy2);    _c5;    _c4;    _c3;    _c2;canvas->drawPath(_c1, paint);
        return true;
    }());
}

bool RenderSliverHelpersCls::hitTestBoxChild(BoxHitTestResult result, RenderBox child, double crossAxisPosition, double mainAxisPosition) {
    bool rightWayUp = _getRightWayUp(constraints());
    double delta = childMainAxisPosition(child);
    double crossAxisDelta = childCrossAxisPosition(child);
    double absolutePosition = mainAxisPosition - delta;
    double absoluteCrossAxisPosition = crossAxisPosition - crossAxisDelta;
    Offset paintOffset, transformedPosition;
    assert(constraints()->axis() != nullptr);
    ;
    assert(paintOffset != nullptr);
    assert(transformedPosition != nullptr);
    return result->addWithOutOfBandPosition(paintOffset, [=] (BoxHitTestResult result) {
        return child->hitTest(result, transformedPosition);
    });
}

void RenderSliverHelpersCls::applyPaintTransformForBoxChild(RenderBox child, Matrix4 transform) {
    bool rightWayUp = _getRightWayUp(constraints());
    double delta = childMainAxisPosition(child);
    double crossAxisDelta = childCrossAxisPosition(child);
    assert(constraints()->axis() != nullptr);
    ;
}

bool RenderSliverHelpersCls::_getRightWayUp(SliverConstraints constraints) {
    assert(constraints != nullptr);
    assert(constraints->axisDirection != nullptr);
    bool rightWayUp;
    ;
    assert(constraints->growthDirection != nullptr);
    ;
    assert(rightWayUp != nullptr);
    return rightWayUp;
}

RenderSliverSingleBoxAdapterCls::RenderSliverSingleBoxAdapterCls(RenderBox child) {
    {
        this->child = child;
    }
}

void RenderSliverSingleBoxAdapterCls::setupParentData(RenderObject child) {
    if (!is<SliverPhysicalParentData>(child->parentData)) {
        child->parentData = make<SliverPhysicalParentDataCls>();
    }
}

void RenderSliverSingleBoxAdapterCls::setChildParentData(RenderObject child, SliverConstraints constraints, SliverGeometry geometry) {
    SliverPhysicalParentData childParentData = as<SliverPhysicalParentData>(child->parentData!);
    assert(constraints->axisDirection != nullptr);
    assert(constraints->growthDirection != nullptr);
    ;
    assert(childParentData->paintOffset != nullptr);
}

bool RenderSliverSingleBoxAdapterCls::hitTestChildren(SliverHitTestResult result, double crossAxisPosition, double mainAxisPosition) {
    assert(geometry()!->hitTestExtent > 0.0);
    if (child != nullptr) {
        return hitTestBoxChild(BoxHitTestResultCls->wrap(result), child!, mainAxisPosition, crossAxisPosition);
    }
    return false;
}

double RenderSliverSingleBoxAdapterCls::childMainAxisPosition(RenderBox child) {
    return -constraints()->scrollOffset;
}

void RenderSliverSingleBoxAdapterCls::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(child != nullptr);
    assert(child == this->child);
    SliverPhysicalParentData childParentData = as<SliverPhysicalParentData>(child->parentData!);
    childParentData->applyPaintTransform(transform);
}

void RenderSliverSingleBoxAdapterCls::paint(PaintingContext context, Offset offset) {
    if (child != nullptr && geometry()!->visible) {
        SliverPhysicalParentData childParentData = as<SliverPhysicalParentData>(child!->parentData!);
        context->paintChild(child!, offset + childParentData->paintOffset);
    }
}

void RenderSliverToBoxAdapterCls::performLayout() {
    if (child == nullptr) {
        geometry() = SliverGeometryCls::zero;
        return;
    }
    SliverConstraints constraints = this->constraints();
    child!->layout(constraints->asBoxConstraints(), true);
    double childExtent;
    ;
    assert(childExtent != nullptr);
    double paintedChildSize = calculatePaintOffset(constraints, 0.0, childExtent);
    double cacheExtent = calculateCacheOffset(constraints, 0.0, childExtent);
    assert(paintedChildSize->isFinite());
    assert(paintedChildSize >= 0.0);
    geometry() = make<SliverGeometryCls>(childExtent, paintedChildSize, cacheExtent, childExtent, paintedChildSize, childExtent > constraints->remainingPaintExtent || constraints->scrollOffset > 0.0);
    setChildParentData(child!, constraints, geometry()!);
}
