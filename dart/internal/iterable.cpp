#include "iterable.hpp"
template<typename E>
Iterator<E> ListIterableCls<E>::iterator() {
    return <E>make<ListIteratorCls>(this);
}

template<typename E>
void ListIterableCls<E>::forEach(std::function<void(E element)> action) {
    int length = this->length();
    for (;  < length; i++) {
        action(elementAt(i));
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
}

template<typename E>
bool ListIterableCls<E>::isEmpty() {
    return length() == 0;
}

template<typename E>
E ListIterableCls<E>::first() {
    if (length() == 0) {
        throw IterableElementErrorCls->noElement();
    }
    return elementAt(0);
}

template<typename E>
E ListIterableCls<E>::last() {
    if (length() == 0) {
        throw IterableElementErrorCls->noElement();
    }
    return elementAt(length() - 1);
}

template<typename E>
E ListIterableCls<E>::single() {
    if (length() == 0) {
        throw IterableElementErrorCls->noElement();
    }
    if (length() > 1) {
        throw IterableElementErrorCls->tooMany();
    }
    return elementAt(0);
}

template<typename E>
bool ListIterableCls<E>::contains(Object element) {
    int length = this->length();
    for (;  < length; i++) {
        if (elementAt(i) == element) {
            return true;
        }
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
    return false;
}

template<typename E>
bool ListIterableCls<E>::every(std::function<bool(E element)> test) {
    int length = this->length();
    for (;  < length; i++) {
        if (!test(elementAt(i))) {
            return false;
        }
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
    return true;
}

template<typename E>
bool ListIterableCls<E>::any(std::function<bool(E element)> test) {
    int length = this->length();
    for (;  < length; i++) {
        if (test(elementAt(i))) {
            return true;
        }
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
    return false;
}

template<typename E>
E ListIterableCls<E>::firstWhere(std::function<bool(E element)> test, std::function<E()> orElse) {
    int length = this->length();
    for (;  < length; i++) {
        E element = elementAt(i);
        if (test(element)) {
            return element;
        }
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
    if (orElse != nullptr) {
        return orElse();
    }
    throw IterableElementErrorCls->noElement();
}

template<typename E>
E ListIterableCls<E>::lastWhere(std::function<bool(E element)> test, std::function<E()> orElse) {
    int length = this->length();
    for (; i >= 0; i--) {
        E element = elementAt(i);
        if (test(element)) {
            return element;
        }
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
    if (orElse != nullptr) {
        return orElse();
    }
    throw IterableElementErrorCls->noElement();
}

template<typename E>
E ListIterableCls<E>::singleWhere(std::function<bool(E element)> test, std::function<E()> orElse) {
    int length = this->length();
    E match;
    bool matchFound = false;
    for (;  < length; i++) {
        E element = elementAt(i);
        if (test(element)) {
            if (matchFound) {
                throw IterableElementErrorCls->tooMany();
            }
            matchFound = true;
            match = element;
        }
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
    if (matchFound) {
        return match;
    }
    if (orElse != nullptr) {
        return orElse();
    }
    throw IterableElementErrorCls->noElement();
}

template<typename E>
String ListIterableCls<E>::join(String separator) {
    int length = this->length();
    if (!separator->isEmpty()) {
        if (length == 0) {
            return __s("");
        }
        String first = __sf("%s", elementAt(0));
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
        StringBuffer buffer = make<StringBufferCls>(first);
        for (;  < length; i++) {
            buffer->write(separator);
            buffer->write(elementAt(i));
            if (length != this->length) {
                throw make<ConcurrentModificationErrorCls>(this);
            }
        }
        return buffer->toString();
    } else {
        StringBuffer buffer = make<StringBufferCls>();
        for (;  < length; i++) {
            buffer->write(elementAt(i));
            if (length != this->length) {
                throw make<ConcurrentModificationErrorCls>(this);
            }
        }
        return buffer->toString();
    }
}

template<typename E>
Iterable<E> ListIterableCls<E>::where(std::function<bool(E element)> test) {
    return super->where(test);
}

template<typename E>
template<typename T>
Iterable<T> ListIterableCls<E>::map(std::function<T(E element)> toElement) {
    return <E, T>make<MappedListIterableCls>(this, toElement);
}

template<typename E>
E ListIterableCls<E>::reduce(std::function<E(E value, E element)> combine) {
    int length = this->length();
    if (length == 0) {
        throw IterableElementErrorCls->noElement();
    }
    E value = elementAt(0);
    for (;  < length; i++) {
        value = combine(value, elementAt(i));
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
    return value;
}

template<typename E>
template<typename T>
T ListIterableCls<E>::fold(T initialValue, std::function<T(T previousValue, E element)> combine) {
    auto value = initialValue;
    int length = this->length();
    for (;  < length; i++) {
        value = combine(value, elementAt(i));
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
    return value;
}

template<typename E>
Iterable<E> ListIterableCls<E>::skip(int count) {
    return <E>make<SubListIterableCls>(this, count, nullptr);
}

template<typename E>
Iterable<E> ListIterableCls<E>::skipWhile(std::function<bool(E element)> test) {
    return super->skipWhile(test);
}

template<typename E>
Iterable<E> ListIterableCls<E>::take(int count) {
    return <E>make<SubListIterableCls>(this, 0, checkNotNullable(count, __s("count")));
}

template<typename E>
Iterable<E> ListIterableCls<E>::takeWhile(std::function<bool(E element)> test) {
    return super->takeWhile(test);
}

template<typename E>
List<E> ListIterableCls<E>::toList(bool growable) {
    return <E>of(this, growable);
}

template<typename E>
Set<E> ListIterableCls<E>::toSet() {
    Set<E> result = <E>make<SetCls>();
    for (;  < length(); i++) {
        result->add(elementAt(i));
    }
    return result;
}

template<typename E>
SubListIterableCls<E>::SubListIterableCls(Iterable<E> _iterable, int _start, int _endOrLength) {
    {
        RangeErrorCls->checkNotNegative(_start, __s("start"));
        int endOrLength = _endOrLength;
        if (endOrLength != nullptr) {
            RangeErrorCls->checkNotNegative(endOrLength, __s("end"));
            if (_start > endOrLength) {
                throw RangeErrorCls->range(_start, 0, endOrLength, __s("start"));
            }
        }
    }
}

template<typename E>
int SubListIterableCls<E>::length() {
    int length = _iterable->length();
    if (_start >= length) {
        return 0;
    }
    int endOrLength = _endOrLength;
    if (endOrLength == nullptr || endOrLength >= length) {
        return length - _start;
    }
    return endOrLength - _start;
}

template<typename E>
E SubListIterableCls<E>::elementAt(int index) {
    int realIndex = _startIndex() + index;
    if ( < 0 || realIndex >= _endIndex()) {
        throw RangeErrorCls->index(index, this, __s("index"));
    }
    return _iterable->elementAt(realIndex);
}

template<typename E>
Iterable<E> SubListIterableCls<E>::skip(int count) {
    RangeErrorCls->checkNotNegative(count, __s("count"));
    int newStart = _start + count;
    int endOrLength = _endOrLength;
    if (endOrLength != nullptr && newStart >= endOrLength) {
        return <E>make<EmptyIterableCls>();
    }
    return <E>make<SubListIterableCls>(_iterable, newStart, _endOrLength);
}

template<typename E>
Iterable<E> SubListIterableCls<E>::take(int count) {
    RangeErrorCls->checkNotNegative(count, __s("count"));
    int endOrLength = _endOrLength;
    if (endOrLength == nullptr) {
        return <E>make<SubListIterableCls>(_iterable, _start, _start + count);
    } else {
        int newEnd = _start + count;
        if ( < newEnd) {
            return this;
        }
        return <E>make<SubListIterableCls>(_iterable, _start, newEnd);
    }
}

template<typename E>
List<E> SubListIterableCls<E>::toList(bool growable) {
    int start = _start;
    int end = _iterable->length();
    int endOrLength = _endOrLength;
    if (endOrLength != nullptr &&  < end) {
        end = endOrLength;
    }
    int length = end - start;
    if (length <= 0) {
        return <E>empty(growable);
    }
    List<E> result = <E>filled(length, _iterable->elementAt(start), growable);
    for (;  < length; i++) {
        result[i] = _iterable->elementAt(start + i);
        if (_iterable->length < end) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
    return result;
}

template<typename E>
int SubListIterableCls<E>::_endIndex() {
    int length = _iterable->length();
    int endOrLength = _endOrLength;
    if (endOrLength == nullptr || endOrLength > length) {
        return length;
    }
    return endOrLength;
}

template<typename E>
int SubListIterableCls<E>::_startIndex() {
    int length = _iterable->length();
    if (_start > length) {
        return length;
    }
    return _start;
}

template<typename E>
ListIteratorCls<E>::ListIteratorCls(Iterable<E> iterable) {
    {
        _iterable = iterable;
        _length = iterable->length();
        _index = 0;
    }
}

template<typename E>
E ListIteratorCls<E>::current() {
    return as<E>(_current);
}

template<typename E>
bool ListIteratorCls<E>::moveNext() {
    int length = _iterable->length();
    if (_length != length) {
        throw make<ConcurrentModificationErrorCls>(_iterable);
    }
    if (_index >= length) {
        _current = nullptr;
        return false;
    }
    _current = _iterable->elementAt(_index);
    _index++;
    return true;
}

template<typename S, typename T>
MappedIterableCls<S, T>::MappedIterableCls(Iterable<S> iterable, std::function<T(S value)> function) {
    {
        if (is<EfficientLengthIterable<any>>(iterable)) {
            return <S, T>make<EfficientLengthMappedIterableCls>(as<EfficientLengthIterableCls>(iterable), function);
        }
        return <S, T>_(iterable, function);
    }
}

template<typename S, typename T>
Iterator<T> MappedIterableCls<S, T>::iterator() {
    return <S, T>make<MappedIteratorCls>(_iterable->iterator(), _f);
}

template<typename S, typename T>
int MappedIterableCls<S, T>::length() {
    return _iterable->length();
}

template<typename S, typename T>
bool MappedIterableCls<S, T>::isEmpty() {
    return _iterable->isEmpty();
}

template<typename S, typename T>
T MappedIterableCls<S, T>::first() {
    return _f(_iterable->first());
}

template<typename S, typename T>
T MappedIterableCls<S, T>::last() {
    return _f(_iterable->last());
}

template<typename S, typename T>
T MappedIterableCls<S, T>::single() {
    return _f(_iterable->single());
}

template<typename S, typename T>
T MappedIterableCls<S, T>::elementAt(int index) {
    return _f(_iterable->elementAt(index));
}

template<typename S, typename T>
EfficientLengthMappedIterableCls<S, T>::EfficientLengthMappedIterableCls(Iterable<S> iterable, std::function<T(S value)> function) {
    {
        super->_(iterable, function);
    }
}

template<typename S, typename T>
bool MappedIteratorCls<S, T>::moveNext() {
    if (_iterator->moveNext()) {
        _current = _f(_iterator->current());
        return true;
    }
    _current = nullptr;
    return false;
}

template<typename S, typename T>
T MappedIteratorCls<S, T>::current() {
    return as<T>(_current);
}

template<typename S, typename T>
int MappedListIterableCls<S, T>::length() {
    return _source->length();
}

template<typename S, typename T>
T MappedListIterableCls<S, T>::elementAt(int index) {
    return _f(_source->elementAt(index));
}

template<typename E>
Iterator<E> WhereIterableCls<E>::iterator() {
    return <E>make<WhereIteratorCls>(_iterable->iterator(), _f);
}

template<typename E>
template<typename T>
Iterable<T> WhereIterableCls<E>::map(std::function<T(E element)> toElement) {
    return <E, T>_(this, toElement);
}

template<typename E>
bool WhereIteratorCls<E>::moveNext() {
    while (_iterator->moveNext()) {
        if (_f(_iterator->current())) {
            return true;
        }
    }
    return false;
}

template<typename E>
E WhereIteratorCls<E>::current() {
    return _iterator->current();
}

template<typename S, typename T>
Iterator<T> ExpandIterableCls<S, T>::iterator() {
    return <S, T>make<ExpandIteratorCls>(_iterable->iterator(), _f);
}

template<typename S, typename T>
T ExpandIteratorCls<S, T>::current() {
    return as<T>(_current);
}

template<typename S, typename T>
bool ExpandIteratorCls<S, T>::moveNext() {
    if (_currentExpansion == nullptr) {
        return false;
    }
    while (!_currentExpansion!->moveNext()) {
        _current = nullptr;
        if (_iterator->moveNext()) {
            _currentExpansion = nullptr;
            _currentExpansion = _f(_iterator->current())->iterator;
        } else {
            return false;
        }
    }
    _current = _currentExpansion!->current();
    return true;
}

template<typename E>
TakeIterableCls<E>::TakeIterableCls(Iterable<E> iterable, int takeCount) {
    {
        ArgumentErrorCls->checkNotNull(takeCount, __s("takeCount"));
        RangeErrorCls->checkNotNegative(takeCount, __s("takeCount"));
        if (is<EfficientLengthIterable<any>>(iterable)) {
            return <E>make<EfficientLengthTakeIterableCls>(as<EfficientLengthIterableCls>(iterable), takeCount);
        }
        return <E>_(iterable, takeCount);
    }
}

template<typename E>
Iterator<E> TakeIterableCls<E>::iterator() {
    return <E>make<TakeIteratorCls>(_iterable->iterator(), _takeCount);
}

template<typename E>
EfficientLengthTakeIterableCls<E>::EfficientLengthTakeIterableCls(Iterable<E> iterable, int takeCount) {
    {
        super->_(iterable, takeCount);
    }
}

template<typename E>
int EfficientLengthTakeIterableCls<E>::length() {
    int iterableLength = _iterable->length();
    if (iterableLength > _takeCount) {
        return _takeCount;
    }
    return iterableLength;
}

template<typename E>
TakeIteratorCls<E>::TakeIteratorCls(Iterator<E> _iterator, int _remaining) {
    {
        assert(_remaining >= 0);
    }
}

template<typename E>
bool TakeIteratorCls<E>::moveNext() {
    _remaining--;
    if (_remaining >= 0) {
        return _iterator->moveNext();
    }
    _remaining = -1;
    return false;
}

template<typename E>
E TakeIteratorCls<E>::current() {
    if ( < 0) {
        return as<E>(nullptr);
    }
    return _iterator->current();
}

template<typename E>
Iterator<E> TakeWhileIterableCls<E>::iterator() {
    return <E>make<TakeWhileIteratorCls>(_iterable->iterator(), _f);
}

template<typename E>
bool TakeWhileIteratorCls<E>::moveNext() {
    if (_isFinished) {
        return false;
    }
    if (!_iterator->moveNext() || !_f(_iterator->current())) {
        _isFinished = true;
        return false;
    }
    return true;
}

template<typename E>
E TakeWhileIteratorCls<E>::current() {
    if (_isFinished) {
        return as<E>(nullptr);
    }
    return _iterator->current();
}

template<typename E>
SkipIterableCls<E>::SkipIterableCls(Iterable<E> iterable, int count) {
    {
        if (is<EfficientLengthIterable<any>>(iterable)) {
            return <E>make<EfficientLengthSkipIterableCls>(as<EfficientLengthIterableCls>(iterable), count);
        }
        return <E>_(iterable, _checkCount(count));
    }
}

template<typename E>
Iterable<E> SkipIterableCls<E>::skip(int count) {
    return <E>_(_iterable, _skipCount + _checkCount(count));
}

template<typename E>
Iterator<E> SkipIterableCls<E>::iterator() {
    return <E>make<SkipIteratorCls>(_iterable->iterator(), _skipCount);
}

template<typename E>
EfficientLengthSkipIterableCls<E>::EfficientLengthSkipIterableCls(Iterable<E> iterable, int count) {
    {
        return <E>_(iterable, _checkCount(count));
    }
}

template<typename E>
int EfficientLengthSkipIterableCls<E>::length() {
    int length = _iterable->length() - _skipCount;
    if (length >= 0) {
        return length;
    }
    return 0;
}

template<typename E>
Iterable<E> EfficientLengthSkipIterableCls<E>::skip(int count) {
    return <E>_(_iterable, _skipCount + _checkCount(count));
}

template<typename E>
void EfficientLengthSkipIterableCls<E>::_(Iterable<E> iterable, int count)

int _checkCount(int count) {
    ArgumentErrorCls->checkNotNull(count, __s("count"));
    RangeErrorCls->checkNotNegative(count, __s("count"));
    return count;
}

template<typename E>
SkipIteratorCls<E>::SkipIteratorCls(Iterator<E> _iterator, int _skipCount) {
    {
        assert(_skipCount >= 0);
    }
}

template<typename E>
bool SkipIteratorCls<E>::moveNext() {
    for (;  < _skipCount; i++) {
        _iterator->moveNext();
    }
    _skipCount = 0;
    return _iterator->moveNext();
}

template<typename E>
E SkipIteratorCls<E>::current() {
    return _iterator->current();
}

template<typename E>
Iterator<E> SkipWhileIterableCls<E>::iterator() {
    return <E>make<SkipWhileIteratorCls>(_iterable->iterator(), _f);
}

template<typename E>
bool SkipWhileIteratorCls<E>::moveNext() {
    if (!_hasSkipped) {
        _hasSkipped = true;
        while (_iterator->moveNext()) {
            if (!_f(_iterator->current())) {
                return true;
            }
        }
    }
    return _iterator->moveNext();
}

template<typename E>
E SkipWhileIteratorCls<E>::current() {
    return _iterator->current();
}

template<typename E>
Iterator<E> EmptyIterableCls<E>::iterator() {
    return <Never>make<EmptyIteratorCls>();
}

template<typename E>
void EmptyIterableCls<E>::forEach(std::function<void(E element)> action) {
}

template<typename E>
bool EmptyIterableCls<E>::isEmpty() {
    return true;
}

template<typename E>
int EmptyIterableCls<E>::length() {
    return 0;
}

template<typename E>
E EmptyIterableCls<E>::first() {
    throw IterableElementErrorCls->noElement();
}

template<typename E>
E EmptyIterableCls<E>::last() {
    throw IterableElementErrorCls->noElement();
}

template<typename E>
E EmptyIterableCls<E>::single() {
    throw IterableElementErrorCls->noElement();
}

template<typename E>
E EmptyIterableCls<E>::elementAt(int index) {
    throw RangeErrorCls->range(index, 0, 0, __s("index"));
}

template<typename E>
bool EmptyIterableCls<E>::contains(Object element) {
    return false;
}

template<typename E>
bool EmptyIterableCls<E>::every(std::function<bool(E element)> test) {
    return true;
}

template<typename E>
bool EmptyIterableCls<E>::any(std::function<bool(E element)> test) {
    return false;
}

template<typename E>
E EmptyIterableCls<E>::firstWhere(std::function<bool(E element)> test, std::function<E()> orElse) {
    if (orElse != nullptr) {
        return orElse();
    }
    throw IterableElementErrorCls->noElement();
}

template<typename E>
E EmptyIterableCls<E>::lastWhere(std::function<bool(E element)> test, std::function<E()> orElse) {
    if (orElse != nullptr) {
        return orElse();
    }
    throw IterableElementErrorCls->noElement();
}

template<typename E>
E EmptyIterableCls<E>::singleWhere(std::function<bool(E element)> test, std::function<E()> orElse) {
    if (orElse != nullptr) {
        return orElse();
    }
    throw IterableElementErrorCls->noElement();
}

template<typename E>
String EmptyIterableCls<E>::join(String separator) {
    return __s("");
}

template<typename E>
Iterable<E> EmptyIterableCls<E>::where(std::function<bool(E element)> test) {
    return this;
}

template<typename E>
template<typename T>
Iterable<T> EmptyIterableCls<E>::map(std::function<T(E element)> toElement) {
    return <T>make<EmptyIterableCls>();
}

template<typename E>
E EmptyIterableCls<E>::reduce(std::function<E(E value, E element)> combine) {
    throw IterableElementErrorCls->noElement();
}

template<typename E>
template<typename T>
T EmptyIterableCls<E>::fold(T initialValue, std::function<T(T previousValue, E element)> combine) {
    return initialValue;
}

template<typename E>
Iterable<E> EmptyIterableCls<E>::skip(int count) {
    RangeErrorCls->checkNotNegative(count, __s("count"));
    return this;
}

template<typename E>
Iterable<E> EmptyIterableCls<E>::skipWhile(std::function<bool(E element)> test) {
    return this;
}

template<typename E>
Iterable<E> EmptyIterableCls<E>::take(int count) {
    RangeErrorCls->checkNotNegative(count, __s("count"));
    return this;
}

template<typename E>
Iterable<E> EmptyIterableCls<E>::takeWhile(std::function<bool(E element)> test) {
    return this;
}

template<typename E>
List<E> EmptyIterableCls<E>::toList(bool growable) {
    return <E>empty(growable);
}

template<typename E>
Set<E> EmptyIterableCls<E>::toSet() {
    return <E>make<SetCls>();
}

template<typename E>
bool EmptyIteratorCls<E>::moveNext() {
    return false;
}

template<typename E>
E EmptyIteratorCls<E>::current() {
    throw IterableElementErrorCls->noElement();
}

template<typename E>
void FollowedByIterableCls<E>::firstEfficient(EfficientLengthIterable<E> first, Iterable<E> second) {
    if (is<EfficientLengthIterable<E>>(second)) {
        return <E>make<EfficientLengthFollowedByIterableCls>(first, as<EfficientLengthIterableCls>(second));
    }
    return <E>make<FollowedByIterableCls>(first, second);
}

template<typename E>
Iterator<E> FollowedByIterableCls<E>::iterator() {
    return make<FollowedByIteratorCls>(_first, _second);
}

template<typename E>
int FollowedByIterableCls<E>::length() {
    return _first->length() + _second->length();
}

template<typename E>
bool FollowedByIterableCls<E>::isEmpty() {
    return _first->isEmpty() && _second->isEmpty();
}

template<typename E>
bool FollowedByIterableCls<E>::isNotEmpty() {
    return _first->isNotEmpty() || _second->isNotEmpty();
}

template<typename E>
bool FollowedByIterableCls<E>::contains(Object value) {
    return _first->contains(value) || _second->contains(value);
}

template<typename E>
E FollowedByIterableCls<E>::first() {
    auto iterator = _first->iterator();
    if (iterator->moveNext()) {
        return iterator->current();
    }
    return _second->first();
}

template<typename E>
E FollowedByIterableCls<E>::last() {
    auto iterator = _second->iterator();
    if (iterator->moveNext()) {
        E last = iterator->current();
        while (iterator->moveNext()) {
            last = iterator->current();
        }
        return last;
    }
    return _first->last();
}

template<typename E>
EfficientLengthFollowedByIterableCls<E>::EfficientLengthFollowedByIterableCls(EfficientLengthIterable<E> first, EfficientLengthIterable<E> second) : FollowedByIterable<E>(first, second) {
}

template<typename E>
E EfficientLengthFollowedByIterableCls<E>::elementAt(int index) {
    int firstLength = _first->length();
    if ( < firstLength) {
        return _first->elementAt(index);
    }
    return _second->elementAt(index - firstLength);
}

template<typename E>
E EfficientLengthFollowedByIterableCls<E>::first() {
    if (_first->isNotEmpty()) {
        return _first->first();
    }
    return _second->first();
}

template<typename E>
E EfficientLengthFollowedByIterableCls<E>::last() {
    if (_second->isNotEmpty()) {
        return _second->last();
    }
    return _first->last();
}

template<typename E>
FollowedByIteratorCls<E>::FollowedByIteratorCls(Iterable<E> first, Iterable<E> _nextIterable) {
    {
        _currentIterator = first->iterator();
    }
}

template<typename E>
bool FollowedByIteratorCls<E>::moveNext() {
    if (_currentIterator->moveNext()) {
        return true;
    }
    if (_nextIterable != nullptr) {
        _currentIterator = _nextIterable!->iterator();
        _nextIterable = nullptr;
        return _currentIterator->moveNext();
    }
    return false;
}

template<typename E>
E FollowedByIteratorCls<E>::current() {
    return _currentIterator->current();
}

template<typename T>
Iterator<T> WhereTypeIterableCls<T>::iterator() {
    return <T>make<WhereTypeIteratorCls>(_source->iterator());
}

template<typename T>
bool WhereTypeIteratorCls<T>::moveNext() {
    while (_source->moveNext()) {
        if (is<T>(_source->current())) {
            return true;
        }
    }
    return false;
}

template<typename T>
T WhereTypeIteratorCls<T>::current() {
    return as<T>(_source->current());
}

StateError IterableElementErrorCls::noElement() {
    return make<StateErrorCls>(__s("No element"));
}

StateError IterableElementErrorCls::tooMany() {
    return make<StateErrorCls>(__s("Too many elements"));
}

StateError IterableElementErrorCls::tooFew() {
    return make<StateErrorCls>(__s("Too few elements"));
}
