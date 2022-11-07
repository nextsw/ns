#include "socket.hpp"
String InternetAddressType::name() {
    return const [_value + 1];
}

String InternetAddressType::toString() {
    return "InternetAddressType: $name";
}

void InternetAddressType::_from(int value) {
    if (value == IPv4._value)     {
        return IPv4;
    }
    if (value == IPv6._value)     {
        return IPv6;
    }
    if (value == unix._value)     {
        return unix;
    }
    ;
}

Future<ServerSocket> ServerSocket::bind(address , int backlog, int port, bool shared, bool v6Only) {
    IOOverrides overrides = IOOverrides.current;
    if (overrides == nullptr) {
        return ServerSocket._bind(address, portbacklog, v6Only, shared);
    }
    return overrides.serverSocketBind(address, portbacklog, v6Only, shared);
}

void RawSocketOption::fromInt(int level, int option, int value) {
    Uint8List list = Uint8List(4);
    Unknown buffer = ByteData.view(list.buffer, list.offsetInBytes);
    buffer.setInt32(0, value, Endian.host);
    return RawSocketOption(level, option, list);
}

void RawSocketOption::fromBool(int level, int option, bool value) {
    return RawSocketOption.fromInt(level, option, value? 1 : 0);
}

int RawSocketOption::levelSocket() {
    return _getOptionValue(_RawSocketOptions.SOL_SOCKET.index);
}

int RawSocketOption::levelIPv4() {
    return _getOptionValue(_RawSocketOptions.IPPROTO_IP.index);
}

int RawSocketOption::IPv4MulticastInterface() {
    return _getOptionValue(_RawSocketOptions.IP_MULTICAST_IF.index);
}

int RawSocketOption::levelIPv6() {
    return _getOptionValue(_RawSocketOptions.IPPROTO_IPV6.index);
}

int RawSocketOption::IPv6MulticastInterface() {
    return _getOptionValue(_RawSocketOptions.IPV6_MULTICAST_IF.index);
}

int RawSocketOption::levelTcp() {
    return _getOptionValue(_RawSocketOptions.IPPROTO_TCP.index);
}

int RawSocketOption::levelUdp() {
    return _getOptionValue(_RawSocketOptions.IPPROTO_UDP.index);
}

String RawSocketEvent::toString() {
    return const [_value];
}

void ConnectionTask::cancel() {
    _onCancel();
}

void ConnectionTask::_(FunctionType onCancel, Future<S> socket)

Future<Socket> Socket::connect(host , sourceAddress , int port, int sourcePort, Duration timeout) {
    IOOverrides overrides = IOOverrides.current;
    if (overrides == nullptr) {
        return Socket._connect(host, portsourceAddress, sourcePort, timeout);
    }
    return overrides.socketConnect(host, portsourceAddress, sourcePort, timeout);
}

Future<ConnectionTask<Socket>> Socket::startConnect(host , sourceAddress , int port, int sourcePort) {
    IOOverrides overrides = IOOverrides.current;
    if (overrides == nullptr) {
        return Socket._startConnect(host, portsourceAddress, sourcePort);
    }
    return overrides.socketStartConnect(host, portsourceAddress, sourcePort);
}

void SocketException::closed()

String SocketException::toString() {
    StringBuffer sb = StringBuffer();
    sb.write("SocketException");
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
    }    if (address != nullptr) {
        sb.write(", address = ${address!.host}");
    }
    if (port != nullptr) {
        sb.write(", port = $port");
    }
    return sb.toString();
}
