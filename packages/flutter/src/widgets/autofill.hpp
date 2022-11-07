#ifndef AUTOFILL_H
#define AUTOFILL_H
#include <memory>
#include <flutter/services.hpp>

#include <flutter/services.hpp>
#include "framework.hpp"



enum AutofillContextAction{
    commit,
    cancel,
} // end AutofillContextAction

class AutofillGroup : StatefulWidget {
public:
    Widget child;

    AutofillContextAction onDisposeAction;


     AutofillGroup(Widget child, Unknown, AutofillContextAction onDisposeAction);

    static AutofillGroupState of(BuildContext context);

    AutofillGroupState createState();

private:

};

class AutofillGroupState : State<AutofillGroup> {
public:

    AutofillClient getAutofillClient(String autofillId);

    Iterable<AutofillClient> autofillClients();

    void register(AutofillClient client);

    void unregister(String autofillId);

    void didChangeDependencies();

    Widget build(BuildContext context);

    void dispose();

private:
    Map<String, AutofillClient> _clients;

    bool _isTopmostAutofillGroup;


};

class _AutofillScope : InheritedWidget {
public:

    AutofillGroup client();

    bool updateShouldNotify(_AutofillScope old);

private:
    AutofillGroupState _scope;


     _AutofillScope(AutofillGroupState autofillScopeState, Unknown);

};

#endif