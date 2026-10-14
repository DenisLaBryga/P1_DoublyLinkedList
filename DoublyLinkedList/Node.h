#pragma once

/**
 * @file Node.h
 * @brief Plik naglowkowy klasy Node reprezentujacej pojedynczy wezel listy dwukierunkowej.
 */

/**
 * @class Node
 * @brief Klasa reprezentujaca element (wezel) listy dwukierunkowej.
 */

class Node {
public:
    int data;   ///< Wartosc przechowywana w wezle
    Node* next; ///< Wskaznik na nastepny wezel w liscie
    Node* prev; ///< Wskaznik na poprzedni wezel w liscie

    /**
     * @brief Konstruktor inicjalizujacy wezel podana wartoscia.
     * @param val Wartosc calkowita do zapisania w wezle.
     */
    Node(int val);
};
