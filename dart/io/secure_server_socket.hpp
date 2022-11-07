#ifndef SECURE_SERVER_SOCKET_H
#define SECURE_SERVER_SOCKET_H
#include <memory>




class SecureServerSocket : Stream<SecureSocket> {
public:

    static Future<SecureServerSocket> bind(address , int backlog, SecurityContext context, int port, bool requestClientCertificate, bool requireClientCertificate, bool shared, List<String> supportedProtocols, bool v6Only);

    StreamSubscription<SecureSocket> listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

    int port();

    InternetAddress address();

    Future<SecureServerSocket> close();

private:
    RawSecureServerSocket _socket;


    void  _(RawSecureServerSocket _socket);

    void _owner(owner );

};

class RawSecureServerSocket : Stream<RawSecureSocket> {
public:
    bool requestClientCertificate;

    bool requireClientCertificate;

    List<String> supportedProtocols;


    static Future<RawSecureServerSocket> bind(address , int backlog, SecurityContext context, int port, bool requestClientCertificate, bool requireClientCertificate, bool shared, List<String> supportedProtocols, bool v6Only);

    StreamSubscription<RawSecureSocket> listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

    int port();

    InternetAddress address();

    Future<RawSecureServerSocket> close();

private:
    RawServerSocket _socket;

    StreamController<RawSecureSocket> _controller;

    StreamSubscription<RawSocket> _subscription;

    SecurityContext _context;

    bool _closed;


    void  _(SecurityContext _context, RawServerSocket _socket, bool requestClientCertificate, bool requireClientCertificate, List<String> supportedProtocols);

    void _onData(RawSocket connection);

    void _onPauseStateChange();

    void _onSubscriptionStateChange();

    void _owner(owner );

};

#endif