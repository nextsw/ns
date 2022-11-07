#ifndef BOX_H
#define BOX_H
#include <memory>

#include <developer/developer.hpp>
#include <math/math.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <vector_math/vector_math_64.hpp>
#include "debug.hpp"
#include "object.hpp"



class _DebugSize : Size {
public:

private:
    RenderBox _owner;

    bool _canBeUsedByParent;


     _DebugSize(bool _canBeUsedByParent, RenderBox _owner, Unknown);

};

class BoxConstraints : Constraints {
public:
    double minWidth;

    double maxWidth;

    double minHeight;

    double maxHeight;


     BoxConstraints(double maxHeight, double maxWidth, double minHeight, double minWidth);

    void  tight(Size size);

    void  tightFor(double height, double width);

    void  tightForFinite(double height, double width);

    void  loose(Size size);

    void  expand(double height, double width);

    BoxConstraints copyWith(double maxHeight, double maxWidth, double minHeight, double minWidth);

    BoxConstraints deflate(EdgeInsets edges);

    BoxConstraints loosen();

    BoxConstraints enforce(BoxConstraints constraints);

    BoxConstraints tighten(double height, double width);

    BoxConstraints flipped();

    BoxConstraints widthConstraints();

    BoxConstraints heightConstraints();

    double constrainWidth(double width);

    double constrainHeight(double height);

    Size constrain(Size size);

    Size constrainDimensions(double height, double width);

    Size constrainSizeAndAttemptToPreserveAspectRatio(Size size);

    Size biggest();

    Size smallest();

    bool hasTightWidth();

    bool hasTightHeight();

    bool isTight();

    bool hasBoundedWidth();

    bool hasBoundedHeight();

    bool hasInfiniteWidth();

    bool hasInfiniteHeight();

    bool isSatisfiedBy(Size size);

    BoxConstraints *(double factor);

    BoxConstraints /(double factor);

    BoxConstraints ~/(double factor);

    BoxConstraints %(double value);

    static BoxConstraints lerp(BoxConstraints a, BoxConstraints b, double t);

    bool isNormalized();

    bool debugAssertIsValid(InformationCollector informationCollector, bool isAppliedConstraint);

    BoxConstraints normalize();

    bool ==(Object other);

    int hashCode();

    String toString();

private:

    Size _debugPropagateDebugSize(Size result, Size size);

};

class BoxHitTestResult : HitTestResult {
public:

     BoxHitTestResult();

    void  wrap(Unknown);

    bool addWithPaintTransform(BoxHitTest hitTest, Offset position, Matrix4 transform);

    bool addWithPaintOffset(BoxHitTest hitTest, Offset offset, Offset position);

    bool addWithRawTransform(BoxHitTest hitTest, Offset position, Matrix4 transform);

    bool addWithOutOfBandPosition(BoxHitTestWithOutOfBandPosition hitTest, Offset paintOffset, Matrix4 paintTransform, Matrix4 rawTransform);

private:

};

class BoxHitTestEntry : HitTestEntry<RenderBox> {
public:
    Offset localPosition;


     BoxHitTestEntry(Offset localPosition, Unknown);

    String toString();

private:

};

class BoxParentData : ParentData {
public:
    Offset offset;


    String toString();

private:

};

class ContainerBoxParentData<ChildType extends RenderObject> : BoxParentData {
public:

private:

};

enum _IntrinsicDimension{
    minWidth,
    maxWidth,
    minHeight,
    maxHeight,
} // end _IntrinsicDimension

class _IntrinsicDimensionsCacheEntry {
public:
    _IntrinsicDimension dimension;

    double argument;


    bool ==(Object other);

    int hashCode();

private:

     _IntrinsicDimensionsCacheEntry(double argument, _IntrinsicDimension dimension);

};

class RenderBox : RenderObject {
public:

    void setupParentData(RenderObject child);

    double getMinIntrinsicWidth(double height);

    double computeMinIntrinsicWidth(double height);

    double getMaxIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double getMinIntrinsicHeight(double width);

    double computeMinIntrinsicHeight(double width);

    double getMaxIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    Size getDryLayout(BoxConstraints constraints);

    Size computeDryLayout(BoxConstraints constraints);

    bool debugCannotComputeDryLayout(FlutterError error, String reason);

    bool hasSize();

    Size size();

    void  size(Size value);

    Size debugAdoptSize(Size value);

    Rect semanticBounds();

    void debugResetSize();

    double getDistanceToBaseline(TextBaseline baseline, bool onlyReal);

    double getDistanceToActualBaseline(TextBaseline baseline);

    double computeDistanceToActualBaseline(TextBaseline baseline);

    BoxConstraints constraints();

    void debugAssertDoesMeetConstraints();

    void markNeedsLayout();

    void layout(Constraints constraints, bool parentUsesSize);

    void performResize();

    void performLayout();

    bool hitTest(Offset position, BoxHitTestResult result);

    bool hitTestSelf(Offset position);

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    void applyPaintTransform(RenderObject child, Matrix4 transform);

    Offset globalToLocal(RenderObject ancestor, Offset point);

    Offset localToGlobal(RenderObject ancestor, Offset point);

    Rect paintBounds();

    void handleEvent(BoxHitTestEntry entry, PointerEvent event);

    bool debugHandleEvent(HitTestEntry entry, PointerEvent event);

    void debugPaint(PaintingContext context, Offset offset);

    void debugPaintSize(PaintingContext context, Offset offset);

    void debugPaintBaselines(PaintingContext context, Offset offset);

    void debugPaintPointers(PaintingContext context, Offset offset);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

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


    double _computeIntrinsicDimension(double argument, FunctionType computer, _IntrinsicDimension dimension);

    Size _computeDryLayout(BoxConstraints constraints);

    static bool _debugSetDoingBaseline(bool value);

    bool _clearCachedData();

};

class RenderBoxContainerDefaultsMixin<ChildType extends RenderBox, ParentDataType extends ContainerBoxParentData<ChildType>> {
public:

    double defaultComputeDistanceToFirstActualBaseline(TextBaseline baseline);

    double defaultComputeDistanceToHighestActualBaseline(TextBaseline baseline);

    bool defaultHitTestChildren(Offset position, BoxHitTestResult result);

    void defaultPaint(PaintingContext context, Offset offset);

    List<ChildType> getChildrenAsList();

private:

};

#endif