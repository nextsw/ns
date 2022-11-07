#ifndef VALUE_LISTENABLE_BUILDER_H
#define VALUE_LISTENABLE_BUILDER_H
#include <memory>

#include <flutter/foundation.hpp>
#include "framework.hpp"



class ValueListenableBuilder<T> : StatefulWidget {
public:
    ValueListenable<T> valueListenable;

    ValueWidgetBuilder<T> builder;

    Widget child;


     ValueListenableBuilder(ValueWidgetBuilder<T> builder, Widget child, Unknown, ValueListenable<T> valueListenable);

    State<StatefulWidget> createState();

private:

};

class _ValueListenableBuilderState<T> : State<ValueListenableBuilder<T>> {
public:
    T value;


    void initState();

    void didUpdateWidget(ValueListenableBuilder<T> oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:

    void _valueChanged();

};

#endif