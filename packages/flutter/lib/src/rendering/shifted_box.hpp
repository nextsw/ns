#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_SHIFTED_BOX
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_SHIFTED_BOX
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "box.hpp"
#include "debug.hpp"
#include "debug_overflow_indicator.hpp"
#include "layer.hpp"
#include "object.hpp"
#include "stack.hpp"


class RenderShiftedBoxCls : public RenderBoxCls {
public:

     RenderShiftedBoxCls(RenderBox child);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual double computeDistanceToActualBaseline(TextBaseline baseline);

    virtual void paint(PaintingContext context, Offset offset);

    virtual bool hitTestChildren(BoxHitTestResult result, Offset position);

private:

};
using RenderShiftedBox = std::shared_ptr<RenderShiftedBoxCls>;

class RenderPaddingCls : public RenderShiftedBoxCls {
public:

     RenderPaddingCls(RenderBox child, EdgeInsetsGeometry padding, TextDirection textDirection);

    virtual EdgeInsetsGeometry padding();

    virtual void  padding(EdgeInsetsGeometry value);

    virtual TextDirection textDirection();

    virtual void  textDirection(TextDirection value);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual void debugPaintSize(PaintingContext context, Offset offset);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    EdgeInsets _resolvedPadding;

    EdgeInsetsGeometry _padding;

    TextDirection _textDirection;


    virtual void _resolve();

    virtual void _markNeedResolution();

};
using RenderPadding = std::shared_ptr<RenderPaddingCls>;

class RenderAligningShiftedBoxCls : public RenderShiftedBoxCls {
public:

     RenderAligningShiftedBoxCls(AlignmentGeometry alignment, RenderBox child, TextDirection textDirection);

    virtual AlignmentGeometry alignment();

    virtual void  alignment(AlignmentGeometry value);

    virtual TextDirection textDirection();

    virtual void  textDirection(TextDirection value);

    virtual void alignChild();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Alignment _resolvedAlignment;

    AlignmentGeometry _alignment;

    TextDirection _textDirection;


    virtual void _resolve();

    virtual void _markNeedResolution();

};
using RenderAligningShiftedBox = std::shared_ptr<RenderAligningShiftedBoxCls>;

class RenderPositionedBoxCls : public RenderAligningShiftedBoxCls {
public:

     RenderPositionedBoxCls(AlignmentGeometry alignment, RenderBox child, double heightFactor, TextDirection textDirection, double widthFactor);

    virtual double widthFactor();

    virtual void  widthFactor(double value);

    virtual double heightFactor();

    virtual void  heightFactor(double value);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual void debugPaintSize(PaintingContext context, Offset offset);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _widthFactor;

    double _heightFactor;


};
using RenderPositionedBox = std::shared_ptr<RenderPositionedBoxCls>;

class RenderConstrainedOverflowBoxCls : public RenderAligningShiftedBoxCls {
public:

     RenderConstrainedOverflowBoxCls(AlignmentGeometry alignment, RenderBox child, double maxHeight, double maxWidth, double minHeight, double minWidth, TextDirection textDirection);

    virtual double minWidth();

    virtual void  minWidth(double value);

    virtual double maxWidth();

    virtual void  maxWidth(double value);

    virtual double minHeight();

    virtual void  minHeight(double value);

    virtual double maxHeight();

    virtual void  maxHeight(double value);

    virtual bool sizedByParent();

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _minWidth;

    double _maxWidth;

    double _minHeight;

    double _maxHeight;


    virtual BoxConstraints _getInnerConstraints(BoxConstraints constraints);

};
using RenderConstrainedOverflowBox = std::shared_ptr<RenderConstrainedOverflowBoxCls>;

class RenderConstraintsTransformBoxCls : public RenderAligningShiftedBoxCls {
public:

     RenderConstraintsTransformBoxCls(AlignmentGeometry alignment, RenderBox child, Clip clipBehavior, BoxConstraintsTransform constraintsTransform, TextDirection textDirection);

    virtual BoxConstraintsTransform constraintsTransform();

    virtual void  constraintsTransform(BoxConstraintsTransform value);

    virtual Clip clipBehavior();

    virtual void  clipBehavior(Clip value);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual void paint(PaintingContext context, Offset offset);

