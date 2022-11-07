#ifndef ORIENTATION_BUILDER_H
#define ORIENTATION_BUILDER_H
#include <memory>

#include "basic.hpp"
#include "framework.hpp"
#include "layout_builder.hpp"
#include "media_query.hpp"



class OrientationBuilder : StatelessWidget {
public:
    OrientationWidgetBuilder builder;


     OrientationBuilder(OrientationWidgetBuilder builder, Unknown);

    Widget build(BuildContext context);

private:

    Widget _buildWithConstraints(BoxConstraints constraints, BuildContext context);

};

#endif