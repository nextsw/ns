#ifndef DART_CORE_URI
#define DART_CORE_URI
#include <base.hpp>

#include <dart/core/core.hpp>

int _SPACE;

int _PERCENT;

int _AMPERSAND;

int _PLUS;

int _DOT;

int _SLASH;

int _COLON;

int _EQUALS;

int _UPPER_CASE_A;

int _UPPER_CASE_Z;

int _LEFT_BRACKET;

int _BACKSLASH;

int _RIGHT_BRACKET;

int _LOWER_CASE_A;

int _LOWER_CASE_F;

int _LOWER_CASE_Z;

String _hexDigits;


class UriCls : public ObjectCls {
public:

    static Uri base();
     UriCls(String fragment, String host, String path, Iterable<String> pathSegments, int port, String query, Map<String, dynamic> queryParameters, String scheme, String userInfo);
    virtual void  http(String authority, String unencodedPath, Map<String, dynamic> queryParameters);
    virtual void  https(String authority, String unencodedPath, Map<String, dynamic> queryParameters);
    virtual void  file(String path, bool windows);
    virtual void  directory(String path, bool windows);
    virtual void  dataFromString(String content, bool base64, Encoding encoding, String mimeType, Map<String, String> parameters);

    virtual void  dataFromBytes(List<int> bytes, String mimeType, Map<String, String> parameters, bool percentEncoded);

    virtual String scheme();
    virtual String authority();
    virtual String userInfo();
    virtual String host();
    virtual int port();
    virtual String path();
    virtual String query();
    virtual String fragment();
    virtual List<String> pathSegments();
    virtual Map<String, String> queryParameters();
    virtual Map<String, List<String>> queryParametersAll();
    virtual bool isAbsolute();
    virtual bool hasScheme();

    virtual bool hasAuthority();
    virtual bool hasPort();
    virtual bool hasQuery();
    virtual bool hasFragment();
    virtual bool hasEmptyPath();
    virtual bool hasAbsolutePath();
    virtual String origin();
    virtual bool isScheme(String scheme);
    virtual String toFilePath(bool windows);
    virtual UriData data();
    virtual int hashCode();
    virtual bool operator==(Object other);
    virtual String toString();
    virtual Uri replace(String fragment, String host, String path, Iterable<String> pathSegments, int port, String query, Map<String, dynamic> queryParameters, String scheme, String userInfo);
    virtual Uri removeFragment();
    virtual Uri resolve(String reference);
    virtual Uri resolveUri(Uri reference);
    virtual Uri normalizePath();
    static Uri parse(String uri, int start, int end);

    static Uri tryParse(String uri, int start, int end);

    static String encodeComponent(String component);

    static String encodeQueryComponent(String component, Encoding encoding);

    static String decodeComponent(String encodedComponent);

    static String decodeQueryComponent(String encodedComponent, Encoding encoding);

    static String encodeFull(String uri);

    static String decodeFull(String uri);

    static Map<String, String> splitQueryString(String query, Encoding encoding);

    static List<int> parseIPv4Address(String host);

    static List<int> parseIPv6Address(String host, int start, int end);

private:

    static List<int> _parseIPv4Address(String host, int start, int end);

};
using Uri = std::shared_ptr<UriCls>;

class _UriCls : public ObjectCls {
public:
    String scheme;

    String path;

    List<String> pathSegments;

    int hashCode;

    Map<String, String> queryParameters;

    Map<String, List<String>> queryParametersAll;


    virtual void  notSimple(String uri, int start, int end, int schemeEnd, int hostStart, int portStart, int pathStart, int queryStart, int fragmentStart, String scheme);

    virtual void  http(String authority, String unencodedPath, Map<String, dynamic> queryParameters);

    virtual void  https(String authority, String unencodedPath, Map<String, dynamic> queryParameters);

    virtual String authority();

    virtual String userInfo();

    virtual String host();

    virtual int port();

    virtual String query();

    virtual String fragment();

    virtual bool isScheme(String scheme);

    virtual void  file(String path, bool windows);

    virtual void  directory(String path, bool windows);

    virtual Uri replace(String fragment, String host, String path, Iterable<String> pathSegments, int port, String query, Map<String, dynamic> queryParameters, String scheme, String userInfo);

    virtual Uri removeFragment();

    virtual Uri normalizePath();

    virtual bool isAbsolute();

    virtual Uri resolve(String reference);

    virtual Uri resolveUri(Uri reference);

    virtual bool hasScheme();

    virtual bool hasAuthority();

    virtual bool hasPort();

