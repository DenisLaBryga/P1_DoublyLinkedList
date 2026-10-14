#pragma once

/**
 * @file NodeFactory.h
 * @brief Plik naglowkowy klasy NodeFactory realizujacej wzorzec projektowy Fabryki.
 */

#include "Node.h"

/**
 * @class NodeFactory
 * @brief Klasa fabryki odpowiedzialna za tworzenie nowych wezlow na stercie.
 */

class NodeFactory {
public:
    /**
     * @brief Tworzy nowy obiekt klasy Node na stercie.
     * @param val Wartosc, ktora zostanie przypisana do nowego wezla.
     * @return Wskaznik na nowo utworzony wezel na stercie.
     */
    static Node* createNode(int val);
};