#include "page_storage.hpp"
bool _StorageEntryIdentifier::isNotEmpty() {
    return keys.isNotEmpty;
}

bool _StorageEntryIdentifier::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is _StorageEntryIdentifier && <PageStorageKey<dynamic>>listEquals(other.keys, keys);
}

int _StorageEntryIdentifier::hashCode() {
    return Object.hashAll(keys);
}

String _StorageEntryIdentifier::toString() {
    return "StorageEntryIdentifier(${keys.join(":")})";
}

_StorageEntryIdentifier::_StorageEntryIdentifier(List<PageStorageKey<dynamic>> keys) {
    {
        assert(keys != nullptr);
    }
}

void PageStorageBucket::writeState(BuildContext context, dynamic data, Object identifier) {
    _storage = ;
    if (identifier != nullptr) {
        _storage![identifier] = data;
    } else {
        _StorageEntryIdentifier contextIdentifier = _computeIdentifier(context);
        if (contextIdentifier.isNotEmpty) {
            _storage![contextIdentifier] = data;
        }
    }
}

dynamic PageStorageBucket::readState(BuildContext context, Object identifier) {
    if (_storage == nullptr) {
        return nullptr;
    }
    if (identifier != nullptr) {
        return _storage![identifier];
    }
    _StorageEntryIdentifier contextIdentifier = _computeIdentifier(context);
    return contextIdentifier.isNotEmpty? _storage![contextIdentifier] : nullptr;
}

bool PageStorageBucket::_maybeAddKey(BuildContext context, List<PageStorageKey<dynamic>> keys) {
    Widget widget = context.widget;
    Key key = widget.key;
    if (key is PageStorageKey) {
        keys.add(key);
    }
    return widget is! PageStorage;
}

List<PageStorageKey<dynamic>> PageStorageBucket::_allKeys(BuildContext context) {
    List<PageStorageKey<dynamic>> keys = ;
    if (_maybeAddKey(context, keys)) {
        context.visitAncestorElements();
    }
    return keys;
}

_StorageEntryIdentifier PageStorageBucket::_computeIdentifier(BuildContext context) {
    return _StorageEntryIdentifier(_allKeys(context));
}

PageStorage::PageStorage(PageStorageBucket bucket, Widget child, Unknown) {
    {
        assert(bucket != nullptr);
    }
}

PageStorageBucket PageStorage::of(BuildContext context) {
    PageStorage widget = context.<PageStorage>findAncestorWidgetOfExactType();
    return widget?.bucket;
}

Widget PageStorage::build(BuildContext context) {
    return child;
}
