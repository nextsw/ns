#ifndef SYNC_SOCKET_H
#define SYNC_SOCKET_H
#include <memory>




class RawSynchronousSocket {
public:

    external static RawSynchronousSocket connectSync(host , int port);

    int available();

    void closeSync();

    int readIntoSync(List<int> buffer, int end, int start);

    List<int> readSync(int bytes);

    void shutdown(SocketDirection direction);

    void writeFromSync(List<int> buffer, int end, int start);

    int port();

    int remotePort();

    InternetAddress address();

    InternetAddress remoteAddress();

private:

};

#endif