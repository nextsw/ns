#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_WILL_POP_SCOPE
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_WILL_POP_SCOPE
#include <base.hpp>

#include <dart/core/core.hpp>
#include "framework.hpp"
#include "navigator.hpp"
#include "routes.hpp"


class WillPopScopeCls : public StatefulWidgetCls {
public:
    Widget child;

    WillPopCallback onWillPop;


     WillPopScopeCls(Widget child, Key key, WillPopCallback onWillPop);

    virtual State<WillPopScope> createState();

private:

};
using WillPopScope = std::shared_ptr<WillPopScopeCls>;

class _WillPopScopeStateCls : public StateCls<WillPopScope> {
public:

    virtual void didChangeDependencies();

    virtual void didUpdateWidget(WillPopScope oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    ModalRoute<dynamic> _route;


};
using _WillPopScopeState = std::shared_ptr<_WillPopScopeStateCls>;


#endif