#include <iostream>
#include "NodeFactory.h"
#include "Iterator.h"
using namespace std;

int main() {
    Node* testNode = NodeFactory::createNode(10);
    Iterator it = Iterator(testNode);
    cout << it.getData() << endl;
    cout << "Utworzono wezel o wartosci: " << testNode->data << endl;
    delete testNode;
    return 0;
}