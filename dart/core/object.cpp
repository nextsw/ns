#include "object.hpp"
int ObjectCls::hash(Object object1, Object object10, Object object11, Object object12, Object object13, Object object14, Object object15, Object object16, Object object17, Object object18, Object object19, Object object2, Object object20, Object object3, Object object4, Object object5, Object object6, Object object7, Object object8, Object object9) {
    if (sentinelValue == object3) {
        return SystemHashCls->hash2(object1->hashCode, object2->hashCode, _hashSeed);
    }
    if (sentinelValue == object4) {
        return SystemHashCls->hash3(object1->hashCode, object2->hashCode, object3->hashCode, _hashSeed);
    }
    if (sentinelValue == object5) {
        return SystemHashCls->hash4(object1->hashCode, object2->hashCode, object3->hashCode, object4->hashCode, _hashSeed);
    }
    if (sentinelValue == object6) {
        return SystemHashCls->hash5(object1->hashCode, object2->hashCode, object3->hashCode, object4->hashCode, object5->hashCode, _hashSeed);
    }
    if (sentinelValue == object7) {
        return SystemHashCls->hash6(object1->hashCode, object2->hashCode, object3->hashCode, object4->hashCode, object5->hashCode, object6->hashCode, _hashSeed);
    }
    if (sentinelValue == object8) {
        return SystemHashCls->hash7(object1->hashCode, object2->hashCode, object3->hashCode, object4->hashCode, object5->hashCode, object6->hashCode, object7->hashCode, _hashSeed);
    }
    if (sentinelValue == object9) {
        return SystemHashCls->hash8(object1->hashCode, object2->hashCode, object3->hashCode, object4->hashCode, object5->hashCode, object6->hashCode, object7->hashCode, object8->hashCode, _hashSeed);
    }
    if (sentinelValue == object10) {
        return SystemHashCls->hash9(object1->hashCode, object2->hashCode, object3->hashCode, object4->hashCode, object5->hashCode, object6->hashCode, object7->hashCode, object8->hashCode, object9->hashCode, _hashSeed);
    }
    if (sentinelValue == object11) {
        return SystemHashCls->hash10(object1->hashCode, object2->hashCode, object3->hashCode, object4->hashCode, object5->hashCode, object6->hashCode, object7->hashCode, object8->hashCode, object9->hashCode, object10->hashCode, _hashSeed);
    }
    if (sentinelValue == object12) {
        return SystemHashCls->hash11(object1->hashCode, object2->hashCode, object3->hashCode, object4->hashCode, object5->hashCode, object6->hashCode, object7->hashCode, object8->hashCode, object9->hashCode, object10->hashCode, object11->hashCode, _hashSeed);
    }
    if (sentinelValue == object13) {
        return SystemHashCls->hash12(object1->hashCode, object2->hashCode, object3->hashCode, object4->hashCode, object5->hashCode, object6->hashCode, object7->hashCode, object8->hashCode, object9->hashCode, object10->hashCode, object11->hashCode, object12->hashCode, _hashSeed);
    }
    if (sentinelValue == object14) {
        return SystemHashCls->hash13(object1->hashCode, object2->hashCode, object3->hashCode, object4->hashCode, object5->hashCode, object6->hashCode, object7->hashCode, object8->hashCode, object9->hashCode, object10->hashCode, object11->hashCode, object12->hashCode, object13->hashCode, _hashSeed);
    }
    if (sentinelValue == object15) {
        return SystemHashCls->hash14(object1->hashCode, object2->hashCode, object3->hashCode, object4->hashCode, object5->hashCode, object6->hashCode, object7->hashCode, object8->hashCode, object9->hashCode, object10->hashCode, object11->hashCode, object12->hashCode, object13->hashCode, object14->hashCode, _hashSeed);
    }
    if (sentinelValue == object16) {
        return SystemHashCls->hash15(object1->hashCode, object2->hashCode, object3->hashCode, object4->hashCode, object5->hashCode, object6->hashCode, object7->hashCode, object8->hashCode, object9->hashCode, object10->hashCode, object11->hashCode, object12->hashCode, object13->hashCode, object14->hashCode, object15->hashCode, _hashSeed);
    }
    if (sentinelValue == object17) {
        return SystemHashCls->hash16(object1->hashCode, object2->hashCode, object3->hashCode, object4->hashCode, object5->hashCode, object6->hashCode, object7->hashCode, object8->hashCode, object9->hashCode, object10->hashCode, object11->hashCode, object12->hashCode, object13->hashCode, object14->hashCode, object15->hashCode, object16->hashCode, _hashSeed);
    }
    if (sentinelValue == object18) {
        return SystemHashCls->hash17(object1->hashCode, object2->hashCode, object3->hashCode, object4->hashCode, object5->hashCode, object6->hashCode, object7->hashCode, object8->hashCode, object9->hashCode, object10->hashCode, object11->hashCode, object12->hashCode, object13->hashCode, object14->hashCode, object15->hashCode, object16->hashCode, object17->hashCode, _hashSeed);
    }
    if (sentinelValue == object19) {
        return SystemHashCls->hash18(object1->hashCode, object2->hashCode, object3->hashCode, object4->hashCode, object5->hashCode, object6->hashCode, object7->hashCode, object8->hashCode, object9->hashCode, object10->hashCode, object11->hashCode, object12->hashCode, object13->hashCode, object14->hashCode, object15->hashCode, object16->hashCode, object17->hashCode, object18->hashCode, _hashSeed);
    }
    if (sentinelValue == object20) {
        return SystemHashCls->hash19(object1->hashCode, object2->hashCode, object3->hashCode, object4->hashCode, object5->hashCode, object6->hashCode, object7->hashCode, object8->hashCode, object9->hashCode, object10->hashCode, object11->hashCode, object12->hashCode, object13->hashCode, object14->hashCode, object15->hashCode, object16->hashCode, object17->hashCode, object18->hashCode, object19->hashCode, _hashSeed);
    }
    return SystemHashCls->hash20(object1->hashCode, object2->hashCode, object3->hashCode, object4->hashCode, object5->hashCode, object6->hashCode, object7->hashCode, object8->hashCode, object9->hashCode, object10->hashCode, object11->hashCode, object12->hashCode, object13->hashCode, object14->hashCode, object15->hashCode, object16->hashCode, object17->hashCode, object18->hashCode, object19->hashCode, object20->hashCode, _hashSeed);
}

int ObjectCls::hashAll(Iterable<Object> objects) {
    int hash = _hashSeed;
    for (auto object : objects) {
        hash = SystemHashCls->combine(hash, object->hashCode);
    }
    return SystemHashCls->finish(hash);
}

int ObjectCls::hashAllUnordered(Iterable<Object> objects) {
    int sum = 0;
    int count = 0;
    int mask = 0x3FFFFFFF;
    for (auto object : objects) {
        int objectHash = SystemHashCls->smear(object->hashCode);
        sum = (sum + objectHash) & mask;
        count = 1;
    }
    return SystemHashCls->hash2(sum, count);
}
