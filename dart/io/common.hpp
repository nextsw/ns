#ifndef DART_IO_COMMON
#define DART_IO_COMMON
#include <base.hpp>

#include <dart/core/core.hpp>

int _successResponse;

int _illegalArgumentResponse;

int _osErrorResponse;

int _fileClosedResponse;

int _errorResponseErrorType;

int _osErrorResponseErrorCode;

int _osErrorResponseMessage;

bool _isErrorResponse(response );

void  _exceptionFromResponse(response , String message, String path);


class IOExceptionCls : public ObjectCls {
public:

    virtual String toString();

private:

};
using IOException = std::shared_ptr<IOExceptionCls>;

class OSErrorCls : public ObjectCls {
public:
    static int noErrorCode;

    String message;

    int errorCode;


     OSErrorCls(int errorCode, String message);
    virtual String toString();

private:

};
using OSError = std::shared_ptr<OSErrorCls>;

class _BufferAndStartCls : public ObjectCls {
public:
    List<int> buffer;

    int start;


private:

     _BufferAndStartCls(List<int> buffer, int start);
};
using _BufferAndStart = std::shared_ptr<_BufferAndStartCls>;
_BufferAndStart _ensureFastAndSerializableByteData(List<int> buffer, int end, int start);

extern bool _isDirectIOCapableTypedList(List<int> buffer);

class _IOCryptoCls : public ObjectCls {
public:

    extern static Uint8List getRandomBytes(int count);
private:

};
using _IOCrypto = std::shared_ptr<_IOCryptoCls>;


#endif