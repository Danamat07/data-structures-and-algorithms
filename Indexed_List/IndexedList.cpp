#include <exception>

#include "IndexedList.h"
#include "ListIterator.h"

IndexedList::IndexedList() {
    head = nullptr;
    length = 0;
}

// complexitate: Theta(1)

int IndexedList::size() const {
    return length;
}

// complexitate: Theta(1)

bool IndexedList::isEmpty() const {
    return length == 0;
}

// best case: Theta(1) -> elem e primul din lista
// average si worst case: O(n)
// complexitate generala: O(n)

TElem IndexedList::getElement(int pos) const {
    if (pos < 0 || pos >= length){
        throw std::exception();
    }
    Node* current = head;
    for (int i=0; i<pos; i++){
        current = current -> next;
    }
    return current -> list;
}

// best case: Theta(1) -> elem e primul din lista
// average si worst case: O(n)
// complexitate generala: O(n)

TElem IndexedList::setElement(int pos, TElem e) {
    if (pos < 0 || pos >= length){
        throw std::exception();
    }
    Node* current = head;
    for (int i=0; i<pos; i++){
        current = current -> next;
    }
    TElem old_elem = current -> list;
    current -> list = e;
    return old_elem;
}

// best case: Theta(1) -> lista e goala
// average si worst case: O(n)
// complexitate generala: O(n)

void IndexedList::addToEnd(TElem e) {
    Node* new_node = new Node{e, nullptr};
    if (isEmpty()){
        head = new_node;
    } else {
        Node* current = head;
        while (current -> next != nullptr){
            current = current -> next;
        }
        current -> next = new_node;
    }
    length++;
}

// best case: Theta(1) -> elem trebuie pus la inceputul listei
// average si worst case: O(n) -> elem trebuie pus la mijloc sau final
// complexitate generala: O(n)

void IndexedList::addToPosition(int pos, TElem e) {
    if (pos < 0 || pos >= length){
        throw std::exception();
    }
    if (pos == length){
        addToEnd(e);
        return;
    }
    if (pos == 0){
        head = new Node{e, head};
    } else {
        Node* current = head;
        for (int i=0; i<pos-1; i++){
            current = current -> next;
        }
        current -> next = new Node{e, current -> next};
    }
    length++;
}

// best case: Theta(1) -> elem e primul din lista
// average si worst case: O(n)
// complexitate generala: O(n)

TElem IndexedList::remove(int pos) {
    if (pos < 0 || pos >= length){
        throw std::exception();
    }
    Node* current = head;
    TElem removed;
    if (pos == 0){
        head = head -> next;
        removed = current -> list;
        delete current;
    } else {
        for (int i=0; i<pos-1; i++){
            current = current -> next;
        }
        Node* jump = current -> next;
        current -> next = jump -> next;
        removed = jump -> list;
        delete jump;
    }
    length--;
    return removed;
}

// best case: Theta(1) -> elem e primul din lista
// average si worst case: O(n)
// complexitate generala: O(n)

int IndexedList::search(TElem e) const{
    int index = 0;
    Node* current = head;
    while (current != nullptr){
        if (current -> list == e){
            return index;
        }
        current = current -> next;
        index++;
    }
    return -1;
}

// complexitate: Theta(1)

ListIterator IndexedList::iterator() const {
    return ListIterator(*this);
}

// complexitate: O(n)

IndexedList::~IndexedList() {
    Node* current = head;
    while (current != nullptr){
        Node* temp = current -> next;
        delete current;
        current = temp;
    }
}