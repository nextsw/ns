#ifndef SHARED_APP_DATA_H
#define SHARED_APP_DATA_H
#include <memory>

#include "framework.hpp"
#include "inherited_model.hpp"



class SharedAppData : StatefulWidget {
public:
    Widget child;


     SharedAppData(Widget child, Unknown);

    State<StatefulWidget> createState();

    static V getValue<K extends Object, V>(BuildContext context, SharedAppDataInitCallback<V> init, K key);

    static void setValue<K extends Object, V>(BuildContext context, K key, V value);

private:

    static bool _debugHasSharedAppData(BuildContext context, String methodName, _SharedAppModel model);

};

class _SharedAppDataState : State<SharedAppData> {
public:
    Map<Object, Object> data;


    Widget build(BuildContext context);

    V getValue<K extends Object, V>(SharedAppDataInitCallback<V> init, K key);

    void setValue<K extends Object, V>(K key, V value);

private:

};

class _SharedAppModel : InheritedModel<Object> {
public:
    _SharedAppDataState sharedAppDataState;

    Map<Object, Object> data;


    bool updateShouldNotify(_SharedAppModel old);

    bool updateShouldNotifyDependent(Set<Object> keys, _SharedAppModel old);

private:

     _SharedAppModel(Unknown, _SharedAppDataState sharedAppDataState);

};

#endif