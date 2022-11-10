#include "pages.hpp"
template<typename T> bool PageRouteCls<T>::opaque() {
    return true;
}

template<typename T> bool PageRouteCls<T>::barrierDismissible() {
    return false;
}

template<typename T> bool PageRouteCls<T>::canTransitionTo(TransitionRoute<dynamic> nextRoute) {
    return is<PageRoute>(nextRoute);
}

template<typename T> bool PageRouteCls<T>::canTransitionFrom(TransitionRoute<dynamic> previousRoute) {
    return is<PageRoute>(previousRoute);
}

Widget _defaultTransitionsBuilder(Animation<double> animation, Widget child, BuildContext context, Animation<double> secondaryAnimation) {
    return child;
}

template<typename T> PageRouteBuilderCls<T>::PageRouteBuilderCls(Color barrierColor, bool barrierDismissible, String barrierLabel, Unknown fullscreenDialog, bool maintainState, bool opaque, RoutePageBuilder pageBuilder, Duration reverseTransitionDuration, Unknown settings, Duration transitionDuration, RouteTransitionsBuilder transitionsBuilder) {
    {
        assert(pageBuilder != nullptr);
        assert(transitionsBuilder != nullptr);
        assert(opaque != nullptr);
        assert(barrierDismissible != nullptr);
        assert(maintainState != nullptr);
        assert(fullscreenDialog != nullptr);
    }
}

template<typename T> Widget PageRouteBuilderCls<T>::buildPage(Animation<double> animation, BuildContext context, Animation<double> secondaryAnimation) {
    return pageBuilder(context, animation, secondaryAnimation);
}

template<typename T> Widget PageRouteBuilderCls<T>::buildTransitions(Animation<double> animation, Widget child, BuildContext context, Animation<double> secondaryAnimation) {
    return transitionsBuilder(context, animation, secondaryAnimation, child);
}
