#include "clip.hpp"
void ClipContextCls::clipPathAndPaint(Path path, Clip clipBehavior, Rect bounds, VoidCallback painter) {
    _clipAndPaint([=] (bool doAntiAlias) {
        canvas()->clipPath(path, doAntiAlias);
    }, clipBehavior, bounds, painter);
}

void ClipContextCls::clipRRectAndPaint(RRect rrect, Clip clipBehavior, Rect bounds, VoidCallback painter) {
    _clipAndPaint([=] (bool doAntiAlias) {
        canvas()->clipRRect(rrect, doAntiAlias);
    }, clipBehavior, bounds, painter);
}

void ClipContextCls::clipRectAndPaint(Rect rect, Clip clipBehavior, Rect bounds, VoidCallback painter) {
    _clipAndPaint([=] (bool doAntiAlias) {
        canvas()->clipRect(rect, doAntiAlias);
    }, clipBehavior, bounds, painter);
}

void ClipContextCls::_clipAndPaint(std::function<void(bool doAntiAlias)> canvasClipCall, Clip clipBehavior, Rect bounds, VoidCallback painter) {
    assert(canvasClipCall != nullptr);
    canvas()->save();
    ;
    painter();
    if (clipBehavior == ClipCls::antiAliasWithSaveLayer) {
        canvas()->restore();
    }
    canvas()->restore();
}
