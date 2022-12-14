#ifndef DART_IO_SECURE_SERVER_SOCKET
#define DART_IO_SECURE_SERVER_SOCKET
#include <base.hpp>

#include <dart/core/core.hpp>


class SecureServerSocketCls : public StreamCls<SecureSocket> {
public:

    static Future<SecureServerSocket> bind(address , int port, SecurityContext context, int backlog, bool requestClientCertificate, bool requireClientCertificate, bool shared, List<String> supportedProtocols, bool v6Only);

    virtual StreamSubscription<SecureSocket> listen(std::function<void(SecureSocket socket)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError);

    virtual int port();

    virtual InternetAddress address();

    virtual Future<SecureServerSocket> close();

private:
    RawSecureServerSocket _socket;


    virtual void  _(RawSecureServerSocket _socket);
    virtual void _owner(owner );

};
using SecureServerSocket = std::shared_ptr<SecureServerSocketCls>;

class RawSecureServerSocketCls : public StreamCls<RawSecureSocket> {
public:
    bool requestClientCertificate;

    bool requireClientCertificate;

    List<String> supportedProtocols;


    static Future<RawSecureServerSocket> bind(address , int port, SecurityContext context, int backlog, bool requestClientCertificate, bool requireClientCertificate, bool shared, List<String> supportedProtocols, bool v6Only);

    virtual StreamSubscription<RawSecureSocket> listen(std::function<void(RawSecureSocket s)> onData, bool cancelOnError, std::function<void()> onDone, std::function<void ()> onError);

    virtual int port();

    virtual InternetAddress address();

    virtual Future<RawSecureServerSocket> close();

private:
    RawServerSocket _socket;

    StreamController<RawSecureSocket> _controller;

    StreamSubscription<RawSocket> _subscription;

    SecurityContext _context;

    bool _closed;


    virtual void  _(RawServerSocket _socket, SecurityContext _context, bool requestClientCertificate, bool requireClientCertificate, List<String> supportedProtocols);

    virtual void _onData(RawSocket connection);

    virtual void _onPauseStateChange();

    virtual void _onSubscriptionStateChange();

    virtual void _owner(owner );

};
using RawSecureServerSocket = std::shared_ptr<RawSecureServerSocketCls>;


#endif