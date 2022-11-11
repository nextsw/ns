#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_VALUE_LISTENABLE_BUILDER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_VALUE_LISTENABLE_BUILDER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "framework.hpp"


template<typename T>
class ValueListenableBuilderCls : public StatefulWidgetCls {
public:
    ValueListenable<T> valueListenable;

    ValueWidgetBuilder<T> builder;

    Widget child;


     ValueListenableBuilderCls(ValueWidgetBuilder<T> builder, Widget child, Key key, ValueListenable<T> valueListenable);

    virtual State<StatefulWidget> createState();

private:

};
template<typename T>
using ValueListenableBuilder = std::shared_ptr<ValueListenableBuilderCls<T>>;

template<typename T>
class _ValueListenableBuilderStateCls : public StateCls<ValueListenableBuilder<T>> {
public:
    T value;


    virtual void initState();

    virtual void didUpdateWidget(ValueListenableBuilder<T> oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:

    virtual void _valueChanged();

};
template<typename T>
using _ValueListenableBuilderState = std::shared_ptr<_ValueListenableBuilderStateCls<T>>;


#endif