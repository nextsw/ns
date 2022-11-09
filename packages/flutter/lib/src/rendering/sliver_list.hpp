#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_SLIVER_LIST
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_SLIVER_LIST
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "box.hpp"
#include "sliver.hpp"
#include "sliver_multi_box_adaptor.hpp"


class RenderSliverListCls : public RenderSliverMultiBoxAdaptorCls {
public:

     RenderSliverListCls(Unknown childManager);
    virtual void performLayout();

private:

};
using RenderSliverList = std::shared_ptr<RenderSliverListCls>;


#endif