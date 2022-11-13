#include "link.hpp"
LinkCls::LinkCls(String path) {
    {
        IOOverrides overrides = IOOverridesCls::current;
        if (overrides == nullptr) {
            return make<_LinkCls>(path);
        }
        return overrides->createLink(path);
    }
}

void LinkCls::fromRawPath(Uint8List rawPath) {
    return _LinkCls->fromRawPath(rawPath);
}

void LinkCls::fromUri(Uri uri) {
    return make<LinkCls>(uri->toFilePath());
}

void _LinkCls::fromRawPath(Uint8List rawPath)

String _LinkCls::path() {
    return _path;
}

String _LinkCls::toString() {
    return __sf("Link: '%s'", path());
}

Future<bool> _LinkCls::exists() {
    return FileSystemEntityCls->_isLinkRaw(_rawPath);
}

bool _LinkCls::existsSync() {
    return FileSystemEntityCls->_isLinkRawSync(_rawPath);
}

Link _LinkCls::absolute() {
    return isAbsolute()? this : make<_LinkCls>(_absolutePath());
}

Future<Link> _LinkCls::create(String target, bool recursive) {
    auto result = recursive? parent()->create(true) : FutureCls->value(nullptr);
    return result->then([=] (Unknown  _) {
        _FileCls->_dispatchWithNamespace(_IOServiceCls::fileCreateLink, makeList(ArrayItem, ArrayItem, ArrayItem));
    })->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __sf("Cannot create link to target '%s'", target), path());
        }
        return this;
    });
}

void _LinkCls::createSync(String target, bool recursive) {
    if (recursive) {
        parent()->createSync(true);
    }
    auto result = _FileCls->_createLink(_NamespaceCls::_namespace, _rawPath, target);
    throwIfError(result, __s("Cannot create link"), path());
}

void _LinkCls::updateSync(String target) {
    deleteSync();
    createSync(target);
}

Future<Link> _LinkCls::update(String target) {
    return delete()-><Link>then([=] (Unknown  _) {
        create(target);
    });
}

Future<Link> _LinkCls::rename(String newPath) {
    return _FileCls->_dispatchWithNamespace(_IOServiceCls::fileRenameLink, makeList(ArrayItem, ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __sf("Cannot rename link to '%s'", newPath), path());
        }
        return make<LinkCls>(newPath);
    });
}

Link _LinkCls::renameSync(String newPath) {
    auto result = _FileCls->_renameLink(_NamespaceCls::_namespace, _rawPath, newPath);
    throwIfError(result, __sf("Cannot rename link '%s' to '%s'", path(), newPath));
    return make<LinkCls>(newPath);
}

Future<String> _LinkCls::target() {
    return _FileCls->_dispatchWithNamespace(_IOServiceCls::fileLinkTarget, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("Cannot get target of link"), path());
        }
        return response;
    });
}

String _LinkCls::targetSync() {
    auto result = _FileCls->_linkTarget(_NamespaceCls::_namespace, _rawPath);
    throwIfError(result, __s("Cannot read link"), path());
    return result;
}

void _LinkCls::throwIfError(Object result, String msg, String path) {
    if (is<OSError>(result)) {
        throw make<FileSystemExceptionCls>(msg, path, as<OSErrorCls>(result));
    }
}

_LinkCls::_LinkCls(String path) {
    {
        _path = path;
        _rawPath = FileSystemEntityCls->_toUtf8Array(path);
    }
}

Future<Link> _LinkCls::_delete(bool recursive) {
    if (recursive) {
        return DirectoryCls->fromRawPath(_rawPath)->delete(true)->then([=] (Unknown  _) {
            this;
        });
    }
    return _FileCls->_dispatchWithNamespace(_IOServiceCls::fileDeleteLink, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            throw _exceptionFromResponse(response, __s("Cannot delete link"), path());
        }
        return this;
    });
}

void _LinkCls::_deleteSync(bool recursive) {
    if (recursive) {
        return DirectoryCls->fromRawPath(_rawPath)->deleteSync(true);
    }
    auto result = _FileCls->_deleteLinkNative(_NamespaceCls::_namespace, _rawPath);
    throwIfError(result, __s("Cannot delete link"), path());
}

bool _LinkCls::_isErrorResponse(response ) {
    return is<List<any>>(response) && response[0] != _successResponse;
}

void _LinkCls::_exceptionFromResponse(response , String message, String path) {
    assert(_isErrorResponse(response));
    ;
}
