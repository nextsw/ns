#ifndef TEXT_SELECTION_TOOLBAR_LAYOUT_DELEGATE_H
#define TEXT_SELECTION_TOOLBAR_LAYOUT_DELEGATE_H
#include <memory>

#include <math/math.hpp>
#include <flutter/rendering.hpp>



class TextSelectionToolbarLayoutDelegate : SingleChildLayoutDelegate {
public:
    Offset anchorAbove;

    Offset anchorBelow;

    bool fitsAbove;


     TextSelectionToolbarLayoutDelegate(Offset anchorAbove, Offset anchorBelow, bool fitsAbove);

    BoxConstraints getConstraintsForChild(BoxConstraints constraints);

    Offset getPositionForChild(Size childSize, Size size);

    bool shouldRelayout(TextSelectionToolbarLayoutDelegate oldDelegate);

private:

    static double _centerOn(double max, double position, double width);

};

#endif