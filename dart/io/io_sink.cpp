#include "io_sink.hpp"
IOSink::IOSink(Encoding encoding, StreamConsumer<List<int>> target) {
}

void _StreamSinkImpl::add(T data) {
    if (_isClosed) {
        ;
    }
    _controller.add(data);
}

void _StreamSinkImpl::addError(error , StackTrace stackTrace) {
    if (_isClosed) {
        ;
    }
    _controller.addError(error, stackTrace);
}

Future _StreamSinkImpl::addStream(Stream<T> stream) {
    if (_isBound) {
        ;
    }
    if (_hasError)     {
        return done;
    }
    _isBound = true;
    auto future = _controllerCompleter == nullptr? _target.addStream(stream) : _controllerCompleter!.future.then();
    _controllerInstance?.close();
    return future.whenComplete();
}

Future _StreamSinkImpl::flush() {
    if (_isBound) {
        ;
    }
    if (_controllerInstance == nullptr)     {
        return Future.value(this);
    }
    _isBound = true;
    auto future = _controllerCompleter!.future;
    _controllerInstance!.close();
    return future.whenComplete();
}

Future _StreamSinkImpl::close() {
    if (_isBound) {
        ;
    }
    if (!_isClosed) {
        _isClosed = true;
        if (_controllerInstance != nullptr) {
            _controllerInstance!.close();
        } else {
            _closeTarget();
        }
    }
    return done;
}

Future _StreamSinkImpl::done() {
    return _doneCompleter.future;
}

void _StreamSinkImpl::_closeTarget() {
    _target.close().then(_completeDoneValue_completeDoneError);
}

void _StreamSinkImpl::_completeDoneValue(value ) {
    if (!_doneCompleter.isCompleted) {
        _doneCompleter.complete(value);
    }
}

void _StreamSinkImpl::_completeDoneError(error , StackTrace stackTrace) {
    if (!_doneCompleter.isCompleted) {
        _hasError = true;
        _doneCompleter.completeError(error, stackTrace);
    }
}

StreamController<T> _StreamSinkImpl::_controller() {
    if (_isBound) {
        ;
    }
    if (_isClosed) {
        ;
    }
    if (_controllerInstance == nullptr) {
        _controllerInstance = <T>StreamController(true);
        _controllerCompleter = Completer();
        _target.addStream(_controller.stream).then();
    }
    return _controllerInstance!;
}

Encoding _IOSinkImpl::encoding() {
    return _encoding;
}

void _IOSinkImpl::encoding(Encoding value) {
    if (!_encodingMutable) {
        ;
    }
    _encoding = value;
}

void _IOSinkImpl::write(Object obj) {
    String string = "$obj";
    if (string.isEmpty)     {
        return;
    }
    add(_encoding.encode(string));
}

void _IOSinkImpl::writeAll(Iterable objects, String separator) {
    Iterator iterator = objects.iterator;
    if (!iterator.moveNext())     {
        return;
    }
    if (separator.isEmpty) {
        do {
            write(iterator.current);
        } while (iterator.moveNext());
    } else {
        write(iterator.current);
        while (iterator.moveNext()) {
            write(separator);
            write(iterator.current);
        }
    }
}

void _IOSinkImpl::writeln(Object object) {
    write(object);
    write("\n");
}

void _IOSinkImpl::writeCharCode(int charCode) {
    write(String.fromCharCode(charCode));
}

_IOSinkImpl::_IOSinkImpl(Encoding _encoding, StreamConsumer<List<int>> target) {
    {
        super(target);
    }
}
