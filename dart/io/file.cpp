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
    sb->write("FileSystemException");
    if (message->isNotEmpty) {
        sb->write(": $message");
        if (path != nullptr) {
            sb->write(", path = '$path'");
        }
        if (osError != nullptr) {
            sb->write(" ($osError)");
        }
    } else     {
        if (osError != nullptr) {
        sb->write(": $osError");
        if (path != nullptr) {
            sb->write(", path = '$path'");
        }
    } else     {
        if (path != nullptr) {
        sb->write(": $path");
    }
;
    };
    }    return sb->toString();
}
