#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SHARED_APP_DATA
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SHARED_APP_DATA
#include <base.hpp>

#include <dart/core/core.hpp>
#include "framework.hpp"
#include "inherited_model.hpp"


class SharedAppDataCls : public StatefulWidgetCls {
public:
    Widget child;


     SharedAppDataCls(Widget child, Unknown key);
    virtual State<StatefulWidget> createState();

    template<typename K, typename V>
 static V getValue(BuildContext context, SharedAppDataInitCallback<V> init, K key);

    template<typename K, typename V>
 static void setValue(BuildContext context, K key, V value);

private:

    static bool _debugHasSharedAppData(BuildContext context, String methodName, _SharedAppModel model);

};
using SharedAppData = std::shared_ptr<SharedAppDataCls>;

class _SharedAppDataStateCls : public StateCls<SharedAppData> {
public:
    Map<Object, Object> data;


    virtual Widget build(BuildContext context);

    template<typename K, typename V>
 virtual V getValue(SharedAppDataInitCallback<V> init, K key);

    template<typename K, typename V>
 virtual void setValue(K key, V value);

private:

};
using _SharedAppDataState = std::shared_ptr<_SharedAppDataStateCls>;

class _SharedAppModelCls : public InheritedModelCls<Object> {
public:
    _SharedAppDataState sharedAppDataState;

    Map<Object, Object> data;


    virtual bool updateShouldNotify(_SharedAppModel old);

    virtual bool updateShouldNotifyDependent(Set<Object> keys, _SharedAppModel old);

private:

     _SharedAppModelCls(Unknown child, _SharedAppDataState sharedAppDataState);

};
using _SharedAppModel = std::shared_ptr<_SharedAppModelCls>;


#endif