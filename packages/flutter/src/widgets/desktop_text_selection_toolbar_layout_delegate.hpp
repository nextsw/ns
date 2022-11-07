#ifndef DESKTOP_TEXT_SELECTION_TOOLBAR_LAYOUT_DELEGATE_H
#define DESKTOP_TEXT_SELECTION_TOOLBAR_LAYOUT_DELEGATE_H
#include <memory>

#include <flutter/rendering.hpp>



class DesktopTextSelectionToolbarLayoutDelegate : SingleChildLayoutDelegate {
public:
    Offset anchor;


     DesktopTextSelectionToolbarLayoutDelegate(Offset anchor);

    BoxConstraints getConstraintsForChild(BoxConstraints constraints);

    Offset getPositionForChild(Size childSize, Size size);

    bool shouldRelayout(DesktopTextSelectionToolbarLayoutDelegate oldDelegate);

private:

};

#endif