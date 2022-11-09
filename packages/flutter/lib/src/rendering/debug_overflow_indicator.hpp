#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_DEBUG_OVERFLOW_INDICATOR
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_DEBUG_OVERFLOW_INDICATOR
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "object.hpp"
#include "stack.hpp"


enum _OverflowSide{
    left,
    top,
    bottom,
    right,
} // end _OverflowSide

class _OverflowRegionDataCls : public ObjectCls {
public:
    Rect rect;

    String label;

    Offset labelOffset;

    double rotation;

    _OverflowSide side;


private:

     _OverflowRegionDataCls(String label, Offset labelOffset, Rect rect, double rotation, _OverflowSide side);
};
using _OverflowRegionData = std::shared_ptr<_OverflowRegionDataCls>;

class DebugOverflowIndicatorMixinCls : public ObjectCls {
public:

    virtual void paintOverflowIndicator(Rect childRect, Rect containerRect, PaintingContext context, Offset offset, List<DiagnosticsNode> overflowHints);

    virtual void reassemble();

private:
    static Color _black;

    static Color _yellow;

    static double _indicatorFraction;

    static double _indicatorFontSizePixels;

    static double _indicatorLabelPaddingPixels;

    static TextStyle _indicatorTextStyle;

    static Paint _indicatorPaint;

    static Paint _labelBackgroundPaint;

    List<TextPainter> _indicatorLabel;

    bool _overflowReportNeeded;


    virtual String _formatPixels(double value);

    virtual List<_OverflowRegionData> _calculateOverflowRegions(Rect containerRect, RelativeRect overflow);

    virtual void _reportOverflow(RelativeRect overflow, List<DiagnosticsNode> overflowHints);

};
using DebugOverflowIndicatorMixin = std::shared_ptr<DebugOverflowIndicatorMixinCls>;


#endif