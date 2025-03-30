#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
    currentPosition = 0;
}

// complexitate Theta(1)
TComp SortedBagIterator::getCurrent() {
    if (!valid()){
        throw exception();
    }
    return bag.elements[currentPosition];
}

// complexitate Theta(1)
bool SortedBagIterator::valid() {
    return currentPosition >= 0 && currentPosition < bag.length;
}

// complexitate Theta(1)
void SortedBagIterator::next() {
    if (currentPosition < bag.length){
        currentPosition++;
    }
    else{
        throw exception();
    }
}

// complexitate Theta(1)
void SortedBagIterator::first() {
    currentPosition = 0;
}