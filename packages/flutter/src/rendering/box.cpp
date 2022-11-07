#include "box.hpp"
_DebugSize::_DebugSize(bool _canBeUsedByParent, RenderBox _owner, Unknown) {
    {
        super.copy();
    }
}

BoxConstraints::BoxConstraints(double maxHeight, double maxWidth, double minHeight, double minWidth) {
    {
        assert(minWidth != nullptr);
        assert(maxWidth != nullptr);
        assert(minHeight != nullptr);
        assert(maxHeight != nullptr);
    }
}

void BoxConstraints::tight(Size size)

void BoxConstraints::tightFor(double height, double width)

void BoxConstraints::tightForFinite(double height, double width)

void BoxConstraints::loose(Size size)

void BoxConstraints::expand(double height, double width)

BoxConstraints BoxConstraints::copyWith(double maxHeight, double maxWidth, double minHeight, double minWidth) {
    return BoxConstraints(minWidth ?? this.minWidth, maxWidth ?? this.maxWidth, minHeight ?? this.minHeight, maxHeight ?? this.maxHeight);
}

BoxConstraints BoxConstraints::deflate(EdgeInsets edges) {
    assert(edges != nullptr);
    assert(debugAssertIsValid());
    double horizontal = edges.horizontal;
    double vertical = edges.vertical;
    double deflatedMinWidth = math.max(0.0, minWidth - horizontal);
    double deflatedMinHeight = math.max(0.0, minHeight - vertical);
    return BoxConstraints(deflatedMinWidth, math.max(deflatedMinWidth, maxWidth - horizontal), deflatedMinHeight, math.max(deflatedMinHeight, maxHeight - vertical));
}

BoxConstraints BoxConstraints::loosen() {
    assert(debugAssertIsValid());
    return BoxConstraints(maxWidth, maxHeight);
}

BoxConstraints BoxConstraints::enforce(BoxConstraints constraints) {
    return BoxConstraints(clampDouble(minWidth, constraints.minWidth, constraints.maxWidth), clampDouble(maxWidth, constraints.minWidth, constraints.maxWidth), clampDouble(minHeight, constraints.minHeight, constraints.maxHeight), clampDouble(maxHeight, constraints.minHeight, constraints.maxHeight));
}

BoxConstraints BoxConstraints::tighten(double height, double width) {
    return BoxConstraints(width == nullptr? minWidth : clampDouble(width, minWidth, maxWidth), width == nullptr? maxWidth : clampDouble(width, minWidth, maxWidth), height == nullptr? minHeight : clampDouble(height, minHeight, maxHeight), height == nullptr? maxHeight : clampDouble(height, minHeight, maxHeight));
}

BoxConstraints BoxConstraints::flipped() {
    return BoxConstraints(minHeight, maxHeight, minWidth, maxWidth);
}

BoxConstraints BoxConstraints::widthConstraints() {
    return BoxConstraints(minWidth, maxWidth);
}

BoxConstraints BoxConstraints::heightConstraints() {
    return BoxConstraints(minHeight, maxHeight);
}

double BoxConstraints::constrainWidth(double width) {
    assert(debugAssertIsValid());
    return clampDouble(width, minWidth, maxWidth);
}

double BoxConstraints::constrainHeight(double height) {
    assert(debugAssertIsValid());
    return clampDouble(height, minHeight, maxHeight);
}

Size BoxConstraints::constrain(Size size) {
    Size result = Size(constrainWidth(size.width), constrainHeight(size.height));
    assert(());
    return result;
}

Size BoxConstraints::constrainDimensions(double height, double width) {
    return Size(constrainWidth(width), constrainHeight(height));
}

Size BoxConstraints::constrainSizeAndAttemptToPreserveAspectRatio(Size size) {
    if (isTight) {
        Size result = smallest;
        assert(());
        return result;
    }
    double width = size.width;
    double height = size.height;
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
    Size result = Size(constrainWidth(width), constrainHeight(height));
    assert(());
    return result;
}

