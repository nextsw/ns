#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_RESTORATION
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_RESTORATION
#include <base.hpp>
#include <packages/flutter/flutter.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic.hpp"
#include "framework.hpp"


class RestorationScopeCls : public StatefulWidgetCls {
public:
    Widget child;

    String restorationId;


     RestorationScopeCls(Widget child, Key key, String restorationId);

    static RestorationBucket of(BuildContext context);

    virtual State<RestorationScope> createState();

private:

};
using RestorationScope = std::shared_ptr<RestorationScopeCls>;

class _RestorationScopeStateCls : public StateCls<RestorationScope> {
public:

    virtual String restorationId();

    virtual void restoreState(RestorationBucket oldBucket, bool initialRestore);

    virtual Widget build(BuildContext context);

private:

};
using _RestorationScopeState = std::shared_ptr<_RestorationScopeStateCls>;

class UnmanagedRestorationScopeCls : public InheritedWidgetCls {
public:
    RestorationBucket bucket;


     UnmanagedRestorationScopeCls(RestorationBucket bucket, Widget child, Key key);

    virtual bool updateShouldNotify(UnmanagedRestorationScope oldWidget);

private:

};
using UnmanagedRestorationScope = std::shared_ptr<UnmanagedRestorationScopeCls>;

class RootRestorationScopeCls : public StatefulWidgetCls {
public:
    Widget child;

    String restorationId;


     RootRestorationScopeCls(Widget child, Key key, String restorationId);

    virtual State<RootRestorationScope> createState();

private:

};
using RootRestorationScope = std::shared_ptr<RootRestorationScopeCls>;

class _RootRestorationScopeStateCls : public StateCls<RootRestorationScope> {
public:

    virtual void didChangeDependencies();

    virtual void didUpdateWidget(RootRestorationScope oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    bool _okToRenderBlankContainer;

    bool _rootBucketValid;

    RestorationBucket _rootBucket;

    RestorationBucket _ancestorBucket;

    bool _isLoadingRootBucket;


    virtual bool _needsRootBucketInserted();

    virtual bool _isWaitingForRootBucket();

    virtual void _loadRootBucketIfNecessary();

    virtual void _replaceRootBucket();

};
using _RootRestorationScopeState = std::shared_ptr<_RootRestorationScopeStateCls>;

template<typename T>
class RestorablePropertyCls : public ChangeNotifierCls {
public:

    virtual T createDefaultValue();
    virtual T fromPrimitives(Object data);
    virtual void initWithValue(T value);
    virtual Object toPrimitives();
    virtual bool enabled();

    virtual void dispose();

    virtual State<any> state();

    virtual bool isRegistered();

private:
    bool _disposed;

    String _restorationId;

    RestorationMixin<any> _owner;


    virtual void _register(String restorationId, RestorationMixin<any> owner);

    virtual void _unregister();

};
template<typename T>
using RestorableProperty = std::shared_ptr<RestorablePropertyCls<T>>;

template<typename S>
class RestorationMixinCls : public ObjectCls {
public:

    virtual String restorationId();
    virtual RestorationBucket bucket();

    virtual void restoreState(RestorationBucket oldBucket, bool initialRestore);
    virtual void didToggleBucket(RestorationBucket oldBucket);

    virtual void registerForRestoration(RestorableProperty<Object> property, String restorationId);

    virtual void unregisterFromRestoration(RestorableProperty<Object> property);

    virtual void didUpdateRestorationId();

    virtual void didUpdateWidget(S oldWidget);

    virtual bool restorePending();

    virtual void didChangeDependencies();

    virtual void dispose();

private:
    RestorationBucket _bucket;

    Map<RestorableProperty<Object>, VoidCallback> _properties;

    List<RestorableProperty<Object>> _debugPropertiesWaitingForReregistration;

    bool _firstRestorePending;

    RestorationBucket _currentParent;


    virtual bool _debugDoingRestore();

    virtual void _doRestore(RestorationBucket oldBucket);

    virtual bool _updateBucketIfNecessary(RestorationBucket parent, bool restorePending);

    virtual bool _setNewBucketIfNecessary(RestorationBucket newBucket, bool restorePending);

    virtual void _updateProperty(RestorableProperty<Object> property);

    virtual void _unregister(RestorableProperty<Object> property);

};
template<typename S>
using RestorationMixin = std::shared_ptr<RestorationMixinCls<S>>;


#endif