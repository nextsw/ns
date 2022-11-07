#ifndef CLIP_H
#define CLIP_H
#include <memory>

#include <ui/ui.hpp>



class ClipContext {
public:

    Canvas canvas();

    void clipPathAndPaint(Rect bounds, Clip clipBehavior, VoidCallback painter, Path path);

    void clipRRectAndPaint(Rect bounds, Clip clipBehavior, VoidCallback painter, RRect rrect);

    void clipRectAndPaint(Rect bounds, Clip clipBehavior, VoidCallback painter, Rect rect);

private:

    void _clipAndPaint(Rect bounds, FunctionType canvasClipCall, Clip clipBehavior, VoidCallback painter);

};

#endif