Size BoxConstraints::biggest() {
    return Size(constrainWidth(), constrainHeight());
}

Size BoxConstraints::smallest() {
    return Size(constrainWidth(0.0), constrainHeight(0.0));
}

bool BoxConstraints::hasTightWidth() {
    return minWidth >= maxWidth;
}

bool BoxConstraints::hasTightHeight() {
    return minHeight >= maxHeight;
}

bool BoxConstraints::isTight() {
    return hasTightWidth && hasTightHeight;
}

bool BoxConstraints::hasBoundedWidth() {
    return  < double.infinity;
}

bool BoxConstraints::hasBoundedHeight() {
    return  < double.infinity;
}

bool BoxConstraints::hasInfiniteWidth() {
    return minWidth >= double.infinity;
}

bool BoxConstraints::hasInfiniteHeight() {
    return minHeight >= double.infinity;
}

bool BoxConstraints::isSatisfiedBy(Size size) {
    assert(debugAssertIsValid());
    return (minWidth <= size.width) && (size.width <= maxWidth) && (minHeight <= size.height) && (size.height <= maxHeight);
}

BoxConstraints BoxConstraints::*(double factor) {
    return BoxConstraints(minWidth * factor, maxWidth * factor, minHeight * factor, maxHeight * factor);
}

BoxConstraints BoxConstraints::/(double factor) {
    return BoxConstraints(minWidth / factor, maxWidth / factor, minHeight / factor, maxHeight / factor);
}

BoxConstraints BoxConstraints::~/(double factor) {
    return BoxConstraints((minWidth ~/ factor).toDouble(), (maxWidth ~/ factor).toDouble(), (minHeight ~/ factor).toDouble(), (maxHeight ~/ factor).toDouble());
}

BoxConstraints BoxConstraints::%(double value) {
    return BoxConstraints(minWidth % value, maxWidth % value, minHeight % value, maxHeight % value);
}

BoxConstraints BoxConstraints::lerp(BoxConstraints a, BoxConstraints b, double t) {
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
    assert(a.debugAssertIsValid());
    assert(b.debugAssertIsValid());
    assert((a.minWidth.isFinite && b.minWidth.isFinite) || (a.minWidth == double.infinity && b.minWidth == double.infinity), "Cannot interpolate between finite constraints and unbounded constraints.");
    assert((a.maxWidth.isFinite && b.maxWidth.isFinite) || (a.maxWidth == double.infinity && b.maxWidth == double.infinity), "Cannot interpolate between finite constraints and unbounded constraints.");
    assert((a.minHeight.isFinite && b.minHeight.isFinite) || (a.minHeight == double.infinity && b.minHeight == double.infinity), "Cannot interpolate between finite constraints and unbounded constraints.");
    assert((a.maxHeight.isFinite && b.maxHeight.isFinite) || (a.maxHeight == double.infinity && b.maxHeight == double.infinity), "Cannot interpolate between finite constraints and unbounded constraints.");
    return BoxConstraints(a.minWidth.isFinite? ui.lerpDouble(a.minWidth, b.minWidth, t)! : double.infinity, a.maxWidth.isFinite? ui.lerpDouble(a.maxWidth, b.maxWidth, t)! : double.infinity, a.minHeight.isFinite? ui.lerpDouble(a.minHeight, b.minHeight, t)! : double.infinity, a.maxHeight.isFinite? ui.lerpDouble(a.maxHeight, b.maxHeight, t)! : double.infinity);
}

bool BoxConstraints::isNormalized() {
    return minWidth >= 0.0 && minWidth <= maxWidth && minHeight >= 0.0 && minHeight <= maxHeight;
}

bool BoxConstraints::debugAssertIsValid(InformationCollector informationCollector, bool isAppliedConstraint) {
    assert(());
    return isNormalized;
}

BoxConstraints BoxConstraints::normalize() {
    if (isNormalized) {
        return this;
    }
    double minWidth = this.minWidth >= 0.0? this.minWidth : 0.0;
    double minHeight = this.minHeight >= 0.0? this.minHeight : 0.0;
    return BoxConstraints(minWidth, minWidth > maxWidth? minWidth : maxWidth, minHeight, minHeight > maxHeight? minHeight : maxHeight);
}

