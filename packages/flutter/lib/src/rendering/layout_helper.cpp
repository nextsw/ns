#include "layout_helper.hpp"
Size ChildLayoutHelperCls::dryLayoutChild(RenderBox child, BoxConstraints constraints) {
    return child->getDryLayout(constraints);
}

Size ChildLayoutHelperCls::layoutChild(RenderBox child, BoxConstraints constraints) {
    child->layout(constraints, true);
    return child->size();
}
