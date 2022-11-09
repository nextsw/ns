#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_PAGES
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_PAGES
#include <base.hpp>

#include <dart/core/core.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "routes.hpp"


template<typename T> class PageRouteCls : public ModalRouteCls<T> {
public:
    bool fullscreenDialog;


     PageRouteCls(bool fullscreenDialog, Unknown settings);
    virtual bool opaque();

    virtual bool barrierDismissible();

    virtual bool canTransitionTo(TransitionRoute<dynamic> nextRoute);

    virtual bool canTransitionFrom(TransitionRoute<dynamic> previousRoute);

private:

};
template<typename T> using PageRoute = std::shared_ptr<PageRouteCls<T>>;
Widget _defaultTransitionsBuilder(Animation<double> animation, Widget child, BuildContext context, Animation<double> secondaryAnimation);


template<typename T> class PageRouteBuilderCls : public PageRouteCls<T> {
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


     PageRouteBuilderCls(Color barrierColor, bool barrierDismissible, String barrierLabel, Unknown fullscreenDialog, bool maintainState, bool opaque, RoutePageBuilder pageBuilder, Duration reverseTransitionDuration, Unknown settings, Duration transitionDuration, RouteTransitionsBuilder transitionsBuilder);

    virtual Widget buildPage(Animation<double> animation, BuildContext context, Animation<double> secondaryAnimation);

    virtual Widget buildTransitions(Animation<double> animation, Widget child, BuildContext context, Animation<double> secondaryAnimation);

private:

};
template<typename T> using PageRouteBuilder = std::shared_ptr<PageRouteBuilderCls<T>>;


#endif