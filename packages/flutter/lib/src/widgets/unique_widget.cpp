#include "unique_widget.hpp"
template<typename T : State<StatefulWidget>> UniqueWidgetCls<T>::UniqueWidgetCls(GlobalKey<T> key) {
    {
        assert(key != nullptr);
    }
}

template<typename T : State<StatefulWidget>> T UniqueWidgetCls<T>::currentState() {
    GlobalKey<T> globalKey = ((GlobalKey<T>)key!);
    return globalKey->currentState;
}
