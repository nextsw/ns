#ifndef CHANGE_NOTIFIER_H
#define CHANGE_NOTIFIER_H
#include <memory>
#include <ui.hpp>

#include <ui/ui.hpp>
#include <meta/meta.hpp>
#include "assertions.hpp"
#include "diagnostics.hpp"



class Listenable {
public:

     Listenable();

    void  merge(List<Listenable> listenables);

    void addListener(VoidCallback listener);

    void removeListener(VoidCallback listener);

private:

};

class ValueListenable<T> : Listenable {
public:

     ValueListenable();

    T value();

private:

};

class ChangeNotifier {
public:

    static bool debugAssertNotDisposed(ChangeNotifier notifier);

    bool hasListeners();

    void addListener(VoidCallback listener);

    void removeListener(VoidCallback listener);

    void dispose();

    void notifyListeners();

private:
    int _count;

    static List<VoidCallback> _emptyListeners;

    List<VoidCallback> _listeners;

    int _notificationCallStackDepth;

    int _reentrantlyRemovedListeners;

    bool _debugDisposed;


    void _removeAt(int index);

};

class _MergingListenable : Listenable {
public:

    void addListener(VoidCallback listener);

    void removeListener(VoidCallback listener);

    String toString();

private:
    List<Listenable> _children;


     _MergingListenable(List<Listenable> _children);

};

class ValueNotifier<T> : ChangeNotifier {
public:

     ValueNotifier(T _value);

    T value();

    void  value(T newValue);

    String toString();

private:
    T _value;


};

#endif