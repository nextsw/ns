#ifndef PAGE_STORAGE_H
#define PAGE_STORAGE_H
#include <memory>

#include <flutter/foundation.hpp>
#include "framework.hpp"



class PageStorageKey<T> : ValueKey<T> {
public:

     PageStorageKey(Unknown);

private:

};

class _StorageEntryIdentifier {
public:
    List<PageStorageKey<dynamic>> keys;


    bool isNotEmpty();

    bool ==(Object other);

    int hashCode();

    String toString();

private:

     _StorageEntryIdentifier(List<PageStorageKey<dynamic>> keys);

};

class PageStorageBucket {
public:

    void writeState(BuildContext context, dynamic data, Object identifier);

    dynamic readState(BuildContext context, Object identifier);

private:
    Map<Object, dynamic> _storage;


    static bool _maybeAddKey(BuildContext context, List<PageStorageKey<dynamic>> keys);

    List<PageStorageKey<dynamic>> _allKeys(BuildContext context);

    _StorageEntryIdentifier _computeIdentifier(BuildContext context);

};

class PageStorage : StatelessWidget {
public:
    Widget child;

    PageStorageBucket bucket;


     PageStorage(PageStorageBucket bucket, Widget child, Unknown);

    static PageStorageBucket of(BuildContext context);

    Widget build(BuildContext context);

private:

};

#endif