#include "unique_widget.hpp"
UniqueWidget::UniqueWidget(GlobalKey<T> key) {
    {
        assert(key != nullptr);
        super(key);
    }
}

T UniqueWidget::currentState() {
    GlobalKey<T> globalKey = (;
    return globalKey.currentState;
}
