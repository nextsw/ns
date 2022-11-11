#include "secure_socket.hpp"
Future<SecureSocket> SecureSocketCls::connect(host , SecurityContext context, void keyLog(String line) , bool onBadCertificate(X509Certificate certificate) , int port, List<String> supportedProtocols, Duration timeout) {
    return RawSecureSocketCls->connect(host, portcontext, onBadCertificate, keyLog, supportedProtocols, timeout)->then([=] (Unknown  rawSocket)     {
        SecureSocketCls->_(rawSocket);
    });
}

Future<ConnectionTask<SecureSocket>> SecureSocketCls::startConnect(host , SecurityContext context, void keyLog(String line) , bool onBadCertificate(X509Certificate certificate) , int port, List<String> supportedProtocols) {
    return RawSecureSocketCls->startConnect(host, portcontext, onBadCertificate, keyLog, supportedProtocols)->then([=] (Unknown  rawState) {
        Future<SecureSocket> socket = rawState->socket->then([=] (Unknown  rawSocket) {
    SecureSocketCls->_(rawSocket);
});
        return <SecureSocket>_(socket, rawState->_onCancel);
    });
}

Future<SecureSocket> SecureSocketCls::secure(host , SecurityContext context, void keyLog(String line) , bool onBadCertificate(X509Certificate certificate) , Socket socket, List<String> supportedProtocols) {
    return (as<Future>((as<dynamic>(socket))->_detachRaw()))-><RawSecureSocket>then([=] (Unknown  detachedRaw) {
        return RawSecureSocketCls->secure(as<RawSocket>(detachedRaw[0])as<StreamSubscription<RawSocketEvent>>(detachedRaw[1]), host, context, onBadCertificate, keyLog, supportedProtocols);
    })-><SecureSocket>then([=] (Unknown  raw)     {
        SecureSocketCls->_(raw);
    });
}

Future<SecureSocket> SecureSocketCls::secureServer(List<int> bufferedData, SecurityContext context, bool requestClientCertificate, bool requireClientCertificate, Socket socket, List<String> supportedProtocols) {
    return (as<Future>((as<dynamic>(socket))->_detachRaw()))-><RawSecureSocket>then([=] (Unknown  detachedRaw) {
        return RawSecureSocketCls->secureServer(as<RawSocket>(detachedRaw[0]), contextas<StreamSubscription<RawSocketEvent>>(detachedRaw[1]), bufferedData, requestClientCertificate, requireClientCertificate, supportedProtocols);
    })-><SecureSocket>then([=] (Unknown  raw)     {
        SecureSocketCls->_(raw);
    });
}

Future<RawSecureSocket> RawSecureSocketCls::connect(host , SecurityContext context, void keyLog(String line) , bool onBadCertificate(X509Certificate certificate) , int port, List<String> supportedProtocols, Duration timeout) {
    _RawSecureSocketCls->_verifyFields(host, port, false, false);
    return RawSocketCls->connect(host, porttimeout)->then([=] (Unknown  socket) {
        return secure(socketcontext, onBadCertificate, keyLog, supportedProtocols);
    });
}

Future<ConnectionTask<RawSecureSocket>> RawSecureSocketCls::startConnect(host , SecurityContext context, void keyLog(String line) , bool onBadCertificate(X509Certificate certificate) , int port, List<String> supportedProtocols) {
    return RawSocketCls->startConnect(host, port)->then([=] (ConnectionTask<RawSocket> rawState) {
        Future<RawSecureSocket> socket = rawState->socket->then([=] (Unknown  rawSocket) {
    return secure(rawSocketcontext, onBadCertificate, keyLog, supportedProtocols);
});
        return <RawSecureSocket>_(socket, rawState->_onCancel);
    });
}

Future<RawSecureSocket> RawSecureSocketCls::secure(host , SecurityContext context, void keyLog(String line) , bool onBadCertificate(X509Certificate certificate) , RawSocket socket, StreamSubscription<RawSocketEvent> subscription, List<String> supportedProtocols) {
    socket->readEventsEnabled = false;
    socket->writeEventsEnabled = false;
    return _RawSecureSocketCls->connect(host != nullptr? host : socket->address()->host(), socket->port(), false, socketsubscription, context, onBadCertificate, keyLog, supportedProtocols);
}

