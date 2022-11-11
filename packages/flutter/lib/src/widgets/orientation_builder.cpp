#include "orientation_builder.hpp"
OrientationBuilderCls::OrientationBuilderCls(OrientationWidgetBuilder builder, Unknown key) {
    {
        assert(builder != nullptr);
    }
}

Widget OrientationBuilderCls::build(BuildContext context) {
    return make<LayoutBuilderCls>(_buildWithConstraints);
}

Widget OrientationBuilderCls::_buildWithConstraints(BoxConstraints constraints, BuildContext context) {
    Orientation orientation = constraints->maxWidth > constraints->maxHeight? OrientationCls::landscape : OrientationCls::portrait;
    return builder(context, orientation);
}