    virtual bool hasQuery();

    virtual bool hasFragment();

    virtual bool hasEmptyPath();

    virtual bool hasAbsolutePath();

    virtual String origin();

    virtual String toFilePath(bool windows);

    virtual UriData data();

    virtual String toString();

    virtual bool operator==(Object other);

private:
    String _userInfo;

    String _host;

    int _port;

    String _query;

    String _fragment;

    String _text;

    static auto  _unreservedTable;

    static auto  _unreserved2396Table;

    static auto  _encodeFullTable;

    static auto  _schemeTable;

    static auto  _genDelimitersTable;

    static auto  _userinfoTable;

    static auto  _regNameTable;

    static auto  _pathCharTable;

    static auto  _pathCharOrSlashTable;

    static auto  _queryCharTable;

    static auto  _zoneIDTable;


    virtual void  _internal(String scheme, String _userInfo, String _host, int _port, String path, String _query, String _fragment);
     _UriCls(String fragment, String host, String path, Iterable<String> pathSegments, int port, String query, Map<String, dynamic> queryParameters, String scheme, String userInfo);

    static int _defaultPort(String scheme);

    static Never _fail(String uri, int index, String message);

    static _Uri _makeHttpUri(String scheme, String authority, String unencodedPath, Map<String, dynamic> queryParameters);

    static bool _isWindows();
    static void _checkNonWindowsPathReservedCharacters(List<String> segments, bool argumentError);

    static void _checkWindowsPathReservedCharacters(List<String> segments, bool argumentError, int firstSegment);

    static void _checkWindowsDriveLetter(int charCode, bool argumentError);

    static Uri _makeFileUri(String path, bool slashTerminated);

    static void  _makeWindowsFileUrl(String path, bool slashTerminated);

    static List<String> _computePathSegments(String pathToSplit);

    static Map<String, List<String>> _computeQueryParametersAll(String query);

    static int _makePort(int port, String scheme);

    static String _makeHost(String host, int start, int end, bool strictIPv6);

    static int _checkZoneID(String host, int start, int end);

    static bool _isZoneIDChar(int charValue);

    static String _normalizeZoneID(String host, int start, int end, String prefix);

    static bool _isRegNameChar(int charValue);

    static String _normalizeRegName(String host, int start, int end);

    static String _makeScheme(String scheme, int start, int end);

    static String _canonicalizeScheme(String scheme);

    static String _makeUserInfo(String userInfo, int start, int end);

    static String _makePath(String path, int start, int end, Iterable<String> pathSegments, String scheme, bool hasAuthority);

    static String _normalizePath(String path, String scheme, bool hasAuthority);

    static String _makeQuery(String query, int start, int end, Map<String, dynamic> queryParameters);

    static String _makeFragment(String fragment, int start, int end);

    static String _normalizeEscape(String source, int index, bool lowerCase);

    static String _escapeChar(int charValue);

    static String _normalizeOrSubstring(String component, int start, int end, List<int> charTable, bool escapeDelimiters, bool replaceBackslash);

    static String _normalize(String component, int start, int end, List<int> charTable, bool escapeDelimiters, bool replaceBackslash);

    static bool _isSchemeCharacter(int ch);

    static bool _isGeneralDelimiter(int ch);

    virtual String _mergePaths(String base, String reference);

    static bool _mayContainDotSegments(String path);

    static String _removeDotSegments(String path);

    static String _normalizeRelativePath(String path, bool allowScheme);

    static String _escapeScheme(String path);

    static int _packageNameEnd(Uri uri, String path);

    virtual String _toFilePath();

    static String _toWindowsFilePath(Uri uri);

    virtual void _writeAuthority(StringSink ss);

    virtual String _initializeText();

    static List<String> _createList();

    static Map<String, List<String>> _splitQueryStringAll(String query, Encoding encoding);

    static String _uriEncode(List<int> canonicalTable, String text, Encoding encoding, bool spaceToPlus);
    static int _hexCharPairToByte(String s, int pos);

    static String _uriDecode(String text, int start, int end, Encoding encoding, bool plusToSpace);

    static bool _isAlphabeticCharacter(int codeUnit);

    static bool _isUnreservedChar(int charValue);

};
using _Uri = std::shared_ptr<_UriCls>;

class UriDataCls : public ObjectCls {
public:

    virtual void  fromString(String content, bool base64, Encoding encoding, String mimeType, Map<String, String> parameters);

    virtual void  fromBytes(List<int> bytes, String mimeType, Map<String, String> parameters, bool percentEncoded);

