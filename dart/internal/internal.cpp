#include "internal.hpp"
int CodeUnitsCls::length() {
    return _string->length();
}

int CodeUnitsCls::[](int i) {
    return _string->codeUnitAt(i);
}

String CodeUnitsCls::stringOf(CodeUnits u) {
    return u->_string;
}

int hexDigitValue(int charValue) {
    assert(charValue >= 0 && charValue <= 0xFFFF);
    int digit0 = 0x30;
    int a = 0x61;
    int f = 0x66;
    int digit = charValue ^ digit0;
    if (digit <= 9)     {
        return digit;
    }
    int letter = (charValue | 0x20);
    if (a <= letter && letter <= f)     {
        return letter - (a - 10);
    }
    return -1;
}

int parseHexByte(String source, int index) {
    assert(index + 2 <= source->length());
    int digit1 = hexDigitValue(source->codeUnitAt(index));
    int digit2 = hexDigitValue(source->codeUnitAt(index + 1));
    return digit1 * 16 + digit2 - (digit2 & 256);
}

int SystemHashCls::combine(int hash, int value) {
    hash = 0x1fffffff & (hash + value);
    hash = 0x1fffffff & (hash + ((0x0007ffff & hash) << 10));
    return hash ^ (hash >> 6);
}

int SystemHashCls::finish(int hash) {
    hash = 0x1fffffff & (hash + ((0x03ffffff & hash) << 3));
    hash = hash ^ (hash >> 11);
    return 0x1fffffff & (hash + ((0x00003fff & hash) << 15));
}

int SystemHashCls::hash2(int v1, int v2, int seed) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    return finish(hash);
}

int SystemHashCls::hash3(int v1, int v2, int v3, int seed) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    return finish(hash);
}

int SystemHashCls::hash4(int v1, int v2, int v3, int v4, int seed) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    return finish(hash);
}

int SystemHashCls::hash5(int v1, int v2, int v3, int v4, int v5, int seed) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    hash = combine(hash, v5);
    return finish(hash);
}

int SystemHashCls::hash6(int v1, int v2, int v3, int v4, int v5, int v6, int seed) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    hash = combine(hash, v5);
    hash = combine(hash, v6);
    return finish(hash);
}

int SystemHashCls::hash7(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int seed) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    hash = combine(hash, v5);
    hash = combine(hash, v6);
    hash = combine(hash, v7);
    return finish(hash);
}

int SystemHashCls::hash8(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int seed) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    hash = combine(hash, v5);
    hash = combine(hash, v6);
    hash = combine(hash, v7);
    hash = combine(hash, v8);
    return finish(hash);
}

int SystemHashCls::hash9(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int seed) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    hash = combine(hash, v5);
    hash = combine(hash, v6);
    hash = combine(hash, v7);
    hash = combine(hash, v8);
    hash = combine(hash, v9);
    return finish(hash);
}

int SystemHashCls::hash10(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int seed) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    hash = combine(hash, v5);
    hash = combine(hash, v6);
    hash = combine(hash, v7);
    hash = combine(hash, v8);
    hash = combine(hash, v9);
    hash = combine(hash, v10);
    return finish(hash);
}

int SystemHashCls::hash11(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int seed) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    hash = combine(hash, v5);
    hash = combine(hash, v6);
    hash = combine(hash, v7);
    hash = combine(hash, v8);
    hash = combine(hash, v9);
    hash = combine(hash, v10);
    hash = combine(hash, v11);
    return finish(hash);
}

int SystemHashCls::hash12(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int v12, int seed) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    hash = combine(hash, v5);
    hash = combine(hash, v6);
    hash = combine(hash, v7);
    hash = combine(hash, v8);
    hash = combine(hash, v9);
    hash = combine(hash, v10);
    hash = combine(hash, v11);
    hash = combine(hash, v12);
    return finish(hash);
}

int SystemHashCls::hash13(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int v12, int v13, int seed) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    hash = combine(hash, v5);
    hash = combine(hash, v6);
    hash = combine(hash, v7);
    hash = combine(hash, v8);
    hash = combine(hash, v9);
    hash = combine(hash, v10);
    hash = combine(hash, v11);
    hash = combine(hash, v12);
    hash = combine(hash, v13);
    return finish(hash);
}

int SystemHashCls::hash14(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int v12, int v13, int v14, int seed) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    hash = combine(hash, v5);
    hash = combine(hash, v6);
    hash = combine(hash, v7);
    hash = combine(hash, v8);
    hash = combine(hash, v9);
    hash = combine(hash, v10);
    hash = combine(hash, v11);
    hash = combine(hash, v12);
    hash = combine(hash, v13);
    hash = combine(hash, v14);
    return finish(hash);
}

int SystemHashCls::hash15(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int v12, int v13, int v14, int v15, int seed) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    hash = combine(hash, v5);
    hash = combine(hash, v6);
    hash = combine(hash, v7);
    hash = combine(hash, v8);
    hash = combine(hash, v9);
    hash = combine(hash, v10);
    hash = combine(hash, v11);
    hash = combine(hash, v12);
    hash = combine(hash, v13);
    hash = combine(hash, v14);
    hash = combine(hash, v15);
    return finish(hash);
}

