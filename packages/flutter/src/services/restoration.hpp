#ifndef PACKAGES_FLUTTER_SRC_SERVICES_RESTORATION
#define PACKAGES_FLUTTER_SRC_SERVICES_RESTORATION
#include <base.hpp>
#include <dart/typed_data/typed_data.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "message_codecs.hpp"
#include "system_channels.hpp"


class RestorationManagerCls : public ChangeNotifierCls {
public:

     RestorationManagerCls();

    virtual void initChannels();

    virtual Future<RestorationBucket> rootBucket();

    virtual bool isReplacing();

    virtual void handleRestorationUpdateFromEngine(Uint8List data, bool enabled);

    virtual Future<void> sendToEngine(Uint8List encodedData);

    virtual void scheduleSerializationFor(RestorationBucket bucket);

    virtual void unscheduleSerializationFor(RestorationBucket bucket);

    virtual void flushData();

private:
    RestorationBucket _rootBucket;

    Completer<RestorationBucket> _pendingRootBucket;

    bool _rootBucketIsValid;

    bool _isReplacing;

    bool _debugDoingUpdate;

    bool _serializationScheduled;

    Set<RestorationBucket> _bucketsNeedingSerialization;


    virtual Future<void> _getRootBucketFromEngine();

    virtual void _parseAndHandleRestorationUpdateFromEngine(Map<Object, Object> update);

    virtual Future<void> _methodHandler(MethodCall call);

    virtual Map<Object, Object> _decodeRestorationData(Uint8List data);

    virtual Uint8List _encodeRestorationData(Map<Object, Object> data);

    virtual void _doSerialization();

};
using RestorationManager = std::shared_ptr<RestorationManagerCls>;

class RestorationBucketCls : public ObjectCls {
public:

    virtual void  empty(Object debugOwner, String restorationId);

    virtual void  root(RestorationManager manager, Map<Object, Object> rawData);

    virtual void  child(Object debugOwner, RestorationBucket parent, String restorationId);

    virtual Object debugOwner();

    virtual bool isReplacing();

    virtual String restorationId();

    template<typename P>
 virtual P read(String restorationId);

    template<typename P>
 virtual void write(String restorationId, P value);

    template<typename P>
 virtual P remove(String restorationId);

    virtual bool contains(String restorationId);

    virtual RestorationBucket claimChild(Object debugOwner, String restorationId);

    virtual void adoptChild(RestorationBucket child);

    virtual void finalize();

    virtual void rename(String newRestorationId);

    virtual void dispose();

    virtual String toString();

private:
    static String _childrenMapKey;

    static String _valuesMapKey;

    Map<Object, Object> _rawData;

    Object _debugOwner;

    RestorationManager _manager;

    RestorationBucket _parent;

    String _restorationId;

    Map<String, RestorationBucket> _claimedChildren;

    Map<String, List<RestorationBucket>> _childrenToAdd;

    bool _needsSerialization;

    bool _debugDisposed;


    virtual Map<Object, Object> _rawChildren();

    virtual Map<Object, Object> _rawValues();

    virtual void _dropChild(RestorationBucket child);

    virtual void _markNeedsSerialization();

    virtual void _recursivelyUpdateManager(RestorationBucket bucket);

    virtual void _updateManager(RestorationManager newManager);

    virtual bool _debugAssertIntegrity();

    virtual void _removeChildData(RestorationBucket child);

    virtual void _addChildData(RestorationBucket child);

    virtual void _finalizeAddChildData(RestorationBucket child);

    virtual void _visitChildren(bool concurrentModification, _BucketVisitor visitor);

    virtual bool _debugAssertNotDisposed();

};
using RestorationBucket = std::shared_ptr<RestorationBucketCls>;
bool debugIsSerializableForRestoration(Object object);



#endif