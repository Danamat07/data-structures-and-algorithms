#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

// complexitate: Theta(n)

SortedMultiMap::SortedMultiMap(Relation r) {
    this->relation = r;
    this->capacity = 10;
    this->nrElems = 0;
    this->elements = new Node[capacity];
    for (int i=0; i<capacity-1; i++)
        this->elements[i].next = i + 1;
    this->elements[capacity-1].next = -1;
    this->keyHead = -1;
    this->firstKeyEmpty = 0;
}

// best case: Theta(1) -> adaugam perechea cheie-valoare la inceput
// average case: O(n)
// worst case: O(n)
// complexitate generala: O(n)

void SortedMultiMap::add(TKey c, TValue v) {
    if (nrElems == capacity)
        resizeUp();
    int prev = -1;
    int current = keyHead;
    while (current != -1 && !relation(elements[current].info, c)){
        prev = current;
        current = elements[current].next;
    }
    if (current != -1 && elements[current].info == c){
        int keyIndex = current;
        int valueIndex = elements[keyIndex].valueHead;
        while (elements[keyIndex].values[valueIndex].nextValue != -1) {
            valueIndex = elements[keyIndex].values[valueIndex].nextValue;
        }
        elements[keyIndex].values[valueIndex].nextValue = elements[keyIndex].valueLength;
        valueIndex = elements[keyIndex].valueLength;
        elements[keyIndex].valueLength++;
        elements[keyIndex].values[valueIndex].value = v;
        elements[keyIndex].values[valueIndex].nextValue = -1;
    } else {
        int newKeyIndex = firstKeyEmpty;
        firstKeyEmpty = elements[firstKeyEmpty].next;
        elements[newKeyIndex].info = c;
        if (prev == -1){
            elements[newKeyIndex].next = keyHead;
            keyHead = newKeyIndex;
        } else {
            elements[newKeyIndex].next = elements[prev].next;
            elements[prev].next = newKeyIndex;
        }
        elements[newKeyIndex].valueHead = 0;
        elements[newKeyIndex].valueLength = 1;
        elements[newKeyIndex].valueCapacity = 3;
        elements[newKeyIndex].values = new ValueNode[elements[newKeyIndex].valueCapacity];
        elements[newKeyIndex].values[0].value = v;
        elements[newKeyIndex].values[0].nextValue = -1;
        nrElems++;
    }
}

// best case: Theta(1) -> stergem prima cheie si prima ei valoare
// average case: O(n)
// worst case: O(n)
// complexitate generala: O(n)

bool SortedMultiMap::remove(TKey c, TValue v) {
    int prev = -1;
    int current = keyHead;
    while (current != -1 && elements[current].info != c){
        prev = current;
        current = elements[current].next;
    }
    if (current == -1)
        return false;
    int prevValue = -1;
    int valueIndex = elements[current].valueHead;
    while (valueIndex != -1 && elements[current].values[valueIndex].value != v){
        prevValue = valueIndex;
        valueIndex = elements[current].values[valueIndex].nextValue;
    }
    if (valueIndex == -1)
        return false;
    if (prevValue == -1) {
        elements[current].valueHead = elements[current].values[valueIndex].nextValue;
    } else {
        elements[current].values[prevValue].nextValue = elements[current].values[valueIndex].nextValue;
    }
    elements[current].values[valueIndex].nextValue = elements[current].firstValueEmpty;
    elements[current].firstValueEmpty = valueIndex;
    elements[current].valueLength--;
    if (elements[current].valueHead == -1) {
        if (prev == -1) {
            keyHead = elements[current].next;
        } else {
            elements[prev].next = elements[current].next;
        }
        elements[current].next = firstKeyEmpty;
        firstKeyEmpty = current;
        nrElems--;
        if (nrElems < capacity/2)
            resizeDown();
    }
    return true;
}

// best case: O(n) -> facem resize doar pt chei
// average case: O(n)
// worst case: O(n^2) -> facem resize si pt chei, si pt valori
// complexitate generala: O(n)

