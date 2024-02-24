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
    for (int i = 0; i < 4; ++i) {
        this->stacks[i] = new Stack();
    }
    fillBoard();
}

void Board::fillBoard() {
    Deck *deck = new Deck();

    for (int i = 0; i < 52; ++i) {
        if (i < 24) {
            deck->getDeck()[i].setHidden(false);
            queue1->getInto(deck->getDeck()[i]);
        }
        else if (i == 24) col[0]->addToFront(deck->getDeck()[i]);
        else if (i < 27) col[1]->addToFront(deck->getDeck()[i]);
        else if (i < 30) col[2]->addToFront(deck->getDeck()[i]);
        else if (i < 34) col[3]->addToFront(deck->getDeck()[i]);
        else if (i < 39) col[4]->addToFront(deck->getDeck()[i]);
        else if (i < 45) col[5]->addToFront(deck->getDeck()[i]);
        else col[6]->addToFront(deck->getDeck()[i]);
    }
}

void Board::printBoard() {
    cout << "\t";
    queue1->print(true);
    queue2->print(false);
    cout << "\t\t\t";
    for (int i = 0; i < 4; ++i) {
        stacks[i]->print();
    }
    cout<<endl;
    for (int i = 0; i < 7; ++i) {
        cout << endl;
        cout << i+1 << ")  ";
        col[i]->print();
    }
    cout<<endl;
}

void Board::play() {
    int option1, option2, list1=-1, list2=-1;
    string line, symbol, suit;
    do{
        printBoard();
        cout << "1. Voltear mazo\n2. Mover cartas\n3. Apilar cartas\n4. Retroceso\n5. Salir" << endl;
        cin >> line;
        option1 = validateNum(line);
        switch (option1) {
            case 1://Voletear mazo
                queue1->moveCards(queue2);
                break;
            case 2://Mover cartas
                cout << "1. Del mazo\n2. De la mesa" << endl;
                cin >> line;
                option2 = validateNum(line);
                if(option2 == 1){
                    cout << "Ingresa la fila: " << endl;
                    cin >> line;
                    option2 = validateNum(line) - 1;

                    if(col[option2]) col[option2]->moveCardFromDeck(queue2);
                }
                else if(option2 == 2) moveCardsFromList(line, list1, list2, symbol, suit);

                else cout << "Instruccion invalida." << endl;

                break;
            case 3://Apilar cartas
                cout << "1. Del mazo\n2. De la mesa" << endl;
                cin >> line;
                option2 = validateNum(line);
                if(option2 == 1) moveCardFromQueueToStack();

                else if(option2 == 2) moveCardFromListToStack(option2, line);

                else cout << "Instruccion invalida." << endl;
                break;
            case 4:
                break;
        }
        if(stacks[0]->verifyFullStack() && stacks[1]->verifyFullStack() &&
            stacks[2]->verifyFullStack() && stacks[3]->verifyFullStack()){
            cout << "\nJUEGO TERMINADO!" << endl;
            break;
        }
    }while(option1 != 5);
}

void Board::moveCardsFromList(string line, int list1, int list2, string symbol, string suit) {
    int aux;
    cout<< "Escribe la columna: " ;
    cin >> line;
    list1 = validateNum(line) - 1;
    cout<< "Escribe el simobolo: " ;
    cin >> symbol;
    cout<< "1.Corazon  2.Diamante \n3.Picas  4.Treboles: " ;
    cin >> line;
    aux = validateNum(line);
    if(aux == 1) suit = "♥";
    else if(aux == 2) suit = "♦";
    else if(aux == 3) suit = "♠";
    else if(aux == 4) suit = "♣";
    else suit = " ";
    cout<< "Escribe la columna donde lo quieres dejar: " ;
    cin >> line;
    list2 = validateNum(line) - 1;

    if(col[list1] != nullptr && col[list2] != nullptr)
    col[list1]->moveCards(symbol,suit,col[list2]);

}

void Board::moveCardFromQueueToStack() {
    if(*queue2->getCard().getSuit() == "♥") stacks[0]->pushFromQueue(queue2);

    else if(*queue2->getCard().getSuit() == "♦") stacks[1]->pushFromQueue(queue2);

    else if(*queue2->getCard().getSuit() == "♠") stacks[2]->pushFromQueue(queue2);

    else if(*queue2->getCard().getSuit() == "♣") stacks[3]->pushFromQueue(queue2);

    else cout << "Movimiento invalido" << endl;
}

void Board::moveCardFromListToStack(int option, string line) {
    cout << "Ingresa la fila: " << endl;
    cin >> line;
    option = validateNum(line) - 1;
    if(col[option] && col[option]->firstCard().getSuit()){
        line = *col[option]->firstCard().getSuit();
        if(line == "♥") col[option]->moveCardsToStack(stacks[0]);

        else if(line == "♦") col[option]->moveCardsToStack(stacks[1]);

        else if(line == "♠") col[option]->moveCardsToStack(stacks[2]);

        else if(line == "♣") col[option]->moveCardsToStack(stacks[3]);

    }
    else cout << "Movimiento invalido." << endl;
}

int Board::validateNum(const string& str) {
    try{
        return stoi(str);
    }
    catch(const invalid_argument& e){
        cout << "Escribe un numero porfavor" << endl;
        return -1;
    }
}