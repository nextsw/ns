#include "internal.hpp"
int CodeUnits::length() {
    return _string.length;
}

int CodeUnits::[](int i) {
    return _string.codeUnitAt(i);
}

String CodeUnits::stringOf(CodeUnits u) {
    return u._string;
}

int hexDigitValue(int char) {
    assert(char >= 0 && char <= 0xFFFF);
    int digit0 = 0x30;
    int a = 0x61;
    int f = 0x66;
    int digit = char ^ digit0;
    if (digit <= 9)     {
        return digit;
    }
    int letter = (char | 0x20);
    if (a <= letter && letter <= f)     {
        return letter - (a - 10);
    }
    return -1;
}

int parseHexByte(int index, String source) {
    assert(index + 2 <= source.length);
    int digit1 = hexDigitValue(source.codeUnitAt(index));
    int digit2 = hexDigitValue(source.codeUnitAt(index + 1));
    return digit1 * 16 + digit2 - (digit2 & 256);
}

int SystemHash::combine(int hash, int value) {
    hash = 0x1fffffff & (hash + value);
    hash = 0x1fffffff & (hash + ((0x0007ffff & hash) << 10));
    return hash ^ (hash >> 6);
}

int SystemHash::finish(int hash) {
    hash = 0x1fffffff & (hash + ((0x03ffffff & hash) << 3));
    hash = hash ^ (hash >> 11);
    return 0x1fffffff & (hash + ((0x00003fff & hash) << 15));
}

int SystemHash::hash2(int seed, int v1, int v2) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    return finish(hash);
}

int SystemHash::hash3(int seed, int v1, int v2, int v3) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    return finish(hash);
}

int SystemHash::hash4(int seed, int v1, int v2, int v3, int v4) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    return finish(hash);
}

int SystemHash::hash5(int seed, int v1, int v2, int v3, int v4, int v5) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    hash = combine(hash, v5);
    return finish(hash);
}

int SystemHash::hash6(int seed, int v1, int v2, int v3, int v4, int v5, int v6) {
    int hash = seed;
    hash = combine(hash, v1);
    hash = combine(hash, v2);
    hash = combine(hash, v3);
    hash = combine(hash, v4);
    hash = combine(hash, v5);
    hash = combine(hash, v6);
    return finish(hash);
}

int SystemHash::hash7(int seed, int v1, int v2, int v3, int v4, int v5, int v6, int v7) {
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

int SystemHash::hash8(int seed, int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8) {
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

int SystemHash::hash9(int seed, int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9) {
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

int SystemHash::hash10(int seed, int v1, int v10, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9) {
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

int SystemHash::hash11(int seed, int v1, int v10, int v11, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9) {
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

int SystemHash::hash12(int seed, int v1, int v10, int v11, int v12, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9) {
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

int SystemHash::hash13(int seed, int v1, int v10, int v11, int v12, int v13, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9) {
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

int SystemHash::hash14(int seed, int v1, int v10, int v11, int v12, int v13, int v14, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9) {
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

int SystemHash::hash15(int seed, int v1, int v10, int v11, int v12, int v13, int v14, int v15, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9) {
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

int SystemHash::hash16(int seed, int v1, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9) {
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

int SystemHash::hash17(int seed, int v1, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int v17, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9) {
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

int SystemHash::hash18(int seed, int v1, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int v17, int v18, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9) {
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

int SystemHash::hash19(int seed, int v1, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int v17, int v18, int v19, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9) {
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

int SystemHash::hash20(int seed, int v1, int v10, int v11, int v12, int v13, int v14, int v15, int v16, int v17, int v18, int v19, int v2, int v20, int v3, int v4, int v5, int v6, int v7, int v8, int v9) {
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

int SystemHash::smear(int x) {
    x = x >> 16;
    x = (x * 0x7feb352d) & 0xFFFFFFFF;
    x = x >> 15;
    x = (x * 0x846ca68b) & 0xFFFFFFFF;
    x = x >> 16;
    return x;
}

T checkNotNullable<T extends Object>(String name, T value) {
    if ((() == nullptr) {
        ;
    }
    return value;
}

String NotNullableError::toString() {
    return "Null is not a valid value for '$_name' of type '$T'";
}

T valueOfNonNullableParamWithDefault<T extends Object>(T defaultVal, T value) {
    if ((() == nullptr) {
        return defaultVal;
    } else {
        return value;
    }
}

void DoubleLinkedQueueEntry::append(E e) {
    <E>DoubleLinkedQueueEntry(e)._link(this, _nextLink);
}

void DoubleLinkedQueueEntry::prepend(E e) {
    <E>DoubleLinkedQueueEntry(e)._link(_previousLink, this);
}

E DoubleLinkedQueueEntry::remove() {
    _previousLink?._nextLink = _nextLink;
    _nextLink?._previousLink = _previousLink;
    _nextLink = nullptr;
    _previousLink = nullptr;
    return element;
}

DoubleLinkedQueueEntry<E> DoubleLinkedQueueEntry::previousEntry() {
    return _previousLink;
}

DoubleLinkedQueueEntry<E> DoubleLinkedQueueEntry::nextEntry() {
    return _nextLink;
}

void DoubleLinkedQueueEntry::_link(DoubleLinkedQueueEntry<E> next, DoubleLinkedQueueEntry<E> previous) {
    _nextLink = next;
    _previousLink = previous;
    previous?._nextLink = this;
    next?._previousLink = this;
}
