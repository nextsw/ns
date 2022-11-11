#include "exceptions.hpp"
ExceptionCls::ExceptionCls(auto message) {
}

String _ExceptionCls::toString() {
    Object message = this->message;
    if (message == nullptr)     {
        return __s("Exception");
    }
    return __s("Exception: $message");
}

String FormatExceptionCls::toString() {
    String report = __s("FormatException");
    Object message = this->message;
    if (message != nullptr && __s("") != message) {
        report = __s("$report: $message");
    }
    int offset = this->offset;
    Object source = this->source;
    if (is<String>(source)) {
        if (offset != nullptr && ( < 0 || offset > as<StringCls>(source)->length)) {
            offset = nullptr;
        }
        if (offset == nullptr) {
            if (source->length > 78) {
                source = source->substring(0, 75) + __s("...");
            }
            return __s("$report\n$source");
        }
        int lineNum = 1;
        int lineStart = 0;
        bool previousCharWasCR = false;
        for (;  < offset; i++) {
            int char = source->codeUnitAt(i);
            if (char == 0x0a) {
                if (lineStart != i || !previousCharWasCR) {
                    lineNum++;
                }
                lineStart = i + 1;
                previousCharWasCR = false;
            } else             {
                if (char == 0x0d) {
                lineNum++;
                lineStart = i + 1;
                previousCharWasCR = true;
            }
;
            }        }
        if (lineNum > 1) {
            report = __s(" (at line $lineNum, character ${offset - lineStart + 1})\n");
        } else {
            report = __s(" (at character ${offset + 1})\n");
        }
        int lineEnd = as<StringCls>(source)->length;
        for (;  < as<StringCls>(source)->length; i++) {
            int char = source->codeUnitAt(i);
            if (char == 0x0a || char == 0x0d) {
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
            } else             {
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
        return __s("$report$prefix$slice$postfix\n${" " * markOffset}^\n");
    } else {
        if (offset != nullptr) {
            report = __s(" (at offset $offset)");
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
