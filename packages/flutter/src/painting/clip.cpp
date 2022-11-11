#include "clip.hpp"
void ClipContextCls::clipPathAndPaint(Rect bounds, Clip clipBehavior, VoidCallback painter, Path path) {
    _clipAndPaint([=] (bool doAntiAlias)     {
        canvas()->clipPath(pathdoAntiAlias);
    }, clipBehavior, bounds, painter);
}

void ClipContextCls::clipRRectAndPaint(Rect bounds, Clip clipBehavior, VoidCallback painter, RRect rrect) {
    _clipAndPaint([=] (bool doAntiAlias)     {
        canvas()->clipRRect(rrectdoAntiAlias);
    }, clipBehavior, bounds, painter);
}

void ClipContextCls::clipRectAndPaint(Rect bounds, Clip clipBehavior, VoidCallback painter, Rect rect) {
    _clipAndPaint([=] (bool doAntiAlias)     {
        canvas()->clipRect(rectdoAntiAlias);
    }, clipBehavior, bounds, painter);
}

void ClipContextCls::_clipAndPaint(Rect bounds, void canvasClipCall(bool doAntiAlias) , Clip clipBehavior, VoidCallback painter) {
    assert(canvasClipCall != nullptr);
    canvas()->save();
    ;
    painter();
    if (clipBehavior == ClipCls::antiAliasWithSaveLayer) {
        canvas()->restore();
    }
    canvas()->restore();
}