Future<RawSecureSocket> RawSecureSocketCls::secureServer(List<int> bufferedData, SecurityContext context, bool requestClientCertificate, bool requireClientCertificate, RawSocket socket, StreamSubscription<RawSocketEvent> subscription, List<String> supportedProtocols) {
    socket->readEventsEnabled = false;
    socket->writeEventsEnabled = false;
    return _RawSecureSocketCls->connect(socket->address(), socket->remotePort(), true, socketcontext, subscription, bufferedData, requestClientCertificate, requireClientCertificate, supportedProtocols);
}

Future<_RawSecureSocket> _RawSecureSocketCls::connect(List<int> bufferedData, SecurityContext context, dynamic host, bool isServer, void keyLog(String line) , bool onBadCertificate(X509Certificate certificate) , bool requestClientCertificate, int requestedPort, bool requireClientCertificate, RawSocket socket, StreamSubscription<RawSocketEvent> subscription, List<String> supportedProtocols) {
    _verifyFields(host, requestedPort, requestClientCertificate, requireClientCertificate);
    if (is<InternetAddress>(host))     {
        as<InternetAddressCls>(host) = as<InternetAddressCls>(host)->as<InternetAddressCls>(host);
    }
    InternetAddress address = socket->address();
    if (host != nullptr) {
        address = InternetAddressCls->_cloneWithNewHost(address, host);
    }
    return make<_RawSecureSocketCls>(address, requestedPort, isServer, context or SecurityContextCls::defaultContext, socket, subscription, bufferedData, requestClientCertificate, requireClientCertificate, onBadCertificate, keyLog, supportedProtocols)->_handshakeComplete->future;
}

StreamSubscription<RawSocketEvent> _RawSecureSocketCls::listen(bool cancelOnError, void onData(RawSocketEvent data) , void onDone() , void  onError() ) {
    _sendWriteEvent();
    return _controller->stream->listen(onDataonError, onDone, cancelOnError);
}

int _RawSecureSocketCls::port() {
    return _socket->port();
}

InternetAddress _RawSecureSocketCls::remoteAddress() {
    return _socket->remoteAddress();
}

int _RawSecureSocketCls::remotePort() {
    return _socket->remotePort();
}

int _RawSecureSocketCls::available() {
    return _status != connectedStatus? 0 : _secureFilter!->buffers()![readPlaintextId]->length();
}

Future<RawSecureSocket> _RawSecureSocketCls::close() {
    shutdown(SocketDirectionCls::both);
    return _closeCompleter->future;
}

void _RawSecureSocketCls::shutdown(SocketDirection direction) {
    if (direction == SocketDirectionCls::send || direction == SocketDirectionCls::both) {
        _closedWrite = true;
        if (_filterStatus->writeEmpty) {
            _socket->shutdown(SocketDirectionCls::send);
            _socketClosedWrite = true;
            if (_closedRead) {
                _close();
            }
        }
    }
    if (direction == SocketDirectionCls::receive || direction == SocketDirectionCls::both) {
        _closedRead = true;
        _socketClosedRead = true;
        _socket->shutdown(SocketDirectionCls::receive);
        if (_socketClosedWrite) {
            _close();
        }
    }
}

bool _RawSecureSocketCls::writeEventsEnabled() {
    return _writeEventsEnabled;
}

void _RawSecureSocketCls::writeEventsEnabled(bool value) {
    _writeEventsEnabled = value;
    if (value) {
        TimerCls->run([=] ()         {
            _sendWriteEvent();
        });
    }
}

bool _RawSecureSocketCls::readEventsEnabled() {
    return _readEventsEnabled;
}

void _RawSecureSocketCls::readEventsEnabled(bool value) {
    _readEventsEnabled = value;
    _scheduleReadEvent();
}

Uint8List _RawSecureSocketCls::read(int length) {
    if (length != nullptr &&  < 0) {
        ;
    }
    if (_closedRead) {
        ;
    }
    if (_status != connectedStatus) {
        return nullptr;
    }
    auto result = _secureFilter!->buffers()![readPlaintextId]->read(length);
    _scheduleFilter();
    return result;
}

