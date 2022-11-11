#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_AUTOFILL
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_AUTOFILL
#include <base.hpp>
#include <packages/flutter/flutter.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/flutter.hpp>
#include "framework.hpp"


enum AutofillContextAction{
    commit,
    cancel,
} // end AutofillContextAction

class AutofillGroupCls : public StatefulWidgetCls {
public:
    Widget child;

    AutofillContextAction onDisposeAction;


     AutofillGroupCls(Widget child, Key key, AutofillContextAction onDisposeAction);

    static AutofillGroupState of(BuildContext context);

    virtual AutofillGroupState createState();

private:

};
using AutofillGroup = std::shared_ptr<AutofillGroupCls>;

class AutofillGroupStateCls : public StateCls<AutofillGroup> {
public:

    virtual AutofillClient getAutofillClient(String autofillId);

    virtual Iterable<AutofillClient> autofillClients();

    virtual void register(AutofillClient client);

    virtual void unregister(String autofillId);

    virtual void didChangeDependencies();

    virtual Widget build(BuildContext context);

    virtual void dispose();

private:
    Map<String, AutofillClient> _clients;

    bool _isTopmostAutofillGroup;


};
using AutofillGroupState = std::shared_ptr<AutofillGroupStateCls>;

class _AutofillScopeCls : public InheritedWidgetCls {
public:

    virtual AutofillGroup client();

    virtual bool updateShouldNotify(_AutofillScope old);

private:
    AutofillGroupState _scope;


     _AutofillScopeCls(AutofillGroupState autofillScopeState, Widget child);

};
using _AutofillScope = std::shared_ptr<_AutofillScopeCls>;


#endif