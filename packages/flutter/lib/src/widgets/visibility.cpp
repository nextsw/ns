#include "visibility.hpp"
VisibilityCls::VisibilityCls(Widget child, Unknown key, bool maintainAnimation, bool maintainInteractivity, bool maintainSemantics, bool maintainSize, bool maintainState, Widget replacement, bool visible) {
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

Widget VisibilityCls::build(BuildContext context) {
    if (maintainSize) {
        Widget result = child;
        if (!maintainInteractivity) {
            result = make<IgnorePointerCls>(!visible, !visible && !maintainSemantics, child);
        }
        return make<OpacityCls>(visible? 1.0 : 0.0, maintainSemantics, result);
    }
    assert(!maintainInteractivity);
    assert(!maintainSemantics);
    assert(!maintainSize);
    if (maintainState) {
        Widget result = child;
        if (!maintainAnimation) {
            result = make<TickerModeCls>(visible, child);
        }
        return make<OffstageCls>(!visible, result);
    }
    assert(!maintainAnimation);
    assert(!maintainState);
    return visible? child : replacement;
}

void VisibilityCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<FlagPropertyCls>("visible"visible, "hidden", "visible"));
    properties->add(make<FlagPropertyCls>("maintainState"maintainState, "maintainState"));
    properties->add(make<FlagPropertyCls>("maintainAnimation"maintainAnimation, "maintainAnimation"));
    properties->add(make<FlagPropertyCls>("maintainSize"maintainSize, "maintainSize"));
    properties->add(make<FlagPropertyCls>("maintainSemantics"maintainSemantics, "maintainSemantics"));
    properties->add(make<FlagPropertyCls>("maintainInteractivity"maintainInteractivity, "maintainInteractivity"));
}

SliverVisibilityCls::SliverVisibilityCls(Unknown key, bool maintainAnimation, bool maintainInteractivity, bool maintainSemantics, bool maintainSize, bool maintainState, Widget replacementSliver, Widget sliver, bool visible) {
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

Widget SliverVisibilityCls::build(BuildContext context) {
    if (maintainSize) {
        Widget result = sliver;
        if (!maintainInteractivity) {
            result = make<SliverIgnorePointerCls>(sliver, !visible, !visible && !maintainSemantics);
        }
        return make<SliverOpacityCls>(visible? 1.0 : 0.0, maintainSemantics, result);
    }
    assert(!maintainInteractivity);
    assert(!maintainSemantics);
    assert(!maintainSize);
    if (maintainState) {
        Widget result = sliver;
        if (!maintainAnimation) {
            result = make<TickerModeCls>(visible, sliver);
        }
        return make<SliverOffstageCls>(result, !visible);
    }
    assert(!maintainAnimation);
    assert(!maintainState);
    return visible? sliver : replacementSliver;
}

void SliverVisibilityCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<FlagPropertyCls>("visible"visible, "hidden", "visible"));
    properties->add(make<FlagPropertyCls>("maintainState"maintainState, "maintainState"));
    properties->add(make<FlagPropertyCls>("maintainAnimation"maintainAnimation, "maintainAnimation"));
    properties->add(make<FlagPropertyCls>("maintainSize"maintainSize, "maintainSize"));
    properties->add(make<FlagPropertyCls>("maintainSemantics"maintainSemantics, "maintainSemantics"));
    properties->add(make<FlagPropertyCls>("maintainInteractivity"maintainInteractivity, "maintainInteractivity"));
}
