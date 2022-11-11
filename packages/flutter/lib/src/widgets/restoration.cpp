#include "restoration.hpp"
RestorationScopeCls::RestorationScopeCls(Widget child, Unknown key, String restorationId) {
    {
        assert(child != nullptr);
    }
}

RestorationBucket RestorationScopeCls::of(BuildContext context) {
    return context-><UnmanagedRestorationScope>dependOnInheritedWidgetOfExactType()?->bucket;
}

State<RestorationScope> RestorationScopeCls::createState() {
    return make<_RestorationScopeStateCls>();
}

String _RestorationScopeStateCls::restorationId() {
    return widget->restorationId;
}

void _RestorationScopeStateCls::restoreState(bool initialRestore, RestorationBucket oldBucket) {
}

Widget _RestorationScopeStateCls::build(BuildContext context) {
    return make<UnmanagedRestorationScopeCls>(bucket, widget->child);
}

UnmanagedRestorationScopeCls::UnmanagedRestorationScopeCls(RestorationBucket bucket, Unknown child, Unknown key) {
    {
        assert(child != nullptr);
    }
}

bool UnmanagedRestorationScopeCls::updateShouldNotify(UnmanagedRestorationScope oldWidget) {
    return oldWidget->bucket != bucket;
}

RootRestorationScopeCls::RootRestorationScopeCls(Widget child, Unknown key, String restorationId) {
    {
        assert(child != nullptr);
    }
}

State<RootRestorationScope> RootRestorationScopeCls::createState() {
    return make<_RootRestorationScopeStateCls>();
}

void _RootRestorationScopeStateCls::didChangeDependencies() {
    super->didChangeDependencies();
    _ancestorBucket = RestorationScopeCls->of(context);
    _loadRootBucketIfNecessary();
    _okToRenderBlankContainer = widget->restorationId != nullptr && _needsRootBucketInserted();
}

void _RootRestorationScopeStateCls::didUpdateWidget(RootRestorationScope oldWidget) {
    super->didUpdateWidget(oldWidget);
    _loadRootBucketIfNecessary();
}

void _RootRestorationScopeStateCls::dispose() {
    if (_rootBucketValid) {
        ServicesBindingCls::instance->restorationManager->removeListener(_replaceRootBucket);
    }
    super->dispose();
}

Widget _RootRestorationScopeStateCls::build(BuildContext context) {
    if (_okToRenderBlankContainer! && _isWaitingForRootBucket()) {
        return SizedBoxCls->shrink();
    }
    return make<UnmanagedRestorationScopeCls>(_ancestorBucket or _rootBucket, make<RestorationScopeCls>(widget->restorationId, widget->child));
}

bool _RootRestorationScopeStateCls::_needsRootBucketInserted() {
    return _ancestorBucket == nullptr;
}

bool _RootRestorationScopeStateCls::_isWaitingForRootBucket() {
    return widget->restorationId != nullptr && _needsRootBucketInserted() && !_rootBucketValid;
}

void _RootRestorationScopeStateCls::_loadRootBucketIfNecessary() {
    if (_isWaitingForRootBucket() && !_isLoadingRootBucket) {
        _isLoadingRootBucket = true;
        RendererBindingCls::instance->deferFirstFrame();
        ServicesBindingCls::instance->restorationManager->rootBucket->then([=] (RestorationBucket bucket) {
            _isLoadingRootBucket = false;
            if (mounted) {
                ServicesBindingCls::instance->restorationManager->addListener(_replaceRootBucket);
                setState([=] () {
                    _rootBucket = bucket;
                    _rootBucketValid = true;
                    _okToRenderBlankContainer = false;
                });
            }
            RendererBindingCls::instance->allowFirstFrame();
        });
    }
}

void _RootRestorationScopeStateCls::_replaceRootBucket() {
    _rootBucketValid = false;
    _rootBucket = nullptr;
    ServicesBindingCls::instance->restorationManager->removeListener(_replaceRootBucket);
    _loadRootBucketIfNecessary();
    assert(!_isWaitingForRootBucket());
}

