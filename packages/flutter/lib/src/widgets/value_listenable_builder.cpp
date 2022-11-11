#include "value_listenable_builder.hpp"
template<typename T>
ValueListenableBuilderCls<T>::ValueListenableBuilderCls(ValueWidgetBuilder<T> builder, Widget child, Key key, ValueListenable<T> valueListenable) {
    {
        assert(valueListenable != nullptr);
        assert(builder != nullptr);
    }
}

template<typename T>
State<StatefulWidget> ValueListenableBuilderCls<T>::createState() {
    return <T>make<_ValueListenableBuilderStateCls>();
}

template<typename T>
void _ValueListenableBuilderStateCls<T>::initState() {
    super->initState();
    value = widget()->valueListenable->value;
    widget()->valueListenable->addListener(_valueChanged);
}

template<typename T>
void _ValueListenableBuilderStateCls<T>::didUpdateWidget(ValueListenableBuilder<T> oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (oldWidget->valueListenable != widget()->valueListenable) {
        oldWidget->valueListenable->removeListener(_valueChanged);
        value = widget()->valueListenable->value;
        widget()->valueListenable->addListener(_valueChanged);
    }
}

template<typename T>
void _ValueListenableBuilderStateCls<T>::dispose() {
    widget()->valueListenable->removeListener(_valueChanged);
    super->dispose();
}

template<typename T>
Widget _ValueListenableBuilderStateCls<T>::build(BuildContext context) {
    return widget()->builder(context, value, widget()->child);
}

template<typename T>
void _ValueListenableBuilderStateCls<T>::_valueChanged() {
    setState([=] () {
        value = widget()->valueListenable->value;
    });
}
