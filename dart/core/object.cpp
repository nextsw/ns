#include "object.hpp"
int Object::hash(Object object1, Object object10, Object object11, Object object12, Object object13, Object object14, Object object15, Object object16, Object object17, Object object18, Object object19, Object object2, Object object20, Object object3, Object object4, Object object5, Object object6, Object object7, Object object8, Object object9) {
    if (sentinelValue == object3) {
        return SystemHash.hash2(object1.hashCode, object2.hashCode, _hashSeed);
    }
    if (sentinelValue == object4) {
        return SystemHash.hash3(object1.hashCode, object2.hashCode, object3.hashCode, _hashSeed);
    }
    if (sentinelValue == object5) {
        return SystemHash.hash4(object1.hashCode, object2.hashCode, object3.hashCode, object4.hashCode, _hashSeed);
    }
    if (sentinelValue == object6) {
        return SystemHash.hash5(object1.hashCode, object2.hashCode, object3.hashCode, object4.hashCode, object5.hashCode, _hashSeed);
    }
    if (sentinelValue == object7) {
        return SystemHash.hash6(object1.hashCode, object2.hashCode, object3.hashCode, object4.hashCode, object5.hashCode, object6.hashCode, _hashSeed);
    }
    if (sentinelValue == object8) {
        return SystemHash.hash7(object1.hashCode, object2.hashCode, object3.hashCode, object4.hashCode, object5.hashCode, object6.hashCode, object7.hashCode, _hashSeed);
    }
    if (sentinelValue == object9) {
        return SystemHash.hash8(object1.hashCode, object2.hashCode, object3.hashCode, object4.hashCode, object5.hashCode, object6.hashCode, object7.hashCode, object8.hashCode, _hashSeed);
    }
    if (sentinelValue == object10) {
        return SystemHash.hash9(object1.hashCode, object2.hashCode, object3.hashCode, object4.hashCode, object5.hashCode, object6.hashCode, object7.hashCode, object8.hashCode, object9.hashCode, _hashSeed);
    }
    if (sentinelValue == object11) {
        return SystemHash.hash10(object1.hashCode, object2.hashCode, object3.hashCode, object4.hashCode, object5.hashCode, object6.hashCode, object7.hashCode, object8.hashCode, object9.hashCode, object10.hashCode, _hashSeed);
    }
    if (sentinelValue == object12) {
        return SystemHash.hash11(object1.hashCode, object2.hashCode, object3.hashCode, object4.hashCode, object5.hashCode, object6.hashCode, object7.hashCode, object8.hashCode, object9.hashCode, object10.hashCode, object11.hashCode, _hashSeed);
    }
    if (sentinelValue == object13) {
        return SystemHash.hash12(object1.hashCode, object2.hashCode, object3.hashCode, object4.hashCode, object5.hashCode, object6.hashCode, object7.hashCode, object8.hashCode, object9.hashCode, object10.hashCode, object11.hashCode, object12.hashCode, _hashSeed);
    }
    if (sentinelValue == object14) {
        return SystemHash.hash13(object1.hashCode, object2.hashCode, object3.hashCode, object4.hashCode, object5.hashCode, object6.hashCode, object7.hashCode, object8.hashCode, object9.hashCode, object10.hashCode, object11.hashCode, object12.hashCode, object13.hashCode, _hashSeed);
    }
    if (sentinelValue == object15) {
        return SystemHash.hash14(object1.hashCode, object2.hashCode, object3.hashCode, object4.hashCode, object5.hashCode, object6.hashCode, object7.hashCode, object8.hashCode, object9.hashCode, object10.hashCode, object11.hashCode, object12.hashCode, object13.hashCode, object14.hashCode, _hashSeed);
    }
    if (sentinelValue == object16) {
        return SystemHash.hash15(object1.hashCode, object2.hashCode, object3.hashCode, object4.hashCode, object5.hashCode, object6.hashCode, object7.hashCode, object8.hashCode, object9.hashCode, object10.hashCode, object11.hashCode, object12.hashCode, object13.hashCode, object14.hashCode, object15.hashCode, _hashSeed);
    }
    if (sentinelValue == object17) {
        return SystemHash.hash16(object1.hashCode, object2.hashCode, object3.hashCode, object4.hashCode, object5.hashCode, object6.hashCode, object7.hashCode, object8.hashCode, object9.hashCode, object10.hashCode, object11.hashCode, object12.hashCode, object13.hashCode, object14.hashCode, object15.hashCode, object16.hashCode, _hashSeed);
    }
    if (sentinelValue == object18) {
        return SystemHash.hash17(object1.hashCode, object2.hashCode, object3.hashCode, object4.hashCode, object5.hashCode, object6.hashCode, object7.hashCode, object8.hashCode, object9.hashCode, object10.hashCode, object11.hashCode, object12.hashCode, object13.hashCode, object14.hashCode, object15.hashCode, object16.hashCode, object17.hashCode, _hashSeed);
    }
    if (sentinelValue == object19) {
        return SystemHash.hash18(object1.hashCode, object2.hashCode, object3.hashCode, object4.hashCode, object5.hashCode, object6.hashCode, object7.hashCode, object8.hashCode, object9.hashCode, object10.hashCode, object11.hashCode, object12.hashCode, object13.hashCode, object14.hashCode, object15.hashCode, object16.hashCode, object17.hashCode, object18.hashCode, _hashSeed);
    }
    if (sentinelValue == object20) {
        return SystemHash.hash19(object1.hashCode, object2.hashCode, object3.hashCode, object4.hashCode, object5.hashCode, object6.hashCode, object7.hashCode, object8.hashCode, object9.hashCode, object10.hashCode, object11.hashCode, object12.hashCode, object13.hashCode, object14.hashCode, object15.hashCode, object16.hashCode, object17.hashCode, object18.hashCode, object19.hashCode, _hashSeed);
    }
    return SystemHash.hash20(object1.hashCode, object2.hashCode, object3.hashCode, object4.hashCode, object5.hashCode, object6.hashCode, object7.hashCode, object8.hashCode, object9.hashCode, object10.hashCode, object11.hashCode, object12.hashCode, object13.hashCode, object14.hashCode, object15.hashCode, object16.hashCode, object17.hashCode, object18.hashCode, object19.hashCode, object20.hashCode, _hashSeed);
}

int Object::hashAll(Iterable<Object> objects) {
    int hash = _hashSeed;
    for (auto object : objects) {
        hash = SystemHash.combine(hash, object.hashCode);
    }
    return SystemHash.finish(hash);
}

int Object::hashAllUnordered(Iterable<Object> objects) {
    int sum = 0;
    int count = 0;
    int mask = 0x3FFFFFFF;
    for (auto object : objects) {
        int objectHash = SystemHash.smear(object.hashCode);
        sum = (sum + objectHash) & mask;
        count = 1;
    }
    return SystemHash.hash2(sum, count);
}
