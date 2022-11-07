#include "text_selection_toolbar_layout_delegate.hpp"
BoxConstraints TextSelectionToolbarLayoutDelegate::getConstraintsForChild(BoxConstraints constraints) {
    return constraints.loosen();
}

Offset TextSelectionToolbarLayoutDelegate::getPositionForChild(Size childSize, Size size) {
    bool fitsAbove = this.fitsAbove ?? anchorAbove.dy >= childSize.height;
    Offset anchor = fitsAbove? anchorAbove : anchorBelow;
    return Offset(_centerOn(anchor.dx, childSize.width, size.width), fitsAbove? math.max(0.0, anchor.dy - childSize.height) : anchor.dy);
}

bool TextSelectionToolbarLayoutDelegate::shouldRelayout(TextSelectionToolbarLayoutDelegate oldDelegate) {
    return anchorAbove != oldDelegate.anchorAbove || anchorBelow != oldDelegate.anchorBelow || fitsAbove != oldDelegate.fitsAbove;
}

double TextSelectionToolbarLayoutDelegate::_centerOn(double max, double position, double width) {
    if (position - width / 2.0 < 0.0) {
        return 0.0;
    }
    if (position + width / 2.0 > max) {
        return max - width;
    }
    return position - width / 2.0;
}
