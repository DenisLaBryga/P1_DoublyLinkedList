/**
 * @file DoublyLinkedList.cpp
 * @brief Implementacja metod klasy DoublyLinkedList.
 */

#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    currentNode = nullptr;
    size = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::pushFront(int val) {
    Node* newNode = NodeFactory::createNode(val);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        currentNode = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

void DoublyLinkedList::pushBack(int val) {
    Node* newNode = NodeFactory::createNode(val);

    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
        currentNode = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

void DoublyLinkedList::insertAt(int index, int val) {
    if (index < 0 || index > size) {
        cout << "Blad: Nieprawidlowy indeks (" << index << ")!" << endl;
        return;
    }

    if (index == 0) {
        pushFront(val);
        return;
    }

    if (index == size) {
        pushBack(val);
        return;
    }

    Node* newNode = NodeFactory::createNode(val);
    Node* temp = head;

    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev->next = newNode;
    temp->prev = newNode;

    size++;
}

void DoublyLinkedList::popFront() {
    if (head == nullptr) {
        std::cout << "Lista jest pusta, nie mozna usunac elementu!" << std::endl;
        return;
    }

    Node* toDelete = head;

    if (head == tail) {
        head = nullptr;
        tail = nullptr;
        currentNode = nullptr;
    }
    else {
        if (currentNode == head) {
            currentNode = head->next;
        }
        head = head->next;
        head->prev = nullptr;
    }

    delete toDelete;
    size--;
}

void DoublyLinkedList::popBack() {
    if (tail == nullptr) {
        std::cout << "Lista jest pusta, nie mozna usunac elementu!" << std::endl;
        return;
    }

    Node* toDelete = tail;

    if (head == tail) {
        head = nullptr;
        tail = nullptr;
        currentNode = nullptr;
    }
    else {
        if (currentNode == tail) {
            currentNode = tail->prev;
        }
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete toDelete;
    size--;
}

void DoublyLinkedList::removeAt(int index) {
    if (index < 0 || index >= size) {
        std::cout << "Blad: Nieprawidlowy indeks (" << index << ")!" << std::endl;
        return;
    }

    if (index == 0) {
        popFront();
        return;
    }

    if (index == size - 1) {
        popBack();
        return;
    }

    Node* toDelete = head;
    for (int i = 0; i < index; i++) {
        toDelete = toDelete->next;
    }

    if (currentNode == toDelete) {
        currentNode = toDelete->next;
    }

    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;

    delete toDelete;
    size--;
}

void DoublyLinkedList::clear() {
    while (head != nullptr) {
        popFront();
    }
}