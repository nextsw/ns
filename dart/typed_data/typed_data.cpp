#include "typed_data.hpp"
void ByteDataCls::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer->asByteData(offsetInBytes, length);
}

void ByteDataCls::sublistView(TypedData data, int end, int start) {
    int elementSize = data->elementSizeInBytes;
    end = RangeErrorCls->checkValidRange(start, end, data->lengthInBytes ~/ elementSize);
    return data->buffer->asByteData(data->offsetInBytes + start * elementSize, (end - start) * elementSize);
}

void Int8ListCls::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer->asInt8List(offsetInBytes, length);
}

void Int8ListCls::sublistView(TypedData data, int end, int start) {
    int elementSize = data->elementSizeInBytes;
    end = RangeErrorCls->checkValidRange(start, end, data->lengthInBytes ~/ elementSize);
    return data->buffer->asInt8List(data->offsetInBytes + start * elementSize, (end - start) * elementSize);
}

void Uint8ListCls::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer->asUint8List(offsetInBytes, length);
}

void Uint8ListCls::sublistView(TypedData data, int end, int start) {
    int elementSize = data->elementSizeInBytes;
    end = RangeErrorCls->checkValidRange(start, end, data->lengthInBytes ~/ elementSize);
    return data->buffer->asUint8List(data->offsetInBytes + start * elementSize, (end - start) * elementSize);
}

void Uint8ClampedListCls::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer->asUint8ClampedList(offsetInBytes, length);
}

void Uint8ClampedListCls::sublistView(TypedData data, int end, int start) {
    int elementSize = data->elementSizeInBytes;
    end = RangeErrorCls->checkValidRange(start, end, data->lengthInBytes ~/ elementSize);
    return data->buffer->asUint8ClampedList(data->offsetInBytes + start * elementSize, (end - start) * elementSize);
}

void Int16ListCls::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer->asInt16List(offsetInBytes, length);
}

void Int16ListCls::sublistView(TypedData data, int end, int start) {
    int elementSize = data->elementSizeInBytes;
    end = RangeErrorCls->checkValidRange(start, end, data->lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data->buffer->asInt16List(data->offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Uint16ListCls::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer->asUint16List(offsetInBytes, length);
}

void Uint16ListCls::sublistView(TypedData data, int end, int start) {
    int elementSize = data->elementSizeInBytes;
    end = RangeErrorCls->checkValidRange(start, end, data->lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data->buffer->asUint16List(data->offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Int32ListCls::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer->asInt32List(offsetInBytes, length);
}

void Int32ListCls::sublistView(TypedData data, int end, int start) {
    int elementSize = data->elementSizeInBytes;
    end = RangeErrorCls->checkValidRange(start, end, data->lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data->buffer->asInt32List(data->offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Uint32ListCls::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer->asUint32List(offsetInBytes, length);
}

void Uint32ListCls::sublistView(TypedData data, int end, int start) {
    int elementSize = data->elementSizeInBytes;
    end = RangeErrorCls->checkValidRange(start, end, data->lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data->buffer->asUint32List(data->offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Int64ListCls::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer->asInt64List(offsetInBytes, length);
}

void Int64ListCls::sublistView(TypedData data, int end, int start) {
    int elementSize = data->elementSizeInBytes;
    end = RangeErrorCls->checkValidRange(start, end, data->lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data->buffer->asInt64List(data->offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Uint64ListCls::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer->asUint64List(offsetInBytes, length);
}

void Uint64ListCls::sublistView(TypedData data, int end, int start) {
    int elementSize = data->elementSizeInBytes;
    end = RangeErrorCls->checkValidRange(start, end, data->lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data->buffer->asUint64List(data->offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Float32ListCls::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer->asFloat32List(offsetInBytes, length);
}

void Float32ListCls::sublistView(TypedData data, int end, int start) {
    int elementSize = data->elementSizeInBytes;
    end = RangeErrorCls->checkValidRange(start, end, data->lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data->buffer->asFloat32List(data->offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Float64ListCls::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer->asFloat64List(offsetInBytes, length);
}

void Float64ListCls::sublistView(TypedData data, int end, int start) {
    int elementSize = data->elementSizeInBytes;
    end = RangeErrorCls->checkValidRange(start, end, data->lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data->buffer->asFloat64List(data->offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Float32x4ListCls::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer->asFloat32x4List(offsetInBytes, length);
}

void Float32x4ListCls::sublistView(TypedData data, int end, int start) {
    int elementSize = data->elementSizeInBytes;
    end = RangeErrorCls->checkValidRange(start, end, data->lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data->buffer->asFloat32x4List(data->offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Int32x4ListCls::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer->asInt32x4List(offsetInBytes, length);
}

void Int32x4ListCls::sublistView(TypedData data, int end, int start) {
    int elementSize = data->elementSizeInBytes;
    end = RangeErrorCls->checkValidRange(start, end, data->lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data->buffer->asInt32x4List(data->offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}

void Float64x2ListCls::view(ByteBuffer buffer, int length, int offsetInBytes) {
    return buffer->asFloat64x2List(offsetInBytes, length);
}

void Float64x2ListCls::sublistView(TypedData data, int end, int start) {
    int elementSize = data->elementSizeInBytes;
    end = RangeErrorCls->checkValidRange(start, end, data->lengthInBytes ~/ elementSize);
    int byteLength = (end - start) * elementSize;
    if (byteLength % bytesPerElement != 0) {
        ;
    }
    return data->buffer->asFloat64x2List(data->offsetInBytes + start * elementSize, byteLength ~/ bytesPerElement);
}
