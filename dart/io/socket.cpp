#include "socket.hpp"
String InternetAddressTypeCls::name() {
    return makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem)[_value + 1];
}

String InternetAddressTypeCls::toString() {
    return __s("InternetAddressType: $name");
}

void InternetAddressTypeCls::_from(int value) {
    if (value == IPv4Cls::_value)     {
        return IPv4Cls;
    }
    if (value == IPv6Cls::_value)     {
        return IPv6Cls;
    }
    if (value == unix->_value)     {
        return unix;
    }
    ;
}

Future<ServerSocket> ServerSocketCls::bind(address , int backlog, int port, bool shared, bool v6Only) {
    IOOverrides overrides = IOOverridesCls::current;
    if (overrides == nullptr) {
        return ServerSocketCls->_bind(address, portbacklog, v6Only, shared);
    }
    return overrides->serverSocketBind(address, portbacklog, v6Only, shared);
}

void RawSocketOptionCls::fromInt(int level, int option, int value) {
    Uint8List list = make<Uint8ListCls>(4);
    Unknown buffer = ByteDataCls->view(list->buffer, list->offsetInBytes);
    buffer->setInt32(0, value, EndianCls::host);
    return make<RawSocketOptionCls>(level, option, list);
}

void RawSocketOptionCls::fromBool(int level, int option, bool value) {
    return RawSocketOptionCls->fromInt(level, option, value? 1 : 0);
}

int RawSocketOptionCls::levelSocket() {
    return _getOptionValue(_RawSocketOptionsCls::SOL_SOCKETCls::index);
}

int RawSocketOptionCls::levelIPv4() {
    return _getOptionValue(_RawSocketOptionsCls::IPPROTO_IPCls::index);
}

int RawSocketOptionCls::IPv4MulticastInterface() {
    return _getOptionValue(_RawSocketOptionsCls::IP_MULTICAST_IFCls::index);
}

int RawSocketOptionCls::levelIPv6() {
    return _getOptionValue(_RawSocketOptionsCls::IPPROTO_IPV6Cls::index);
}

int RawSocketOptionCls::IPv6MulticastInterface() {
    return _getOptionValue(_RawSocketOptionsCls::IPV6_MULTICAST_IFCls::index);
}

int RawSocketOptionCls::levelTcp() {
    return _getOptionValue(_RawSocketOptionsCls::IPPROTO_TCPCls::index);
}

int RawSocketOptionCls::levelUdp() {
    return _getOptionValue(_RawSocketOptionsCls::IPPROTO_UDPCls::index);
}

String RawSocketEventCls::toString() {
    return makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem)[_value];
}

template<typename S>
void ConnectionTaskCls<S>::cancel() {
    _onCancel();
}

template<typename S>
void ConnectionTaskCls<S>::_(void onCancel() , Future<S> socket)

Future<Socket> SocketCls::connect(host , sourceAddress , int port, int sourcePort, Duration timeout) {
    IOOverrides overrides = IOOverridesCls::current;
    if (overrides == nullptr) {
        return SocketCls->_connect(host, portsourceAddress, sourcePort, timeout);
    }
    return overrides->socketConnect(host, portsourceAddress, sourcePort, timeout);
}

Future<ConnectionTask<Socket>> SocketCls::startConnect(host , sourceAddress , int port, int sourcePort) {
    IOOverrides overrides = IOOverridesCls::current;
    if (overrides == nullptr) {
        return SocketCls->_startConnect(host, portsourceAddress, sourcePort);
    }
    return overrides->socketStartConnect(host, portsourceAddress, sourcePort);
}

void SocketExceptionCls::closed()

String SocketExceptionCls::toString() {
    StringBuffer sb = make<StringBufferCls>();
    sb->write(__s("SocketException"));
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
    }    if (address != nullptr) {
        sb->write(__s(", address = ${address!.host}"));
    }
    if (port != nullptr) {
        sb->write(__s(", port = $port"));
    }
    return sb->toString();
}
