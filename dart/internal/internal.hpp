#ifndef DART_INTERNAL_INTERNAL
#define DART_INTERNAL_INTERNAL
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <dart/async/async.hpp>
#include <dart/convert/convert.hpp>
#include <dart/core/core.hpp>
#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <dart/typed_data/typed_data.hpp>

template<typename T>
 bool typeAcceptsNull();
template<typename T>
 T unsafeCast(Object value);
auto  POWERS_OF_TEN;


class CodeUnitsCls : public UnmodifiableListBaseCls<int> {
public:

     CodeUnitsCls(String _string);
    virtual int length();

    virtual int operator[](int i);

    static String stringOf(CodeUnits u);

private:
    String _string;


};
using CodeUnits = std::shared_ptr<CodeUnitsCls>;

class ExternalNameCls : public ObjectCls {
public:
    String name;


     ExternalNameCls(String name);
private:

};
using ExternalName = std::shared_ptr<ExternalNameCls>;
int hexDigitValue(int charValue);

int parseHexByte(String source, int index);

Future<Null> nullFuture;


class SystemHashCls : public ObjectCls {
public:

    static int combine(int hash, int value);

    static int finish(int hash);

    static int hash2(int v1, int v2, int seed);

    static int hash3(int v1, int v2, int v3, int seed);

    static int hash4(int v1, int v2, int v3, int v4, int seed);

    static int hash5(int v1, int v2, int v3, int v4, int v5, int seed);

    static int hash6(int v1, int v2, int v3, int v4, int v5, int v6, int seed);

    static int hash7(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int seed);

    static int hash8(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int seed);

    static int hash9(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int seed);

    static int hash10(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int seed);

    static int hash11(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int seed);

    static int hash12(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int v12, int seed);

    static int hash13(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int v12, int v13, int seed);

    static int hash14(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int v12, int v13, int v14, int seed);

    static int hash15(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int v12, int v13, int v14, int v15, int seed);

    static int hash16(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int seed);

    static int hash17(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int v17, int seed);

    static int hash18(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int v17, int v18, int seed);

    static int hash19(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int v17, int v18, int v19, int seed);

    static int hash20(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int v17, int v18, int v19, int v20, int seed);

    static int smear(int x);

private:

};
using SystemHash = std::shared_ptr<SystemHashCls>;

class SentinelValueCls : public ObjectCls {
public:
    int id;


     SentinelValueCls(int id);
private:

};
using SentinelValue = std::shared_ptr<SentinelValueCls>;
Object sentinelValue;

template<typename T>
 Object extractTypeArguments(T instance, std::function<void ()> extract);

class SinceCls : public ObjectCls {
public:
    String version;


     SinceCls(String version);
private:

};
using Since = std::shared_ptr<SinceCls>;
template<typename T>
 T checkNotNullable(T value, String name);


template<typename T>
class NotNullableErrorCls : public ErrorCls {
public:

     NotNullableErrorCls(String _name);
    virtual String toString();

private:
    String _name;


};
template<typename T>
using NotNullableError = std::shared_ptr<NotNullableErrorCls<T>>;
template<typename T>
 T valueOfNonNullableParamWithDefault(T value, T defaultVal);


class HttpStatusCls : public ObjectCls {
public:
    static int continue_;

    static int switchingProtocols;

    static int processing;

    static int ok;

    static int created;

    static int accepted;

    static int nonAuthoritativeInformation;

    static int noContent;

    static int resetContent;

    static int partialContent;

    static int multiStatus;

    static int alreadyReported;

    static int imUsed;

    static int multipleChoices;

    static int movedPermanently;

    static int found;

    static int movedTemporarily;

    static int seeOther;

    static int notModified;

    static int useProxy;

    static int temporaryRedirect;

    static int permanentRedirect;

    static int badRequest;

    static int unauthorized;

    static int paymentRequired;

    static int forbidden;

    static int notFound;

    static int methodNotAllowed;

    static int notAcceptable;

    static int proxyAuthenticationRequired;

    static int requestTimeout;

    static int conflict;

