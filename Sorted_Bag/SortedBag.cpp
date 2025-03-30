#include "SortedBag.h"
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r) {
    relation = r;
    length = 0;
    capacity = 6;
    elements = new TComp [capacity];
}

// average case : O(n) -> elementul exista in bag dar nu se afla pe prima sau ultima pozitie
// worst case: Theta(n) -> elementul se afla pe prima sau ultima pozitie din bag
void SortedBag::add(TComp e) {
    if (length == capacity){
        resize();
    }
    int pos = 0;
    while (pos < length && relation(elements[pos], e)){
        pos++;
    }
    for (int i = length; i > pos; i--) {
        elements[i] = elements[i - 1];
    }
    elements[pos] = e;
    length++;
}

// complexitate Theta(n)
void SortedBag::resize() {
    capacity *= 2;
    TComp* array = new TComp [capacity];
    for (int i = 0; i < length; i++){
        array[i] = elements[i];
    }
    delete[] elements;
    elements = array;
}

// best case: Theta(n-1) -> elementul se afla pe prima pozitie din bag
// average case: O(n) -> elementul exista in bag dar nu se afla pe prima sau ultima pozitie
// worst case: Theta(n) -> elementul nu se exista in bag sau se afla pe ultima pozitie
bool SortedBag::remove(TComp e) {
    int pos = 0;
    while (pos < length && elements[pos] != e){
        pos++;
    }
    if (pos == length){
        return false;
    }
    for (int i = pos; i < length - 1; i++){
        elements[i] = elements[i+1];
    }
    length--;
    return true;
}

// best case: Theta(1) -> elementul se afla pe prima pozitie
// average case: O(n) -> elementul exista in bag dar nu se afla pe prima sau ultima pozitie
// worst case: Theta(n) -> elementul se afla pe ultima pozitie sau nu nu exista in bag
bool SortedBag::search(TComp elem) const {
    for (int i = 0; i < length; i++){
        if (elements[i] == elem){
            return true;
        }
    }
    return false;
}

// complexitate Theta(n) -> indiferent unde se afla elementul se va parcurge mereu acelasi nr de pasi
int SortedBag::nrOccurrences(TComp elem) const {
    int count = 0;
    for (int i = 0; i < length; i++){
        if (elements[i] == elem){
            count++;
        }
    }
    return count;
}

// complexitate Theta(1)
int SortedBag::size() const {
    return length;
}

// complexitate Theta(1)
bool SortedBag::isEmpty() const {
    return length == 0;
}

// complexitate Theta(1)
SortedBagIterator SortedBag::iterator() const {
    return SortedBagIterator(*this);
}

// complexitate Theta(1)
SortedBag::~SortedBag() {
    delete[] elements;
}