bool BoxConstraints::==(Object other) {
    assert(debugAssertIsValid());
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    assert(other is BoxConstraints && other.debugAssertIsValid());
    return other is BoxConstraints && other.minWidth == minWidth && other.maxWidth == maxWidth && other.minHeight == minHeight && other.maxHeight == maxHeight;
}

int BoxConstraints::hashCode() {
    assert(debugAssertIsValid());
    return Object.hash(minWidth, maxWidth, minHeight, maxHeight);
}

String BoxConstraints::toString() {
    String annotation = isNormalized? "" : "; NOT NORMALIZED";
    if (minWidth == double.infinity && minHeight == double.infinity) {
        return "BoxConstraints(biggest$annotation)";
    }
    if (minWidth == 0 && maxWidth == double.infinity && minHeight == 0 && maxHeight == double.infinity) {
        return "BoxConstraints(unconstrained$annotation)";
    }
    ;
    String width = describe(minWidth, maxWidth, "w");
    String height = describe(minHeight, maxHeight, "h");
    return "BoxConstraints($width, $height$annotation)";
}

Size BoxConstraints::_debugPropagateDebugSize(Size result, Size size) {
    assert(());
    return result;
}

BoxHitTestResult::BoxHitTestResult() {
    {
        super();
    }
}

void BoxHitTestResult::wrap(Unknown)

bool BoxHitTestResult::addWithPaintTransform(BoxHitTest hitTest, Offset position, Matrix4 transform) {
    assert(position != nullptr);
    assert(hitTest != nullptr);
    if (transform != nullptr) {
        transform = Matrix4.tryInvert(PointerEvent.removePerspectiveTransform(transform));
        if (transform == nullptr) {
            return false;
        }
    }
    return addWithRawTransform(transform, position, hitTest);
}

