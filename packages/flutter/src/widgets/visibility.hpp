#ifndef VISIBILITY_H
#define VISIBILITY_H
#include <memory>

#include <flutter/foundation.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "sliver.hpp"
#include "ticker_provider.hpp"



class Visibility : StatelessWidget {
public:
    Widget child;

    Widget replacement;

    bool visible;

    bool maintainState;

    bool maintainAnimation;

    bool maintainSize;

    bool maintainSemantics;

    bool maintainInteractivity;


     Visibility(Widget child, Unknown, bool maintainAnimation, bool maintainInteractivity, bool maintainSemantics, bool maintainSize, bool maintainState, Widget replacement, bool visible);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class SliverVisibility : StatelessWidget {
public:
    Widget sliver;

    Widget replacementSliver;

    bool visible;

    bool maintainState;

    bool maintainAnimation;

    bool maintainSize;

    bool maintainSemantics;

    bool maintainInteractivity;


     SliverVisibility(Unknown, bool maintainAnimation, bool maintainInteractivity, bool maintainSemantics, bool maintainSize, bool maintainState, Widget replacementSliver, Widget sliver, bool visible);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

#endif