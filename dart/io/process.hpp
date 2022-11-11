#ifndef DART_IO_PROCESS
#define DART_IO_PROCESS
#include <base.hpp>

#include <dart/core/core.hpp>


class _ProcessUtilsCls : public ObjectCls {
public:

private:

    static Never _exit(int status);
    static void _setExitCode(int status);
    static int _getExitCode();
    static void _sleep(int millis);
    static int _pid(Process process);
    static Stream<ProcessSignal> _watchSignal(ProcessSignal signal);
};
using _ProcessUtils = std::shared_ptr<_ProcessUtilsCls>;
Never exit(int code);

void exitCode(int code);

int exitCode();

void sleep(Duration duration);

int pid();


class ProcessInfoCls : public ObjectCls {
public:

    static int currentRss();
    static int maxRss();
private:

};
using ProcessInfo = std::shared_ptr<ProcessInfoCls>;

class ProcessStartModeCls : public ObjectCls {
public:
    static auto  normal;

    static auto  inheritStdio;

    static auto  detached;

    static auto  detachedWithStdio;


    static List<ProcessStartMode> values();

    virtual String toString();

private:
    int _mode;


    virtual void  _internal(int _mode);
};
using ProcessStartMode = std::shared_ptr<ProcessStartModeCls>;

class ProcessCls : public ObjectCls {
public:

    virtual Future<int> exitCode();
    static Future<Process> start(String executable, List<String> arguments, Map<String, String> environment, bool includeParentEnvironment, ProcessStartMode mode, bool runInShell, String workingDirectory);
    static Future<ProcessResult> run(String executable, List<String> arguments, Map<String, String> environment, bool includeParentEnvironment, bool runInShell, Encoding stderrEncoding, Encoding stdoutEncoding, String workingDirectory);
    static ProcessResult runSync(String executable, List<String> arguments, Map<String, String> environment, bool includeParentEnvironment, bool runInShell, Encoding stderrEncoding, Encoding stdoutEncoding, String workingDirectory);
    static bool killPid(int pid, ProcessSignal signal);
    virtual Stream<List<int>> stdout();
    virtual Stream<List<int>> stderr();
    virtual IOSink stdin();
    virtual int pid();
    virtual bool kill(ProcessSignal signal);
private:

};
using Process = std::shared_ptr<ProcessCls>;

class ProcessResultCls : public ObjectCls {
public:
    int exitCode;

    auto  stdout;

    auto  stderr;

    int pid;


     ProcessResultCls(int pid, int exitCode, Unknown stdout, Unknown stderr);
private:

};
using ProcessResult = std::shared_ptr<ProcessResultCls>;

class ProcessSignalCls : public ObjectCls {
public:
    static ProcessSignal sighup;

    static ProcessSignal sigint;

    static ProcessSignal sigquit;

    static ProcessSignal sigill;

    static ProcessSignal sigtrap;

    static ProcessSignal sigabrt;

    static ProcessSignal sigbus;

    static ProcessSignal sigfpe;

    static ProcessSignal sigkill;

    static ProcessSignal sigusr1;

    static ProcessSignal sigsegv;

    static ProcessSignal sigusr2;

    static ProcessSignal sigpipe;

    static ProcessSignal sigalrm;

    static ProcessSignal sigterm;

    static ProcessSignal sigchld;

    static ProcessSignal sigcont;

    static ProcessSignal sigstop;

    static ProcessSignal sigtstp;

    static ProcessSignal sigttin;

    static ProcessSignal sigttou;

    static ProcessSignal sigurg;

    static ProcessSignal sigxcpu;

    static ProcessSignal sigxfsz;

    static ProcessSignal sigvtalrm;

    static ProcessSignal sigprof;

    static ProcessSignal sigwinch;

    static ProcessSignal sigpoll;

    static ProcessSignal sigsys;


    virtual String toString();

    virtual Stream<ProcessSignal> watch();

private:
    int _signalNumber;

    String _name;


    virtual void  _(int _signalNumber, String _name);
};
using ProcessSignal = std::shared_ptr<ProcessSignalCls>;

class SignalExceptionCls : public ObjectCls {
public:
    String message;

    auto  osError;


     SignalExceptionCls(String message, Unknown osError);
    virtual String toString();

private:

};
using SignalException = std::shared_ptr<SignalExceptionCls>;

class ProcessExceptionCls : public ObjectCls {
public:
    String executable;

    List<String> arguments;

    String message;

    int errorCode;


     ProcessExceptionCls(String executable, List<String> arguments, String message, int errorCode);
    virtual String toString();

private:

};
using ProcessException = std::shared_ptr<ProcessExceptionCls>;


#endif