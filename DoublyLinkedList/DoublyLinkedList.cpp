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

void DoublyLinkedList::clear() {
    
}