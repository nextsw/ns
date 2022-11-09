#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_LAYOUT_HELPER
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_LAYOUT_HELPER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include "box.hpp"


class ChildLayoutHelperCls : public ObjectCls {
public:

    static Size dryLayoutChild(RenderBox child, BoxConstraints constraints);

    static Size layoutChild(RenderBox child, BoxConstraints constraints);

private:

    virtual void  _();
};
using ChildLayoutHelper = std::shared_ptr<ChildLayoutHelperCls>;


#endif