SocketMessage _RawSecureSocketCls::readMessage(int count) {
    ;
}

int _RawSecureSocketCls::write(int bytes, List<int> data, int offset) {
    if (bytes != nullptr &&  < 0) {
        ;
    }
    offset = _fixOffset(offset);
    if ( < 0) {
        ;
    }
    if (_closedWrite) {
        _controller->addError(make<SocketExceptionCls>(__s("Writing to a closed socket")));
        return 0;
    }
    if (_status != connectedStatus)     {
        return 0;
    }
    bytes = data->length() - offset;
    int written = _secureFilter!->buffers()![writePlaintextId]->write(data, offset, bytes);
    if (written > 0) {
        _filterStatus->writeEmpty = false;
    }
    _scheduleFilter();
    return written;
}

int _RawSecureSocketCls::sendMessage(List<SocketControlMessage> controlMessages, int count, List<int> data, int offset) {
    ;
}

X509Certificate _RawSecureSocketCls::peerCertificate() {
    return _secureFilter!->peerCertificate();
}

String _RawSecureSocketCls::selectedProtocol() {
    return _selectedProtocol;
}

bool _RawSecureSocketCls::setOption(bool enabled, SocketOption option) {
    return _socket->setOption(option, enabled);
}

Uint8List _RawSecureSocketCls::getRawOption(RawSocketOption option) {
    return _socket->getRawOption(option);
}

void _RawSecureSocketCls::setRawOption(RawSocketOption option) {
    _socket->setRawOption(option);
}

void _RawSecureSocketCls::renegotiate(bool requestClientCertificate, bool requireClientCertificate, bool useSessionCache) {
    if (_status != connectedStatus) {
        ;
    }
    _status = handshakeStatus;
    _filterStatus->writeEmpty = false;
    _scheduleFilter();
}

bool _RawSecureSocketCls::_isBufferEncrypted(int identifier) {
    return identifier >= readEncryptedId;
}

_RawSecureSocketCls::_RawSecureSocketCls(List<int> _bufferedData, RawSocket _socket, InternetAddress address, SecurityContext context, bool isServer, void Function(String line) keyLog, bool Function(X509Certificate certificate) onBadCertificate, bool requestClientCertificate, int requestedPort, bool requireClientCertificate, StreamSubscription<RawSocketEvent> subscription, List<String> supportedProtocols) {
    {
            auto _c1 = _controller;    _c1.onListen = auto _c2 = _onSubscriptionStateChange;    _c2.onPause = auto _c3 = _onPauseStateChange;    _c3.onResume = auto _c4 = _onPauseStateChange;    _c4.onCancel = _onSubscriptionStateChange;    _c4;    _c3;    _c2;_c1;
        Unknown secureFilter = _secureFilter!;
        secureFilter->init();
        secureFilter->registerHandshakeCompleteCallback(_secureHandshakeCompleteHandler);
        if (keyLog != nullptr) {
            Unknown port = make<ReceivePortCls>();
            port->listen([=] (Unknown  line) {
                try {
                    keyLog!((as<String>(line)) + __s("\n"));
                } catch (Unknown e) {
                    stderr->writeln(__s("Failure in keyLog callback:"));
                    stderr->writeln(s);
                };
            });
            secureFilter->registerKeyLogPort(port->sendPort);
            keyLogPort = port;
        }
        if (onBadCertificate != nullptr) {
            secureFilter->registerBadCertificateCallback(_onBadCertificateWrapper);
        }
        _socket->readEventsEnabled = true;
        _socket->writeEventsEnabled = false;
        if (subscription == nullptr) {
            _socketSubscription = _socket->listen(_eventDispatcher_reportError, _doneHandler);
        } else {
            _socketSubscription = subscription;
            if (_socketSubscription->isPaused) {
                _socket->close();
                ;
            }
            dynamic s = _socket;
            if (s->_socket->closedReadEventSent) {
                _eventDispatcher(RawSocketEventCls::readClosed);
            }
                    auto _c5 = _socketSubscription;        _c5.auto _c6 = onData(_eventDispatcher);        _c6.auto _c7 = onError(_reportError);        _c7.onDone(_doneHandler);        _c7;        _c6;_c5;
        }
        try {
            auto encodedProtocols = SecurityContextCls->_protocolsToLengthEncoding(supportedProtocols);
            secureFilter->connect(address->host(), context, isServer, requestClientCertificate || requireClientCertificate, requireClientCertificate, encodedProtocols);
            _secureHandshake();
        } catch (Unknown e) {
            _reportError(e, s);
        };
    }
}