bool BoxHitTestResult::addWithPaintOffset(BoxHitTest hitTest, Offset offset, Offset position) {
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

bool BoxHitTestResult::addWithRawTransform(BoxHitTest hitTest, Offset position, Matrix4 transform) {
    assert(position != nullptr);
    assert(hitTest != nullptr);
    assert(position != nullptr);
    Offset transformedPosition = transform == nullptr? position : MatrixUtils.transformPoint(transform, position);
    if (transform != nullptr) {
        pushTransform(transform);
    }
    bool isHit = hitTest(this, transformedPosition);
    if (transform != nullptr) {
        popTransform();
    }
    return isHit;
}

bool BoxHitTestResult::addWithOutOfBandPosition(BoxHitTestWithOutOfBandPosition hitTest, Offset paintOffset, Matrix4 paintTransform, Matrix4 rawTransform) {
    assert(hitTest != nullptr);
    assert((paintOffset == nullptr && paintTransform == nullptr && rawTransform != nullptr) || (paintOffset == nullptr && paintTransform != nullptr && rawTransform == nullptr) || (paintOffset != nullptr && paintTransform == nullptr && rawTransform == nullptr), "Exactly one transform or offset argument must be provided.");
    if (paintOffset != nullptr) {
        pushOffset(-paintOffset);
    } else     {
        if (rawTransform != nullptr) {
        pushTransform(rawTransform);
    } else {
        assert(paintTransform != nullptr);
        paintTransform = Matrix4.tryInvert(PointerEvent.removePerspectiveTransform(paintTransform!));
        assert(paintTransform != nullptr, "paintTransform must be invertible.");
        pushTransform(paintTransform!);
    }
;
    }    bool isHit = hitTest(this);
    popTransform();
    return isHit;
}

BoxHitTestEntry::BoxHitTestEntry(Offset localPosition, Unknown) {
    {
        assert(localPosition != nullptr);
    }
}

String BoxHitTestEntry::toString() {
    return "${describeIdentity(target)}@$localPosition";
}

String BoxParentData::toString() {
    return "offset=$offset";
}

bool _IntrinsicDimensionsCacheEntry::==(Object other) {
    return other is _IntrinsicDimensionsCacheEntry && other.dimension == dimension && other.argument == argument;
}

int _IntrinsicDimensionsCacheEntry::hashCode() {
    return Object.hash(dimension, argument);
}

void RenderBox::setupParentData(RenderObject child) {
    if (child.parentData is! BoxParentData) {
        child.parentData = BoxParentData();
    }
}

double RenderBox::getMinIntrinsicWidth(double height) {
    assert(());
    return _computeIntrinsicDimension(_IntrinsicDimension.minWidth, height, computeMinIntrinsicWidth);
}

double RenderBox::computeMinIntrinsicWidth(double height) {
    return 0.0;
}

double RenderBox::getMaxIntrinsicWidth(double height) {
    assert(());
    return _computeIntrinsicDimension(_IntrinsicDimension.maxWidth, height, computeMaxIntrinsicWidth);
}

double RenderBox::computeMaxIntrinsicWidth(double height) {
    return 0.0;
}

double RenderBox::getMinIntrinsicHeight(double width) {
    assert(());
    return _computeIntrinsicDimension(_IntrinsicDimension.minHeight, width, computeMinIntrinsicHeight);
}

double RenderBox::computeMinIntrinsicHeight(double width) {
    return 0.0;
}

double RenderBox::getMaxIntrinsicHeight(double width) {
    assert(());
    return _computeIntrinsicDimension(_IntrinsicDimension.maxHeight, width, computeMaxIntrinsicHeight);
}

double RenderBox::computeMaxIntrinsicHeight(double width) {
    return 0.0;
}

Size RenderBox::getDryLayout(BoxConstraints constraints) {
    bool shouldCache = true;
    assert(());
    if (shouldCache) {
        Map<String, String> debugTimelineArguments;
        assert(());
        if (!kReleaseMode) {
            if (debugProfileLayoutsEnabled || _debugIntrinsicsDepth == 0) {
                Timeline.startSync("$runtimeType.getDryLayout"debugTimelineArguments);
            }
            _debugIntrinsicsDepth = 1;
        }
        _cachedDryLayoutSizes = ;
        Size result = _cachedDryLayoutSizes!.putIfAbsent(constraints, );
        if (!kReleaseMode) {
            _debugIntrinsicsDepth = 1;
            if (debugProfileLayoutsEnabled || _debugIntrinsicsDepth == 0) {
                Timeline.finishSync();
            }
        }
        return result;
    }
    return _computeDryLayout(constraints);
}

Size RenderBox::computeDryLayout(BoxConstraints constraints) {
    assert(debugCannotComputeDryLayout(FlutterError.fromParts()));
    return Size.zero;
}

bool RenderBox::debugCannotComputeDryLayout(FlutterError error, String reason) {
    assert((reason == nullptr) != (error == nullptr));
    assert(());
    return true;
}

bool RenderBox::hasSize() {
    return _size != nullptr;
}

Size RenderBox::size() {
    assert(hasSize, "RenderBox was not laid out: $this");
    assert(());
    return _size!;
}

void RenderBox::size(Size value) {
    assert(!(debugDoingThisResize && debugDoingThisLayout));
    assert(sizedByParent || !debugDoingThisResize);
    assert(());
    assert(());
    _size = value;
    assert(());
}

Size RenderBox::debugAdoptSize(Size value) {
    Size result = value;
    assert(());
    return result;
}

Rect RenderBox::semanticBounds() {
    return Offset.zero & size;
}

void RenderBox::debugResetSize() {
    size = size;
}

double RenderBox::getDistanceToBaseline(TextBaseline baseline, bool onlyReal) {
    assert(!_debugDoingBaseline, "Please see the documentation for computeDistanceToActualBaseline for the required calling conventions of this method.");
    assert(!debugNeedsLayout);
    assert(());
    assert(_debugSetDoingBaseline(true));
    double result = getDistanceToActualBaseline(baseline);
    assert(_debugSetDoingBaseline(false));
    if (result == nullptr && !onlyReal) {
        return size.height;
    }
    return result;
}

double RenderBox::getDistanceToActualBaseline(TextBaseline baseline) {
    assert(_debugDoingBaseline, "Please see the documentation for computeDistanceToActualBaseline for the required calling conventions of this method.");
    _cachedBaselines = ;
    _cachedBaselines!.putIfAbsent(baseline, );
    return _cachedBaselines![baseline];
}

double RenderBox::computeDistanceToActualBaseline(TextBaseline baseline) {
    assert(_debugDoingBaseline, "Please see the documentation for computeDistanceToActualBaseline for the required calling conventions of this method.");
    return nullptr;
}

BoxConstraints RenderBox::constraints() {
    return (;
}

void RenderBox::debugAssertDoesMeetConstraints() {
    assert(constraints != nullptr);
    assert(());
}

void RenderBox::markNeedsLayout() {
    if (_clearCachedData() && parent is RenderObject) {
        markParentNeedsLayout();
        return;
    }
    super.markNeedsLayout();
}

void RenderBox::layout(Constraints constraints, bool parentUsesSize) {
    if (hasSize && constraints != this.constraints && _cachedBaselines != nullptr && _cachedBaselines!.isNotEmpty) {
        _cachedBaselines?.clear();
    }
    super.layout(constraintsparentUsesSize);
}

void RenderBox::performResize() {
    size = computeDryLayout(constraints);
    assert(size.isFinite);
}

void RenderBox::performLayout() {
    assert(());
}

bool RenderBox::hitTest(Offset position, BoxHitTestResult result) {
    assert(());
    if (_size!.contains(position)) {
        if (hitTestChildren(resultposition) || hitTestSelf(position)) {
            result.add(BoxHitTestEntry(this, position));
            return true;
        }
    }
    return false;
}

bool RenderBox::hitTestSelf(Offset position) {
    return false;
}

bool RenderBox::hitTestChildren(Offset position, BoxHitTestResult result) {
    return false;
}

void RenderBox::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(child != nullptr);
    assert(child.parent == this);
    assert(());
    BoxParentData childParentData = (;
    Offset offset = childParentData.offset;
    transform.translate(offset.dx, offset.dy);
}

Offset RenderBox::globalToLocal(RenderObject ancestor, Offset point) {
    Matrix4 transform = getTransformTo(ancestor);
    double det = transform.invert();
    if (det == 0.0) {
        return Offset.zero;
    }
    Vector3 n = Vector3(0.0, 0.0, 1.0);
    Vector3 i = transform.perspectiveTransform(Vector3(0.0, 0.0, 0.0));
    Vector3 d = transform.perspectiveTransform(Vector3(0.0, 0.0, 1.0)) - i;
    Vector3 s = transform.perspectiveTransform(Vector3(point.dx, point.dy, 0.0));
    Vector3 p = s - d * (n.dot(s) / n.dot(d));
    return Offset(p.x, p.y);
}

Offset RenderBox::localToGlobal(RenderObject ancestor, Offset point) {
    return MatrixUtils.transformPoint(getTransformTo(ancestor), point);
}

Rect RenderBox::paintBounds() {
    return Offset.zero & size;
}

void RenderBox::handleEvent(BoxHitTestEntry entry, PointerEvent event) {
    super.handleEvent(event, entry);
}

bool RenderBox::debugHandleEvent(HitTestEntry entry, PointerEvent event) {
    assert(());
    return true;
}

void RenderBox::debugPaint(PaintingContext context, Offset offset) {
    assert(());
}

void RenderBox::debugPaintSize(PaintingContext context, Offset offset) {
    assert(());
}

void RenderBox::debugPaintBaselines(PaintingContext context, Offset offset) {
    assert(());
}

void RenderBox::debugPaintPointers(PaintingContext context, Offset offset) {
    assert(());
}

void RenderBox::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Size>DiagnosticsProperty("size", _sizetrue));
}

