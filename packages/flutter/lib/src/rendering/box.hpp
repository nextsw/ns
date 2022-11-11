#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_BOX
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_BOX
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/developer/developer.hpp>
#include <dart/math/math.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "debug.hpp"
#include "object.hpp"


class _DebugSizeCls : public SizeCls {
public:

private:
    RenderBox _owner;

    bool _canBeUsedByParent;


     _DebugSizeCls(Unknown source, RenderBox _owner, bool _canBeUsedByParent);

};
using _DebugSize = std::shared_ptr<_DebugSizeCls>;

class BoxConstraintsCls : public ConstraintsCls {
public:
    double minWidth;

    double maxWidth;

    double minHeight;

    double maxHeight;


     BoxConstraintsCls(double maxHeight, double maxWidth, double minHeight, double minWidth);

    virtual void  tight(Size size);

    virtual void  tightFor(double height, double width);

    virtual void  tightForFinite(double height, double width);

    virtual void  loose(Size size);

    virtual void  expand(double height, double width);

    virtual BoxConstraints copyWith(double maxHeight, double maxWidth, double minHeight, double minWidth);

    virtual BoxConstraints deflate(EdgeInsets edges);

    virtual BoxConstraints loosen();

    virtual BoxConstraints enforce(BoxConstraints constraints);

    virtual BoxConstraints tighten(double height, double width);

    virtual BoxConstraints flipped();

    virtual BoxConstraints widthConstraints();

    virtual BoxConstraints heightConstraints();

    virtual double constrainWidth(double width);

    virtual double constrainHeight(double height);

    virtual Size constrain(Size size);

    virtual Size constrainDimensions(double width, double height);

    virtual Size constrainSizeAndAttemptToPreserveAspectRatio(Size size);

    virtual Size biggest();

    virtual Size smallest();

    virtual bool hasTightWidth();

    virtual bool hasTightHeight();

    virtual bool isTight();

    virtual bool hasBoundedWidth();

    virtual bool hasBoundedHeight();

    virtual bool hasInfiniteWidth();

    virtual bool hasInfiniteHeight();

    virtual bool isSatisfiedBy(Size size);

    virtual BoxConstraints operator*(double factor);

    virtual BoxConstraints operator/(double factor);

    virtual BoxConstraints operator~/(double factor);

    virtual BoxConstraints operator%(double value);

    static BoxConstraints lerp(BoxConstraints a, BoxConstraints b, double t);

    virtual bool isNormalized();

    virtual bool debugAssertIsValid(InformationCollector informationCollector, bool isAppliedConstraint);

    virtual BoxConstraints normalize();

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

    virtual Size _debugPropagateDebugSize(Size size, Size result);

};
using BoxConstraints = std::shared_ptr<BoxConstraintsCls>;

class BoxHitTestResultCls : public HitTestResultCls {
public:

     BoxHitTestResultCls();

    virtual void  wrap(Unknown result);

    virtual bool addWithPaintTransform(BoxHitTest hitTest, Offset position, Matrix4 transform);

    virtual bool addWithPaintOffset(BoxHitTest hitTest, Offset offset, Offset position);

    virtual bool addWithRawTransform(BoxHitTest hitTest, Offset position, Matrix4 transform);

    virtual bool addWithOutOfBandPosition(BoxHitTestWithOutOfBandPosition hitTest, Offset paintOffset, Matrix4 paintTransform, Matrix4 rawTransform);

private:

};
using BoxHitTestResult = std::shared_ptr<BoxHitTestResultCls>;

class BoxHitTestEntryCls : public HitTestEntryCls<RenderBox> {
public:
    Offset localPosition;


     BoxHitTestEntryCls(T target, Offset localPosition);

    virtual String toString();

private:

};
using BoxHitTestEntry = std::shared_ptr<BoxHitTestEntryCls>;

class BoxParentDataCls : public ParentDataCls {
public:
    Offset offset;


    virtual String toString();

private:

};
using BoxParentData = std::shared_ptr<BoxParentDataCls>;

template<typename ChildType>
class ContainerBoxParentDataCls : public BoxParentDataCls {
public:

private:

};
template<typename ChildType>
using ContainerBoxParentData = std::shared_ptr<ContainerBoxParentDataCls<ChildType>>;

