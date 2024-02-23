//
// Created by dog on 20/02/24.
//

#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}
LinkedList::~LinkedList() {
    Node *current = head;
    while (current) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}

void LinkedList::addToFront(Card card) {
    Node *newNode = new Node();
    newNode->card = card;
    newNode->next = head;
    if (head) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }
    head = newNode;
}

void LinkedList::moveCards(string symbol, string suit, LinkedList* &list) {
    Node *current = head;
    Node *aux = nullptr;

    while (current) {
        if(*current->card.getSymbol() == symbol && *current->card.getSuit() == suit){
            aux = current;
            break;
        }
        current = current->next;
    }
    if(!aux){
        cout << "No existe esa carta en esta lista." << endl;
        return;
    }

    Node *firstNode = head;
    if(aux->next) aux->next->prev = nullptr;
    else {
        head = nullptr;
        tail = nullptr;
    }

    head = aux->next;
    aux->next = list->head;
    if(list->head) list->head->prev = aux;
    list->head = firstNode;

}


void LinkedList::print() {
    Node *current = tail;
    while (current) {
        if(current == head){
            current->card.setHidden(false);
        }
        current->card.print();
        current = current->prev;
    }
   cout << endl;
}