double RenderBox::_computeIntrinsicDimension(double argument, FunctionType computer, _IntrinsicDimension dimension) {
    assert(RenderObject.debugCheckingIntrinsics || !debugDoingThisResize);
    bool shouldCache = true;
    assert(());
    if (shouldCache) {
        Map<String, String> debugTimelineArguments;
        assert(());
        if (!kReleaseMode) {
            if (debugProfileLayoutsEnabled || _debugIntrinsicsDepth == 0) {
                Timeline.startSync("$runtimeType intrinsics"debugTimelineArguments);
            }
            _debugIntrinsicsDepth = 1;
        }
        _cachedIntrinsicDimensions = ;
        double result = _cachedIntrinsicDimensions!.putIfAbsent(_IntrinsicDimensionsCacheEntry(dimension, argument), );
        if (!kReleaseMode) {
            _debugIntrinsicsDepth = 1;
            if (debugProfileLayoutsEnabled || _debugIntrinsicsDepth == 0) {
                Timeline.finishSync();
            }
        }
        return result;
    }
    return computer(argument);
}

Size RenderBox::_computeDryLayout(BoxConstraints constraints) {
    assert(());
    Size result = computeDryLayout(constraints);
    assert(());
    return result;
}

bool RenderBox::_debugSetDoingBaseline(bool value) {
    _debugDoingBaseline = value;
    return true;
}

