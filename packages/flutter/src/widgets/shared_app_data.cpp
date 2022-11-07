#include "shared_app_data.hpp"
State<StatefulWidget> SharedAppData::createState() {
    return _SharedAppDataState();
}

V SharedAppData::getValue<K extends Object, V>(BuildContext context, SharedAppDataInitCallback<V> init, K key) {
    _SharedAppModel model = InheritedModel.<_SharedAppModel>inheritFrom(contextkey);
    assert(_debugHasSharedAppData(model, context, "getValue"));
    return model!.sharedAppDataState.<K, V>getValue(key, init);
}

void SharedAppData::setValue<K extends Object, V>(BuildContext context, K key, V value) {
    _SharedAppModel model = (;
    assert(_debugHasSharedAppData(model, context, "setValue"));
    model!.sharedAppDataState.<K, V>setValue(key, value);
}

bool SharedAppData::_debugHasSharedAppData(BuildContext context, String methodName, _SharedAppModel model) {
    assert(());
    return true;
}

Widget _SharedAppDataState::build(BuildContext context) {
    return _SharedAppModel(this, widget.child);
}

V _SharedAppDataState::getValue<K extends Object, V>(SharedAppDataInitCallback<V> init, K key) {
    data[key] = init();
    return (;
}

void _SharedAppDataState::setValue<K extends Object, V>(K key, V value) {
    if (data[key] != value) {
        setState();
    }
}

bool _SharedAppModel::updateShouldNotify(_SharedAppModel old) {
    return data != old.data;
}

bool _SharedAppModel::updateShouldNotifyDependent(Set<Object> keys, _SharedAppModel old) {
    for (Object key : keys) {
        if (data[key] != old.data[key]) {
            return true;
        }
    }
    return false;
}

_SharedAppModel::_SharedAppModel(Unknown, _SharedAppDataState sharedAppDataState) {
    {
        data = sharedAppDataState.data;
    }
}
