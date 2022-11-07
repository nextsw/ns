#include "restoration.hpp"
RestorationScope::RestorationScope(Widget child, Unknown, String restorationId) {
    {
        assert(child != nullptr);
    }
}

RestorationBucket RestorationScope::of(BuildContext context) {
    return context.<UnmanagedRestorationScope>dependOnInheritedWidgetOfExactType()?.bucket;
}

State<RestorationScope> RestorationScope::createState() {
    return _RestorationScopeState();
}

String _RestorationScopeState::restorationId() {
    return widget.restorationId;
}

void _RestorationScopeState::restoreState(bool initialRestore, RestorationBucket oldBucket) {
}

Widget _RestorationScopeState::build(BuildContext context) {
    return UnmanagedRestorationScope(bucket, widget.child);
}

UnmanagedRestorationScope::UnmanagedRestorationScope(RestorationBucket bucket, Unknown, Unknown) {
    {
        assert(child != nullptr);
    }
}

bool UnmanagedRestorationScope::updateShouldNotify(UnmanagedRestorationScope oldWidget) {
    return oldWidget.bucket != bucket;
}

RootRestorationScope::RootRestorationScope(Widget child, Unknown, String restorationId) {
    {
        assert(child != nullptr);
    }
}

State<RootRestorationScope> RootRestorationScope::createState() {
    return _RootRestorationScopeState();
}

void _RootRestorationScopeState::didChangeDependencies() {
    super.didChangeDependencies();
    _ancestorBucket = RestorationScope.of(context);
    _loadRootBucketIfNecessary();
    _okToRenderBlankContainer = widget.restorationId != nullptr && _needsRootBucketInserted;
}

void _RootRestorationScopeState::didUpdateWidget(RootRestorationScope oldWidget) {
    super.didUpdateWidget(oldWidget);
    _loadRootBucketIfNecessary();
}

void _RootRestorationScopeState::dispose() {
    if (_rootBucketValid) {
        ServicesBinding.instance.restorationManager.removeListener(_replaceRootBucket);
    }
    super.dispose();
}

Widget _RootRestorationScopeState::build(BuildContext context) {
    if (_okToRenderBlankContainer! && _isWaitingForRootBucket) {
        return const SizedBox.shrink();
    }
    return UnmanagedRestorationScope(_ancestorBucket ?? _rootBucket, RestorationScope(widget.restorationId, widget.child));
}

bool _RootRestorationScopeState::_needsRootBucketInserted() {
    return _ancestorBucket == nullptr;
}

bool _RootRestorationScopeState::_isWaitingForRootBucket() {
    return widget.restorationId != nullptr && _needsRootBucketInserted && !_rootBucketValid;
}

void _RootRestorationScopeState::_loadRootBucketIfNecessary() {
    if (_isWaitingForRootBucket && !_isLoadingRootBucket) {
        _isLoadingRootBucket = true;
        RendererBinding.instance.deferFirstFrame();
        ServicesBinding.instance.restorationManager.rootBucket.then();
    }
}

void _RootRestorationScopeState::_replaceRootBucket() {
    _rootBucketValid = false;
    _rootBucket = nullptr;
    ServicesBinding.instance.restorationManager.removeListener(_replaceRootBucket);
    _loadRootBucketIfNecessary();
    assert(!_isWaitingForRootBucket);
}

bool RestorableProperty::enabled() {
    return true;
}

void RestorableProperty::dispose() {
    assert(ChangeNotifier.debugAssertNotDisposed(this));
    _owner?._unregister(this);
    super.dispose();
    _disposed = true;
}

State RestorableProperty::state() {
    assert(isRegistered);
    assert(ChangeNotifier.debugAssertNotDisposed(this));
    return _owner!;
}

bool RestorableProperty::isRegistered() {
    assert(ChangeNotifier.debugAssertNotDisposed(this));
    return _restorationId != nullptr;
}

void RestorableProperty::_register(RestorationMixin owner, String restorationId) {
    assert(ChangeNotifier.debugAssertNotDisposed(this));
    assert(restorationId != nullptr);
    assert(owner != nullptr);
    _restorationId = restorationId;
    _owner = owner;
}

void RestorableProperty::_unregister() {
    assert(ChangeNotifier.debugAssertNotDisposed(this));
    assert(_restorationId != nullptr);
    assert(_owner != nullptr);
    _restorationId = nullptr;
    _owner = nullptr;
}

RestorationBucket RestorationMixin::bucket() {
    return _bucket;
}

void RestorationMixin::didToggleBucket(RestorationBucket oldBucket) {
    assert(_bucket?.isReplacing != true);
}

