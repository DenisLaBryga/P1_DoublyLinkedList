#pragma once

/**
 * @file Iterator.h
 * @brief Plik naglowkowy klasy Iterator realizujacej wzorzec projektowy Iteratora.
 */

#include "Node.h"

/**
 * @class Iterator
 * @brief Klasa umozliwiajaca przechodzenie po elementach listy dwukierunkowej.
 */
class Iterator {
private:
    Node* current; ///< Wskaznik na aktualnie wskazywany wezel listy

public:
    /**
     * @brief Konstruktor ustawiajacy iterator na wybrany wezel poczatkowy.
     * @param startNode Wskaznik na wezel, od ktorego rozpoczyna sie iteracja.
     */
    Iterator(Node* startNode = nullptr);

    /**
     * @brief Przesuwa iterator na nastepny wezel w liscie.
     */
    void next();

    /**
     * @brief Przesuwa iterator na poprzedni wezel w liscie.
     */
    void prev();

    /**
     * @brief Sprawdza, czy iterator wskazuje na istniejacy wezel (czy nie wyszedl poza liste).
     * @return true jesli wezel istnieje, false jesli wskaznik to nullptr.
     */
    bool isValid() const;

    /**
     * @brief Zwraca wartosc przechowywana w aktualnym wezle.
     * @return Wartosc calkowita z aktualnego wezla.
     */
    int getData() const;

    /**
     * @brief Ustawia iterator na nowy wybrany wezel.
     * @param node Wskaznik na wezel, na ktory ma wskazywac iterator.
     */
    void setNode(Node* node);
};
