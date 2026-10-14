/**
 * @file Iterator.cpp
 * @brief Implementacja metod klasy Iterator.
 */

#include "Iterator.h"

Iterator::Iterator(Node* startNode) {
    current = startNode;
}

void Iterator::next() {
    if (current != nullptr) {
        current = current->next;
    }
}

void Iterator::prev() {
    if (current != nullptr) {
        current = current->prev;
    }
}

bool Iterator::isValid() const {
    return current != nullptr;
}

int Iterator::getData() const {
    if (current != nullptr) {
        return current->data;
    }
    return 0;
}

void Iterator::setNode(Node* node) {
    current = node;
}