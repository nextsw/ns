#include "secure_socket.hpp"
Future<SecureSocket> SecureSocket::connect(host , SecurityContext context, FunctionType keyLog, FunctionType onBadCertificate, int port, List<String> supportedProtocols, Duration timeout) {
    return RawSecureSocket.connect(host, portcontext, onBadCertificate, keyLog, supportedProtocols, timeout).then();
}

Future<ConnectionTask<SecureSocket>> SecureSocket::startConnect(host , SecurityContext context, FunctionType keyLog, FunctionType onBadCertificate, int port, List<String> supportedProtocols) {
    return RawSecureSocket.startConnect(host, portcontext, onBadCertificate, keyLog, supportedProtocols).then();
}

Future<SecureSocket> SecureSocket::secure(host , SecurityContext context, FunctionType keyLog, FunctionType onBadCertificate, Socket socket, List<String> supportedProtocols) {
    return (().<RawSecureSocket>then().<SecureSocket>then();
}

Future<SecureSocket> SecureSocket::secureServer(List<int> bufferedData, SecurityContext context, bool requestClientCertificate, bool requireClientCertificate, Socket socket, List<String> supportedProtocols) {
    return (().<RawSecureSocket>then().<SecureSocket>then();
}

Future<RawSecureSocket> RawSecureSocket::connect(host , SecurityContext context, FunctionType keyLog, FunctionType onBadCertificate, int port, List<String> supportedProtocols, Duration timeout) {
    _RawSecureSocket._verifyFields(host, port, false, false);
    return RawSocket.connect(host, porttimeout).then();
}

Future<ConnectionTask<RawSecureSocket>> RawSecureSocket::startConnect(host , SecurityContext context, FunctionType keyLog, FunctionType onBadCertificate, int port, List<String> supportedProtocols) {
    return RawSocket.startConnect(host, port).then();
}

Future<RawSecureSocket> RawSecureSocket::secure(host , SecurityContext context, FunctionType keyLog, FunctionType onBadCertificate, RawSocket socket, StreamSubscription<RawSocketEvent> subscription, List<String> supportedProtocols) {
    socket.readEventsEnabled = false;
    socket.writeEventsEnabled = false;
    return _RawSecureSocket.connect(host != nullptr? host : socket.address.host, socket.port, false, socketsubscription, context, onBadCertificate, keyLog, supportedProtocols);
}

Future<RawSecureSocket> RawSecureSocket::secureServer(List<int> bufferedData, SecurityContext context, bool requestClientCertificate, bool requireClientCertificate, RawSocket socket, StreamSubscription<RawSocketEvent> subscription, List<String> supportedProtocols) {
    socket.readEventsEnabled = false;
    socket.writeEventsEnabled = false;
    return _RawSecureSocket.connect(socket.address, socket.remotePort, true, socketcontext, subscription, bufferedData, requestClientCertificate, requireClientCertificate, supportedProtocols);
}

Future<_RawSecureSocket> _RawSecureSocket::connect(List<int> bufferedData, SecurityContext context, dynamic host, bool isServer, FunctionType keyLog, FunctionType onBadCertificate, bool requestClientCertificate, int requestedPort, bool requireClientCertificate, RawSocket socket, StreamSubscription<RawSocketEvent> subscription, List<String> supportedProtocols) {
    _verifyFields(host, requestedPort, requestClientCertificate, requireClientCertificate);
    if (host is InternetAddress)     {
        host = host.host;
    }
    InternetAddress address = socket.address;
    if (host != nullptr) {
        address = InternetAddress._cloneWithNewHost(address, host);
    }
    return _RawSecureSocket(address, requestedPort, isServer, context ?? SecurityContext.defaultContext, socket, subscription, bufferedData, requestClientCertificate, requireClientCertificate, onBadCertificate, keyLog, supportedProtocols)._handshakeComplete.future;
}

StreamSubscription<RawSocketEvent> _RawSecureSocket::listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError) {
    _sendWriteEvent();
    return _controller.stream.listen(onDataonError, onDone, cancelOnError);
}

int _RawSecureSocket::port() {
    return _socket.port;
}

InternetAddress _RawSecureSocket::remoteAddress() {
    return _socket.remoteAddress;
}

int _RawSecureSocket::remotePort() {
    return _socket.remotePort;
}

int _RawSecureSocket::available() {
    return _status != connectedStatus? 0 : _secureFilter!.buffers![readPlaintextId].length;
}

Future<RawSecureSocket> _RawSecureSocket::close() {
    shutdown(SocketDirection.both);
    return _closeCompleter.future;
}

void _RawSecureSocket::shutdown(SocketDirection direction) {
    if (direction == SocketDirection.send || direction == SocketDirection.both) {
        _closedWrite = true;
        if (_filterStatus.writeEmpty) {
            _socket.shutdown(SocketDirection.send);
            _socketClosedWrite = true;
            if (_closedRead) {
                _close();
            }
        }
    }
    if (direction == SocketDirection.receive || direction == SocketDirection.both) {
        _closedRead = true;
        _socketClosedRead = true;
        _socket.shutdown(SocketDirection.receive);
        if (_socketClosedWrite) {
            _close();
        }
    }
}

bool _RawSecureSocket::writeEventsEnabled() {
    return _writeEventsEnabled;
}

void _RawSecureSocket::writeEventsEnabled(bool value) {
    _writeEventsEnabled = value;
    if (value) {
        Timer.run();
    }
}

bool _RawSecureSocket::readEventsEnabled() {
    return _readEventsEnabled;
}

void _RawSecureSocket::readEventsEnabled(bool value) {
    _readEventsEnabled = value;
    _scheduleReadEvent();
}

Uint8List _RawSecureSocket::read(int length) {
    if (length != nullptr &&  < 0) {
        ;
    }
    if (_closedRead) {
        ;
    }
    if (_status != connectedStatus) {
        return nullptr;
    }
    auto result = _secureFilter!.buffers![readPlaintextId].read(length);
    _scheduleFilter();
    return result;
}

SocketMessage _RawSecureSocket::readMessage(int count) {
    ;
}

int _RawSecureSocket::write(int bytes, List<int> data, int offset) {
    if (bytes != nullptr &&  < 0) {
        ;
    }
    offset = _fixOffset(offset);
    if ( < 0) {
        ;
    }
    if (_closedWrite) {
        _controller.addError(SocketException("Writing to a closed socket"));
        return 0;
    }
    if (_status != connectedStatus)     {
        return 0;
    }
    bytes = data.length - offset;
    int written = _secureFilter!.buffers![writePlaintextId].write(data, offset, bytes);
    if (written > 0) {
        _filterStatus.writeEmpty = false;
    }
    _scheduleFilter();
    return written;
}

int _RawSecureSocket::sendMessage(List<SocketControlMessage> controlMessages, int count, List<int> data, int offset) {
    ;
}

X509Certificate _RawSecureSocket::peerCertificate() {
    return _secureFilter!.peerCertificate;
}

String _RawSecureSocket::selectedProtocol() {
    return _selectedProtocol;
}

bool _RawSecureSocket::setOption(bool enabled, SocketOption option) {
    return _socket.setOption(option, enabled);
}

Uint8List _RawSecureSocket::getRawOption(RawSocketOption option) {
    return _socket.getRawOption(option);
}

void _RawSecureSocket::setRawOption(RawSocketOption option) {
    _socket.setRawOption(option);
}

void _RawSecureSocket::renegotiate(bool requestClientCertificate, bool requireClientCertificate, bool useSessionCache) {
    if (_status != connectedStatus) {
        ;
    }
    _status = handshakeStatus;
    _filterStatus.writeEmpty = false;
    _scheduleFilter();
}

bool _RawSecureSocket::_isBufferEncrypted(int identifier) {
    return identifier >= readEncryptedId;
}

_RawSecureSocket::_RawSecureSocket(List<int> _bufferedData, RawSocket _socket, InternetAddress address, SecurityContext context, bool isServer, FunctionType keyLog, FunctionType onBadCertificate, bool requestClientCertificate, int requestedPort, bool requireClientCertificate, StreamSubscription<RawSocketEvent> subscription, List<String> supportedProtocols) {
    {
        ;
        Unknown secureFilter = _secureFilter!;
        secureFilter.init();
        secureFilter.registerHandshakeCompleteCallback(_secureHandshakeCompleteHandler);
        if (keyLog != nullptr) {
            Unknown port = ReceivePort();
            port.listen();
            secureFilter.registerKeyLogPort(port.sendPort);
            keyLogPort = port;
        }
        if (onBadCertificate != nullptr) {
            secureFilter.registerBadCertificateCallback(_onBadCertificateWrapper);
        }
        _socket.readEventsEnabled = true;
        _socket.writeEventsEnabled = false;
        if (subscription == nullptr) {
            _socketSubscription = _socket.listen(_eventDispatcher_reportError, _doneHandler);
        } else {
            _socketSubscription = subscription;
            if (_socketSubscription.isPaused) {
                _socket.close();
                ;
            }
            dynamic s = _socket;
            if (s._socket.closedReadEventSent) {
                _eventDispatcher(RawSocketEvent.readClosed);
            }
            ;
        }
        ;
    }
}

void _RawSecureSocket::_verifyFields(host , bool requestClientCertificate, int requestedPort, bool requireClientCertificate) {
    if (host is! String && host is! InternetAddress) {
        ;
    }
    ArgumentError.checkNotNull(requestedPort, "requestedPort");
    if ( < 0 || requestedPort > 65535) {
        ;
    }
    ArgumentError.checkNotNull(requestClientCertificate, "requestClientCertificate");
    ArgumentError.checkNotNull(requireClientCertificate, "requireClientCertificate");
}

void _RawSecureSocket::_owner(owner ) {
    (()._owner = owner;
}

void _RawSecureSocket::_completeCloseCompleter(RawSocket dummy) {
    if (!_closeCompleter.isCompleted)     {
        _closeCompleter.complete(this);
    }
}

void _RawSecureSocket::_close() {
    _closedWrite = true;
    _closedRead = true;
    _socket.close().then(_completeCloseCompleter);
    _socketClosedWrite = true;
    _socketClosedRead = true;
    if (!_filterActive && _secureFilter != nullptr) {
        _secureFilter!.destroy();
        _secureFilter = nullptr;
    }
    keyLogPort?.close();
    if (_socketSubscription != nullptr) {
        _socketSubscription.cancel();
    }
    _controller.close();
    _status = closedStatus;
}

int _RawSecureSocket::_fixOffset(int offset) {
    return offset ?? 0;
}

bool _RawSecureSocket::_onBadCertificateWrapper(X509Certificate certificate) {
    if (onBadCertificate == nullptr)     {
        return false;
    }
    return onBadCertificate!(certificate);
}

void _RawSecureSocket::_eventDispatcher(RawSocketEvent event) {
    ;
}

void _RawSecureSocket::_readHandler() {
    _readSocket();
    _scheduleFilter();
}

void _RawSecureSocket::_writeHandler() {
    _writeSocket();
    _scheduleFilter();
}

void _RawSecureSocket::_doneHandler() {
    if (_filterStatus.readEmpty) {
        _close();
    }
}

void _RawSecureSocket::_reportError(e , StackTrace stackTrace) {
    if (_status == closedStatus) {
        return;
    } else     {
        if (_connectPending) {
        _handshakeComplete.completeError(e, stackTrace);
    } else {
        _controller.addError(e, stackTrace);
    }
;
    }    _close();
}

void _RawSecureSocket::_closeHandler() {
    if (_status == connectedStatus) {
        if (_closedRead)         {
            return;
        }
        _socketClosedRead = true;
        if (_filterStatus.readEmpty) {
            _closedRead = true;
            _controller.add(RawSocketEvent.readClosed);
            if (_socketClosedWrite) {
                _close();
            }
        } else {
            await await _scheduleFilter();
        }
    } else     {
        if (_status == handshakeStatus) {
        _socketClosedRead = true;
        if (_filterStatus.readEmpty) {
            _reportError(HandshakeException("Connection terminated during handshake"), nullptr);
        } else {
            await await _secureHandshake();
        }
    }
;
    }}

Future<void> _RawSecureSocket::_secureHandshake() {
    ;
}

void _RawSecureSocket::_secureHandshakeCompleteHandler() {
    _status = connectedStatus;
    if (_connectPending) {
        _connectPending = false;
        ;
    }
}

void _RawSecureSocket::_onPauseStateChange() {
    if (_controller.isPaused) {
        _pauseCount++;
    } else {
        _pauseCount--;
        if (_pauseCount == 0) {
            _scheduleReadEvent();
            _sendWriteEvent();
        }
    }
    if (!_socketClosedRead || !_socketClosedWrite) {
        if (_controller.isPaused) {
            _socketSubscription.pause();
        } else {
            _socketSubscription.resume();
        }
    }
}

void _RawSecureSocket::_onSubscriptionStateChange() {
    if (_controller.hasListener) {
    }
}

Future<void> _RawSecureSocket::_scheduleFilter() {
    _filterPending = true;
    return _tryFilter();
}

Future<void> _RawSecureSocket::_tryFilter() {
    ;
}

List<int> _RawSecureSocket::_readSocketOrBufferedData(int bytes) {
    Unknown bufferedData = _bufferedData;
    if (bufferedData != nullptr) {
        if (bytes > bufferedData.length - _bufferedDataIndex) {
            bytes = bufferedData.length - _bufferedDataIndex;
        }
        auto result = bufferedData.sublist(_bufferedDataIndex, _bufferedDataIndex + bytes);
        _bufferedDataIndex = bytes;
        if (bufferedData.length == _bufferedDataIndex) {
            _bufferedData = nullptr;
        }
        return result;
    } else     {
        if (!_socketClosedRead) {
        return _socket.read(bytes);
    } else {
        return nullptr;
    }
;
    }}

void _RawSecureSocket::_readSocket() {
    if (_status == closedStatus)     {
        return;
    }
    auto buffer = _secureFilter!.buffers![readEncryptedId];
    if (buffer.writeFromSource(_readSocketOrBufferedData) > 0) {
        _filterStatus.readEmpty = false;
    } else {
        _socket.readEventsEnabled = false;
    }
}

void _RawSecureSocket::_writeSocket() {
    if (_socketClosedWrite)     {
        return;
    }
    auto buffer = _secureFilter!.buffers![writeEncryptedId];
    if (buffer.readToSocket(_socket)) {
        _socket.writeEventsEnabled = true;
    }
}

void _RawSecureSocket::_scheduleReadEvent() {
    if (!_pendingReadEvent && _readEventsEnabled && _pauseCount == 0 && _secureFilter != nullptr && !_secureFilter!.buffers![readPlaintextId].isEmpty) {
        _pendingReadEvent = true;
        Timer.run(_sendReadEvent);
    }
}

void _RawSecureSocket::_sendReadEvent() {
    _pendingReadEvent = false;
    if (_status != closedStatus && _readEventsEnabled && _pauseCount == 0 && _secureFilter != nullptr && !_secureFilter!.buffers![readPlaintextId].isEmpty) {
        _controller.add(RawSocketEvent.read);
        _scheduleReadEvent();
    }
}

void _RawSecureSocket::_sendWriteEvent() {
    if (!_closedWrite && _writeEventsEnabled && _pauseCount == 0 && _secureFilter != nullptr && _secureFilter!.buffers![writePlaintextId].free > 0) {
        _writeEventsEnabled = false;
        _controller.add(RawSocketEvent.write);
    }
}

Future<_FilterStatus> _RawSecureSocket::_pushAllFilterStages() {
    bool wasInHandshake = _status != connectedStatus;
    List args = <dynamic>filled(2 + bufferCount * 2, nullptr);
    args[0] = _secureFilter!._pointer();
    args[1] = wasInHandshake;
    auto bufs = _secureFilter!.buffers!;
    for (;  < bufferCount; ++i) {
        args[2 * i + 2] = bufs[i].start;
        args[2 * i + 3] = bufs[i].end;
    }
    auto response = await _IOService._dispatch(_IOService.sslProcessFilter, args);
    if (response.length == 2) {
        if (wasInHandshake) {
            _reportError(HandshakeException("${response[1]} error ${response[0]}"), nullptr);
        } else {
            _reportError(TlsException("${response[1]} error ${response[0]}"), nullptr);
        }
    }
    ;
    ;
    _FilterStatus status = _FilterStatus();
    status.writeEmpty = bufs[writePlaintextId].isEmpty && start(writeEncryptedId) == end(writeEncryptedId);
    if (wasInHandshake)     {
        status.writeEmpty = false;
    }
    status.readEmpty = bufs[readEncryptedId].isEmpty && start(readPlaintextId) == end(readPlaintextId);
    _ExternalBuffer buffer = bufs[writePlaintextId];
    int new_start = start(writePlaintextId);
    if (new_start != buffer.start) {
        status.progress = true;
        if (buffer.free == 0) {
            status.writePlaintextNoLongerFull = true;
        }
        buffer.start = new_start;
    }
    buffer = bufs[readEncryptedId];
    new_start = start(readEncryptedId);
    if (new_start != buffer.start) {
        status.progress = true;
        if (buffer.free == 0) {
            status.readEncryptedNoLongerFull = true;
        }
        buffer.start = new_start;
    }
    buffer = bufs[writeEncryptedId];
    int new_end = end(writeEncryptedId);
    if (new_end != buffer.end) {
        status.progress = true;
        if (buffer.length == 0) {
            status.writeEncryptedNoLongerEmpty = true;
        }
        buffer.end = new_end;
    }
    buffer = bufs[readPlaintextId];
    new_end = end(readPlaintextId);
    if (new_end != buffer.end) {
        status.progress = true;
        if (buffer.length == 0) {
            status.readPlaintextNoLongerEmpty = true;
        }
        buffer.end = new_end;
    }
    return status;
}

void _ExternalBuffer::advanceStart(int bytes) {
    assert(start > end || start + bytes <= end);
    start = bytes;
    if (start >= size) {
        start = size;
        assert(start <= end);
        assert( < size);
    }
}

void _ExternalBuffer::advanceEnd(int bytes) {
    assert(start <= end || start > end + bytes);
    end = bytes;
    if (end >= size) {
        end = size;
        assert( < start);
        assert( < size);
    }
}

bool _ExternalBuffer::isEmpty() {
    return end == start;
}

int _ExternalBuffer::length() {
    return start > end? size + end - start : end - start;
}

int _ExternalBuffer::linearLength() {
    return start > end? size - start : end - start;
}

int _ExternalBuffer::free() {
    return start > end? start - end - 1 : size + start - end - 1;
}

int _ExternalBuffer::linearFree() {
    if (start > end)     {
        return start - end - 1;
    }
    if (start == 0)     {
        return size - end - 1;
    }
    return size - end;
}

Uint8List _ExternalBuffer::read(int bytes) {
    if (bytes == nullptr) {
        bytes = length;
    } else {
        bytes = min(bytes, length);
    }
    if (bytes == 0)     {
        return nullptr;
    }
    Uint8List result = Uint8List(bytes);
    int bytesRead = 0;
    while ( < bytes) {
        int toRead = min(bytes - bytesRead, linearLength);
        result.setRange(bytesRead, bytesRead + toRead, data!, start);
        advanceStart(toRead);
        bytesRead = toRead;
    }
    return result;
}

int _ExternalBuffer::write(int bytes, List<int> inputData, int offset) {
    if (bytes > free) {
        bytes = free;
    }
    int written = 0;
    int toWrite = min(bytes, linearFree);
    while (toWrite > 0) {
        data!.setRange(end, end + toWrite, inputData, offset);
        advanceEnd(toWrite);
        offset = toWrite;
        written = toWrite;
        toWrite = min(bytes - written, linearFree);
    }
    return written;
}

int _ExternalBuffer::writeFromSource(FunctionType getData) {
    int written = 0;
    int toWrite = linearFree;
    while (toWrite > 0) {
        auto inputData = getData(toWrite);
        if (inputData == nullptr || inputData.length == 0)         {
                    break;
        }
        auto len = inputData.length;
        data!.setRange(end, end + len, inputData);
        advanceEnd(len);
        written = len;
        toWrite = linearFree;
    }
    return written;
}

bool _ExternalBuffer::readToSocket(RawSocket socket) {
    while (true) {
        auto toWrite = linearLength;
        if (toWrite == 0)         {
            return false;
        }
        int bytes = socket.write(data!, start, toWrite);
        advanceStart(bytes);
        if ( < toWrite) {
            return true;
        }
    }
}

_ExternalBuffer::_ExternalBuffer(int size) {
    {
        size = size;
        start = size ~/ 2;
        end = size ~/ 2;
    }
}

TlsException::TlsException(String message, OSError osError) {
    {
        this._("TlsException", message, osError);
    }
}

String TlsException::toString() {
    StringBuffer sb = StringBuffer();
    sb.write(type);
    if (message.isNotEmpty) {
        sb.write(": $message");
        if (osError != nullptr) {
            sb.write(" ($osError)");
        }
    } else     {
        if (osError != nullptr) {
        sb.write(": $osError");
    }
;
    }    return sb.toString();
}

HandshakeException::HandshakeException(String message, OSError osError) {
    {
        super._("HandshakeException", message, osError);
    }
}

CertificateException::CertificateException(String message, OSError osError) {
    {
        super._("CertificateException", message, osError);
    }
}
