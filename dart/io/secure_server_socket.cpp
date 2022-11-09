#include "secure_server_socket.hpp"
Future<SecureServerSocket> SecureServerSocketCls::bind(address , int backlog, SecurityContext context, int port, bool requestClientCertificate, bool requireClientCertificate, bool shared, List<String> supportedProtocols, bool v6Only) {
    return RawSecureServerSocketCls->bind(address, port, contextbacklog, v6Only, requestClientCertificate, requireClientCertificate, supportedProtocols, shared)->then([=] (Unknown  serverSocket)     {
        SecureServerSocketCls->_(serverSocket);
    });
}

StreamSubscription<SecureSocket> SecureServerSocketCls::listen(bool cancelOnError, void onData(SecureSocket socket) , void onDone() , void  onError() ) {
    return _socket->map([=] (Unknown  rawSocket)     {
        SecureSocketCls->_(rawSocket);
    })->listen(onDataonError, onDone, cancelOnError);
}

int SecureServerSocketCls::port() {
    return _socket->port;
}

InternetAddress SecureServerSocketCls::address() {
    return _socket->address;
}

Future<SecureServerSocket> SecureServerSocketCls::close() {
    return _socket->close()->then([=] ()     {
        this;
    });
}

void SecureServerSocketCls::_owner(owner ) {
    _socket->_owner = owner;
}

Future<RawSecureServerSocket> RawSecureServerSocketCls::bind(address , int backlog, SecurityContext context, int port, bool requestClientCertificate, bool requireClientCertificate, bool shared, List<String> supportedProtocols, bool v6Only) {
    return RawServerSocketCls->bind(address, portbacklog, v6Only, shared)->then([=] (Unknown  serverSocket)     {
        RawSecureServerSocketCls->_(serverSocket, context, requestClientCertificate, requireClientCertificate, supportedProtocols);
    });
}

StreamSubscription<RawSecureSocket> RawSecureServerSocketCls::listen(bool cancelOnError, void onData(RawSecureSocket s) , void onDone() , void  onError() ) {
    return _controller->stream->listen(onDataonError, onDone, cancelOnError);
}

int RawSecureServerSocketCls::port() {
    return _socket->port;
}

InternetAddress RawSecureServerSocketCls::address() {
    return _socket->address;
}

Future<RawSecureServerSocket> RawSecureServerSocketCls::close() {
    _closed = true;
    return _socket->close()->then([=] ()     {
        this;
    });
}

void RawSecureServerSocketCls::_(SecurityContext _context, RawServerSocket _socket, bool requestClientCertificate, bool requireClientCertificate, List<String> supportedProtocols) {
    _controller = <RawSecureSocket>make<StreamControllerCls>(true, _onSubscriptionStateChange, _onPauseStateChange, _onPauseStateChange, _onSubscriptionStateChange);
}

void RawSecureServerSocketCls::_onData(RawSocket connection) {
    auto remotePort;
    try {
        remotePort = connection->remotePort;
    } catch (Unknown e) {
        return;
    };
    _RawSecureSocketCls->connect(connection->address, remotePort, true, connection_context, requestClientCertificate, requireClientCertificate, supportedProtocols)->then([=] (RawSecureSocket secureConnection) {
        if (_closed) {
            secureConnection->close();
        } else {
            _controller->add(secureConnection);
        }
    })->catchError([=] (Unknown  e,Unknown  s) {
        if (!_closed) {
            _controller->addError(e, s);
        }
    });
}

void RawSecureServerSocketCls::_onPauseStateChange() {
    if (_controller->isPaused) {
        _subscription!->pause();
    } else {
        _subscription!->resume();
    }
}

void RawSecureServerSocketCls::_onSubscriptionStateChange() {
    if (_controller->hasListener) {
        _subscription = _socket->listen(_onData_controller->addError, _controller->close);
    } else {
        close();
    }
}

void RawSecureServerSocketCls::_owner(owner ) {
    (((dynamic)_socket))->_owner = owner;
}