int SystemHashCls::hash16(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int seed) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    hash = combine(hash, v5);
    hash = combine(hash, v6);
    hash = combine(hash, v7);
    hash = combine(hash, v8);
    hash = combine(hash, v9);
    hash = combine(hash, v10);
    hash = combine(hash, v11);
    hash = combine(hash, v12);
    hash = combine(hash, v13);
    hash = combine(hash, v14);
    hash = combine(hash, v15);
    hash = combine(hash, v16);
    return finish(hash);
}

int SystemHashCls::hash17(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int v17, int seed) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    hash = combine(hash, v5);
    hash = combine(hash, v6);
    hash = combine(hash, v7);
    hash = combine(hash, v8);
    hash = combine(hash, v9);
    hash = combine(hash, v10);
    hash = combine(hash, v11);
    hash = combine(hash, v12);
    hash = combine(hash, v13);
    hash = combine(hash, v14);
    hash = combine(hash, v15);
    hash = combine(hash, v16);
    hash = combine(hash, v17);
    return finish(hash);
}

int SystemHashCls::hash18(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int v17, int v18, int seed) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    hash = combine(hash, v5);
    hash = combine(hash, v6);
    hash = combine(hash, v7);
    hash = combine(hash, v8);
    hash = combine(hash, v9);
    hash = combine(hash, v10);
    hash = combine(hash, v11);
    hash = combine(hash, v12);
    hash = combine(hash, v13);
    hash = combine(hash, v14);
    hash = combine(hash, v15);
    hash = combine(hash, v16);
    hash = combine(hash, v17);
    hash = combine(hash, v18);
    return finish(hash);
}

int SystemHashCls::hash19(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int v17, int v18, int v19, int seed) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    hash = combine(hash, v5);
    hash = combine(hash, v6);
    hash = combine(hash, v7);
    hash = combine(hash, v8);
    hash = combine(hash, v9);
    hash = combine(hash, v10);
    hash = combine(hash, v11);
    hash = combine(hash, v12);
    hash = combine(hash, v13);
    hash = combine(hash, v14);
    hash = combine(hash, v15);
    hash = combine(hash, v16);
    hash = combine(hash, v17);
    hash = combine(hash, v18);
    hash = combine(hash, v19);
    return finish(hash);
}

int SystemHashCls::hash20(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int v17, int v18, int v19, int v20, int seed) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    hash = combine(hash, v5);
    hash = combine(hash, v6);
    hash = combine(hash, v7);
    hash = combine(hash, v8);
    hash = combine(hash, v9);
    hash = combine(hash, v10);
    hash = combine(hash, v11);
    hash = combine(hash, v12);
    hash = combine(hash, v13);
    hash = combine(hash, v14);
    hash = combine(hash, v15);
    hash = combine(hash, v16);
    hash = combine(hash, v17);
    hash = combine(hash, v18);
    hash = combine(hash, v19);
    hash = combine(hash, v20);
    return finish(hash);
}

int SystemHashCls::smear(int x) {
    x ^= x >> 16;
    x = (x * 0x7feb352d) & 0xFFFFFFFF;
    x ^= x >> 15;
    x = (x * 0x846ca68b) & 0xFFFFFFFF;
    x ^= x >> 16;
    return x;
}

template<typename T>
T checkNotNullable(T value, String name) {
    if ((as<dynamic>(value)) == nullptr) {
        throw <T>make<NotNullableErrorCls>(name);
    }
    return value;
}

template<typename T>
String NotNullableErrorCls<T>::toString() {
    return __s("Null is not a valid value for '$_name' of type '$T'");
}

template<typename T>
T valueOfNonNullableParamWithDefault(T value, T defaultVal) {
    if ((as<dynamic>(value)) == nullptr) {
        return defaultVal;
    } else {
        return value;
    }
}

template<typename E>
void DoubleLinkedQueueEntryCls<E>::append(E e) {
    <E>make<DoubleLinkedQueueEntryCls>(e)->_link(this, _nextLink);
}

template<typename E>
void DoubleLinkedQueueEntryCls<E>::prepend(E e) {
    <E>make<DoubleLinkedQueueEntryCls>(e)->_link(_previousLink, this);
}

template<typename E>
E DoubleLinkedQueueEntryCls<E>::remove() {
    _previousLink?->_nextLink = _nextLink;
    _nextLink?->_previousLink = _previousLink;
    _nextLink = nullptr;
    _previousLink = nullptr;
    return element;
}

template<typename E>
DoubleLinkedQueueEntry<E> DoubleLinkedQueueEntryCls<E>::previousEntry() {
    return _previousLink;
}

template<typename E>
DoubleLinkedQueueEntry<E> DoubleLinkedQueueEntryCls<E>::nextEntry() {
    return _nextLink;
}

template<typename E>
void DoubleLinkedQueueEntryCls<E>::_link(DoubleLinkedQueueEntry<E> previous, DoubleLinkedQueueEntry<E> next) {
    _nextLink = next;
    _previousLink = previous;
    previous?->_nextLink = this;
    next?->_previousLink = this;
}
