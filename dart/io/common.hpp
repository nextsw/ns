#ifndef COMMON_H
#define COMMON_H
#include <memory>



const int _successResponse;

const int _illegalArgumentResponse;

const int _osErrorResponse;

const int _fileClosedResponse;

const int _errorResponseErrorType;

const int _osErrorResponseErrorCode;

const int _osErrorResponseMessage;

bool _isErrorResponse(response );

void  _exceptionFromResponse(response , String message, String path);


class IOException {
public:

    String toString();

private:

};

class OSError {
public:
    static const int noErrorCode;

    String message;

    int errorCode;


     OSError(int errorCode, String message);

    String toString();

private:

};

class _BufferAndStart {
public:
    List<int> buffer;

    int start;


private:

     _BufferAndStart(List<int> buffer, int start);

};
_BufferAndStart _ensureFastAndSerializableByteData(List<int> buffer, int end, int start);

external bool _isDirectIOCapableTypedList(List<int> buffer);


class _IOCrypto {
public:

    external static Uint8List getRandomBytes(int count);

private:

};

#endif