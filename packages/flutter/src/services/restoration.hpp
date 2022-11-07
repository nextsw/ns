#ifndef RESTORATION_H
#define RESTORATION_H
#include <memory>
#include <typed_data.hpp>

#include <async/async.hpp>
#include <flutter/foundation.hpp>
#include <flutter/scheduler.hpp>
#include "message_codecs.hpp"
#include "system_channels.hpp"



class RestorationManager : ChangeNotifier {
public:

     RestorationManager();

    void initChannels();

    Future<RestorationBucket> rootBucket();

    bool isReplacing();

    void handleRestorationUpdateFromEngine(Uint8List data, bool enabled);

    Future<void> sendToEngine(Uint8List encodedData);

    void scheduleSerializationFor(RestorationBucket bucket);

    void unscheduleSerializationFor(RestorationBucket bucket);

    void flushData();

private:
    RestorationBucket _rootBucket;

    Completer<RestorationBucket> _pendingRootBucket;

    bool _rootBucketIsValid;

    bool _isReplacing;

    bool _debugDoingUpdate;

    bool _serializationScheduled;

    Set<RestorationBucket> _bucketsNeedingSerialization;


    Future<void> _getRootBucketFromEngine();

    void _parseAndHandleRestorationUpdateFromEngine(Map<Object, Object> update);

    Future<void> _methodHandler(MethodCall call);

    Map<Object, Object> _decodeRestorationData(Uint8List data);

    Uint8List _encodeRestorationData(Map<Object, Object> data);

    void _doSerialization();

};

class RestorationBucket {
public:

    void  empty(Object debugOwner, String restorationId);

    void  root(RestorationManager manager, Map<Object, Object> rawData);

    void  child(Object debugOwner, RestorationBucket parent, String restorationId);

    Object debugOwner();

    bool isReplacing();

    String restorationId();

    P read<P>(String restorationId);

    void write<P>(String restorationId, P value);

    P remove<P>(String restorationId);

    bool contains(String restorationId);

    RestorationBucket claimChild(Object debugOwner, String restorationId);

    void adoptChild(RestorationBucket child);

    void finalize();

    void rename(String newRestorationId);

    void dispose();

    String toString();

private:
    static const String _childrenMapKey;

    static const String _valuesMapKey;

    Map<Object, Object> _rawData;

    Object _debugOwner;

    RestorationManager _manager;

    RestorationBucket _parent;

    String _restorationId;

    Map<String, RestorationBucket> _claimedChildren;

    Map<String, List<RestorationBucket>> _childrenToAdd;

    bool _needsSerialization;

    bool _debugDisposed;


    Map<Object, Object> _rawChildren();

    Map<Object, Object> _rawValues();

    void _dropChild(RestorationBucket child);

    void _markNeedsSerialization();

    void _recursivelyUpdateManager(RestorationBucket bucket);

    void _updateManager(RestorationManager newManager);

    bool _debugAssertIntegrity();

    void _removeChildData(RestorationBucket child);

    void _addChildData(RestorationBucket child);

    void _finalizeAddChildData(RestorationBucket child);

    void _visitChildren(bool concurrentModification, _BucketVisitor visitor);

    bool _debugAssertNotDisposed();

};
bool debugIsSerializableForRestoration(Object object);


#endif