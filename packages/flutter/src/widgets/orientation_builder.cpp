#include "orientation_builder.hpp"
OrientationBuilder::OrientationBuilder(OrientationWidgetBuilder builder, Unknown) {
    {
        assert(builder != nullptr);
    }
}

Widget OrientationBuilder::build(BuildContext context) {
    return LayoutBuilder(_buildWithConstraints);
}

Widget OrientationBuilder::_buildWithConstraints(BoxConstraints constraints, BuildContext context) {
    Orientation orientation = constraints.maxWidth > constraints.maxHeight? Orientation.landscape : Orientation.portrait;
    return builder(context, orientation);
}
