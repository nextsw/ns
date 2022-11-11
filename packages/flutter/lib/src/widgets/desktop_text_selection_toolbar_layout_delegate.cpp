#include "desktop_text_selection_toolbar_layout_delegate.hpp"
BoxConstraints DesktopTextSelectionToolbarLayoutDelegateCls::getConstraintsForChild(BoxConstraints constraints) {
    return constraints->loosen();
}

Offset DesktopTextSelectionToolbarLayoutDelegateCls::getPositionForChild(Size childSize, Size size) {
    Offset overhang = make<OffsetCls>(anchor->dx() + childSize->width() - size->width(), anchor->dy() + childSize->height() - size->height());
    return make<OffsetCls>(overhang->dx() > 0.0? anchor->dx() - overhang->dx() : anchor->dx(), overhang->dy() > 0.0? anchor->dy() - overhang->dy() : anchor->dy());
}

bool DesktopTextSelectionToolbarLayoutDelegateCls::shouldRelayout(DesktopTextSelectionToolbarLayoutDelegate oldDelegate) {
    return anchor != oldDelegate->anchor;
}
