#include "visibility.hpp"
Visibility::Visibility(Widget child, Unknown, bool maintainAnimation, bool maintainInteractivity, bool maintainSemantics, bool maintainSize, bool maintainState, Widget replacement, bool visible) {
    {
        assert(child != nullptr);
        assert(replacement != nullptr);
        assert(visible != nullptr);
        assert(maintainState != nullptr);
        assert(maintainAnimation != nullptr);
        assert(maintainSize != nullptr);
        assert(maintainState == true || maintainAnimation == false, "Cannot maintain animations if the state is not also maintained.");
        assert(maintainAnimation == true || maintainSize == false, "Cannot maintain size if animations are not maintained.");
        assert(maintainSize == true || maintainSemantics == false, "Cannot maintain semantics if size is not maintained.");
        assert(maintainSize == true || maintainInteractivity == false, "Cannot maintain interactivity if size is not maintained.");
    }
}

Widget Visibility::build(BuildContext context) {
    if (maintainSize) {
        Widget result = child;
        if (!maintainInteractivity) {
            result = IgnorePointer(!visible, !visible && !maintainSemantics, child);
        }
        return Opacity(visible? 1.0 : 0.0, maintainSemantics, result);
    }
    assert(!maintainInteractivity);
    assert(!maintainSemantics);
    assert(!maintainSize);
    if (maintainState) {
        Widget result = child;
        if (!maintainAnimation) {
            result = TickerMode(visible, child);
        }
        return Offstage(!visible, result);
    }
    assert(!maintainAnimation);
    assert(!maintainState);
    return visible? child : replacement;
}

void Visibility::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(FlagProperty("visible"visible, "hidden", "visible"));
    properties.add(FlagProperty("maintainState"maintainState, "maintainState"));
    properties.add(FlagProperty("maintainAnimation"maintainAnimation, "maintainAnimation"));
    properties.add(FlagProperty("maintainSize"maintainSize, "maintainSize"));
    properties.add(FlagProperty("maintainSemantics"maintainSemantics, "maintainSemantics"));
    properties.add(FlagProperty("maintainInteractivity"maintainInteractivity, "maintainInteractivity"));
}

SliverVisibility::SliverVisibility(Unknown, bool maintainAnimation, bool maintainInteractivity, bool maintainSemantics, bool maintainSize, bool maintainState, Widget replacementSliver, Widget sliver, bool visible) {
    {
        assert(sliver != nullptr);
        assert(replacementSliver != nullptr);
        assert(visible != nullptr);
        assert(maintainState != nullptr);
        assert(maintainAnimation != nullptr);
        assert(maintainSize != nullptr);
        assert(maintainSemantics != nullptr);
        assert(maintainInteractivity != nullptr);
        assert(maintainState == true || maintainAnimation == false, "Cannot maintain animations if the state is not also maintained.");
        assert(maintainAnimation == true || maintainSize == false, "Cannot maintain size if animations are not maintained.");
        assert(maintainSize == true || maintainSemantics == false, "Cannot maintain semantics if size is not maintained.");
        assert(maintainSize == true || maintainInteractivity == false, "Cannot maintain interactivity if size is not maintained.");
    }
}

Widget SliverVisibility::build(BuildContext context) {
    if (maintainSize) {
        Widget result = sliver;
        if (!maintainInteractivity) {
            result = SliverIgnorePointer(sliver, !visible, !visible && !maintainSemantics);
        }
        return SliverOpacity(visible? 1.0 : 0.0, maintainSemantics, result);
    }
    assert(!maintainInteractivity);
    assert(!maintainSemantics);
    assert(!maintainSize);
    if (maintainState) {
        Widget result = sliver;
        if (!maintainAnimation) {
            result = TickerMode(visible, sliver);
        }
        return SliverOffstage(result, !visible);
    }
    assert(!maintainAnimation);
    assert(!maintainState);
    return visible? sliver : replacementSliver;
}

void SliverVisibility::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(FlagProperty("visible"visible, "hidden", "visible"));
    properties.add(FlagProperty("maintainState"maintainState, "maintainState"));
    properties.add(FlagProperty("maintainAnimation"maintainAnimation, "maintainAnimation"));
    properties.add(FlagProperty("maintainSize"maintainSize, "maintainSize"));
    properties.add(FlagProperty("maintainSemantics"maintainSemantics, "maintainSemantics"));
    properties.add(FlagProperty("maintainInteractivity"maintainInteractivity, "maintainInteractivity"));
}
