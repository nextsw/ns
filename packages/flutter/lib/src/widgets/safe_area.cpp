#include "safe_area.hpp"
SafeAreaCls::SafeAreaCls(bool bottom, Widget child, Unknown key, bool left, bool maintainBottomViewPadding, EdgeInsets minimum, bool right, bool top) {
    {
        assert(left != nullptr);
        assert(top != nullptr);
        assert(right != nullptr);
        assert(bottom != nullptr);
    }
}

Widget SafeAreaCls::build(BuildContext context) {
    assert(debugCheckHasMediaQuery(context));
    MediaQueryData data = MediaQueryCls->of(context);
    EdgeInsets padding = data->padding;
    if (maintainBottomViewPadding) {
        padding = padding->copyWith(data->viewPadding->bottom);
    }
    return make<PaddingCls>(EdgeInsetsCls->only(math->max(left? padding->left : 0.0, minimum->left), math->max(top? padding->top : 0.0, minimum->top), math->max(right? padding->right : 0.0, minimum->right), math->max(bottom? padding->bottom : 0.0, minimum->bottom)), MediaQueryCls->removePadding(context, left, top, right, bottom, child));
}

void SafeAreaCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<FlagPropertyCls>("left"left, "avoid left padding"));
    properties->add(make<FlagPropertyCls>("top"top, "avoid top padding"));
    properties->add(make<FlagPropertyCls>("right"right, "avoid right padding"));
    properties->add(make<FlagPropertyCls>("bottom"bottom, "avoid bottom padding"));
}

SliverSafeAreaCls::SliverSafeAreaCls(bool bottom, Unknown key, bool left, EdgeInsets minimum, bool right, Widget sliver, bool top) {
    {
        assert(left != nullptr);
        assert(top != nullptr);
        assert(right != nullptr);
        assert(bottom != nullptr);
    }
}

Widget SliverSafeAreaCls::build(BuildContext context) {
    assert(debugCheckHasMediaQuery(context));
    EdgeInsets padding = MediaQueryCls->of(context)->padding;
    return make<SliverPaddingCls>(EdgeInsetsCls->only(math->max(left? padding->left : 0.0, minimum->left), math->max(top? padding->top : 0.0, minimum->top), math->max(right? padding->right : 0.0, minimum->right), math->max(bottom? padding->bottom : 0.0, minimum->bottom)), MediaQueryCls->removePadding(context, left, top, right, bottom, sliver));
}

void SliverSafeAreaCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<FlagPropertyCls>("left"left, "avoid left padding"));
    properties->add(make<FlagPropertyCls>("top"top, "avoid top padding"));
    properties->add(make<FlagPropertyCls>("right"right, "avoid right padding"));
    properties->add(make<FlagPropertyCls>("bottom"bottom, "avoid bottom padding"));
}
