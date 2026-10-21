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
        cout << "Blad: Nieprawidlowy indeks (" << index << ")" << endl;
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
        cout << "Lista jest pusta, nie mozna usunac elementu" << endl;
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
        cout << "Lista jest pusta, nie mozna usunac elementu" << endl;
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
        cout << "Blad: Nieprawidlowy indeks (" << index << ")" << endl;
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

void DoublyLinkedList::displayForward() const {
    if (head == nullptr) {
        cout << "Lista jest pusta" << endl;
        return;
    }

    Iterator it(head);
    std::cout << "Lista (od poczatku): ";
    while (it.isValid()) {
        cout << it.getData() << " ";
        it.next();
    }
    cout << endl;
}

void DoublyLinkedList::displayBackward() const {
    if (tail == nullptr) {
        std::cout << "Lista jest pusta" << std::endl;
        return;
    }

    Iterator it(tail);
    cout << "Lista (od konca): ";
    while (it.isValid()) {
        std::cout << it.getData() << " ";
        it.prev();
    }
    cout << endl;
}

void DoublyLinkedList::displayNext() {
    if (currentNode == nullptr) {
        cout << "Lista jest pusta" << endl;
        return;
    }

    if (currentNode->next != nullptr) {
        currentNode = currentNode->next;
        cout << "Nastepny element: " << currentNode->data << endl;
    }
    else {
        cout << "Koniec listy. Aktualny element to nadal: " << currentNode->data << endl;
    }
}

void DoublyLinkedList::displayPrev() {
    if (currentNode == nullptr) {
        cout << "Lista jest pusta" << endl;
        return;
    }

    if (currentNode->prev != nullptr) {
        currentNode = currentNode->prev;
        cout << "Poprzedni element: " << currentNode->data << endl;
    }
    else {
        cout << "Poczatek listy. Aktualny element to nadal: " << currentNode->data << endl;
    }
}