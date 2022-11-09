#ifndef PACKAGES_FLUTTER_SRC_PAINTING_CLIP
#define PACKAGES_FLUTTER_SRC_PAINTING_CLIP
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>


class ClipContextCls : public ObjectCls {
public:

    virtual Canvas canvas();
    virtual void clipPathAndPaint(Rect bounds, Clip clipBehavior, VoidCallback painter, Path path);

    virtual void clipRRectAndPaint(Rect bounds, Clip clipBehavior, VoidCallback painter, RRect rrect);

    virtual void clipRectAndPaint(Rect bounds, Clip clipBehavior, VoidCallback painter, Rect rect);

private:

    virtual void _clipAndPaint(Rect bounds, void canvasClipCall(bool doAntiAlias) , Clip clipBehavior, VoidCallback painter);

};
using ClipContext = std::shared_ptr<ClipContextCls>;


#endif