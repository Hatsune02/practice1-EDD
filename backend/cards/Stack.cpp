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
    newNode->card = card;
    newNode->next = top;
    top = newNode;
}

Card Stack::pop() {
    Node *aux = top;
    Card card = top->card;
    top = top->next;
    delete aux;
    return card;
}

void Stack::print() {
    if(!top){
        cout << "░░  ";
    }
    else{
        top->card.print();
    }
}

bool Stack::validatePush(Card card) {
    if(!top){
        if(card.getValue() == 1) return true;
    }
    else if(card.getValue() == (top->card.getValue() - 1)) return true;
    cout << "Movimiento invalido." << endl;
    return false;
}

void Stack::pushFromQueue(Queue* &queue) {
    if(validatePush(queue->getCard())){
        push(queue->takeOutRear());
    }
}

bool Stack::verifyFullStack() {
    if(top) {
        if(top->card.getValue() == 13) return true;
        else return false;
    }
    else return false;
}