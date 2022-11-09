#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_VISIBILITY
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_VISIBILITY
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "sliver.hpp"
#include "ticker_provider.hpp"


class VisibilityCls : public StatelessWidgetCls {
public:
    Widget child;

    Widget replacement;

    bool visible;

    bool maintainState;

    bool maintainAnimation;

    bool maintainSize;

    bool maintainSemantics;

    bool maintainInteractivity;


     VisibilityCls(Widget child, Unknown key, bool maintainAnimation, bool maintainInteractivity, bool maintainSemantics, bool maintainSize, bool maintainState, Widget replacement, bool visible);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using Visibility = std::shared_ptr<VisibilityCls>;

class SliverVisibilityCls : public StatelessWidgetCls {
public:
    Widget sliver;

    Widget replacementSliver;

    bool visible;

    bool maintainState;

    bool maintainAnimation;

    bool maintainSize;

    bool maintainSemantics;

    bool maintainInteractivity;


     SliverVisibilityCls(Unknown key, bool maintainAnimation, bool maintainInteractivity, bool maintainSemantics, bool maintainSize, bool maintainState, Widget replacementSliver, Widget sliver, bool visible);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using SliverVisibility = std::shared_ptr<SliverVisibilityCls>;


#endif