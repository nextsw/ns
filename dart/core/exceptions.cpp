#include "exceptions.hpp"
ExceptionCls::ExceptionCls(auto message) {
}

String _ExceptionCls::toString() {
    Object message = this->message;
    if (message == nullptr)     {
        return "Exception";
    }
    return "Exception: $message";
}

String FormatExceptionCls::toString() {
    String report = "FormatException";
    Object message = this->message;
    if (message != nullptr && "" != message) {
        report = "$report: $message";
    }
    int offset = this->offset;
    Object source = this->source;
    if (source is String) {
        if (offset != nullptr && ( < 0 || offset > source->length)) {
            offset = nullptr;
        }
        if (offset == nullptr) {
            if (source->length > 78) {
                source = source->substring(0, 75) + "...";
            }
            return "$report\n$source";
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
            report = " (at line $lineNum, character ${offset - lineStart + 1})\n";
        } else {
            report = " (at character ${offset + 1})\n";
        }
        int lineEnd = source->length;
        for (;  < source->length; i++) {
            int char = source->codeUnitAt(i);
            if (char == 0x0a || char == 0x0d) {
                lineEnd = i;
                                break;
            }
        }
        int length = lineEnd - lineStart;
        int start = lineStart;
        int end = lineEnd;
        String prefix = "";
        String postfix = "";
        if (length > 78) {
            int index = offset - lineStart;
            if ( < 75) {
                end = start + 75;
                postfix = "...";
            } else             {
                if (end -  < 75) {
                start = end - 75;
                prefix = "...";
            } else {
                start = offset - 36;
                end = offset + 36;
                prefix = postfix = "...";
            }
;
            }        }
        String slice = source->substring(start, end);
        int markOffset = offset - start + prefix->length;
        return "$report$prefix$slice$postfix\n${" " * markOffset}^\n";
    } else {
        if (offset != nullptr) {
            report = " (at offset $offset)";
        }
        return report;
    }
}

String IntegerDivisionByZeroExceptionCls::message() {
    return "Division resulted in non-finite value";
}

StackTrace IntegerDivisionByZeroExceptionCls::stackTrace() {
    return nullptr;
}

String IntegerDivisionByZeroExceptionCls::toString() {
    return "IntegerDivisionByZeroException";
}
