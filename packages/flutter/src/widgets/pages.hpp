#ifndef PAGES_H
#define PAGES_H
#include <memory>

#include "basic.hpp"
#include "framework.hpp"
#include "routes.hpp"



class PageRoute<T> : ModalRoute<T> {
public:
    bool fullscreenDialog;


     PageRoute(bool fullscreenDialog, Unknown);

    bool opaque();

    bool barrierDismissible();

    bool canTransitionTo(TransitionRoute<dynamic> nextRoute);

    bool canTransitionFrom(TransitionRoute<dynamic> previousRoute);

private:

};
Widget _defaultTransitionsBuilder(Animation<double> animation, Widget child, BuildContext context, Animation<double> secondaryAnimation);


class PageRouteBuilder<T> : PageRoute<T> {
public:
    RoutePageBuilder pageBuilder;

    RouteTransitionsBuilder transitionsBuilder;

    Duration transitionDuration;

    Duration reverseTransitionDuration;

    bool opaque;

    bool barrierDismissible;

    Color barrierColor;

    String barrierLabel;

    bool maintainState;


     PageRouteBuilder(Color barrierColor, bool barrierDismissible, String barrierLabel, Unknown, bool maintainState, bool opaque, RoutePageBuilder pageBuilder, Duration reverseTransitionDuration, Unknown, Duration transitionDuration, RouteTransitionsBuilder transitionsBuilder);

    Widget buildPage(Animation<double> animation, BuildContext context, Animation<double> secondaryAnimation);

    Widget buildTransitions(Animation<double> animation, Widget child, BuildContext context, Animation<double> secondaryAnimation);

private:

};

#endif