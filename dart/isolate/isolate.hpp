#ifndef DART_ISOLATE_ISOLATE
#define DART_ISOLATE_ISOLATE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/internal/internal.hpp>
#include <dart/async/async.hpp>
#include <dart/typed_data/typed_data.hpp>


class IsolateSpawnExceptionCls : public ObjectCls {
public:
    String message;


     IsolateSpawnExceptionCls(String message);
    virtual String toString();

private:

};
using IsolateSpawnException = std::shared_ptr<IsolateSpawnExceptionCls>;

class IsolateCls : public ObjectCls {
public:
    static int immediate;

    static int beforeNextEvent;

    SendPort controlPort;

    Capability pauseCapability;

    Capability terminateCapability;


    String debugName();
     IsolateCls(SendPort controlPort, Capability pauseCapability, Capability terminateCapability);
    static Isolate current();
    static Future<Uri> packageConfig();
    static Future<Uri> resolvePackageUri(Uri packageUri);
    template<typename T>  static Future<Isolate> spawn(String debugName, void entryPoint(T message) , bool errorsAreFatal, T message, SendPort onError, SendPort onExit, bool paused);
    static Future<Isolate> spawnUri(List<String> args, bool automaticPackageResolution, bool checked, String debugName, Map<String, String> environment, bool errorsAreFatal, auto message, SendPort onError, SendPort onExit, Uri packageConfig, Uri packageRoot, bool paused, Uri uri);
    virtual Capability pause(Capability resumeCapability);

    void resume(Capability resumeCapability);
    void addOnExitListener(Object response, SendPort responsePort);
    void removeOnExitListener(SendPort responsePort);
    void setErrorsFatal(bool errorsAreFatal);
    void kill(int priority);
    void ping(int priority, Object response, SendPort responsePort);
    void addErrorListener(SendPort port);
    void removeErrorListener(SendPort port);
    virtual Stream errors();

    static Never exit(SendPort finalMessagePort, Object message);
private:

    void _pause(Capability resumeCapability);
};
using Isolate = std::shared_ptr<IsolateCls>;

class SendPortCls : public ObjectCls {
public:

    virtual void send(Object message);
    virtual bool operator==(auto other);
    virtual int hashCode();
private:

};
using SendPort = std::shared_ptr<SendPortCls>;

class ReceivePortCls : public ObjectCls {
public:

     ReceivePortCls(String debugName);
    void  fromRawReceivePort(RawReceivePort rawPort);
    virtual StreamSubscription<dynamic> listen(bool cancelOnError, void onData(auto message) , void onDone() , void  onError() );
    virtual void close();
    virtual SendPort sendPort();
private:

};
using ReceivePort = std::shared_ptr<ReceivePortCls>;

class RawReceivePortCls : public ObjectCls {
public:

     RawReceivePortCls(String debugName, void  handler() );
    virtual void handler(void  newHandler() );
    virtual void close();
    virtual SendPort sendPort();
private:

};
using RawReceivePort = std::shared_ptr<RawReceivePortCls>;

class RemoteErrorCls : public ObjectCls {
public:
    StackTrace stackTrace;


     RemoteErrorCls(String description, String stackDescription);

    virtual String toString();

private:
    String _description;


};
using RemoteError = std::shared_ptr<RemoteErrorCls>;

class TransferableTypedDataCls : public ObjectCls {
public:

    void  fromList(List<TypedData> list);
    virtual ByteBuffer materialize();
private:

};
using TransferableTypedData = std::shared_ptr<TransferableTypedDataCls>;

// Parts
#include "capability.hpp"

#endif