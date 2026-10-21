/**
 * @file main.cpp
 * @brief Glowny plik programu testujacy dzialanie listy dwukierunkowej.
 */

#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

 /**
  * @brief Glowna funkcja programu testujaca wszystkie metody klasy DoublyLinkedList.
  * @return Kod powrotu programu (0 oznacza poprawne zakonczenie).
  */
int main() {
    DoublyLinkedList list;

    cout << "1. Test dodawania elementow" << endl;
    list.pushFront(20);          // Lista: 20
    list.pushFront(10);          // Lista: 10, 20
    list.pushBack(40);           // Lista: 10, 20, 40
    list.insertAt(2, 30);        // Lista: 10, 20, 30, 40 
    list.displayForward();
    list.displayBackward();

    cout << "\n2. Test nawigacji (nastepny / poprzedni)" << endl;
    list.displayNext();          // Przejscie na kolejny element
    list.displayNext();          // Przejscie na kolejny element
    list.displayPrev();          // Cofniecie o jeden element

    cout << "\n3. Test usuwania elementow" << endl;
    cout << "Usuwanie spod indeksu 1 (wartosc 20):" << endl;
    list.removeAt(1);            // Lista: 10, 30, 40
    list.displayForward();

    cout << "Usuwanie z poczatku (wartosc 10):" << endl;
    list.popFront();             // Lista: 30, 40
    list.displayForward();

    cout << "Usuwanie z konca (wartosc 40):" << endl;
    list.popBack();              // Lista: 30
    list.displayForward();

    cout << "\n4. Test czyszczenia calej listy" << endl;
    list.clear();
    list.displayForward();

    return 0;
}