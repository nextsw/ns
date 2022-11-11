#include "stack_frame.hpp"
StackFrameCls::StackFrameCls(String className, int column, bool isConstructor, int line, String method, int number, String package, String packagePath, String packageScheme, String source) {
    {
        assert(number != nullptr);
        assert(column != nullptr);
        assert(line != nullptr);
        assert(method != nullptr);
        assert(packageScheme != nullptr);
        assert(package != nullptr);
        assert(packagePath != nullptr);
        assert(className != nullptr);
        assert(isConstructor != nullptr);
        assert(source != nullptr);
    }
}

List<StackFrame> StackFrameCls::fromStackTrace(StackTrace stack) {
    assert(stack != nullptr);
    return fromStackString(stack->toString());
}

List<StackFrame> StackFrameCls::fromStackString(String stack) {
    assert(stack != nullptr);
    return stack->trim()->split(__s("\n"))->where([=] (String line) {
        line->isNotEmpty;
    })->map(fromStackTraceLine)-><StackFrame>whereType()->toList();
}

StackFrame StackFrameCls::fromStackTraceLine(String line) {
    assert(line != nullptr);
    if (line == __s("<asynchronous suspension>")) {
        return asynchronousSuspension;
    } else {
        if (line == __s("...")) {
        return stackOverFlowElision;
    }
;
    }    assert(line != __s("===== asynchronous gap ==========================="), __s("Got a stack frame from package:stack_trace, where a vm or web frame was expected. This can happen if FlutterError.demangleStackTrace was not set in an environment that propagates non-standard stack traces to the framework, such as during tests."));
    if (!line->startsWith(__s("#"))) {
        return _parseWebFrame(line);
    }
    RegExp parser = make<RegExpCls>(__s("^#(\d+) +(.+) \((.+?):?(\d+){0,1}:?(\d+){0,1}\)$"));
    Match match = parser->firstMatch(line);
    assert(match != nullptr, __s("Expected $line to match $parser."));
    match = match!;
    bool isConstructor = false;
    String className = __s("");
    String method = match->group(2)!->replaceAll(__s(".<anonymous closure>"), __s(""));
    if (method->startsWith(__s("new"))) {
        List<String> methodParts = method->split(__s(" "));
        className = methodParts->length() > 1? method->split(__s(" "))[1] : __s("<unknown>");
        method = __s("");
        if (className->contains(__s("."))) {
            List<String> parts = className->split(__s("."));
            className = parts[0];
            method = parts[1];
        }
        isConstructor = true;
    } else {
        if (method->contains(__s("."))) {
        List<String> parts = method->split(__s("."));
        className = parts[0];
        method = parts[1];
    }
;
    }    Uri packageUri = UriCls->parse(match->group(3)!);
    String package = __s("<unknown>");
    String packagePath = packageUri->path;
    if (packageUri->scheme == __s("dart") || packageUri->scheme == __s("package")) {
        package = packageUri->pathSegments[0];
        packagePath = packageUri->path->replaceFirst(__s("${packageUri.pathSegments[0]}/"), __s(""));
    }
    return make<StackFrameCls>(intValue->parse(match->group(1)!), className, method, packageUri->scheme, package, packagePath, match->group(4) == nullptr? -1 : intValue->parse(match->group(4)!), match->group(5) == nullptr? -1 : intValue->parse(match->group(5)!), isConstructor, line);
}

int StackFrameCls::hashCode() {
    return ObjectCls->hash(number, package, line, column, className, method, source);
}

bool StackFrameCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<StackFrame>(other) && other->number == number && other->package == package && other->line == line && other->column == column && other->className == className && other->method == method && other->source == source;
}

String StackFrameCls::toString() {
    return __s("${objectRuntimeType(this, 'StackFrame')}(#$number, $packageScheme:$package/$packagePath:$line:$column, className: $className, method: $method)");
}

StackFrame StackFrameCls::_parseWebFrame(String line) {
    if (kDebugMode) {
        return _parseWebDebugFrame(line);
    } else {
        return _parseWebNonDebugFrame(line);
    }
}

StackFrame StackFrameCls::_parseWebDebugFrame(String line) {
    bool hasPackage = line->startsWith(__s("package"));
    RegExp parser = hasPackage? make<RegExpCls>(__s("^(package.+) (\d+):(\d+)\s+(.+)$")) : make<RegExpCls>(__s("^(.+) (\d+):(\d+)\s+(.+)$"));
    Match match = parser->firstMatch(line);
    assert(match != nullptr, __s("Expected $line to match $parser."));
    match = match!;
    String package = __s("<unknown>");
    String packageScheme = __s("<unknown>");
    String packagePath = __s("<unknown>");
    if (hasPackage) {
        packageScheme = __s("package");
        Uri packageUri = UriCls->parse(match->group(1)!);
        package = packageUri->pathSegments[0];
        packagePath = packageUri->path->replaceFirst(__s("${packageUri.pathSegments[0]}/"), __s(""));
    }
    return make<StackFrameCls>(-1, packageScheme, package, packagePath, intValue->parse(match->group(2)!), intValue->parse(match->group(3)!), __s("<unknown>"), match->group(4)!, line);
}

StackFrame StackFrameCls::_parseWebNonDebugFrame(String line) {
    Match match = _webNonDebugFramePattern->firstMatch(line);
    if (match == nullptr) {
        return nullptr;
    }
    List<String> classAndMethod = match->group(1)!->split(__s("."));
    String className = classAndMethod->length() > 1? classAndMethod->first : __s("<unknown>");
    String method = classAndMethod->length() > 1? classAndMethod->skip(1)->join(__s(".")) : classAndMethod->single;
    return make<StackFrameCls>(-1, __s("<unknown>"), __s("<unknown>"), __s("<unknown>"), -1, -1, className, method, line);
}
