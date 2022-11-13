#ifndef DART_IO_SECURE_SOCKET
#define DART_IO_SECURE_SOCKET
#include <base.hpp>

#include <dart/core/core.hpp>


class SecureSocketCls : public ObjectCls {
public:

    static Future<SecureSocket> connect(host , int port, SecurityContext context, std::function<void(String line)> keyLog, std::function<bool(X509Certificate certificate)> onBadCertificate, List<String> supportedProtocols, Duration timeout);

    static Future<ConnectionTask<SecureSocket>> startConnect(host , int port, SecurityContext context, std::function<void(String line)> keyLog, std::function<bool(X509Certificate certificate)> onBadCertificate, List<String> supportedProtocols);

    static Future<SecureSocket> secure(Socket socket, host , SecurityContext context, std::function<void(String line)> keyLog, std::function<bool(X509Certificate certificate)> onBadCertificate, List<String> supportedProtocols);

    static Future<SecureSocket> secureServer(Socket socket, SecurityContext context, List<int> bufferedData, bool requestClientCertificate, bool requireClientCertificate, List<String> supportedProtocols);

    virtual X509Certificate peerCertificate();
    virtual String selectedProtocol();
    virtual void renegotiate(bool requestClientCertificate, bool requireClientCertificate, bool useSessionCache);
private:

    void  _(RawSecureSocket rawSocket);
};
using SecureSocket = std::shared_ptr<SecureSocketCls>;

class RawSecureSocketCls : public ObjectCls {
public:

    static Future<RawSecureSocket> connect(host , int port, SecurityContext context, std::function<void(String line)> keyLog, std::function<bool(X509Certificate certificate)> onBadCertificate, List<String> supportedProtocols, Duration timeout);

    static Future<ConnectionTask<RawSecureSocket>> startConnect(host , int port, SecurityContext context, std::function<void(String line)> keyLog, std::function<bool(X509Certificate certificate)> onBadCertificate, List<String> supportedProtocols);

    static Future<RawSecureSocket> secure(RawSocket socket, host , SecurityContext context, std::function<void(String line)> keyLog, std::function<bool(X509Certificate certificate)> onBadCertificate, StreamSubscription<RawSocketEvent> subscription, List<String> supportedProtocols);

    static Future<RawSecureSocket> secureServer(RawSocket socket, SecurityContext context, List<int> bufferedData, bool requestClientCertificate, bool requireClientCertificate, StreamSubscription<RawSocketEvent> subscription, List<String> supportedProtocols);

    virtual void renegotiate(bool requestClientCertificate, bool requireClientCertificate, bool useSessionCache);
    virtual X509Certificate peerCertificate();
    virtual String selectedProtocol();
private:

};
using RawSecureSocket = std::shared_ptr<RawSecureSocketCls>;

class X509CertificateCls : public ObjectCls {
public:

    virtual Uint8List der();
    virtual String pem();
    virtual Uint8List sha1();
    virtual String subject();
    virtual String issuer();
    virtual DateTime startValidity();
    virtual DateTime endValidity();
private:

    void  _();
};
using X509Certificate = std::shared_ptr<X509CertificateCls>;

class _FilterStatusCls : public ObjectCls {
public:
    bool progress;

    bool readEmpty;

    bool writeEmpty;

    bool readPlaintextNoLongerEmpty;

    bool writePlaintextNoLongerFull;

    bool readEncryptedNoLongerFull;

    bool writeEncryptedNoLongerEmpty;


private:

     _FilterStatusCls();
};
using _FilterStatus = std::shared_ptr<_FilterStatusCls>;

class _RawSecureSocketCls : public StreamCls<RawSocketEvent> {
public:
    static int handshakeStatus;

    static int connectedStatus;

    static int closedStatus;

    static int readPlaintextId;

    static int writePlaintextId;

    static int readEncryptedId;

    static int writeEncryptedId;

    static int bufferCount;

    InternetAddress address;

    bool isServer;

    SecurityContext context;

    bool requestClientCertificate;

    bool requireClientCertificate;

    std::function<bool(X509Certificate certificate)> onBadCertificate;

    std::function<void(String line)> keyLog;

    ReceivePort keyLogPort;


    static Future<_RawSecureSocket> connect(Object host, int requestedPort, bool isServer, RawSocket socket, List<int> bufferedData, SecurityContext context, std::function<void(String line)> keyLog, std::function<bool(X509Certificate certificate)> onBadCertificate, bool requestClientCertificate, bool requireClientCertificate, StreamSubscription<RawSocketEvent> subscription, List<String> supportedProtocols);

    virtual StreamSubscription<RawSocketEvent> listen(std::function<void(RawSocketEvent data)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError);

    virtual int port();

    virtual InternetAddress remoteAddress();

    virtual int remotePort();

    virtual int available();

    virtual Future<RawSecureSocket> close();

    virtual void shutdown(SocketDirection direction);

    virtual bool writeEventsEnabled();

    virtual void writeEventsEnabled(bool value);

    virtual bool readEventsEnabled();

    virtual void readEventsEnabled(bool value);

    virtual Uint8List read(int length);

    virtual SocketMessage readMessage(int count);

    virtual int write(List<int> data, int offset, int bytes);

