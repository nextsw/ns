#ifndef INTERNAL_H
#define INTERNAL_H
#include <memory>

#include <collection/collection.hpp>
#include <async/async.hpp>
#include <convert/convert.hpp>
#include <core/core.hpp>
#include <core/core.hpp>
#include <math/math.hpp>
#include <typed_data/typed_data.hpp>

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

external bool typeAcceptsNull<T>();

external T unsafeCast<T>(dynamic value);

const auto  POWERS_OF_TEN;


class CodeUnits : UnmodifiableListBase<int> {
public:

     CodeUnits(String _string);

    int length();

    int [](int i);

    static String stringOf(CodeUnits u);

private:
    String _string;


};

class ExternalName {
public:
    String name;


     ExternalName(String name);

private:

};
int hexDigitValue(int char);

int parseHexByte(int index, String source);

Future<Null> nullFuture;


class SystemHash {
public:

    static int combine(int hash, int value);

    static int finish(int hash);

    static int hash2(int seed, int v1, int v2);

    static int hash3(int seed, int v1, int v2, int v3);

    static int hash4(int seed, int v1, int v2, int v3, int v4);

    static int hash5(int seed, int v1, int v2, int v3, int v4, int v5);

    static int hash6(int seed, int v1, int v2, int v3, int v4, int v5, int v6);

    static int hash7(int seed, int v1, int v2, int v3, int v4, int v5, int v6, int v7);

    static int hash8(int seed, int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8);

    static int hash9(int seed, int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9);

    static int hash10(int seed, int v1, int v10, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9);

    static int hash11(int seed, int v1, int v10, int v11, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9);

    static int hash12(int seed, int v1, int v10, int v11, int v12, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9);

    static int hash13(int seed, int v1, int v10, int v11, int v12, int v13, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9);

    static int hash14(int seed, int v1, int v10, int v11, int v12, int v13, int v14, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9);

    static int hash15(int seed, int v1, int v10, int v11, int v12, int v13, int v14, int v15, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9);

    static int hash16(int seed, int v1, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9);

    static int hash17(int seed, int v1, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int v17, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9);

    static int hash18(int seed, int v1, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int v17, int v18, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9);

    static int hash19(int seed, int v1, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int v17, int v18, int v19, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9);

    static int hash20(int seed, int v1, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int v17, int v18, int v19, int v2, int v20, int v3, int v4, int v5, int v6, int v7, int v8, int v9);

    static int smear(int x);

private:

};

class SentinelValue {
public:
    int id;


     SentinelValue(int id);

private:

};
const Object sentinelValue;

external Object extractTypeArguments<T>(FunctionType extract, T instance);


class Since {
public:
    String version;


     Since(String version);

private:

};
T checkNotNullable<T extends Object>(String name, T value);


class NotNullableError<T> : Error {
public:

     NotNullableError(String _name);

    String toString();

private:
    String _name;


};
T valueOfNonNullableParamWithDefault<T extends Object>(T defaultVal, T value);


class HttpStatus {
public:
    static const int continue_;

    static const int switchingProtocols;

    static const int processing;

    static const int ok;

    static const int created;

    static const int accepted;

    static const int nonAuthoritativeInformation;

    static const int noContent;

    static const int resetContent;

    static const int partialContent;

    static const int multiStatus;

    static const int alreadyReported;

    static const int imUsed;

    static const int multipleChoices;

    static const int movedPermanently;

    static const int found;

    static const int movedTemporarily;

    static const int seeOther;

    static const int notModified;

    static const int useProxy;

    static const int temporaryRedirect;

    static const int permanentRedirect;

    static const int badRequest;

    static const int unauthorized;

    static const int paymentRequired;

    static const int forbidden;

    static const int notFound;

    static const int methodNotAllowed;

    static const int notAcceptable;

    static const int proxyAuthenticationRequired;

    static const int requestTimeout;

    static const int conflict;

    static const int gone;

    static const int lengthRequired;

    static const int preconditionFailed;

    static const int requestEntityTooLarge;

    static const int requestUriTooLong;

    static const int unsupportedMediaType;

    static const int requestedRangeNotSatisfiable;

    static const int expectationFailed;

    static const int misdirectedRequest;

    static const int unprocessableEntity;

    static const int locked;

    static const int failedDependency;

    static const int upgradeRequired;

    static const int preconditionRequired;

    static const int tooManyRequests;

    static const int requestHeaderFieldsTooLarge;

    static const int connectionClosedWithoutResponse;

    static const int unavailableForLegalReasons;

    static const int clientClosedRequest;

    static const int internalServerError;

    static const int notImplemented;

    static const int badGateway;

    static const int serviceUnavailable;

    static const int gatewayTimeout;

    static const int httpVersionNotSupported;

    static const int variantAlsoNegotiates;

    static const int insufficientStorage;

    static const int loopDetected;

    static const int notExtended;

    static const int networkAuthenticationRequired;

    static const int networkConnectTimeoutError;

    static const int CONTINUE;

    static const int SWITCHING_PROTOCOLS;

    static const int OK;

    static const int CREATED;

    static const int ACCEPTED;

    static const int NON_AUTHORITATIVE_INFORMATION;

    static const int NO_CONTENT;

    static const int RESET_CONTENT;

    static const int PARTIAL_CONTENT;

    static const int MULTIPLE_CHOICES;

    static const int MOVED_PERMANENTLY;

    static const int FOUND;

    static const int MOVED_TEMPORARILY;

    static const int SEE_OTHER;

    static const int NOT_MODIFIED;

    static const int USE_PROXY;

    static const int TEMPORARY_REDIRECT;

    static const int BAD_REQUEST;

    static const int UNAUTHORIZED;

    static const int PAYMENT_REQUIRED;

    static const int FORBIDDEN;

    static const int NOT_FOUND;

    static const int METHOD_NOT_ALLOWED;

    static const int NOT_ACCEPTABLE;

    static const int PROXY_AUTHENTICATION_REQUIRED;

    static const int REQUEST_TIMEOUT;

    static const int CONFLICT;

    static const int GONE;

    static const int LENGTH_REQUIRED;

    static const int PRECONDITION_FAILED;

    static const int REQUEST_ENTITY_TOO_LARGE;

    static const int REQUEST_URI_TOO_LONG;

    static const int UNSUPPORTED_MEDIA_TYPE;

    static const int REQUESTED_RANGE_NOT_SATISFIABLE;

    static const int EXPECTATION_FAILED;

    static const int UPGRADE_REQUIRED;

    static const int INTERNAL_SERVER_ERROR;

    static const int NOT_IMPLEMENTED;

    static const int BAD_GATEWAY;

    static const int SERVICE_UNAVAILABLE;

    static const int GATEWAY_TIMEOUT;

    static const int HTTP_VERSION_NOT_SUPPORTED;

    static const int NETWORK_CONNECT_TIMEOUT_ERROR;


private:

};

class DoubleLinkedQueueEntry<E> {
public:
    E element;


     DoubleLinkedQueueEntry(E element);

    void append(E e);

    void prepend(E e);

    E remove();

    DoubleLinkedQueueEntry<E> previousEntry();

    DoubleLinkedQueueEntry<E> nextEntry();

private:
    DoubleLinkedQueueEntry<E> _previousLink;

    DoubleLinkedQueueEntry<E> _nextLink;


    void _link(DoubleLinkedQueueEntry<E> next, DoubleLinkedQueueEntry<E> previous);

};

#endif