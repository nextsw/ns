#ifndef DEBUG_OVERFLOW_INDICATOR_H
#define DEBUG_OVERFLOW_INDICATOR_H
#include <memory>

#include <math/math.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "object.hpp"
#include "stack.hpp"



enum _OverflowSide{
    left,
    top,
    bottom,
    right,
} // end _OverflowSide

class _OverflowRegionData {
public:
    Rect rect;

    String label;

    Offset labelOffset;

    double rotation;

    _OverflowSide side;


private:

     _OverflowRegionData(String label, Offset labelOffset, Rect rect, double rotation, _OverflowSide side);

};

class DebugOverflowIndicatorMixin {
public:

    void paintOverflowIndicator(Rect childRect, Rect containerRect, PaintingContext context, Offset offset, List<DiagnosticsNode> overflowHints);

    void reassemble();

private:
    static const Color _black;

    static const Color _yellow;

    static const double _indicatorFraction;

    static const double _indicatorFontSizePixels;

    static const double _indicatorLabelPaddingPixels;

    static const TextStyle _indicatorTextStyle;

    static Paint _indicatorPaint;

    static Paint _labelBackgroundPaint;

    List<TextPainter> _indicatorLabel;

    bool _overflowReportNeeded;


    String _formatPixels(double value);

    List<_OverflowRegionData> _calculateOverflowRegions(Rect containerRect, RelativeRect overflow);

    void _reportOverflow(RelativeRect overflow, List<DiagnosticsNode> overflowHints);

};

#endif