#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_TEXT_SELECTION_TOOLBAR_LAYOUT_DELEGATE
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_TEXT_SELECTION_TOOLBAR_LAYOUT_DELEGATE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/rendering.hpp>


class TextSelectionToolbarLayoutDelegateCls : public SingleChildLayoutDelegateCls {
public:
    Offset anchorAbove;

    Offset anchorBelow;

    bool fitsAbove;


     TextSelectionToolbarLayoutDelegateCls(Offset anchorAbove, Offset anchorBelow, bool fitsAbove);
    virtual BoxConstraints getConstraintsForChild(BoxConstraints constraints);

    virtual Offset getPositionForChild(Size childSize, Size size);

    virtual bool shouldRelayout(TextSelectionToolbarLayoutDelegate oldDelegate);

private:

    static double _centerOn(double max, double position, double width);

};
using TextSelectionToolbarLayoutDelegate = std::shared_ptr<TextSelectionToolbarLayoutDelegateCls>;


#endif