#include "geometry.hpp"
Offset positionDependentBox(Size childSize, double margin, bool preferBelow, Size size, Offset target, double verticalOffset) {
    assert(size != nullptr);
    assert(childSize != nullptr);
    assert(target != nullptr);
    assert(verticalOffset != nullptr);
    assert(preferBelow != nullptr);
    assert(margin != nullptr);
    bool fitsBelow = target->dy + verticalOffset + childSize->height <= size->height - margin;
    bool fitsAbove = target->dy - verticalOffset - childSize->height >= margin;
    bool tooltipBelow = preferBelow? fitsBelow || !fitsAbove : !(fitsAbove || !fitsBelow);
    double y;
    if (tooltipBelow) {
        y = math->min(target->dy + verticalOffset, size->height - margin);
    } else {
        y = math->max(target->dy - verticalOffset - childSize->height, margin);
    }
    double x;
    if (size->width - margin * 2.0 < childSize->width) {
        x = (size->width - childSize->width) / 2.0;
    } else {
        double normalizedTargetX = clampDouble(target->dx, margin, size->width - margin);
        double edge = margin + childSize->width / 2.0;
        if ( < edge) {
            x = margin;
        } else         {
            if (normalizedTargetX > size->width - edge) {
            x = size->width - margin - childSize->width;
        } else {
            x = normalizedTargetX - childSize->width / 2.0;
        }
;
        }    }
    return make<OffsetCls>(x, y);
}
