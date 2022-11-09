#include "navigation_toolbar.hpp"
NavigationToolbarCls::NavigationToolbarCls(bool centerMiddle, Unknown key, Widget leading, Widget middle, double middleSpacing, Widget trailing) {
    {
        assert(centerMiddle != nullptr);
        assert(middleSpacing != nullptr);
    }
}

Widget NavigationToolbarCls::build(BuildContext context) {
    assert(debugCheckHasDirectionality(context));
    TextDirection textDirection = DirectionalityCls->of(context);
    List<Widget> list1 = make<ListCls<>>();if (leading != nullptr) {    list1.add(ArrayItem);}if (middle != nullptr) {    list1.add(ArrayItem);}if (trailing != nullptr) {    list1.add(ArrayItem);}return make<CustomMultiChildLayoutCls>(make<_ToolbarLayoutCls>(centerMiddle, middleSpacing, textDirection), list1);
}

void _ToolbarLayoutCls::performLayout(Size size) {
    double leadingWidth = 0.0;
    double trailingWidth = 0.0;
    if (hasChild(_ToolbarSlotCls::leading)) {
        BoxConstraints constraints = make<BoxConstraintsCls>(size->width / 3.0, size->height, size->height);
        leadingWidth = layoutChild(_ToolbarSlotCls::leading, constraints)->width;
        double leadingX;
        ;
        positionChild(_ToolbarSlotCls::leading, make<OffsetCls>(leadingX, 0.0));
    }
    if (hasChild(_ToolbarSlotCls::trailing)) {
        BoxConstraints constraints = BoxConstraintsCls->loose(size);
        Size trailingSize = layoutChild(_ToolbarSlotCls::trailing, constraints);
        double trailingX;
        ;
        double trailingY = (size->height - trailingSize->height) / 2.0;
        trailingWidth = trailingSize->width;
        positionChild(_ToolbarSlotCls::trailing, make<OffsetCls>(trailingX, trailingY));
    }
    if (hasChild(_ToolbarSlotCls::middle)) {
        double maxWidth = math->max(size->width - leadingWidth - trailingWidth - middleSpacing * 2.0, 0.0);
        BoxConstraints constraints = BoxConstraintsCls->loose(size)->copyWith(maxWidth);
        Size middleSize = layoutChild(_ToolbarSlotCls::middle, constraints);
        double middleStartMargin = leadingWidth + middleSpacing;
        double middleStart = middleStartMargin;
        double middleY = (size->height - middleSize->height) / 2.0;
        if (centerMiddle) {
            middleStart = (size->width - middleSize->width) / 2.0;
            if (middleStart + middleSize->width > size->width - trailingWidth) {
                middleStart = size->width - trailingWidth - middleSize->width;
            } else             {
                if ( < middleStartMargin) {
                middleStart = middleStartMargin;
            }
;
            }        }
        double middleX;
        ;
        positionChild(_ToolbarSlotCls::middle, make<OffsetCls>(middleX, middleY));
    }
}

bool _ToolbarLayoutCls::shouldRelayout(_ToolbarLayout oldDelegate) {
    return oldDelegate->centerMiddle != centerMiddle || oldDelegate->middleSpacing != middleSpacing || oldDelegate->textDirection != textDirection;
}

_ToolbarLayoutCls::_ToolbarLayoutCls(bool centerMiddle, double middleSpacing, TextDirection textDirection) {
    {
        assert(middleSpacing != nullptr);
        assert(textDirection != nullptr);
    }
}
