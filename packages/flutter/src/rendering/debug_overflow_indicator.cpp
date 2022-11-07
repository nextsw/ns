#include "debug_overflow_indicator.hpp"
void DebugOverflowIndicatorMixin::paintOverflowIndicator(Rect childRect, Rect containerRect, PaintingContext context, Offset offset, List<DiagnosticsNode> overflowHints) {
    RelativeRect overflow = RelativeRect.fromRect(containerRect, childRect);
    if (overflow.left <= 0.0 && overflow.right <= 0.0 && overflow.top <= 0.0 && overflow.bottom <= 0.0) {
        return;
    }
    List<_OverflowRegionData> overflowRegions = _calculateOverflowRegions(overflow, containerRect);
    for (_OverflowRegionData region : overflowRegions) {
        context.canvas.drawRect(region.rect.shift(offset), _indicatorPaint);
        TextSpan textSpan = (;
        if (textSpan?.text != region.label) {
            _indicatorLabel[region.side.index].text = TextSpan(region.label, _indicatorTextStyle);
            _indicatorLabel[region.side.index].layout();
        }
        Offset labelOffset = region.labelOffset + offset;
        Offset centerOffset = Offset(-_indicatorLabel[region.side.index].width / 2.0, 0.0);
        Rect textBackgroundRect = centerOffset & _indicatorLabel[region.side.index].size;
        context.canvas.save();
        context.canvas.translate(labelOffset.dx, labelOffset.dy);
        context.canvas.rotate(region.rotation);
        context.canvas.drawRect(textBackgroundRect, _labelBackgroundPaint);
        _indicatorLabel[region.side.index].paint(context.canvas, centerOffset);
        context.canvas.restore();
    }
    if (_overflowReportNeeded) {
        _overflowReportNeeded = false;
        _reportOverflow(overflow, overflowHints);
    }
}

void DebugOverflowIndicatorMixin::reassemble() {
    super.reassemble();
    assert(());
}

String DebugOverflowIndicatorMixin::_formatPixels(double value) {
    assert(value > 0.0);
    String pixels;
    if (value > 10.0) {
        pixels = value.toStringAsFixed(0);
    } else     {
        if (value > 1.0) {
        pixels = value.toStringAsFixed(1);
    } else {
        pixels = value.toStringAsPrecision(3);
    }
;
    }    return pixels;
}

List<_OverflowRegionData> DebugOverflowIndicatorMixin::_calculateOverflowRegions(Rect containerRect, RelativeRect overflow) {
    List<_OverflowRegionData> regions = ;
    if (overflow.left > 0.0) {
        Rect markerRect = Rect.fromLTWH(0.0, 0.0, containerRect.width * _indicatorFraction, containerRect.height);
        regions.add(_OverflowRegionData(markerRect, "LEFT OVERFLOWED BY ${_formatPixels(overflow.left)} PIXELS", markerRect.centerLeft + const Offset(_indicatorFontSizePixels + _indicatorLabelPaddingPixels, 0.0), math.pi / 2.0, _OverflowSide.left));
    }
    if (overflow.right > 0.0) {
        Rect markerRect = Rect.fromLTWH(containerRect.width * (1.0 - _indicatorFraction), 0.0, containerRect.width * _indicatorFraction, containerRect.height);
        regions.add(_OverflowRegionData(markerRect, "RIGHT OVERFLOWED BY ${_formatPixels(overflow.right)} PIXELS", markerRect.centerRight - const Offset(_indicatorFontSizePixels + _indicatorLabelPaddingPixels, 0.0), -math.pi / 2.0, _OverflowSide.right));
    }
    if (overflow.top > 0.0) {
        Rect markerRect = Rect.fromLTWH(0.0, 0.0, containerRect.width, containerRect.height * _indicatorFraction);
        regions.add(_OverflowRegionData(markerRect, "TOP OVERFLOWED BY ${_formatPixels(overflow.top)} PIXELS", markerRect.topCenter + const Offset(0.0, _indicatorLabelPaddingPixels), _OverflowSide.top));
    }
    if (overflow.bottom > 0.0) {
        Rect markerRect = Rect.fromLTWH(0.0, containerRect.height * (1.0 - _indicatorFraction), containerRect.width, containerRect.height * _indicatorFraction);
        regions.add(_OverflowRegionData(markerRect, "BOTTOM OVERFLOWED BY ${_formatPixels(overflow.bottom)} PIXELS", markerRect.bottomCenter - const Offset(0.0, _indicatorFontSizePixels + _indicatorLabelPaddingPixels), _OverflowSide.bottom));
    }
    return regions;
}

void DebugOverflowIndicatorMixin::_reportOverflow(RelativeRect overflow, List<DiagnosticsNode> overflowHints) {
    overflowHints = ;
    if (overflowHints.isEmpty) {
        overflowHints.add(ErrorDescription("The edge of the $runtimeType that is overflowing has been marked in the rendering with a yellow and black striped pattern. This is usually caused by the contents being too big for the $runtimeType."));
        overflowHints.add(ErrorHint("This is considered an error condition because it indicates that there is content that cannot be seen. If the content is legitimately bigger than the available space, consider clipping it with a ClipRect widget before putting it in the $runtimeType, or using a scrollable container, like a ListView."));
    }
    List<String> overflows = ;
    String overflowText = "";
    assert(overflows.isNotEmpty, "Somehow $runtimeType didn't actually overflow like it thought it did.");
    ;
    FlutterError.reportError(FlutterErrorDetails(FlutterError("A $runtimeType overflowed by $overflowText."), "rendering library", ErrorDescription("during layout"), ));
}
