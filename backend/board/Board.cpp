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
    cout << " ";
    queue2->print(false);
    cout << "\t\t   ";
    for (int i = 0; i < 4; ++i) {
        stacks[i]->print();
    }
    cout<<endl;

    //IMPRIMIR 7 LISTAS
    Node *currentNodes[7];
    bool finished = false;
    for (int i = 0; i < 7; i++) {
        currentNodes[i] = col[i]->getTail();
    }
    cout << endl;
    // Iterar hasta que todos los nodos de todas las listas se hayan recorrido
    while (!finished) {
        finished = true;
        cout << "\t";
        for (int i = 0; i < 7; i++) {
            if (currentNodes[i] != nullptr) {
                finished = false;
                if (currentNodes[i] == col[i]->getHead()) {
                    currentNodes[i]->card.setHidden(false);
                }
                currentNodes[i]->card.print();
                cout << "  ";
                currentNodes[i] = currentNodes[i]->prev;
            } else {
                cout << "     "; // Espacio para mantener la alineación
            }
        }
        cout << endl;
    }
    delete *currentNodes;
}

void Board::play() {
    int option1, option2, list1=-1, list2=-1;
    string line, symbol, suit;
    do{
        printBoard();
        if(canUndo) cout << "1. Voltear mazo\n2. Mover cartas\n3. Apilar cartas\n4. Retroceder\n5. Ver siguiente\t6. Ver anterior\n7. Salir" << endl;
        else cout << "1. Voltear mazo\n2. Mover cartas\n3. Apilar cartas\n4. Adelantar\n5. Ver siguiente\t6. Ver anterior\n7. Salir" << endl;
        cin >> line;
        option1 = validateNum(line);
        switch (option1) {
            case 1://Voltear mazo
                makeBackup();
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
                    if(col[option2]) {
                        makeBackup();
                        col[option2]->moveCardFromDeck(queue2);
                    }
                }
                else if(option2 == 2) {
                    makeBackup();
                    moveCardsFromList(line, list1, list2, symbol, suit);
                }
                else cout << "Instruccion invalida.\n" << endl;

                break;
            case 3://Apilar cartas
                cout << "1. Del mazo\n2. De la mesa" << endl;
                cin >> line;
                option2 = validateNum(line);
                if(option2 == 1) {
                    makeBackup();
                    moveCardFromQueueToStack();
                }
                else if(option2 == 2) {
                    makeBackup();
                    moveCardFromListToStack(option2, line);
                }
                else cout << "Instruccion invalida.\n" << endl;
                break;
            case 4: // Retroceso
                if(!queue1) cout << "No puedes retroceder.\n" << endl;
                else undo();
                break;
            case 5:
                peekNext(line);
                break;
            case 6:
                peekPrev(line);
                break;
        }
        if(stacks[0]->verifyFullStack() && stacks[1]->verifyFullStack() &&
            stacks[2]->verifyFullStack() && stacks[3]->verifyFullStack()){
            cout << "\n_____JUEGO TERMINADO!_____\n" << endl;
            break;
        }
    }while(option1 != 7);
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
    if(aux == 1) suit = "♡";
    else if(aux == 2) suit = "♢";
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
    if(*queue2->getCard().getSuit() == "♡   ") stacks[0]->pushFromQueue(queue2);

    else if(*queue2->getCard().getSuit() == "♢") stacks[1]->pushFromQueue(queue2);

    else if(*queue2->getCard().getSuit() == "♠") stacks[2]->pushFromQueue(queue2);

    else if(*queue2->getCard().getSuit() == "♣") stacks[3]->pushFromQueue(queue2);

    else cout << "Movimiento invalido\n" << endl;
}

void Board::moveCardFromListToStack(int option, string line) {
    cout << "Ingresa la columna: " << endl;
    cin >> line;
    option = validateNum(line) - 1;
    if(col[option] && col[option]->firstCard().getSuit()){
        line = *col[option]->firstCard().getSuit();
        if(line == "♡") col[option]->moveCardsToStack(stacks[0]);

        else if(line == "♢") col[option]->moveCardsToStack(stacks[1]);

        else if(line == "♠") col[option]->moveCardsToStack(stacks[2]);

        else if(line == "♣") col[option]->moveCardsToStack(stacks[3]);

    }
    else cout << "Movimiento invalido.\n" << endl;
}

int Board::validateNum(const string& str) {
    try{
        return stoi(str);
    }
    catch(const invalid_argument& e){
        cout << "Escribe un numero porfavor\n" << endl;
        return -1;
    }
}

void Board::undo() {
    // Crea variables auxiliares para guardar copias de seguridad
    LinkedList* bC[7];
    Stack* bS[4];
    Queue* bQ1;
    Queue* bQ2;
    for (int i = 0; i < 7; i++) {
        bC[i] = new LinkedList(*col[i]);
    }
    for (int i = 0; i < 4; i++) {
        bS[i] = new Stack(*stacks[i]);
    }
    bQ1 = new Queue(*queue1);
    bQ2 = new Queue(*queue2);

    // Restaurar los objetos desde las copias de seguridad
    for (int i = 0; i < 7; i++) {
        delete col[i];
        col[i] = new LinkedList(*backupCol[i]);
    }
    for (int i = 0; i < 4; i++) {
        delete stacks[i];
        stacks[i] = new Stack(*backupStacks[i]);
    }
    delete queue1;
    delete queue2;
    queue1 = new Queue(*backupQueue1);
    queue2 = new Queue(*backupQueue2);

    if(canUndo) canUndo = false;
    else canUndo = true;

    // Actualizar las copias de seguridad con el estado anterior
    for (int i = 0; i < 7; i++) {
        delete backupCol[i];
        backupCol[i] = new LinkedList(*bC[i]);
    }
    for (int i = 0; i < 4; i++) {
        delete backupStacks[i];
        backupStacks[i] = new Stack(*bS[i]);
    }
    delete backupQueue1;
    delete backupQueue2;
    backupQueue1 = bQ1;
    backupQueue2 = bQ2;
}

void Board::makeBackup() {
    for (int i = 0; i < 7; i++) {
        backupCol[i] = new LinkedList(*col[i]);
    }

    // Hacer copias de seguridad de los stacks
    for (int i = 0; i < 4; i++) {
        backupStacks[i] = new Stack(*stacks[i]);
    }

    // Hacer copias de seguridad de las colas
    backupQueue1 = new Queue(*queue1);
    backupQueue2 = new Queue(*queue2);

    canUndo = true;
}

void Board::peekNext(string line) {
    int colA, pos;
    cout << "Ingresa la fila: " << endl;
    cin >> line;
    colA = validateNum(line) - 1;
    if(col[colA]){
        cout << "Ingresa la posicion: " << endl;
        cin >> line;
        pos = validateNum(line)-1;
        if(col[colA]->showCard(pos, 1)){
            printBoard();
            cout<<"__________________________________________________________________________________________\n"<<endl;
            col[colA]->showCard(pos, -1);
        }
    }
    else cout << "Movimiento invalido." << endl;
}

void Board::peekPrev(string line) {
    int colA, pos;
    cout << "Ingresa la fila: " << endl;
    cin >> line;
    colA = validateNum(line) - 1;
    if(col[colA]){
        cout << "Ingresa la posicion: " << endl;
        cin >> line;
        pos = validateNum(line)-1;
        if(col[colA]->showCard(pos, 2)){
            printBoard();
            cout<<"__________________________________________________________________________________________\n"<<endl;
            col[colA]->showCard(pos, -2);
        }
    }
    else cout << "Movimiento invalido.\n" << endl;
}