#ifndef ISOLATE_H
#define ISOLATE_H
#include <memory>

#include <internal/internal.hpp>
#include <async/async.hpp>
#include <typed_data/typed_data.hpp>

// Parts
#include "capability.hpp"


class IsolateSpawnException {
public:
    String message;


     IsolateSpawnException(String message);

    String toString();

private:

};

class Isolate {
public:
    static const int immediate;

    static const int beforeNextEvent;

    SendPort controlPort;

    Capability pauseCapability;

    Capability terminateCapability;


    external String debugName();

     Isolate(SendPort controlPort, Capability pauseCapability, Capability terminateCapability);

    external static Isolate current();

    external static Future<Uri> packageConfig();

    external static Future<Uri> resolvePackageUri(Uri packageUri);

    external static Future<Isolate> spawn<T>(String debugName, FunctionType entryPoint, bool errorsAreFatal, T message, SendPort onError, SendPort onExit, bool paused);

    external static Future<Isolate> spawnUri(List<String> args, bool automaticPackageResolution, bool checked, String debugName, Map<String, String> environment, bool errorsAreFatal, auto message, SendPort onError, SendPort onExit, Uri packageConfig, Uri packageRoot, bool paused, Uri uri);

    Capability pause(Capability resumeCapability);

    external void resume(Capability resumeCapability);

    external void addOnExitListener(Object response, SendPort responsePort);

    external void removeOnExitListener(SendPort responsePort);

    external void setErrorsFatal(bool errorsAreFatal);

    external void kill(int priority);

    external void ping(int priority, Object response, SendPort responsePort);

    external void addErrorListener(SendPort port);

    external void removeErrorListener(SendPort port);

    Stream errors();

    external static Never exit(SendPort finalMessagePort, Object message);

private:

    external void _pause(Capability resumeCapability);

};

class SendPort {
public:

    void send(Object message);

    bool ==(auto other);

    int hashCode();

private:

};

class ReceivePort {
public:

    external  ReceivePort(String debugName);

    external void  fromRawReceivePort(RawReceivePort rawPort);

    StreamSubscription<dynamic> listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

    void close();

    SendPort sendPort();

private:

};

class RawReceivePort {
public:

    external  RawReceivePort(String debugName, FunctionType handler);

    void handler(FunctionType newHandler);

    void close();

    SendPort sendPort();

private:

};

class RemoteError {
public:
    StackTrace stackTrace;


     RemoteError(String description, String stackDescription);

    String toString();

private:
    String _description;


};

class TransferableTypedData {
public:

    external void  fromList(List<TypedData> list);

    ByteBuffer materialize();

private:

};

#endif