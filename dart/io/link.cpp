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
    return __s("Link: '$path'");
}

Future<bool> _LinkCls::exists() {
    return FileSystemEntityCls->_isLinkRaw(_rawPath);
}

bool _LinkCls::existsSync() {
    return FileSystemEntityCls->_isLinkRawSync(_rawPath);
}

Link _LinkCls::absolute() {
    return isAbsolute? this : make<_LinkCls>(_absolutePath);
}

Future<Link> _LinkCls::create(bool recursive, String target) {
    auto result = recursive? parent->create(true) : FutureCls->value(nullptr);
    return result->then([=] ()     {
        _FileCls->_dispatchWithNamespace(_IOServiceCls::fileCreateLink, makeList(ArrayItem, ArrayItem, ArrayItem));
    })->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            ;
        }
        return this;
    });
}

void _LinkCls::createSync(bool recursive, String target) {
    if (recursive) {
        parent->createSync(true);
    }
    auto result = _FileCls->_createLink(_NamespaceCls::_namespace, _rawPath, target);
    throwIfError(result, __s("Cannot create link"), path());
}

void _LinkCls::updateSync(String target) {
    deleteSync();
    createSync(target);
}

Future<Link> _LinkCls::update(String target) {
    return delete()-><Link>then([=] ()     {
        create(target);
    });
}

Future<Link> _LinkCls::rename(String newPath) {
    return _FileCls->_dispatchWithNamespace(_IOServiceCls::fileRenameLink, makeList(ArrayItem, ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            ;
        }
        return make<LinkCls>(newPath);
    });
}

Link _LinkCls::renameSync(String newPath) {
    auto result = _FileCls->_renameLink(_NamespaceCls::_namespace, _rawPath, newPath);
    throwIfError(result, __s("Cannot rename link '$path' to '$newPath'"));
    return make<LinkCls>(newPath);
}

Future<String> _LinkCls::target() {
    return _FileCls->_dispatchWithNamespace(_IOServiceCls::fileLinkTarget, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            ;
        }
        return response;
    });
}

String _LinkCls::targetSync() {
    auto result = _FileCls->_linkTarget(_NamespaceCls::_namespace, _rawPath);
    throwIfError(result, __s("Cannot read link"), path());
    return result;
}

void _LinkCls::throwIfError(String msg, String path, Object result) {
    if (is<OSError>(result)) {
        ;
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
        return DirectoryCls->fromRawPath(_rawPath)->delete(true)->then([=] ()         {
            this;
        });
    }
    return _FileCls->_dispatchWithNamespace(_IOServiceCls::fileDeleteLink, makeList(ArrayItem, ArrayItem))->then([=] (Unknown  response) {
        if (_isErrorResponse(response)) {
            ;
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
    return is<List>(response) && response[0] != _successResponse;
}

void _LinkCls::_exceptionFromResponse(response , String message, String path) {
    assert(_isErrorResponse(response));
    ;
}
