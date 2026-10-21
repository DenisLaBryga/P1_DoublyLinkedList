#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

int main() {
    DoublyLinkedList list;
    cout << "1. Test dodawania elementow" << endl;
    list.pushFront(20);          // 20
    list.pushFront(10);          // 10, 20
    list.pushBack(40);           // 10, 20, 40
    list.insertAt(2, 30);        // 10, 20, 30, 40 
}