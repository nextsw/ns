#include "value_listenable_builder.hpp"
ValueListenableBuilder::ValueListenableBuilder(ValueWidgetBuilder<T> builder, Widget child, Unknown, ValueListenable<T> valueListenable) {
    {
        assert(valueListenable != nullptr);
        assert(builder != nullptr);
    }
}

State<StatefulWidget> ValueListenableBuilder::createState() {
    return <T>_ValueListenableBuilderState();
}

void _ValueListenableBuilderState::initState() {
    super.initState();
    value = widget.valueListenable.value;
    widget.valueListenable.addListener(_valueChanged);
}

void _ValueListenableBuilderState::didUpdateWidget(ValueListenableBuilder<T> oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (oldWidget.valueListenable != widget.valueListenable) {
        oldWidget.valueListenable.removeListener(_valueChanged);
        value = widget.valueListenable.value;
        widget.valueListenable.addListener(_valueChanged);
    }
}

void _ValueListenableBuilderState::dispose() {
    widget.valueListenable.removeListener(_valueChanged);
    super.dispose();
}

Widget _ValueListenableBuilderState::build(BuildContext context) {
    return widget.builder(context, value, widget.child);
}

void _ValueListenableBuilderState::_valueChanged() {
    setState();
}
