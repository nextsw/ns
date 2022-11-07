#include "clip.hpp"
void ClipContext::clipPathAndPaint(Rect bounds, Clip clipBehavior, VoidCallback painter, Path path) {
    _clipAndPaint(, clipBehavior, bounds, painter);
}

void ClipContext::clipRRectAndPaint(Rect bounds, Clip clipBehavior, VoidCallback painter, RRect rrect) {
    _clipAndPaint(, clipBehavior, bounds, painter);
}

void ClipContext::clipRectAndPaint(Rect bounds, Clip clipBehavior, VoidCallback painter, Rect rect) {
    _clipAndPaint(, clipBehavior, bounds, painter);
}

void ClipContext::_clipAndPaint(Rect bounds, FunctionType canvasClipCall, Clip clipBehavior, VoidCallback painter) {
    assert(canvasClipCall != nullptr);
    canvas.save();
    ;
    painter();
    if (clipBehavior == Clip.antiAliasWithSaveLayer) {
        canvas.restore();
    }
    canvas.restore();
}
