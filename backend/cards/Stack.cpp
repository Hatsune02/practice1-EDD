//
// Created by dog on 23/02/24.
//
#include <iostream>
#include "Stack.h"
using namespace std;
//░░
Stack::Stack() {
    top = nullptr;
}

void Stack::push(Card card) {
    Node *newNode = new Node();
    newNode->next = top;
    top = newNode;
}

void Stack::print() {
    if(!top){
        cout << "░░  ";
    }
    else{
        top->card.print();
        cout << " ";
    }
}

bool Stack::validatePush(Card card) {
    if(!top){
        if(card.getValue() == 1) return true;
    }
    if(card.getValue() == (top->card.getValue() - 1)) return true;
    cout << "Movimiento invalido." << endl;
    return false;
}