#include "socket.hpp"
String InternetAddressTypeCls::name() {
    return makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem)[_value + 1];
}

String InternetAddressTypeCls::toString() {
    return __sf("InternetAddressType: %s", name());
}

void InternetAddressTypeCls::_from(int value) {
    if (value == IPv4Cls::_value) {
        return IPv4Cls;
    }
    if (value == IPv6Cls::_value) {
        return IPv6Cls;
    }
    if (value == unix->_value) {
        return unix;
    }
    throw make<ArgumentErrorCls>(__sf("Invalid type: %s", value));
}

Future<ServerSocket> ServerSocketCls::bind(address , int port, int backlog, bool shared, bool v6Only) {
    IOOverrides overrides = IOOverridesCls::current;
    if (overrides == nullptr) {
        return ServerSocketCls->_bind(address, port, backlog, v6Only, shared);
    }
    return overrides->serverSocketBind(address, port, backlog, v6Only, shared);
}

void RawSocketOptionCls::fromInt(int level, int option, int value) {
    Uint8List list = make<Uint8ListCls>(4);
    auto buffer = ByteDataCls->view(list->buffer, list->offsetInBytes);
    buffer->setInt32(0, value, EndianCls::host);
    return make<RawSocketOptionCls>(level, option, list);
}

void RawSocketOptionCls::fromBool(int level, int option, bool value) {
    return RawSocketOptionCls->fromInt(level, option, value? 1 : 0);
}

int RawSocketOptionCls::levelSocket() {
    return _getOptionValue(_RawSocketOptionsCls::SOL_SOCKET::index);
}

int RawSocketOptionCls::levelIPv4() {
    return _getOptionValue(_RawSocketOptionsCls::IPPROTO_IP::index);
}

int RawSocketOptionCls::IPv4MulticastInterface() {
    return _getOptionValue(_RawSocketOptionsCls::IP_MULTICAST_IF::index);
}

int RawSocketOptionCls::levelIPv6() {
    return _getOptionValue(_RawSocketOptionsCls::IPPROTO_IPV6::index);
}

int RawSocketOptionCls::IPv6MulticastInterface() {
    return _getOptionValue(_RawSocketOptionsCls::IPV6_MULTICAST_IF::index);
}

int RawSocketOptionCls::levelTcp() {
    return _getOptionValue(_RawSocketOptionsCls::IPPROTO_TCP::index);
}

int RawSocketOptionCls::levelUdp() {
    return _getOptionValue(_RawSocketOptionsCls::IPPROTO_UDP::index);
}

String RawSocketEventCls::toString() {
    return makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem)[_value];
}

template<typename S>
void ConnectionTaskCls<S>::cancel() {
    _onCancel();
}

template<typename S>
void ConnectionTaskCls<S>::_(Future<S> socket, std::function<void()> onCancel)

Future<Socket> SocketCls::connect(host , int port, sourceAddress , int sourcePort, Duration timeout) {
    IOOverrides overrides = IOOverridesCls::current;
    if (overrides == nullptr) {
        return SocketCls->_connect(host, port, sourceAddress, sourcePort, timeout);
    }
    return overrides->socketConnect(host, port, sourceAddress, sourcePort, timeout);
}

Future<ConnectionTask<Socket>> SocketCls::startConnect(host , int port, sourceAddress , int sourcePort) {
    IOOverrides overrides = IOOverridesCls::current;
    if (overrides == nullptr) {
        return SocketCls->_startConnect(host, port, sourceAddress, sourcePort);
    }
    return overrides->socketStartConnect(host, port, sourceAddress, sourcePort);
}

void SocketExceptionCls::closed()

String SocketExceptionCls::toString() {
    StringBuffer sb = make<StringBufferCls>();
    sb->write(__s("SocketException"));
    if (message->isNotEmpty()) {
        sb->write(__sf(": %s", message));
        if (osError != nullptr) {
            sb->write(__sf(" (%s)", osError));
        }
    } else {
        if (osError != nullptr) {
        sb->write(__sf(": %s", osError));
    }
;
    }    if (address != nullptr) {
        sb->write(__sf(", address = %s", address!->host()));
    }
    if (port != nullptr) {
        sb->write(__sf(", port = %s", port));
    }
    return sb->toString();
}
