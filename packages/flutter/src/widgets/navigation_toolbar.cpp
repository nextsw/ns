#include "navigation_toolbar.hpp"
NavigationToolbar::NavigationToolbar(bool centerMiddle, Unknown, Widget leading, Widget middle, double middleSpacing, Widget trailing) {
    {
        assert(centerMiddle != nullptr);
        assert(middleSpacing != nullptr);
    }
}

Widget NavigationToolbar::build(BuildContext context) {
    assert(debugCheckHasDirectionality(context));
    TextDirection textDirection = Directionality.of(context);
    return CustomMultiChildLayout(_ToolbarLayout(centerMiddle, middleSpacing, textDirection), );
}

void _ToolbarLayout::performLayout(Size size) {
    double leadingWidth = 0.0;
    double trailingWidth = 0.0;
    if (hasChild(_ToolbarSlot.leading)) {
        BoxConstraints constraints = BoxConstraints(size.width / 3.0, size.height, size.height);
        leadingWidth = layoutChild(_ToolbarSlot.leading, constraints).width;
        double leadingX;
        ;
        positionChild(_ToolbarSlot.leading, Offset(leadingX, 0.0));
    }
    if (hasChild(_ToolbarSlot.trailing)) {
        BoxConstraints constraints = BoxConstraints.loose(size);
        Size trailingSize = layoutChild(_ToolbarSlot.trailing, constraints);
        double trailingX;
        ;
        double trailingY = (size.height - trailingSize.height) / 2.0;
        trailingWidth = trailingSize.width;
        positionChild(_ToolbarSlot.trailing, Offset(trailingX, trailingY));
    }
    if (hasChild(_ToolbarSlot.middle)) {
        double maxWidth = math.max(size.width - leadingWidth - trailingWidth - middleSpacing * 2.0, 0.0);
        BoxConstraints constraints = BoxConstraints.loose(size).copyWith(maxWidth);
        Size middleSize = layoutChild(_ToolbarSlot.middle, constraints);
        double middleStartMargin = leadingWidth + middleSpacing;
        double middleStart = middleStartMargin;
        double middleY = (size.height - middleSize.height) / 2.0;
        if (centerMiddle) {
            middleStart = (size.width - middleSize.width) / 2.0;
            if (middleStart + middleSize.width > size.width - trailingWidth) {
                middleStart = size.width - trailingWidth - middleSize.width;
            } else             {
                if ( < middleStartMargin) {
                middleStart = middleStartMargin;
            }
;
            }        }
        double middleX;
        ;
        positionChild(_ToolbarSlot.middle, Offset(middleX, middleY));
    }
}

bool _ToolbarLayout::shouldRelayout(_ToolbarLayout oldDelegate) {
    return oldDelegate.centerMiddle != centerMiddle || oldDelegate.middleSpacing != middleSpacing || oldDelegate.textDirection != textDirection;
}

_ToolbarLayout::_ToolbarLayout(bool centerMiddle, double middleSpacing, TextDirection textDirection) {
    {
        assert(middleSpacing != nullptr);
        assert(textDirection != nullptr);
    }
}
