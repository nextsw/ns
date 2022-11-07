#ifndef RESTORATION_H
#define RESTORATION_H
#include <memory>
#include <flutter/services.hpp>

#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include <flutter/services.hpp>
#include "basic.hpp"
#include "framework.hpp"



class RestorationScope : StatefulWidget {
public:
    Widget child;

    String restorationId;


     RestorationScope(Widget child, Unknown, String restorationId);

    static RestorationBucket of(BuildContext context);

    State<RestorationScope> createState();

private:

};

class _RestorationScopeState : State<RestorationScope> {
public:

    String restorationId();

    void restoreState(bool initialRestore, RestorationBucket oldBucket);

    Widget build(BuildContext context);

private:

};

class UnmanagedRestorationScope : InheritedWidget {
public:
    RestorationBucket bucket;


     UnmanagedRestorationScope(RestorationBucket bucket, Unknown, Unknown);

    bool updateShouldNotify(UnmanagedRestorationScope oldWidget);

private:

};

class RootRestorationScope : StatefulWidget {
public:
    Widget child;

    String restorationId;


     RootRestorationScope(Widget child, Unknown, String restorationId);

    State<RootRestorationScope> createState();

private:

};

class _RootRestorationScopeState : State<RootRestorationScope> {
public:

    void didChangeDependencies();

    void didUpdateWidget(RootRestorationScope oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:
    bool _okToRenderBlankContainer;

    bool _rootBucketValid;

    RestorationBucket _rootBucket;

    RestorationBucket _ancestorBucket;

    bool _isLoadingRootBucket;


    bool _needsRootBucketInserted();

    bool _isWaitingForRootBucket();

    void _loadRootBucketIfNecessary();

    void _replaceRootBucket();

};

class RestorableProperty<T> : ChangeNotifier {
public:

    T createDefaultValue();

    T fromPrimitives(Object data);

    void initWithValue(T value);

    Object toPrimitives();

    bool enabled();

    void dispose();

    State state();

    bool isRegistered();

private:
    bool _disposed;

    String _restorationId;

    RestorationMixin _owner;


    void _register(RestorationMixin owner, String restorationId);

    void _unregister();

};

class RestorationMixin<S extends StatefulWidget> {
public:

    String restorationId();

    RestorationBucket bucket();

    void restoreState(bool initialRestore, RestorationBucket oldBucket);

    void didToggleBucket(RestorationBucket oldBucket);

    void registerForRestoration(RestorableProperty<Object> property, String restorationId);

    void unregisterFromRestoration(RestorableProperty<Object> property);

    void didUpdateRestorationId();

    void didUpdateWidget(S oldWidget);

    bool restorePending();

    void didChangeDependencies();

    void dispose();

private:
    RestorationBucket _bucket;

    Map<RestorableProperty<Object>, VoidCallback> _properties;

    List<RestorableProperty<Object>> _debugPropertiesWaitingForReregistration;

    bool _firstRestorePending;

    RestorationBucket _currentParent;


    bool _debugDoingRestore();

    void _doRestore(RestorationBucket oldBucket);

    bool _updateBucketIfNecessary(RestorationBucket parent, bool restorePending);

    bool _setNewBucketIfNecessary(RestorationBucket newBucket, bool restorePending);

    void _updateProperty(RestorableProperty<Object> property);

    void _unregister(RestorableProperty<Object> property);

};

#endif