    virtual int sendMessage(List<SocketControlMessage> controlMessages, List<int> data, int offset, int count);

    virtual X509Certificate peerCertificate();

    virtual String selectedProtocol();

    virtual bool setOption(SocketOption option, bool enabled);

    virtual Uint8List getRawOption(RawSocketOption option);

    virtual void setRawOption(RawSocketOption option);

    virtual void renegotiate(bool requestClientCertificate, bool requireClientCertificate, bool useSessionCache);

private:
    RawSocket _socket;

    Completer<_RawSecureSocket> _handshakeComplete;

    auto  _controller;

    StreamSubscription<RawSocketEvent> _socketSubscription;

    List<int> _bufferedData;

    int _bufferedDataIndex;

    auto _status;

    bool _writeEventsEnabled;

    bool _readEventsEnabled;

    int _pauseCount;

    bool _pendingReadEvent;

    bool _socketClosedRead;

    bool _socketClosedWrite;

    bool _closedRead;

    bool _closedWrite;

    Completer<RawSecureSocket> _closeCompleter;

    _FilterStatus _filterStatus;

    bool _connectPending;

    bool _filterPending;

    bool _filterActive;

    _SecureFilter _secureFilter;

    String _selectedProtocol;


    static bool _isBufferEncrypted(int identifier);

     _RawSecureSocketCls(InternetAddress address, int requestedPort, bool isServer, SecurityContext context, RawSocket _socket, StreamSubscription<RawSocketEvent> subscription, List<int> _bufferedData, bool requestClientCertificate, bool requireClientCertificate, std::function<bool(X509Certificate certificate)> onBadCertificate, std::function<void(String line)> keyLog, List<String> supportedProtocols);

    static void _verifyFields(host , int requestedPort, bool requestClientCertificate, bool requireClientCertificate);

    virtual void _owner(owner );

    virtual void _completeCloseCompleter(RawSocket dummy);

    virtual void _close();

    static int _fixOffset(int offset);

    virtual bool _onBadCertificateWrapper(X509Certificate certificate);

    virtual void _eventDispatcher(RawSocketEvent event);

    virtual void _readHandler();

    virtual void _writeHandler();

    virtual void _doneHandler();

    virtual void _reportError(e , StackTrace stackTrace);

    virtual void _closeHandler();

    virtual Future<void> _secureHandshake();

    virtual void _secureHandshakeCompleteHandler();

    virtual void _onPauseStateChange();

    virtual void _onSubscriptionStateChange();

    virtual Future<void> _scheduleFilter();

    virtual Future<void> _tryFilter();

    virtual List<int> _readSocketOrBufferedData(int bytes);

    virtual void _readSocket();

    virtual void _writeSocket();

    virtual void  _scheduleReadEvent();

    virtual void  _sendReadEvent();

    virtual void  _sendWriteEvent();

    virtual Future<_FilterStatus> _pushAllFilterStages();

};
using _RawSecureSocket = std::shared_ptr<_RawSecureSocketCls>;

class _ExternalBufferCls : public ObjectCls {
public:
    List<int> data;

    int start;

    int end;

    int size;


    virtual void advanceStart(int bytes);

    virtual void advanceEnd(int bytes);

    virtual bool isEmpty();

    virtual int length();

    virtual int linearLength();

    virtual int free();

    virtual int linearFree();

    virtual Uint8List read(int bytes);

    virtual int write(List<int> inputData, int offset, int bytes);

    virtual int writeFromSource(std::function<List<int>(int requested)> getData);

    virtual bool readToSocket(RawSocket socket);

private:

     _ExternalBufferCls(int size);

};
using _ExternalBuffer = std::shared_ptr<_ExternalBufferCls>;

class _SecureFilterCls : public ObjectCls {
public:

    virtual void connect(String hostName, SecurityContext context, bool isServer, bool requestClientCertificate, bool requireClientCertificate, Uint8List protocols);
    virtual void destroy();
    virtual Future<bool> handshake();
    virtual String selectedProtocol();
    virtual void rehandshake();
    virtual void init();
    virtual X509Certificate peerCertificate();
    virtual int processBuffer(int bufferIndex);
    virtual void registerBadCertificateCallback(std::function<void ()> callback);
    virtual void registerHandshakeCompleteCallback(std::function<void ()> handshakeCompleteHandler);
    virtual void registerKeyLogPort(SendPort port);
    virtual List<_ExternalBuffer> buffers();
private:

    void  _();
    virtual int _pointer();
};
using _SecureFilter = std::shared_ptr<_SecureFilterCls>;

class TlsExceptionCls : public ObjectCls {
public:
    String type;

    String message;

    OSError osError;


     TlsExceptionCls(String message, OSError osError);

    virtual String toString();

private:

    virtual void  _(String type, String message, OSError osError);
};
using TlsException = std::shared_ptr<TlsExceptionCls>;

class HandshakeExceptionCls : public TlsExceptionCls {
public:

     HandshakeExceptionCls(String message, OSError osError);

private:

};
using HandshakeException = std::shared_ptr<HandshakeExceptionCls>;

class CertificateExceptionCls : public TlsExceptionCls {
public:

     CertificateExceptionCls(String message, OSError osError);

private:

};
using CertificateException = std::shared_ptr<CertificateExceptionCls>;


#endif