void RestorationMixin::registerForRestoration(RestorableProperty<Object> property, String restorationId) {
    assert(property != nullptr);
    assert(restorationId != nullptr);
    assert(property._restorationId == nullptr || (_debugDoingRestore && property._restorationId == restorationId), "Property is already registered under ${property._restorationId}.");
    assert(_debugDoingRestore || !_properties.keys.map().contains(restorationId), ""$restorationId" is already registered to another property.");
    bool hasSerializedValue = bucket?.contains(restorationId) ?? false;
    Object initialValue = hasSerializedValue? property.fromPrimitives(bucket!.<Object>read(restorationId)) : property.createDefaultValue();
    if (!property.isRegistered) {
        property._register(restorationId, this);
        ;
        property.addListener(listener);
        _properties[property] = listener;
    }
    assert(property._restorationId == restorationId && property._owner == this && _properties.containsKey(property));
    property.initWithValue(initialValue);
    if (!hasSerializedValue && property.enabled && bucket != nullptr) {
        _updateProperty(property);
    }
    assert(());
}

void RestorationMixin::unregisterFromRestoration(RestorableProperty<Object> property) {
    assert(property != nullptr);
    assert(property._owner == this);
    _bucket?.<Object>remove(property._restorationId!);
    _unregister(property);
}

void RestorationMixin::didUpdateRestorationId() {
    if (_currentParent == nullptr || _bucket?.restorationId == restorationId || restorePending) {
        return;
    }
    RestorationBucket oldBucket = _bucket;
    assert(!restorePending);
    bool didReplaceBucket = _updateBucketIfNecessary(_currentParent, false);
    if (didReplaceBucket) {
        assert(oldBucket != _bucket);
        assert(_bucket == nullptr || oldBucket == nullptr);
        oldBucket?.dispose();
    }
}

void RestorationMixin::didUpdateWidget(S oldWidget) {
    super.didUpdateWidget(oldWidget);
    didUpdateRestorationId();
}

bool RestorationMixin::restorePending() {
    if (_firstRestorePending) {
        return true;
    }
    if (restorationId == nullptr) {
        return false;
    }
    RestorationBucket potentialNewParent = RestorationScope.of(context);
    return potentialNewParent != _currentParent && (potentialNewParent?.isReplacing ?? false);
}

void RestorationMixin::didChangeDependencies() {
    super.didChangeDependencies();
    RestorationBucket oldBucket = _bucket;
    bool needsRestore = restorePending;
    _currentParent = RestorationScope.of(context);
    bool didReplaceBucket = _updateBucketIfNecessary(_currentParent, needsRestore);
    if (needsRestore) {
        _doRestore(oldBucket);
    }
    if (didReplaceBucket) {
        assert(oldBucket != _bucket);
        oldBucket?.dispose();
    }
}

void RestorationMixin::dispose() {
    _properties.forEach();
    _bucket?.dispose();
    _bucket = nullptr;
    super.dispose();
}

bool RestorationMixin::_debugDoingRestore() {
    return _debugPropertiesWaitingForReregistration != nullptr;
}

void RestorationMixin::_doRestore(RestorationBucket oldBucket) {
    assert(());
    restoreState(oldBucket, _firstRestorePending);
    _firstRestorePending = false;
    assert(());
}

bool RestorationMixin::_updateBucketIfNecessary(RestorationBucket parent, bool restorePending) {
    if (restorationId == nullptr || parent == nullptr) {
        bool didReplace = _setNewBucketIfNecessary(nullptr, restorePending);
        assert(_bucket == nullptr);
        return didReplace;
    }
    assert(restorationId != nullptr);
    assert(parent != nullptr);
    if (restorePending || _bucket == nullptr) {
        RestorationBucket newBucket = parent.claimChild(restorationId!this);
        assert(newBucket != nullptr);
        bool didReplace = _setNewBucketIfNecessary(newBucket, restorePending);
        assert(_bucket == newBucket);
        return didReplace;
    }
    assert(_bucket != nullptr);
    assert(!restorePending);
    _bucket!.rename(restorationId!);
    parent.adoptChild(_bucket!);
    return false;
}

bool RestorationMixin::_setNewBucketIfNecessary(RestorationBucket newBucket, bool restorePending) {
    if (newBucket == _bucket) {
        return false;
    }
    RestorationBucket oldBucket = _bucket;
    _bucket = newBucket;
    if (!restorePending) {
        if (_bucket != nullptr) {
            _properties.keys.forEach(_updateProperty);
        }
        didToggleBucket(oldBucket);
    }
    return true;
}

void RestorationMixin::_updateProperty(RestorableProperty<Object> property) {
    if (property.enabled) {
        _bucket?.write(property._restorationId!, property.toPrimitives());
    } else {
        _bucket?.<Object>remove(property._restorationId!);
    }
}

void RestorationMixin::_unregister(RestorableProperty<Object> property) {
    VoidCallback listener = _properties.remove(property)!;
    assert(());
    property.removeListener(listener);
    property._unregister();
}
