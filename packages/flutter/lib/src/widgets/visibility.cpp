#include "visibility.hpp"
VisibilityCls::VisibilityCls(Widget child, Unknown key, bool maintainAnimation, bool maintainInteractivity, bool maintainSemantics, bool maintainSize, bool maintainState, Widget replacement, bool visible) {
    {
        assert(child != nullptr);
        assert(replacement != nullptr);
        assert(visible != nullptr);
        assert(maintainState != nullptr);
        assert(maintainAnimation != nullptr);
        assert(maintainSize != nullptr);
        assert(maintainState == true || maintainAnimation == false, __s("Cannot maintain animations if the state is not also maintained."));
        assert(maintainAnimation == true || maintainSize == false, __s("Cannot maintain size if animations are not maintained."));
        assert(maintainSize == true || maintainSemantics == false, __s("Cannot maintain semantics if size is not maintained."));
        assert(maintainSize == true || maintainInteractivity == false, __s("Cannot maintain interactivity if size is not maintained."));
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
    properties->add(make<FlagPropertyCls>(__s("visible")visible, __s("hidden"), __s("visible")));
    properties->add(make<FlagPropertyCls>(__s("maintainState")maintainState, __s("maintainState")));
    properties->add(make<FlagPropertyCls>(__s("maintainAnimation")maintainAnimation, __s("maintainAnimation")));
    properties->add(make<FlagPropertyCls>(__s("maintainSize")maintainSize, __s("maintainSize")));
    properties->add(make<FlagPropertyCls>(__s("maintainSemantics")maintainSemantics, __s("maintainSemantics")));
    properties->add(make<FlagPropertyCls>(__s("maintainInteractivity")maintainInteractivity, __s("maintainInteractivity")));
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
        assert(maintainState == true || maintainAnimation == false, __s("Cannot maintain animations if the state is not also maintained."));
        assert(maintainAnimation == true || maintainSize == false, __s("Cannot maintain size if animations are not maintained."));
        assert(maintainSize == true || maintainSemantics == false, __s("Cannot maintain semantics if size is not maintained."));
        assert(maintainSize == true || maintainInteractivity == false, __s("Cannot maintain interactivity if size is not maintained."));
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
    properties->add(make<FlagPropertyCls>(__s("visible")visible, __s("hidden"), __s("visible")));
    properties->add(make<FlagPropertyCls>(__s("maintainState")maintainState, __s("maintainState")));
    properties->add(make<FlagPropertyCls>(__s("maintainAnimation")maintainAnimation, __s("maintainAnimation")));
    properties->add(make<FlagPropertyCls>(__s("maintainSize")maintainSize, __s("maintainSize")));
    properties->add(make<FlagPropertyCls>(__s("maintainSemantics")maintainSemantics, __s("maintainSemantics")));
    properties->add(make<FlagPropertyCls>(__s("maintainInteractivity")maintainInteractivity, __s("maintainInteractivity")));
}
