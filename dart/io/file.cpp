#include "file.hpp"
File::File(String path) {
    {
        IOOverrides overrides = IOOverrides.current;
        if (overrides == nullptr) {
            return _File(path);
        }
        return overrides.createFile(path);
    }
}

void File::fromUri(Uri uri) {
    return File(uri.toFilePath());
}

void File::fromRawPath(Uint8List rawPath) {
    return _File.fromRawPath(rawPath);
}

String FileSystemException::toString() {
    StringBuffer sb = StringBuffer();
    sb.write("FileSystemException");
    if (message.isNotEmpty) {
        sb.write(": $message");
        if (path != nullptr) {
            sb.write(", path = '$path'");
        }
        if (osError != nullptr) {
            sb.write(" ($osError)");
        }
    } else     {
        if (osError != nullptr) {
        sb.write(": $osError");
        if (path != nullptr) {
            sb.write(", path = '$path'");
        }
    } else     {
        if (path != nullptr) {
        sb.write(": $path");
    }
;
    };
    }    return sb.toString();
}