template<typename T> bool RestorablePropertyCls<T>::enabled() {
    return true;
}

template<typename T> void RestorablePropertyCls<T>::dispose() {
    assert(ChangeNotifierCls->debugAssertNotDisposed(this));
    _owner?->_unregister(this);
    super->dispose();
    _disposed = true;
}

template<typename T> State RestorablePropertyCls<T>::state() {
    assert(isRegistered());
    assert(ChangeNotifierCls->debugAssertNotDisposed(this));
    return _owner!;
}

template<typename T> bool RestorablePropertyCls<T>::isRegistered() {
    assert(ChangeNotifierCls->debugAssertNotDisposed(this));
    return _restorationId != nullptr;
}

template<typename T> void RestorablePropertyCls<T>::_register(RestorationMixin owner, String restorationId) {
    assert(ChangeNotifierCls->debugAssertNotDisposed(this));
    assert(restorationId != nullptr);
    assert(owner != nullptr);
    _restorationId = restorationId;
    _owner = owner;
}

template<typename T> void RestorablePropertyCls<T>::_unregister() {
    assert(ChangeNotifierCls->debugAssertNotDisposed(this));
    assert(_restorationId != nullptr);
    assert(_owner != nullptr);
    _restorationId = nullptr;
    _owner = nullptr;
}

template<typename S> RestorationBucket RestorationMixinCls<S>::bucket() {
    return _bucket;
}

template<typename S> void RestorationMixinCls<S>::didToggleBucket(RestorationBucket oldBucket) {
    assert(_bucket?->isReplacing() != true);
}

template<typename S> void RestorationMixinCls<S>::registerForRestoration(RestorableProperty<Object> property, String restorationId) {
    assert(property != nullptr);
    assert(restorationId != nullptr);
    assert(property->_restorationId == nullptr || (_debugDoingRestore() && property->_restorationId == restorationId), __s("Property is already registered under ${property._restorationId}."));
    assert(_debugDoingRestore() || !_properties->keys->map([=] (RestorableProperty<Object> r)     {
        r->_restorationId;
    })->contains(restorationId), __s(""$restorationId" is already registered to another property."));
    bool hasSerializedValue = bucket?->contains(restorationId) or false;
    Object initialValue = hasSerializedValue? property->fromPrimitives(bucket!-><Object>read(restorationId)) : property->createDefaultValue();
    if (!property->isRegistered()) {
        property->_register(restorationId, this);
        InlineMethod;
        property->addListener(listener);
        _properties[property] = listener;
    }
    assert(property->_restorationId == restorationId && property->_owner == this && _properties->containsKey(property));
    property->initWithValue(initialValue);
    if (!hasSerializedValue && property->enabled && bucket != nullptr) {
        _updateProperty(property);
    }
    assert([=] () {
        _debugPropertiesWaitingForReregistration?->remove(property);
        return true;
    }());
}

template<typename S> void RestorationMixinCls<S>::unregisterFromRestoration(RestorableProperty<Object> property) {
    assert(property != nullptr);
    assert(property->_owner == this);
    _bucket?-><Object>remove(property->_restorationId!);
    _unregister(property);
}

template<typename S> void RestorationMixinCls<S>::didUpdateRestorationId() {
    if (_currentParent == nullptr || _bucket?->restorationId == restorationId || restorePending()) {
        return;
    }
    RestorationBucket oldBucket = _bucket;
    assert(!restorePending());
    bool didReplaceBucket = _updateBucketIfNecessary(_currentParent, false);
    if (didReplaceBucket) {
        assert(oldBucket != _bucket);
        assert(_bucket == nullptr || oldBucket == nullptr);
        oldBucket?->dispose();
    }
}

template<typename S> void RestorationMixinCls<S>::didUpdateWidget(S oldWidget) {
    super->didUpdateWidget(oldWidget);
    didUpdateRestorationId();
}

