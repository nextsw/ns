#include "typed_data.hpp"
void ByteData::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer.asByteData(offsetInBytes, length);
}

void ByteData::sublistView(TypedData data, int end, int start) {
    int elementSize = data.elementSizeInBytes;
    end = RangeError.checkValidRange(start, end, data.lengthInBytes ~/ elementSize);
    return data.buffer.asByteData(data.offsetInBytes + start * elementSize, (end - start) * elementSize);
}

void Int8List::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer.asInt8List(offsetInBytes, length);
}

void Int8List::sublistView(TypedData data, int end, int start) {
    int elementSize = data.elementSizeInBytes;
    end = RangeError.checkValidRange(start, end, data.lengthInBytes ~/ elementSize);
    return data.buffer.asInt8List(data.offsetInBytes + start * elementSize, (end - start) * elementSize);
}

void Uint8List::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer.asUint8List(offsetInBytes, length);
}

void Uint8List::sublistView(TypedData data, int end, int start) {
    int elementSize = data.elementSizeInBytes;
    end = RangeError.checkValidRange(start, end, data.lengthInBytes ~/ elementSize);
    return data.buffer.asUint8List(data.offsetInBytes + start * elementSize, (end - start) * elementSize);
}

void Uint8ClampedList::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer.asUint8ClampedList(offsetInBytes, length);
}

void Uint8ClampedList::sublistView(TypedData data, int end, int start) {
    int elementSize = data.elementSizeInBytes;
    end = RangeError.checkValidRange(start, end, data.lengthInBytes ~/ elementSize);
    return data.buffer.asUint8ClampedList(data.offsetInBytes + start * elementSize, (end - start) * elementSize);
}

void Int16List::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer.asInt16List(offsetInBytes, length);
}

void Int16List::sublistView(TypedData data, int end, int start) {
    int elementSize = data.elementSizeInBytes;
    end = RangeError.checkValidRange(start, end, data.lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data.buffer.asInt16List(data.offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Uint16List::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer.asUint16List(offsetInBytes, length);
}

void Uint16List::sublistView(TypedData data, int end, int start) {
    int elementSize = data.elementSizeInBytes;
    end = RangeError.checkValidRange(start, end, data.lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data.buffer.asUint16List(data.offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Int32List::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer.asInt32List(offsetInBytes, length);
}

void Int32List::sublistView(TypedData data, int end, int start) {
    int elementSize = data.elementSizeInBytes;
    end = RangeError.checkValidRange(start, end, data.lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data.buffer.asInt32List(data.offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Uint32List::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer.asUint32List(offsetInBytes, length);
}

void Uint32List::sublistView(TypedData data, int end, int start) {
    int elementSize = data.elementSizeInBytes;
    end = RangeError.checkValidRange(start, end, data.lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data.buffer.asUint32List(data.offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Int64List::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer.asInt64List(offsetInBytes, length);
}

void Int64List::sublistView(TypedData data, int end, int start) {
    int elementSize = data.elementSizeInBytes;
    end = RangeError.checkValidRange(start, end, data.lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data.buffer.asInt64List(data.offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Uint64List::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer.asUint64List(offsetInBytes, length);
}

void Uint64List::sublistView(TypedData data, int end, int start) {
    int elementSize = data.elementSizeInBytes;
    end = RangeError.checkValidRange(start, end, data.lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data.buffer.asUint64List(data.offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Float32List::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer.asFloat32List(offsetInBytes, length);
}

void Float32List::sublistView(TypedData data, int end, int start) {
    int elementSize = data.elementSizeInBytes;
    end = RangeError.checkValidRange(start, end, data.lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data.buffer.asFloat32List(data.offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Float64List::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer.asFloat64List(offsetInBytes, length);
}

void Float64List::sublistView(TypedData data, int end, int start) {
    int elementSize = data.elementSizeInBytes;
    end = RangeError.checkValidRange(start, end, data.lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data.buffer.asFloat64List(data.offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Float32x4List::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer.asFloat32x4List(offsetInBytes, length);
}

void Float32x4List::sublistView(TypedData data, int end, int start) {
    int elementSize = data.elementSizeInBytes;
    end = RangeError.checkValidRange(start, end, data.lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data.buffer.asFloat32x4List(data.offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Int32x4List::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer.asInt32x4List(offsetInBytes, length);
}

void Int32x4List::sublistView(TypedData data, int end, int start) {
    int elementSize = data.elementSizeInBytes;
    end = RangeError.checkValidRange(start, end, data.lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data.buffer.asInt32x4List(data.offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Float64x2List::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer.asFloat64x2List(offsetInBytes, length);
}

void Float64x2List::sublistView(TypedData data, int end, int start) {
    int elementSize = data.elementSizeInBytes;
    end = RangeError.checkValidRange(start, end, data.lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data.buffer.asFloat64x2List(data.offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}
