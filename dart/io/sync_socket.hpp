#ifndef DART_IO_SYNC_SOCKET
#define DART_IO_SYNC_SOCKET
#include <base.hpp>

#include <dart/core/core.hpp>


class RawSynchronousSocketCls : public ObjectCls {
public:

    extern static RawSynchronousSocket connectSync(host , int port);
    virtual int available();
    virtual void closeSync();
    virtual int readIntoSync(List<int> buffer, int end, int start);
    virtual List<int> readSync(int bytes);
    virtual void shutdown(SocketDirection direction);
    virtual void writeFromSync(List<int> buffer, int end, int start);
    virtual int port();
    virtual int remotePort();
    virtual InternetAddress address();
    virtual InternetAddress remoteAddress();
private:

};
using RawSynchronousSocket = std::shared_ptr<RawSynchronousSocketCls>;


#endif