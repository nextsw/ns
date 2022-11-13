#include "page_storage.hpp"
bool _StorageEntryIdentifierCls::isNotEmpty() {
    return keys->isNotEmpty();
}

bool _StorageEntryIdentifierCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<_StorageEntryIdentifier>(other) && <PageStorageKey<Object>>listEquals(other->keys, keys);
}

int _StorageEntryIdentifierCls::hashCode() {
    return ObjectCls->hashAll(keys);
}

String _StorageEntryIdentifierCls::toString() {
    return __sf("StorageEntryIdentifier(%s)", keys->join(__s(":")));
}

_StorageEntryIdentifierCls::_StorageEntryIdentifierCls(List<PageStorageKey<Object>> keys) {
    {
        assert(keys != nullptr);
    }
}

void PageStorageBucketCls::writeState(BuildContext context, Object data, Object identifier) {
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

Object PageStorageBucketCls::readState(BuildContext context, Object identifier) {
    if (_storage == nullptr) {
        return nullptr;
    }
    if (identifier != nullptr) {
        return _storage![identifier];
    }
    _StorageEntryIdentifier contextIdentifier = _computeIdentifier(context);
    return contextIdentifier->isNotEmpty()? _storage![contextIdentifier] : nullptr;
}

bool PageStorageBucketCls::_maybeAddKey(BuildContext context, List<PageStorageKey<Object>> keys) {
    Widget widget = context->widget();
    Key key = widget->key;
    if (is<PageStorageKey<any>>(key)) {
        keys->add(as<PageStorageKeyCls>(key));
    }
    return !is<PageStorage>(widget);
}

List<PageStorageKey<Object>> PageStorageBucketCls::_allKeys(BuildContext context) {
    List<PageStorageKey<Object>> keys = makeList();
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

PageStorageCls::PageStorageCls(PageStorageBucket bucket, Widget child, Key key) {
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