void _RawSecureSocketCls::_verifyFields(host , bool requestClientCertificate, int requestedPort, bool requireClientCertificate) {
    if (!is<String>(host) && !is<InternetAddress>(host)) {
        ;
    }
    ArgumentErrorCls->checkNotNull(requestedPort, __s("requestedPort"));
    if ( < 0 || requestedPort > 65535) {
        ;
    }
    ArgumentErrorCls->checkNotNull(requestClientCertificate, __s("requestClientCertificate"));
    ArgumentErrorCls->checkNotNull(requireClientCertificate, __s("requireClientCertificate"));
}

void _RawSecureSocketCls::_owner(owner ) {
    (as<dynamic>(_socket))->_owner = owner;
}

void _RawSecureSocketCls::_completeCloseCompleter(RawSocket dummy) {
    if (!_closeCompleter->isCompleted)     {
        _closeCompleter->complete(this);
    }
}

void _RawSecureSocketCls::_close() {
    _closedWrite = true;
    _closedRead = true;
    _socket->close()->then(_completeCloseCompleter);
    _socketClosedWrite = true;
    _socketClosedRead = true;
    if (!_filterActive && _secureFilter != nullptr) {
        _secureFilter!->destroy();
        _secureFilter = nullptr;
    }
    keyLogPort?->close();
    if (_socketSubscription != nullptr) {
        _socketSubscription->cancel();
    }
    _controller->close();
    _status = closedStatus;
}

int _RawSecureSocketCls::_fixOffset(int offset) {
    return offset or 0;
}

bool _RawSecureSocketCls::_onBadCertificateWrapper(X509Certificate certificate) {
    if (onBadCertificate == nullptr)     {
        return false;
    }
    return onBadCertificate!(certificate);
}

void _RawSecureSocketCls::_eventDispatcher(RawSocketEvent event) {
    try {
        if (event == RawSocketEventCls::read) {
            _readHandler();
        } else         {
            if (event == RawSocketEventCls::write) {
            _writeHandler();
        } else         {
            if (event == RawSocketEventCls::readClosed) {
            _closeHandler();
        }
;
        };
        }    } catch (Unknown e) {
        _reportError(e, stackTrace);
    };
}

void _RawSecureSocketCls::_readHandler() {
    _readSocket();
    _scheduleFilter();
}

void _RawSecureSocketCls::_writeHandler() {
    _writeSocket();
    _scheduleFilter();
}

void _RawSecureSocketCls::_doneHandler() {
    if (_filterStatus->readEmpty) {
        _close();
    }
}

void _RawSecureSocketCls::_reportError(e , StackTrace stackTrace) {
    if (_status == closedStatus) {
        return;
    } else     {
        if (_connectPending) {
        _handshakeComplete->completeError(e, stackTrace);
    } else {
        _controller->addError(e, stackTrace);
    }
;
    }    _close();
}

void _RawSecureSocketCls::_closeHandler() {
    if (_status == connectedStatus) {
        if (_closedRead)         {
            return;
        }
        _socketClosedRead = true;
        if (_filterStatus->readEmpty) {
            _closedRead = true;
            _controller->add(RawSocketEventCls::readClosed);
            if (_socketClosedWrite) {
                _close();
            }
        } else {
            await await _scheduleFilter();
        }
    } else     {
        if (_status == handshakeStatus) {
        _socketClosedRead = true;
        if (_filterStatus->readEmpty) {
            _reportError(make<HandshakeExceptionCls>(__s("Connection terminated during handshake")), nullptr);
        } else {
            await await _secureHandshake();
        }
    }
;
    }}

