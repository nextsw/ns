#include "desktop_text_selection_toolbar_layout_delegate.hpp"
BoxConstraints DesktopTextSelectionToolbarLayoutDelegate::getConstraintsForChild(BoxConstraints constraints) {
    return constraints.loosen();
}

Offset DesktopTextSelectionToolbarLayoutDelegate::getPositionForChild(Size childSize, Size size) {
    Offset overhang = Offset(anchor.dx + childSize.width - size.width, anchor.dy + childSize.height - size.height);
    return Offset(overhang.dx > 0.0? anchor.dx - overhang.dx : anchor.dx, overhang.dy > 0.0? anchor.dy - overhang.dy : anchor.dy);
}

bool DesktopTextSelectionToolbarLayoutDelegate::shouldRelayout(DesktopTextSelectionToolbarLayoutDelegate oldDelegate) {
    return anchor != oldDelegate.anchor;
}
