#include "SMMIterator.h"
#include "SortedMultiMap.h"

// complexitate: Theta(1)

SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d){
    currentValueIndex = map.elements[map.keyHead].valueHead;
    currentKeyIndex = map.keyHead;
}

// complexitate: Theta(1)

void SMMIterator::first(){
    currentKeyIndex = map.keyHead;
    currentValueIndex = map.elements[map.keyHead].valueHead;
}

// complexitate: Theta(1)

void SMMIterator::next(){
    if (!valid()){
        throw exception();
    }
    if (map.elements[currentKeyIndex].values[currentValueIndex].nextValue != -1){
        currentValueIndex = map.elements[currentKeyIndex].values[currentValueIndex].nextValue;
    } else {
        currentKeyIndex = map.elements[currentKeyIndex].next;
        currentValueIndex = map.elements[currentKeyIndex].valueHead;
    }
}

// complexitate: Theta(1)

bool SMMIterator::valid() const{
    return currentKeyIndex != -1;
}

// complexitate: Theta(1)

TElem SMMIterator::getCurrent() const{
    if (!valid()){
        throw exception();
    }
    TKey currentKey = map.elements[currentKeyIndex].info;
    TValue currentValue = map.elements[currentKeyIndex].values[currentValueIndex].value;
    TElem currentPair;
    currentPair.first = currentKey;
    currentPair.second = currentValue;
    return currentPair;
}