enum _IntrinsicDimension{
    minWidth,
    maxWidth,
    minHeight,
    maxHeight,
} // end _IntrinsicDimension

class _IntrinsicDimensionsCacheEntryCls : public ObjectCls {
public:
    _IntrinsicDimension dimension;

    double argument;


    virtual bool operator==(Object other);

    virtual int hashCode();

private:

     _IntrinsicDimensionsCacheEntryCls(_IntrinsicDimension dimension, double argument);
};
using _IntrinsicDimensionsCacheEntry = std::shared_ptr<_IntrinsicDimensionsCacheEntryCls>;

class RenderBoxCls : public RenderObjectCls {
public:

    virtual void setupParentData(RenderObject child);

    virtual double getMinIntrinsicWidth(double height);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double getMaxIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double getMinIntrinsicHeight(double width);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double getMaxIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual Size getDryLayout(BoxConstraints constraints);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual bool debugCannotComputeDryLayout(FlutterError error, String reason);

    virtual bool hasSize();

    virtual Size size();

    virtual void  size(Size value);

    virtual Size debugAdoptSize(Size value);

    virtual Rect semanticBounds();

    virtual void debugResetSize();

    virtual double getDistanceToBaseline(TextBaseline baseline, bool onlyReal);

    virtual double getDistanceToActualBaseline(TextBaseline baseline);

    virtual double computeDistanceToActualBaseline(TextBaseline baseline);

    virtual BoxConstraints constraints();

    virtual void debugAssertDoesMeetConstraints();

    virtual void markNeedsLayout();

    virtual void layout(Constraints constraints, bool parentUsesSize);

    virtual void performResize();

    virtual void performLayout();

    virtual bool hitTest(BoxHitTestResult result, Offset position);

    virtual bool hitTestSelf(Offset position);

    virtual bool hitTestChildren(BoxHitTestResult result, Offset position);

    virtual void applyPaintTransform(RenderObject child, Matrix4 transform);

    virtual Offset globalToLocal(Offset point, RenderObject ancestor);

    virtual Offset localToGlobal(Offset point, RenderObject ancestor);

    virtual Rect paintBounds();

    virtual void handleEvent(PointerEvent event, BoxHitTestEntry entry);

    virtual bool debugHandleEvent(PointerEvent event, HitTestEntry entry);

    virtual void debugPaint(PaintingContext context, Offset offset);

    virtual void debugPaintSize(PaintingContext context, Offset offset);

    virtual void debugPaintBaselines(PaintingContext context, Offset offset);

    virtual void debugPaintPointers(PaintingContext context, Offset offset);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Map<_IntrinsicDimensionsCacheEntry, double> _cachedIntrinsicDimensions;

    static int _debugIntrinsicsDepth;

    Map<BoxConstraints, Size> _cachedDryLayoutSizes;

    bool _computingThisDryLayout;

    static bool _dryLayoutCalculationValid;

    Size _size;

    Map<TextBaseline, double> _cachedBaselines;

    static bool _debugDoingBaseline;

    int _debugActivePointers;


    virtual double _computeIntrinsicDimension(_IntrinsicDimension dimension, double argument, std::function<double(double argument)> computer);

    virtual Size _computeDryLayout(BoxConstraints constraints);

    static bool _debugSetDoingBaseline(bool value);

    virtual bool _clearCachedData();

};
using RenderBox = std::shared_ptr<RenderBoxCls>;

template<typename ChildType, typename ParentDataType>
class RenderBoxContainerDefaultsMixinCls : public ObjectCls {
public:

    virtual double defaultComputeDistanceToFirstActualBaseline(TextBaseline baseline);

    virtual double defaultComputeDistanceToHighestActualBaseline(TextBaseline baseline);

    virtual bool defaultHitTestChildren(BoxHitTestResult result, Offset position);

    virtual void defaultPaint(PaintingContext context, Offset offset);

    virtual List<ChildType> getChildrenAsList();

private:

};
template<typename ChildType, typename ParentDataType>
using RenderBoxContainerDefaultsMixin = std::shared_ptr<RenderBoxContainerDefaultsMixinCls<ChildType, ParentDataType>>;


#endif