template<typename S> bool RestorationMixinCls<S>::restorePending() {
    if (_firstRestorePending) {
        return true;
    }
    if (restorationId == nullptr) {
        return false;
    }
    RestorationBucket potentialNewParent = RestorationScopeCls->of(context);
    return potentialNewParent != _currentParent && (potentialNewParent?->isReplacing() or false);
}

template<typename S> void RestorationMixinCls<S>::didChangeDependencies() {
    super->didChangeDependencies();
    RestorationBucket oldBucket = _bucket;
    bool needsRestore = restorePending();
    _currentParent = RestorationScopeCls->of(context);
    bool didReplaceBucket = _updateBucketIfNecessary(_currentParent, needsRestore);
    if (needsRestore) {
        _doRestore(oldBucket);
    }
    if (didReplaceBucket) {
        assert(oldBucket != _bucket);
        oldBucket?->dispose();
    }
}

template<typename S> void RestorationMixinCls<S>::dispose() {
    _properties->forEach([=] (RestorableProperty<Object> property,VoidCallback listener) {
        if (!property->_disposed) {
            property->removeListener(listener);
        }
    });
    _bucket?->dispose();
    _bucket = nullptr;
    super->dispose();
}

template<typename S> bool RestorationMixinCls<S>::_debugDoingRestore() {
    return _debugPropertiesWaitingForReregistration != nullptr;
}

template<typename S> void RestorationMixinCls<S>::_doRestore(RestorationBucket oldBucket) {
    assert([=] () {
        _debugPropertiesWaitingForReregistration = _properties->keys->toList();
        return true;
    }());
    restoreState(oldBucket, _firstRestorePending);
    _firstRestorePending = false;
    assert([=] () {
        if (_debugPropertiesWaitingForReregistration!->isNotEmpty) {
            ;
        }
        _debugPropertiesWaitingForReregistration = nullptr;
        return true;
    }());
}

template<typename S> bool RestorationMixinCls<S>::_updateBucketIfNecessary(RestorationBucket parent, bool restorePending) {
    if (restorationId == nullptr || parent == nullptr) {
        bool didReplace = _setNewBucketIfNecessary(nullptr, restorePending);
        assert(_bucket == nullptr);
        return didReplace;
    }
    assert(restorationId != nullptr);
    assert(parent != nullptr);
    if (restorePending || _bucket == nullptr) {
        RestorationBucket newBucket = parent->claimChild(restorationId!this);
        assert(newBucket != nullptr);
        bool didReplace = _setNewBucketIfNecessary(newBucket, restorePending);
        assert(_bucket == newBucket);
        return didReplace;
    }
    assert(_bucket != nullptr);
    assert(!restorePending);
    _bucket!->rename(restorationId!);
    parent->adoptChild(_bucket!);
    return false;
}

template<typename S> bool RestorationMixinCls<S>::_setNewBucketIfNecessary(RestorationBucket newBucket, bool restorePending) {
    if (newBucket == _bucket) {
        return false;
    }
    RestorationBucket oldBucket = _bucket;
    _bucket = newBucket;
    if (!restorePending) {
        if (_bucket != nullptr) {
            _properties->keys->forEach(_updateProperty);
        }
        didToggleBucket(oldBucket);
    }
    return true;
}

template<typename S> void RestorationMixinCls<S>::_updateProperty(RestorableProperty<Object> property) {
    if (property->enabled) {
        _bucket?->write(property->_restorationId!, property->toPrimitives());
    } else {
        _bucket?-><Object>remove(property->_restorationId!);
    }
}

template<typename S> void RestorationMixinCls<S>::_unregister(RestorableProperty<Object> property) {
    VoidCallback listener = _properties->remove(property)!;
    assert([=] () {
        _debugPropertiesWaitingForReregistration?->remove(property);
        return true;
    }());
    property->removeListener(listener);
    property->_unregister();
}
