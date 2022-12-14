#include "pages.hpp"
template<typename T>
bool PageRouteCls<T>::opaque() {
    return true;
}

template<typename T>
bool PageRouteCls<T>::barrierDismissible() {
    return false;
}

template<typename T>
bool PageRouteCls<T>::canTransitionTo(TransitionRoute<Object> nextRoute) {
    return is<PageRoute<any>>(nextRoute);
}

template<typename T>
bool PageRouteCls<T>::canTransitionFrom(TransitionRoute<Object> previousRoute) {
    return is<PageRoute<any>>(previousRoute);
}

Widget _defaultTransitionsBuilder(BuildContext context, Animation<double> animation, Animation<double> secondaryAnimation, Widget child) {
    return child;
}

template<typename T>
PageRouteBuilderCls<T>::PageRouteBuilderCls(Color barrierColor, bool barrierDismissible, String barrierLabel, bool fullscreenDialog, bool maintainState, bool opaque, RoutePageBuilder pageBuilder, Duration reverseTransitionDuration, Unknown settings, Duration transitionDuration, RouteTransitionsBuilder transitionsBuilder) {
    {
        assert(pageBuilder != nullptr);
        assert(transitionsBuilder != nullptr);
        assert(opaque != nullptr);
        assert(barrierDismissible != nullptr);
        assert(maintainState != nullptr);
        assert(fullscreenDialog != nullptr);
    }
}

template<typename T>
Widget PageRouteBuilderCls<T>::buildPage(BuildContext context, Animation<double> animation, Animation<double> secondaryAnimation) {
    return pageBuilder(context, animation, secondaryAnimation);
}

template<typename T>
Widget PageRouteBuilderCls<T>::buildTransitions(BuildContext context, Animation<double> animation, Animation<double> secondaryAnimation, Widget child) {
    return transitionsBuilder(context, animation, secondaryAnimation, child);
}