Future<void> _RawSecureSocketCls::_secureHandshake() {
    try {
        bool needRetryHandshake = await _secureFilter!->handshake();
        if (needRetryHandshake) {
            await await _secureHandshake();
        } else {
            _filterStatus->writeEmpty = false;
            _readSocket();
            _writeSocket();
            await await _scheduleFilter();
        }
    } catch (Unknown e) {
        _reportError(e, stackTrace);
    };
}

void _RawSecureSocketCls::_secureHandshakeCompleteHandler() {
    _status = connectedStatus;
    if (_connectPending) {
        _connectPending = false;
        try {
            _selectedProtocol = _secureFilter!->selectedProtocol();
            TimerCls->run([=] ()             {
                _handshakeComplete->complete(this);
            });
        } catch (Unknown error) {
            _handshakeComplete->completeError(error, stack);
        };
    }
}

void _RawSecureSocketCls::_onPauseStateChange() {
    if (_controller->isPaused) {
        _pauseCount++;
    } else {
        _pauseCount--;
        if (_pauseCount == 0) {
            _scheduleReadEvent();
            _sendWriteEvent();
        }
    }
    if (!_socketClosedRead || !_socketClosedWrite) {
        if (_controller->isPaused) {
            _socketSubscription->pause();
        } else {
            _socketSubscription->resume();
        }
    }
}

void _RawSecureSocketCls::_onSubscriptionStateChange() {
    if (_controller->hasListener) {
    }
}

Future<void> _RawSecureSocketCls::_scheduleFilter() {
    _filterPending = true;
    return _tryFilter();
}

Future<void> _RawSecureSocketCls::_tryFilter() {
    try {
        while (true) {
            if (_status == closedStatus) {
                return;
            }
            if (!_filterPending || _filterActive) {
                return;
            }
            _filterActive = true;
            _filterPending = false;
            _filterStatus = await _pushAllFilterStages();
            _filterActive = false;
            if (_status == closedStatus) {
                _secureFilter!->destroy();
                _secureFilter = nullptr;
                return;
            }
            _socket->readEventsEnabled = true;
            if (_filterStatus->writeEmpty && _closedWrite && !_socketClosedWrite) {
                shutdown(SocketDirectionCls::send);
                if (_status == closedStatus) {
                    return;
                }
            }
            if (_filterStatus->readEmpty && _socketClosedRead && !_closedRead) {
                if (_status == handshakeStatus) {
                    _secureFilter!->handshake();
                    if (_status == handshakeStatus) {
                        ;
                    }
                }
                _closeHandler();
            }
            if (_status == closedStatus) {
                return;
            }
            if (_filterStatus->progress) {
                _filterPending = true;
                if (_filterStatus->writeEncryptedNoLongerEmpty) {
                    _writeSocket();
                }
                if (_filterStatus->writePlaintextNoLongerFull) {
                    _sendWriteEvent();
                }
                if (_filterStatus->readEncryptedNoLongerFull) {
                    _readSocket();
                }
                if (_filterStatus->readPlaintextNoLongerEmpty) {
                    _scheduleReadEvent();
                }
                if (_status == handshakeStatus) {
                    await await _secureHandshake();
                }
            }
        }
    } catch (Unknown e) {
        _reportError(e, st);
    };
}

List<int> _RawSecureSocketCls::_readSocketOrBufferedData(int bytes) {
    Unknown bufferedData = _bufferedData;
    if (bufferedData != nullptr) {
        if (bytes > bufferedData->length() - _bufferedDataIndex) {
            bytes = bufferedData->length() - _bufferedDataIndex;
        }
        auto result = bufferedData->sublist(_bufferedDataIndex, _bufferedDataIndex + bytes);
        _bufferedDataIndex = bytes;
        if (bufferedData->length() == _bufferedDataIndex) {
            _bufferedData = nullptr;
        }
        return result;
    } else     {
        if (!_socketClosedRead) {
        return _socket->read(bytes);
    } else {
        return nullptr;
    }
;
    }}

