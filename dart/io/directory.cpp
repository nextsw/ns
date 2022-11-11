#include "directory.hpp"
DirectoryCls::DirectoryCls(String path) {
    {
        IOOverrides overrides = IOOverridesCls::current;
        if (overrides == nullptr) {
            return make<_DirectoryCls>(path);
        }
        return overrides->createDirectory(path);
    }
}

void DirectoryCls::fromRawPath(Uint8List path) {
    return _DirectoryCls->fromRawPath(path);
}

void DirectoryCls::fromUri(Uri uri) {
    return make<DirectoryCls>(uri->toFilePath());
}

Directory DirectoryCls::current() {
    IOOverrides overrides = IOOverridesCls::current;
    if (overrides == nullptr) {
        return _DirectoryCls::current;
    }
    return overrides->getCurrentDirectory();
}

void DirectoryCls::current(path ) {
    IOOverrides overrides = IOOverridesCls::current;
    if (overrides == nullptr) {
        _DirectoryCls::current = path;
        return;
    }
    overrides->setCurrentDirectory(path);
}

Directory DirectoryCls::systemTemp() {
    IOOverrides overrides = IOOverridesCls::current;
    if (overrides == nullptr) {
        return _DirectoryCls::systemTemp;
    }
    return overrides->getSystemTempDirectory();
}
