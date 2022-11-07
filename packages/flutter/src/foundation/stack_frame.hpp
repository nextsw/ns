#ifndef STACK_FRAME_H
#define STACK_FRAME_H
#include <memory>

#include <meta/meta.hpp>
#include "constants.hpp"
#include "object.hpp"



class StackFrame {
public:
    static const StackFrame asynchronousSuspension;

    static const StackFrame stackOverFlowElision;

    String source;

    int number;

    String packageScheme;

    String package;

    String packagePath;

    int line;

    int column;

    String className;

    String method;

    bool isConstructor;


     StackFrame(String className, int column, bool isConstructor, int line, String method, int number, String package, String packagePath, String packageScheme, String source);

    static List<StackFrame> fromStackTrace(StackTrace stack);

    static List<StackFrame> fromStackString(String stack);

    static StackFrame fromStackTraceLine(String line);

    int hashCode();

    bool ==(Object other);

    String toString();

private:
    static RegExp _webNonDebugFramePattern;


    static StackFrame _parseWebFrame(String line);

    static StackFrame _parseWebDebugFrame(String line);

    static StackFrame _parseWebNonDebugFrame(String line);

};

#endif