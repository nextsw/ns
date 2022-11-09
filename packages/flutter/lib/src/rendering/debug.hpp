#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_DEBUG
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_DEBUG
#include <base.hpp>
#include <packages/flutter/lib/foundation.hpp>

#include <dart/core/core.hpp>
#include "object.hpp"

HSVColor _kDebugDefaultRepaintColor;

bool debugPaintSizeEnabled;

bool debugPaintBaselinesEnabled;

bool debugPaintLayerBordersEnabled;

bool debugPaintPointersEnabled;

bool debugRepaintRainbowEnabled;

bool debugRepaintTextRainbowEnabled;

HSVColor debugCurrentRepaintColor;

bool debugPrintMarkNeedsLayoutStacks;

bool debugPrintMarkNeedsPaintStacks;

bool debugPrintLayouts;

bool debugCheckIntrinsicSizes;

bool debugProfileLayoutsEnabled;

bool debugProfilePaintsEnabled;

bool debugEnhanceLayoutTimelineArguments;

bool debugEnhancePaintTimelineArguments;

ProfilePaintCallback debugOnProfilePaint;

bool debugDisableClipLayers;

bool debugDisablePhysicalShapeLayers;

bool debugDisableOpacityLayers;

void _debugDrawDoubleRect(Canvas canvas, Color color, Rect innerRect, Rect outerRect);

void debugPaintPadding(Canvas canvas, Rect innerRect, Rect outerRect, double outlineWidth);

bool debugAssertAllRenderVarsUnset(bool debugCheckIntrinsicSizesOverride, String reason);



#endif