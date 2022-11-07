#include "hash_codes.hpp"
int _Jenkins::combine(int hash, Object o) {
    assert(o is! Iterable);
    hash = 0x1fffffff & (hash + o.hashCode);
    hash = 0x1fffffff & (hash + ((0x0007ffff & hash) << 10));
    return hash ^ (hash >> 6);
}

int _Jenkins::finish(int hash) {
    hash = 0x1fffffff & (hash + ((0x03ffffff & hash) << 3));
    hash = hash ^ (hash >> 11);
    return 0x1fffffff & (hash + ((0x00003fff & hash) << 15));
}

int hashValues(Object arg01, Object arg02, Object arg03, Object arg04, Object arg05, Object arg06, Object arg07, Object arg08, Object arg09, Object arg10, Object arg11, Object arg12, Object arg13, Object arg14, Object arg15, Object arg16, Object arg17, Object arg18, Object arg19, Object arg20) {
    int result = 0;
    result = _Jenkins.combine(result, arg01);
    result = _Jenkins.combine(result, arg02);
    if (!identical(arg03, _hashEnd)) {
        result = _Jenkins.combine(result, arg03);
        if (!identical(arg04, _hashEnd)) {
            result = _Jenkins.combine(result, arg04);
            if (!identical(arg05, _hashEnd)) {
                result = _Jenkins.combine(result, arg05);
                if (!identical(arg06, _hashEnd)) {
                    result = _Jenkins.combine(result, arg06);
                    if (!identical(arg07, _hashEnd)) {
                        result = _Jenkins.combine(result, arg07);
                        if (!identical(arg08, _hashEnd)) {
                            result = _Jenkins.combine(result, arg08);
                            if (!identical(arg09, _hashEnd)) {
                                result = _Jenkins.combine(result, arg09);
                                if (!identical(arg10, _hashEnd)) {
                                    result = _Jenkins.combine(result, arg10);
                                    if (!identical(arg11, _hashEnd)) {
                                        result = _Jenkins.combine(result, arg11);
                                        if (!identical(arg12, _hashEnd)) {
                                            result = _Jenkins.combine(result, arg12);
                                            if (!identical(arg13, _hashEnd)) {
                                                result = _Jenkins.combine(result, arg13);
                                                if (!identical(arg14, _hashEnd)) {
                                                    result = _Jenkins.combine(result, arg14);
                                                    if (!identical(arg15, _hashEnd)) {
                                                        result = _Jenkins.combine(result, arg15);
                                                        if (!identical(arg16, _hashEnd)) {
                                                            result = _Jenkins.combine(result, arg16);
                                                            if (!identical(arg17, _hashEnd)) {
                                                                result = _Jenkins.combine(result, arg17);
                                                                if (!identical(arg18, _hashEnd)) {
                                                                    result = _Jenkins.combine(result, arg18);
                                                                    if (!identical(arg19, _hashEnd)) {
                                                                        result = _Jenkins.combine(result, arg19);
                                                                        if (!identical(arg20, _hashEnd)) {
                                                                            result = _Jenkins.combine(result, arg20);
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return _Jenkins.finish(result);
}

int hashList(Iterable<Object> arguments) {
    int result = 0;
    if (arguments != nullptr) {
        for (Object argument : arguments)         {
            result = _Jenkins.combine(result, argument);
        }
    }
    return _Jenkins.finish(result);
}
