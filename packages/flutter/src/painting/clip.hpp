#ifndef PACKAGES_FLUTTER_SRC_PAINTING_CLIP
#define PACKAGES_FLUTTER_SRC_PAINTING_CLIP
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>


class ClipContextCls : public ObjectCls {
public:

    virtual Canvas canvas();
    virtual void clipPathAndPaint(Path path, Clip clipBehavior, Rect bounds, VoidCallback painter);

    virtual void clipRRectAndPaint(RRect rrect, Clip clipBehavior, Rect bounds, VoidCallback painter);

    virtual void clipRectAndPaint(Rect rect, Clip clipBehavior, Rect bounds, VoidCallback painter);

private:

    virtual void _clipAndPaint(std::function<void(bool doAntiAlias)> canvasClipCall, Clip clipBehavior, Rect bounds, VoidCallback painter);

};
using ClipContext = std::shared_ptr<ClipContextCls>;


#endif