    virtual void  fromUri(Uri uri);

    static UriData parse(String uri);

    virtual Uri uri();

    virtual String mimeType();

    virtual bool isMimeType(String mimeType);

    virtual String charset();

    virtual bool isCharset(String charset);

    virtual bool isEncoding(Encoding encoding);

    virtual bool isBase64();

    virtual String contentText();

    virtual Uint8List contentAsBytes();

    virtual String contentAsString(Encoding encoding);

    virtual Map<String, String> parameters();

    virtual String toString();

private:
    static int _noScheme;

    String _text;

    List<int> _separatorIndices;

    Uri _uriCache;

    static Base64Codec _base64;

    static auto  _tokenCharTable;

    static auto  _uricTable;


    virtual void  _(String _text, List<int> _separatorIndices, Uri _uriCache);
    static void _writeUri(String mimeType, String charsetName, Map<String, String> parameters, StringBuffer buffer, List<int> indices);

    static int _validateMimeType(String mimeType);

    virtual Uri _computeUri();

    virtual int _findCharsetIndex();

    static UriData _parse(String text, int start, Uri sourceUri);

    static void _uriEncodeBytes(List<int> canonicalTable, List<int> bytes, StringSink buffer);

};
using UriData = std::shared_ptr<UriDataCls>;
int _schemeEndIndex;

int _hostStartIndex;

int _portStartIndex;

int _pathStartIndex;

int _queryStartIndex;

int _fragmentStartIndex;

int _notSimpleIndex;

int _uriStart;

int _nonSimpleEndStates;

int _schemeStart;

List<Uint8List> _scannerTables;

List<Uint8List> _createTables();

int _scan(String uri, int start, int end, int state, List<int> indices);


class _SimpleUriCls : public ObjectCls {
public:

    virtual bool hasScheme();

    virtual bool hasAuthority();

    virtual bool hasUserInfo();

    virtual bool hasPort();

    virtual bool hasQuery();

    virtual bool hasFragment();

    virtual bool hasAbsolutePath();

    virtual bool hasEmptyPath();

    virtual bool isAbsolute();

    virtual bool isScheme(String scheme);

    virtual String scheme();

    virtual String authority();

    virtual String userInfo();

    virtual String host();

    virtual int port();

    virtual String path();

    virtual String query();

    virtual String fragment();

    virtual String origin();

    virtual List<String> pathSegments();

    virtual Map<String, String> queryParameters();

    virtual Map<String, List<String>> queryParametersAll();

    virtual Uri normalizePath();

    virtual Uri removeFragment();

    virtual Uri replace(String fragment, String host, String path, Iterable<String> pathSegments, int port, String query, Map<String, dynamic> queryParameters, String scheme, String userInfo);

    virtual Uri resolve(String reference);

    virtual Uri resolveUri(Uri reference);

    virtual String toFilePath(bool windows);

    virtual UriData data();

    virtual int hashCode();

    virtual bool operator==(Object other);

    virtual String toString();

private:
    String _uri;

    int _schemeEnd;

    int _hostStart;

    int _portStart;

    int _pathStart;

    int _queryStart;

    int _fragmentStart;

    String _schemeCache;

    int _hashCodeCache;


     _SimpleUriCls(String _uri, int _schemeEnd, int _hostStart, int _portStart, int _pathStart, int _queryStart, int _fragmentStart, String _schemeCache);
    virtual bool _isFile();

    virtual bool _isHttp();

    virtual bool _isHttps();

    virtual bool _isPackage();

    virtual bool _isScheme(String scheme);

    virtual String _computeScheme();

    virtual bool _isPort(String port);

    static int _packageNameEnd(_SimpleUri uri);

    virtual Uri _simpleMerge(_SimpleUri base, _SimpleUri ref);

    virtual String _toFilePath();

    virtual Uri _toNonSimple();

};
using _SimpleUri = std::shared_ptr<_SimpleUriCls>;

class _DataUriCls : public _UriCls {
public:

    virtual UriData data();

private:
    UriData _data;


     _DataUriCls(UriData _data, String path, String query);

};
using _DataUri = std::shared_ptr<_DataUriCls>;
int _startsWithData(String text, int start);

int _stringOrNullLength(String s);

List<String> _toUnmodifiableStringList(String key, List<String> list);

int _skipPackageNameChars(String source, int start, int end);

bool _caseInsensitiveStartsWith(String prefix, String stringValue, int start);

int _caseInsensitiveCompareStart(String prefix, String stringValue, int start);

bool _caseInsensitiveEquals(String string1, String string2);



#endif