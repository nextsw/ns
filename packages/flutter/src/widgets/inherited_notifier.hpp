#ifndef INHERITED_NOTIFIER_H
#define INHERITED_NOTIFIER_H
#include <memory>

#include <flutter/foundation.hpp>
#include "framework.hpp"



class InheritedNotifier<T extends Listenable> : InheritedWidget {
public:
    T notifier;


     InheritedNotifier(Unknown, Unknown, T notifier);

    bool updateShouldNotify(InheritedNotifier<T> oldWidget);

    InheritedElement createElement();

private:

};

class _InheritedNotifierElement<T extends Listenable> : InheritedElement {
public:

    void update(InheritedNotifier<T> newWidget);

    Widget build();

    void notifyClients(InheritedNotifier<T> oldWidget);

    void unmount();

private:
    bool _dirty;


     _InheritedNotifierElement(InheritedNotifier<T> widget);

    void _handleUpdate();

};

#endif