#ifndef DART_IO_SOCKET
#define DART_IO_SOCKET
#include <base.hpp>

#include <dart/core/core.hpp>


class InternetAddressTypeCls : public ObjectCls {
public:
    static InternetAddressType IPv4;

    static InternetAddressType IPv6;

    static InternetAddressType unix;

    static InternetAddressType any;


    virtual String name();

    virtual String toString();

private:
    int _value;


    virtual void  _(int _value);
    virtual void  _from(int value);

};
using InternetAddressType = std::shared_ptr<InternetAddressTypeCls>;

class InternetAddressCls : public ObjectCls {
public:

    static InternetAddress loopbackIPv4();
    static InternetAddress loopbackIPv6();
    static InternetAddress anyIPv4();
    static InternetAddress anyIPv6();
    virtual InternetAddressType type();
    virtual String address();
    virtual String host();
    virtual Uint8List rawAddress();
    virtual bool isLoopback();
    virtual bool isLinkLocal();
    virtual bool isMulticast();
     InternetAddressCls(String address, InternetAddressType type);
    void  fromRawAddress(Uint8List rawAddress, InternetAddressType type);
    virtual Future<InternetAddress> reverse();
    static Future<List<InternetAddress>> lookup(String host, InternetAddressType type);
    static InternetAddress tryParse(String address);
private:

    static InternetAddress _cloneWithNewHost(InternetAddress address, String host);
};
using InternetAddress = std::shared_ptr<InternetAddressCls>;

class NetworkInterfaceCls : public ObjectCls {
public:

    virtual String name();
    virtual int index();
    virtual List<InternetAddress> addresses();
    static bool listSupported();
    static Future<List<NetworkInterface>> list(bool includeLinkLocal, bool includeLoopback, InternetAddressType type);
private:

};
using NetworkInterface = std::shared_ptr<NetworkInterfaceCls>;

class RawServerSocketCls : public ObjectCls {
public:

    static Future<RawServerSocket> bind(address , int port, int backlog, bool shared, bool v6Only);
    virtual int port();
    virtual InternetAddress address();
    virtual Future<RawServerSocket> close();
private:

};
using RawServerSocket = std::shared_ptr<RawServerSocketCls>;

class ServerSocketCls : public ObjectCls {
public:

    static Future<ServerSocket> bind(address , int port, int backlog, bool shared, bool v6Only);

    virtual int port();
    virtual InternetAddress address();
    virtual Future<ServerSocket> close();
private:

    static Future<ServerSocket> _bind(address , int port, int backlog, bool shared, bool v6Only);
};
using ServerSocket = std::shared_ptr<ServerSocketCls>;

class SocketDirectionCls : public ObjectCls {
public:
    static SocketDirection receive;

    static SocketDirection send;

    static SocketDirection both;


private:
    auto  _value;


    virtual void  _(Unknown _value);
};
using SocketDirection = std::shared_ptr<SocketDirectionCls>;

class SocketOptionCls : public ObjectCls {
public:
    static SocketOption tcpNoDelay;


private:
    static SocketOption _ipMulticastLoop;

    static SocketOption _ipMulticastHops;

    static SocketOption _ipMulticastIf;

    static SocketOption _ipBroadcast;

    auto  _value;


    virtual void  _(Unknown _value);
};
using SocketOption = std::shared_ptr<SocketOptionCls>;

enum _RawSocketOptions{
    SOL_SOCKET,
    IPPROTO_IP,
    IP_MULTICAST_IF,
    IPPROTO_IPV6,
    IPV6_MULTICAST_IF,
    IPPROTO_TCP,
    IPPROTO_UDP,
} // end _RawSocketOptions

class RawSocketOptionCls : public ObjectCls {
public:
    int level;

    int option;

    Uint8List value;


     RawSocketOptionCls(int level, int option, Uint8List value);
    virtual void  fromInt(int level, int option, int value);

    virtual void  fromBool(int level, int option, bool value);

    static int levelSocket();

    static int levelIPv4();

    static int IPv4MulticastInterface();

    static int levelIPv6();

    static int IPv6MulticastInterface();

    static int levelTcp();

    static int levelUdp();

private:

    static int _getOptionValue(int key);
};
using RawSocketOption = std::shared_ptr<RawSocketOptionCls>;

class RawSocketEventCls : public ObjectCls {
public:
    static RawSocketEvent read;

    static RawSocketEvent write;

    static RawSocketEvent readClosed;

    static RawSocketEvent closed;


    virtual String toString();

private:
    int _value;


    virtual void  _(int _value);
};
using RawSocketEvent = std::shared_ptr<RawSocketEventCls>;

template<typename S>
class ConnectionTaskCls : public ObjectCls {
public:
    Future<S> socket;


    virtual void cancel();

private:
    std::function<void()> _onCancel;