    virtual void dispose();

    virtual Rect describeApproximatePaintClip(RenderObject child);

    virtual String toStringShort();

private:
    BoxConstraintsTransform _constraintsTransform;

    Clip _clipBehavior;

    Rect _overflowContainerRect;

    Rect _overflowChildRect;

    bool _isOverflowing;

    BoxConstraints _childConstraints;

    LayerHandle<ClipRectLayer> _clipRectLayer;


};
using RenderConstraintsTransformBox = std::shared_ptr<RenderConstraintsTransformBoxCls>;

class RenderUnconstrainedBoxCls : public RenderConstraintsTransformBoxCls {
public:

     RenderUnconstrainedBoxCls(AlignmentGeometry alignment, RenderBox child, Clip clipBehavior, Axis constrainedAxis, TextDirection textDirection);

    virtual Axis constrainedAxis();

    virtual void  constrainedAxis(Axis value);

private:
    Axis _constrainedAxis;


    static BoxConstraints _unconstrained(BoxConstraints constraints);

    static BoxConstraints _widthConstrained(BoxConstraints constraints);

    static BoxConstraints _heightConstrained(BoxConstraints constraints);

    static BoxConstraintsTransform _convertAxis(Axis constrainedAxis);

};
using RenderUnconstrainedBox = std::shared_ptr<RenderUnconstrainedBoxCls>;

class RenderSizedOverflowBoxCls : public RenderAligningShiftedBoxCls {
public:

     RenderSizedOverflowBoxCls(AlignmentGeometry alignment, RenderBox child, Size requestedSize, TextDirection textDirection);

    virtual Size requestedSize();

    virtual void  requestedSize(Size value);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual double computeDistanceToActualBaseline(TextBaseline baseline);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

private:
    Size _requestedSize;


};
using RenderSizedOverflowBox = std::shared_ptr<RenderSizedOverflowBoxCls>;

class RenderFractionallySizedOverflowBoxCls : public RenderAligningShiftedBoxCls {
public:

     RenderFractionallySizedOverflowBoxCls(AlignmentGeometry alignment, RenderBox child, double heightFactor, TextDirection textDirection, double widthFactor);

    virtual double widthFactor();

    virtual void  widthFactor(double value);

    virtual double heightFactor();

    virtual void  heightFactor(double value);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _widthFactor;

    double _heightFactor;


    virtual BoxConstraints _getInnerConstraints(BoxConstraints constraints);

};
using RenderFractionallySizedOverflowBox = std::shared_ptr<RenderFractionallySizedOverflowBoxCls>;

class SingleChildLayoutDelegateCls : public ObjectCls {
public:

     SingleChildLayoutDelegateCls(Listenable relayout);

    virtual Size getSize(BoxConstraints constraints);

    virtual BoxConstraints getConstraintsForChild(BoxConstraints constraints);

    virtual Offset getPositionForChild(Size size, Size childSize);

    virtual bool shouldRelayout(SingleChildLayoutDelegate oldDelegate);
private:
    Listenable _relayout;


};
using SingleChildLayoutDelegate = std::shared_ptr<SingleChildLayoutDelegateCls>;

class RenderCustomSingleChildLayoutBoxCls : public RenderShiftedBoxCls {
public:

     RenderCustomSingleChildLayoutBoxCls(RenderBox child, SingleChildLayoutDelegate delegate);

    virtual SingleChildLayoutDelegate delegate();

    virtual void  delegate(SingleChildLayoutDelegate newDelegate);

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

private:
    SingleChildLayoutDelegate _delegate;


    virtual Size _getSize(BoxConstraints constraints);

};
using RenderCustomSingleChildLayoutBox = std::shared_ptr<RenderCustomSingleChildLayoutBoxCls>;

class RenderBaselineCls : public RenderShiftedBoxCls {
public:

     RenderBaselineCls(double baseline, TextBaseline baselineType, RenderBox child);

    virtual double baseline();

    virtual void  baseline(double value);

    virtual TextBaseline baselineType();

    virtual void  baselineType(TextBaseline value);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _baseline;

    TextBaseline _baselineType;


};
using RenderBaseline = std::shared_ptr<RenderBaselineCls>;


#endif