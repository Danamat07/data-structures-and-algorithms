#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;

// best case: Theta(1)
// average case: O(n)
// worst case: O(n)
// complexitate generala: O(n)
MapIterator::MapIterator(const Map& d) : map(d)
{
    this -> currentPosition = 0;
    while (this->currentPosition < this->map.capacity && this->map.elems[this->currentPosition] == NULL_TELEM) {
        this->currentPosition++;
    }
}

// best case: Theta(1)
// average case: O(n)
// worst case: O(n)
// complexitate generala: O(n)
void MapIterator::first() {
    this -> currentPosition = 0;
    while (this->currentPosition < this->map.capacity && this->map.elems[this->currentPosition] == NULL_TELEM) {
        this->currentPosition++;
    }
}

// best case: Theta(1)
// average case: O(n)
// worst case: O(n)
// complexitate generala: O(n)
void MapIterator::next() {
    if (!this->valid()) {
        throw exception();
    }
    this->currentPosition++;
    while (this->currentPosition < this->map.capacity && this->map.elems[this->currentPosition] == NULL_TELEM) {
        this->currentPosition++;
    }
}

// complexitate: Theta(1)
TElem MapIterator::getCurrent(){
    if (!this->valid()) {
        throw exception();
    }
    return this->map.elems[this->currentPosition];
}

// complexitate: Theta(1)
bool MapIterator::valid() const {
    return this->currentPosition < this->map.capacity && this->map.elems[this->currentPosition] != NULL_TELEM;
}