    virtual void  _(Future<S> socket, std::function<void()> onCancel);

};
template<typename S>
using ConnectionTask = std::shared_ptr<ConnectionTaskCls<S>>;

class RawSocketCls : public ObjectCls {
public:
    bool readEventsEnabled;

    bool writeEventsEnabled;


    static Future<RawSocket> connect(host , int port, sourceAddress , int sourcePort, Duration timeout);
    static Future<ConnectionTask<RawSocket>> startConnect(host , int port, sourceAddress , int sourcePort);
    virtual int available();
    virtual Uint8List read(int len);
    virtual SocketMessage readMessage(int count);
    virtual int write(List<int> buffer, int offset, int count);
    virtual int sendMessage(List<SocketControlMessage> controlMessages, List<int> data, int offset, int count);
    virtual int port();
    virtual int remotePort();
    virtual InternetAddress address();
    virtual InternetAddress remoteAddress();
    virtual Future<RawSocket> close();
    virtual void shutdown(SocketDirection direction);
    virtual bool setOption(SocketOption option, bool enabled);
    virtual Uint8List getRawOption(RawSocketOption option);
    virtual void setRawOption(RawSocketOption option);
private:

};
using RawSocket = std::shared_ptr<RawSocketCls>;

class SocketCls : public ObjectCls {
public:

    static Future<Socket> connect(host , int port, sourceAddress , int sourcePort, Duration timeout);

    static Future<ConnectionTask<Socket>> startConnect(host , int port, sourceAddress , int sourcePort);

    virtual void destroy();
    virtual bool setOption(SocketOption option, bool enabled);
    virtual Uint8List getRawOption(RawSocketOption option);
    virtual void setRawOption(RawSocketOption option);
    virtual int port();
    virtual int remotePort();
    virtual InternetAddress address();
    virtual InternetAddress remoteAddress();
    virtual Future close();
    virtual Future done();
private:

    static Future<Socket> _connect(host , int port, sourceAddress , int sourcePort, Duration timeout);
    static Future<ConnectionTask<Socket>> _startConnect(host , int port, sourceAddress , int sourcePort);
};
using Socket = std::shared_ptr<SocketCls>;

class DatagramCls : public ObjectCls {
public:
    Uint8List data;

    InternetAddress address;

    int port;


     DatagramCls(Uint8List data, InternetAddress address, int port);
private:

};
using Datagram = std::shared_ptr<DatagramCls>;

class ResourceHandleCls : public ObjectCls {
public:

    void  fromFile(RandomAccessFile file);
    void  fromSocket(Socket socket);
    void  fromRawSocket(RawSocket socket);
    void  fromRawDatagramSocket(RawDatagramSocket socket);
    void  fromStdin(Stdin stdin);
    void  fromStdout(Stdout stdout);
    virtual RandomAccessFile toFile();
    virtual Socket toSocket();
    virtual RawSocket toRawSocket();
    virtual RawDatagramSocket toRawDatagramSocket();
private:

};
using ResourceHandle = std::shared_ptr<ResourceHandleCls>;

class SocketControlMessageCls : public ObjectCls {
public:

    void  fromHandles(List<ResourceHandle> handles);
    virtual List<ResourceHandle> extractHandles();
    virtual int level();
    virtual int type();
    virtual Uint8List data();
private:

};
using SocketControlMessage = std::shared_ptr<SocketControlMessageCls>;

class SocketMessageCls : public ObjectCls {
public:
    Uint8List data;

    List<SocketControlMessage> controlMessages;


     SocketMessageCls(Uint8List data, List<SocketControlMessage> controlMessages);
private:

};
using SocketMessage = std::shared_ptr<SocketMessageCls>;

class RawDatagramSocketCls : public StreamCls<RawSocketEvent> {
public:
    bool readEventsEnabled;

    bool writeEventsEnabled;

    bool multicastLoopback;

    int multicastHops;

    NetworkInterface multicastInterface;

    bool broadcastEnabled;


    static Future<RawDatagramSocket> bind(host , int port, bool reuseAddress, bool reusePort, int ttl);
    virtual int port();
    virtual InternetAddress address();
    virtual void close();
    virtual int send(List<int> buffer, InternetAddress address, int port);
    virtual Datagram receive();
    virtual void joinMulticast(InternetAddress group, NetworkInterface interface);
    virtual void leaveMulticast(InternetAddress group, NetworkInterface interface);
    virtual Uint8List getRawOption(RawSocketOption option);
    virtual void setRawOption(RawSocketOption option);
private:

};
using RawDatagramSocket = std::shared_ptr<RawDatagramSocketCls>;

class SocketExceptionCls : public ObjectCls {
public:
    String message;

    OSError osError;

    InternetAddress address;

    int port;


     SocketExceptionCls(String message, InternetAddress address, OSError osError, int port);
    virtual void  closed();

    virtual String toString();

private:

};
using SocketException = std::shared_ptr<SocketExceptionCls>;


#endif