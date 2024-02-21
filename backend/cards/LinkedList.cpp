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

void LinkedList::addToBack(Card card) {
    Node *newNode = new Node();
    newNode->card = card;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
}

void LinkedList::removeFront() {
    if (!head) {
        return;
    }

    Node *aux = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete aux;
}

void LinkedList::removeBack() {
    if (!tail) {
        return;
    }

    Node *aux = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete aux;
}

void LinkedList::display() {
    Node *current = head;
    while (current) {
        cout << current->card.getSymbol();
        cout << current->card.getSuit() << " ";
        current = current->next;
    }
   cout << endl;
}
