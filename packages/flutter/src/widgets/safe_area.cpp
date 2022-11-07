#include "safe_area.hpp"
SafeArea::SafeArea(bool bottom, Widget child, Unknown, bool left, bool maintainBottomViewPadding, EdgeInsets minimum, bool right, bool top) {
    {
        assert(left != nullptr);
        assert(top != nullptr);
        assert(right != nullptr);
        assert(bottom != nullptr);
    }
}

Widget SafeArea::build(BuildContext context) {
    assert(debugCheckHasMediaQuery(context));
    MediaQueryData data = MediaQuery.of(context);
    EdgeInsets padding = data.padding;
    if (maintainBottomViewPadding) {
        padding = padding.copyWith(data.viewPadding.bottom);
    }
    return Padding(EdgeInsets.only(math.max(left? padding.left : 0.0, minimum.left), math.max(top? padding.top : 0.0, minimum.top), math.max(right? padding.right : 0.0, minimum.right), math.max(bottom? padding.bottom : 0.0, minimum.bottom)), MediaQuery.removePadding(context, left, top, right, bottom, child));
}

void SafeArea::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(FlagProperty("left"left, "avoid left padding"));
    properties.add(FlagProperty("top"top, "avoid top padding"));
    properties.add(FlagProperty("right"right, "avoid right padding"));
    properties.add(FlagProperty("bottom"bottom, "avoid bottom padding"));
}

SliverSafeArea::SliverSafeArea(bool bottom, Unknown, bool left, EdgeInsets minimum, bool right, Widget sliver, bool top) {
    {
        assert(left != nullptr);
        assert(top != nullptr);
        assert(right != nullptr);
        assert(bottom != nullptr);
    }
}

Widget SliverSafeArea::build(BuildContext context) {
    assert(debugCheckHasMediaQuery(context));
    EdgeInsets padding = MediaQuery.of(context).padding;
    return SliverPadding(EdgeInsets.only(math.max(left? padding.left : 0.0, minimum.left), math.max(top? padding.top : 0.0, minimum.top), math.max(right? padding.right : 0.0, minimum.right), math.max(bottom? padding.bottom : 0.0, minimum.bottom)), MediaQuery.removePadding(context, left, top, right, bottom, sliver));
}

void SliverSafeArea::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(FlagProperty("left"left, "avoid left padding"));
    properties.add(FlagProperty("top"top, "avoid top padding"));
    properties.add(FlagProperty("right"right, "avoid right padding"));
    properties.add(FlagProperty("bottom"bottom, "avoid bottom padding"));
}
