//
// Created by dog on 20/02/24.
//
#include <iostream>
#include "Board.h"
#include <stack>
#include "../cards/Deck.h"
using namespace std;

Board::Board() {
    this->queue1 = new Queue();
    this->queue2 = new Queue();
    for (int i = 0; i < 7; ++i) {
        this->col[i] = new LinkedList();
    }
}

void Board::fillBoard() {
    Deck *deck = new Deck();

    for (int i = 0; i < 52; ++i) {
        if (i < 24) queue1->getInto(deck->getDeck()[i]);
        else if (i == 24) col[0]->addToFront(deck->getDeck()[i]);
        else if (i < 27) col[1]->addToFront(deck->getDeck()[i]);
        else if (i < 30) col[2]->addToFront(deck->getDeck()[i]);
        else if (i < 34) col[3]->addToFront(deck->getDeck()[i]);
        else if (i < 39) col[4]->addToFront(deck->getDeck()[i]);
        else if (i < 45) col[5]->addToFront(deck->getDeck()[i]);
        else col[6]->addToFront(deck->getDeck()[i]);
    }
    printBoard();

    int fila1, fila2, suit;
    string symbol,suit2;
    cout<< "Escribe la columna: " ;
    //getline(cin, fila);
    cin >> fila1;
    cout<< "Escribe el simobolo: " ;
    cin >> symbol;
    cout<< "Escribe el palo 1.corazon 2.diamante 3.picas 4.treboles: " ;
    cin >> suit;
/*    cout<< "Escribe la columna donde lo quieres dejar: " ;
    //getline(cin, fila);
    cin >> fila2;*/

    if(suit == 1) suit2 = "♥";
    if(suit == 2) suit2 = "♦";
    if(suit == 3) suit2 = "♠";
    if(suit == 4) suit2 = "♣";

    col[fila1-1]->moveCards(symbol,suit2,col[0]);
    printBoard();
}

void Board::printBoard() {
    //queue1->print();
    cout<<endl;
    for (int i = 0; i < 7; ++i) {
        cout << endl;
        col[i]->print();
    }
}