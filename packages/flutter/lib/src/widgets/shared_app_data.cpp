#include "shared_app_data.hpp"
State<StatefulWidget> SharedAppDataCls::createState() {
    return make<_SharedAppDataStateCls>();
}

template<typename K, typename V>
V SharedAppDataCls::getValue(BuildContext context, SharedAppDataInitCallback<V> init, K key) {
    _SharedAppModel model = InheritedModelCls-><_SharedAppModel>inheritFrom(contextkey);
    assert(_debugHasSharedAppData(model, context, __s("getValue")));
    return model!->sharedAppDataState-><K, V>getValue(key, init);
}

template<typename K, typename V>
void SharedAppDataCls::setValue(BuildContext context, K key, V value) {
    _SharedAppModel model = as<_SharedAppModel>(context-><_SharedAppModel>getElementForInheritedWidgetOfExactType()?->widget);
    assert(_debugHasSharedAppData(model, context, __s("setValue")));
    model!->sharedAppDataState-><K, V>setValue(key, value);
}

bool SharedAppDataCls::_debugHasSharedAppData(BuildContext context, String methodName, _SharedAppModel model) {
    assert([=] () {
        if (model == nullptr) {
            ;
        }
        return true;
    }());
    return true;
}

Widget _SharedAppDataStateCls::build(BuildContext context) {
    return make<_SharedAppModelCls>(this, widget->child);
}

template<typename K, typename V>
V _SharedAppDataStateCls::getValue(SharedAppDataInitCallback<V> init, K key) {
    data[key] = init();
    return as<V>(data[key]);
}

template<typename K, typename V>
void _SharedAppDataStateCls::setValue(K key, V value) {
    if (data[key] != value) {
        setState([=] () {
            data = <Object, Object>of(data);
            data[key] = value;
        });
    }
}

bool _SharedAppModelCls::updateShouldNotify(_SharedAppModel old) {
    return data != old->data;
}

bool _SharedAppModelCls::updateShouldNotifyDependent(Set<Object> keys, _SharedAppModel old) {
    for (Object key : keys) {
        if (data[key] != old->data[key]) {
            return true;
        }
    }
    return false;
}

_SharedAppModelCls::_SharedAppModelCls(Unknown child, _SharedAppDataState sharedAppDataState) {
    {
        data = sharedAppDataState->data;
    }
}