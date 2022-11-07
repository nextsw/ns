#ifndef SECURE_SOCKET_H
#define SECURE_SOCKET_H
#include <memory>




class SecureSocket {
public:

    static Future<SecureSocket> connect(host , SecurityContext context, FunctionType keyLog, FunctionType onBadCertificate, int port, List<String> supportedProtocols, Duration timeout);

    static Future<ConnectionTask<SecureSocket>> startConnect(host , SecurityContext context, FunctionType keyLog, FunctionType onBadCertificate, int port, List<String> supportedProtocols);

    static Future<SecureSocket> secure(host , SecurityContext context, FunctionType keyLog, FunctionType onBadCertificate, Socket socket, List<String> supportedProtocols);

    static Future<SecureSocket> secureServer(List<int> bufferedData, SecurityContext context, bool requestClientCertificate, bool requireClientCertificate, Socket socket, List<String> supportedProtocols);

    X509Certificate peerCertificate();

    String selectedProtocol();

    void renegotiate(bool requestClientCertificate, bool requireClientCertificate, bool useSessionCache);

private:

    external void  _(RawSecureSocket rawSocket);

};

class RawSecureSocket {
public:

    static Future<RawSecureSocket> connect(host , SecurityContext context, FunctionType keyLog, FunctionType onBadCertificate, int port, List<String> supportedProtocols, Duration timeout);

    static Future<ConnectionTask<RawSecureSocket>> startConnect(host , SecurityContext context, FunctionType keyLog, FunctionType onBadCertificate, int port, List<String> supportedProtocols);

    static Future<RawSecureSocket> secure(host , SecurityContext context, FunctionType keyLog, FunctionType onBadCertificate, RawSocket socket, StreamSubscription<RawSocketEvent> subscription, List<String> supportedProtocols);

    static Future<RawSecureSocket> secureServer(List<int> bufferedData, SecurityContext context, bool requestClientCertificate, bool requireClientCertificate, RawSocket socket, StreamSubscription<RawSocketEvent> subscription, List<String> supportedProtocols);

    void renegotiate(bool requestClientCertificate, bool requireClientCertificate, bool useSessionCache);

    X509Certificate peerCertificate();

    String selectedProtocol();

private:

};

class X509Certificate {
public:

    Uint8List der();

    String pem();

    Uint8List sha1();

    String subject();

    String issuer();

    DateTime startValidity();

    DateTime endValidity();

private:

    external void  _();

};

class _FilterStatus {
public:
    bool progress;

    bool readEmpty;

    bool writeEmpty;

    bool readPlaintextNoLongerEmpty;

    bool writePlaintextNoLongerFull;

    bool readEncryptedNoLongerFull;

    bool writeEncryptedNoLongerEmpty;


private:

     _FilterStatus();

};

class _RawSecureSocket : Stream<RawSocketEvent> {
public:
    static const int handshakeStatus;

    static const int connectedStatus;

    static const int closedStatus;

    static const int readPlaintextId;

    static const int writePlaintextId;

    static const int readEncryptedId;

    static const int writeEncryptedId;

    static const int bufferCount;

    InternetAddress address;

    bool isServer;

    SecurityContext context;

    bool requestClientCertificate;

    bool requireClientCertificate;

    FunctionType onBadCertificate;

    FunctionType keyLog;

    ReceivePort keyLogPort;


    static Future<_RawSecureSocket> connect(List<int> bufferedData, SecurityContext context, dynamic host, bool isServer, FunctionType keyLog, FunctionType onBadCertificate, bool requestClientCertificate, int requestedPort, bool requireClientCertificate, RawSocket socket, StreamSubscription<RawSocketEvent> subscription, List<String> supportedProtocols);

    StreamSubscription<RawSocketEvent> listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

    int port();

    InternetAddress remoteAddress();

    int remotePort();

    int available();

    Future<RawSecureSocket> close();

    void shutdown(SocketDirection direction);

    bool writeEventsEnabled();

    void writeEventsEnabled(bool value);

    bool readEventsEnabled();

    void readEventsEnabled(bool value);

    Uint8List read(int length);

    SocketMessage readMessage(int count);

    int write(int bytes, List<int> data, int offset);

    int sendMessage(List<SocketControlMessage> controlMessages, int count, List<int> data, int offset);

    X509Certificate peerCertificate();

    String selectedProtocol();

    bool setOption(bool enabled, SocketOption option);

    Uint8List getRawOption(RawSocketOption option);

    void setRawOption(RawSocketOption option);

    void renegotiate(bool requestClientCertificate, bool requireClientCertificate, bool useSessionCache);

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

     _RawSecureSocket(List<int> _bufferedData, RawSocket _socket, InternetAddress address, SecurityContext context, bool isServer, FunctionType keyLog, FunctionType onBadCertificate, bool requestClientCertificate, int requestedPort, bool requireClientCertificate, StreamSubscription<RawSocketEvent> subscription, List<String> supportedProtocols);

    static void _verifyFields(host , bool requestClientCertificate, int requestedPort, bool requireClientCertificate);

    void _owner(owner );

    void _completeCloseCompleter(RawSocket dummy);

    void _close();

    static int _fixOffset(int offset);

    bool _onBadCertificateWrapper(X509Certificate certificate);

    void _eventDispatcher(RawSocketEvent event);

    void _readHandler();

    void _writeHandler();

    void _doneHandler();

    void _reportError(e , StackTrace stackTrace);

    void _closeHandler();

    Future<void> _secureHandshake();

    void _secureHandshakeCompleteHandler();

    void _onPauseStateChange();

    void _onSubscriptionStateChange();

    Future<void> _scheduleFilter();

    Future<void> _tryFilter();

    List<int> _readSocketOrBufferedData(int bytes);

    void _readSocket();

    void _writeSocket();

    void  _scheduleReadEvent();

    void  _sendReadEvent();

    void  _sendWriteEvent();

    Future<_FilterStatus> _pushAllFilterStages();

};

class _ExternalBuffer {
public:
    List<int> data;

    int start;

    int end;

    int size;


    void advanceStart(int bytes);

    void advanceEnd(int bytes);

    bool isEmpty();

    int length();

    int linearLength();

    int free();

    int linearFree();

    Uint8List read(int bytes);

    int write(int bytes, List<int> inputData, int offset);

    int writeFromSource(FunctionType getData);

    bool readToSocket(RawSocket socket);

private:

     _ExternalBuffer(int size);

};

class _SecureFilter {
public:

    void connect(SecurityContext context, String hostName, bool isServer, Uint8List protocols, bool requestClientCertificate, bool requireClientCertificate);

    void destroy();

    Future<bool> handshake();

    String selectedProtocol();

    void rehandshake();

    void init();

    X509Certificate peerCertificate();

    int processBuffer(int bufferIndex);

    void registerBadCertificateCallback(FunctionType callback);

    void registerHandshakeCompleteCallback(FunctionType handshakeCompleteHandler);

    void registerKeyLogPort(SendPort port);

    List<_ExternalBuffer> buffers();

private:

    external void  _();

    int _pointer();

};

class TlsException {
public:
    String type;

    String message;

    OSError osError;


     TlsException(String message, OSError osError);

    String toString();

private:

    void  _(String message, OSError osError, String type);

};

class HandshakeException : TlsException {
public:

     HandshakeException(String message, OSError osError);

private:

};

class CertificateException : TlsException {
public:

     CertificateException(String message, OSError osError);

private:

};

#endif