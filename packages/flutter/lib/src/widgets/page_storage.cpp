#include "page_storage.hpp"
bool _StorageEntryIdentifierCls::isNotEmpty() {
    return keys->isNotEmpty;
}

bool _StorageEntryIdentifierCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<_StorageEntryIdentifier>(other) && <PageStorageKey<dynamic>>listEquals(other->keys, keys);
}

int _StorageEntryIdentifierCls::hashCode() {
    return ObjectCls->hashAll(keys);
}

String _StorageEntryIdentifierCls::toString() {
    return __s("StorageEntryIdentifier(${keys.join(":")})");
}

_StorageEntryIdentifierCls::_StorageEntryIdentifierCls(List<PageStorageKey<dynamic>> keys) {
    {
        assert(keys != nullptr);
    }
}

void PageStorageBucketCls::writeState(BuildContext context, dynamic data, Object identifier) {
    _storage |= makeMap(makeList(), makeList();
    if (identifier != nullptr) {
        _storage![identifier] = data;
    } else {
        _StorageEntryIdentifier contextIdentifier = _computeIdentifier(context);
        if (contextIdentifier->isNotEmpty()) {
            _storage![contextIdentifier] = data;
        }
    }
}

dynamic PageStorageBucketCls::readState(BuildContext context, Object identifier) {
    if (_storage == nullptr) {
        return nullptr;
    }
    if (identifier != nullptr) {
        return _storage![identifier];
    }
    _StorageEntryIdentifier contextIdentifier = _computeIdentifier(context);
    return contextIdentifier->isNotEmpty()? _storage![contextIdentifier] : nullptr;
}

bool PageStorageBucketCls::_maybeAddKey(BuildContext context, List<PageStorageKey<dynamic>> keys) {
    Widget widget = context->widget();
    Key key = widget->key;
    if (is<PageStorageKey>(key)) {
        keys->add(as<PageStorageKeyCls>(key));
    }
    return !is<PageStorage>(widget);
}

List<PageStorageKey<dynamic>> PageStorageBucketCls::_allKeys(BuildContext context) {
    List<PageStorageKey<dynamic>> keys = makeList();
    if (_maybeAddKey(context, keys)) {
        context->visitAncestorElements([=] (Element element) {
            return _maybeAddKey(element, keys);
        });
    }
    return keys;
}

_StorageEntryIdentifier PageStorageBucketCls::_computeIdentifier(BuildContext context) {
    return make<_StorageEntryIdentifierCls>(_allKeys(context));
}

PageStorageCls::PageStorageCls(PageStorageBucket bucket, Widget child, Unknown key) {
    {
        assert(bucket != nullptr);
    }
}

PageStorageBucket PageStorageCls::of(BuildContext context) {
    PageStorage widget = context-><PageStorage>findAncestorWidgetOfExactType();
    return widget?->bucket;
}

Widget PageStorageCls::build(BuildContext context) {
    return child;
}
