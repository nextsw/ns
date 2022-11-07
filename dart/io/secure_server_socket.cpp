#include "secure_server_socket.hpp"
Future<SecureServerSocket> SecureServerSocket::bind(address , int backlog, SecurityContext context, int port, bool requestClientCertificate, bool requireClientCertificate, bool shared, List<String> supportedProtocols, bool v6Only) {
    return RawSecureServerSocket.bind(address, port, contextbacklog, v6Only, requestClientCertificate, requireClientCertificate, supportedProtocols, shared).then();
}

StreamSubscription<SecureSocket> SecureServerSocket::listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    return _socket.map().listen(onDataonError, onDone, cancelOnError);
}

int SecureServerSocket::port() {
    return _socket.port;
}

InternetAddress SecureServerSocket::address() {
    return _socket.address;
}

Future<SecureServerSocket> SecureServerSocket::close() {
    return _socket.close().then();
}

void SecureServerSocket::_owner(owner ) {
    _socket._owner = owner;
}

Future<RawSecureServerSocket> RawSecureServerSocket::bind(address , int backlog, SecurityContext context, int port, bool requestClientCertificate, bool requireClientCertificate, bool shared, List<String> supportedProtocols, bool v6Only) {
    return RawServerSocket.bind(address, portbacklog, v6Only, shared).then();
}

StreamSubscription<RawSecureSocket> RawSecureServerSocket::listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    return _controller.stream.listen(onDataonError, onDone, cancelOnError);
}

int RawSecureServerSocket::port() {
    return _socket.port;
}

InternetAddress RawSecureServerSocket::address() {
    return _socket.address;
}

Future<RawSecureServerSocket> RawSecureServerSocket::close() {
    _closed = true;
    return _socket.close().then();
}

void RawSecureServerSocket::_(SecurityContext _context, RawServerSocket _socket, bool requestClientCertificate, bool requireClientCertificate, List<String> supportedProtocols) {
    _controller = <RawSecureSocket>StreamController(true, _onSubscriptionStateChange, _onPauseStateChange, _onPauseStateChange, _onSubscriptionStateChange);
}

void RawSecureServerSocket::_onData(RawSocket connection) {
    auto remotePort;
    ;
    _RawSecureSocket.connect(connection.address, remotePort, true, connection_context, requestClientCertificate, requireClientCertificate, supportedProtocols).then().catchError();
}

void RawSecureServerSocket::_onPauseStateChange() {
    if (_controller.isPaused) {
        _subscription!.pause();
    } else {
        _subscription!.resume();
    }
}

void RawSecureServerSocket::_onSubscriptionStateChange() {
    if (_controller.hasListener) {
        _subscription = _socket.listen(_onData_controller.addError, _controller.close);
    } else {
        close();
    }
}

void RawSecureServerSocket::_owner(owner ) {
    (()._owner = owner;
}
