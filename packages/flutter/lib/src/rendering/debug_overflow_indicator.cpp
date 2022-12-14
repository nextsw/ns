#include "debug_overflow_indicator.hpp"
void DebugOverflowIndicatorMixinCls::paintOverflowIndicator(PaintingContext context, Offset offset, Rect containerRect, Rect childRect, List<DiagnosticsNode> overflowHints) {
    RelativeRect overflow = RelativeRectCls->fromRect(containerRect, childRect);
    if (overflow->left <= 0.0 && overflow->right <= 0.0 && overflow->top <= 0.0 && overflow->bottom <= 0.0) {
        return;
    }
    List<_OverflowRegionData> overflowRegions = _calculateOverflowRegions(overflow, containerRect);
    for (_OverflowRegionData region : overflowRegions) {
        context->canvas()->drawRect(region->rect->shift(offset), _indicatorPaint);
        TextSpan textSpan = as<TextSpan>(_indicatorLabel[region->side->index]->text());
        if (textSpan?->text != region->label) {
            _indicatorLabel[region->side->index]->text() = make<TextSpanCls>(region->label, _indicatorTextStyle);
            _indicatorLabel[region->side->index]->layout();
        }
        Offset labelOffset = region->labelOffset + offset;
        Offset centerOffset = make<OffsetCls>(-_indicatorLabel[region->side->index]->width() / 2.0, 0.0);
        Rect textBackgroundRect = centerOffset & _indicatorLabel[region->side->index]->size();
        context->canvas()->save();
        context->canvas()->translate(labelOffset->dx(), labelOffset->dy());
        context->canvas()->rotate(region->rotation);
        context->canvas()->drawRect(textBackgroundRect, _labelBackgroundPaint);
        _indicatorLabel[region->side->index]->paint(context->canvas(), centerOffset);
        context->canvas()->restore();
    }
    if (_overflowReportNeeded) {
        _overflowReportNeeded = false;
        _reportOverflow(overflow, overflowHints);
    }
}

void DebugOverflowIndicatorMixinCls::reassemble() {
    super->reassemble();
    assert([=] () {
        _overflowReportNeeded = true;
        return true;
    }());
}

String DebugOverflowIndicatorMixinCls::_formatPixels(double value) {
    assert(value > 0.0);
    String pixels;
    if (value > 10.0) {
        pixels = value->toStringAsFixed(0);
    } else {
        if (value > 1.0) {
        pixels = value->toStringAsFixed(1);
    } else {
        pixels = value->toStringAsPrecision(3);
    }
;
    }    return pixels;
}

List<_OverflowRegionData> DebugOverflowIndicatorMixinCls::_calculateOverflowRegions(RelativeRect overflow, Rect containerRect) {
    List<_OverflowRegionData> regions = makeList();
    if (overflow->left > 0.0) {
        Rect markerRect = RectCls->fromLTWH(0.0, 0.0, containerRect->width() * _indicatorFraction, containerRect->height());
        regions->add(make<_OverflowRegionDataCls>(markerRect, __sf("LEFT OVERFLOWED BY %s PIXELS", _formatPixels(overflow->left)), markerRect->centerLeft() + make<OffsetCls>(_indicatorFontSizePixels + _indicatorLabelPaddingPixels, 0.0), math->pi / 2.0, _OverflowSideCls::left));
    }
    if (overflow->right > 0.0) {
        Rect markerRect = RectCls->fromLTWH(containerRect->width() * (1.0 - _indicatorFraction), 0.0, containerRect->width() * _indicatorFraction, containerRect->height());
        regions->add(make<_OverflowRegionDataCls>(markerRect, __sf("RIGHT OVERFLOWED BY %s PIXELS", _formatPixels(overflow->right)), markerRect->centerRight() - make<OffsetCls>(_indicatorFontSizePixels + _indicatorLabelPaddingPixels, 0.0), -math->pi / 2.0, _OverflowSideCls::right));
    }
    if (overflow->top > 0.0) {
        Rect markerRect = RectCls->fromLTWH(0.0, 0.0, containerRect->width(), containerRect->height() * _indicatorFraction);
        regions->add(make<_OverflowRegionDataCls>(markerRect, __sf("TOP OVERFLOWED BY %s PIXELS", _formatPixels(overflow->top)), markerRect->topCenter() + make<OffsetCls>(0.0, _indicatorLabelPaddingPixels), _OverflowSideCls::top));
    }
    if (overflow->bottom > 0.0) {
        Rect markerRect = RectCls->fromLTWH(0.0, containerRect->height() * (1.0 - _indicatorFraction), containerRect->width(), containerRect->height() * _indicatorFraction);
        regions->add(make<_OverflowRegionDataCls>(markerRect, __sf("BOTTOM OVERFLOWED BY %s PIXELS", _formatPixels(overflow->bottom)), markerRect->bottomCenter() - make<OffsetCls>(0.0, _indicatorFontSizePixels + _indicatorLabelPaddingPixels), _OverflowSideCls::bottom));
    }
    return regions;
}

void DebugOverflowIndicatorMixinCls::_reportOverflow(RelativeRect overflow, List<DiagnosticsNode> overflowHints) {
    overflowHints |= makeList();
    if (overflowHints->isEmpty()) {
        overflowHints->add(make<ErrorDescriptionCls>(__sf("The edge of the %s that is overflowing has been marked in the rendering with a yellow and black striped pattern. This is usually caused by the contents being too big for the %s.", runtimeType, runtimeType)));
        overflowHints->add(make<ErrorHintCls>(__sf("This is considered an error condition because it indicates that there is content that cannot be seen. If the content is legitimately bigger than the available space, consider clipping it with a ClipRect widget before putting it in the %s, or using a scrollable container, like a ListView.", runtimeType)));
    }
    List<String> list1 = make<ListCls<>>();if (overflow->left > 0.0) {    list1.add(ArrayItem);}if (overflow->top > 0.0) {    list1.add(ArrayItem);}if (overflow->bottom > 0.0) {    list1.add(ArrayItem);}if (overflow->right > 0.0) {    list1.add(ArrayItem);}List<String> overflows = list1;
    String overflowText = __s("");
    assert(overflows->isNotEmpty(), __sf("Somehow %s didn't actually overflow like it thought it did.", runtimeType));
    ;
    List<DiagnosticsNode> list2 = make<ListCls<>>();if (kDebugMode && debugCreator != nullptr) {    list2.add(ArrayItem);}for (auto _x2 : overflowHints!) {{    list2.add(_x2);}list2.add(ArrayItem);list2.add(ArrayItem);FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(make<FlutterErrorCls>(__sf("A %s overflowed by %s.", runtimeType, overflowText)), __s("rendering library"), make<ErrorDescriptionCls>(__s("during layout")), [=] () {
        list2;
    }));
}
