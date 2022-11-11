#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION__ISOLATES_IO
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION__ISOLATES_IO
#include <base.hpp>
#include "isolates.hpp"

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/developer/developer.hpp>
#include <dart/isolate/isolate.hpp>
#include <packages/meta/meta.hpp>
#include "constants.hpp"
#include "isolates.hpp"

template<typename Q, typename R>
 Future<R> compute(ComputeCallback<Q, R> callback, String debugLabel, Q message);


template<typename Q, typename R>
class _IsolateConfigurationCls : public ObjectCls {
public:
    ComputeCallback<Q, R> callback;

    Q message;

    SendPort resultPort;

    String debugLabel;

    int flowId;


    virtual FutureOr<R> applyAndTime();

private:

     _IsolateConfigurationCls(ComputeCallback<Q, R> callback, String debugLabel, int flowId, Q message, SendPort resultPort);
};
template<typename Q, typename R>
using _IsolateConfiguration = std::shared_ptr<_IsolateConfigurationCls<Q, R>>;
template<typename Q, typename R>
 Future<void> _spawn(_IsolateConfiguration<Q, R> configuration);

template<typename R>
 List<R> _buildSuccessResponse(R result);

List<dynamic> _buildErrorResponse(Object error, StackTrace stack);



#endif