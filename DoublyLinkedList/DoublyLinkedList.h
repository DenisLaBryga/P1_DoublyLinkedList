#pragma once

/**
 * @file DoublyLinkedList.h
 * @brief Plik naglowkowy klasy DoublyLinkedList reprezentujacej liste dwukierunkowa.
 */

#include "Node.h"
#include "NodeFactory.h"
#include "Iterator.h"

/**
 * @class DoublyLinkedList
 * @brief Klasa implementujaca liste dwukierunkowa dzialajaca na stercie.
 */
class DoublyLinkedList {
private:
    Node* head;        ///< Wskaznik na pierwszy element listy (glowa)
    Node* tail;        ///< Wskaznik na ostatni element listy (ogon)
    Node* currentNode; ///< Wskaznik pomocniczy do nawigacji (nastepny/poprzedni element)
    int size;          ///< Aktualna liczba elementow w liscie

public:
    /**
     * @brief Konstruktor domyslny tworzacy pusta liste.
     */
    DoublyLinkedList();

    /**
     * @brief Destruktor zwalniajacy cala pamiec zajmowana przez liste na stercie.
     */
    ~DoublyLinkedList();

    /**
     * @brief Dodaje nowy element na poczatek listy.
     * @param val Wartosc do wstawienia.
     */
    void pushFront(int val);

    /**
     * @brief Dodaje nowy element na koniec listy.
     * @param val Wartosc do wstawienia.
     */
    void pushBack(int val);

    /**
     * @brief Dodaje nowy element pod wskazany indeks.
     * @param index Pozycja, na ktora ma trafic element (liczac od 0).
     * @param val Wartosc do wstawienia.
     */
    void insertAt(int index, int val);

    /**
     * @brief Usuwa element z poczatku listy.
     */
    void popFront();

    /**
     * @brief Usuwa element z konca listy.
     */
    void popBack();

    /**
     * @brief Usuwa element spod wskazanego indeksu.
     * @param index Pozycja elementu do usuniecia (liczac od 0).
     */
    void removeAt(int index);

    /**
     * @brief Wyswietla cala liste od poczatku do konca.
     */
    void displayForward() const;

    /**
     * @brief Wyswietla liste w odwrotnej kolejnosci (od konca do poczatku).
     */
    void displayBackward() const;

    /**
     * @brief Przesuwa wskaznik nawigacji i wyswietla nastepny element.
     */
    void displayNext();

    /**
     * @brief Przesuwa wskaznik nawigacji i wyswietla poprzedni element.
     */
    void displayPrev();

    /**
     * @brief Czysci cala liste i zwalnia pamiec na stercie.
     */
    void clear();
};