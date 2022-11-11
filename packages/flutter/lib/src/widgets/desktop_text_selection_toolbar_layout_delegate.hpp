#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DESKTOP_TEXT_SELECTION_TOOLBAR_LAYOUT_DELEGATE
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DESKTOP_TEXT_SELECTION_TOOLBAR_LAYOUT_DELEGATE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/rendering.hpp>


class DesktopTextSelectionToolbarLayoutDelegateCls : public SingleChildLayoutDelegateCls {
public:
    Offset anchor;


     DesktopTextSelectionToolbarLayoutDelegateCls(Offset anchor);
    virtual BoxConstraints getConstraintsForChild(BoxConstraints constraints);

    virtual Offset getPositionForChild(Size size, Size childSize);

    virtual bool shouldRelayout(DesktopTextSelectionToolbarLayoutDelegate oldDelegate);

private:

};
using DesktopTextSelectionToolbarLayoutDelegate = std::shared_ptr<DesktopTextSelectionToolbarLayoutDelegateCls>;


#endif