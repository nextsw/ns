#include "file.hpp"
FileCls::FileCls(String path) {
    {
        IOOverrides overrides = IOOverridesCls::current;
        if (overrides == nullptr) {
            return make<_FileCls>(path);
        }
        return overrides->createFile(path);
    }
}

void FileCls::fromUri(Uri uri) {
    return make<FileCls>(uri->toFilePath());
}

void FileCls::fromRawPath(Uint8List rawPath) {
    return _FileCls->fromRawPath(rawPath);
}

String FileSystemExceptionCls::toString() {
    StringBuffer sb = make<StringBufferCls>();
    sb->write(__s("FileSystemException"));
    if (message->isNotEmpty()) {
        sb->write(__sf(": %s", message));
        if (path != nullptr) {
            sb->write(__sf(", path = '%s'", path));
        }
        if (osError != nullptr) {
            sb->write(__sf(" (%s)", osError));
        }
    } else {
        if (osError != nullptr) {
        sb->write(__sf(": %s", osError));
        if (path != nullptr) {
            sb->write(__sf(", path = '%s'", path));
        }
    } else {
        if (path != nullptr) {
        sb->write(__sf(": %s", path));
    }
;
    };
    }    return sb->toString();
}
