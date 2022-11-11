#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ORIENTATION_BUILDER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ORIENTATION_BUILDER
#include <base.hpp>

#include <dart/core/core.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "layout_builder.hpp"
#include "media_query.hpp"


class OrientationBuilderCls : public StatelessWidgetCls {
public:
    OrientationWidgetBuilder builder;


     OrientationBuilderCls(OrientationWidgetBuilder builder, Key key);

    virtual Widget build(BuildContext context);

private:

    virtual Widget _buildWithConstraints(BuildContext context, BoxConstraints constraints);

};
using OrientationBuilder = std::shared_ptr<OrientationBuilderCls>;


#endif