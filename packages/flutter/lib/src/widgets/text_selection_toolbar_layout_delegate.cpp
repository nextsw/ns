#include "text_selection_toolbar_layout_delegate.hpp"
BoxConstraints TextSelectionToolbarLayoutDelegateCls::getConstraintsForChild(BoxConstraints constraints) {
    return constraints->loosen();
}

Offset TextSelectionToolbarLayoutDelegateCls::getPositionForChild(Size size, Size childSize) {
    bool fitsAbove = this->fitsAbove | anchorAbove->dy() >= childSize->height();
    Offset anchor = fitsAbove? anchorAbove : anchorBelow;
    return make<OffsetCls>(_centerOn(anchor->dx(), childSize->width(), size->width()), fitsAbove? math->max(0.0, anchor->dy() - childSize->height()) : anchor->dy());
}

bool TextSelectionToolbarLayoutDelegateCls::shouldRelayout(TextSelectionToolbarLayoutDelegate oldDelegate) {
    return anchorAbove != oldDelegate->anchorAbove || anchorBelow != oldDelegate->anchorBelow || fitsAbove != oldDelegate->fitsAbove;
}

double TextSelectionToolbarLayoutDelegateCls::_centerOn(double position, double width, double max) {
    if (position - width / 2.0 < 0.0) {
        return 0.0;
    }
    if (position + width / 2.0 > max) {
        return max - width;
    }
    return position - width / 2.0;
}
