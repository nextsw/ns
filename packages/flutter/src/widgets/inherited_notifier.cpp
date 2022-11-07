#include "inherited_notifier.hpp"
InheritedNotifier::InheritedNotifier(Unknown, Unknown, T notifier) {
    {
        assert(child != nullptr);
    }
}

bool InheritedNotifier::updateShouldNotify(InheritedNotifier<T> oldWidget) {
    return oldWidget.notifier != notifier;
}

InheritedElement InheritedNotifier::createElement() {
    return <T>_InheritedNotifierElement(this);
}

void _InheritedNotifierElement::update(InheritedNotifier<T> newWidget) {
    T oldNotifier = (().notifier;
    T newNotifier = newWidget.notifier;
    if (oldNotifier != newNotifier) {
        oldNotifier?.removeListener(_handleUpdate);
        newNotifier?.addListener(_handleUpdate);
    }
    super.update(newWidget);
}

Widget _InheritedNotifierElement::build() {
    if (_dirty) {
        notifyClients(();
    }
    return super.build();
}

void _InheritedNotifierElement::notifyClients(InheritedNotifier<T> oldWidget) {
    super.notifyClients(oldWidget);
    _dirty = false;
}

void _InheritedNotifierElement::unmount() {
    (().notifier?.removeListener(_handleUpdate);
    super.unmount();
}

_InheritedNotifierElement::_InheritedNotifierElement(InheritedNotifier<T> widget) {
    {
        super(widget);
    }
    {
        widget.notifier?.addListener(_handleUpdate);
    }
}

void _InheritedNotifierElement::_handleUpdate() {
    _dirty = true;
    markNeedsBuild();
}
