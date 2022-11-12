#include "io_sink.hpp"
IOSinkCls::IOSinkCls(StreamConsumer<List<int>> target, Encoding encoding) {
}

template<typename T>
void _StreamSinkImplCls<T>::add(T data) {
    if (_isClosed) {
        throw make<StateErrorCls>(__s("StreamSink is closed"));
    }
    _controller()->add(data);
}

template<typename T>
void _StreamSinkImplCls<T>::addError(error , StackTrace stackTrace) {
    if (_isClosed) {
        throw make<StateErrorCls>(__s("StreamSink is closed"));
    }
    _controller()->addError(error, stackTrace);
}

template<typename T>
Future<any> _StreamSinkImplCls<T>::addStream(Stream<T> stream) {
    if (_isBound) {
        throw make<StateErrorCls>(__s("StreamSink is already bound to a stream"));
    }
    if (_hasError) {
        return done();
    }
    _isBound = true;
    auto future = _controllerCompleter == nullptr? _target->addStream(stream) : _controllerCompleter!->future()->then([=] (Unknown  _) {
    _target->addStream(stream);
});
    _controllerInstance?->close();
    return future->whenComplete([=] () {
        _isBound = false;
    });
}

template<typename T>
Future<any> _StreamSinkImplCls<T>::flush() {
    if (_isBound) {
        throw make<StateErrorCls>(__s("StreamSink is bound to a stream"));
    }
    if (_controllerInstance == nullptr) {
        return FutureCls->value(this);
    }
    _isBound = true;
    auto future = _controllerCompleter!->future();
    _controllerInstance!->close();
    return future->whenComplete([=] () {
        _isBound = false;
    });
}

template<typename T>
Future<any> _StreamSinkImplCls<T>::close() {
    if (_isBound) {
        throw make<StateErrorCls>(__s("StreamSink is bound to a stream"));
    }
    if (!_isClosed) {
        _isClosed = true;
        if (_controllerInstance != nullptr) {
            _controllerInstance!->close();
        } else {
            _closeTarget();
        }
    }
    return done();
}

template<typename T>
Future<any> _StreamSinkImplCls<T>::done() {
    return _doneCompleter->future();
}

template<typename T>
void _StreamSinkImplCls<T>::_closeTarget() {
    _target->close()->then(_completeDoneValue, _completeDoneError);
}

template<typename T>
void _StreamSinkImplCls<T>::_completeDoneValue(value ) {
    if (!_doneCompleter->isCompleted()) {
        _doneCompleter->complete(value);
    }
}

template<typename T>
void _StreamSinkImplCls<T>::_completeDoneError(error , StackTrace stackTrace) {
    if (!_doneCompleter->isCompleted()) {
        _hasError = true;
        _doneCompleter->completeError(error, stackTrace);
    }
}

template<typename T>
StreamController<T> _StreamSinkImplCls<T>::_controller() {
    if (_isBound) {
        throw make<StateErrorCls>(__s("StreamSink is bound to a stream"));
    }
    if (_isClosed) {
        throw make<StateErrorCls>(__s("StreamSink is closed"));
    }
    if (_controllerInstance == nullptr) {
        _controllerInstance = <T>make<StreamControllerCls>(true);
        _controllerCompleter = make<CompleterCls>();
        _target->addStream(_controller()->stream())->then([=] (Unknown  _) {
            if (_isBound) {
                _controllerCompleter!->complete(this);
                _controllerCompleter = nullptr;
                _controllerInstance = nullptr;
            } else {
                _closeTarget();
            }
        }, [=] (Unknown  error,Unknown  stackTrace) {
            if (_isBound) {
                _controllerCompleter!->completeError(error, stackTrace);
                _controllerCompleter = nullptr;
                _controllerInstance = nullptr;
            } else {
                _completeDoneError(error, stackTrace);
            }
        });
    }
    return _controllerInstance!;
}

Encoding _IOSinkImplCls::encoding() {
    return _encoding;
}

void _IOSinkImplCls::encoding(Encoding value) {
    if (!_encodingMutable) {
        throw make<StateErrorCls>(__s("IOSink encoding is not mutable"));
    }
    _encoding = value;
}

void _IOSinkImplCls::write(Object obj) {
    String string = __s("%s;");
    if (stringValue->isEmpty()) {
        return;
    }
    add(_encoding->encode(stringValue));
}

void _IOSinkImplCls::writeAll(Iterable<any> objects, String separator) {
    Iterator<any> iterator = objects->iterator();
    if (!iterator->moveNext()) {
        return;
    }
    if (separator->isEmpty()) {
        do {
            write(iterator->current());
        } while (iterator->moveNext());
    } else {
        write(iterator->current());
        while (iterator->moveNext()) {
            write(separator);
            write(iterator->current());
        }
    }
}

void _IOSinkImplCls::writeln(Object object) {
    write(object);
    write(__s("\n"));
}

void _IOSinkImplCls::writeCharCode(int charCode) {
    write(StringCls->fromCharCode(charCode));
}

_IOSinkImplCls::_IOSinkImplCls(StreamConsumer<List<int>> target, Encoding _encoding) : _StreamSinkImpl<List<int>>(target) {
}
