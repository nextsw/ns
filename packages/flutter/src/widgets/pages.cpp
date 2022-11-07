#include "pages.hpp"
bool PageRoute::opaque() {
    return true;
}

bool PageRoute::barrierDismissible() {
    return false;
}

bool PageRoute::canTransitionTo(TransitionRoute<dynamic> nextRoute) {
    return nextRoute is PageRoute;
}

bool PageRoute::canTransitionFrom(TransitionRoute<dynamic> previousRoute) {
    return previousRoute is PageRoute;
}

Widget _defaultTransitionsBuilder(Animation<double> animation, Widget child, BuildContext context, Animation<double> secondaryAnimation) {
    return child;
}

PageRouteBuilder::PageRouteBuilder(Color barrierColor, bool barrierDismissible, String barrierLabel, Unknown, bool maintainState, bool opaque, RoutePageBuilder pageBuilder, Duration reverseTransitionDuration, Unknown, Duration transitionDuration, RouteTransitionsBuilder transitionsBuilder) {
    {
        assert(pageBuilder != nullptr);
        assert(transitionsBuilder != nullptr);
        assert(opaque != nullptr);
        assert(barrierDismissible != nullptr);
        assert(maintainState != nullptr);
        assert(fullscreenDialog != nullptr);
    }
}

Widget PageRouteBuilder::buildPage(Animation<double> animation, BuildContext context, Animation<double> secondaryAnimation) {
    return pageBuilder(context, animation, secondaryAnimation);
}

Widget PageRouteBuilder::buildTransitions(Animation<double> animation, Widget child, BuildContext context, Animation<double> secondaryAnimation) {
    return transitionsBuilder(context, animation, secondaryAnimation, child);
}