void _RawSecureSocketCls::_readSocket() {
    if (_status == closedStatus)     {
        return;
    }
    auto buffer = _secureFilter!->buffers()![readEncryptedId];
    if (buffer->writeFromSource(_readSocketOrBufferedData) > 0) {
        _filterStatus->readEmpty = false;
    } else {
        _socket->readEventsEnabled = false;
    }
}

void _RawSecureSocketCls::_writeSocket() {
    if (_socketClosedWrite)     {
        return;
    }
    auto buffer = _secureFilter!->buffers()![writeEncryptedId];
    if (buffer->readToSocket(_socket)) {
        _socket->writeEventsEnabled = true;
    }
}

void _RawSecureSocketCls::_scheduleReadEvent() {
    if (!_pendingReadEvent && _readEventsEnabled && _pauseCount == 0 && _secureFilter != nullptr && !_secureFilter!->buffers()![readPlaintextId]->isEmpty()) {
        _pendingReadEvent = true;
        TimerCls->run(_sendReadEvent);
    }
}

void _RawSecureSocketCls::_sendReadEvent() {
    _pendingReadEvent = false;
    if (_status != closedStatus && _readEventsEnabled && _pauseCount == 0 && _secureFilter != nullptr && !_secureFilter!->buffers()![readPlaintextId]->isEmpty()) {
        _controller->add(RawSocketEventCls::read);
        _scheduleReadEvent();
    }
}

void _RawSecureSocketCls::_sendWriteEvent() {
    if (!_closedWrite && _writeEventsEnabled && _pauseCount == 0 && _secureFilter != nullptr && _secureFilter!->buffers()![writePlaintextId]->free() > 0) {
        _writeEventsEnabled = false;
        _controller->add(RawSocketEventCls::write);
    }
}

Future<_FilterStatus> _RawSecureSocketCls::_pushAllFilterStages() {
    bool wasInHandshake = _status != connectedStatus;
    List args = <dynamic>filled(2 + bufferCount * 2, nullptr);
    args[0] = _secureFilter!->_pointer();
    args[1] = wasInHandshake;
    auto bufs = _secureFilter!->buffers()!;
    for (;  < bufferCount; ++i) {
        args[2 * i + 2] = bufs[i]->start;
        args[2 * i + 3] = bufs[i]->end;
    }
    auto response = await _IOServiceCls->_dispatch(_IOServiceCls::sslProcessFilter, args);
    if (response->length == 2) {
        if (wasInHandshake) {
            _reportError(make<HandshakeExceptionCls>(__s("${response[1]} error ${response[0]}")), nullptr);
        } else {
            _reportError(make<TlsExceptionCls>(__s("${response[1]} error ${response[0]}")), nullptr);
        }
    }
    InlineMethod;
    InlineMethod;
    _FilterStatus status = make<_FilterStatusCls>();
    status->writeEmpty = bufs[writePlaintextId]->isEmpty() && start(writeEncryptedId) == end(writeEncryptedId);
    if (wasInHandshake)     {
        status->writeEmpty = false;
    }
    status->readEmpty = bufs[readEncryptedId]->isEmpty() && start(readPlaintextId) == end(readPlaintextId);
    _ExternalBuffer buffer = bufs[writePlaintextId];
    int new_start = start(writePlaintextId);
    if (new_start != buffer->start) {
        status->progress = true;
        if (buffer->free() == 0) {
            status->writePlaintextNoLongerFull = true;
        }
        buffer->start = new_start;
    }
    buffer = bufs[readEncryptedId];
    new_start = start(readEncryptedId);
    if (new_start != buffer->start) {
        status->progress = true;
        if (buffer->free() == 0) {
            status->readEncryptedNoLongerFull = true;
        }
        buffer->start = new_start;
    }
    buffer = bufs[writeEncryptedId];
    int new_end = end(writeEncryptedId);
    if (new_end != buffer->end) {
        status->progress = true;
        if (buffer->length() == 0) {
            status->writeEncryptedNoLongerEmpty = true;
        }
        buffer->end = new_end;
    }
    buffer = bufs[readPlaintextId];
    new_end = end(readPlaintextId);
    if (new_end != buffer->end) {
        status->progress = true;
        if (buffer->length() == 0) {
            status->readPlaintextNoLongerEmpty = true;
        }
        buffer->end = new_end;
    }
    return status;
}

