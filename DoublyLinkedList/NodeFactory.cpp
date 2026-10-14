/**
 * @file NodeFactory.cpp
 * @brief Implementacja metod klasy NodeFactory.
 */

#include "NodeFactory.h"

Node* NodeFactory::createNode(int val) {
    return new Node(val);
}