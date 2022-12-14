#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_PAGE_STORAGE
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_PAGE_STORAGE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "framework.hpp"


template<typename T>
class PageStorageKeyCls : public ValueKeyCls<T> {
public:

     PageStorageKeyCls(T value);
private:

};
template<typename T>
using PageStorageKey = std::shared_ptr<PageStorageKeyCls<T>>;

class _StorageEntryIdentifierCls : public ObjectCls {
public:
    List<PageStorageKey<Object>> keys;


    virtual bool isNotEmpty();

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

     _StorageEntryIdentifierCls(List<PageStorageKey<Object>> keys);

};
using _StorageEntryIdentifier = std::shared_ptr<_StorageEntryIdentifierCls>;

class PageStorageBucketCls : public ObjectCls {
public:

    virtual void writeState(BuildContext context, Object data, Object identifier);

    virtual Object readState(BuildContext context, Object identifier);

private:
    Map<Object, Object> _storage;


    static bool _maybeAddKey(BuildContext context, List<PageStorageKey<Object>> keys);

    virtual List<PageStorageKey<Object>> _allKeys(BuildContext context);

    virtual _StorageEntryIdentifier _computeIdentifier(BuildContext context);

};
using PageStorageBucket = std::shared_ptr<PageStorageBucketCls>;

class PageStorageCls : public StatelessWidgetCls {
public:
    Widget child;

    PageStorageBucket bucket;


     PageStorageCls(PageStorageBucket bucket, Widget child, Key key);

    static PageStorageBucket of(BuildContext context);

    virtual Widget build(BuildContext context);

private:

};
using PageStorage = std::shared_ptr<PageStorageCls>;


#endif