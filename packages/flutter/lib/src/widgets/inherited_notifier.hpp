#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_INHERITED_NOTIFIER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_INHERITED_NOTIFIER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "framework.hpp"


template<typename T> class InheritedNotifierCls : public InheritedWidgetCls {
public:
    T notifier;


     InheritedNotifierCls(Unknown child, Unknown key, T notifier);

    virtual bool updateShouldNotify(InheritedNotifier<T> oldWidget);

    virtual InheritedElement createElement();

private:

};
template<typename T> using InheritedNotifier = std::shared_ptr<InheritedNotifierCls<T>>;

template<typename T> class _InheritedNotifierElementCls : public InheritedElementCls {
public:

    virtual void update(InheritedNotifier<T> newWidget);

    virtual Widget build();

    virtual void notifyClients(InheritedNotifier<T> oldWidget);

    virtual void unmount();

private:
    bool _dirty;


     _InheritedNotifierElementCls(InheritedNotifier<T> widget);

    virtual void _handleUpdate();

};
template<typename T> using _InheritedNotifierElement = std::shared_ptr<_InheritedNotifierElementCls<T>>;


#endif