    static int gone;

    static int lengthRequired;

    static int preconditionFailed;

    static int requestEntityTooLarge;

    static int requestUriTooLong;

    static int unsupportedMediaType;

    static int requestedRangeNotSatisfiable;

    static int expectationFailed;

    static int misdirectedRequest;

    static int unprocessableEntity;

    static int locked;

    static int failedDependency;

    static int upgradeRequired;

    static int preconditionRequired;

    static int tooManyRequests;

    static int requestHeaderFieldsTooLarge;

    static int connectionClosedWithoutResponse;

    static int unavailableForLegalReasons;

    static int clientClosedRequest;

    static int internalServerError;

    static int notImplemented;

    static int badGateway;

    static int serviceUnavailable;

    static int gatewayTimeout;

    static int httpVersionNotSupported;

    static int variantAlsoNegotiates;

    static int insufficientStorage;

    static int loopDetected;

    static int notExtended;

    static int networkAuthenticationRequired;

    static int networkConnectTimeoutError;

    static int CONTINUE;

    static int SWITCHING_PROTOCOLS;

    static int OK;

    static int CREATED;

    static int ACCEPTED;

    static int NON_AUTHORITATIVE_INFORMATION;

    static int NO_CONTENT;

    static int RESET_CONTENT;

    static int PARTIAL_CONTENT;

    static int MULTIPLE_CHOICES;

    static int MOVED_PERMANENTLY;

    static int FOUND;

    static int MOVED_TEMPORARILY;

    static int SEE_OTHER;

    static int NOT_MODIFIED;

    static int USE_PROXY;

    static int TEMPORARY_REDIRECT;

    static int BAD_REQUEST;

    static int UNAUTHORIZED;

    static int PAYMENT_REQUIRED;

    static int FORBIDDEN;

    static int NOT_FOUND;

    static int METHOD_NOT_ALLOWED;

    static int NOT_ACCEPTABLE;

    static int PROXY_AUTHENTICATION_REQUIRED;

    static int REQUEST_TIMEOUT;

    static int CONFLICT;

    static int GONE;

    static int LENGTH_REQUIRED;

    static int PRECONDITION_FAILED;

    static int REQUEST_ENTITY_TOO_LARGE;

    static int REQUEST_URI_TOO_LONG;

    static int UNSUPPORTED_MEDIA_TYPE;

    static int REQUESTED_RANGE_NOT_SATISFIABLE;

    static int EXPECTATION_FAILED;

    static int UPGRADE_REQUIRED;

    static int INTERNAL_SERVER_ERROR;

    static int NOT_IMPLEMENTED;

    static int BAD_GATEWAY;

    static int SERVICE_UNAVAILABLE;

    static int GATEWAY_TIMEOUT;

    static int HTTP_VERSION_NOT_SUPPORTED;

    static int NETWORK_CONNECT_TIMEOUT_ERROR;


private:

};
using HttpStatus = std::shared_ptr<HttpStatusCls>;

template<typename E>
class DoubleLinkedQueueEntryCls : public ObjectCls {
public:
    E element;


     DoubleLinkedQueueEntryCls(E element);
    virtual void append(E e);

    virtual void prepend(E e);

    virtual E remove();

    virtual DoubleLinkedQueueEntry<E> previousEntry();

    virtual DoubleLinkedQueueEntry<E> nextEntry();

private:
    DoubleLinkedQueueEntry<E> _previousLink;

    DoubleLinkedQueueEntry<E> _nextLink;


    virtual void _link(DoubleLinkedQueueEntry<E> previous, DoubleLinkedQueueEntry<E> next);

};
template<typename E>
using DoubleLinkedQueueEntry = std::shared_ptr<DoubleLinkedQueueEntryCls<E>>;

// Parts
#include "async_cast.hpp"
#include "bytes_builder.hpp"
#include "cast.hpp"
#include "errors.hpp"
#include "iterable.hpp"
#include "list.hpp"
#include "linked_list.hpp"
#include "print.hpp"
#include "sort.hpp"
#include "symbol.hpp"

#endif