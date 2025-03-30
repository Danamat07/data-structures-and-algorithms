#include "ListIterator.h"
#include "IndexedList.h"
#include <exception>

ListIterator::ListIterator(const IndexedList& list) : list(list) {
    current = list.head;
}

// complexitate: Theta(1)

void ListIterator::first(){
    current = list.head;
}

// complexitate: Theta(1)

void ListIterator::next(){
    if (!valid()) {
        throw std::exception();
    }
    current = current -> next;
}

// complexitate: Theta(1)

bool ListIterator::valid() const{
    return current != nullptr;
}

// complexitate: Theta(1)

TElem ListIterator::getCurrent() const {
    if (!valid()) {
        throw std::exception();
    }
    return current -> list;
}