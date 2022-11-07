#include "link.hpp"
Link::Link(String path) {
    {
        IOOverrides overrides = IOOverrides.current;
        if (overrides == nullptr) {
            return _Link(path);
        }
        return overrides.createLink(path);
    }
}

void Link::fromRawPath(Uint8List rawPath) {
    return _Link.fromRawPath(rawPath);
}

void Link::fromUri(Uri uri) {
    return Link(uri.toFilePath());
}

void _Link::fromRawPath(Uint8List rawPath)

String _Link::path() {
    return _path;
}

String _Link::toString() {
    return "Link: '$path'";
}

Future<bool> _Link::exists() {
    return FileSystemEntity._isLinkRaw(_rawPath);
}

bool _Link::existsSync() {
    return FileSystemEntity._isLinkRawSync(_rawPath);
}

Link _Link::absolute() {
    return isAbsolute? this : _Link(_absolutePath);
}

Future<Link> _Link::create(bool recursive, String target) {
    auto result = recursive? parent.create(true) : Future.value(nullptr);
    return result.then().then();
}

void _Link::createSync(bool recursive, String target) {
    if (recursive) {
        parent.createSync(true);
    }
    auto result = _File._createLink(_Namespace._namespace, _rawPath, target);
    throwIfError(result, "Cannot create link", path);
}

void _Link::updateSync(String target) {
    deleteSync();
    createSync(target);
}

Future<Link> _Link::update(String target) {
    return delete().<Link>then();
}

Future<Link> _Link::rename(String newPath) {
    return _File._dispatchWithNamespace(_IOService.fileRenameLink, ).then();
}

Link _Link::renameSync(String newPath) {
    auto result = _File._renameLink(_Namespace._namespace, _rawPath, newPath);
    throwIfError(result, "Cannot rename link '$path' to '$newPath'");
    return Link(newPath);
}

Future<String> _Link::target() {
    return _File._dispatchWithNamespace(_IOService.fileLinkTarget, ).then();
}

String _Link::targetSync() {
    auto result = _File._linkTarget(_Namespace._namespace, _rawPath);
    throwIfError(result, "Cannot read link", path);
    return result;
}

void _Link::throwIfError(String msg, String path, Object result) {
    if (result is OSError) {
        ;
    }
}

_Link::_Link(String path) {
    {
        _path = path;
        _rawPath = FileSystemEntity._toUtf8Array(path);
    }
}

Future<Link> _Link::_delete(bool recursive) {
    if (recursive) {
        return Directory.fromRawPath(_rawPath).delete(true).then();
    }
    return _File._dispatchWithNamespace(_IOService.fileDeleteLink, ).then();
}

void _Link::_deleteSync(bool recursive) {
    if (recursive) {
        return Directory.fromRawPath(_rawPath).deleteSync(true);
    }
    auto result = _File._deleteLinkNative(_Namespace._namespace, _rawPath);
    throwIfError(result, "Cannot delete link", path);
}

bool _Link::_isErrorResponse(response ) {
    return response is List && response[0] != _successResponse;
}

void _Link::_exceptionFromResponse(response , String message, String path) {
    assert(_isErrorResponse(response));
    ;
}
