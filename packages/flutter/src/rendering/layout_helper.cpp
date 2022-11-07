#include "layout_helper.hpp"
Size ChildLayoutHelper::dryLayoutChild(RenderBox child, BoxConstraints constraints) {
    return child.getDryLayout(constraints);
}

Size ChildLayoutHelper::layoutChild(RenderBox child, BoxConstraints constraints) {
    child.layout(constraintstrue);
    return child.size;
}
