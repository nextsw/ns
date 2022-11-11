#include "unique_widget.hpp"
template<typename T>
UniqueWidgetCls<T>::UniqueWidgetCls(GlobalKey<T> key) {
    {
        assert(key != nullptr);
    }
}

template<typename T>
T UniqueWidgetCls<T>::currentState() {
    GlobalKey<T> globalKey = as<GlobalKey<T>>(key!);
    return globalKey->currentState();
}
