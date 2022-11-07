#include "directory.hpp"
Directory::Directory(String path) {
    {
        IOOverrides overrides = IOOverrides.current;
        if (overrides == nullptr) {
            return _Directory(path);
        }
        return overrides.createDirectory(path);
    }
}

void Directory::fromRawPath(Uint8List path) {
    return _Directory.fromRawPath(path);
}

void Directory::fromUri(Uri uri) {
    return Directory(uri.toFilePath());
}

Directory Directory::current() {
    IOOverrides overrides = IOOverrides.current;
    if (overrides == nullptr) {
        return _Directory.current;
    }
    return overrides.getCurrentDirectory();
}

void Directory::current(path ) {
    IOOverrides overrides = IOOverrides.current;
    if (overrides == nullptr) {
        _Directory.current = path;
        return;
    }
    overrides.setCurrentDirectory(path);
}

Directory Directory::systemTemp() {
    IOOverrides overrides = IOOverrides.current;
    if (overrides == nullptr) {
        return _Directory.systemTemp;
    }
    return overrides.getSystemTempDirectory();
}
