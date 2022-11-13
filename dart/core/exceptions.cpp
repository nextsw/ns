#include "exceptions.hpp"
ExceptionCls::ExceptionCls(auto message) {
}

String _ExceptionCls::toString() {
    Object message = this->message;
    if (message == nullptr) {
        return __s("Exception");
    }
    return __sf("Exception: %s", message);
}

String FormatExceptionCls::toString() {
    String report = __s("FormatException");
    Object message = this->message;
    if (message != nullptr && __s("") != message) {
        report = __sf("%s: %s", report, message);
    }
    int offset = this->offset;
    Object source = this->source;
    if (is<String>(source)) {
        if (offset != nullptr && ( < 0 || offset > as<StringCls>(source)->length())) {
            offset = nullptr;
        }
        if (offset == nullptr) {
            if (source->length() > 78) {
                source = source->substring(0, 75) + __s("...");
            }
            return __sf("%s\n%s", report, source);
        }
        int lineNum = 1;
        int lineStart = 0;
        bool previousCharWasCR = false;
        for (;  < offset; i++) {
            int char = source->codeUnitAt(i);
            if (charValue == 0x0a) {
                if (lineStart != i || !previousCharWasCR) {
                    lineNum++;
                }
                lineStart = i + 1;
                previousCharWasCR = false;
            } else {
                if (charValue == 0x0d) {
                lineNum++;
                lineStart = i + 1;
                previousCharWasCR = true;
            }
;
            }        }
        if (lineNum > 1) {
            report += __sf(" (at line %s, character %s)\n", lineNum, offset - lineStart + 1);
        } else {
            report += __sf(" (at character %s)\n", offset + 1);
        }
        int lineEnd = as<StringCls>(source)->length();
        for (;  < as<StringCls>(source)->length(); i++) {
            int char = source->codeUnitAt(i);
            if (charValue == 0x0a || charValue == 0x0d) {
                lineEnd = i;
                break;
            }
        }
        int length = lineEnd - lineStart;
        int start = lineStart;
        int end = lineEnd;
        String prefix = __s("");
        String postfix = __s("");
        if (length > 78) {
            int index = offset - lineStart;
            if ( < 75) {
                end = start + 75;
                postfix = __s("...");
            } else {
                if (end -  < 75) {
                start = end - 75;
                prefix = __s("...");
            } else {
                start = offset - 36;
                end = offset + 36;
                prefix = postfix = __s("...");
            }
;
            }        }
        String slice = as<StringCls>(source)->substring(start, end);
        int markOffset = offset - start + prefix->length;
        return __sf("%s%s%s%s\n%s^\n", report, prefix, slice, postfix, __s(" ") * markOffset);
    } else {
        if (offset != nullptr) {
            report += __sf(" (at offset %s)", offset);
        }
        return report;
    }
}

String IntegerDivisionByZeroExceptionCls::message() {
    return __s("Division resulted in non-finite value");
}

StackTrace IntegerDivisionByZeroExceptionCls::stackTrace() {
    return nullptr;
}

String IntegerDivisionByZeroExceptionCls::toString() {
    return __s("IntegerDivisionByZeroException");
}