void _ExternalBufferCls::advanceStart(int bytes) {
    assert(start > end || start + bytes <= end);
    start = bytes;
    if (start >= size) {
        start = size;
        assert(start <= end);
        assert( < size);
    }
}

void _ExternalBufferCls::advanceEnd(int bytes) {
    assert(start <= end || start > end + bytes);
    end = bytes;
    if (end >= size) {
        end = size;
        assert( < start);
        assert( < size);
    }
}

bool _ExternalBufferCls::isEmpty() {
    return end == start;
}

int _ExternalBufferCls::length() {
    return start > end? size + end - start : end - start;
}

int _ExternalBufferCls::linearLength() {
    return start > end? size - start : end - start;
}

int _ExternalBufferCls::free() {
    return start > end? start - end - 1 : size + start - end - 1;
}

int _ExternalBufferCls::linearFree() {
    if (start > end)     {
        return start - end - 1;
    }
    if (start == 0)     {
        return size - end - 1;
    }
    return size - end;
}

Uint8List _ExternalBufferCls::read(int bytes) {
    if (bytes == nullptr) {
        bytes = length();
    } else {
        bytes = min(bytes, length());
    }
    if (bytes == 0)     {
        return nullptr;
    }
    Uint8List result = make<Uint8ListCls>(bytes);
    int bytesRead = 0;
    while ( < bytes) {
        int toRead = min(bytes - bytesRead, linearLength());
        result->setRange(bytesRead, bytesRead + toRead, data!, start);
        advanceStart(toRead);
        bytesRead = toRead;
    }
    return result;
}

int _ExternalBufferCls::write(int bytes, List<int> inputData, int offset) {
    if (bytes > free()) {
        bytes = free();
    }
    int written = 0;
    int toWrite = min(bytes, linearFree());
    while (toWrite > 0) {
        data!->setRange(end, end + toWrite, inputData, offset);
        advanceEnd(toWrite);
        offset = toWrite;
        written = toWrite;
        toWrite = min(bytes - written, linearFree());
    }
    return written;
}

int _ExternalBufferCls::writeFromSource(List<int> getData(int requested) ) {
    int written = 0;
    int toWrite = linearFree();
    while (toWrite > 0) {
        auto inputData = getData(toWrite);
        if (inputData == nullptr || inputData->length == 0)         {
                    break;
        }
        auto len = inputData->length;
        data!->setRange(end, end + len, inputData);
        advanceEnd(len);
        written = len;
        toWrite = linearFree();
    }
    return written;
}

bool _ExternalBufferCls::readToSocket(RawSocket socket) {
    while (true) {
        auto toWrite = linearLength();
        if (toWrite == 0)         {
            return false;
        }
        int bytes = socket->write(data!, start, toWrite);
        advanceStart(bytes);
        if ( < toWrite) {
            return true;
        }
    }
}

_ExternalBufferCls::_ExternalBufferCls(int size) {
    {
        size = size;
        start = size ~/ 2;
        end = size ~/ 2;
    }
}

TlsExceptionCls::TlsExceptionCls(String message, OSError osError) {
    {
        this->_(__s("TlsException"), message, osError);
    }
}

String TlsExceptionCls::toString() {
    StringBuffer sb = make<StringBufferCls>();
    sb->write(type);
    if (message->isNotEmpty()) {
        sb->write(__s(": $message"));
        if (osError != nullptr) {
            sb->write(__s(" ($osError)"));
        }
    } else     {
        if (osError != nullptr) {
        sb->write(__s(": $osError"));
    }
;
    }    return sb->toString();
}

HandshakeExceptionCls::HandshakeExceptionCls(String message, OSError osError) {
    {
        super->_(__s("HandshakeException"), message, osError);
    }
}

CertificateExceptionCls::CertificateExceptionCls(String message, OSError osError) {
    {
        super->_(__s("CertificateException"), message, osError);
    }
}
