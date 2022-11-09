#ifndef PACKAGES_FLUTTER_SRC_GESTURES_DRAG
#define PACKAGES_FLUTTER_SRC_GESTURES_DRAG
#include <base.hpp>
#include "drag_details.hpp"

#include <dart/core/core.hpp>
#include "drag_details.hpp"


class DragCls : public ObjectCls {
public:

    virtual void update(DragUpdateDetails details);

    virtual void end(DragEndDetails details);

    virtual void cancel();

private:

};
using Drag = std::shared_ptr<DragCls>;


#endif