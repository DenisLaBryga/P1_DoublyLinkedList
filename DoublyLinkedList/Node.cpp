/**
 * @file Node.cpp
 * @brief Implementacja metod klasy Node.
 */

#include "Node.h"

Node::Node(int val) {
    data = val;
    next = nullptr;
    prev = nullptr;
}