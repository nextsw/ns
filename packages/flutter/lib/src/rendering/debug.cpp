#include "debug.hpp"
void _debugDrawDoubleRect(Canvas canvas, Color color, Rect innerRect, Rect outerRect) {
    auto _c1 = make<PathCls>();_c1.fillType = auto _c2 = PathFillTypeCls::evenOdd;_c2.auto _c3 = addRect(outerRect);_c3.addRect(innerRect);_c3;_c2;Path path = _c1;
    auto _c4 = make<PaintCls>();_c4.color = color;Paint paint = _c4;
    canvas->drawPath(path, paint);
}

void debugPaintPadding(Canvas canvas, Rect innerRect, Rect outerRect, double outlineWidth) {
    assert([=] () {
        if (innerRect != nullptr && !innerRect->isEmpty()) {
            _debugDrawDoubleRect(canvas, outerRect, innerRect, make<ColorCls>(0x900090FF));
            _debugDrawDoubleRect(canvas, innerRect->inflate(outlineWidth)->intersect(outerRect), innerRect, make<ColorCls>(0xFF0090FF));
        } else {
                    auto _c1 = make<PaintCls>();        _c1.color = make<ColorCls>(0x90909090);Paint paint = _c1;
            canvas->drawRect(outerRect, paint);
        }
        return true;
    }());
}

bool debugAssertAllRenderVarsUnset(bool debugCheckIntrinsicSizesOverride, String reason) {
    assert([=] () {
        if (debugPaintSizeEnabled || debugPaintBaselinesEnabled || debugPaintLayerBordersEnabled || debugPaintPointersEnabled || debugRepaintRainbowEnabled || debugRepaintTextRainbowEnabled || debugCurrentRepaintColor != _kDebugDefaultRepaintColor || debugPrintMarkNeedsLayoutStacks || debugPrintMarkNeedsPaintStacks || debugPrintLayouts || debugCheckIntrinsicSizes != debugCheckIntrinsicSizesOverride || debugProfileLayoutsEnabled || debugProfilePaintsEnabled || debugOnProfilePaint != nullptr || debugDisableClipLayers || debugDisablePhysicalShapeLayers || debugDisableOpacityLayers) {
            ;
        }
        return true;
    }());
    return true;
}