bool RenderBox::_clearCachedData() {
    if ((_cachedBaselines != nullptr && _cachedBaselines!.isNotEmpty) || (_cachedIntrinsicDimensions != nullptr && _cachedIntrinsicDimensions!.isNotEmpty) || (_cachedDryLayoutSizes != nullptr && _cachedDryLayoutSizes!.isNotEmpty)) {
        _cachedBaselines?.clear();
        _cachedIntrinsicDimensions?.clear();
        _cachedDryLayoutSizes?.clear();
        return true;
    }
    return false;
}

double RenderBoxContainerDefaultsMixin::defaultComputeDistanceToFirstActualBaseline(TextBaseline baseline) {
    assert(!debugNeedsLayout);
    ChildType child = firstChild;
    while (child != nullptr) {
        ParentDataType childParentData = (;
        double result = child.getDistanceToActualBaseline(baseline);
        if (result != nullptr) {
            return result + childParentData!.offset.dy;
        }
        child = childParentData!.nextSibling;
    }
    return nullptr;
}

double RenderBoxContainerDefaultsMixin::defaultComputeDistanceToHighestActualBaseline(TextBaseline baseline) {
    assert(!debugNeedsLayout);
    double result;
    ChildType child = firstChild;
    while (child != nullptr) {
        ParentDataType childParentData = (;
        double candidate = child.getDistanceToActualBaseline(baseline);
        if (candidate != nullptr) {
            candidate = childParentData.offset.dy;
            if (result != nullptr) {
                result = math.min(result, candidate);
            } else {
                result = candidate;
            }
        }
        child = childParentData.nextSibling;
    }
    return result;
}

bool RenderBoxContainerDefaultsMixin::defaultHitTestChildren(Offset position, BoxHitTestResult result) {
    ChildType child = lastChild;
    while (child != nullptr) {
        ParentDataType childParentData = (;
        bool isHit = result.addWithPaintOffset(childParentData.offset, position, );
        if (isHit) {
            return true;
        }
        child = childParentData.previousSibling;
    }
    return false;
}

void RenderBoxContainerDefaultsMixin::defaultPaint(PaintingContext context, Offset offset) {
    ChildType child = firstChild;
    while (child != nullptr) {
        ParentDataType childParentData = (;
        context.paintChild(child, childParentData.offset + offset);
        child = childParentData.nextSibling;
    }
}

List<ChildType> RenderBoxContainerDefaultsMixin::getChildrenAsList() {
    List<ChildType> result = ;
    RenderBox child = firstChild;
    while (child != nullptr) {
        ParentDataType childParentData = (;
        result.add(();
        child = childParentData.nextSibling;
    }
    return result;
}
