#include "inherited_notifier.hpp"
template<typename T : Listenable> InheritedNotifierCls<T>::InheritedNotifierCls(Unknown child, Unknown key, T notifier) {
    {
        assert(child != nullptr);
    }
}

template<typename T : Listenable> bool InheritedNotifierCls<T>::updateShouldNotify(InheritedNotifier<T> oldWidget) {
    return oldWidget->notifier != notifier;
}

template<typename T : Listenable> InheritedElement InheritedNotifierCls<T>::createElement() {
    return <T>make<_InheritedNotifierElementCls>(this);
}

template<typename T : Listenable> void _InheritedNotifierElementCls<T>::update(InheritedNotifier<T> newWidget) {
    T oldNotifier = (((InheritedNotifier<T>)widget))->notifier;
    T newNotifier = newWidget->notifier;
    if (oldNotifier != newNotifier) {
        oldNotifier?->removeListener(_handleUpdate);
        newNotifier?->addListener(_handleUpdate);
    }
    super->update(newWidget);
}

template<typename T : Listenable> Widget _InheritedNotifierElementCls<T>::build() {
    if (_dirty) {
        notifyClients(((InheritedNotifier<T>)widget));
    }
    return super->build();
}

template<typename T : Listenable> void _InheritedNotifierElementCls<T>::notifyClients(InheritedNotifier<T> oldWidget) {
    super->notifyClients(oldWidget);
    _dirty = false;
}

template<typename T : Listenable> void _InheritedNotifierElementCls<T>::unmount() {
    (((InheritedNotifier<T>)widget))->notifier?->removeListener(_handleUpdate);
    super->unmount();
}

template<typename T : Listenable> _InheritedNotifierElementCls<T>::_InheritedNotifierElementCls(InheritedNotifier<T> widget) {
    {
        widget->notifier?->addListener(_handleUpdate);
    }
}

template<typename T : Listenable> void _InheritedNotifierElementCls<T>::_handleUpdate() {
    _dirty = true;
    markNeedsBuild();
}
