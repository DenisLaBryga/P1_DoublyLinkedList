#include <iostream>
#include "NodeFactory.h"
using namespace std;

int main() {
    Node* testNode = NodeFactory::createNode(10);
    cout << "Utworzono wezel o wartosci: " << testNode->data << endl;
    delete testNode;
    return 0;
}