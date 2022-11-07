#ifndef WILL_POP_SCOPE_H
#define WILL_POP_SCOPE_H
#include <memory>

#include "framework.hpp"
#include "navigator.hpp"
#include "routes.hpp"



class WillPopScope : StatefulWidget {
public:
    Widget child;

    WillPopCallback onWillPop;


     WillPopScope(Widget child, Unknown, WillPopCallback onWillPop);

    State<WillPopScope> createState();

private:

};

class _WillPopScopeState : State<WillPopScope> {
public:

    void didChangeDependencies();

    void didUpdateWidget(WillPopScope oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:
    ModalRoute<dynamic> _route;


};

#endif