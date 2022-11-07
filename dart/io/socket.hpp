#ifndef SOCKET_H
#define SOCKET_H
#include <memory>




class InternetAddressType {
public:
    static const InternetAddressType IPv4;

    static const InternetAddressType IPv6;

    static const InternetAddressType unix;

    static const InternetAddressType any;


    String name();

    String toString();

private:
    int _value;


    void  _(int _value);

    void  _from(int value);

};

class InternetAddress {
public:

    external static InternetAddress loopbackIPv4();

    external static InternetAddress loopbackIPv6();

    external static InternetAddress anyIPv4();

    external static InternetAddress anyIPv6();

    InternetAddressType type();

    String address();

    String host();

    Uint8List rawAddress();

    bool isLoopback();

    bool isLinkLocal();

    bool isMulticast();

    external  InternetAddress(String address, InternetAddressType type);

    external void  fromRawAddress(Uint8List rawAddress, InternetAddressType type);

    Future<InternetAddress> reverse();

    external static Future<List<InternetAddress>> lookup(String host, InternetAddressType type);

    external static InternetAddress tryParse(String address);

private:

    external static InternetAddress _cloneWithNewHost(InternetAddress address, String host);

};

class NetworkInterface {
public:

    String name();

    int index();

    List<InternetAddress> addresses();

    external static bool listSupported();

    external static Future<List<NetworkInterface>> list(bool includeLinkLocal, bool includeLoopback, InternetAddressType type);

private:

};

class RawServerSocket {
public:

    external static Future<RawServerSocket> bind(address , int backlog, int port, bool shared, bool v6Only);

    int port();

    InternetAddress address();

    Future<RawServerSocket> close();

private:

};

class ServerSocket {
public:

    static Future<ServerSocket> bind(address , int backlog, int port, bool shared, bool v6Only);

    int port();

    InternetAddress address();

    Future<ServerSocket> close();

private:

    external static Future<ServerSocket> _bind(address , int backlog, int port, bool shared, bool v6Only);

};

class SocketDirection {
public:
    static const SocketDirection receive;

    static const SocketDirection send;

    static const SocketDirection both;


private:
    auto  _value;


    void  _(Unknown _value);

};

class SocketOption {
public:
    static const SocketOption tcpNoDelay;


private:
    static const SocketOption _ipMulticastLoop;

    static const SocketOption _ipMulticastHops;

    static const SocketOption _ipMulticastIf;

    static const SocketOption _ipBroadcast;

    auto  _value;


    void  _(Unknown _value);

};

enum _RawSocketOptions{
    SOL_SOCKET,
    IPPROTO_IP,
    IP_MULTICAST_IF,
    IPPROTO_IPV6,
    IPV6_MULTICAST_IF,
    IPPROTO_TCP,
    IPPROTO_UDP,
} // end _RawSocketOptions

class RawSocketOption {
public:
    int level;

    int option;

    Uint8List value;


     RawSocketOption(int level, int option, Uint8List value);

    void  fromInt(int level, int option, int value);

    void  fromBool(int level, int option, bool value);

    static int levelSocket();

    static int levelIPv4();

    static int IPv4MulticastInterface();

    static int levelIPv6();

    static int IPv6MulticastInterface();

    static int levelTcp();

    static int levelUdp();

private:

    external static int _getOptionValue(int key);

};

class RawSocketEvent {
public:
    static const RawSocketEvent read;

    static const RawSocketEvent write;

    static const RawSocketEvent readClosed;

    static const RawSocketEvent closed;


    String toString();

private:
    int _value;


    void  _(int _value);

};

class ConnectionTask<S> {
public:
    Future<S> socket;


    void cancel();

private:
    FunctionType _onCancel;


    void  _(FunctionType onCancel, Future<S> socket);

};

class RawSocket {
public:
    bool readEventsEnabled;

    bool writeEventsEnabled;


    external static Future<RawSocket> connect(host , sourceAddress , int port, int sourcePort, Duration timeout);

    external static Future<ConnectionTask<RawSocket>> startConnect(host , sourceAddress , int port, int sourcePort);

    int available();

    Uint8List read(int len);

    SocketMessage readMessage(int count);

    int write(List<int> buffer, int count, int offset);

    int sendMessage(List<SocketControlMessage> controlMessages, int count, List<int> data, int offset);

    int port();

    int remotePort();

    InternetAddress address();

    InternetAddress remoteAddress();

    Future<RawSocket> close();

    void shutdown(SocketDirection direction);

    bool setOption(bool enabled, SocketOption option);

    Uint8List getRawOption(RawSocketOption option);

    void setRawOption(RawSocketOption option);

private:

};

class Socket {
public:

    static Future<Socket> connect(host , sourceAddress , int port, int sourcePort, Duration timeout);

    static Future<ConnectionTask<Socket>> startConnect(host , sourceAddress , int port, int sourcePort);

    void destroy();

    bool setOption(bool enabled, SocketOption option);

    Uint8List getRawOption(RawSocketOption option);

    void setRawOption(RawSocketOption option);

    int port();

    int remotePort();

    InternetAddress address();

    InternetAddress remoteAddress();

    Future close();

    Future done();

private:

    external static Future<Socket> _connect(host , sourceAddress , int port, int sourcePort, Duration timeout);

    external static Future<ConnectionTask<Socket>> _startConnect(host , sourceAddress , int port, int sourcePort);

};

class Datagram {
public:
    Uint8List data;

    InternetAddress address;

    int port;


     Datagram(InternetAddress address, Uint8List data, int port);

private:

};

class ResourceHandle {
public:

    external void  fromFile(RandomAccessFile file);

    external void  fromSocket(Socket socket);

    external void  fromRawSocket(RawSocket socket);

    external void  fromRawDatagramSocket(RawDatagramSocket socket);

    external void  fromStdin(Stdin stdin);

    external void  fromStdout(Stdout stdout);

    RandomAccessFile toFile();

    Socket toSocket();

    RawSocket toRawSocket();

    RawDatagramSocket toRawDatagramSocket();

private:

};

class SocketControlMessage {
public:

    external void  fromHandles(List<ResourceHandle> handles);

    List<ResourceHandle> extractHandles();

    int level();

    int type();

    Uint8List data();

private:

};

class SocketMessage {
public:
    Uint8List data;

    List<SocketControlMessage> controlMessages;


     SocketMessage(List<SocketControlMessage> controlMessages, Uint8List data);

private:

};

class RawDatagramSocket : Stream<RawSocketEvent> {
public:
    bool readEventsEnabled;

    bool writeEventsEnabled;

    bool multicastLoopback;

    int multicastHops;

    NetworkInterface multicastInterface;

    bool broadcastEnabled;


    external static Future<RawDatagramSocket> bind(host , int port, bool reuseAddress, bool reusePort, int ttl);

    int port();

    InternetAddress address();

    void close();

    int send(InternetAddress address, List<int> buffer, int port);

    Datagram receive();

    void joinMulticast(InternetAddress group, NetworkInterface interface);

    void leaveMulticast(InternetAddress group, NetworkInterface interface);

    Uint8List getRawOption(RawSocketOption option);

    void setRawOption(RawSocketOption option);

private:

};

class SocketException {
public:
    String message;

    OSError osError;

    InternetAddress address;

    int port;


     SocketException(InternetAddress address, String message, OSError osError, int port);

    void  closed();

    String toString();

private:

};

#endif