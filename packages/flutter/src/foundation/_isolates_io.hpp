#ifndef _ISOLATES_IO_H
#define _ISOLATES_IO_H
#include <memory>
#include "isolates.hpp"

#include <async/async.hpp>
#include <developer/developer.hpp>
#include <isolate/isolate.hpp>
#include <meta/meta.hpp>
#include "constants.hpp"
#include "isolates.hpp"


Future<R> compute<Q, R>(ComputeCallback<Q, R> callback, String debugLabel, Q message);


class _IsolateConfiguration<Q, R> {
public:
    ComputeCallback<Q, R> callback;

    Q message;

    SendPort resultPort;

    String debugLabel;

    int flowId;


    FutureOr<R> applyAndTime();

private:

     _IsolateConfiguration(ComputeCallback<Q, R> callback, String debugLabel, int flowId, Q message, SendPort resultPort);

};
Future<void> _spawn<Q, R>(_IsolateConfiguration<Q, R> configuration);

List<R> _buildSuccessResponse<R>(R result);

List<dynamic> _buildErrorResponse(Object error, StackTrace stack);


#endif