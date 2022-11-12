#include "uri.hpp"
void UriCls::dataFromString(String content, bool base64, Encoding encoding, String mimeType, Map<String, String> parameters) {
    UriData data = UriDataCls->fromString(content, mimeType, encoding, parameters, base64);
    return data->uri();
}

void UriCls::dataFromBytes(List<int> bytes, String mimeType, Map<String, String> parameters, bool percentEncoded) {
    UriData data = UriDataCls->fromBytes(bytes, mimeType, parameters, percentEncoded);
    return data->uri();
}

bool UriCls::hasScheme() {
    return scheme()->isNotEmpty();
}

Uri UriCls::parse(String uri, int start, int end) {
    end |= uri->length();
    if (end >= start + 5) {
        int dataDelta = _startsWithData(uri, start);
        if (dataDelta == 0) {
            if (start > 0 ||  < uri->length()) {
                uri = uri->substring(start, end);
            }
            return UriDataCls->_parse(uri, 5, nullptr)->uri;
        } else {
            if (dataDelta == 0x20) {
            return UriDataCls->_parse(uri->substring(start + 5, end), 0, nullptr)->uri;
        }
;
        }    }
    auto indices = <int>filled(8, 0, false);
    auto _c1 = indices;_c1[0] =auto _c2 = 0;_c2[_schemeEndIndex] =auto _c3 = start - 1;_c3[_hostStartIndex] =auto _c4 = start - 1;_c4[_notSimpleIndex] =auto _c5 = start - 1;_c5[_portStartIndex] =auto _c6 = start;_c6[_pathStartIndex] =auto _c7 = start;_c7[_queryStartIndex] =auto _c8 = end;_c8[_fragmentStartIndex] =end;_c8;_c7;_c6;_c5;_c4;_c3;_c2;_c1;
    auto state = _scan(uri, start, end, _uriStart, indices);
    if (state >= _nonSimpleEndStates) {
        indices[_notSimpleIndex] = end;
    }
    int schemeEnd = indices[_schemeEndIndex];
    if (schemeEnd >= start) {
        state = _scan(uri, start, schemeEnd, _schemeStart, indices);
        if (state == _schemeStart) {
            indices[_notSimpleIndex] = schemeEnd;
        }
    }
    int hostStart = indices[_hostStartIndex] + 1;
    int portStart = indices[_portStartIndex];
    int pathStart = indices[_pathStartIndex];
    int queryStart = indices[_queryStartIndex];
    int fragmentStart = indices[_fragmentStartIndex];
    String scheme;
    if ( < queryStart) {
        queryStart = fragmentStart;
    }
    if ( < hostStart) {
        pathStart = queryStart;
    } else {
        if (pathStart <= schemeEnd) {
        pathStart = schemeEnd + 1;
    }
;
    }    if ( < hostStart) {
        portStart = pathStart;
    }
    assert(hostStart == start || schemeEnd <= hostStart);
    assert(hostStart <= portStart);
    assert(schemeEnd <= pathStart);
    assert(portStart <= pathStart);
    assert(pathStart <= queryStart);
    assert(queryStart <= fragmentStart);
    bool isSimple = indices[_notSimpleIndex] < start;
    if (isSimple) {
        if (hostStart > schemeEnd + 3) {
            isSimple = false;
        } else {
            if (portStart > start && portStart + 1 == pathStart) {
            isSimple = false;
        } else {
            if (uri->startsWith(__s("\"), pathStart) || hostStart > start && (uri->startsWith(__s("\"), hostStart - 1) || uri->startsWith(__s("\"), hostStart - 2))) {
            isSimple = false;
        } else {
            if ( < end && (queryStart == pathStart + 2 && uri->startsWith(__s(".."), pathStart)) || (queryStart > pathStart + 2 && uri->startsWith(__s("/.."), queryStart - 3))) {
            isSimple = false;
        } else {
            if (schemeEnd == start + 4) {
                if (uri->startsWith(__s("file"), start)) {
                    scheme = __s("file");
                    if (hostStart <= start) {
                        String schemeAuth = __s("file://");
                        int delta = 2;
                        if (!uri->startsWith(__s("/"), pathStart)) {
                            schemeAuth = __s("file:///");
                            delta = 3;
                        }
                        uri = schemeAuth + uri->substring(pathStart, end);
                        schemeEnd -= start;
                        hostStart = 7;
                        portStart = 7;
                        pathStart = 7;
                        queryStart += delta - start;
                        fragmentStart += delta - start;
                        start = 0;
                        end = uri->length();
                    } else {
                        if (pathStart == queryStart) {
                        if (start == 0 && end == uri->length()) {
                            uri = uri->replaceRange(pathStart, queryStart, __s("/"));
                            queryStart += 1;
                            fragmentStart += 1;
                            end += 1;
                        } else {
                            uri = __s("%s$%s;");
                            schemeEnd -= start;
                            hostStart -= start;
                            portStart -= start;
                            pathStart -= start;
                            queryStart += 1 - start;
                            fragmentStart += 1 - start;
                            start = 0;
                            end = uri->length();
                        }
                    }
;
                    }                } else {
                    if (uri->startsWith(__s("http"), start)) {
                    scheme = __s("http");
                    if (portStart > start && portStart + 3 == pathStart && uri->startsWith(__s("80"), portStart + 1)) {
                        if (start == 0 && end == uri->length()) {
                            uri = uri->replaceRange(portStart, pathStart, __s(""));
                            pathStart -= 3;
                            queryStart -= 3;
                            fragmentStart -= 3;
                            end -= 3;
                        } else {
                            uri = uri->substring(start, portStart) + uri->substring(pathStart, end);
                            schemeEnd -= start;
                            hostStart -= start;
                            portStart -= start;
                            pathStart -= 3 + start;
                            queryStart -= 3 + start;
                            fragmentStart -= 3 + start;
                            start = 0;
                            end = uri->length();
                        }
                    }
                }
;
                }            } else {
                if (schemeEnd == start + 5 && uri->startsWith(__s("https"), start)) {
                scheme = __s("https");
                if (portStart > start && portStart + 4 == pathStart && uri->startsWith(__s("443"), portStart + 1)) {
                    if (start == 0 && end == uri->length()) {
                        uri = uri->replaceRange(portStart, pathStart, __s(""));
                        pathStart -= 4;
                        queryStart -= 4;
                        fragmentStart -= 4;
                        end -= 3;
                    } else {
                        uri = uri->substring(start, portStart) + uri->substring(pathStart, end);
                        schemeEnd -= start;
                        hostStart -= start;
                        portStart -= start;
                        pathStart -= 4 + start;
                        queryStart -= 4 + start;
                        fragmentStart -= 4 + start;
                        start = 0;
                        end = uri->length();
                    }
                }
            }
;
            }        }
;
        };
        };
        }    }
    if (isSimple) {
        if (start > 0 ||  < uri->length()) {
            uri = uri->substring(start, end);
            schemeEnd -= start;
            hostStart -= start;
            portStart -= start;
            pathStart -= start;
            queryStart -= start;
            fragmentStart -= start;
        }
        return make<_SimpleUriCls>(uri, schemeEnd, hostStart, portStart, pathStart, queryStart, fragmentStart, scheme);
    }
    return _UriCls->notSimple(uri, start, end, schemeEnd, hostStart, portStart, pathStart, queryStart, fragmentStart, scheme);
}

Uri UriCls::tryParse(String uri, int start, int end) {
    try {
        return parse(uri, start, end);
    } catch (FormatException null) {
        return nullptr;
    };
}

String UriCls::encodeComponent(String component) {
    return _UriCls->_uriEncode(_UriCls::_unreserved2396Table, component, utf8, false);
}

String UriCls::encodeQueryComponent(String component, Encoding encoding) {
    return _UriCls->_uriEncode(_UriCls::_unreservedTable, component, encoding, true);
}

String UriCls::decodeComponent(String encodedComponent) {
    return _UriCls->_uriDecode(encodedComponent, 0, encodedComponent->length(), utf8, false);
}

String UriCls::decodeQueryComponent(String encodedComponent, Encoding encoding) {
    return _UriCls->_uriDecode(encodedComponent, 0, encodedComponent->length(), encoding, true);
}

String UriCls::encodeFull(String uri) {
    return _UriCls->_uriEncode(_UriCls::_encodeFullTable, uri, utf8, false);
}

String UriCls::decodeFull(String uri) {
    return _UriCls->_uriDecode(uri, 0, uri->length(), utf8, false);
}

Map<String, String> UriCls::splitQueryString(String query, Encoding encoding) {
    return query->split(__s("&"))->fold(makeMap(makeList(), makeList(), [=] (Unknown  map,Unknown  element) {
        int index = element->indexOf(__s("="));
        if (index == -1) {
            if (element != __s("")) {
                map[decodeQueryComponent(element, encoding)] = __s("");
            }
        } else {
            if (index != 0) {
            auto key = element->substring(0, index);
            auto value = element->substring(index + 1);
            map[decodeQueryComponent(key, encoding)] = decodeQueryComponent(value, encoding);
        }
;
        }        return map;
    });
}

List<int> UriCls::parseIPv4Address(String host) {
    return _parseIPv4Address(host, 0, host->length());
}

List<int> UriCls::parseIPv6Address(String host, int start, int end) {
    end |= host->length();
    InlineMethod;
    InlineMethod;
    if (host->length() < 2) {
        error(__s("address is too short"), nullptr);
    }
    List<int> parts = makeList();
    bool wildcardSeen = false;
    bool seenDot = false;
    int partStart = start;
    for (;  < end; i++) {
        int char = host->codeUnitAt(i);
        if (charValue == _COLON) {
            if (i == start) {
                i++;
                if (host->codeUnitAt(i) != _COLON) {
                    error(__s("invalid start colon."), i);
                }
                partStart = i;
            }
            if (i == partStart) {
                if (wildcardSeen) {
                    error(__s("only one wildcard `::` is allowed"), i);
                }
                wildcardSeen = true;
                parts->add(-1);
            } else {
                parts->add(parseHex(partStart, i));
            }
            partStart = i + 1;
        } else {
            if (charValue == _DOT) {
            seenDot = true;
        }
;
        }    }
    if (parts->length() == 0) {
        error(__s("too few parts"), nullptr);
    }
    bool atEnd = (partStart == end);
    bool isLastWildcard = (parts->last == -1);
    if (atEnd && !isLastWildcard) {
        error(__s("expected a part after last `:`"), end);
    }
    if (!atEnd) {
        if (!seenDot) {
            parts->add(parseHex(partStart, end));
        } else {
            List<int> last = _parseIPv4Address(host, partStart, end);
            parts->add(last[0] << 8 | last[1]);
            parts->add(last[2] << 8 | last[3]);
        }
    }
    if (wildcardSeen) {
        if (parts->length() > 7) {
            error(__s("an address with a wildcard must have less than 7 parts"), nullptr);
        }
    } else {
        if (parts->length() != 8) {
        error(__s("an address without a wildcard must contain exactly 8 parts"), nullptr);
    }
;
    }    List<int> bytes = make<Uint8ListCls>(16);
    for (;  < parts->length(); i++) {
        int value = parts[i];
        if (value == -1) {
            int wildCardLength = 9 - parts->length();
            for (;  < wildCardLength; j++) {
                bytes[index] = 0;
                bytes[index + 1] = 0;
                index += 2;
            }
        } else {
            bytes[index] = value >> 8;
            bytes[index + 1] = value & 0xff;
            index += 2;
        }
    }
    return bytes;
}

List<int> UriCls::_parseIPv4Address(String host, int start, int end) {
    InlineMethod;
    auto result = make<Uint8ListCls>(4);
    int partIndex = 0;
    int partStart = start;
    for (;  < end; i++) {
        int char = host->codeUnitAt(i);
        if (charValue != _DOT) {
            if (charValue ^ 0x30 > 9) {
                error(__s("invalid character"), i);
            }
        } else {
            if (partIndex == 3) {
                error(__s("IPv4 address should contain exactly 4 parts"), i);
            }
            int part = intValue->parse(host->substring(partStart, i));
            if (part > 255) {
                error(__s("each part must be in the range 0..255"), partStart);
            }
            result[partIndex++] = part;
            partStart = i + 1;
        }
    }
    if (partIndex != 3) {
        error(__s("IPv4 address should contain exactly 4 parts"), end);
    }
    int part = intValue->parse(host->substring(partStart, end));
    if (part > 255) {
        error(__s("each part must be in the range 0..255"), partStart);
    }
    result[partIndex] = part;
    return result;
}

void _UriCls::notSimple(String uri, int start, int end, int schemeEnd, int hostStart, int portStart, int pathStart, int queryStart, int fragmentStart, String scheme) {
    if (scheme == nullptr) {
        scheme = __s("");
        if (schemeEnd > start) {
            scheme = _makeScheme(uri, start, schemeEnd);
        } else {
            if (schemeEnd == start) {
            _fail(uri, start, __s("Invalid empty scheme"));
        }
;
        }    }
    String userInfo = __s("");
    String host;
    int port;
    if (hostStart > start) {
        int userInfoStart = schemeEnd + 3;
        if ( < hostStart) {
            userInfo = _makeUserInfo(uri, userInfoStart, hostStart - 1);
        }
        host = _makeHost(uri, hostStart, portStart, false);
        if (portStart + 1 < pathStart) {
            int portNumber = intValue->tryParse(uri->substring(portStart + 1, pathStart)) | (throw make<FormatExceptionCls>(__s("Invalid port"), uri, portStart + 1));
            port = _makePort(portNumber, scheme);
        }
    }
    String path = _makePath(uri, pathStart, queryStart, nullptr, scheme, host != nullptr);
    String query;
    if ( < fragmentStart) {
        query = _makeQuery(uri, queryStart + 1, fragmentStart, nullptr);
    }
    String fragment;
    if ( < end) {
        fragment = _makeFragment(uri, fragmentStart + 1, end);
    }
    return _UriCls->_internal(scheme, userInfo, host, port, path, query, fragment);
}

void _UriCls::http(String authority, String unencodedPath, Map<String, dynamic> queryParameters) {
    return _makeHttpUri(__s("http"), authority, unencodedPath, queryParameters);
}

void _UriCls::https(String authority, String unencodedPath, Map<String, dynamic> queryParameters) {
    return _makeHttpUri(__s("https"), authority, unencodedPath, queryParameters);
}

String _UriCls::authority() {
    if (!hasAuthority()) {
        return __s("");
    }
    auto sb = make<StringBufferCls>();
    _writeAuthority(sb);
    return sb->toString();
}

String _UriCls::userInfo() {
    return _userInfo;
}

String _UriCls::host() {
    String host = _host;
    if (host == nullptr) {
        return __s("");
    }
    if (host->startsWith(__s("["))) {
        return host->substring(1, host->length() - 1);
    }
    return host;
}

int _UriCls::port() {
    return _port | _defaultPort(scheme);
}

String _UriCls::query() {
    return _query | __s("");
}

String _UriCls::fragment() {
    return _fragment | __s("");
}

bool _UriCls::isScheme(String scheme) {
    String thisScheme = this->scheme;
    if (scheme == nullptr) {
        return thisScheme->isEmpty();
    }
    if (scheme->length() != thisScheme->length()) {
        return false;
    }
    return _caseInsensitiveStartsWith(scheme, thisScheme, 0);
}

void _UriCls::file(String path, bool windows) {
    return (windows | _UriCls::_isWindows)? _makeWindowsFileUrl(path, false) : _makeFileUri(path, false);
}

void _UriCls::directory(String path, bool windows) {
    return (windows | _UriCls::_isWindows)? _makeWindowsFileUrl(path, true) : _makeFileUri(path, true);
}

Uri _UriCls::replace(String fragment, String host, String path, Iterable<String> pathSegments, int port, String query, Map<String, dynamic> queryParameters, String scheme, String userInfo) {
    bool schemeChanged = false;
    if (scheme != nullptr) {
        scheme = _makeScheme(scheme, 0, scheme->length());
        schemeChanged = (scheme != this->scheme);
    } else {
        scheme = this->scheme;
    }
    bool isFile = (scheme == __s("file"));
    if (userInfo != nullptr) {
        userInfo = _makeUserInfo(userInfo, 0, userInfo->length());
    } else {
        userInfo = this->_userInfo;
    }
    if (port != nullptr) {
        port = _makePort(port, scheme);
    } else {
        port = this->_port;
        if (schemeChanged) {
            port = _makePort(port, scheme);
        }
    }
    if (host != nullptr) {
        host = _makeHost(host, 0, host->length(), false);
    } else {
        if (this->hasAuthority()) {
        host = this->_host;
    } else {
        if (userInfo->isNotEmpty() || port != nullptr || isFile) {
        host = __s("");
    }
;
    };
    }    bool hasAuthority = host != nullptr;
    if (path != nullptr || pathSegments != nullptr) {
        path = _makePath(path, 0, _stringOrNullLength(path), pathSegments, scheme, hasAuthority);
    } else {
        auto currentPath = this->path;
        if ((isFile || (hasAuthority && !currentPath->isEmpty())) && !currentPath->startsWith(__s("/"))) {
            currentPath = __s("/") + currentPath;
        }
        path = currentPath;
    }
    if (query != nullptr || queryParameters != nullptr) {
        query = _makeQuery(query, 0, _stringOrNullLength(query), queryParameters);
    } else {
        query = this->_query;
    }
    if (fragment != nullptr) {
        fragment = _makeFragment(fragment, 0, fragment->length());
    } else {
        fragment = this->_fragment;
    }
    return _UriCls->_internal(scheme, userInfo, host, port, path, query, fragment);
}

Uri _UriCls::removeFragment() {
    if (!this->hasFragment()) {
        return this;
    }
    return _UriCls->_internal(scheme, _userInfo, _host, _port, path, _query, nullptr);
}

Uri _UriCls::normalizePath() {
    String path = _normalizePath(this->path, scheme, hasAuthority());
    if (identical(path, this->path)) {
        return this;
    }
    return this->replace(path);
}

bool _UriCls::isAbsolute() {
    return scheme != __s("") && fragment() == __s("");
}

Uri _UriCls::resolve(String reference) {
    return resolveUri(UriCls->parse(reference));
}

Uri _UriCls::resolveUri(Uri reference) {
    String targetScheme;
    String targetUserInfo = __s("");
    String targetHost;
    int targetPort;
    String targetPath;
    String targetQuery;
    if (reference->scheme->isNotEmpty()) {
        targetScheme = reference->scheme;
        if (reference->hasAuthority()) {
            targetUserInfo = reference->userInfo();
            targetHost = reference->host();
            targetPort = reference->hasPort()? reference->port() : nullptr;
        }
        targetPath = _removeDotSegments(reference->path);
        if (reference->hasQuery()) {
            targetQuery = reference->query();
        }
    } else {
        targetScheme = this->scheme;
        if (reference->hasAuthority()) {
            targetUserInfo = reference->userInfo();
            targetHost = reference->host();
            targetPort = _makePort(reference->hasPort()? reference->port() : nullptr, targetScheme);
            targetPath = _removeDotSegments(reference->path);
            if (reference->hasQuery()) {
                targetQuery = reference->query();
            }
        } else {
            targetUserInfo = this->_userInfo;
            targetHost = this->_host;
            targetPort = this->_port;
            if (reference->path == __s("")) {
                targetPath = this->path;
                if (reference->hasQuery()) {
                    targetQuery = reference->query();
                } else {
                    targetQuery = this->_query;
                }
            } else {
                String basePath = this->path;
                int packageNameEnd = _packageNameEnd(this, basePath);
                if (packageNameEnd > 0) {
                    assert(targetScheme == __s("package"));
                    assert(!this->hasAuthority());
                    assert(!this->hasEmptyPath());
                    String packageName = basePath->substring(0, packageNameEnd);
                    if (reference->hasAbsolutePath()) {
                        targetPath = packageName + _removeDotSegments(reference->path);
                    } else {
                        targetPath = packageName + _removeDotSegments(_mergePaths(basePath->substring(packageName->length()), reference->path));
                    }
                } else {
                    if (reference->hasAbsolutePath()) {
                    targetPath = _removeDotSegments(reference->path);
                } else {
                    if (this->hasEmptyPath()) {
                        if (!this->hasAuthority()) {
                            if (!this->hasScheme()) {
                                targetPath = reference->path;
                            } else {
                                targetPath = _removeDotSegments(reference->path);
                            }
                        } else {
                            targetPath = _removeDotSegments(__s("/") + reference->path);
                        }
                    } else {
                        auto mergedPath = _mergePaths(this->path, reference->path);
                        if (this->hasScheme() || this->hasAuthority() || this->hasAbsolutePath()) {
                            targetPath = _removeDotSegments(mergedPath);
                        } else {
                            targetPath = _normalizeRelativePath(mergedPath, this->hasScheme() || this->hasAuthority());
                        }
                    }
                }
;
                }                if (reference->hasQuery()) {
                    targetQuery = reference->query();
                }
            }
        }
    }
    String fragment = reference->hasFragment()? reference->fragment() : nullptr;
    return _UriCls->_internal(targetScheme, targetUserInfo, targetHost, targetPort, targetPath, targetQuery, fragment);
}

bool _UriCls::hasScheme() {
    return scheme->isNotEmpty();
}

bool _UriCls::hasAuthority() {
    return _host != nullptr;
}

bool _UriCls::hasPort() {
    return _port != nullptr;
}

bool _UriCls::hasQuery() {
    return _query != nullptr;
}

bool _UriCls::hasFragment() {
    return _fragment != nullptr;
}

bool _UriCls::hasEmptyPath() {
    return path->isEmpty();
}

bool _UriCls::hasAbsolutePath() {
    return path->startsWith(__s("/"));
}

String _UriCls::origin() {
    if (scheme == __s("")) {
        throw make<StateErrorCls>(__s("Cannot use origin without a scheme: %s)"));
    }
    if (scheme != __s("http") && scheme != __s("https")) {
        throw make<StateErrorCls>(__s("Origin is only applicable schemes http and https: %s)"));
    }
    String host = _host;
    if (host == nullptr || host == __s("")) {
        throw make<StateErrorCls>(__s("A %s$%s)"));
    }
    int port = _port;
    if (port == nullptr) {
        return __s("%s$%s;");
    }
    return __s("%s$%s$%s;");
}

String _UriCls::toFilePath(bool windows) {
    if (scheme != __s("") && scheme != __s("file")) {
        throw make<UnsupportedErrorCls>(__s("Cannot extract a file path from a %s)"));
    }
    if (query() != __s("")) {
        throw make<UnsupportedErrorCls>(__s("Cannot extract a file path from a URI with a query component"));
    }
    if (fragment() != __s("")) {
        throw make<UnsupportedErrorCls>(__s("Cannot extract a file path from a URI with a fragment component"));
    }
    return (windows | _isWindows())? _toWindowsFilePath(this) : _toFilePath();
}

UriData _UriCls::data() {
    return (scheme == __s("data"))? UriDataCls->fromUri(this) : nullptr;
}

String _UriCls::toString() {
    return _text;
}

bool _UriCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    return is<Uri>(other) && scheme == other->scheme && hasAuthority() == other->hasAuthority && userInfo() == other->userInfo && host() == other->host && port() == other->port && path == other->path && hasQuery() == other->hasQuery && query() == other->query && hasFragment() == other->hasFragment && fragment() == other->fragment;
}

_UriCls::_UriCls(String fragment, String host, String path, Iterable<String> pathSegments, int port, String query, Map<String, dynamic> queryParameters, String scheme, String userInfo) {
    {
        if (scheme == nullptr) {
            scheme = __s("");
        } else {
            scheme = _makeScheme(scheme, 0, scheme->length());
        }
        userInfo = _makeUserInfo(userInfo, 0, _stringOrNullLength(userInfo));
        if (userInfo == nullptr) {
            throw __s("unreachable");
        }
        host = _makeHost(host, 0, _stringOrNullLength(host), false);
        if (query == __s("")) {
            query = nullptr;
        }
        query = _makeQuery(query, 0, _stringOrNullLength(query), queryParameters);
        fragment = _makeFragment(fragment, 0, _stringOrNullLength(fragment));
        port = _makePort(port, scheme);
        bool isFile = (scheme == __s("file"));
        if (host == nullptr && (userInfo->isNotEmpty() || port != nullptr || isFile)) {
            host = __s("");
        }
        bool hasAuthority = (host != nullptr);
        path = _makePath(path, 0, _stringOrNullLength(path), pathSegments, scheme, hasAuthority);
        if (path == nullptr) {
            throw __s("unreachable");
        }
        if (scheme->isEmpty() && host == nullptr && !path->startsWith(__s("/"))) {
            bool allowScheme = scheme->isNotEmpty() || host != nullptr;
            path = _normalizeRelativePath(path, allowScheme);
        } else {
            path = _removeDotSegments(path);
        }
        if (host == nullptr && path->startsWith(__s("//"))) {
            host = __s("");
        }
        return _UriCls->_internal(scheme, userInfo, host, port, path, query, fragment);
    }
}

int _UriCls::_defaultPort(String scheme) {
    if (scheme == __s("http")) {
        return 80;
    }
    if (scheme == __s("https")) {
        return 443;
    }
    return 0;
}

Never _UriCls::_fail(String uri, int index, String message) {
    throw make<FormatExceptionCls>(message, uri, index);
}

_Uri _UriCls::_makeHttpUri(String scheme, String authority, String unencodedPath, Map<String, dynamic> queryParameters) {
    auto userInfo = __s("");
    String host;
    int port;
    if (authority != nullptr && authority->isNotEmpty()) {
        auto hostStart = 0;
        for (;  < authority->length(); i++) {
            int atSign = 0x40;
            if (authority->codeUnitAt(i) == atSign) {
                userInfo = authority->substring(0, i);
                hostStart = i + 1;
                break;
            }
        }
        auto hostEnd = hostStart;
        if ( < authority->length() && authority->codeUnitAt(hostStart) == _LEFT_BRACKET) {
            int escapeForZoneID = -1;
            for (;  < authority->length(); hostEnd++) {
                int char = authority->codeUnitAt(hostEnd);
                if (charValue == _PERCENT &&  < 0) {
                    escapeForZoneID = hostEnd;
                    if (authority->startsWith(__s("25"), hostEnd + 1)) {
                        hostEnd += 2;
                    }
                } else {
                    if (charValue == _RIGHT_BRACKET) {
                    break;
                }
;
                }            }
            if (hostEnd == authority->length()) {
                throw make<FormatExceptionCls>(__s("Invalid IPv6 host entry."), authority, hostStart);
            }
            UriCls->parseIPv6Address(authority, hostStart + 1, ( < 0)? hostEnd : escapeForZoneID);
            hostEnd++;
            if (hostEnd != authority->length() && authority->codeUnitAt(hostEnd) != _COLON) {
                throw make<FormatExceptionCls>(__s("Invalid end of authority"), authority, hostEnd);
            }
        }
        for (;  < authority->length(); hostEnd++) {
            if (authority->codeUnitAt(hostEnd) == _COLON) {
                auto portString = authority->substring(hostEnd + 1);
                if (portString->isNotEmpty()) {
                    port = intValue->parse(portString);
                }
                break;
            }
        }
        host = authority->substring(hostStart, hostEnd);
    }
    return make<_UriCls>(scheme, userInfo, host, port, unencodedPath->split(__s("/")), queryParameters);
}

void _UriCls::_checkNonWindowsPathReservedCharacters(List<String> segments, bool argumentError) {
    for (auto segment : segments) {
        if (segment->contains(__s("/"))) {
            if (argumentError) {
                throw make<ArgumentErrorCls>(__s("Illegal path character %s)"));
            } else {
                throw make<UnsupportedErrorCls>(__s("Illegal path character %s)"));
            }
        }
    }
}

void _UriCls::_checkWindowsPathReservedCharacters(List<String> segments, bool argumentError, int firstSegment) {
    for (auto segment : segments->skip(firstSegment)) {
        if (segment->contains(make<RegExpCls>(__s("["*/:<>?\\|]")))) {
            if (argumentError) {
                throw make<ArgumentErrorCls>(__s("Illegal character in path"));
            } else {
                throw make<UnsupportedErrorCls>(__s("Illegal character in path: %s)"));
            }
        }
    }
}

void _UriCls::_checkWindowsDriveLetter(int charCode, bool argumentError) {
    if ((_UPPER_CASE_A <= charCode && charCode <= _UPPER_CASE_Z) || (_LOWER_CASE_A <= charCode && charCode <= _LOWER_CASE_Z)) {
        return;
    }
    if (argumentError) {
        throw make<ArgumentErrorCls>(__s("Illegal drive letter ") + StringCls->fromCharCode(charCode));
    } else {
        throw make<UnsupportedErrorCls>(__s("Illegal drive letter ") + StringCls->fromCharCode(charCode));
    }
}

Uri _UriCls::_makeFileUri(String path, bool slashTerminated) {
    String sep = __s("/");
    auto segments = path->split(sep);
    if (slashTerminated && segments->isNotEmpty() && segments->last->isNotEmpty) {
        segments->add(__s(""));
    }
    if (path->startsWith(sep)) {
        return make<UriCls>(__s("file"), segments);
    } else {
        return make<UriCls>(segments);
    }
}

void _UriCls::_makeWindowsFileUrl(String path, bool slashTerminated) {
    if (path->startsWith(__s("\\?\"))) {
        if (path->startsWith(__s("UNC\"), 4)) {
            path = path->replaceRange(0, 7, __s("\"));
        } else {
            path = path->substring(4);
            if (path->length() < 3 || path->codeUnitAt(1) != _COLON || path->codeUnitAt(2) != _BACKSLASH) {
                throw make<ArgumentErrorCls>(__s("Windows paths with \\?\ prefix must be absolute"));
            }
        }
    } else {
        path = path->replaceAll(__s("/"), __s("\"));
    }
    String sep = __s("\");
    if (path->length() > 1 && path->codeUnitAt(1) == _COLON) {
        _checkWindowsDriveLetter(path->codeUnitAt(0), true);
        if (path->length() == 2 || path->codeUnitAt(2) != _BACKSLASH) {
            throw make<ArgumentErrorCls>(__s("Windows paths with drive letter must be absolute"));
        }
        auto pathSegments = path->split(sep);
        if (slashTerminated && pathSegments->last->isNotEmpty) {
            pathSegments->add(__s(""));
        }
        _checkWindowsPathReservedCharacters(pathSegments, true, 1);
        return make<UriCls>(__s("file"), pathSegments);
    }
    if (path->startsWith(sep)) {
        if (path->startsWith(sep, 1)) {
            int pathStart = path->indexOf(__s("\"), 2);
            String hostPart = ( < 0)? path->substring(2) : path->substring(2, pathStart);
            String pathPart = ( < 0)? __s("") : path->substring(pathStart + 1);
            auto pathSegments = pathPart->split(sep);
            _checkWindowsPathReservedCharacters(pathSegments, true);
            if (slashTerminated && pathSegments->last->isNotEmpty) {
                pathSegments->add(__s(""));
            }
            return make<UriCls>(__s("file"), hostPart, pathSegments);
        } else {
            auto pathSegments = path->split(sep);
            if (slashTerminated && pathSegments->last->isNotEmpty) {
                pathSegments->add(__s(""));
            }
            _checkWindowsPathReservedCharacters(pathSegments, true);
            return make<UriCls>(__s("file"), pathSegments);
        }
    } else {
        auto pathSegments = path->split(sep);
        _checkWindowsPathReservedCharacters(pathSegments, true);
        if (slashTerminated && pathSegments->isNotEmpty() && pathSegments->last->isNotEmpty) {
            pathSegments->add(__s(""));
        }
        return make<UriCls>(pathSegments);
    }
}

List<String> _UriCls::_computePathSegments(String pathToSplit) {
    if (pathToSplit->isNotEmpty() && pathToSplit->codeUnitAt(0) == _SLASH) {
        pathToSplit = pathToSplit->substring(1);
    }
    return (pathToSplit->isEmpty())? makeList() : <String>unmodifiable(pathToSplit->split(__s("/"))->map(UriCls::decodeComponent));
}

Map<String, List<String>> _UriCls::_computeQueryParametersAll(String query) {
    if (query == nullptr || query->isEmpty()) {
        return makeMap(makeList(), makeList();
    }
    Map<String, List<String>> queryParameterLists = _splitQueryStringAll(query);
    queryParameterLists->updateAll(_toUnmodifiableStringList);
    return <String, List<String>>unmodifiable(queryParameterLists);
}

int _UriCls::_makePort(int port, String scheme) {
    if (port != nullptr && port == _defaultPort(scheme)) {
        return nullptr;
    }
    return port;
}

String _UriCls::_makeHost(String host, int start, int end, bool strictIPv6) {
    if (host == nullptr) {
        return nullptr;
    }
    if (start == end) {
        return __s("");
    }
    if (host->codeUnitAt(start) == _LEFT_BRACKET) {
        if (host->codeUnitAt(end - 1) != _RIGHT_BRACKET) {
            _fail(host, start, __s("Missing end `]` to match `[` in host"));
        }
        String zoneID = __s("");
        int index = _checkZoneID(host, start + 1, end - 1);
        if ( < end - 1) {
            int zoneIDstart = (host->startsWith(__s("25"), index + 1))? index + 3 : index + 1;
            zoneID = _normalizeZoneID(host, zoneIDstart, end - 1, __s("%25"));
        }
        UriCls->parseIPv6Address(host, start + 1, index);
        return host->substring(start, index)->toLowerCase() + zoneID + __s("]");
    }
    if (!strictIPv6) {
        for (;  < end; i++) {
            if (host->codeUnitAt(i) == _COLON) {
                String zoneID = __s("");
                int index = _checkZoneID(host, start, end);
                if ( < end) {
                    int zoneIDstart = (host->startsWith(__s("25"), index + 1))? index + 3 : index + 1;
                    zoneID = _normalizeZoneID(host, zoneIDstart, end, __s("%25"));
                }
                UriCls->parseIPv6Address(host, start, index);
                return __s("[%s+") + zoneID + __s("]");
            }
        }
    }
    return _normalizeRegName(host, start, end);
}

int _UriCls::_checkZoneID(String host, int start, int end) {
    int index = host->indexOf(__s("%"), start);
    index = (index >= start &&  < end)? index : end;
    return index;
}

bool _UriCls::_isZoneIDChar(int charValue) {
    return  < 127 && (_zoneIDTable[charValue >> 4] & (1 << (charValue & 0xf))) != 0;
}

String _UriCls::_normalizeZoneID(String host, int start, int end, String prefix) {
    StringBuffer buffer;
    if (prefix != __s("")) {
        buffer = make<StringBufferCls>(prefix);
    }
    int sectionStart = start;
    int index = start;
    bool isNormalized = true;
    while ( < end) {
        int char = host->codeUnitAt(index);
        if (charValue == _PERCENT) {
            String replacement = _normalizeEscape(host, index, true);
            if (replacement == nullptr && isNormalized) {
                index += 3;
                continue;
            }
            buffer |= make<StringBufferCls>();
            String slice = host->substring(sectionStart, index);
            buffer->write(slice);
            int sourceLength = 3;
            if (replacement == nullptr) {
                replacement = host->substring(index, index + 3);
            } else {
                if (replacement == __s("%")) {
                _fail(host, index, __s("ZoneID should not contain % anymore"));
            }
;
            }            buffer->write(replacement);
            index += sourceLength;
            sectionStart = index;
            isNormalized = true;
        } else {
            if (_isZoneIDChar(charValue)) {
            if (isNormalized && _UPPER_CASE_A <= charValue && _UPPER_CASE_Z >= charValue) {
                buffer |= make<StringBufferCls>();
                if ( < index) {
                    buffer->write(host->substring(sectionStart, index));
                    sectionStart = index;
                }
                isNormalized = false;
            }
            index++;
        } else {
            int sourceLength = 1;
            if ((charValue & 0xFC00) == 0xD800 && (index + 1) < end) {
                int tail = host->codeUnitAt(index + 1);
                if ((tail & 0xFC00) == 0xDC00) {
                    charValue = 0x10000 | ((charValue & 0x3ff) << 10) | (tail & 0x3ff);
                    sourceLength = 2;
                }
            }
            String slice = host->substring(sectionStart, index);
                    auto _c1 = (buffer ??= make<StringBufferCls>());        _c1.auto _c2 = write(slice);        _c2.write(_escapeChar(charValue));        _c2;_c1;
            index += sourceLength;
            sectionStart = index;
        }
;
        }    }
    if (buffer == nullptr) {
        return host->substring(start, end);
    }
    if ( < end) {
        String slice = host->substring(sectionStart, end);
        buffer->write(slice);
    }
    return buffer->toString();
}

bool _UriCls::_isRegNameChar(int charValue) {
    return  < 127 && (_regNameTable[charValue >> 4] & (1 << (charValue & 0xf))) != 0;
}

String _UriCls::_normalizeRegName(String host, int start, int end) {
    StringBuffer buffer;
    int sectionStart = start;
    int index = start;
    bool isNormalized = true;
    while ( < end) {
        int char = host->codeUnitAt(index);
        if (charValue == _PERCENT) {
            String replacement = _normalizeEscape(host, index, true);
            if (replacement == nullptr && isNormalized) {
                index += 3;
                continue;
            }
            buffer |= make<StringBufferCls>();
            String slice = host->substring(sectionStart, index);
            if (!isNormalized) {
                slice = slice->toLowerCase();
            }
            buffer->write(slice);
            int sourceLength = 3;
            if (replacement == nullptr) {
                replacement = host->substring(index, index + 3);
            } else {
                if (replacement == __s("%")) {
                replacement = __s("%25");
                sourceLength = 1;
            }
;
            }            buffer->write(replacement);
            index += sourceLength;
            sectionStart = index;
            isNormalized = true;
        } else {
            if (_isRegNameChar(charValue)) {
            if (isNormalized && _UPPER_CASE_A <= charValue && _UPPER_CASE_Z >= charValue) {
                buffer |= make<StringBufferCls>();
                if ( < index) {
                    buffer->write(host->substring(sectionStart, index));
                    sectionStart = index;
                }
                isNormalized = false;
            }
            index++;
        } else {
            if (_isGeneralDelimiter(charValue)) {
            _fail(host, index, __s("Invalid character"));
        } else {
            int sourceLength = 1;
            if ((charValue & 0xFC00) == 0xD800 && (index + 1) < end) {
                int tail = host->codeUnitAt(index + 1);
                if ((tail & 0xFC00) == 0xDC00) {
                    charValue = 0x10000 | ((charValue & 0x3ff) << 10) | (tail & 0x3ff);
                    sourceLength = 2;
                }
            }
            String slice = host->substring(sectionStart, index);
            if (!isNormalized) {
                slice = slice->toLowerCase();
            }
                    auto _c1 = (buffer ??= make<StringBufferCls>());        _c1.auto _c2 = write(slice);        _c2.write(_escapeChar(charValue));        _c2;_c1;
            index += sourceLength;
            sectionStart = index;
        }
;
        };
        }    }
    if (buffer == nullptr) {
        return host->substring(start, end);
    }
    if ( < end) {
        String slice = host->substring(sectionStart, end);
        if (!isNormalized) {
            slice = slice->toLowerCase();
        }
        buffer->write(slice);
    }
    return buffer->toString();
}

String _UriCls::_makeScheme(String scheme, int start, int end) {
    if (start == end) {
        return __s("");
    }
    int firstCodeUnit = scheme->codeUnitAt(start);
    if (!_isAlphabeticCharacter(firstCodeUnit)) {
        _fail(scheme, start, __s("Scheme not starting with alphabetic character"));
    }
    bool containsUpperCase = false;
    for (;  < end; i++) {
        int codeUnit = scheme->codeUnitAt(i);
        if (!_isSchemeCharacter(codeUnit)) {
            _fail(scheme, i, __s("Illegal scheme character"));
        }
        if (_UPPER_CASE_A <= codeUnit && codeUnit <= _UPPER_CASE_Z) {
            containsUpperCase = true;
        }
    }
    scheme = scheme->substring(start, end);
    if (containsUpperCase) {
        scheme = scheme->toLowerCase();
    }
    return _canonicalizeScheme(scheme);
}

String _UriCls::_canonicalizeScheme(String scheme) {
    if (scheme == __s("http")) {
        return __s("http");
    }
    if (scheme == __s("file")) {
        return __s("file");
    }
    if (scheme == __s("https")) {
        return __s("https");
    }
    if (scheme == __s("package")) {
        return __s("package");
    }
    return scheme;
}

String _UriCls::_makeUserInfo(String userInfo, int start, int end) {
    if (userInfo == nullptr) {
        return __s("");
    }
    return _normalizeOrSubstring(userInfo, start, end, _userinfoTable);
}

String _UriCls::_makePath(String path, int start, int end, Iterable<String> pathSegments, String scheme, bool hasAuthority) {
    bool isFile = (scheme == __s("file"));
    bool ensureLeadingSlash = isFile || hasAuthority;
    String result;
    if (path == nullptr) {
        if (pathSegments == nullptr) {
            return isFile? __s("/") : __s("");
        }
        result = pathSegments->map([=] (Unknown  s) {
            _uriEncode(_pathCharTable, s, utf8, false);
        })->join(__s("/"));
    } else {
        if (pathSegments != nullptr) {
        throw make<ArgumentErrorCls>(__s("Both path and pathSegments specified"));
    } else {
        result = _normalizeOrSubstring(path, start, end, _pathCharOrSlashTable, true, true);
    }
;
    }    if (result->isEmpty()) {
        if (isFile) {
            return __s("/");
        }
    } else {
        if (ensureLeadingSlash && !result->startsWith(__s("/"))) {
        result = __s("/") + result;
    }
;
    }    result = _normalizePath(result, scheme, hasAuthority);
    return result;
}

String _UriCls::_normalizePath(String path, String scheme, bool hasAuthority) {
    if (scheme->isEmpty() && !hasAuthority && !path->startsWith(__s("/")) && !path->startsWith(__s("\"))) {
        return _normalizeRelativePath(path, scheme->isNotEmpty() || hasAuthority);
    }
    return _removeDotSegments(path);
}

String _UriCls::_makeQuery(String query, int start, int end, Map<String, dynamic> queryParameters) {
    if (query != nullptr) {
        if (queryParameters != nullptr) {
            throw make<ArgumentErrorCls>(__s("Both query and queryParameters specified"));
        }
        return _normalizeOrSubstring(query, start, end, _queryCharTable, true);
    }
    if (queryParameters == nullptr) {
        return nullptr;
    }
    auto result = make<StringBufferCls>();
    auto separator = __s("");
    InlineMethod;
    queryParameters->forEach([=] (Unknown  key,Unknown  value) {
        if (value == nullptr || is<String>(value)) {
            writeParameter(key, value);
        } else {
            Iterable<any> values = value;
            for (String value : values) {
                writeParameter(key, value);
            }
        }
    });
    return result->toString();
}

String _UriCls::_makeFragment(String fragment, int start, int end) {
    if (fragment == nullptr) {
        return nullptr;
    }
    return _normalizeOrSubstring(fragment, start, end, _queryCharTable, true);
}

String _UriCls::_normalizeEscape(String source, int index, bool lowerCase) {
    assert(source->codeUnitAt(index) == _PERCENT);
    if (index + 2 >= source->length()) {
        return __s("%");
    }
    int firstDigit = source->codeUnitAt(index + 1);
    int secondDigit = source->codeUnitAt(index + 2);
    int firstDigitValue = hexDigitValue(firstDigit);
    int secondDigitValue = hexDigitValue(secondDigit);
    if ( < 0 ||  < 0) {
        return __s("%");
    }
    int value = firstDigitValue * 16 + secondDigitValue;
    if (_isUnreservedChar(value)) {
        if (lowerCase && _UPPER_CASE_A <= value && _UPPER_CASE_Z >= value) {
            value |= 0x20;
        }
        return StringCls->fromCharCode(value);
    }
    if (firstDigit >= _LOWER_CASE_A || secondDigit >= _LOWER_CASE_A) {
        return source->substring(index, index + 3)->toUpperCase();
    }
    return nullptr;
}

String _UriCls::_escapeChar(int charValue) {
    assert(charValue <= 0x10ffff);
    List<int> codeUnits;
    if ( < 0x80) {
        codeUnits = make<Uint8ListCls>(3);
        codeUnits[0] = _PERCENT;
        codeUnits[1] = _hexDigits->codeUnitAt(charValue >> 4);
        codeUnits[2] = _hexDigits->codeUnitAt(charValue & 0xf);
    } else {
        int flag = 0xc0;
        int encodedBytes = 2;
        if (charValue > 0x7ff) {
            flag = 0xe0;
            encodedBytes = 3;
            if (charValue > 0xffff) {
                encodedBytes = 4;
                flag = 0xf0;
            }
        }
        codeUnits = make<Uint8ListCls>(3 * encodedBytes);
        int index = 0;
        while (--encodedBytes >= 0) {
            int byte = ((charValue >> (6 * encodedBytes)) & 0x3f) | flag;
            codeUnits[index] = _PERCENT;
            codeUnits[index + 1] = _hexDigits->codeUnitAt(byte >> 4);
            codeUnits[index + 2] = _hexDigits->codeUnitAt(byte & 0xf);
            index += 3;
            flag = 0x80;
        }
    }
    return StringCls->fromCharCodes(codeUnits);
}

String _UriCls::_normalizeOrSubstring(String component, int start, int end, List<int> charTable, bool escapeDelimiters, bool replaceBackslash) {
    return _normalize(component, start, end, charTable, escapeDelimiters, replaceBackslash) | component->substring(start, end);
}

String _UriCls::_normalize(String component, int start, int end, List<int> charTable, bool escapeDelimiters, bool replaceBackslash) {
    StringBuffer buffer;
    int sectionStart = start;
    int index = start;
    while ( < end) {
        int char = component->codeUnitAt(index);
        if ( < 127 && (charTable[charValue >> 4] & (1 << (charValue & 0x0f))) != 0) {
            index++;
        } else {
            String replacement;
            int sourceLength;
            if (charValue == _PERCENT) {
                replacement = _normalizeEscape(component, index, false);
                if (replacement == nullptr) {
                    index += 3;
                    continue;
                }
                if (__s("%") == replacement) {
                    replacement = __s("%25");
                    sourceLength = 1;
                } else {
                    sourceLength = 3;
                }
            } else {
                if (charValue == _BACKSLASH && replaceBackslash) {
                replacement = __s("/");
                sourceLength = 1;
            } else {
                if (!escapeDelimiters && _isGeneralDelimiter(charValue)) {
                _fail(component, index, __s("Invalid character"));
                throw __s("unreachable");
            } else {
                sourceLength = 1;
                if ((charValue & 0xFC00) == 0xD800) {
                    if (index + 1 < end) {
                        int tail = component->codeUnitAt(index + 1);
                        if ((tail & 0xFC00) == 0xDC00) {
                            sourceLength = 2;
                            charValue = 0x10000 | ((charValue & 0x3ff) << 10) | (tail & 0x3ff);
                        }
                    }
                }
                replacement = _escapeChar(charValue);
            }
;
            };
            }                    auto _c1 = (buffer ??= make<StringBufferCls>());        _c1.auto _c2 = write(component->substring(sectionStart, index));        _c2.write(replacement);        _c2;_c1;
            index += sourceLength;
            sectionStart = index;
        }
    }
    if (buffer == nullptr) {
        return nullptr;
    }
    if ( < end) {
        buffer->write(component->substring(sectionStart, end));
    }
    return buffer->toString();
}

bool _UriCls::_isSchemeCharacter(int ch) {
    return  < 128 && ((_schemeTable[ch >> 4] & (1 << (ch & 0x0f))) != 0);
}

bool _UriCls::_isGeneralDelimiter(int ch) {
    return ch <= _RIGHT_BRACKET && ((_genDelimitersTable[ch >> 4] & (1 << (ch & 0x0f))) != 0);
}

String _UriCls::_mergePaths(String base, String reference) {
    int backCount = 0;
    int refStart = 0;
    while (reference->startsWith(__s("../"), refStart)) {
        refStart += 3;
        backCount++;
    }
    int baseEnd = base->lastIndexOf(__s("/"));
    while (baseEnd > 0 && backCount > 0) {
        int newEnd = base->lastIndexOf(__s("/"), baseEnd - 1);
        if ( < 0) {
            break;
        }
        int delta = baseEnd - newEnd;
        if ((delta == 2 || delta == 3) && base->codeUnitAt(newEnd + 1) == _DOT && (delta == 2 || base->codeUnitAt(newEnd + 2) == _DOT)) {
            break;
        }
        baseEnd = newEnd;
        backCount--;
    }
    return base->replaceRange(baseEnd + 1, nullptr, reference->substring(refStart - 3 * backCount));
}

bool _UriCls::_mayContainDotSegments(String path) {
    if (path->startsWith(__s("."))) {
        return true;
    }
    int index = path->indexOf(__s("/."));
    return index != -1;
}

String _UriCls::_removeDotSegments(String path) {
    if (!_mayContainDotSegments(path)) {
        return path;
    }
    assert(path->isNotEmpty());
    List<String> output = makeList();
    bool appendSlash = false;
    for (String segment : path->split(__s("/"))) {
        appendSlash = false;
        if (segment == __s("..")) {
            if (output->isNotEmpty()) {
                output->removeLast();
                if (output->isEmpty()) {
                    output->add(__s(""));
                }
            }
            appendSlash = true;
        } else {
            if (__s(".") == segment) {
            appendSlash = true;
        } else {
            output->add(segment);
        }
;
        }    }
    if (appendSlash) {
        output->add(__s(""));
    }
    return output->join(__s("/"));
}

String _UriCls::_normalizeRelativePath(String path, bool allowScheme) {
    assert(!path->startsWith(__s("/")));
    if (!_mayContainDotSegments(path)) {
        if (!allowScheme) {
            path = _escapeScheme(path);
        }
        return path;
    }
    assert(path->isNotEmpty());
    List<String> output = makeList();
    bool appendSlash = false;
    for (String segment : path->split(__s("/"))) {
        appendSlash = false;
        if (__s("..") == segment) {
            if (!output->isEmpty() && output->last != __s("..")) {
                output->removeLast();
                appendSlash = true;
            } else {
                output->add(__s(".."));
            }
        } else {
            if (__s(".") == segment) {
            appendSlash = true;
        } else {
            output->add(segment);
        }
;
        }    }
    if (output->isEmpty() || (output->length() == 1 && output[0]->isEmpty())) {
        return __s("./");
    }
    if (appendSlash || output->last == __s("..")) {
        output->add(__s(""));
    }
    if (!allowScheme) {
        output[0] = _escapeScheme(output[0]);
    }
    return output->join(__s("/"));
}

String _UriCls::_escapeScheme(String path) {
    if (path->length() >= 2 && _isAlphabeticCharacter(path->codeUnitAt(0))) {
        for (;  < path->length(); i++) {
            int char = path->codeUnitAt(i);
            if (charValue == _COLON) {
                return __s("%s$%s;");
            }
            if (charValue > 127 || ((_schemeTable[charValue >> 4] & (1 << (charValue & 0x0f))) == 0)) {
                break;
            }
        }
    }
    return path;
}

int _UriCls::_packageNameEnd(Uri uri, String path) {
    if (uri->isScheme(__s("package")) && !uri->hasAuthority()) {
        return _skipPackageNameChars(path, 0, path->length());
    }
    return -1;
}

String _UriCls::_toFilePath() {
    if (hasAuthority() && host() != __s("")) {
        throw make<UnsupportedErrorCls>(__s("Cannot extract a non-Windows file path from a file URI with an authority"));
    }
    auto pathSegments = this->pathSegments;
    _checkNonWindowsPathReservedCharacters(pathSegments, false);
    auto result = make<StringBufferCls>();
    if (hasAbsolutePath()) {
        result->write(__s("/"));
    }
    result->writeAll(pathSegments, __s("/"));
    return result->toString();
}

String _UriCls::_toWindowsFilePath(Uri uri) {
    bool hasDriveLetter = false;
    auto segments = uri->pathSegments();
    if (segments->length() > 0 && segments[0]->length() == 2 && segments[0]->codeUnitAt(1) == _COLON) {
        _checkWindowsDriveLetter(segments[0]->codeUnitAt(0), false);
        _checkWindowsPathReservedCharacters(segments, false, 1);
        hasDriveLetter = true;
    } else {
        _checkWindowsPathReservedCharacters(segments, false, 0);
    }
    auto result = make<StringBufferCls>();
    if (uri->hasAbsolutePath() && !hasDriveLetter) {
        result->write(__s("\"));
    }
    if (uri->hasAuthority()) {
        auto host = uri->host();
        if (host->isNotEmpty()) {
            result->write(__s("\"));
            result->write(host);
            result->write(__s("\"));
        }
    }
    result->writeAll(segments, __s("\"));
    if (hasDriveLetter && segments->length() == 1) {
        result->write(__s("\"));
    }
    return result->toString();
}

void _UriCls::_writeAuthority(StringSink ss) {
    if (_userInfo->isNotEmpty()) {
        ss->write(_userInfo);
        ss->write(__s("@"));
    }
    if (_host != nullptr) {
        ss->write(_host);
    }
    if (_port != nullptr) {
        ss->write(__s(":"));
        ss->write(_port);
    }
}

String _UriCls::_initializeText() {
    StringBuffer sb = make<StringBufferCls>();
    auto _c1 = sb;_c1.auto _c2 = write(scheme);_c2.write(__s(":"));_c2;if (scheme->isNotEmpty()) {
        _c1;
    }
    if (hasAuthority() || (scheme == __s("file"))) {
        sb->write(__s("//"));
        _writeAuthority(sb);
    }
    sb->write(path);
    auto _c3 = sb;_c3.auto _c4 = write(__s("?"));_c4.write(_query);_c4;if (_query != nullptr) {
        _c3;
    }
    auto _c5 = sb;_c5.auto _c6 = write(__s("#"));_c6.write(_fragment);_c6;if (_fragment != nullptr) {
        _c5;
    }
    return sb->toString();
}

List<String> _UriCls::_createList() {
    return makeList();
}

Map<String, List<String>> _UriCls::_splitQueryStringAll(String query, Encoding encoding) {
    auto result = makeMap(makeList(), makeList();
    int i = 0;
    int start = 0;
    int equalsIndex = -1;
    InlineMethod;
    while ( < query->length()) {
        int char = query->codeUnitAt(i);
        if (charValue == _EQUALS) {
            if ( < 0) {
                equalsIndex = i;
            }
        } else {
            if (charValue == _AMPERSAND) {
            parsePair(start, equalsIndex, i);
            start = i + 1;
            equalsIndex = -1;
        }
;
        }        i++;
    }
    parsePair(start, equalsIndex, i);
    return result;
}

int _UriCls::_hexCharPairToByte(String s, int pos) {
    int byte = 0;
    for (;  < 2; i++) {
        auto charCode = s->codeUnitAt(pos + i);
        if (0x30 <= charCode && charCode <= 0x39) {
            byte = byte * 16 + charCode - 0x30;
        } else {
            charCode |= 0x20;
            if (0x61 <= charCode && charCode <= 0x66) {
                byte = byte * 16 + charCode - 0x57;
            } else {
                throw make<ArgumentErrorCls>(__s("Invalid URL encoding"));
            }
        }
    }
    return byte;
}

String _UriCls::_uriDecode(String text, int start, int end, Encoding encoding, bool plusToSpace) {
    assert(0 <= start);
    assert(start <= end);
    assert(end <= text->length());
    bool simple = true;
    for (;  < end; i++) {
        auto codeUnit = text->codeUnitAt(i);
        if (codeUnit > 127 || codeUnit == _PERCENT || (plusToSpace && codeUnit == _PLUS)) {
            simple = false;
            break;
        }
    }
    List<int> bytes;
    if (simple) {
        if (utf8 == encoding || latin1 == encoding || ascii == encoding) {
            return text->substring(start, end);
        } else {
            bytes = text->substring(start, end)->codeUnits();
        }
    } else {
        bytes = makeList();
        for (;  < end; i++) {
            auto codeUnit = text->codeUnitAt(i);
            if (codeUnit > 127) {
                throw make<ArgumentErrorCls>(__s("Illegal percent encoding in URI"));
            }
            if (codeUnit == _PERCENT) {
                if (i + 3 > text->length()) {
                    throw make<ArgumentErrorCls>(__s("Truncated URI"));
                }
                bytes->add(_hexCharPairToByte(text, i + 1));
                i += 2;
            } else {
                if (plusToSpace && codeUnit == _PLUS) {
                bytes->add(_SPACE);
            } else {
                bytes->add(codeUnit);
            }
;
            }        }
    }
    return encoding->decode(bytes);
}

bool _UriCls::_isAlphabeticCharacter(int codeUnit) {
    auto lowerCase = codeUnit | 0x20;
    return (_LOWER_CASE_A <= lowerCase && lowerCase <= _LOWER_CASE_Z);
}

bool _UriCls::_isUnreservedChar(int charValue) {
    return  < 127 && ((_unreservedTable[charValue >> 4] & (1 << (charValue & 0x0f))) != 0);
}

void UriDataCls::fromString(String content, bool base64, Encoding encoding, String mimeType, Map<String, String> parameters) {
    StringBuffer buffer = make<StringBufferCls>();
    List<int> indices = makeList(ArrayItem);
    String charsetName = parameters?[__s("charset")];
    String encodingName;
    if (encoding == nullptr) {
        if (charsetName != nullptr) {
            encoding = EncodingCls->getByName(charsetName);
        }
    } else {
        if (charsetName == nullptr) {
        encodingName = encoding->name();
    }
;
    }    encoding |= ascii;
    _writeUri(mimeType, encodingName, parameters, buffer, indices);
    indices->add(buffer->length());
    if (base64) {
        buffer->write(__s(";base64,"));
        indices->add(buffer->length() - 1);
        buffer->write(encoding->fuse(_base64)->encode(content));
    } else {
        buffer->write(__s(","));
        _uriEncodeBytes(_uricTable, encoding->encode(content), buffer);
    }
    return UriDataCls->_(buffer->toString(), indices, nullptr);
}

void UriDataCls::fromBytes(List<int> bytes, String mimeType, Map<String, String> parameters, bool percentEncoded) {
    StringBuffer buffer = make<StringBufferCls>();
    List<int> indices = makeList(ArrayItem);
    _writeUri(mimeType, nullptr, parameters, buffer, indices);
    indices->add(buffer->length());
    if (percentEncoded) {
        buffer->write(__s(","));
        _uriEncodeBytes(_uricTable, bytes, buffer);
    } else {
        buffer->write(__s(";base64,"));
        indices->add(buffer->length() - 1);
        _base64->encoder()->startChunkedConversion(StringConversionSinkCls->fromStringSink(buffer))->addSlice(bytes, 0, bytes->length(), true);
    }
    return UriDataCls->_(buffer->toString(), indices, nullptr);
}

void UriDataCls::fromUri(Uri uri) {
    if (!uri->isScheme(__s("data"))) {
        throw ArgumentErrorCls->value(uri, __s("uri"), __s("Scheme must be 'data'"));
    }
    if (uri->hasAuthority()) {
        throw ArgumentErrorCls->value(uri, __s("uri"), __s("Data uri must not have authority"));
    }
    if (uri->hasFragment()) {
        throw ArgumentErrorCls->value(uri, __s("uri"), __s("Data uri must not have a fragment part"));
    }
    if (!uri->hasQuery()) {
        return _parse(uri->path(), 0, uri);
    }
    return _parse(uri->toString(), 5, uri);
}

UriData UriDataCls::parse(String uri) {
    if (uri->length() >= 5) {
        int dataDelta = _startsWithData(uri, 0);
        if (dataDelta == 0) {
            return _parse(uri, 5, nullptr);
        }
        if (dataDelta == 0x20) {
            return _parse(uri->substring(5), 0, nullptr);
        }
    }
    throw make<FormatExceptionCls>(__s("Does not start with 'data:'"), uri, 0);
}

Uri UriDataCls::uri() {
    return _uriCache ??= _computeUri();
}

String UriDataCls::mimeType() {
    int start = _separatorIndices[0] + 1;
    int end = _separatorIndices[1];
    if (start == end) {
        return __s("text/plain");
    }
    return _UriCls->_uriDecode(_text, start, end, utf8, false);
}

bool UriDataCls::isMimeType(String mimeType) {
    int start = _separatorIndices[0] + 1;
    int end = _separatorIndices[1];
    if (start == end) {
        return mimeType->isEmpty() || identical(mimeType, __s("text/plain")) || _caseInsensitiveEquals(mimeType, __s("text/plain"));
    }
    if (mimeType->isEmpty()) {
        mimeType = __s("text/plain");
    }
    return (mimeType->length() == end - start) && _caseInsensitiveStartsWith(mimeType, _text, start);
}

String UriDataCls::charset() {
    auto charsetIndex = _findCharsetIndex();
    if (charsetIndex >= 0) {
        auto valueStart = _separatorIndices[charsetIndex + 1] + 1;
        auto valueEnd = _separatorIndices[charsetIndex + 2];
        return _UriCls->_uriDecode(_text, valueStart, valueEnd, utf8, false);
    }
    return __s("US-ASCII");
}

bool UriDataCls::isCharset(String charset) {
    auto charsetIndex = _findCharsetIndex();
    if ( < 0) {
        return charset->isEmpty() || _caseInsensitiveEquals(charset, __s("US-ASCII")) || identical(EncodingCls->getByName(charset), ascii);
    }
    if (charset->isEmpty()) {
        charset = __s("US-ASCII");
    }
    auto valueStart = _separatorIndices[charsetIndex + 1] + 1;
    auto valueEnd = _separatorIndices[charsetIndex + 2];
    auto length = valueEnd - valueStart;
    if (charset->length == length && _caseInsensitiveStartsWith(charset, _text, valueStart)) {
        return true;
    }
    auto checkedEncoding = EncodingCls->getByName(charset);
    return checkedEncoding != nullptr && identical(checkedEncoding, EncodingCls->getByName(_UriCls->_uriDecode(_text, valueStart, valueEnd, utf8, false)));
}

bool UriDataCls::isEncoding(Encoding encoding) {
    auto charsetIndex = _findCharsetIndex();
    if ( < 0) {
        return identical(encoding, ascii);
    }
    auto valueStart = _separatorIndices[charsetIndex + 1] + 1;
    auto valueEnd = _separatorIndices[charsetIndex + 2];
    return identical(encoding, EncodingCls->getByName(_UriCls->_uriDecode(_text, valueStart, valueEnd, utf8, false)));
}

bool UriDataCls::isBase64() {
    return _separatorIndices->length()->isOdd();
}

String UriDataCls::contentText() {
    return _text->substring(_separatorIndices->last + 1);
}

Uint8List UriDataCls::contentAsBytes() {
    String text = _text;
    int start = _separatorIndices->last + 1;
    if (isBase64()) {
        return base64->decoder->convert(text, start);
    }
    int percent = 0x25;
    int length = text->length() - start;
    for (;  < text->length; i++) {
        auto codeUnit = text->codeUnitAt(i);
        if (codeUnit == percent) {
            i += 2;
            length -= 2;
        }
    }
    Uint8List result = make<Uint8ListCls>(length);
    if (length == text->length) {
        result->setRange(0, length, text->codeUnits(), start);
        return result;
    }
    int index = 0;
    for (;  < text->length; i++) {
        auto codeUnit = text->codeUnitAt(i);
        if (codeUnit != percent) {
            result[index++] = codeUnit;
        } else {
            if (i + 2 < text->length) {
                int byte = parseHexByte(text, i + 1);
                if (byte >= 0) {
                    result[index++] = byte;
                    i += 2;
                    continue;
                }
            }
            throw make<FormatExceptionCls>(__s("Invalid percent escape"), text, i);
        }
    }
    assert(index == result->length);
    return result;
}

String UriDataCls::contentAsString(Encoding encoding) {
    if (encoding == nullptr) {
        auto charset = this->charset();
        encoding = EncodingCls->getByName(charset);
        if (encoding == nullptr) {
            throw make<UnsupportedErrorCls>(__s("Unknown charset: %s)"));
        }
    }
    String text = _text;
    int start = _separatorIndices->last + 1;
    if (isBase64()) {
        auto converter = base64->decoder->fuse(encoding->decoder());
        return converter->convert(text->substring(start));
    }
    return _UriCls->_uriDecode(text, start, text->length(), encoding, false);
}

Map<String, String> UriDataCls::parameters() {
    auto result = makeMap(makeList(), makeList();
    for (;  < _separatorIndices->length(); i += 2) {
        auto start = _separatorIndices[i - 2] + 1;
        auto equals = _separatorIndices[i - 1];
        auto end = _separatorIndices[i];
        String key = _UriCls->_uriDecode(_text, start, equals, utf8, false);
        String value = _UriCls->_uriDecode(_text, equals + 1, end, utf8, false);
        result[key] = value;
    }
    return result;
}

String UriDataCls::toString() {
    return (_separatorIndices[0] == _noScheme)? __s("data:%s:") : _text;
}

void UriDataCls::_writeUri(String mimeType, String charsetName, Map<String, String> parameters, StringBuffer buffer, List<int> indices) {
    if (mimeType == nullptr || _caseInsensitiveEquals(__s("text/plain"), mimeType)) {
        mimeType = __s("");
    }
    if (mimeType->isEmpty() || identical(mimeType, __s("application/octet-stream"))) {
        buffer->write(mimeType);
    } else {
        int slashIndex = _validateMimeType(mimeType);
        if ( < 0) {
            throw ArgumentErrorCls->value(mimeType, __s("mimeType"), __s("Invalid MIME type"));
        }
        buffer->write(_UriCls->_uriEncode(_tokenCharTable, mimeType->substring(0, slashIndex), utf8, false));
        buffer->write(__s("/"));
        buffer->write(_UriCls->_uriEncode(_tokenCharTable, mimeType->substring(slashIndex + 1), utf8, false));
    }
    if (charsetName != nullptr) {
            auto _c1 = indices;    _c1.auto _c2 = add(buffer->length());    _c2.add(buffer->length() + 8);    _c2;_c1;
        buffer->write(__s(";charset="));
        buffer->write(_UriCls->_uriEncode(_tokenCharTable, charsetName, utf8, false));
    }
    parameters?->forEach([=] (Unknown  key,Unknown  value) {
        if (key->isEmpty) {
            throw ArgumentErrorCls->value(__s(""), __s("Parameter names must not be empty"));
        }
        if (value->isEmpty) {
            throw ArgumentErrorCls->value(__s(""), __s("Parameter values must not be empty"), __s("parameters["%s)"));
        }
        indices?->add(buffer->length());
        buffer->write(__s(";"));
        buffer->write(_UriCls->_uriEncode(_tokenCharTable, key, utf8, false));
        indices?->add(buffer->length());
        buffer->write(__s("="));
        buffer->write(_UriCls->_uriEncode(_tokenCharTable, value, utf8, false));
    });
}

int UriDataCls::_validateMimeType(String mimeType) {
    int slashIndex = -1;
    for (;  < mimeType->length(); i++) {
        auto char = mimeType->codeUnitAt(i);
        if (charValue != _SLASH) {
            continue;
        }
        if ( < 0) {
            slashIndex = i;
            continue;
        }
        return -1;
    }
    return slashIndex;
}

Uri UriDataCls::_computeUri() {
    String path = _text;
    String query;
    int colonIndex = _separatorIndices[0];
    int queryIndex = _text->indexOf(__s("?"), colonIndex + 1);
    int end = _text->length();
    if (queryIndex >= 0) {
        query = _UriCls->_normalizeOrSubstring(_text, queryIndex + 1, end, _UriCls::_queryCharTable);
        end = queryIndex;
    }
    path = _UriCls->_normalizeOrSubstring(_text, colonIndex + 1, end, _UriCls::_pathCharOrSlashTable);
    return make<_DataUriCls>(this, path, query);
}

int UriDataCls::_findCharsetIndex() {
    auto separatorIndices = _separatorIndices;
    for (; i <= separatorIndices->length(); i += 2) {
        auto keyStart = separatorIndices[i - 2] + 1;
        auto keyEnd = separatorIndices[i - 1];
        if (keyEnd == keyStart + __s("charset")->length() && _caseInsensitiveStartsWith(__s("charset"), _text, keyStart)) {
            return i - 2;
        }
    }
    return -1;
}

UriData UriDataCls::_parse(String text, int start, Uri sourceUri) {
    assert(start == 0 || start == 5);
    assert((start == 5) == text->startsWith(__s("data:")));
    int comma = 0x2c;
    int slash = 0x2f;
    int semicolon = 0x3b;
    int equals = 0x3d;
    List<int> indices = makeList(ArrayItem);
    int slashIndex = -1;
    auto char;
    int i = start;
    for (;  < text->length(); i++) {
        charValue = text->codeUnitAt(i);
        if (charValue == comma || charValue == semicolon) {
            break;
        }
        if (charValue == slash) {
            if ( < 0) {
                slashIndex = i;
                continue;
            }
            throw make<FormatExceptionCls>(__s("Invalid MIME type"), text, i);
        }
    }
    if ( < 0 && i > start) {
        throw make<FormatExceptionCls>(__s("Invalid MIME type"), text, i);
    }
    while (charValue != comma) {
        indices->add(i);
        i++;
        int equalsIndex = -1;
        for (;  < text->length(); i++) {
            charValue = text->codeUnitAt(i);
            if (charValue == equals) {
                if ( < 0) {
                    equalsIndex = i;
                }
            } else {
                if (charValue == semicolon || charValue == comma) {
                break;
            }
;
            }        }
        if (equalsIndex >= 0) {
            indices->add(equalsIndex);
        } else {
            auto lastSeparator = indices->last;
            if (charValue != comma || i != lastSeparator + 7 || !text->startsWith(__s("base64"), lastSeparator + 1)) {
                throw make<FormatExceptionCls>(__s("Expecting '='"), text, i);
            }
            break;
        }
    }
    indices->add(i);
    bool isBase64 = indices->length()->isOdd();
    if (isBase64) {
        text = base64->normalize(text, i + 1, text->length());
    } else {
        auto data = _UriCls->_normalize(text, i + 1, text->length(), _uricTable, true);
        if (data != nullptr) {
            text = text->replaceRange(i + 1, text->length(), data);
        }
    }
    return UriDataCls->_(text, indices, sourceUri);
}

void UriDataCls::_uriEncodeBytes(List<int> canonicalTable, List<int> bytes, StringSink buffer) {
    int byteOr = 0;
    for (;  < bytes->length(); i++) {
        int byte = bytes[i];
        byteOr |= byte;
        if ( < 128 && ((canonicalTable[byte >> 4] & (1 << (byte & 0x0f))) != 0)) {
            buffer->writeCharCode(byte);
        } else {
            buffer->writeCharCode(_PERCENT);
            buffer->writeCharCode(_hexDigits->codeUnitAt(byte >> 4));
            buffer->writeCharCode(_hexDigits->codeUnitAt(byte & 0x0f));
        }
    }
    if ((byteOr & ~0xFF) != 0) {
        for (;  < bytes->length(); i++) {
            auto byte = bytes[i];
            if ( < 0 || byte > 255) {
                throw ArgumentErrorCls->value(byte, __s("non-byte value"));
            }
        }
    }
}

List<Uint8List> _createTables() {
    int stateCount = 22;
    int schemeOrPath = 1;
    int authOrPath = 2;
    int authOrPathSlash = 3;
    int uinfoOrHost0 = 4;
    int uinfoOrHost = 5;
    int uinfoOrPort0 = 6;
    int uinfoOrPort = 7;
    int ipv6Host = 8;
    int relPathSeg = 9;
    int pathSeg = 10;
    int path = 11;
    int query = 12;
    int fragment = 13;
    int schemeOrPathDot = 14;
    int schemeOrPathDot2 = 15;
    int relPathSegDot = 16;
    int relPathSegDot2 = 17;
    int pathSegDot = 18;
    int pathSegDot2 = 19;
    int scheme0 = _schemeStart;
    int scheme = 21;
    int schemeEnd = _schemeEndIndex << 5;
    int hostStart = _hostStartIndex << 5;
    int portStart = _portStartIndex << 5;
    int pathStart = _pathStartIndex << 5;
    int queryStart = _queryStartIndex << 5;
    int fragmentStart = _fragmentStartIndex << 5;
    int notSimple = _notSimpleIndex << 5;
    unreserved = __s("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-._~");
    subDelims = __s("!$&'()*+,;=");
    pchar = __s("%s$%s;");
    auto tables = <Uint8List>generate(stateCount, [=] (Unknown  _) {
    make<Uint8ListCls>(96);
});
    InlineMethod;
    InlineMethod;
    InlineMethod;
    auto b;
    b = build(_uriStart, schemeOrPath | notSimple);
    setChars(b, pchar, schemeOrPath);
    setChars(b, __s("."), schemeOrPathDot);
    setChars(b, __s(":"), authOrPath | schemeEnd);
    setChars(b, __s("/"), authOrPathSlash);
    setChars(b, __s("\"), authOrPathSlash | notSimple);
    setChars(b, __s("?"), query | queryStart);
    setChars(b, __s("#"), fragment | fragmentStart);
    b = build(schemeOrPathDot, schemeOrPath | notSimple);
    setChars(b, pchar, schemeOrPath);
    setChars(b, __s("."), schemeOrPathDot2);
    setChars(b, __s(":"), authOrPath | schemeEnd);
    setChars(b, __s("/\"), pathSeg | notSimple);
    setChars(b, __s("?"), query | queryStart);
    setChars(b, __s("#"), fragment | fragmentStart);
    b = build(schemeOrPathDot2, schemeOrPath | notSimple);
    setChars(b, pchar, schemeOrPath);
    setChars(b, __s("%"), schemeOrPath | notSimple);
    setChars(b, __s(":"), authOrPath | schemeEnd);
    setChars(b, __s("/"), relPathSeg);
    setChars(b, __s("\"), relPathSeg | notSimple);
    setChars(b, __s("?"), query | queryStart);
    setChars(b, __s("#"), fragment | fragmentStart);
    b = build(schemeOrPath, schemeOrPath | notSimple);
    setChars(b, pchar, schemeOrPath);
    setChars(b, __s(":"), authOrPath | schemeEnd);
    setChars(b, __s("/"), pathSeg);
    setChars(b, __s("\"), pathSeg | notSimple);
    setChars(b, __s("?"), query | queryStart);
    setChars(b, __s("#"), fragment | fragmentStart);
    b = build(authOrPath, path | notSimple);
    setChars(b, pchar, path | pathStart);
    setChars(b, __s("/"), authOrPathSlash | pathStart);
    setChars(b, __s("\"), authOrPathSlash | pathStart);
    setChars(b, __s("."), pathSegDot | pathStart);
    setChars(b, __s("?"), query | queryStart);
    setChars(b, __s("#"), fragment | fragmentStart);
    b = build(authOrPathSlash, path | notSimple);
    setChars(b, pchar, path);
    setChars(b, __s("/"), uinfoOrHost0 | hostStart);
    setChars(b, __s("\"), uinfoOrHost0 | hostStart);
    setChars(b, __s("."), pathSegDot);
    setChars(b, __s("?"), query | queryStart);
    setChars(b, __s("#"), fragment | fragmentStart);
    b = build(uinfoOrHost0, uinfoOrHost | notSimple);
    setChars(b, pchar, uinfoOrHost);
    setRange(b, __s("AZ"), uinfoOrHost | notSimple);
    setChars(b, __s(":"), uinfoOrPort0 | portStart);
    setChars(b, __s("@"), uinfoOrHost0 | hostStart);
    setChars(b, __s("["), ipv6Host | notSimple);
    setChars(b, __s("/"), pathSeg | pathStart);
    setChars(b, __s("\"), pathSeg | pathStart);
    setChars(b, __s("?"), query | queryStart);
    setChars(b, __s("#"), fragment | fragmentStart);
    b = build(uinfoOrHost, uinfoOrHost | notSimple);
    setChars(b, pchar, uinfoOrHost);
    setRange(b, __s("AZ"), uinfoOrHost | notSimple);
    setChars(b, __s(":"), uinfoOrPort0 | portStart);
    setChars(b, __s("@"), uinfoOrHost0 | hostStart);
    setChars(b, __s("/"), pathSeg | pathStart);
    setChars(b, __s("\"), pathSeg | pathStart);
    setChars(b, __s("?"), query | queryStart);
    setChars(b, __s("#"), fragment | fragmentStart);
    b = build(uinfoOrPort0, uinfoOrPort | notSimple);
    setRange(b, __s("19"), uinfoOrPort);
    setChars(b, __s("@"), uinfoOrHost0 | hostStart);
    setChars(b, __s("/"), pathSeg | pathStart);
    setChars(b, __s("\"), pathSeg | pathStart);
    setChars(b, __s("?"), query | queryStart);
    setChars(b, __s("#"), fragment | fragmentStart);
    b = build(uinfoOrPort, uinfoOrPort | notSimple);
    setRange(b, __s("09"), uinfoOrPort);
    setChars(b, __s("@"), uinfoOrHost0 | hostStart);
    setChars(b, __s("/"), pathSeg | pathStart);
    setChars(b, __s("\"), pathSeg | pathStart);
    setChars(b, __s("?"), query | queryStart);
    setChars(b, __s("#"), fragment | fragmentStart);
    b = build(ipv6Host, ipv6Host);
    setChars(b, __s("]"), uinfoOrHost);
    b = build(relPathSeg, path | notSimple);
    setChars(b, pchar, path);
    setChars(b, __s("."), relPathSegDot);
    setChars(b, __s("/\"), pathSeg | notSimple);
    setChars(b, __s("?"), query | queryStart);
    setChars(b, __s("#"), fragment | fragmentStart);
    b = build(relPathSegDot, path | notSimple);
    setChars(b, pchar, path);
    setChars(b, __s("."), relPathSegDot2);
    setChars(b, __s("/\"), pathSeg | notSimple);
    setChars(b, __s("?"), query | queryStart);
    setChars(b, __s("#"), fragment | fragmentStart);
    b = build(relPathSegDot2, path | notSimple);
    setChars(b, pchar, path);
    setChars(b, __s("/"), relPathSeg);
    setChars(b, __s("\"), relPathSeg | notSimple);
    setChars(b, __s("?"), query | queryStart);
    setChars(b, __s("#"), fragment | fragmentStart);
    b = build(pathSeg, path | notSimple);
    setChars(b, pchar, path);
    setChars(b, __s("."), pathSegDot);
    setChars(b, __s("/\"), pathSeg | notSimple);
    setChars(b, __s("?"), query | queryStart);
    setChars(b, __s("#"), fragment | fragmentStart);
    b = build(pathSegDot, path | notSimple);
    setChars(b, pchar, path);
    setChars(b, __s("."), pathSegDot2);
    setChars(b, __s("/\"), pathSeg | notSimple);
    setChars(b, __s("?"), query | queryStart);
    setChars(b, __s("#"), fragment | fragmentStart);
    b = build(pathSegDot2, path | notSimple);
    setChars(b, pchar, path);
    setChars(b, __s("/\"), pathSeg | notSimple);
    setChars(b, __s("?"), query | queryStart);
    setChars(b, __s("#"), fragment | fragmentStart);
    b = build(path, path | notSimple);
    setChars(b, pchar, path);
    setChars(b, __s("/"), pathSeg);
    setChars(b, __s("/\"), pathSeg | notSimple);
    setChars(b, __s("?"), query | queryStart);
    setChars(b, __s("#"), fragment | fragmentStart);
    b = build(query, query | notSimple);
    setChars(b, pchar, query);
    setChars(b, __s("?"), query);
    setChars(b, __s("#"), fragment | fragmentStart);
    b = build(fragment, fragment | notSimple);
    setChars(b, pchar, fragment);
    setChars(b, __s("?"), fragment);
    b = build(scheme0, scheme | notSimple);
    setRange(b, __s("az"), scheme);
    b = build(scheme, scheme | notSimple);
    setRange(b, __s("az"), scheme);
    setRange(b, __s("09"), scheme);
    setChars(b, __s("+-."), scheme);
    return tables;
}

int _scan(String uri, int start, int end, int state, List<int> indices) {
    auto tables = _scannerTables;
    assert(end <= uri->length());
    for (;  < end; i++) {
        auto table = tables[state];
        int char = uri->codeUnitAt(i) ^ 0x60;
        if (charValue > 0x5f) {
            charValue = 0x1f;
        }
        int transition = table[charValue];
        state = transition & 0x1f;
        indices[transition >> 5] = i;
    }
    return state;
}

bool _SimpleUriCls::hasScheme() {
    return _schemeEnd > 0;
}

bool _SimpleUriCls::hasAuthority() {
    return _hostStart > 0;
}

bool _SimpleUriCls::hasUserInfo() {
    return _hostStart > _schemeEnd + 4;
}

bool _SimpleUriCls::hasPort() {
    return _hostStart > 0 && _portStart + 1 < _pathStart;
}

bool _SimpleUriCls::hasQuery() {
    return  < _fragmentStart;
}

bool _SimpleUriCls::hasFragment() {
    return  < _uri->length();
}

bool _SimpleUriCls::hasAbsolutePath() {
    return _uri->startsWith(__s("/"), _pathStart);
}

bool _SimpleUriCls::hasEmptyPath() {
    return _pathStart == _queryStart;
}

bool _SimpleUriCls::isAbsolute() {
    return hasScheme() && !hasFragment();
}

bool _SimpleUriCls::isScheme(String scheme) {
    if (scheme == nullptr || scheme->isEmpty()) {
        return  < 0;
    }
    if (scheme->length() != _schemeEnd) {
        return false;
    }
    return _caseInsensitiveStartsWith(scheme, _uri, 0);
}

String _SimpleUriCls::scheme() {
    return _schemeCache ??= _computeScheme();
}

String _SimpleUriCls::authority() {
    return _hostStart > 0? _uri->substring(_schemeEnd + 3, _pathStart) : __s("");
}

String _SimpleUriCls::userInfo() {
    return (_hostStart > _schemeEnd + 3)? _uri->substring(_schemeEnd + 3, _hostStart - 1) : __s("");
}

String _SimpleUriCls::host() {
    return _hostStart > 0? _uri->substring(_hostStart, _portStart) : __s("");
}

int _SimpleUriCls::port() {
    if (hasPort()) {
        return intValue->parse(_uri->substring(_portStart + 1, _pathStart));
    }
    if (_isHttp()) {
        return 80;
    }
    if (_isHttps()) {
        return 443;
    }
    return 0;
}

String _SimpleUriCls::path() {
    return _uri->substring(_pathStart, _queryStart);
}

String _SimpleUriCls::query() {
    return ( < _fragmentStart)? _uri->substring(_queryStart + 1, _fragmentStart) : __s("");
}

String _SimpleUriCls::fragment() {
    return ( < _uri->length())? _uri->substring(_fragmentStart + 1) : __s("");
}

String _SimpleUriCls::origin() {
    bool isHttp = _isHttp();
    if ( < 0) {
        throw make<StateErrorCls>(__s("Cannot use origin without a scheme: %s)"));
    }
    if (!isHttp && !_isHttps()) {
        throw make<StateErrorCls>(__s("Origin is only applicable to schemes http and https: %s)"));
    }
    if (_hostStart == _portStart) {
        throw make<StateErrorCls>(__s("A %s$%s)"));
    }
    if (_hostStart == _schemeEnd + 3) {
        return _uri->substring(0, _pathStart);
    }
    return _uri->substring(0, _schemeEnd + 3) + _uri->substring(_hostStart, _pathStart);
}

List<String> _SimpleUriCls::pathSegments() {
    int start = _pathStart;
    int end = _queryStart;
    if (_uri->startsWith(__s("/"), start)) {
        start++;
    }
    if (start == end) {
        return makeList();
    }
    List<String> parts = makeList();
    for (;  < end; i++) {
        auto char = _uri->codeUnitAt(i);
        if (charValue == _SLASH) {
            parts->add(_uri->substring(start, i));
            start = i + 1;
        }
    }
    parts->add(_uri->substring(start, end));
    return <String>unmodifiable(parts);
}

Map<String, String> _SimpleUriCls::queryParameters() {
    if (!hasQuery()) {
        return makeMap(makeList(), makeList();
    }
    return <String, String>make<UnmodifiableMapViewCls>(UriCls->splitQueryString(query()));
}

Map<String, List<String>> _SimpleUriCls::queryParametersAll() {
    if (!hasQuery()) {
        return makeMap(makeList(), makeList();
    }
    Map<String, List<String>> queryParameterLists = _UriCls->_splitQueryStringAll(query());
    queryParameterLists->updateAll(_toUnmodifiableStringList);
    return <String, List<String>>unmodifiable(queryParameterLists);
}

Uri _SimpleUriCls::normalizePath() {
    return this;
}

Uri _SimpleUriCls::removeFragment() {
    if (!hasFragment()) {
        return this;
    }
    return make<_SimpleUriCls>(_uri->substring(0, _fragmentStart), _schemeEnd, _hostStart, _portStart, _pathStart, _queryStart, _fragmentStart, _schemeCache);
}

Uri _SimpleUriCls::replace(String fragment, String host, String path, Iterable<String> pathSegments, int port, String query, Map<String, dynamic> queryParameters, String scheme, String userInfo) {
    bool schemeChanged = false;
    if (scheme != nullptr) {
        scheme = _UriCls->_makeScheme(scheme, 0, scheme->length());
        schemeChanged = !_isScheme(scheme);
    } else {
        scheme = this->scheme;
    }
    bool isFile = (scheme == __s("file"));
    if (userInfo != nullptr) {
        userInfo = _UriCls->_makeUserInfo(userInfo, 0, userInfo->length());
    } else {
        if (_hostStart > 0) {
        userInfo = _uri->substring(_schemeEnd + 3, _hostStart);
    } else {
        userInfo = __s("");
    }
;
    }    if (port != nullptr) {
        port = _UriCls->_makePort(port, scheme);
    } else {
        port = this->hasPort()? this->port : nullptr;
        if (schemeChanged) {
            port = _UriCls->_makePort(port, scheme);
        }
    }
    if (host != nullptr) {
        host = _UriCls->_makeHost(host, 0, host->length(), false);
    } else {
        if (_hostStart > 0) {
        host = _uri->substring(_hostStart, _portStart);
    } else {
        if (userInfo->isNotEmpty() || port != nullptr || isFile) {
        host = __s("");
    }
;
    };
    }    bool hasAuthority = host != nullptr;
    if (path != nullptr || pathSegments != nullptr) {
        path = _UriCls->_makePath(path, 0, _stringOrNullLength(path), pathSegments, scheme, hasAuthority);
    } else {
        path = _uri->substring(_pathStart, _queryStart);
        if ((isFile || (hasAuthority && !path->isEmpty())) && !path->startsWith(__s("/"))) {
            path = __s("/") + path;
        }
    }
    if (query != nullptr || queryParameters != nullptr) {
        query = _UriCls->_makeQuery(query, 0, _stringOrNullLength(query), queryParameters);
    } else {
        if ( < _fragmentStart) {
        query = _uri->substring(_queryStart + 1, _fragmentStart);
    }
;
    }    if (fragment != nullptr) {
        fragment = _UriCls->_makeFragment(fragment, 0, fragment->length());
    } else {
        if ( < _uri->length()) {
        fragment = _uri->substring(_fragmentStart + 1);
    }
;
    }    return _UriCls->_internal(scheme, userInfo, host, port, path, query, fragment);
}

Uri _SimpleUriCls::resolve(String reference) {
    return resolveUri(UriCls->parse(reference));
}

Uri _SimpleUriCls::resolveUri(Uri reference) {
    if (is<_SimpleUri>(reference)) {
        return _simpleMerge(this, as<_SimpleUriCls>(reference));
    }
    return _toNonSimple()->resolveUri(reference);
}

String _SimpleUriCls::toFilePath(bool windows) {
    if (_schemeEnd >= 0 && !_isFile()) {
        throw make<UnsupportedErrorCls>(__s("Cannot extract a file path from a %s)"));
    }
    if ( < _uri->length()) {
        if ( < _fragmentStart) {
            throw make<UnsupportedErrorCls>(__s("Cannot extract a file path from a URI with a query component"));
        }
        throw make<UnsupportedErrorCls>(__s("Cannot extract a file path from a URI with a fragment component"));
    }
    return (windows | _UriCls::_isWindows)? _UriCls->_toWindowsFilePath(this) : _toFilePath();
}

UriData _SimpleUriCls::data() {
    assert(scheme() != __s("data"));
    return nullptr;
}

int _SimpleUriCls::hashCode() {
    return _hashCodeCache ??= _uri->hashCode();
}

bool _SimpleUriCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    return is<Uri>(other) && _uri == other->toString();
}

String _SimpleUriCls::toString() {
    return _uri;
}

bool _SimpleUriCls::_isFile() {
    return _schemeEnd == 4 && _uri->startsWith(__s("file"));
}

bool _SimpleUriCls::_isHttp() {
    return _schemeEnd == 4 && _uri->startsWith(__s("http"));
}

bool _SimpleUriCls::_isHttps() {
    return _schemeEnd == 5 && _uri->startsWith(__s("https"));
}

bool _SimpleUriCls::_isPackage() {
    return _schemeEnd == 7 && _uri->startsWith(__s("package"));
}

bool _SimpleUriCls::_isScheme(String scheme) {
    return _schemeEnd == scheme->length() && _uri->startsWith(scheme);
}

String _SimpleUriCls::_computeScheme() {
    if (_schemeEnd <= 0) {
        return __s("");
    }
    if (_isHttp()) {
        return __s("http");
    }
    if (_isHttps()) {
        return __s("https");
    }
    if (_isFile()) {
        return __s("file");
    }
    if (_isPackage()) {
        return __s("package");
    }
    return _uri->substring(0, _schemeEnd);
}

bool _SimpleUriCls::_isPort(String port) {
    int portDigitStart = _portStart + 1;
    return portDigitStart + port->length() == _pathStart && _uri->startsWith(port, portDigitStart);
}

int _SimpleUriCls::_packageNameEnd(_SimpleUri uri) {
    if (uri->_isPackage() && !uri->hasAuthority()) {
        return _skipPackageNameChars(uri->_uri, uri->_pathStart, uri->_queryStart);
    }
    return -1;
}

Uri _SimpleUriCls::_simpleMerge(_SimpleUri base, _SimpleUri ref) {
    if (ref->hasScheme()) {
        return ref;
    }
    if (ref->hasAuthority()) {
        if (!base->hasScheme()) {
            return ref;
        }
        bool isSimple = true;
        if (base->_isFile()) {
            isSimple = !ref->hasEmptyPath();
        } else {
            if (base->_isHttp()) {
            isSimple = !ref->_isPort(__s("80"));
        } else {
            if (base->_isHttps()) {
            isSimple = !ref->_isPort(__s("443"));
        }
;
        };
        }        if (isSimple) {
            auto delta = base->_schemeEnd + 1;
            auto newUri = base->_uri->substring(0, base->_schemeEnd + 1) + ref->_uri->substring(ref->_schemeEnd + 1);
            return make<_SimpleUriCls>(newUri, base->_schemeEnd, ref->_hostStart + delta, ref->_portStart + delta, ref->_pathStart + delta, ref->_queryStart + delta, ref->_fragmentStart + delta, base->_schemeCache);
        } else {
            return _toNonSimple()->resolveUri(ref);
        }
    }
    if (ref->hasEmptyPath()) {
        if (ref->hasQuery()) {
            int delta = base->_queryStart - ref->_queryStart;
            auto newUri = base->_uri->substring(0, base->_queryStart) + ref->_uri->substring(ref->_queryStart);
            return make<_SimpleUriCls>(newUri, base->_schemeEnd, base->_hostStart, base->_portStart, base->_pathStart, ref->_queryStart + delta, ref->_fragmentStart + delta, base->_schemeCache);
        }
        if (ref->hasFragment()) {
            int delta = base->_fragmentStart - ref->_fragmentStart;
            auto newUri = base->_uri->substring(0, base->_fragmentStart) + ref->_uri->substring(ref->_fragmentStart);
            return make<_SimpleUriCls>(newUri, base->_schemeEnd, base->_hostStart, base->_portStart, base->_pathStart, base->_queryStart, ref->_fragmentStart + delta, base->_schemeCache);
        }
        return base->removeFragment();
    }
    if (ref->hasAbsolutePath()) {
        int basePathStart = base->_pathStart;
        int packageNameEnd = _packageNameEnd(this);
        if (packageNameEnd > 0) {
            basePathStart = packageNameEnd;
        }
        auto delta = basePathStart - ref->_pathStart;
        auto newUri = base->_uri->substring(0, basePathStart) + ref->_uri->substring(ref->_pathStart);
        return make<_SimpleUriCls>(newUri, base->_schemeEnd, base->_hostStart, base->_portStart, base->_pathStart, ref->_queryStart + delta, ref->_fragmentStart + delta, base->_schemeCache);
    }
    if (base->hasEmptyPath() && base->hasAuthority()) {
        int refStart = ref->_pathStart;
        while (ref->_uri->startsWith(__s("../"), refStart)) {
            refStart += 3;
        }
        auto delta = base->_pathStart - refStart + 1;
        auto newUri = __s("%s$%s;");
        return make<_SimpleUriCls>(newUri, base->_schemeEnd, base->_hostStart, base->_portStart, base->_pathStart, ref->_queryStart + delta, ref->_fragmentStart + delta, base->_schemeCache);
    }
    String baseUri = base->_uri;
    String refUri = ref->_uri;
    int baseStart = base->_pathStart;
    int baseEnd = base->_queryStart;
    int packageNameEnd = _packageNameEnd(this);
    if (packageNameEnd >= 0) {
        baseStart = packageNameEnd;
    } else {
        while (baseUri->startsWith(__s("../"), baseStart)) {
            baseStart += 3;
        }
    }
    int refStart = ref->_pathStart;
    int refEnd = ref->_queryStart;
    int backCount = 0;
    while (refStart + 3 <= refEnd && refUri->startsWith(__s("../"), refStart)) {
        refStart += 3;
        backCount += 1;
    }
    String insert = __s("");
    while (baseEnd > baseStart) {
        baseEnd--;
        int char = baseUri->codeUnitAt(baseEnd);
        if (charValue == _SLASH) {
            insert = __s("/");
            if (backCount == 0) {
                break;
            }
            backCount--;
        }
    }
    if (baseEnd == baseStart && !base->hasScheme() && !base->hasAbsolutePath()) {
        insert = __s("");
        refStart -= backCount * 3;
    }
    auto delta = baseEnd - refStart + insert->length();
    auto newUri = __s("%s$%s$%s;");
    return make<_SimpleUriCls>(newUri, base->_schemeEnd, base->_hostStart, base->_portStart, base->_pathStart, ref->_queryStart + delta, ref->_fragmentStart + delta, base->_schemeCache);
}

String _SimpleUriCls::_toFilePath() {
    if ( < _portStart) {
        throw make<UnsupportedErrorCls>(__s("Cannot extract a non-Windows file path from a file URI with an authority"));
    }
    return this->path();
}

Uri _SimpleUriCls::_toNonSimple() {
    return _UriCls->_internal(this->scheme(), this->userInfo(), this->hasAuthority()? this->host() : nullptr, this->hasPort()? this->port() : nullptr, this->path(), this->hasQuery()? this->query() : nullptr, this->hasFragment()? this->fragment() : nullptr);
}

UriData _DataUriCls::data() {
    return _data;
}

_DataUriCls::_DataUriCls(UriData _data, String path, String query) {
    {
        super->_internal(__s("data"), __s(""), nullptr, nullptr, path, query, nullptr);
    }
}

int _startsWithData(String text, int start) {
    int delta = (text->codeUnitAt(start + 4) ^ _COLON) * 3;
    delta |= text->codeUnitAt(start) ^ 0x64;
    delta |= text->codeUnitAt(start + 1) ^ 0x61;
    delta |= text->codeUnitAt(start + 2) ^ 0x74;
    delta |= text->codeUnitAt(start + 3) ^ 0x61;
    return delta;
}

int _stringOrNullLength(String s) {
    return (s == nullptr)? 0 : s->length();
}

List<String> _toUnmodifiableStringList(String key, List<String> list) {
    return <String>unmodifiable(list);
}

int _skipPackageNameChars(String source, int start, int end) {
    auto dots = 0;
    for (;  < end; i++) {
        auto char = source->codeUnitAt(i);
        if (charValue == _SLASH) {
            return (dots != 0)? i : -1;
        }
        if (charValue == _PERCENT || charValue == _COLON) {
            return -1;
        }
        dots |= charValue ^ _DOT;
    }
    return -1;
}

bool _caseInsensitiveStartsWith(String prefix, String stringValue, int start) {
    return _caseInsensitiveCompareStart(prefix, stringValue, start) >= 0;
}

int _caseInsensitiveCompareStart(String prefix, String stringValue, int start) {
    int result = 0;
    for (;  < prefix->length(); i++) {
        int prefixChar = prefix->codeUnitAt(i);
        int stringChar = stringValue->codeUnitAt(start + i);
        int delta = prefixChar ^ stringChar;
        if (delta != 0) {
            if (delta == 0x20) {
                int lowerChar = stringChar | delta;
                if (0x61 <= lowerChar && lowerChar <= 0x7a) {
                    result = 0x20;
                    continue;
                }
            }
            return -1;
        }
    }
    return result;
}

bool _caseInsensitiveEquals(String string1, String string2) {
    return string1->length() == string2->length() && _caseInsensitiveStartsWith(string1, string2, 0);
}