void SortedMultiMap::resizeUp() {
    int newCapacity = capacity * 2;
    Node* newElements = new Node[newCapacity];
    for (int i = 0; i < capacity; i++) {
        newElements[i] = elements[i];
    }
    for (int i = capacity; i < newCapacity - 1; i++) {
        newElements[i].next = i + 1;
    }
    newElements[newCapacity - 1].next = -1;
    delete[] elements;
    elements = newElements;
    capacity = newCapacity;
    for (int i = 0; i < capacity / 2; i++) {
        if (elements[i].info != NULL_TVALUE) {
            if (elements[i].valueLength == elements[i].valueCapacity){
                int valueCapacity = elements[i].valueCapacity * 2;
                ValueNode* newValues = new ValueNode[valueCapacity];
                for (int j = 0; j < elements[i].valueLength; j++) {
                    newValues[j] = elements[i].values[j];
                }
                for (int j = elements[i].valueLength; j < valueCapacity - 1; j++) {
                    newValues[j].nextValue = j + 1;
                }
                newValues[valueCapacity - 1].nextValue = -1;
                delete[] elements[i].values;
                elements[i].values = newValues;
                elements[i].valueCapacity = valueCapacity;
            }
        }
    }
}

// best case: O(n) -> facem resize doar pt chei
// average case: O(n)
// worst case: O(n^2) -> facem resize si pt chei, si pt valori
// complexitate generala: O(n)

void SortedMultiMap::resizeDown() {
    int newCapacity = capacity / 2;
    Node* newElements = new Node[newCapacity];
    for (int i = 0; i < newCapacity; i++) {
        newElements[i] = elements[i];
    }
    for (int i = newCapacity; i < capacity - 1; i++) {
        newElements[i].next = i + 1;
    }
    newElements[capacity - 1].next = -1;
    delete[] elements;
    elements = newElements;
    capacity = newCapacity;
    for (int i = 0; i < newCapacity; i++) {
        if (elements[i].info != NULL_TVALUE) {
            if (elements[i].valueLength < elements[i].valueCapacity/2){
                int valueCapacity = elements[i].valueCapacity / 2;
                ValueNode* newValues = new ValueNode[valueCapacity];
                for (int j = 0; j < elements[i].valueLength; j++) {
                    newValues[j] = elements[i].values[j];
                }
                for (int j = elements[i].valueLength; j < valueCapacity - 1; j++) {
                    newValues[j].nextValue = j + 1;
                }
                newValues[valueCapacity - 1].nextValue = -1;
                delete[] elements[i].values;
                elements[i].values = newValues;
                elements[i].valueCapacity = valueCapacity;
            }
        }
    }
}

// best case: Theta(1) -> cheia cautata este prima si are o singura valoare
// average case: O(n) -> cheia cautata nu este prima dar are numai o valoare
// worst case: O(n+m)
// complexitate generala: O(n)

vector<TValue> SortedMultiMap::search(TKey c) const {
    vector<TValue> values;
    int currentKeyIndex = keyHead;
    while (currentKeyIndex != -1) {
        if (elements[currentKeyIndex].info == c) {
            int currentValueIndex = elements[currentKeyIndex].valueHead;
            while (currentValueIndex != -1) {
                values.push_back(elements[currentKeyIndex].values[currentValueIndex].value);
                currentValueIndex = elements[currentKeyIndex].values[currentValueIndex].nextValue;
            }
            return values;
        }
        currentKeyIndex = elements[currentKeyIndex].next;
    }
    return values;
}

// best case: Theta(1) -> exista o singura cheie
// average case: O(n)
// worst case: O(n)
// complexitate generala: O(n)

int SortedMultiMap::size() const {
    int count = 0;
    int currentKeyIndex = keyHead;
    while (currentKeyIndex != -1){
        count += elements[currentKeyIndex].valueLength;
        currentKeyIndex = elements[currentKeyIndex].next;
    }
    return count;
}

// complexitate: Theta(1)

bool SortedMultiMap::isEmpty() const {
    return nrElems == 0;
}

// complexitate: Theta(1)

SMMIterator SortedMultiMap::iterator() const {
    return SMMIterator(*this);
}

// complexitate: Theta(1)

SortedMultiMap::~SortedMultiMap() {
    delete[] elements;
}