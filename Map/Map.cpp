#include "Map.h"
#include "MapIterator.h"

// complexitate: Theta(n)

Map::Map() {
    this->capacity = 10;
    this->length = 0;
    this->elems = new TElem[this->capacity];
    for (int i = 0; i < this->capacity; i++) {
        this->elems[i] = {-111111, NULL_TVALUE};
    }
}

// complexitate: Theta(1)

Map::~Map() {
    delete[] this->elems;
}

// complexitate: Theta(1)

int Map::h_prim(TKey c) const {
    return (c % this->capacity + this->capacity) % this->capacity;
}

// complexitate: Theta(1)

int Map::h(TKey c, int i) const {
    int c1 = 1;
    int c2 = 1;
    return (h_prim(c) + c1 * i + c2 * i * i) % this->capacity;
}

// complexitate: Theta(n)

TValue Map::add(TKey c, TValue v){
    if (this->length >= this->capacity / 2) {
        resize();
    }
    for (int i = 0; i < this->capacity; i++) {
        int pos = h(c, i);
        if (this->elems[pos].first == -111111 || this->elems[pos].first == c) {
            TValue oldValue = this->elems[pos].second;
            this->elems[pos] = {c, v};
            if (oldValue == NULL_TVALUE) {
                this->length++;
            }
            return oldValue;
        }
    }
    return NULL_TVALUE;
}

// complexitate: Theta(n)

TValue Map::search(TKey c) const{
    for (int i = 0; i < this->capacity; i++) {
        int pos = h(c, i);
        if (this->elems[pos].first == -111111) {
            return NULL_TVALUE;
        }
        if (this->elems[pos].first == c) {
            return this->elems[pos].second;
        }
    }
    return NULL_TVALUE;
}

// complexitate: Theta(n)

TValue Map::remove(TKey c){
    for (int i = 0; i < this->capacity; i++) {
        int pos = h(c, i);
        if (this->elems[pos].first == -111111) {
            return NULL_TVALUE;
        }
        if (this->elems[pos].first == c) {
            TValue oldValue = this->elems[pos].second;
            this->elems[pos] = {-111111, NULL_TVALUE};
            this->length--;
            return oldValue;
        }
    }
    return NULL_TVALUE;
}

// complexitate: Theta(1)

int Map::size() const {
    return this->length;
}

// complexitate: Theta(1)

bool Map::isEmpty() const{
    return this->length == 0;
}

// complexitate: Theta(1)

MapIterator Map::iterator() const {
    return MapIterator(*this);
}

// best case: O(n)
// average case: O(n)
// worst case: O(n^2)
// complexitate generala: O(n)

void Map::resize() {
    int oldCapacity = this->capacity;
    this->capacity *= 2;
    TElem* newElems = new TElem[this->capacity];
    for (int i = 0; i < this->capacity; i++) {
        newElems[i] = {-111111, NULL_TVALUE};
    }
    for (int i = 0; i < oldCapacity; i++) {
        if (this->elems[i].first != -111111) {
            int j = 0;
            int pos;
            do {
                pos = h(this->elems[i].first, j);
                j++;
            } while (newElems[pos].first != -111111);
            newElems[pos] = this->elems[i];
        }
    }
    delete[] this->elems;
    this->elems = newElems;
}
